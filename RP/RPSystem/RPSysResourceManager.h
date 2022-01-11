#ifndef RP_SYSTEM_RESOURCE_MANAGER_H
#define RP_SYSTEM_RESOURCE_MANAGER_H
#include "types_rp.h"

#include "RPSysFile.h"
#include "RPSysSceneCreator.h"
#include <egg/core/eggHeap.h>
#include <nw4r/ut/ut_list.h>

/**
 * @brief Engine resource manager
 * 
 * Responsible for pretty much all file loads from the disc,
 * and also serves as a utility for building scene/pack relative paths to files.
 * 
 * (Name from Wii Fit U)
 */
class RPSysResourceManager
{
public:
    //! Singleton methods
    static RPSysResourceManager * CreateInstance(); // 80187ae8
    static RPSysResourceManager * GetInstance() { return sInstance; }

    //! Open binary message (BMG) file
    static void * GetMessageResource(const char *path); // 8018783c
    //! Get file from EGG archive (optionally get file size)
    static void * GetFileFromArchive(EGG::Archive *arc, const char *path, u32 *sizeOut); // 80187878
    //! Load archive from current scene's Stage directory
    static EGG::Archive * LoadGameStageArchive(const char *path); // 801878c4
    //! Load local archive (local.carc) for the specified scene
    static EGG::Archive * LoadGameLocalArchive(int sceneID, EGG::Heap *heap); // 80187964
    //! Load common archive (common.carc) for the specified scene
    static EGG::Archive * LoadGameCommonArchive(int sceneID, EGG::Heap *heap); // 80187a0c

    //! Load file from DVD (optionally get file size)
    void * LoadFromDVD(const char *path, EGG::Heap *heap, int allocDir, int *sizeOut); // 80186eb4
    //! Load and decompress file
    void * LoadCompressed(const char *path, EGG::Heap *heap); // 80186fa0
    //! Load local archive in specified directory
    EGG::Archive * LoadLocalArchive(const char *dir); // 801871f4
    //! Get local sound path of specified scene
    void GetGameSoundLocalPath(char *bufOut, u32 bufSize, int sceneID); // 80187290
    //! Get common sound path of specified scene
    void GetGameSoundCommonPath(char *bufOut, u32 bufSize, int sceneID); // 80187300
    //! Get local sound path of current pack's static directory
    void GetStaticSoundLocalPath(char *bufOut, u32 bufSize); // 8018736c
    //! Get common sound path of current pack's static directory
    void GetStaticSoundCommonPath(char *bufOut, u32 bufSize); // 801873e8
    //! Load Mii resources (kokeshi.carc)
    void LoadKokeshiArchive(); // 8018744c
    //! Load static common archive
    void LoadSharedCommonArchive(); // 801874b4
    //! Load cached archives (font, BMG, static common)
    void LoadCacheArchives(); // 80187604
    //! Remove file from file list
    void RemoveFromFileList(RPSysFile *file); // 801877d4
    //! Load sound archive
    bool LoadSoundArchive(const char *path); // 801877dc

private:
    RPSysResourceManager()
    {
        nw4r::ut::List_Init(&LIST_0x4, offsetof(RPSysFile, mNode));
        nw4r::ut::List_Init(&mFileList, offsetof(RPSysFile, mNode));
        mPath = new char[128];
    }
    virtual ~RPSysResourceManager(); // 80187aa8

    nw4r::ut::List LIST_0x4;
    nw4r::ut::List mFileList; // at 0x10
    char *mPath; // at 0x1C
    EGG::Archive *mKokeshiArc; // at 0x20
    EGG::Archive *mMessageArc; // at 0x24
    EGG::Archive *mFontArc; // at 0x28
    EGG::Archive *mGameCommonArc; // at 0x2C
    EGG::Archive *mGameLocalArc; // at 0x30
    UNKWORD WORD_0x34;
    UNKTYPE *PTR_0x38;
    UNKWORD WORD_0x3C;

    //! Static instance
    static RPSysResourceManager *sInstance; // 804bf4f0
    //! Pack Project static paths
    static const char *sPackStaticPaths[4]; // 803b9850
};

const char *RPSysResourceManager::sPackStaticPaths[4] = 
{
    "SportsStatic/", // Wii Sports
    "PartyStatic/",  // Wii Play
    "HealthStatic/", // Wii Fit
    "MusicStatic/"   // Wii Music
};

#endif