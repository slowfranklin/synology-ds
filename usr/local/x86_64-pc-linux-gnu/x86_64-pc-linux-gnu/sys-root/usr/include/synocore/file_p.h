/**
 * @addtogroup FILE
 *
 * @{
 */

/**
 * Lock a file with @p options in @p timeout.
 *
 * @param[in]   options   Files to lock and exclusive/shared lock info.
 * @param[in]   timeout   Timout.
 *
 * @retval 0 Success.
 * @retval -1 Failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileLock(int options, int timeout);

/**
 * Unlock a file with @p options.
 *
 * @param[in]   options   Files to unlock.
 *
 * @retval 0 Success.
 * @retval -1 Failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileUnlock(int options);

/**
 * Close all locks that previous locked by SLIBCFileLock.
 *
 * @retval 0 Success.
 * @retval -1 Failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileCloseLock(void);

/**
 * Dunmp lock information with @p options.
 *
 * @param[in]   options   Files to dump info.
 *
 * @retval 0 Success.
 * @retval -1 Failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileLockInfoDump(int options);

/**
 * Lock by file @pszFile
 *
 * @param[in]   pszFile      The file is used to lock. Should not be NULL
 * @param[in]   blExclusive  Whether the lock can be shared or not
 * @param[out]  fdLock       The file descriptor if lock success. Should not be NULL
 *
 * @retval  TRUE Lock success
 * @retval FALSE Lock fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_LOCK_FAILED
 *
 * @grantable No
 * @user Who can read/write @p pszFile, or the owner that you want of @p pszFile.
 *
 * @apparmor None.
 */
BOOL SLIBCFileLockByFile(const char *pszFile, BOOL blExclusive, int *fdLock);

/**
 * Unlock by file descriptor @fdLock. This function must be co-work with SLIBCFileLockByFile or SLIBCFileLockTimeByFile
 *
 * @param[in]  fdLock The file descriptor created by SLIBCFileLockByFile or SLIBCFileLockTimeByFile
 *
 * @retval  TRUE Unlock success
 * @retval FALSE Unlock fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_UNLOCK_FAILED
 * @exception ERR_CLOSE_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCFileUnlockByFile(int fdLock);

/**
 * Lock by file @pszFile with a timeout @p timeout.
 *
 * @param[in]   pszFile      The file is used to lock. Should not be NULL
 * @param[in]   blExclusive  Whether the lock can be shared or not
 * @param[in]   timeout      maximum wating time in second to get a lock
 * @param[out]  fdLock       The file descriptor if lock success. Should not be NULL
 *
 * @retval  TRUE Lock success
 * @retval FALSE Lock fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_LOCK_FAILED
 *
 * @grantable No
 * @user Who can read/write @p pszFile, or the owner that you want of @p pszFile.
 *
 * @apparmor None.
 */
int SLIBCFileLockTimeByFile(const char *pszFile, BOOL blExclusive, int timeout, int *fdLock);

/**
 * Add a new line @p szLine into @p szFile before or after the
 * specific line which contains @p szKey according to @p flag. This
 * function will add "\n" to new line.
 *
 * If file doesn't exist, it will create a new one.  And set the
 * line to new file.
 *
 * If the file doesn't end with "\n" and the new line is to be appended
 * at the end of file, it will add a "\n" first.
 *
 * @param[in] szFile The file to be searched. Should not be NULL.
 * @param[in] szKey The key to see if exist in the @p szFile. If @p szKey is NULL, just add line to head or tail of @p szFile determined by @p flag. If key not found, just return 0.
 * @param[in] szLine A new line to add into @p szFile before or after the specific line contains @p szKey according to @p flag. Should not be NULL.
 * @param[in] flag The finding method:
 *            - OP_ADD_AFTER: add new line after the key.
 *            - OP_FIND_LAST: find the last match key in file.
 *            - OP_FIND_CASE: case-insensitive.
 *            - no OP_ADD_AFTER: add new line before the key.
 *
 * @retval 1 successful.
 * @retval 0 not found.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCILineMatch()
 */
int SLIBCFileAddLine(const char *szFile, const char *szKey, const char *szLine, int flag);

