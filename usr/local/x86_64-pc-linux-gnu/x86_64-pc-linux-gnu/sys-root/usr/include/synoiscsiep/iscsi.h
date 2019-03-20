/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_ISCSI_H_
#define _SYNOISCSIEP_ISCSI_H_

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <search.h>
#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <synocore/string.h>
#include <synonetsdk/net.h>
#include <synosdk/wins.h>
#include <synostoragecore/space.h>
#include <synoiscsiep/iscsi_error.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_TMP_DIR_NAME                      "tmp"
#define ISCSI_VOLUME_TMP_DIR_FORMAT             "%s/" ISCSI_DIR_NAME "/" ISCSI_TMP_DIR_NAME
#define ISCSI_INITIATOR_SERVICE_PATH            "/usr/syno/etc.defaults/rc.iscsi"
#define ISCSI_INITIATOR_SERVICE_PID_PATH        "/var/run/iscsid.pid"
#define ISCSI_ISCSIADM_BIN_PATH                 "/sbin/iscsiadm"
#define ISCSI_ISCSIADM_NODES_PATH               "/etc/iscsi/nodes"
#define ISCSI_ISCSISCHSNAPTOOL_BIN_PATH         "/usr/syno/bin/iscsischsnaptool"
#define ISCSI_CONFIGFS_ROOT_PATH                "/config"
#define ISCSI_CONFIGFS_TARGET_ROOT_PATH         ISCSI_CONFIGFS_ROOT_PATH "/target"
#define ISCSI_CONFIGFS_CORE_ROOT_PATH           ISCSI_CONFIGFS_TARGET_ROOT_PATH "/core"
#define ISCSI_CONFIGFS_FILEIO_0_NAME            "fileio_0"
#define ISCSI_CONFIGFS_FILEIO_0_PATH            ISCSI_CONFIGFS_CORE_ROOT_PATH "/" ISCSI_CONFIGFS_FILEIO_0_NAME
#define ISCSI_CONFIGFS_BLOCKIO_0_NAME           "iblock_0"
#define ISCSI_CONFIGFS_BLOCKIO_0_PATH           ISCSI_CONFIGFS_CORE_ROOT_PATH "/" ISCSI_CONFIGFS_BLOCKIO_0_NAME

// TODO: These definitions should be in the internal header when all callers are migrate to webapi or something else.
#define ISCSI_DIR_NAME                          "@iSCSI"
#define ISCSI_TMP_DIR_PATH                      "/tmp/iscsi"

/*** constants ***/
#define ISCSI_MAX_FILE_PATH_SIZE                (MAX_LEN_ISCSI_NAME + 64)
#define ISCSI_MAX_SECTION_SIZE                  64
#define ISCSI_UUID_SIZE                         16                       // in binary format
#define ISCSI_UUID_STRING_SIZE                  (ISCSI_UUID_SIZE * 2 + 5) // format: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
#define ISCSI_UUID_STRING_SIZE_SHORT            (ISCSI_UUID_SIZE * 2 + 1) // format: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define ISCSI_PORTAL_KEY_SIZE                   13
#define ISCSI_VLUN_NOTE_SIZE                    1024
#define ISCSI_MAX_SESSION_ID                    128
#define ISCSI_CONFIG_NO_ADDITIONAL_FLAG         0
#define ISCSI_RODSP_DEFAULT_PORT                3261
#define ISCSI_DEFAULT_CLONE_LUN_SID             0
#define ISCSI_NO_TIMEOUT_LIMIT                  0
#define ISCSI_TIMEOUT_OF_CREATE_LUN             300    // in seconds
#define ISCSI_TIMEOUT_OF_EXPORT_CANCEL          180    // in seconds
#define ISCSI_TIMEOUT_OF_IMPORT_CANCEL          180    // in seconds
#define ISCSI_TIMEOUT_OF_TAKE_SNAPSHOT          1800   // in seconds
#define ISCSI_TIMEOUT_OF_ISNS_CONNECT           3      // in seconds
#define ISCSI_SLEEP_TIME_SHORT                  1      // in seconds
#define ISCSI_SLEEP_TIME_NOT_SO_SHORT           3      // in seconds
#define ISCSI_SLEEP_TIME_MIDDLE                 10     // in seconds
#define SZV_ISCSI_STEP_CREATING                 "creating"
#define SZV_ISCSI_STEP_DELETING                 "deleting"
#define SZV_ISCSI_STEP_PROCESSING               "processing"

