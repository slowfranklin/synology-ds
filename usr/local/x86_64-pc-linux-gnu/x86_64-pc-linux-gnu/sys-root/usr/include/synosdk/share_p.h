/**
 * @addtogroup SHARE
 *
 * @{
 */

/**
 * Copies a SYNOSHARE @p pShareIn and returns.  This function
 * will check the values SYNOSHARE::szName, SYNOSHARE::szPath,
 * SYNOSHARE::fType and SYNOSHARE::fBrowseable and
 * SYNOSHARE::fFTPPrivilege in @p pShareIn
 * are validated or not.
 *
 * @param[in]   pShareIn   The SYNOSHARE struct that to be copied.
 * Should not be NULL.
 *
 * @retval   !NULL a SYNOSHARE
 * @retval   NULL  On error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_SHARENAME
 * @exception ERR_INVALID_PATHNAME SYNOSHARE::szPath does not start with "/"
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) PSYNOSHARE SYNOShareAlloc(const PSYNOSHARE pShareIn);

/**
 * Transforms a PSLIBSZHASH @p pshSection which is received from
 * configure file into SYNOSHARE pData.
 *
 * @param[in]   szShareName          The section name, not including []. Should not be NULL.
 * @param[in]   pshSection           A hash which includes key-value of a section. Should not be NULL
 * @param[in]   IsVaildateUserGroup  Whether to check the users/groups exist.
 *
 * @retval   !NULL a SYNOSHARE
 * @retval   NULL  On error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_FORMAT_ERROR
 * @exception SYNOShareAlloc()
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) PSYNOSHARE SLIBShareAllocFromConf(const char *szShareName, PSLIBSZHASH pshSection, BOOL IsVaildateUserGroup);

/**
 * Get a default SYNOSHARE::status according to the share name @p szName.
 *
 * @param[in]   szName  The share name.
 *
 * @return  A default SYNOSHARE::status for @p szName.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) int ShareDefaultStatusGet(const char *szName);

/**
 * Check if @p pShare::szPath matched @p enumType
 *
 * @param[in]   pShare   The PSYNOSHAREDB handler. Should not be NULL.
 * @param[in]   enumType   The SYNOSHAREENUM. Matching by @p SYNOSHARE::szPath.
 *
 * @retval   0 matched
 * @retval   -1 not matched
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBEnumTypeMatched(const PSYNOSHARE pShare, const SYNOSHAREENUM enumType);

/**
 * Gets all share names that matched @p enumType from server
 * and stored into SzList @p pplistShareName.
 *
 * @param[out]  pplistShareName  the SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]   enumType         the SYNOSHAREENUM.
 *
 * @retval   >0 the number that appended into SzList.
 * @retval   0  none share found.
 * @retval   -1 On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see SYNOShareEnumByPrefix()
 * @see SYNOShareEnumByRegex()
 * @see SYNOShareEnumByMntPath()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareEnum(PSLIBSZLIST *pplistShareName, const SYNOSHAREENUM enumType);

/**
 * Gets all share names that prefix of share path matched mount
 * path @p szMntPath from server and stored into SzList @p
 * pplistShareName.
 *
 * @param[out]  pplistShareName    The SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]   szMntPath          The string that presents the mount path prefix, ie, /volume[1-4]. Should not be NULL.
 *
 * @retval   >0 the number that appended into SzList.
 * @retval   0  none share found.
 * @retval   -1 On error
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see SYNOShareDBEnumI()
 * @see SYNOShareEnum()
 * @see SYNOShareEnumByPrefix()
 * @see SYNOShareEnumByRegex()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareEnumByMntPath(PSLIBSZLIST *pplistShareName, const char *szMntPath);

/**
 * Gets all share names that mount path matched @p enumType and
 * prefix of share path matched mount path @p szMntPath from
 * server and stored into SzList @p pplistShareName.
 *
 * @param[out]  pplistShareName   The SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]   szMntPath         The string that presents the mount path prefix, ie, /volume[1-4]. Should not be NULL.
 * @param[in]   enumType          The SYNOSHAREENUM.
 *
 * @retval   >0 the number that appended into SzList.
 * @retval   0  none share found.
 * @retval   -1 On error
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see SYNOShareDBEnumI()
 * @see SYNOShareEnum()
 * @see SYNOShareEnumByPrefix()
 * @see SYNOShareEnumByRegex()
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOShareEnumByMntPathAndEnumType(PSLIBSZLIST *pplistShareName, const char *szMntPath, const SYNOSHAREENUM enumType);

/**
 * Gets all share names that mount path matched @p enumType and
 * share name partial matched string prefix @p szPrefix from
 * server and stored into SzList @p plistShareName.
 *
 * @param[out]  pplistShareName   The SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]   enumType   The SYNOSHAREENUM. Matching by SYNOSHARE::szPath.
 * @param[in]   szPrefix   The string that presents the name prefix. Should not be NULL.
 * @param[in]   blCaseLess   The boolean that will do caseless compare when true.
 *
 * @retval   >0 the number that appended into SzList.
 * @retval   0  none share found.
 * @retval   -1 On error
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see SYNOShareDBEnumI()
 * @see SYNOShareEnum()
 * @see SYNOShareEnumByRegex()
 * @see SYNOShareEnumByMntPath()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareEnumByPrefix(PSLIBSZLIST *pplistShareName, const SYNOSHAREENUM enumType, const char *szPrefix, const BOOL blCaseLess);

/**
 * Frees a Synology Share structure.
 *
 * @param[in,out]   pShare   The Synology Share struct. Should not be NULL.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOShareFree(void *pShare);

/**
 * Obtains the share information according to the share name you
 * specify in @p szShareName argument from the default
 * SYNOSHAREDB.
 *
 * The return information will save in @p ppShare argument and
 * it's allocated size stored into @p pcbShareSize.
 *
 * If @p *ppShare is NULL, this function will allocates for this
 * share.
 *
 * Otherwise, @p *ppShare is not NULL, this function
 * will check @p SYNOSHARE::nAlloc is large enough to store this
 * share information. When the size is bigger than we need, we
 * will copy share information into @p *ppShare. When
 * SYNOSHARE::nAlloc is smaller than we need, this function will
 * reallocf() for it and update SYNOSHARE::nAlloc.
 *
 * @param[in]    szShareName   The string that contains Share name. Should not be NULL.
 * @param[out]   ppShare       The pointer that this share to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_NO_SUCH_SHARE
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see SYNOShareDBOpen()
 * @see SYNOShareDBGet()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareGet(const char *szShareName, PSYNOSHARE *ppShare);

/**
 * check the input string is a SATA Share name or not.
 *
 * @param[in]   szName   This should not be NULL, and used to validate if the share name is a SATA share name.
 *
 * @retval   TRUE  Is a SATA Share name.
 * @retval   FALSE Is not a SATA Share name.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlShareIIsSATASection(const char *szName);

/**
 * Check if input share name is valid.
 *
 * @deprecated Please use SLIBShareIsShareName instead.
 *
 * @param[in]   szName   To check if the share name is valid with following steps:
 *                       1. Allow blank, but the head and tail of szName can't include blank.
 *                       2. ASCII code >= 128 or only including digit, alpha, blank, '.', '_' and '-'.
 *                       3. fisrt char can't be '-'
 *
 * @retval   TRUE Is a valid share name.
 * @retval   FALSE Is not a valid share name.
 *
 * @grantable No
 *
 * @apparmor None.
*/
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsShareName(const char *szName);

