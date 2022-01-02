#ifndef RP_SYSTEM_SYS_QUEUED_SCENE_H
#define RP_SYSTEM_SYS_QUEUED_SCENE_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Represents the next scene that will be loaded.
 * 
 * Used commonly by the menu scene to determine whether the player select scene
 * should be in its regular/training/fitness state.
 * 
 * (Custom name)
 */
class RPSysQueuedScene
{
public:    
    static RPSysQueuedScene * CreateInstance(EGG::Heap *heap); // 80187ba0
    static RPSysQueuedScene * getInstance() { return sInstance; }

    void Reset(); // 80187b94

private:
    RPSysQueuedScene(EGG::Heap *heap) : mParentHeap(heap), mSceneID(-1) {}
    virtual ~RPSysQueuedScene(); // 80187b54

private:
    EGG::Heap *mParentHeap; // at 0x4
    //! @brief ID of queued scene
    s32 mSceneID; // at 0x8

    static RPSysQueuedScene *sInstance; // 804bf4f8
};

#endif