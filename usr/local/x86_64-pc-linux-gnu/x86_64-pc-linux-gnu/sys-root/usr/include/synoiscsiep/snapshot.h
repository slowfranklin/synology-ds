/* Copyright (c) 2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_SNAPSHOT_H_
#define _SYNOISCSIEP_SNAPSHOT_H_

#include <synocore/conf.h>
#include <synosdk/log.h>
#include <synoiscsiep/lun.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_SNAPSHOT_EXPORT_PROG_PATH_FORMAT    ISCSI_TMP_DIR_PATH "/L%d_S%d.export_progress"
#define ISCSI_SNAPSHOT_ISS_CONN_PATH              "/tmp/synocomm_iss.conn"

/*** constants ***/
#define ISCSI_SNAPSHOT_MIN_SID                    1
#define ISCSI_SNAPSHOT_MAX_SID                    256
#define ISCSI_SNAPSHOT_SCHE_TASK_NAME_SIZE        256
#define ISCSI_SNAPSHOT_STATUS_SIZE                32
#define ISCSI_SNAPSHOT_TOKEN_BY_SIZE              32
#define ISCSI_SNAPSHOT_NOTE_SIZE                  1024
#define ISCSI_SNAPSHOT_MAX_APP_KEY_SIZE           128
#define ISCSI_SNAPSHOT_TIME_STR_SIZE              20
#define ISCSI_SNAPSHOT_HEALTHY                    "Healthy"
#define ISCSI_SNAPSHOT_UNHEALTHY                  "Unhealthy"
#define ISCSI_SNAPSHOT_TYPE_APP                   "app"
#define ISCSI_SNAPSHOT_TYPE_CRASH                 "crash"
#define ISCSI_SNAPSHOT_BY_HAND                    "hand"
#define ISCSI_SNAPSHOT_BY_USER                    "user"
#define ISCSI_SNAPSHOT_BY_SCHEDULER               "scheduler"
#define ISCSI_SNAPSHOT_BY_WEBAPI                  "webapi"
#define ISCSI_SNAPSHOT_BY_TOOL                    "synoiscsitool"
#define ISCSI_SNAPSHOT_BY_REPAIRED                "repaired"
#define ISCSI_SNAPSHOT_DELETED_BY_USER            "user"
#define ISCSI_SNAPSHOT_DELETED_BY_RETENTION_RULE  "retention rule"
#define ISCSI_SNAPSHOT_DELETED_BY_ROTATION        "rotation"
#define ISCSI_SNAPSHOT_DELETED_BY_WEBAPI          "webapi"
#define ISCSI_SNAPSHOT_DELETED_BY_SYNOISCSIEP     "synoiscsiep"

#define ISCSI_SNAPSHOT_USE_TRASH                  (0b1)
#define ISCSI_SNAPSHOT_USE_UNSYNC_SIZE            (0b10)
#define ISCSI_SNAPSHOT_USE_NO_APP_KEY             (0b100)
#define ISCSI_SNAPSHOT_USE_SCHEDULED              (0b1000)
#define ISCSI_SNAPSHOT_USE_CONFIG_ONLY            (0b10000)
#define ISCSI_SNAPSHOT_USE_CACHE_ONLY             (0b100000)

/*** keys ***/
#define ISCSI_SNAPSHOT_MAX_COUNT_KEY              "max_snapshot_per_lun"
#define ISCSI_SNAPSHOT_ISS_CID                    "cid"
#define ISCSI_SNAPSHOT_ISS_IP                     "ip"

/*** etc ***/
#define ISCSI_SNAPSHOT_TAG                        "SNAPSHOT_"
#define ISCSI_SNAPSHOT_EMPTY_VERSION              "00000000-0000-0000-0000-000000000000"
#define ISCSI_SNAPSHOT_SCHEDULER_CMD              "/usr/syno/bin/synosnapschedtask.sh local lun %s"

