// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_DYNAMIC_LINK_H
#define __SYNOHACORE_DYNAMIC_LINK_H

#include <sys/cdefs.h>

extern void *gHADLHandle;
extern int gHADLHandleRef;

__BEGIN_DECLS

/**
 * Init ha dynamic loading handle.
 *
 * @retval 0 success (gHADLHandleRef++)
 * @retval -1 error
 * @retval -2 HA is not running
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 * @see SYNOHADlClose
 */
int SYNOHADlInit(void);

/**
 * Close ha dynamic loading handle.
 *
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @see SYNOHADlInit
 */
void SYNOHADlClose(void);

/**
 * Keep the handle after DL function returned, so that it can be used for next DL function in a daemon
 *
 * MUST remember to call SYNOHADlKeepHandleRelease manually at the end.
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 * @see SYNOHADlKeepHandleRelease
 */
void SYNOHADlKeepHandle(void);

/**
 * Release the kept handle by SYNOHADlKeepHandle
 *
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @see SYNOHADlKeepHandle
 */
void SYNOHADlKeepHandleRelease(void);

/**
 * Get ha dynamic loading function pointer.
 * Internal use!
 *
 * @param [in]  funcName dynamic loading function name
 * @param [out] fp function pointer's pointer
 * @retval 0 success (caller need to call SYNOHADlClose() only when ret = 0)
 * @retval -1 error
 * @retval -2 HA is not running
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHADlGetFP(const char *funcName, void **fp);

__END_DECLS

#endif