/**
 * Check if a name can be a share name.
 *
 * @param[in]   szName  The share name.
 *
 * @retval   TRUE   Is a valid share name.
 * @retval   FALSE  Is not a valid share name.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBShareIsShareName(const char * szName);

/**
 * check the input string is a USB Share name or not
 *
 * @param[in]   szName   This should not be NULL, and used to validate if the share name is a USB share name.
 *
 * @retval   TRUE Is a USB Share name.
 * @retval   FALSE Is not a USB Share name.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlShareIIsUsbSection(const char *szName);

/**
 * get share path from share database.
 *
 * @param[in]   szShareFolder   The share name.
 * @param[out]  szSharePath	    The buffer to store share path.
 * @param[in]   iSize           The number of bytes in @p szSharePath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 *
 * @see PSLIBSZHASH
 * @see SLIBCFileGetSection()
*/
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOSharePathGet(const char *szShareFolder, char *szSharePath, int iSize);

/**
 * Get share path.
 *
 * @param[in]   pShare   The share handler.
 *
 * @retval    !NULL share path.
 * @retval    NULL on error.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @exception ERR_BAD_PARAMETERS
 */
SDK_STARTING_FROM(SDK_VER_5_0) const char* SLIBSharePathGet(const PSYNOSHARE pShare);

