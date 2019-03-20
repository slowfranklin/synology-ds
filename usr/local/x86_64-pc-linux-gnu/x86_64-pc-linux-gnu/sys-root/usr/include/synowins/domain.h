// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOWINS_DOMAIN_H__
#define __SYNOWINS_DOMAIN_H__

#include <stdint.h>
#include <synosdk/wins.h>
#include <synosmb.h>

__BEGIN_DECLS;

#define SZ_ADSERVER_SERVICE_NAME	"pkgctl-ActiveDirectoryServer"
#define SZ_ADSERVER_CFG_FILE		"/usr/syno/etc/synoservice.d/pkgctl-ActiveDirectoryServer.cfg"

#define SZ_UPDATE_DOMAIN_COMMAND	"/usr/syno/sbin/synowin -updateDomain"
#define SZF_DOMAIN_USER_FULL_DB		"/usr/syno/etc/private/.db.domain_user_full"
#define SZF_DOMAIN_GROUP_FULL_DB	"/usr/syno/etc/private/.db.domain_group_full"
#define SZF_SYNODCTEST              "/usr/syno/sbin/synodctest"

#define SZ_DB_DOMINFO		"dominfo"

typedef struct _tag_DOMENUMOPTION *PSYNODOMENUMOPTION;

typedef enum _tag_search_type_ {
	ENUM_SUBSTR  = 0x0,
	ENUM_PREFIX  = 0x1,
	ENUM_SUFFIX  = 0x2,
	ENUM_MATCH   = 0x3,
	ENUM_TYPEMAX = 0x4
} SEARCH_TYPE;

#ifndef NO_PROTO
#include "domain_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOWINS_DOMAIN_H__
