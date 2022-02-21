#ifndef RP_SPORTS_GOL_CONFIG_H
#define RP_SPORTS_GOL_CONFIG_H
#include "types_RP.h"
#include "RPSysUnknownBase.h"

/**
 * @brief Global settings used by the golf scene
 * @wscname
 */
class RPGolConfig : RPSysUnknownBase
{
public:
    /**
     * @brief Configuration for a golf hole
     * @wscname
     */
    struct HoleInfo
    {
        const char *name; // at 0x0
        u32 par; // at 0x4

        /**
         * @see EHoleResource
         * @details Only one resource can be used as they are not flags.
         */
        u32 resource; // at 0x8

        f32 FLOAT_0xC;
        f32 FLOAT_0x10;
        f32 FLOAT_0x14;
        f32 FLOAT_0x18;
        f32 FLOAT_0x1C;
        f32 FLOAT_0x20;
    };

    //! Optional resources that can be requested for a hole
    enum EHoleResource
    {
        RES_NONE,
        RES_RIVER_SFX,
        RES_SEA_SFX,
        RES_SKY_REFLECT
    };

    //! Golf gamemode
    enum EGameMode
    {
        GAMEMODE_0,
        GAMEMODE_1,
        GAMEMODE_2,

        GAMEMODE_TR_PUTTING,
        GAMEMODE_TR_NEARPIN,
        GAMEMODE_TR_TARGET,

        GAMEMODE_FT_PUTTING,
        GAMEMODE_FT_NEARPIN,
        GAMEMODE_FT_TARGET,

        GAMEMODE_9H,

        GAMEMODE_3H_BEGINNER,
        GAMEMODE_3H_INTERMED,
        GAMEMODE_3H_EXPERT,
    };

public:
    //! @address 8029dcc0
    static void CreateInstance();
    //! @address 8029dcc0
    static void DestroyInstance();

    /**
     * Number of holes played so far
     * @address 8029cb1c
     */
    static int GetNumHolesPlayed();

    /**
     * Check if the current hole is the first hole of the gamemode
     * @address 8029cb74
     */
    static bool IsFirstHole();

    /**
     * Player's score on specified hole
     * @address 8029cbd4
     * @param hole Hole id (Nth hole played in round, not hole N)
     * @param player Player id
     */
    static int GetNthHoleScore(u32 hole, u32 player);

    /**
     * Player's stroke count on specified hole
     * @address 8029cc54
     * @param hole Hole id (Nth hole played in round, not hole N)
     * @param player Player id
     */
    static int GetNthHoleStrokes(u32 hole, u32 player);

    /**
     * @brief Player's total score so far
     * @details Caller can optionally include the current hole in the calculation,
     * which is used for the result screen as the hole is not incremented after finishing the round
     * @address 8029ccbc
     * @param player Player id
     * @param includeCurr Include the current hole in the calculation (for results)
     */
    static int GetTotalScore(u32 player, bool includeCurr);

    /**
     * ID of the Nth hole of the round
     * @address 8029ce04
     */
    static int GetRelativeHole(int n);

    /**
     * Number of holes that will be played
     * @address 8029ce58
     */
    static int GetNumHolesTotal();

    /**
     * Current wind direction + speed
     * @address 8029ce74
     * @param dirOut Direction output ptr
     * @param spdOut Speed output ptr
     */
    void GetWind(int *dirOut, int *spdOut) const;

    /**
     * Creates the wind set based on what holes are required by the gamemode
     * @address 8029cea8
     */
    void CreateWindForGamemode();

    /**
     * @brief Update player scores
     * @details Scores taken from golf player manager
     * @address 8029cf24
     */
    void UpdateScores();

    /**
     * Check if the round is not over yet
     * @address 8029cff0
     */
    bool CanPlayNextHole() const;

    /**
     * Current hole ID, one-indexed for UI
     * @address 8029d0b8
     */
    static int GetUIHoleNum();

    /**
     * Par of specified hole
     * @address 8029d0c8
     * @param n Hole id (Hole N, not relative to round)
     */
    static int GetHolePar(int n);

    /**
     * Par of current hole
     * @address 8029d0e0
     */
    static int GetCurrentHolePar();

    /**
     * Choose random pin position
     * @address 8029d100
     */
    void ChoosePinPos();

    // FUN_8029d238
    
    // FUN_8029d2c4

    /**
     * Check if the current gamemode is training or fitness, not standard
     * @address 8029d3ac
     */
    static bool IsNotStandardGame();

