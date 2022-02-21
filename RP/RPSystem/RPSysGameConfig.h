#ifndef RP_SYSTEM_GAME_CONFIG_H
#define RP_SYSTEM_GAME_CONFIG_H
#include "types_RP.h"

#include "RPSysTagParms.h"
#include <types_egg.h>

/**
 * @brief Tag parameter container for the Pack Project Game Config File (`gameConfig.ini`)
 * @details Likely only exists in the binary because CreateInstance is called by RPSysSystem
 * @wfuname
 */
class RPSysGameConfig : RPSysTagParameters
{
public:
    static RPSysGameConfig * getInstance() { return sInstance; }
    //! @address 801866e0
    static RPSysGameConfig * CreateInstance(EGG::Heap *heap);

private:
    //! @address 80186470
    RPSysGameConfig(EGG::Heap *heap);
    //! @address 80186430
    virtual ~RPSysGameConfig();

private:
    //! Heap in which this object was allocated
    EGG::Heap *mParentHeap; // at 0xC
    //! Root scene, possibly used by the stripped `RPSysSceneCreator::getSceneID(const char *)`
    RPSysStringTagParm mRootScene; // at 0x10
    //! TV Mode (Aspect ratio)
    RPSysStringTagParm mTVMode; // at 0x20
    //! Language; unused in .ini, likely predates language support in RPSysProjectLocal
    RPSysStringTagParm mLanguage; // at 0x30
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

    /**
     * Static instance
     * @address 804bf4e8
     */
    static RPSysGameConfig *sInstance;
};

#endif