/**
 * Add a section named @p szSection in the @p szFile, and set
 * new parameters which stored in @p pHash.
 *
 * @param[in] szFile The path of the configure file. Should not be NULL.
 * @param[in] szSection The name of a section which you want to set new value. Should not be NULL.
 * @param[in] pHash The pointer to a hash which contains (key, value) pairs. Should not be NULL.
 * @param[in] szFormat The output format of the (key, value) pairs. If NULL, the default format is "key=value\n".
 *
 * @retval 1 successful.
 * @retval 0 section already exists.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception SLIBCFileHash2File()
 *
 * @grantable No
 * @user Who can read/write @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileAddSection(const char *szFile, const char *szSection, PSLIBSZHASH pHash, const char *szFormat);

/**
 * Check output format of parameter lines.
 *
 * @param[in] szFormat The format to check.
 *
 * @retval 1 format ok or NULL.
 * @retval 0 format bad.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCIFileCheckFormat(const char *szFormat);

/**
 * Retrieve all section names and stored them in the @p pList.
 *
 * @param[in] szFile The file path of the configure file. Should not be NULL.
 * @param[out] ppList The list which you put the section names. Should not be NULL.
 *
 * @retval  -1  on error.
 * @retval  >=0 num of list items.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileEnumSection(const char *szFile, PSLIBSZLIST *ppList);

/**
 * Check @p szFilePath if existed and if is a regular file.
 *
 * @param[in] szFilePath The path to check.
 *
 * @retval  TRUE existed.
 * @retval FALSE not existed.
 *
 * @grantable No
 * @user Who has execute permission of the dirname of @p szFile.
 *
 * @apparmor None.
 */
BOOL SLIBCFileExist(const char *szFilePath);

