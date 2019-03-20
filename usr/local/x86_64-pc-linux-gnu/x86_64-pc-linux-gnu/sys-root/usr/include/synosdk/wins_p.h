/**
 * @addtogroup WINS
 *
 * @{
 */

/**
 * Get domain work group name from smb.conf.
 * The work group name will be placed in @p szWorkgroup.
 *
 * @param[out]   szWorkgroup   The buffer to store the domain group name. Should not be NULL.
 * @param[in]    BuffLen       The number of bytes in @p szWorkgroup. Should be positive.
 *
 * @retval   0   On success.
 * @retval   -1  On failure.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOWorkgroupGet(char *szWorkgroup, int BuffLen);

/**
 * Set the domain work group name in smb.conf.
 *
 * @param[in]    szWorkgroup       The work group name to be set.
 *
 * @retval   0   On success.
 * @retval   -1  On failure.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOWorkgroupSet(const char *szWorkgroup);

/**
 * enum domain list from file
 * If not enable trust domain, will only return join domain
 *
 * @param[out]   pListTrust   domain enum result
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOWinsEnumAllDomains(PSLIBSZLIST *pListTrust);

/**
 * Check Support Key and Trust Domain
 *
 * @retval    TRUE support and enable
 * @retval    FALSE not support or not enable
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOWinIsEnableTrustDomain(void);

/**
 * Set key Trust Domain
 *
 * @param[in]   blEnable   Boolean value to set.
 *
 * @retval    TRUE support and enable
 * @retval    FALSE not support or not enable
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOWinSetTrustDomain(BOOL blEnable);

/**
 * check Domain is join domain or not
 *
 * @param[in]   szDomain   Domain Netbios name
 *
 * @retval    0 success is join domain
 * @retval    -1 fail
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOWinsIsOwnDomain(const char *szDomain);

/**
 * Check if DS joins domain.
 *
 * @retval   TRUE   Joins.
 * @retval   FALSE  Does not join.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOWinsIsJoined(void);

/**
 * Enum domain user/group names with start index @p start, max number of names @limit, substring @p szSubstr, and other parameters.
 *
 * @param[out]  pplistName   The list of strings that stores the enum names of users/groups.
 * @param[in]   UGType       0 means user, 1 means group.
 * @param[in]   start        The start index. Must be non-negative.
 * @param[in]   limit        The max number of names to enum. -1 means no limits.
 * @param[in]   szSubstr     A substring or prefix to match. @p blPrefix determine whether it's substring or prefix. NULL or empty string means enum all.
 * @param[in]   szDomain     A domain to enum. NULL or empty string means all domains.
 * @param[in]   blPrefix     Determine whether @p szSubstr is a substring or prefix.
 * @param[in]   order        1 means in ascending order, 2 means in descending order, 0 means don't care.
 *
 * @retval   TRUE   On success.
 * @retval   FALSE  On error.
 *
 * @exception ERR_NOT_SUPPORT      If DS doesn't support "supporttrustdomain".
 * @exception ERR_DB_BUILDING      The domain database is still building.
 * @exception ERR_FILE_NOT_FOUND   The domain database doesn't exist.
 * @exception ERR_OUT_OF_MEMORY    The memory is not enough for the SQL command.
 * @exception ERR_OPEN_FAILED      Can't open the domain database.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOWinsDomainUGPagingEnum(PSLIBSZLIST *pplistName, int UGType, int start, int limit,const char *szSubstr, const char *szDomain, BOOL blPrefix, int order);

/**
 * Check if a domain user/group @p szName exists and get the real name (i.e. in correct case) of it.
 *
 * @param[in]   pDomainDb   The database handle of domain user/group database.
 * @param[in]   szName      The user/group name to be checked.
 * @param[out]  szRealName  The real name of @p szName.
 * @param[in]   cbRealName  The number of bytes in @p szRealName.
 *
 * @retval   TRUE   The user/group exists.
 * @retval   FALSE  The user/group exists.
 *
 * @exception ERR_OUT_OF_MEMORY   There is not enough memory for the SQL command.
 * @exception ERR_NO_SUCH_USER    The user/group doesn't exist.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL WinsDBCheckDomainUserExist(sqlite3 *pDomainDb, const char *szName, char *szRealName, int cbRealName);

/**
 * Get the samba advance options configure from smbinfo.conf
 *
 * @param[out]   pConf   The advanced options.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOSMBAdvConfGet(SYNO_SAMBA_ADVCONF *pConf);

/**
 * Set the samba advance options configure from smbinfo.conf
 *
 * @param[in]    Conf    The advanced options to set.
 * @param[in]    mode    The mode.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOSMBAdvConfSet(SYNO_SAMBA_ADVCONF Conf, ADVANCE_OPT_STATUS mode);

/**
 * Get the samba CTDB config from /usr/syno/etc/smb.conf
 *
 * @param[out]   pConf   CTDB config
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOSMBCtdbConfGet(SYNO_SAMBA_CTDB_CONF *pConf);

/**
 * Set the samba CTDB config to /usr/syno/etc/smb.conf
 *
 * @param[in]   pConf   CTDB config
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOSMBCtdbConfSet(const SYNO_SAMBA_CTDB_CONF *pConf);

/**
 * Remove CTDB key-value from /usr/syno/etc/smb.conf
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOSMBCtdbConfDel(void);

/**
 * concat 2 command
 *
 * @param[out]      pplistName    The enum results.
 * @param[in]       UGType       0 means user, 1 means group.
 * @param[in]       start        The start index. Must be non-negative.
 * @param[in]       limit        The max number of names to enum. -1 means no limits.
 * @param[in]       szSubstr     A substring or prefix to match. @p blPrefix determine whether it's substring or prefix. NULL or empty string means enum all.
 * @param[in]       szDN         A domain to enum. NULL or empty string means all domains.
 * @param[in]       blPrefix     Determine whether @p szSubstr is a substring or prefix.
 * @param[in]       order        1 means in ascending order, 2 means in descending order, 0 means don't care.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOWinsDNUGPagingEnum(PSLIBSZLIST *pplistName, int UGType, int start, int limit, const char *szSubstr, const char *szDN, BOOL blPrefix, int order);

/**
 * @param[out]    pplistName   the enum result list
 * @param[in]     plistMatch   match list, user/group name to match
 * @param[in]     blExclude   decide whether @p plistMatch is exclude (TRUE) or include (FALSE)
 * @param[in]     UGType
 *                - 0: get domain user
 *                - 1: get domain group
 * @param[in]     start   offset
 * @param[in]     limit
 *                - -1: get all user/group
 *                - >0: get at most limit amounts of user/group
 * @param[in]     szSubstr   search substring
 * @param[in]     szDomain
 *                - NULL or "": all domain
 *                - else: specify domain
 * @param[in]     szDN
 *                - NULL or "": entire domain
 *                - else: specify dn
 * @param[in]     blPrefix
 *                - 0: search szSubstr as sub string
 *                - 1: search szSubstr as prefix
 * @param[in]     order
 *                - 1: Name order ascend
 *                - 2: Name order descend
 *                - other: no order
 *
 * @retval    >=0 success and return the enum number
 * @retval    -1 Fail
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOWinsDNUGPagingEnumInclude(PSLIBSZLIST *pplistName, PSLIBSZLIST plistInclude, int UGType, int start, int limit, const char *szSubstr, const char *szDN, BOOL blPrefix, int order);

/**
 * Check if spotlight is enabled
 *
 * @retval    TRUE enable
 * @retval    FALSE not enable
 *
 * @grantable No
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOSMBIsEnableSpotlight(void);

/**
 * Set key spotlight enable setting.
 *
 * @param[in]    blEnable   Whether to enable spotlight.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSMBSetSpotlight(BOOL blEnable);

/**
 * Get the expiry day of the user @p szName.
 *
 * @param[in]   szName   The user name.
 *
 * @retval   NOT_EXPIRED  The user will never expire.
 * @retval   Otherwise    The number of days from 1970/1/1 until the expiry date.
 *
 * @exception ERR_OPEN_FAILED         Failed to open domain database.
 * @exception ERR_NOT_ENOUGH_MEMORY   Memory not enough for the SQL command.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) long WinsDBDomainUserExpiryDayGet(const char *szName);

/**
 * Check is domain user/group/list building.
 *
 * @retval   TRUE    The Domain db is building
 * @retval   False   db is not building
 *
 * @grantable No
 * @apparmor abstractions/libsynosdk/wins
 */
SDK_STARTING_FROM(SDK_VER_6_1) BOOL SYNOWinsIsDbBuilding();

/**
 * @}
 */
