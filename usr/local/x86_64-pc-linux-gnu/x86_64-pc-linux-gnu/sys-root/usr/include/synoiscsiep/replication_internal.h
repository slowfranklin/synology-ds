#ifndef _SYNOISCSIEP_REPLICATION_INTERNAL_H_
#define _SYNOISCSIEP_REPLICATION_INTERNAL_H_

#include <synoiscsiep/replication.h>
#include <synoiscsiep/snapshot_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_REPLICATION_CONF_NAME             "iscsi_replication_task.conf"
#define ISCSI_REPLICATION_DIR_NAME              "Replication"
#define ISCSI_REPLICATION_DIR_FORMAT            "%s/" ISCSI_DIR_NAME "/" ISCSI_REPLICATION_DIR_NAME
#define ISCSI_REPLICATION_PER_VOL_CONF_FORMAT   ISCSI_REPLICATION_DIR_FORMAT "/" ISCSI_REPLICATION_CONF_NAME
#define ISCSI_REPLICATION_OVERALL_CONF_PATH     ISCSI_OVERALL_CONF_DIR_PATH "/" ISCSI_REPLICATION_CONF_NAME
#define ISCSI_REPLICATION_TASK_PROG_PATH        ISCSI_TMP_DIR_PATH "/replication_task_progress.conf"
#define ISCSI_REPLICATION_TASK_UNSYNC_CONF_PATH ISCSI_TMP_DIR_PATH "/replication_task_unsync.conf"
#define ISCSI_REPLICATION_CONF_LOCK_PATH        ISCSI_TMP_DIR_PATH "/" ISCSI_REPLICATION_CONF_NAME ".lock"
#define ISCSI_REPLICATION_TASK_PROG_LOCK_PATH   ISCSI_TMP_DIR_PATH "/replication_task_progress.conf.lock"
#define ISCSI_REPLICATION_UNSYNC_CONF_LOCK_PATH ISCSI_TMP_DIR_PATH "/replication_task_unsync.conf.lock"
#define ISCSI_VIRTUAL_LUN_CONF_NAME             "iscsi_virtual_lun.conf"
#define ISCSI_VIRTUAL_LUN_PER_VOL_CONF_FORMAT   ISCSI_REPLICATION_DIR_FORMAT "/" ISCSI_VIRTUAL_LUN_CONF_NAME
#define ISCSI_VIRTUAL_LUN_OVERALL_CONF_PATH     ISCSI_OVERALL_CONF_DIR_PATH "/" ISCSI_VIRTUAL_LUN_CONF_NAME
#define ISCSI_VIRTUAL_LUN_CONF_LOCK_PATH        ISCSI_TMP_DIR_PATH "/" ISCSI_VIRTUAL_LUN_CONF_NAME ".lock"
#define ISCSI_DIR_NAME_FOR_CHECK_NODE           "CHECK_NODE"
#define ISCSI_VSYS_PATH_FOR_CHECK_NODE          ISCSI_VSYS_CONFIGFS_ROOT "/" ISCSI_DIR_NAME_FOR_CHECK_NODE
#define ISCSI_PURE_VLUN_PATH_PREFIX             "pure_virtual_"
#define ISCSI_PURE_VLUN_PATH_FOR_CHECK_NODE     ISCSI_PURE_VLUN_PATH_PREFIX ISCSI_DIR_NAME_FOR_CHECK_NODE
#define ISCSI_REPLICATION_CHECK_NODE_LOCK_PATH  "/tmp/iscsi-replication-check-node.lock"

/*** constants ***/
#define SZ_ISCSI_RODSP_RBIND_FLAG_DEFAULT       0
#define SZ_ISCSI_RODSP_RBIND_FLAG_ENCRYPT       16
#define LIO_TRACK_HEADER_SIZE                   128
#define VID_MIN                                 1
#define VID_MAX                                 65536
#define VALID_VID(id)                           ((VID_MIN <= (id)) && (VID_MAX >= (id)))
#define ISCSI_TIMEOUT_OF_SEND_SNAPSHOT          1800    // in seconds

/*** keys ***/
#define SZK_VLUN_ID                             "vid"
#define SZK_SOURCE_LID                          "srcLid"
#define SZK_VLUN_SID                            "sid"
#define SZK_VLUN_TYPE                           "type"
#define SZK_BASE_VERSION                        "baseVersion"
#define SZK_TRACK_TYPE                          "trackType"
#define SZK_PROMOTE_TIME                        "promoteTime"
#define SZK_TRACK_NOTE                          "note"
#define SZK_TRACK_LOCKED                        "locked"

