#ifndef RP_KERNEL_LYT_ALLOCATOR_H
#define RP_KERNEL_LYT_ALLOCATOR_H
#include "types_RP.h"

#include <egg/core/eggAllocator.h>

/**
 * @brief Wrapper for EGG's Allocator for use with layouts
 * 
 * (Name from Wii Fit U)
 */
class RPSysLytAllocator : EGG::Allocator
{
public:
    RPSysLytAllocator(EGG::Heap *heap, s32 r5); // 8019e434
    virtual ~RPSysLytAllocator(); // 8019e3dc

private:
    //! @brief Alloc/free funcs
    //! Inherited func pointers are overwritten to point here
    MEMAllocatorFuncs mFuncs; // at 0x14
};

//! Layout allocator free func (alloc func is carried over from the inherited Allocator)
static void FreeMemory(MEMAllocator *allocator, void *mem); // 8019e490

#endif