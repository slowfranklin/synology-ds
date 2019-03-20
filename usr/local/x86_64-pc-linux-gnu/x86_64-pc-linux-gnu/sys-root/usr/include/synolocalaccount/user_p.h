// Copyright (c) 2000-2016 Synology Inc. All rights reserved.

__BEGIN_DECLS;

/* user_set.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserSet(const char **rgszOldName, const PSYNOUSER *rgpUser, const PSYNOSHADOW *rgpShadow, const int nItems, PSLIBCMRESULT *ppMResult);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserSetOne(const char *szOldName, const PSYNOUSER pUser, const PSYNOSHADOW pShadow, PSLIBCMRESULT *ppMResult);
/* user_delete.c  */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserDelete(const char **rgszUserName, const int nItem, PSLIBCMRESULT *ppMResult);
/* user_prepare_for_pkg.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserPrepareForPkg(const char *szUserName, const char *szPrimaryGroup, const char *szHomePath);

/* user_password_rule_set.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserPasswordRuleSet(SYNOPASSWDRULE rule);
/* user_smbpasswd_get.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserSmbPasswdGet(const char *szUserName, char *szLmPasswd, size_t cbLmPasswd, char *szNtPasswd, size_t cbNtPasswd);
/* user_import_passwd.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserImportPasswd(const PSYNOUSER *rgpUser, const char **rgszShadowPW, const char **rgszLMPW, const char **rgszNTPW, int nItems);

/**
 * @brief Check @p szPassword against current password policy.
 *
 * @note If you're going to rename user (i.e. @p szUserName is new user name)
 *       at the same time, call @a SYNOLocalAccountCheckPasswordStrengthEx()
 *       instead.
 *
 * @param[in] szPassword  Password to be checked, must not be NULL.
 * @param[in] szUserName  Current user name, must not be NULL.
 * @param[in] szUserDesc  New user description, must not be NULL.
 *
 * @retval  0 @p szPassword is strong enough.
 * @retval -1 Error or @p szPassword is not strong enough.
 *
 * @exception SYNOLocalAccountCheckPasswordStrengthEx()
 *
 * @sa SYNOLocalAccountCheckPasswordStrengthEx()
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountCheckPasswordStrength(const char *szPassword, const char *szUserName, const char *szUserDesc);

/**
 * @brief Check @p szPassword against current password policy.
 *
 * Password policcy is strored in strongpassword.conf. The behavior should be
 * the same as SYNO.SDS.Utils.CheckStrongPassword in UI.
 *
 * @note Length of admin's password should be at least 6 anyway.
 *
 * @param[in] szPassword  Password to be checked, must not be NULL.
 * @param[in] szOldName   Old user name, pass NULL to ignore history check
 *                        in case of user creation.
 * @param[in] pUser       New user handle, must not be NULL.
 *
 * @retval  0 @p szPassword is strong enough.
 * @retval -1 Error or @p szPassword is not strong enough.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_LOCK_FAILED
 * @exception ERR_INVALID_PASSWORDNAME
 * @exception ERR_PASSWORD_TOO_COMMON
 * @exception ERR_PASSWORD_IN_HISTORY
 * @exception SLIBCUnicodeUTF8StrUpper()
 * @exception SLIBUserRealNameGet()
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountCheckPasswordStrengthEx(const char *szPassword, const char *szOldName, const PSYNOUSER pUser);

/* user_refresh_shells.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountUserRefreshShells();

/**
 * @brief Get status of password for local user @p szUserName.
 *        "Disallow change password" is not included.
 *
 * @param[in] szUserName  Local user name, must not be NULL.
 *
 * @return @a SYNO_PASSWORD_STATUS, PASSWORD_STATUS_UNKNOWN on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 * @exception ERR_LOCK_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_USER
 * @exception SLIBCUnicodeUTF8StrUpper()
 * @exception SLIBCBdbGet()
 * @exception SYNOUserUnpackShadow()
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_1) SYNO_PASSWORD_STATUS SYNOLocalAccountPasswordStatusGet(const char *szUserName);

/**
 * @brief Get number of days in which password @p szUserName is still valid
 *        (i.e. not expired).
 *
 * Result @p pValidDays>0 means expired @p pValidDays days later,
 * 0 means today is the last day, negative means already expired.
 *
 * @param[in]  szUserName  Local user name, must not be NULL.
 * @param[out] pValidDays  Valid days, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 * @exception ERR_LOCK_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_USER
 * @exception SLIBCUnicodeUTF8StrUpper()
 * @exception SLIBCBdbGet()
 * @exception SYNOUserUnpackShadow()
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordValidDaysGet(const char *szUserName, long *pValidDays);

/**
 * @brief Get whether password of local user @p szUserName never expire.
 *
 * @param[in]  szUserName      Local user name, must not be NULL.
 * @param[out] pblNeverExpire  Result, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 * @exception ERR_LOCK_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_USER
 * @exception SLIBCUnicodeUTF8StrUpper()
 * @exception SLIBCBdbGet()
 * @exception SYNOUserUnpackShadow()
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordNeverExpireGet(const char *szUserName, BOOL *pblNeverExpire);

/**
 * @brief Get whether expired password is changeable or not.
 *
 * @note This is for DSM web UI login only.
 *
 * @return Changable or not.
 *
 * @exception SLIBCSzHashAlloc()
 * @exception SLIBCSzListAlloc()
 * @exception SLIBCFileGetKeys()
 *
 * @grantable No
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) BOOL SYNOLocalAccountIsExpiredPasswordChangable();

/**
 * @brief Get number of days before password expired to prompt warning about
 *        the expiration when login DSM web UI.
 *
 * @retval >0 Number of days.
 * @retval =0 Not enabled.
 * @retval <0 On error.
 *
 * @exception SLIBCSzHashAlloc()
 * @exception SLIBCSzListAlloc()
 * @exception SLIBCFileGetKeys()
 *
 * @grantable No
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordExpiryWarningDaysGet();

/**
 * @brief Set password history number for local users.
 *
 * @param[in] iHistoryNum  History number.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountUpdateHistoryNum(int iHistoryNum);

__END_DECLS;

#ifdef __cplusplus

/**
 * @brief Get password expiry settings for local users.
 *
 * Fields with value -1 means not set. In most cases, it's fine to ignore
 * failure, @p expiry will be filled by default values (all false or -1).
 *
 * @param[out] expiry  Password expiry handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordExpiryGet(SYNOPASSWORDEXPIRY *expiry);

/**
 * @brief Set password expiry settings for local users.
 *
 * Apply expiry settings @p expiry then refresh max and min age in /etc/shadow.
 * Max age @a SP_MAX and min age @a SP_MAX+1 won't be changed but there's one
 * exception for the former: password expiry is originally disabled and
 * @p never_expire is not NULL. If so, max age of users in @p never_expire will
 * keep @p SP_MAX which means "never expire".
 *
 * @param[in] expiry        Password expiry handle, must not be NULL.
 * @param[in] never_expire  List of never expire users, may be NULL.
 *                          Used only when password expiry originally disabled.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_LOCK_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OP_FAILURE
 * @exception ERR_RENAME_FAILED
 * @exception SLIBCSzHashAlloc()
 * @exception SLIBCFileSetKeys()
 * @exception SLIBCFileLock()
 * @exception SYNOSchedTaskAlloc()
 * @exception SYNOSchedTaskSave()
 * @exception SYNOSchedTaskRemove()
 * @exception SLIBUserEnum()
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordExpirySet(SYNOPASSWORDEXPIRY *expiry, const PSLIBSZLIST never_expire);

/**
 * @brief Import password expiry settings for local users.
 *
 * Apply expiry settings @p expiry then refresh max and min age in /etc/shadow.
 * If max age is originally disabled, all users follow @p expiry (no never expire).
 *
 * @param[in] expiry  Password expiry handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc()
 * @exception SYNOLocalAccountPasswordExpirySet()
 *
 * @sa SYNOLocalAccountPasswordExpirySet()
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountPasswordExpiryImport(SYNOPASSWORDEXPIRY *expiry);

#endif  // __cplusplus
