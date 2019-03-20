/* bandwidth_curr_time_get.c */

/**
 * Get the current time in micro_seconds
 *
 * @ingroup bandwidth
 *
 * @return micro_seconds
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor  None
 */
int64_t SYNOBandwidthCurrTimeGet(void);

/* bandwidth_op.c */

/**
 * Check if @a a < @a b
 *
 * @ingroup bandwidth_op
 *
 * @param[in] a     Speed in KB/s
 * @param[in] b     Speed in KB/s
 *
 * @retval TRUE     a < b
 * @retval FALSE    otherwise
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 */
BOOL SYNOBandwidthIsLessThan(syno_speed_t a, syno_speed_t b);

/**
 * Check if @a a > @a b
 *
 * @ingroup bandwidth_op
 *
 * @param[in] a     Speed in KB/s
 * @param[in] b     Speed in KB/s
 *
 * @retval TRUE     a > b
 * @retval FALSE    otherwise
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 *
 */
BOOL SYNOBandwidthIsLargerThan(syno_speed_t a, syno_speed_t b);

/**
 * @a a + @a b
 *
 * @ingroup bandwidth_op
 *
 * @param[in] a     Speed in KB/s
 * @param[in] b     Speed in KB/s
 *
 * @return @a a + @a b (Speed in KB/s)
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 */
syno_speed_t SYNOBandwidthSum(syno_speed_t a, syno_speed_t b);

/* bandwidth_enum.c */

/**
 * Get addon protocol config path by protocol enum number
 *
 * @ingroup bandwidth_addon
 *
 * @param[in]   iProtocol   protocol number
 * @param[out]  szPath      config path
 * @param[in]   cbPath      size of the given buffer of @p szPath
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   SYNOBandwidthEnumToNameAddon()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthGetAddonConfigPath(int iProtocol, char *szPath, size_t cbPath);

/**
 * Get addon protocol name by protocol enum number
 *
 * @ingroup bandwidth_addon
 *
 * @param[in]   iProtocol   protocol number
 * @param[out]  szProtocol  protocol name
 * @param[in]   cbProtocol  size of the given buffer of @p szProtocol
 *
 * @retval  1   success
 * @retval  0   not found
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_PATH_NOT_FOUND  if addon configuration file cannot found
 * @exception   ERR_PATH_CONFLICT   if there are multiple addon configurations
 * @exception   ERR_INVALID_PATH
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthEnumToNameAddon(int iProtocol, char *szProtocol, size_t cbProtocol);

/**
 * Get protocol enum number by the given protocol name
 *
 * @ingroup bandwidth_addon
 *
 * @param[in]   szName  protocol name
 *
 * @retval  >0  protocol enum number
 * @retval  0   not found
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_PATH_NOT_FOUND  if addon configuration file cannot found
 * @exception   ERR_PATH_CONFLICT   if there are multiple addon configurations
 * @exception   ERR_INVALID_PATH
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthEnumToValueAddon(const char *szName);

/**
 * Get the name of enum list with value @a val
 *
 * @ingroup bandwidth
 *
 * @param[in]   enum_list     the enum_list to search
 * @param[in]   val           the value to match
 * @param[out]  szProtocol    protocol name
 * @param[in]   cbProtocol    size of the given buffer of @p szProtocol
 *
 * @retval -1   error
 * @retval 0    not found
 * @retval 1    success
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   SYNOBandwidthEnumToNameAddon()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthEnumToName(const SYNO_BANDWIDTH_ENUM_LIST *enum_list, int val, char *szProtocol, int cbProtocol);

/**
 * Get the value of enum list with name @a szName
 *
 * @ingroup bandwidth
 *
 * @param[in] enum_list     the enum_list to search
 * @param[in] szName        the name to match
 *
 * @retval -1           the name was not found
 * @retval  0           not found
 * @retval  1           the found value
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   SYNOBandwidthEnumToValueAddon()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthEnumToValue(const SYNO_BANDWIDTH_ENUM_LIST *enum_list, const char *szName);

/* bandwidth_limit_init.c */

