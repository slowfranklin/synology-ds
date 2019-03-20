/**
 * @addtogroup APPPRIVILEGE
 *
 * @{
 */

/**
 * Set all application privilege rules which stored in @p pDListRule
 *
 * @param[in]   pDListRule   A doule link-list which stores rules.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleSet(const PSLIBCDLIST pDListRule);

/**
 * Set one application privilege rules to db.
 *
 * @param[in]   pRule   a rule.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleSetOne(const PSYNO_APPPRIV_RULE pRule);

/**
 * Allow @p pszPrivilegeName from user @p pszUsername.
 *
 * @param[in]   pszUsername   User name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivUserAddOne(const char *pszUsername, const char *pszPrivilegeName);

/**
 * Allow @p pszPrivilegeName from group @p pszGroupname.
 *
 * @param[in]   pszGroupname   Group name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivGroupAddOne(const char *pszGroupname, const char *pszPrivilegeName);

/**
 * Deny @p pszPrivilegeName from user @p pszUsername.
 *
 * @param[in]   pszUsername   User name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivUserDenyOne(const char *pszUsername, const char *pszPrivilegeName);

/**
 * Deny @p pszPrivilegeName from group @p pszGroupname.
 *
 * @param[in]   pszGroupname   Group name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivGroupDenyOne(const char *pszGroupname, const char *pszPrivilegeName);

/**
 * Delete @p pszPrivilegeName from user @p pszUsername.
 *
 * @param[in]   pszUsername   User name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivUserDelOne(const char *pszUsername, const char *pszPrivilegeName);

 /**
 * Delete @p pszPrivilegeName from group @p pszGroupname.
 *
 * @param[in]   pszGroupname   Group name, must not be NULL.
 * @param[in]   pszPrivilegeName   Privilege name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivGroupDelOne(const char *pszGroupname, const char *pszPrivilegeName);

/**
 * Delete all application rule from user @p pszUsername.
 *
 * @param[in]   pszUsername   User name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivUserDel(const char *pszUsername);

/**
 * Delete all application rule from group @p pszGroupname.
 *
 * @param[in]   pszGroupname   Group name, must not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivGroupDel(const char *pszGroupname);

/**
 * Get all app priv rule in db.
 *
 * @param[in]   pList   double link list store all rules
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleList(PSLIBCDLIST pList);

/**
 * Allocate a SYNO_APPPRIV_RULE.
 *
 * @retval !NULL A new SYNO_APPPRIV_RULE..
 * @retval NULL on error.
 *
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) PSYNO_APPPRIV_RULE SLIBAppPrivRuleAlloc();

/**
 * Free a SYNO_APPPRIV_RULE.
 *
 * @param[in]   pRule   a rule to be freed.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) void SLIBAppPrivRuleFree(PSYNO_APPPRIV_RULE pRule);

/**
 * Delete app priv rules in db.
 *
 * @param[in]   pList   double link list store delete rules
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleDel(PSLIBCDLIST pList);

/**
 * Delete a app priv rule in db.
 *
 * @param[in]   pRule   rule
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleDelOne(const PSYNO_APPPRIV_RULE pRule);

/**
 * Get rule with specified @p @szUsername and append in @p @pList.
 *
 * @param[in]   szUsername   query user name, can be NULL
 * @param[in]   pList   double link list store all result
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleUserGet(const char *szUsername, PSLIBCDLIST pList);

/**
 * Get rule with specified @p @szGroupname and append in @p @pList.
 *
 * @param[in]   szGroupname   query group name, can be NULL
 * @param[in]   pList   double link list store all result
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleGroupGet(const char *szGroupname, PSLIBCDLIST pList);

/**
 * Get default user application privilege and append in @p @pList.
 *
 * @param[in]   pList   double link list store all result
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleDefaultGet(PSLIBCDLIST pList);

/**
 * Get user @szUsername application preview privilege from @szIP.
 * Return a PSLIBSZHASH: key application name and value privilege (allow or deny).
 *
 * @param[in]   szUsername   User name, must not be NULL.
 * @param[in]   szIP   Query IP, must not be NULL
 *
 * @retval   NULL    On error.
 * @retval   !NULL   PSLIBSZHASH as a mapping between application name and privilege.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) PSLIBSZHASH SLIBAppPrivUserHashGet(const char *szUsername, const char *szIP);

/**
 * Get groups @p pGrpNameList application preview privilege from @szIP.
 * Return a PSLIBSZHASH: key application name and value privilege (allow or deny).
 *
 * @param[in]   pGrpNameList   Group name list, must not be NULL.
 * @param[in]   szIP           Query IP, must not be NULL
 * @param[in]   blInclude      result include everyone or not
 *
 * @retval   NULL     On error.
 * @retval   !NULL    PSLIBSZHASH as a mapping between application name and privilege.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) PSLIBSZHASH SLIBAppPrivGroupPreviewHashGet(const PSLIBSZLIST pGrpNameList, const char *szIP, BOOL blInclude);

/**
 * Get user @szUsername allow application from @szIP.
 * Return a PSLIBSZLIST: allow application list.
 *
 * @param[in]   szUsername   User name, must not be NULL.
 * @param[in]   szIP   Query IP, must not be NULL
 *
 * @retval   NULL     On error.
 * @retval   !NULL    PSLIBSZLIST stores all allow application names.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) PSLIBSZLIST SLIBAppPrivUserListGet(const char *szUsername, const char *szIP);

/**
 * Check whether user @p szUsername has app privilege @p szAppName from @p szIP
 * SZ_DEFUSER has all privilege while SZ_GUEST has nothing.
 *
 * @param[in]   szUsername   User name, must not be NULL.
 * @param[in]   szAppName   Application name, must not be NULL.
 * @param[in]   szIP   Query IP, must not be NULL
 *
 * @retval   TRUE   @p szUsername has privilege @p szAppName from @p szIP.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) BOOL SLIBAppPrivUserHas(const char *szUsername, const char *szAppName, const char *szIP);

/**
 * Allocate a PSLIBCDLIST list of app privilege rules.
 *
 * @retval !NULL A PSLIBCDLIST list of rules.
 * @retval NULL On error.
 *
 * @exception SLIBCDListAlloc()
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) PSLIBCDLIST SLIBAppPrivDListAlloc();

/**
 * Get app @p szAppName priv rule in db.
 *
 * @param[in]    szAppName   The app name.
 * @param[out]   pList       Double link list to store all the rules.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivRuleListByApp(const char *szAppName, PSLIBCDLIST pList);

/**
 * Delete an array of uid @p arrUid from app privilege database.
 *
 * @param[in]   arrUid   The array of uid to be deleted.
 * @param[in]   nItem    The number of uids in @p arrUid.
 *
 * @retval  0   On Success
 * @retval  -1  On error.
 *
 * @exception BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBAppPrivUidDel(const uid_t *arrUid, const int nItem);

/**
 * List all priv rules in db by given type (user/group) @p rule_type with app @p szAppName and filter @p filter_type.
 *
 * @param[in]       szAppName     application id, should not be NULL
 * @param[in]       rule_type     rule type, should be RULE_USER or RULE_GROUP
 * @param[in]       filter_type   filter type: any, allow, deny and custom
 * @param[in,out]   pList         double link list store all rules
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SLIBAppPrivRuleListByAppFilter(const char *szAppName, const RULE_TYPE rule_type, const RULE_FILTER_TYPE filter_type, PSLIBCDLIST pList);

/**
 * Convert @p oldAppPrivilege, represented by integer, to current representation.
 * Result is a PSLIBSZLIST which must be freed by caller.
 *
 * @param[in]   oldAppPrivilege   Old app privilege representation.
 *
 * @retval   NULL    On error.
 * @retval   !NULL   PSLIBSZLIST contains result privileges, must be freed by caller.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSLIBSZLIST SLIBAppPrivConvertOld(int oldAppPrivilege);

/**
 * Get default user app privileges.
 *
 * @retval   NULL    On error.
 * @retval   !NULL   PSLIBSZLIST contains sorted default privileges, must be freed by caller.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSLIBSZLIST SLIBAppPrivGetDefault(void);

/**
 * Check whether app privilege of user @p pszUsername has ever been set.
 * SZ_DEFUSER and SZ_GUEST are always "not set".
 *
 * @param[in]   pszUsername   User name, must not be NULL.
 *
 * @retval   TRUE   App privilege of @p pszUsername has been set.
 * @retval   FALSE  Otherwise.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SLIBAppPrivUserExist(const char *pszUsername);

/**
 * Paging Enum users with/without application privilege @szPrivilege and auth type @auth.
 * NULL @szPrivilege means any privilege and result will be put in @ppUserList.
 * Besides, non-empty @ppUserList will be cleared first.
 *
 * @param[out]   ppUserList   Result user list, can't be NULL
 * @param[in]    start        Paging start; 0 <= start
 * @param[in]    limit        Paging limit; 0 > limit means get all
 * @param[in]    type         User auth type
 * @param[in]    szPrivilege  Name of privilege, NULL means any
 * @param[in]    blInclude    TRUE to include, FALSE to exclude
 * @param[in]    szQuery      sub string for search
 * @param[in]    szDomain     Domain Netbios Name
 *
 * @retval  >=0   total user number
 * @retval  -1    On error
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBAppPrivPagingUserEnum(PSLIBSZLIST *ppUserList, int start, int limit, AUTH_TYPE type, const char *szPrivilege, BOOL blInclude, const char *szQuery, const char *szDomain);

/**
 * Enum users with/without application privilege @szPrivilege and auth type @auth.
 * NULL @szPrivilege means any privilege and result will be put in @ppUserList.
 * Besides, non-empty @ppUserList will be cleared first.
 *
 * @param[out]   ppUserList   Result user list, can't be NULL
 * @param[in]   szPrivilege   Name of privilege, NULL means any
 * @param[in]   auth   User auth type
 * @param[in]   blInclude   TRUE to include, FALSE to exclude
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBAppPrivUserEnum(PSLIBSZLIST *ppUserList, const char *szPrivilege, AUTH_TYPE auth, BOOL blInclude);

/**
 * @}
 */