/**
 * Get the section Type.
 *
 * @param[in] szName the section name which not including []. Should not be NULL
 *
 * @retval   <=0 section type
 * @retval   -1  On error
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int ShareSectionTypeGet(const char *szName);

/**
 * Get "loose" permission, as NA/RO/RW, of @p szUser against @p pShare.
 *
 * If @p pShare is forbidden/readonly, NA/RO is returned. Otherwise,
 * as long as @p szUser has ANY permission against @p pShare, RW is returned.
 * This is also why we call it "loose", compare with SLIBShareUserRightGet().
 *
 * This function is appropriate when list available shares for given user.
 * A share should be listed if not NA, further permission check will be done
 * by kernel in subsequent read/write operations.
 *
 * @param[in]   szUser   User name, must not be NULL.
 * @param[in]   pShare   Share handle, must not be NULL.
 *
 * @retval   Share permission [SHARE_NA/SHARE_RW/SHARE_RO].
 *
 * @grantable No
 * @user @p szUser
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareUserPrivGet(const char *szUser, const PSYNOSHARE pShare);

/**
 * Get Encrytpion share encrypted path.
 * for path /volume1/share, encrypted path is /volume1/@share@
 *
 * @param[in]   szPath   share path.
 * @param[out]   szEncPath   share encpryted path.
 * @param[in]   cbEncPath   size of @szEncPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_INVALID_PATH
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareEncryptPathGet(const char* szPath, char* szEncPath, size_t cbEncPath);

/**
 * Check if the volume path is in a reclycle folder.
 *
 * @param[in]   szVolPath   The the volume path. Should not be NULL. ex: /volumeX/share_name/folder
 *
 * @retval   TRUE In Recylce Folder.
 * @retval   FALSE Not in Recylce Folder.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOShareIsShareRecycle(const char *szVolPath);

/**
 * Check shares name.
 *
 * @param[in]   szShareName   share name
 *
 * @retval    >0 special share.
 * @retval    0  general share.
 * @retval    -1 parameter failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int ShareNameCheck(const char *szShareName);

/**
 * Check if the given share name is "sandwiched" by "@".
 *
 * @param[in]   szShareName   The share name.
 *
 * @retval   TRUE    Is an encryption share name.
 * @retval   FALSE   Is not an encryption share name.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL IsEncryptionShareName(const char *szShareName);

/**
 * Get the share backup configuration.
 * @note free by  SYNOShareFree()
 *
 * @param[in]   szMapName   Map section name. Should not be NULL. It can be Sharename or GUID (with partition number).
 * @param[out]   ppShare   Share information.
 *
 * @retval   2  map found but share conflict.
 * @retval   1  found.
 * @retval   0  file not found or share not found.
 * @retval   -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_0) int ShareMapGet(const char *szMapName, PSYNOSHARE *ppShare);

/**
 * parse share path to get volume path.
 * @p szSharePath path should start with "/volume"
 *
 * @param[in]   szSharePath   The share that to be parsed.
 * @param[out]   szVolPath   The volume path of @p szSharePath.
 * @param[in]   sizeVolPath   The size of @p szVolPath
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_PATH
 *
 * @grantable No
 *
 * @apparmor None.
*/
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareVolPathGet(const char *szSharePath, char *szVolPath, int sizeVolPath);

