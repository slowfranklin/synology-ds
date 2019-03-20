/**
 * @addtogroup VOLUME
 *
 * @{
 */

/**
 * Get volume id by volume mount path.
 *
 * For example: /volume1, /volumeX1, /volume1/public
 *
 * @param[in]   szPath   volume path or share path
 * @param[out]   pVolID   volume id information
 *
 * @retval -1 error
 * @retval 0 not supported volume path.
 * @retval 1 success
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int VolumePathParse(const char *szPath, VOL_ID *pVolID);

/**
 * This function is to overcome the problem that "USB volume path" might contain more than 1 digital,
 * so the original function VolumePathParse and struct VOL_ID is not enough to rebuild the full path
 *
 * @param[in]   szPath   you can pass any path that is on a volume, such as volume path, share path or sharebin path
 * @param[out]   pVolInfo   the parsed result
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_2) int VolumePathParseEx(const char *szPath, VOL_INFO *pVolInfo);

/**
 * Get volume id by volume mount path.
 *
 * @param[in]   szPath   volume path
 *
 * @retval >=1 volume id
 * @retval 0 not supported volume path
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_PATHNAME
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOVolIDParse(const char *szPath);

/**
 * Get all the mounted volume including the usb and sata
 * volumes.
 *
 * @param[in] iGetOne       1 means only get the first mounted volume, and 0 means get all the mounted volume.
 * @param[in] iVolumeType   the desired volume type to return. Can be Internal, Ebox, Usb, or Sata.
 * @param[in] volInfoOpt    option to filter volumes please refer to enum type VOLUME_INFO_OPTION defined in libsynocore/include/synoglobal.h
 *
 * @retval   !NULL - link list with SYNOVOLINFO
 * @retval   NULL - error encountered
 *
 * @note
 * This function uses /proc/mounts, so /proc is assumed
 * to be mounted before calling this function. Else it
 * will not work correctly.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) SYNOVOLINFOLIST *SYNOMountVolAllEnum(int iGetOne, int iVolumeType, int volInfoOpt);

/**
 *
 * @param[in]   pVol   Volume list.
 * @param[in]   pLoc   If NULL means no limitation. Otherwise give value of DEV_LOCATION.
 *
 * @retval >=0 counts of volume
 * @retval -1 error
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOMountVolInfoCount(const SYNOVOLINFOLIST *pVol, const int *pLoc);

/**
 * Get all the volume information.
 *
 * @param[in]   iGetOne       1 means only get the first mounted volume, and 0 means get all the mounted volume.
 * @param[in]   volInfoOpt    Option to filter volumes. Please refer to enum type VOLUME_INFO_OPTION defined in libsynocore/include/synoglobal.h
 *
 * @retval   !NULL link list with SYNOVOLINFO
 * @retval   NULL error encountered
 *
 * This function uses /proc/mounts, so /proc is assumed
 * to be mounted before calling this function. Else it
 * will not work correctly.
 *
 * @exception ERR_INVALID_VOLUME_TABLE_ENTRY
 * @exception ERR_VOLUME_NOT_FOUND
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) SYNOVOLINFOLIST *SYNOMountVolInfoEnum(int iGetOne, int volInfoOpt);

/**
 * Free all node in @p pVolList.
 *
 * @param[in] pVolList volume list, NULL is acceptable.
 *
 * @return void
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOMountVolInfoFree(SYNOVOLINFOLIST *pVolList);

/**
 * Get the specified volume information.
 *
 * @note it can be used in all models.
 *
 * @param[in]   szPath   any path start with "/"
 * @param[out]   pOutVol   volume information
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOMountVolInfoGet(const char *szPath, SYNOVOLInfo *pOutVol);

/**
 * Find volume info from @p pVolList according to the filter @p pFilter, and store the results in @p ppVolInfo.
 *
 * @param[in]     pVolList    The volume info list to search.
 * @param[in]     pFilter     The filter.
 * @param[out]    ppVolInfo   The result volume info.
 *
 * @retval 1 found
 * @retval 0 not found
 * @retval -1 error
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOMountVolInfoSearch(SYNOVOLINFOLIST *pVolList, const SYNOVOL_FILTER *pFilter, SYNOVOLInfo **ppVolInfo);

/**
 * Sort @p pBufList by volume ID
 *
 * @param[in] pBufList volume list
 *
 * @retval !NULL sorted list
 * @retval NULL  if @p pBufList is NULL
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) SYNOVOLINFOLIST *SYNOMountVolInfoSort(SYNOVOLINFOLIST *pBufList);

/**
 * Get the one avalible volume information.
 *
 * @param[in]   minBytes   minimum free space in bytes
 * @param[out]   pOutVol   volume information
 * @param[out]   status   error status
 * @param[in]   volInfoOpt   option to filter volumes, please refer to enum type VOLUME_INFO_OPTION defined in libsynocore/include/synoglobal.h
 *
 * @retval   1 - found one avalible volume
 * @retval   0 - not found one avalible volume
 * @retval   -1 - error
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int VolumeAvailGet(const unsigned long long minBytes, SYNOVOLInfo *pOutVol, int *pOutstatus, int volInfoOpt);

/**
 * Get legal volume location, return value must be greater than 0
 *
 * @return legal volume location, please refer to DEV_LOCATION.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOVolumeSupportLocGet(void);

/**
 * Check if given path is writable
 *
 * @param[in]   szPath   any path which is on a volume (include external devices)
 *
 * @retval   TRUE   Is Writable.
 * @retval   FALSE  Is not writable.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOVolumeIsWritable(const char *szPath);

/**
 * Check volume is used by glusterfs.
 *
 * For example: /volume1, /volumeX1
 *
 * @param[in]   szVolRefPath   volume path
 *
 * @retval   -1 error
 * @retval   0 not used by glusterfs.
 * @retval   1 used by glusterfs
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOVolumeIsUsedByGlusterFs(const char *szVolRefPath);

/**
 * Enum entries in /run/synostorage/volumetab, filter by pEnumFunc
 * /run/synostorage/volumetab includes internal, USB, eSATA volumes
 *
 * @param[out]   ppVolTabEntList   All entries in /run/synostorage/volumetab that matches pEnumFunc filter result
 * @param[in]   pEnumFunc   enum filter
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_VOLUME_TABLE_ENTRY
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBVolumeTableEnum(VOL_TAB_ENT **ppVolTabEntList, const PVOLTABENUMFUNC pEnumFunc);

/**
 * Free all node in @p pVolTabEntList.
 *
 * @param[in] pVolTabEntList volume entry list, NULL is acceptable
 *
 * @return void
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) void SLIBVolumeTableFree(VOL_TAB_ENT *pVolTabEntList);

/**
 * Check whether the volume obey the service policy. If violating policy, the volume can not run
 * any service on it.
 *
 * Service policy:
 * 1. must be internal or ebox volume.
 * 2. follow cross RAID rules.
 *
 * @param[in] pVol volume info. Only check first one.
 *
 * @retval TRUE  the volume follow service policy
 * @retval FALSE the volume does not follow service policy
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOVolumeServicePolicy(const SYNOVOLINFOLIST *pVol);

/**
 * Decide new volume.
 *
 * If service is already in one of volume. (According to smb.conf or link)
 * then return such volume path,
 * otherwise return first healthy volume path.
 *
 * @param[in]   szShareName   The share name.
 * @param[out]  szVolPath     The buffer to store the volume path.
 * @param[in]   cbVolPath     Number of bytes of @p szVolPath.
 *
 * @retval   1    volume found
 * @retval   0    no volume alive
 * @retval   -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOVolumeServiceVolumeDecide(const char *szShareName, char *szVolPath, int cbVolPath);

/**
 * @}
 */
