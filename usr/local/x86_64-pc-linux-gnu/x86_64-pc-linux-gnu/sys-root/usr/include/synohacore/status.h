#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_STATUS_H
#define __SYNOHACORE_STATUS_H

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS

/**
 * Check if HA is running.
 *
 * This function is called from scemd regularly.
 * check order: is_running tmp file -> is_not_running tmp file -> synoinfo.conf to prevent wake up hdd
 *
 * @retval TRUE running
 * @retval FALSE not running or others
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @ingroup ha
 */
BOOL SYNOHAIsRunning(void);

/**
 * Check if current node is active node.
 *
 * Use @ref SYNOHANodeRoleGet to get detailed role type.
 *
 * @retval TRUE local role is active
 * @retval FALSE not running or others (passive, prepare, error)
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @ingroup ha
 */
BOOL SYNOHAIsActive(void);

/**
 * Check if HA is in HA safe mode.
 *
 * Don't be confused with UPS safe mode.
 *
 * @retval TRUE HA cluster is in safe mode 
 * @retval FALSE HA cluster is not in safe mode
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
BOOL SYNOHAIsSafemode(void);

/**
 * Check if HA is running in hybrid mode.
 *
 * @retval 1 HA is running in hybrid mode, i.e., active and passive server are different models.
 * @retval 0 HA is not running in hybrid mode.
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAIsHybridDL(char* szRemoteModel, size_t cbRemoteModel);

/**
 * Get HA status in System Health Widget
 *
 * @param [out] szStatus HA Status
 * @param [in]  cSize    size of szStatus
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
void SYNOHAGetOverviewStatusDL(char* szStatus, unsigned int cSize);

__END_DECLS

#ifdef MY_ABC_HERE

typedef enum _tag_HAStatus_ {
	HA_UNKNOWN,
	HA_HEALTHY,
	HA_WARNING,
	HA_ERROR,
	HA_STANDALONE,
	HA_EMPTY_PASSIVE,
} HAStatus;

// stage of node binding
typedef enum _tag_BindingProgress {
	BIND_UNKNOWN,
	BIND_SETUP_COMM,
	BIND_VERIFY,
	BIND_BUILD_PASSIVE_SPACE,
	BIND_SYNC_PASSIVE_CONF,
	BIND_SETUP_RESOURCE,
	BIND_REBOOT_PASSIVE,
	BIND_DONE,
	BIND_FAILED,
} BindingProgress;

// stage of node binding
typedef enum _tag_UnbindingProgress {
	UNBIND_UNKNOWN,
	UNBIND_PREPARE,
	UNBIND_REMOTE,
	UNBIND_LOCAL,
} UnbindingProgress;

HAStatus HAStatusGet(void);
int BindingProgressGet(BindingProgress*);
int BindingProgressSet(const BindingProgress);
int UnbindingProgressGet(UnbindingProgress*);
int UnbindingProgressSet(const UnbindingProgress);

BOOL PcmkIsRunning(void);
BOOL HAIsRunningCoroPace(void);
BOOL HAIsBinding(void);
BOOL HAIsUpgrading();

#endif /* MY_ABC_HERE */

#endif
