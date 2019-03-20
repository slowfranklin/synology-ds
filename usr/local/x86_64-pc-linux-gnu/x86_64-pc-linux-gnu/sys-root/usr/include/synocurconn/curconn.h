// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_CURCONN_H__
#define __SYNO_CURCONN_H__

#include <sys/cdefs.h>
#include <time.h>
#include <synocore/list.h>
#include <synocore/file.h>

__BEGIN_DECLS;

#define SZF_FTPD_CONNECTION_REC			"/var/tmp/ftp_cur_con.log"
#define SZF_SFTPD_CONNECTION_REC		"/var/tmp/sftp_cur_con.log"

#define LOG_SYSTEM				1
#define LOG_MANAGE				2
#define LOG_UNIX				3
#define LOG_WIN					4
#define LOG_APPLE				5
#define LOG_NOVELL				6
#define LOG_FTPSERVICE			7
#define LOG_TELNET				8
#define LOG_HTTP				9
#define LOG_SSH					10
#define LOG_UNKNOWN_LOGIN		11
#define LOG_NFS					12
#define LOG_SFTPSERVICE			13

#define SZ_UNKNOWN_USERNAME	"-"
#define SZ_UNKNOWN_PID		"0"

typedef struct _tag_SYNO_CURCONN_ {
	unsigned int id;
	char *szTime;
	char *szHost;
	char *szName;
	char *szDesc;
	int type;
}SYNOCURCONN, *PSYNOCURCONN;

#ifndef NO_PROTO
#include <availability.h>
#include <synocurconn/curconn_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif
