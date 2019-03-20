__BEGIN_DECLS;

/**
 * Translate units between B, KB, MB, GB, TB.
 *
 * @param[in]    iType    From which unit to which unit.
 * @param[in]    fNum     The number to be translated.
 *
 * @return   The translated number.
 */
float SYNOUnitTrans(UNIT_TRANS iType, float fNum);

/**
 * Check QUOTA support from default synoinfo.
 *
 * @retval TRUE   Supports.
 * @retval FALSE  Doesn't support.
 */
BOOL SYNOSupportQUOTA(void);

/**
 * Get quota data (hard block limit) for single user.
 *
 * @param[in]    szName     User name.
 * @param[in]    szDevPath  Device path to get quota.
 * @param[out]   pQuota     The quota info.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @apparmor  None.
 */
int SYNOQuotaGet(const char *szName, const char *szDevPath, PSYNOQUOTA pQuota);

/**
 * Get quota data (hard block limit) for user by uid.
 *
 * @param[in]   uid         The user uid.
 * @param[in]   szDevPath   The device path.
 * @param[in]   pQuota      The address of quota data.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_QUOTA_NOT_FOUND
 * @exception ERR_SYS_UNKNOWN
 */
int SYNOQuotaGetByUID(uid_t uid, const char *szDevPath, PSYNOQUOTA pQuota);

/**
 * Get the quota limit of share.
 *
 * @param[in]   pShare           Share, should not be NULL.
 * @param[out]  ullQuotaInMB     Share quota in MB.
 *
 * @retval 0  on suceess.
 * @retval -1 on error.
 *
 * @apparmor abstractions/libsynoquota
 */
int SYNOQuotaShareQuotaGet(const PSYNOSHARE pShare, SYNOQUOTA *synoQuota);

/**
 * Set share quota limit.
 *
 * @param[in]  pShare           Share, should not be NULL.
 * @param[in]  ullQuotaInMB     Share quota in MB.
 *
 * @retval   0    on suceess.
 * @retval   -1   on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 * @exception ERR_NOT_SUPPORT
 */
int SYNOQuotaShareQuotaSet(const PSYNOSHARE pShare, unsigned long long ullQuotaInMB);

/**
 * Get the quota limit of share.
 *
 * @param[in]   pShare              Share, should not be NULL.
 * @param[out]  synoQuota           Share user quota and used capacity.
 *
 * @retval 0  on suceess.
 * @retval -1 on error.
 *
 * @apparmor abstractions/libsynoquota
 */
int SYNOQuotaShareUserQuotaGet(const PSYNOSHARE pShare, const char *szUserName, SYNOQUOTA *synoQuota);

/**
 * Get the quota limit of share for user by uid.
 *
 * Normal share:
 *   SYNOQuotaShareUserQuotaGetByUID("/volume1/share", 1024, &quota);
 * Encryption share:
 *   SYNOQuotaShareUserQuotaGetByUID("/volume1/@encrypt_share@", 1024, &quota);
 *
 * @param[in]   szEntityPath        Share entity path, should not be NULL, and caller must guarantee it's BTRFS filesystem share entity path.
 * @param[in]   uid                 The user uid.
 * @param[out]  synoQuota           Share user quota and used capacity.
 *
 * @retval 0  on suceess.
 * @retval -1 on error.
 *
 * @apparmor abstractions/libsynoquota
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOQuotaShareUserQuotaGetByUID(const char *szEntityPath, uid_t uid, SYNOQUOTA *synoQuota);

/**
 * Get all the user quota limit of @pShare.
 *
 * @param[in]   pShare           Share, should not be NULL.
 * @param[out]  ppUserQuota      An array, each element contains uid, share user quota and used capacity, caller has to free it.
 * @param[out]  nItem            The total number of elements in array @p ppUserQuota.
 *
 * @retval 0  on suceess.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 *
 */
int SYNOQuotaShareUserQuotaGetByShare(const PSYNOSHARE pShare, PSYNOUSERQUOTA *ppUserQuota, int *nItem);

