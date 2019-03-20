// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_BANDWIDTH_H__
#define __SYNO_BANDWIDTH_H__

__BEGIN_DECLS
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <synocore/file.h>
#include <synosdk/service.h>

/**
 * @defgroup    bandwidth   Bandwidth
 * @brief       main functions
 */
/**
 * @defgroup    bandwidth_op    Operation
 * @brief       bandwidth calculation
 */
/**
 * @defgroup    bandwidth_addon Addon
 * @brief       Addon file protocol
 */
/**
 * @defgroup    print   Print
 * @brief       Print the configuration
 */

/**
 * @addtogroup  bandwidth
 * @{
 **/
typedef unsigned long long syno_speed_t;
#define SYNO_BANDWIDTH_UNLIMITED_SPEED ((syno_speed_t)0)
#define SYNO_BANDWIDTH_BYTES_PER_KB (1024)
#define SZF_BANDWIDTH_STATUS_DIRECTORY "/tmp/bandwidth/"
#define SZF_BANDWIDTH_INFO_ADDON_DIR "/usr/syno/etc/bandwidth/addon/"

typedef struct _tag_syno_bandwidth_enum_list_ {
	int value;
	const char *name;
} SYNO_BANDWIDTH_ENUM_LIST;

#define SYNO_BW_PROTOCOL_FILESTATION	0x0001
#define SYNO_BW_PROTOCOL_WEBDAV			0x0002
#define SYNO_BW_PROTOCOL_FTP			0x0004
#define SYNO_BW_PROTOCOL_RSYNC			0x0008
/* ALL will not include add on protocol */
#define SYNO_BW_PROTOCOL_ALL			(0x0001 | 0x0002 | 0x0004 | 0x0008)

/* add on protocol, record, but cannot use directly in code !!
 * the id must be got from add on config file, instead of using the define
#define SYNO_BW_PROTOCOL_CLOUD_STATION	0x0010
*/

/* just enum built-in protocol, excluding addon protocol */
#define SYNO_BANDWIDTH_ENUM_PROTOCOL_DECLS(enum_syno_bw_protocol) \
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_protocol[] = {	\
		{SYNO_BW_PROTOCOL_FILESTATION, "filestation"},	\
		{SYNO_BW_PROTOCOL_WEBDAV, "webdav"},			\
		{SYNO_BW_PROTOCOL_FTP, "ftp"},					\
		{SYNO_BW_PROTOCOL_RSYNC, "rsync"},				\
		{SYNO_BW_PROTOCOL_ALL, "all"},					\
		{-1, NULL}										\
	};

typedef struct _tag_syno_bandwidth_hup_entry_ {
	int protocol_type;
	const char* rgszService[8];
	void (*hook)(void);
	BOOL blEnabled;
} SYNO_BANDWIDTH_HUP_ENTRY;

#define SYNO_BANDWIDTH_HUP_TABLE_DECLS(syno_bw_hup_table) \
	SYNO_BANDWIDTH_HUP_ENTRY syno_bw_hup_table[] = {														\
		{0, {NULL}, SYNOBandwidthHupSimulator, TRUE},	\
		{SYNO_BW_PROTOCOL_FILESTATION, {NULL}, SYNOBandwidthHupFileStaion, FALSE},	\
		{SYNO_BW_PROTOCOL_WEBDAV, {NULL}, SYNOBandwidthHupWebDAV, FALSE}, \
		{SYNO_BW_PROTOCOL_FTP, {"ftpd", "ftpd-ssl", "sftp", NULL}, NULL, FALSE},	\
		{SYNO_BW_PROTOCOL_RSYNC, {"rsyncd", NULL}, NULL, FALSE}, \
		{-1, {NULL}, NULL, FALSE}						\
	};

#define SYNO_BANDWIDTH_HUP_TABLE_ADD(syno_bw_hup_table, type) do {			\
	int i = 0;																\
	for (i = 0; -1 != syno_bw_hup_table[i].protocol_type; ++i) {			\
		if (type & syno_bw_hup_table[i].protocol_type) {					\
			syno_bw_hup_table[i].blEnabled = TRUE;							\
		}																	\
	}																		\
} while (0)

#define SYNO_BANDWIDTH_HUP_SIMULATOR(syno_bw_hup_table) do {				\
	syno_bw_hup_table[0].hook();											\
} while (0)

#define SYNO_BANDWIDTH_HUP(syno_bw_hup_table) do {							\
	int i = 0;																\
	int j = 0; \
	for (i = 0; -1 != syno_bw_hup_table[i].protocol_type; ++i) {			\
		if (TRUE == syno_bw_hup_table[i].blEnabled) {						\
			while (NULL != syno_bw_hup_table[i].rgszService[j]) {						\
				SLIBServiceReload((char *)syno_bw_hup_table[i].rgszService[j]); \
				j++; \
			}																\
			if (syno_bw_hup_table[i].hook) {			 					\
				syno_bw_hup_table[i].hook();								\
			}																\
		}																	\
	}																		\
} while (0)