/*** types ***/
typedef enum _tag_iscsi_snapshot_progress_step_ {
	ISCSI_SNAPSHOT_CREATING,
	ISCSI_SNAPSHOT_DELETING,
	ISCSI_SNAPSHOT_USING,
	ISCSI_SNAPSHOT_PROCESSING,
	ISCSI_SNAPSHOT_FINISH,
} ISCSI_SNAPSHOT_PROGRESS_STEP;

typedef struct _tag_iscsi_snapshot_progress_state_ {
	int lid;
	int sid;
	ISCSI_SNAPSHOT_PROGRESS_STEP st;
	char szName[MAX_LEN_ISCSI_NAME];
	uint64_t doneBytes;
	uint64_t totalBytes;
} ISCSI_SNAPSHOT_PROGRESS_STATE;

typedef struct _tag_iscsi_snapshot_export_config_ {
	uint64_t u64TotalFiles;
	uint64_t exportSize;
	unsigned int extentSize;
	char szStatus[16];
	char szNote[ISCSI_SNAPSHOT_NOTE_SIZE];
	char szTakenBy[ISCSI_SNAPSHOT_TOKEN_BY_SIZE];
	time_t snapshotTime;
	bool blAppConsistent;
	bool blLock;
} ISCSI_SNAPSHOT_EXPORT_CONFIG;

typedef enum _tag_iscsi_snapshot_type_ {
	ISCSI_SNAPSHOT_TYPE_UNKNOWN,

	ISCSI_SNAPSHOT_TYPE_ADV,
	ISCSI_SNAPSHOT_TYPE_BLUN,

	ISCSI_SNAPSHOT_TYPE_BOUND,
} ISCSI_SNAPSHOT_TYPE;

typedef struct _tag_iscsi_snapshot_ {
	int lid;
	int sid;
	int fdLock;
	int use;
	ISCSI_SNAPSHOT_TYPE type;
	uint64_t totalSize;
	uint64_t mappedSize;
	time_t createTime;
	time_t snapshotTime;
	bool blAppConsistent;
	bool blLock;
	char szName[MAX_LEN_ISCSI_NAME];
	char szStatus[ISCSI_SNAPSHOT_STATUS_SIZE];
	char szNote[ISCSI_SNAPSHOT_NOTE_SIZE];
	char szRootPath[MAX_PATH_LEN];
	char szTakenBy[ISCSI_SNAPSHOT_TOKEN_BY_SIZE];
	char szUUID[ISCSI_UUID_STRING_SIZE];
	char szParentUUID[ISCSI_UUID_STRING_SIZE];
	char szVersion[ISCSI_UUID_STRING_SIZE];
	SYNO_LINKED_LIST list;
} ISCSI_SNAPSHOT;

typedef enum _tag_iscsi_snapshot_filter_type_ {
	ISCSI_SNAPSHOT_ALL              = 0x0000,
	ISCSI_SNAPSHOT_BY_ROOT_PATH     = 0x0001,
	ISCSI_SNAPSHOT_BY_LID           = 0x0002,
	ISCSI_SNAPSHOT_BY_SID           = 0x0004,
	ISCSI_SNAPSHOT_BY_LID_EXCLUD    = 0x0008,
	ISCSI_SNAPSHOT_BY_PARENTLID     = 0x0010,
	ISCSI_SNAPSHOT_BY_UUID          = 0x0020,
	ISCSI_SNAPSHOT_BY_SNAPSHOT_TIME = 0x0040,
	ISCSI_SNAPSHOT_BY_NAME          = 0x0080,
	ISCSI_SNAPSHOT_BY_PARENT_UUID   = 0x0100,
	ISCSI_SNAPSHOT_BY_FIRST_MATCHED = 0x0200,
} ISCSI_SNAPSHOT_FILTER_TYPE;

