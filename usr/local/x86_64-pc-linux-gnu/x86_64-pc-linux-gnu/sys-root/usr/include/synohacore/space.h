#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_SPACE_H
#define __SYNOHACORE_SPACE_H

#include <sys/cdefs.h>

typedef enum {
	HA_REMOTE_CHECK_TYPE_NONE = 0x00,
	HA_REMOTE_DISK_CHECK = 0x01,
	HA_REMOTE_SPACE_CHECK_NORMAL = 0x02,
	HA_REMOTE_SPACE_CHECK_NORMAL_OR_DEGRADE = 0x04,
	HA_REMOTE_SPACE_SYNC_DONE = 0x08,
	HA_REMOTE_CHECK_FCACHE = 0x10,
	HA_REMOTE_REPAIR_CHECK = 0x20,
	HA_REMOTE_EXPAND_CHECK = 0x40,
} HA_REMOTE_CHECK_TYPE;

typedef enum {
	DATA_SCRUBBING_DO,
	DATA_SCRUBBING_CANCEL,
	DATA_SCRUBBING_MAX,
} DATA_SCRUBBING_OPERATION;

typedef enum {
	HA_MISMATCH_DISK_NONE = 0x00,
	HA_MISMATCH_DISK_SIZE = 0x01,
	HA_MISMATCH_DISK_TYPE = 0x02,
	HA_MISMATCH_DISK_LOG_SECT_SIZE = 0x03,
	HA_MISMATCH_DISK_EMPTY = 0x04,
} HA_MISMATCH_DISK_ENUM;

__BEGIN_DECLS

/**
 * Pre-action needed before expansion/resizing of space
 *
 * @param [in] szSpacePath space path
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int HASpaceExpandResizePre(const char* szSpacePath);

/**
 * Sync system partition layout to remote server
 *
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASetRemoteSysPart(void);

/**
 * Start to trim remote ssd space
 *
 * @param [in] szSpacePath space path
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASSDRemoteTrim(const char* szSpacePath);

__END_DECLS

#ifdef MY_ABC_HERE

typedef enum {
	FAKE_DRBD_NONE,
	FAKE_DRBD_PRIMARY,
	FAKE_DRBD_SECONDARY,
} FAKE_DRBD_ROLE;

int HANoSpaceFakeDRBDRoleSet(const FAKE_DRBD_ROLE fakeRole);
FAKE_DRBD_ROLE HANoSpaceFakeDRBDRoleGet();
void HANoSpaceFakeDRBDRoleClear();

#endif /* MY_ABC_HERE */

#endif