/**
 * For user @a uid and whose groups,
 * it tries to load corresponding conf files to array @a ppLimit,
 * and also indicates if the user/group conf exist or not.
 *
 * @ingroup bandwidth
 *
 * @param[in]   uid                 user uid
 * @param[in]   pGlobalConf         Global conf, was used for protocol_type
 *                                  and user_group_policy
 * @param[out]  ppLimit             address of array SYNO_BANDWIDTH_LIMIT* for
 *                                  individual conf of user/groups
 * @param[out]  pblUserConfExist    address of variable to indicate
 *                                  if the user conf exists
 * @param[out]  pblGroupConfExist   address of variable to indicate
 *                                  if any group conf exists
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_FORMAT_ERROR
 * @exception   SYNOBandwidthConfGetByID()
 * @exception   SYNOUserGetByUID() from libsynosdk
 * @exception   SLIBGroupInfoListGet() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthLimitInit(uid_t uid, const SYNO_BANDWIDTH_GLOBAL_CONF *pGlobalConf, SYNO_BANDWIDTH_LIMIT **ppLimit, BOOL *pblUserConfExist, BOOL *pblGroupConfExist);

/* bandwidth_status_convert.c */

/**
 * transform SYNO_BANDWIDTH_STATUS to PSLIBSZHASH.
 *
 * @ingroup bandwidth
 *
 * @param[out]  ppHash      address of PSLIBSZHASH
 * @param[in]   pStatus     address of SYNO_BANDWIDTH_STATUS
 *
 * @retval  0   success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 * @apparmor    None
 */
int SYNOBandwidthInitHashFromStatus(PSLIBSZHASH *ppHash, const SYNO_BANDWIDTH_STATUS *pStatus);

/**
 * transform PSLIBSZHASH to SYNO_BANDWIDTH_STATUS
 *
 * @ingroup bandwidth
 *
 * @param[out]  pStatus     address of SYNO_BANDWIDTH_STATUS
 * @param[in]   pHash       address of PSLIBSZHASH
 *
 * @retval  0   success
 * @retval -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable   no
 * @apparmor    None
 */
int SYNOBandwidthInitStatusFromHash(SYNO_BANDWIDTH_STATUS *pStatus, const PSLIBSZHASH pHash);

/* bandwidth_status_get_all.c */

/**
 * Obtain the connections in a status file and add them into a list.
 *
 * @ingroup     bandwidth
 *
 * @param[in]   owner_type      type of @a id,
 * can be one of following values:
 *   - SYNO_BW_OWNER_TYPE_USER
 *   - SYNO_BW_OWNER_TYPE_GROUP
 * @param[in]   id              uid or gid
 * @param[in]   protocol_filter type of protocol,
 * can be union of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 *   - SYNO_BW_PROTOCOL_ALL
 *
 * @param[in]   transfer_filter type of transfer direction
 * @param[out]  pStatusList     address of SYNO_BANDWIDTH_STATUS_LIST
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SYNOBandwidthIStatusGetAll()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusGetAll(enum SYNO_BANDWIDTH_OWNER_TYPE owner_type, unsigned id, int protocol_filter, enum SYNO_BANDWIDTH_TRANSFER transfer_filter, SYNO_BANDWIDTH_STATUS_LIST *pStatusList);

/**
 * Obtain the connections in a status file and add them into a list.
 *
 * @ingroup     bandwidth
 *
 * @param[in]   szStatusFile    status file
 * @param[in]   protocol_filter type of protocol,
 * can be union of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 *   - SYNO_BW_PROTOCOL_ALL
 *
 * @param[in]   transfer_filter type of transfer direction
 * @param[out]  pStatusList     address of SYNO_BANDWIDTH_STATUS_LIST
 * @param[in]   blMerge         When this flag is true,
 * only uSpeedBps and uExpectSpeedBps are meaningful.
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   SYNOBandwidthInitStatusFromHash()
 * @exception   SLIBCFileEnumSection() from libsynocore
 * @exception   SLIBCFileGetSection() from libsynocore
 * @exception   SLIBCFileRemoveSection() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthIStatusGetAll(const char *szStatusFile, int protocol_filter, enum SYNO_BANDWIDTH_TRANSFER transfer_filter, SYNO_BANDWIDTH_STATUS_LIST *pStatusList, BOOL blMerge);

/**
 * Free the status list
 *
 * @ingroup bandwidth
 *
 * @param[in,out] bwStatusList  address of SYNO_BANDWIDTH_STATUS
 *
 * @return      None
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor    None
 */
void SYNOBandwidthStatusListFree(SYNO_BANDWIDTH_STATUS_LIST *bwStatusList);

/* bandwidth_status_get.c */

