// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICECTL_H__
#define __SYNO_SERVICECTL_H__

__BEGIN_DECLS;

/**
 * @addtogroup SERVICECTL
 *
 * @brief Some wrappers of initctl in Upstart.
 *
 * @{
 */

#include <synocore/synotype.h>
#include <synocore/hash.h>
#include <synosdk/servicecfg.h>

#define SZD_SERVICECTL_INIT "/etc/init"
#define SZ_SERVICECTL_INICTL "/sbin/initctl"

#define SZ_SERVICECTL_OVERRIDE_POSTFIX ".override"
#define SZ_SERVICECTL_CONF_POSTFIX ".conf"
#define SZ_SERVICECTL_MANUAL "manual"

typedef enum _tag_servicectl_goal_ {
	SLIB_SERVICECTL_START,
	SLIB_SERVICECTL_STOP
} SLIB_SERVICECTL_GOAL;

typedef enum _tag_servicectl_job_ {
	SLIB_SERVICECTL_UPSTART,
	SLIB_SERVICECTL_SYSTEMV
} SLIB_SERVICECTL_JOB;

typedef enum _tag_servicectl_state_ {
	SLIB_SERVICECTL_WAITING,
	SLIB_SERVICECTL_STARTING,
	SLIB_SERVICECTL_PRE_START,
	SLIB_SERVICECTL_SPAWNED,
	SLIB_SERVICECTL_POST_START,
	SLIB_SERVICECTL_RUNNING,
	SLIB_SERVICECTL_PRE_STOP,
	SLIB_SERVICECTL_STOPPING,
	SLIB_SERVICECTL_KILLED,
	SLIB_SERVICECTL_POST_STOP
} SLIB_SERVICECTL_STATE;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/servicectl_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif
