// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/**
 * @addtogroup AHA_WEBAPI_CORE
 *
 * @brief The operations of AHA_WEBAPI_CORE.
 *
 * @{
 */

#ifndef __SYNO_AHA_WEBAPI_CORE_H_
#define __SYNO_AHA_WEBAPI_CORE_H_

#include <synoahacore/aha_core.h>
#include <synocore/list.h>

__BEGIN_DECLS

#define AHA_MAX_DESC_SIZE 64

#define SZ_AHA_KEY_DESC_REMOTE_BOOT_ERROR      "desc_remote_boot_error"
#define SZ_AHA_KEY_DESC_SWITCHOVER_FAILED      "desc_switchover_failed"
#define SZ_AHA_KEY_DESC_FAILOVER_FAILED        "desc_failover_failed"
#define SZ_AHA_KEY_DESC_NO_PASSIVE             "desc_no_passive"
#define SZ_AHA_KEY_DESC_PASSIVE_OFFLINE        "desc_passive_offline"
#define SZ_AHA_KEY_DESC_FAILED_NET_ACTIVE      "desc_failed_net_active"
#define SZ_AHA_KEY_DESC_FAILED_NET_PASSIVE     "desc_failed_net_passive"

// both host are failed, cant failover
#define SZ_AHA_KEY_DESC_FAILED_SERVICE_ACTIVE  "desc_failed_service_active"
#define SZ_AHA_KEY_DESC_FAILED_SERVICE_PASSIVE "desc_failed_service_passive"

#define SZ_AHA_KEY_DESC_ENC_HW_ERROR             "desc_enclosure_hw_error"
#define SZ_AHA_KEY_DESC_INVALID_ENC_LIST_ACTIVE  "desc_invalid_enc_list_active"
#define SZ_AHA_KEY_DESC_INVALID_ENC_LIST_PASSIVE "desc_invalid_enc_list_passive"

#define SZ_AHA_KEY_DESC_HEARTBEAT_LINK_LOST      "desc_heartbeat_link_lost"
#define SZ_AHA_KEY_DESC_SPACE_BUSY               "desc_space_busy"
#define SZ_AHA_KEY_DESC_FCACHE_DEGRADE           "desc_fcache_degrade"
#define SZ_AHA_KEY_DESC_FCACHE_CRASH             "desc_fcache_crashed"
#define SZ_AHA_KEY_DESC_SPACE_RAID_DEGRADE       "desc_space_degrade"
#define SZ_AHA_KEY_DESC_SPACE_RAID_CRASH         "desc_space_crash"

#define SZ_AHA_KEY_DESC_HALT_BLOCKING_ACTIVE     "desc_halt_blocking_active"
#define SZ_AHA_KEY_DESC_HALT_BLOCKING_PASSIVE    "desc_halt_blocking_passive"

#define SZ_AHA_KEY_DESC_HOST_HW_ERROR_ACTIVE     "desc_host_hw_error_active"
#define SZ_AHA_KEY_DESC_HOST_HW_ERROR_PASSIVE    "desc_host_hw_error_passive" // passive hw error.
#define SZ_AHA_KEY_DESC_FAILED_DEVICE_FAN        "fan"
#define SZ_AHA_KEY_DESC_FAILED_DEVICE_POWER      "power"

// can't failover
#define SZ_AHA_KEY_DESC_MEMORY_NOT_MATCH       "desc_memory_not_match" // only show on passive
#define SZ_AHA_KEY_DESC_NO_MONITORED_IF        "desc_no_monitored_if"
#define SZ_AHA_KEY_DESC_MONITORED_IFS_NO_STATIC_IP "desc_monitored_ifs_no_static_ip"

#define SZ_AHA_KEY_DESC_RECOVERING_PASSIVE     "desc_recovering_passive"
#define SZ_AHA_KEY_DESC_UPGRADING_PASSIVE      "desc_upgrading_passive"

#define SZ_AHA_KEY_DESC_HA_NORMAL              "desc_ha_normal"

#define SZ_AHA_WEBAPI_HEARTBEAT_IF     "heartbeat"

#define SZ_AHA_STATUS_HEALTHY          "healthy"
#define SZ_AHA_STATUS_WARNING          "warning"
#define SZ_AHA_STATUS_ERROR            "error"

#define AHA_SWITCHOVE_REMOTE_REBOOT_TIMEOUT 300

typedef enum {
	AHA_WEBAPI_VALUE_UNKNOWN = 0,
	AHA_WEBAPI_VALUE_HEALTHY,
	AHA_WEBAPI_VALUE_NORMAL,
	AHA_WEBAPI_VALUE_WARNING,
	AHA_WEBAPI_VALUE_ERROR,
	AHA_WEBAPI_VALUE_OFFLINE,
	AHA_WEBAPI_VALUE_NONE,
	AHA_WEBAPI_VALUE_RUNNING,
	AHA_WEBAPI_VALUE_STOPPED,
	AHA_WEBAPI_VALUE_LOADING,
	AHA_WEBAPI_VALUE_SWITCHING,
	AHA_WEBAPI_VALUE_SWITCHING_REMOTE,
	AHA_WEBAPI_VALUE_UPGRADING,
	AHA_WEBAPI_VALUE_CONFIGURING,
	AHA_WEBAPI_VALUE_UNKNOWN_SERVER,
	AHA_WEBAPI_VALUE_RECOVERING,
	AHA_WEBAPI_VALUE_BOOT_ERROR,
	AHA_WEBAPI_VALUE_SWITCHING_REMOTE_FAILED,
} AHA_WEBAPI_VALUE;

typedef struct {
	char key[64];
	char info[1024];
} AHA_WEBAPI_DESCRIPTIONS;

typedef struct {
	int status;
	int sync_status;
	int heartbeat_link_status;
	int total;
	BOOL can_switchover;
	BOOL can_failover;
	BOOL recover_remote;
	BOOL login_ip_is_static;
	BOOL is_remote_boot_done;
	AHA_WEBAPI_DESCRIPTIONS descriptions[AHA_MAX_DESC_SIZE];
} AHA_WEBAPI_AHA_INFO;

typedef struct {
	char sn[MAX_SN_SIZE];
	AHA_ROLE_STATUS role;
	int physical_position;
	int fan_status;
	int power_status;
	int thermal;
	int memory_size;
	int net_status;
	int storage_status;
	int status;
} AHA_WEBAPI_NODE_INFO;

typedef struct {
	char name[SYNO_IFNAME_MAX];
	BOOL is_active_connected;
	int active_speed;
	BOOL is_passive_connected;
	int passive_speed;
	BOOL is_bond_mode;
	int bond_id;
	int status;
	BOOL is_monitored;
} AHA_WEBAPI_NET_INFO;

typedef struct {
	AHA_ROLE_STATUS role;
	char sn[MAX_SN_SIZE];
	int thermal;
	int memory_size;
	AHA_WEBAPI_VALUE fan_status;
	AHA_WEBAPI_VALUE power_status;
} AHA_WEBAPI_NODE_INFO_UI;

typedef enum {
	AHA_WEBAPI_MONITOR_SYSTEM,
	AHA_WEBAPI_MONITOR_SERVICE,
	AHA_WEBAPI_MONITOR_NETWORK,
} AHA_WEBAPI_MONITOR_TYPE;

typedef struct {
	BOOL is_monitored;
	char name[64];
	AHA_WEBAPI_VALUE status;
} AHA_WEBAPI_MONITOR_ITEMS;

typedef struct {
	AHA_WEBAPI_VALUE status;
	AHA_WEBAPI_VALUE status_of_local;
	AHA_WEBAPI_VALUE status_of_remote;
	AHA_WEBAPI_VALUE power_status;
	AHA_WEBAPI_VALUE fan_status;
} AHA_WEBAPI_ENCLOSURE_INFO;

typedef struct {
	AHA_ROLE_STATUS role;
	AHA_HALT_CHECK_RESULT local;
	AHA_HALT_CHECK_RESULT remote;
} AHA_WEBAPI_POWEROFF_CHECK;

/**
 * Get AHA info from cache
 *
 * @param[out] pAHAInfo  The output AHA info
 * @param[in]  blBlock   Whether to block a period time for waiting new cache or not
 *
 * @retval  1 Success
 * @retval  0 No cache or the cache is out of date
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetAHAInfoCached(AHA_WEBAPI_AHA_INFO *pAHAInfo, BOOL blBlock), -1);

/**
 * Get node info from cache
 *
 * @param[in]  role          The role of node to be get. Should be either @ref AHA_ROLE_ACTIVE or @ref AHA_ROLE_PASSIVE
 * @param[out] pAHANodeInfo  The output node info
 * @param[in]  blBlock       Whether to block a period time for waiting new cache or not
 *
 * @retval  1 Success
 * @retval  0 No cache or the cache is out of date
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetNodeInfoCached(AHA_ROLE_STATUS role, AHA_WEBAPI_NODE_INFO *pAHANodeInfo, BOOL blBlock), -1);

/**
 * Get AHA net info
 *
 * @note This function must be called on active server.
 *
 * @param[out] ppAHANetInfo  The output net info array
 * @param[in]  size          The array length of @p ppAHANetInfo
 * @param[out] length        The numbers of net infos actually be gotten
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetNetInfo(AHA_WEBAPI_NET_INFO *ppAHANetInfo, int size, int *length), -1);

/**
 * Get AHA monitor info
 *
 * @param[in]  type               The type of monitor info to be get
 * @param[out] ppAHAMonitorItems  The output monitor item array
 * @param[in]  max_size           The array length of @p ppAHAMonitorItems
 * @param[out] length             The numbers of monitor items actually be gotten
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAListMonitor(AHA_WEBAPI_MONITOR_TYPE type, AHA_WEBAPI_MONITOR_ITEMS *ppAHAMonitorItems, int max_size, int *length), -1);

/**
 * Set AHA monitor info
 *
 * @param[in] type               The type of monitor info to be set
 * @param[in] ppAHAMonitorItems  The monitor item array to be set
 * @param[in] max_size           The array length of @p ppAHAMonitorItems
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHASetMonitor(AHA_WEBAPI_MONITOR_TYPE type, AHA_WEBAPI_MONITOR_ITEMS *ppAHAMonitorItems, int max_size), -1);

/**
 * Get AHA enclosure info
 *
 * @note This function must be called on active server.
 *
 * @param[out] pAHAEnclosureInfo  The output enclosure info
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetEnclosure(AHA_WEBAPI_ENCLOSURE_INFO *pAHAEnclosureInfo), -1);

/**
 * Check if there has any poweroff feasibility constrain and should halt and
 * wait on @p role
 *
 * @note This function must be called on active server.
 *
 * @param[in]  role                The role to be checked. Should be either @ref AHA_ROLE_ACTIVE or @ref AHA_ROLE_PASSIVE
 * @param[out] poweroff            The output halt information
 * @param[in]  blStoreBlockStatus  Whether to store the halt information into ha.status or not
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHACheckHaltOpt(AHA_ROLE_STATUS role, AHA_WEBAPI_POWEROFF_CHECK *poweroff, BOOL blStoreBlockStatus), -1);
__END_DECLS

#endif

/**
 * @}
 */