/**
 * If szPath is on USB/ESATA device, the szShareBinPath will be
 * VOLUME_PATH/SZD_SHARE_BIN, otherwise szShareBinPath will be VOLUME_PATH
 * e.g.
 * 1. szPath: /volumeUSB1/usbshare1-2 -> szShareBinPath: /volumeUSB1/usbshare1-2/@sharebin
 * 2. szPath: /volumeUSB1/usbshare1-2/@sharebin/photo -> szShareBinPath: /volumeUSB1/usbshare1-2/@sharebin
 * 3. szPath: /volume1 -> szShareBinPath: /volume1
 * 4. szPath: /volume1/web -> szShareBinPath: /volume1
 *
 * @param[in]    szPath           Volume path or share path
 * @param[out]   szShareBinPath   The buffer to store share bin path.
 * @param[in]    cbShareBinPath   Number of bytes @p szShareBinPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOShareBinPathGet(const char *szPath, char *szShareBinPath, int cbShareBinPath);

/**
 * Get share name and path from any path
 *
 * e.g.
 * 1. you give path that is exactly the same with share path
 *  1-1. /volume1/photo
 *  1-2. /volumeUSB1/usbshare
 *  1-3. /volumeUSB2/usbshare2-1/@sharebin/video
 *
 * 2. you give path that is a dir or file on one share
 *  2-1. /volume1/music/celine dion/To love you more.mp3
 *  2-2. /volume1/photo/japan/hokkaido/DSC_0024.JPG
 *  2-3. /volumeUSB1/usbshare/@sharebin/photo/kenting/
 *  2-4. /volumeUSB3/usbshare3-2/@sharebin/video/movie/G.I. Joe 2/1.avi
 *
 * 3. other case will be fail
 * @param[in]   szPath   path (please refer to description above)
 * @param[out]   szShareName   share name
 * @param[in]   cbShareName   length of szShareName
 * @param[out]   szSharePath   share path
 * @param[in]   cbSharePath   length of szSharePath
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOShareNamePathGet(const char *szPath, char *szShareName, int cbShareName, char *szSharePath, int cbSharePath);

/**
 * Check if share is inside @sharebin or not
 *
 * @param[in]   szName   share name
 *
 * @retval   TRUE   Is in @sharebin.
 * @retval   FALSE  Is not in @sharebin.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOShareIsInSharebin(const char *szName);

/**
 * You could give any path which is on a volume either on internal volume or USB/SATA volume,
 * and this interface give you the @tmp path on that volume (won't create it for you)
 *
 * e.g.
 * 1. szPath: /volumeUSB1/usbshare1-2 -> szTmpPath: /volumeUSB1/usbshare1-2/@sharebin/@tmp
 * 2. szPath: /volumeUSB1/usbshare1-2/@sharebin/photo -> szTmpPath: /volumeUSB1/usbshare1-2/@sharebin/@tmp
 * 3. szPath: /volume1 -> szTmpPath: /volume1/@tmp
 * 4. szPath: /volume1/web -> szTmpPath: /volume1/@tmp
 *
 * @param[in]    szPath      Any path on some volume.
 * @param[out]   szTmpPath   The buffer to store tmp path.
 * @param[in]    cbTmpPath   Number of bytes of @p szTmpPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOShareTmpPathGet(const char *szPath, char *szTmpPath, int cbTmpPath);

/**
 * check the share is a Gluster Share or not
 *
 * @param[in]   pShare   The PSYNOSHAREDB handler. Should not be NULL, and it used to validate if the share is a Gluster share.
 *
 * @retval   TRUE Is a Gluster Share.
 * @retval   FALSE Is not a Gluster Share.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBIsGlusterShare(const PSYNOSHARE pShare);

/**
 * Enable/Disalbe recycle bin for a certain share.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   blEnabled   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareRecycleStatusSet(PSYNOSHARE pShare, BOOL blEnabled);

/**
 * Check if recycle bin is enabled for a share.
 *
 * @param[in]   pShare   The share handler.
 * @param[out]   pblEnabled   recycle bin is on/off.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareRecycleStatusGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Set yes/no for admin only status of a certain share.
 *
 * @param[in]   pShare   The share handler.
 * @param[in]   blAdminOnly   TRUE for yes and FALSE for no.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareRecycleAdminOnlyStatusSet(PSYNOSHARE pShare, BOOL blAdminOnly);

/**
 * Check if recycle bin is admin only or not.
 *
 * @param[in]   pShare   a share handler.
 * @param[out]   pblEnabled   addmin only status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareRecycleAdminOnlyStatusGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Check if acl enable.
 *
 * @param[in]   pShare   a share handler.
 * @param[out]   pblEnabled   addmin only status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareACLStatusGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Enable/Disalbe ACL permission.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   blEnabled   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareACLStatusSet(PSYNOSHARE pShare, BOOL blEnabled);

/**
 * Set share description.
 *
 * @param[in]   pShare   The share handler.
 * @param[in]   szDescription   Share Description.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STRING_TOO_LONG The given description is too long.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareDescriptionSet(PSYNOSHARE pShare, char* szDescription);

/**
 * Get share Description.
 *
 * @param[in]   pShare   The share handler.
 *
 * @retval    !NULL share description.
 * @retval    NULL On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) char* SLIBShareDescriptionGet(const PSYNOSHARE pShare);

/**
 * Get NA, RW, RO list from share.
 *
 * @param[in]   pShare   a share handeler.
 * @param[out]   pszNA   NA list.
 * @param[out]   pszRW   RW list.
 * @param[out]   pszRO   RO list.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBSharePrivListGet(PSYNOSHARE pShare, const char** pszNA, const char** pszRW, const char** pszRO);

/**
 * Set NA, RW, RO list to share.
 *
 * @param[in]   pShare   The pointer to the share.
 * @param[in]   szNA     The NA list to set.
 * @param[in]   szRW     The RW list to set.
 * @param[in]   szRO     The RO list to set.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBSharePrivListSet(PSYNOSHARE pShare, char* szNA, char* szRW, char* szRO);

/**
 * Get advance privilege.
 *
 * @param[in]   pShare   The share handler.
 * @param[out]   pAdvancePri   advaice privelge value.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareAdvancePrivGet(const PSYNOSHARE pShare, int *pAdvancePriv);

/**
 * Set advance privilege.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   advancePriv   advance privilege.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareAdvancePrivSet(PSYNOSHARE pShare, int advancePriv);

/**
 * Check if share is browseable.
 *
 * @param[in]    pShare          The share handler.
 * @param[out]   pblBrowseable   Is browseable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareBrowseableGet(const PSYNOSHARE pShare, BOOL *pblBrowseable);

/**
 * Enable/Disalbe share browseable.
 *
 * @param[in]   pShare         The share handeler.
 * @param[in]   blBrowseable   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareBrowseableSet(PSYNOSHARE pShare, BOOL blBrowseable);

/**
 * Mark the share as an encryption share.
 *
 * @param[in]   pShare         The share handeler.
 * @param[in]   IsEncryption   Boolean to set encryption share.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsEncryptionSet(PSYNOSHARE pShare, BOOL IsEncryption);

/**
 * Check if the share is encryption share.
 *
 * @param[in]   pShare   The share handler.
 * @param[out]   pIsEncryption   is encryption share or not .
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsEncryptionGet(const PSYNOSHARE pShare, BOOL *pIsEncryption);

/**
 * Get share name.
 *
 * @param[in]   pShare   The share handler.
 *
 * @retval    !NULL share name.
 * @retval    NULL on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) const char* SLIBShareNameGet(const PSYNOSHARE pShare);

/**
 * Enable/Disalbe share hide unreadable files.
 *
 * @param[in]   pShare   The share handeler.
 * @param[in]   blHide   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareHideUnreadableSet(PSYNOSHARE pShare, BOOL blHide);

/**
 * Check if share is hide unreadable files.
 *
 * @param[in]    pShare   The share handler.
 * @param[out]   pblHide  Is hide unreadable files.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareHideUnreadableGet(const PSYNOSHARE pShare, BOOL *pblHide);

/**
 * Check if the share is encrypted.
 *
 * @param[in]    pShare         The share handler.
 * @param[out]   pIsEncrypted   Is share encrypted or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsEncryptedGet(const PSYNOSHARE pShare, BOOL *pIsEncrypted);

/**
 * Mark the encryption share as encrypted.
 *
 * @note this share must be an encryption share.
 *
 * @param[in]   pShare        The share handeler.
 * @param[in]   IsEncrypted   Boolean to set @p pShare as a encrypted share.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @excpetion ERR_ENC_NOT_SUPPORT not an ecrypiont share.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsEncryptedSet(const PSYNOSHARE pShare, BOOL IsEncrypted);

/**
 * Check if the share is auto decrypt on boot.
 *
 * @param[in]    pShare           The share handler.
 * @param[out]   pIsAutoDecrypt   Whether @p pShare is auto decrypt or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsAutoDecryptGet(const PSYNOSHARE pShare, BOOL *pIsAutoDecrypt);

/**
 * Mark the share auto decrypt on boot.
 *
 * @param[in]   pShare          The share handeler.
 * @param[in]   IsAutoDecrypt   Boolean to set auto decrypt on boot.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsAutoDecryptSet(PSYNOSHARE pShare, BOOL IsAutoDecrypt);

/**
 * Check if index is enabled.
 *
 * @param[in]   pShare   The share handler.
 * @param[out]   pblEnabled   file index is on/off.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIndexStatusGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Enable/Disalbe index for a certain share.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   blEnabled   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIndexStatusSet(PSYNOSHARE pShare, BOOL blEnabled);

/**
 * Check if @szShareName is exist share.
 *
 * @param[in]   szShareName   share name to check.
 * @param[out]   pIsExist   share name is exist or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsExist(const char* szShareName, BOOL *pIsExist);

/**
 * Get share location type from path.
 *
 * @param[in]   szSharePath   share path.
 *
 * @retval   SHARE_LOC_UNKOWN on error.
 * @retval   SHARE_LOC_INTERNEL share is in internal device.
 * @retval   SHARE_LOC_EXT_DEVICE share is external device (USB/SATA/SD) mount point.
 * @retval   SHARE_LOC_EXT_SHAREBIN share is in external device share bin.
 * @retval   SHARE_LOC_REMOTE share is in remote (GlusterFS).
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) SHARE_LOC_TYPE SLIBShareLocTypeGet(const char* szSharePath);

/**
 * Check if a share name @p szShareName is a name of some service share.
 *
 * @param[in]   szShareName   The share name to be checked.
 *
 * @retval   TRUE   Is a service share.
 * @retval   FALSE  Is not a service share.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBShareServiceMapGet()
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBShareIsServiceShareName(const char* szShareName);

/**
 * Get an array of SERVICE_SHARE_MAP.
 *
 * @return     An statically allocated array of SERVICE_SHARE_MAP.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBShareIsServiceShareName()
 * @see SLIBShareServiceLinkNameGet()
 */
