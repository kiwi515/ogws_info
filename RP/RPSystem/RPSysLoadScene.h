#ifndef RP_SYSTEM_LOAD_SCENE_H
#define RP_SYSTEM_LOAD_SCENE_H
#include "types_rp.h"

/**
 * @brief Seems to "queue" up the next scene to load.
 * 
 * Used commonly by the menu scene to determine whether the player select scene
 * should be in its regular/training/fitness state.
 * 
 * Name from Wii Fit U
 */
class RPSysLoadScene
{
public:    
    static RPSysLoadScene * getInstance() { return sInstance; }

    static RPSysLoadScene * CreateInstance(EGG::Heap *); // 80187ba0
    void Reset(); // 80187b94

private:
    RPSysLoadScene(EGG::Heap *heap) : mHeap(heap), mNextSceneID(-1) {}
    virtual ~RPSysLoadScene(); // 80187b54

private:
    EGG::Heap *mHeap; // at 0x4
    s32 mNextSceneID; // at 0x8

    static RPSysLoadScene *sInstance; // 804bf4f8
};

#endif