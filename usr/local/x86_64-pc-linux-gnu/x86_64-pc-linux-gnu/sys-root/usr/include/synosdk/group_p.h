/**
 * @addtogroup GROUP
 *
 * @{
 */

/**
 * Frees a Synology Group structure.
 *
 * @param[in,out]   pGroup   The Synology Group struct. Should not be NULL.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOGroupFree(void *pGroup);

/**
 * Obtains the group information according to the group name you
 * specify in @p szGroupName argument from a opened SYNOGROUPDB
 * handle @p pGroupDb.  The return information will save in @p
 * ppGroup argument and it's allocated size stored into @p
 * pcbGroupSize.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group. Otherwise, @p *ppGroup is not NULL, this function
 * will check SYNOGROUP::nAlloc is large enough to store this
 * group information.  When the size is bigger than we need, we
 * will copy share information into @p *ppGroup. When the size
 * is smaller than we need, this function will reallocf() for it
 * and update SYNOGROUP::nAlloc accordingly.
 *
 * @param[in]        szGroupName The string that contains Group name. Should not be NULL.
 * @param[in,out]    ppGroup     The pointer that this share to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_GROUP
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupGetLocal(const char *szGroupName, PSYNOGROUP *ppGroup);

/**
 * Obtains the group information according to the group name you
 * specify in @p szGroupName argument.
 *
 * This function calls SYNOGroupGetLocal() to lookup the group
 * information for local group. If lookup failed, it returns -1.
 * For non-local account, it calls SYNOGroupGetNss() to lookup
 * group through name service.
 *
 * The return information will save in @p ppGroup argument and
 * it's allocated size stored into @p * pcbGroupSize.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group. Otherwise, @p *ppGroup is not NULL, this function
 * will check SYNOGROUP::nAlloc is large enough to store this
 * group information.  When the size is bigger than we need, we
 * will copy share information into @p *ppGroup. When the size
 * is smaller than we need, this function will reallocf() for it
 * and update SYNOGROUP::nAlloc accordingly.
 *
 * By default, the groupname is assumed to be caseless compared.
 * However, it strongly depends on the implementation of
 * name service plugin modules (nss_xxx.so).
 * We've tested the comparison in nss_winbindd (winbindd) and
 * nss_ldap (nslcd). They are both in caseless maner.
 *
 * @param[in]       szGroupName   The string that contains Group name. Should not be NULL.
 * @param[in,out]   ppGroup       The pointer that this share to be stored. Should not be NULL.
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
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupGet(const char *szGroupName, PSYNOGROUP *ppGroup);

/**
 * Obtains the Group information according to the Group ID you
 * specify in @p nGroupID argument.  The return information will
 * save in @p ppGroup argument.
 *
 * This function will call SYNOGroupDbOpen() at begining to
 * get the PSYNOGROUPDB handler and call SYNOGroupDbClose()
 * after done.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group. Otherwise, @p *ppGroup is not NULL, this function
 * will check SYNOGROUP::nAlloc is large enough to store this
 * share information.  When the size is bigger than we need, we
 * will copy share information into @p *ppGroup and update
 * SYNOGROUP::nUsed to the size it actually is. When
 * SYNOGROUP::nAlloc is smaller than we need, this function will
 * reallocf() for it and update SYNOGROUP::nAlloc and
 * SYNOGROUP::nUsed accordingly.
 *
 * @param[in]    nGroupID  The Group ID. Should be a positive.
 * @param[out]   ppGroup   The pointer that this group to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NO_SUCH_GROUP
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupGetLocalByGID(gid_t nGroupID, PSYNOGROUP *ppGroup);

/**
 * Obtains the Group information according to the Group ID you
 * specify in @p nGroupID argument.  The return information will
 * save in @p ppGroup argument.
 *
 * This function calls SYNOGroupGetLocalByGID() to lookup the group
 * information first. When success it returns the obtained information;
 * otherwise it calls SYNOGroupGetNssByGID() to lookup group
 * through name service.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group. Otherwise, @p *ppGroup is not NULL, this function
 * will check SYNOGROUP::nAlloc is large enough to store this
 * share information.  When the size is bigger than we need, we
 * will copy share information into @p *ppGroup and update
 * SYNOGROUP::nUsed to the size it actually is. When
 * SYNOGROUP::nAlloc is smaller than we need, this function will
 * reallocf() for it and update SYNOGROUP::nAlloc and
 * SYNOGROUP::nUsed accordingly.
 *
 * @param[in]   nGroupID   The Group ID. Should be a positive.
 * @param[out]   ppGroup   The pointer that this group to be stored. Should not be NULL.
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
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupGetByGID(gid_t nGroupID, PSYNOGROUP *ppGroup);

/**
 * Enumerates the member of group @p szGroup into SZLIST @p
 * pslMember. If @p szGroup is SZ_DEFGRP, then enumerates all
 * local users. Otherwise, check each member of @p szGroup is in
 * /etc/passwd then insert into @p pslMember.
 *
 * @param[in]   szGroup   The UTF-8 string that is group name.
 * @param[out]   ppslMember   The pointer to SZLIST that will store the user names that is valid.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBUserEnum()
 * @exception SYNOGroupGet()
 * @exception SLIBCStrSep()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupListMember(const char *szGroup, PSLIBSZLIST *ppslMember);

/**
 * Obtains the gid of local or domain group.
 *
 * @param[in]    szGroupName  The group name.
 * @param[out]   gid          GID_ERR means not such user
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
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupGetGID(const char *szGroupName, gid_t *gid);

/**
 * Get and Create group's perference directory
 *
 * @param[in]   szGroupName   Group name
 * @param[out]   szPath   The value of the group preference dir
 * @param[in]   cbPath   The size of @p szPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_GROUP
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupPreferenceDirGet(const char *szGroupName, char *szPath, const int cbPath);

/**
 * Reports how many valid local admins in DS.
 * The valid local admin means the local admins
 * who are not expired yet.
 * There is at least one valid local admin on DS.
 *
 * @retval    >0 number of valid local admins.
 * @retval    0 error
 *
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_RESERVED_GROUP
 * @exception SYNOGroupGetGID()
 * @exception SYNOGroupListMember()
 * @exception SYNOUserGet()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupTotalValidLocalAdmin(void);

/**
 * Obtains the Group description of Group @p szGroup and saves
 * into the string buf pointed by @p pszDesc.  When success,
 * returns the string length of description in bytes.  When
 * encounters an error, return -1.
 *
 * If @p *pszDesc is NULL, this function will allocates for
 * this string. Otherwise, @p *pszDesc is not NULL, this
 * function will check @p *pcbSize is large enough to store this
 * share information.  When the size is bigger than we need, we
 * will copy Group description into @p *pszDesc and returns the
 * size it actually is. When @p *pcbSize is smaller than we
 * need, this function will reallocf() for it and update @p
 * *pcbSize accordingly.
 *
 * @param[in]   szGrpName   The UTF-8 string that contains Group name.  Should not be NULL.
 * @param[out]   pszDesc   The pointer to UTF-8 string that will be stored the Group description.  Should not be NULL.
 * @param[out]   pcbSize   The pointer to number that is the length of this string buf.
 *                         The maximum length of this string is SYNO_GROUPDESC_UTF32_MAX in Unicode characters or SYNO_GROUPDESC_UTF8_MAX in bytes. Should not be NULL.
 *
 * @retval   -1          On error
 * @retval   Otherwise   The description length.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 *
 * @see SYNO_GROUPDESC_UTF32_MAX
 * @see SYNO_GROUPDESC_UTF8_MAX
 * @see SYNOGroupDescSet()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupDescGet(const char *szGrpName, char **pszDesc, size_t *pcbSize);

/**
 * Gets the total number of groups in server.
 *
 * @param[in]   authType   The AUTH_TYPE. Should be AUTH_LOCAL, AUTH_DOMAIN, or the union.
 *
 * @retval    -1 On error.
 * @retval    Otherwise The total number of groups.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBGroupEnum()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupTotalNum(AUTH_TYPE authType);

/**
 * Check if @p szGroup is one of admin groups in local/ldap/domain.
 *
 * @param[in]   szGroup   The groupname to be checked. Should not be NULL.
 *
 * @retval    1 @p szGroup is one of admin groups
 * @retval    0 @p szGroup is not one of admin groups
 * @retval    -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOGroupIsLocalAdminGroup
 * @exception SYNOGroupIsDomainAdminGroup
 * @exception SYNOGroupIsLDAPAdminGroup
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupIsAdminGroup(const char *szGroup);

/**
 * Check if the group with @p gid is an Local or Domain or
 * LDAP admin group.
 *
 * @param[in]   gid   The gid to be checked.
 *
 * @retval    1 the group with @p gid is an admin group
 * @retval    0 the group with @p gid is not an admin group
 * @retval    -1 error
 *
 * @exception SYNOGroupGetByGID()
 * @exception SYNOGroupIsAdminGroup()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGroupIsAdminGroupByGid(const gid_t gid);

/**
 * Allocates a SYNOGROUP from another SYNOGROUP members.
 * The return information will save in @p ppGroup argument.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group information. Otherwise, @p *ppGroup is not NULL,
 * this function will check SYNOGROUP::nAlloc is large enough to
 * store this group information. When the size is bigger than we
 * need, we will copy group information into @p *ppGroup. When
 * the size is smaller than we need, this function will
 * reallocf() for it and update SYNOGROUP::nAlloc accordingly.
 *
 * @param[out]   ppGroup      The pointer that this group to be stored. Should not be NULL.
 * @param[in]    szName       The name of SYNOGROUP. Should not be NULL.
 * @param[in]    nGid         The gid of SYNOGROUP.
 * @param[in]    rgszMember   The mamber array of SYNOGROUP. The end element should be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCCheckAndRealloc()
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupAlloc(PSYNOGROUP *ppGroup, const char *szName, gid_t nGid, char **rgszMember);

/**
 * Check if @p szUser is a member of the admin group.
 *
 * Admin group includes members of
 * 1. local group: SZ_ADMINGRP
 * 2. domain groups: SZ_DOMAIN_ADMINS and SZ_ENTERPRISE_ADMINS
 *
 * @param[in]   szUser       The username to be checked. Should not be NULL.
 * @param[in]   blRealTime   If FALSE, try to read cache file first; FALSE to ignore cache file and query ad/ldap server directly/
 *
 * @retval    1    @p szUser is a member of the admin group
 * @retval    0    @p szUser is not a member of the admin group
 * @retval    -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_ACCESS_DENIED
 *
 * @grantable No (see below)
 * @user system (need root permission to write cache)
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupIsAdminGroupMem(const char *szUser, BOOL blRealTime);

/**
 * Check whether user with uid @p uid is member of the admin group.
 * Convert @p uid to user name then use SLIBGroupIsAdminGroupMem().
 *
 * @param[in]   uid   The uid to be checked.
 * @param[in]   blRealTime   FALSE to lookup in cache file first, then query LDAP/domain server.
 *
 * @retval   1  @p uid is member of admin group.
 * @retval   0  @p uid is not member of admin group.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupIsAdminGroupMemByUid(uid_t uid, BOOL blRealTime);

/**
 * Lookup groups of user @p szUserName through name service.
 * Return a PSLIBSZLIST of group names or gids depends on @p blGroupName.
 * Case of result group names depends on how GetGroupNameFromGid works.
 *
 * @param[in]   szUserName   User name, must not be NULL.
 * @param[in]   blGroupName   TRUE to get group names; otherwise, gids.
 *
 * @retval   NULL On error.
 * @retval   Othersiwe PSLIBSZLIST contains group names or gids.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) PSLIBSZLIST SLIBGroupInfoListGet(const char *szUserName, BOOL blGroupName);

/**
 * Lookup groups of user @p szUserName through name service.
 * Return a PSLIBSZHASH as a mapping between group name and gid.
 * Use group name as key if @p blNameAsKey is TRUE; otherwise, use gid.
 * Turn group names into upper case if @p blNameAsKey is TRUE; otherwise, depends on how GetGroupNameFromGid works.
 *
 * @param[in]   szUserName   User name, must not be NULL.
 * @param[in]   blNameAsKey   TRUE to use group name as key; otherwise, use gid.
 * @param[in]   blNameInUpperCase   Whether to turn result group name into upper case.
 *
 * @retval   NULL On error.
 * @retval   Othersiwe PSLIBSZHASH as a mapping between group name and gid.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) PSLIBSZHASH SLIBGroupInfoHashGet(const char *szUserName, BOOL blNameAsKey, BOOL blNameInUpperCase);

/**
 * Get all groups with auth type @p authType and store result group names in @p pplistGroupName.
 * Group names in @p pplistGroupName are real names from group DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistGroupName   List of result group names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 *
 * @retval   >=0 Number of enumerated groups.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupEnum(PSLIBSZLIST *pplistGroupName, AUTH_TYPE authType, const char *szDomain);

/**
 * Get all groups with auth type @p authType and store result group names in @p pplistGroupName.
 * Result group names are prefixed by @p szPrefix, @ blCaseLess.
 * Group names in @p pplistGroupName are real names from group DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistGroupName   List of result group names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   szPrefix   Prefix to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 *
 * @retval   >=0 Number of enumerated groups.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupEnumByPrefix(PSLIBSZLIST *pplistGroupName, AUTH_TYPE authType, const char *szDomain, const char *szPrefix, BOOL blCaseLess);

/**
 * Get all groups with auth type @p authType and store result group names in @p pplistGroupName.
 * Result group names contain sub-string @p szSubstr, @ blCaseLess.
 * Group names in @p pplistGroupName are real names from group DB.
 * @p szDomain specifies which domain to enumerate. This is ignored when @p authType contains no AUTH_DOMAIN or domain is not joined.
 *
 * @param[out]   pplistGroupName   List of result group names, must not be NULL
 * @param[in]   authType   Auth type.
 * @param[in]   szDomain   Domain name, NULL or empty string means all domains.
 * @param[in]   szSubstr   Sub-string to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 *
 * @retval   >=0 Number of enumerated groups.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupEnumBySubstr(PSLIBSZLIST *pplistGroupName, AUTH_TYPE authType, const char *szDomain, const char *szSubstr, BOOL blCaseLess);

/**
 * Enumerate all groups with auth type @p authType and paging.
 * Only group names contain prefix @p szPrefix, @p blCaseLess are taken into consideration.
 *
 * For each group that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pGroup is result PSYNOGROUP and @p idx is index of @p pGroup in all enumerated users.
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
 * @retval   >=0 Total number of groups with prefix @p szPrefix.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBGroupInfoEnumByPrefix(AUTH_TYPE authType, const char *szDomain, int start, int limit, const char *szPrefix, BOOL blCaseLess, GroupEnumCallback callback, void *data);

/**
 * Enumerate all groups with auth type @p authType and paging.
 * Only group names contain sub-string @p szSubstr, @p blCaseLess are taken into consideration.
 *
 * For each group that in the paging interval, invoke @p callback(@p pUser, @p idx, @p data) where
 * @p pGroup is result PSYNOGROUP and @p idx is index of @p pGroup in all enumerated users.
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
 * @param[in]   szSubstr   Sub-string to match, must not be NULL.
 * @param[in]   blCaseLess   The match is caseless or not.
 * @param[in]   callback   Callback function, must not be NULL.
 * @param[in]   data   Additional data passed to @p callback.
 *
 * @retval   >=0 Total number of groups with substring @p szSubstr.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupInfoEnumBySubstr(AUTH_TYPE authType, const char *szDomain, int start, int limit, const char *szSubstr, BOOL blCaseLess, GroupEnumCallback callback, void *data);

/**
 * Get extra admin (local/domain/LDAP uid/gid) for @p category.
 * This function uses reallocf() to re-allocate @p *ppLocalUid/@p *ppLocalGid/@p *ppDirUid/@p *ppDirGid if not NULL.
 *
 * @note Give NULL for settings you're not interested in and free @p *ppLocalUid, @p *ppLocalGid, @p *ppDirUid, @p *ppDirGid by yourself.
 *
 * @param[in]    category     Category (eg. SZ_EXTRA_ADMIN_CMS). Must not be NULL or empty string.
 * @param[out]   ppLocalUid   List of local uid if not NULL.
 * @param[out]   ppLocalGid   List of local gid if not NULL.
 * @param[out]   ppDirUid     List of domain/LDAP uid if not NULL.
 * @param[out]   ppDirGid     List of domain/LDAP gid if not NULL.
 *
 * @retval   1 On success.
 * @retval   0 No extra admin settings for @p category.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupExtraAdminGet(const char *category, unsigned int **ppLocalUid, unsigned int **ppLocalGid, unsigned int **ppDirUid, unsigned int **ppDirGid);

/**
 * Append CMS delegated admin user/group names to @p ppslUser/@p ppslGroup if @p ppslUser/@p ppslGroup is not NULL and join to some CMS server.
 * This function won't expand group members. Pass NULL to arguments you're not interested in.
 *
 * @note @p blRealName only works for user names in @p ppslUser.
 * @see SYNOGroupExtraAdminGetNames().
 *
 * @param[in]    blLocal      TRUE to get local user/group; otherwise, get domain/LDAP user/group.
 * @param[out]   ppslUser     CMS admin user names.
 * @param[out]   ppslGroup    CMS admin group names.
 * @param[in]    blRealName   TRUE to get real name for CMS admin users.
 *
 * @retval   1 On Success.
 * @retval   0 Not join to CMS or no CMS admin settings.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGroupCmsAdminGetNames(BOOL blLocal, PSLIBSZLIST *ppslUser, PSLIBSZLIST *ppslGroup, BOOL blRealName);

/**
 * Get real group name of @p szName for local/LDAP/domain groups.
 * This function will acquire shared lock on group DB for non-domain group.
 *
 * @param[in]    szName       Group name, must not be NULL.
 * @param[out]   szRealName   Real group name, must not be NULL.
 * @param[in]    cbRealName   Size of @p szRealName, must >0.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBGroupRealNameGet(const char *szName, char *szRealName, size_t cbRealName);

/**
 * Get "admin users" in the smb.conf global section. The value of
 * "admin users" is seperated into @p ppslGroups and @p ppslUsers.
 *
 * @param[out]   ppslGroups    The list to contain group names, and the group names are NOT start with "@". Should not be NULL.
 * @param[out]   ppslUsers     The list to contain user names, should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCListDBGet()
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOGroupDomainAdminListGet(PSLIBSZLIST *ppslGroups, PSLIBSZLIST *ppslUsers);

/**
 * Check whether the group gid @p gid is a reserved for local group.
 *
 * @param[in]   gid   Group's gid
 *
 * @retval   TRUE    @p szName is reserved.
 * @retval   FALSE   Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) BOOL SYNOGroupIsReservedLocalGid(gid_t gid);

/**
 * Check whether the group with name @p szName and gid @p gid is a internal group (neither system nor normal).
 *
 * @param[in]   szName   Group name, must not be NULL.
 * @param[in]   gid   GID to check.
 *
 * @retval  TRUE   Internal group.
 * @retval  FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOGroupIsInternal(const char *szName, gid_t gid);

/**
 * Check whether the group with name @p szName and gid @p gid is a system group.
 *
 * @param[in]   szName   Group name, must not be NULL.
 * @param[in]   gid   Group's gid, must not be UID_ERR.
 *
 * @retval   TRUE   System group.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOGroupIsReserved(const char *szName, gid_t gid);

/**
 * Get group name from gid.
 *
 * If the gid is large enough, this function will try to get domain group name without
 * getting the group members, which can speed up substantially. If fail to get domain
 * group name, fall back to SYNOGroupGetByGID(), which will get the group name with
 * all the group members.
 *
 * @param[in]   gid            The gid.
 * @param[out]  szGroupName    The buffer to store the group name.
 * @param[in]   cbGroupName    Number of bytes in @p szGroupName.
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
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupGIDToName(gid_t gid, char *szGroupName, int cbGroupName);

/**
 * Check whether the group gid @p gid is a local group.
 *
 * @param[in]   gid   Group gid.
 *
 * @retval   TRUE   @p gid is local gid.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SLIBGroupIsLocalGid(const gid_t gid);

#ifdef SYNOSDK_LOCAL_ACCOUNT
/**
 * Check whether "non-domain" group @p szNameUpper exists in group DB @p pdbGroup.
 * If the answer is yes and @p szRealName is not NULL, store real group name in @p szRealName.
 *
 * @param[in]   pdbGroup     Group DB handle, must not be NULL.
 * @param[in]   szNameUpper  Group name in upper case, must not be NULL.
 * @param[out]  szRealName   Real group name if not NULL.
 * @param[in]   cbRealName   Size of @p szRealName, must >0 if @p szRealName isn't NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOGroupDbCheckExist(const PSYNOGROUPDB pdbGroup, const char *szNameUpper, char *szRealName, size_t cbRealName);

/**
 * Close and free group DB handle @p pdbGroup.
 *
 * @param[in]   pdbGroup   Group DB handle, NULL input results in nothing.
 */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOGroupDbClose(const PSYNOGROUPDB pdbGroup);

