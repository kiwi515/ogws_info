#pragma ipa file
#include "RPBoxBoxerCombo.h"

#define MAX_COMBO_STRENGTH 6

void RPBoxBoxerCombo::onPunchLand(PunchType punch)
{
    mLastPunchType = punch;
    mPunchCount++;

    mStrength++;
    if (mStrength > MAX_COMBO_STRENGTH)
        mStrength = MAX_COMBO_STRENGTH;

    // Combo continuation window, in frames?
    u16 timers[MAX_COMBO_STRENGTH] = { 40, 20, 8, 4, 2, 0 };
    mWindowLength = timers[mStrength - 1];
    mContinueTimer = mWindowLength;
}

void RPBoxBoxerCombo::onPunchThrow(PunchType punch)
{
    // Combos must be alternating punches
    if (punch == mLastPunchType) reset();
}

void RPBoxBoxerCombo::calc()
{
    mContinueTimer -= 1.0f;
    if (mContinueTimer < 0.0f) mContinueTimer = 0.0f;

    if (mContinueTimer > 0.0f)
    {
        mWindowRemaining = mContinueTimer / mWindowLength;
    }
    else
    {
        mWindowRemaining = 0.0f;
        mStrength = 0;
    }
}

void RPBoxBoxerCombo::onPunchEnd()
{
    reset();
}

void RPBoxBoxerCombo::onRoundStart()
{
    reset();
}

RPBoxBoxerCombo::RPBoxBoxerCombo()
{

}

RPBoxBoxerCombo::~RPBoxBoxerCombo()
{
    
}