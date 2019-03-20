/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef SYNOHA_STRINGS_H
#define SYNOHA_STRINGS_H

#ifndef SYNOHA_STRINGS_BIN
#include <synohacore/strings_sdk.h>
#endif

#define SZ_AIS_REBOOT                   "REBOOT  "
#define SZ_AIS_POWEROFF                 "POWEROFF"
#define SZ_AIS_SYNOLOG_REQ              "LOGREQ  "
#define SZ_AIS_SYNOLOG_RESP             "LOGRESP "
#define SZ_AIS_INFOSET_REQ              "INFOREQ "
#define SZ_AIS_PASSIVE_MAC              "PAS_MAC "
#define SZ_AIS_RUN_SSHD                 "RUN_SSHD"
#define SZ_AIS_STOP_SSHD                "STP_SSHD"
#define SZ_AIS_RUN_SAFEMODE             "RUN_SAFE"
#define SZ_AIS_CHK_REMOTE_IN_SAFEMODE   "CHK_SAFE"
#define SZ_AIS_CHK_REMOTE_IN_SAFEMODE_REPLY  "RLY_SAFE"
#define SZ_AIS_DO_SCRUBBING             "SCRUBDO "
#define SZ_AIS_CANCEL_SCRUBBING         "SCRUBCNL"
#define SZ_AIS_SET_GATEWAY_REQ          "SETGWREQ"
#define SZ_AIS_ARP_IGNORE_REQ           "ARPREQ  "
#define SZ_AIS_CHANGE_DSM_VERSION       "CHDSMVER"
#define SZ_AIS_NOTIFY_REMOTE            "NOTIFICA"
#define SZ_AIS_SB_SET_ROLE              "SBSROLE "
#define SZ_AIS_TOUCH_SHUTDOWN_FLAG      "TSDFLAG "
#define SZ_AIS_TOUCH_WAIT_FSCK_FLAG     "TWFFLAG "
#define SZ_AIS_SYNOLOG_REMOTE           "LOGSET1 "
#define SZ_AIS_SYNC_MD0_MD1             "SYNCMD01"
#define SZ_AIS_PASSIVE_ENTER_UPS_SAFEMODE "PASINUPS"
#define SZ_AIS_SSD_REMOTE_TRIM          "SSD_TRIM"
#define SZ_AIS_REMOTE_SMART_TEST        "SMARTEST"

#define SZ_ROLE_ACTIVE                  "Active"
#define SZ_ROLE_PASSIVE                 "Passive"
#define SZ_ROLE_PREPARE                 "Prepare"
#define SZ_ROLE_PREACTIVE               "Preactive"
#define SZ_ROLE_UNKNOWN                 "Unknown"

#define SZ_ERROR_CONF_NOT_EXISTING      "necessary conf files not existing"
#define SZ_ERROR_SPLIT_BRAIN            "Split Brain"
#define SZ_ERROR_SWITCH_SERVICE_FAIL    "switch services failed"
#define SZ_ERROR_REMOVED_FROM_HA        "removed from High Availability cluster by active server"
#define SZ_ERROR_SPACE_NOT_SYNCED       "the storage space is not matched with the other server"
#define SZ_ERROR_BIND_FAILED            "High Availability cluster binding failed"
#define SZ_ERROR_UPGRADE_FAILED         "DSM upgrade failed"
#define SZ_ERROR_UPGRADE_RESTART_TIMEOUT "High Availability restart timeout during DSM upgrade"
#define SZ_ERROR_NO_ACTIVE              "no active in High Availability cluster"
#define SZ_HA_DEACTIVATED               "High Availability cluster is deactivated"

#define SZF_HA_SERV_MON                 SZD_HA_PREFIX"/etc/serv.mon.conf"
#define SZF_HA_SERV_MON_DEFAULT         SZD_HA_PREFIX"/etc.defaults/serv.mon.conf"
#define SZF_HA_SERV_MUST                SZD_HA_PREFIX"/etc.defaults/serv.must.conf"
#define SZF_HA_SERV_FAIL                SZD_HA_TMP_FOLDER"/ha.serv_failed."

