// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOSHARESNAPSHOT_SNAPSHOT_H__
#define __SYNOSHARESNAPSHOT_SNAPSHOT_H__

#include <synosdk/plugin.h>
#include <synosdk/share.h>
#include <synosdk/fs.h>
#include <openssl/md5.h>
#include <synofileop/ea.h>
#include <synostoragecore/fs.h>

#define SZK_SHARESNAP_SUPPORT_KEY_SUPPORT_BTRFS "support_btrfs"
#define SZD_SHARESNAP_RESTORE "@sharesnap_restoring"
#define SZ_SHARESNAP_METAFILE_PREFIX "@"
#define SZ_SHARESNAP_METAFILE_POSTFIX ".meta"
#define SZD_SHARESNAP_EXPORT "#snapshot"
#define SZD_SHARESNAP_ATSHARESNAP "@sharesnap"
#define SZF_DESKTOP_INI "desktop.ini"

#define SHARESNAP_META_KEY_LEN 64
#define SHARESNAP_META_VALUE_LEN 512
#define SHARESNAP_META_SECTION_NUM 64
#define SZK_SCHEDULE_SNAPSHOT "schedule_snapshot"
#define SZK_SPECIAL_LOCK "special_lock"
#define SHARESNAP_SNAPNAME_FORMAT "GMT-%Y.%m.%d-%H.%M.%S"
#define SHARESNAP_SNAPNAME_LOCAL_TIME_FORMAT "GMT%z-%Y.%m.%d-%H.%M.%S"
#define SHARESNAP_SNAPNAME_LOCAL_TIME_FORMAT_TEMPLATE "GMT%s-%%Y.%%m.%%d-%%H.%%M.%%S"
#define SHARESNAP_LOCALTIME false
#define SHARESNAP_META_FORMAT "%s=%s\n"
#define UUID_BUF_LEN 40
#define SHARESNAP_DEFAULT_MAX_SNAPSHOT 1024
#define SHARESNAP_DEFAULT_GLOBAL_MAX_SNAPSHOT 65536
#define SHARESNAP_VOLUME_RESERVED_SPACE_FOR_SNAP_CREATE_MB 100

#define SZD_RUN_SHARESNAP "/run/sharesnap"
#define SZD_RUN_LOCK_SHARESNAP "/run/lock/sharesnap"
#define SZD_SHARESNAP_META_LOCK SZD_RUN_LOCK_SHARESNAP"/sharesnap_meta_lock"
#define SZD_SYNO_ETC_SHARESNAP "/usr/syno/etc/sharesnap"
#define SZF_SHARESNAP_CONF SZD_SYNO_ETC_SHARESNAP"/sharesnap.conf"
#define SZF_SHARESNAP_CONF_LOCK SZD_RUN_LOCK_SHARESNAP"/sharesnap_conf.lock"
#define SZF_SHARESNAP_RESTORE_LOCK SZD_RUN_LOCK_SHARESNAP"/sharesnap_restore.lock"
#define SZF_SHARESNAP_RESTORE_COUNT SZD_RUN_LOCK_SHARESNAP"/sharesnap_restore_count"
#define SZF_SYNOSHARESNAP_BIN "/usr/syno/sbin/synosharesnap"
#define SZF_SYNOSHARESNAPSCHED_BIN "/usr/syno/bin/synosnapschedtask.sh"
#define SZV_DESC_SCHEDULE_SNAPSHOT "Schedule Snapshot"
#define SZ_SCHEDULE_SNAPSHOT_CMD SZF_SYNOSHARESNAPSCHED_BIN" local share \"%s\""
#define SZ_SHARE_SNAPSHOT "Share [%s] Snapshot"
#define SZ_SHARESNAP_USER "user"
#define SZ_SHARESNAP_SCHEDULER "scheduler"
#define SZ_SHARESNAP_RETENTION_RULE "retention rule"
#define SZK_SCHEDULE_SNAPSHOT_TASKID "schedule_task_id"
#define SZK_LAST_RESTORE "last_restore"
#define SZK_MAX_SHARE_SNAPSHOTS "max_snapshots_per_share"
#define SZK_GLOBAL_MAX_SHARE_SNAPSHOTS "max_share_snapshots"
#define SHARESNAP_CONF_LOCK_TIMEOUT 5
#define SHARESNAP_META_LOCK_TIMEOUT 2
#define SHARESNAP_RESTORE_LOCK_TIMEOUT 2
#define SZK_SHARESNAP_TIME "time"
#define SZK_SHARESNAP_ENABLE_LOCAL_TIME_FORMAT "local_time_format"

