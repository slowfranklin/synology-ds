/* Copyright (c) 2016 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_LUN_INTERNAL_H_
#define _SYNOISCSIEP_LUN_INTERNAL_H_

#include <synoiscsiep/lun.h>
#include <synoiscsiep/ep_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
  // LUN data files
#define ISCSI_LUN_FILE_NAME_SCAN             "%256[^_]_%d%c"
#define ISCSI_LUN_PATH_WILDCARD_FORMAT       ISCSI_LUN_DIR_FORMAT "/%s_*"
#define ISCSI_LUN_TMP_PATH_WILDCARD_FORMAT   ISCSI_LUN_TMP_DIR_FORMAT "/%s_*"
  // LUN config files
#define ISCSI_LUN_CONF_NAME                  "iscsi_lun.conf"
#define ISCSI_LUN_OVERALL_CONF_PATH          ISCSI_OVERALL_CONF_DIR_PATH "/" ISCSI_LUN_CONF_NAME
#define ISCSI_LUN_PER_VOL_CONF_PATH_FORMAT   ISCSI_LUN_TOP_DIR_FORMAT "/" ISCSI_LUN_CONF_NAME
  // LUN lock/status files
#define ISCSI_LUN_CONF_LOCK_PATH             ISCSI_TMP_DIR_PATH "/" ISCSI_LUN_CONF_NAME ".lock"
#define ISCSI_LUN_LOCK_DIR_NAME              "lun_lock"
#define ISCSI_LUN_LOCK_DIR_PATH              ISCSI_TMP_DIR_PATH "/" ISCSI_LUN_LOCK_DIR_NAME
#define ISCSI_LUN_LOCK_PATH_FORMAT           ISCSI_LUN_LOCK_DIR_PATH "/LUN_%s.lock"
#define ISCSI_LUN_UNSYNC_LOCK_DIR_NAME       "lun_unsync"
#define ISCSI_LUN_UNSYNC_LOCK_DIR_PATH       ISCSI_TMP_DIR_PATH "/" ISCSI_LUN_UNSYNC_LOCK_DIR_NAME
#define ISCSI_LUN_UNSYNC_LOCK_PATH_FORMAT    ISCSI_LUN_UNSYNC_LOCK_DIR_PATH "/LUN_%s_unsync.lock"
#define ISCSI_LUN_PROG_PATH_FORMAT           ISCSI_TMP_DIR_PATH "/LUN_%s.progress"
#define ISCSI_LUN_CREATION_LOCK_PATH         ISCSI_TMP_DIR_PATH "/iscsi_lun_creation.lock"
  // LUN configfs path
#define ISCSI_LUN_HBA_DIR_NAME_PREFIX_UNSYNC "UNSYNC_LUN_"
#define ISCSI_LUN_HBA_DIR_NAME_PREFIX_TRASH  "UNMAP_LUN_"
#define ISCSI_LUN_TCM_ATTRIB_DEFER_QUEUE_MODE "defer_queue_mode"
#define ISCSI_LUN_TCM_ATTRIB_VOLUME_ID       "volume_id"
  // Others
#define ISCSI_LUN_CONF_REPAIRING_TMP_PATH    ISCSI_TMP_DIR_PATH "/iscsi_lun_section_repair.tmp"

/*** constants ***/
#define ISCSI_LUN_DEFAULT_ADV_LUN_SIZE       10737418240ULL  // 10G
#define ISCSI_LUN_IMPORT_TIMEOUT             600    // in seconds
#define ISCSI_LUN_DEFAULT_QUANTITY_LIMIT     256
#define ISCSI_LUN_IMPORT_PROG_UPDATE_SIZE    268435456ULL  // 256MB

/*** keys ***/
#define ISCSI_LUN_QUANTITY_LIMIT_KEY         "max_iscsiluns"
#define ISCSI_LUN_ASYNC_JOB_ERROR_CODE       "error_code"
#define ISCSI_LUN_ASYNC_JOB_PROG_TOTAL       "progress_total"
#define ISCSI_LUN_ASYNC_JOB_PROG_DONE        "progress_done"
#define ISCSI_LUN_ASYNC_JOB_PROG_RESULT_VAL  "progress_result_value"
#define ISCSI_LUN_ASYNC_JOB_IMPORT_STATUS    "import_status"
#define ISCSI_LUN_ASYNC_JOB_IMPORT_PROGRESS  "import_progress"
#define ISCSI_LUN_RODSP_SINK_CONNECT_IP      "connect_ip"
#define ISCSI_LUN_RODSP_SINK_WHITELIST       "whitelist"