typedef struct _tag_iscsi_snapshot_filter_ {
	ISCSI_SNAPSHOT_FILTER_TYPE type;
	int lid;
	int sid;
	const char *szRootPath;
	const char *szUUID;
	const char *szName;
	const char *szParentUUID;
	time_t snapshot_time;
} ISCSI_SNAPSHOT_FILTER;

typedef struct _tag_iscsi_snapshot_config_ {
	int snapshot_cnt;
	SYNO_LINKED_LIST snaps;
} ISCSI_SNAPSHOT_CONFIG, *PISCSI_SNAPSHOT_CONFIG;

typedef struct _tag_iscsi_family_ {
	int lid;
	int parentLID;
	int parentSID;
	time_t time;
	char szStatus[ISCSI_SNAPSHOT_STATUS_SIZE];
	SYNO_LINKED_LIST list;
} ISCSI_FAMILY;

typedef enum _tag_iscsi_family_filter_type_ {
	ISCSI_FAMILY_ALL                 = 0x0000,
	ISCSI_FAMILY_BY_LID              = 0x0001,
	ISCSI_FAMILY_BY_PARENTLID        = 0x0002,
	ISCSI_FAMILY_BY_PARENTSID        = 0x0004,
	ISCSI_FAMILY_BY_LID_OR_PARENTLID = 0x0008,
} ISCSI_FAMILY_FILTER_TYPE;

typedef struct _tag_iscsi_family_filter_ {
	ISCSI_FAMILY_FILTER_TYPE type;
	int lid;
	int parentLID;
	int parentSID;
} ISCSI_FAMILY_FILTER;

typedef struct _tag_iscsi_family_config_ {
	int family_cnt;
	SYNO_LINKED_LIST families;
} ISCSI_FAMILY_CONFIG;

typedef struct _tag_schedule_snapshot_task_ {
	int tid;
	int lid;
	char szName[ISCSI_SNAPSHOT_SCHE_TASK_NAME_SIZE];
	char szType[16];
	SYNO_LINKED_LIST list;
} SCHEDULE_SNAPSHOT_TASK, *PSCHEDULE_SNAPSHOT_TASK;

typedef enum _tag_schedule_snapshot_task_filter_type_ {
	ISCSI_SNAPSHOT_SCHE_TASK_ALL         = 0x0000,
	ISCSI_SNAPSHOT_SCHE_TASK_BY_TID      = 0x0001,
	ISCSI_SNAPSHOT_SCHE_TASK_BY_LID      = 0x0002,
} SCHEDULE_SNAPSHOT_TASK_FILTER_TYPE;

typedef struct _tag_schedule_snapshot_task_filter_ {
	SCHEDULE_SNAPSHOT_TASK_FILTER_TYPE type;
	int tid; //Task ID
	int lid; //Lun ID
} SCHEDULE_SNAPSHOT_TASK_FILTER;

typedef struct _tag_schedule_snapshot_task_config_ {
	int task_cnt;
	SYNO_LINKED_LIST tasks;
} SCHEDULE_SNAPSHOT_TASK_CONFIG, *PSCHEDULE_SNAPSHOT_TASK_CONFIG;

/*** macro or inline functions ***/
#define LIST_SNAPSHOT_CONFIG_HEAD_INIT(p_config)                         \
	do {                                                                 \
		LIST_HEAD_INIT(&(p_config)->snaps);                              \
	} while (0)

#define LIST_SNAPSHOT_CONFIG_HEAD_FREE(p_config)                         \
	do {                                                                 \
		if ((p_config)->snapshot_cnt) {                                  \
			LIST_FREE(&(p_config)->snaps, ISCSI_SNAPSHOT, list);         \
			(p_config)->snapshot_cnt = 0;                                \
		}                                                                \
	} while (0)

#define LIST_FAMILY_CONFIG_HEAD_INIT(p_config)                           \
	do {                                                                 \
		(p_config)->family_cnt = 0;                                        \
		LIST_HEAD_INIT(&(p_config)->families);                           \
	} while (0)

