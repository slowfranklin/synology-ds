// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICE_NTP_H__
#define __SYNO_SERVICE_NTP_H__

#include <sys/cdefs.h>
#include <sys/param.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZF_NTPDATE					"/usr/sbin/ntpdate"
#define SZF_NTPCONF					"/etc/ntp.conf"
#define SZF_NTP_USER_CONF			"/etc/ntp.conf.user"
#define SZF_NTP_COMMON_CONF		"/usr/share/ntp/ntp-common.conf"
#define SZF_NTP_INCLUDE_POOLNTPORG_CONF		"/usr/share/ntp/pool.ntp.org.conf"
#define SZF_NTP_INCLUDE_TIMEGOOGLE_CONF		"/usr/share/ntp/time.google.com.conf"
#define SZF_NTP_RESTRICT_SERVERON_CONF		"/usr/share/ntp/ntp-restrict-serveron.conf"
#define SZF_NTP_RESTRICT_SERVEROFF_CONF		"/usr/share/ntp/ntp-restrict-serveroff.conf"
#define SZ_CRON_NTP_FORMAT			"%s\troot\t%s -b %s %s"

#define SZ_NTP_CONF_RESTRICT_CLIENT_V4		"restrict default ignore"
#define SZ_NTP_CONF_RESTRICT_CLIENT_V6		"restrict -6 default ignore"
#define SZ_NTP_CONF_RESTRICT_SERVER_V4		"restrict default kod nomodify notrap nopeer noquery"
#define SZ_NTP_CONF_RESTRICT_SERVER_V6		"restrict -6 default kod nomodify notrap nopeer noquery"
#define SZ_NTP_CONF_RESTRICT_ALLOW_LOCAL_V4	"restrict 127.0.0.1"
#define SZ_NTP_CONF_RESTRICT_ALLOW_LOCAL_V6	"restrict -6 ::1"
#define SZ_NTP_CONF_DISABLE_MONITOR		"disable monitor"
#define SZ_NTP_SERV_DEFAULT                     "127.127.1.0" //for local clock server
#define SZ_NTP_SERV_POOLNTPORG              "pool.ntp.org"
#define SZ_NTP_SERV_TIMEGOOGLE              "time.google.com"

#define SZ_NTP_SERVER_SERVICE			"ntpd-server"
#define SZ_NTP_CLIENT_SERVICE			"ntpd-client"

typedef struct _tag_SYNO_NTP_ {
	int runNtp;			/* 0:disable ntpdate , 1:enable ntpdate*/
	char szPeriod[10];	/* Periodic running ntpdate */
	char szNtpdateServer[MAXHOSTNAMELEN];	/* Primary NTP server */
	char szNtpdateServerBk[MAXHOSTNAMELEN];	/* Secondary NTP server */
	int runNtpServer;	/* 0:disable NTP server , 1:enable NTP server */
} SYNONTP, *PSYNONTP;

#ifndef NO_PROTO
#include <synoserviceutil/ntp_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_SERVICE_NTP_H__