/*** etc ***/
#define ISCSI_LUN_SECTION_FORMAT             "LUN_%s"
#define ISCSI_LUN_AUTO_RESTORED_NAME_PREFIX  "AutoRestored"
#define ISCSI_LUN_CREATE_PLUGIN_NAME         "lun_create"
#define ISCSI_LUN_DELETE_PLUGIN_NAME         "lun_delete"
#define ISCSI_LUN_RENAME_PLUGIN_NAME         "lun_rename"
#define ISCSI_LUN_MOVE_PLUGIN_NAME           "lun_move"
#define ISCSI_LUN_CLONE_PLUGIN_NAME          "lun_clone"

//- Configfs path for loopback
#define ISCSI_LOOPBACK_TPGT_DEFAULT_PORT     1
#define ISCSI_LOOPBACK_TPGT_DEFAULT_MAPLUN   0
#define ISCSI_LOOPBACK_NAA_DEFAULT_SIZE      1024
#define ISCSI_LOOPBACK_TARGET_PREFIX         "naa."
#define ISCSI_LOOPBACK_TARGET_NAME           ISCSI_LOOPBACK_TARGET_PREFIX "%s"
#define ISCSI_LOOPBACK_CONFIGFS_ROOT         ISCSI_CONFIGFS_TARGET_ROOT_PATH "/loopback"
#define ISCSI_LOOPBACK_TARGET_PATH           ISCSI_LOOPBACK_CONFIGFS_ROOT "/" ISCSI_LOOPBACK_TARGET_NAME
#define ISCSI_LOOPBACK_TPGT_PATH             ISCSI_LOOPBACK_TARGET_PATH "/tpgt_%d"
#define ISCSI_LOOPBACK_TPGT_LUN_PATH         ISCSI_LOOPBACK_TPGT_PATH "/lun/lun_%d"
#define ISCSI_LOOPBACK_TPGT_NEXUS            ISCSI_LOOPBACK_TPGT_PATH "/nexus"
#define ISCSI_SCSI_DEV_SYS_ROOT              "/sys/class/scsi_disk/"
#define ISCSI_SCSI_DEV_FUNCTION_NUMBER       "0"
#define ISCSI_SCSI_DISK_ADDRESS_FULL         "%s:" ISCSI_SCSI_DEV_FUNCTION_NUMBER
#define ISCSI_SCSI_DEV_DEVICE_PATH           ISCSI_SCSI_DEV_SYS_ROOT ISCSI_SCSI_DISK_ADDRESS_FULL "/device/block"
#define ISCSI_MAX_WAIT_SCSI_DEV_SETUP_TIME   30

//- Configfs path for vhost
#define ISCSI_VHOST_TPGT_DEFAULT_PORT        1
#define ISCSI_VHOST_TPGT_DEFAULT_MAPLUN      0
#define ISCSI_VHOST_NAA_DEFAULT_SIZE         1024
#define ISCSI_VHOST_SCSI_TARGET_PREFIX       "naa."
#define ISCSI_VHOST_SCSI_TARGET_NAME         ISCSI_VHOST_SCSI_TARGET_PREFIX "%s"
#define ISCSI_VHOST_SCSI_CONFIGFS_ROOT       ISCSI_CONFIGFS_TARGET_ROOT_PATH "/vhost"
#define ISCSI_VHOST_SCSI_TARGET_PATH         ISCSI_VHOST_SCSI_CONFIGFS_ROOT "/" ISCSI_VHOST_SCSI_TARGET_NAME
#define ISCSI_VHOST_SCSI_TPGT_PATH           ISCSI_VHOST_SCSI_TARGET_PATH "/tpgt_%d"
#define ISCSI_VHOST_SCSI_TPGT_NEXUS          ISCSI_VHOST_SCSI_TPGT_PATH "/nexus"
#define ISCSI_VHOST_SCSI_TPGT_LUN_PATH       ISCSI_VHOST_SCSI_TPGT_PATH "/lun/lun_%d"
#define ISCSI_VHOST_SCSI_TPGT_USE_IOV        ISCSI_VHOST_SCSI_TPGT_PATH "/use_iov"

#define ISCSI_UNMAP_PROG_NAME                "synoiscsiunmap"
#define ISCSI_UNMAP_PROG_PATH                "/usr/syno/bin/" ISCSI_UNMAP_PROG_NAME

