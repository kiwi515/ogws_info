#ifndef RP_SYSTEM_SYS_QUEUED_SCENE_H
#define RP_SYSTEM_SYS_QUEUED_SCENE_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Represents the next scene that will be loaded.
 * 
 * Used commonly by the menu scene to determine whether the player select scene
 * should be in its regular/training/fitness state.
 */
class RPSysQueuedScene
{
public:    
    static RPSysQueuedScene * getInstance() { return sInstance; }

    static RPSysQueuedScene * CreateInstance(EGG::Heap *); // 80187ba0
    void Reset(); // 80187b94

private:
    RPSysQueuedScene(EGG::Heap *heap) : mHeap(heap), mSceneID(-1) {}
    virtual ~RPSysQueuedScene(); // 80187b54

private:
    EGG::Heap *mHeap; // at 0x4
    s32 mSceneID; // at 0x8

    static RPSysQueuedScene *sInstance; // 804bf4f8
};

#endif