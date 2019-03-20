// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_UPGRADE_H
#define __SYNOHACORE_UPGRADE_H

#include <sys/cdefs.h>

#define SZF_UPGRADE_UPDATER_ZIP_FOR_PASSV       "/upd@te_passv.pat"

typedef enum {
	/** Start upgrading */
	HA_UPG_TYPE_START,
	/** Check space status before upgrading */
	HA_UPG_TYPE_CHKSPACE,
	/** Check HA status before upgrading */
	HA_UPG_TYPE_CHKHEALTHY,
	/** Report failure and restore without unbinding any node */
	HA_UPG_TYPE_FAIL_AND_RESET,
	/** Report failure and unbind failed node */
	HA_UPG_TYPE_FAIL,
	/** Prepare small update files for passive server */
	HA_UPG_TYPE_INIT_SMALLUPDATE,
} HA_UPG_TYPE;

__BEGIN_DECLS

/**
 * Handle HA upgrading
 *
 * @param [in] type action type
 * @retval 0 success
 * @retval -1 error
 * @ingroup ha
 * @exception SLIBCFileSetKeyValue
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAUpgradeHandleDL(HA_UPG_TYPE type);

__END_DECLS

#endif
