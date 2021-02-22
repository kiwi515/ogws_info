.global BaseballCalcNewSkill
BaseballCalcNewSkill:
# Stack frame + backup
/* 8024F5F0 0024A4F0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8024F5F4 0024A4F4  7C 08 02 A6 */	mflr r0
/* 8024F5F8 0024A4F8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8024F5FC 0024A4FC  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8024F600 0024A500  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8024F604 0024A504  39 61 00 30 */	addi r11, r1, 0x30

# Backup r26 to keep copy of this ptr
/* 8024F608 0024A508  4B E6 27 39 */	bl _savegpr_26
/* 8024F60C 0024A50C  7C 7A 1B 78 */	mr r26, r3

# Call (_thiscall) func
/* 8024F610 0024A510  48 02 28 D9 */	bl func_80271EE8
# if (this->IsGameMultiplayer() == 0) {
    /* 8024F614 0024A514  2C 03 00 00 */	cmpwi r3, 0
    /* 8024F618 0024A518  40 82 00 18 */	bne lbl_8024F630
    # r3 = gobj_804BF740
    /* 8024F61C 0024A51C  80 6D A3 C0 */	lwz r3, lbl_804BF740-_SDA_BASE_(r13)
    # r4 = -1 (0xFFFFFFFF)
    # func_801F9390(gobj_804BF740, -1)
    /* 8024F620 0024A520  38 80 FF FF */	li r4, -1
    /* 8024F624 0024A524  4B FA 9D 6D */	bl func_801F9390
    # func_801F813C(r3, 1)
    /* 8024F628 0024A528  38 80 00 01 */	li r4, 1
    /* 8024F62C 0024A52C  4B FA 8B 11 */	bl func_801F813C
# }

lbl_8024F630:
# r3 = this->word_0x118
/* 8024F630 0024A530  80 7A 01 18 */	lwz r3, 0x118(r26)
# r4 = 0
/* 8024F634 0024A534  38 80 00 00 */	li r4, 0
# r5 = gobj_804BF730
/* 8024F638 0024A538  80 AD A3 B0 */	lwz r5, lbl_804BF730-_SDA_BASE_(r13)
# r29 = this->word_0x118->word_0x180
/* 8024F63C 0024A53C  83 A3 01 80 */	lwz r29, 0x180(r3)
# r27 = gobj_804BF730->word_0x68
/* 8024F640 0024A540  83 65 00 68 */	lwz r27, 0x68(r5)

# Copy this ptr back to r3
# this->func_802656BC(0)
/* 8024F644 0024A544  7F A3 EB 78 */	mr r3, r29
/* 8024F648 0024A548  48 01 60 75 */	bl func_802656BC

# copy retval -> r28
/* 8024F64C 0024A54C  7C 7C 1B 78 */	mr r28, r3
# copy this ptr (r29) -> r3
/* 8024F650 0024A550  7F A3 EB 78 */	mr r3, r29
# r4 = 1
/* 8024F654 0024A554  38 80 00 01 */	li r4, 1
# this->func_802656BC(1)
/* 8024F658 0024A558  48 01 60 65 */	bl func_802656BC

# copy this ptr -> r29
/* 8024F65C 0024A55C  7C 7D 1B 78 */	mr r29, r3
# r3 = this->word_0x118
/* 8024F660 0024A560  80 7A 01 18 */	lwz r3, 0x118(r26)
# r4 = 0
/* 8024F664 0024A564  38 80 00 00 */	li r4, 0
# func_8026755C(this->word_0x118, 0)
/* 8024F668 0024A568  48 01 7E F5 */	bl func_8026755C

# Move retval -> r30
/* 8024F66C 0024A56C  7C 7E 1B 78 */	mr r30, r3
# r3 = this->word_0x118
/* 8024F670 0024A570  80 7A 01 18 */	lwz r3, 0x118(r26)
# r4 = 1
/* 8024F674 0024A574  38 80 00 01 */	li r4, 1
# func_8026755C(this->word_0x118, 1)
/* 8024F678 0024A578  48 01 7E E5 */	bl func_8026755C

