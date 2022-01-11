#ifndef TYPES_RP_H
#define TYPES_RP_H
#include <types.h>

//! Provides year, month, month day
typedef u16 RPTime16;
//! Provides year, month, month day, week day, hour
typedef u32 RPTime32;

// RPGraphics
struct IRPGrpDrawObject;
struct RPGrpRenderer;

// RPKernel
struct RPSysSystem;
struct RPSysFile;
struct IRPSysHostIOSocket;
struct RPSysTextWriter;
struct RPSysMessage;
struct RPSysWideTextWriter;
struct RPSysLytAllocator;

// RPSystem
struct RPSysSceneCreator;
struct RPSysScene;
struct RPSysSceneMgr;
struct RPSysProjectLocal;
struct RPSysResourceManager;
struct RPSysQueuedScene;
struct RPSysCommonObject;
struct RPSysDvdStatus;
struct RPSysSaveDataMgr;
struct RPSysFontManager;
struct RPSysSaveData;

// RPSports
struct RPSportsCommonData;
struct RPSportsPlayerData;
struct RPSportsBaseScene;
struct RPBoxBoxer;
struct RPBoxBoxerEnergy;
struct RPBoxBoxerCombo;

// RPParty
struct RPPartyCommonData;
struct RPPartyPlayerData;

#endif