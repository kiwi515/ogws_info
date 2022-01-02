#ifndef RP_SYSTEM_SYS_PROJECT_LOCAL_H
#define RP_SYSTEM_SYS_PROJECT_LOCAL_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Offers support for runtime localization with values that can be set at compile time.
 * Utilized for everything from regional files, formatting date/time, singular numbers, number system, and more.
 */
class RPSysProjectLocal
{
public:
    enum ENumberSystem
    {
        RP_NUMSYS_0,
        RP_NUMSYS_1,
    };

    enum EPackID
    {
        RP_SPORTS_PACK,
        RP_PARTY_PACK,
        RP_HEALTH_PACK,
        RP_MUSIC_PACK,
        RP_ALLPACK
    };

    // Used for both locale and language
    enum ERegion
    {
        RP_ENGLISH_GB,
        RP_FRENCH,
        RP_GERMAN,
        RP_ITALIAN,
        RP_SPANISH,
        RP_ENGLISH_NL,
        RP_JAPANESE,
        RP_ENGLISH_US
    };

    enum EStorage
    {
        RP_STORAGE_MEM,
        RP_STORAGE_NAND,
        RP_STORAGE_DVD,
    };

public:
    static RPSysProjectLocal * CreateInstance(EGG::Heap *heap); // 801863a4
    static RPSysProjectLocal * getInstance() { return sInstance; }

    void setLanguage(u32 lang); // 80186234
    void setLocale(u32 locale); // 8018623c
    void appendLocalDirectory(char *, const char *); // 80186244

private:
    RPSysProjectLocal(EGG::Heap *heap) : mParentHeap(heap), mNumberSystem(RP_NUMSYS_1), mPackID(RP_SPORTS_PACK),
        mLocale(RP_ENGLISH_US), mLanguage(RP_ENGLISH_US), WORD_0x18(0), mSndStorage(RP_STORAGE_MEM) {}
    virtual ~RPSysProjectLocal(); // 80186364

    EGG::Heap *mParentHeap; // at 0x4
    //! @brief Primarily for formatting decimal numbers (dot vs comma)
    u32 mNumberSystem; // at 0x8
    //! @brief Pack Project game ID
    u32 mPackID; // at 0xC
    //! @brief Controls what directory is used for regional files, etc.
    u32 mLocale; // at 0x10
    //! @brief Seems to be unused, set alongside locale
    u32 mLanguage; // at 0x14
    //! @brief Audio related, only used by code leftover from Wii Play
    UNKWORD WORD_0x18;
    //! @brief Where audio archives are stored (DVD, NAND, etc.)
    //! Only used by openArchiveRP
    u32 mSndStorage;

    static RPSysProjectLocal *sInstance; // 804bf4e0
};

#endif