/**
 * Set multiple user quota limit.
 * This function sets the records in array @p pUserQuota as many as possible.
 * The failed records will be skipped. If any record fails, -1 will be returned.
 *
 * @param[in]  pShare           Share, should not be NULL.
 * @param[in]  pUserQuota       An array, each element is a record to be set.
 * @param[in]  nItem            The total number of elements in @p pUserQuota.
 *
 * @retval 0 on suceess.
 * @retval -1 on any error happened.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 */
int SYNOQuotaShareUserQuotaSetByShare(const PSYNOSHARE pShare, PSYNOUSERQUOTA pUserQuota, int nItem);

/**
 * Refresh effective quota for give UID on all volumes/shares.
 *
 * @param[in] uid  UID to refresh.
 *
 * @return None.
 */
void SYNOQuotaUsrQuotaRefresh(const uid_t uid);

/**
 * Remove quota DB. Used when changes to volume that doesn't support share user quota.
 *
 * @param[in] pShare  Share handle, must not be NULL.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaRemove(const PSYNOSHARE pShare);

/**
 * Get the quota limit of share.
 *
 * @param[in]   pShare           Share, should not be NULL.
 * @param[out]  ullQuotaInMB     Share quota in MB.
 *
 * @retval 0 on suceess.
 * @retval -1 on error.
 *
 */
int SYNOQuotaShareQuotaReservedGet(const PSYNOSHARE pShare);

/**
 * Get the quota limit of share.
 *
 * @param[in]   pShare           Share, should not be NULL.
 *
 * @retval 0 on suceess.
 * @retval -1 on error.
 */
int SYNOQuotaShareUserQuotaReservedGet(const PSYNOSHARE pShare, const char *szUserName);

/**
 * Check if user has enough quota on the volume of the given path.
 * External devices are skipped.
 *
 * @important If you modify this function, you must also modify libsynosdk_cs/4.3/user/user_quota_is_enough.c
 *
 * @param[in]  uid        User id.
 * @param[in]  szPath     Any path which is on a volume, need to exist.
 * @param[in]  size       Size to be compared with user's remaining quota.
 *
 * @retval TRUE  Enough.
 * @retval FALSE Not enough.
 *
 * @apparmor None.
 */
BOOL SYNOQuotaIsEnough(uid_t uid, const char *szPath, off64_t size);

/**
 * Get the quota limit of BTRFS path.
 *
 * @param[in]   szPath              path, should not be NULL
 * @param[out]  synoQuota           share user quota and used capacity.
 *
 * @retval 0 on suceess.
 * @retval -1 on error.
 */
int SYNOQuotaSubvolumeQuotaGet(const char *szPath, SYNOQUOTA *synoQuota);

/**
 * Get path of "user space" quota DB from given @p szPath.
 *
 * @param[in]   szPath    Path on some volume, must not be NULL.
 * @param[out]  szDbPath  Result DB path, must not be NULL.
 * @param[in]   cbDbPath  Size of @p szDbPath, must >0.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception SYNOMountVolInfoGet()
 * @exception SYNOShareNamePathGet()
 * @exception SYNOShareGet()
 */
int SYNOQuotaDbPathGet(const char *szPath, char *szDbPath, size_t cbDbPath);

/**
 * Sync effective quota for pShare according to corresponding DB.
 * Ignore errors when flush / refresh.
 *
 * @note May take a long time to do so.
 *
 * @param[in]  pShare   Share handle, must not be NULL.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 */
int SYNOQuotaShareQuotaSync(const PSYNOSHARE pShare);

__END_DECLS;

#ifdef __cplusplus

#include <list>
#include <map>

typedef std::map<uid_t, unsigned long long> UserQuotaMap;
typedef std::map<gid_t, unsigned long long> GroupQuotaMap;

