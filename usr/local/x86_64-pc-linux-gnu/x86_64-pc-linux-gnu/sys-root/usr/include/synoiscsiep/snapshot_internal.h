/* Copyright (c) 2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_SNAPSHOT_INTERNAL_H_
#define _SYNOISCSIEP_SNAPSHOT_INTERNAL_H_

#include <libgen.h>
#include <synoiscsiep/snapshot.h>
#include <synoiscsiep/lun_internal.h>
#include <synoiscsiep/util_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
  // Snapshot data files
#define ISCSI_SNAPSHOT_TOP_DIR_NAME               "Snapshot"
#define ISCSI_SNAPSHOT_TOP_DIR_FORMAT             "%s/" ISCSI_DIR_NAME "/" ISCSI_SNAPSHOT_TOP_DIR_NAME
#define ISCSI_SNAPSHOT_TYPE_DIR_FORMAT            ISCSI_SNAPSHOT_TOP_DIR_FORMAT "/%s"
#define ISCSI_SNAPSHOT_PARENT_DIR_FORMAT          ISCSI_SNAPSHOT_TYPE_DIR_FORMAT "/%s"
#define ISCSI_SNAPSHOT_DIR_FORMAT                 ISCSI_SNAPSHOT_PARENT_DIR_FORMAT "/%s"
#define ISCSI_SNAPSHOT_MAP_FILE_PATH_FORMAT       ISCSI_SNAPSHOT_DIR_FORMAT "/%s"
  // Snapshot config files
#define ISCSI_SNAPSHOT_CONF_NAME_FORMAT           "iscsi_snapshot_%s.conf"
#define ISCSI_SNAPSHOT_CONF_NAME_SCAN             "iscsi_snapshot_%37[^_.].conf%c"
#define ISCSI_SNAPSHOT_CONF_PATH_FORMAT           ISCSI_SNAPSHOT_TOP_DIR_FORMAT "/" ISCSI_SNAPSHOT_CONF_NAME_FORMAT
#define ISCSI_SNAPSHOT_CACHE_DIR_NAME             "snapshot_cache"
#define ISCSI_SNAPSHOT_CACHE_DIR_PATH             ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_CACHE_DIR_NAME
#define ISCSI_SNAPSHOT_CACHE_NAME_FORMAT          "iscsi_snapshot_%c%c%c.conf.cache"
#define ISCSI_SNAPSHOT_CACHE_NAME_SCAN            "iscsi_snapshot_%3[0-9a-fA-F].conf.cache%c"
#define ISCSI_SNAPSHOT_CACHE_PATH_FORMAT          ISCSI_SNAPSHOT_CACHE_DIR_PATH "/" ISCSI_SNAPSHOT_CACHE_NAME_FORMAT
  // Snapshot lock/status files
#define ISCSI_SNAPSHOT_LOCK_DIR_NAME              "snapshot_lock"
#define ISCSI_SNAPSHOT_LOCK_DIR_PATH              ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_LOCK_DIR_NAME
#define ISCSI_SNAPSHOT_LOCK_PATH_FORMAT           ISCSI_SNAPSHOT_LOCK_DIR_PATH "/SN_%s.lock"
#define ISCSI_SNAPSHOT_CONF_LOCK_DIR_NAME         "snapshot_conf_lock"
#define ISCSI_SNAPSHOT_CONF_LOCK_DIR_PATH         ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_CONF_LOCK_DIR_NAME
#define ISCSI_SNAPSHOT_CONF_LOCK_PATH_FORMAT      ISCSI_SNAPSHOT_CONF_LOCK_DIR_PATH "/" ISCSI_SNAPSHOT_CONF_NAME_FORMAT ".lock"
#define ISCSI_SNAPSHOT_CACHE_LOCK_DIR_NAME        "snapshot_cache_lock"
#define ISCSI_SNAPSHOT_CACHE_LOCK_DIR_PATH        ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_CACHE_LOCK_DIR_NAME
#define ISCSI_SNAPSHOT_CACHE_LOCK_PATH_FORMAT     ISCSI_SNAPSHOT_CACHE_LOCK_DIR_PATH "/" ISCSI_SNAPSHOT_CACHE_NAME_FORMAT ".lock"
#define ISCSI_SNAPSHOT_APP_LOCK_DIR_NAME          "snapshot_app_lock"
#define ISCSI_SNAPSHOT_APP_LOCK_DIR_PATH          ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_APP_LOCK_DIR_NAME
#define ISCSI_SNAPSHOT_APP_LOCK_PATH_FORMAT       ISCSI_SNAPSHOT_APP_LOCK_DIR_PATH "/SN_%s.app.lock"
#define ISCSI_SNAPSHOT_UNSYNC_LOCK_DIR_NAME       "snapshot_unsync_lock"
#define ISCSI_SNAPSHOT_UNSYNC_LOCK_DIR_PATH       ISCSI_TMP_DIR_PATH "/" ISCSI_SNAPSHOT_UNSYNC_LOCK_DIR_NAME
#define ISCSI_SNAPSHOT_UNSYNC_LOCK_PATH_FORMAT    ISCSI_SNAPSHOT_UNSYNC_LOCK_DIR_PATH "/SN_%s_unsync.lock"
#define ISCSI_SNAPSHOT_PROG_PATH_FORMAT           ISCSI_TMP_DIR_PATH "/SN_%s.progress"
  // Snapshot config path
#define ISCSI_SNAPSHOT_CFS_DIR_NAME_NORMAL        "LUN_%s_SN_%s"
#define ISCSI_SNAPSHOT_CFS_PATH_FORMAT_NORMAL     "%s/" ISCSI_SNAPSHOT_CFS_DIR_NAME_NORMAL
#define ISCSI_SNAPSHOT_CFS_PATH_FORMAT_TRASH      "%s/UNMAP_" ISCSI_SNAPSHOT_CFS_DIR_NAME_NORMAL
#define ISCSI_SNAPSHOT_CFS_PATH_FORMAT_UNSYNC     "%s/UNSYNC_" ISCSI_SNAPSHOT_CFS_DIR_NAME_NORMAL
  // Others
#define ISCSI_SNAPSHOT_SCHE_TASK_CONF_PATH        ISCSI_OVERALL_CONF_DIR_PATH "/iscsi_sched_snap_task.conf"
#define ISCSI_SNAPSHOT_SCHE_TASK_CONF_LOCK_PATH   ISCSI_TMP_DIR_PATH "/iscsi_sched_snap_task.conf.lock"
#define ISCSI_SNAPSHOT_EXPORT_FILENAME_PREFIX     "EXP_DAT"
#define ISCSI_SNAPSHOT_EXPORT_FILENAME_SCAN       "EXP_DAT_%d%c"
#define ISCSI_SNAPSHOT_ISS_CONN_LOCK_PATH         "/tmp/synocomm_iss.lock"
#define ISCSI_SNAPSHOT_CONF_REPAIRING_TMP_PATH    "/tmp/iscsi-snapshot-section-repair.tmp"

/*** constants ***/
#define ISCSI_SNAPSHOT_ISS_CONN_SECTION_SIZE      64
#define ISCSI_SNAPSHOT_EXPORT_TIMEOUT             600    // in seconds
#define ISCSI_SNAPSHOT_EXPORT_MAX_FILE_SIZE       (uint64_t)4294967296ULL // 1 << 32

