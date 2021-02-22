#include "GolfCalcSkill.h"
#include "types.h"

// US 1.01 @ 802c2494
void GolfCalcNewSkill()
{
    unsigned int uVar5;
    f64 dVar12;
    f64 dVar13;

    // Loop through each player
    // (This is because Golf awards skill points in multiplayer games,
    // so skill level needs to be calculated for *everyone*)
    for (int i = 0; i < DAT_804bf8d0->numOfPlayers_0x338; i++)
    {
        // Get player i's skill level
        // (in current sport)
        f64 currentSkill = GetCurrentSportSkill(DAT_804bf730->sub_0x68, i);

        // Loop through each hole played
        for (int j = 0; j < GetRoundLength(); j++)
        {
            uVar5 = GetPlayerScoreOnRelativeHole(j, i);
            dVar12 = float(uVar5);
            uVar5 = GetIndexedHoleNum(j);
            dVar13 = -((float)uVar5 * 0.125f - dVar12);
            dVar12 = nw4r::math::detail::FLog(2.0f);
            dVar12 = nw4r::math::detail::FExp(-dVar13 * 0.5f * dVar12);
            currentSkill = 0.97f * currentSkill + dVar12 * 30.0f;
        }

        // Set skill level to new value
        FUN_801ef944(currentSkill, DAT_804bf730->sub_0x68, i);
    }

    return;
}
