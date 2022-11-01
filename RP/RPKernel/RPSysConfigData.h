#ifndef RP_KERNEL_CONFIG_DATA_H
#define RP_KERNEL_CONFIG_DATA_H
#include "types_rp.h"

#include <egg/core/eggSystem.h>

/**
 * @brief Engine configuration data
 * @details Hooks RP engine into EGG's system
 */
class RPSysConfigData : public EGG::ConfigurationData
{
public:
    RPSysConfigData()
    {
        mSystemHeapSize = 0;
    }

    //! @address 80183eb4
    virtual EGG::Video * getVideo() { return mVideo; } // at 0x8
    
    //! @address 80183eac
    virtual EGG::Heap * getSystemHeap() { return mSystemHeap; } // at 0xc
    
    //! @address 80183ebc
    virtual EGG::Display * getDisplay() { return mDisplay; } // at 0x10
    
    //! @address 80183ec4
    virtual EGG::XfbManager * getXfbMgr() { return mXfbMgr; } // at 0x14
    
    //! @address 80183ecc
    virtual EGG::PerformanceView * getPerfView() { return mPerfView; } // at 0x18
    
    //! @address 80183ed4
    virtual EGG::SceneManager * getSceneMgr() { return mSceneMgr; } // at 0x1C
    
    //! @address 80183edc
    virtual EGG::IAudioMgr * getAudioMgr() { return mAudioMgr; } // at 0x20
};

#endif