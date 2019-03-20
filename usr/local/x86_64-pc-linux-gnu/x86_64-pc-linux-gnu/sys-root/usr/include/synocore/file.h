// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_FILE_H__
#define __SYNO_FILE_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/cdefs.h>
#include <synocore/hash.h>
#include <synocore/list.h>

__BEGIN_DECLS;

/**
 * @addtogroup FILE
 *
 * @brief The structure and operation of files.
 *
 * @{
 */

#define OP_COMMENT      0x0100
#define OP_FIND_LAST    0x0001
#define OP_FIND_PREFIX  0x0002
#define OP_FIND_POSTFIX 0x0004
#define OP_FIND_DIR     0x0040
#define OP_FIND_FILE    0x0080
#define OP_ADD_AFTER    0x0200
#define OP_FIND_CASE    0x0400

#define SYNO_BUFFER_SIZE 1024

#define LOCK_SH_NB      0x0005	// LOCK_SH | LOCK_NB
#define LOCK_EX_NB      0x0006	// LOCK_EX | LOCK_NB
#define LOCK_PW         0x0010
#define LOCK_GR         0x0020
#define LOCK_SMB        0x0040
#define LOCK_RC         0x0080
#define LOCK_HOST       0x0100
#define LOCK_EXPORTS    0x0200
#define LOCK_NW         0X0400
#define LOCK_SYNOINFO   0X0800
#define LOCK_APPLE      0X1000
#define LOCK_SNMP       0X2000
#define LOCK_WIN        0x4000
#define LOCK_TAPEBKP    0x8000
#define LOCK_CONNECT    0x10000
#define LOCK_USBIDMAP   0x20000
#define LOCK_DUSERUID   0x40000
#define LOCK_DUSERGID   0x80000
#define LOCK_FSTAB      0x100000
#define LOCK_HOTSWAP    0x200000
#define LOCK_SPACE      0x400000  //space config
#define LOCK_TTYS1      0x800000
#define LOCK_SRVMGR	0x1000000
#define LOCK_MOUNT	0x2000000
#define LOCK_LUNBKP_TASK		0x4000000
#define LOCK_LUNBKP_ENV			0x8000000
#define LOCK_PKG				0x10000000
#define LOCK_FTP_CURRLOG		0x20000000
#define LOCK_SSHD_REFERENCE		0x40000000
#define LOCK_SFTP_CURRLOG		0x80000000
#define LOCK_TIMEOUT    5

#define SZ_LOCK_DIR     "/run/synosdk/lock/"
#define SZD_CONF_TMP    "/etc/skel"
#define SET_SECTION     0x0001

typedef struct {
	FILE       *pfFile;
	char       *szFile;
	int         idFile;
	int         cLock;
	int         type;
} SLIBLOCK;

/**
 * Flag for SLIBCFileUTime to set access & modify time.
 */
#define SLIB_AMTIME 			0x0001
/**
 * Flag for SLIBCFileUTime to set create time.
 */
#define SLIB_CRTIME  			0x0002
/**
 * Flag to tell SLIBCFileUTime not to follow symbolic links.
 */
#define SLIB_NOT_FOLLOW_LINK  	0x1000
/**
 * Flag to tell SLIBCFileUTime to log error.
 */
#define SLIB_LOG_ERR  			0x2000

typedef struct {
	/**
	 * Last access time.
	 */
	struct timespec atime;
	/**
	 * Last modify time.
	 */
	struct timespec mtime;
	/**
	 * Create time.
	 */
	struct timespec crtime;
} SLIB_FILETIME;

/*--------------------------SYNOSTAT Start------------------------*/

// Be careful!! If you want to change following structure, 
// you should modify kernel/include/linux/stat.h, too.

struct SYNOSTAT_EXTRA {
	/**
	 * Create time.
	 */
	struct timespec creatTime;
	/**
	 * Backup version.
	 */
	unsigned int bkpVer;
	/**
	 * Archive bit.
	 */
	unsigned int archBit;
};
typedef struct {
	/**
	 * Linux native stat.
	 */
	struct stat st;
	/**
	 * Extra stat.
	 */
	struct SYNOSTAT_EXTRA ext;
}SYNOSTAT;

/**
 * Flags to get stat.
 */
#define SYNOST_STAT			0x00000001
/**
 * Flags to get archive bit.
 */
#define SYNOST_ARBIT		0x00000002
/**
 * Flags to get backup version.
 */
#define SYNOST_BKPVER		0x00000004
/**
 * Flags to get create time.
 */
#define SYNOST_CREATIME		0x00000008

/**
 * Flags to get all above.
 */
#define SYNOST_ALL			SYNOST_STAT|SYNOST_ARBIT|SYNOST_BKPVER|SYNOST_CREATIME
/**
 * Flags indicating caseless stat.
 */
#define SYNOST_IS_CASELESS	0x10000000

/*------------------------SYNOSTAT End-------------------------*/

#define SYNOAssert(expr) { \
	char rgb[256]; \
	if (!(expr)) { \
		snprintf(rgb, sizeof(rgb), "assertion \"%s\" failed: file \"%s\", line %d0\n", "expr", __FILE__, __LINE__); \
		syslog(LOG_ERR, rgb); \
	} \
}

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/file_p.h>
#endif //NO_PROTO

__END_DECLS;

#endif // __SYNO_FILE_H__
