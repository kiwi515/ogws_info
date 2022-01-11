#ifndef RP_SPORTS_BASE_SCENE_H
#define RP_SPORTS_BASE_SCENE_H
#include "types_RP.h"

#include "RPSysScene.h"

/**
 * @brief Base class for all scenes unique to the Sports Pack (Wii Sports)
 */
class RPSportsBaseScene : RPSysScene
{
public:
    RPSportsBaseScene() {}
    ~RPSportsBaseScene() {}

    //! Initialize/setup the scene
    virtual void Configure(); // 801ef1c8
    //! Load any needed resources
    virtual void LoadResource(); // 801ef184
    //! Re-initialize the scene
    virtual void Reset(); // 801ef140
    //! Run scene logic
    virtual void Calculate(); // 801ef0fc
    //! Exit the scene
    virtual void Exit(); // 801ef064

    //! Configure callback
    virtual void OnConfigure(); // 801ef20c
    //! LoadResource callback
    virtual void OnLoadResource(); // 801ef1c4
    //! Reset callback
    virtual void OnReset(); // 801ef180
    //! Calculate callback
    virtual void OnCalculate(); // 801ef13c
    //! UserDraw callback
    virtual void OnUserDraw(); // 801ef0f8
    //! DebugDraw callback
    virtual void OnDebugDraw(); // 801ef0b4
    //! Exit callback
    virtual void OnExit(); // 801ef0a0

    //! Any drawing the object needs to do
    virtual void UserDraw(); // 801ef0b8
    //! Debug draw pass, nearly all objects stub this out
    virtual void DebugDraw(); // 801ef0a4
};

#endif