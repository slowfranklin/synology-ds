/**
 * Get an NFS rule with path in /etc/exports.
 *
 *   NOTE:
 *      1. Remember to free the NFS_RULE with SYNONFSRuleFree().
 *      2. Not a thread-safe function.
 *
 * @param [in]	szNFSFilePath	The path of export file.
 * @param [in]	szTargetPath	The mount path or GUID for external device.
 * @param [out]	ppRule			Output for NFS rule.
 *
 * @retval 1	Found
 * @retval 0	Not found
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleGet(const char *szNFSFilePath, const char *szTargetPath, NFS_RULE **ppRule);

/**
 * Get an NFS rule (whith extend option) with path in /etc/exports.
 *
 *   NOTE:
 *      1. Remember to free the NFS_RULE with SYNONFSRuleFree().
 *      2. Not a thread-safe function.
 *
 * @param [in]	szNFSFilePath	The path of export file.
 * @param [in]	szTargetPath	The mount path or GUID for external device.
 * @param [out]	ppRule			Output for NFS rule.
 *
 * @retval 1	Found
 * @retval 0	Not found
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSRuleExtGet(const char * szNFSFilePath, const char * szTargetPath, NFS_RULE_EXTEND **ppRuleExtend);

/**
 * Free an NFS rule
 *
 * @param [in] pRule
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNONFSRuleFree(NFS_RULE *pRule);

/**
 * Free an NFS rule (with extend option)
 *
 * @param [in] pRuleExt
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) void SYNONFSRuleExtFree(NFS_RULE_EXTEND *pRuleExt);

/**
 * Set an NFS rule in /etc/exports.
 *
 * @param [in] szNFSFilePath	The path of export file.
 * @param [in] szTargetPath		Old nfs mount path, cannot be NULL.
 * @param [in] pRule			The rule to be set, or pass NULL to remove the rule of target path.
 *
 * @retval 0	Success
 * @retval -1	Error,  error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleSet(const char *szNFSFilePath, const char *szTargetPath, NFS_RULE *pRule);

/**
 * Set an NFS rule (with extend option) in /etc/exports.
 *
 * @param [in] szNFSFilePath	The path of export file.
 * @param [in] szTargetPath		Old nfs mount path, cannot be NULL.
 * @param [in] pRuleExt			The rule to be set, or pass NULL to remove the rule of target path.
 *
 * @retval 0	Success
 * @retval -1	Error,  error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSRuleExtSet(const char *szNFSFilePath, const char *szTargetPath, NFS_RULE_EXTEND *pRuleExt);

/**
 * Remove an NFS rule in /etc/exports.
 *
 * @param [in] szNFSFilePath	The path of export file.
 * @param [in] szTargetPath		The nfs mount path, cannot be NULL.
 *
 * @retval 0 Success
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleRemove(const char *szNFSFilePath, const char *szTargetPath);

/**
 * Validate the NFS path.
 *
 * @param [in] szTargetPath		The path to be checked.
 *
 * @retval 0 Not a valid nfs path
 * @retval 1 Pass, v2/v3 path
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSCheckPath(const char *szTargetPath);

/**
 * Dlopen to get setexportent, getexportent, endexportent.
 * Remember to call SYNONFSDlCloseFunc() when finish.
 *
 * @param [out] ppsetexportent	Function pointer to setexportent.
 * @param [out] ppgetexportent	Function pointer to getexportent.
 * @param [out] ppendexportent	Function pointer to endexportent.
 *
 * @retval -1	Error
 * @retval 0	Success
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSDlOpenFunc(SETEXPORTENT *ppsetexportent, GETEXPORTENT *ppgetexportent, ENDEXPORTENT *ppendexportent);

/**
 * DlClose.
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNONFSDlCloseFunc(void);

/**
 * Change the path of an NFS rule in /etc/exports.
 *
 * @param [in] szNFSFilePath	The path of export file.
 * @param [in] szOldPath		The old exported path.
 * @param [in] szNewPath		The new exported path.
 *
 * @retval 0 Success
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleChangePath(const char *szNFSFilePath, const char *szOldPath, const char *szNewPath);

/**
 * This function will read the share's NFS right information
 * from /usr/syno/etc/share_nfs_right.map.
 *
 *      1. Remember to free the pNFSRule with SYNONFSRuleFree().
 *      2. Not a thread-safe function.
 *
 * @author \$Author: claudiac $
 * @version \$Revision: 1.4 $
 * @ingroup SHARE
 *
 * @param [in]	pOpt		The device name
 * @param [out]	ppNFSRule	If the GUID of old share name is the
 *                          same, then we put the old share NFS
 *                          information. If not, will set default value
 *
 * @retval 1	Success
 * @retval 0	Not found or GUID not match
 * @retval -1	Failed
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleMapGet(const NFS_MAP_OPTION *pOpt, NFS_RULE **ppNFSRule);

/**
 * This function will read the share's NFS right information
 * from /usr/syno/etc/share_nfs_right.map.
 *
 *      1. Remember to free the pNFSRule with SYNONFSRuleFree().
 *      2. Not a thread-safe function.
 *
 * @author \$Author: claudiac $
 * @version \$Revision: 1.4 $
 * @ingroup SHARE
 *
 * @param [in]	pOpt		The device name
 * @param [out] pNFSRule	If the GUID of old share name is the
 *						    same, then we put the old share NFS
 *						    information. If not, will set default value
 *
 * @retval 1	Success
 * @retval 0	Not found or GUID not match
 * @retval -1	Failed
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSRuleExtMapGet(const NFS_MAP_OPTION *pOpt, NFS_RULE_EXTEND **ppNFSRule);

/**
 * Set an NFS rule in /etc/exports, /etc/exports_map.
 *
 * @param [in] szTargetPath	The old mount path or GUID for external device.
 * @param [in] pRule		The rule.
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONFSRuleSetAll(const char *szTargetPath, NFS_RULE *pRule);

/**
 * Set an NFS rule (with extend option) in /etc/exports, /etc/exports_map.
 *
 * @param [in] szTargetPath	The old mount path or GUID for external device.
 * @param [in] pRuleExt		The rule.
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSRuleExtSetAll(const char *szTargetPath, NFS_RULE_EXTEND *pRuleExt);

/**
 * Get NFS_ID_MAP from file /etc/idmapd.conf.
 *
 * Note: Caller should call SYNONFSIDMapFree() to free the members of NFS_ID_MAP and itself point after success return.
 *
 * @retval NFS_ID_MAP Success
 * @retval NULL Fail
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) PNFS_ID_MAP SYNONFSIDMapGet(void);

/**
 * Dump NFS_ID_MAP to file @p szNFSIDMapPath
 *
 * @param [in] szNFSIDMapPath	The Dump file path, should not be NULL
 * @param [in] pIDMap			The NFS_ID_MAP info, should not be NULL
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSIDMapSet(const char *szNFSIDMapPath, NFS_ID_MAP *pIDMap);

/**
 * Free an NFS_ID_MAP
 *
 * @param [in] pIDMap
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) void SYNONFSIDMapFree(NFS_ID_MAP *pIDMap);

/**
 * Get @p ppStaticMap from file /etc/idmapd.conf.
 *
 * @param [in,out]	ppStaticMap	Output for PSLIBSZHASH @p ppStaticMap, should not be NULL
 * @param [in]		szSearch	Search LocalName and PrincipaleName whose substring match @p szSearch, may be NULL
 *                              NULL: search all
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSStaticMapGet(PSLIBSZHASH *ppStaticMap, const char *szSearch);

/**
 * Append @p pStaticMap to @p ppStaticMapTarget.
 *
 * @param [in,out]	ppStaticMapTarget	Output for PSLIBSZHASH @p ppStaticMapTarget, should not be NULL
 * @param [in]		pStaticMap			The pStaticMap will Append to @p ppStaticMapTarget, should not be NULL
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSStaticMapAppend(PSLIBSZHASH *ppStaticMapTarget, PSLIBSZHASH pStaticMap);

/**
 * Remove the key from @p pStaticMap when key match the string in @p pRmPrincList
 *
 * @param [in,out]	pStaticMap		Output for @p pStaticMap, should not be NULL
 * @param [in]		pRmPrincList	The principal will be remove from @p pStaticMap, should not be NULL
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSStaticMapRemove(PSLIBSZHASH pStaticMap, PSLIBSZLIST pRmPrincList);

/**
 * create /etc/nfs/krb5.conf
 *
 * @param [in] szRealm	Kerberos Realm, should not be NULL
 *
 * @retval 0	Success
 * @retval -1	Error, error code is returned via SLIBCErrGet()
 * @exception ERR_OPEN_FAILED
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSCreateKrb5Conf(const char *szRealm);

/**
 * Set nfs prefer read&write size to kernel nfsd
 * user space use file SZF_NFS_PREFER_PACKET_SIZE to communicate with kernel
 *
 * @param [in] readSize		Prefer udp packet read size, value range should between MIN_NFS_UDP_SIZE~MAX_NFS_UDP_SIZE
 * @param [in] writeSize	Prefer udp packet write size, value range should between MIN_NFS_UDP_SIZE~MAX_NFS_UDP_SIZE
 *
 * @retval  0 Success
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 * @retval -2 Can not open proc file, this may due to nfsd is not start
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSUDPPrefSizeSet(int readSize, int writeSize);

/**
 * This function will get nfs rule from file SZF_NFS_EXPORTS_MAP
 *
 *      1. Remember to free the ppNFSRule with SYNONFSRuleExtFree().

 *
 * @param [in]	pOpt		The information to get nfs rule
 * @param [out]	ppNFSRule	Return nfs rule if any nfs rule find on SZF_NFS_EXPORTS_MAP match pOpt->GUID
 *
 * @retval 1	Success
 * @retval 0	Not found or GUID not match
 * @retval -1	Failed
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSRuleGetByGUID(const NFS_MAP_OPTION *pOpt, NFS_RULE_EXTEND **ppNFSRule);

/**
 * Get syno NFS conf info from file /etc/nfs/syno_nfs_conf
 *
 * @param [out] pNFSSynoConf	Output for NFS CONF INFO
 *
 * @retval  0 No error
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSConfGet(NFS_SYNO_CONF *pNFSSynoConf);

/**
 * Set NFS info to file /etc/nfs/syno_nfs_conf
 *
 * @param [in] pNFSSynoConf		Input info that will be set to /etc/nfs/syno_nfs_conf
 *
 * @retval  0 No error
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSConfSet(NFS_SYNO_CONF *pNFSSynoConf);

/**
 * Import kerberos keytab, update kerberos information to below file
 * - principal name: /etc/nfs/syno_nfs_conf
 * - kerberos realm: /etc/nfs/krb5.conf
 * - nfsv4 domain: /etc/idmapd.conf
 *
 * @param [in] szFile Path for kerberos keytab
 *
 * @retval  0 No error
 * @retval -1 System error
 * @retval -2 Kerberos keytab format error
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSKeytabImport(const char *szFile);

/**
 * Validate kerberos keytab by tool "klist"
 *
 * @param [in] szFile Path for kerberos keytab
 *
 * @retval  0 No error
 * @retval -1 Error
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSKeytabValidate(const char *szFile);

/**
 * Read kerberos keytab from @szFile, and store keytab info to @pKeyInfo
 *
 * @param [in]	szFile		Path for Kerberos keytab
 * @param [out]	ppKeyInfo	Output for Kerberos keytab info
 *
 * @retval  0 No error
 * @retval -1 Error, error code is returned via SLIBCErrGet()
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSKeytabInfoGet(const char *szFile, NFS_KRB5_KEY_INFO **ppKeyInfo);

/**
 *
 * Free NFS Kerberos KeyInfo
 *
 * @param [in] pKeyInfo
 *
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) void SYNONFSKeytabInfoFree(NFS_KRB5_KEY_INFO *pKeyInfo);

/**
 * Get kerberos principal from kerberos keytab
 *
 * Note: a kerberos keytab may contain many principal, get the first one
 *
 * @param [in]	szFile		Path for Kerberos keytab
 * @param [out]	szPrincipal	Output for principal
 * @param [in]	cbPrincipal Size of @p szPrincipal
 *
 * @retval  0 No error
 * @retval -1 Error
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSKeytabPrincipalGet(const char *szFile, char *szPrincipal, int cbPrincipal);

/**
 * Check if kernel version support NFS kerberos
 *
 * @retval TRUE		Support
 * @retval FALSE	Not support
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNONFSSupportKerberos(void);

/**
 * 1. Remove kerberos keytab
 * 2. Remove kerberos principal name from file /etc/nfs/syno_nfs_conf
 *
 * @retval  0 No error
 * @retval -1 System error
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONFSKeytabRemove(void);

/**
 * Set if NFS enable default UNIX privilege
 * user space use file SZF_NFS_UNIX_PRI(in /proc) to communicate with kernel
 *
 * @param [in] blUNIXEnable		Enable default UNIX privilege or not
 *
 * @retval 0	Success
 * @retval -1	Error => can not open proc file, this may due to nfsd is not start
 *
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynonfs
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNONFSUNIXPriEnableSet(BOOL blUNIXEnable);
