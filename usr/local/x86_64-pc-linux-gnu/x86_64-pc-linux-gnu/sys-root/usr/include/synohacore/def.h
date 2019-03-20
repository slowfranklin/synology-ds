// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_DEF_H
#define __SYNOHACORE_DEF_H

#define SZ_CONF_SUFFIX ".conf"
#define SZ_CONF_PREFIX SZD_HA_TMP_FOLDER"/ha_dc_"

// put at "/var/lib/ha/sync" because we want to sync this file to passive
#define SZF_FIRST_TIME_SYNCED           SZD_HA_PREFIX"/var/lib/ha/sync/first_time_synced"

#define SZK_HA_CMD_BINDING              "cmd_node_binding"
#define SZK_HA_CMD_HACONF_SYNC          "cmd_haconfig_sync"
#define SZK_HA_CMD_HACONF_SYNC_RT       "cmd_haconfig_sync_rt"
#define SZK_HA_CMD_REBOOT               "cmd_node_reboot"
#define SZK_HA_CMD_UNBIND               "cmd_node_unbind"
#define SZK_HA_CMD_VERIFY               "cmd_node_verify"
#define SZK_HA_CMD_CHECK_SERVICES       "cmd_node_check_services"

#define SZK_HA_CMD_GET_REMOTE_INTERFACE_IP              "get_remote_interface_ip"
#define SZK_HA_CMD_GET_REMOTE_DRBD_VLAN_INFO            "get_remote_drbd_vlan_info"
#define SZK_HA_CMD_GET_REMOTE_DRBDIP_CONFLICT_INFO      "get_remote_drbdip_conflict_info"
#define SZK_HA_CMD_GET_REMOTE_LINK_AGGR_CONFLICT_INFO   "get_remote_link_aggr_conflict_info"
#define SZK_HA_CMD_GET_REMOTE_STORAGE_VALIDATION_INFO   "get_remote_storage_validation_info"
#define SZK_HA_CMD_INSTALL_REMOTE_SERVICE_CONFIG        "install_remote_service_config"
#define SZK_HA_CMD_UNINSTALL_REMOTE_SERVICE_CONFIG      "uninstall_remote_service_config"
#define SZK_HA_CMD_GET_SB_SYSTEM_INFO                   "list_system_info"
#define SZK_HA_CMD_GET_SB_ISCSI_INFO                    "list_iscsi_info"
#define SZK_HA_CMD_VERIFY_PASSIVE_MATCH "verify_passive_match"
#define SZK_HA_CMD_RES_PASSIVE_MATCH    "passive_match"
#define SZK_TASK_REDIRECT               "redirect"
#define SZK_VERIFY_HOST                 "host"
#define SZK_VERIFY_KEY                  "key"

#define SZK_PREPARE_HEARTBEAT_CHECK  "prepare_heartbeat_check_env"
#define SZK_RESET_HEARTBEAT_CHECK    "reset_heartbeat_check_env"

#define SZF_HA_PROMPT_FOR_PASSIVE_NODE  SZD_HA_VAR_LIB_FOLDER"/ha_was_passive_node"
#define SZF_HA_PROMPT_FOR_SPLIT_BRAIN   SZD_HA_VAR_LIB_FOLDER"/ha_has_split_brain"

// dump/construct tmp file
#define SZF_HA_DC_PARTITION    SZ_CONF_PREFIX"partition"SZ_CONF_SUFFIX
#define SZF_HA_DC_DRBD         SZ_CONF_PREFIX"drbd"SZ_CONF_SUFFIX
#define SZF_HA_DC_SPACE        SZ_CONF_PREFIX"space"SZ_CONF_SUFFIX
#define SZF_HA_DC_META         SZ_CONF_PREFIX"meta"SZ_CONF_SUFFIX
#define SZF_HA_DC_ADDDISK      SZ_CONF_PREFIX"adddisk"SZ_CONF_SUFFIX
#define SZF_HA_DC_UNDEPLOY     SZ_CONF_PREFIX"undeploy"SZ_CONF_SUFFIX // only save in active
#define SZF_HA_DC_FLASHCACHE   SZ_CONF_PREFIX"flashcache"SZ_CONF_SUFFIX

// remote dump tmp file
#define SZ_CONF_SUFFIX_REMOTE         SZ_CONF_SUFFIX ".remote"
#define SZF_HA_DC_REMOTE_PARTITION    SZ_CONF_PREFIX "partition" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_DRBD         SZ_CONF_PREFIX "drbd" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_SPACE        SZ_CONF_PREFIX "space" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_META         SZ_CONF_PREFIX "meta" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_ADDDISK      SZ_CONF_PREFIX "adddisk" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_RESIZE       SZ_CONF_PREFIX "resize" SZ_CONF_SUFFIX_REMOTE
#define SZF_HA_DC_REMOTE_FLASHCACHE   SZ_CONF_PREFIX "flashcache" SZ_CONF_SUFFIX_REMOTE