    /**
     * Check if the current hole needs `sky2`, the mirrored skybox for reflections
     * @address 8029d438
     */
    static bool IsSkyReflect();

    /**
     * Check if the current hole uses the sea environment sfx (`SE_LV_Env2_Sea`)
     * @address 8029d464
     */
    static bool IsUseSeaSfx();

    /**
     * Check if the current hole uses the river environment sfx (`SE_LV_Env2_River`)
     * @address 8029d490
     */
    static bool IsUseRiverSfx();

    //! @address 8029d4bc
    void SetupStandardGame();
    //! @address 8029d6e0
    void SetupFitnessGame();
    //! @address 8029d778
    void SetupStandardGame();
    //! @address 8029d810
    void SetupGame();

    // FUN_8029d86c()

    // FUN_8029d960()

    // FUN_8029d970()

    /**
     * CARC name of the current hole
     * @address 8029d978
     */
    static const char * GetCurrentHoleName();

    // FUN_8029d994()

    /**
     * Create wind set from settings
     * @address 8029cea8
     */
    static void CreateWind(int startHole, int endHole, int minWind, int maxWind);

    /**
     * Create a random, exclusive sequence between 0 and `max`
     * @address 8029dea8
     * @param max Sequence max value
     * @param array Output array
     */
    static void CreateRandomSeq(int max, int *array);

    /**
     * @brief Lookup hole number by name
     * @address 8029e084
     * @param name Hole name (ex: "fc1")
     */
    static int GetHoleNumFromName(const char *name);

private:
    //! @address 8029d9fc
    RPGolConfig();
    //! @address 8029d9a0
    virtual ~RPGolConfig();

private:
    static const u32 PLAYER_MAX = 4;
    static const u32 HOLE_MAX = 9;

    u32 mPlayerScores[PLAYER_MAX][HOLE_MAX]; // at 0x4
    u32 mGameMode; // at 0x94
    u32 mCurrentHole; // at 0x98
    char UNK_0x9C[0x1C74 - 0x9C];

    /**
     * Hole info for the 9 holes plus a few unused courses
     * @address 803c7aa0
     */
    static HoleInfo sHoleInfo[];

    /**
     * Static instance
     * @address 804bf8c4 
     */
    static RPGolConfig *sInstance;
};

RPGolConfig::HoleInfo sHoleInfo[] = {
    {"fc1",    4, RPGolConfig::RES_NONE,        -136.0f, -216.0f, -2.9f, 0.0f, 0.0f, 0.0f},
    {"fc3",    3, RPGolConfig::RES_SKY_REFLECT,  198.0f, -520.0f,  2.1f, 0.0f, 0.0f, 0.0f},
    {"fc8",    5, RPGolConfig::RES_SKY_REFLECT,  958.0f, -246.0f, -4.3f, 0.0f, 0.0f, 0.0f},
    {"fc14",   3, RPGolConfig::RES_SEA_SFX,       64.0f, -380.0f,  2.4f, 0.0f, 0.0f, 0.0f},
    {"fc5",    5, RPGolConfig::RES_SEA_SFX,    -1354.0f,  -96.0f, -3.0f, 0.0f, 0.0f, 0.0f},
    {"fc16",   4, RPGolConfig::RES_RIVER_SFX,   -980.0f, -451.0f, -1.3f, 0.0f, 0.0f, 0.0f},
    {"fc12",   4, RPGolConfig::RES_NONE,        -331.0f, -941.0f,  2.4f, 0.0f, 0.0f, 0.0f},
    {"fc9",    3, RPGolConfig::RES_SEA_SFX,     -397.0f, -205.0f,  0.4f, 0.0f, 0.0f, 0.0f},
    {"fc13",   5, RPGolConfig::RES_SEA_SFX,     1044.0f, -287.0f, -4.5f, 0.0f, 0.0f, 0.0f},
    //! Target Practice hole
    {"fc11",   3, RPGolConfig::RES_SKY_REFLECT,    0.0f, -205.0f, -0.8f, 0.0f, 0.0f, 0.0f},
    //! E3 hole
    {"E3",     4, RPGolConfig::RES_NONE,           0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f},
    //! "Survey" (Driving range)
    {"survey", 5, RPGolConfig::RES_NONE,           0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f},
    //! "Angle" (Physics test)
    {"angle",  5, RPGolConfig::RES_NONE,           0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f},
    //! Unfinished port of Famicom Hole 18
    {"fc18",   5, RPGolConfig::RES_NONE,           0.0f,    0.0f,  0.0f, 0.0f, 0.0f, 0.0f}
};

#endif