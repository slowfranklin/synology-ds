/**
 * @addtogroup USER
 *
 * @{
 */

/**
 * Allocates a SYNOUSER from these input parameters.
 * The return information will save in @p ppUser argument.
 * 
 * If @p *ppUser is NULL, this function will allocates for
 * this user information. Otherwise, @p *ppUser is not NULL,
 * this function will check SYNOUSER::nAlloc is large enough to
 * store this user information. When the size is bigger than we
 * need, we will copy user information into @p *ppUser. When
 * the size is smaller than we need, this function will
 * reallocf() for it and update SYNOUSER::nAlloc accordingly.
 *
 * @param[out]   ppUser   The pointer that this user to be stored. Should not be NULL.
 * @param[in]    szName   The UTF-8 string of User Name. Should not be NULL.
 * @param[in]    pw_uid   The user id.
 * @param[in]    pw_gid   The group id.
 * @param[in]    szFullname   The UTF-8 sting of user Real Name.
 * @param[in]    pw_dir   Home directory.
 * @param[in]    pw_shell   Shell program.
 * @param[in]    szMail   The unix string to the email of this user.
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
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserAlloc(PSYNOUSER *ppUser, const char *szName, uid_t pw_uid, gid_t pw_gid, const char *szFullname, const char *pw_dir, const char *pw_shell, const char *szMail);

/**
 * Checks current time is larger than lExpiryDay or not.
 *
 * @param[in]   lExpiryDay   The time_t (in seconds) at the 00:00.0 of expired day.
 *
 * @retval   TRUE   User is expired.
 * @retval   FALSE  User is not expired.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOUserIsExpired(long lExpiryDay);

/**
 * This function checks the expiration of the input user.
 *
 * @param[in]   szUserName   The user name you want to check.
 *
 * @retval   -1 error
 * @retval    0 available
 * @retval    1 expired
 *
 * @grantable Yes (see below)
 * @user root (or system if @p szUserName is a local user)
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserCheckExpired(const char *szUserName);

/**
 * Frees a Synology User structure.
 *
 * @param[in,out]   pUser   The Synology User struct. May be NULL.
 *
 * @note This function is a Thread-Safe function.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOUserFree(void *pUser);

/**
 * Obtains the user information according to the User ID you
 * specify in @p nUserID argument. The return information will
 * save in @p ppUser argument.
 * 
 * This function will call SYNOUserDbOpen() at begining to
 * get the PSYNOUSERDB handler and call SYNOUserDbClose()
 * after done.
 * 
 * If @p *ppUser is NULL, this function will allocates for
 * this user. Otherwise, @p *ppUser is not NULL, this function
 * will check SYNOUSER::nAlloc is large enough to store this
 * share information. When the size is bigger than we need, we
 * will copy share information into @p *ppUser. When the size is
 * smaller than we need, this function will reallocf() for it
 * and update SYNOUSER::nAlloc accordingly.
 *
 * @param[in]   nUserID   The User ID. Should be a positive.
 * @param[in,out]   ppUser   The pointer that this user to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_USER
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserGetLocalByUID(uid_t nUserID, PSYNOUSER *ppUser);

/**
 * Obtains the user information according to the User ID you
 * specify in @p nUserID argument.
 * The return information will save in @p ppUser argument.
 *
 * This function calls SYNOUserGetLocalByUID() to lookup the user
 * information for local user. When success it returns the
 * obtained information; otherwise it calls SYNOUserGetNssByUID()
 * to lookup user through name service.
 *
 * If @p *ppUser is NULL, this function will allocates for
 * this user. Otherwise, @p *ppUser is not NULL, this function
 * will check SYNOUSER::nAlloc is large enough to store this
 * share information. When the size is bigger than we need, we
 * will copy share information into @p *ppUser. When the size is
 * smaller than we need, this function will reallocf() for it
 * and update SYNOUSER::nAlloc accordingly.
 *
 * @param[in]   nUserID   The User ID. Should be a positive.
 * @param[in,out]   ppUser   The pointer that this user to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserGetByUID(uid_t nUserID, PSYNOUSER *ppUser);

/**
 * Obtains the user information according to the user name you
 * specify in @p szUserName argument from SYNOUSERDB. The return
 * information will save in @p ppUser argument.
 *
 * If @p *ppUser is NULL, this function will allocates for
 * this share. Otherwise, @p *ppUser is not NULL, this function
 * will check SYNOUSER::nAlloc is large enough to store this
 * share information.  When the size is bigger than we need, we
 * will copy user information into @p *ppUser. When the size is
 * smaller than we need, this function will reallocf() for it
 * and update SYNOUSER::nAlloc accordingly.
 *
 * @param[in]       szUserName   The string that contains User name. Should not be NULL.
 * @param[out]      ppUser       The pointer that this user information to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_USER
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserGetLocal(const char *szUserName, PSYNOUSER *ppUser);

/**
 * Obtains the user information according to the user name you
 * specify in @p szUserName argument.
 *
 * This function calls SYNOUserGetLocal() to lookup the user
 * information for local user. If lookup failed, it returns -1.
 * For non-local user, it calls SYNOUserGetNss() to lookup
 * user through name service.
 *
 * The return information will save in @p ppUser argument.
 * 
 * If @p *ppUser is NULL, this function will allocates for
 * this share. Otherwise, @p *ppUser is not NULL, this function
 * will check SYNOUSER::nAlloc is large enough to store this
 * share information.  When the size is bigger than we need, we
 * will copy user information into @p *ppUser. When the size is
 * smaller than we need, this function will reallocf() for it
 * and update SYNOUSER::nAlloc accordingly.
 *
 * By default, the username is assumed to be caseless compared.
 * However, it strongly depends on the implementation of
 * name service plugin modules (nss_xxx.so).
 * We've tested the comparison in nss_winbindd (winbindd) and
 * nss_ldap (nslcd). They are both in caseless maner.
 *
 * @param[in]    szUserName     The string that contains User name. Should not be NULL.
 * @param[out]   ppUser         The pointer that this user information to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserGet(const char *szUserName, PSYNOUSER *ppUser);

/**
 * Get uid and gid of local or domain user.
 *
 * @param[in]   szName   username
 * @param[out]   pUid   for uid return, can be null
 * @param[out]   pGid   for gid return, can be null
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserGetUGID(const char *szName, uid_t *pUid, gid_t *pGid);

/**
 * Get and create user's preference directory
 *
 * @param[in]    szName    The user name.
 * @param[out]   szPath    A buffer to store the preference directory path.
 * @param[in]    cbPath    Number of bytes in @p szPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_USER
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserPreferenceDirGet(const char *szName, char *szPath, const int cbPath);

/**
 * Convert the user name into canonical form (formal login name).
 * It tries to determine the name type by SYNOGetAuthType().
 * For AUTH_DOMAIN type, it returns 0 directly to tell the caller
 * the conversion is not performed.
 * For AUTH_LDAP type, it checks if it can be transformed in an
 * AUTH_DOMAIN form (domain\user) when domain is joined.
 * For AUTH_LOCAL type, it calls SYNOUserGetLocal() to identify if
 * it's a local username.
 * If not, the name will be appended with the LDAP login suffix when
 * DS is binding to an LDAP server. The appended name is then checked
 * through SYNOUserGetNss(). If no such user is returned, The user
 * name is then concatenated with the domain prefix to check again
 * via SYNOUserGetNss().
 *
 * @note @p szNewName won't be changed if no conversion (i.e. return value <=0).
 *
 * @param[in]   szOldName   The user name to convert. When it's NULL, the szNewName would be checked.
 * @param[in,out]   szNewName   If szOldName is NULL, szNewName will be converted. The converted name will be stored in szNewName.
 * @param[in]   cbNewName   The buffer size of szNewName
 *
 * @retval    1 On success, the name was converted.
 * @retval    0 On success, the name is not necessary to convert.
 * @retval   -1 On error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_USER
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserLoginNameConvert(const char *szOldName, char *szNewName, size_t cbNewName);

/**
 * This function obtains the total number of users in the server.
 *
 * @param[in]   authType   The union of AUTH_TYPE.
 *
 * @retval    -1   On error
 * @retval    >=0  total number of users
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBUserEnum()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUserTotalNum(AUTH_TYPE authType);

/**
 * Convert from calendar date to accumulated days since 1970/1/1
 *
 * @param[out]   plExpiryDay   pointer to the expiry day
 * @param[in]   szExpiredDate   Calendar date format: "yyyy/mm/dd"
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserExpiryDateToDay(long *plExpiryDay, const char *szExpiredDate);

/**
 * Convert from accumulated days since 1970/1/1 to calendar date
 * with Format "yyyy/mm/dd"
 *
 * @param[in]   plExpiryDay   Expiry day since 1970/1/1.
 * @param[out]  szBuf         A buffer to store the expiry date.
 * @param[in]   cbBufSize     Size of @p szBuf.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserExpiryDayToDate(const long plExpiryDay, char *szBuf, int cbBufSize);

/**
 * Check whether @p szName a valid user name. Following are the rules:
 * - Allow blank, but the head and tail of @p szName can't be blank.
 * - Can't be empty string and first character can't be '-'.
 * - Number of Unicode characters should <= SYNO_USERNAME_UTF32_MAX.
 * - ASCII code >= 128 or digit, alphabets, blank, '.', '_' and '-'.
 *
 * @param[in]   szName   User name to be checked, must not be NULL.
 *
 * @retval   TRUE   @p szName is valid user name.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBUserNameIsValid(const char *szName);

/**
 * Get real user name of @p szName for local/LDAP/domain users.
 * This function will acquire shared lock on user DB for non-domain user.
 *
 * @param[in]   szName   User name, must not be NULL.
 * @param[out]   szRealName   Real user name, must not be NULL.
 * @param[in]   cbRealName   Size of @p szRealName, must >0.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserRealNameGet(const char *szName, char *szRealName, size_t cbRealName);

/**
 * Get all users with auth type @p authType and store result user names in @p pplistUserName.
 * User names in @p pplistUserName are real names from user DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistUserName   List of result user names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 *
 * @retval   >=0 Number of enumerated users.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserEnum(PSLIBSZLIST *pplistUserName, AUTH_TYPE authType, const char *szDomain);

/**
 * Get all users with auth type @p authType and store result user names in @p pplistUserName.
 * Result user names are prefixed by @p szPrefix, @ blCaseLess.
 * User names in @p pplistUserName are real names from user DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistUserName   List of result user names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   szPrefix   Prefix to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 *
 * @retval   >=0 Number of enumerated users.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserEnumByPrefix(PSLIBSZLIST *pplistUserName, AUTH_TYPE authType, const char *szDomain, const char *szPrefix, BOOL blCaseLess);

/**
 * Get all users with auth type @p authType and store result user names in @p pplistUserName.
 * Result user names contain sub-string @p szSubstr, @ blCaseLess.
 * User names in @p pplistUserName are real names from user DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistUserName   List of result user names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   szSubstr   Sub-string to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 *
 * @retval   >=0 Number of enumerated users.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserEnumBySubstr(PSLIBSZLIST *pplistUserName, AUTH_TYPE authType, const char *szDomain, const char *szSubstr, BOOL blCaseLess);

/**
 * Enumerate all users with auth type @p authType and paging.
 *
 * For each user that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pUser is result PSYNOUSER and @p idx is index of @p pUser in all enumerated users.
 * Negative return of @p callback interrupts the enumeration process.
 *
 * For non-local users:
 * - Enumerated only when domain/LDAP is joined/binded.
 * - Only info in local DB/cache are returned, caller can invoke SYNOUserGet() to get more info for non-local user only.
 *
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   start   Start of paging, must >=0.
 * @param[in]   limit   Number of users in a page, must >=-1, -1 means no limit.
 * @param[in]   callback   Callback function, must not be NULL.
 * @param[in]   data   Additional data passed to @p callback.
 *
 * @retval    >=0 Total number of users.
 * @retval    -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserInfoEnum(AUTH_TYPE authType, const char *szDomain, int start, int limit, UserEnumCallback callback, void *data);

/**
 * Enumerate all users with auth type @p authType and paging.
 * Only user names prefixed by @p szPrefix, @p blCaseLess are taken into consideration.
 *
 * For each user that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pUser is result PSYNOUSER and @p idx is index of @p pUser in all enumerated users.
 * Negative return of @p callback interrupts the enumeration process.
 *
 * For non-local users:
 * - Enumerated only when domain/LDAP is joined/binded.
 * - Only info in local DB/cache are returned, caller can invoke SYNOUserGet() to get more info for non-local user only.
 *
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   start   Start of paging, must >=0.
 * @param[in]   limit   Number of users in a page, must >=-1, -1 means no limit.
 * @param[in]   szPrefix   Prefix to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 * @param[in]   callback   Callback function, must not be NULL.
 * @param[in]   data   Additional data passed to @p callback.
 *
 * @retval   >=0 Total number of users with prefix @p szPrefix.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserInfoEnumByPrefix(AUTH_TYPE authType, const char *szDomain, int start, int limit, const char *szPrefix, BOOL blCaseLess, UserEnumCallback callback, void *data);

/**
 * Enumerate all users with auth type @p authType and paging.
 * Only user names contain sub-string @p szSubstr, @p blCaseLess are taken into consideration.
 *
 * For each user that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pUser is result PSYNOUSER and @p idx is index of @p pUser in all enumerated users.
 * Negative return of @p callback interrupts the enumeration process.
 *
 * For non-local users:
 * - Enumerated only when domain/LDAP is joined/binded.
 * - Only info in local DB/cache are returned, caller can invoke SYNOUserGet() to get more info for non-local user only.
 *
 * @param[in]   authType     Auth type.
 * @param[in]   szDomain     Domain name, NULL or empty string means all domains.
 * @param[in]   start        Start of paging, must >=0.
 * @param[in]   limit        Number of users in a page, must >=-1, -1 means no limit.
 * @param[in]   szPrefix     Sub-string to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 * @param[in]   callback     Callback function, must not be NULL.
 * @param[in]   data         Additional data passed to @p callback.
 *
 * @retval   >=0 Total number of users of substring @p szSubstr.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserInfoEnumBySubstr(AUTH_TYPE authType, const char *szDomain, int start, int limit, const char *szPrefix, BOOL blCaseLess, UserEnumCallback callback, void *data);

/**
 * Enumerate all "internal" users with paging.
 * Only user names contain sub-string @p szPattern, @p blCaseLess are taken into consideration.
 *
 * For each user that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pUser is result PSYNOUSER and @p idx is index of @p pUser in all enumerated users.
 * Negative return of @p callback interrupts the enumeration process.
 *
 * @param[in]   start   Start of paging, must >=0.
 * @param[in]   limit   Number of users in a page, must >=-1, -1 means no limit.
 * @param[in]   szPattern   Sub-string to match, must not be NULL.
 * @param[in]   blPrefix   Match prefix or substring.
 * @param[in]   blCaseLess   The match is caseless or not.
 * @param[in]   callback   Callback function, must not be NULL.
 * @param[in]   data   Additional data passed to @p callback.
 *
 * @retval   >=0 Total number of internal users with substring/prefix @p blPrefix.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserInfoEnumInternalUsers(int start, int limit, const char *szPattern, BOOL blPrefix, BOOL blCaseLess, UserEnumCallback callback, void *data);

/**
 * Get maximum number of users we are allowed to create.
 *
 * @retval   -1 On error.
 * @retval   >=0 Maximun number.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserNumRemained();

/**
 * Replace items separated by ',' in @p szList according to @p pshMap and store result in @p pszStr with size @p pchStr.
 * NULL @p *pszStr will be allocated by this function with size BUFSIZE.
 * Key and value in @p pshMap means to replace key in @p szList by value. Empty value means to delete key.
 * The comparison is caseless and number of replaced and/or deleted items is returned.
 *
 * @param[in]   szList   Item list to be replaced, must not be NULL.
 * @param[in]   pshMap   Map to indicate how to replace (key in upper case), must not be NULL.
 * @param[in,out]   pszStr   Buffer to save the result, must not be NULL.
 * @param[in,out]   pcbStr   Allocated size of @p pszStr, must not be NULL and >=0 if @p *pszStr not NULL.
 *
 * @retval   >=0 Number of replaced and/or replaced items.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUGListReplace(const char *szList, const PSLIBSZHASH pshMap, char **pszStr, int *pcbStr);

/**
 * Get admin users according to @p authType and store result in @p *ppslAdmin.
 *
 * @param[in]   authType   Auth type of admin users to get.
 * @param[out]   ppslAdmin   Admin user list, must not be NULL.
 *
 * @retval   >=0 Number of admin users.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBUserAdminListGet(AUTH_TYPE authType, PSLIBSZLIST *ppslAdmin);

/**
 * Check whether the user uid @p uid is a reserved for local user.
 *
 * @param[in]   uid   Local user's uid.
 *
 * @retval    TRUE   @p uid is reserved.
 * @retval    FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) BOOL SYNOUserIsReservedLocalUid(uid_t uid);

/**
 * Encrypt plain text password @p szPlain into NT password @p szNtPwd.
 *
 * @param[in]   szPlain   Plain text password, should not be NULL.
 * @param[out]   szNtPwd   Encrypted NT password, should not be NULL.
 * @param[in]   cbNtPwd   Size of @p szNtPwd, should >= MAX_SMBPASSWD_LEN.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserSmbNtEncrypt(const char *szPlain, char *szNtPwd, size_t cbNtPwd);

/**
 * Get the hashed password of user with @p szUserName.
 *
 * @param[in]   szUserName   The username, must not be NULL.
 * @param[out]   szPassword   Buffer to store the hashed password, must not be NULL.
 * @param[in]   cbPassword   Size of @p szPassword, must be positive.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserPasswordGet(const char *szUserName, char *szPassword, size_t cbPassword);

/**
 * Get the expiry day of user with the name of @p szUserName.
 *
 * @param[in]   szUserName   The username, must not be NULL.
 * @param[out]   plExpiryDay   The pointer to the expiry day, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes (see below)
 * @user root (or system if @p szUserName is a local user)
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserExpiryDayGet(const char *szUserName, long *plExpiryDay);

/**
 * Get the disallow change password status of user with the name of @p szUserName.
 *
 * @param[in]    szUserName         The username, must not be NULL.
 * @param[out]   pAllowChPassword   The pointer to the allow change password status, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes (see below)
 * @user root (or system if @p szUserName is a local user)
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserAllowChPasswordGet(const char *szUserName, SYNOALLOWCHPASSWORD *pAllowChPassword);

/**
 * Check whether the user with name @p szName and uid @p uid is a internal user (neither system nor normal).
 *
 * @param[in]   szName   User name, must not be NULL.
 * @param[in]   uid   UID to check.
 *
 * @retval   TRUE   Internal user.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOUserIsInternal(const char *szName, uid_t uid);

/**
 * Check whether the user with name @p szName and uid @p uid is a system user.
 *
 * @param[in]   szName   User name, must not be NULL.
 * @param[in]   uid   User's uid, must not be UID_ERR.
 *
 * @retval   TRUE   System user.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOUserIsReserved(const char *szName, uid_t uid);

/**
 * Alloc or re-alloc memory space for @p ppShadow.
 *
 * @param[in]   ppShadow     The pointer to the shadow, must not by NULL. But @p *ppShadow may be NULL.
 * @param[in]   shadowType   The type of shadow:
 *                           - SYNO_SHADOW_CREATE_USER: Fill in all default values, e.g. NOT_EXPIRED.
 *                           - SYNO_SHADOW_UPDATE_USER: Fill in all "no-change" values, e.g. NO_CHANGE_EXPIRED.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowAlloc(PSYNOSHADOW *ppShadow, const SYNOSHADOWALLOCTYPE shadowType);

/**
 * Frees a Synology Shadow structure.
 *
 * @param[in]    pShadow   The shadow to free.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) void SLIBUserShadowFree(PSYNOSHADOW pShadow);

/**
 * Get the password from the opaque pointer @p pShadow.
 * The caller must free @p *pszPassword by himself.
 *
 * @param[in]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[out]   pszPassword   The pointer for the password.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowPasswordGet(const PSYNOSHADOW pShadow, char **pszPassword);

/**
 * Set the password for the opaque pointer @p pShadow.
 * @p szPassword should be a plain text password.
 *
 * @param[out]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[in]   szPassword   The pointer for the plain text password.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowPasswordSet(PSYNOSHADOW pShadow, const char *szPassword);

/**
 * Get the expiry day from the opaque pointer @p pShadow.
 *
 * @param[in]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[out]   plExpiryDay   The pointer to the expiry day, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowExpiryDayGet(const PSYNOSHADOW pShadow, long *plExpiryDay);

/**
 * Set the expiry day for the opaque pointer @p pShadow.
 *
 * @param[out]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[in]   lExpiryDay   The expiry day.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowExpiryDaySet(PSYNOSHADOW pShadow, const long lExpiryDay);

/**
 * Get the disallow change password status from the opaque pointer @p pShadow.
 *
 * @param[in]    pShadow            The opaque pointer of shadow, must not be NULL.
 * @param[out]   pAllowChPassword   The pointer to the allow change password status, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowAllowChPasswordGet(const PSYNOSHADOW pShadow, SYNOALLOWCHPASSWORD *pAllowChPassword);

/**
 * Set the disallow change password status for the opaque pointer @p pShadow.
 *
 * @param[out]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[in]   allowChPassword   The disallow change password status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowAllowChPasswordSet(PSYNOSHADOW pShadow, const SYNOALLOWCHPASSWORD allowChPassword);

/**
 * Set the option of changing password required for the opaque pointer @p pShadow.
 *
 * @param[out]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[in]   mustChPassword   must change password or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserShadowMustChPasswordSet(PSYNOSHADOW pShadow, const SYNOMUSTCHPASSWORD mustChPassword);

/**
 * Set maximum password age option and value
 *
 * @param[out]   pShadow   The opaque pointer of shadow, must not by NULL.
 * @param[in]    passwordMaxAge   set maximum age or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SLIBUserShadowPasswordMaxAgeSet(PSYNOSHADOW pShadow, const SYNOPASSWORDMAXAGE passwordMaxAge);

/**
 * Check if any field in @p pShadow is set to "no change".
 *
 * @param[in]   pShadow   The opaque pointer of shadow, must not by NULL.
 *
 * @retval   TRUE There is some field in @p pShadow that is "no change".
 * @retval   FALSE Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SLIBUserShadowIsEveryFieldSet(const PSYNOSHADOW pShadow);

/**
 * Check whether the user uid @p uid is a local user.
 *
 *
 * @param[in]   uid   User uid.
 *
 * @retval   TRUE   @p uid is local user uid.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SLIBUserIsLocalUid(const uid_t uid);

#ifdef SYNOSDK_LOCAL_ACCOUNT

/**
 * Open temporary files @p rgpFile for writing.
 * Items in every parameter must be one-to-one mapping.
 * Last element of @p rgszFileName should be NULL to indicate end of array.
 * Temporary file names are concatenation of @p rgszFileName and @p szSuffix.
 *
 * @param[in,out]   rgpFile   Opened file pointers, must not be NULL.
 * @param[in]   rgszFileName   Main config file names, must not be NULL.
 * @param[in]   szSuffix   Suffix used to open temporary files, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOTmpFilesOpen(FILE **rgpFile, const char **rgszFileName, const char *szSuffix);

/**
 * Close and rename temporary files @p rgpFile to replace the original ones; namely, @p rgszFileName. Then chmod() to @p rgFileMode.
 * Items in every parameter must be one-to-one mapping.
 * Last element of @p rgszFileName should be NULL to indicate end of array.
 * Temporary file names are decided by the concatenation of @p rgszFileName and @p szSuffix.
 * Every element in @p rgpFile will be closed and reset to NULL.
 *
 * @param[in,out]   rgpFile   Opened file pointers, must not be NULL.
 * @param[in]   rgszFileName   Main config file names, must not be NULL.
 * @param[in]   szSuffix   Suffix used to open temporary files, must not be NULL.
 * @param[in]   rgFileMode   Mode/Permission of main config files, must not be NULL.
 * @param[in]   blClearOnly   TRUE to close and remove temporary files without rename.
 *
 * @note All temporary files will be removed.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOTmpFilesRename(FILE **rgpFile, const char **rgszFileName, const char *szSuffix, const mode_t *rgFileMode, BOOL blClearOnly);

/**
 * Check whether "non-domain" user @p szNameUpper exists in user DB @pdbUser.
 * If the answer is yes and @p szRealName is not NULL, store real user name in @p szRealName.
 *
 * @param[in]   pdbUser   User DB handle, must not be NULL.
 * @param[in]   szNameUpper   User name in upper case, must not be NULL.
 * @param[out]   szRealName   Real user name if not NULL.
 * @param[in]   cbRealName   Size of @p szRealName, must >0 if @p szRealName isn't NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOUserDbCheckExist(const PSYNOUSERDB pdbUser, const char *szNameUpper, char *szRealName, size_t cbRealName);

/**
 * Close and free user DB handle @p pdbUser.
 *
 * @param[in]   pdbUser   User DB handle, NULL input results in nothing.
 */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOUserDbClose(const PSYNOUSERDB pdbUser);