#define SZ_HA_NODE_STATUS_STANDALONE       "standalone"
#define SZ_HA_NODE_STATUS_ONLINE           "online"
#define SZ_HA_NODE_STATUS_WARNING_ONLINE   "warning_online"
#define SZ_HA_NODE_STATUS_WARNING_OFFLINE  "warning_offline"
#define SZ_HA_NODE_STATUS_OFFLINE          "offline"
#define SZ_HA_NODE_STATUS_ERROR            "error"
#define SZ_HA_NODE_STATUS_NONE             "none"
#define SZ_HA_NODE_STATUS_UNKNOWN          "unknown"

#define SZF_INFO_IF_LOCAL               SZD_HA_TMP_FOLDER"info_if.local"
#define SZF_INFO_IF_LOCAL_TMP           SZD_HA_TMP_FOLDER"info_if.local.tmp"
#define SZF_INFO_IF_REMOTE              SZD_HA_TMP_FOLDER"info_if.remote"

#define SZF_INFO_HD_LOCAL               SZD_HA_TMP_FOLDER"info_hd.local"
#define SZF_INFO_HD_LOCAL_TMP           SZD_HA_TMP_FOLDER"info_hd.local.tmp"
#define SZF_INFO_HD_REMOTE              SZD_HA_TMP_FOLDER"info_hd.remote"

#define SZF_INFO_MD_LOCAL               SZD_HA_TMP_FOLDER"info_md.local"
#define SZF_INFO_MD_LOCAL_TMP           SZD_HA_TMP_FOLDER"info_md.local.tmp"
#define SZF_INFO_MD_REMOTE              SZD_HA_TMP_FOLDER"info_md.remote"

#define SZF_INFO_NODE_LOCAL             SZD_HA_TMP_FOLDER"info_node.local"
#define SZF_INFO_NODE_LOCAL_TMP         SZD_HA_TMP_FOLDER"info_node.local.tmp"
#define SZF_INFO_NODE_REMOTE            SZD_HA_TMP_FOLDER"info_node.remote"

// if role is passive before shutdown then wait for remote online when bootup
#define SZF_PREVIOUS_ROLE_ACTIVE        SZD_HA_VAR_LIB_FOLDER"previous_role_active"
#define SZF_PREVIOUS_ROLE_PASSIVE       SZD_HA_VAR_LIB_FOLDER"previous_role_passive"

#define SZF_HA_UPGRADE_INFO             SZD_HA_VAR_LIB_FOLDER "ha.upg"
#define SZF_HA_UPGRADE_PASSIVE_STANDBY  SZD_HA_VAR_LIB_FOLDER "ha.upg.passive.standby"

#define SZF_DRBD_DISCARD_MYDATA         "/tmp/.ha.drbd.discard.mydata"
#define SZF_DRBD_FORCE_UNLOAD           "/proc/drbd_force_unload"
#define SZF_DRBD_BUSY_RESOUCE           "/tmp/ha/.drbd.busy.resource"

// this file is touch by drbd ocf if drbd demote error
// and rc.ha will check this file
#define SZF_CRM_DRBD_DEMOTE_ERROR       SZD_HA_VAR_LIB_FOLDER"ha.drbd.demote.error"

// MUST modify pacemaker-1.x/include/syno.h at the same time!
#define SZF_CRM_HOSTNAME_ORIGINAL       SZD_HA_VAR_LIB_FOLDER"ha.hostname.original"
#define SZF_CRM_HOSTNAME_ORIGINAL_TMP   "/tmp/.ha.hostname.original"

#define SZF_HA_SB_REMOTE_IN_SAFEMODE        SZD_HA_TMP_FOLDER".ha.sb.remote.in.safemode"
#define SZF_HA_SB_REMOTE_NOT_IN_SAFEMODE    SZD_HA_TMP_FOLDER".ha.sb.remote.not.in.safemode"

#define SZ_HA_ALIAS_NAME                "HA"

