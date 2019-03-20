// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_PPOLICY_H__
#define __SYNOLDAP_PPOLICY_H__

#include <sys/cdefs.h>
#include <time.h>
#include <availability.h>
#include <synosdk/ldap.h>

__BEGIN_DECLS;

/**
 * @addtogroup ppolicy
 *
 * @brief Provides structures and APIs for LDAP user password policy, presume
 *        target LDAP server is Synology Directory Server.
 *
 * Since DSM 6.0, Synology Directory Server supports user password policy via
 * ppolicy overlay provided by OpenLDAP. These APIs are used to get policy
 * settings and check LDAP user status.
 *
 * @{
 */

typedef struct __tag__LDAP_HOST LDAP_HOST;

/*
 * LDAP ppolicy keywords
 */

#define SZK_PPOLICY_SUBENTRY        "pwdPolicySubentry"
#define SZ_PPOLICY_PREFIX           "ou=pwpolicies"
#define SZ_PPOLICY_DEFAULT_PREFIX   "cn=default," SZ_PPOLICY_PREFIX
#define SZ_PPOLICY_SYNO_PREFIX      "cn=synopwpolicy,cn=" SZ_LDAP_VALUE_SYNOCONF

#define SZK_PPOLICY_ATTRIBUTE              "pwdAttribute"
#define SZK_PPOLICY_MINAGE                 "pwdMinAge"
#define SZK_PPOLICY_MAXAGE                 "pwdMaxAge"
#define SZK_PPOLICY_INHISTORY              "pwdInHistory"
#define SZK_PPOLICY_CHECKQUALITY           "pwdCheckQuality"
#define SZK_PPOLICY_MINLENGTH              "pwdMinLength"
#define SZK_PPOLICY_EXPIREWARNING          "pwdExpireWarning"
#define SZK_PPOLICY_GRACEAUTHNLIMIT        "pwdGraceAuthnLimit"
#define SZK_PPOLICY_LOCKOUT                "pwdLockout"
#define SZK_PPOLICY_LOCKOUTDURATION        "pwdLockoutDuration"
#define SZK_PPOLICY_MAXFAILURE             "pwdMaxFailure"
#define SZK_PPOLICY_FAILURECONUTINTERVAL   "pwdFailureCountInterval"
#define SZK_PPOLICY_MUSTCHANGE             "pwdMustChange"
#define SZK_PPOLICY_ALLOWUSERCHANGE        "pwdAllowUserChange"
#define SZK_PPOLICY_SAFEMODIFY             "pwdSafeModify"
#define SZK_PPOLICY_CHECKMODULE            "pwdCheckModule"

#define SZK_SYNO_PPOLICY_EXNAMEDESC        "pwdSynoExcludeNameDesc"
#define SZK_SYNO_PPOLICY_MIXEDCASE         "pwdSynoMixedCase"
#define SZK_SYNO_PPOLICY_NUMBER            "pwdSynoNumber"
#define SZK_SYNO_PPOLICY_SPECIALCHAR       "pwdSynoSpecialChar"
#define SZK_SYNO_PPOLICY_EXPIRECHANGE      "pwdSynoExpireChange"
#define SZK_SYNO_PPOLICY_EXPIREMAIL        "pwdSynoExpireMail"
#define SZK_SYNO_PPOLICY_LOGINFAILINFO     "pwdSynoLoginFailInfo"
#define SZK_SYNO_PPOLICY_PWDCHANGEONLY     "pwdSynoPwdChangeOnly"
#define SZK_SYNO_PPOLICY_PWDEXPIRE         "pwdSynoPwdExpire"
#define SZK_SYNO_PPOLICY_STRONGPWD         "pwdSynoStrongPwd"
#define SZK_SYNO_PPOLICY_LOCKOUTEXPIRE     "pwdSynoLockoutExpire"
#define SZK_SYNO_PPOLICY_MINAGE            "pwdSynoMinAgeEnable"
#define SZK_SYNO_PPOLICY_HISTORY           "pwdSynoInHistoryEnable"
#define SZK_SYNO_PPOLICY_MINLENGTH         "pwdSynoMinLengthEnable"
#define SZK_SYNO_PPOLICY_PWDRESET          "pwdSynoPwdReset"
#define SZK_SYNO_PPOLICY_WARNINGENABLE     "pwdSynoExpireWarningEnable"
#define SZK_SYNO_PPOLICY_EXPIREWARNING     "pwdSynoExpireWarning"
#define SZK_SYNO_PPOLICY_EXPIREMAILTIME	   "pwdSynoExpireMailTime"
#define SZK_SYNO_PPOLICY_EXPIREMAILDAYS	   "pwdSynoExpireMailBeforeDays"
#define SZK_SYNO_PPOLICY_MAILTASKID		   "pwdSynoMailTaskId"

#define SZ_LDAP_OPERATIONAL_ATTR_PWDACCOUNTLOCKEDTIME	"pwdAccountLockedTime"
#define SZ_LDAP_OPERATIONAL_ATTR_PWDCHANGEDTIME			"pwdChangedTime"
#define SZ_LDAP_OPERATIONAL_ATTR_RESET					"pwdReset"

/**
 * @brief LDAP user status.
 */
typedef enum {
	PWD_UNKNOWN,
	/** @brief Normal. */
	PWD_NORMAL,
	/** @brief Password must be changed. */
	PWD_RESET,
	/** @brief Password expired. */
	PWD_EXPIRED,
	/** @brief Account locked. */
	PWD_LOCKED,
} LDAP_PWD_STATUS;

