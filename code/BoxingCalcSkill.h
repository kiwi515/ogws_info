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
//               RPBoxSub                 //
//========================================//
struct RPBoxSub_91b69b24
{
    void *obj_0x68;

    struct _0x9C {
        // 91bf4850
        struct RPBoxPlayer {
            struct _0xd8 {
                f32 totalDamageDealt_0x28;
            } *obj_0xd8;
        } *boxer1_0x414;
        struct RPBoxPlayer *boxer2_0x418;
        struct SkillObj {
            // 91BF4AE8
            f32 aiScale_0x80;
        } *skillObj_0x438;
    } *sub_0x9C;


}; static RPBoxSub_91b69b24* DAT_804bf958;
//========================================//

// Undocumented
struct RPBox_91B6DF58 {}; static RPBox_91B6DF58 *DAT_804bf740;

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
