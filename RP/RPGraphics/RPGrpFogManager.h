#ifndef RP_GRAPHICS_FOG_MANAGER_H
#define RP_GRAPHICS_FOG_MANAGER_H
#include "types_RP.h"

#include <egg/gfx/eggFogManager.h>

/**
 * @brief RP engine fog manager
 * 
 * (Name from Wii Fit U)
 */
class RPGrpFogManager : EGG::FogManager
{
public:
    RPGrpFogManager() {}
    virtual ~RPGrpFogManager() {} // 801b2424
};

#endif