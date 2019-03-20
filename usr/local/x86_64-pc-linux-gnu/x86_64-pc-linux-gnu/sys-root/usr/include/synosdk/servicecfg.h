// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICECFG_H__
#define __SYNO_SERVICECFG_H__

#include <sys/cdefs.h>

__BEGIN_DECLS;

/**
 * @addtogroup SERVICECFG
 *
 * @brief The basic structures and operations of Service Framework. More features in libsynoservice.
 *
 * @{
 */

#include <synocore/list.h>

#define SZ_SERVICE_START "start"
#define SZ_SERVICE_STOP "stop"
#define SZ_SERVICE_RELOAD "reload"
#define SZ_SERVICE_RESTART "restart"
#define SZ_SERVICE_RESTART_COUNT "restart_count"
#define SZD_SYNOSERVICE_RUNTIME	"/run/synoservice/service"
#define SZD_SYNOSERVICE_RESTART		"/run/synoservice/restart"
#define SZD_SYNOSERVICED "/usr/syno/etc/synoservice.d"
#define SZD_SYNOSERVICE_OVERRIDE "/usr/syno/etc/synoservice.override"
#define SZD_DEF_SYNOSERVICED "/usr/syno/etc.defaults/synoservice.d"
#define SZD_SYNOSERVICED_ERRCFG SZD_SYNOSERVICED"/error"
#define SZD_SYSTEMV "/usr/syno/etc/rc.sysv"
#define SZ_SLIBSERVICCFG_FILE_POSTFIX ".cfg"
#define SZ_SLIBSERVICCFG_UPSTART "upstart"
#define SZ_SLIBSERVICCFG_SYSTEMV "sysv"
#define SZ_SLIBSERVICCFG_NAME "service_name"
#define SZ_SLIBSERVICCFG_FILE_PROTOCOL "is_file_protocol"
#define SZ_SLIBSERVICCFG_SET_STOP_ON_BOOTUP "set_stop_on_bootup"
#define SZ_SLIBSERVICCFG_SET_START_ON_BOOTUP "set_start_on_bootup"
#define SZ_SLIBSERVICCFG_SUPPORT_KEY "support_key"
#define SZ_SLIBSERVICCFG_SKIP_BOOTUP_CHECK "skip_bootup_check"
#define SZ_SLIBSERVICCFG_APP "is_application"
#define SZ_SLIBSERVICCFG_PKG "is_package"
#define SZ_SLIBSERVICCFG_USR_CTRL "user_controllable"
#define SZ_SLIBSERVICCFG_SUPP_ONE_CLICK_ENABLE "support_one_click_enable"
#define SZ_SLIBSERVICCFG_RUNKEY "auto_start"
#define SZ_SLIBSERVICCFG_INITJOBMAP "init_job_map"
#define SZ_SLIBSERVICCFG_REQUIRED_SERVICE "required_synoservice"
#define SZ_SLIBSERVICCFG_CONFLICT_SERVICE "conflict_synoservice"
#define SZ_SLIBSERVICCFG_REQUIRED_RESOURCE "required_resource"
#define SZ_SLIBSERVICCFG_REQUIRED_PORTNAME "firewall_section_map"
#define SZ_SLIBSERVICCFG_REQUEST_SERVICE "request_service"
#define SZ_SLIBSERVICCFG_SHARE "share"
#define SZ_SLIBSERVICCFG_CUSTOM "custom"
#define SZ_SLIBSERVICCFG_VOLUME "volume"
#define SZ_SLIBSERVICCFG_STATUS_HOOK "status_hook"
#define SZ_SLIBSERVICCFG_START_HOOK "start_hook"
#define SZ_SLIBSERVICCFG_STOP_HOOK "stop_hook"
#define SZ_SLIBSERVICCFG_RESTART_HOOK "restart_hook"
#define SZ_SLIBSERVICCFG_RELOAD_HOOK "reload_hook"
#define SZ_SLIBSERVICCFG_PAUSE "pause"
#define SZV_PAUSE "pause"
#define SZ_SLIBSERVICCFG_DISPLAY_NAME "display_name"
#define SZ_SLIBSERVICCFG_NEED_DISPLAY_NAME "need_display_name"
#define SZ_SERVICE_ACTION_EVENT "syno.service.action"
#define SZK_SKIP_ACTION_SERVICE "skip-action-service"

