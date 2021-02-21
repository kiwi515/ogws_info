// Objects' names will prefix their usual address (if they are static)
// US 1.01 only
#pragma once
#include "types.h"

//========================================//
//               RPBoxMain                //
//========================================//
struct RPBoxMain
{
    enum BoxGamemode
    {
        SINGLEPLAYER = 0,
        MULTIPLAYER = 1
    };

    enum MatchResult
    {
        MATCH_NOT_OVER = 0,
        P1_BEAT_P2 = 1,
        P1_LOSE_P2 = 2,
        P1_TIE_P2 = 3
    };

    u32 gamemode_0x0;
    u32 matchResult_0x38;

    void BoxingCalcNewSkill();
};
//========================================//

//========================================//
//               Functions                //
//========================================//
f64 BoxGetCurrentSkill(RPBoxSub_91b69b24::_0x9C::SkillObj *, u32);
f64 FUN_801efa00();
u32 FUN_803057b8() { return 3; }
void *FUN_801f9390(f64, RPBox_91B6DF58 *, u32);
u32 FUN_801f813c(void *, u32);
u32 FUN_80304914(RPBoxSub_91b69b24::_0x9C::SkillObj *, f32);
void FUN_801f7f34(void *);
void FUN_801ef944(f64, void *, u32);
//========================================//