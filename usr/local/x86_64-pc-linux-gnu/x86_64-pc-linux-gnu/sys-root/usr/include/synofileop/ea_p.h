#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/**
 * SYNOEACopy Procedure:
 * 1. Detect the fs type. FAT/NTFS use appledouble v2 file.
 * 2. If both src and dest are in non-FAT fs, then try to do
 *      2.1 Upgrade the SZ_RESOURCE_FORK in SYNO_EA_DIR
 *      2.2 Copy the SZ_EASTREAM
 *      2.3 Copy the MY_ABC_HERE folder in SYNO_EA_DIR
 * 3. Remove the src file if blRemoveSrc is specified.
 * If blForceCopySYNOEA is set, then SYNO_EA_DIR will be copied to destination (even to external device).
 *
 * @param[in] szSrcPath           The path of source file
 * @param[in] szDstPath           The path of destination file
 * @param[in] blRemoveSrc         Specify whether to remove the source file or not
 * @param[in] blForceCopySYNOEA   Copy MY_ABC_HERE to destination
 * @param[in] srcFsType           The filesystem of source. -1 means to autodetect the filesystem through @szSrcPath.
 *                            If @szSrcPath is not absolute, it would try to getcwd to statfs.
 * @param[in] dstFsType           The filesystem of destination. -1 means to autodetect the filesystem through @szDstPath.
 *                            If @szDstPath is not absolute, it would try to getcwd to statfs.
 * @param[in] blFileIndexNeeded   If file index is necessary
 * @param[in] blMediaIndexNeeded  If media index is necessary
 *
 * @retval    0  succeed
 * @retval   -1  errors
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEACopy(const char *szSrcPath, const char *szDstPath, BOOL blRemoveSrc, BOOL blForceCopySYNOEA, int srcFsType, int dstFsType, BOOL blFileIndexNeeded, BOOL blMediaInexNeeded);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOEACopyEx(const char *szSrcPath, const char *szDstPath, BOOL blRemoveSrc, BOOL blForceCopySYNOEA, int srcFsType, int dstFsType, BOOL blFileIndexNeeded, BOOL blMediaInexNeeded, PFUNC_CopyEA pfunCopyEA);