#define ISCSI_LOAD_TARGET                       0x001000
#define ISCSI_LOAD_LUN                          0x002000
#define ISCSI_LOAD_MAPPING                      0x004000
#define ISCSI_LOAD_ACL                          0x008000
#define ISCSI_FILTER_MASK                       0xf00fff

/*** keys ***/
#define ISCSI_DR_SNAP_SUPPORT_KEY               "support_dr_snap"
#define SZK_ISCSI_LID                           "lid"
#define SZK_ISCSI_TID                           "tid"
#define SZK_ISCSI_SID                           "sid"
#define SZK_ISCSI_LUN                           "lun"
#define SZK_ISCSI_TYPE                          "type"
#define SZK_ISCSI_DEVTYPE                       "devtype"
#define SZK_ISCSI_RESTORED_TIME                 "restored_time"
#define SZK_ISCSI_NAME                          "name"
#define SZK_ISCSI_IQN                           "iqn"
#define SZK_ISCSI_ENABLED                       "enabled"
#define SZK_ISCSI_ROOTPATH                      "rootpath"
#define SZK_ISCSI_SIZE                          "bytes"
#define SZK_ISCSI_PRE_ALLOC                     "pre_alloc"
#define SZK_ISCSI_IS_AUTHEN                     "authen"
#define SZK_ISCSI_AUTHEN_USERNAME               "username"
#define SZK_ISCSI_AUTHEN_PASSWORD               "password"
#define SZK_ISCSI_IS_MUTUAL                     "mutual"
#define SZK_ISCSI_MUTUAL_USERNAME               "mutual_username"
#define SZK_ISCSI_MUTUAL_PASSWORD               "mutual_password"
#define SZK_ISCSI_HDR_CHKSUM                    "hdr_chksum"
#define SZK_ISCSI_DATA_CHKSUM                   "data_chksum"
#define SZK_ISCSI_SENDSEG_BYTES                 "send_seg_bytes"
#define SZK_ISCSI_RECVSEG_BYTES                 "recv_seg_bytes"
#define SZK_ISCSI_MAX_SESSIONS                  "max_sessions"
#define SZK_ISCSI_ACL_AUTHORITY                 "authority"
#define SZK_ISCSI_ADDRESS                       "address"
#define SZK_ISCSI_BKPOBJ                        "bkp_obj"
#define SZK_ISCSI_LUNCMD                        "lun_command"
#define SZK_ISCSI_IS_VAAI                       "vaai_support"
#define SZK_ISCSI_BLOCKSIZE                     "blocksize"
#define SZK_ISCSI_UUID                          "uuid"
#define SZK_ISCSI_VPD_UNIT_SERIAL               "vpd_unit_serial"
#define SZK_ISCSI_IS_SOURCE                     "is_source"
#define SZK_ISCSI_SOURCE_LUN                    "source_lun"
#define SZK_ISCSI_DESTINATION_LUN               "destination_lun"
#define SZK_ISCSI_SOURCE_NODE                   "source_node"
#define SZK_ISCSI_DESTINATION_NODE              "destination_node"
#define SZK_ISCSI_ROOT_PATH                     "root_path"
#define SZK_ISCSI_PARENT_TASK                   "parent_task"
#define SZK_ISCSI_TASK                          "task"
#define SZK_ISCSI_SENDING_SNAPSHOT              "sending_snapshot"
#define SZK_ISCSI_BASE_SNAPSHOT                 "base_snapshot"
#define SZK_ISCSI_SYNC_SIZE                     "sync_size"
#define SZK_ISCSI_SENT_SIZE                     "sent_size"
#define SZK_ISCSI_ERROR_NO                      "error_no"
#define SZK_ISCSI_PARENT_LID                    "parent_lid"
#define SZK_ISCSI_PARENT_SID                    "parent_sid"
#define SZK_ISCSI_CREATE_TIME                   "time"
#define SZK_ISCSI_NOTE                          "note"
#define SZK_ISCSI_STATUS                        "status"
#define SZK_ISCSI_SNAPTYPE                      "type"
#define SZK_ISCSI_LOCK                          "lock"
#define SZK_ISCSI_SCHEDULED                     "scheduled"
#define SZK_ISCSI_TASK_NAME                     "task"
#define SZK_ISCSI_TOTAL_SIZE                    "total_size"
#define SZK_ISCSI_EXTENT_SIZE                   "extent_size"
#define SZK_ISCSI_SNAPSHOT_TIME                 "snapshot_time"
#define SZK_ISCSI_TAKEN_BY                      "taken_by"
#define SZK_ISCSI_VERSION                       "version"
#define SZK_ISCSI_SOURCE_LUN                    "source_lun"
#define SZK_ISCSI_SCANNED_SIZE                  "scanned_size"
#define SZK_ISCSI_UNSYNC_SIZE                   "unsync_size"
#define SZK_ISCSI_PARENT_UUID                   "parent_uuid"
#define SZK_ISCSI_TOTAL_NUMBER                  "total_number"
#define SZK_ISCSI_DONE_NUMBER                   "done_number"
#define SZK_ISCSI_DONE_SIZE                     "done_size"
#define SZK_ISCSI_IS_APP_CONSISTENCE            "isAppConsistence"
#define SZK_ISCSI_MAPPED_SIZE                   "mappedSize"
#define SZK_ISCSI_PROGRESS                      "progressing"
#define SZK_ISCSI_TASK                          "task"
#define SZK_ISCSI_PROGRESS_LID                  "lid"
#define SZK_ISCSI_PROGRESS_PID                  "pid"
#define SZK_ISCSI_PROGRESS_STEP                 "step"
#define SZK_ISCSI_PROGRESS_TOTAL_BYTES          "total_bytes"
#define SZK_ISCSI_PROGRESS_ORG_PATH             "org_path"
#define SZK_ISCSI_PROGRESS_NEW_PATH             "new_path"
#define SZK_ISCSI_PROGRESS_NAME                 "name"
#define SZK_ISCSI_PROGRESS_DONE_BYTES           "done_bytes"
#define SZK_ISCSI_LUN_TYPE                      "lun_type"
#define SZK_ISCSI_NETWORK_PORTALS               "network_portals"

