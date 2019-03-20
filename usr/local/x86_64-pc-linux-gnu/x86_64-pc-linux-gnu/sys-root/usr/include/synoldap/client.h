// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_CLIENT_H__
#define __SYNOLDAP_CLIENT_H__

#include <sys/cdefs.h>
#include <availability.h>
#include <synocore/hash.h>
#include <synosdk/ldap.h>

__BEGIN_DECLS;

/**
 * @addtogroup client
 *
 * @brief LDAP client APIs.
 *
 * @{
 */

typedef struct __tag__LDAP_HOST LDAP_HOST;

#define UID_LDAP_MIN   1000000
#define GID_LDAP_MIN   1000000
#define UID_LDAP_MAX   2097151
#define GID_LDAP_MAX   2097151

#define SZF_LDAP_CONF    "/usr/syno/etc/synoldap.conf"
#define SZK_UPDATE_MIN   "update_min"
#define DEFAULT_LDAP_CLIENT_UPDATE_MIN   5

/**
 * @brief Initialize @p pHost by nslcd.conf then run ldapsearch to check
 *        server type and supported schema.
 *
 * @param[out] pHost  Host handle, must not be NULL.
 *
 * @retval  1  On success.
 * @retval  0  Initialize @p pHost OK, but ldapsearch failed.
 * @retval -1  On error, config not found.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAP_ERR_SERVER_NOT_SUPPORT
 * @exception SYNOLDAPInfoGetFromConf()
 * @exception SYNOLDAPSSLGetByBindConfig()
 * @exception SYNOLDAPSecretGet()
 * @exception SYNOLDAPBrowserCheckServerType()
 * @exception SYNOLDAPHostGetSupportedSchema()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostInitByBindConfig(LDAP_HOST *pHost);

/**
 * @brief Bind to LDAP server.
 *
 * @note Use standard ports, i.e. 398 for ldap:// and 636 for ldaps://, custom
 *       port is not supported. Protocol (ldap:// or ldaps://) is decided by
 *       @p szSSL, do not prepend protocol to @p szHost.
 *
 * Bind as anonymous if both @p szBindDN and @p szPassword are NULL.
 *
 * The steps are:
 * 1. Unbind first if it's curretly binded to another LDAP server.
 * 2. Configure `nslcd.conf` and save password in @a SZF_LDAP_SECRET.
 * 3. Update `/etc/nsswitch.conf`.
 * 4. Start nslcd, sleep 2 seconds then check LDAP server is binded.
 *
 * @param[in] szSSL       SSL type, must be one of `SZ_SSL_NO`, `SZ_SSL_YES`,
 *                        `SZ_SSL_START_TLS`. Others are taken as `SZ_SSL_NO`.
 * @param[in] szHost      Server URI, must not be NULL.
 * @param[in] szBaseDN    Base DN, must not be NULL.
 * @param[in] szBindDN    Bind DN.
 * @param[in] szPassword  Bind password of @p szBindDN.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_NOT_SET
 * @exception SYNOLDAPDomainName()
 * @exception SYNOLDAPDNDomainName()
 * @exception SYNOLDAPConfSet()
 * @exception SYNOLDAPNslcdConfSetOne()
 * @exception SYNOLDAPModuleSet()
 * @exception SYNOLDAPSecretSet()
 *
 * @sa LDAP_HOST
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPBind(const char *szSSL, const char *szHost, const char *szBaseDN, const char *szBindDN, const char *szPassword);

/**
 * @brief Save @p szPassword in @a SZF_LDAP_SECRET.
 *
 * @param[in] szPassword  Plaintext password, NULL to unlink @a SZF_LDAP_SECRET.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_OP_FAILURE
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSecretSet(const char *szPassword);

/**
 * @brief Reset related configs and stop nslcd. This function is for internal
 *        use, __DO NOT__ call it.
 *
 * Related configs are `/etc/nsswitch.conf`, `/etc/samba/smb.conf` and
 * user/group DB.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_SERVICE_NOT_SET
 * @exception SYNOLDAPModuleSet()
 * @exception SYNOLDAPSetSMBSupportDisable()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPResetConfig(void);

/**
 * @brief Unbind from LDAP server.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SYNOLDAPResetConfig()
 *
 * @sa SYNOLDAPResetConfig()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPUnBind(void);

/**
 * @brief Modify settings in `/etc/nsswitch.conf` to enable or disable LDAP.
 *
 * @note If @p blEnabled is TRUE, both "ldap" and "winbind" are added to
 *       nsswitch.conf with "ldap" prior to "winbind".
 *
 * @param[in] blEnabled  Whether enable LDAP or not.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SYNOLDAPNssSet()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPModuleSet(BOOL blEnabled);

/**
 * @brief Refresh LDAP groups in group DB.
 *
 * @deprecated Since DSM 6.1, it's done by synoldapclientd periodically.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SLIBLdapRefreshGroup();

/**
 * @brief Refresh LDAP users in user DB.
 *
 * @deprecated Since DSM 6.1, it's done by synoldapclientd periodically.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SLIBLdapRefreshUser();

/**
 * @brief Get profile, filter and mappings, from @p szFile and store result in
 *        @p ppshFilter and @p ppshMap.
 *
 * Lines in @p szFile follows the format of nslcd.conf and will be converted to
 * key-value pairs according to following rules (empty values means use default
 * of nslcd):
 *
 * "filter passwd (objectClass=somePerson)" => key="passwd", value="objectClass=somePerson".
 * "map passwd uidNumber someUid" => key="passwd uidNumber", value="someUid".
 *
 * @param[in]  szFile      File to read, must not be NULL.
 * @param[out] ppshFilter  Result filters, must not be NULL.
 * @param[out] ppshMap     Result maps, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCStrTok()
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPNslcdProfileGet(const char *szFile, PSLIBSZHASH *ppshFilter, PSLIBSZHASH *ppshMap);

/**
 * @brief Write key-value pairs in @p pshFilter and @p pshMap to @p szFile
 *        in the format of nslcd.conf.
 *
 * @note For backward compatibility, legacy filters without surrounding
 *       parenthesis are accepted.
 *
 * @param[in] szFile      File to write, must not be NULL.
 * @param[in] ppshFilter  Filters, must not be NULL.
 * @param[in] ppshMap     Maps, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception SLIBCFileSetKeys()
 *
 * @sa SYNOLDAPNslcdProfileGet().
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPNslcdProfileSet(const char *szFile, const PSLIBSZHASH pshFilter, const PSLIBSZHASH pshMap);

/**
 * @brief Allocate `PSYNOLDAP_SEARCH_OPTION` with all members NULL.
 *
 * @return Allocated result or NULL on error.
 *
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOLDAP_SEARCH_OPTION SYNOLDAPSearchOptionAlloc(void);

/**
 * @brief Free space of @p pOption.
 *
 * @param[in] pOption  `PSYNOLDAP_SEARCH_OPTION` to free, NULL is ignored.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOLDAPSearchOptionFree(const PSYNOLDAP_SEARCH_OPTION pOption);

/**
 * @brief Get options for ldapsearch command according to current nslcd.conf.
 *        Use nslcd's default, i.e. follow RFC 2307, if not given.
 *
 * @param[out] pOption  Result search options, must not be NULL.
 * @param[in]  iType    0 means user, else means group.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPNslcdProfileGet()
 *
 * @sa SYNOLDAPNslcdProfileGet().
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSearchOptionGet(PSYNOLDAP_SEARCH_OPTION pOption, int iType);

/**
 * @brief Configure `/etc/samba/smb.conf` to enable CIFS support for LDAP users.
 *        Use PAM instead of NTLM authenticaion, hence plaintext password is
 *        required.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SLIBCFileLock()
 * @exception SLIBCFileGetSection()
 * @exception SLIBCFileSetSection()
 *
 * @sa SYNOLDAPSetSMBSupportLdapsam()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSetSMBSupportPAM(void);

/**
 * @brief Configure `/etc/samba/smb.conf` to disable CIFS support for LDAP users.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SLIBCFileLock()
 * @exception SLIBCFileGetSection()
 * @exception SLIBCFileSetSection()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSetSMBSupportDisable(void);

/**
 * @brief Configure `/etc/samba/smb.conf` to enable CIFS support for LDAP users.
 *        Use multisam to avoid tranmission of plaintext passwords.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SLIBCFileLock()
 * @exception SLIBCFileGetSection()
 * @exception SLIBCFileSetSection()
 * @exception SYNOLDAPInfoGetFromConf()
 * @exception SYNOLDAPSecretGet()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSetSMBSupportLdapsam(void);

/**
 * @brief Get CIFS support types.
 *
 * @return One of `LDAP_SMB_NONE`, `LDAP_SMB_PAM`, `LDAP_SMB_LDAPSAM`.
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) LDAP_SMB_TYPE SYNOLDAPIsSMBSupportEnable(void);

/**
 * @brief Create temporary file by copy @p szConfFile to @p szConfTmp.
 *
 * If @p szConfFile doesn't exist, copy @p szDefault instead or simply touch an
 * empty file when @p szDefault is NULL or the copy failed.
 *
 * @param[in]  szConfFile  File to update, must not be NULL.
 * @param[in]  szDefault   Template file to use, NULL.
 * @param[out] szConfTmp   Result temporary file, must not be NULL.
 * @param[in]  cbConfTmp   Size of @p szConfTmp, must >0
 *
 * @return Always 0.
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPGenTmpConf(const char *szConfFile, const char *szDefault, char *szConfTmp, size_t cbConfTmp);

/**
 * @brief Update key-value pairs in @p szConfFile with given @p pHash.
 *
 * @param[in] szConfFile  File to update, must not be NULL.
 * @param[in] szDefault   Template file to use is @p szConfFile doesn't exist.
 *                        NULL is ignored.
 * @param[in] pHash       Key-value pairs, must not be NULL or empty.
 * @param[in] blRemove    TRUE to remove @p szKey.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_RENAME_FAILED
 *
 * @sa SYNOLDAPGenTmpConf()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPConfSet(const char *szConfFile, const char *szDefault, const PSLIBSZHASH pHash, BOOL blRemove);

/**
 * @brief Update @p szKey with @p szVal in @p szConfFile.
 *
 * @param[in] szConfFile  File to update, must not be NULL.
 * @param[in] szDefault   Template file to use is @p szConfFile doesn't exist.
 *                        NULL is ignored.
 * @param[in] szKey       Key, must not be NULL.
 * @param[in] szVal       Value, must not be NULL.
 * @param[in] blRemove    TRUE to remove @p szKey.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPConfSet()
 *
 * @sa SYNOLDAPGenTmpConf(), SYNOLDAPConfSet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPConfSetOne(const char *szConfFile, const char *szDefault, const char *szKey, const char *szVal, BOOL blRemove);

/**
 * @brief Update @p szKey with @p szVal in `nslcd.conf`.
 *
 * @param[in] szKey     Key, must not be NULL.
 * @param[in] szVal     Value, must not be NULL.
 * @param[in] blRemove  TRUE to remove @p szKey.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception SYNOLDAPGenTmpConf(), SYNOLDAPConfSetOne()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPNslcdConfSetOne(const char *szKey, const char *szVal, BOOL blRemove);

/**
 * @brief Get @a LDAP_SSL_TYPE from nslcd.conf.
 *
 * @return Result @a LDAP_SSL_TYPE
 *
 * @exception SYNOLDAPInfoGetFromConf()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) LDAP_SSL_TYPE SYNOLDAPSSLTypeGetFromNslcd(void);

/**
 * @brief Set @p pHost->sslType according to nslcd.conf.
 *
 * @param[in,out] pHost  LDAP host handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPInfoGetFromConf()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSSLGetByBindConfig(LDAP_HOST *pHost);

/**
 * @brief Check @a pHost by enumerate users, follow RFC 2307.
 *
 * This function checks the "ability" to enumerate user, not existence of users.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPPosixCheckEnumUser(const LDAP_HOST *pHost);

/**
 * @brief Check bind informations for LDAP client.
 *
 * Check by enumrate users via @a SYNOLDAPPosixCheckEnumUser().
 *
 * @param[in] pHost  Host handle, check currently joined LDAP server if NULL.
 *
 * @return 0 on succes, -1 check failed.
 *
 * @exception SYNOLDAP_ERR_SERVER_NOT_SUPPORT
 * @exception SYNOLDAPHostInitByBindConfig()
 *
 * @grantable Yes if @p pHost is NULL.
 * @user root if @p pHost is NULL.
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPClientCheckBindInfo(const LDAP_HOST *pHost);

/**
 * @brief Change password of @p szUserDN via ldappasswd command.
 *
 * This is performed as @p pHost->szBindDN with @p pHost->szBindPW.
 *
 * @param[in] pHost        LDAP host handle, must not be NULL.
 * @param[in] szUserDN     LDAP user DN, must not be NULL.
 * @param[in[ szClearPass  New password for @p szUserDN, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCExecv()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPPasswd(const LDAP_HOST *pHost, const char *szUserDN, const char *szClearPass);

/**
 * @brief Change `sambaLMPassword` and `sambaNTPassword` of @p pHost->szBindDN
 *        via ldapmodify command.
 *
 * This is performed as @p pHost->szBindDN with @p pHost->szBindPW.
 * For security, `sambaLMPassword` is always "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX".
 *
 * @param[in] pHost        Host handle, must not be NULL.
 * @param[in] szClearPass  New password of @p pHost->szBindDN, must not be NULL.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPModify()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSambaPasswd(const LDAP_HOST *pHost, const char *szClearPass);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_CLIENT_H__
// vim:ts=4 sts=4 sw=4
