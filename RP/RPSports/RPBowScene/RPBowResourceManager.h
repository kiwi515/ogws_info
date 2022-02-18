#ifndef RP_SPORTS_BOW_RESOURCE_MANAGER_H
#define RP_SPORTS_BOW_RESOURCE_MANAGER_H
#include "types_RP.h"
#include "IRPSysHostIOSocket.h"

/**
 * @brief Bowling scene resource manager
 */
class RPBowResourceManager : IRPSysHostIOSocket
{
public:
    //! @address 80320ea4
    static void CreateInstance();
    //! @address 80320e60
    static void DestroyInstance();
    static RPBowResourceManager * GetInstance() { return sInstance; }

    RPBowResourceManager() : mExcelGlobal(NULL) {}
    //! @address 80320da8
    virtual ~RPBowResourceManager();

    /**
     * Sets up all bowling resources
     * @address 80320e00
     */
    void LoadResource();
    /**
     * Get specified file from the scene common archive
     * @address 80320d9c
     */
    void * GetFileFromCmnArchive(const char *path);

private:
    //! EXBIN globals (`BowExcelGlobal.bin`)
    void *mExcelGlobal; // at 0x0
    //! Scene common archive
    void *mCmnArchive; // at 0x4
    //! Scene local archive
    void *mLocalArchive; // at 0x8

    /**
     * Static instance
     * @address 804bf9a8
     */
    static RPBowResourceManager * sInstance;
};

#endif