/**
 * Read the connection info from status file to SYNO_BANDWIDTH_STATUS (internal use)
 *
 * @ingroup bandwidth
 *
 * @param[in]   owner_type      type of @a id,
 * can be one of following values:
 *   - SYNO_BW_OWNER_TYPE_USER
 *   - SYNO_BW_OWNER_TYPE_GROUP
 * @param[in]   id              uid or gid
 * @param[in]   pid             connection id
 * @param[in]   transfer_type   can be SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[out]  pStatus         addresss of SYNO_BANDWIDTH_STATUS
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SYNOBandwidthInitStatusFromHash()
 * @exception   SLIBCFileGetSection() from libsynocore
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthIStatusGet(enum SYNO_BANDWIDTH_OWNER_TYPE owner_type, unsigned id, pid_t pid, enum SYNO_BANDWIDTH_TRANSFER transfer_type, SYNO_BANDWIDTH_STATUS *pStatus);

/**
 * Read the connection info from status file to SYNO_BANDWIDTH_STATUS (external use)
 *
 * @ingroup bandwidth
 *
 * @param[in]   owner_type      type of @a id,
 * can be one of following values:
 *   - SYNO_BW_OWNER_TYPE_USER
 *   - SYNO_BW_OWNER_TYPE_GROUP
 * @param[in]   id              uid or gid
 * @param[in]   transfer_type   can be SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[out]  pStatus         addresss of SYNO_BANDWIDTH_STATUS
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   SYNOBandwidthIStatusGet()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusGet(enum SYNO_BANDWIDTH_OWNER_TYPE owner_type, unsigned id, enum SYNO_BANDWIDTH_TRANSFER transfer_type, SYNO_BANDWIDTH_STATUS *pStatus);

/* bandwidth_status_dump.c */

/**
 * Dump SYNO_BANDWIDTH_STATUS
 *
 * @ingroup bandwidth
 *
 * @param[in]   fp      FILE pointer to output file
 * @param[in]   pStatus address of SYNO_BANDWIDTH_STATUS
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthInitHashFromStatus()
 * @exception   SLIBCSzHashAlloc() from libsynocore
 * @exception   SYNOUserGetByUID() from libsynosdk
 * @exception   SYNOGroupGetByGID() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusDump(FILE *fp, const SYNO_BANDWIDTH_STATUS *pStatus);

/* bandwidth_status_remove.c */

/**
 * remove connection from status file of user @a uid, including of groups (external use)
 *
 * @ingroup bandwidth
 *
 * @param[in]   pConfig         addresss of SYNO_BANDWIDTH_CONFIG
 * @param[in]   transfer_filter can be union of SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCFileExist() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusRemove(const SYNO_BANDWIDTH_CONFIG *pConfig, enum SYNO_BANDWIDTH_TRANSFER transfer_filter);

/**
 * set user's bandwidth status to @p active limitation by @p szUserName
 *
 * @param[in]   szUserName      username
 * @param[in]   transfer_type   transfer direction
 * @param[in]   pid             pid
 * @param[in]   active          active status
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   SYNOBandwidthIStatusGet()
 * @exception   SYNOBandwidthStatusSave()
 * @exception   SYNOUserGet() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusSetActiveByUserName(const char *szUserName, enum SYNO_BANDWIDTH_TRANSFER transfer_type, pid_t pid, unsigned active);

/**
 * Remove all user's bandwidth status by @p szUserName
 *
 * @param[in]   szUserName      username
 * @param[in]   transfer_filter transfer direction
 * @param[in]   pid             pid
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_FORMAT_ERROR
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCFIleExist() from libsynocore
 * @exception   SYNOUserGet() from libsynosdk
 * @exception   SLIBGroupInfoListGet() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusForceRemoveAllByUserName(const char *szUserName, enum SYNO_BANDWIDTH_TRANSFER transfer_filter, pid_t pid);

/**
 * Remove all user's bandwidth status by @p uid
 *
 * @param[in]   uid             uid
 * @param[in]   transfer_filter transfer direction
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_FORMAT_ERROR
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCFIleExist() from libsynocore
 * @exception   SYNOUserGetByUID() from libsynosdk
 * @exception   SLIBGroupInfoListGet() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusForceRemoveAllByUID(uid_t uid, enum SYNO_BANDWIDTH_TRANSFER transfer_filter);

/**
 * Remove group's bandwidth status
 *
 * @param[in] OccGroups[]       gids
 * @param[in] iOccGroups        number of gids
 * @param[in] transfer_filter   transfer direction
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCFileExist() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusRemoveByOccGroups(gid_t OccGroups[], int iOccGroups, enum SYNO_BANDWIDTH_TRANSFER transfer_filter);

/* bandwidth_status_save.c */
/**
 * Update status to all status files, including of groups (external use)
 *
 * @ingroup bandwidth
 *
 * @param[in]       uid         user id
 * @param[in]       pConfig     address of SYNO_BANDWIDTH_CONFIG
 * @param[in,out]   pStatus     address of SYNO_BANDWIDTH_STATUS
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       ERR_STAT_FAILED
 * @exception       ERR_OUT_OF_MEMORY
 * @exception       SYNOBandwidthEnumToName()
 * @exception       SYNOBandwidthInitHashFromStatus()
 * @exception       SYNOBandwidthStatusSetSection()
 * @exception       SYNOBandwidthStatusAddSection()
 * @exception       SLIBCFileTouch() from libsynocore
 * @exception       SYNOFSMkDirP() from libsynosdk
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusSave(uid_t uid, const SYNO_BANDWIDTH_CONFIG *pConfig, SYNO_BANDWIDTH_STATUS *pStatus);

/* bandwidth_status_init.c */