/*** etc ***/
#define ISCSI_ISCSITRG_SERVICE_NAME             "iscsitrg"

// iscsi folder convert to subvolume
#define SZ_VOL_TMP_DIR                           "%s/@tmp"
#define ISCSI_DIR_MAX_TRAVERSE_LEVEL             5
#define ISCSI_DIR_SUBVOL_CONV_NAME               "@iSCSI_for_subvol_conv"
#define ISCSI_DIR_SUBVOL_CONV_PATH_FORMAT        "%s/" ISCSI_DIR_SUBVOL_CONV_NAME
#define ISCSI_SUBVOL_CONV_TAG                    "SUBVOLCONV_"
#define ISCSI_SUBVOL_CONV_SECTION_FORMAT         ISCSI_SUBVOL_CONV_TAG "%s"
#define ISCSI_SUBVOL_CONV_PROG_PATH              "/usr/syno/etc/iscsi_subvol_conv_progress.conf"
#define ISCSI_SUBVOL_CONV_LOCK_PATH_FORMAT       SZ_VOL_TMP_DIR "/iscsi_subvol_conv.lock"
#define ISCSI_SUBVOL_CONV_PROG_LOCK_PATH_FORMAT  SZ_VOL_TMP_DIR "/iscsi_subvol_conv_progress.lock"
#define ISCSI_CONV_PROG_STATUS_CONVERTED         "Converted"
#define ISCSI_CONV_PROG_STATUS_NOT_CONVERTED     "Not Converted"
#define ISCSI_CONV_PROG_STATUS_CONVERTING        "Converting"
#define ISCSI_CONV_PROG_STATUS_CONVERT_FAILED    "Convert Failed"