/**
 * Get EA directory path against specified file.
 * (the directory to put all EAs of 'file1')
 * For example, /volume2/share3/dir/file1
 * => /volume2/share3/dir/SYNO_EA_DIR/file or
 * => /volume2/share3/dir/SYNO_EA_DIR
 *
 * @param[in]  DirType      The type of EA
 * @param[in]  szPathName   The path of which we want to get the EA dirpath
 * @param[out] szEAName     A Buffer to store result
 * @param[in]  cbEAName     The buffer size
 *
 * @retval   0   succeed
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception  ERR_NAME_TOO_LONG
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      char szFilePath[] = "/volume1/share/test.txt"
 *      char szEADirPath[4096] = {0};
 *
 *      if (0 > SYNOEADirPath(EATYPE_EASTREAM, szFilePath, szEADirPath, sizeof(szEADirPath))) {
 *          perror("SYNOEADirPath Error");
 *          exit(1);
 *      }
 *      printf("SYNOEADirPath: %s\n",szEADirPath);
 *      return 0;
 * }
 * @endcode
 *
 * Output:
 * @code
 * SYNOEADirPath: /volume1/share/@eaDir
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEADirPath(const EATYPE DirType, const char *szPathName, char *szEAName, int cbEAName);

/**
 * Prepare the destination path ready for EA.
 * To be compatible with SYNOACL,
 * this function would chmod to SYNO_EAPATH_CHMOD after mkdir succeed.
 * Hence it should be used only for system meta folder, not for data folder.
 *
 * Eg: mkdir SYNO_EA_DIR/filename, SYNO_EA_DIR
 *
 * @param[in] bMkParent
 *            0: just mkdir with szEADirPath
 *            1: try to mkdir the parent folder of szEADirPath (only try 1 level up)
 * @param[in] szEADirPath
 *            The path of EA folder we want to check
 *
 * @retval   0  success
 * @retval  -1  fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 * @exception ERR_MKDIR_FAILED
 *
 * @grandchild N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAMKDir(int bMkParent, const char *szEADirPath);

/**
 * !!! DEPRECATED !!!!
 * Add / Add Recusively / Delete / Delete Dir / Rename files or folders through
 * /usr/syno/bin/synoindex
 * *To speed up, fork grandchild to do index jobs
 *
 * @param[in] szFile    The source file (if rename, it is new path)
 * @param[in] szFile2   The old path(only be used with rename)
 * @param[in] Mode      Specify which operation
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOIndex(const char *szFile, const char *szFile2, int Mode);

/**
 * Use @szPathName and @szStreamName to open a EA file and return the FD
 *
 * Note: shareType: SYNO_SHARE -> Not ._ type (FAT/NTFS)
 *                  AD_SHARE -> ._ type (FAT/NTFS)
 *
 * @param[in] EATYPE        Specify which EA we want. EATYPE_SYNOEA or EATYPE_EASTREAM
 * @param[in] szPathName    The path of which we want to open the EA for
 * @param[in] szStreamName  The stream name we want to open. Ex: SYNO:Resource, SYNO:PhotoXXX
 * @param[in] fOpen         The open flag
 * @param[in] isADFS        The ADFS flag
 *
 * @retval  >=0  success, the opened fd
 * @retval   -1  error
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      int eaFd = -1;
 *      char szFilePath[] = "/volume1/share/test.txt"
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePath,
 *               SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Error");
 *          exit(1);
 *      }
 *      if (0 <= eaFd) {
 *          close(eaFd);
 *      }
 *      return 0;
 * }
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOEAOpen(const EATYPE DirType, const char *szPathName, const char *szStreamName, int fOpen, EA_AD_SHARE shareType);

/**
 * Based on shareType to compose ea path.
 * Get a EA or EAStream Path, EX: share1/@eaDir/file1/thumbnail,
 * or EA on FAT/NTFS, EX: usbshare/._file1
 *
 * Note: shareType: SYNO_SHARE -> Not ._ type (FAT/NTFS)
 *                  AD_SHARE -> ._ type (FAT/NTFS)
 *
 * @param[in]  DirType
 * @param[in]  szFileName
 * @param[in]  szStreamName
 * @param[out] szEAName
 * @param[in]  cbEAName
 * @param[in]  shareType
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NAME_TOO_LONG
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <string.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      char szFileADPath[] = "/usbvolume/share/test.txt";
 *      char szFileSYNOPath[] = "/volume1/share/test.txt";
 *      char szEAPath[4096] = {0}
 *      if (0 > SYNOEAPath(EATYPE_EASTREAM, szFileADPath, SZ_EASTREAM,
 *                         szEAPath, sizeof(szEAPath), AD_SHARE)) {
 *          perror("SYNOEAPath Error");
 *          exit(1);
 *      }
 *      printf("AD EAPath: %s\n", szEAPath);
 *      bzero(szEAPath, sizeof(szEAPath));
 *      if (0 > SYNOEAPath(EATYPE_EASTREAM, szFileSYNOPath, SZ_EASTREAM,
 *                         szEAPath, sizeof(szEAPath), SYNO_SHARE)) {
 *          perror(""SYNOEAPath Error);
 *          exit(1);
 *      }
 *      printf("SYNO EAPath: %s\n",szEAPath);
 *      return 0;
 * }
 * @endcode
 *
 * Output:
 * @code
 * AD EAPath: AD EAPath: /usbvolume/share/._test.txt
 * SYNO EAPath: SYNO EAPath: /volume1/share/@eaDir/test.txt@SynoEAStream
 * @endcode
*/
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOEAPath(const EATYPE DirType, const char *szFileName, const char *szStreamName, char *szEAName, int cbEAName, EA_AD_SHARE shareType);

/**
 * This function should be called with Caution.
 * It is like the SYNOEARemove(), except that it won't remove SZ_EASTREAM.
 *
 * @param[in] szPathName
 *            The Unix path that need to map resource fork.
 * @param[in] fsType
 *            The filesystem type of dst. -1 means auto-detect it.
 *
 * @retval   0  The SYNOEARemove() returns the value 0 if successful
 * @retval  -1  fail; The global variable errno is set to indicate the error.
 *
 * @grantable N
 *
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_BAD_PARAMETERS
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEARemoveWithoutEAStream(const char *szPathName, int fsType);

/**
 * check dst file system type
 * if it's FAT, goto FAT style ea functions.
 *
 * !! CAUTION !!
 * When @fsType == -1, the @szPathName should be the absolute path.
 * Otherwise, it would try to getcwd to statfs and remove ea.
 * !! CAUTION !!
 *
 * @param[in] szPathName The Unix path that need to map resource fork.
 * @param[in] fsType The filesystem type of dst. -1 means auto-detect it.
 *
 * @retval   0  success
 * @retval  -1  fail; errno is set to indeicate th error.
 *
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEARemove(const char *szPathName, int fsType, SYNO_INDEX_ENABLE *pstIndexEnable);
SDK_STARTING_FROM(SDK_VER_4_0) int EARemove(const EATYPE DirType, const char *szPathName);

/**
 * Remove SYNO_EA_DIR dir if it's empty
 * *SZ_PHOTO_COVER_FILENAME will be ignored.
 * !!! the input szEADir should include SYNO_EA_DIR
 * as "/volume1/share1/@eaDir/file1"
 *
 * @ingroup EA_int
 */
