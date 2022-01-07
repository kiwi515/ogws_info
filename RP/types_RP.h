#ifndef TYPES_RP_H
#define TYPES_RP_H
#include <types.h>

//! Provides year, month, month day
typedef u16 RPTime16;
//! Provides year, month, month day, week day, hour
typedef u32 RPTime32;

// RPKernel
struct RPSysSystem;
struct RPSysFile;
struct IRPSysHostIOSocket;
struct RPSysTextWriter;
struct RPSysMessage;
struct RPSysWideTextWriter;

// RPSystem
struct RPSysFontManager;
struct RPSysSaveData;
struct RPSysSaveDataMgr;
struct RPSysSceneCreator;
struct RPSysScene;
struct RPSysProjectLocal;
struct RPSysResourceManager;
struct RPSysQueuedScene;
struct RPSysDvdStatus;

// RPSports
struct RPSportsCommonData;
struct RPSportsPlayerData;
struct RPBoxBoxer;
struct RPBoxBoxerEnergy;
struct RPBoxBoxerCombo;

// RPParty
struct RPPartyCommonData;
struct RPPartyPlayerData;

#endif