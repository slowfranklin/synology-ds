// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICE_H__
#define __SYNO_SERVICE_H__

#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synosdk/share.h>
#include <synosdk/volume.h>
#include <synosdk/plugin.h>
#include <synocore/conf.h>
#include <sys/stat.h>

__BEGIN_DECLS;

/**
 * @addtogroup SERVICE
 *
 * @brief Some functions of User Home and some common macros of Service.
 *
 * @{
 */

#define	FIX_HTTP_PORT	80

#define SERV_INDEX_START				0

#define SZD_DATABASE                   "database"
#define SZD_MYSQL_NAME                 "mysql"
#define SZD_PGSQL_NAME                 "pgsql"
#define SZD_PRINTER_NAME               "printer"
#define SZD_SPOOL_NAME                 "spool"

#define SZD_SHARE_BIN		   	   	   "@sharebin"

/**
 * Service configure port
 */
#define SERVICE_SECTION_NAME_MAX       256
#define UISTRING_SECTION_MAX       64
#define UISTRING_KEY_MAX       128
#define SERVICE_DEF_STR_MAX       128
#define PROTOCOL_STR_MAX       64
#define PORT_STR_MAX       64

/**
 * UPnP portmapping Service
 */
#define UPNPD_PIDFILE			"/var/run/upnpd.pid"
#define DDNSD_PIDFILE			"/var/run/ddnsd.pid"
#define HEARTBEATD_PIDFILE		"/var/run/heartbeatd.pid"
#define SNMPD_PIDFILE			"/var/run/snmpd.pid"
#define SZK_DDNS_UPDATE			"ddns_update"
#define SZF_RUN_DDNS            "/run/ddns"
#define SZF_EXTERNALIP_RESULT	SZF_RUN_DDNS"/externalIP.result"
#define SZK_DDNS_EXT_IP			"externalIP"
#define PPPOE_USER_PATH	"/etc/ppp/pppoe.conf"
#define PPPOE_USER_PASSWORD_PATH		"/etc/ppp/pap-secrets"
#define PPPOE_START_PATH	PPPOE_START_PATH_NO_REDIRECT" > /dev/null 2>&1"
#define PPPOE_STOP_PATH		PPPOE_STOP_PATH_NO_REDIRECT" > /dev/null 2>&1"
#define PPPOE_START_PATH_NO_REDIRECT	"/usr/sbin/pppoe-start"
#define PPPOE_STOP_PATH_NO_REDIRECT		"/usr/sbin/pppoe-stop"
#define PPPOE_STATUS_PATH "/usr/sbin/pppoe-status"

#define SZF_SERVICE_VOLUME_MAP	"/usr/syno/etc/service_volume.map"
#define SZF_PACKAGE_VOLUME_MAP	"/usr/syno/etc/package_volume.map"
#define SZK_USERHOME_SERVICE_NAME	"userhome"
#define SZK_WEB_SERVICE_NAME	"web"
#define SZK_DOWNLOAD_SERVICE_NAME	"download"
#define SZK_WEB_LOCAL_SERVICE_NAME	"weblocal"
#define SZK_NET_BACKUP_SERVICE_NAME "netbkp"
#define SZ_BONJOUR_SERVICE_NAME "bonjour"

#define SZ_SERVICE_CUPSD "cupsd"
#define SZ_SERVICE_CUPS_LPD "cups-lpd"
#define SZ_SERVICE_GCPD "gcpd"

/**
 * router
 */
#define SZF_SYNOROUTERTOOL     "/usr/syno/sbin/synoroutertool"
#define SZD_PF_ROOT		"/etc/portforward"
#define SZF_PF_RULE		SZD_PF_ROOT "/rule.conf"

/**
 * printer
 */
#define SZF_SYNOPRINT "/usr/syno/bin/synoprint"

