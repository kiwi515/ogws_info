#pragma ipa file
#include "RPBoxBoxer.h"

// Returns true if the hit knocks down the boxer
bool RPBoxBoxer::onHit(f32 damage, f32 adjustedDmg)
{
    // Hits should only be processed while the boxer is fighting
    if (mState != STATE_FIGHTING) return false;

    // Check if the punch will knockdown
    if (mHealth - damage <= 0.0f)
    {
        // Weak punches that were supposed to knockdown will
        // only do 0.001 damage (1/100 slice) instead of their normal value
        if (damage >= 0.006f)
        {
            damage = mHealth;
        }
        else
        {
            damage = 0.001f;
        }
    }

    // Update health bar/pie
    mHealthPie = mHealth;

    // Update last damage taken
    mLastDamageTaken = damage;

    // Do damage to player health (cannot go below zero)
    mHealth -= damage;
    if (mHealth < 0.0f) mHealth = 0.0f;

    // Update damage dealt
    mTotalMatchDmgDealt += damage;
    mTotalRoundDmgDealt += damage;

    // Combo damage = adjusted damage * 3
    f32 comboDmg = 3.0f * adjustedDmg;
    if (comboDmg > 0.0f)
    {
        // Reset some timer if a combo starts
        FLOAT_0x18 = 0.0f;
    }
    addComboDmg(comboDmg);

    // Process knockdown
    if (mHealth <= 0.0f)
    {
        mHealth = 0.0f;
        mKnockdownCount++;

        // Because of the outer 2X, each knockdown effectively adds 2 seconds to the get up time
        mGetUpTime = 2.0f * ((4.0f * mComboDmg) + mKnockdownCount);
        
        mState = STATE_KNOCKDOWN;
        return true;
    }

    return false;
}

