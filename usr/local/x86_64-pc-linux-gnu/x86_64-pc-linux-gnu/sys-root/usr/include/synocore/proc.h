// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_PROC_H__
#define __SYNO_PROC_H__

#include <sys/types.h>
#include <sys/cdefs.h>
#include <synocore/hash.h>
#include <synocore/list.h>

__BEGIN_DECLS;

/**
 * @addtogroup PROC
 *
 * @brief Functions related to process.
 *
 * @{
 */

#define SZF_CRON_PID_FILE			"/var/run/crond.pid"
#define SZF_SCEMD_PIDFILE			"/var/run/scemd.pid"

#define SZF_SMBSTATUS				"/usr/bin/smbstatus"

//For SFTP
#define SZD_SFTP_PROC 			"internal-sftp"
#define SZ_SYNO_SFTPD_STANDALONE_PROCESS    "sftpd"

//defined in service.h
#define GET_BY_USER 			0
#define GET_BY_SHARE 			1

// default value of max connections
#define DEF_MAX_CONNECTIONS		32

// define value for control oom score
#define SLIBC_PROC_OOM_SCORE_NEVER_KILL -1000
#define SLIBC_PROC_OOM_SCORE_DEFAULT 0

#define PARALLEL_JOB_NUM 10
typedef int (*PFuncCallback) (int itemIdx, void* pParams);

#define EINTR_RETRY_COUNT 3

typedef struct {
	pid_t pid;		/* process id */
	pid_t ppid;		/* pid of parent process*/

	char szCmd[16];	/*basename of executable file*/
	char state;		/*process state*/

	int ruid;		/* real uid */
	int rgid;		/* real gid */
	int euid;		/* effective uid */
	int egid;		/* effective gid */
} SYNOPROC, *PSYNOPROC;

#define	SLIBC_PROC_FORK_REDIRECT_STD_FD			0x0001
#define SLIBC_PROC_FORK_CLOSE_SLIBC_FILE_LOCK 	0x0002
#define	SLIBC_PROC_FORK_CLOSE_NONSTD_FD			0x0004
#define SLIBC_PROC_FORK_CLEAN_ENV				0x0008
#define SLIBC_PROC_FORK_CHANGE_DIR				0x0010
#define SLIBC_PROC_FORK_SET_SID					0x0020
#define SLIBC_PROC_FORK_NOWAIT					0x0040
#define SLIBC_PROC_FORK_RENICE					0x0080
#define SLIBC_PROC_INIT_CREDENTIALS				0x0100  // Ignored in flash mode SLIBCExecl().
#define SLIBC_PROC_FORK_DEFAULT		(SLIBC_PROC_FORK_REDIRECT_STD_FD | \
									SLIBC_PROC_FORK_CLOSE_SLIBC_FILE_LOCK | \
									SLIBC_PROC_FORK_SET_SID | \
									SLIBC_PROC_FORK_CHANGE_DIR | \
									SLIBC_PROC_FORK_RENICE | \
									SLIBC_PROC_FORK_CLEAN_ENV)

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/synotype.h>
#include <synocore/proc_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_PROC_H__