/**
 * Delete local group @p szNameUpper from group DB @p pdbGroup.
 *
 * @param[in,out]   pdbGroup      Group DB handle, must not be NULL.
 * @param[in]       szUpperName   Group name in upper case, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbDelete(const PSYNOGROUPDB pdbGroup, const char *szUpperName);

/**
 * Dump group DB @p pdbGroup into corresponding config files.
 *
 * @param[in]   pdb   Group DB handle, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbDump(const PSYNOGROUPDB pdb);

/**
 * Get info of group @p szNameUpper (name in upper case) from group DB @p pdbGroup then store result in @p ppGroup.
 * If success, non-NULL @p *ppGroup will be freed then re-allocated; otherwise, no change.
 *
 * @param[in]    pdbGroup       Group DB handle, must not be NULL.
 * @param[in]    szNameUpper    Group name in upper case, must not be NULL.
 * @param[out]   ppGroup        Result PSYNOGROUP, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbGet(const PSYNOGROUPDB pdbGroup, const char *szNameUpper, PSYNOGROUP *ppGroup);

/**
 * Obtains the group information according to the cursor from a
 * opened SYNOGROUPDB handle @p pGroupDb.  The return
 * information will save in @p ppGroup argument.
 *
 * If @p *ppGroup is NULL, this function will allocates for
 * this group information. Otherwise, @p *ppGroup is not NULL,
 * this function will check SYNOGROUP::nAlloc is large enough to
 * store this group information. When the size is bigger than we
 * need, we will copy group information into @p *ppGroup. When
 * the size is smaller than we need, this function will
 * reallocf() for it and update SYNOGROUP::nAlloc accordingly.
 *
 * This function that want to enumerate all keys should use
 * SLIBCBdbCursorSetType() with
 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_FIRST or
 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_LAST first to guarantee
 * the cursor starting at the position it desired.
 *
 * The SYNOBDB_CURSOR_TYPE defaults to SYNOBDB_CURSOR_NEXT
 * when db open, so there is no need to call
 * SLIBCBdbCursorSetType() if the DB does not come from
 * parameter.
 *
 * Example 1:
 * @code{.c}
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_FIRST);
 * if (0 != SYNOGroupDbGetByCursor()) { // Get the 1-st record
 *     if (ERR_BDB_CURSOR_FINISH != SLIBCErrGet()) {
 *         //Error handling
 *     }
 *     goto ERR;
 * }
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_NEXT);
 *
 * do {
 *     // do something, eg. SLIBCSzListPush();
 * } while(0 == SYNOGroupDbGetByCursor());
 *
 * if (ERR_BDB_CURSOR_FINISH != SLIBCErrGet()) {
 *     // Error handling
 *     got ERR;
 * }
 * @endcode
 *
 * Example 2:
 * @code{.c}
 * pGroupDb = SYNOGroupDbOpen(O_RDONLY);
 *
 * while(0 == SYNOGroupDbGetByCursor()) {
 *     // do something, eg. SLIBCSzListPush();
 * }
 *
 * if (ERR_BDB_CURSOR_FINISH != SLIBCErrGet()) {
 *     // Error handling
 *     got ERR;
 * }
 * @endcode
 *
 * @param[in]     pGroupDb           The PSYNOGROUPDB handler. Should not be NULL.
 * @param[out]    ppGroup            The pointer that this group to be stored. Should not be NULL.
 * @param[in]     authType           The AUTH_TYPE. Matching by SYNOGROUP::authType.
 * @param[in]     blGetSystemGroup   The BOOL that will return the root, smmsp, lp, ... when TRUE.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_BDB_CURSOR_FINISH
 * @exception ERR_NO_SUCH_GROUP
 *
 * @see SYNOGroupGet()
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbGetByCursor(const PSYNOGROUPDB pGroupDb, PSYNOGROUP *ppGroup, AUTH_TYPE authType, BOOL blGetSystemGroup);

/**
 * Get a free gid @p free_gid from group DB @p pdbGroup.
 * @p free_gid is reserved for you only if you have exclusively locked @p pdbGroup first.
 *
 * @param[in]   pdbGroup   Group DB handle, must not be NULL.
 * @param[out]  free_gid   Free gid, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbGetFreeGid(const PSYNOGROUPDB pdbGroup, uid_t *free_gid);

/**
 * Open/Create group DB and return it.
 * Exam its validness at the same time.
 *
 * @param[in]   flag   The flag to open database. Must be either O_RDONLY or O_RDWR.
 *
 * @retval   NULL On error.
 * @retval   !NULL Opened group DB handle.
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOGROUPDB SYNOGroupDbOpen(int flag);

/**
 * Modify or create local group in group DB @p pdbGroup according to @p pGroup.
 * Non-null @p szOldNameUpper indicates the group to be modified; otherwise, insert a new group.
 *
 * @param[in,out]   pdbGroup   Group DB handle, must not be NULL.
 * @param[in]       szOldNameUpper   Group name in upper case, NULL means insert new group.
 * @param[in]       pGroup   The group to be stored, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOGroupDbSet(PSYNOGROUPDB pdbGroup, const char *szOldNameUpper, const PSYNOGROUP pGroup);

/**
 * @brief Check whether @p szUserName a "valid" local admin user.
 *
 * @note It does NOT check whether @p szUserName belongs to SZ_ADMINGRP.
 *       Acutally, it's a helper function for checking valid admin users.
 *
 * By "valid" we means @p szUserName matches ALL following conditions:
 * 1. NOT expired
 * 2. uid passes @a SLIBUserIsLocalUid()
 *
 * @param[in] szUserName  User name, must not be NULL.
 *
 * @return Is "valid" local admin user or not.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOUserGetUGID()
 * @exception SYNOUserCheckExpired()
 *
 * @sa SYNOGroupTotalValidLocalAdmin()
 *
 * @grantable No
 * @apparmor abstractions/synosdk/usergroup
 */
DSM_STARTING_FROM(SDK_VER_6_1) BOOL SYNOGroupIsValidLocalAdmin(const char *szUserName);
#endif // SYNOSDK_LOCAL_ACCOUNT

#ifdef SYNOSDK_BUILD_GROUP_DB

/**
 * Rebuild group DB files by writing to tmp DB files then rename.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBGroupDbBuild();
#endif // SYNOSDK_BUILD_GROUP_DB

/**
 * @}
 */