SDK_STARTING_FROM(SDK_VER_6_0) SERVICE_SHARE_MAP* SLIBShareServiceMapGet();

/**
 * Check if the share name is for service share.
 *
 * @param[in]   szShareName   The share name.
 * @param[out]  szLinkName    A buffer to store the link name.
 * @param[in]   cbLinkName    The number of bytes of @p cbLinkName.
 *
 * @retval   TRUE a service share name.
 * @retval   FALSE not a service share name.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareServiceLinkNameGet(const char *szShareName, char *szLinkName, int cbLinkName);

/**
 * Check if the share is forbidden access.
 *
 * @param[in]    pShare          The share handler.
 * @param[out]   pIsForbidden    Is share forbidden access or not .
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsForbiddenGet(const PSYNOSHARE pShare, BOOL *pIsForbidden);

/**
 * Mark the share is forbidden access.
 *
 * @param[in]   pShare        The share handeler.
 * @param[in]   IsForbidden   Boolean to set forbidden access.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsForbiddenSet(PSYNOSHARE pShare, BOOL IsForbidden);

/**
 * Enum shares to @pplistShareName by pEnumFunc callback.
 *
 * @param[out] pplistShareName   the SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]   pEnumFunc   callback.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_LOCK_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareEnum(PSLIBSZLIST * pplistShareName, const PSYNOSHAREENUMFUNC pEnumFunc);

/**
 * Check if share @szName is accessible or not.
 * A share is accessible means the share path is RW.
 *
 * @param[in]   szName   share name to check.
 *
 * @retval    TRUE @p szShareName is accessible.
 * @retval    FALSE @p szShareName is not accessible.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBShareIsAccessible(const char *szName);

/**
 * Check each item in @p szList separated by "," and return a string contains valid user/group real names.
 * Both @p szList and return string are in the format of RO/RW/NA list in SZF_SMBCONF.
 * What is "valid" depends on how ValidateNames() works.
 * For domain user/group, "real name" means the name in @p szList.
 * For local and LDAP user/group, get real name from user/group DB.
 * This function will acquire shared locks on user & group DB.
 *
 *
 * @param[in]   szList   RO/RW/NA list from SZF_SMBCONF, must not be NULL.
 *
 * @retval   NULL On error.
 * @retval   !NULL Validated RO/RW/NA list as a string, must be freed by caller.
 *
 * @grantable No
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) char *SLIBShareGetValidUGList(const char *szList);

/**
 * Check if share is Only ACL mode.
 *
 * @param[in]   pShare   a share handler.
 * @param[out]   pblEnabled   addmin only status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsWinShareGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Enable/Disalbe share Only ACL mode.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   blEnabled   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsWinShareSet(PSYNOSHARE pShare, BOOL blEnabled);

/**
 * Check if share is Only ACL mode.
 *
 * @param[in]   pShare   a share handler.
 * @param[out]   pblEnabled   skip smb perm status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsSkipSmbPermGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Enable/Disalbe share skip smb perm.
 *         You should call SYNOShareSet() to commit the change.
 *
 * @param[in]   pShare   a share handeler.
 * @param[in]   blEnabled   TRUE to enable and FALSE to disable.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsSkipSmbPermSet(PSYNOSHARE pShare, BOOL blEnabled);

/**
 * Check if @pShare1 is equal to @pShare2
 *
 * @param[in]   pShare1   first share.
 * @param[in]   pShare2   seconde share.
 *
 * @retval   TRUE two shares are equal.
 * @retval   FALSE two shares are not equal.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBShareIsEqual(const PSYNOSHARE pShare1, const PSYNOSHARE pShare2);

/**
 * Check if share is Only ACL mode.
 * share must be win share, and RW/NA/RO no any permission
 *
 * @param[in]   pShare   a share handler.
 * @param[out]   pblEnabled   addmin only status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareIsOnlyAcl(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Check if enable snapshot browsing or not. This will bind mount snapshot directory in /volumeX/shareY/#snapshot
 *
 * @param[in]   pShare   The share handler.
 * @param[out]   pblEnabled   snapshot browsing status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBShareSnapshotBrowsingStatusGet(const PSYNOSHARE pShare, BOOL *pblEnabled);

/**
 * Set yes/no for snapshot browsing status of a certain share.
 *
 * @param[in]   pShare   The share handler.
 * @param[in]   blSnapshotBrowsing   TRUE for yes and FALSE for no.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBShareSnapshotBrowsingStatusSet(const PSYNOSHARE pShare, BOOL blSnapshotBrowsing);

/**
 * Get relative path begins from 'share name'
 *
 * e.g.
 *
 * 1. 'normal' share
 *  1-1. /volume1/music/mayday/1.mp3 -> /music/mayday/1.mp3
 *  1-2. /volumeUSB1/usbshare/winter_trip/day1/1.jpg -> /usbshare/winter_trip/day1/1.jpg
 *
 * 2. 'sharebin' share
 *  2-1. /volumeUSB1/usbshare/@sharebin/music/mayday/1.mp3 -> /music/mayday/1.mp3
 *
 * @param[in]   szPath   path (please refer to description above)
 * @param[out]   szRelativePath   relative path from a share
 * @param[in]   cbRelativePath   length of szRelativePath
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SLIBShareRelativePathGet(const char *szPath, char *szRelativePath, int cbRelativePath);

/**
 * Check whether @p pShare is readonly by others or not
 *
 * @param[in]   pShare   share handle
 * @param[out]   pblIsReadOnly   is readonly by others or not
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SLIBShareIsReadOnlyGet(const PSYNOSHARE pShare, BOOL *pblIsReadOnly);

/**
 * Mark @p pShare as readonly by others
 *
 * @param[in]   pShare   share handele
 * @param[in]   blIsReadOnly   is readonly by others or not
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SLIBShareIsReadOnlySet(PSYNOSHARE pShare, BOOL blIsReadOnly);

/**
 * This function is for Only ACL Mode to check share permission by ACL for file protocol.
 * The function will change to specify user to get ACL permission.
 *
 * @param[in]   szUser   Local/Domain user name
 * @param[in]   szPath   Share path
 *
 * @retval   SHARE_NA share_permission NA
 * @retval   SHARE_RW share_permission RW
 * @retval   -1 error
 *
 * @grantable No
 * @user @p szUser
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBShareUserACLPrivGet(const char *szUser, const char *szPath);

/**
 * Check if a share name @p szShareName is in /var/services, and is a live link.
 *
 * @param[in]   szShareName   The share name to be checked.
 *
 * @retval   TRUE    /var/services/@p szShareName is a live link.
 * @retval   FALSE   Either /var/services/@p szShareName doesn't exist or it's a dead link.
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOServiceIsLiveLink(const char *szShareName);

/**
 * Get volume of service by link.
 * Only link and real path exist results in return volume ID.
 *
 * @param[in]     szLinkName    The service link name.
 * @param[out]    szVolPath     The service volume path.
 * @param[in]     cbVolPath     The buffer size for the service volume path.
 *
 * @retval   0  Link not found
 * @retval   1  Link found and exist.
 * @retval   -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_KEY_NOT_FOUND   Can't find value of link
 * @exception ERR_NOT_A_SYMLINK   @szLinkPath is not a symblic link
 * @exception ERR_UNKNOWN         readlink() fail with unknown errno
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOShareServiceVolumeGetbyLink(const char *szLinkName, char *szVolPath, int cbVolPath);

/**
 * Check whether @p pShare is clustered share or not
 *
 * @param[in]   pShare   share handle
 * @param[out]   pblIsCluster   is clustered share or not
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareIsClusterGet(const PSYNOSHARE pShare, BOOL *pblIsCluster);

/**
 * Mark @p pShare as clustered share or not
 *
 * @param[in]   pShare   share handele
 * @param[in]   blIsCluster   is clustered share or not
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareIsClusterSet(PSYNOSHARE pShare, BOOL blIsCluster);

/**
 * Get all shares by user's needed permission
 *
 * @param[out]   ppListShare     The SzList container. Should not be NULL. The matched share names will APPEND into the SzList.
 * @param[in]    enumType        The SYNOSHAREENUM.
 * @param[in]    szUserName      User Name
 * @param[in]    Permission      Permission. Can be SHARE_NA, SHARE_RW, SHARE_RO. The permission combination is also allow. Ex: SHARE_RW | SHARE_RO.
 * @param[in]    blAccessible    Flag for check SHARE is accessible
 *
 * @grantable No
 *
 * @apparmor abstractions/share
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareEnumByUserPermission(PSLIBSZLIST *ppListShare, const SYNOSHAREENUM enumType, const char *szUserName, int Permission, BOOL blAccessible);

/**
 * @brief Convert @p pShare to @p *ppshSMB, in appropriate format for smb.conf.
 *
 * @p *ppshSMB will be cleared first, value of "comment" won't be surrounded by quotation marks.
 *
 * @param[in]  pShare   Share handle, must not be NULL.
 * @param[out] ppshSMB  Result hash, must be allocated by caller.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 * @apparmor None
 */