enum SYNO_BANDWIDTH_TRANSFER {
	SYNO_BW_TRANSFER_UPLOAD = 0x01,
	SYNO_BW_TRANSFER_DOWNLOAD = 0x02,
	SYNO_BW_TRANSFER_ALL = SYNO_BW_TRANSFER_UPLOAD | SYNO_BW_TRANSFER_DOWNLOAD,
	SYNO_BW_TRANSFER_MAX = SYNO_BW_TRANSFER_ALL + 1
};
#define SYNO_BANDWIDTH_ENUM_TRANSFER_DECLS(enum_syno_bw_transfer) \
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_transfer[] = {	\
		{SYNO_BW_TRANSFER_UPLOAD, "upload"},							\
		{SYNO_BW_TRANSFER_DOWNLOAD, "download"},						\
		{-1, NULL}														\
	};

enum SYNO_BANDWIDTH_OWNER_TYPE {
	SYNO_BW_OWNER_TYPE_USER = 0x01,
	SYNO_BW_OWNER_TYPE_GROUP = 0x02,
	SYNO_BW_OWNER_TYPE_ALL = SYNO_BW_OWNER_TYPE_USER | SYNO_BW_OWNER_TYPE_GROUP
};
#define SYNO_BANDWIDTH_ENUM_OWNER_TYPE_DECLS(enum_syno_bw_owner_type) \
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_owner_type[] = {	\
		{SYNO_BW_OWNER_TYPE_USER, "user"},								\
		{SYNO_BW_OWNER_TYPE_GROUP, "group"},							\
		{SYNO_BW_OWNER_TYPE_ALL, "all"},								\
		{-1, NULL}														\
	};

enum SYNO_BANDWIDTH_CONF_STATE {SYNO_BW_CONF_STATE_NOTEXIST, SYNO_BW_CONF_STATE_ENABLED, SYNO_BW_CONF_STATE_DISABLED, SYNO_BW_CONF_STATE_SCHEDULE};
#define SYNO_BANDWIDTH_ENUM_CONF_STATE_DECLS(enum_syno_bw_conf_state)	\
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_conf_state[] = {	\
		{SYNO_BW_CONF_STATE_NOTEXIST, "NotExisted"},					\
		{SYNO_BW_CONF_STATE_ENABLED, "enabled"},						\
		{SYNO_BW_CONF_STATE_DISABLED, "disabled"},						\
		{SYNO_BW_CONF_STATE_SCHEDULE, "schedule"},						\
		{-1, NULL}														\
	};

enum SYNO_BANDWIDTH_GROUP_POLICY {
	SYNO_BW_GROUP_POLICY_USER_ONLY,
	SYNO_BW_GROUP_POLICY_GROUP_ONLY,
	SYNO_BW_GROUP_POLICY_USER_FIRST,
	SYNO_BW_GROUP_POLICY_GROUP_FIRST,
	SYNO_BW_GROUP_POLICY_MIN,
	SYNO_BW_GROUP_POLICY_MAX,
	SYNO_BW_GROUP_POLICY_SUM
};
#define SYNO_BANDWIDTH_ENUM_CONF_INTER_GROUP_POLICY_DECLS(enum_syno_bw_conf_inter_group_policy)	\
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_conf_inter_group_policy[] = {	\
		{SYNO_BW_GROUP_POLICY_MIN, "min"},						\
		{SYNO_BW_GROUP_POLICY_MAX, "max"},						\
		{SYNO_BW_GROUP_POLICY_SUM, "sum"},						\
		{-1, NULL}														\
	};

#define SYNO_BANDWIDTH_ENUM_CONF_USER_GROUP_POLICY_DECLS(enum_syno_bw_conf_user_group_policy)	\
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_conf_user_group_policy[] = {	\
		{SYNO_BW_GROUP_POLICY_USER_ONLY, "user-only"},			\
		{SYNO_BW_GROUP_POLICY_GROUP_ONLY, "group-only"},		\
		{SYNO_BW_GROUP_POLICY_USER_FIRST, "user-first"},			\
		{SYNO_BW_GROUP_POLICY_GROUP_FIRST, "group-first"},		\
		{SYNO_BW_GROUP_POLICY_MIN, "min"},						\
		{SYNO_BW_GROUP_POLICY_MAX, "max"},						\
		{SYNO_BW_GROUP_POLICY_SUM, "sum"},						\
		{-1, NULL}														\
	};

