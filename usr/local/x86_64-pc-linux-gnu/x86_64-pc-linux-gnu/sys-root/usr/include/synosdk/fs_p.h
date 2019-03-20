/**
 * @addtogroup FS
 *
 * @{
 */

/**
 * Get the type of file system according to @p szPathName or @p cwd.
 *
 * @param[in]   szPathName  If szPathName == NULL, get FS of cwd.
 * @param[in]   cwd         If cwd == 0, skip the getcwd part.
 *
 * @retval   FSTYPE_ERR    On error.
 * @retval   Otherwise     Filesystem type of @p szPathName or @p cwd.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) FSTYPE SYNOGetFSType(const char *szPathName, int cwd);

/**
 * Get the available free size for non-root users in the given filesystem.
 *
 * @note Since the return type is unsigned long long, it will return @b ZERO when error occurs.
 *
 * @param[in]   szFsPath   The full path to the given filesystem.
 *
 * @retval   >0   The available number of bytes of the given filesystem.
 * @retval   0    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see statfs(2)
 */
SDK_STARTING_FROM(SDK_VER_4_0) uint64_t SLIBGetFsAvailSize(const char *szFsPath);

/**
 * This function is used to get selected share folder(s) size in the given filesystem.
 * It will get the expected total filesize instead of the actual filesize.
 *
 * Ex. A Bittorrent file has a filesize of 3G. However, its actual downloaded filesize
 * is 2M.  If we use 'du -h filename' [SLIBGetDirSize()], we get 2M which is correct.  However, when
 * we copy file to another volume, it's filesize should be 3G. This function will get
 * the total filesize, ie. 3G, for such calculation.
 *
 * @param[in]   szPath    Target share in full path
 *
 * @retval   >0   The total size in byte of the given ShareFolder(s)
 * @retval   0    Error
 *
 * @grantable No
 * @user Who can traverse @p szPath.
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) uint64_t SLIBGetFullDirSize(const char *szPath);

/**
 * Get selected share folder(s) size in the given filesystem.
 *
 * @param[in]   szFsPath   The full path to the given filesystem
 * @param[out]   ullDirSize   The total size in byte of the given ShareFolder(s)
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 * @user Who can traverse @p szFsPath.
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBGetDirSize(const char *szFsPath, uint64_t *ullDirSize);

/**
 * Enumerate mount paths of /proc/mounts.
 *
 * @param[in]   pFilter   enumerate filter, if NULL it means no limit
 * @param[out]   ppList   output path
 *
 * @retval   >0    Found counts.
 * @retval    0    Not found.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int FSPathEnum(const FS_FILTER *pFilter, PSLIBSZLIST *ppList);

/**
 * Get the file system mount path according to szPathName or
 * cwd.
 *
 * @param[in]   szPath   absolute path or relative path
 * @param[out]   szMntPath   mount path
 * @param[in]   cbMntPath   size of mount path
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSMntPathGet(const char *szPath, char *szMntPath, int cbMntPath);

/**
 * Creates target directory @p szPath and its prefix if
 * necessery.
 *
 * POSIX 1003.2: For each dir operand that does not name an
 * existing directory, effects equivalent to those caused by the
 * following command shall occcur:
 *
 * @code{.sh}
 * mkdir -p -m $(umask -S),u+wx $(dirname dir) && mkdir [-m mode] dir
 * @endcode
 *
 * We change the user's umask and then restore it, instead of
 * doing chmod's.
 *
 * @param[in]       szPath          The string that to be created.  Should not be NULL or empty string.
 * @param[out]      endptr          If there is a trailing '/' of @p szPath, points to it. Otherwise points to the '\0' of @p szPath.
 * @param[in]       blForceCreate   If TRUE, this function will remove the old path if it is not directory.
 * @param[in]       uid             If not UID_ERR, this function will force chown all the directory hierarchy.
 * @param[in]       gid             If not GID_ERR, this function will force chgrp all the directory hierarchy.
 * @param[in]       mode            If not -1, this fucntion will umask(0) to get @p mode will not be masked.
 *                                  If is -1, this function will not reset umask() and pass default mode (0777) to mkdir().
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_EXISTS             The @p blForceCreate is FALSE and the last component of @p szPath is existed and is not a directory.
 * @exception ERR_DIRECTORY_NOT_EXISTS    The @p blForceCreate is FALSE and the prefix component of @p szPath is existed and is not a directory.
 * @exception ERR_MKDIR_FAILED            Input path is valid, but failed to mkdir()
 *
 * @grantable No
 * @user Who can create files in @p szPath.
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSMkdirP(const char *szPath, char **endptr, BOOL blForceCreate, uid_t uid, gid_t gid, mode_t mode);

/**
 * Find out the device path.
 * ex. /volume1 may be /dev/md2
 *
 * @param[in]     szPath       Volume/device path, if it is device path, the function will copy to szDevice
 * @param[out]    szDevPath    Device path, shouldn't be null
 * @param[in]     pathLen      Number of bytes of @p szDevPath.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception  ERR_BAD_PARAMETERS
 * @exception  ERR_OP_FAILURE
 * @exception  ERR_OPEN_FAILED
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOVolPathToDevPath(const char *szPath, char *szDevPath, int pathLen);

/**
 * Check whether the @p fsType is an image fs such
 * as ISO9660 and UDF.
 *
 * @param[in]   fsType   query fs type
 *
 * @retval   TRUE  @p fsType is an image fs
 * @retval   FALSE @p szPath is NOT an image fs
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOFSIsImageFS(const FSTYPE fsType);

/**
 * Check whether the @p fsType is a remote fs.
 *
 * @param[in]   fsType   query fs type
 *
 * @retval   TRUE  @p fsType is a remote fs
 * @retval   FALSE @p szPath is NOT a remote fs
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOFSIsRemoteFS(const FSTYPE fsType);

/**
 * Check whether the @p szPath is a mount point, if yes, get
 * the FSTYPE of @p szPath.
 *
 * @param[in]   szPath   absolute path of a directory, should not be NULL.
 *
 * @retval FSTYPE_ERR     On error.
 * @retval FSTYPE_DEFAULT @p szPath is NOT a mount point.
 * @retval FSTYPE_UNKOWN  @p szPath is a mount point with unknown fs type, maybe 'fuseblk' or other fs type not defined in rgszFsType.
 * @retval Otherwise      @p szPath is a mount point, and the return value is the filesystem type of @p szPath.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) FSTYPE SYNOFSIsInMountTable(const char *szPath);

/**
 * Get the available free size for root in the given filesystem.
 *
 * @note Since the return type is unsigned long long, it will return @b ZERO when error occurs.
 *
 * @param[in]   szFsPath   The full path to the given filesystem.
 *
 * @retval   >0   The free number of bytes of the given filesystem.
 * @retval   0    On error.
 *
 * @see statfs(2)
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) uint64_t SLIBGetFsFreeSize(const char *szFsPath);

/**
 * Get the used size in the given filesystem.
 *
 * @note Since the return type is unsigned long long, it will return @b ZERO when error occurs.
 *
 * @param[in]   szFsPath   The full path to the given filesystem.
 *
 * @retval   >0   The total number of bytes of the given filesystem.
 * @retval   0    On error.
 *
 * @see statfs(2)
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) uint64_t SLIBGetFsUsedSize(const char *szFsPath);

/**
 * Parse /proc/mounts to see if some path mounted
 *
 * @param[in]   szPath   The path of the mount point
 *
 * @retval   1     mounted
 * @retval   0     not mounted
 * @retval   -1    error occurs
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOIBlPathMounted(const char *szPath);

/**
 * Get file system information by mount path list
 *
 * @param[in]    pMountPathList    Ex: /volume1, /volumeUSB1
 * @param[out]   rgpFSInfoResult   File system information pointer array.(length equal to pMountPathList)
 *
 * @retval   >0   FSInfoGet successfully and returns mounted volume count.
 * @retval   0    path is not mounted.
 * @retval   <0   error occured.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int FSInfoGetAll(PSLIBSZLIST pMountPathList, FS_INFO ***rgpFSInfoResult);

/**
 * Get file system information by mount path
 *
 * @param[in]   szMountPath   Ex: /volume1, /volumeUSB1
 * @param[out]   ppFSInfo   File system information
 *
 * @retval   1 path is mounted and succeed to get information.
 * @retval   0 path is not mounted.
 * @retval   -1 failed to get file system of mount path.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int FSInfoGet(const char *szMountPath, FS_INFO **ppFSInfo);

/**
 * Free file system information
 *
 * @param[out]   pFSInfo   File system information
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) void FSInfoFree(FS_INFO *pFSInfo);

/**
 * Get file system type from the device/mount path. It will query disk directly and wake up the disk.
 *
 * @param[in]   szPath   Target file system volume/device path, shouldn't be null.
 *
 * @retval   FSTYPE_ERR    On error.
 * @retval   Otherwise     Filesystem type of @p szPathName or @p cwd.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) FSTYPE SYNOFSTypeGetFromDisk(const char *szPath);

/**
 * It will return file system type id, if input file
 * system name is valid for our system.
 *
 * @param[in]   szFSString   Filesystem name.
 *
 * @retval   FSTYPE_ERR    On error.
 * @retval   Otherwise     Filesystem type of @p szPathName or @p cwd.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) FSTYPE SYNOFSGetFSIdByName(char *szFSString);

/**
 * Check if the filesystem type is in the skip File system list.
 *
 * @param[in]    fsType        Filesystem type.
 * @param[out]   iSkipFSType   Filesystem types to be skipped.
 *
 * @retval   1 needs to skip.
 * @retval   0 no need to skip.
 * @retval   -1 failed to get file system of mount path.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int FSIsMatchSkipFS(FSTYPE fsType, FSFILTERTYPE iSkipFSType);

/**
 * Check the target path has available size to store metadata.
 *
 * @param[in]   szPgsqlPath   The full path to pgsql folder, ie,
 *                         /volumeUSB1/usbshare/@pgsql.
 *
 * @retval   -1 szPgsqlPath is NULL or empty string.
 * @retval   0 Dont have available size.
 * @retval   1 Have available size.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSHasFreeSizeForMetaDataStore(const char *szPgsqlPath);

/**
 * It will return file system name, if input file
 * system name is valid for our system.
 *
 * @param[in]   fstype   file system type
 * @param[out]   szFSType   file system name
 * @param[in]   cbFSType   size of file system type
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSGetFSNameById(FSTYPE fstype, char *szFSType, int cbFSType);

/**
 * Check whether the @p szPath/cwd is a mount point or not.
 *
 * @param[in]   szPath   Absolute path or relative path of a directory, should not be NULL. If it is an empty string, use getcwd() instead.
 *
 * @retval   0     @p szPath is NOT a mount point
 * @retval   1     @p szPath is a mount point
 * @retval   -1    error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 * @exception ERR_SYS_UNKNOWN
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSDirIsMntPoint(const char *szPath);

/**
 * Check whether the @p szPath/cwd is a sub-directory of
 * a mount point. The mount points are folders under /volumeX.
 *
 * @param[in]   szPath   absolute path or relative path of a directory, should not be NULL
 *
 * @retval 0 @p szPath is NOT a sub-directory of a mount point
 * @retval 1 @p szPath is a sub-directory of a mount point
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSPathIsUnderMntPoint(const char *szPath);

/**
 * Check whether the @p szPath has mount points or not.
 * In other words, if itself or any subfolder of @p szPath is a mount
 * point, the return value will be 1.
 *
 * @param[in]   szPath   absolute path of a directory, should not be NULL.
 *
 * @retval   0 @p szPath has NO mount point
 * @retval   1 @p szPath has one or more mount points
 * @retval   -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_CANNOT_GET_MNTINFO
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSHasMountPoint(const char *szPath);

/**
 * Convert @szFsType to FSFILTERTYPE, ex: "iso9660" to FSFILTERTYPE_ISO.
 *
 * @param[in]   szFsType   The fs type name.
 *
 * @retval   FSFILTERTYPE_NONE   No matched type.
 * @retval   Otherwise           Matched filesystem type.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) FSFILTERTYPE SYNOFSType2fsFilter(const char *szFsType);

/**
 * Unmount the @p szPath if it is a iso/remote mount point.
 * If @p blUmountRecursive = TRUE, unmount all mount points
 * under @szPath whose fs type is specify in @p fsFilter.
 *
 * @param[in]   szPath   absolute path of a directory, should not be NULL.
 * @param[in]   fsFilter   file system types to be umount
 * @param[in]   blUmountRecursive   TRUE to umount all mount points under @szPath whose fs type is specify in @p fsFilter
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS ERR_OUT_OF_MEMORY
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSISORemoteUnmount(const char *szPath, FSFILTERTYPE fsFilter, BOOL blUmountRecursive);

/**
 * Check whether the @p szPath has mount points or not.
 * In other words, if itself or any subfolder of @p szPath is a mount
 * point, the return value will be 1.
 *
 * @param[in]   szPath    absolute path of a directory, should not be NULL.
 * @param[in]   fsTypes   The filesystem filter types.
 *
 * @retval 0 @p szPath has NO mount point
 * @retval 1 @p szPath has one or more mount points
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_CANNOT_GET_MNTINFO
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFSHasMountPointType(const char *szPath, FSFILTERTYPE fsTypes);

/**
 * get the ext4 UUID from ext4 superblock.
 * this function can get UUID without mount the volume.
 *
 * @param[in]   szFSPath   target file system volume/device path, shouldn't be null
 * @param[out]   szUuid   return the UUID
 * @param[in]   iUuid   buffer size of szUuid
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOFSGetExt4Uuid(const char *szFSPath, char *szUuid, int iUuid);

/**
 * Get the type of file system by fd.
 * See SYNOGetFSType for more details.
 *
 * @param[in]   fd   File descriptor
 *
 * @retval   FSTYPE_ERR    On error.
 * @retval   Otherwise     Filesystem type of @p szPathName or @p cwd.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) FSTYPE SYNOGetFSTypeByFd(int fd);

/**
 * Get uuid from uuid file in sharebin of szVolPath.
 *
 * @param[in]    szVolPath   Volume path.
 * @param[out]   szUuid      Buffer to store the uuid.
 * @param[in]    cbUuid      Number of bytes in @p szUuid.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOFSUuidGet(const char *szVolPath, char *szUuid, int cbUuid);

/**
 * It will auto detect fs type from @p szPath or @p fd and then call SYNOFSAclChmodWithFs.
 *
 * @param[in] szPath file path. if NULL means use fd instead
 * @param[in] fd     file descriptor. if -1 means use szPath instead
 * @param[in] mode   mode for chmod
 *
 * @retval  0 success
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor None.
 *
 * @see SYNOFSAclChmodWithFS
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOFSAclChmod(const char *szPath, int fd, mode_t mode);

/**
 * Skip chmod when file/dir supports ACL. If files in FAT or
 * NTFS file system, skip chmod and return success
 *
 * @param[in]   szPath   path, if NULL means use fd instead
 * @param[in]   fd       file descriptor, if -1 means use szPath instead
 * @param[in]   mode     mode for chmod
 * @param[in]   fsType   FSTYPE of szPath for skip FAT, NTFS, CIFS, ISO
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @user Who has read/write access on @p szPath.
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOFSAclChmodWithFS(const char *szPath, int fd, mode_t mode, FSTYPE fsType);

/**
 * Get the compressed file size. This function only supports btrfs.
 *
 * @param[in] szPath      file path
 * @param[in] ullFileSize file size in byte
 *
 * @retval  0 success
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_SUPPORT     fs type is not support
 * @exception ERR_OPEN_FAILED     open file path fail
 * @exception ERR_OP_FAILURE      error in getting size through ioctl
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOFSGetComprSize(const char *szPath, unsigned long long *ullFileSize);

/**
 * Get the btrfs filesystem UUID by ioctl
 *
 * @param[in]   szFSPath   target file system volume path, should not be null
 * @param[out]   szUuid   return the UUID
 * @param[in]   cbUuid   buffer size of szUuid
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception  ERR_BAD_PARAMETERS
 * @exception  ERR_STAT_FAILED
 * @exception  ERR_NOT_SUPPORT file ssytem type is not btrfs
 * @exception  ERR_OPEN_FAILED
 * @exception  ERR_OP_FAILURE io control command failed
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOFSGetBTRFSUuid(const char *szFSPath, char *szUuid, int cbUuid);

/**
 * Get the btrfs filesystem UUID from disk
 *
 * @param[in]   szFSPath   target file system volume path, should be mounted volume path
 *                         or dev path, e.g. /volume1 or /dev/vg1/volume_1
 * @param[out]   szUuid   return the UUID
 * @param[in]   cbUuid   buffer size of szUuid
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception  ERR_BAD_PARAMETERS
 * @exception  ERR_STAT_FAILED
 * @exception  ERR_NOT_SUPPORT file ssytem type is not btrfs
 * @exception  ERR_OPEN_FAILED
 * @exception  ERR_OP_FAILURE io control command failed
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOFSGetBTRFSUuidFromDisk(const char *szFSPath, char *szUuid, const size_t cbUuid);

/**
 * Get nodatacow flag of the file/folder
 *
 * @param[in]   szPath   file/folder path
 *
 * @retval    1    nodatacow is set.
 * @retval    0    nodatacow is not set
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBFSGetBTRFSNodatacow(const char *szPath);

/**
 * Get compression flag of the file/folder
 *
 * @param[in]   szPath   file/folder path
 *
 * @retval    1    compression is set.
 * @retval    0    compression is not set
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBFSGetBTRFSCompression(const char *szPath);

/**
 * @}
 */
