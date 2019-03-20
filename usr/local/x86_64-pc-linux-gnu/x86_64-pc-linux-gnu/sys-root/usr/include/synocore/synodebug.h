// Copyright (c) 2000-2007 Synology Inc. All rights reserved.

#ifndef __SYNO_DEBUG_H__
#define __SYNO_DEBUG_H__

/**
 * @addtogroup SYNODEBUG
 *
 * @brief The macros to Log/Print debug messages.
 *
 * @{
 */

/**
 * Appends "file:line " to message head.  These are variadic
 * macro.
 *
 * @param[in] fmt The format string for syslog or fprintf. Should not be NULL. May be emtpy string "".
 *
 * @return No Return (void for syslog).
 *
 * @grantable No
 *
 * @remarks Output target mappings:
 * - For syslog: _DMSG()
 * - For fprintf: _PMSG()
 */
#define _DMSG(fmt, ... ) syslog(LOG_ERR, "%s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

/**
 * Appends "file:line " to message head.  These are variadic
 * macro.
 * @param[in] fmt The format string for syslog or fprintf. Should not be NULL.  May be emtpy string "".
 *
 * @return No Return (void for syslog).
 *
 * @grantable No
 *
 * @remarks Output target mappings:
 * - For syslog: _DMSG()
 * - For fprintf: _PMSG()
 */
#define _PMSG(fmt, ... ) fprintf(stderr, "%s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#include <stdio.h>
#include <synocore/error.h>

/**
 * Prints file location and the back trace that lastest synoerr is
 * setted.
 *
 * @return no return
 *
 * @grantable No
 *
 * @remarks Output target mappings:
 * - For syslog: N/A
 * - For fprintf: SYNOErrorDump()
 */
static inline void
SYNOErrorDump()
{
	printf("Lastest SynoErr=[%s:%d]\n", SLIBCErrorGetFile(), SLIBCErrorGetLine());
}

/**
 * @}
 */

#endif // __SYNO_DEBUG_H__