/*** types ***/
typedef enum _tag_iscsi_device_type_ {
	ISCSI_DEVICE_TYPE_NONE  = 0x00,
	ISCSI_FILE              = 0x01,
	ISCSI_BLOCK             = 0x02,
	ISCSI_SINK              = 0x03,
	ISCSI_CINDER            = 0x04,
	ISCSI_BLUN              = 0x05,
	ISCSI_VDISK_ADV         = 0x06,
	ISCSI_VDISK_BLUN        = 0x07,
	ISCSI_DEVICE_TYPE_BOUND = 0x08,
} ISCSI_DEV_TYPE;

static inline int SYNOiSCSILunPerVolumeConfigPathGet(const ISCSI_LUN *pLun, char *szPath, size_t cbSize) {
	const int ret = snprintf(szPath, cbSize, ISCSI_LUN_PER_VOL_CONF_PATH_FORMAT, pLun->szRootPath);
	return (0 > ret || cbSize <= ret) ? ERR_ISCSI_FAILED_TO_PARSE_STRING : ERR_ISCSI_SUCCESS;
}

static inline void SYNOiSCSILunDirPath(const ISCSI_LUN *pLun, char *szPath, const int cbPath)
{
	if (IsLunUsedForTmpFolder(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_TMP_DIR_FORMAT, pLun->szRootPath, pLun->szUUID);
	} else if ( ! IsLUNCategoryBLOCK(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_DIR_FORMAT, pLun->szRootPath, SYNOiSCSILunTypeToString(pLun->type), pLun->szUUID);
	}
}

static inline void SYNOiSCSILunTypeDirPath(const ISCSI_LUN *pLun, char *szPath, const int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_LUN_TYPE_DIR_FORMAT, pLun->szRootPath, SYNOiSCSILunTypeToString(pLun->type));
}

static inline void SYNOiSCSILunFileNameWithIndex(const ISCSI_LUN *pLun, char *szPath, const int cbPath, const int iIndex)
{
	if (IsLunUsedForTrash(pLun)) {
		snprintf(szPath, cbPath, "%s", pLun->szUUID);
	} else if (!IsLUNCategoryBLOCK(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_FILE_NAME_FORMAT, pLun->szName, iIndex);
	}
}

static inline void SYNOiSCSILunWildcardFilePath(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	if (IsLunUsedForTmpFolder(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_TMP_PATH_WILDCARD_FORMAT, pLun->szRootPath, pLun->szUUID, pLun->szName);
	} else if ( ! IsLUNCategoryBLOCK(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_PATH_WILDCARD_FORMAT, pLun->szRootPath,
			SYNOiSCSILunTypeToString(pLun->type), pLun->szUUID, pLun->szName);
	}
}

static inline void SYNOiSCSILunPath(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	if (IsLUNCategoryBLOCK(pLun)) {
		snprintf(szPath, cbPath, "%s", pLun->szRootPath);
	} else if (IsLUNCategoryADV(pLun)) {
		SYNOiSCSILunFilePathWithIndex(pLun, szPath, cbPath, ISCSI_LUN_MIN_FILE_INDEX);
	} else if (IsLUNCategoryFILE(pLun)) {
		SYNOiSCSILunWildcardFilePath(pLun, szPath, cbPath);
	}
}

static inline void SYNOiSCSILunLockPath(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	if (ISCSI_LUN_USE_UNSYNC_SIZE & pLun->use) {
		snprintf(szPath, cbPath, ISCSI_LUN_UNSYNC_LOCK_PATH_FORMAT, pLun->szUUID);
	} else {
		snprintf(szPath, cbPath, ISCSI_LUN_LOCK_PATH_FORMAT, pLun->szUUID);
	}
}

static inline void SYNOiSCSILunProgressPath(const ISCSI_LUN *pLun, char *szPath, int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_LUN_PROG_PATH_FORMAT, pLun->szUUID);
}

static inline void SYNOiSCSILunLoadDirName(const ISCSI_LUN *pLun, char *szDirName, size_t cbDirName)
{
	if (IsLunUsedForTrash(pLun)) {
		snprintf(szDirName, cbDirName, ISCSI_LUN_HBA_DIR_NAME_PREFIX_TRASH "%s", pLun->szUUID);
	} else if (IsLunUsedForUnsyncSize(pLun)) {
		snprintf(szDirName, cbDirName, ISCSI_LUN_HBA_DIR_NAME_PREFIX_UNSYNC "%s", pLun->szUUID);
	} else {
		snprintf(szDirName, cbDirName, ISCSI_LUN_HBA_DIR_NAME_PREFIX_NORMAL "%s", pLun->szUUID);
	}
}