#define ISCSI_SNAPSHOT_TYPE_STR_UNKNOWN           "UNKNOWN"
#define ISCSI_SNAPSHOT_TYPE_STR_ADV               "ADV"
#define ISCSI_SNAPSHOT_TYPE_STR_BLUN              "BLUN"

/*** keys ***/
#define ISCSI_SNAPSHOT_PROGRESS_KEY_LID           "lid"
#define ISCSI_SNAPSHOT_PROGRESS_KEY_SID           "sid"
#define ISCSI_SNAPSHOT_PROGRESS_KEY_STEP          "step"
#define ISCSI_SNAPSHOT_PROGRESS_KEY_NAME          "name"
#define ISCSI_SNAPSHOT_PROGRESS_KEY_TOTAL_BYTES   "totalBytes"
#define ISCSI_SNAPSHOT_EXPORT_TOTAL_FILES         "total_files"
#define ISCSI_SNAPSHOT_ASYNC_JOB_EXPORT_STATUS    "export_status"
#define ISCSI_SNAPSHOT_ASYNC_JOB_EXPORT_PROGRESS  "export_progress"

/*** etc ***/
#define ISCSI_SNAPSHOT_NAME_PREFIX                "SnapShot-"
#define ISCSI_SNAPSHOT_SECTION_FORMAT             ISCSI_SNAPSHOT_TAG "%s"
#define ISCSI_SNAPSHOT_SCHE_TASK_TAG              "SST_"
#define ISCSI_SNAPSHOT_SCHE_TASK_SECTION_FORMAT   ISCSI_SNAPSHOT_SCHE_TASK_TAG "%d"
#define ISCSI_SNAPSHOT_SCHE_TASK_NOTE             "Created by schedule snapshot task"
#define ISCSI_SNAPSHOT_SCHE_TASK_FILTER_MASK      0x0fff
#define ISCSI_SNAPSHOT_ISS_CONN_SECTION_FORMAT    "%s %s"
#define ISCSI_SNAPSHOT_TP_MIRRORCLONE_NAME        "LUN-%s-BACKUP-AT-%d%d%d%d%d%d"
#define ISCSI_SNAPSHOT_TP_TARGET_IQN_FORMAT       "iqn.2000-01.com.synology.%s"
#define ISCSI_SNAPSHOT_TP_TARGET_NAME_FORMAT      "ThirdPartyTarget-%s"