#define LIST_FAMILY_CONFIG_HEAD_FREE(p_config)                           \
	do {                                                                 \
		if ((p_config)->family_cnt) {                                    \
			LIST_FREE(&(p_config)->families, ISCSI_FAMILY, list);        \
			(p_config)->family_cnt = 0;                                  \
		}                                                                \
	} while (0)

#define LIST_SS_TASK_CONFIG_HEAD_INIT(p_config)                          \
	do {                                                                 \
		LIST_HEAD_INIT(&(p_config)->tasks);                              \
	} while (0)

#define LIST_SS_TASK_CONFIG_HEAD_FREE(p_config)                          \
	do {                                                                 \
		if ((p_config)->task_cnt) {                                      \
			LIST_FREE(&(p_config)->tasks, SCHEDULE_SNAPSHOT_TASK, list); \
			(p_config)->task_cnt = 0;                                    \
		}                                                                \
	} while (0)

static inline bool valid_sid_index(int id)
{
	return (ISCSI_SNAPSHOT_MIN_SID <= id) && (ISCSI_SNAPSHOT_MAX_SID >= id);
}

static inline char * SYNOiSCSIGetSnapshotTimeStr(time_t time, char *timeStr, size_t strLength) {
	struct tm *timeStamp = localtime(&time);

	strftime(timeStr, strLength, "%Y/%m/%d %T", timeStamp);

	return timeStr;
}

// Snapshot Use Tools
static inline void SYNOiSCSISnapshotUseAdd(ISCSI_SNAPSHOT *pSnapshot, int use) {
	pSnapshot->use |= use;
}
static inline void SYNOiSCSISnapshotUseRemove(ISCSI_SNAPSHOT *pSnapshot, int use) {
	pSnapshot->use &= ~use;
}

// Snapshot Path Getter
static inline void SYNOiSCSISnapshotLogSet1(
		int eventType,
		unsigned long eventID,
		const char *szArg1,
		const char *szArg2,
		const char *szArg3,
		const char *szArg4) {
	bool blIsDRSupported = (TRUE == SLIBCFileCheckKeyValue(SZF_DEF_SYNOINFO, ISCSI_DR_SNAP_SUPPORT_KEY, SZV_YES, FALSE));

	SYNOLogSet1(blIsDRSupported ? LOG1_DR : LOG1_SYS, eventType, eventID, szArg1, szArg2, szArg3, szArg4);
}

static inline const char * SYNOiSCSISnapshotErrMsg(int errorCode)
{
	switch (errorCode) {
	case ERR_ISCSI_OUT_OF_FREE_SPACE:
		return "Out of volume space";
	case ERR_ISCSI_REACH_MAX_SNAPSHOT_COUNT:
		return "Maximum snapshot count reached";
	default:
		return "Internal error";
	}
}

