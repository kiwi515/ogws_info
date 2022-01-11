#ifndef RP_SYSTEM_SCENE_MGR_H
#define RP_SYSTEM_SCENE_MGR_H
#include "types_RP.h"

#include "RPSysSystem.h"
#include <egg/core/eggSceneManager.h>
#include <egg/core/eggColorFader.h>

/**
 * @brief RP engine scene manager
 * 
 * Inherits from EGG's SceneManager, while adding some functionality
 * to make scene changes easier for the programmer.
 * 
 * Additionally, this class has another ColorFader, which gets purposed for the current scene.
 * The inherited fader is referred to as the "manager fader" and is used to fade in/out the entire game graphics.
 */
class RPSysSceneMgr : EGG::SceneManager
{
public:
    /**
     * @brief States of the scene manager
     */
    enum EState
    {
        STATE_NORMAL,
        STATE_PAUSED,
        STATE_SOFT_RESET,
        //! These don't seem to be different
        STATE_RETURN_TO_MENU,
        STATE_RETURN_TO_MENU_2
    };

public:
    //! State logic
    void updateState(); // 801856d0
    //! Update scene
    void calcCurrentScene(); // 80185868
    //! Draw faders
    void drawMgrFader(); // 8018589c
    void drawSceneFader(); // 801858b0
    //! Update scene fader
    void calcSceneFader(); // 801858c4
    //! @brief If the scene can be changed
    //! The manager fader needs to be done and the NAND must not be busy
    bool isSceneChangeEnable(); // 801858d8
    //! Checks if all of the system threads are idle
    bool isTaskFinished(); // 80185968
    //! If both faders are currently fading in
    bool isFadeIn(); // 801859dc
    //! The scene is blank when both faders are preparing to fade in
    bool isBlank(); // 80185a50
    //! The scene is displaying when both faders are done fading in
    bool isDisplay(); // 80185ac4
    //! Fade scene in/out
    void startSceneFadeOut(); // 80185b38
    void startSceneFadeIn(); // 80185b4c
    //! Fade in manager fader
    void startMgrFadeIn(); // 80185b60
    //! Scene status
    void setSceneStatus(EGG::Fader::EStatus status); // 80185b64
    EGG::Fader::EStatus getSceneStatus(); // 80185b78
    //! Scene/mgr fader colors
    void setSceneFadeColor(EGG::Color color); // 80185b8c
    void setFadeColor(EGG::Color color); // 80185bd4
    EGG::Color getFadeColor(); // 80185c60
    void resetFadeColor(); // 80185c8c
    //! Scene/mgr fader frame
    void setFadeFrame(u16 frame); // 80185ce0
    u16 getFadeFrame(); // 80185d28
    void resetFadeFrame(); // 80185d34
    //! Change the current scene
    bool changeNextSceneAfterFade(int scene, bool reload); // 80185d74

    // TO-DO: State check functions
    // ? FUN_80185f04()
    // ? FUN_80185f18()
    // ? FUN_80185f38()
    // ? FUN_80185f50()
    // ? FUN_80185f64()

    //! @brief Reset/exit game
    //! Boolean param for calling VISetBlack
    bool shutdownSystem(bool b); // 80185f74
    bool returnToMenu(bool b); // 80185fe4
    bool softReset(bool b); // 80186054
    //! Retrieve current scene
    EGG::Scene * getCurrentScene() const; // 80186100

private:
    RPSysSceneMgr() : EGG::SceneManager(NULL)
    {
        RPSysSystem *sys = RPSysSystem::getInstance();
        mSceneFader = new EGG::ColorFader(0.0f, 0.0f,
            sys->getFBWidth(), sys->getXFBHeight(),
            nw4r::ut::Color(0), EGG::ColorFader::STATUS_PREPARE_IN);
    }
    virtual ~RPSysSceneMgr(); // 80185678

private:
    //! Heap in which this object was allocated
    EGG::Heap *mParentHeap; // at 0x2C
    //! Manager state
    int mState; // at 0x30
    //! @brief Fader for the current scene
    //! The inherited fader is referred to as the manager fader
    //! and is used to obscure the screen between scenes
    EGG::ColorFader *mSceneFader; // at 0x34
};

#endif