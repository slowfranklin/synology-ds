// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_FTP_H__
#define __SYNO_FTP_H__

#include <sys/cdefs.h>

#include <synocore/list.h>
#include <synosdk/share.h>
#include <unistd.h>
#include <limits.h>

__BEGIN_DECLS;

typedef struct _tag_SYNO_FTP_PASVPORT_ {
	int lowPort;
	int highPort;
} SYNO_FTP_PASVPORT;

#define	ANONYMOUS_FTP_USER	"Anonymous FTP"
#define	SZ_CONF_USER_FTP	"ftp"

#define PASSIVE_PORT_MIN	1025 // port of passive mode must > 1024
#define FTP_PORT_RANGE_LIMIT	4 //at least 4 ports
#define FTP_PORT_RANGE_MAX	128  //at most 128 ports  and also used by webman/jslib/utils.js
#define SZK_FTP_EXT_IP "ftp_ext_ip"
#define SZK_FTP_ENABLE_FXP "ftp_enable_fxp"
#define SZK_FTP_ENABLE_FIPS "ftp_enable_fips"
#define SZK_FTP_ENABLE_ASCII_MODE "ftp_enable_ascii_mode"
#define SZK_FTP_ENABLE_UMASK "ftp_enable_umask"
#define SZK_FTP_SUPPORT_UTF8 "ftpsupportutf8"
#define SZK_FTP_USE_UTF8 "ftp_use_utf8"
#define FTP_DISABLE		0
#define FTP_ENABLE		1
#define SZK_FTP_TIMEOUT "ftptimeout"
#define FTP_DEFAULT_TIMEOUT 300
#define FTP_DEFAULT_MIN_TIMEOUT 1
#define FTP_DEFAULT_MAX_TIMEOUT 7200	//This value should be mapped to ftpd default max timeout
#define SZ_FTP_CHROOT_PATH_HOME "/home"
#define FTP_CHROOT_RULE_MAX 2048
#define SZF_FTP_CHROOT_USER_UID "/usr/syno/etc/ftpchrootuid.conf"
#define SZF_FTP_CHROOT_RULE "/usr/syno/etc/ftpchrootrule.conf"
#define SZ_FTP_SERVICE_NAME "ftpd"
#define SZ_FTPES_SERVICE_NAME "ftpd-ssl"
#define SZF_FTP_SERVICE_SCRIPT SZD_SYSTEMV"/S99ftpd.sh"

typedef struct _tag_SYNO_FTP_CONF_ {
	char szPort[8];
	char szAnonymousRoot[SYNO_SHARENAME_UTF8_MAX];
	int SupportExternalIP;
	int FlowControl;
	int MaxUploadRate;
	int MaxDownloadRate;
	int AnonymousLogin;
	int AnonymousChroot;
	int LowPort;
	int HighPort;
	int EnableSSL; //SSL mandatory
	int SupportUTF8Client;
	int MaxConnectionPerIP;
	int EnableTransferLog;
	int EnableFXP;
	int UserChroot;
} __attribute__((packed)) SYNO_FTP_CONF;

enum FTP_SSL_ENABLED {
	FTP_STATUS_NOT_RUNNING = 0x0,
	FTP_STATUS_ONLYFTP = 0x1,
	FTP_STATUS_ONLYFTPES = 0x2,
	FTP_STATUS_BOTH = FTP_STATUS_ONLYFTP | FTP_STATUS_ONLYFTPES
};

/* SFTP */
#define SZF_SSHD_UTILS			"/usr/syno/bin/synosshdutils"
#define SZD_SFTP_REFER_KEY 		"sftpd"
#define SZD_SSH_REFER_KEY 		"shell"
#define SFTP_DEFATUL_PORT		22
#define SFTP_ON_SSH_PORT		0
#define SFTP_SSHD				"sshd"
#define SFTP_SFTPD				"sftpd"
#define SFTP_SERVICE_NAME		"SFTP"
#define SZF_FIREWALL_SFTP_SERVICE_CONTROL "syno_sftpsys.sc"
#define SZF_FIREWALL_SFTP_SYS_PATH SZD_FIREWALL_SERVICE_DIRECTORY SZF_FIREWALL_SFTP_SERVICE_CONTROL

typedef enum _tag_sftp_config_filter_ {
	SFTP_CONF_GENERAL = 0x01,
	SFTP_CONF_CHROOT = 0x02,
	SFTP_CONF_ALL = SFTP_CONF_GENERAL | SFTP_CONF_CHROOT,
} SYNO_SFTP_CONF_FILTER;

typedef struct _tag_SYNO_SFTP_CONFIG_ {
	BOOL isEnable;				//SFTP is enabled
	BOOL isChrootEnable;		//General User Chroot
	BOOL isAnonyEnable;			//Anonymous Enabled
	BOOL isAnonyChrootEnable;	//Anonymous Chroot
	BOOL isXferLogEnable;		//Transfer Log
	unsigned int port;			//SFTP's port.
	char * szAnonyChrootShareName; //Share name when Anonymous Chroot 
} SYNO_SFTP_CONFIG;

typedef enum _tag_sftp_service_action_ {
	SFTP_HUP,
	SFTP_START,
	SFTP_STOP,
	SFTP_RESTART
} SYNO_SFTP_SERVICE_ACTION;

/* TFTP */
#define SZF_TFTP_SCRIPT                 "/usr/syno/etc/rc.d/S99tftpd.sh"
#define SZF_OPENTFTPD_INI			"/etc/opentftp.ini"
#define SZF_FIREWALL_TFTP_SERVICE_CONTROL "syno_tftpsys.sc"
#define TFTP_SERVICE_NAME		"TFTP"
#define SZ_TFTP_SERVICE_NAME "tftp"
#define TFTP_DEFATUL_PORT		69
#define SZF_FIREWALL_TFTP_SYS_PATH SZD_FIREWALL_SERVICE_DIRECTORY SZF_FIREWALL_TFTP_SERVICE_CONTROL

typedef struct _tag_SYNO_TFTP_CONFIG_ {
	BOOL isEnable;
	BOOL isPXEEnable;
	BOOL isAllowWrite;
	BOOL isAllowAll;
	char szTftpRoot [PATH_MAX];
	char szBootLoader [PATH_MAX];
	char szAllowIPLow [MAX_IP_LENGTH];
	char szAllowIPHigh [MAX_IP_LENGTH];
	BOOL isLogEnable;
	int Timeout;
} SYNO_TFTP_CONFIG;

typedef enum _tag_tftp_service_action_ {
	TFTP_START,
	TFTP_STOP,
	TFTP_RESTART
} SYNO_TFTP_SERVICE_ACTION;

#ifndef NO_PROTO
#include <availability.h>
#include "synoftp_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_FTP_H__