/*** types ***/
typedef enum _tag_iscsi_engine_support_ {
	ISCSI_NONE_SUPPORT     = 0x00,
	ISCSI_LIO_4_0_SUPPORT  = 0x02,
	ISCSI_LIO_4_X_SUPPORT  = 0x04,
} ISCSI_SUPPORT_TYPE;

/*
 * It's compatible with struct qelem in <search.h>
 * You may need to include <search.h> or implement your own insque/remque
 * when using it. Please refer to insque/remque manpages for more details.
 */
typedef struct _tag_LINKEDLIST_LIST_ {
	struct _tag_LINKEDLIST_LIST_* q_forw;
	struct _tag_LINKEDLIST_LIST_* q_back;
} SYNO_LINKED_LIST;

typedef enum _tag_iscsi_filter_type_ {
	ISCSI_ALL                = 0x0000 | ISCSI_LOAD_TARGET | ISCSI_LOAD_LUN | ISCSI_LOAD_MAPPING,
	ISCSI_BY_TID             = 0x0001 | ISCSI_LOAD_TARGET,
	ISCSI_BY_ROOT_PATH       = 0x0002 | ISCSI_LOAD_LUN,
	ISCSI_BY_TARGET_NAME     = 0x0004 | ISCSI_LOAD_TARGET,
	ISCSI_BY_IQN             = 0x0008 | ISCSI_LOAD_TARGET,
	ISCSI_BY_LUN_NAME        = 0x0010 | ISCSI_LOAD_LUN,
	ISCSI_BY_LID             = 0x0020 | ISCSI_LOAD_LUN,
	ISCSI_BY_LUN             = 0x0040 | ISCSI_LOAD_MAPPING,
	ISCSI_BY_LID_LIST        = 0x0080 | ISCSI_LOAD_LUN,
	ISCSI_BY_TID_LIST        = 0x0100 | ISCSI_LOAD_TARGET,
	ISCSI_ALL_CONNECTED      = 0x0200 | ISCSI_LOAD_TARGET | ISCSI_LOAD_LUN | ISCSI_LOAD_MAPPING,
	ISCSI_ALLOW_BKPOBJ       = 0x0400,
	ISCSI_BY_EPLUN_SUPPORT   = 0x0800 | ISCSI_LOAD_LUN,
	// 0x0ff000 is reserved for load masks.
	ISCSI_BY_UUID            = 0x100000 | ISCSI_LOAD_LUN,
	ISCSI_BY_STORAGE_MANAGER = 0x200000 | ISCSI_LOAD_TARGET | ISCSI_LOAD_LUN | ISCSI_LOAD_MAPPING,
	ISCSI_BY_FIRST_MATCHED   = 0x400000,
} ISCSI_FILTER_TYPE;

typedef struct _tag_iscsi_filter_ {
	ISCSI_FILTER_TYPE type;
	int tid; //Target ID
	int lid; //Lun ID
	int lun; //map lun
	const char *szRootPath; // e.g. /volume1
	const char *szName;
	const char *szLunName;
	const char *szIQN;
	const int *pTidList;
	const int *pLidList;
	int lenTidList;
	int lenLidList;
	const char *szUUID;
} ISCSI_FILTER;

typedef enum _tag_iscsi_status_ {
	ISCSI_STANDBY,
	ISCSI_CONNECTED,
	ISCSI_OFFLINE,
} ISCSI_STATUS;

typedef enum _tag_iscsi_progress_step_ {
	ISCSI_FINISH,
	ISCSI_SETTING_CHANGING,
	ISCSI_LOCATION_MOVING,
	ISCSI_FILE_CREATING,
	ISCSI_FILE_EXPANDING,
	ISCSI_FILE_DELETING,
	ISCSI_FILE_CLONING,
	ISCSI_FILE_BE_COMMITING,
	ISCSI_FILE_RESTORING,
	ISCSI_FILE_BE_CLONING,
	ISCSI_FILE_SNAPSHOTTING,
	ISCSI_FILE_SNAPSHOT_DELETING,
	ISCSI_FILE_WAIT_FOR_CREATE,
} ISCSI_PROGRESS_STEP;