DSM_STARTING_FROM(SDK_VER_6_1) int SLIBShareConvertToSmbHash(const PSYNOSHARE pShare, PSLIBSZHASH *ppshSMB);

#ifdef SYNOSDK_SHARE_PRIVATE_API
/**
 * A wrapper of SYNOShareUpdate from libsynoshare.
 * This wrapper is to eliminate memory usage by dlopen libsynoshare.so instead of linking it.
 * To use this function, please think twice, and define SYNOSDK_SHARE_PRIVATE_API.
 *
 * @param[in]   pShare   The share info to be updated.
 *
 * @retval   0    On success.
 * @retval   -1   Failed to dlopen, or failed to SYNOShareUpdate.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED       When dlopen failed.
 * @exception ERR_UNKNOWN           When dlsym failed.
 * @exception SYNOShareUpdate()
 *
 * @grantable Yes
 * @user root
 *
 * @see SYNOShareUpdate()
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareUpdate(const PSYNOSHARE pShare);
#endif

#ifdef SYNOSDK_USE_SHARE_DB

/**
 * Closes and frees a Synology Share DB File Handler.
 *
 * @param[in,out]   pShareDb   The Synology Share DB File Handler. Should not be NULL.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @see SYNOShareDBOpen()
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOShareDBClose(const PSYNOSHAREDB pShareDb);

/**
 * Obtains the share information according to the cursor from a
 * opened SYNOSHAREDB handle @p pShareDb. The return information
 * will save in @p ppShare argument.
 *
 * If @p *ppShare is NULL, this function will allocate for
 * this share. Otherwise, @p *ppShare is not NULL, this function
 * will check SYNOSHARE::nAlloc is large enough to store this
 * share information. When the size is bigger than we need, we
 * will copy share information into @p *ppShare. When
 * SYNOSHARE::nAlloc is smaller than we need, this
 * function will reallocf() for it and update SYNOSHARE::nAlloc
 * accordingly.
 *
 * @param[in]   pShareDb   The PSYNOSHAREDB handler. Should not be NULL.
 * @param[out]   ppShare   The pointer that this share to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_SHARE
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBCursorGet(const PSYNOSHAREDB pShareDb, PSYNOSHARE *ppShare);

/**
 * Deletes SYNOSHARE from @p pShareDb by @p szShareName.
 *
 * @param[in]   pShareDb    The PSYNOSHAREDB handler. Should not be NULL.
 * @param[in] szShareName   The string that contains Share name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @see SYNOShareDelete()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBDelete(const PSYNOSHAREDB pShareDb, const char *szShareName);

/**
 * Obtains the share information according to the share name you
 * specify in @p szShareName argument from the specify
 * SYNOSHAREDB @p pShareDb.  The returned share information will
 * save in @p ppShare argument and it's allocated size stored into @p
 * pcbShareSize. This function will do a caseless compare
 * bewteen @p szShareName and SYNOSHARE::szName.
 *
 * If @p *ppShare is NULL, this function will
 * allocates for this share.  Otherwise, @p *ppShare is not
 * NULL, this function will check SYNOSHARE::nAlloc is large
 * enough to store this share information.  When the size is
 * bigger than we need, we will copy share information into @p
 * *ppShare.  When SYNOSHARE::nAlloc is smaller than we need,
 * this function will reallocf() for it and update
 * SYNOSHARE::nAlloc.
 *
 * @param[in]   pShareDb   The PSYNOSHAREDB handler. Should not be NULL.
 * @param[in] szShareName  The string that contains Share name. Should not be NULL.
 * @param[out]   ppShare   The pointer that this share to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_NO_SUCH_SHARE
 * @exception ERR_LOCK_FAILED
 * @exception ERR_UNLOCK_FAILED
 *
 * @see SLIBCBdbGet()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBGet(const PSYNOSHAREDB pShareDb, const char *szShareName, PSYNOSHARE *ppShare);

/**
 * Open Synology Share DB file. This function opens
 * default db file SZF_SHARE_DB_PATH, allocs Synology Share DB
 * File Handler and returns. Returns NULL if error occurs when
 * opening db file.
 *
 * The underlying operation is implemented by
 * SYNOShareDBOpenFile()
 *
 * @param[in]   flag   The flag to open database. Must be either O_RDONLY or O_RDWR.
 *
 * @retval   !NULL a vaild Synology Share DB File Handler.
 * @retval   NULL on failure
 *
 * @see SZF_SHARE_DB_PATH
 * @see SYNOShareDBOpenFile()
 * @see SYNOShareDBClose()
 */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOSHAREDB SYNOShareDBOpen(int flag);

