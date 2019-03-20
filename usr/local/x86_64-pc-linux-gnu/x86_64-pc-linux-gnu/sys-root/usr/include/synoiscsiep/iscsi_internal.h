/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_ISCSI_INTERNAL_H_
#define _SYNOISCSIEP_ISCSI_INTERNAL_H_

#include <synoiscsiep/iscsi.h>
#include <synoiscsiep/synocomm_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_DIR_PATH_FORMAT                   "%s/@iSCSI"
#define ISCSI_CONFIGFS_ALUA_ROOT_PATH           ISCSI_CONFIGFS_TARGET_ROOT_PATH "/core/alua/lu_gps"
#define ISCSI_CONFIGFS_ISCSI_ROOT_PATH          ISCSI_CONFIGFS_TARGET_ROOT_PATH "/iscsi"
#define ISCSI_CONFIGFS_TARGET_PATH_FORMAT       ISCSI_CONFIGFS_ISCSI_ROOT_PATH "/%s"
#define ISCSI_CONFIGFS_TPGT_PATH_FORMAT         ISCSI_CONFIGFS_TARGET_PATH_FORMAT "/tpgt_%d"
#define ISCSI_CONFIGFS_TPGT_LUN_PATH            ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/lun/lun_%d"
#define ISCSI_CONFIGFS_TPGT_NETPORTAL           ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/np/%s:%d"
#define ISCSI_CONFIGFS_TPGT_ENABLE              ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/enable"
#define ISCSI_CONFIGFS_TPGT_FORCE_LOGOUT        ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/force_logout"
#define ISCSI_CONFIGFS_TPGT_DYNAMIC_SESSIONS    ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/dynamic_sessions"
#define ISCSI_CONFIGFS_TPGT_NP_PATH             ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/np"
#define ISCSI_CONFIGFS_TPGT_ACLS_PATH           ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/acls"
#define ISCSI_CONFIGFS_TPGT_AUTH_PATH           ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/auth"
#define ISCSI_CONFIGFS_TPGT_LUNS_PATH           ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/lun"
#define ISCSI_CONFIGFS_TPGT_ATTRIB_DEMO_MODE_DISCOVERY  ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/attrib/demo_mode_discovery"
#define ISCSI_CONFIGFS_TPGT_ATTRIB_GENERATE_NODE_ACLS   ISCSI_CONFIGFS_TPGT_PATH_FORMAT "/attrib/generate_node_acls"
#define ISCSI_CRASH_DUMP_DIR                    "/var/crash"
#define ISCSI_VAR_LOCK_DIR                      "/var/lock"
#define ISCSI_SUBSYS_DIR                        "/var/lock/subsys"
#define ISCSI_METADATA_DIR                      "/var/target"
#define ISCSI_PR_METADATA_DIR                   "/var/target/pr"
#define ISCSI_ALUA_METADATA_DIR                 "/var/target/alua"
#define ISCSI_OVERALL_CONF_DIR_PATH             "/usr/syno/etc"
#define ISCSI_ROD_KEY_PATH                      ISCSI_CONFIGFS_ROOT_PATH "/rodsys/local_key"
#define ISCSI_PROG_PATH_FORMAT                  ISCSI_TMP_DIR_PATH "/P%d.progress"
#define ISCSI_SYNOISNS_BIN_PATH                 "/usr/syno/sbin/synoisns"
#define ISCSI_SYNOISNS_PID_FILE                 "/var/run/synoisns.pid"
#define ISCSI_ISNS_CONF                         "/usr/syno/etc/isns.conf"
#define ISCSI_VSYS_CONFIGFS_ROOT                ISCSI_CONFIGFS_ROOT_PATH "/vsys"
#define ISCSI_VSYS_VLUN_VOLUME                  ISCSI_VSYS_CONFIGFS_ROOT "/%s/vlun_vol_num"
#define ISCSI_VSYS_VLUN_FILE_PATH               ISCSI_VSYS_CONFIGFS_ROOT "/%s/vlun_path"
#define ISCSI_VSYS_VLUN_COMMAND                 ISCSI_VSYS_CONFIGFS_ROOT "/%s/vlun_command"
#define ISCSI_VSYS_VLUN_INFO                    ISCSI_VSYS_CONFIGFS_ROOT "/%s/info"
#define ISCSI_VSYS_VLUN_PROGRESS                ISCSI_VSYS_CONFIGFS_ROOT "/%s/vlun_command_progress"
#define ISCSI_VSYS_VLUN_ERRNO                   ISCSI_VSYS_CONFIGFS_ROOT "/%s/vlun_command_errno"
#define ISCSI_CONFIGFS_DEFER_QUEUE_MODE_PATH    "iscsi_defer_queue_mode"
#define ISCSI_SUBVOL_CONV_PROG_LOCK_PATH        ISCSI_TMP_DIR_PATH "/iscsi_subvol_conv_progress.conf.lock"

