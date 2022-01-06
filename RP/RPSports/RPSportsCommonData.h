#ifndef RP_SPORTS_COMMON_DATA_H
#define RP_SPORTS_COMMON_DATA_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Common data in the RPSports save file
 * This includes everything that isn't tied to a specific player
 * 
 * NOTE: Not a packed structure, this is an abstraction of the binary format
 * 
 * (Custom name, derived from some Wii Fit U symbols)
 */
class RPSportsCommonData
{
public:
    /**
     * @brief Structure used to allow players' Miis to be automatically selected.
     * 
     * The Mii's player list index is kept alongside information identifying the remote used,
     * so that Mii can be chosen automatically when applicable.
     */
    struct MiiHistory
    {
        //! @brief Previously selected Mii (Index into player list)
        //! -1 if unused
        s8 mPrevMiiIdx; // at 0x0

        //! @brief Set by WPADGetRadioSensitivity
        //! Used to identify the remote previously used
        u8 mRadioSensitivity[6]; // at 0x1
    };

    /**
     * @brief Indices for the common save data bitfield
     * 
     * Must be used with getTrainingUnlock, or getBitFlag(15 + bit)
     */
    enum ETrainingBits
    {
        // Throwing Punches
        BIT_BOX_MITUCHI,
        // Dodging
        BIT_BOX_TAMAYOKE,
        // Working the Bag
        BIT_BOX_SANDBAG,

        // Target Practice
        BIT_GOL_TARGET,
        // Hitting the Green
        BIT_GOL_NEARPIN,
        // Putting
        BIT_GOL_ONEPAT,

        // Spin Control
        BIT_BOW_GATETOSHI,
        // Power Throws
        BIT_BOW_NAGITAOSHI,
        // Picking Up Spares
        BIT_BOW_SPAREGET,

        // Batting Practice
        BIT_BSB_RENZOKU,
        // Swing Control
        BIT_BSB_UCHIWAKE,
        // Hitting Home Runs
        BIT_BSB_HOMERUN,

        // Target Practice
        BIT_TNS_KABEUCHI,
        // Timing Your Swing
        BIT_TNS_NERAUCHII,
        // Returning Balls
        BIT_TNS_RENZOKU,
    };

public:
    RPSportsCommonData(); // 8018ad34

    //! For serialization (From WFU)
    void write(EGG::RamStream *stream) const; // 8018a90c
    void read(EGG::RamStream *stream); // 8018a9d0

    //! Access Mii history
    void getMiiHistory(s8 *miiIdxOut, u8 *radioSensOut, u32 numPlayers, u32 playerIdx) const; // 8018abe0
    void setMiiHistory(const s8 *miiIdx, const u8 *radioSens, u32 numPlayers, u32 playerIdx); // 8018ab60

    //! Access training bits in bitfield
    bool getTrainingUnlock(u8 i) const; // 8018aa90
    bool setTrainingUnlock(u8 i, bool val); // 8018aab8

    //! Access any bit in bitfield
    bool getBitFlag(u8 i) const; // 8018aaf0
    bool setBitFlag(u8 i, bool val); // 8018ab10

    //! Access last fitness test time (RPCalendarTime16)
    u16 getLastFitnessTestTime() const; // 8018ab40
    void setLastFitnessTestTime(u16 time); // 8018ab40

    //! Access number of total fitness tests
    u8 getTotalFitnessTests() const; // 8018ab50
    void setTotalFitnessTests(u8 num); // 8018ab58

    //! Reset all data (From WFU)
    void reset(); // 8018ac64

private:
    //! Mii History for every possible amount of players
    MiiHistory mHistory[1 + 2 + 3 + 4]; // at 0x0

    //! Used for the Wii Message Board
    u8 mTotalFitnessTests; // at 0x46
    u16 mLastFitnessTestTime; // at 0x48

    u16 SHORT_0x4A;
    u8 BYTE_0x4C;

    //! Common save data bitfield, used primarily for training games
    u32 mBitfield;

    u32 WORD_0x54;
};

#endif