#define SZK_HA_SERV_MON_GROUP_BUILTIN   "builtin"
#define SZK_HA_SERV_MON_GROUP_PACKAGE   "package"

#define SZ_HA_HOSTNAME                  "HostName"
#define SZ_HA_LOGTYPE                   "LogType"
#define SZ_HA_LOGCLASS                  "LogClass"
#define SZ_HA_USERID                    "User"
#define SZ_HA_EVENT                     "Event"
#define SZ_HA_DATETIME                  "Datetime"
#define SZ_HA_RESERVEFIELD1             "ReserveField1"
#define SZ_HA_RESERVEFIELD2             "ReserveField2"
#define SZ_HA_RESERVEFIELD3             "ReserveField3"
#define SZF_HA_TMP_SYNOLOG_REQ          SZD_HA_TMP_FOLDER"ha_synolog_req"
#define SZF_HA_TMP_SYNOLOG_RESP         SZD_HA_TMP_FOLDER"ha_synolog_resp"
#define SZ_SEND_SYNOLOG_RESULT_SUCCESS  "SUCCESS "
#define SZ_SEND_SYNOLOG_RESULT_FAIL     "FAIL    "

#define SZF_HA_TMP_FAKE_DRBD_PRIMARY    SZD_HA_TMP_FOLDER"ha_fake_drbd_primary"
#define SZF_HA_TMP_FAKE_DRBD_SECONDARY  SZD_HA_TMP_FOLDER"ha_fake_drbd_secondary"

#define SZF_HA_STATUS_RECORD            "/tmp/ha/.ha.status.record"
#define SZF_HA_SERVICE_SKIP_FOR_BINDING "/tmp/.ha.service.skip.for.binding"
#define SZF_HA_TMP_MAC_ADDR             "/tmp/.ha_mac_addr"
#define SZF_HA_RC_HA_START_DONE         SZD_HA_TMP_FOLDER"rc_ha_start_done"
#define SZF_HA_TMP_CURL_BIND_REQUEST    "/tmp/.curl_bind_request"
#define SZF_HA_TMP_PASSIVE_IS_BINDING   "/tmp/.ha_passive_is_binding"
#define SZF_HA_IS_EXPANDING_SPACE       "/tmp/ha/ha_is_expanding_space"
#define SZ_INFORMATION                  "Information"
#define SZ_EXPAND_SPACE                 "expandSpace"

#define SZF_HA_UNBIND_PROCESSING        SZD_HA_VAR_LIB_FOLDER"ha.unbind.processing"

#define SZ_UNBIND_WITH_REBOOT           "reboot"

#define SZF_REMOTE_SHUTDOWN_FLAG        SZD_HA_VAR_LIB_FOLDER".ha_remote_shutdown"

#define SZF_QUERY_SYNOTOKEN             "/tmp/.ha.SynoToken"

/* This flag set for stop pacemaker promote, check in project corosync */
#define SZF_HA_REMOTE_BUSY              SZD_HA_TMP_FOLDER"ha_remote_busy"

#define SZF_HA_NETWORK_FAILED           SZD_HA_TMP_FOLDER"ha_network_failed"

#define SZF_HA_PING_FAILED              SZD_HA_TMP_FOLDER"ha_ping_failed"

#define SZF_HA_STANDBY_FAILED           SZD_HA_VAR_LIB_FOLDER"ha_standby_failed"

#define SZF_WAIT_FSCK_FLAG              SZD_HA_VAR_LIB_FOLDER"ha_fsck_processing"

#define SZF_ROLE_ACTIVE_WHEN_UNBINDING_HA "/tmp/.ha.role.active.when.unbinding.ha"

#define SZF_UPGRADE_FROM_VERSION_AFTER_6_0_BETA_2 SZD_HA_VAR_LIB_FOLDER"ha_upgrade_from_new_version"

#define SZF_HAS_BUMPED_UP_ADMIN_EPOCH SZD_HA_TMP_FOLDER"/ha_has_bumped_admin_epoch"

#define SZF_PING_SERVER                 SZD_HA_VAR_LIB_FOLDER"ha.ping.server"

#endif