#define SZK_BINDING_PROGRESS            "BINDING"
#define SZK_UNBINDING_PROGRESS          "UNBINDING"
#define SZK_MODEL                       "model"
#define SZK_DSM_VERSION                 "dsm_version"
#define SZK_SMALL_PAT_VERSION           "small_pat_version"
#define SZK_LAN_PORT                    "lan_num"
#define SZK_IS_STANDALONE               "is_standalone"
#define SZK_IS_OVS_RUNNING              "is_ovs_running"
#define SZK_HAS_STATIC_IP               "has_static_ip"
#define SZK_MEM_SIZE                    "mem_size"
#define SZK_MEM_SIZE_UNMATCHED          "mem_size_unmatched"
#define SZK_HOSTNAME                    "hostname"

#define SZD_HA_PREFIX_SBIN              SZD_HA_PREFIX"/sbin/"
#define SZD_PREFIX_USR_BIN              "/usr/bin/"
#define SZD_HA_PREFIX_TEXTS             "/usr/syno/synoman/webman/modules/HAManager/texts/"
#define SZF_CIBADMIN                    SZD_PREFIX_USR_BIN"cibadmin"
#define SZF_CRM                         SZD_PREFIX_USR_BIN"crm"
#define SZF_CRM_ATTRIBUTE               SZD_PREFIX_USR_BIN"crm_attribute"
#define SZF_CRM_MON                     SZD_PREFIX_USR_BIN"crm_mon -1"
#define SZF_CRM_CONFIGURE               SZD_PREFIX_USR_BIN"crm configure "
#define SZF_CRM_RESOURCE                SZD_PREFIX_USR_BIN"crm_resource"
#define SZF_CRM_NODE                    SZD_PREFIX_USR_BIN"crm node "
#define SZF_CRM_NODE_FORCE              SZD_PREFIX_USR_BIN"crm -F node "
#define SZF_CRM_NODE_1                  SZD_PREFIX_USR_BIN"crm_node"
#define SZF_COROSYNC_OBJCTL             SZD_PREFIX_USR_BIN"corosync-objctl"

#define SZ_HA_MANAGER                   "HA Manager"
#define SZF_HA_STATUS                   "/tmp/.ha.status"
#define SZF_PCMK_PID                    SZD_HA_PREFIX"/var/run/pacemaker.pid"

#define SZ_TRUE                         "true"
#define SZ_FALSE                        "false"
#define SZ_HA_FIREWALL_SERV_NAME        "synoha"
#define SZ_NTP_FIREWALL_SERV_NAME       "ntp"
#define SZ_HA_NETWORKS                  "ha_networks"
#define SZ_STATUS_NORMAL                "status_normal"
#define SZ_PASSIVE_DISABLED_IF          "passive_disabled_if"

#define SZ_BIN_CP "/bin/cp"
#define SZ_BIN_CP_FORCE "-f"

// special define for extend RAID_STATUS, used internally
// MUST not overwrite original define in RAID_STATUS
#define HA_RAID_EXPANDABLE 0x8000

// MUST! Change synoha/etc/rc.subr at the same time!
#define MAX_HA_SERV_START_SEC 4800 // 20 + 60 (pgsql migration, HA #1892) min
#define SZ_MAX_HA_SERV_START_SEC "4800"
#define MAX_HA_SERV_START_FAST_SEC 1200 // 20 min
#define SZ_MAX_HA_SERV_START_FAST_SEC "1200"
#define MAX_HA_SERV_STOP_SEC  600 // 10 min
#define SZ_MAX_HA_SERV_STOP_SEC "600"
#define MAX_HA_REBOOT_SEC 300 // 5 min
#define MAX_HA_CRM_RESOURCE_SEC 300 // 5min // for passive crm resource start or stop (not all services)
#define HA_CRM_NODE_APPEAR_SEC 300 // 5min

#define MAX_HA_CURL_LENGTH     4096

#define SZF_HA_DISK_INFO          SZD_HA_VAR_LIB_FOLDER"/disk_info"
#define SZK_HA_DISK_INFO_SERIAL   "DiskSerial"
#define SZK_HA_DISK_INFO_ROOT     "Root"

#define SZ_HA_OVS_REG_NAME        "SHA"

#define SZ_HA_SC_BASE_NAME "synoha.sc"
#define SZF_HA_SERVICE_CONFIG SZD_HA_PREFIX "/etc.defaults/" SZ_HA_SC_BASE_NAME

#define SZK_HA_HOST0_ACTIVE_TIME    "host0_active_time"
#define SZK_HA_HOST1_ACTIVE_TIME    "host1_active_time"
#define SZK_HA_ACTIVE_TIME          "active_time"
#define SZK_HA_SB_TIME              "split_brain_time"
#define SZK_HA_SYS_INFO             "sys_info"
#define SZF_HA_TIME_RECORD          SZD_HA_VAR_LIB_FOLDER"ha.state.time.info"

#define BUF_SIZE_FOR_LIST 4096

#endif
