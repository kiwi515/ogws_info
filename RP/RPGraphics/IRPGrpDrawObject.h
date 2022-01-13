#ifndef RP_GRAPHICS_I_DRAW_OBJECT_H
#define RP_GRAPHICS_I_DRAW_OBJECT_H
#include "types_RP.h"

/**
 * @brief Linked-list interface for renderable objects.
 * The engine's renderer has a linked list of DrawObjects that it traverses through when rendering.
 * 
 * (Name from Wii Fit U)
 */
class IRPGrpDrawObject
{
private:
    IRPGrpDrawObject *mNext; // at 0x0

public:
    IRPGrpDrawObject() : mNext(NULL) {}
    virtual ~IRPGrpDrawObject() {} // at 0x4
    virtual void UserDraw() {} // at 0x8
    virtual void DebugDraw() {} // at 0xC
};

#endif