#ifndef RP_SYSTEM_DVD_STATUS_H
#define RP_SYSTEM_DVD_STATUS_H
#include "types_rp.h"

#include <egg/core/eggHeap.h>
#include <egg/core/eggColorFader.h>

/**
 * @brief Current status/error of the DVD
 * 
 * Extremely similar to EGG's DvdStatus, but seems to be a re-implementation (missing Disposer inheritance).
 * Additionally, EGG's version does not exist in OGWS.
 * 
 * (Class name from Wii Fit U, and most member names from EGG)
 */
class RPSysDvdStatus
{
public:
    enum EDvdStatus
    {
        DVD_IDLE = -2,
        DVD_READING,
        DVD_DISC_REMOVED,
        DVD_CANNOT_READ,
        DVD_FATAL_ERROR
    };

public:
    static RPSysDvdStatus * CreateInstance(EGG::Heap *heap); // 80188280
    static RPSysDvdStatus * getInstance() { return sInstance; }

    void draw(); // 80187fa4
    void update(); // 8018818c
    //! Typo
    bool isErrorOccured(); // 80188260

private:
    RPSysDvdStatus(EGG::Heap *heap) : mParentHeap(heap), mErrorStatus(DVD_IDLE)
    {
        mErrorMessage = new char[256];

        mErrorFader = new EGG::ColorFader(0.0f, 0.0f, 640.0f, 456.0f,
            nw4r::ut::Color(0), EGG::ColorFader::STATUS_PREPARE_IN);

        // Maybe the status in the constructor is a defualt argument?
        mErrorFader->setStatus(EGG::ColorFader::STATUS_PREPARE_IN);
    }
    virtual ~RPSysDvdStatus(); // 80187f64

private:
    EGG::Heap *mParentHeap; // at 0x4
    s32 mErrorStatus; // at 0x8
    const char *mErrorMessage; // at 0xC
    EGG::ColorFader *mErrorFader; // at 0x10

    static RPSysDvdStatus *sInstance; // 804bf500
};

#endif