#include "BaseballCalcSkill.h"
#include "types.h"

// US 1.01 @ 8024f5f0
void BaseballCalcNewSkill()
{
    u8 bVar1;
    u8 bVar2;
    int iVar3;
    int iVar4;
    undefined4 uVar5;
    int iVar6;
    int iVar7;
    uint uVar8;
    undefined4 uVar9;
    double dVar11;
    undefined8 in_f31;
    double dVar12;
    double dVar13;

    iVar3 = _savegpr_26();
    iVar4 = FUN_80271ee8();

    if (iVar4 == 0)
    {
        uVar5 = FUN_801f9390(DAT_804bf740, 0xffffffff);
        FUN_801f813c(uVar5,1);
    }

    uVar9 = *(*(iVar3 + 0x118) + 0x180);
    uVar5 = *(DAT_804bf730 + 0x68);
    FUN_802656bc(uVar9,0);
    FUN_802656bc(uVar9,1);
    iVar4 = FUN_8026755c(*(iVar3 + 0x118),0);
    iVar6 = FUN_8026755c(*(iVar3 + 0x118),1);
    iVar7 = (**(**(iVar3 + 300) + 0x1c))();

    if (iVar7 == 0)
    {
        uVar8 = iVar4 - iVar6;
    }
    else
    {
        uVar8 = iVar6 - iVar4;
    }

    dVar11 = nw4r::math::AtanFIdx(0.1f * (float)uVar8));
    dVar12 = 0.65f * 0.024543693f * dVar11 * 150.0f;
    dVar13 = FUN_801efa00(uVar5,0);
    dVar11 = 10000.0f;
    dVar13 = 150.0f * *(*(iVar3 + 0x100) + 0x18) + 0.91f * dVar13 + dVar12;

    if ((dVar13 <= dVar11) && (dVar11 = dVar13, dVar13 < 0.0f))
    {
        dVar11 = 0.0f;
    }

    iVar3 = FUN_80271ee8(iVar3);

    if (iVar3 == 0)
    {
        FUN_801ef944(dVar11,uVar5,0);
    }

    FUN_801ee840(DAT_804bf730);

    return;
}