/*** etc ***/
#define SZ_LOCAL_IP                             "127.0.0.1"
#define SZ_ISCSI_REPLICATION_TAG                "TASK_"
#define SZ_ISCSI_REPLICATION_SECTION_FORMAT     SZ_ISCSI_REPLICATION_TAG "%s"
#define SZ_ISCSI_VIRTUAL_LUN_TAG                "VISCSI_"
#define SZ_ISCSI_VIRTUAL_LUN_SECTION            SZ_ISCSI_VIRTUAL_LUN_TAG "L%d_V%d"
#define SZ_ISCSI_VIRTUAL_LUN_FILENAME           SZ_ISCSI_VIRTUAL_LUN_TAG "L%d_V%d"

/*** types ***/
// iSCSI virtual LUN
typedef enum _tag_iscsi_virtual_lun_filter_type_ {
	ISCSI_VIRTUAL_LUN_ALL           = 0x0000,
	ISCSI_VIRTUAL_LUN_BY_UUID       = 0x0001,
	ISCSI_VIRTUAL_LUN_BY_VID        = 0x0002,
	ISCSI_VIRTUAL_LUN_BY_NAME       = 0x0004,
	ISCSI_VIRTUAL_LUN_BY_SOURCE_LID = 0x0008,
	ISCSI_VIRTUAL_LUN_BY_ROOT_PATH  = 0x0010,
} ISCSI_VIRTUAL_LUN_FILTER_TYPE;

typedef struct _tag_iscsi_virtual_lun_filter_ {
	ISCSI_VIRTUAL_LUN_FILTER_TYPE type;
	int vid;
	int srcLid;
	const char *szUUID;
	const char *szName;
	const char *szRootPath;
} ISCSI_VIRTUAL_LUN_FILTER;

typedef struct _tag_iscsi_virtual_lun_config_ {
	int vlun_cnt;
	SYNO_LINKED_LIST vluns;
} ISCSI_VIRTUAL_LUN_CONFIG;

typedef enum _tag_iscsi_task_progress_filter_type_ {
	ISCSI_TASK_PROGRESS_ALL                 = 0x0000,
	ISCSI_TASK_PROGRESS_BY_TASK             = 0x0001,
	ISCSI_TASK_PROGRESS_BY_SENDING_SNAPSHOT = 0x0002,
	ISCSI_TASK_PROGRESS_BY_BASE_SNAPSHOT    = 0x0004,
} ISCSI_TASK_PROGRESS_FILTER_TYPE;

typedef struct _tag_iscsi_task_progress_filter_ {
	ISCSI_TASK_PROGRESS_FILTER_TYPE type;
	const char *szTask;
	const char *szSendingSnapshot;
	const char *szBaseSnapshot;
} ISCSI_TASK_PROGRESS_FILTER;

typedef struct _tag_iscsi_task_progress_config_ {
	int task_progress_cnt;
	SYNO_LINKED_LIST task_progress_list;
} ISCSI_TASK_PROGRESS_CONFIG;

/*** macro or inline functions ***/
#define LIST_ISCSI_VIRTUAL_LUN_CONFIG_HEAD_INIT(p_config)                            \
	do {                                                                             \
		LIST_HEAD_INIT(&(p_config)->vluns);                                          \
	} while (0)

#define LIST_ISCSI_VIRTUAL_LUN_CONFIG_HEAD_FREE(p_config)                            \
	do {                                                                             \
		if ((p_config)->vlun_cnt) {                                                  \
			LIST_FREE(&(p_config)->vluns, VISCSI_VIRTUAL_LUN, list);                 \
			(p_config)->vlun_cnt = 0;                                                \
		}                                                                            \
	} while (0)

#define LIST_ISCSI_TASK_PROGRESS_CONFIG_HEAD_INIT(p_config)                          \
	do {                                                                             \
		LIST_HEAD_INIT(&(p_config)->task_progress_list);                             \
	} while (0)

#define LIST_ISCSI_TASK_PROGRESS_CONFIG_HEAD_FREE(p_config)                          \
	do {                                                                             \
		if ((p_config)->task_progress_cnt) {                                         \
			LIST_FREE(&(p_config)->task_progress_list, ISCSI_TASK_PROGRESS, list);   \
			(p_config)->task_progress_cnt = 0;                                       \
		}                                                                            \
	} while (0)

static inline void SYNOiSCSIReplicationPerVolumeConfPath(const ISCSI_TASK *pTask, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_REPLICATION_PER_VOL_CONF_FORMAT, pTask->szRootPath);
}

static inline void SYNOiSCSIVlunPath(const VISCSI_VIRTUAL_LUN *pVlun, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_REPLICATION_DIR_FORMAT "/L%d_%s", pVlun->szRootPath, pVlun->srcLid, pVlun->szName);
}

