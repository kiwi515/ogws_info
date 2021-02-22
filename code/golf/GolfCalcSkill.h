// Objects' names will prefix their usual address (if they are static)
// US 1.01 only
#pragma once
#include "types.h"

//========================================//
//             RPGol_91b69b24             //
//========================================//
struct RPGol_91b69b24
{
    // 91B9B648
    struct _0x68 {
        
    } *sub_0x68;
}; static RPGol_91b69b24 *DAT_804bf730;
//========================================//

//========================================//
//             RPGol_91bf9268             //
//========================================//
struct RPGol_91bf9268
{
    u32 numOfPlayers_0x338;
}; static RPGol_91bf9268 *DAT_804bf8d0;
//========================================//

//========================================//
//               Functions                //
//========================================//
u32 GetRoundLength();                                   // 8029ce58
s32 GetPlayerScoreOnRelativeHole(u32, u32);             // 8029cbd4
u32 GetIndexedHoleNum(u32);                             // 8029ce04
f64 GolGetCurrentSkill(RPGol_91b69b24::_0x68 *, u32);   // 801efa00
void FUN_801ef944(f64, RPGol_91b69b24::_0x68 *, u32);   // 801ef944

namespace nw4r::math::detail {
    f32 FLog(f32);
    f32 FExp(f32);
}
//========================================//