# copy retval -> r31
/* 8024F67C 0024A57C  7C 7F 1B 78 */	mr r31, r3
# r3 = this->obj_0x12C
/* 8024F680 0024A580  80 7A 01 2C */	lwz r3, 0x12c(r26)
# r12 = this->obj_0x12C->obj_0x0
/* 8024F684 0024A584  81 83 00 00 */	lwz r12, 0(r3)
# r12 = this->obj_0x12C->obj_0x0->ptmf_0x1C
/* 8024F688 0024A588  81 8C 00 1C */	lwz r12, 0x1c(r12)
# this->obj_0x12C->obj_0x0->ptmf_0x1C()
/* 8024F68C 0024A58C  7D 89 03 A6 */	mtctr r12
/* 8024F690 0024A590  4E 80 04 21 */	bctrl 
# if (this->obj_0x0->ptmf_0x1C() != 0) {
    /* 8024F694 0024A594  2C 03 00 00 */	cmpwi r3, 0
    /* 8024F698 0024A598  41 82 00 10 */	beq lbl_8024F6A8
    # r0 = [retval from this->func_802656BC(0)] - [this]
    /* 8024F69C 0024A59C  7C 1C E8 50 */	subf r0, r28, r29
    # r4 = [retval from func_8026755C(this->word_0x118, 0)] - [retval from func_8026755C(this->word_0x118, 1)]
    /* 8024F6A0 0024A5A0  7C 9E F8 50 */	subf r4, r30, r31
    /* 8024F6A4 0024A5A4  48 00 00 0C */	b lbl_8024F6B0
# }
lbl_8024F6A8:
# r0 = [this] - [retval from this->func_802656BC(0)]
/* 8024F6A8 0024A5A8  7C 1D E0 50 */	subf r0, r29, r28
# r4 = [retval from func_8026755C(this->word_0x118, 1)] - [retval from func_8026755C(this->word_0x118, 0)]
/* 8024F6AC 0024A5AC  7C 9F F0 50 */	subf r4, r31, r30

# Most of this label is just converting uVar8 (r4) from int -> float
lbl_8024F6B0:
# r3 = r0 ^ 0x80000000
/* 8024F6B0 0024A5B0  6C 03 80 00 */	xoris r3, r0, 0x8000
# r0 = 0x43300000
/* 8024F6B4 0024A5B4  3C 00 43 30 */	lis r0, 0x4330
# backup r3 on stack
/* 8024F6B8 0024A5B8  90 61 00 0C */	stw r3, 0xc(r1)
# f3 = int2float constant
/* 8024F6BC 0024A5BC  C8 62 B8 D0 */	lfd f3, lbl_804C32F0-_SDA2_BASE_(r2)
# backup r0 on stack
/* 8024F6C0 0024A5C0  90 01 00 08 */	stw r0, 8(r1)
# f1 = 3.0f
/* 8024F6C4 0024A5C4  C0 22 B8 AC */	lfs f1, lbl_804C32CC-_SDA2_BASE_(r2)
# load double off of stack (r0, which equals 0x43300000)
/* 8024F6C8 0024A5C8  C8 41 00 08 */	lfd f2, 8(r1)
# f0 = 120.0f
/* 8024F6CC 0024A5CC  C0 02 B8 A8 */	lfs f0, lbl_804C32C8-_SDA2_BASE_(r2)
# f2 = f2 (0x43300000) - int2float const (0x461c4000)
/* 8024F6D0 0024A5D0  EC 42 18 28 */	fsubs f2, f2, f3
# finish converting uVar8 to float
/* 8024F6D4 0024A5D4  EC 22 08 24 */	fdivs f1, f2, f1
/* 8024F6D8 0024A5D8  EC 20 00 72 */	fmuls f1, f0, f1

