SDK_STARTING_FROM(SDK_VER_4_0) int Default_GenerateNewName(const char *szOldPath, char *szNewPath, int cbNewPath);

/**
 * Copys regular file @a szSrcFileName to @a szDstFileName by
 * ZEROCOPY methods and sets the extra file attributes, such as
 * Windows create time, dos mode attributes.
 * <p>
 * The underlying operation is implemented by SYNOFileCopyFd().
 *
 * @note SYNOCopyFileI, SYNOFileCopy, SYNOCopyDirectoryI,
 *       SYNOFileCopyDirectory should have the same return value
 *
 * @author ericlee
 * @version Revision: 1.31
 *
 * @param[in] szSrcFileName
 *               The source file path. Should not be NULL.
 * @param[in] szDstFileName
 *               The destination file path, cannot be a
 *               directory name. Should not be NULL.
 * @param[in] pArgs       The pointer to SYNOCOPYARGS. May be NULL.
 * @param[in] destFsType  The FSTYPE of @a szDstFileName. Call
 *               SYNOGetFSType() to get if -1.
 * @param blFileIndexNeed [IN] If file index is necessary.
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_IS_DIRECTORY overwrite but data type is not equal (destination path is directory)
 * @exception ERR_FAT_FILESIZE_TOO_LARGE copy over 4G file to FAT.
 * @exception ERR_FAT_FILENAME_ILLEGAL filename contains illeagle char in FAT.
 * @exception ERR_PATH_NOT_FOUND destination path not found
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_VOLUME_READ_ONLY file system is read-only
 * @exception ERR_NOT_ENOUGH_SPACE space or Quota not enough
 * @exception ERR_PATH_CONFLICT source and destination file are identical (same file name or hard link)
 * @exception ERR_PATH_CONFLICT doesn't specify overwrite or not (COPY_UNKNOWN), but destination exists.
 * @exception ERR_UNKNOWN undefined error or be canceled ,and caller should clean the destination file by itself.
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOCopyFileI(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYARGS pArgs, int destFsType, BOOL blFileIndexNeed);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyFileExI(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYARGS pArgs, int srcFsType, int destFsType, BOOL blFileIndexNeed, const SYNOCOPYARGSEX *pArgsEx);

/**
 * Copys regular file @a szSrcFileName to @a szDstFileName by
 * ZEROCOPY methods and sets the extra file attributes, such as
 * Windows create time, dos mode attributes.
 * <p>
 * The underlying operation is implemented by SYNOFileCopyI().
 *
 * Note: SYNOCopyFileI, SYNOFileCopy, SYNOCopyDirectoryI,
 *       SYNOFileCopyDirectory should have the same return value
 *
 * @author  ericlee
 * @version Revision: 1.31
 *
 * @param[in] szSrcFileName  The source file path. Should not be NULL.
 * @param[in] szDstFileName  The destination file path, cannot be a
 *                           directory name. Should not be NULL.
 * @param[in] pArgs          The pointer to SYNOCOPYARGS. May be NULL.
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_USER_CANCEL be canceled
 * @exception ERR_UNKNOWN undefined error, and caller should clean the destination file by itself.
 *
 * @see SYNOFileCopyI()
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFileCopy(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYARGS pArgs);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOFileCopyEx(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYARGS pArgs, const SYNOCOPYARGSEX *pArgsEx);

/**
 * Just like SYNOFileCopy() but it is thread safe
 *
 * @param[in] szSrcFileName  The source file path. Should not be NULL.
 * @param[in] szDstFileName  The destination file path, cannot be a
 *                           directory name. Should not be NULL.
 * @param[in] pArgs          The pointer to SYNOCOPYARGS. May be NULL.
 *
 * @retval  0                                success
 * @retval -1                                error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_CHOWN_FAILED copy success but failed to chown
 * @exception ERR_USER_CANCEL be canceled
 * @exception ERR_UNKNOWN undefined error, and caller should clean the destination file by itself.
 *
 * @see SYNOFileCopyI()
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOFileCopy_r(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYTHRARGS pArgs, const SYNOCOPYTHRCALLBACK *pCallbackArgs);

/**
 * Enable copy doing control clone/CoW copies globally.
 *
 * @param[in] blEnableReflink  The BOOL flage to enable/disable reflink copy option.
 *
 * @retval  0                                success
 * @retval -1                                error
 *
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_ACCESS_DENIED error privilege
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOFileCopyReflinkEnable(BOOL blEnableReflink);

/**
 * Check synoinf.conf that copy doing control clone/CoW copies is enabled.
 *
 * @retval  TRUE     clone/CoW enable
 * @retval  FALSE    clone/CoW disable
 *
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_6_1) BOOL SYNOFileCopyReflinkIsEnabled(void);

/**
 * File copy doing control clone/CoW copies.
 *
 * @param[in] szSrcFileName  The source file path. Should not be NULL.
 * @param[in] szDstFileName  The destination file path, cannot be a
 *                           directory name. Should not be NULL.
 * @param[in] pArgs          The pointer to SYNOCOPYARGS. May be NULL.
 *
 * @retval  0                                success
 * @retval -1                                error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_CHOWN_FAILED copy success but failed to chown
 * @exception ERR_USER_CANCEL be canceled
 * @exception ERR_UNKNOWN undefined error, and caller should clean the destination file by itself.
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOFileReflinkCopy(const char *szSrcFileName, const char *szDstFileName, const PSYNOCOPYARGS pArgs, const SYNOCOPYARGSEX *pArgsEx);

/**
 * Copys regular file @a szSrcFileName to @a szDstFileName by
 * ZEROCOPY methods and sets the extra file attributes, such as
 * Windows create time, dos mode attributes.
 * <p>
 * The underlying operation is implemented by SYNOFileCopyFd().
 *
 * Note: SYNOCopyFileI, SYNOFileCopy, SYNOCopyDirectoryI,
 *       SYNOFileCopyDirectory should have the same return value
 *
 * @author  ericlee
 * @version Revision: 1.39
 *
 * @param[in] szSrcDirName      The source dir path.
 * @param[in] szDstDirName      The destination dir path, cannot
 *                              be a file name.
 * @param[in] pArgs             The pointer to SYNOCOPYARGS.  May be NULL.
 * @param[in] srcFsType         The FSTYPE of @a szSrcDirName. Call
 *                              SYNOGetFSType() to get if -1.
 * @param[in] destFsType        The FSTYPE of @a szDstDirName. Call
 *                              SYNOGetFSType() to get if -1.
 * @param[in] blFileIndexNeed   According to it, decide whether
 *                              it is necessary to do file index
 *
 * @retval  0  success
 * @retval -1  generic error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FILE_NOT_FOUND src not found.
 * @exception ERR_PATH_NOT_FOUND destination path not found
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_UNKNOWN undefined error or be canceled ,and caller should clean the destination file by itself.
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOCopyDirectoryI(const char *szSrcDirName, const char *szDstDirName, const PSYNOCOPYARGS pArgs, int srcFsType, int destFsType, BOOL blFileIndexNeed);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyDirectoryExI(const char *szSrcDirName, const char *szDstDirName, const PSYNOCOPYARGS pArgs, int srcFsType, int destFsType, BOOL blFileIndexNeed, const SYNOCOPYARGSEX *pArgsEx);

/**
 * Copys regular file @a szSrcFileName to @a szDstFileName by
 * ZEROCOPY methods and sets the extra file attributes, such as
 * Windows create time, dos mode attributes.
 * <p>
 * The underlying operation is implemented by SYNOFileCopyFd().
 *
 * @note SYNOCopyFileI, SYNOFileCopy, SYNOCopyDirectoryI,
 *       SYNOFileCopyDirectory should have the same return value
 *
 * @author  ericlee
 * @version Revision: 1.39
 *
 * @param[in] szSrcDirName      The source dir path.
 * @param[in] szDstDirName      The destination dir path, cannot
 *                              be a file name.
 * @param[in] pArgs             The pointer to SYNOCOPYARGS. May be NULL.
 *
 * @retval  0  success
 * @retval -1  generic error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_PATH_NOT_FOUND destination path not found
 * @exception ERR_ACCESS_DENIED error privilege
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFileCopyDirectory(const char *szSrcDirName, const char *szDstDirName, const PSYNOCOPYARGS pArgs);
int SYNOFileReflinkCopyDirectory(const char *szSrcDirName, const char *szDstDirName, const PSYNOCOPYARGS pArgs);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOFileCopyDirectoryEx(const char *szSrcDirName, const char *szDstDirName, const PSYNOCOPYARGS pArgs, const SYNOCOPYARGSEX *pArgsEx);

/**
 * This function accepts two descriptors to regular files, and
 * copy entire file contains from @a fdSrc to @a fdDst by
 * ZEROCOPY methods. This function also has two call back
 * functions, @a pfuncSetProgress and @a pfuncIsCancel. If @a
 * pfuncSetProgress is not NULL, the progress of copy file will
 * be updated every @a RECVFILE_BUFFER bytes is written.  If @a
 * pfuncIsCancel is not NULL, the operation of copy file will be
 * cancelled when @a pfuncIsCancel returns TRUE.
 *
 * @param[in] fdSrc             The file descriptor that associated to
 *                              source file.
 * @param[in] fdDst             The file descriptor that associated to
 *                              destination file.
 * @param[in] filesize          The file size, in bytes.
 * @param[in] pfuncSetProgress  The call back function that
 *                              updates copy progress.
 * @param[in] pfuncIsCancel     The call back function that checks
 *                              this operation should be terminated
 *                              before it finished.
 *
 * @retval  0  success
 * @retval -1  unknown error and caller should clean the
 *             destination file by itself.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_PATH_NOT_FOUND destination path not found
 * @exception ERR_ACCESS_DENIED error privilege
 * @exception ERR_NOT_ENOUGH_SPACE space or Quota not enough
 * @exception ERR_UNKNOWN undefined error
 * @exception ERR_USER_CANCEL
 * @exception ERR_COPY_FAILED The size of write does not equal
 *                            to the size of read.
 * @author claudiac
 * @version Revision: 1.11
 *
 * @todo Should I try to lock and test that src descriptor is
 *       valid?
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOCopyFileFd(const int fdSrc, const int fdDst, off_t filesize, PFUNC_Prog pfuncSetProgress, PFUNC_Test pfuncIsCancel);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyFileFdEx(const int fdSrc, const int fdDst, off_t filesize, PFUNC_Prog pfuncSetProgress, PFUNC_Test pfuncIsCancel, const SYNOCOPYARGSEX * pArgsEx);
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOWriteFileFd(const int fdDst, const char *pCopyBuf, ssize_t cbRead);

/**
 * Opens file @a szFileName in read/write mode as @a open_flags,
 * return the file descriptor if this file is a regular file.
 *
 * @param[in] szFileName    The filename to be open(2)
 * @param[in] open_flags    The access modes, ie, O_RDONLY,
 *                          O_WRONLY, or O_RDWR.
 * @param[in] open_mode     The permissions to use in case a new
 *                          file is created, ie, 0666 or 0644.
 * @param[in] pStbuf        The pointer to stat buffer. Should not be
 *                          NULL.
 *
 * @author claudiac
 * @version Revision: 1.6
 *
 * @retval  >=0  success and this is a valid file descriptor.
 * @retval   -1  open file fail or this file is not a regular file.
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOCopyOpenAndCheckIsRegular(const char *szFileName, const int open_flags, const int open_mode, struct stat * pSt, SYNOSTAT * pSynoSt);

/**
 * Change the basename of path to FAT-allowable filename.
 *
 * @param[in]   szPath
 * @param[out]  szFATPath
 * @param[in]   sizeFATPath
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @author claudiac
 * @version Revision: 1.5
 * @todo Change to Module String or FS?
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOStrReplaceFATReservedChar(const char *szPath, char *szFATPath, int sizeFATPath);

/**
 * Copy or move the source path to the specified external volume.
 * eg. /volumeUSB1/usbshare
 * Will create and move to the @tmp folder first before copying or moving
 * the source folder.
 *
 * @param[in] szOldDirPath
 * @param[in] szNewDirPath
 * @param[in] blCopy
 * @param[in] pArgs
 *
 * @retval   0  On success.
 * @retval  -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_PATH_NOT_FOUND
 * @exception ERR_VOLUME_NOT_FOUND
 * @exception ERR_VOLUME_READ_ONLY
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_COPY_FAILED,
 *            Failed to copy data or set destination folder.
 *
 * @grantable N
 *
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOCopyDirToExternal(char *szOldDirPath, char *szNewDirPath, BOOL blCopy, const PSYNOCOPYARGS pArgs);

/**
 * Allocate extra arguments to copy/move file(s).
 *
 * @retval  != NULL: On success.
 * @retval  NULL: error
 */
