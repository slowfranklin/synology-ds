// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_BROWSER_H__
#define __SYNOLDAP_BROWSER_H__

#include <sys/cdefs.h>
#include <sys/types.h>
#include <availability.h>
#include <synocore/list.h>
#include <synosdk/group.h>
#include <synosdk/user.h>
#include <synosdk/ldap.h>

__BEGIN_DECLS;

/**
 * @addtogroup browser
 *
 * @brief APIs to get information about LDAP server/user/group according to
 *        some standards, e.g. RFC 2307.
 *
 * Most APIs presume target LDAP server follow RFC 2307, i.e. take entries with
 * `posixAccount` as users, `uid` as user name, `uidNumber` as numeric uid etc.
 *
 * Some APIs accept `PSYNOLDAP_SEARCH_OPTION` as parameter by which caller can
 * specify their own filter and mapping appropriate for target LDAP servers.
 *
 * @{
 */

typedef struct __tag__LDAP_HOST LDAP_HOST;
typedef struct __tag__LDAP_SEARCH_REQUEST LDAP_SEARCH_REQUEST;
typedef struct __tag__LDAP_RESULT LDAP_RESULT;

/**
 * @brief Initialize @p pRequest for enumerate LDAP users, follow RFC 2307.
 *
 * @note __DO NOT__ initialize @p pRequest yourself before calling
 *       this function, or you may get memory leak.
 *
 * @param[out] pRequest  Request handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumRequestInit(LDAP_SEARCH_REQUEST *pRequest);

/**
 * @brief Initialize @p pRequest for enumerate LDAP groups, follow RFC 2307.
 *
 * @note __DO NOT__ initialize @p pRequest yourself before calling
 *       this function, or you may get memory leak.
 *
 * @param[out] pRequest  Request handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGroupEnumRequestInit(LDAP_SEARCH_REQUEST *pRequest);

/**
 * @brief Enumerate possible base DN (i.e. `namingContexts`) of given @p pHost.
 *
 * @note This search is performed as anonymous, in RootDSE of @p pHost.
 *
 * @param[in]  pHost         Host handle, must not be NULL.
 * @param[out] pplistBaseDN  Result base DN list, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserSuggestBaseDN(const LDAP_HOST *pHost, PSLIBSZLIST *pplistBaseDN);

/**
 * @brief Get belonging groups of @p szUserDN, follow RFC 2307.
 *
 * @param[in]  pHost            Host handle, must not be NULL.
 * @param[in]  szUserDN         User DN, must not be NULL.
 * @param[out] ppGroupDNList    Result group DN list, NULL is ignored.
 * @param[out] ppGroupNameList  Result group name list, NULL is ignored.
 *
 * @return Number of belonging groups, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_USER
 * @exception SYNOLDAPPosixGetUserUID()
 * @exception SYNOLDAPBrowserGroupEnumByUserUID()
 *
 * @sa SYNOLDAPBrowserGroupEnumByUserUID()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGroupEnumByUserDN(const LDAP_HOST *pHost, const char *szUserDN, PSLIBSZLIST *ppGroupDNList, PSLIBSZLIST *ppGroupNameList);

/**
 * @brief Get belonging groups of @p szUserUID, follow RFC 2307.
 *
 * @note This function doesn't check whether @p szUserUID exists or not.
 *
 * @param[in]  pHost            Host handle, must not be NULL.
 * @param[in]  szUserUID        User UID, must not be NULL.
 * @param[out] ppGroupDNList    Result group DN list, NULL is ignored.
 * @param[out] ppGroupNameList  Result group name list, NULL is ignored.
 *
 * @return Number of belonging groups, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGroupEnumByUserUID(const LDAP_HOST *pHost, const char *szUserUID, PSLIBSZLIST *ppGroupDNList, PSLIBSZLIST *ppGroupNameList);

/**
 * @brief Enumerate users whose primary group is @p szGroupDN / @p szGroupCN,
 *        follow RFC 2307.
 *
 * If @p szGroupDN is specified then it uses gid of @p szGroupDN; otherwise it
 * users gid of @p szGroupCN.
 *
 * @deprecated Not used by DSM, kept for compatibility for old Directory Server.
 *
 * @param[in]  pHost          Host handle, must not be NULL.
 * @param[in]  szGroupDN      Group DN, must not be NULL if @p szGroupCN is NULL.
 * @param[in]  szGroupCN      Group CN, must not be NULL if @p szGroupDN is NULL.
 * @param[out] ppUserUIDList  Result user UID list, must not be NULL.
 *
 * @return Number of users, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchGetValueByDN()
 * @exception SYNOLDAPSearchEachValue()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumByPrimaryGroup(const LDAP_HOST *pHost, const char *szGroupDN, const char *szGroupCN, PSLIBSZLIST *ppUserUIDList);

/**
 * @brief Enumerate members of @p szGroupDN, follow RFC 2307.
 *
 * @param[in]  pHost          Host handle, must not be NULL.
 * @param[in]  szGroupDN      Group DN, must not be NULL.
 * @param]out] ppUserUIDList  Result user UID list, must not be NULL.
 *
 * @return Number of members. -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_GROUP
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 * @exception SYNOLDAPResultGetAll()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumByGroupDN(const LDAP_HOST *pHost, const char *szGroupDN, PSLIBSZLIST *ppUserUIDList);

/**
 * @brief Enumerate users which are not members of @p szGroupDN, follow RFC 2307.
 *
 * @deprecated Not used by DSM, kept for compatibility for old Directory Server.
 *
 * @param[in]  pHost          Host handle, must not be NULL.
 * @param[in]  szGroupDN      Group DN, must not be NULL.
 * @param[out] ppUserUIDList  Result user UID list, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPBrowserUserEnumAll()
 * @exception SYNOLDAPBrowserUserEnumByGroupDN()
 * @exception SYNOLDAPBrowserUserEnumByPrimaryGroup()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumNotInGroupDN(const LDAP_HOST *pHost, const char *szGroupDN, PSLIBSZLIST *ppUserUIDList);

/**
 * @brief Get DN of first entry which matches @p szFilter on given @p pHost.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  szFilter  Search filter, must not be NULL.
 * @param[out] szDN      Result first DN, NULL is ignored.
 * @param[in]  cbDN      Size of @p szDN, 0 is ignored.
 *
 * @return Number of matched entries, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGetFirstDN(const LDAP_HOST *pHost, const char *szFilter, char *szDN, size_t cbDN);

/**
 * @brief Get DN of user @p szUserUID, with customized filter and mapping via
 *        @p pOption.
 *
 * @param[in]  pHost      Host handle, must not be NULL.
 * @param[in]  szUserUID  User UID, must not be NULL.
 * @param[out] szUserDN   Result user DN, NULL is ignored.
 * @param[in]  cbUserDN   Size of @p szUserUID, 0 is ignored.
 * @param[in]  pOption    Custom filter and mapping, follow RFC 2307 if NULL.
 *
 * @retval >1 @p szUserUID is ambiguous.
 * @retval  1 Success.
 * @retval  0 No such user.
 * @retval -1 Error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPBrowserGetFirstDN()
 *
 * @sa SYNOLDAPSearchOptionGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOLDAPBrowserGetDNByUserUIDEx(const LDAP_HOST *pHost, const char *szUserUID, char *szUserDN, size_t cbUserDN, const PSYNOLDAP_SEARCH_OPTION pOption);

/**
 * @brief Get DN of user @p szUserUID, follow RFC 2307.
 *
 * @param[in]  pHost      Host handle, must not be NULL.
 * @param[in]  szUserUID  User UID, must not be NULL.
 * @param[out] szUserDN   Result user DN, NULL is ignored.
 * @param[in]  cbUserDN   Size of @p szUserUID, 0 is ignored.
 *
 * @retval >1 @p szUserUID is ambiguous.
 * @retval  1 Success.
 * @retval  0 No such user.
 * @retval -1 Error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPBrowserGetDNByUserUIDEx()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGetDNByUserUID(const LDAP_HOST *pHost, const char *szUserUID, char *szUserDN, size_t cbUserDN);

/**
 * @brief Get DN of group @p szGroupCN, follow RFC 2307.
 *
 * @param[in]  pHost       Host handle, must not be NULL.
 * @param[in]  szGroupCN   Group CN, must not be NULL.
 * @param[out] szGroupDN   Result group DN, NULL is ignored.
 * @param[in]  cbGroupDN   Size of @p szGroupUID, 0 is ignored.
 *
 * @retval >1 @p szGroupCN is ambiguous.
 * @retval  1 Success.
 * @retval  0 No such user.
 * @retval -1 Error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPBrowserGetFirstDN()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGetDNByGroupCN(const LDAP_HOST *pHost, const char *szGroupCN, char *szGroupDN, size_t cbGroupDN);

/**
 * @brief Get information about @p szUserDN from @p pHost. All retrieved
 *        attributes are stored in @p pResult if it's not NULL.
 *
 * @note The information is only for LDAP browsing, please use @a SYNOUserGet()
 *       to get user information instead.
 *
 * @param[in]  pHost             Host handle, must not be NULL.
 * @param[in]  szUserDN          User DN, must not be NULL.
 * @param[out] ppUser            Result user handle, NULL is ignored.
 * @param[in]  szPassword        Value of `userPassword`, NULL is ignored.
 * @param[in]  cbPassword        Size of @p szPassword, 0 is ignored.
 * @param[in]  plExpiryDay       Value of `shadowExpire`, NULL is ignored.
 * @param[in]  pAllowChPassword  Allowed to change password or not, NULL is ignored.
 * @param[out] pResult           Search result, NULL is ignored.
 * @param[in]  pOption           Custom filter and mapping, follow RFC 2307 if NULL.
 *
 * @retval  1 Success.
 * @retval  0 No such user.
 * @retval -1 Error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 * @exception SYNOLDAPResultClone()
 *
 * @sa SYNOLDAPSearchOptionGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOLDAPBrowserUserGetEx(const LDAP_HOST *pHost, const char *szUserDN, PSYNOUSER *ppUser, char *szPassword, size_t cbPassword, long *plExpiryDay, SYNOALLOWCHPASSWORD *pAllowChPassword, LDAP_RESULT *pResult, const PSYNOLDAP_SEARCH_OPTION pOption);

/**
 * @breif Get information about @p szUserDN from @p pHost, follow RFC 2307.
 *        All retrieved attributes are stored in @p pResult if it's not NULL.
 *
 * @note The information is only for LDAP browsing, please use @a SYNOUserGet()
 *       to get user information instead.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  szUserDN  User DN, must not be NULL.
 * @param[out] ppUser    Result user handle, NULL is ignored.
 * @param[out] pResult   Search result, NULL is ignored.
 *
 * @retval  1 Success.
 * @retval  0 No such user.
 * @retval -1 Error.
 *
 * @exception SYNOLDAPBrowserUserGetEx()
 *
 * @sa SYNOLDAPBrowserUserGetEx()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserGet(const LDAP_HOST *pHost, const char *szUserDN, PSYNOUSER *ppUser, LDAP_RESULT *pResult);

/**
 * @brief Get information about @p szGroupDN from @p pHost, follow RFC 2307.
 *
 * @note The information is only for LDAP browsing, please use @a SYNOGroupGet()
 *       to get group information instead.
 *
 * @param[in]  pHost      Host handle, must not be NULL.
 * @param[in]  szGroupDN  Group DN, must not be NULL.
 * @param[out] ppGroup    Result user handle, must not be NULL.
 * @param[out] szDesc     Description, must not be NULL.
 * @param[in]  cbDesc     Size of @p szDesc, must >0.
 *
 * @retval  1 Success.
 * @retval  0 No such group.
 * @retval -1 Error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 * @exception SYNOLDAPResultGetFirst()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGroupGet(const LDAP_HOST *pHost, const char *szGroupDN, PSYNOGROUP *ppGroup, char *szDesc, size_t cbDesc);

/**
 * @brief Enumerate groups with given @p gid, follow RFC 2307.
 *
 * @param[in]  pHost          Host handle, must not be NULL.
 * @param[in]  gid            Numeric gid.
 * @param[out] ppGroupDNList  Result group DN list, NULL is ignored.
 *
 * @return Number of matched groups, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserGroupEnumByGIDNumber(const LDAP_HOST *pHost, gid_t gid, PSLIBSZLIST *ppGroupDNList);

/**
 * @brief Enumerate users with given @p uid, follow RFC 2307.
 *
 * @param[in]  pHost         Host handle, must not be NULL.
 * @param[in]  uid           Numeric uid.
 * @param[out] ppUserDNList  Result group DN list, NULL is ignored.
 *
 * @return Number of matched users, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumByUIDNumber(const LDAP_HOST *pHost, uid_t uid, PSLIBSZLIST *ppUserDNList);

/**
 * @brief Enumerate users on @p pHost, follow RFC 2307
 *
 * @param[in]  pHost          Host handle, must not be NULL.
 * @param[out] ppUserDNList   Result user DN list, NULL is ignored.
 * @param[out] ppUserUIDList  Result user UID list, NULL is ignored.
 *
 * @return Number of users, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserUserEnumAll(const LDAP_HOST *pHost, PSLIBSZLIST *ppUserDNList, PSLIBSZLIST *ppUserUIDList);

/**
 * @brief Get server type then fill @p pHost->serverType, presume
 *        `LDAP_SERVER_POSIX` if this function can't check it.
 *
 * @param[in,out] pHost  Host handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBrowserCheckServerType(LDAP_HOST *pHost);

/**
 * @brief Get user name of @p szUserDN, follow RFC 2307.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  szUserDN  User DN, must not be NULL.
 * @param[out] szUID     Result user UID, must not be NULL.
 * @param[in]  cbUID     Size of @p szUID, must >0.
 *
 * @retval  1 Success.
 * @retval  0 User not found.
 * @retval -1 Error.
 *
 * @exception SYNOLDAPSearchGetValueByDN()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPPosixGetUserUID(const LDAP_HOST *pHost, const char *szUserDN, char *szUID, size_t cbUID);

/**
 * @brief Get group name of @p szGroupDN, follow RFC 2307.
 *
 * @param[in]  pHost      Host handle, must not be NULL.
 * @param[in]  szGroupCN  Group DN, must not be NULL.
 * @param[out] szCN       Result group CN, must not be NULL.
 * @param[in]  cbCN       Size of @p szCN, must >0.
 *
 * @retval  1 Success.
 * @retval  0 group not found.
 * @retval -1 Error.
 *
 * @exception SYNOLDAPSearchGetValueByDN()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPPosixGetGroupCN(const LDAP_HOST *pHost, const char *szGroupDN, char *szCN, size_t cbCN);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_BROWSER_H__
// vim:ts=4 sts=4 sw=4
