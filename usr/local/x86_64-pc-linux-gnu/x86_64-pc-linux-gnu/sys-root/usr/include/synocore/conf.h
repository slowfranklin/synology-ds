// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_CONF_H__
#define __SYNO_CONF_H__

#include <stdint.h>
#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/error.h>
#include <synocore/unicode.h>

__BEGIN_DECLS;

/**
 * @addtogroup CONF
 *
 * @brief Some helper function for reading and setting configs.
 *
 * @{
 */

#define SZ_DS_UNIQUE    "unique"

#define SZK_ADMIN_PORT			"admin_port"
#define SZK_ADMIN_SSL_PORT		"secure_admin_port"
#define SZV_ADMIN_DEF_PORT		"5000"
#define SZV_ADMIN_SSL_DEF_PORT	"5001"

#define SZK_SYNOBIOS		"synobios"
#define SZV_SYNOBIOS_VDSM	"kvmx64"
#define SZK_CDSM_MODE		"c2_dsm"
#define SZK_TIME_MACHINE_SHARE	"time_machine_share"
#define SZK_TIME_MACHINE_SHARE_MAP	"time_machine_share_map"
#define	SZK_SUPPORT_NETBKP		"netbkp"
#define SZK_SUPPORT_TIMEBKP		"support_timebkp_server"
#define SZK_SUPPORT_IMG_BKP		"support_img_backupd"
#define SZK_SUPPORT_UPS		"supportups"
#define SZK_RUN_MYSQL			"runmysql"
#define SZK_PGSQL_FS_UUID		"pgsql_fs_uuid"
#define SZK_PGSQL_AUTOSELECT	"pgsql_autoselect"
#define SZK_PGSQL_MANUAL_MODE	"pgsql_manual_mode"
#define SZK_SUPPORT_OFFLINE_FILES "support_offline_files"
#define SZK_OPLOCK_DISABLED		"oplock_disabled"
#define SZK_SUPPORT_MEDIASERVICE    "supportmediaservice"
#define SZK_RUN_PHOTO    "runphoto"
#define SZK_SUPPORT_FILE_INDEX              "supportfileindex"
#define SZK_SUPPORT_RAIDGROUP              "supportraidgroup"
#define SZK_SAMBA_LMB		"local master"
#define SZK_SAMBA_SYNC_DCTIME "syno sync dctime"
#define SZK_SAMBA_ENCRYPT_PASSWORDS "encrypt passwords"
#define	SZK_SUPPORT_SSH		"supportssh"
#define	SZK_SUPPORT_WEB		"supportweb"
#define	SZK_SUPPORT_PHOTO		"supportphoto"
#define SZK_SUPPORT_PHOTO_PERSONAL "supportphotopersonal"
#define SZK_SUPPORT_USBBKP		"usbbkp"
#define SZK_SUPPORT_BUZZER		"support_buzzer"
#define SZK_SUPPORT_LED_ADJUST	"support_led_brightness_adjustment"
/** Used as key in SZF_DEF_SYNOINFO to indicate whether USB copy is supported */
#define SZK_SUPPORT_SDCOPY		"sdcopy"
#define	SZK_SUPPORT_USBCOPY		"usbcopy"
#define SZK_SUPPORT_RAID        "supportraid"
#define SZK_SUPPORT_RAIDCROSS	"supportraidcross"
#define SZK_SUPPORT_DDNS        "supportddns"
#define SZK_SUPPORT_QUOTA        "supportquota"
#define SZK_SUPPORT_GROUP        "support_group"
#define SZK_SUPPORT_APP_PRIVILEGE        "support_app_privilege"
#define SZK_SUPPORT_UART2		"supportuart2"
#define SZK_SUPPORT_VIDEOSTATION	"supportvideostation"
#define SZK_SUPPORT_S2S_SERVER "support_s2s_server"
#define SZK_SUPPORT_HA		"support_ha"
#define SZK_SUPPORT_TRUSTDOMAIN		"supporttrustdomain"
#define SZK_SUPPORT_PERFEVENT "support_performance_event"
#define SZK_WEB_LOCAL_ENABLE		"supportweblocaluser"
#define SZK_PERSONALPHOTOSTATION_ENABLE "runpersonalphotostation"
#define SZK_FILEBRROWSER_LOG_ENABLE		"filebrowserxferlog"
#define SZK_SMB_LOG_ENABLE                "smbxferlog"
#define SZK_AFP_LOG_ENABLE                "afpxferlog"
#define SZK_FILESTATION_SUPPORT		"supportfilestation"
#define SZK_GROUPS_MAX				"maxgroups"
#define SZK_SHARES_MAX				"maxshares"
#define SZK_USERS_MAX				"maxaccounts"
#define SZK_MAX_STORAGE_BATCH_TASK	"max_storage_batch_task"
#define SZK_RUN_SNMPD               "runsnmpd"
#define SZK_RUN_HTTPS				"runHTTPS"
#define SZK_RUN_WEB_HTTPS			"runWebHTTPS"
#define SZK_RUN_SYS_SPDY			"runsysspdy"
#define SZK_RUN_USER_SPDY			"runuserspdy"
#define SZK_RUN_SYS_HSTS			"runsyshsts"
#define SZK_RUN_USER_HSTS			"runuserhsts"
#define SZK_RUN_HA                  "runha"
#define SZK_RUN_SYSTEMDR            "runsystemdr"
#define SZK_SFTP_PORT           	"sftpPort"
#define SZK_WEBDAV_PORT             "WebDavPort"
#define SZK_WEBDAV_SSL_PORT			"secure_WebDavPort"
#define SZV_WEBDAV_DEF_PORT         "5005"
#define SZV_WEBDAV_SSL_DEF_PORT		"5006"
#define SZK_WEBDAV_LOG_ENABLE		"webdavxferlog"
#define SZK_WEBDAV_ANONYMOUSLOGIN   "webdavanonymouslogin"
#define SZK_WEBDAV_DEPTH_INFINITY   "webdavdepthinfinity"
#define SZK_RUN_CALDAV              "runCalDav"
#define SZK_DSM_UPDATE_TYPE			"upgradetype"
#define SZK_DSM_AUTOUPDATE_TYPE		"dsm_autoupdate_type"
#define SZK_DSM_TIMEOUT				"dsmtimeout"
#define SZK_USER_HOME               "userHomeEnable"
#define SZK_DOMAIN_USER_HOME		"enableduserhome"
#define SZK_LDAP_USER_HOME			"enableluserhome"
#define SZK_TRUST_DOMAIN		"enabletrustdomain"
#define SZK_FTP_CHROOT              "ftpUserChroot"
#define SZK_ANONYMOUS_CHROOT        "ftpanonymouschroot"
#define SZK_ANONYMOUS_ROOT          "ftpanonymousroot"
#define SZK_UPGRADE_PKG_EMAIL_NOTIFY	"upgrade_pkg_email_notification"
#define SZK_UPGRADE_PKG_DSM_NOTIFY	"upgrade_pkg_dsm_notification"
#define SZK_PKG_SOURCE_TRUST_LEVLE	"pkg_source_trust_level"
#define SZK_PKG_DEF_INSTALL_VOL		"pkg_def_intall_vol"
#define SZK_PKG_ENABLE_AUTOUPDATE_ALL	"enable_pkg_autoupdate_all"
#define SZK_PKG_AUTOUPDATE_ALL		"pkg_autoupdate_all"
#define SZK_PKG_ENABLE_PAYPAL		"pkg_enable_paypal"
#define SZF_JUNIOR_FHOST_STATUS		"/tmp/fhost.status"
#define SZF_DEF_VERSION_FILE		"/etc.defaults/VERSION"
#define SZF_SYNO_INFO				"/etc/synoinfo.conf"
#define SZF_SS_INFO					"/var/packages/SurveillanceStation/etc/settings.conf"
#define SZF_DEF_SYNOINFO			"/etc.defaults/synoinfo.conf"
#define SZF_CUSTOM_DEF				"/etc.defaults/synoinfo.conf"
#define SZD_PHP_CONFD				"/etc/php/conf.d"
#define SZD_PHP_CONFD_DEFAULT			"/etc.defaults/php/conf.d"
#define SZF_PHP_USER_SETTING_INI		SZD_PHP_CONFD"/user-settings.ini"
#define SZF_PHP_USER_SETTING_INI_DEFAULT	SZD_PHP_CONFD_DEFAULT"/user-settings.ini"
#define SZF_EXTENSION_INI			SZD_PHP_CONFD"/extensions.ini"
#define SZF_EXTENSION_INI_DEFAULT		SZD_PHP_CONFD_DEFAULT"/extensions.ini"
#define SZD_BUILDIN_SERVICE_CONF		"/usr/syno/etc/services.d"
#define SZD_PACKAGE_SERVICE_CONF		"/usr/local/etc/services.d"
#define SZD_PHP_EXTENSION			"/lib/php/modules"
#define SZD_ETC_DEFAULTS		"/etc.defaults"
#define SZ_SMB_FILE                 "/etc/samba/smb.conf"
#define	SZ_DEF_COMPANY				"synology"
#define SZK_PHP_APC_ENABLED			"apc.enabled"
#define SZK_PHP_OPCACHE_ENABLED		"opcache.enable"
#define SZK_PHP_OPCACHE_ENABLED_CLI		"opcache.enable_cli"
#define SZK_PHP_DISPLAY_ERRORS			"display_errors"
#define SZK_OPEN_BASEDIR			"open_basedir"
#define SZK_PHP_SAFE_MODE_EXEC_DIR      "safe_mode_exec_dir"
#define SZK_PHP_OPENBASEDIR_CUSTOMIZE			"php_openbasedir_customize"
#define SZK_SUPPORT_NTFS_WRITE		"supportntfswrite"
#define SZK_SUPPORT_ISCSI_TARGET    "support_iscsi_target"
#define SZK_SUPPORT_HFSPLUS			"supporthfsplus"
#define SZK_SUPPORT_HFSPLUS_RW		"support_hfsplus_rw"
#define SZK_ISCSI_TARGET_TYPE       "iscsi_target_type"
#define SZK_SUPPORT_ISCSI_TARGET_BLOCK  "support_iscsi_target_block"
#define SZK_SUPPORT_DEMOMODE		"support_demomode"
#define SZK_ENABLE_DEMOMODE			"enable_demomode"
#define SZK_DEMOMODE_KEY			"demomode_key"
#define SZK_SUPPORT_SURVEILLANCE	"supportsurveillance"
#define SZK_SHOW_POOL_TAB   "showpooltab"
#define SZK_SS_CMS_SLAVE 			"ss_cms_slave"
#define SZK_MAX_LAN_PORT 			"maxlanport"
#define SZK_SUPPORT_SHARE_ENCRYPTION	"support_share_encryption"
#define SZK_SUPPORT_WIRELESS        "support_wireless"
#define SZK_SUPPORT_WIMAX        "support_wimax"
#define SZK_SUPPORT_TASK_SCHEDULER        "support_task_scheduler"
#define SZK_SUPPORT_DISK_REPORT        "support_disk_report"
#define SZK_SUPPORT_SYNOACL			"support_synoacl"
#define SZK_SKIP_CHECK_SESSION_SRCIP "skip_checksrcip"
#define SZK_SNAPSHOT_ORIGIN			"enable_snapshot_origin"
#define	SZK_SUPPORT_RSRC_MON		"supportrsrcmon"
#define	SZK_SUPPORT_MEM_TEST		"supportmemtest"
#define SZK_SUPPORT_SYS_MIGRAT		"supportsysmigrat"
#define SZK_SUPPORT_SHR				"support_syno_hybrid_raid"
#define	SZK_SUPPORT_SSD_CACHE		"support_ssd_cache"
#define	SZK_SUPPORT_WRITE_CACHE		"support_write_cache"
#define SZK_STRICT_SSD_POLICY		"strict_ssd_policy"
#define SZK_SATA_AS_CACHE			"sata_as_cache"
#define SZK_SUPPORT_TEMPERATURE                "supportsystemperature"
#define SZK_RESTART_CLEAN_SESSION	"restart_clean_session"
#define	SZK_ESATA_PORT_CONFIG       "esataportcfg"
#define SZK_SUPPORT_APPAMOR			"support_apparmor"
#define SZK_RETAIN_ADMIN_PWD		"retain_admin_pwd"
#define SZK_SUPPORT_RDMA            "support_rdma"

