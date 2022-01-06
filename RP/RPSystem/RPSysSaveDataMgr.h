#ifndef RP_SYSTEM_SYS_SAVE_DATA_MGR_H
#define RP_SYSTEM_SYS_SAVE_DATA_MGR_H
#include "types_RP.h"

#include "IRPSysHostIOSocket.h"
#include "RPSportsCommonData.h"
#include "RPSportsPlayerData.h"
#include "RPPartyCommonData.h"
#include "RPPartyPlayerData.h"
#include <types_egg.h>

/**
 * @brief RP engine save data manager
 * 
 * Alongside the main save data class, the manager also seems to
 * have some behavior set at compile-time based on the pack ID.
 * 
 * Additionally, because this class supports multiple packs,
 * there exists code to support Wii Play save data, which was not stripped
 * because of the player select scene (runtime localization).
 * 
 * (Name from Wii Fit U, most function names also from Wii Fit U)
 */
class RPSysSaveDataMgr : IRPSysHostIOSocket
{
public:
    /**
     * @brief Banner files that can be created
     */
    enum EBannerType
    {
        BANNER_REAL, // banner.bin
        BANNER_TEMP  // /tmp/banner.bin
    };

    /**
     * @brief Status flags
     */
    enum EStatusFlag
    {
        NAND_MEMORY_EXIST = (1 << 0),
        BANNER_EXIST = (1 << 1),
        SAVE_EXIST = (1 << 2),
        DISABLE_SAVING = (1 << 4),
        NAND_ACCESS_ONGOING = (1 << 8),
        WRITE_TASK_ONGOING = (1 << 9)
    };

public:
    //! Singleton methods
    static RPSysSaveDataMgr * CreateInstance(EGG::Heap *heap); // 8018a8a4
    static RPSysSaveDataMgr * getInstance() { return sInstance; }

    //! @brief Write both save and banner files
    //! Used asynchronously through task threads
    static void saveDataFunc(); // 801884f0
    //! @brief Read save file
    //! Used asynchronously through task threads
    static void loadDataFunc(); // 80188520
    //! @brief Create NAND entries for both save/banner
    //! Used asynchronously through task threads
    static void createPackFileFunc(); // 80188528
    //! @brief Check if the NAND has enough free space
    //! Used asynchronously through task threads
    static void existNandMemoryFunc(); // 801885c0
    //! @brief Validate that both the save/banner exist by checking their filetype
    //! Used asynchronously through task threads
    static void existPackFileFunc(); // 801885c8

    //! @brief Write banner file to NAND
    //! Caller can choose between temp/real file
    void saveBanner(u32 bannerType); // 801886ac
    //! Read NAND save data into mRawSaveFile, then construct mRPSaveFile
    void loadSync(); // 8018877c
    //! @brief Write mRPSaveFile into mRawSaveFile,
    //! then write the raw contents to the NAND save
    void saveSync(); // 80188868
    //! Create temp banner file on NAND (/tmp/banner.bin)
    void createBannerFile(); // 8018895c
    //! Check if the NAND has enough free space
    void existNandMemorySync(); // 80188a60
    //! @brief Display "Continue without saving?" message when applicable,
    //! and handle the player's yes/no choice
    void continueNoSaveProc(); // 80188b04
    //! @brief Constructs banner.bin inside mBannerBin
    //! TPL exists on disc and text comes from the BMG
    void buildBannerBin(); // 80188bd4
    //! @brief Displays "Unable to save" message when applicable,
    //! then hands off to continueNoSaveProc
    void unableToSaveProc(); // 80188d60
    //! Finishes NAND access by clearing the flag
    void finishNandAccess(); // 80188e54

    //! @brief How many empty NAND blocks the game requires
    //! Constant value set to 2 (250kb)
    u32 getUserBlockSize() const; // 80188e6c
    //! @brief How many empty NAND blocks the game requires
    //! Calculated dynamically from the save file size
    //! Still yields same result (2 blocks)
    u32 calcUserBlockSize() const; // 80188e6c

