#ifndef RP_SYSTEM_FONT_MANAGER_H
#define RP_SYSTEM_FONT_MANAGER_H
#include "types_RP.h"

#include <nw4r/ut/ut_RomFont.h>
#include <nw4r/ut/ut_ResFont.h>

/**
 * @brief RP engine font manager
 * 
 * Responsible for loading and setting up the rom font and any res fonts needed.
 * Whether specific fonts are used is determined at compile time.
 * 
 * (Name from Wii Fit U)
 */
class RPSysFontManager
{
public:
    /**
     * @brief Pack Project res fonts
     */
    enum EResFont
    {
        FONT_NRODDB_32_I4,
        FONT_NRODDB_32_IA4,
        FONT_NRODDB_62_IA4,
        FONT_NRODDB_200_IA4,
        FONT_NRODEB_32_I4,
        FONT_NRODEB_70_IA4,
        FONT_HEALTHTIME,

        FONT_MAX
    };

public:
    //! Singleton methods
    static RPSysFontManager * CreateInstance(); // 8018bea4
    static RPSysFontManager * GetInstance() { return sInstance; }

    //! Set up rom font
    void LoadRomFont(); // 8018be10
    //! Set up res fonts
    void LoadResFonts(); // 8018bd64
    //! Retrieve ResFont data by name
    void * GetResFontData(const char *name) const; // 8018bcdc

    //! Access RomFont (for text writer)
    nw4r::ut::RomFont& GetRomFont() const { return *mRomFont; }

private:
    RPSysFontManager()
    {
        // Initialize rom font
        mRomFont = new nw4r::ut::RomFont();
        // Initialize res fonts
        for (int i = 0; i < FONT_MAX; i++)
        {
            mResFonts[i] = new nw4r::ut::ResFont();
            mResFontData[i] = NULL;
        }
    }
    virtual ~RPSysFontManager(); // 8018be64

private:
    nw4r::ut::RomFont *mRomFont; // at 0x4
    //! ResFont objects
    nw4r::ut::ResFont *mResFonts[FONT_MAX]; // at 0x8
    //! Binary ResFont files
    void *mResFontData[FONT_MAX]; // at 0x24

    //! Boolean(?) array that decides whether a given font should be loaded
    static u32 sIsResFontUsed[FONT_MAX]; // 80382a50
    //! Strings of the font filenames
    static const char *sPackResFonts[FONT_MAX]; // 803b9950
    //! Static instance
    static RPSysFontManager *sInstance; // 804bf510
};

#endif