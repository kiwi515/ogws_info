#ifndef RP_KERNEL_TEXT_WRITER_H
#define RP_KERNEL_TEXT_WRITER_H
#include "types_RP.h"

#include "RPSysFontManager.h"
#include <nw4r/ut/ut_TextWriterBase.h>
#include <nw4r/ut/ut_RomFont.h>

/**
 * @brief RP engine screen text writer
 * @details Provides base functionality from NW4R, but with some extra features to make printing easier,
 * such as the ability to print to an arbitrary screenspace location, or begin/end rendering.
 * @wfuname
 */
class RPSysTextWriter : nw4r::ut::TextWriterBase<char>
{
public:
    //! @address 80190cc4
    static RPSysTextWriter * CreateInstance();
    static RPSysTextWriter * GetInstance() { return sInstance; }

    /**
     * Reset all settings
     * @address 80190b9c
     */
    void Reset();

    /**
     * Print formatted text to screen coordinates (relative to the top-left)
     * @address 80190af8
     */
    void Printf(f32 x, f32 y, const char *msg, ...);

    /**
     * Print formatted text to screen coordinates (relative to the center)
     * @address 80190960
     */
    void PrintfZeroCenter(f32 x, f32 y, const char *msg, ...);

    /**
     * Setup GX for rendering
     * @address 801908d8
     */
    void Begin();
    
    /**
     * End rendering
     * @address 801908cc
     */
    void End();

private:
    RPSysTextWriter()
    {
        SetFont(RPSysFontManager::GetInstance()->GetRomFont());
        mIsRendering = FALSE;
    }
    //! @address 80190c6c
    virtual ~RPSysTextWriter();

private:
    //! Render status (Begin/End)
    BOOL mIsRendering; // at 0x68

    /**
     * Static instance
     * @address 804bf538
     */
    static RPSysTextWriter *sInstance;
};

#endif