/**
 * Get the value of @p szKey in @p szFile and put in @p szValue.
 *
 * @param[in] szFile The input file. Should not be NULL.
 * @param[in] szKey The searched key from @p szFile. Should not be NULL.
 * @param[out] szValue The value of found key. Should not be NULL.
 * @param[in] sizeMax The size of @p szValue.
 * @param[in] flag The finding methods. Should be 0 or OP_FIND_LAST.
 *
 * @retval -1 on error.
 * @retval 0 key not found.
 * @retval >0 size of @p szValue.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetKeyValue(const char *szFile, const char *szKey, char *szValue, int sizeMax, int flag);

/**
 * Get the line contains @p szKey in @p szFile and put in @p
 * szLine.
 *
 * @param[in] szFile The file to be searched. Should not be
 *                NULL.
 * @param[in] szKey The key to see if exist in @p szFile.
 *                Should not be NULL.
 * @param[out] szLine The line contains @p szKey. Should not
 *                be NULL.
 * @param[in] linemax The size of @p szLine.
 * @param[in] flag The finding methods. Should be union of
 *                OP_FIND_CASE,OP_FIND_PREFIX,OP_FIND_POSTFIX,
 *                OP_FIND_LAST.
 *
 * @retval -1 on error.
 * @retval 0 key not found.
 * @retval >0 size of @p szLine.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetLine(const char *szFile, const char *szKey, char *szLine, int linemax, int flag);

/**
 * Get each parameter lines in @p szFile and store (key,value)
 * pairs into the hash @p *ppHash.
 *
 * @param[in] szFile The file path of the configuration file.
 *               Should not be NULL.
 * @param[out] ppHash The hash to store (key,value) pairs.
 *               Should not be NULL.
 *
 * @retval -1 on error.
 * @retval >=0 num of pairs stored in hash.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCStrSepPair()
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetPair(const char *szFile, PSLIBSZHASH *ppHash);

/**
 * Open a samba configuation file @p szFile, get all parameter
 * lines of section @p szSection, add (name, value) pairs into a
 * hash @p *ppHash. Section contains parameters of the form
 * 	name=value
 *
 * @note If @p szSection not found, this function will return 0 and set no
 * error.
 *
 * @param[in] szFile The file path of the configure file.
 *                  Should not be NULL.
 * @param[in] szSection The name of a section. Should not be
 *                  NULL.
 * @param[out] ppHash The hash to store all pairs. Should
 *                  not be NULL.
 *
 * @retval -1 on error.
 * @retval 0 section not found.
 * @retval >=0 num of pairs stored in hash.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCIFileIsSection()
 * @exception SLIBCIFileMatchSection()
 * @exception SLIBCStrSepPair()
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetSection(const char *szFile, const char *szSection, PSLIBSZHASH *ppHash);

/**
 * Check if @p szLine whose length is @p Length is a line
 * containing section.
 *
 * @param[in] szLine The line to check. Should not be NULL.
 * @param[in] Length The size of @p szLine.
 *
 * @retval 1 The line contains a section.
 * @retval 0 The line does not contain a section.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCIFileIsSection(const char *szLine, int Length);

/**
 * Searches @p szKey from @p szLine which not start with '#' and
 * ';'. The @p szKey should be before '='.
 *
 * @param[in] szLine The line to search key @p szKey. Should not be NULL.
 * @param[in] szKey The searched key from @p szLine. Should not be NULL.
 *
 * @retval 1 found.
 * @retval 0 not found.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCILineKeyMatch(char *szLine, const char *szKey);

/**
 * Check if @p szKey in @p szSelLine with @p flag method.
 *
 * @param[in] szSelLine The line to search. Should not be NULL.
 * @param[in] szKey The key to see if exist in @p szSelLine. Should not be NULL.
 * @param[in] flag The finding methods. Should be union of OP_FIND_CASE, OP_FIND_PREFIX, OP_FIND_POSTFIX.
 *
 * @retval 1 key found.
 * @retval 0 key not found.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCILineMatch(const char *szSelLine, const char *szKey, int flag);

/**
 * Get the value of the key @p szKey from the section @p szSection in
 * the file @p szFile, and store into @p szValue which size is @p cbValue.
 *
 * @param[in] szFile The file name to get section. Should not be NULL.
 * @param[in] szSection The section name to get from @p szFile. Should not be NULL.
 * @param[in] szKey The key to get from section @p szSection. Should not be NULL.
 * @param[out] szValue The pointer that this value to be stored. Should not be NULL.
 * @param[in] cbValue The buffer size of @p szValue. Should be a positive.
 *
 * @retval 0 on success.
 * @retval -1 on error.
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetSectionValue(const char *szFile, const char *szSection, const char *szKey, char *szValue, int cbValue);

/**
 * Check if @p szLine matches the [@p szSection].
 *
 * @param[in] szLine The line to search @p szSection. Should not be NULL.
 * @param[in] Length The length of @p szLine.
 * @param[in] szSection The section to search from @p szLine. Should not be NULL.
 *
 * @retval 1 matched.
 * @retval 0 not matched.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCIFileMatchSection(const char *szLine, int Length, const char *szSection);

/**
 * Find the section @p szSection in @p szFile and set the
 * section to new value stored in @p pHash if @p fOP ==
 * SECTION_SET. If @p fOp != SECTION_SET, just delete the section.
 * If @p szNew != NULL, change section name to @p szNew.
 * Every section name or new pair will force to add "\n"
 *
 * @param[in] szFile    The file to access. Should not be NULL.
 * @param[in] szSection The section name to be find. Should not be NULL.
 * @param[in] szNew     The new section name if not NULL.
 * @param[in] pHash     The new section value to be set.  If NULL, it will clear szSection's content.
 * @param[in] fOp       Set new value to section if @p fOp is SECTION_SET. Delete @p szSection if not.
 * @param[in] szFormat  The key-value format. Default is "%s=%s\n"
 *
 * @retval 1 on success.
 * @retval 0 section not found.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCIFileMatchSection()
 */
int SLIBCIFileModifySection(const char *szFile, const char *szSection, const char *szNew, PSLIBSZHASH pHash, int fOp, const char *szFormat);

/**
 * Remove a section(including parameters) named @p szSection
 * from @p szFile.
 *
 * The underlying operation is implemented by
 * SLIBCIFileModifySection().
 *
 * @param[in]  szFile    The file path of the configure file. Should not be NULL.
 * @param[in]  szSection The section name to be remove. Should not be NULL.
 *
 * @retval 1 on success.
 * @retval 0 section not found.
 * @retval -1 on error.
 *
 * @exception SLIBCIFileModifySection()
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileRemoveSection(const char *szFile, const char *szSection);

/**
 * Set the value of the key. If the key doesn't exists, append
 * new key value on the last of file. If there are more than one
 * key match, this function only reserve first one.  And other
 * the same name key will be remove.
 *
 * If the file isn't exist, new file will be create.  And new
 * key will be added in.
 *
 * @param[in]  szFile   The input file. Should not be NULL.
 * @param[in]  szKey    The searched key from @p szFile. Should not be NULL.
 * @param[in]  szValue  The new value to replace old value. Should not be NULL.
 * @param[in]  szFormat The format of the key-value pair. If NULL, the default format is "%s=%s\n".
 *
 * @retval 1 successful.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCILineKeyMatch()
 */
