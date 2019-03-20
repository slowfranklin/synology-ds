// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_GROUP_H__
#define __SYNO_GROUP_H__

#include <grp.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/bdb.h>
#include <synocore/error.h>
#include <synocore/hash.h>
#include <synocore/list.h>
#include <synosdk/appprivilege.h>

__BEGIN_DECLS;

/**
 * @addtogroup GROUP
 *
 * @brief Some basic structure and operation of Group. More features in libsynolocalaccount.
 *
 * @{
 */

/**
 * The prefix string that is group identifer.
 * @see ::SIZEOF_GROUP_PREFIX
 */
#define SZ_GROUP_PREFIX	"@"

/**
 * The string length of ::SZ_GROUP_PREFIX.
 * @see ::SZ_GROUP_PREFIX
 */
#define SIZEOF_GROUP_PREFIX (sizeof(SZ_GROUP_PREFIX)-1)
/**
 * The default group of all local users.
 */
#define SZ_DEFGRP		"users"

#define SZ_HTTPGRP		"http"

/**
 * The default admin group of local admin users.
 */
#define SZ_ADMINGRP		"administrators"

/**
 * The default domain admin groups.
 */
#define SZ_DOMAIN_ADMINS "Domain Admins"
#define SZ_ENTERPRISE_ADMINS "Enterprise Admins"
#define SZ_DOMAIN_ADMINS_RID "512"
#define SZ_DOMAIN_USERS_RID "513"
#define SZ_ENTERPRISE_ADMINS_RID "519"
#define SZK_SMB_ADMIN_USERS	"admin users"

/**
 * The group those users can run netbkp.
 */
#define SZ_NETBKP_GROUP		"smmsp"

/**
 * The gid that indicates error.  Note that (-1 == (gid_t)-1)
 * but ( 0 < (gid_t) -1 )
 */
#define GID_ERR ((gid_t) -1)

/**
 * The root group id.
 */
#define GID_ROOT		0

/**
 * The group id of users group.
 */
#define GID_USERS		100

/**
 * The group id of local admin group.
 */
#define GID_ADMIN		101

/**
 * The gid of smmsp group. For netbkp
 */
#define GID_SMMSP		25

/**
 * The gid of http
 */
#define GID_HTTP 1023

/**
 * The maximum length in bytes of SYNOGROUP::szName.
 */
#define SYNO_GROUPNAME_UTF8_MAX         256

/**
 * The maximum length in Unicode characters of SYNOGROUP::szName.
 */
#define SYNO_GROUPNAME_UTF32_MAX        32

/**
 * The maximum length in bytes of group descrption.
 */
#define SYNO_GROUPDESC_UTF8_MAX         492

/**
 * The maximum length in Unicode characters of group descrption.
 */
#define SYNO_GROUPDESC_UTF32_MAX        64

/**
 * The format items of a line in SZF_GROUP:
 * `name:passwd:gid:members`
 */
#define SZK_GRP_ALLITEMS	4

/**
 * The path of file that contains descrptions of groups.
 */
#define SZF_GROUP_DESC		"/etc/group_desc"

/**
 * The path of local groups.
 */
#define SZF_GROUP		"/etc/group"
#define SZF_DEF_GROUP		"/etc.defaults/group"

/**
 * Extra admin categories.
 */
#define SZ_EXTRA_ADMIN_CMS	"CMS"

/**
 * The group information.
 *
 * @struct SYNOGROUP group.h <synosdk/group.h>
 * @dotfile synogroup.dot
 */
typedef struct {
	/**
	 * The UTF-8 string pointer to the position of group name. The
	 * maximum length of this string is ::SYNO_GROUPNAME_UTF32_MAX
	 * in Unicode characters or ::SYNO_GROUPNAME_UTF8_MAX in bytes.
	 * Should not be NULL.
	 */
	char *szName;
	gid_t nGid;
	char **rgszMem;
	/**
	 * This group is local group or domain group.  The valild value
	 * are AUTH_TYPE::AUTH_LOCAL and
	 * AUTH_TYPE::AUTH_DOMAIN.
	 */
	AUTH_TYPE authType;
	size_t nAlloc;
} SYNOGROUP, *PSYNOGROUP;

/**
 * Init the SYNOGROUP @a pGroup to all default values.
 *
 * @param pGroup	[OUT] The pointer to a SYNOGROUP, should not be NULL.
 */
static inline void
SYNOGroupInit(PSYNOGROUP pGroup)
{
	if (NULL == pGroup) {
		return;
	}
	bzero(pGroup, sizeof(SYNOGROUP));
	pGroup->nGid = GID_ERR;
}

#ifdef SYNOSDK_LOCAL_ACCOUNT

/**
 * Group DB handle.
 * Only libsynolocalaccount is allowed to use it.
 * We prevent others to use it by the flag SYNOSDK_LOCAL_ACCOUNT.
 */
typedef struct {
	PSYNOBDB pGRPName;
	PSYNOBDB pGRPGID;
	PSYNOBDB pGRPDesc;
} SYNOGROUPDB, *PSYNOGROUPDB;

#define INTERNAL_GID_MIN	100000
#define INTERNAL_GID_MAX	999999

#define SZK_CURRENT_GID		SYNO_BDB_SZK_PREFIX"CURRENT_GID"

#define SZK_EXTRA_LOCAL_UID	"local_uid"
#define SZK_EXTRA_LOCAL_GID	"local_gid"
#define SZK_EXTRA_DIRECTORY_UID	"directory_uid"
#define SZK_EXTRA_DIRECTORY_GID	"directory_gid"
#define SZ_EXTRA_CONF_PREFIX	"/usr/syno/etc/extra-admin-"

#define SZF_ADMINGRP_CACHE	"/tmp/current.admins"

#endif // SYNOSDK_LOCAL_ACCOUNT

/**
 * Callback function for SLIBGroupInfoEnum APIs.
 *
 * - @a PSYNOGROUP contains all info of a local group. For non-local group, it contains only info stored in local DB/cache.
 *   Use SYNOGroupGet() to get detailed info, for non-local group only.
 * - @a int is the index of @a PSYNOGROUP that matches the conditions (string-matching, paging) of SLIBGroupInfoEnum APIs.
 * - Last pointer can carry anything the caller wants, SLIBGroupInfoEnum APIs will pass it intactly to the callback function.
 *
 * Keep you own copy of @a PSYNOGROUP in callback function if necessary, this won't be available after callback function returns.
 *
 * @retval 0 Continue enumeration process.
 * @retval <0 Interrupt enumeration process.
 */
typedef int (*GroupEnumCallback)(const PSYNOGROUP, int, void *);

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/group_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif  /* __SYNO_GROUP_H__ */