/* For SSD Cache */
#define SZK_MEM_DEFAULT_MB "mem_default_mb"
#define SZK_CACHE_PSEUDO_MEM_DEFAULT_MB "cache_pseudo_mem_default_mb"
#define SZK_MEM_MAX_MB "mem_max_mb"
#define SZK_MIN_CACHE_SIZE_MB		"ssd_cache_min_cache_size_mb"
#define SZK_SSD_CACHE_FREE_RESERVED_MB	"ssd_cache_free_reserved_mb"
#define SZK_SSD_CACHE_DEFAULT_MEM_PERCENT "ssd_cache_default_mem_percent"

#define SZV_YES		"yes"
#define SZV_NO		"no"
#define SZK_PPPOE_ENABLE			"pppoe_enable"
#define SZF_NORMAL_EJECT			"NORMAL_EJECT"
#define SZF_DSM_NOTIFY				"/usr/syno/bin/synodsmnotify"
#define SZF_APP_NOTIFY				"/usr/syno/bin/synoappnotify"
#define SZK_LOGIN_FORGET_PASS  "forget_password_enable"
#define SZK_LOGIN_STYLE			"login_style"
#define SZK_LOGIN_WEATHER		"weather_info"
#define SZK_LOGIN_LOGO			"login_logo_customize"
#define SZK_LOGIN_LOGO_POS		"login_logo_position"
#define SZK_LOGIN_LOGO_EXT		"login_logo_ext"
#define SZK_LOGIN_LOGO_SEQ		"login_logo_seq"
#define SZK_LOGIN_WELCOME_TITLE	"login_welcome_title"
#define SZK_LOGIN_WELCOME_MSG		"login_welcome_msg"
#define SZK_LOGIN_VERSION_LOGO	"login_version_logo"
#define SZK_RSYNC_SSHD_PORT		"rsync_sshd_port"
#define SZK_RSYNC_ACCOUNT		"rsync_account"
#define SZK_SUPPORT_SAS			"supportsas"
#define SZK_SUPPORT_NVME			"supportnvme"
#define SZK_SUPPORT_EXPANSION_HEARTBEAT  "support_expansion_heartbeat"
#define SZK_SUPPORT_NETFILTER_SHORTCUT	"support_netfliter_shortcut"
#define SZK_CUSTOM_LOGIN_TITLE	"custom_login_title"
#define SZK_WELCOME_HIDE "welcome_hide"
#define SZK_ENABLE_SMB2 "enable_smb2"
#define SZK_USB_STATION "usbstation"
#define SZK_SUPPORT_CONFIG_SWAP "support_config_swap"
#define SZK_NO_DISK_SWAP "no_disk_swap"
#define SZK_AFP_UMASK "afp_umask"
#define SZK_CONFIGURED "configured"
#define SZK_NET_ARP_IGNORE       "arp_ignore"
#define SZK_NET_MULTI_GATEWAY	 "multi_gateway"
#define SZK_EXTERNAL_DEVICE_DELALLO "external_device_delalloc"
#define SZK_EXTERNAL_DEVICE_SUPPORT_EXFAT "external_device_support_exfat"