int SLIBCFileSetKeyValue(const char *szFile, const char *szKey, const char *szValue, const char *szFormat);

/**
 * Set multiple key-value pairs that stored in @p pshHash. This
 * function won't change the order of keys in @p szFile. If keys
 * are not in @p szFile, append to the last of @p szFile.
 *
 * @note the content of @p pshHash will be modified after
 *       calling this function.
 *
 * @param[in]      szFile     The file path of the configure file. Should not be NULL.
 * @param[in,out]  pshHash    The hash which contains (key, value) pairs. Should not be NULL.
 * @param[in]      szFormat   The output format. If NULL, "%s=%s" is default.
 *
 * @retval  >=0 num of keys that are set successfully.
 * @retval   -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_WRITE_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBILineKeyMoveHash2File()
 */
int SLIBCFileSetKeys(const char *szFile, PSLIBSZHASH pshHash, PSLIBSZHASH pshHashDel, const char *szFormat);

/**
 * Sets @p szLine by @p szKey in @p szFile. If @p szFile
 * contains no @p szKey, do not set @p szLine and return 0.
 * It will add "\n" to new line.
 *
 * @param[in]  szFile The file to be searched. Should not be NULL.
 * @param[in]  szKey  The key to see if exist in @p szFile. Should not be NULL.
 * @param[in]  szLine A new line to replace the specific line which contains @p szKey.
 * @param[in]  flag   The finding methods.
 *                    - OP_ADD_AFTER: add new line after the key.
 *                    - OP_FIND_LAST: find the last match key in file.
 *                    - OP_FIND_CASE: case-insensitive.
 *                    - no OP_ADD_AFTER: add new line before the key.
 *
 * @retval 1 on success.
 * @retval 0 not found.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCILineMatch()
 */
int SLIBCFileSetLine(const char *szFile, const char *szKey, const char *szLine, int flag);

/**
 * Finds a section named @p szSection in @p szFile, and set new
 * parameters which stored in @p pHash. Besides, it changed old
 * section name @p szOldsection to @p szNew if szNew != NULL.
 *
 * The underlying operation is implemented by
 * SLIBCIFileModifySection().
 *
 * @param[in]  szFile       The file path of the configure file. Should not be NULL.
 * @param[in]  szOldSection The name of a section before you set new value. Should not be NULL.
 * @param[in]  szNew        The new name of the section you made changes. May be NULL.
 * @param[in]  pHash        The hash which contains (name,value) pairs. Should not be NULL.
 * @param[in]  szFormat     The output format.
 *
 * @retval 1 on success.
 * @retval 0 can not set.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCIFileModifySection()
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileSetSection(const char *szFile, const char *szOldSection, const char *szNew, PSLIBSZHASH pHash, const char *szFormat);

/**
 * To create a tempfile for writing whose file name @p
 * szTempFile is unique and random name.
 *
 * @param[in,out] szTempFile Temp file name. Should be end with "XXXXXX" (six upper x for template) and should not be NULL.
 *
 * @retval !NULL File pointer for writing.
 * @retval NULL On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who has write permission on the dirname of @p szTempFile.
 *
 * @apparmor None.
 *
 * @see SLIBFileTempFileClose()
 */
FILE *SLIBCFileTempFileOpen(char *szTempFile);

/**
 * To comment/uncomment a line in file @p szFile which line
 * contains @p szKey. If there are many keys in file, it will
 * comment all line containing @szKey.
 *
 * @param[in] szKey  the key to fine with line prefix
 * @param[in] szFile the file name to be opened
 * @param[in] fOp    0 means comment otherwise uncomment
 *
 * @retval  -1  error
 * @retval  0   not found
 * @retval  1   success
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SYNOUnComment()
 */
int SLIBCFileLineComment(const char *szFile, const char *szKey, int fOp);

/**
 * Checks if the value of @p szKey in the file @p szFilename
 * matches @p szValue. Return @p blWhenKeyNotFound when @p szKey
 * is not found in @p szFilename.
 *
 * @note use strcasecmp() instead of strcmp() to match value.
 *
 * @param[in] szFilename          The file to find the key. Should not be NULL.
 * @param[in] szKey               The key to be found. Should not be NULL.
 * @param[in] szValue             The value to be compared with the value of @p szKey. Should not be NULL.
 * @param[in] blWhenKeyNotFound   Return value when @p szKey not be found in @p szFilename.
 *
 * @retval  TRUE If @p szKey found and match, or not found but @p blWhenKeyNotFound is TRUE.
 * @retval  FALSE If @p szKey not match and @p blWhenKeyNotFound is FALSE, or error occurs.
 *
 * @grantable No
 * @user Who has write permission on @p szFilename and the dirname of @p szFilename.
 *
 * @apparmor None.
 */