SDK_STARTING_FROM(SDK_VER_4_0) int EARemoveEADir(const char *szEADir);

/**
 * check dst file system type
 * if it's FAT, goto FAT style ea functions.
 *
 * !! CAUTION !!
 * When @fsType == -1, the @szNewPath should be the absolute path.
 * Otherwise, it would try to getcwd to statfs and rename ea.
 * !! CAUTION !!
 *
 * @param[in] szOldPath The Unix path that need to map resource fork before rename.
 * @param[in] szNewPath The Unix path that need to map resource fork after rename.
 * @param[in] fsType The dst file system type. fsType=-1: autodetect fstype by szNewPath
 *
 * @retval   0  success
 * @retval  -1  fail; global variable errno is set to indicate the error.
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEARename(const char *szOldPath, const char *szNewPath, int fsType, SYNO_INDEX_ENABLE *pstIndexEnable);

/**
 * Set the archive bit for samba
 *
 * @param[in] szPathName  The UNIX path of file
 *
 * @retval   0  success
 * @retval  -1  fail; errno is set appropriately
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int EASetSmbArchive(const char *szPathName);

/**
 * Used to determine whether szStreamName is SYNO hidden
 * name(should not expose for transmit) or not.
 *
 * @param[in] szStreamName  The name of stream's file name,
 *            ex:/volume1/public/a/@eaDir/b/SYNO:Resource
 *
 * @retval  1  szStreamName is hidden name -> return TRUE(1)
 * @retval  0  szStreamName is not hidden name -> return FALSE(0)
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAIsHiddenName(const char *szStreamName);

/**
 * Get a EA path - @szPathEA of @szPath in FAT/NTFS filesystem.
 * It generates a path with ._ prefix.
 *
 * @param szPath        The path of target
 * @param szPathEA      A Buffer to store result
 * @param cbPathEA      The buffer size
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_NAME_TOO_LONG
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAADPath(const char *szPath, char *szPathEA, int cbPathEA);

/**
 * Get a List containing the names of grgszHiddenDir.
 *
 * Note: "Hidden" is the same as "Veto" in directory.
 *
 * @param[in] pList a pointer to the PSLIBSZLIST
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAHiddenDirGet(PSLIBSZLIST *ppList);

/**
 * Used to determine whether szDirName is SYNO hidden dir
 * name(should not expose) or not.
 *
 * Note: If szDirName[0] != '@', do a fast return since all hidden dir are started with '@'
 *
 * Note: "Hidden" is the same as "Veto" in directory.
 *
 * @param[in] szDirName  The name of dir,
 *                       ex: @eaDir
 *                       ex: not_a_eaDir
 *                       ex: /volume1/public/a/@eaDir
 *
 * @retval  1  is hidden dir -> return TRUE(1)
 * @retval  0  is not hidden dir -> return FALSE(0)
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAIsHiddenDir(const char *szDirName);

/**
 * Used to determine whether szDirName is SYNO hidden dir. ( Only for dir name, not path.)
 * name(should not expose) or not.
 *
 * Note: "Hidden" is the same as "Veto" in directory.
 *
 * @param[in] szDirName  The name of dir,
 *                       ex: @eaDir
 *                       ex: not_a_eaDir
 *
 * @retval  1  is hidden dir -> return TRUE(1)
 * @retval  0  is not hidden dir -> return FALSE(0)
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAIsHiddenDirName(const char *szDirName);

/**
 * Upgrade the EA @szStreamName file of @szPath
 *
 * 1. Check whether the new EA in SYNO_EA_DIR exist.
 * returned if the new EA found.
 *
 * 2. Check whether the old EA in SYNO_EA_DIR exist.
 * Upgrade it to new path if found the old one.
 *
 * 3. If target is a SZ_RESOURCE_FORK, this function will also try to sync 2 attributes of afp and smb:
 *      a) afp:lock file <-> smb:readonly
 *      b) afp:invisible <-> smb:hidden
 *
 * @param[in] szPath    The target file
 * @param[in] szStreamName  The EA file name. SZ_RESOURCE_FORK or SZ_EASTREAM
 *
 * @retval  0 = UP_SUCCESS: success
 * @retval  EA_UPGRADE_STATUS: UP_NEW_EXIST, UP_OLD_NO_EXIST
 * @retval  UP_ERR: some errors occur during the upgrading process.
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEAUpgrade(const char *szPath, const char *szStreamName);

/**
 * The function is used to allocate <code>AttrEntries</code> for
 * stream handle <code>pEAStream</code>
 *
 * @param[out] pEAStream    Pointer to stream handle
 * @param[in]  iEntryNum    The number of entries needed to be allocated
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASAllocEntry(SYNO_EASTREAM *pEAStream, size_t iEntryNum);

/**
 * The function is used to write the header info to <code>SZ_EASTREAM</code>
 *
 * @param[in] pEAStream  The pointer to stream handle
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SEEK_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASWriteHeader(SYNO_EASTREAM *pEAStream);

/**
 * The function is used to update stream header for certain stream name and
 * read data from SZ_EASTREAM. The function would move such entry in the handle
 * to the lasti of the list. This function also resolves the movement of entry
 * and data.
 *
 * @param pEAStream   [in/out]  The pointer to stream handle
 * @param iEntryIndex [in]      The iEntryIndex of <code>AttrEntries</code>, by
 *                              calling <code>SYNOEASSearch</code>
 * @param pData       [out]     The data buffer for return
 * @param iDataLen    [in]      The buffer length
 * @param blRemove    [in]      The flag to indicate if removing such stream
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_READ_FAILED
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASUpdateEntry(SYNO_EASTREAM *pEAStream, uint16_t iEntryIndex, char *pData, uint32_t iDataLen, int blRemove);

/**
 * The function is used to open stream handle, which is for
 * accessing <code>SZ_EASTREAM</code>.
 *
 * @param[in] fd         The file descriptor of <code>SZ_EASTREAM</code>
 * @param[in] iLockType  The lock type: F_RDLCK/F_WRLCK
 *
 * @retval   NULL: error
 * @retval   otherwise: success
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      int eaFd = -1;
 *      SYNO_EASTREAM *pEAStream = NULL;
 *      char szFilePath[] = "/volume1/share/test.txt"
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream first
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePath,
 *                                 SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Error");
 *          exit(1);
 *      }
 *      // Get SYNO_EASTREAM struct
 *      if (NULL == (pEAStream = SYNOEASOpen(eaFd, F_RDLCK))) {
 *          perror("SYNOEASOpen Error");
 *          exit(1);
 *      }
 *      // Do something ...
 *      // Close(Free) SYNO_EASTREAM stuct
 *      if (pEAStream) {
 *          SYNOEASClose(pEAStream);
 *          pEAStream = NULL;
 *      }
 *      // Close eaFd
 *      if (0 <= eaFd) {
 *          close(eaFd);
 *      }
 *      return 0;
 * }
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_0) SYNO_EASTREAM *SYNOEASOpen(int fd, int iLockType);

/**
 * Get number of attr entry from fd.
 *
 * @author jaypan (2013/5/27)
 *
 * @param[in] fd   The file descriptor from ._file or SynoEAStream
 *
 * @retval  otherwise   success
 * @retval  -1          error
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      int numOfEAEntry = 0;
 *      int eaFd = -1;
 *      char szFilePath[] = "/volume1/share/test.txt";
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream first
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePath,
 *                                 SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Error");
 *          exit(1);
 *      }
 *      if (0 > (numOfEAEntry = SYNOEASGetEntry(eaFd))) {
 *          perror("SYNOEASGetEntry Error");
 *          exit(1);
 *      }
 *      printf("Number of EAStream Entry: %d\n", numOfEAEntry);
 *      return 0;
 * }
 * @endcode
 *
 * Output Example:
 *
 * @code
 * Number of EAStream Entry: 3
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_3) __attribute__((visibility("hidden"))) int SYNOEASGetEntry(int fd);

/**
 * The function is used to close stream handle <code>pEAStream</code>
 * of file <code>SZ_EASTREAM</code>
 *
 * @param[in] pEAStream   Pointer to stream handle
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASClose(SYNO_EASTREAM *pEAStream);

/**
 * The function is used to search an ea entry by stream name
 *
 * @param[in] pEAStream  The pointer to stream handle
 * @param[in] szEASName  The stream name
 *
 * @retval   >=0  success, return the array index
 * @retval    -1   error, include szEASName not found (ERR_KEY_NOT_FOUND)
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * int main(int argc, char *argv[]) {
 *      int eaFd = -1;
 *      int attrEntryIdx = -1;
 *      char szFilePath[] = "/volume1/share/test.txt"
 *      SYNO_EASTREAM pEAStream = NULL;
 *      char szAttrEntryName = "com.apple.meta:_kMDItemUserTags";
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePaht,
 *                                 SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Error");
 *          exit(1);
 *      }
 *      // Open(alloc) SYNO_EASTREAM struct
 *      if (NULL == (pEAStream = SYNOEASOpen(eaFd, F_RDLCK))) {
 *          perror("SYNOEASOpen Error");
 *          exit(1);
 *      }
 *      // Search Attr Index
 *      if (0 > (attrEntryIdx = SYNOEASSearch(pEAStream, szAttrEntryName))) {
 *          perror("SYNOEASearch Error");
 *          exit(1);
 *      }
 *      printf("Entry Index: %d\n",attrEntryIdx);
 *      // Free Resource
 *      if (0 <= eaFd) {
 *          close(eaFd);
 *      }
 *      if (pEAStream) {
 *          SYNOEASClose(pEAStream);
 *      }
 * }
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASSearch(const SYNO_EASTREAM *pEAStream, const char *szEASName);

/**
 * The function is used to enumerate all EA stream names and
 * store them in a list <code>pList</code>
 *
 * @param[in] pEAStream   The pointer to a stream handle
 * @param[out] ppList     The pointer to list for EA stream names
 *
 * @retval   >=0  number of streams
 * @retval    -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <synofileop/ea.h>
 *
 * #define BUFFER_SIZE 4096
 *
 * int main(int argc, char *argv[]) }{
 *      char szFilePath[] = "/volume1/share/test.txt";
 *      char *pEASName = NULL
 *      int numOfEA = 0;
 *      int eaFd = -1;
 *      int i = 0;
 *      SYNO_EASTREAM pEAStream = NULL;
 *      PSLIBSZLIST pList = NULL;
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePath,
 *                                 SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Failed");
 *          exit(1);
 *      }
 *      // Open(alloc) SYNO_EASTREAM struct
 *      if (NULL == (pEAStream = SYNOEASOpen(eaFd, F_RDLCK))) {
 *          perror("SYNOEASOpen Failed");
 *          exit(1);
 *      }
 *      // Get EASName List
 *      if (0 > (numOfEA = SYNOEASEnum(pEAStream, &pList))) {
 *          perror("SYNOEASEnum Error");
 *          exit(1);
 *      }
 *      for (i=0;i<numOfEA;i++) {
 *          if (NULL == (pEASName = SLIBCSzListGet(pList, i))) {
 *              perror("SLIBCSzListGet Error");
 *               exit(1);
 *          }
 *          printf("EASName: %s\n",pEASName);
 *      }
 *      if (0 <= eaFd) {
 *          close(eaFd);
 *      }
 *      if (pEAStream) {
 *          SYNOEASClose(pEAStream)
 *      }
 *      return 0;
 * }
 * @endcode
 *
 * Output Example:
 * @code
 * EASName: com.apple.meta:_kMDItemUserTags
 * EASname: com.apple.TextEncode
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASEnum(const SYNO_EASTREAM *pEAStream, PSLIBSZLIST *ppList);

/**
 * The function is used to read strem from <code>SZ_EASTREAM</code>
 *
 * @param[in]  pEAStrem   The pointer to stream handle
 * @param[in]  szEASName  The stream name
 * @param[out] Buf        The buffer for stream
 * @param[in]  iBufSize   The buffer size
 *
 * @retval  >=0  Bytes read
 * @retval   -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_SEEK_FAILED
 * @exception ERR_READ_FAILED
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable N
 *
 * @code{.c}
 * #include <stdio.h>
 * #include <string.h>
 * #include <synofileop/ea.h>
 *
 * #define BUF_LEN 4096
 *
 * int main(int argc, char *argv[]) {
 *      int eaFd = -1;
 *      int i = 0;
 *      SYNO_EASTREAM pEAStream = NULL;
 *      char szFilePath[] = "/volume1/share/test.txt";
 *      char szEASValueBuf[BUF_LEN] = {0};
 *      attr_entry_t *pAttr = NULL;
 *
 *      // Open /volume1/share/@eaDir/test.txt@SynoEAStream
 *      if (0 > (eaFd = SYNOEAOpen(EATYPE_EASTREAM, szFilePath,
 *                                 SZ_EASTREAM, O_RDONLY, SYNO_SHARE))) {
 *          perror("SYNOEAOpen Error");
 *          exit(1);
 *      }
 *      // Open(alloc) SYNO_EASTREAM struct
 *      if (NULL == (pEAStream = SYNOEASOpen(eaFd, F_RDLCK))) {
 *          perror("SYNOEASOpen Error");
 *          exit(1);
 *      }
 *      // Using SYNOEASRead (Not Good for Traverse Entry. (O(n^2)))
 *      bzero(szEASValueBuf, sizeof(szEASValueBuf));
 *      for (i=0;i<pEAStream->AttrHeader.num_attrs;i++) {
 *          pAttr = &pEAStream->AttrEntries[i];
 *          if (0 > SYNOEASRead(pEAStream, pAttr->name, szEASValueBuf, sizeof(szEASValueBuf), 0)) {
 *              perror("SYNOEASRead Error");
 *              exit(1);
 *          }
 *          printf("===== EAName =====\n");
 *          printf("%s\n", pAttr->name);
 *          printf("===== EAValue =====\n");
 *          printf("%s\n",szEASValueBuf);
 *          bzero(szEASValueBuf, sizeof(szEASValueBuf));
 *      }
 *      if (pEAStream) {
 *          SYNOEASClose(pEAStream);
 *      }
 *      if (0 <= eaFd) {
 *          close(eaFd);
 *      }
 *      retrun 0;
 * }
 * @endcode
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASRead(SYNO_EASTREAM *pEAStream, const char *szEASName, char *Buf, size_t iBufSize, size_t offSet);

/**
 * The function is used to write EA stream to <code>SZ_EASTREAM</code>
 *
 * Note: Could write a empty attribute. e.g. cbBufSize=0
 *
 * @param[int/out] pEAStream   The pointer to stream handle
 * @param[in]      szEASName   The stream name
 * @param[in]      Buf         The data buffer for write
 * @param[in]      cbBufsize   The size of buffer
 * @param[in]      Off         The position to write
 * @param[in]      iMode       0:
 *                             Don't overwrite when stream exists,
 *                             write when stream NOT exist
 *                             1(EAS_OVERWRITE):
 *                             Overwrite when stream exists,
 *                             write when stream NOT exist
 *                             2(EAS_NO_CREAT):
 *                             Don't overwrite when stream exists,
 *                             don't write when stream NOT exists
 *                             3(EAS_NO_CREAT|EAS_OVERWRITE):
 *                             Overwrite when stream exists,
 *                             don't write when stream NOT exists
 *
 * @retval  >=0  Bytes writted
 * @retval   -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_SEEK_FAILED
 * @exception ERR_READ_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASWrite(SYNO_EASTREAM *pEAStream, const char *szEASName, const char *Buf, uint32_t cbBufSize, uint32_t Off, int iMode);

/**
 * The function is used to remove EA streams
 *
 * @param[in]  pEAStream   The pointer to stream handle
 * @param[out] szEASName   The stream name
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASRemove(SYNO_EASTREAM *pEAStream, const char *szEASName);

/**
 * The function is used to truncate EA stream
 *
 * @param[in/out] pEAStream   The pointer to stream handle
 * @param[in]     szEASName   The stream name
 * @param[in]     iLen        The length for truncation
 *
 * @retval    0   success
 * @retval   -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_SEEK_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_OP_FAILURE
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASTruncate(SYNO_EASTREAM *pEAStream, const char *szEASName, uint32_t iLen);

/**
 * The function is used to flush stream handle <code>pEAStream</code>
 *
 * @param[in] pEAStream   The pointer to stream handle
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASFlush(SYNO_EASTREAM *pEAStream);

/**
 * The function is used to get lock of file <code>SZ_EASTREAM</code>
 *
 * @param[in] pEAStream  The pointer to stream handle
 * @param[in] lock       The pointer to lock struct
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASLockGet(SYNO_EASTREAM *pEAStream, struct flock *lock);

/**
 * The function is used to set file lock of <code>SZ_EASTREAM</code>
 *
 * @param[in/out] pEAStream   The pointer to stream handle
 * @param[in]     iLockType   The lock type going to be set
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_LOCK_FAILED
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEASLockSet(SYNO_EASTREAM *pEAStream, int iLockType);

/**
 * Check input file is a AppleDouble format file by
 *  1. Prefix (._)
 *  2. Magic number (00051617)
 *  3. Has master file
 *
 * @author jamie (2010/11/9)
 *
 * @param[in] szFileName   The path of EA file
 *
 * @retval AD_SUCCESS
 * @retval otherwise
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOEACheckADFile(const char *szFilePath);

/**
 * To check if dir "dirname" is only remain ".", "..", and "eaDir"
 * In this case, rmdir function will be failed because dir "dirname"
 * is not empty.
 *
 * So the main objective is to remove this kind of dangling "eaDir"
 *
 * @param[in]  szDirname
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_1) void SYNOEARemoveDanglingEADir(const char *szDirname);

/**
 * Determine whether @a szFileName is SYNO hidden
 * file name (should not be enumed in file browser) or not.
 *
 * @param[in] szFileName  The file name,
 *                        ex: @eaDir, .DS_Store
 *
 * @retval  TRUE    szFileName is hidden file name
 * @retval  FALSE   szFileName is not hidden file name
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOEAIsHiddenFile(const char *szFileName);

/**
 * Determine whether @a szFileName is SYNO veto
 * file name (should not be enumed in file browser) or not.
 *
 * @param[in] szFileName   The file name,
 *                         ex: @eaDir, ., ..
 *
 * @retval   TRUE   szFileName is veto file name
 * @retval   FALSE  szFileName is not veto file name
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNOEAIsVetoFile(const char *szFileName);

/**
 * List native suported EA by listxattr()
 *
 * @param[in]  szPath   The path of target file
 * @param[out] ppList   The list of EA name returned
 *                      (should be allocated first)
 *
 * @retval  0  succeed
 * @retval -1  errors, check errno
 *
 * @exception  ERR_BAD_PARAMETERS
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOEAXattrEnum(const char *path, PSLIBSZLIST *ppList);

/**
 * Get filesystem native suported EA by syscall
 *
 * @param[in]  szPath       The path of target file
 * @param[in]  szName       The name of target EA
 * @param[out] szValue      The buffer to store EA content
 * @param[in]  cbValue      The size of buffer
 *
 * @retval  >0  succeed, returned value size
 * @retval  -1  errors, check errno
 *
 * @exception  ERR_BAD_PARAMETERS
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOEAXattrGet(const char *szPath, const char *szName, void *szValue, int cbValue);

/**
 * Set filesystem native suported EA by syscall
 *
 * @param[in] szPath    The path of target file
 * @param[in] szName    The name of target EA
 * @param[in] cbValue   The size of buffer
 * @param[in] iFlags    [in] flags to specify force create or replace
 *                      SYNO_XATTR_CREATE:  force create a non-existing EA
 *                                          fail if attr already exists
 *                      SYNO_XATTR_REPLACE: force replace an existing EA
 *                                          fail if attr doesn't exist
 *
 * @retval  0  succeed
 * @retval -1  errors, check errno
 *
 * @exception  ERR_BAD_PARAMETERS
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOEAXattrSet(const char *szPath, const char *szName, const void *szValue, int cbValue, int iFlags);

/**
 * Remove filesystem native suported EA by syscall
 *
 * @param[in] szPath    The path of target file
 * @param[in] szName    The name of target EA
 *
 * @retval   0  succeed
 * @retval  -1  errors, check errno
 *
 * @exception  ERR_BAD_PARAMETERS
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOEAXattrRemove(const char *szPath, const char *szName);

/**
 * Get the finder info entry index from attribute header structure.
 *  1. Go through all entry
 *  2. Get the finder info entry index
 *
 * @author jaypan (2013/5/23)
 *
 * @param[in] pAttrHeader    The pointer to attribute header structure.
 *
 * @retval  otherwise   success
 * @retval  -1          error
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_3) __attribute__((visibility("hidden"))) int SYNOEASGetFinderInfoIndex(attr_header_t* pAttrHeader);

/**
 * Get the resource fork offset and length from pEAStream structure.
 *  1. Get finder info index
 *  2. Compose resource fork by adding finder info offset and finder info length.
 *  3. Get resource fork offset.
 *
 * @author jaypan (2013/5/23)
 *
 * @param[in]  pEAStream   The pointer to stream handle
 * @param[out] puiRFOff    The pointer to store resource fork offset
 * @param[out] puiRFLen    The pointer to store resource fork length
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_3) __attribute__((visibility("hidden"))) int SYNOEASGetRForkEntry(SYNO_EASTREAM *pEAStream, uint32_t *puiRFOff, uint32_t *puiRFLen);

/**
 * Move resource fork from old offset to new offset in ea file.
 *  1. If new offset is greater than old offset, resize the ea file.
 *  2. Move the resource fork in file.
 *
 * @author jaypan (2013/5/23)
 *
 * @param[in] pEAStream     The pointer to stream handle
 * @param[in] uiRFNewOff    New resource fork offset
 * @param[in] uiRFOldOff    Old resource fork offset
 * @param[in] uiRFLen       Resource fork length
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_3) __attribute__((visibility("hidden"))) int SYNOEASMoveRFork(SYNO_EASTREAM *pEAStream, uint32_t uiRFNewOff, uint32_t uiRFOldOff, uint32_t uiRFLen);

/**
 * Write the ea attribute from source to destination via file descriptor.
 *  1. Open the EAStream structure
 *  2. Get each ea attribute from source
 *  3. Write each ea attribute to destination
 *
 * @author jaypan (2013/5/23)
 *
 * @param[in] fdSrc     Source file descriptor
 * @param[in] fdDst     Destination file descriptor
 *
 * @retval   0  success
 * @retval  -1  error
 * @retval <-1  error while writing
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_3) __attribute__((visibility("hidden"))) int SYNOEASWriteToFD(int fdSrc, int fdDst);

/**
 * Copy and transfer the EA file from src to dest based on the tType.
 * EACopyAdouble() opens src EA file, and reads ad_header.
 * If the src EA files is ADouble v1, is not supported ;
 * else if the src EA files is ADouble v2, call
 * EACopyAdoubleV2() to do conversion.
 *
 * @param[in] szEAFrom    The path of source EA file.
 * @param[in] szEATo      The path of dest EA file.
 * @param[in] tType       The transfer type.
 *                          1. EA_13_ENTRY_TO_2_ENTRY      convert from ext2/3 to FAT/NTFS
 *                          2. EA_2_ENTRY_TO_13_ENTRY      convert from FAT/NTFS to ext2/3
 *                          3. EA_13_ENTRY_TO_13_ENTRY     convert from ext2/3 to ext2/3
 *                          4. EA_2_ENTRY_TO_2_ENTRY       convert from FAT/NTFS to FAT/NTFS
 *
 * @retval  0         succeed
 * @retval  otherwise fail
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_5_0) __attribute__((visibility("hidden"))) int EACopyAdouble(const char *szEAFrom, const char *szEATo, int tType);
SDK_STARTING_FROM(SDK_VER_5_1) __attribute__((visibility("hidden"))) int SYNOEAFileEAFSFInfoFileSync(const char* szTargetPath);

/**
 * The function is used to sync finder info in SynoResource to xattr,
 * The sync behavior only sync is in FileEA file system.
 * If not, ignore it and return success.
 *
 * @param[in] szTargetPath      file path
 * @param[in] blNeedCheckFS     Is need check file system type
 *                              File systemS should be EXT4.
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OP_FAILURE
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOEAFileEAFSFinfoEASync(const char* szTargetPath, BOOL blNeedCheckFS);
/**
 * The function is used to write finder info to @eaDir.
 *
 * @param[in] szTargetPath      file path
 * @param[in] pFinderInfo       finder info attr
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_SEEK_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOEAEADirFSFInfoWrite(const char* szTargetPath, char* pFinderInfo);

/**
 * The function is used to flush file time.
 *
 * @param[in] szTargetFile      file path
 * @param[in] blNeedCheckFS     Is need check file system type
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOEAFileEAWriteFlushTime(const char* szTargetFile, BOOL blNeedCheckFS);

/**
 * The function is used to set file lock of copy file.
 *
 * @param[in] szSrcPath         source file path
 * @param[in] szDstPath         destination file path
 * @param[in] inSrcFsType       source file system type
 * @param[in] inDstFsType       destination file system type
 *
 * @retval  0  success
 * @retval -1  error
 * @retval  1  lock
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_5_1) __attribute__((visibility("hidden"))) int SYNOEACopyLock(const char *szSrcPath, const char *szDstPath, const int inSrcFsType, const int inDstFsType);
