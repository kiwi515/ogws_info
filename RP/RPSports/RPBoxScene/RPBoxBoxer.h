#ifndef RP_SPORTS_BOX_BOXER_H
#define RP_SPORTS_BOX_BOXER_H
#include "types_RP.h"

class RPBoxBoxer
{
public:
    enum BoxerState
    {
        STATE_FIGHTING,
        STATE_KNOCKDOWN,
        STATE_STAND_UP,
        // Unique to Wii Sports Club
        STATE_AS_IS,
        STATE_FIGHT_STILL,
        STATE_T_POSE
    };

    void addComboDmg(f32 dmg)
    {
        // Limited to 0.3 combo dmg per punch
        if (dmg > 0.3f) dmg = 0.3f;

        // Overall combo dmg is capped at 1.0
        mComboDmg += dmg;
        if (mComboDmg > 1.0f) mComboDmg = 1.0f;
    }

private:
    BoxerState mState; // at 0x0
    u8 mKnockdownCount; // at 0x4
    u16 SHORT_0x6;
    f32 mHealth; // at 0x8
    f32 mHealthPie; // at 0xC
    f32 mTotalRoundDmgDealt; // at 0x10
    f32 mComboDmg; // at 0x14
    f32 FLOAT_0x18;
    f32 FLOAT_0x1C;
    f32 mLastDamageTaken; // at 0x20
    f32 mGetUpTime; // at 0x24
    f32 mTotalMatchDmgDealt; // at 0x28
    f32 FLOAT_0x2C;

public:
    RPBoxBoxer(); // 80305b7c
    virtual ~RPBoxBoxer(); // 80305b8c
    
    bool onHit(f32 damage, f32 adjustedDmg); // 803057c0
    void onUpdate(); // 80305900
    void onGetUp(); // 80305a50
    void onRoundStart(); // 80305a64
    void onReset(); // 80305aa8
};

#endif