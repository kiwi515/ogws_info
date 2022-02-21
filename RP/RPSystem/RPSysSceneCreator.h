#ifndef RP_SYSTEM_SCENE_CREATOR_H
#define RP_SYSTEM_SCENE_CREATOR_H
#include "types_rp.h"

#include <egg/core/eggSceneCreator.h>

/**
 * @brief Factory for all RP scenes
 * @details Not to be confused with the scene manager, the scene creator simply creates/destroys scenes.
 * The scene creator ensures that all scenes created are intended
 * for the current pack by referencing the scene attributes.
 * @wfuname
 */
class RPSysSceneCreator : EGG::SceneCreator
{
public:
    //! RP Scene ID
    //! @wfuname
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

    //! Pack Project game ID
    enum EPackID
    {
        RP_SPORTS_PACK,
        RP_PARTY_PACK,
        RP_HEALTH_PACK,
        RP_MUSIC_PACK,
        RP_ALLPACK
    };

    /**
     * @brief Attributes to show the creator how to handle a given scene
     * @customname
     */
    struct SceneAttributes
    {
        //! Scene ID
        s32 scene; // at 0x0
        //! Pack ID
        s32 pack; // at 0x4
        //! How to create the scene
        s32 createType; // at 0x8
        //! Toggle "Now Loading" text (unused)
        s32 showLoadingText; // at 0xC
        //! How to exit the scene
        s32 exitType; // at 0x10
        //! Whether to use the RP common sound archive
        s32 useCommonSound; // at 0x14
        //! Scene file directory
        const char *resDirName; // at 0x18
        //! Proper name (unused lookup feature?)
        const char *sceneName; // at 0x1C
    };

public:    
    //! @address 80184e10
    static RPSysSceneCreator * CreateInstance(EGG::Heap *heap);
    static RPSysSceneCreator * getInstance() { return sInstance; }
    
    /**
     * Fade out into a new scene, optionally reloading the current scene
     * @address 80184ba4
     * @return Success
     */
    bool changeSceneAfterFade(s32 sceneID, bool reenterCurrent);
    /**
     * Change to the boot scene (performing a soft reset)
     * @address 80184b98
     */
    void changeSoftReset();

    /**
     * Create a Sports Pack scene
     * @address 80184000
     */
    EGG::Scene * createSportsScene(s32 sceneID);

    //! Scene attribute accessor
    //! @address 801845f4
    s32 getCreateType(s32 sceneID);
    //! Scene attribute accessor
    //! @address 80184558
    s32 getExitType(s32 sceneID);
    //! Scene attribute accessor
    //! @address 801844bc    
    s32 getUseCommonSound(s32 sceneID);
    //! Scene attribute accessor
    //! @address 80184758    
    s32 getResDirName(s32 sceneID);
    //! Scene attribute accessor
    //! @address 80184690    
    s32 getSceneID(s32 sportID);
    //! Scene attribute accessor
    //! @address 801846ec    
    s32 getSportID(s32 sceneID);

    /**
     * Create any Pack Project scene
     * @address 80184838
     */
    virtual EGG::Scene * create(s32 sceneID);

    /**
     * Request engine shutdown
     * @address 80184804
     */
    virtual void destroy(s32);

private:
    RPSysSceneCreator(EGG::Heap *heap) : mParentHeap(heap), mSceneId(-1) {}
    //! @address 80183f68
    virtual ~RPSysSceneCreator() {}

private:
    //! Heap in which this object was allocated
    EGG::Heap *mParentHeap; // at 0x4
    //! Last created scene's ID
    int mSceneId; // at 0x8

    /**
     * Static instance
     * @address 804bf4f8
     */
    static RPSysSceneCreator *sInstance;

    /**
     * Configuration for all supported Pack Project scenes
     * @address 803820f8
     */
    static SceneAttributes sSceneAttributeTable[];
};

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