BOOL SLIBCFileCheckKeyValue(const char *szFilename, const char *szKey, const char *szValue, BOOL blWhenKeyNotFound);

/**
 * To remove line which contains @p szKey in @p szFile.
 *
 * @param[in] szFile The input file. Should not be NULL.
 * @param[in] szKey  The searched key which want to be removed from the @p szFile. Should not be NULL.
 *
 * @retval >0 num of removed key.
 * @retval 0 key not found.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCILineKeyMatch()
 */
int SLIBCFileRemoveKey(const char *szFile, const char *szKey);

/**
 * Get the first match section name and match szValue from szFile
 * Store result into szKey and szSection
 *
 * It will find the first match section and key to return.
 *
 * @param[in]   szFile      The file name to get section. Should not be NULL.
 * @param[in]   szValue     The pointer that this value should be search for match. Should not be NULL.
 * @param[out]  szSection   The section name to be got
 * @param[in]   cbSection   The size of szSection
 * @param[out]  szKey       The key to be got
 * @param[in]   cbKey       The size of szKey
 *
 * @retval 1 on success and found
 * @retval 0 on success but not found
 * @retval -1 on error.
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetSectionByValue(const char *szFile, const char *szValue, char *szSection, int cbSection, char *szKey, int cbKey);

/**
 * Touch @p szFilePath if not existed.
 *
 * @param[in] szFilePath The path to touch.
 *
 * @retval 0 success
 * @retval -1 error
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileTouch(const char *szFilePath);

/**
 * Check if folder @p szPath exist? (represent as absolutely path)
 *
 * @param[in] szPath The folder path to check (ex: /usr/local/)
 *
 * @retval TRUE Exist
 * @retval FALSE Does not exist
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szPath.
 *
 * @apparmor None.
 */
BOOL SLIBCFileCheckDir(const char *szPath);

/**
 * Read lines from @p szFilePath and append into @p ppList.
 *
 * @note the internal buffer length for single is only 1024
 *       bytes.
 *
 * @param[in]      szFilePath The file to read. Should not be NULL.
 * @param[in,out]  ppList     The list to append read lines. Should not be NULL.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileReadLines(const char *szFilePath, PPSLIBSZLIST ppList);

/**
 * Get all entry name matched @p szKey in @p szDir, and put them
 * into @p *ppslList.
 *
 * @param[in]  szDir     The specific directory to search. Should not be NULL.
 * @param[in]  szKey     The key to search, if NULL, means no limit.
 * @param[out] ppslList  The pointer to a list that stores result. Should not be NULL.
 * @param[in]  fOpt      The finding methods. Should be union of
 *                       - OP_FIND_CASE
 *                       - OP_FIND_PREFIX
 *                       - OP_FIND_POSTFIX
 *                       - OP_FIND_DIR
 *                       - OP_FIND_FILE
 *
 * @retval  >=0 num of list items.
 * @retval  -1   on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCILineMatch()
 *
 * @grantable No
 * @user Who has read permission on @p szDir.
 *
 * @apparmor None.
 */
int SLIBCFileEnumDir(const char *szDir, const char *szKey, PSLIBSZLIST *ppslList, int fOpt);

/**
 * Change access/modified/create time of the file/directory.
 *
 * @param[in] szFilePath  File path.
 * @param[in] flags       To specify the type time to change.
 * @param[in] pTime       Value of time. tv_nsec is:
 *                        - UTIME_NOW: set to the current time.
 *                        - UTIME_OMIT: left unchanged.
 *                        - SLIB_CRTIME: pTime can not be NULL.
 *                        - SLIB_AMTIME: pTime can be NULL, which means current time.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @grantable No
 * @user If pTime is not NULL, the caller's euid has to:
 *      - Match the owner of the @p szFilePath, or
 *      - Should be a privileged user, e.g. root.
 *
 * @apparmor None.
 */
int SLIBCFileUTime(const char *szFilePath, unsigned int flags, SLIB_FILETIME *pTime);