// family
#define ISCSI_FAMILY_TAG                          "FAMILY_"
#define ISCSI_FAMILY_LUN_SECTION                  ISCSI_FAMILY_TAG "L%d"
#define ISCSI_FAMILY_CONF_NAME                    "iscsi_family_lun.conf"
#define ISCSI_FAMILY_CONF_PATH                    ISCSI_OVERALL_CONF_DIR_PATH "/" ISCSI_FAMILY_CONF_NAME
#define ISCSI_FAMILY_CONF_LOCK_PATH               ISCSI_TMP_DIR_PATH "/" ISCSI_FAMILY_CONF_NAME ".lock"

/*** types ***/
typedef struct _tag_iscsi_snapshot_export_progress_state_ {
	int lid;
	int sid;
	int st;
	uint64_t doneBytes;
	uint64_t totalBytes;
} ISCSI_SNAPSHOT_EXPORT_PROGRESS_STATE;

/*** macro or inline functions ***/
// Snapshot Type Tools
static inline const char * SYNOiSCSISnapshotTypeToString(const ISCSI_SNAPSHOT_TYPE snapshotType) {
	switch (snapshotType) {
	case ISCSI_SNAPSHOT_TYPE_ADV:
		return ISCSI_SNAPSHOT_TYPE_STR_ADV;
	case ISCSI_SNAPSHOT_TYPE_BLUN:
		return ISCSI_SNAPSHOT_TYPE_STR_BLUN;
	default:
		return ISCSI_SNAPSHOT_TYPE_STR_UNKNOWN;
	}
}

static inline ISCSI_SNAPSHOT_TYPE SYNOiSCSISnapshotTypeFromString(const char *szTypeStr) {
	if ( ! szTypeStr) {
		return ISCSI_SNAPSHOT_TYPE_UNKNOWN;
	} else if ( ! strcmp(szTypeStr, ISCSI_SNAPSHOT_TYPE_STR_ADV)) {
		return ISCSI_SNAPSHOT_TYPE_ADV;
	} else if ( ! strcmp(szTypeStr, ISCSI_SNAPSHOT_TYPE_STR_BLUN)) {
		return ISCSI_SNAPSHOT_TYPE_BLUN;
	} else {
		return ISCSI_SNAPSHOT_TYPE_UNKNOWN;
	}
}

// Snapshot Use Tools
static inline bool IsSnapshotUsedForNormal(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && 0 == pSnapshot->use;
}
static inline bool IsSnapshotUsedForTrash(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_TRASH);
}
static inline bool IsSnapshotUsedForUnsyncSize(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_UNSYNC_SIZE);
}
static inline bool IsSnapshotUsedForNoAppKey(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_NO_APP_KEY);
}
static inline bool IsSnapshotUsedForScheduled(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_SCHEDULED);
}
static inline bool IsSnapshotUsedForConfigOnly(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_CONFIG_ONLY);
}
static inline bool IsSnapshotUsedForCacheOnly(const ISCSI_SNAPSHOT *pSnapshot) {
	return pSnapshot && (pSnapshot->use & ISCSI_SNAPSHOT_USE_CACHE_ONLY);
}

// Snapshot Path Getter
static inline void SYNOiSCSISnapshotConfigfsTargetPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, int cbPath)
{
	if (IsSnapshotUsedForTrash(pSnapshot)) {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CFS_PATH_FORMAT_TRASH, getTCMHBATrash(), pSnapshot->szParentUUID, pSnapshot->szUUID);
	} else if (IsSnapshotUsedForUnsyncSize(pSnapshot)) {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CFS_PATH_FORMAT_UNSYNC, getTCMHBAEPIO(), pSnapshot->szParentUUID, pSnapshot->szUUID);
	} else {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CFS_PATH_FORMAT_NORMAL, getTCMHBAEPIO(), pSnapshot->szParentUUID, pSnapshot->szUUID);
	}
}

