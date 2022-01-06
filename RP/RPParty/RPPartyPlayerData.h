#ifndef RP_PARTY_PLAYER_DATA_H
#define RP_PARTY_PLAYER_DATA_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Save data pertaining to a player in the player list in Wii Play
 * 
 * NOTE: Not a packed structure, this is an abstraction of the binary format
 * 
 * (Custom name, derived from some Wii Fit U symbols)
 */
class RPPartyPlayerData
{
public:
    /**
     * @brief For mFlags
     */
    enum EPlayerFlag
    {
        FLAG_ON_PLAYER_LIST = (1 << 1)
    };

    /**
     * @brief Bit indices for the game unlock bitfield
     */
    enum EGameID
    {
        //! Shooting Range
        GAME_DUC,
        //! Find Mii
        GAME_WLY,
        //! Table Tennis
        GAME_PNP,
        //! Pose Mii
        GAME_BOM,
        //! Laser Hockey
        GAME_HKY,
        //! Billiards
        GAME_BIL,
        //! Fishing
        GAME_FSH,
        //! Charge!
        GAME_COW,
        //! Tanks!
        GAME_TNK,

        GAME_MAX
    };

    /**
     * @brief Cutscene IDs for mCutscenesSeen
     */
    enum ECutsceneID
    {
        CUTSCENE_0,
        CUTSCENE_ALL_BRONZE,
        CUTSCENE_ALL_SILVER,
        CUTSCENE_ALL_GOLD,
        CUTSCENE_ALL_PLATINUM,
    };

public:
    //! Player list debut time
    void setDebutTime(RPTime32 time); // 8018d6d0
    RPTime32 getDebutTime() const; // 8018d6d8

    //! Mii unique ID
    void setUniqueID(const u8* id); // 8018d6e0
    void getUniqueID(u8 *idOut) const; // 8018d724

    //! Player list flag
    void setOnPlayerList(bool onList); // 8018d768
    bool isOnPlayerList() const; // 8018d790

    //! Reset all data (From WFU)
    void reset(); // 8018d79c

private:
    //! Length of high score list
    static const u32 NUM_SCORES = 5;
    
    //! Player list entry flags
    u32 mFlags; // at 0x0
    //! Mii unique ID
    u8 mUniqueID[8]; // at 0x4
    //! @brief Time player was added to the player list
    //! (referred to as their debut on the message board)
    RPTime32 mDebutTime; // at 0xC
    //! Top 5 scores in each game
    s32 mTopScores[GAME_MAX][NUM_SCORES]; // at 0x10
    //! Player's medal in every game
    u8 mMedals[GAME_MAX]; // at 0xC4
    //! Bitfield marking medal cutscenes as seen
    u8 mCutscenesSeen; // at 0xCD
};

#endif