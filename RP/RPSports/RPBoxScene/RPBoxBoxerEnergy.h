#ifndef RP_SPORTS_BOX_BOXER_STATUS_H
#define RP_SPORTS_BOX_BOXER_STATUS_H
#include "types_RP.h"

/**
 * @brief State of a boxer's energy
 * 
 * All player objects have energy, which depletes as you whiff punches and/or get blocked.
 * 
 * However, the code that allows the energy to deplete/regen is locked behind scene flags,
 * so the entire feature goes unused.
 * 
 * (Custom name)
 */
class RPBoxBoxerEnergy
{
public:
    enum EnergyState
    {
        ENERGY_NORMAL,
        ENERGY_STUNNED
    };

    enum EnergyFlag
    {
        FLAG_STUNNED = 0x1
    };

    EnergyState mState; // at 0x0
    f32 FLOAT_0x4;
    f32 mEnergy; // at 0x8
    f32 FLOAT_0xC;
    f32 FLOAT_0x10;
    u16 mFlags; // at 0x14

public:
    RPBoxBoxerEnergy(); // 80305e0c
    virtual ~RPBoxBoxerEnergy(); // 80305e1c
    
    bool shouldStun() const; // 80305bcc
    void calcStun(f32 baseRegen, u32 boxerState); // 80305be8
    void calcEnergy(u32 flag, bool resetEnergy); // 80305cc4
};

#endif