SDK_STARTING_FROM(SDK_VER_5_1) SYNOCOPYARGSEX * SYNOCopyArgsExAlloc(void);

/**
 * Free extra arguments to copy/move file(s)
 *
 * @param[in] pArgs  SYNOCOPYARGSEX
 */
SDK_STARTING_FROM(SDK_VER_5_1) void SYNOCopyArgsExFree(SYNOCOPYARGSEX * pArgs);

/**
 * Set PFUNC_ReadSize function pointer of extra arguments to copy a file
 *
 * @param[in] pArgs              SYNOCOPYARGSEX
 * @param[in] pfuncGetReadSize   PFUNC_GetReadSize
 *
 * @retval  0  on success
 * @retval -1  error
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyArgsExSetGetReadSize(SYNOCOPYARGSEX * pArgs, const PFUNC_GetReadSize pfuncGetReadSize);

/**
 * Set PFUNC_ReadWriteData function pointer of extra arguments to copy a file
 *
 * @param[in] pArgs              SYNOCOPYARGSEX
 * @param[in] pfuncGetReadSize   PFUNC_GetReadSize
 *
 * @retval  0  on success
 * @retval -1  error
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyArgsExSetReadWriteData(SYNOCOPYARGSEX * pArgs, const PFUNC_ReadWriteData pfuncReadWriteData);

/**
 * Set PFUNC_CopyFile function pointer of extra arguments to copy a file
 *
 * @param[in] pArgs          SYNOCOPYARGSEX
 * @param[in] pfuncCopyFile  PFUNC_CopyFile
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyArgsExSetCopyFile(SYNOCOPYARGSEX * pArgs, const PFUNC_CopyFile pfuncCopyFile);

/**
 * Set PFUNC_CopyEA function pointer of extra arguments to copy a file
 *
 * @param[in] pArgs    SYNOCOPYARGSEX
 * @param[in] pfuncEA  PFUNC_CopyEA
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyArgsExSetCopyEA(SYNOCOPYARGSEX * pArgs, const PFUNC_CopyEA pfuncEA);

/**
 * Set PFUNC_GetDirSize function pointer of extra arguments to copy a file
 *
 * @param[in] pArgs             SYNOCOPYARGSEX
 * @param[in] pfuncGetDirSize   PFUNC_GetDirSize
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOCopyArgsExSetGetDirSize(SYNOCOPYARGSEX * pArgs, const PFUNC_GetDirSize pfuncGetDirSize);

/**
 * Set PFUNC_GetDirSize function pointer of extra arguments to copy a file
 *
 * @param[in] szPath  Remove directory path
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBCopyRemoveDir(char *szPath);

/**
 * Clean and Create tmp directory.
 *
 * @param[in] szTmpDirPath      The path of the tmp directory
 * @param[in] blReserved        Whether the data in @a szTmpDirPath should be kept
 * @param[in] mode              The mode of the newly created directory
 *
 * @retval  0  On success.
 * @retval -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_REMOVE_FAILED
 * @exception ERR_NOT_ENOUGH_SPACE
 * @exception ERR_MKDIR_FAILED
 *
 * @author claudiac
 * @version Revision: 1.8
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBCopyCreateTmpDir(const char *szTmpDirPath, BOOL blReserved, mode_t mode);

/**
 * Allocate extra arguments to copy/move file(s).
 *
 * @retval  != NULL: On success.
 * @retval  NULL: error
 */
