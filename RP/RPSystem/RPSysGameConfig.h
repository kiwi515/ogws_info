#ifndef RP_SYSTEM_GAME_CONFIG_H
#define RP_SYSTEM_GAME_CONFIG_H
#include "types_RP.h"

#include "RPSysTagParms.h"
#include <types_egg.h>

/**
 * @brief Tag parameter container for the Pack Project Game Config File (gameConfig.ini)
 * 
 * (Name from Wii Fit U)
 */
class RPSysGameConfig : RPSysTagParameters
{
public:
    //! Singleton methods
    static RPSysGameConfig * getInstance() { return sInstance; }
    static RPSysGameConfig * CreateInstance(EGG::Heap *heap); // 801866e0

private:
    RPSysGameConfig(EGG::Heap *heap); // 80186470
    virtual ~RPSysGameConfig(); // 80186430

private:
    //! Heap in which this object was allocated
    EGG::Heap *mParentHeap; // at 0xC
    //! @brief Root scene ("Sports Pack")
    //! I believe this was used to lookup the scene ID in the scene attributes
    RPSysStringTagParm mRootScene; // at 0x10
    //! TV Mode (Aspect ratio)
    RPSysStringTagParm mTVMode; // at 0x20
    //! @brief Language (unused in config file)
    //! I wonder if this was made before RPSysProjectLocal
    RPSysStringTagParm mLanguage; // at 0x30

    /**
     * @brief These options seem to have toggled debug prints
     * for various parts of the RP engine.
     * 
     * Very few are present in Wii Sports's gameConfig,
     * but all except three show up in Wii Fit's file.
     */
    //! "Common print setting"
    RPSysPrimTagParm<int> mRPPrint; // at 0x40
    //! "System print setting"
    RPSysPrimTagParm<int> mRPSysPrint; // at 0x50
    //! "Utility print setting"
    RPSysPrimTagParm<int> mRPUtlPrint; // at 0x60
    //! "Audio print setting"
    RPSysPrimTagParm<int> mRPAudPrint; // at 0x70
    //! "Sound print setting"
    RPSysPrimTagParm<int> mRPSndPrint; // at 0x80
    //! "User print setting"
    RPSysPrimTagParm<int> mRPUserPrint; // at 0x90
    //! Unknown
    RPSysPrimTagParm<int> mRPSmkPrint; // at 0xA0
    //! Unknown
    RPSysPrimTagParm<int> mRPOkaPrint; // at 0xB0
    //! Unknown
    RPSysPrimTagParm<int> mRPOknPrint; // at 0xC0
    //! "Kasamatsu-san print setting"
    RPSysPrimTagParm<int> mRPKasPrint; // at 0xD0
    //! "Mr. Matsutani print setting"
    RPSysPrimTagParm<int> mRPMatPrint; // at 0xE0
    //! "Mr. Sawaya print setting"
    RPSysPrimTagParm<int> mRPSawPrint; // at 0xF0
    //! "Sakakibara-san print setting"
    RPSysPrimTagParm<int> mRPSakPrint; // at 0x100
    //! "Mr. Koda print setting"
    RPSysPrimTagParm<int> mRPKodPrint; // at 0x110
    //! "Mr. Sakaguchi print setting"
    RPSysPrimTagParm<int> mRPGutPrint; // at 0x120
    //! "Sakai-san print setting"
    RPSysPrimTagParm<int> mRPSaiPrint; // at 0x130
    //! "Sumiyoshi print setting"
    RPSysPrimTagParm<int> mRPSumPrint; // at 0x140
    //! "Umemiya-san print setting"
    RPSysPrimTagParm<int> mRPUmePrint; // at 0x150

    //! "Game open setting"
    RPSysPrimTagParm<int> mGameOpen; // at 0x160

    //! Static instance
    static RPSysGameConfig *sInstance; // 804bf4e8
};

#endif