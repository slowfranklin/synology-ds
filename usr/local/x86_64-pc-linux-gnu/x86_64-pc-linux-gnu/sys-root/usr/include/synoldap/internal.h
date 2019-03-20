// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_INTERNAL_H__
#define __SYNOLDAP_INTERNAL_H__

#include <sys/cdefs.h>
#include <sys/types.h>
#include <availability.h>

__BEGIN_DECLS;

/**
 * @addtogroup internal
 *
 * @brief Internal APIs for nslcd and synoldapclientd, __DO NOT__ use them.
 *
 * Some LDAP server doesn't follow RFC 2307 and doesn't provide numeric
 * attributes as uid and gid for clients. Here we provide a hash mechanism
 * to help mapping string (e.g. UUID) to numeric uid or gid, most applications
 * don't have to be aware of this.
 *
 * @{
 */

#ifndef __SYNOLDAP_INTERNAL_ONLY
/**
 * @brief Define this as empty before `#include <synoldap/internal.h>`
 *        if you're allowed to use these APIs.
 */
#define __SYNOLDAP_INTERNAL_ONLY __attribute__((error("LDAP client only")))
#endif

/**
 * @brief Get numeric uid from @p szRealUid.
 *
 * @param[in] szRealUid  Real unique user identity.
 *
 * @return Result uid or 0 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
uid_t SYNONslcdResolveUidNumber(const char* szRealUid) __SYNOLDAP_INTERNAL_ONLY;

/**
 * @brief Get numeric gid from @p szRealGid.
 *
 * @param[in] szRealGid  Real unique group identity.
 *
 * @return Result gid or 0 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
gid_t SYNONslcdResolveGidNumber(const char* szRealGid) __SYNOLDAP_INTERNAL_ONLY;

/**
 * @brief Get @p szRealUid from numeric @p uid.
 *
 * @param[in]  uid        Numeric uid to search.
 * @param[out] szRealUid  Real unique user identity.
 * @param[in]  cbRealUid  Size of @p szRealUid.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
int SYNONslcdResolveRealUid(uid_t uid, char *szRealUid, size_t cbRealUid) __SYNOLDAP_INTERNAL_ONLY;

/**
 * @brief Get @p szRealGid from numeric @p gid.
 *
 * @param[in]  gid        Numeric gid to search.
 * @param[out] szRealGid  Real unique group identity.
 * @param[in]  cbRealGid  Size of @p szRealGid.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
int SYNONslcdResolveRealGid(gid_t gid, char *szRealGid, size_t cbRealGid) __SYNOLDAP_INTERNAL_ONLY;

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_INTERNAL_H__
// vim:ts=4 sts=4 sw=4
