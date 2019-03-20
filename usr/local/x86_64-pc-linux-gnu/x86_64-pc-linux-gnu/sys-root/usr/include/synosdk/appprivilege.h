// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_APPPRIVILEGE_H__
#define __SYNO_APPPRIVILEGE_H__

#include <sys/types.h>
#include <unistd.h>
#include <synocore/synoglobal.h>
#include <synocore/hash.h>
#include <synocore/list.h>
#include <synocore/dlist.h>

__BEGIN_DECLS;

/**
 * @addtogroup APPPRIVILEGE
 *
 * @brief The structure and operation of App Privilege.
 *
 * @{
 */

#define SZ_RULE_FROM_ALL_IP "0.0.0.0"

#define SZ_RULE_IGNORE_IP_CHECK "ignore"

/**
 * This define means all application for admin or SynologyCMS.
 */
#define SZ_SYNO_ALLOW_ALL_APPLICATIONS	"SYNO.ALLOW.ALL.APPLICATIONS"

typedef enum {
	FILTER_ANY,
	FILTER_ALLOW,
	FILTER_DENY,
	FILTER_CUSTOM
} RULE_FILTER_TYPE;

typedef enum {
	RULE_USER,
	RULE_GROUP,
	RULE_EVERYONE
} RULE_TYPE;

typedef struct {
	RULE_TYPE ruleType;
	unsigned int id;
	char *szAppName;
	PSLIBSZLIST pAllowList;
	PSLIBSZLIST pDenyList;
} SYNO_APPPRIV_RULE, *PSYNO_APPPRIV_RULE;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/appprivilege_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif  /* __SYNO_APPPRIVILEGE_H__ */