enum SYNO_BANDWIDTH_OCCUPY_POLICY {
	SYNO_BW_OCCUPY_POLICY_NONE,
	SYNO_BW_OCCUPY_POLICY_ALL,
	SYNO_BW_OCCUPY_POLICY_MIN,
	SYNO_BW_OCCUPY_POLICY_MAX,
	SYNO_BW_OCCUPY_POLICY_WEIGHTED
};
#define SYNO_BANDWIDTH_ENUM_CONF_OCCUPY_POLICY_DECLS(enum_syno_bw_conf_occupy_policy)	\
	static const SYNO_BANDWIDTH_ENUM_LIST enum_syno_bw_conf_occupy_policy[] = {	\
		{SYNO_BW_OCCUPY_POLICY_NONE, "none"},			\
		{SYNO_BW_OCCUPY_POLICY_ALL, "all"},			\
		{SYNO_BW_OCCUPY_POLICY_MIN, "min"},		\
		{SYNO_BW_OCCUPY_POLICY_MAX, "max"},		\
		{SYNO_BW_OCCUPY_POLICY_WEIGHTED, "weighted"},						\
		{-1, NULL}														\
	};

/********************************** Status File **********************************/
typedef struct _tag_syno_bandwidth_status_ {
	struct _tag_syno_bandwidth_status_ *pNext;
	pid_t pid;									// process id
	unsigned id;								// user/group id
	unsigned uid;								// user id
	unsigned active;							// indicate the process is active or not
	time_t timestamp;							// update timestamp
	syno_speed_t uSpeedBps;						// real speed in bps
	syno_speed_t uExpectSpeedBps;				// expected speed in bps
	char szFileName[PATH_MAX];					// filename
	enum SYNO_BANDWIDTH_OWNER_TYPE owner_type;	// owner type (user or group)
	int  protocol_type;							// protocol type
	enum SYNO_BANDWIDTH_TRANSFER transfer_type;	// transfer type
	unsigned uProgress;							// 98.52% will be stored as 9852.
} SYNO_BANDWIDTH_STATUS, *SYNO_BANDWIDTH_STATUS_LIST;

/*typedef struct _tag_syno_bandwidth_status_node_ {
	//enum SYNO_BANDWIDTH_OWNER_TYPE owner_type;
	//unsigned id;
	SYNO_BANDWIDTH_STATUS bw_status;
	struct _tag_syno_bandwidth_status_node_ *pNext;
} SYNO_BANDWIDTH_STATUS_NODE, *SYNO_BANDWIDTH_STATUS_LIST;*/

#define SYNO_BANDWIDTH_STATUS_TABLE_DECLS(table, status)				\
		SYNO_BANDWIDTH_ENUM_OWNER_TYPE_DECLS(enum_syno_bw_owner_type) \
		SYNO_BANDWIDTH_ENUM_PROTOCOL_DECLS(enum_syno_bw_protocol)	\
		SYNO_BANDWIDTH_ENUM_TRANSFER_DECLS(enum_syno_bw_transfer)	\
		SYNO_BANDWIDTH_FILE_INFO table[] = {						\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "pid", pid, pid_t),										\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "id", id, unsigned),									\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "uid", uid, unsigned),									\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "active", active, unsigned),							\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "timestamp", timestamp, time_t),						\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "current speed", uSpeedBps, syno_speed_t),				\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "expect speed", uExpectSpeedBps, syno_speed_t),			\
		SYNO_BANDWIDTH_EXPAND_STR_TABLE(status, "filename", szFileName),								\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(status, "owner type", owner_type, enum_syno_bw_owner_type),	\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(status, "protocol type", protocol_type, enum_syno_bw_protocol),\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(status, "transfer type", transfer_type, enum_syno_bw_transfer),\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(status, "progress", uProgress, unsigned),						\
		{ NULL, NULL, 0, NULL, NULL, NULL }																\
	};

/********************************** Config File **********************************/