void RPBoxBoxer::onUpdate()
{
    // lbl_80305900:
    // /* 80305900 00300800  94 21 FF F0 */	stwu r1, -0x10(r1)
    // /* 80305904 00300804  80 03 00 00 */	lwz r0, 0(r3)
    // /* 80305908 00300808  2C 00 00 01 */	cmpwi r0, 1
    // /* 8030590C 0030080C  41 82 00 68 */	beq lbl_80305974
    // /* 80305910 00300810  40 80 00 F8 */	bge lbl_80305A08
    // /* 80305914 00300814  2C 00 00 00 */	cmpwi r0, 0
    // /* 80305918 00300818  40 80 00 0C */	bge lbl_80305924
    // /* 8030591C 0030081C  48 00 00 EC */	b lbl_80305A08
    // /* 80305920 00300820  48 00 00 E8 */	b lbl_80305A08
    // lbl_80305924:
    // /* 80305924 00300824  C0 43 00 18 */	lfs f2, 0x18(r3)
    // /* 80305928 00300828  C0 22 DD F0 */	lfs f1, lbl_804C5810-_SDA2_BASE_(r2)
    // /* 8030592C 0030082C  C0 02 DD F4 */	lfs f0, lbl_804C5814-_SDA2_BASE_(r2)
    // /* 80305930 00300830  C0 62 DD DC */	lfs f3, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 80305934 00300834  EC 82 00 7A */	fmadds f4, f2, f1, f0
    // /* 80305938 00300838  C0 42 DD F8 */	lfs f2, lbl_804C5818-_SDA2_BASE_(r2)
    // /* 8030593C 0030083C  C0 22 DD C8 */	lfs f1, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 80305940 00300840  C0 03 00 14 */	lfs f0, 0x14(r3)
    // /* 80305944 00300844  EC 63 20 28 */	fsubs f3, f3, f4
    // /* 80305948 00300848  D0 83 00 18 */	stfs f4, 0x18(r3)
    // /* 8030594C 0030084C  EC 42 01 32 */	fmuls f2, f2, f4
    // /* 80305950 00300850  C0 8D 88 B0 */	lfs f4, lbl_804BDC30-_SDA_BASE_(r13)
    // /* 80305954 00300854  EC 41 10 FA */	fmadds f2, f1, f3, f2
    // /* 80305958 00300858  EC 02 01 3C */	fnmsubs f0, f2, f4, f0
    // /* 8030595C 0030085C  FC 00 08 40 */	fcmpo cr0, f0, f1
    // /* 80305960 00300860  D0 03 00 14 */	stfs f0, 0x14(r3)
    // /* 80305964 00300864  4C 40 13 82 */	cror 2, 0, 2
    // /* 80305968 00300868  40 82 00 A0 */	bne lbl_80305A08
    // /* 8030596C 0030086C  D0 23 00 14 */	stfs f1, 0x14(r3)
    // /* 80305970 00300870  48 00 00 98 */	b lbl_80305A08
    // lbl_80305974:
    // /* 80305974 00300874  C0 02 DD FC */	lfs f0, lbl_804C581C-_SDA2_BASE_(r2)
    // /* 80305978 00300878  FC 01 00 40 */	fcmpo cr0, f1, f0
    // /* 8030597C 0030087C  40 80 00 8C */	bge lbl_80305A08
    // /* 80305980 00300880  C0 43 00 24 */	lfs f2, 0x24(r3)
    // /* 80305984 00300884  C0 02 DD DC */	lfs f0, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 80305988 00300888  EC 02 00 28 */	fsubs f0, f2, f0
    // /* 8030598C 0030088C  FC 00 08 40 */	fcmpo cr0, f0, f1
    // /* 80305990 00300890  40 80 00 78 */	bge lbl_80305A08
    // /* 80305994 00300894  88 03 00 04 */	lbz r0, 4(r3)
    // /* 80305998 00300898  2C 00 00 05 */	cmpwi r0, 5
    // /* 8030599C 0030089C  41 80 00 08 */	blt lbl_803059A4
    // /* 803059A0 003008A0  38 00 00 04 */	li r0, 4
    // lbl_803059A4:
    // /* 803059A4 003008A4  3C A0 80 39 */	lis r5, lbl_80391858@ha
    // /* 803059A8 003008A8  3C 80 80 39 */	lis r4, lbl_80391870@ha
    // /* 803059AC 003008AC  54 06 10 3A */	slwi r6, r0, 2
    // /* 803059B0 003008B0  C0 82 DD C8 */	lfs f4, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 803059B4 003008B4  38 A5 18 58 */	addi r5, r5, lbl_80391858@l
    // /* 803059B8 003008B8  38 84 18 70 */	addi r4, r4, lbl_80391870@l
    // /* 803059BC 003008BC  7C A5 34 2E */	lfsx f5, r5, r6
    // /* 803059C0 003008C0  38 00 00 02 */	li r0, 2
    // /* 803059C4 003008C4  C0 22 DD DC */	lfs f1, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 803059C8 003008C8  7C 04 34 2E */	lfsx f0, r4, r6
    // /* 803059CC 003008CC  EC 61 28 28 */	fsubs f3, f1, f5
    // /* 803059D0 003008D0  C0 43 00 10 */	lfs f2, 0x10(r3)
    // /* 803059D4 003008D4  EC 01 00 28 */	fsubs f0, f1, f0
    // /* 803059D8 003008D8  C0 23 00 28 */	lfs f1, 0x28(r3)
    // /* 803059DC 003008DC  EC 42 28 2A */	fadds f2, f2, f5
    // /* 803059E0 003008E0  D0 83 00 0C */	stfs f4, 0xc(r3)
    // /* 803059E4 003008E4  EC 00 18 24 */	fdivs f0, f0, f3
    // /* 803059E8 003008E8  D0 63 00 08 */	stfs f3, 8(r3)
    // /* 803059EC 003008EC  D0 43 00 10 */	stfs f2, 0x10(r3)
    // /* 803059F0 003008F0  D0 83 00 14 */	stfs f4, 0x14(r3)
    // /* 803059F4 003008F4  D0 83 00 18 */	stfs f4, 0x18(r3)
    // /* 803059F8 003008F8  90 03 00 00 */	stw r0, 0(r3)
    // /* 803059FC 003008FC  EC 21 28 2A */	fadds f1, f1, f5
    // /* 80305A00 00300900  D0 03 00 2C */	stfs f0, 0x2c(r3)
    // /* 80305A04 00300904  D0 23 00 28 */	stfs f1, 0x28(r3)
    // lbl_80305A08:
    // /* 80305A08 00300908  88 83 00 04 */	lbz r4, 4(r3)
    // /* 80305A0C 0030090C  3C 00 43 30 */	lis r0, 0x4330
    // /* 80305A10 00300910  90 01 00 08 */	stw r0, 8(r1)
    // /* 80305A14 00300914  C8 62 DD E8 */	lfd f3, lbl_804C5808-_SDA2_BASE_(r2)
    // /* 80305A18 00300918  90 81 00 0C */	stw r4, 0xc(r1)
    // /* 80305A1C 0030091C  C0 42 DE 00 */	lfs f2, lbl_804C5820-_SDA2_BASE_(r2)
    // /* 80305A20 00300920  C8 01 00 08 */	lfd f0, 8(r1)
    // /* 80305A24 00300924  C0 22 DD DC */	lfs f1, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 80305A28 00300928  EC 60 18 28 */	fsubs f3, f0, f3
    // /* 80305A2C 0030092C  C0 02 DD C8 */	lfs f0, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 80305A30 00300930  EC 43 10 24 */	fdivs f2, f3, f2
    // /* 80305A34 00300934  EC 21 10 28 */	fsubs f1, f1, f2
    // /* 80305A38 00300938  FC 01 00 40 */	fcmpo cr0, f1, f0
    // /* 80305A3C 0030093C  D0 23 00 1C */	stfs f1, 0x1c(r3)
    // /* 80305A40 00300940  40 80 00 08 */	bge lbl_80305A48
    // /* 80305A44 00300944  D0 03 00 1C */	stfs f0, 0x1c(r3)
    // lbl_80305A48:
    // /* 80305A48 00300948  38 21 00 10 */	addi r1, r1, 0x10
    // /* 80305A4C 0030094C  4E 80 00 20 */	blr 
}