typedef struct _tag_iscsi_progress_state_ {
	int lid;
	pid_t pid;
	ISCSI_PROGRESS_STEP st;
	uint64_t doneBytes;
	uint64_t totalBytes;
	char szOldPath[128]; //for /volume1
	char szNewPath[128]; //for /volume1
	char szName[MAX_LEN_ISCSI_NAME]; //for iSCSI target name
	bool isExtentLun;
} ISCSI_PROGRESS_STATE;

typedef struct _tag_iscsi_session_state_ {
	bool blConnected;
	char szIPConnected[CB_SZ_IPv6];
	char szSID[ISCSI_MAX_SESSION_ID];
	char szInitiatorIQN[MAX_LEN_ISCSI_NAME];
	int cid;
	SYNO_LINKED_LIST list;
} ISCSI_SESSION_STATE;

typedef struct _tag_iscsi_session_state_list_ {
	int state_cnt;
	SYNO_LINKED_LIST states;
} ISCSI_SESSION_STATE_LIST;

typedef struct _tag_iscsi_status_report_ {
	ISCSI_STATUS st;
	ISCSI_PROGRESS_STATE stProgress;
} ISCSI_STATUS_REPORT;

typedef enum {
	ISCSI_ONLY_COUNT,
	ISCSI_DO_START
} ISCSI_START_TYPE;

typedef struct _tag_iscsi_config_ {
	int lun_cnt;
	int target_cnt;
	int mapping_cnt;
	SYNO_LINKED_LIST luns;
	SYNO_LINKED_LIST targets;
	SYNO_LINKED_LIST mappings;
} ISCSI_CONFIG, *PISCSI_CONFIG;

typedef struct _tag_iscsi_isns_config_ {
	bool blEnabled;
	char szAddress[512];    // no existent definition for max length of URL
} ISCSI_ISNS_CONFIG;

typedef enum _tag_iscsitrack_type_ {
	TRACK_TYPE_UNKNOWN,
	TRACK_TYPE_FULL,
	TRACK_TYPE_CBT
} ISCSI_TRACK_TYPE;

typedef struct _tag_iscsi_version_info_ {
	ISCSI_TRACK_TYPE type;
	char szUUID[ISCSI_UUID_STRING_SIZE];
	char szPreviousTrackID[ISCSI_UUID_STRING_SIZE];
	char szBaseTrackID[ISCSI_UUID_STRING_SIZE];
	char szCurrentTrackID[ISCSI_UUID_STRING_SIZE];
	unsigned int promoteTime;
} ISCSI_VERSION_INFO;

// iSCSI convert to subvolume progress
typedef struct _tag_iscsi_conv_to_subvol_progress_ {
	uint64_t totalSize;
	uint64_t doneSize;
	int totalNum;
	int doneNum;
	int errorNo;
	char szStatus[ISCSI_MAX_SECTION_SIZE];
	char szTask[ISCSI_UUID_STRING_SIZE];
	char szRootPath[MAX_PATH_LEN];
	SYNO_LINKED_LIST list;
} ISCSI_SUBVOL_CONV_PROGRESS;

typedef enum _tag_iscsi_subvol_conv_progress_filter_type_ {
	ISCSI_SUBVOL_CONV_PROGRESS_ALL                 = 0x0000,
	ISCSI_SUBVOL_CONV_PROGRESS_BY_TASK             = 0x0001,
	ISCSI_SUBVOL_CONV_PROGRESS_BY_ROOT_PATH        = 0x0002,
} ISCSI_SUBVOL_CONV_PROGRESS_FILTER_TYPE;

typedef struct _tag_iscsi_subvol_conv_progress_filter_ {
	ISCSI_SUBVOL_CONV_PROGRESS_FILTER_TYPE type;
	const char *szTask;
	const char *szRootPath;
} ISCSI_SUBVOL_CONV_PROGRESS_FILTER;

