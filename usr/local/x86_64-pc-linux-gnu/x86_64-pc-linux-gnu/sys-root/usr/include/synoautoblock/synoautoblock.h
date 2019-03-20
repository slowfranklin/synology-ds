// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNOAUTOBLOCK_H__
#define __SYNOAUTOBLOCK_H__

#include <netinet/in.h>
#include <sys/cdefs.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <time.h>

#include <synocore/error.h>
#include <synocore/list.h>
#include <synosdk/autoblock.h>

__BEGIN_DECLS;

#define SYNO_AUTOBLOCK_ALLOW 0
#define SYNO_AUTOBLOCK_DENY 1
#define SYNO_AUTOBLOCK_NOT_EXIST 2

#define SZF_SYNOAUTOBLOCK_HELPER "/usr/syno/bin/synoautoblock"
#define SZD_SYNOAUTOBLOCK_HELPER_DENY "--deny"
#define SZD_SYNOAUTOBLOCK_HELPER_ATTEMPT "--attempt"
#define SZD_SYNOAUTOBLOCK_HELPER_RESET "--reset"
#define SZD_SYNOAUTOBLOCK_HELPER_IN_WHITE_LIST "--in-white-list"

#define SZK_AUTOBLOCK_ATTEMPTS		"autoblock_attempts"
#define SZK_AUTOBLOCK_ATTEMPT_MIN	"autoblock_attempt_min"
#define SZK_AUTOBLOCK_EXPIRED_DAY	"autoblock_expriedday"

typedef struct __tag_AUTOBLOCK_CONF_{
	int attempts;
	int attemptmin;
	int expiredday;
} AUTOBLOCKCONF, *PAUTOBLOCKCONF;

typedef struct _tag_SYNO_AUTOBLOCK_IP_INFO{
	time_t recordtime;
	time_t expiretime;
	char szIP[CB_SZ_IPv6];
	int ipType;
	char szMeta[256];
}SYNO_AUTOBLOCK_IP_INFO, *PSYNO_AUTOBLOCK_IP_INFO;

typedef enum __tag_SYNO_AUTOBLOCKIP_COLUMN {
	COLUMN_IP = 0,
	COLUMN_RECORDTIME = 1,
	COLUMN_EXPIRETIME = 2,
	COLUMN_DENY = 3,
	COLUMN_IPStd = 4,
	COLUME_IPType = 5,
	COLUME_META = 6,
	COLUMN_NONE
} SYNO_AUTOBLOCKIP_COLUMN;

typedef enum __tag_SYNO_AUTOBLOCK_IPTYPE {
	IPTYPE_SINGLEHOST = 0,
	IPTYPE_DOMAIN = 1,
	IPTYPE_IPRANGE = 2,
	IPTYPE_SUBNET = 3,
	IPTYPE_NONE
} SYNO_AUTOBLOCK_IPTYPE;

typedef enum __tag_SYNOAUTOBLOCK_ORDER {
	ORDER_ASC,
	ORDER_DESC,
	ORDER_NONE
} SYNOAUTOBLOCK_ORDER;

#ifndef NO_PROTO
#include <synoautoblock/synoautoblock_api.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_AUTOBLOCK_H__