/**
 * Sets SYNOSHARE @p pShare into share DB @p pShareDb. The
 * SYNOSHARE::szName of @p pShare is transfromed to upper case
 * and treats as db key. If the key existed in db already, and
 * the @p szOldShareName does not be NULL, then set
 * ERR_SHARE_EXISTS and return -1. If @p szOldShareName does not
 * equal to SYNOSHARE::szName in caseless, the @p szOldShareName
 * will be deleted from db then insert.
 *
 * After database finished, will call SYNOShareDBDump() to
 * sync the database to smb.conf.
 *
 * @param[in]   pShareDb        The PSYNOSHAREDB handler. Should not be NULL.
 * @param[in]   szOldShareName  The string that contains old sharename. May be NULL.
 * @param[in]   pShare          The Share that to be stored. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SHARE_EXISTS
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBSet(const PSYNOSHAREDB pShareDb, const char *szOldShareName, const PSYNOSHARE pShare);

/**
 * Dumps the db @p pShareDb to configure file SZF_SMBCONF.
 * Should update the modify time of SZF_SMBCONF to @p pShareDb.
 *
 * @param[in]   pShareDb   The PSYNOSHAREDB handler that represents
 *                 the primary db file name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_RENAME_FAILED
 * @exception ERR_REMOVE_FAILED
 * @exception ReservedSectionDump()
 * @exception GeneralSectionDump()
 * @exception SLIBCBdbCursorSetType()
 * @exception ShareDbConfSyncTimeSet()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOShareDBDump(const PSYNOSHAREDB pShareDb);
#endif // SYNOSDK_USE_SHARE_DB

/**
 * Get "loose" permission, as NA/RO/RW, of @p szUser against @p pShare.
 *
 * If @p pShare is forbidden/readonly, NA/RO is returned. Otherwise,
 * as long as @p szUser has ANY permission against @p pShare, RW is returned.
 * This is also why we call it "loose", compare with SLIBShareUserRightGet().
 *
 * This function is appropriate when list available shares for given user.
 * A share should be listed if not NA, further permission check will be done
 * by kernel in subsequent read/write operations.
 *
 * This function should have the same result with SYNOShareUserPrivGet()
 * But this function will not seteuid, so the multi-thread program can use it.
 *
 * @param[in]   szUser   User name, must not be NULL.
 * @param[in]   pShare   Share handle, must not be NULL.
 *
 * @retval   >=0 Share permission [SHARE_NA/SHARE_RW/SHARE_RO].
 * @retval   -1 On error.
 *
 * @grantable No
 * @user @p szUser
 *
 * @apparmor abstractions/synosdk/usergroup
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOShareUserPrivCalc(const char *szUser, const PSYNOSHARE pShare);

/**
 * Translate ACL permission, as NA/RO/RW, of @p szUser against @p pShare.
 *
 * If @p pShare is ACL-only share, "every" RO/RW ACL bit should be true then
 * RO/RW is returned. For example, if @p szUser is able to list forlders not
 * can't read extended attribute, NA is returned.
 *
 * Compare with SYNOShareUserPrivGet(), this function is stricter. If it returns
 * SHARE_RO/SHARE_RW, @p szUser has ALL types of read/write permissions (see
 * SYNO_ACL_PERM) against @p pShare.
 *
 * @grantable No
 * @user Who has the ACL privilege to read ACL privileges of @p pShare
 *
 * @param[in]   szUser   User name, must not be NULL.
 * @param[in]   pShare   Share handle, must not be NULL.
 *
 * @retval   >=0 Share permission [SHARE_NA/SHARE_RW/SHARE_RO].
 * @retval   -1 On error.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBShareUserRightGet(const char *szUser, const PSYNOSHARE pShare);

/**
 * @}
 */