/*** constants ***/
#define ISCSI_DD_BUFFER_SIZE                    1048576
#define ISCSI_MAX_RETRY_GENERATE_UUID           16
#define ISCSI_MAX_FILE_INDEX                    20    //TB, ext3 limit 16T (but why 20?, keep 20 for backward compatible)
#define ISCSI_MAX_FILE_INDEX_EXT                1000  //TB, btrfs and ext4 limit 1024*1024TB, but we have ISCSI_LUN_FILE_INDEX_WIDTH limit
#define ISCSI_CONFIGFS_BUFFER_SIZE              4096  //check the ConfigFS document before trying to change this buffer size!
#define ISCSI_LOCK_TIME_NO_LIMIT                -1
#define ISCSI_LOCK_TIME_SHORT                   5     // in seconds
#define ISCSI_LOCK_TIME_CONFIG_FILE             60    // in seconds
#define ISCSI_LOCK_TIME_LUN_CREATION            180   // in seconds
#define ISCSI_LOCK_TIME_CHECK_NODE              60   // in seconds
#define ISCSI_TRUE                              "yes"
#define ISCSI_FALSE                             "no"
#define ISCSI_SUPPORT_KEY_YES                   "yes"
#define ISCSI_SUPPORT_KEY_NO                    "no"
#define ISCSI_RESERVED_FREE_SPACE               (1ULL << 30)  // 1G

/*** keys ***/

/*** etc ***/
#define ISCSI_TAG                               "iSCSI_"
#define ISCSI_SECTION_FORMAT                    "\t%s=%s\n"
#define ISCSI_LOG_KEY                           "iSCSI:"

/*** types ***/
typedef enum _tag_struct_iscsi_chg_type_ {
	TARGET_NAME_CHG     = 0x01,
	PATH_CHG            = 0x02,
	SIZE_CHG            = 0x04,
	LUN_NAME_CHG        = 0x08,
	LUN_TYPE_CHG        = 0x10,
	IQN_CHG             = 0x20,
	NEED_TO_UNLOAD      = 0x40,
} ISCSI_CHG_TYPE;

/*** macro or inline functions ***/
static inline void SYNOiSCSIProcessProgressPath(int pid, char *szPath, int cbPath)
{
	snprintf(szPath, cbPath, ISCSI_PROG_PATH_FORMAT, pid);
}

/*** function declarations ***/
int  SYNOiSCSIConfFilter(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSIiSNSConnect(void);
void SYNOiSCSIiSNSDisconnect(void);
bool SYNOiSCSIiSNSIsConnected(void);
int  SYNOiSCSILoopbackStartAll();
int  SYNOiSCSILoopbackStopAll();
int  SYNOiSCSILoopbackStopAllWithoutLock();
void SYNOiSCSIStateListFree(ISCSI_SESSION_STATE_LIST *pStateList);
int  SYNOiSCSIStopMiscService();
int  SYNOiSCSIStopAll();
int  SYNOiSCSIStopAllWithoutLock();
int  SYNOiSCSITotallyStopAndUnload();
int  SYNOiSCSISubvolConvFileSizeAndCount(const char *szRootPath, const char *szISCSIDirName, int *pFileNum, uint64_t *pTotalSize);
int  SYNOiSCSISubvolConvProgressAdd(ISCSI_SUBVOL_CONV_PROGRESS *subvolConvProgress);
int  SYNOiSCSISubvolConvProgressCompute(const char *szRootPath, bool blInit, ISCSI_SUBVOL_CONV_PROGRESS *subvolConvProgress);
int  SYNOiSCSISubvolConvProgressDelete(const ISCSI_SUBVOL_CONV_PROGRESS *subvolConvProgress);
int  SYNOiSCSISubvolConvProgressGetByUUID(const char *szUUID, ISCSI_SUBVOL_CONV_PROGRESS *pSubvolConvProgress);
int  SYNOiSCSISubvolConvProgressLoad(
		const ISCSI_SUBVOL_CONV_PROGRESS_FILTER *pSubvolConvProgressFilter,
		ISCSI_SUBVOL_CONV_PROGRESS_CONFIG *pSubvolConvProgressConf);
int  SYNOiSCSISubvolConvProgressStatusGet(const char *szRootPath, char *szStatus, int cbStatus);
int  SYNOiSCSISubvolConvProgressStatusUpdate(const char *szStatus, ISCSI_SUBVOL_CONV_PROGRESS *subvolConvProgress);

#ifdef __cplusplus

class SYNOiSCSIServiceLockGuard {
public:
	SYNOiSCSIServiceLockGuard();
	~SYNOiSCSIServiceLockGuard();
private:
	int fd;
};

#endif // __cplusplus

__END_DECLS;

#endif // _SYNOISCSIEP_ISCSI_INTERNAL_H_