void RPBoxBoxer::onGetUp()
{
    // Make boxer get up
    mState = STATE_FIGHTING;
    // Sync health pie
    mHealthPie = mHealth;
}

void RPBoxBoxer::onRoundStart()
{
    // Regen one pie slice per round
    mHealth += 0.1f;
    if (mHealth > 1.0f) mHealth = 1.0f;

    // Reset boxer
    mComboDmg = 0.0f;
    mGetUpTime = 0.0f;
    mState = STATE_FIGHTING;
    mTotalRoundDmgDealt = 0.0f;

    // Sync health display with new health
    mHealthPie = mHealth;
}

void RPBoxBoxer::reset()
{
    // .global func_80305AA8
    // func_80305AA8:
    // /* 80305AA8 003009A8  C0 22 DD DC */	lfs f1, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 80305AAC 003009AC  38 00 00 00 */	li r0, 0
    // /* 80305AB0 003009B0  C0 02 DD C8 */	lfs f0, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 80305AB4 003009B4  2C 00 00 05 */	cmpwi r0, 5
    // /* 80305AB8 003009B8  98 03 00 04 */	stb r0, 4(r3)
    // /* 80305ABC 003009BC  38 C0 00 00 */	li r6, 0
    // /* 80305AC0 003009C0  B0 03 00 06 */	sth r0, 6(r3)
    // /* 80305AC4 003009C4  D0 23 00 08 */	stfs f1, 8(r3)
    // /* 80305AC8 003009C8  D0 03 00 20 */	stfs f0, 0x20(r3)
    // /* 80305ACC 003009CC  D0 23 00 1C */	stfs f1, 0x1c(r3)
    // /* 80305AD0 003009D0  D0 03 00 28 */	stfs f0, 0x28(r3)
    // /* 80305AD4 003009D4  D0 23 00 2C */	stfs f1, 0x2c(r3)
    // /* 80305AD8 003009D8  41 80 00 08 */	blt lbl_80305AE0
    // /* 80305ADC 003009DC  38 C0 00 04 */	li r6, 4
    // lbl_80305AE0:
    // /* 80305AE0 003009E0  3C A0 80 39 */	lis r5, lbl_80391858@ha
    // /* 80305AE4 003009E4  3C 80 80 39 */	lis r4, lbl_80391870@ha
    // /* 80305AE8 003009E8  54 C6 10 3A */	slwi r6, r6, 2
    // /* 80305AEC 003009EC  C0 C2 DD C8 */	lfs f6, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 80305AF0 003009F0  38 A5 18 58 */	addi r5, r5, lbl_80391858@l
    // /* 80305AF4 003009F4  38 84 18 70 */	addi r4, r4, lbl_80391870@l
    // /* 80305AF8 003009F8  7C E5 34 2E */	lfsx f7, r5, r6
    // /* 80305AFC 003009FC  38 00 00 02 */	li r0, 2
    // /* 80305B00 00300A00  C0 A2 DD DC */	lfs f5, lbl_804C57FC-_SDA2_BASE_(r2)
    // /* 80305B04 00300A04  7C 24 34 2E */	lfsx f1, r4, r6
    // /* 80305B08 00300A08  EC 85 38 28 */	fsubs f4, f5, f7
    // /* 80305B0C 00300A0C  C0 02 DE 04 */	lfs f0, lbl_804C5824-_SDA2_BASE_(r2)
    // /* 80305B10 00300A10  EC 25 08 28 */	fsubs f1, f5, f1
    // /* 80305B14 00300A14  C0 63 00 10 */	lfs f3, 0x10(r3)
    // /* 80305B18 00300A18  C0 43 00 28 */	lfs f2, 0x28(r3)
    // /* 80305B1C 00300A1C  EC 04 00 2A */	fadds f0, f4, f0
    // /* 80305B20 00300A20  EC 21 20 24 */	fdivs f1, f1, f4
    // /* 80305B24 00300A24  D0 C3 00 0C */	stfs f6, 0xc(r3)
    // /* 80305B28 00300A28  D0 C3 00 14 */	stfs f6, 0x14(r3)
    // /* 80305B2C 00300A2C  D0 C3 00 18 */	stfs f6, 0x18(r3)
    // /* 80305B30 00300A30  90 03 00 00 */	stw r0, 0(r3)
    // /* 80305B34 00300A34  D0 03 00 08 */	stfs f0, 8(r3)
    // /* 80305B38 00300A38  EC 63 38 2A */	fadds f3, f3, f7
    // /* 80305B3C 00300A3C  D0 23 00 2C */	stfs f1, 0x2c(r3)
    // /* 80305B40 00300A40  EC 22 38 2A */	fadds f1, f2, f7
    // /* 80305B44 00300A44  FC 00 28 40 */	fcmpo cr0, f0, f5
    // /* 80305B48 00300A48  D0 63 00 10 */	stfs f3, 0x10(r3)
    // /* 80305B4C 00300A4C  D0 23 00 28 */	stfs f1, 0x28(r3)
    // /* 80305B50 00300A50  40 81 00 08 */	ble lbl_80305B58
    // /* 80305B54 00300A54  D0 A3 00 08 */	stfs f5, 8(r3)
    // lbl_80305B58:
    // /* 80305B58 00300A58  C0 22 DD C8 */	lfs f1, lbl_804C57E8-_SDA2_BASE_(r2)
    // /* 80305B5C 00300A5C  38 00 00 00 */	li r0, 0
    // /* 80305B60 00300A60  C0 03 00 08 */	lfs f0, 8(r3)
    // /* 80305B64 00300A64  D0 23 00 14 */	stfs f1, 0x14(r3)
    // /* 80305B68 00300A68  D0 23 00 24 */	stfs f1, 0x24(r3)
    // /* 80305B6C 00300A6C  90 03 00 00 */	stw r0, 0(r3)
    // /* 80305B70 00300A70  D0 23 00 10 */	stfs f1, 0x10(r3)
    // /* 80305B74 00300A74  D0 03 00 0C */	stfs f0, 0xc(r3)
    // /* 80305B78 00300A78  4E 80 00 20 */	blr 
}

RPBoxBoxer::RPBoxBoxer()
{

}

RPBoxBoxer::~RPBoxBoxer()
{

}