/**
 * Get create time of the file/directory.
 * If create time cannot get from SYNOSTAT, calculate create time
 * from the parameter stat.
 *
 * This function is different with the function SLIBCFileStat with
 * only one parameter, SYNOST_CREATIME. In SLIBCFileStat, if the create
 * time is zero, it will stat again.
 *
 * @param[in]  szFilePath       File path.
 * @param[in]  pSt              Specify which information to get.
 * @param[in]  isCaseSensitive  Flag of case sensitive
 * @param[out] pTimeSpec        Create time
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szFilePath.
 *
 * @apparmor None.
 */
int SLIBCFileCreateTimeGet(const char *szFilePath, struct stat *pSt, BOOL isCaseSensitive, struct timespec *pTimeSpec);

/**
 * Get stat and extra information of the file/directory.
 *
 * @param[in,out]  szFilePath  File path. Return real filepath if caseless.
 * @param[in]      flags       Specify which information to get.
 *                             - SYNOST_STAT
 *                             - SYNOST_ARBIT
 *                             - SYNOST_BKPVER
 *                             - SYNOST_CREATIME
 *                             - SYNOST_ALL
 * @param[out]     pSt         A pointer of SYNOSTAT.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szFilePath.
 *
 * @apparmor None.
 */
int SLIBCFileStat(const char *szFilePath, unsigned int flags, SYNOSTAT *pSt);

/**
 * Get stat and extra information of the file/directory
 * caselessly.
 *
 * @param[in,out]  szFilePath  File path. Return real filepath if caseless.
 * @param[in]      flags       Specify which information to get.
 *                             - SYNOST_STAT
 *                             - SYNOST_ARBIT
 *                             - SYNOST_BKPVER
 *                             - SYNOST_CREATIME
 *                             - SYNOST_ALL
 * @param[out]     pSt         A pointer of SYNOSTAT.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szFilePath.
 *
 * @apparmor None.
 */
int SLIBCFileCaselessStat(char *szFilePath, unsigned int flags, SYNOSTAT *pSt);

/**
 * Get stat and extra information of the file/directory.
 *
 * @param[in] fd     file descriptor
 * @param[in] flags  1. Specify which information to get.
 *                   - SYNOST_STAT
 *                   - SYNOST_ARBIT
 *                   - SYNOST_BKPVER
 *                   - SYNOST_CREATIME
 *                   - SYNOST_ALL
 *                   2. Specify whether filename is caseless.
 *                   - SYNOST_IS_CASELESS
 * @param[out] pSt   A pointer of SYNOSTAT.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileFStat(int fd, unsigned int flags, SYNOSTAT *pSt);

/**
 * Get stat and extra information of the file/directory.
 *
 * @param[in]  szFilePath    File path of symbolic.
 * @param[in]  flags         Specify which information to get.
 *                           - SYNOST_STAT
 *                           - SYNOST_ARBIT
 *                           - SYNOST_BKPVER
 *                           - SYNOST_CREATIME
 *                           - SYNOST_ALL
 * @param[out] pSt           A pointer of SYNOSTAT.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 * @exception ERR_NOT_SUPPORT
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szFilePath.
 *
 * @apparmor None.
 */
int SLIBCFileLStat(const char *szFilePath, unsigned int flags, SYNOSTAT *pSt);

/**
 * Get stat and extra information of the file/directory
 * caselessly.
 *
 * @param[in] szFilePath File path of symbolic.
 * @param[in] flags      Specify which information to get.
 *                       - SYNOST_STAT
 *                       - SYNOST_ARBIT
 *                       - SYNOST_BKPVER
 *                       - SYNOST_CREATIME
 *                       - SYNOST_ALL
 * @param[out] pSt       A pointer of SYNOSTAT.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 * @exception ERR_NOT_SUPPORT
 *
 * @grantable No
 * @user Who has execute permission on the dirname of @p szFilePath.
 *
 * @apparmor None.
 */
int SLIBCFileCaselessLStat(char *szFilePath, unsigned int flags, SYNOSTAT *pSt);

