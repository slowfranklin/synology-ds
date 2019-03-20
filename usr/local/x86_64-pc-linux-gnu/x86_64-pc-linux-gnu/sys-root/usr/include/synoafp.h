// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_AFPUTIL_H__
#define __SYNO_AFPUTIL_H__

#include <sys/cdefs.h>

#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZF_ATALKD_CONF_PATH		"/usr/syno/etc/atalkd.conf"
#define SZF_DEF_AFPD_CONF_PATH		"/usr/syno/etc.defaults/afpd.conf"
#define SZF_AFPD_CONF_PATH			"/usr/syno/etc/afpd.conf"
#define SZF_AFPD_CONF_PATH_TMP		"/usr/syno/etc/afpd.conf.tmp"
#define SZF_RCATALK_PATH			"/usr/syno/etc/rc.atalk"
#define AFP_DISABLE		0
#define AFP_ENABLE		1
#define     CURRENT_ZONE        0x0001
#define     LOCAL_ZONE          0x0002
#define     DEFAULT_ZONE        0x0004

#define APPLE_TCPIP		0x0001
#define APPLE_ATALK		0x0002
#define SZ_AFP_SERVICE_NAME	"atalk"

typedef struct SYNO_APPLE_ZONE{
	int Type;
	/** The AppleTalk zone name can be up to 32 characters in
	 *  length, and if you add a length byte, each can have a
	 *  maximum size of 33 bytes.  As there can be a maximum of
	 *  254 zones on an extended network, the maximum size of the
	 *  buffer is 8382 bytes.
	 *  
	 *  http://tuvix.apple.com/documentation/mac/NetworkingOT/NetworkingWOT-65.html
	 */
	char szZone[36];
	struct SYNO_APPLE_ZONE *next;
} SYNO_APPLE_ZONE;

#define SZF_AFP_CONF_PATH "/etc/afp.conf"
#define AFP_DISCONNECT_KEY "disconnect time"
#define DISCONNECT_ON_VALUE 0
#define DISCONNECT_OFF_VALUE 48

#ifndef NO_PROTO
#include <availability.h>
#include "synoafp_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_AFPUTIL_H__
