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
    virtual ~IRPSysHostIOSocket(); // 80190794
    virtual UNKTYPE FUN_8018a904(UNKTYPE) {} // 8018a904
    virtual UNKTYPE FUN_8018a908(UNKTYPE) {} // 8018a908
    
    IRPSysHostIOSocket(const char *, ...); // 801907e4
    IRPSysHostIOSocket(); // 801907d4
};

#endif