/**
 * Initialize SYNO_BANDWIDTH_STATUS and obtain the current time that will be used in the main loop.
 *
 * @ingroup bandwidth
 *
 * @param[in,out]   pConfig         address of SYNO_BANDWIDTH_CONFIG
 * @param[in]       transfer_type   can be SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[in]       szFileName      The filenmae transmitting
 * @param[in]       pTime           address of current time for return
 * @param[in,out]   pStatus         address of SYNO_BANDWIDTH_STATUS
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthExpectSpeedEstimateByPolicy()
 * @exception   SYNOBandwidthStatusSave()
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusInit(SYNO_BANDWIDTH_CONFIG *pConfig, enum SYNO_BANDWIDTH_TRANSFER transfer_type, const char *szFileName, int64_t *pTime, SYNO_BANDWIDTH_STATUS *pStatus);

/* bandwidth_status_add_section.c */

/**
 * Add a section named @a szSection in the @a szFile, and set
 * new parameters which stored in @a pHash.
 *
 * @ingroup bandwidth
 *
 * @param[in] szFile        The path of the configure file. Should not be NULL.
 * @param[in] szSection     The name of a section which you want to set new value. Should not be NULL.
 * @param[in] pHash         The pointer to a hash which contains (key, value) pairs. Should not be NULL.
 *
 * @retval 1    success
 * @retval 0    section already exists
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OPEN_FAILED
 * @exception   ERR_WRITE_FAILED
 * @exception   SLIBCFileHash2File() from libsynocore
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthStatusAddSection(const char *szFile, const char *szSection, PSLIBSZHASH pHash);

/* bandwidth_status_set_section.c */

/**
 * Set parameters @a pHash into an existed section @a szSection of @a szFile.
 *
 * @param[in] szFile        The path of the configure file. Should not be NULL.
 * @param[in] szSection     The name of a section which you want to set new value. Should not be NULL.
 * @param[in] pHash         The pointer to a hash which contains (key, value) pairs. Should not be NULL.
 *
 * @retval 1    success
 * @retval 0    section not found
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OPEN_FAILED
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_WRITE_FAILED
 * @exception   ERR_READ_FAILED
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   ERR_RENAME_FAILED
 * @exception   SLIBCFileMatchSection()
 * @exception   SLIBCFileHash2File() from libsynocore
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 *
 * @see SLIBCIFileMatchSection()
 */
int SYNOBandwidthStatusSetSection(const char *szFile, const char *szSection, PSLIBSZHASH pHash);

/**
 * Remove an existed section @a szSection from @a szFile
 *
 * @param[in] szFile        The path of the configure file. Should not be NULL.
 * @param[in] szSection     The name of a section which you want to set new value. Should not be NULL.
 *
 * @retval 1    success
 * @retval 0    section not found
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OPEN_FAILED
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_WRITE_FAILED
 * @exception   ERR_READ_FAILED
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   ERR_RENAME_FAILED
 * @exception   SLIBCFileMatchSection()
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 *
 * @see SLIBCIFileMatchSection()
 */
int SYNOBandwidthStatusRemoveSection(const char *szFile, const char *szSection);