/**
 * Parse setion name to delete two chars of '[' and ']'
 *
 * @param[in]   szSectionName  the section name including []. Should not be NULL.
 * @param[out]  pszNewName     the section name after parsing and not including []. Should not be NULL.
 * @param[in]   cbNewName      the size of pszNewName. Should be > 0
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileParseSectionName(const char *szSectionName, char *pszNewName, int cbNewName);

/**
 * Insert @p szAddLine before/after the FIRST line which
 * matches keywords in @p pslKey. There is a padding "\n" if the
 * last character of @p szAddLine is not "\n" and @p pslKey is
 * not NULL or empty.
 *
 * Match examples:
 * if line is "run_time_error", and seperator is "_"
 * 1. key list contains "run", "time", "error", than it match.
 * 2. key list contains "run", "time", than it won't match.
 * 3. key list contains "time", "run", "error", than it won't match.
 * 4. key list contains "run", "time", "error", "error", than it won't match.
 *
 * @param[in] szFile    The file path which you want to access. Should not be NULL.
 * @param[in] pslKey    The keys to find. If @p pslKey is NULL or empty, insert @p szAddLine into the head or tail of @p szFile.
 * @param[in] szAddLine The line to add. If NULL, do nothing. If @p szAddLine is an empty string, insert a blank line.
 * @param[in] fOpt      Should be 0 or OP_ADD_AFTER.
 * @param[in] szSep     The seperator. Should not be NULL.
 *
 * @retval 1 Successful.
 * @retval 0 No lines match.
 * @retval -1 Error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCFileMatch()
 */
int SLIBCFileAddLineByKey(const char *szFile, PSLIBSZLIST pslKey, const char *szAddLine, int fOpt, const char *szSep);

/**
 * Add a key-value pair with @p szKey and @p szValue into @p
 * szFile with format @p szFormat.
 *
 * @param[in] szFile The input file. Should not be NULL.
 * @param[in] szKey The key of a new pair to append. Should not be NULL.
 * @param[in] szValue The value of a new pair to append. Should not be NULL.
 * @param[in] szFormat The format of the key-value pair. If NULL, the default format is "%s=%s\n".
 *
 * @retval 1 successful.
 * @retval 0 key exist.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_KEY_EXISTS
 *
 * @grantable No
 * @user Who can read/write on @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileAppendKey(const char *szFile, const char *szKey, const char *szValue, const char *szFormat);

/**
 * Check if tokens in @p szLine match with items of @p pslKey in
 * order.
 *
 * @param[in] szLine The line to check. Should not be NULL.
 * @param[in] pslKey The key list to be checked with.
 * @param[in] szSep The key seperator. Should not be NULL.
 *
 * @retval 1 if matched or pslKey is NULL or empty.
 * @retval 0 not matched.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileMatch(const char *szLine, PSLIBSZLIST pslKey, const char *szSep);

/**
 * Match @p szLine from @p szFile and ouput the line number if
 * matched.
 *
 * @note the internal buffer length for single is only 1024 bytes.
 *
 * @param[in] szFile The file to search. Should not be NULL.
 * @param[in] szLine The line to be matched. Should not be NULL.
 *
 * @retval >0 if matched line.
 * @retval 0 not matched.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileMatchLineNo(const char *szFile, char *szLine);

/**
 * Replace all @p szOld patterns with @p szNew.
 *
 * @param[in] szFile The file path which you want to access. Should not be NULL.
 * @param[in] szOld The string to be replaced. Should not be NULL.
 * @param[in] szNew The string to replace. Should not be NULL.
 *
 * @retval -1   error.
 * @retval >=0  num of replace strings.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileReplaceSubStr(const char *szFile, const char *szOld, const char *szNew);

/**
 * To remove line @p szLine in @p szFile.
 * The function is similar to SLIBCFileRemoveKey.
 * However, SLIBCFileRemoveKey would trim spaces in @p szLine before comparison.
 *
 * @param[in] szFile The input file. Should not be NULL.
 * @param[in] szLine The searched line which want to be removed from the @p szFile. Should not be NULL.
 *
 * @retval >0 Num of removed line.
 * @retval 0 Line not found.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileRemoveLine(const char *szFile, const char *szLine);

/**
 * To replace line @p szLine by @p szNewLine in @p szFile.
 * The function is similar to SLIBCFileRemoveLine.
 *
 * @param[in] szFile The input file. Should not be NULL.
 * @param[in] szLine The searched line which want to be replaced from the @p szFile. Should not be NULL.
 * @param[in] szNewLine The line to replace @p szLine from the @p szFile. NULL means "removal" of @p szLine.
 * @param[in] uRepCount If more than one lines are found,
 *            at most @p uRepCount lines would be replaced.
 *            The remainder would not be replaced or removed.
 *            Zero means that do not perform the operation,
 *            just return the number of searched lines.
 *
 * @retval >0 num of replaced line. (num of searched lines if uRepCount = 0)
 * @retval 0 line not found.
 * @retval -1 error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileReplaceLine(const char *szFile, const char *szLine, const char *szNewLine, size_t uRepCount);

/**
 * Replaces matched key line with @p szNew.
 *
 * ex. if target key is "run_time_error", and seperator is "_"
 *     1.key list are "run", "time", "error", than it match.
 *     2.key list are "run", "time", than it won't match.
 *     3.key list are "time", "run", "error", than it won't match.
 *     4.key list are "run", "time", "error", "error", than it won't match.
 *
 * @param[in] szFile The file path which you want to access. Should not be NULL.
 * @param[in] pslKey The list of key's pattern for matching. Should not be NULL or empty.
 * @param[in] szNew If NULL, delete the matched line.
 * @param[in] szSep The seperator. Should not be NULL.
 *
 * @retval >0 num of replace string.
 * @retval 0 keywords not found.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 *
 * @see SLIBCFileMatch()
 */