/**
 * Get details of user quota with given target share and UID.
 * Includes used capacity and constraint implied by belonging groups.
 *
 * @param[in]    pShare  Target share to get quota.
 * @param[in]    uid     UID to get quota.
 * @param[out]   detail  Result quota handle.
 * @param[out]   grpMB   Quota of belonging groups, NULL if don't need it.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaGet(const PSYNOSHARE pShare, const uid_t uid, SYNOQUOTA &quota, unsigned long long *grpMB = NULL);

/**
 * Get details of user quota with given target volume and UID.
 * Includes used capacity and constraint implied by belonging groups.
 *
 * @param[in]    pVolInfo  Target volume to get quota.
 * @param[in]    uid       UID to get quota.
 * @param[out]   detail    Result quota handle.
 * @param[out]   grpMB     Quota of belonging groups, NULL if don't need it.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaGet(const PSYNOVOLInfo pVolInfo, const uid_t uid, SYNOQUOTA &quota, unsigned long long *grpMB = NULL);

/**
 * Get group quota from DB with given target share and GID.
 *
 * @param[in]   pShare   Target share to get quota.
 * @param[in]   gid      GID to get quota.
 * @param[out]  quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaGet(const PSYNOSHARE pShare, const gid_t gid, unsigned long long &quotaMB);

/**
 * Get group quota from DB with given target volume and GID.
 *
 * @param[in]   pVolInfo Target volume to get quota.
 * @param[in]   gid      GID to get quota.
 * @param[out]  quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaGet(const PSYNOVOLInfo pVolInfo, const gid_t gid, unsigned long long &quotaMB);

/**
 * Get group quota constraint from DB with given target share and list of GID.
 *
 * @param[in]   pShare     Target share to get quota.
 * @param[in]   gids       List of GID to get quota.
 * @param[out]  quotaMB    Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaGet(const PSYNOSHARE pShare, const std::list<gid_t> &gids, unsigned long long &quotaMB);

/**
 * Get group quota constraint from DB with given target volume and list of GID.
 *
 * @param[in]   pVolInfo   Target volume to get quota.
 * @param[in]   gids       List of GID to get quota.
 * @param[out]  quotaMB    Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaGet(const PSYNOVOLInfo pVolInfo, const std::list<gid_t> &gids, unsigned long long &quotaMB);

/**
 * Set user quota with given target share and UID.
 *
 * @param[in]   pShare   Target share to set quota.
 * @param[in]   uid      UID to set quota.
 * @param[in]   quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaSet(const PSYNOSHARE pShare, const uid_t uid, const unsigned long long quotaMB);

/**
 * Set user quota with given target volume and UID.
 *
 * @param[in]   pVolInfo Target volume to set quota.
 * @param[in]   uid      UID to set quota.
 * @param[in]   quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaSet(const PSYNOVOLInfo pVolInfo, const uid_t uid, const unsigned long long quotaMB);

/**
 * Set group quota with given target share and GID.
 *
 * @param[in]  pShare   Target share to set quota.
 * @param[in]  gid      GID to set quota.
 * @param[in]  quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaSet(const PSYNOSHARE pShare, const gid_t gid, const unsigned long long quotaMB);

/**
 * Set group quota with given target volume and GID.
 *
 * @param[in]  pVolInfo Target volume to set quota.
 * @param[in]  gid      GID to set quota.
 * @param[in]  quotaMB  Quota in MB.
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaSet(const PSYNOVOLInfo pVolInfo, const gid_t gid, const unsigned long long quotaMB);

/**
 * Enum user quota with given target share.
 * The quota size is in MB.
 *
 * @param[in]  pShare         Target share to enum quota.
 * @param[out] userQuotaMap   The map of (uid -> quota).
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaEnum(const PSYNOSHARE pShare, UserQuotaMap &userQuotaMap);

/**
 * Enum user quota with given target volume.
 * The quota size is in MB.
 *
 * @param[in]  pVolInfo       Target volume to enum quota.
 * @param[out] userQuotaMap   The map of (uid -> quota).
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaUsrQuotaEnum(const PSYNOVOLInfo pVolInfo, UserQuotaMap &userQuotaMap);

/**
 * Enum group quota with given target share.
 * The quota size is in MB.
 *
 * @param[in]  pShare         Target share to enum quota.
 * @param[out] groupQuotaMap  The map of (gid -> quota).
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaEnum(const PSYNOSHARE pShare, GroupQuotaMap &groupQuotaMap);

/**
 * Enum user quota with given target volume.
 * The quota size is in MB.
 *
 * @param[in]  pVolInfo       Target volume to enum quota.
 * @param[out] groupQuotaMap  The map of (gid -> quota).
 *
 * @retval 0  On success.
 * @retval -1 On error.
 */
int SYNOQuotaGrpQuotaEnum(const PSYNOVOLInfo pVolInfo, GroupQuotaMap &groupQuotaMap);

#endif  // __cplusplus
