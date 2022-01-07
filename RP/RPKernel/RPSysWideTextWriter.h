#ifndef RP_KERNEL_WIDE_TEXT_WRITER_H
#define RP_KERNEL_WIDE_TEXT_WRITER_H
#include "types_RP.h"

/**
 * @brief RP engine screen wide text (wchar_t) writer
 * 
 * It can be assumed that this rivals the standard RP text writer in how it inherits from NW4R,
 * but it is not known for sure as only one function is in Wii Sports, and very few are in Wii Fit U.
 * 
 * (Name from Wii Fit U)
 */
class RPSysWideTextWriter
{
public:
    //! Initialize format buffer
    static void Initialize(); // 80198968

private:
    //! @brief Name based on NW4R's text writer
    //! This is because they share sizes (mFormatBufferSize * sizeof(wchar_t))
    static wchar_t *mFormatBuffer; // 804bf558
};

#endif