typedef struct _tag_iscsi_subvol_conv_progress_config_ {
	int subvol_conv_progress_cnt;
	SYNO_LINKED_LIST subvol_conv_progress_list;
} ISCSI_SUBVOL_CONV_PROGRESS_CONFIG;

/*** macro or inline functions ***/
#define LIST_HEAD_INIT(ptr)                        \
	do {                                             \
		(ptr)->q_forw = (ptr); (ptr)->q_back = (ptr);  \
	} while(0)

#define LIST_EMPTY(ptr) ((ptr)->q_forw == (ptr))

/**
 * insert a new entry after the specified head.
 */
#define LIST_ADD(ptr, head) insque(ptr, head)

/**
 * insert a new entry before the specified head.
 */
#define LIST_ADD_TAIL(ptr, head) insque(ptr, (head)->q_back)

/**
 * delete entry from list
 */
#define LIST_DEL(ptr) remque(ptr)

/**
 * get the structruct for this entry
 */
#define LIST_ENTRY(ptr, type, member) ({                         \
	const __typeof__(((type*)0)->member)*__mptr = (ptr);           \
	(type*)((char*)__mptr - OFFSET_OF(type, member));})

/**
 * iterate over a list of given type
 */
#define LIST_FOR_EACH_ENTRY(pos, head, member)                        \
	for (pos = LIST_ENTRY((head)->q_forw, __typeof__(*pos), member);    \
			&pos->member != (head);                                         \
			pos = LIST_ENTRY(pos->member.q_forw, __typeof__(*pos), member))

/**
 * iterate over a list safe against removal of list entry
 */
#define LIST_FOR_EACH_ENTRY_SAFE(pos, n, head, member)                   \
	for (pos = LIST_ENTRY((head)->q_forw, __typeof__(*pos), member),       \
			n = LIST_ENTRY(pos->member.q_forw, __typeof__(*pos), member);      \
			&pos->member != (head);                                            \
			pos = n, n = LIST_ENTRY(n->member.q_forw, __typeof__(*n), member))

#define LIST_FREE(head, type, member)                           \
	while (!LIST_EMPTY(head)) {                                   \
		type* __lptr = LIST_ENTRY((head)->q_forw, type, member);    \
		LIST_DEL((head)->q_forw);                                   \
		free(__lptr);                                               \
	}

#define LIST_FIRST_ENTRY(pos, head, member)                     \
	(pos = ((LIST_EMPTY(head)) ? NULL :                           \
		LIST_ENTRY((head)->q_forw, typeof(*pos), member)))

#define LIST_LAST_ENTRY(pos, head, member)                      \
	(pos = ((LIST_EMPTY(head)) ? NULL :                           \
		LIST_ENTRY((head)->q_back, typeof(*pos), member)))

#define LIST_CONFIG_HEAD_INIT(p_config)                         \
	do {                                                          \
		LIST_HEAD_INIT(&(p_config)->targets);                       \
		LIST_HEAD_INIT(&(p_config)->luns);                          \
		LIST_HEAD_INIT(&(p_config)->mappings);                      \
	} while (0)

#define LIST_CONFIG_HEAD_FREE(p_config)                         \
	do {                                                          \
		if ((p_config)->target_cnt) {                               \
			LIST_FREE(&(p_config)->targets, ISCSI_TARGET, list);      \
			(p_config)->target_cnt = 0;                               \
		}                                                           \
		if ((p_config)->lun_cnt) {                                  \
			LIST_FREE(&(p_config)->luns, ISCSI_LUN, list);            \
			(p_config)->lun_cnt = 0;                                  \
		}                                                           \
		if ((p_config)->mapping_cnt) {                              \
			LIST_FREE(&(p_config)->mappings, ISCSI_MAPPING, list);    \
			(p_config)->mapping_cnt = 0;                              \
		}                                                           \
	} while (0)

#define LIST_ISCSI_SUBVOL_CONV_PROGRESS_CONFIG_HEAD_INIT(p_config)                                 \
	do {                                                                                           \
		LIST_HEAD_INIT(&(p_config)->subvol_conv_progress_list);                                    \
	} while (0)