SDK_STARTING_FROM(SDK_VER_6_1) SYNOCOPYTHRCALLBACK *SYNOCopyTHRArgsAlloc(void);

/**
 * Free extra arguments to copy/move file(s)
 * Notice: the function would not free internal data ex: pSetProgressData, pErrReportData ...
 *
 * @param[in] pArgs SYNOCOPYTHRCALLBACK
 */
SDK_STARTING_FROM(SDK_VER_6_1) void SYNOCopyTHRArgsFree(SYNOCOPYTHRCALLBACK *pCallbackArgs);

/**
 * Set PFUNC_THR_Prog function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncSetProgress  callback function
 * @param[in] pSetProgressData  callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackSetProgress(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_Prog pfuncSetProgress, void *pSetProgressData);

/**
 * Set PFUNC_THR_ErrReport function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncErrReport    callback function
 * @param[in] pErrReportData    callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackErrReport(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_ErrReport pfuncErrReport, void *pErrReportData);

/**
 * Set PFUNC_THR_Test function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncIsCancel     callback function
 * @param[in] pIsCancelData     callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackIsCancel(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_Test pfuncIsCancel, void *pIsCancelData);

/**
 * Set PFUNC_THR_Rename function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncRename       callback function
 * @param[in] pRenameData       callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackRename(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_Rename pfuncRename, void *pRenameData);

/**
 * Set PFUNC_THR_GetReadSize function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncGetReadSize  callback function
 * @param[in] pGetReadSizeData  callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackGetReadSize(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_GetReadSize pfuncGetReadSize, void *pGetReadSizeData);

/**
 * Set PFUNC_THR_ReadWriteData function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs      SYNOCOPYTHRCALLBACK
 * @param[in] pfuncReadWriteData  callback function
 * @param[in] pReadWriteData      callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackReadWriteData(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_ReadWriteData pfuncReadWriteData, void *pReadWriteData);

/**
 * Set PFUNC_THR_CopyFile function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncCopyFile     callback function
 * @param[in] pCopyFileData     callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackCopyFile(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_CopyFile pfuncCopyFile, void *pCopyFileData);

/**
 * Set PFUNC_THR_CopyEA function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncCopyEA       callback function
 * @param[in] pCopyEAData       callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackCopyEA(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_CopyEA pfuncCopyEA, void *pCopyEAData);

/**
 * Set PFUNC_THR_GetDirSize function pointer of callback arguments to copy a file
 *
 * @param[in] pCallbackArgs    SYNOCOPYTHRCALLBACK
 * @param[in] pfuncGetDirSize   callback function
 * @param[in] pGetDirSizeData   callback function argument
 *
 * @retval   0  on success
 * @retval  -1  error
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOCopyTHRSetCallbackGetDirSize(SYNOCOPYTHRCALLBACK *pCallbackArgs, PFUNC_THR_GetDirSize pfuncGetDirSize, void *pGetDirSizeData);