/* bandwidth_conf_convert.c */
/**
 * transform SYNO_BANDWIDTH_CONF to PSLIBSZHASH.
 *
 * @ingroup bandwidth
 *
 * @param[out] ppHash       address of PSLIBSZHASH
 * @param[in]  pConf        address of SYNO_BANDWIDTH_CONF
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_FORMAT_ERROR
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCSzHashSetValue() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthInitHashFromConf(PSLIBSZHASH *ppHash, const SYNO_BANDWIDTH_CONF *pConf);

/**
 * transform PSLIBSZHASH to SYNO_BANDWIDTH_CONF
 *
 * @ingroup bandwidth
 *
 * @param[out] pConf         address of SYNO_BANDWIDTH_CONF
 * @param[in] pHash         address of PSLIBSZHASH
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCSzHashSetValue() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthInitConfFromHash(SYNO_BANDWIDTH_CONF *pConf, const PSLIBSZHASH pHash);

/**
 * transform SYNO_BANDWIDTH_GLOBAL_CONF to PSLIBSZHASH
 *
 * @ingroup bandwidth
 *
 * @param[in]   ppHash          address of PSLIBSZHASH
 * @param[out]  pConf           address of SYNO_BANDWIDTH_CONF
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCSzHashSetValue() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthInitHashFromGlobalConf(PSLIBSZHASH *ppHash, const SYNO_BANDWIDTH_GLOBAL_CONF *pConf);

/**
 * transform PSLIBSZHASH to SYNO_BANDWIDTH_GLOBAL_CONF
 *
 * @ingroup bandwidth
 *
 * @param[out] pHash       address of SLIBSZHASH
 * @param[in]  pConf        address of SYNO_BANDWIDTH_CONF
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_FORMAT_ERROR
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCSzHashSetValue() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthInitGlobalConfFromHash(SYNO_BANDWIDTH_GLOBAL_CONF *pConf, const PSLIBSZHASH pHash);
/* bandwidth_conf_dump.c */

/**
 * print formated header of SYNO_BANDWIDTH_CONF to fp
 *
 * @ingroup print
 *
 * @param[in,out] fp         pointer of FILE to output
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 * @apparmor    None
 */
int SYNOBandwidthConfDumpHeader(FILE *fp);

/**
 * dump SYNO_BANDWIDTH_CONF info to fp
 *
 * @ingroup print
 *
 * @param[in,out]   fp      pointer of FILE to output
 * @param[in]       pConf   address of SYNO_BANDWIDTH_CONF to dump
 *
 * @retval 0        success
 * @retval -1       error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       ERR_NOT_SUPPORT
 * @exception       SYNOBandwidthInitHashFromConf()
 * @exception       SLIBCSzHashGetValue() from libsynocore
 * @exception       SYNOUSerGetByUID() from libsynosdk
 * @exception       SYNOGroupByGID() from libsynosdk
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthConfDump(FILE *fp, const SYNO_BANDWIDTH_CONF *pConf);

/* bandwidth_conf_get_by_id.c */

/**
 * Load info from conf file to SYNO_BANDWIDTH_CONF
 *
 * @ingroup bandwidth
 *
 * @param[in]   owner_type          type of @a id,
 * can be one of following values
 *   - SYNO_BW_OWNER_TYPE_USER
 *   - SYNO_BW_OWNER_TYPE_GROUP
 * @param[in]   id                  uid or gid
 * @param[in]   protocol_type       type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 * @param[out] pConf                address of SYNO_BANDWIDTH_CONF
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthConfPath()
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SYNOBandwidthInitConfFromHash()
 * @exception   SYNOCFileGetSection() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthConfGetByID(enum SYNO_BANDWIDTH_OWNER_TYPE owner_type, unsigned id, int protocol_type, SYNO_BANDWIDTH_CONF *pConf);

/* bandwidth_config_get.c */

/**
 *
 * Load config from files to SYNO_BANDWIDTH_CONFIG,
 * including global, user, and belonged groups' config files.
 *
 * @ingroup bandwidth
 *
 * @param[in] uid               user uid
 * @param[in] protocol_type     type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 * @param[out] pConfig         address of SYNO_BANDWIDTH_CONFIG
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthLimitInit()
 * @exception   SYNOBandwidthGlobalConfGet()
 * @exception   SYNOBandwidthInitConfig()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthConfigGet(uid_t uid, int protocol_type, SYNO_BANDWIDTH_CONFIG *pConfig);

/* bandwidth_conf_path.c */

/**
 * Obtain the conf path corresponding to protocol
 *
 * @ingroup bandwidth
 *
 * @param[in] protocol_type     type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 *   - SYNO_BW_PROTOCOL_ALL
 * @param[out] szConfPath       output buffer of path
 * @param[in] cbConfPath        size of buffer @a szConfPath
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthEnumToName()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthConfPath(int protocol_type, char *szConfPath, size_t cbConfPath);

/* bandwidth_conf_set_by_id.c */

