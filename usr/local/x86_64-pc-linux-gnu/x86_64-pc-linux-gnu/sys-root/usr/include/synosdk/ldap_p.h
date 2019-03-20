/**
 * @addtogroup LDAP
 *
 * @{
 */

/**
 * Check if LDAP is binded.
 *
 * @retval    TRUE   yes
 * @retval   FALSE   no
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOLDAPIsBinded();

/**
 * Return the domain name (value of the first domain componet) of the BaseDN in nslcd.conf
 * dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC.SYNO.COM
 * cn=users,dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC.SYNO.COM
 * uid=diradmin,cn=users,dc=SYNO,dc=COM => SYNO.COM
 *
 * @param[out]  szDomainName   The domain name, cannot be NULL.
 * @param[in]   cbDomainName   The size of szDomainName.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPDomainName(char *szDomainName, size_t cbDomainName);

/**
 * Extract attribute-value pair from a given RDN.
 *
 * @param[in]   szRDN   The RDN to extract, will be modified temporarily, ex: dc=SYNO
 * @param[out]   szAttr   The attribute, can be NULL, ex: dc
 * @param[in]   cbAttr   The size of szAttr
 * @param[out]   szVal   The value, can be NULL, ex: SYNO
 * @param[in]   cbVal   The size of szVal
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPRDNPairExtract(char *szRDN, char *szAttr, size_t cbAttr, char *szVal, size_t cbVal);

/**
 * Return a list of RDN components from DN
 *
 * @param[in]   szDN   The DN to extract, ex: dc=SIGMAC,dc=SYNO,dc=COM
 * @param[out]   ppList   The address of a pointer to a list for RDNs
 *
 * @retval   >=0   number of RDNs
 * @retval    -1   fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPRDNListExtract(const char *szDN, PSLIBSZLIST *ppList);

/**
 * Return the domain name of a given DN
 * dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC.SYNO.COM
 * cn=users,dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC.SYNO.COM
 * uid=diradmin,cn=users,dc=SYNO,dc=COM => SYNO.COM
 *
 * @param[in]   szDN   The DN, ex: uid=diradmin,cn=users,dc=SYNO,dc=COM
 * @param[out]   szDomainName   The domain name, cannot be NULL
 * @param[in]   cbDomainName   The size of szDomainName
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPDNDomainName(const char *szDN, char *szDomainName, size_t cbDomainName);

/**
 * Return the value of the first domain componet of a given DN
 * dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC
 * cn=users,dc=SIGMAC,dc=SYNO,dc=COM => SIGMAC
 * uid=diradmin,cn=users,dc=SYNO,dc=COM => SYNO
 *
 * @param[in]   szDN   The DN, ex: uid=diradmin,cn=users,dc=SYNO,dc=COM
 * @param[out]   szDomainComponent   The domain name, cannot be NULL
 * @param[in]   cbDomainComponent   The size of szDomainComponent
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPDNFirstDomainComponent(const char *szDN, char *szDomainComponent, size_t cbDomainComponent);

/**
 * Get Base DN from nslcd.conf
 *
 * @param[out]   szBaseDN   The Base DN to be filled. ex. dc=SIGMAC,dc=SYNO,dc=COM
 * @param[in]   cbBaseDN   The size of szBaseDN
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBaseDNGet(char *szBaseDN, size_t cbBaseDN);

/**
 * Get Information from configure file @p szConfFile. @p szConfFile is usually nslcd.conf or slapd.conf.
 *
 * @param[in]   szConfFile   The configure file to read.
 * @param[in]   szKey        The key for search, ex: uri, base, binddn
 * @param[out]  szVal        The valude to be filled
 * @param[in]   cbVal        The size of szVal
 *
 * @retval    1    success
 * @retval    0    key not found
 * @retval   -1    fail
 *
 * @grantable No
 * @user Who can read @p szConfFile
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPInfoGetFromConf(const char *szConfFile, const char *szKey, char *szVal, size_t cbVal);

/**
 * Get Password from ldap.secret
 *
 * @param[out]   szPass   The Pass to be filled
 * @param[in]   cbPass   The size of szPass
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSecretGet(char *szPass, size_t cbPass);

/**
 * Get URI from nslcd.conf
 *
 * @param[out]   szUri   The Uri to be filled
 * @param[in]   cbUri   The size of szUri
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPUriGet(char *szUri, size_t cbUri);

/**
 * Get Bind DN from nslcd.conf
 *
 * @param[out]   szBindDN   The Bind DN to be filled. ex. dc=SIGMAC,dc=SYNO,dc=COM
 * @param[in]   cbBindDN   The size of szBindDN
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPBindDNGet(char *szBindDN, size_t cbBindDN);

/**
 * Split domain name and user name.
 *
 *
 * @param[in]   szName   szName, ex: diradmin@sigmac
 * @param[out]   szDomainName   Domain Name (Could be NULL)
 * @param[in]   cbDomainName   size of szDomainName (Should be 0 if szDomainName == NULL )
 * @param[out]   szUserName   User Name (Could be NULL)
 * @param[in]   cbUserName   size of szUserName (Should be 0 if szUserName == NULL)
 *
 * @retval      1    success
 * @retval      0    invaid format, only User Name is set (if szUserName != NULL)
 * @retval      -1   error
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSplitName(const char *szName, char *szDomainName, size_t cbDomainName, char *szUserName, size_t cbUserName);

/**
 * Concatenate domain name and user name.
 *
 *
 * @param[out]   szName   szName
 * @param[in]   cbName   size of szName
 * @param[out]   szDomainName   Domain Name (Could be NULL)
 * @param[out]   szUserName   User Name
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPCatName(char *szName, size_t cbName, const char *szDomainName, const char *szUserName);

/**
 * Get login_suffix @p szLoginSuffix which size is @p cbLoginSuffix
 * in /usr/syno/etc/nslcd.conf. If not found, use basd_dn to composite
 * the login_suffix
 *
 * @param[out] szLoginSuffix	The login_suffix value in nslcd.conf. Should not be NULL.
 * @param[in] cbLoginSuffix		Size of szLoginSuffix. Should bigger than zero.
 *
 * @retval 0 on success.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPInfoGetFromConf()
 * @exception SYNOLDAPDomainName()
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLoginSuffixGet(char *szLoginSuffix, size_t cbLoginSuffix);

/**
 * Modify settings in /etc/nsswitch.conf
 *
 * @param[in]   szDatabase    The database name. ex: passwd, group, host, ...
 * @param[in]   szService     The service name to be add/remove. ex: files, winbind, ldap, ...
 * @param[in]   blAdd         - TRUE:  Add the service to the database
 *                            - FALSE: Remove the service from the database
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPNssSet(const char *szDatabase, const char *szService, BOOL blAdd);

/**
 * @}
 */