    //! NAND error code
    s32 getErrorCode() const; // 80188e8c
    //! NAND check answer
    u32 getNandCheckAnswer() const; // 80188e94
    
    //! Toggle ability to save
    void setSaveDisable(bool disable); // 80188e9c

    //! Manager save data validity
    bool isSaveFileBroken() const; // 80188ec4
    //! Save data class validity (typo)
    bool isErrorOccured() const; // 80188efc
    //! Is there enough free memory on the NAND for the save file?
    bool isNandMemoryExist() const; // 80188f04
    //! Do the banner/save files exist?
    bool isPackFileExist() const; // 80188f10
    //! Is the manager currently done with the NAND?
    bool isNandAccessDone() const; // 80188f30
    //! Check for NAND access/write task
    bool isIdle() const; // 80188f44

    //! @brief Requests saveDataFunc on the NAND thread
    //! Returns whether the task request was successful
    bool saveAsync(); // 80188f64
    //! @brief Requests loadDataFunc on the NAND thread
    //! Returns whether the task request was successful
    bool loadAsync(); // 80189040

    //! Attempts to write save/banner files if the scene is idle
    bool writePackFileSync(); // 801890e0
    //! Attempts to delete save/banner files if the scene is idle
    bool deletePackFileSync(); // 8018915c

    //! @brief Tries to create the banner/save files asynchronously, by using the NAND thread
    //! Returns whether the task request was successful
    bool createPackFileAsync(); // 80189234
    //! @brief Asynchronously checks if the NAND has enough space for the save file, by using the NAND thread
    //! Returns whether the task request was successful
    bool existNandMemoryAsync(); // 801892d4
    //! @brief Asynchronously checks if the banner/save files exist on the NAND
    //! Returns whether the task request was successful
    bool existPackFileAsync(); // 80189374
    //! @brief Checks if the banner/save files exist on the NAND
    bool existPackFileSync(); // 80189414

    //! Wii Play common save data
    RPPartyCommonData getPartyCommonData() const; // 80189534

    //! Wii Play player list save data
    void setPartyPlayerData(const RPPartyPlayerData *playerData, u32 id); // 8018962c
    RPPartyPlayerData getPartyPlayerData(u32 id) const; // 80189720

    //! Wii Sports common save data
    void setSportsCommonData(const RPSportsCommonData *cmnData); // 80189820
    RPSportsCommonData getSportsCommonData() const; // 80189c10

    //! Wii Sports player list save data
    void setSportsPlayerData(const RPSportsPlayerData *playerData, u32 id); // 80189ea0
    RPSportsPlayerData getSportsPlayerData(u32 id) const; // 8018a39c

private:
    RPSysSaveDataMgr(EGG::Heap *heap); // 801883c0
    virtual ~RPSysSaveDataMgr(); // 80188368

private:
    //! The Heap which contains this object
    EGG::Heap *mParentHeap; // at 0x4
    //! Flags regarding the manager's status
    u32 mStatus; // at 0x8
    //! Most recent NAND error code
    s32 mNandErrorCode; // at 0xC
    UNKWORD WORD_0x10;
    //! NAND check answer
    u32 mNandCheckAnswer; // at 0x14
    //! Size of the raw save file (RPSports.dat)
    u32 mSaveFileSize; // at 0x18
    //! Banner.bin size (hardcoded 0x72a0)
    u32 mBannerBinSize; // at 0x1C
    //! @brief Save file size aligned some way
    //! Used to calculate no. of empty blocks needed
    UNKWORD INT_0x20;
    //! @brief Banner.bin contents
    //! This buffer is strangely a bit larger than mBannerBinSize
    void *mBannerBin; // at 0x24
    //! Raw save file data (RPSports.dat)
    void *mRawSaveFile; // at 0x28
    //! RP save file class
    RPSysSaveData *mRPSaveFile; // at 0x2C

    //! Static instance
    static RPSysSaveDataMgr *sInstance; // 804bf508
};

#endif