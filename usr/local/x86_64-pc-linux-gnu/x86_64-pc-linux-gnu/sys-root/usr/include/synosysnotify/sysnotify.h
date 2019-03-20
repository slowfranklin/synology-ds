// Copyright (c) 2000-2011 Synology Inc. All rights reserved.
#ifndef __SYNO_SYSNOTIFY_H__
#define __SYNO_SYSNOTIFY_H__

#include <synocore/synotype.h>
#include <synocore/hash.h>

__BEGIN_DECLS
#define SZ_SYNONCLIEN_SEND_CMD	"/usr/syno/bin/synonclient_send"
#define SZ_CMS_RELAYING_TAG "cms_relaying_tag"
#define SZK_NOTIFICATION_CMS_ENABLE "notification_cms_enable"
#define SZK_JOIN_DSM_CMS "join_dsm_cms"

#define SZD_CACHE_TEXTS "/var/cache/texts/"
#define SZF_SYSNOTIFY_FILTER_SETTING_PATH_OLD "/usr/syno/etc/notification/notification_filter.setting"
#define SZF_SYSNOTIFY_FILTER_SETTING_PATH "/usr/syno/etc/notification/notification_filter.settings"
#define SZF_SYSNOTIFY_CUSTOMIZED_MAIL_TEXT_DIR "/usr/syno/etc/notification/"
#define SZF_NOTIFICATION_UTILS "/usr/syno/bin/notification_utils"
#define SZF_NOTIFICAITON_SEND "/usr/syno/bin/notification_send"
#define SZF_NOTIFICATION_AGGREGATE "/usr/syno/bin/notification_aggregate"
#define SZF_NOTIFICATION_AGGREGATE_DIR "/usr/local/share/notification/"

#define SZF_NOTIFICATION_CATEGORY "notification_category"

#define SZ_SYSNOTIFY_TARGET_MAIL "mail"
#define SZ_SYSNOTIFY_TARGET_SMS "sms"
#define SZ_SYSNOTIFY_TARGET_MOBILE "mobile"
#define SZ_SYSNOTIFY_TARGET_MSN "msn"
#define SZ_SYSNOTIFY_TARGET_SKYPE "skype"
#define SZ_SYSNOTIFY_TARGET_CMS "cms"

#define SZK_SYSNOTIFY_DESKTOP_HTML_ENCODE "DESKTOP_NOTIFY_HTML_ENCODE"
#define SZK_SYSNOTIFY_DESKTOP_CLASSNAME "DESKTOP_NOTIFY_CLASSNAME"
#define SZK_SYSNOTIFY_DESKTOP_TITLE "DESKTOP_NOTIFY_TITLE"
#define SZV_SYSNOTIFY_DESKTOP_HTML_ENCODE "false"

#define SZD_CMS_TEXTS "/var/packages/CMS/target/ui/texts/"

#define SZ_MAILTAG_DEVICE_EJECTED_IMPROPERLY "DeviceEjectedImproperly"
#define SZK_SYSNOTIFY_TARGET_FILTER_SETTING  "FILTER_SETTING"

#ifndef NO_PROTO
#include <availability.h>
#include <synosysnotify/sysnotify_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_SYSNOTIFY_H__