static inline void SYNOiSCSIVlunConfigfsPath(const VISCSI_VIRTUAL_LUN *pVlun, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_VSYS_CONFIGFS_ROOT "/%s", pVlun->szName);
}

static inline int SYNOiSCSIVlunConfigfsControlPath(const char *szConfigfsDirName, char *szPath, size_t pathLen)
{
	return SYNOiSCSIConfigfsEpControlPath(szConfigfsDirName, szPath, pathLen);
}

static inline int SYNOiSCSIVlunConfigfsEnablePath(const char *szConfigfsDirName, char *szPath, size_t pathLen)
{
	return SYNOiSCSIConfigfsEpEnablePath(szConfigfsDirName, szPath, pathLen);
}

/*** function declarations ***/
int  SYNOiSCSIReplicationConfAdd(const ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationConfDelete(const ISCSI_TASK *pTask);
int  SYNOiSCSIReplicationMkdir(const char *szRootPath);
int  SYNOiSCSIReplicationProgressCollect(const char *szRootPath, const char *szConfigFSDir, ISCSI_TASK_PROGRESS *taskProgress);
int  SYNOiSCSIReplicationProgressDelete(const ISCSI_TASK_PROGRESS *pTaskProgress);
int  SYNOiSCSIReplicationProgressLoad(const ISCSI_TASK_PROGRESS_FILTER *pTaskProgressFilter, ISCSI_TASK_PROGRESS_CONFIG *pTaskProgressConf);
int  SYNOiSCSIReplicationUnsyncSizeAdd(ISCSI_TASK_UNSYNC_SIZE *pTaskUnsyncSize);
int  SYNOiSCSIReplicationUnsyncSizeCollect(const char *szRootPath, const char *szConfigFSDir, ISCSI_TASK_UNSYNC_SIZE *pTaskUnsyncSize);
int  SYNOiSCSIVlunBindSinkByStruct(VISCSI_VIRTUAL_LUN *vLun, const char *ip, const char *key, const char *sinkUUID, bool blDoOverwrite);
int  SYNOiSCSIVlunCloneStart(ISCSI_LUN *pSrcLun, VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunConfAdd(const VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunConfLoad(const ISCSI_VIRTUAL_LUN_FILTER *pFilter, ISCSI_VIRTUAL_LUN_CONFIG *pVlunConfig);
int  SYNOiSCSIVlunConfRemove(VISCSI_VIRTUAL_LUN *pVlun);
int  SYNOiSCSIVlunFileTrunc(const char *szSrcFilePath, const char *szDstFilePath,
		const uint64_t u64TruncSize, const VISCSI_VIRTUAL_LUN_TYPE type);
int  SYNOiSCSIVlunFillDefault(VISCSI_VIRTUAL_LUN *vLun, const ISCSI_LUN *srcLun, const VISCSI_VIRTUAL_LUN_TYPE type);
int  SYNOiSCSIVlunIsDirty(const VISCSI_VIRTUAL_LUN *pVirtualLUN, bool *outIsDirty);
bool SYNOiSCSIVlunIsFull(const VISCSI_VIRTUAL_LUN *currentTrack);
bool SYNOiSCSIVlunIsLoaded(const VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunLoad(const VISCSI_VIRTUAL_LUN *vLun, const bool isTrash);
int  SYNOiSCSIVlunMkdir(VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunNewId(const ISCSI_LUN *pLun);
int  SYNOiSCSIVlunObjectCreate(ISCSI_LUN *srcLun, VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunObjectRemove(VISCSI_VIRTUAL_LUN *vLun, const bool blUnmapRequired);
int  SYNOiSCSIVlunStatsGetByStruct(const VISCSI_VIRTUAL_LUN *vLun, VISCSI_VIRTUAL_LUN_STATS *stats);
int  SYNOiSCSIVlunStructCreateByHash(const PSLIBSZHASH pshHash, VISCSI_VIRTUAL_LUN **ppVlun);
int  SYNOiSCSIVlunUnbindByStruct(VISCSI_VIRTUAL_LUN *vLun);
int  SYNOiSCSIVlunUnbind(const char *vLunUUID);
int  SYNOiSCSIVlunUnload(const VISCSI_VIRTUAL_LUN *vLun, const bool isTrash);
int  SYNOiSCSIReplicationConfRepair(const SPACE_INFO *pSpaceList);
int  SYNOiSCSIReplicationConfSetSection(const ISCSI_TASK *pTask, char *szConfPath);
int  SYNOiSCSIReplicationConfLoadByPath(const ISCSI_TASK_FILTER *pTaskFilter, ISCSI_TASK_CONFIG *pTaskConf, const char *szConfPath);

__END_DECLS

#endif // _SYNOISCSIEP_REPLICATION_H_