# if (f1 > 120.0f)
/* 8024F6DC 0024A5DC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8024F6E0 0024A5E0  40 81 00 08 */	ble lbl_8024F6E8
/* 8024F6E4 0024A5E4  48 00 00 0C */	b lbl_8024F6F0
lbl_8024F6E8:
# f0 = -120.0f
/* 8024F6E8 0024A5E8  C0 02 B8 B0 */	lfs f0, lbl_804C32D0-_SDA2_BASE_(r2)
# compare f1 and f0????
/* 8024F6EC 0024A5EC  FC 01 00 40 */	fcmpo cr0, f1, f0
# }
lbl_8024F6F0:
/* 8024F6F0 0024A5F0  6C 83 80 00 */	xoris r3, r4, 0x8000
/* 8024F6F4 0024A5F4  3C 00 43 30 */	lis r0, 0x4330
/* 8024F6F8 0024A5F8  90 61 00 0C */	stw r3, 0xc(r1)
/* 8024F6FC 0024A5FC  C8 42 B8 D0 */	lfd f2, lbl_804C32F0-_SDA2_BASE_(r2)
/* 8024F700 0024A600  90 01 00 08 */	stw r0, 8(r1)
/* 8024F704 0024A604  C0 02 B8 B4 */	lfs f0, lbl_804C32D4-_SDA2_BASE_(r2)
/* 8024F708 0024A608  C8 21 00 08 */	lfd f1, 8(r1)
/* 8024F70C 0024A60C  EC 21 10 28 */	fsubs f1, f1, f2
/* 8024F710 0024A610  EC 20 00 72 */	fmuls f1, f0, f1
/* 8024F714 0024A614  4B DE 02 D1 */	bl AtanFIdx__Q24nw4r4mathFf
/* 8024F718 0024A618  C0 02 B8 B8 */	lfs f0, lbl_804C32D8-_SDA2_BASE_(r2)
/* 8024F71C 0024A61C  7F 63 DB 78 */	mr r3, r27
/* 8024F720 0024A620  C0 42 B8 BC */	lfs f2, lbl_804C32DC-_SDA2_BASE_(r2)
/* 8024F724 0024A624  38 80 00 00 */	li r4, 0
/* 8024F728 0024A628  EC 20 00 72 */	fmuls f1, f0, f1
/* 8024F72C 0024A62C  C0 02 B8 C0 */	lfs f0, lbl_804C32E0-_SDA2_BASE_(r2)
/* 8024F730 0024A630  EF E2 00 72 */	fmuls f31, f2, f1
/* 8024F734 0024A634  EF FF 00 32 */	fmuls f31, f31, f0
/* 8024F738 0024A638  4B FA 02 C9 */	bl func_801EFA00
/* 8024F73C 0024A63C  C0 02 B8 C4 */	lfs f0, lbl_804C32E4-_SDA2_BASE_(r2)
/* 8024F740 0024A640  80 7A 01 00 */	lwz r3, 0x100(r26)
/* 8024F744 0024A644  EC 60 F8 7A */	fmadds f3, f0, f1, f31
/* 8024F748 0024A648  C0 42 B8 C0 */	lfs f2, lbl_804C32E0-_SDA2_BASE_(r2)
/* 8024F74C 0024A64C  C0 23 00 18 */	lfs f1, 0x18(r3)
/* 8024F750 0024A650  C0 02 B8 C8 */	lfs f0, lbl_804C32E8-_SDA2_BASE_(r2)
/* 8024F754 0024A654  EF E2 18 7A */	fmadds f31, f2, f1, f3
/* 8024F758 0024A658  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 8024F75C 0024A65C  40 81 00 0C */	ble lbl_8024F768
/* 8024F760 0024A660  FF E0 00 90 */	fmr f31, f0
/* 8024F764 0024A664  48 00 00 14 */	b lbl_8024F778
lbl_8024F768:
/* 8024F768 0024A668  C0 02 B8 98 */	lfs f0, lbl_804C32B8-_SDA2_BASE_(r2)
/* 8024F76C 0024A66C  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 8024F770 0024A670  40 80 00 08 */	bge lbl_8024F778
/* 8024F774 0024A674  FF E0 00 90 */	fmr f31, f0
lbl_8024F778:
/* 8024F778 0024A678  7F 43 D3 78 */	mr r3, r26
/* 8024F77C 0024A67C  48 02 27 6D */	bl func_80271EE8
/* 8024F780 0024A680  2C 03 00 00 */	cmpwi r3, 0
/* 8024F784 0024A684  40 82 00 14 */	bne lbl_8024F798
/* 8024F788 0024A688  FC 20 F8 90 */	fmr f1, f31
/* 8024F78C 0024A68C  7F 63 DB 78 */	mr r3, r27
/* 8024F790 0024A690  38 80 00 00 */	li r4, 0
/* 8024F794 0024A694  4B FA 01 B1 */	bl func_801EF944
lbl_8024F798:
/* 8024F798 0024A698  80 6D A3 B0 */	lwz r3, lbl_804BF730-_SDA_BASE_(r13)
/* 8024F79C 0024A69C  4B F9 F0 A5 */	bl func_801EE840
/* 8024F7A0 0024A6A0  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8024F7A4 0024A6A4  39 61 00 30 */	addi r11, r1, 0x30
/* 8024F7A8 0024A6A8  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8024F7AC 0024A6AC  4B E6 25 E1 */	bl _restgpr_26
/* 8024F7B0 0024A6B0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8024F7B4 0024A6B4  7C 08 03 A6 */	mtlr r0
/* 8024F7B8 0024A6B8  38 21 00 40 */	addi r1, r1, 0x40
/* 8024F7BC 0024A6BC  4E 80 00 20 */	blr 
