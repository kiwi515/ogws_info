#ifndef RP_KERNEL_MESSAGE_H
#define RP_KERNEL_MESSAGE_H
#include "types_RP.h"

#include <egg/util/eggMsgRes.h>

/**
 * @brief Wrapper class for EGG's MsgRes, but with added support
 * for the extra text features seen in RP BMG files.
 * 
 * (Name from Wii Fit U)
 */
class RPSysMessage : EGG::MsgRes
{
public:
    /**
     * @brief Custom RP BMG message info block entry.
     * MsgInfoBlock denotes the size of the block entry,
     * allowing games to add extra features to their text.
     */
    struct RPMsgInfoBlockEntry : EGG::MsgRes::MsgInfoBlockEntry
    {
        //! Text scale
        u16 mScale; // at 0x8
        //! Text kerning
        u8 mCharSpace; // at 0xA
    };

public:
    RPSysMessage(const void *bin, EGG::Heap *heap); // 80190dec
    virtual ~RPSysMessage(); // 80190d94

private:
    //! Retrieve message info by searching the message ID data block
    RPMsgInfoBlockEntry * GetMessage(u32 id1, u32 id2); // 80190d90
    //! Retrieve attribute from message info block
    u32 GetAttribute(u32 id1, u32 id2); // 80190d6c
    //! Retrieve scale from message info block
    u16 GetScale(u32 id1, u32 id2); // 80190d48
    //! Retrieve kerning from message info block
    u8 GetCharSpace(u32 id1, u32 id2); // 80190d24
};

#endif