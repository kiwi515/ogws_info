#ifndef RP_SYS_SAVE_DATA_H
#define RP_SYS_SAVE_DATA_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Structure to hold RP engine save data
 * 
 * While this structure is generic and can support multiple Pack Project games,
 * it seems that its behavior is set at compile time (along with getFileSize),
 * rather than using RPSysProjectLocal.
 * 
 * (Custom name, derived from some Wii Fit U symbols)
 */
class RPSysSaveData
{
public:
    /**
     * @brief Potential errors in the save data
     */
    enum ESaveError
    {
        SAVE_NO_HI_MAGIC = (1 << 0),
        SAVE_NO_LO_MAGIC = (1 << 1),
        SAVE_BAD_CHECKSUM = (1 << 2)
    };

public:
    //! Total size of raw save file
    static u32 getFileSize(); // 8018bf54

    RPSysSaveData(); // 8018ad34

    //! @brief For serialization (From WFU)
    //! Raw save is needed to calculate checksum
    void write(EGG::RamStream *stream, const void *rawSave) const; // 8018ad70
    void read(EGG::RamStream *stream, const void *rawSave); // 8018b0e4

    //! Wii Play common save data
    RPPartyCommonData *getPartyCommonData() const; // 8018c32c

    //! Wii Play player list data
    void setPartyPlayerData(const RPPartyPlayerData *playerData, u32 id); // 8018c334
    RPPartyPlayerData *getPartyPlayerData(u32 id) const; // 8018c40c

    //! Wii Sports common data
    void setSportsCommonData(const RPSportsCommonData *cmnData); // 8018c41c
    RPSportsCommonData *getSportsCommonData() const; // 8018c684

    //! Wii Sports player list data
    void setSportsPlayerData(const RPSportsPlayerData *playerData, u32 id); // 8018c68c
    RPSportsPlayerData *getSportsPlayerData(u32 id) const; // 8018cb6c

    //! Save data validity (typo)
    bool isErrorOccured() const; // 8018cb7c

private:
    //! Flags regarding the status of the data
    u32 mErrors; // at 0x0
    //! Wii Sports common save data
    RPSportsCommonData *mSportsCmnData; // at 0x4
    //! Wii Sports player list (100 entries)
    RPSportsPlayerData *mSportsPlayerList; // at 0x8
    //! Wii Play common save data
    RPPartyCommonData *mPartyCmnData; // at 0xC
    //! Wii Play player list (100 entries)
    RPPartyPlayerData *mPartyPlayerList; // at 0x10

    // TO-DO: Other Pack Project game saves?
    UNKWORD WORD_0x14;
    UNKWORD WORD_0x18;
    UNKWORD WORD_0x1C;
    UNKWORD WORD_0x20;
    UNKWORD WORD_0x24;
};

#endif