int SLIBCFileSetLineByKey(const char *szFile, PSLIBSZLIST pslKey, const char *szNew, const char *szSep);

/**
 * Sets (name,value) parameter lines which stored in @p pHash to @p szFile.
 *
 * @param[in] szFile The file path of the configuration file. Should not be NULL.
 * @param[in] pHash The hash that stores the pairs. Should not be NULL.
 * @param[in] szFormat The output format.
 *
 * @retval ERR_SUCCESS on success.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception SLIBCFileHash2File()
 *
 * @grantable No
 * @user Who has write permission on @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileSetPair(const char *szFile, PSLIBSZHASH pHash, const char *szFormat);

/**
 * Set the value @p szValue of the key @p szKey from the section
 * @p szSection in the file @p szFile.
 *
 * @note This function will modify
 * the format of all key-value pairs of the section @p szSection by
 * the format "%s=%s\n" (see SLIBCFileHash2File for details).
 *
 * @param[in] szFile The file name to get section. Should not be NULL.
 * @param[in] szSection The section name to get from @p szFile. Should not be NULL.
 * @param[in] szKey The key to be set into section @p szSection. Should not be NULL.
 * @param[in] szValue The value associates with @p szKey. Should not be NULL.
 *
 * @retval 0 on success.
 * @retval -1 on error.
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileSetSectionValue(const char *szFile, const char *szSection, const char *szKey, const char *szValue);

/**
 * Generates a temp name whose prefix is @p szPrefix and saves
 * it in @p szPath with buffer length @p size.  The format of
 * @p szPath will be "%s%d-%d" (szPrefix + pid + sequence number)
 *
 * @param[in] szPrefix The prefix string of temp name. Should not be NULL.
 * @param[out] szPath The string buffer.  Should not be NULL.
 * @param[in] size The buffer length of @p szPath. Should be greater than length of @p szPrefix.
 *
 * @retval -1 Error
 * @retval 0 Success
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileITmpName(const char *szPrefix, char *szPath, int size);

/**
 * Get key-value paires which match the given keys @p pslKey and
 * stores them in @p ppshHash.
 *
 * @param[in] szFile The file path which you want to access. Should not be NULL.
 * @param[in] pslKey The keys to find. May be NULL. If NULL or empty, save all key-value pairs to @p ppshHash.
 * @param[out] ppshHash The hash saves key-value pairs match @p pslKey. Should not be NULL.
 * @param[in] szSep The seperator. Should not be NULL.
 *
 * @retval  >=0 num of pairs in @p ppshHash.
 * @retval   -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileGetKeys(const char *szFile, PSLIBSZLIST pslKey, PSLIBSZHASH *ppshHash, const char *szSep);

/**
 * Strip the UTF8 BOM of @szFilePath if it has BOM.
 *
 * @param[in] szFilePath The path of file to read. Should not be NULL.
 *
 * @retval  0 successfully remove BOM or no BOM found.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_STAT_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_RENAME_FAILED
 *
 * @grantable No
 * @user Who has write permission on @p szFile and the dirname of @p szFile.
 *
 * @apparmor None.
 */
int SLIBCFileUTF8BomStrip(const char *szFilePath);

/**
 * @}
 */
