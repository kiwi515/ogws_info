#ifndef RP_KERNEL_I_HOSTIO_SOCKET_H
#define RP_KERNEL_I_HOSTIO_SOCKET_H
#include "types_RP.h"

/**
 * @brief Seems to be functionality for IO while debugging?
 * All of its functions have been stubbed out.
 */
class IRPSysHostIOSocket
{
public:
    virtual ~IRPSysHostIOSocket();
    
    IRPSysHostIOSocket(const char *, ...);
    IRPSysHostIOSocket();
};

#endif