#define SZF_TUNNEL_SCRIPTS_LNX  "/etc/gogoc/rc.tun"
#define TUNNEL_PASSWD_MAX_LEN	32
#define SZ_TUNNEL_DEVICE "tun"
#define TUNNEL_PASSWD_ENC_LEN 64
#define SZF_TUNNEL_PASSWD "/etc/gogoc/.tunnel_passwd"
#define SZF_TUNNEL_BIN "/usr/bin/gogoc"
#define SZF_GOGOC_CONF "/etc/gogoc/gogoc.conf"

#define SZD_USER_HOME "/var/services/homes"
#define SZD_REMOTE_USER_HOME "/var/services/dirhomes"
#define SZD_USER_HOME_FAKE "/volume1/@fake_home_link"
#define SZ_DOMAIN_HOME_PREFIX	"@DH-"
#define SZ_LDAP_HOME_PREFIX		"@LH-"
#define SZD_THIRD_PARTY_SCRIPT  "/usr/local/etc/rc.d"
#define SZD_THIRD_PARTY_REGISTRY_DIR "/var/packages"

#define SZF_CUPSD_SCRIPT				SZD_SYSTEMV "/cupsd.sh"

#define SZ_CROND_SERVICE_NAME                           	"crond"
#define SZF_PID_PATH					"/var/run/"

/**
 * snmpd.conf
 */
#define SZF_SNMPDCONF			"/etc/snmp/snmpd.conf"

#define	PHOTO_DEF_NOPUBLIC		0
#define	PHOTO_DEF_PUBLIC		1
#define PPPoE_DISABLE			0
#define PPPoE_ENABLE			1

#define RCPOWER_DISABLE			0
#define RCPOWER_ENABLE			1

#define APPLE_OK				0x0001
#define UPNP_OK					0x0002
//#define NOVELL_OK		0x0002
#define WIN_OK					0x0004
//#define UNIX_OK			0x0008
#define FTP_OK					0x0008
#define MYSQL_OK				0x0010
#define PGSQL_OK				0x0020
#define DOWNLOAD_OK				0x0040
#define NETBKP_OK				0x0080
#define DMS_OK					0x0100
#define WEB_OK					0x0200
#define PHOTO_OK				0x0400
#define PRINTER_OK				0x0800
#define ITUNES_OK				0x1000
#define INDEX_OK				0x2000
#define CRON_OK					0x4000
#define MKTHUMB_OK				0x8000
#define SURVEILLANCE_OK	0x00010000
#define MKTFLV_OK				0x00020000
#define NFS_OK			0x00040000
#define mDNS_OK			0x00080000
#define SYNOREALYD_OK		0x00100000
#define SYNOLOG_OK		0x00200000
#define ISCSI_OK		0x00400000
#define PPPOE_RELAY_OK	0x00800000
#define NSLCD_OK		0x01000000
#define IPTABLE_OK		0x04000000
#define SLAPD_OK		0x08000000
#define SFTPD_OK		0x10000000

#define HUP_FTP					0x0004
#define HUP_NOVELL				0x0008
#define HUP_APPLE				0x0010

#define DAEMON_NONE_ACTION				0x0000
#define DAEMON_DB_ACTION				0x0020
#define DAEMON_PPPOE_RELAY				0x00200000
#define DAEMON_NSLCD_ACTION				0x00800000

#define DAEMON_IPTABLE_ACTION			0x40000000
/**
 * exclude DAEMON_SYS_WEB_ACTION & DAEMON_NSLCD_ACTION (LDAP client) & DAEMON_SLAPD_ACTION
 */
#define DAEMON_ALL						0x7c7fd7fd

#define DAEMON_IP_SENSITIVE	(DAEMON_PPPOE_RELAY)
/**
 * If hostname change, the services must be restart
 */
#define DAEMON_HOSTNAME_SENSITIVE	(DAEMON_PPPOE_RELAY )

/**
 * new service framework
 */
