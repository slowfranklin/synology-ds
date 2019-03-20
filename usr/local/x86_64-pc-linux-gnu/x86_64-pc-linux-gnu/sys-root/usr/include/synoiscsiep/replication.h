#ifndef _SYNOISCSIEP_REPLICATION_H_
#define _SYNOISCSIEP_REPLICATION_H_

#include <synoiscsiep/snapshot.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/

/*** constants ***/

/*** keys ***/

/*** etc ***/

/*** types ***/
// iSCSI virtual LUN
typedef enum _tag_viscsi_virtual_lun_type {
	MIRROR_SYNC,
	MIRROR_ASYNC,
	CHILD,
} VISCSI_VIRTUAL_LUN_TYPE;

typedef struct _tag_viscsi_virtual_lun_ {
	int id;
	int sid;
	int srcLid;
	int isAppConsistent;
	int isLocked;
	time_t promoteTime;
	uint64_t u64Size;
	uint64_t u64CBTMappedSize;
	char szBaseVersion[ISCSI_UUID_STRING_SIZE];
	char szName[MAX_LEN_ISCSI_NAME];
	char szRootPath[MAX_PATH_LEN];
	char szUUID[ISCSI_UUID_STRING_SIZE];
	char szNote[ISCSI_VLUN_NOTE_SIZE];
	ISCSI_TRACK_TYPE trackType;
	VISCSI_VIRTUAL_LUN_TYPE type;

	SYNO_LINKED_LIST list;
} VISCSI_VIRTUAL_LUN;

typedef struct _tag_viscsi_virtual_lun_stats_ {
	uint64_t totalSize;
	uint64_t syncSize;
	uint64_t sentSize;
	int errNo;
} VISCSI_VIRTUAL_LUN_STATS;

// iSCSI task
typedef struct _tag_iscsi_task_ {
	char szUUID[ISCSI_UUID_STRING_SIZE];        // Necessary input when creating a destination task
	bool blIsSource;
	char szSrcLUN[ISCSI_UUID_STRING_SIZE];
	char szDstLUN[ISCSI_UUID_STRING_SIZE];
	char szSrcNode[ISCSI_UUID_STRING_SIZE];
	char szDstNode[ISCSI_UUID_STRING_SIZE];
	char szRootPath[ISCSI_MAX_FILE_PATH_SIZE];
	char szParentTask[ISCSI_UUID_STRING_SIZE];  // Filled automatically when creating a task
	SYNO_LINKED_LIST list;
} ISCSI_TASK;

typedef enum _tag_iscsi_task_filter_type_ {
	ISCSI_TASK_ALL                 = 0x0000,
	ISCSI_TASK_BY_UUID             = 0x0001,
	ISCSI_TASK_BY_SOURCE_LUN       = 0x0002,
	ISCSI_TASK_BY_DESTINATION_LUN  = 0x0004,
	ISCSI_TASK_BY_SOURCE_NODE      = 0x0008,
	ISCSI_TASK_BY_DESTINATION_NODE = 0x0010,
	ISCSI_TASK_BY_ROOT_PATH        = 0x0020,
	ISCSI_TASK_BY_PARENT_TASK      = 0x0040
} ISCSI_TASK_FILTER_TYPE;

typedef struct _tag_iscsi_task_filter_ {
	ISCSI_TASK_FILTER_TYPE type;
	const char *szUUID;
	const char *szSrcLUN;
	const char *szDstLUN;
	const char *szSrcNode;
	const char *szDstNode;
	const char *szRootPath;
	const char *szParentTask;
} ISCSI_TASK_FILTER;

typedef struct _tag_iscsi_task_config_ {
	int task_cnt;
	SYNO_LINKED_LIST tasks;
} ISCSI_TASK_CONFIG;

