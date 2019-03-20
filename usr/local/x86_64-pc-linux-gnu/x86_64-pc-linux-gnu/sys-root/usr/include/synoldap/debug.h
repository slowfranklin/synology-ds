// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_DEBUG_H__
#define __SYNOLDAP_DEBUG_H__

#include <sys/cdefs.h>
#include <availability.h>
#include <synocore/synoglobal.h>

__BEGIN_DECLS;

/**
 * @addtogroup debug
 *
 * @brief Utilities for debugging.
 *
 * @{
 */

/**
 * @brief Check whether in debug mode, i.e. existence of `/tmp/synoldap_debug`.
 *        If yes, debug messages will be written to `/var/log/messsages` via syslog.
 *
 * @note First invocation decides results of future invocations by the same
 *       thread, This should be thread-safe since the flag is stored in
 *       thread-local storage.
 *
 * @return 1 if enabled or 0 if disabled.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPDebugEnabled(void);

/**
 * @brief Macro to print message if in debug mode.
 *
 * @sa SYNOLDAPDebugEnabled()
 */
#define SYNOLDAP_DEBUG(fmt...) do {  \
	if (SYNOLDAPDebugEnabled()) {    \
		SYSLOG(LOG_ERR, fmt);        \
	}                                \
} while (0)

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_DEBUG_H__
// vim:ts=4 sts=4 sw=4
