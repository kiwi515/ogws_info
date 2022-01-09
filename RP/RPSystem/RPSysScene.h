#ifndef RP_SYSTEM_SCENE_H
#define RP_SYSTEM_SCENE_H
#include "types_rp.h"

#include "IRPGrpDrawObject.h"
#include <egg/core/eggScene.h>
#include <egg/core/eggColor.h>

/**
 * @brief Base class for all RP engine scenes.
 * 
 * Inherits from EGG::Scene for compatability,
 * and inherits from a renderable interface to simplify the renderer's job.
 * 
 * (Name from Wii Fit U)
 */
class RPSysScene : EGG::Scene, IRPGrpDrawObject
{
public:
    RPSysScene();
    virtual ~RPSysScene() {} // 80183fa8
    virtual void calc(); // 80185094
    virtual void draw(); // 80185048
    virtual void enter(); // 80185304
    virtual void exit(); // 80184f90
    virtual void reinit(); // 8018522c
    virtual void incoming_childDestroy(); // 80185168
    virtual void outgoing_childCreate(); // 80185008
    //! Any drawing the object needs to do
    virtual void UserDraw(); // 801855a0
    //! Unused draw pass, nearly all objects stub this out
    virtual void DebugDraw(); // 801855a4
    //! Returns address of some unused global object
    virtual UNKTYPE * VF38(UNKTYPE); // 8018558c
    //! Callback for pause/unpause (bool true if pausing)
    virtual void pauseCallBack(bool pauseOn); // 80185594
    //! Initialize/setup the scene
    virtual void Configure(); // 80185400
    //! Load any needed resources
    virtual void LoadResource(); // 80185598
    //! Re-initialize the scene
    virtual void Reset(); // 80185228
    //! Run scene logic
    virtual void Calculate(); // 80185164
    //! Exit the scene
    virtual void Exit(); // 80185004
    //! @brief Task method
    //! Not static, but EGG's TaskThread lets you request
    //! non-static functions by giving it args to pass in
    virtual void taskAsync(); // 8018559c

    //! Disable fade-in when entering/re-initializing the scene
    void disableFadeIn(); // 80184e80
    //! Creator scene ID
    s32 getCreatorSceneID() const; // 80184e90
    void setCreatorSceneID(int scene); // 80184e98
    //! Initialize scene members
    void init(); // 80184ea0
    //! Set VI dimming
    void setDimming(bool dim); // 8018546c
    //! @brief Control scene fader
    //! Bool is used in WFU, but these have the scene mgr do it,
    //! rather than accessing the fader directly
    void startFadeOut(bool); // 80185474
    void startFadeIn(bool); // 8018547c
    //! Set manager's scene fade color
    void setSceneFadeColor(EGG::Color color); // 80185484
    //! Fade color of both of manager's faders
    void setFadeColor(EGG::Color color); // 80185484
    EGG::Color getFadeColor() const; // 80185514
    //! Set fade frame of both of manager's faders
    void setFadeFrame(u16 frame); // 8018551c
    //! @brief If it is safe for the console NAND to be accessed
    //! The scene manager must not be fading in or be busy
    bool isNandAccessEnable() const; // 80185524
    //! @brief If it is okay for the scene to be changed
    //! The manager must be ready to fade out and not be busy
    bool isSceneChangeEnable() const; // 80185574
    //! @brief If the scene is currently blank (not displayed at all)
    //! This happens when both faders are preparing to fade in
    bool isSceneBlank() const; // 8018557c
    //! @brief If the scene is currently fully displayed
    //! This happens when both faders are done and ready to fade back out
    bool isSceneDisplay() const; // 80185584

private:
    //! Becomes the global renderer when scene is entered
    RPGrpRenderer *mRenderer; // at 0x2C
    //! Not sure what purpose these serve yet
    RPSysCommonObject *mCmnObject; // at 0x30
    //! @brief TODO, constructor at 801988d8
    //! Some particle related structure
    UNKTYPE *PTR_0x34;
    /**
     * @brief Local scene heap (speculative)
     * Is passed to RPSysSystem::FUN_80183518 when non-null (never happens)
     * which would call the VF @ 0x1C (would be Heap::destroy if ptr was to a Heap),
     * and RPSysSystem has destroyHeap(EGG::Heap *) in WFU
     */
    EGG::Heap *mHeap; // at 0x38
    //! Scene flags
    u32 mFlags; // at 0x3C
    //! @brief Scene ID set by scene creator
    int mCreatorSceneId; // at 0x40

    //! @brief Unknown, unused global object
    //! VF38 will return its address
    static UNKWORD DAT_804bf4d0; // 804bf4d0
};

#endif