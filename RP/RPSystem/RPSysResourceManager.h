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
    static RPSysResourceManager * CreateInstance(); // 80187ae8
    static RPSysResourceManager * GetInstance() { return sInstance; }

    static void * GetMessageResource(const char *path); // 8018783c
    static void GetFileFromArchive(EGG::Archive *arc, const char *path, u32 *sizeOut); // 80187878
    static EGG::Archive * LoadGameStageArchive(const char *path); // 801878c4
    static EGG::Archive * LoadGameLocalArchive(int sceneID, EGG::Heap *heap); // 80187964
    static EGG::Archive * LoadGameCommonArchive(int sceneID, EGG::Heap *heap); // 80187a0c

    void * LoadFromDVD(const char *path, EGG::Heap *heap, int allocDir, int *sizeOut); // 80186eb4
    void * LoadCompressed(const char *path, EGG::Heap *heap); // 80186fa0
    EGG::Archive * LoadGameLocalArchive(const char *staticDir); // 801871f4
    void GetGameSoundLocalPath(char *bufOut, u32 bufSize, int sceneID); // 80187290
    void GetGameSoundCommonPath(char *bufOut, u32 bufSize, int sceneID); // 80187300
    void GetStaticSoundLocalPath(char *bufOut, u32 bufSize); // 8018736c
    void GetStaticSoundCommonPath(char *bufOut, u32 bufSize); // 801873e8
    void LoadKokeshiArchive(); // 8018744c
    void LoadSharedCommonArchive(); // 801874b4
    void LoadCacheArchives(); // 80187604
    void RemoveFromFileList(RPSysFile *file); // 801877d4
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

    static RPSysResourceManager *sInstance; // 804bf4f0
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