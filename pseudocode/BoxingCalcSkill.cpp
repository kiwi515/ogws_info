#include "BoxingCalcSkill.h"
#include "types.h"

// US 1.01 @ 802cc160
// this ptr = 91bf3e18 (in r31)
void RPBoxMain::BoxingCalcNewSkill()
{
    // Stop if gamemode is not singleplayer boxing
    // (Skill is not changed in multiplayer)
    if (gamemode_0x0 != SINGLEPLAYER) {
       return;
    }

    // Get player 1 skill level
    f64 dCurrentSkill = BoxGetCurrentSkill(DAT_804bf958->sub_0x9C->skillObj_0x438, 0);

    //=================================================================//
    //          Factor in total damage dealt (from both players)       //
    //=================================================================//
    RPBoxSub_91b69b24::_0x9C *box_0x9C = DAT_804bf958->sub_0x9C;
    // P1 total dealt damage - 1.0
    f32 playerDmgCoeff = box_0x9C->boxer1_0x414->obj_0xd8->totalDamageDealt_0x28 - 1.0f;
    // P2 (A.I boxer) total dealt damage - 1.0
    f32 aiDmgCoeff = box_0x9C->boxer2_0x418->obj_0xd8->totalDamageDealt_0x28 - 1.0f;
    
    // Clamped from zero because a loss will result in total damage < 1.0
    if (playerDmgCoeff < 0.0f)
    {
        playerDmgCoeff = 0.0f;
    }
    // Also clamped from zero (for same reason)
    if (aiDmgCoeff < 0.0f)
    {
        aiDmgCoeff = 0.0f;
    }

    // Some math regarding the coefficients
    // Not really sure what this accomplishes exactly
    playerDmgCoeff = -(0.5f * playerDmgCoeff - 1.0f);
    aiDmgCoeff = -(0.5f * aiDmgCoeff - 1.0f);

    // Both are clamped again
    if (playerDmgCoeff < 0.0f)
    {
        playerDmgCoeff = 0.0f;
    }
    // Also clamped from zero (for same reason)
    if (aiDmgCoeff < 0.0f)
    {
        aiDmgCoeff = 0.0f;
    }
    //=================================================================//

    //=================================================================//
    //             Factor in match result (Win/Loss/Tie)               //
    //=================================================================//
    f32 skillCoeff; // Skill coefficient
    
    /* Player 1 lost to player 2 */
    if (this->matchResult_0x38 == P1_LOSE_P2)
    {
        skillCoeff = -(aiDmgCoeff * 75.0f);
    }
    /* Player 1 beat player 2 */
    else if (this->matchResult_0x38 == P1_BEAT_P2)
    {
        // Same math as a loss (except positive)
        skillCoeff = aiDmgCoeff * 75.0f;
    }
    /* Player 1 tied with player 2 */
    else if (this->matchResult_0x38 == P1_TIE_P2)
    {
        // Factors in both players' damage output in order to
        // accurately award skill (for cases such as: R1 Win, R2 Loss, R3 Tie)
        skillCoeff = 50.0f * (aiDmgCoeff + playerDmgCoeff * -1.0f) * 0.5f;
    }
    //=================================================================//

    //=================================================================//
    //              Adjust skill level (Calculate change)              //
    //=================================================================//
    // Calculate change in skill (This gets added to the original skill level)
    // aiScale represents a decimal number that is derived from the opponents skill level.
    f64 skillChange = skillCoeff + 50.0f * box_0x9C->skillObj_0x438->aiScale_0x80;
    if (skillChange < 0.0f) {
        skillChange = 0.0f;
    }

    // True "new skill level"
    // Skill = 0.96(Current skill) + Change in skill
    dCurrentSkill = 0.96f * dCurrentSkill + skillChange;
    //=================================================================//

    //=================================================================//
    //            Undocumented (Doesn't affect skill calc)             //
    //=================================================================//
    void *result = FUN_801f9390(skillChange, DAT_804bf740, 0);
    FUN_801f813c(result, 1);

    u32 result2 = FUN_80304914(DAT_804bf958->sub_0x9C->skillObj_0x438,
        DAT_804bf958->sub_0x9C->boxer2_0x418->obj_0xd8->totalDamageDealt_0x28;

    if ((result2 != 0) && (this->matchResult_0x38 == P1_BEAT_P2)) {
        FUN_801f7f34(result);
    }
    
    // I believe this updates the skill level
    // with what was calculated earlier
    FUN_801ef944(dCurrentSkill, DAT_804bf958->obj_0x68, 0);
    //=================================================================//

    return;
}

// Get player's current skill level (double precision)
f64 BoxGetCurrentSkill(RPBoxSub_91b69b24::_0x9C::SkillObj *obj, u32 player)
{
    // obj_0x68 being NULL still causes a crash later (???)
    if (DAT_804bf958->obj_0x68 == NULL)
    {
        return 0.0;
    }

    return FUN_801efa00();
}
