/**
 * A chmod wrapper function
 *
 * @param[in] szPath             File or directory path
 * @param[in] blAdminOnly        Restrict access to admin only
 *
 * @grantable N
 *
 * @retval  0  On success
 * @retval -1  On error.
 *
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_OP_FAILURE
 */
int SYNORecycleACLChmodBin(const char *szPath, BOOL blAdminOnly);

/**
 * Create share level recycle folder
 *
 * @param[in] szShare             Share Name
 * @param[in] blCaselessPath      Indicate stat is caseless
 * @param[in] blAdminOnly         Restrict access to admin only
 * @param[in] blDomain            Is Domain
 * @param[in] blLdap              Is LDAP
 *
 * @grantable N
 *
 * @retval  0  On success.
 * @retval -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_MKDIR_FAILED
 * @exception ERR_OP_FAILURE
 * @exception ERR_OPEN_FAILED
 */
int SYNORecycleMkdirBinShare(const char *szShare, BOOL blCaselessPath, BOOL blAdminOnly, BOOL blDomain, BOOL blLdap);

/**
 * If @a szPath is a file, the file will be unlink directly.
 * If @a szPath is a symbolic link, the link will not be followed and the link will be unlink directly.
 * If @a szPath is a directory, all content inside will be removed recursively.
 *
 * @param[in] szPath          The path to remove. Should not be NULL.
 * @param[in] blCaselessPath  Indicate if we have to perform caseless search.
 *
 * @grantable N
 *
 * @retval   0  On success.
 * @retval  -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 * @exception ERR_REMOVE_FAILED
 */
int SYNORecycleUnlinkDirectly(const char *szPath, BOOL blCaselessPath);

/**
 * Call SYNORecycleUnlinkFileWithSharePath() without considering recycle bin is enabled or not.
 *
 * @param[in] szShareName      The share name. Should not be NULL. ex: 'music', 'photo'
 * @param[in] szRelativePath   The relative path of file to share folder. Should not be NULL.
 * @param[in] blCaselessPath   Indicate if we have to perform caseless search.
 *
 * @retval   0   On success.
 * @retval  -1 On error.
 *
 * @grantable N
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_PATHNAME
 * @exception ERR_STAT_FAILED
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_RENAME_FAILED
 */
int SYNORecycleUnlinkFileWithSharePathEx(const char *szShareName, const char *szRelativePath, BOOL blCaselessPath);

/**
 * Remove file into recycle bin. The caller should specify @a szSharePath, otherwise we cannot
 * distinguish between "personal home" share and "homes" share when seeing /volumeX/homes/admin/abc.txt.
 * The function will not check if the recycle bin was enabled or not, the caller should
 * check it before calling.
 *
 * @param[in] szSharePath      The share path. Should not be NULL.
 * @param[in] szRelativePath   The relative path of file or directory to share folder. Should not be NULL.
 * @param[in] blCaselessPath   Indicate if we have to perform caseless search.
 * @param[in] blAdminOnly      Restrict to admin only
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @grantable Y
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_PATHNAME
 * @exception ERR_STAT_FAILED
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_RENAME_FAILED
 */
int SYNORecycleUnlinkFileWithSharePath(const char *szSharePath, const char *szRelativePath, BOOL blCaselessPath, BOOL blAdminOnly);

/**
 * Remove director into recycle bin. The caller should specify @a szSharePath, otherwise we cannot
 * distinguish between "personal home" share and "homes" share when seeing /volumeX/homes/admin/abc/.
 * The function will not check if the recycle bin was enabled or not, the caller should
 * check it before calling.
 *
 * @param[in] szSharePath     The share path. Should not be NULL.
 * @param[in] szRelativePath  The relative path of file or directory to share folder. Should not be NULL.
 * @param[in] blCaselessPath  Indicate if we have to perform caseless search.
 * @param[in] blAdminOnly     Restrict to admin
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @grantable Y
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INVALID_PATHNAME
 * @exception ERR_STAT_FAILED
 * @exception ERR_OPEN_FAILED
 * @exception ERR_REMOVE_FAILED
 */
int SYNORecycleRmDirWithSharePath(const char *szSharePath, const char *szRelativePath, BOOL blCaselessPath, BOOL blAdminOnly);
int SYNORecycleRmDirWithSharePathEx(const char *szSharePath, const char *szRelativePath, BOOL blCaselessPath, BOOL blAdminOnly, PSLIBSZHASH pMountHash);

/**
 * Clean all recycle bins under user home directories.
 *
 * @param[in] szHomesDir   path of homes dir. Should not be NULL.
 *
 * @grantable N
 *
 * @retval   0  On success.
 * @retval  -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNOShareRecycleUserHomeClean(const char *szHomesDir);

/**
 * Running the clean recycle bin process to clean share's recycle bin
 *
 * @param[in] szShare    Recycle bin on share @a szShare will be cleaned.
 *                       If @a szShare == NULL, recycle bins on all shares will be cleaned.
 *
 * @grantable N
 *
 * @retval  -1   error
 * @retval   1   success
 */
int SYNOShareRecycleClean(const char *szShare);
int SYNOShareRecycleCleanByPolicy(const char *szShare, SYNO_RECYCLE_POLICY_CLEAN policy);