// iSCSI task progress
typedef struct _tag_iscsi_task_progress_ {
	uint64_t totalSize;
	uint64_t syncSize;
	uint64_t sentSize;
	int errorNo;
	char szTask[ISCSI_UUID_STRING_SIZE];
	char szSendingSnapshot[ISCSI_UUID_STRING_SIZE];
	char szBaseSnapshot[ISCSI_UUID_STRING_SIZE];
	SYNO_LINKED_LIST list;
} ISCSI_TASK_PROGRESS;

// iSCSI task unsync size
typedef struct _tag_iscsi_task_unsync_size_ {
	uint64_t totalSize;
	uint64_t scannedSize;
	uint64_t unsyncSize;
	int errorNo;
	char szTask[ISCSI_UUID_STRING_SIZE];
	char szBaseSnapshot[ISCSI_UUID_STRING_SIZE];
	char szSendingSnapshot[ISCSI_UUID_STRING_SIZE];
	char szSourceLUN[ISCSI_UUID_STRING_SIZE];
	SYNO_LINKED_LIST list;
} ISCSI_TASK_UNSYNC_SIZE;

/*** macro or inline functions ***/
#define LIST_ISCSI_TASK_CONFIG_HEAD_INIT(p_config)                                   \
	do {                                                                             \
		LIST_HEAD_INIT(&(p_config)->tasks);                                          \
	} while (0)

#define LIST_ISCSI_TASK_CONFIG_HEAD_FREE(p_config)                                   \
	do {                                                                             \
		if ((p_config)->task_cnt) {                                                  \
			LIST_FREE(&(p_config)->tasks, ISCSI_TASK, list);                         \
			(p_config)->task_cnt = 0;                                                \
		}                                                                            \
	} while (0)

/*** function declarations ***/
int  SYNOiSCSIPureVirtualLunLoad(const char *szSrcUUID);
int  SYNOiSCSIPureVirtualLunUnload(const char *szSrcUUID);
int  SYNOiSCSIReplicationCheckConnection(const char *szHostname, unsigned int dstPort, const char *szRODKey);
int  SYNOiSCSIReplicationConfGetByUuid(const char *szUUID, ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationConfLoad(const ISCSI_TASK_FILTER *pTaskFilter, ISCSI_TASK_CONFIG *pTaskConf);
int  SYNOiSCSIReplicationConvertDstToSrc(ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationConvertSrcToDst(ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationCreate(ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationDelete(const ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationProgressAdd(ISCSI_TASK_PROGRESS *pTaskProgress);
int  SYNOiSCSIReplicationProgressGetByTask(const ISCSI_TASK *pTask, ISCSI_TASK_PROGRESS *pTaskProgress);
int  SYNOiSCSIReplicationSendSnapshot(
		ISCSI_TASK *pTask,
		const char *szDstHostname,
		const char *szRodKey,
		const char *szSendingSnapshot,
		const char *szBaseSnapshot,
		unsigned int dstPort,
		bool blFullSync,
		bool blDataEncrypted,
		bool blLastTry,
		uint64_t initSentSize);
int  SYNOiSCSIReplicationStopSendingSnapshot(ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationUnsyncSizeCompute(const ISCSI_TASK *pTask, ISCSI_SNAPSHOT *pBaseSnapshot, ISCSI_SNAPSHOT *pSendingSnapshot);
int  SYNOiSCSIReplicationUnsyncSizeGet(const ISCSI_TASK *pTask, ISCSI_SNAPSHOT *pSendingSnapshot, ISCSI_TASK_UNSYNC_SIZE *pTaskUnsyncSize);
int  SYNOiSCSIVlunBindSink(const char *vLunUUID, const char *ip, const char *key, const char *sinkUUID);
int  SYNOiSCSIVlunCreate(const char *szSrcLunUUID, const VISCSI_VIRTUAL_LUN_TYPE type, char *szUUID);
int  SYNOiSCSIVlunFillByUuid(const char *szUUID, VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunRemove(const char *vLunUUID);
int  SYNOiSCSIVlunStatsGet(const char *vLunUUID, VISCSI_VIRTUAL_LUN_STATS *stats);

__END_DECLS

#endif // _SYNOISCSIEP_REPLICATION_H_