#define SZ_MDNS_SERVICE_NAME "avahi"
#define SZ_WEB_STATION_SERVICE	"webstation"
#define SZ_HTTP_SYS_SERVICE	"httpd-sys"
#define SZ_NGINX_SERVICE	"nginx"
#define SZ_APPARMOR_SERVICE	"apparmor"
#define SZ_SSDP_SERVICE "ssdp"

#define GET_BY_USER 0
#define GET_BY_SHARE 1

/**
 * User home check
 */
#define SZK_RESULT_USER_NAME	"user name"
#define SZK_RESULT_HOME_PATH	"home path"

#define SZ_PKG_CMD	"/usr/syno/bin/synopkg"

/**
 * HTTPd PID files
 */
#define HTTPD_SYS_PIDFILE	"/run/httpd/httpd-sys.pid"
#define HTTPD_WEBDAV_PIDFILE	"/run/httpd/httpd-webdav.pid"

/**
 * Service Framework
 */
#define SZ_WEBDAV_SERVICE_NAME "webdav-httpd-pure"
#define SZ_SECUREWEBDAV_SERVICE_NAME "webdav-httpd-ssl"
#define SZ_PGSQL_SERVICE_NAME	"pgsql"
#define SZ_RSYNC_SERVICE_NAME	"rsyncd"
#define SZ_NETBACKUP_SERVICE_NAME	"rsyncd"
#define SZF_PGSQL_SERVICE_SCRIPT	SZD_SYSTEMV"/S20pgsql.sh"
#define SZ_DBUS_SERVICE_NAME	"dbus"
#define SZ_SYNOTUNNEL_SERVICE_NAME "synotunnel"
#define SZ_SYNORELAYD_SERVICE_NAME "synorelayd"
#define SZ_SUPPORT_REMOTE_ACCESS_SERVICE_NAME "support-remote-access"
#define SZ_HOTPLUGD_SERVICE_NAME "hotplugd"
#define SZ_APPARMOR_SERVICE_NAME	"apparmor"
#define SZ_DDNS_SERVICE_NAME        "ddns"
#define SZ_HEARTBEAT_SERVICE_NAME   "heartbeat"
#define SZ_SNMP_SERVICE_NAME        "snmp"
#define SZ_UPS_USB_SERVICE_NAME     "ups-usb"
#define SZ_UPS_NET_SERVICE_NAME     "ups-net"
#define SZ_TELNET_SERVICE_NAME		"telnetd"
#define SZ_NSLCD_SERVICE_NAME		"nslcd"
#define SZF_APPARMOR_SERVICE_SCRIPT	SZD_SYSTEMV"/apparmor.sh"

/**
 * Gernel pause reason
 */
#define SZ_REASON_NO_VOLUME "no-volume"

/**
 * Home on remote(gluster) volume
 */
#define SZK_SYNO_REMOTE_HOME	"remote_userhome"

typedef enum {
	SERVICE_DSM,
	SERVICE_PKG
} SERVICE_TYPE;

enum {
	SERVICE_NOT_ONVOLUME = 0, //must be 0
	SERVICE_ONVOLUME
};

/**
 * SERV_SHARE_ID:
 * This id is represented as the share service used.
 */
typedef enum {
	SERV_SHARE_WEB = 1,
	SERV_SHARE_PHOTO,
	SERV_SHARE_NETBKP,
	SERV_SHARE_DOWNLOAD,
	SERV_SHARE_VIDEO,
	SERV_SHARE_MUSIC,
	SERV_SHARE_MYSQL,
	SERV_SHARE_PRINTER,
	SERV_SHARE_SURVEILLANCE,
	SERV_SHARE_USERHOME,
	SERV_SHARE_PGSQL,
	SERV_SHARE_END,
} SERV_SHARE_ID;

/**
 * DAEMON_ACTION:
 * This ACTION is used in SLIBNetService().
 * It is treated as a script action parameters.
 */
typedef enum _tag_SYNO_ACTION_ {
	ACTION_NONE,
	ACTION_STOP,
	ACTION_START,
	ACTION_RESTART,
	ACTION_HUP,
} DAEMON_ACTION;