/*** function declarations ***/
int  SYNOiSCSIFamilyConfCloneParentGet(const int lid, int *pLid, int *pSid);
int  SYNOiSCSIFamilyConfGetByLid(const int lid, ISCSI_FAMILY *pFamily);
int  SYNOiSCSIFamilyConfLoad(const ISCSI_FAMILY_FILTER *pFamilyFilter, ISCSI_FAMILY_CONFIG *pFamilyConf);
int  SYNOiSCSISnapshotClone(ISCSI_SNAPSHOT *pSnapshot, ISCSI_LUN *pCloneLun);
int  SYNOiSCSISnapshotConfAdd(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfGetByLid(int lid, ISCSI_SNAPSHOT_CONFIG *pSnapConfig);
int  SYNOiSCSISnapshotConfGetByLidAndName(int lid, const char *szName, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfGetBySid(const int lid, const int sid, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfGetByUuid(const char *szUUID, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfLoad(const ISCSI_SNAPSHOT_FILTER *pSnapFilter, ISCSI_SNAPSHOT_CONFIG *pSnapConfig);
int  SYNOiSCSISnapshotConfLoadByParentUuid(const char *szParentUuid, ISCSI_SNAPSHOT_FILTER *pSnapFilter, ISCSI_SNAPSHOT_CONFIG *pSnapConfig);
int  SYNOiSCSISnapshotCreate(ISCSI_LUN *pLun, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotDelete(ISCSI_SNAPSHOT *pSnapshot, const char *szDeletedBy);
int  SYNOiSCSISnapshotExportCancel(ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotExportConfigGet(const char *szConfigDirPath, ISCSI_SNAPSHOT_EXPORT_CONFIG *pConfig);
int  SYNOiSCSISnapshotExport(ISCSI_SNAPSHOT *pSnapshot, const char *szExportDstPath);
int  SYNOiSCSISnapshotIsLockedByApp(const ISCSI_SNAPSHOT *pSnapshot, bool *blIsLockedByApp);
int  SYNOiSCSISnapshotIsLocked(ISCSI_SNAPSHOT *pSnapshot, bool *blIsLocked);
bool SYNOiSCSISnapshotIsQuantityLimitReached(ISCSI_LUN *pLun);
bool SYNOiSCSISnapshotIsSpaceEnoughToClone(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotLoad(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotLockByAppKey(const ISCSI_SNAPSHOT *pSnapshot, char *szAppKey);
int  SYNOiSCSISnapshotLock(ISCSI_SNAPSHOT *pSnapshot, ISCSI_SNAPSHOT_PROGRESS_STEP step);
int  SYNOiSCSISnapshotLockedAppKeysGet(const ISCSI_SNAPSHOT *pSnapshot, SLIBSZLIST *pList);
int  SYNOiSCSISnapshotProgressGet(ISCSI_SNAPSHOT *pSnapshot, ISCSI_SNAPSHOT_PROGRESS_STATE *pProgress);
int  SYNOiSCSISnapshotQuantityGet(ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotQuantityLimitGet();
int  SYNOiSCSISnapshotRestore(ISCSI_SNAPSHOT *pSnapshot, ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotScheduleConfAdd(const SCHEDULE_SNAPSHOT_TASK *pTask);
int  SYNOiSCSISnapshotScheduleConfLoad(const SCHEDULE_SNAPSHOT_TASK_FILTER *pFilter, SCHEDULE_SNAPSHOT_TASK_CONFIG *pTaskConfig);
int  SYNOiSCSISnapshotScheduleGetStidByLid(const int lid);
int  SYNOiSCSISnapshotScheduleRun(const SCHEDULE_SNAPSHOT_TASK *pTask);
void SYNOiSCSISnapshotScheduleTaskConfigFree(SCHEDULE_SNAPSHOT_TASK_CONFIG *pIscsiConfig);
int  SYNOiSCSISnapshotSyncProgressGet(const ISCSI_SNAPSHOT *pSnapshot, uint64_t *pParentTotalCount, uint64_t *pSyncedCount);
int  SYNOiSCSISnapshotUnload(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotUnlockByAppKey(const ISCSI_SNAPSHOT *pSnapshot, const char *szAppKey);
int	 SYNOiSCSISnapshotUnusedNameFind(int lid, char *szUnusedName, int cbUnusedName);
int  SYNOiSCSISnapshotUuidGenerate(char *szUuid);
int  SYNOiSCSISnapshotWaitUntilUnlock(ISCSI_SNAPSHOT *pSnapshot, unsigned int timeout);

// in lib/synocomm
int ISSClientConnSectionLoad(PSLIBSZLIST *ppslSections);

// For compatibility in project: libsynodr
#define SZV_SNAPSHOT_HEALTHY ISCSI_SNAPSHOT_HEALTHY
#define ScheduleSnapshotTaskGetIDByLid(lid) SYNOiSCSISnapshotScheduleGetStidByLid(lid)

__END_DECLS;

#endif // _SYNOISCSIEP_SNAPSHOT_H_