static inline void SYNOiSCSISnapshotConfigfsVsysPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_VSYS_CONFIGFS_ROOT "/" ISCSI_SNAPSHOT_CFS_DIR_NAME_NORMAL,
			pSnapshot->szParentUUID, pSnapshot->szUUID);
}

static inline void SYNOiSCSISnapshotMapFilePathWithoutStruct(
		int use,
		const char *szRootPath,
		const char *szParentUUID,
		const char *szSnapshotUUID,
		const char *szName,
		char *szPath,
		const int cbPath)
{
	if (use & ISCSI_SNAPSHOT_USE_TRASH) {
		snprintf(szPath, cbPath, ISCSI_EP_TRASH_PATH_FORMAT, szRootPath, szSnapshotUUID);
	} else {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_MAP_FILE_PATH_FORMAT,
				szRootPath, ISCSI_SNAPSHOT_TYPE_STR_ADV, szParentUUID, szSnapshotUUID, szName);
	}
}

static inline void SYNOiSCSISnapshotMapFilePath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, const int cbPath)
{
	SYNOiSCSISnapshotMapFilePathWithoutStruct(
			pSnapshot->use,
			pSnapshot->szRootPath,
			pSnapshot->szParentUUID,
			pSnapshot->szUUID,
			pSnapshot->szName,
			szPath,
			cbPath);
}

static inline void SYNOiSCSISnapshotTypeDirPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_TYPE_DIR_FORMAT,
				pSnapshot->szRootPath,
				SYNOiSCSISnapshotTypeToString(pSnapshot->type));
}

static inline void SYNOiSCSISnapshotParentDirPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_PARENT_DIR_FORMAT,
				pSnapshot->szRootPath,
				SYNOiSCSISnapshotTypeToString(pSnapshot->type),
				pSnapshot->szParentUUID);
}

static inline void SYNOiSCSISnapshotDirPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_DIR_FORMAT,
				pSnapshot->szRootPath,
				SYNOiSCSISnapshotTypeToString(pSnapshot->type),
				pSnapshot->szParentUUID,
				pSnapshot->szUUID);
}

static inline void SYNOiSCSISnapshotBlunGlobPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_DIR_FORMAT "/*_[0-9]*",
				pSnapshot->szRootPath,
				SYNOiSCSISnapshotTypeToString(pSnapshot->type),
				pSnapshot->szParentUUID,
				pSnapshot->szUUID);
}

static inline void SYNOiSCSISnapshotConfPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CONF_PATH_FORMAT, pSnapshot->szRootPath, pSnapshot->szParentUUID);
}
static inline void SYNOiSCSISnapshotConfLockPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CONF_LOCK_PATH_FORMAT, pSnapshot->szParentUUID);
}
static inline void SYNOiSCSISnapshotConfPathByLun(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CONF_PATH_FORMAT, pLun->szRootPath, pLun->szUUID);
}
static inline void SYNOiSCSISnapshotConfLockPathByLun(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CONF_LOCK_PATH_FORMAT, pLun->szUUID);
}

static inline void SYNOiSCSISnapshotCachePath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CACHE_PATH_FORMAT, pSnapshot->szUUID[0], pSnapshot->szUUID[1], pSnapshot->szUUID[2]);
}
static inline void SYNOiSCSISnapshotCacheLockPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CACHE_LOCK_PATH_FORMAT, pSnapshot->szUUID[0], pSnapshot->szUUID[1], pSnapshot->szUUID[2]);
}
static inline void SYNOiSCSISnapshotCachePathByUuid(const char *szUuid, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CACHE_PATH_FORMAT, szUuid[0], szUuid[1], szUuid[2]);
}
static inline void SYNOiSCSISnapshotCacheLockPathByUuid(const char *szUuid, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_CACHE_LOCK_PATH_FORMAT, szUuid[0], szUuid[1], szUuid[2]);
}

static inline void SYNOiSCSISnapshotLockPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	if (IsSnapshotUsedForUnsyncSize(pSnapshot)) {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_UNSYNC_LOCK_PATH_FORMAT, pSnapshot->szUUID);
	} else {
		snprintf(szPath, cbPath, ISCSI_SNAPSHOT_LOCK_PATH_FORMAT, pSnapshot->szUUID);
	}
}
static inline void SYNOiSCSISnapshotProgressPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_PROG_PATH_FORMAT, pSnapshot->szUUID);
}
static inline void SYNOiSCSISnapshotAppLockPath(const ISCSI_SNAPSHOT *pSnapshot, char *szPath, size_t cbPath)
{
	snprintf(szPath, cbPath, ISCSI_SNAPSHOT_APP_LOCK_PATH_FORMAT, pSnapshot->szUUID);
}

