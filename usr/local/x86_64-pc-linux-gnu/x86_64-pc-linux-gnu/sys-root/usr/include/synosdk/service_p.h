/**
 * @addtogroup SERVICE
 *
 * @{
 */

/**
 * Check if the user home is enabled. For local/domain/ldap users.
 *
 * @param[in]   authType   auth type of the user. can be obtained by pUser->authType or SYNOGetAuthType().
 * @param[in]   pUid   We check if it's in avaliable range for local user uid.
 *                      Can be null.
 *
 * @retval    FALSE disabled
 * @retval     TRUE enabled
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOServiceUserHomeIsEnabled(AUTH_TYPE authType, uid_t *pUid);

/**
 * Allocate PSYNO_HOME_CHECK_RESULT from data stored in hash @p pszConf
 * Legal keys are SZK_RESULT_USER_NAME, SZK_RESULT_HOME_PATH
 *
 * @param[in]   pszConf   Allocation config
 * @param[out]   ppResult   Allocated result, non-NULL *ppResult will be re-allocated
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOHomeCheckResultAlloc(PSYNO_HOME_CHECK_RESULT *ppResult, const PSLIBSZHASH pszConf);

/**
 * Free space of PSYNO_HOME_CHECK_RESULT
 *
 * @param[in]   pResult   PSYNO_HOME_CHECK_RESULT to free
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_2) void SYNOHomeCheckResultFree(PSYNO_HOME_CHECK_RESULT pResult);

/**
 * Check whether @p szRawPath under some user's home. Return checked result in @p ppResult
 * as long as @p szRawPath is a legal (in right format) home path. Otherwise, do nothing to @p ppResult.
 * @p ppResult->szHomePath starts with service link.
 *
 *
 * @param[in]   szRawPath     Full path starts with "/".
 * @param[in]   blChkEnable   TRUE to check:
 *                            - Whether home service is enabled.
 *                            - Whether @p szRawPath is on the right volume if it starts with "/volumeX".
 * @param[in]   blChkValid    TRUE to check home path is valid (really owned by some user). Will perform SYNOUserGet().
 * @param[out]  ppResult      Check result, non-NULL ppResult will be re-allocated.
 *
 * @retval   1 Match some user's home path
 * @retval   0 No user's home path matches
 * @retval   -1 On error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_NO_SUCH_USER
 * @exception ERR_NO_SUCH_SHARE
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOServiceHomePathCheck(const char *szRawPath, BOOL blChkEnable, BOOL blChkValid, PSYNO_HOME_CHECK_RESULT *ppResult);

/**
 * Get user home path for @p szFullName and create it if not exist.
 * @p szFullName can be local user name, domain user name with workgroup, LDAP user name with login suffix.
 *
 * @note Case of user name in result @p szHomePath will be the same as the result from SYNOUserGet().
 *
 *
 * @param[in]   szFullName   Full user name, must not be NULL or empty string.
 * @param[out]   szHomePath   Result user home path, can be NULL if no need to get.
 * @param[in]   cbHomePath   Size of @p szHomePath, can be 0 if no need to get.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_NOT_SET
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_MKDIR_FAILED
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_RENAME_FAILED
 * @exception SYNOUserGet()
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/homes
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOServiceHomePathGet(const char *szFullName, char *szHomePath, int cbHomePath);

/**
 * Get user home path for @p szFullName and create it if not exist.
 * @p szFullName can be local user name, domain user name with workgroup, LDAP user name with login suffix.
 *
 * @note Case of user name in result @p szHomePath will be the same as the result from SYNOUserGet().
 *
 * @param[in]    szFullName   Full user name, must not be NULL or empty string.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_NOT_SET
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_MKDIR_FAILED
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_RENAME_FAILED
 * @exception SYNOUserGet()
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/homes
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceHomePathCreate(const char *szFullName);

/**
 * This function is called by winbindd.
 *
 * Assume @p rid=500, the result will be /var/services/homes/@DH-%D/0/%U-500.
 *
 * @note This is for NSS modules only. Please use SLIBServiceHomePathGet() instead.
 *
 *
 * @param[in]   rid   Domain user rid.
 * @param[out]   szHomePath   Result home path, must not be NULL.
 * @param[in]   cbHomePath   Size of @p cbHomePath, must >0.
 *
 * @return See DirectoryUserHomePathGet().
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceHomePathGetForWinbind(unsigned long rid, char *szHomePath, int cbHomePath);

/**
 * This function is called by nslcd.
 *
 * Assume @p szSuffix=syno.com, @p szUserName=admin, @p uid=1000001,
 * the result will be /var/services/homes/@LH-SYNO.COM/61/admin-1000001.
 *
 * @note This is for NSS modules only. Please use SLIBServiceHomePathGet() instead.
 *
 * @param[in]   szSuffix   LDAP login suffix, must not be NULL.
 * @param[in]   szUserName   LDAP user name without login suffix, must not be NULL.
 * @param[in]   uid   LDAP user uid.
 * @param[out]   szHomePath   Result home path, must not be NULL.
 * @param[in]   cbHomePath   Size of @p cbHomePath, must >0.
 *
 * @return See DirectoryUserHomePathGet().
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceHomePathGetForNslcd(const char *szSuffix, const char *szUserName, uid_t uid, char *szHomePath, int cbHomePath);

/**
 * Just a wrapper function for SYNOServiceRemoteHomeCheck().
 * This function will check remote home of AUTH_LDAP and AUTH_DOMAIN.
 *
 * @param[out]  szShareName   Non NULL to get remote home share name.
 * @param[in]   cbShareName   Size of @p szShareName, must be positive if @p szShareName is not NULL.
 *
 * @retval   TRUE    Home on remote volume is enabled.
 * @retval   FALSE   Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOServiceRemoteHomeCheckAll(char *szShareName, size_t cbShareName);

/**
 * Return whether home enabled on remote volume by checking:
 * - @p authType doesn't contains AUTH_LOCAL.
 * - SZK_SYNO_REMOTE_HOME in SZF_SYNO_INFO is not empty.
 *
 * If @p szShareName not NULL, return content of SZK_SYNO_REMOTE_HOME; namely, remote home share name.
 *
 * @param[in]   authType      Auth type, at least one bit is on. AUTH_LOCAL should not be on.
 * @param[out]  szShareName   Non NULL to get remote home share name.
 * @param[in]   cbShareName   Size of @p szShareName, must be positive if @p szShareName is not NULL.
 *
 * @retval   TRUE    Home on remote volume is enabled.
 * @retval   FALSE   Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOServiceRemoteHomeCheck(AUTH_TYPE authType, char *szShareName, size_t cbShareName);

/**
 * @}
 */