typedef enum {
	SERV_TYPE_NONE = -1,
	SERV_TYPE_APP,
	SERV_TYPE_SERVICE,
	SERV_TYPE_RUNKEY_ONLY,
	SERV_TYPE_DAEMON
} SERV_TYPE;

/**
 * SERVICE_ACTION:
 * This is used in the function of service to specify action.
 */
typedef enum {
	SERVICE_ENABLE = 0,
	SERVICE_DISABLE,
	SERVICE_RESTART
} SERVICE_ACTION;

typedef enum {
	SERVICE_NONE = SERV_INDEX_START - 1,
	SERVICE_WEB,
	SERVICE_PGSQL,
	SERVICE_USERHOME,
	SERVICE_END
} SERVICE_INDEX;

typedef enum {
	SERVINDEX_MIN = 0x0,
	SERVINDEX_FIREWALL = 0x01,
	SERVINDEX_ROUTER = 0x02,
	SERVINDEX_CONF_FILE = 0x04,
	SERVINDEX_SYNOINFO_FILE = 0x08,
	SERVINDEX_RUNTIME = 0x10,
	SERVINDEX_MAX = 0x20
} SERV_CONF_SERVINDEX;

#define SERVINDEX_ALL (SERVINDEX_FIREWALL | SERVINDEX_ROUTER | SERVINDEX_CONF_FILE | SERVINDEX_SYNOINFO_FILE)

typedef enum {
	SERV_MIN = 0x0,
	SERV_BUILDIN = 0x01,
	SERV_PACKAGE = 0x02,
	SERV_MAX = 0x4
} SYNO_SERV_TYPE;

#define SERV_ALL (SERV_BUILDIN | SERV_PACKAGE)

typedef enum {
	SERV_PROTOCOL_TCP = 0x01,
	SERV_PROTOCOL_UDP = 0x02
} SYNO_SERV_PROTOCOL;

#define SERV_PROTOCOL_ALL (SERV_PROTOCOL_TCP | SERV_PROTOCOL_UDP)

typedef struct {
	SYNO_SERV_PROTOCOL type;
	char *szType;
} PROTOCOL_STR_MAPPING;

typedef enum {
	POST_ACTION_NONE = 0,
	POST_ACTION_NORESTART = 1,
	POST_ACTION_RESTART = 2,
	POST_ACTION_MAX
} SYNO_SERV_POST_ACTION;

typedef enum {
	WRITE_ACTION_NONE = 0,
	WRITE_ACTION_APPEND = 1,
	WRITE_ACTION_OVERWRITE = 2,
	WRITE_ACTION_REMOVE = 3,
	WRITE_ACTION_MAX
} SYNO_SERV_WRITE_ACTION;

typedef enum _tag_NET_SERVICE_PLUGIN_EVENT_TYPE_ {
	EVENT_MIN = 0x0,
	EVENT_IP_CHANGED = 0x01,
	EVENT_HOSTNAME_CHANGED = 0x02,
	EVENT_MTU_CHANGED = 0x4,
	EVENT_MAX = 0x8
} NET_SERVICE_PLUGIN_EVENT_TYPE;

typedef struct {
	PSLIBPLUGIN pPlugin;
	int eType;
	DAEMON_ACTION daemonAct;
	int iResult;
} NET_SERVICE_PLUGIN_ENV;

typedef struct _tag_SYNO_HOME_CHECK_RESULT_ {
	size_t nAlloc;
	/** TRUE if "home service enabled and volume of it" is checked */
	BOOL blChkEnable;
	/** TRUE if "home path really owned by some existing user" is checked */
	BOOL blChkValid;
	AUTH_TYPE authType;
	char *szUserName;
	char *szHomePath;
	BOOL blHomeEnabled;
	/** Meaningless if blChkValid is FALSE */
	BOOL blExpired;
} *PSYNO_HOME_CHECK_RESULT;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/service_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_SERVICE_H__
