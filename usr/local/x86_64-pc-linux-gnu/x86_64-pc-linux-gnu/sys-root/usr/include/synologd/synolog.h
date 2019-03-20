#ifndef	_SYNO_LOG_H
#define _SYNO_LOG_H

#include <stdlib.h> /* for off_t */
#include <synosdk/log.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SZF_SYNOLOGD_PID    "/var/run/synologd.pid"
#define SYNO_LOGD_SOCK	    "/var/run/synologd"
#define SYNOLOG_MAX_LEN     5120

typedef enum {
	SYNO_LOG_FTP_XFERLOG = 1, /* Must start > 0 */
	SYNO_LOG_WEBFM_XFERLOG,
	SYNO_LOG_DSMFM_XFERLOG,
	SYNO_LOG_WEBDAV_XFERLOG,
	SYNO_LOG_SMB_XFERLOG,
	SYNO_LOG_AFP_XFERLOG,
	SYNO_LOG_TFTP_XFERLOG,
} SYNO_LOG_TYPE;

/* Prototype for libsynolog */

/**
 * Write file transfer log to socket listened by syslog-ng 
 * 1. Compose bsd log format (RFC3124) log buffer 
 * 2. Open default syslog-ng socket (/var/log/syslog) 
 * 3. Write composed buffer to socket 
 * 
 * @param szIP		[IN]
 * @param szUser 	[IN]
 * @param szCmd		[IN]
 * @param Size		[IN]
 * @param szPath 	[IN]
 * @param blIsDir 	[IN]
 * @param LOG_TYPE 	[IN]
 * 
 * @return int 
 *   0: success
 *   -1: failed
 */
int SyslogSend(const char *szIP, const char *szUser, const char *szCmd, off_t Size, 
			   const char *szPath, int blIsDir, SYNO_LOG_TYPE LOG_TYPE);

/**
 * Write file transfer log to given socket 
 * 1. Compose BSD log format (RFC3124) log buffer 
 * 2. Write composed buffer to given socket
 * 
 * @param fd 		[IN]
 * @param szIP 		[IN]
 * @param szUser 	[IN]
 * @param szCmd 	[IN]
 * @param Size 		[IN]
 * @param szPath 	[IN]
 * @param blIsDir 	[IN]
 * @param LOG_TYPE 	[IN]
 * @section apparmor AppArmor
 * synologd supports AppArmor, the abstraction profile is placed in abstractions/synologd
 * 
 * @return int 
 *   0: success
 *   -1: failed
 */
int SyslogSendByFd(int fd,
				   const char *szIP, const char *szUser, const char *szCmd, off_t Size,
				   const char *szPath, int blIsDir, SYNO_LOG_TYPE LOG_TYPE);

/* ftpxfer.c */
int SYNOLogFTPXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir, unsigned int justOpenFd);

int SYNOLogWebFMXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogDSMFMXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogWebDAVXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogSMBXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogAFPXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogTFTPXferLog(const char *szIP, const char *szUser,
					  const char *szCmd, off_t Size, const char *szPath, int blIsDir);

int SYNOLogXferLog(const char *szIP, const char *szUser, const char *szCmd, off_t Size, 
						const char *szPath, int blIsDir, SYNO_LOG_TYPE LOG_TYPE);

#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* _SYNO_LOG_H */
