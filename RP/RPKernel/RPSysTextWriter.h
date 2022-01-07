#ifndef RP_KERNEL_TEXT_WRITER_H
#define RP_KERNEL_TEXT_WRITER_H
#include "types_RP.h"

#include "RPSysFontManager.h"
#include <nw4r/ut/ut_TextWriterBase.h>
#include <nw4r/ut/ut_RomFont.h>

/**
 * @brief RP engine screen text writer
 * 
 * Provides base functionality from NW4R, but with some extra features to make printing easier,
 * such as the ability to print to an arbitrary screenspace location, or begin/end rendering.
 * 
 * (Name from Wii Fit U)
 */
class RPSysTextWriter : nw4r::ut::TextWriterBase<char>
{
public:
    //! Singleton methods
    static RPSysTextWriter * CreateInstance(); // 80190cc4
    static RPSysTextWriter * GetInstance() { return sInstance; }

    //! Reset all settings
    void Reset(); // 80190b9c
    //! Format text and print to screen coordinates
    void Printf(f32 x, f32 y, const char *msg, ...); // 80190af8
    //! Format text and print to screen coordinates, with the origin at the screen center
    void PrintfZeroCenter(f32 x, f32 y, const char *msg, ...); // 80190960
    //! Setup and begin rendering
    void Begin(); // 801908d8
    //! End rendering
    void End(); // 801908cc

private:
    RPSysTextWriter()
    {
        SetFont(RPSysFontManager::GetInstance()->GetRomFont());
        mIsRendering = FALSE;
    }
    virtual ~RPSysTextWriter(); // 80190c6c

private:
    //! Render status (Begin/End)
    BOOL mIsRendering; // at 0x68

    //! Static instance
    static RPSysTextWriter *sInstance; // 804bf538
};

#endif