#define SZK_SHARESNAP_SNAPCOUNT "user.snapcount"
#define SZD_SHARESNAP_SNAPCOUNT_LOCK SZD_RUN_LOCK_SHARESNAP"/sharesnap_snapcount_lock"
#define SHARESNAP_SNAPCOUNT_LOCK_TIMEOUT 5

#define SHARESNAP_MKDIR(path, mode, tag) \
do { \
	if ((-1 == mkdir(path, mode)) && (EEXIST != errno)) {\
		SYSLOG(LOG_ERR, "Failed to mkdir [%s], errno=%d/%m\n", path, errno);\
		SLIBCErrSet(ERR_CREATE_FAILED);\
		goto tag;\
	}\
}while(0)

typedef enum _tag_snap_enum_function_ret {
	SNAP_ENUM_SELECT,          //select the snapshot
	SNAP_ENUM_NOT_SELECT,      //not select the snapshot
	SNAP_ENUM_SUCCESS_STOP,    //stop select and return success
	SNAP_ENUM_ERROR_STOP       //stop select and return error
} SNAP_ENUM_FUNC_RET;

typedef enum {
	SNAP_TIME_NONE = 0x0,
	SNAP_TIME_GT = 0x1,
	SNAP_TIME_LT = 0x2,
	SNAP_TIME_EQ = 0X4,
} SNAP_TIME_OP;

typedef SNAP_ENUM_FUNC_RET (*PSNAP_SELECTOR_FUNC)(const char *szSnapName, PSLIBSZHASH pHash, uintptr_t pData);
typedef struct _tag_SYNO_SHARE_SNAP_ENUM {
	PSNAP_SELECTOR_FUNC pSelector;
	uintptr_t pData;
	struct _tag_SYNO_SHARE_SNAP_ENUM *pNext;
} SYNOSHARESNAPENUM, *PSYNOSHARESNAPENUM, **PPSYNOSHARESNAPENUM;

typedef enum {
	SNAP_NONE = 0x0,
	SNAP_CREATE = 0x1,
	SNAP_DELETE = 0x2,
	SNAP_RESTORE = 0x4,
	SNAP_CLONE = 0x8,
	SNAP_BIND = 0x10,
	SNAP_SEND = 0x20,
	SNAP_RECEIVE = 0x40,
	SNAP_EXPORT = 0x80,
	SNAP_IMPORT = 0x100,
	SNAP_ALL = SNAP_CREATE | SNAP_DELETE | SNAP_RESTORE | SNAP_CLONE | SNAP_BIND | SNAP_SEND | SNAP_RECEIVE | SNAP_EXPORT | SNAP_IMPORT
} SNAPSHOT_ACTION;

#define SZK_SHARESNAP_RETENTION_PREFIX "Share#"

typedef enum {
	SNAP_SHARE_INFO_COMMENT = 0x1 << 0,
	SNAP_SHARE_INFO_SMB_PERM = 0x1 << 1,
	SNAP_SHARE_INFO_BROWSEABLE = 0X1 << 2,
	SNAP_SHARE_INFO_FTPPRIVILEGE = 0X1 << 3,
	SNAP_SHARE_INFO_STATUS = 0X1 << 4,
	SNAP_SHARE_INFO_SHARE_QUOTA = 0X1 << 5,
	SNAP_SHARE_INFO_COW = 0X1 << 6,
	SNAP_SHARE_INFO_COMPRESSION = 0X1 << 7,
	SNAP_SHARE_INFO_USER_QUOTA = 0X1 << 8,
	SNAP_SHARE_INFO_ALL = (SNAP_SHARE_INFO_COMMENT | SNAP_SHARE_INFO_SMB_PERM | SNAP_SHARE_INFO_BROWSEABLE |
							SNAP_SHARE_INFO_FTPPRIVILEGE | SNAP_SHARE_INFO_STATUS | SNAP_SHARE_INFO_SHARE_QUOTA |
							SNAP_SHARE_INFO_COW | SNAP_SHARE_INFO_COMPRESSION | SNAP_SHARE_INFO_USER_QUOTA ),
} SNAP_SHARE_INFO_FLAG;

typedef struct {
	char* szComment;
	char* szDeny;
	char* szRW;
	char* szRO;
	int fBrowseable;
	int fFTPPrivilege;
	SHARE_STATUS status;
	unsigned long long shareQuota;
	BOOL cow;
	BOOL compression;
	SNAP_SHARE_INFO_FLAG flags;
}ShareSnapInfo, *PShareSnapInfo;

__BEGIN_DECLS;

#ifndef NO_PROTO
#include "snapshot_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOSHARESNAPSHOT_SNAPSHOT_H__