/**
 * Save SYNO_BANDWIDTH_CONF info to conf file
 *
 * @ingroup bandwidth
 *
 * @param[in] pConf         the conf info to save
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthConfPath()
 * @exception   SYNOBandwidthInitHashFromConf()
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SLIBCFileExist() from libsynocore
 * @exception   SLIBCFileTouch() from libsynocore
 * @exception   SLIBCFileSetSection() from libsynocore
 * @exception   SLIBCFileAddSection() from libsynocore
 * @exception   SYNOFSMkdirP() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthConfSetByID(const SYNO_BANDWIDTH_CONF *pConf);

/* bandwidth_config_free.c */

/**
 * Free allocated structures in SYNO_BANDWIDTH_CONFIG.
 *
 * Should not pass NULL Pointer to SYNOBandwidthConfigFree().
 *
 * @ingroup bandwidth
 *
 * @param[in] pConfig         address of SYNO_BANDWIDTH_CONFIG to be freed.
 *
 * @exception   None
 *
 * @grantable   no
 * @apparmor    None
 */
void SYNOBandwidthConfigFree(SYNO_BANDWIDTH_CONFIG *pConfig);

/* bandwidth_global_conf_get.c */

/**
 * Load global config to SYNO_BANDWIDTH_GLOBAL_CONF corresponding to protocol @a protocol_type
 *
 * @ingroup bandwidth
 *
 * @param[in] protocol_type     type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 * @param[out] pConf            address of SYNO_BANDWIDTH_GLOBAL_CONF
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthConfPath()
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SYNOBandwidthInitGlobalConfFromHash()
 * @exception   SLIBCFileGetSection() from libsynocore
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthGlobalConfGet(int protocol_type, SYNO_BANDWIDTH_GLOBAL_CONF *pConf);

/* bandwidth_global_conf_dump.c */

/**
 * print formated header of SYNO_BANDWIDTH_GLOBAL_CONF to fp
 *
 * @ingroup bandwidth
 *
 * @param[in,out] fp         pointer of FILE to output
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthGlobalConfDumpHeader(FILE *fp);

/**
 * dump SYNO_BANDWIDTH_GLOBAL_CONF info to fp
 *
 * @ingroup bandwidth
 *
 * @param[in,out]   fp          pointer of FILE to output
 * @param[in]       pConf       address of SYNO_BANDWIDTH_GLOBAL_CONF to dump
 *
 * @retval 0        success
 * @retval -1       error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       ERR_NOT_SUPPORT
 * @exception       SYNOBandwidthInitHashFromGlobalConf()
 * @exception       SYNOBandwidthEnumToName()
 * @exception       SLIBCSzHashGetValue() from libsynocore
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthGlobalConfDump(FILE *fp, const SYNO_BANDWIDTH_GLOBAL_CONF *pConf);

/* bandwidth_global_conf_set.c */

/**
 * Save SYNO_BANDWIDTH_GLOBAL_CONF info to global conf file
 *
 * @ingroup bandwidth
 *
 * @param[in] pConf         the conf info to save
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthConfPath()
 * @exception   SYNOBandwidthEnumToName()
 * @exception   SYNOBandwidthInitHashFromGlobalConf()
 * @exception   SLIBCFileTouch() from libsynocore
 * @exception   SLIBCFileSetSection() from libsynocore
 * @exception   SLIBCFileAddSection() from libsynocore
 * @exception   SYNOFSMkdirP() from libsynosdk
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthGlobalConfSet(SYNO_BANDWIDTH_GLOBAL_CONF *pConf);

/* bandwidth_conf_check_enabled.c */
/**
 * Check if any bandwidth settings were enabled.
 *
 * @ingroup bandwidth
 *
 * @param[in] pConfig   address of SYNO_BANDWIDTH_CONFIG. Should not be NULL.
 *
 * @retval TRUE     is enabled.
 * @retval FALSE    is disabled.
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 *
 */
int SYNOBandwidthConfCheckEnabled(SYNO_BANDWIDTH_CONFIG *pConfig);

/* bandwidth_speed_estimate.c */

/**
 * Given the time elapsed and bytes transferred, calculate the real speed in KB/s
 *
 * @ingroup bandwidth
 *
 * @param[in] time_diff              the time elapsed
 * @param[in] cbTransferByte         the bytes transferred
 *
 * @return real speed in B/s
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 */
syno_speed_t SYNOBandwidthSpeedEstimate(int64_t time_diff, size_t cbTransferByte);