/**
 * Delete local user @p szNameUpper from user DB @p pdbUser.
 *
 *
 * @param[in,out]   pdbUser       User DB handle, must not be NULL.
 * @param[in]       szNameUpper   User name in upper case, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserDbDelete(const PSYNOUSERDB pdbUser, const char *szNameUpper);

/**
 * Dump user DB @p pdbUser into corresponding config files.
 *
 *
 * @param[in]   pdbUser   User DB handle, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserDbDump(const PSYNOUSERDB pdbUser);

/**
 * Get info of user @p szNameUpper (name in upper case) from user DB @p pdbUser then store result in @p ppUser.
 * If success, non-NULL @p *ppUser will be freed then re-allocated; otherwise, no change.
 *
 *
 * @param[in]    pdbUser       User DB handle, must not be NULL.
 * @param[in]    szUpperKey    User name in upper case, must not be NULL.
 * @param[out]   ppUser        Result PSYNOUSER, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserDbGet(const PSYNOUSERDB pdbUser, const char *szUpperKey, PSYNOUSER *ppUser);

/**
 * Get a free uid @p free_uid from user DB @p pdbUser.
 * @p free_uid is reserved for you only if you have exclusively locked @p pdbUser first.
 *
 *
 * @param[in]    pdbUser    User DB handle, must not be NULL.
 * @param[out]   free_uid   Free uid, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOUserDbGetFreeUid(const PSYNOUSERDB pdbUser, uid_t *free_uid);

/**
 * Open/Create user DB and return it.
 * Exam its validness at the same time.
 *
 * @param[in]   flag   The flag to open database. Must be either O_RDONLY or O_RDWR.
 *
 * @retval   !NULL Opened user DB handle.
 * @retval   NULL On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOUSERDB SYNOUserDbOpen(int flag);

/**
 * Insert local user into user DB @p pdbUser according to
 * @p pUser and @p pShadow.
 *
 *
 * @param[in]   pdbUser   User DB handle, must not be NULL.
 * @param[in]   pUser   The user to be stored, must not be NULL.
 * @param[in]   pShadow   The user shadow settings, must not be NULL.
 *
 * @note This function is not reentrant due to the use of crypt() in WrapSha512Encrypt().
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOUserDbInsert(PSYNOUSERDB pdbUser, const PSYNOUSER pUser, const PSYNOSHADOW pShadow, int iMinAge, int iMaxAge);

/**
 * Update local user @p szOldNameUpper in user DB @p pdbUser according to
 * @p pUser and @p pShadow.
 *
 *
 * @param[in]   pdbUser   User DB handle, must not be NULL.
 * @param[in]   szOldNameUpper   User name in upper case, must not be NULL.
 * @param[in]   pUser   The user to be stored, must not be NULL.
 * @param[in]   pShadow   User shadow settings, must not be NULL.
 *
 * @note This function is not reentrant due to the use of crypt() in WrapSha512Encrypt().
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOUserDbUpdate(PSYNOUSERDB pdbUser, const char *szOldNameUpper, const PSYNOUSER pUser, const PSYNOSHADOW pShadow, int iMinAge, int iMaxAge);

/**
 * Parse @p szPacked from user's smbpasswd BDB and return result SYNOSMBPASSWD.
 * Use free() to free SYNOSMBPASSWD returned from this function.
 *
 * @param[in]  szPacked   Data to be parsed, must not be NULL.
 *
 * @retval   NULL   Pointer to SYNOSMBPASSWD, must be freed by caller.
 * @retval   !NULL  On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) SYNOSMBPASSWD *SYNOUserUnpackSmbPasswd(const char *szPacked);

/**
 * Parse @p szPacked from user's passwd BDB and return result struct spwd.
 * Use free() to free struct spwd returned from this function.
 *
 * @param[in]  szPacked   Data to be parsed, must not be NULL.
 *
 * @retval   NULL   Pointer to struct spwd, must be freed by caller.
 * @retval   !NULL  On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) struct spwd *SYNOUserUnpackShadow(const char *szPacked);
#endif // SYNOSDK_LOCAL_ACCOUNT

#ifdef SYNOSDK_BUILD_USER_DB

/**
 * Rebuild user DB files by writing to tmp DB files then rename.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBUserDbBuild();
#endif // SYNOSDK_BUILD_USER_DB

/**
 * @}
 */