#define SZF_NSSWITCH_CONF "/etc/nsswitch.conf"
#define SZF_DEFAULT_NSSWITCH_CONF "/etc.defaults/nsswitch.conf"
#define SZK_USE_RESERVED_MORE_GDT		"use_reserved_more_gdt"

#define SZK_EXTERNAL_HOST_IP			"external_host_ip"
#define SZK_EXTERNAL_PORT_DSM_HTTP		"external_port_dsm_http"
#define SZK_EXTERNAL_PORT_DSM_HTTPS		"external_port_dsm_https"
#define SZK_EXTERNAL_PORT_PHOTO_HTTP	"external_port_photo_http"
#define SZK_EXTERNAL_PORT_PHOTO_HTTPS	"external_port_photo_https"

#define SZK_MAX_HA_SPACECOUNT           "max_ha_spacecount"
#define SZK_SUPPORT_BUILDIN_STORAGE		"support_buildin_storage"
#define SZK_SUPPORT_AUTO_INSTALL		"support_auto_install"
#define SZK_SUPPORT_USB_VOLUME			"support_usb_volume"
#define SZK_SUPPORT_DIRECTORY_SERVICE	"support_directory_service"
#define SZK_SUPPORT_SMART				"supportsmart"
#define SZK_SUPPORT_RC_POWER			"supportrcpower"
#define SZK_SUPPORT_EMMC_BOOT           "support_emmc_boot"