/* bandwidth_expect_speed_estimate.c */
/**
 * Estimate the available bandwidth for a user or group.
 *
 * It tries to obtain the connection status of a specific user/group.
 *
 * @ingroup bandwidth
 *
 * @param[in] uid           user id
 * @param[in] pConf         SYNO_BANDWIDTH_CONF struct for a user or group
 * @param[in] transfer_type SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[out] pMaxSpeedBps address of variable for returning the available speed in B/s
 * @param[in] pid           connection pid
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthStatusGetAll()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthExpectSpeedEstimate(uid_t uid, SYNO_BANDWIDTH_CONF *pConf, enum SYNO_BANDWIDTH_TRANSFER transfer_type, syno_speed_t *pMaxSpeedBps, pid_t pid);

/* bandwidth_expect_speed_estimate_by_policy.c */
/**
 * Calculate the expected speed according to the policy in @a pConfig->global_conf
 *
 * @ingroup bandwidth
 *
 * @param[in]       transfer_type   SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[in,out]   pConfig         pConfig->global_conf will be referenced and
 *                                  pConfig->pLimit[i]..uOccupyRatio will be updated.
 * @param[out]      pSpeedBps       address of variable for the final calculated expected speed in B/s
 * @param[in]       blOnline        indicate if we need to check the status file
 *                                  for calculating the expected speed.
 *                                  FALSE is leading to calculate the expected speed
 *                                  based on the conf files
 *
 * @retval 0        success
 * @retval -1       error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       SYNOBandwidthExpectSpeedEstimate()
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthExpectSpeedEstimateByPolicy(enum SYNO_BANDWIDTH_TRANSFER transfer_type, SYNO_BANDWIDTH_CONFIG *pConfig, syno_speed_t *pSpeedBps, BOOL blOnline);

/* bandwidth_sleep_estimate.c */

/**
 * Given the bytes transferred, expected speed and the elapsed time (in micro_seconds),
 * calculate how many micro_seconds should be in idle to meet the expected speed.
 *
 * @ingroup bandwidth
 *
 * @param[in] time_elapsed         Time elapsed during the transmission
 * @param[in] cbTransferByte         How many bytes transferred during @a time_elapsed
 * @param[in] uExpectSpeedBps         The expected speed in KB/s
 *
 * @retval >=0          micro_seconds that should be in idle
 * @retval otherwise    error
 *
 * @exception       None
 * @grantable       no
 * @apparmor        None
 *
 */
int64_t SYNOBandwidthSleepEstimate(int64_t time_elapsed, size_t cbTransferByte, syno_speed_t uExpectSpeedBps);

/* bandwidth_sleep_in_loop.c */

/**
 * Get gid of configs
 *
 * @ingroup bandwidth
 *
 * @param[out]  OccGroups   gid of configs
 * @param[out]  piOccGroups numbers of OccGroups
 * @param[in]   pConfig     Config objects
 *
 * @retval  0   success
 * @retval  -1  error
 *
 * @exception   None
 * @grantable   no
 * @apparmor    None
 */
int SYNOBandwidthOccGroupsGet(gid_t OccGroups[], int *piOccGroups, const SYNO_BANDWIDTH_CONFIG *pConfig);

/**
 * initialize config file
 *
 * @ingroup bandwidth
 *
 * @param[in] pConfig         The address of config file
 * @param[in] time_now         the timestamp of current time
 *
 * @retval TRUE     success
 * @retval FALSE    error
 *
 * @exception       None
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
BOOL SYNOBandwidthInitConfig(SYNO_BANDWIDTH_CONFIG *pConfig, int64_t time_now);

/**
 * check running state of user/group limit enable
 *
 * @ingroup bandwidth
 *
 * @param[in] pConfig         The address of config file
 *
 * @retval TRUE     success
 * @retval FALSE    error
 *
 * @exception       None
 * @grantable       no
 * @apparmor        None
 *
 */
BOOL SYNOBandwidthIsUserGroupLimitEnable(SYNO_BANDWIDTH_CONFIG *pConfig);

/**
 * Estimate the expect speed and sleep time, and then sleep.
 *
 * The only API should be placed in the transmiting loop.
 *
 * @ingroup bandwidth
 *
 * @param[in,out] pConfig               address of SYNO_BANDWIDTH_CONFIG
 * @param[in] uTransferedBytesLastLoop  How many bytes transferred this time
 * @param[in] uProgress                 (size_t)(Total transferred bytes * 10000.0 / Total bytes)
 * @param[in] pTimeLast                 The timestamp before transmission
 * @param[in,out] pStatus               address of SYNO_BANDWIDTH_STATUS.
 *                                      timestamp, uSpeedBps and uProgress will be updated.
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       ERR_ACCESS_DENIED
 * @exception       SYNOBandwidthStatusRemove()
 * @exception       SYNOBandwidthStatusSave()
 * @exception       SYNOBandwidthExpectSpeedEstimateByPolicy()
 * @exception       SYNOBandwidthOccGroupsGet()
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthSleepInLoop(SYNO_BANDWIDTH_CONFIG *pConfig, size_t uTransferedBytesLastLoop, size_t uProgress, int64_t *pTimeLast, SYNO_BANDWIDTH_STATUS *pStatus);

/* bandwidth_transfer_size_estimate.c */