/*** macro or inline functions ***/

/*** function declarations ***/
int  SYNOiSCSILunAsyncJobProgressGetWithInfoPath(const char *szPath, int *pError, uint64_t *pTotal, uint64_t *pDone);
int  SYNOiSCSILunAsyncJobWaitTillSuccessWithInfoPath(const char *szPath);
int  SYNOiSCSILunAsyncJobWaitTillSuccess(ISCSI_LUN *pLun);
int  SYNOiSCSILunCloneByMirror(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunCloneConditionsCheck(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneFor3rdParty(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneObjectCreate(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneBySubvol(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunCloneByClone(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun);
int  SYNOiSCSILunCloneConfAdd(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneConfRemove(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneObjectCreateADV(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneObjectCreateBLUN(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneStart(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunConfInVolumeLoadByUuid(const char *szVolPath, const char *szUUID, ISCSI_LUN *pLun);
int  SYNOiSCSILunConfInVolumeLoad(const char *szVolPath, ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSILunConfLoadByPath(const ISCSI_FILTER *pLunFilter, ISCSI_CONFIG *pLunConfig, const char *szConfigPath);
int  SYNOiSCSILunDirDelete(ISCSI_LUN *pLun);
int  SYNOiSCSILunDirRename(const ISCSI_LUN *pSrcLun, const ISCSI_LUN *pDstLun);
int  SYNOiSCSILunGlobalConfRemove(const ISCSI_LUN *pLun);
int  SYNOiSCSILunVolumeConfRemove(const ISCSI_LUN *pLun);
int  SYNOiSCSILunGlobalConfSetSection(const ISCSI_LUN *pLun);
int  SYNOiSCSILunVolumeConfSetSection(const ISCSI_LUN *pLun);
int  SYNOiSCSILunConfGetByLid(const int lunId, const int additionalFlag, ISCSI_CONFIG *pLunConfig);
int  SYNOiSCSILunConfigfsAttribSet(const ISCSI_LUN *pLun, const char *szAttrib, const char *szValue);
int  SYNOiSCSILunConfigfsAttribGetInt(const ISCSI_LUN *pLun, const char *szAttrib, int *pInt);
int  SYNOiSCSILunConfigfsAttrPathByUuid(const char *szUUID, const char *szAttrib, char* szPath, const size_t cbSize);
int  SYNOiSCSILunConfigfsControlPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsControl(const ISCSI_LUN *pLun, const char *szString);
int  SYNOiSCSILunConfigfsEnablePath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsEnable(const ISCSI_LUN *pLun, bool blEnable);
int  SYNOiSCSILunConfigfsHbaPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsInfoPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsInfoAsyncJobPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsInfoRodspPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);
int  SYNOiSCSILunConfigfsInfoKeyValueGetWithPath(const char *szPath, const char *szKey, char *szVal, size_t cbSize);
int  SYNOiSCSILunCloneFor3rdPartyStart(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunCloneForPlugin(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunClonePluginReply(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun, P_SYNOAPPCOMM pSynoComm, FIELD_UUID *pCommSrcUUID, bool blIsThirdParty);
int  SYNOiSCSILunCloneBlunNotifyPlugin(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunCloneByMapFileClone(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun);
int  SYNOiSCSILunCloneByMirrorNotifyPlugin(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun, P_SYNOAPPCOMM pSynoComm);
int  SYNOiSCSILunEnumIndexNumber(const ISCSI_LUN *pLun, int *rgIndex);
int  SYNOiSCSILunFrontendFabricUnloadByNaa(const char *szFabricPath, const char *szNAA);
int  SYNOiSCSILunFamilyConfRemove(int lid);
int  SYNOiSCSILunFileMove(ISCSI_LUN *pLun, ISCSI_LUN *pOrgLun);
int  SYNOiSCSILunFileProgressUpdate(const ISCSI_LUN *pLun, uint64_t ui64Inc);
int  SYNOiSCSILunFileRename(const ISCSI_LUN *pLun, const ISCSI_LUN *pOrgLun);
int  SYNOiSCSILunCloneObjectCreateBLUN(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunConfLoadByFilter(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pLunConfig);
int  SYNOiSCSILunImportProgressRead(const ISCSI_LUN *pLun, ISCSI_LUN_IMPORT_PROGRESS_STATE *pProg);
int  SYNOiSCSILunImportProgressWrite(const ISCSI_LUN *pLun, const ISCSI_LUN_IMPORT_PROGRESS_STATE prog);
int  SYNOiSCSILunIsLoaded(const ISCSI_LUN *pLun, bool *pIsLoaded);
int  SYNOiSCSILunIsSpaceEnoughToClone(const ISCSI_LUN *pLun);
int  SYNOiSCSILunIsSpaceEnoughToCreate(const ISCSI_LUN *pLun);
int  SYNOiSCSILunIsQuantityLimitReached(bool *isReached);
int  SYNOiSCSILunMappingRemove(int lid);
int  SYNOiSCSILunMkdir(const ISCSI_LUN *pLun);
int  SYNOiSCSILunMoveToTrash(ISCSI_LUN *pLun);
int  SYNOiSCSILunObjectCreateFILE(ISCSI_LUN *pLun);
int  SYNOiSCSILunObjectCreate(ISCSI_LUN *pLun);
int  SYNOiSCSILunObjectDelete(ISCSI_LUN *pLun);
int  SYNOiSCSILunUnmapALUNInBackground(const char *szMapFileFullPath);
bool SYNOiSCSILunPathCheck(const ISCSI_LUN *pLun, const ISCSI_LUN *pOrgLun, int chgType);
int  SYNOiSCSILunProgressUpdate(ISCSI_LUN *pLun, ISCSI_PROGRESS_STEP step);
int  SYNOiSCSILunQuantityGet(int *lunQuantity);
int  SYNOiSCSILunQuantityLimitGet();
int  SYNOiSCSILunRepair(const SPACE_INFO *pSpaceList);
int  SYNOiSCSILunRestoreTimeSet(ISCSI_LUN *pLun);
int  SYNOiSCSILunRestoreFor3rdParty(ISCSI_LUN *srcLun, ISCSI_LUN *dstLun);
int  SYNOiSCSILunServiceStartAllWithoutLock();
int  SYNOiSCSILunServiceStartAll();
int  SYNOiSCSILunServiceStopAllByVolumePath(const char *szVolPath);
int  SYNOiSCSILunServiceStopAllByVolumeId(int volId);
int  SYNOiSCSILunServiceStopAll();
int  SYNOiSCSILunServiceStopAllWithoutLock();
int  SYNOiSCSILunSizeGet(const ISCSI_LUN *pLun, uint64_t *pSize);
int  SYNOiSCSILunSpaceCheck(ISCSI_LUN *pLun, const ISCSI_LUN *pOrgLun, int chgType);
int  SYNOiSCSILunStableVersionGenerate(ISCSI_LUN *trgLun, bool forced);
int  SYNOiSCSILunStructCreate(ISCSI_LUN *pLun, const PSLIBSZHASH pshHash);
int  SYNOiSCSILunTotalSizeGet(const ISCSI_FILTER *pFilter, uint64_t *pu64Size);
int  SYNOiSCSILunUnloadForLio(const ISCSI_LUN *pLun);
int  SYNOiSCSILunUnloadAllByUdevPathPrefixBLOCK(const char *szPrefix);
int  SYNOiSCSILunUnusedMappingNumberGet(int tid);
int  SYNOiSCSILunUnusedNameGet(const char *szPrefix, char *szUnusedName, int cbUnusedName);
int  SYNOiSCSILunUnmapTrashInBackground();
int  SYNOiSCSILunUnmapTrashEnable();
int  SYNOiSCSILunUnmapTrashDisable();
int  SYNOiSCSILunUnmapTrashStop();
int  SYNOiSCSILunUnmapTrashIsEnabled(bool *pEnabled);
int  SYNOiSCSILunUuidGenerate(char *szUuid);

__END_DECLS

#ifdef __cplusplus
#include <string>

int  SYNOiSCSILunUnloadAllByConfigfsPath(const std::string &HBAPath);
int  SYNOiSCSILunUnloadAllByVolumePath(const std::string &volPath);
int  SYNOiSCSILunUnloadAllByVolumeId(int volNum);
int  SYNOiSCSILunUnloadAllForVsys(void);

#endif // __cplusplus

#endif // _SYNOISCSIEP_LUN_INTERNAL_H_
