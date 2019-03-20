// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

#ifndef __SYNO_FEASIBILITY_CHECK_H__
#define __SYNO_FEASIBILITY_CHECK_H__

#include <synocore/list.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SZ_CHECK_CONF_POSTFIX ".cfg"
#define SZ_CHECK_CONF_TASK "task"      //necessary, for syslog
#define SZ_CHECK_CONF_TASK_MULTI_LINGUAL "task_i18n"   //opt, use "task" instead
#define SZ_CHECK_CONF_TYPE "type"      //necessary
#define SZ_CHECK_CONF_PLUGIN "plugin"  //necessary
#define SZ_CHECK_CONF_VER "version"    //necessary

typedef enum {
	FTYPE_SHARE_DELETE = 0,
	FTYPE_SHARE_RENAME,
	FTYPE_SHARE_MOVE,
	FTYPE_FILE_LUN_DELETE,
	FTYPE_VOLUME_DELETE,
	FTYPE_UPGRADE_NOTICE,
	FTYPE_NET_HOSTNAME_CHANGE,
	FTYPE_POWEROFF,
	FTYPE_NET_DHCP_CHANGE,
	FTYPE_NET_OVS_CREATE,
	FTYPE_NET_OVS_DELETE,
	FTYPE_NET_BOND_CREATE,
	FTYPE_NET_BOND_DELETE,
	FTYPE_DIRSVS_LEAVE,
	FTYPE_PACKAGE_INSTALL,
	FTYPE_PACKAGE_UNINSTALL,
	FTYPE_PACKAGE_STOP,
	FTYPE_SHARE_TRANSFORM,
	FTYPE_FILE_LUN_CREATE,
	FTYPE_FILE_LUN_CLONE,
	FTYPE_FILE_LUN_RENAME,
	FTYPE_FILE_LUN_MOVE,
	FTYPE_VOLUME_CREATE,
	FTYPE_POOL_CREATE,
	FTYPE_POOL_DELETE,
	FTYPE_FACTORY_RESET,
	FTYPE_SHARE_CREATE,
	FTYPE_SHARE_CLONE,
	FTYPE_SHARE_UMOUNT,
	FTYPE_LUN_SUBVOL_CONVERT,
	FTYPE_SYNO_ACCOUNT_LOGOUT,
	FTYPE_MAX
} SYNO_FEASIBILITY_TYPE;

typedef enum {
	CTYPE_UNKNOWN = 0x00,
	CTYPE_HARD = 0x01,
	CTYPE_SOFT = 0x02,
	CTYPE_CRIT = 0x04
} SYNO_FEASIBILITY_CHECK_TYPE;

typedef enum {
	STYPE_UNKNOWN = 0x00,
	STYPE_BUILD_IN = 0x01,
	STYPE_PACKAGE = 0x02,
} SYNO_FEASIBILITY_SERV_TYPE;

/**
 * This function does feasibility check.
 *
 * @param eFType [IN] The feasibility check action type.
 *			Ex: share delete, volume delete, ...
 *
 * @param eCheckType [IN] The feasibility check type.
 *			See SYNO_FEASIBILITY_CHECK_TYPE.
 *			Soft check failed means user would have
 *			chance to decide if action proceeds or not.
 *			Hard check failed means action will be blocked.
 *
 * @param ppslTaskMsg [OUT] Can be NULL. All check failed message.
 *			The element would be multilingual-supported,
 *			denoted as section:key of uistring; or simply
 *			just a lettered string.
 *
 * @param szArg [IN] const char* argments. Please give a NULL for last
 *			argumnet.
 *
 * @return <ul>
 *         <li> -1 : On error
 *         <li> 0 : No check or check passed
 *         <li> > 0 : number of failed check
 *         </ul>
 *
 * @apparmor abstractions/libsynofeasibilitycheck
 */
int SYNOFeasibilityCheck(SYNO_FEASIBILITY_TYPE eFType, unsigned int eCheckType, PPSLIBSZLIST ppslTaskMsg, ...);
int SYNOFeasibilityCheck2Str(const PSLIBSZLIST pslTasks, PSLIBSZLIST *ppslTaskMsg);
int SYNOFeasibilityCheckTypeValidate(const char *szConfType, const SYNO_FEASIBILITY_SERV_TYPE eSType, char *szPath, int cbPath);

#ifdef __cplusplus
}
#endif

#endif	// __SYNO_FEASIBILITY_CHECK_H__