/**
 * Given the sleep time,
 * it estimates the maximum filesize that can be transferred according to current expect speed.
 *
 * @ingroup bandwidth
 *
 * @param[in,out]   pConfig             address of SYNO_BANDWIDTH_CONFIG
 * @param[in]       transfer_type       can be SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[in]       uMaxTransferBytes   maximum transfer bytes
 * @param[out]      pTransferBytes      address of variable for maximum transferred bytes.
 *                                      0 means unlimited.
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthExpectSpeedEstimateByPolicy()
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthTransferSizeEstimate(SYNO_BANDWIDTH_CONFIG *pConfig, enum SYNO_BANDWIDTH_TRANSFER transfer_type, size_t uMaxTransferBytes, size_t *pTransferBytes);

/* bandwidth_simulate.c */

/**
 * The function is an example of use of the libsynobandwidth library. It also provides a way to stress the functionality.
 *
 * @ingroup bandwidth
 *
 * @param[in] szUserName        Username
 * @param[in] protocol_type     type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 * @param[in] transfer_type     can be SYNO_BW_TRANSFER_UPLOAD or SYNO_BW_TRANSFER_DOWNLOAD
 * @param[in] uSizeKB           total file size
 *
 * @retval 0    success
 * @retval -1   error
 *
 * @exception       ERR_BAD_PARAMETERS
 * @exception       SYNOBandwidthConfigGet()
 * @exception       SYNOBandwidthStatusInit()
 * @exception       SYNOBandwidthStatusRemove()
 * @exception       SYNOBandwidthHupRecv()
 * @exception       SYNOBandwidthSleepInLoop()
 * @exception       SYNOUserGetUGID() from libsynosdk
 *
 * @grantable       no
 * @apparmor        abstractions/libsynobandwidth
 */
int SYNOBandwidthSimulate(const char *szUserName, int protocol_type, enum SYNO_BANDWIDTH_TRANSFER transfer_type, size_t uSizeKB);

/* bandwidth_preview.c */

/**
 * Get the speed of a protocol with a specific user
 *
 * @param[in]   uid             user id
 * @param[in]   protocol_type   type of protocol,
 * can be one of following values
 *   - SYNO_BW_PROTOCOL_FILESTATION
 *   - SYNO_BW_PROTOCOL_WEBDAV
 *   - SYNO_BW_PROTOCOL_FTP
 *   - SYNO_BW_PROTOCOL_RSYNC
 * @param[out]  uSpeedBps       upload and download speed of the protocol
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   SYNOBandwidthConfigGet()
 * @exception   SYNOBandwidthExpectSpeedEstimateByPolicy()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthPreview(uid_t uid, int protocol_type, syno_speed_t uSpeedBps[SYNO_BW_TRANSFER_ALL]);

/* bandwidth_hup.c */

/**
 * Hup the FileStation process
 *
 * @ingroup bandwidth
 * @return      None
 * @exception   None
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
void SYNOBandwidthHupFileStaion(void);

/**
 * Hup the WebDAV process
 *
 * @ingroup bandwidth
 * @return      None
 * @exception   None
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
void SYNOBandwidthHupWebDAV(void);

/**
 * Hup the Simulator
 *
 * @ingroup bandwidth
 * @return      None
 * @exception   None
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
void SYNOBandwidthHupSimulator(void);

/**
 * Hup the receiving process
 *
 * @ingroup bandwidth
 *
 * @param[in,out]   pConfig         address of SYNO_BANDWIDTH_CONFIG
 * @param[in]       pStatus         address of SYNO_BANDWIDTH_STATUS
 * @param[out]      pTime           current time
 *
 * @retval  0       success
 * @retval  -1      failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOBandwidthOccGroupsGet()
 * @exception   SYNOBandwidthStatusRemoveByOccGroups()
 * @exception   SYNOBandwidthConfigGet()
 *
 * @grantable   no
 * @apparmor    abstractions/libsynobandwidth
 */
int SYNOBandwidthHupRecv(SYNO_BANDWIDTH_CONFIG *pConfig, SYNO_BANDWIDTH_STATUS *pStatus, int64_t *pTime);
