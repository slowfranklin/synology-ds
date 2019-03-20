// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOSHARE_UTILS_H__
#define __SYNOSHARE_UTILS_H__

#include <synosdk/share.h>
#include <synocore/list.h>
#include <synofileop/copy.h>
#include <synocore/mresult.h>

__BEGIN_DECLS;

#define SHARE_UUID_LENGTH   36  // without terminating null

typedef struct _tag_share_def_option_ {
	const char * szShareName;
	const char * szSharePath;
	const char * szDevName; //device name for USB/SATA device
	BOOL blForcePosix;  // Force using Posix mode
}SHARE_DEF_OPTION;

typedef struct _SYNOSHAREARGS *PSYNOSHAREARGS;

#ifdef SYNOSHARE_ENABLE_CUSTOM_OPERATIONS

/**
 * Custom callback to create a share entity.
 * See SYNOShareCreateEntity() for example.
 *
 * @return 0: On success.
 * @return -1: On error to terminate the creation.
 */
typedef int (*PFUNC_SHARE_CREATE)(
	const PSYNOSHARE pShare,  // [IN] Share handle, must not be NULL.
	void *pData               // [IN] User data, may be NULL.
);

/**
 * Custom callback to rename a share entity.
 * See SYNOShareRenameEntity() for example.
 *
 * @return 0: On success.
 * @return -1: On error to terminate the rename.
 */
typedef int (*PFUNC_SHARE_RENAME)(
	const PSYNOSHARE pOldShare,  // [IN] Old share handle, must not be NULL.
	const PSYNOSHARE pNewShare,  // [IN] New share handle, must not be NULL.
	void *pData                  // [IN] User data, may be NULL.
);

/**
 * Custom callback to delete a share entity.
 * See SYNOShareDeleteEntity() for example.
 *
 * Push path into @a ppListRm if you want SYNOShareCustomDelete() to `rm -rf' it.
 * Therefore, DO NOT clear @a ppListRm.
 *
 * @return 0: On success.
 * @return -1: On error.
 */
typedef int (*PFUNC_SHARE_DELETE)(
	const PSYNOSHARE pShare,  // [IN] Share handle, must not be NULL.
	BOOL blCleanData,         // [IN] Whether to clean data.
	PSLIBSZLIST *ppListRm,    // [OUT] List of paths to rm, must not be NULL.
	void *pData               // [IN] User data, may be NULL.
);

/**
 * Custom callback to move a share entity.
 * See SYNOShareMoveEntity() for example.
 *
 * @return 0: On success.
 * @return -1: On error to terminate the move.
 */
typedef int (*PFUNC_SHARE_MOVE)(
	const PSYNOSHARE pOldShare,  // [IN] Old share handle, must not be NULL.
	const PSYNOSHARE pNewShare,  // [IN] New share handle, must not be NULL.
	PFUNC_Prog pProgFunc,        // [IN] Callback to report progress.
	PFUNC_ErrReport pErrFunc,    // [IN] Callback to report error.
	void *pData                  // [IN] User data, may be NULL.
);

#endif   // SYNOSHARE_ENABLE_CUSTOM_OPERATIONS

#ifndef NO_PROTO
#include "utils_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOSHARE_UTILS_H__
