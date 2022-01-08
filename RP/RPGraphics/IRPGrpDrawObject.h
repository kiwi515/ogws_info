#ifndef RP_GRAPHICS_I_DRAW_OBJECT_H
#define RP_GRAPHICS_I_DRAW_OBJECT_H
#include "types_RP.h"

/**
 * @brief Interface for renderable objects.
 * The engine's renderer has a linked list of DrawObjects that it traverses through when rendering.
 * 
 * (Name from Wii Fit U)
 */
class IRPGrpDrawObject
{
public:
    virtual ~IRPGrpDrawObject(); // at 0x0
    virtual void UserDraw(); // at 0x4
    virtual void DebugDraw(); // at 0x8
};

#endif