#define SZK_CHECK_FRAME_OPTIONS		"check_frame_options"
#define SZK_FRAME_OPTIONS_ALLOW_URL		"frame_options_built_in_allow_url"

#define SZK_SUPPORT_SYS_ADJUST          "support_sys_adjust"
#define SZK_SYS_ADJUST_GROUPS           "sys_adjust_groups"

//For PXE
#define SZK_PXE_BOOTLOADER		"pxebootloader"
#define SZK_PXE_ENABLE			"pxeenable"
#define SZK_TFTP_LOG_ENABLE     "tftpxferlog"

//For apache
#define SZF_APACHE_SSL_INTERMEDIATE	"/usr/syno/etc/ssl/ssl.intercrt/server-ca.crt"

// For UPnP
#define SZK_ENABLE_UPNP_PORTMAPPING		"runupnpportmapping"
#define SZK_ENABLE_NATPMP_PORTMAPPING		"runnatpmpportmapping"

// For user/group
#define NSS_BUFFSIZE_LIMIT 1 << 28 // 256 MB

// For DSM CMS
#define SZK_JOIN_DSM_CMS 	"join_dsm_cms"
#define SZK_DSM_CMS_SELF	"dsm_cms_self_join"
#define SZK_DISABLE_JOIN_CMS_HOST	"disable_join_cms_host"