#define LIST_ISCSI_SUBVOL_CONV_PROGRESS_CONFIG_HEAD_FREE(p_config)                                 \
	do {                                                                                           \
		if ((p_config)->subvol_conv_progress_cnt) {                                                \
			LIST_FREE(&(p_config)->subvol_conv_progress_list, ISCSI_SUBVOL_CONV_PROGRESS, list);   \
			(p_config)->subvol_conv_progress_cnt = 0;                                              \
		}                                                                                          \
	} while (0)

#define ISCSIINFO(format, ...) syslog(LOG_INFO,    "iSCSI:%s:%d:%s " format, \
		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, __func__, ## __VA_ARGS__)
#define ISCSIWARN(format, ...) syslog(LOG_WARNING, "iSCSI:%s:%d:%s " format, \
		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, __func__, ## __VA_ARGS__)
#define ISCSIERR(format, ...)  syslog(LOG_ERR,     "iSCSI:%s:%d:%s " format, \
		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, __func__, ## __VA_ARGS__)

#define ISCSIWEBAPILOG(mesg) syslog(LOG_DEBUG, "[D] iSCSIWebAPI:%s:%d:%s %s", \
		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, __func__, mesg)
#define ISCSIWEBAPIERRLOG(errorno, mesg) syslog(LOG_ERR, "[E] iSCSIWebAPI:%s:%d:%s error code: %d (%s) [%s]", \
		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, __func__, \
		errorno, SYNOiSCSIStrError(errorno), mesg)

/*** function declarations ***/
int  SYNOiSCSIBaseMkdir(const char *szRootPath);
void SYNOiSCSIConfFree(ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSIConfGet(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSIConfSectionEnum(const char *szFilePath, PSLIBSZLIST *ppslOutSections);
int  SYNOiSCSIConfigfsWrite(const char *szPath, const char *szString);
int  SYNOiSCSIConfigfsPrintf(const char *szPath, const char *szFormat, ...);
int  SYNOiSCSIConfigfsPutInteger(const char *szPath, int intVal);
int  SYNOiSCSIConfigfsGetInteger(const char *szPath, int *pInt);
int  SYNOiSCSIConfigfsGetBool(const char *szPath, bool *pBool);
int  SYNOiSCSIConfigfsGetString(const char *szPath, char *szString, size_t stringSize);
int  SYNOiSCSICrashHandler(const SPACE_INFO *pSpace);
int  SYNOiSCSIDirPathGet(const char *szRootPath, char *szISCSIDirPath, int cbISCSIDirPath);
ISCSI_SUPPORT_TYPE SYNOiSCSIGetLioVersion();
int  SYNOiSCSIiSNSConfGet(ISCSI_ISNS_CONFIG* pConf);
int  SYNOiSCSIiSNSConfSet(const ISCSI_ISNS_CONFIG* pConf);
int  SYNOiSCSIRepair();
int  SYNOiSCSIServiceIsInUse(bool *pBool);
int  SYNOiSCSISubvolConvProgressGetByRootpath(const char *szRootPath, ISCSI_SUBVOL_CONV_PROGRESS *pSubvolConvProgress);
int  SYNOiSCSISubvolConvStart(const char *szRootPath);
int  SYNOiSCSITimebkpSetup(const char *targetName, int volId, int sizeGB);
int  SYNOiSCSITimebkpTearDown(const char *targetName);
int  SYNOiSCSIUsedSpaceGet(const char *szRootPath, uint64_t *pAllocatedSize);
int  SYNOiSCSIUuidStrGen(char uuidStr[ISCSI_UUID_STRING_SIZE]);

// TODO: These SDK functions should be in the internal header when all callers are migrate to webapi or something else.
int  SYNOiSCSIMigrateFromIetToLio();
int  SYNOiSCSIStartAll(void);

// For compatibility in project: libsynodr
#define EP_META_UUID_STRING_LEN ISCSI_UUID_STRING_SIZE

__END_DECLS;

#endif // _SYNOISCSIEP_ISCSI_H_