#define SZ_SYSTEM_SERVICE "system"
#define SYNOSERVICE_DISPLAYNAME_MAX 512

typedef enum _tag_servicecfg_action_ {
	SLIB_SERVICECFG_START,
	SLIB_SERVICECFG_STOP,
	SLIB_SERVICECFG_RESTART,
	SLIB_SERVICECFG_RELOAD,
	SLIB_SERVICECFG_PAUSE,
} SLIB_SERVICECFG_ACTION;

typedef enum _tag_servicecfg_runkey_ {
	RUNKEY_NULL,
	RUNKEY_START,
	RUNKEY_STOP,
	RUNKEY_PAUSE,
} SLIB_SERVICECFG_RUNKEY;

typedef enum _tag_servicecfg_config_type_ {
	/** original config file */
	CONFIG_STATIC,
	/** store info which change after install */
	CONFIG_OVERRIDE,
	/** store info which will be remove after reboot */
	CONFIG_RUNTIME,
} SLIB_SERVICECFG_CONFIG_TYPE;

typedef enum _tag_servicecfg_state_ {
	SLIB_SERVICECFG_NONE = 0x00,
	SLIB_SERVICECFG_ENABLE = 0x01,
	SLIB_SERVICECFG_DISABLE = 0x02,
	SLIB_SERVICECFG_ENABLE_ERR = 0x04,
	SLIB_SERVICECFG_ENABLE_PAUSE = 0x08,
} SLIB_SERVICECFG_STATE;

#define SLIB_SERVICECFG_ALL (SLIB_SERVICECFG_ENABLE | SLIB_SERVICECFG_DISABLE | SLIB_SERVICECFG_ENABLE_ERR | SLIB_SERVICECFG_ENABLE_PAUSE)

typedef enum _tag_servicecfg_category_ {
	SLIB_SERVICECFG_NULL = 0x00,
	SLIB_SERVICECFG_VOLUME = 0x01,
	SLIB_SERVICECFG_SHARE = 0x02,
	SLIB_SERVICECFG_UPSTART = 0x04,
	SLIB_SERVICECFG_SYSTEMV = 0x08,
	SLIB_SERVICECFG_DEPEND_SERVICE = 0x10,
	SLIB_SERVICECFG_CONFLICT_SERVICE = 0x20,
	SLIB_SERVICECFG_PORTNAME = 0x40,
	SLIB_SERVICECFG_CUSTOM = 0x80,
	SLIB_SERVICECFG_REQUEST_SERVICE = 0x100,
} SLIB_SERVICECFG_CATEGORY;

#define SLIB_SERVICECFG_ALL_RESOURCE (SLIB_SERVICECFG_VOLUME | SLIB_SERVICECFG_SHARE | SLIB_SERVICECFG_CUSTOM)

typedef enum _tag_service_type {
	SLIB_SERVICE_TYPE_NULL = 0x00,
//	SLIB_SERVICE_TYPE_IP_SENS = 0x01,  // removed, not in used
//	SLIB_SERVICE_TYPE_MTU_SENS = 0x02, // removed, not in used
//	SLIB_SERVICE_TYPE_HOSTNAME_SENS = 0x04,// removed, not in used
	SLIB_SERVICE_TYPE_FILE_PROTOCOL = 0x08,
	/** legacy all */
	SLIB_SERVICE_TYPE_APP = 0x010,
	SLIB_SERVICE_TYPE_PACKAGE = 0x20,
//	SLIB_SERVICE_TYPE_LINK_SENS = 0x40, // removed, not in used
} SLIB_SERVICE_TYPE;

typedef enum _tag_service_action_ {
	SLIB_ACTION_START,
	SLIB_ACTION_STOP,
} SLIB_SERVICE_ACTION;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/servicecfg_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif
