#ifndef RP_SYSTEM_SYS_SCENE_CREATOR_H
#define RP_SYSTEM_SYS_SCENE_CREATOR_H
#include "types_rp.h"

#include <egg/core/eggSceneCreator.h>

/**
 * @brief Scene creator for all RP scenes.
 * 
 * Not to be confused with the scene manager, the scene creator simply creates/destroys scenes.
 * It does have some methods involving changing the current scene,
 * but those usually hand over the request to the scene manager.
 * 
 * The scene creator also ensures that all scenes created are intended for the current pack.
 * This is done by referencing the scene attributes.
 */
class RPSysSceneCreator : EGG::SceneCreator
{
public:
    enum ESceneID
    {
        RP_BOOT_SCENE,
        RP_PLAYER_SELECT_SCENE,
        RP_NUNCHAKU_SCENE,
        RP_BSB_SCENE,
        RP_BOW_SCENE,
        RP_GOL_SCENE,
        RP_TNS_SCENE,
        RP_BOX_SCENE,
        RP_SPORTS_TITLE_SCENE,
        RP_SPORTS_MENU_SCENE,
        RP_TRAIN_MENU_SCENE,
        RP_PHYSICAL_MENU_SCENE,
        RP_PHYSICAL_PREVIEW_SCENE,
        RP_PHYSICAL_RESULT_SCENE,
        RP_GOL_SELECT_SCENE,
    };

    enum EPackID
    {
        RP_SPORTS_PACK,
        RP_PARTY_PACK,
        RP_HEALTH_PACK,
        RP_MUSIC_PACK,
        RP_ALLPACK
    };

    struct SceneAttributes
    {
        s32 scene; // at 0x0
        s32 pack; // at 0x4
        s32 createType; // at 0x8
        s32 showLoadingText; // at 0xC
        s32 exitType; // at 0x10
        s32 useCommonSound; // at 0x14
        const char *resDirName; // at 0x18
        const char *sceneName; // at 0x1C
    };

public:    
    static RPSysSceneCreator * CreateInstance(EGG::Heap *heap); // 80184e10
    static RPSysSceneCreator * getInstance() { return sInstance; }
    
    bool changeSceneAfterFade(s32 sceneID, bool reenterCurrent); // 80184ba4
    void changeSoftReset(); // 80184b98
    EGG::Scene * createSportsScene(s32 sceneID); // 80184000
    s32 getCreateType(s32 sceneID); // 801845f4
    s32 getExitType(s32 sceneID); // 80184558
    s32 getUseCommonSound(s32 sceneID); // 801844bc
    s32 getResDirName(s32 sceneID); // 80184758
    s32 getSceneID(s32 sportID); // 80184690
    s32 getSportID(s32 sceneID); // 801846ec

private:
    RPSysSceneCreator(EGG::Heap *heap) : mParentHeap(heap), mExitScene(-1) {}
    virtual ~RPSysSceneCreator() {} // 80183f68
    virtual EGG::Scene * create(s32 sceneID); // 80184838
    virtual void destroy(s32); // 80184804

private:
    EGG::Heap *mParentHeap; // at 0x4
    //! @brief Newest created scene's exit scene (only set if exit type needs one)
    s32 mExitScene; // at 0x8

    static RPSysSceneCreator *sInstance; // 804bf4f8
    static SceneAttributes sSceneAttributeTable[]; // 803820f8
};

/**
 * @brief Information about every scene that the scene creator supports.
 * 
 * It includes instructions on how the creator should create the new scene/destroy the old scene,
 * information on where a given scene's resources reside, etc.
 * 
 * There is notably an unused flag that allows the unused "Now Loading" text to display.
 * 
 * Additionally, the "name" field seems to be unused but may be related
 * to the getSceneID(const char*) method mentioned in Wii Fit U.
 */
RPSysSceneCreator::SceneAttributes RPSysSceneCreator::sSceneAttributeTable[] = {
    // Scene                       pack         c    s    e    u       resDir                 name
    {RP_BOOT_SCENE,             RP_ALLPACK,     0, FALSE, 1, TRUE,  "RPCommon/",             "ロゴ"},
    {RP_PLAYER_SELECT_SCENE,    RP_ALLPACK,     0, FALSE, 2, TRUE,  "RPCommon/",             "プレイヤーセレクト"},
    {RP_NUNCHAKU_SCENE,         RP_ALLPACK,     1, FALSE, 3, FALSE, "RPCommon/",             "ヌンチャクチェック"},
    {RP_BSB_SCENE,              RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPBsbScene/",           "野球"},
    {RP_BOW_SCENE,              RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPBowScene/",           "ボウリング"},
    {RP_GOL_SCENE,              RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPGolScene/",           "ゴルフ"},
    {RP_TNS_SCENE,              RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPTnsScene/",           "テニス"},
    {RP_BOX_SCENE,              RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPBoxScene/",           "ボクシング"},
    {RP_SPORTS_TITLE_SCENE,     RP_SPORTS_PACK, 0, FALSE, 1, TRUE,  "RPSportsTitle/",        "スポーツパック"},
    {RP_SPORTS_MENU_SCENE,      RP_SPORTS_PACK, 0, FALSE, 2, TRUE,  "RPSportsCommon/",       "スポーツメニューセレクト"},
    {RP_TRAIN_MENU_SCENE,       RP_SPORTS_PACK, 1, FALSE, 3, TRUE,  "RPSportsTrainingMenu/", "トレーニングメニュー"},
    {RP_PHYSICAL_MENU_SCENE,    RP_SPORTS_PACK, 1, FALSE, 3, TRUE,  "RPSportsPhysical/",     "体力測定メニュー"},
    {RP_PHYSICAL_PREVIEW_SCENE, RP_SPORTS_PACK, 1, FALSE, 3, TRUE,  "RPSportsPhysical/",     "体力測定説明"},
    {RP_PHYSICAL_RESULT_SCENE,  RP_SPORTS_PACK, 1, FALSE, 3, TRUE,  "RPSportsPhysical/",     "体力測定結果"},
    {RP_GOL_SELECT_SCENE,       RP_SPORTS_PACK, 1, FALSE, 0, FALSE, "RPGolScene/",           "ゴルフコースセレクト"},
};

#endif