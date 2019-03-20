/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef SYNOHA_STRINGS_SDK_H
#define SYNOHA_STRINGS_SDK_H

#define SZD_HA_TMP_FOLDER               "/tmp/ha/"

#define SYNOHA_IOPRIO_WHO_PROCESS       1
#define SYNOHA_IOPRIO_CLASS_IDLE        3
#define SYNOHA_IOPRIO_CLASS_BE          2
#define SYNOHA_IOPRIO_CLASS_RT          1
#define SYNOHA_IOPRIO_CLASS_NONE        0
#define SYNOHA_IOPRIO_CLASS_SHIFT       13
#define SYNOHA_IOPRIO_PRIO_VALUE(class, data) (((class) << SYNOHA_IOPRIO_CLASS_SHIFT) | data)
#define SYNOHA_CPU_PRIORITY             -15
#define SYNOHA_IO_PRIORITY              SYNOHA_IOPRIO_PRIO_VALUE(SYNOHA_IOPRIO_CLASS_RT, 0)
#define SYNOHA_OOM_SCORE_PRIORITY       -900
#define SYNOHA_OOM_SCORE_PATH           "/proc/self/oom_score_adj"
#define SYNOHA_OOM_PRIORITY             -13
#define SYNOHA_OOM_PATH                 "/proc/self/oom_adj"

/** (mismatch_reason) location */
#define SYNOHA_MISMATCH_DISK_FORMAT "(%d) %s"

// defined in synoha/etc/rc.ha
// MUST modify that at the same time
// this file is created when rc.ha start, and kept to poweroff/reboot,
// this is for ha disable, after ha disable and before reboot,
// the state should be still in "ha running"
// #146, crash after disable ha
#define SZF_TMP_HA_RUNNING              "/tmp/.ha.running"
#define SZF_TMP_HA_NOT_RUNNING          "/tmp/.ha.not.running"
#define SZF_TMP_HA_SXX_ROLE_PREACTIVE   SZD_HA_TMP_FOLDER"/ha_Sxx_role_preactive"
#define SZF_TMP_HA_SXX_ROLE_PREPASSIVE  SZD_HA_TMP_FOLDER"/ha_Sxx_role_prepassive"
#define SZF_HA_INIT_SCRIPT              SZD_HA_PREFIX"/etc.defaults/rc.ha"

#define SZD_HA_PREFIX                   "/usr/syno/synoha"
#define SZD_HA_VAR_RUN_FOLDER           "/var/run/ha/"
#define SZD_HA_VAR_LIB_FOLDER           "/var/lib/ha/"
#define SZD_HA_VAR_LIB_SYNC_FOLDER      "/var/lib/ha/sync/"
#define SZD_HA_SAFEMODE_FOLDER          SZD_HA_VAR_LIB_FOLDER "safemode/"
#define SZ_SYNOHA_SBIN_SYNOHA           SZD_HA_PREFIX"/sbin/synoha"
#define SZ_SYNOHA_UNBIND_LOCAL          "--unbind-local"
#define SZ_SYNOHA_NOREBOOT              "noreboot"
#define SZ_SYNOHA_USER_RESET_ACTIVE     "user reset active"
#define SZ_SYNOHA_USER_RESET_PASSIVE    "user reset passive"
#define SZ_HA_DSMUPDATE                 "dsmupdate"
#define SZ_HA_SMALLUPDATE               "smallupdate"
#define SZ_HA_UPGRADE_PATH              "upgrade_path"
#define SZF_HA_REMOTE_UPGRADE           "/var/lib/ha/ha_remote_upgrade"
#define SZK_HA_REMOTE_PROGRESS          "remote_progress"
#define SZK_HA_UPDATE_TYPE              "update_type"
#define SZF_HA_ROLE_ACTIVE              "/tmp/ha_role_active"
#define SZF_HA_SAFEMODE_INFO            SZD_HA_VAR_LIB_FOLDER"ha.safemode.info"

#define SZF_ORIG_IP_LOCAL               SZD_HA_VAR_LIB_FOLDER"/ip.local"
#define SZF_ORIG_IP_REMOTE              SZD_HA_VAR_LIB_FOLDER"/ip.remote"

#endif