typedef struct _tag_syno_bandwidth_conf_ {
	unsigned id;								// user/group id
	enum SYNO_BANDWIDTH_CONF_STATE state;		// state of the entry
	enum SYNO_BANDWIDTH_CONF_STATE state_config;	// state of the entry
	int  protocol_type;							// protocol type
	enum SYNO_BANDWIDTH_OWNER_TYPE owner_type;	// owner type (user or group)
	syno_speed_t uRate[SYNO_BW_TRANSFER_MAX];	// rate limit for upload/download
	syno_speed_t defRate[SYNO_BW_TRANSFER_MAX];	// rate limit for upload/download
	syno_speed_t cusRate[SYNO_BW_TRANSFER_MAX];	// rate limit for upload/download
	char szSchedulePlan[256];
} SYNO_BANDWIDTH_CONF;
#define SYNO_BANDWIDTH_CONF_TABLE_DECLS(table, conf)	\
		SYNO_BANDWIDTH_ENUM_OWNER_TYPE_DECLS(enum_syno_bw_owner_type) \
		SYNO_BANDWIDTH_ENUM_PROTOCOL_DECLS(enum_syno_bw_protocol) \
		SYNO_BANDWIDTH_ENUM_CONF_STATE_DECLS(enum_syno_bw_conf_state) \
		SYNO_BANDWIDTH_FILE_INFO table[] = {			\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(conf, "id", id, unsigned),													\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "state", state_config, enum_syno_bw_conf_state),							\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "owner type", owner_type, enum_syno_bw_owner_type),					\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "protocol type", protocol_type, enum_syno_bw_protocol),				\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(conf, "upload rate", defRate[SYNO_BW_TRANSFER_UPLOAD], syno_speed_t),			\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(conf, "download rate", defRate[SYNO_BW_TRANSFER_DOWNLOAD], syno_speed_t),		\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(conf, "upload rate custom", cusRate[SYNO_BW_TRANSFER_UPLOAD], syno_speed_t),			\
		SYNO_BANDWIDTH_EXPAND_VAR_TABLE(conf, "download rate custom", cusRate[SYNO_BW_TRANSFER_DOWNLOAD], syno_speed_t),		\
		SYNO_BANDWIDTH_EXPAND_STR_TABLE(conf, "schedule plan", szSchedulePlan), \
		{ NULL, NULL, 0, NULL, NULL, NULL }																			\
	};

/********************************** Global Config File **********************************/
typedef struct _tag_syno_bandwidth_global_conf_ {
	enum SYNO_BANDWIDTH_CONF_STATE state;
	enum SYNO_BANDWIDTH_CONF_STATE state_config;
	int  protocol_type;
	enum SYNO_BANDWIDTH_GROUP_POLICY user_group_policy;
	enum SYNO_BANDWIDTH_GROUP_POLICY inter_group_policy;
	enum SYNO_BANDWIDTH_OCCUPY_POLICY occupy_policy;
	char szSchedulePlan[256];
} SYNO_BANDWIDTH_GLOBAL_CONF;
#define SYNO_BANDWIDTH_GLOBAL_CONF_TABLE_DECLS(table, conf)	\
		SYNO_BANDWIDTH_ENUM_CONF_STATE_DECLS(enum_syno_bw_conf_state) \
		SYNO_BANDWIDTH_ENUM_CONF_USER_GROUP_POLICY_DECLS(enum_syno_bw_conf_user_group_policy) \
		SYNO_BANDWIDTH_ENUM_CONF_INTER_GROUP_POLICY_DECLS(enum_syno_bw_conf_inter_group_policy) \
		SYNO_BANDWIDTH_ENUM_CONF_OCCUPY_POLICY_DECLS(enum_syno_bw_conf_occupy_policy) \
		SYNO_BANDWIDTH_FILE_INFO table[] = {			\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "state", state_config, enum_syno_bw_conf_state),								\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "user-group policy", user_group_policy, enum_syno_bw_conf_user_group_policy),	\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "inter-group policy", inter_group_policy, enum_syno_bw_conf_inter_group_policy),	\
		SYNO_BANDWIDTH_EXPAND_ENUM_TABLE(conf, "occupy policy", occupy_policy, enum_syno_bw_conf_occupy_policy),	\
		SYNO_BANDWIDTH_EXPAND_STR_TABLE(conf, "schedule plan", szSchedulePlan), \
		{ NULL, NULL, 0, NULL, NULL, NULL }																			\
	};

typedef struct _tag_syno_bandwidth_limit_ {
	SYNO_BANDWIDTH_CONF conf;
	syno_speed_t uExpectSpeedBps;	// run-ime buffer, 0 for unlimited
	size_t uOccupyRatio;			// run-time used, indicate whether the conf was chosen, only for group conf, 45.98 => 4598.
} SYNO_BANDWIDTH_LIMIT;

typedef struct _tag_syno_bandwidth_config_ {
	uid_t uid;
	int cLimit;
	BOOL blUserConfExist;
	BOOL blGroupConfExist;
	SYNO_BANDWIDTH_LIMIT *pLimit;
	SYNO_BANDWIDTH_GLOBAL_CONF global_conf;
} SYNO_BANDWIDTH_CONFIG;
/**
 * @}
 */
#ifndef NO_PROTO
#include "synobandwidth_p.h"
#endif // NO_PROTO

__END_DECLS
#endif // __SYNO_BANDWIDTH_H__
