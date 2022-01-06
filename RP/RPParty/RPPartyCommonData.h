#ifndef RP_PARTY_COMMON_DATA_H
#define RP_PARTY_COMMON_DATA_H
#include "types_rp.h"

#include <types_egg.h>

/**
 * @brief Common data in the RPParty save file
 * This includes everything that isn't tied to a specific player
 * 
 * NOTE: Not a packed structure, this is an abstraction of the binary format
 * 
 * (Custom name, derived from some Wii Fit U symbols)
 */
class RPPartyCommonData
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
     * @brief Bit indices for the game unlock bitfield
     */
    enum EGameUnlock
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
    };

    /**
     * @brief Bit indices for the dialog seen bitfield
     */
    enum EDialogSeen
    {
        //! Seen when game is played for first time
        DIALOG_WELCOME,
        //! Seen when stage two is unlocked
        DIALOG_STAGE_TWO,
        //! Seen when stage three is unlocked
        DIALOG_STAGE_THREE,
        //! Seen when stage four is unlocked
        DIALOG_STAGE_FOUR,
        //! Seen when stage five is unlocked
        DIALOG_STAGE_FIVE,
        //! Seen when stage six is unlocked
        DIALOG_STAGE_SIX,
        //! Seen when stage seven is unlocked
        DIALOG_STAGE_SEVEN,
        //! Seen when stage eight is unlocked
        DIALOG_STAGE_EIGHT,
        //! Seen when final stage is unlocked
        DIALOG_FINAL_STAGE,
        //! Seen when all stages are completed
        DIALOG_WII_REMOTE_MASTER,
    };

public:
    //! Check if a game has been unlocked
    bool isGameUnlock(u32 id) const; // 8018d6ac

private:
    //! Mii History for every possible amount of players
    MiiHistory mHistory[1 + 2]; // at 0x0
    //! @brief Number of players added to the player list on the current date
    //! Why is this counted?
    u8 mAddedPlayersToday; // at 0x15
    //! @brief Date last player was added to player list
    //! Used to increment mAddedPlayersToday.
    RPTime16 mLastDatePlayerAdded; // at 0x16
    //! Bitfield marking games as unlocked
    u32 mGameUnlockBitfield; // at 0x18
    //! Bitfield marking dialog windows as seen
    u32 mDialogSeenBitfield; // at 0x1C
};

#endif