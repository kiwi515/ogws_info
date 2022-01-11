#ifndef RP_SYSTEM_TAG_PARMS_H
#define RP_SYSTEM_TAG_PARMS_H
#include "types_RP.h"

#include <egg/core/eggStream.h>

/**
 * @brief Container for tag parameters
 * Base used for RP engine's GameConfig
 * 
 * (Name from Wii Fit U)
 */
class RPSysTagParameters
{
public:
    RPSysTagParameters(char *name); // 8018674c

private:
    //! Name of parameter group
    const char *mName; // at 0x0
    //! Children parameters
    RPSysTagParm *mChildren; // at 0x4
};

/**
 * @brief Base class for tag parameters
 * 
 * (Name from Wii Fit U)
 */
class RPSysTagParm
{
public:
    RPSysTagParm(RPSysTagParameters *parent, char *tag); // 80186840

    //! Parameter I/O
    virtual void read(EGG::Stream& stream); // 80186748
    virtual void write(EGG::Stream& stream); // 80186744
    //! Print parameter information?
    virtual void dump(); // 80186740

private:
    //! Parameter tag
    char *mTag; // at 0x0
    //! Next parameter in linked list
    RPSysTagParm *mNext; // at 0x4
};

/**
 * @brief Tag parameter class for primitive type values
 *
 * Only the int template is used by the game.
 * 
 * @tparam T Parameter value type
 * 
 * (Name from Wii Fit U)
 */
template <typename T>
class RPSysPrimTagParm : RPSysTagParm
{
public:
    RPSysPrimTagParm(RPSysTagParameters *parent, char *tag) : RPSysTagParm(parent, tag) {}

    //! Parameter I/O
    virtual void read(EGG::Stream& stream); // 8018680c (<int>)
    virtual void write(EGG::Stream& stream); // 801867fc (<int>)
    //! Print parameter information?
    virtual void dump(); // 801867f8 (<int>)

private:
    //! Parameter value
    T mValue; // at 0xC
};

/**
 * @brief Tag parameter class for string values
 * 
 * (Name from Wii Fit U)
 */
class RPSysStringTagParm : RPSysTagParm
{
public:
    RPSysStringTagParm(RPSysTagParameters *parent, char *tag); // 801867ac

    //! Parameter I/O
    virtual void read(EGG::Stream& stream); // 80186770
    virtual void write(EGG::Stream& stream); // 80186760
    //! Print parameter information?
    virtual void dump(); // 8018675c

private:
    //! Parameter value
    const char *mValue; // at 0xC
};

#endif