/**
 * Query the status of clean recycle bin process
 *
 * @param[in] szShare    Get the status of clean process of share @a szShare.
 *                       If @a szShare == NULL, it gets the status of clean process of all shares.
 *
 * @grantable N
 *
 * @retval  -1   error
 * @retval   0   no clean process running
 * @retval   1   clean process alive
 */
int SYNOShareRecycleCleanStatusGet(const char *szShare);

/**
 * Kill the clean recycle bin process
 *
 * @param[in] szShare    Kill the the clean process of share @a szShare.
 *                       If @a szShare == NULL, it kills clean process of all shares.
 *
 * @grantable N
 *
 * @retval   -1  impossible
 * @retval    0  success
 */
int SYNOShareRecycleCleanStop(const char *szShare);

/**
 * Set a file delete time, when file move into recycle bin
 *
 * @ingroup SHARE
 * @param[in] szFile    file name include path. Should not be NULL.
 * @param[in] t         delete time.
 *
 * @grantable N
 *
 * @retval    0  On success.
 * @retval   -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNOShareRecycleDtimeSet(const char *szFile, time_t t);

/**
 * Get a file delete time(dtime) from EA
 *
 * @param[in]  szFile   file name include path. Should not be NULL.
 * @param[out] pTime    pointer of delete time
 *
 * @grantable N
 *
 * @retval   -1   error
 * @retval    1   success
 */
int SYNOShareRecycleDtimeGet(const char *szFile, time_t *pTime);

/**
 * Check if recycle bin is enabled for user home share.
 * Return TRUE for enabled and FALSE for disabled.
 *
 * @grantable N
 *
 * @retval   TRUE   Recycle bin for user home share is enabled.
 * @retval   FALSE  Recycle bin for user home share is disabled.
 */
BOOL SYNORecycleHomeShareStatusGet(void);

/**
 * Check if recycle bin is enabled for a certain share.
 *
 * @param[in]   szShare      The sharename to be checked.
 * @param[out]  pblEnabled   address of variable for enabled/disabled status
 *                           should not be NULL.
 *
 * @grantable N
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNORecycleStatusGet(const char *szShare, BOOL *pblEnabled);

/**
 * Check if recycle bin is admin only or not.
 *
 * @param[in]  szShare       The sharename to be checked.
 * @param[out] pblAdminOnly  address of variable for admin only status should not be NULL.
 *
 * @grantable N
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNORecycleAdminOnlyStatusGet(const char *szShare, BOOL *pblAdminOnly);

/**
 * Enable/Disable recycle bin for user home share.
 *
 * @param[in]  blEnable  TRUE to enable and FALSE to disable.
 *
 * @grantable N
 *
 * @retval   0  On success.
 * @retval  -1  On error.
 */
int SYNORecycleHomeShareStatusSet(BOOL blEnable);

/**
 * Enable/Disalbe recycle bin for a certain share.
 *
 * @param[in]  szShare    The sharename
 * @param[in]  blEnabled  TRUE to enable and FALSE to disable.
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @grantable N
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNORecycleStatusSet(const char *szShare, BOOL blEnabled);

/**
 * Set yes/no for admin only status of a certain share.
 *
 * @param[in] szShare       The sharename
 * @param[in] blAdminOnly   TRUE for yes and FALSE for no.
 *
 * @retval   0   On success.
 * @retval  -1   On error.
 *
 * @grantable N
 *
 * @exception ERR_BAD_PARAMETERS
 */
int SYNORecycleAdminOnlyStatusSet(const char *szShare, BOOL blAdminOnly);

/*
 * Get the all user home recycle path.
 *
 * @param[out] ppListDir  put all share paths of recycle bin of all user
 *
 * @grantable N
 *
 * @retval   -1  failed
 * @retval    0  Success
 */
int SYNORecycleHomeEnumRecyclePath(PSLIBSZLIST *ppListDir);

/*
 * Get the all user exist home path
 *
 * @param[out]  ppListDir   put all paths of exist home of specify user
 * @param[in]   authType    The AUTH_TYPE. Matching by SYNOUSER::authType
 *
 * @grantable N
 *
 * @retval    0   none path found.
 * @retval   -1   On error
 *
 */
int SYNORecycleHomePathEnum(PSLIBSZLIST *ppListDir, const AUTH_TYPE authType);

/*
 * Get the all user home recycle path.
 *
 * @param[out] ppListDir  put all share paths of recycle bin of all user
 * @param[in]  authType   The AUTH_TYPE. Matching by SYNOUSER::authType
 *
 * @grantable N
 *
 * @retval   -1  failed or none path found
 * @retval    0  Success
 */
int SYNORecycleHomeEnumRecyclePathForAuthType(PSLIBSZLIST *ppListDir, const AUTH_TYPE authType);

/**
 * Check if the full path is recycle bin in user home.
 *
 * @param[in]  szPath     The recycle bin full path
 * @param[in]  authType   The AUTH_TYPE. Matching by SYNOUSER::authType
 *
 * @grantable N
 *
 * @retval   TRUE   szPath is Recycle bin path for authType
 * @retval   FALSE  szPath is not Recycle bin path for authType
 */
BOOL SYNORecycleUserHomePathIsExist(const char *szPath, const AUTH_TYPE authType);
