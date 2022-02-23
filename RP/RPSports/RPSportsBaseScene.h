#ifndef RP_SPORTS_BASE_SCENE_H
#define RP_SPORTS_BASE_SCENE_H
#include "types_RP.h"

#include "RPSysScene.h"

/**
 * @brief Base class for all Sports Pack scenes
 * @customname
 */
class RPSportsBaseScene : RPSysScene
{
public:
    RPSportsBaseScene() {}
    //! @address 80184460
    virtual ~RPSportsBaseScene() {}

    /**
     * @brief Initialize/setup the scene
     * @address 801ef1c8
     */
    virtual void Configure();
    /**
     * @brief Load any needed resources
     * @address 801ef184
     */
    virtual void LoadResource();
    /**
     * @brief Re-initialize the scene
     * @address 801ef140
     */
    virtual void Reset();
    /**
     * @brief Run scene logic
     * @address 801ef0fc
     */
    virtual void Calculate();
    /**
     * @brief Exit the scene
     * @address 801ef064
     */
    virtual void Exit();

    /**
     * @brief Configure callback
     * @address 801ef20c
     */
    virtual void OnConfigure();
    /**
     * @brief LoadResource callback
     * @address 801ef1c4
     */
    virtual void OnLoadResource();
    /**
     * @brief Reset callback
     * @address 801ef180
     */
    virtual void OnReset();
    /**
     * @brief Calculate callback
     * @address 801ef13c
     */
    virtual void OnCalculate();
    /**
     * @brief UserDraw callback
     * @address 801ef0f8
     */
    virtual void OnUserDraw();
    /**
     * @brief DebugDraw callback
     * @address 801ef0b4
     */
    virtual void OnDebugDraw();
    /**
     * @brief Exit callback
     * @address 801ef0a0
     */
    virtual void OnExit();

    /**
     * @brief Any drawing the object needs to do
     * @address 801ef0b8
     */
    virtual void UserDraw();
    /**
     * @brief Debug draw pass, nearly all objects stub this out
     * @address 801ef0a4
     */
    virtual void DebugDraw();
};

#endif