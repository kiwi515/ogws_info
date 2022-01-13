#ifndef RP_SYSTEM_COMMON_OBJECT_H
#define RP_SYSTEM_COMMON_OBJECT_H
#include "types_RP.h"

#include "IRPGrpDrawObject.h"

/**
 * @brief Seems to provide common draw functionality to objects,
 * considering it has no additional functionality.
 */
class RPSysCommonObject : IRPGrpDrawObject
{
public:
    RPSysCommonObject(); // 80187dbc
    virtual ~RPSysCommonObject(); // 80187f24
    //! Draws scene fader, pause mgr, etc.
    virtual void UserDraw(); // 80187c10
};

#endif