// For SPDY
#define SZK_SUPPORT_SPDY			"support_spdy"

// For FTP
#define FTP_DEF_LOW_PORT    55536    // also used by webman/jslib/utils.js
#define FTP_DEF_MAX_PASSIVE_PORT_RANGE  128
#define SZK_FTP_LOW_PORT "ftplowport"
#define SZK_FTP_HIGH_PORT "ftphighport"

// For NFS
#define SZK_SUPPORT_NFS "supportNFS"
#define SZD_ETC_NFS "/etc/nfs"
#define SZ_NFS_KRB5_CONF "krb5.conf"
#define SZF_NFS_KRB5_CONF SZD_ETC_NFS "/" SZ_NFS_KRB5_CONF
#define SZ_NFS_KRB5_KEYTAB "krb5.keytab"
#define SZF_NFS_KEYTAB SZD_ETC_NFS "/" SZ_NFS_KRB5_KEYTAB
#define SZ_NFS_SYNO_CONF "syno_nfs_conf"
#define SZF_NFS_CONF SZD_ETC_NFS "/" SZ_NFS_SYNO_CONF
#define SZK_NFS_CUSTOM_PORT "nfs_custom_port_enable"
#define SZK_NFS_STATD_PORT "statd_port"
#define SZK_NFS_NLM_PORT "nlm_port"
#define SZ_NFS_NAME "nfsd"
#define SZF_NFS_SCRIPT SZD_SYSTEMV"/S83nfsd.sh"
#define SZ_PORT_NFS "111,892,2049"
#define SZK_NFSV4_ENABLE "nfsv4_enable"

//for uistring
#define SZ_REPLACE_PRODUCT_KEY "_DISKSTATION_"
#define SZ_REPLACE_OSNAME_KEY "_OSNAME_"
#define SZK_OS_NAME "os_name"
#define SZK_PRODUCT_NAME "product"
#define SZV_DEF_OS_NAME "DSM"
#define SZV_DEF_PRODUCT_NAME "DiskStation"
#define SZ_MAIL_REPLACE_PRODUCT_KEY "%DISKSTATION%"
#define SZ_MAIL_REPLACE_OSNAME_KEY "%OSNAME%"

// For Firewall & Tc
#define SZD_FIREWALL "/usr/syno/etc/firewall.d"
#define SZD_SECURITY "/etc/fw_security"

typedef enum _tag_syno_firewall_protocol_{
	FW_PROTOCOL_TCP=0x01,
	FW_PROTOCOL_UDP=0x02,
	FW_PROTOCOL_ICMP=0x04,
	FW_PROTOCOL_ALL=FW_PROTOCOL_TCP|FW_PROTOCOL_UDP, // includes protocols out of tcp
} SYNO_FW_PROTOCOL;

#define SYNO_TC_BINARY "/usr/syno/bin/tctool"
#define SYNO_FW_BINARY "/usr/syno/bin/synofirewall"

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/conf_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_CONF_H__