/**
 * @brief Password policy handle, refer slapo-ppolicy's man page for details.
 */
typedef struct __tag__LDAP_PPOLICY {
	char pwdAttribute[MAX_DN_LEN];
	/** @brief Password min age in seconds. */
	int pwdMinAge;
	/** @brief Password max age in seconds. */
	int pwdMaxAge;
	int pwdInHistory;
	int pwdCheckQuality;
	int pwdMinLength;
	int pwdExpireWarning;
	int pwdGraceAuthnLimit;
	/** @brief Locked or not. */
	BOOL pwdLockout;
	/** @brief Lockout duration in seconds, 0 means forever. */
	int pwdLockoutDuration;
	int pwdMaxFailure;
	int pwdFailureCountInterval;
	/** @brief Password must be changed. */
	BOOL pwdMustChange;
	BOOL pwdAllowUserChange;
	BOOL pwdSafeModify;
	char pwdCheckModule[MAX_PATH_LEN];
} LDAP_PPOLICY;

/**
 * @brief Convert LDAP Generalized Time @p szLdapTime, say 20160622095220Z,
 *        to timestamp.
 *
 * @param[in]  szLdapTime  LDAP Generalized Time, must not be NULL.
 * @param[out] ts          Result timestamp, must not be NULL.
 *
 * @return 0 on success, else if failed.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPTimeToTimestamp(const char *szLdapTime, time_t *ts);

/**
 * @brief Check LDAP user's status.
 *
 * The precedence is `PWD_RESET` > `PWD_LOCKED` > `PWD_EXPIRED`.
 *
 * @param[in]  blLockout         Lockout is enabled or not.
 * @param[in]  nLockoutDuration  Lockout duration in seconds, 0 means forever.
 * @param[in]  nMaxAge           Password max age in seconds.
 * @param[in]  szChangedTime     Password changed time as LDAP Generalized Time,
 *                               NULL is ignored.
 * @param[in]  szLockedTime      Locked time as LDAP Generalized Time,
 *                               NULL means not locked.
 * @param[out] status            Result status, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @sa LDAP_PPOLICY, LDAP_PWD_STATUS, SYNOLDAPTimeToTimestamp()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPPasswdStatusCheck(const BOOL blLockout, const int nLockoutDuration, const int nMaxAge, const char *szChangedTime, const char *szLockedTime, const char *szReset, LDAP_PWD_STATUS *status);

/**
 * @brief Get default password policy settings from @a SYNOLDAPSearchGetNext()
 *        under base DN of @p pHost.
 *
 * @param[in]  pHost      Host handle, must not be NULL.
 * @param[out] pLppolicy  Result password policy handle, must not be NULL.
 *
 * @return 0 on success, -1 on error or not found.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchRequestInit()
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPPpolicyGet(const LDAP_HOST *pHost, LDAP_PPOLICY *pLppolicy);

/**
 * @brief Get LDAP server page for changing password/profile if @p pHost is
 *        Synology Directory Server.
 *
 * Result @p szPageUrl will be something like
 * "https://{0}:5001/webman/3rdparty/DirectoryServer/profile.cgi" where "{0}"
 * should be replaced by LDAP server's address. Non-NULL @p szServerAddr will
 * be filled by @p pHost->szUri.
 *
 * @param[in]  pHost         Host handle, must not be NULL.
 * @param[out] szPageUrl     Result page URL, must not be NULL.
 * @param[in]  cbPageUrl     Size of @p szPageUrl, must >0.
 * @param[out] szServerAddr  Result LDAP server address, NULL is ignored.
 * @param[in]  cbServerAddr  Size of @p szServerAddr, 0 is ignored.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchRequestInit()
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPResultGetFirst()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPBrowserPwdPageGetByHost(const LDAP_HOST *pHost, char *szPageUrl, const size_t cbPageUrl, char *szServerAddr, const size_t cbServerAddr);

/**
 * @brief Get LDAP server page for changing password/profile for currently
 *        joined LDAP server.
 *
 * @param[out] szPageUrl     Result page URL, must not be NULL.
 * @param[in]  cbPageUrl     Size of @p szPageUrl, must >0.
 * @param[out] szServerAddr  Result LDAP server address, must >0.
 * @param[in]  cbServerAddr  Size of @p szServerAddr, must >0.
 *
 * @retval  1 Success.
 * @retval  0 Success, but changing password is forbidden if password is expired.
 * @retval -1 Error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPHostInitByBindConfig()
 * @exception SYNOLDAPBrowserPwdPageGetByHost()
 *
 * @sa SYNOLDAPBrowserPwdPageGetByHost()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPBrowserPwdPageGet(char *szPageUrl, const size_t cbPageUrl, char *szServerAddr, const size_t cbServerAddr);

/**
 * Check whether have notify @p szUID when his password is about to expire.
 *
 * @note This function presumes target LDAP server is Synology Directory Server.
 *
 * @param[in]  szUID  User UID, must not be NULL.
 * @param[out] pDays  Number of days before password is expired, NULL is ignored.
 *
 * @return Have to notify or not.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPHostInitByBindConfig()
 * @exception SYNOLDAPSearchRequestInit()
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 * @exception SYNOLDAPBrowserUserGet()
 * @exception SYNOLDAPResultGetFirst()
 * @exception SYNOLDAPTimeToTimestamp()
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynoldap
 */
DSM_STARTING_FROM(SDK_VER_6_0) BOOL SYNOLDAPUserIsNeedLoginNotify(const char *szUID, int *pDays);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_PPOLICY_H__
// vim:ts=4 sts=4 sw=4