/*** function declarations ***/
int  SYNOiSCSIFamilyConfAdd(const ISCSI_FAMILY *pFamily);
int  SYNOiSCSIFamilyConfCloneLunsGet(const int parentLID, ISCSI_FAMILY_CONFIG *pFamilyConf);
int  SYNOiSCSIFamilyConfDelete(const ISCSI_FAMILY *pFamily);
void SYNOiSCSIFamilyConfFree(ISCSI_FAMILY_CONFIG *pFamilyConf);
int  SYNOiSCSIFamilyConfGetLunPath(const ISCSI_FAMILY *pFamily, char *szPath, const int cbPath);
int  SYNOiSCSIFamilyConfRepair();
void SYNOiSCSIFamilyConfSetStatus(const int lid);
int  SYNOiSCSIFamilyConfUpdateStatus(const ISCSI_FAMILY *pFamily);
int  SYNOiSCSISnapshotAsyncJobWaitTillSuccess(ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfDeleteByParentLun(const ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotConfDelete(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfInVolumeLoadByUuid(const char *szVolPath, const char *szParentUuid, const char *szUuid, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotConfLoadByParentLun(const ISCSI_LUN *pLun, ISCSI_SNAPSHOT_FILTER *pSnapFilter, ISCSI_SNAPSHOT_CONFIG *pSnapConfig);
int  SYNOiSCSISnapshotConfLoadWithPath(const ISCSI_SNAPSHOT_FILTER *pSnapFilter, ISCSI_SNAPSHOT_CONFIG *pSnapConfig, const char *configPath);
int  SYNOiSCSISnapshotCreateByMirror(ISCSI_LUN *pLun, ISCSI_SNAPSHOT *pSnapshot, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSISnapshotCreateBySubvol(ISCSI_LUN *pLun, ISCSI_SNAPSHOT *pSnapshot, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSISnapshotDeleteByLun(ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotDeleteWithoutCheckingAppKey(ISCSI_SNAPSHOT *pSnapshot, const char *szDeletedBy);
int  SYNOiSCSISnapshotExportConfigUpdateStatus(const char *szConfigDirPath, const char *szStatus);
int  SYNOiSCSISnapshotExportProgressRead(const ISCSI_SNAPSHOT *pSnapshot, ISCSI_SNAPSHOT_EXPORT_PROGRESS_STATE *pProg);
int  SYNOiSCSISnapshotExportProgressWrite(const ISCSI_SNAPSHOT *pSnapshot, const ISCSI_SNAPSHOT_EXPORT_PROGRESS_STATE prog);
int  SYNOiSCSISnapshotIsNameUsed(const ISCSI_SNAPSHOT_CONFIG *pSnapConfig, const char *szSnapshotName, bool *pDoesSnapshotNameExist);
bool SYNOiSCSISnapshotIsSpaceEnoughToCreate(const ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotMkdir(const ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotObjectCreateBLUN(ISCSI_LUN *pLun, ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotProgressUpdate(const ISCSI_SNAPSHOT *pSnapshot, ISCSI_SNAPSHOT_PROGRESS_STEP step);
int  SYNOiSCSISnapshotRepair(const SPACE_INFO *pSpaceList);
int  SYNOiSCSISnapshotScheduleConfRemoveByStid(const int tid);
int  SYNOiSCSISnapshotScheduleConfRemove(const SCHEDULE_SNAPSHOT_TASK *pTask);
int  SYNOiSCSISnapshotScheduleCreate(ISCSI_LUN *pLun, const SCHEDULE_SNAPSHOT_TASK *pTask);
int  SYNOiSCSISnapshotScheduleRotate(const ISCSI_LUN *pLun);
int  SYNOiSCSISnapshotScheduleSendNotification(const char *szLunName);
int  SYNOiSCSISnapshotScheduleStructCreate(const PSLIBSZHASH pshHash, SCHEDULE_SNAPSHOT_TASK **ppTask);
int  SYNOiSCSISnapshotSizeGet(const ISCSI_SNAPSHOT *pSnapshot, uint64_t *pSize);
int  SYNOiSCSISnapshotUnlock(ISCSI_SNAPSHOT *pSnapshot);
int  SYNOiSCSISnapshotUnusedSidFind(ISCSI_LUN *pLun, const ISCSI_SNAPSHOT_CONFIG *pSnapConfig);

__END_DECLS;

#endif // _SYNOISCSIEP_SNAPSHOT_INTERNAL_H_
