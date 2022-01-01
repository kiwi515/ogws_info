#ifndef RP_KERNEL_SYS_FILE_H
#define RP_KERNEL_SYS_FILE_H
#include "types_rp.h"

#include <nw4r/ut/ut_list.h>
#include <egg/core/eggDisposer.h>

/**
 * @brief Similar to EGG's DvdFile structure,
 * except this class expects the file's data to already have been loaded into RAM.
 * 
 * Paths are relative to the project root, i.e. "Common/Kokeshi/common.carc"
 * 
 * In theory this class could be used for all open files, but the resource manager
 * seems to only use it for archives post-decompression.
 * Perhaps it "simulates" the existence of data only in memory as a file?
 * 
 * This class has an additional ut::Node so that the resource manager can keep track of all open files.
 * It removes itself from the resource manager's file list (at 0x10) on destruction.
 * 
 * (Name from Wii Fit U)
 */
class RPSysFile : EGG::Disposer
{
public:
    RPSysFile(const char *path, int size, const void *data); // 80199678
    virtual ~RPSysFile(); // 80199604

public:
    nw4r::ut::Node mNode; // at 0x10
private:
    char mPath[128]; // at 0x18
    int mSize; // at 0x98
    void *mData; // at 0x9C
};

#endif