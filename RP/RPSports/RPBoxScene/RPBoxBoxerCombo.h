#ifndef RP_SPORTS_BOX_BOXER_COMBO_H
#define RP_SPORTS_BOX_BOXER_COMBO_H
#include "types_RP.h"

/**
 * @brief Combo for boxer's punches
 * 
 * The combo system rewards alternating hands when punching, and increases punch strength over time.
 * If the player either waits too long or does not alternate hands, the combo will reset.
 * 
 * (Custom name)
 */
class RPBoxBoxerCombo
{
public:
    enum PunchType
    {
        PUNCH_LEFT,
        PUNCH_RIGHT,
        PUNCH_MISS
    };

private:
    u16 mStrength; // at 0x0
    f32 mContinueTimer; // at 0x4
    u16 mWindowLength; // at 0x8
    f32 mWindowRemaining; // at 0xC
    u16 mPunchCount; // at 0x10
    PunchType mLastPunchType; // at 0x14

public:
    RPBoxBoxerCombo(); // 80306c24
    virtual ~RPBoxBoxerCombo(); // 80306c34

    void onPunchLand(PunchType); // 80306a8c
    void onPunchThrow(PunchType); // 80306b30
    void calc(); // 80306b64
    void onPunchEnd(); // 80306bd4
    void onRoundStart(); // 80306bfc

    void reset()
    {
        mStrength = 0;
        mContinueTimer = 0.0f;
        mWindowLength = 0;
        mWindowRemaining = 0.0f;
        mPunchCount = 0;
        mLastPunchType = PUNCH_MISS;   
    }
};

#endif