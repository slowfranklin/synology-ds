// Copyright (c) 2000-2011 Synology Inc. All rights reserved.
#ifndef __SYNO_PLUGIN_H__
#define __SYNO_PLUGIN_H__

#include <unistd.h>
#include <synocore/synotype.h>
#include <synocore/list.h>
#include <synocore/hash.h>

__BEGIN_DECLS;

/**
 * @addtogroup PLUGIN
 *
 * @brief The structure and operation of SDK Plugin.
 *
 * @{
 */

typedef enum _tag_sdk_plugin_action_ {
	SDK_PLUGIN_MODVER = 0,
	SDK_PLUGIN_NAME,
	SDK_PLUGIN_PKGVER,
	SDK_PLUGIN_VENDOR,
	SDK_PLUGIN_PRE,
	SDK_PLUGIN_POST,
	SDK_PLUGIN_NUM
} SDK_PLUGIN_ACTION;

struct SLIBPLUGIN_IMP;
typedef struct SLIBPLUGIN_IMP *PSLIBPLUGIN;
typedef PSLIBPLUGIN *PPSLIBPLUGIN;

#define MKVER (major , minor) ((major) << 16 | (minor))
#define GETMAJOR (ver) (ver | 0xffff0000)
#define GETMINOR (ver) (ver | 0x0000ffff)

#define SZD_PLUGIN_DSM   "/usr/libexec"
#define SZD_PLUGIN_PKG   "/usr/local/libexec"

#define SZ_SYNO_SHARE_MODULE             "share"
#define SZ_SYNO_USER_MODULE              "user"
#define SZ_SYNO_GROUP_MODULE             "group"
#define SZ_SYNO_SERVICE_MODULE           "service"
#define SZ_SYNO_NET_MODULE               "net"
#define SZ_SYNO_MYDS_MODULE              "myds"
#define SZ_SYNO_TASK_SCHEDULER_MODULE    "task_scheduler"
#define SZ_SYNO_CMS_CLIENT_MODULE        "cms_client"
#define SZ_SYNO_DIRECTORY_SERVICE_MODULE "dirsvs"
#define SZ_SYNO_DSM_MODULE               "dsm"
#define SZ_SYNO_VOLUME_MODULE            "volume"
#define SZ_SYNO_CERTIFICATE_MODULE       "certificate"
#define SZ_SYNO_LUN_MODULE               "lun"
#define SZ_SYNO_APPPRIV_MODULE           "app_priv"
#define SZ_SYNO_TIMEZONE_MODULE          "timezone"
#define SZ_SYNO_LVM_VG_MODULE            "lvm_vg"
#define SZ_SYNO_POWEROFF_MODULE          "poweroff"
#define SZ_SYNO_PORT_CONFIG_MODULE       "port_config"
#define SZ_SYNO_USBCOPY_MODULE           "usbcopy"

#define MAX_VER_LEN 32
#define GENERAL_LEN 32

#define SZ_SYNO_PLUGIN_PATH "/sbin:/bin:/usr/sbin:/usr/bin:/usr/syno/sbin:/usr/syno/bin:/usr/local/sbin:/usr/local/bin"

/**
 * directory_service
 */
#define SZD_SYNO_DIRECTORY_SERVICE_JOIN_PLUGIN "dirsvs_join"
#define SZD_SYNO_DIRECTORY_SERVICE_LEAVE_PLUGIN "dirsvs_leave"
#define SZD_SYNO_DIRECTORY_SERVICE_DB_REFRESH_PLUGIN "dirsvs_db_refresh"

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/plugin_p.h>
#endif

__END_DECLS;
#endif // __SYNO_PLUGIN_H__
