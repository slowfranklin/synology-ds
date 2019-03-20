/**
 * @addtogroup BDB
 *
 * @{
 */

/**
 * Closes and frees a opened Synology Database File Handle. This
 * function will try to flush any cached information to disk,
 * free any allocated resources, and close the underlying file.
 * But it may be failed to finish those operations and return -1
 * on error.  In this case, caller should try to build a new db
 * and deprecate this db. Otherwise return 0 on success.
 *
 * @param[out] pDb The SYNOBDB handle. Should not be NULL.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS	when occurs I/O errors
 * @exception ERR_DISK_IO_FAILED	when occurs disk I/O
 * @exception ERR_INTERRUPTED		when occurs interrupted by signal
 * @exception ERR_NOT_ENOUGH_SPACE	when remaining space is not enough
 * @exception ERR_VOLUME_READ_ONLY	it's imposible to open the device for writing on read-only file system
 *
 * @grantable No
 *
 * @see SLIBCBdbOpen()
 *
 * @apparmor None.
 */
int SLIBCBdbClose(PSYNOBDB pDb);

/**
 * Obtains the last sync time that this @p pDb Database file has
 * been sync to the associated configure file and stores into
 * the pointer @p pptimeSync.
 *
 * The sync time is stored as key
 * ::SYNO_BDB_SZK_CONF_SYNC_TIME.
 *
 * @param[in] pDb The SYNOBDB handle. Should not be NULL.
 * @param[out] pptimeSync The pointer to store last sync time. Should not be NULL.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SYNO_BDB_SZK_CONF_SYNC_TIME
 * @see SLIBCBdbConfSyncTimeSet()
 */
int SLIBCBdbConfSyncTimeGet(const PSYNOBDB pDb, time_t **pptimeSync);

/**
 * Marks that this @p pDb Database file has been sync to the
 * associated configure file at the time @p timeConfModify. The
 * @p timeConfModify should come from the modify time of
 * updated configure file.
 *
 * The sync time is stored as key
 * ::SYNO_BDB_SZK_CONF_SYNC_TIME.
 *
 * @param[in] pDb The SYNOBDB handle. Should not be NULL.
 * @param[in] timeConfModify The time_t that contains modify time of newly updated configure file.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCBdbSet()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SYNO_BDB_SZK_CONF_SYNC_TIME
 * @see SLIBCBdbIsNeedToRebuild()
 */
int SLIBCBdbConfSyncTimeSet(const PSYNOBDB pDb, const time_t timeConfModify);

/**
 * Gets a record from database @p pDb according to
 * SYNOBDB::dbCursor. On success, returns 0, stores key into
 * buffer @p ppKey, stores data into buffer @p ppData and
 * updates @p pcbKey and @p pcbData. On failure, returns -1 and
 * leaves @p ppKey, @p ppData unchanged. When @p blSkipMetaData
 * is TRUE, this function will skip all keys that started with
 * ::SYNO_BDB_SZK_PREFIX.
 *
 * If @p *ppKey is NULL, then this function will allocate a
 * buffer for storing the data, which should be freed by
 * SLIBCBdbFree(). Alternatively, before calling this function,
 * @p *ppKey can contain a pointer to a malloc()-allocated
 * buffer with @p *pcbKey bytes in size. If the buffer is not
 * large enough to hold the data, this function resizes it with
 * realloc(), updating @p *ppKey and @p *pcbKey as necessary. In
 * either case, on a successful call, @p *ppKey and @p *pcbKey
 * will be updated to reflect the buffer address and allocated
 * size respectively.
 *
 * This rule also applies to @p *ppData and @p *pcbData.
 *
 * Those functions that want to enumerates all keys should
 * use SLIBCBdbCursorSetType() with
 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_FIRST or
 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_LAST first to guarantee
 * the cursor starting at the position it desired.
 *
 * For example:
 *
 * @code{.c}
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_FIRST);
 * SLIBCBdbCursorGet(); // Get the 1-st record
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_NEXT);
 *
 * while(NEXT) {
 *       SLIBCBdbCursorGet(); // Get the rest records
 * }
 * @endcode
 *
 * @param[in] pDb The SYNOBDB handle. Should not be NULL.
 * @param[in] blSkipMetaData The boolean that indicats this enumeration should skip meta data when TRUE.
 * @param[out] ppKey The pointer to key buffer. Should not be NULL.
 * @param[out] pcbKey The pointer to size or length of key. Should not be NULL.
 * @param[out] ppData The pointer to data buffer. Should not be NULL.
 * @param[out] pcbData The pointer to data buffer length. Should not be NULL.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_BDB_GET_FAILED
 * @exception ERR_DISK_IO_FAILED
 * @exception ERR_INTERRUPTED
 * @exception ERR_BDB_CURSOR_FINISH
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCBdbCursorGet(const PSYNOBDB pDb, const BOOL blSkipMetaData, void **ppKey, size_t *pcbKey, void **ppData, size_t *pcbData);

/**
 * Change the cursor type to @p iCursorType of
 * db handle @p pDb.Calling this function will
 * not affect the cursor behavior until calling
 * SLIBCBdbCursorGet().
 *
 * The example code illustrates how to
 * enumerate over the db twice:
 *
 * @code{.c}
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_FIRST);
 * SLIBCBdbCursorGet();  // Get the 1-st record
 * SLIBCBdbCursorSetType(SYNOBDB_CURSOR_NEXT);
 *
 * while(NEXT) {
 *       SLIBCBdbCursorGet(); // Get the rest records
 * }
 * @endcode
 *
 * @param[out] pDb The SYNOBDB handle.  Should not be NULL.
 * @param[in] iCursorType The cursor type.  Should be checked by BDbIsValidCursorType()
 *
 * @retval 0 on success
 * @retval -1 on failure
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCBdbCursorSetType(const PSYNOBDB pDb, const SYNOBDB_CURSOR_TYPE iCursorType);

/**
 * Gets data from @p pDbt, and stores into buffer @p ppData and
 * updates @p pcbData. If @p ppData is NULL, allocs buffer for
 * it. Otherwise if the @p ppData is not NULL, buffer size @p
 * pcbData will be checked is large enough to store the data.
 *
 * @param[in] pVoidDbt The pointer to DBT that
 * @param[out] ppData The pointer to data buffer. May be NULL.
 * @param[out] pcbData The pointer to data buffer length. Should not be NULL if ppData is not NULL.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception SLIBCCheckAndRealloc()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDBTCopyOut(const void *pVoidDbt, void **ppData, size_t *pcbData, BOOL blEncoded);

/**
 * Sets @p pData and @p cbSize to @p dbt.
 *
 * SLIBCDBTSet() set the DataType of DB.
 *
 * @param[out] pDbt The pointer of DBT. Should not be NULL.
 * @param[in] pData The data to be set into DBT. Should not be NULL.
 * @param[in] cbSize The size of data be set into DBT. Should be positive.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDBTSet(void *pDbt, const void *pData, const size_t cbSize);

/**
 * Deletes a record represented by @p pKey from
 * database @p pDb.
 *
 * @param[in] pDb The SYNOBDB handle. Should not be NULL.
 * @param[in] pKey The key need to be delete from pDB. Should not be NULL.
 * @param[in] cbKey The size or length of key. Should be a positive number.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_BDB_DELETE_FAILED
 * @exception ERR_DISK_IO_FAILED
 * @exception ERR_INTERRUPTED
 * @exception ERR_NOT_ENOUGH_SPACE
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCBdbDelete(const PSYNOBDB pDb, const void *pKey, const size_t cbKey);

/**
 * Frees a allocated resource the allocated by SYNOBDb family.
 *
 * @param[out] pData The pointer of resource the allocated by SYNOBDb family. Should not be NULL.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCBdbFree(void *pData);

/**
 * Gets a record represented by @p pKey from
 * database @p pDb. And stores the record into buffer @p ppData
 * and Updates pcbData.
 *
 * If @p *ppData is NULL, then this function will allocate a
 * buffer for storing the data, which should be freed by
 * SLIBCBdbFree().  Alternatively, before calling this function,
 * @p *ppData can contain a pointer to a malloc()-allocated
 * buffer with @p *pcbData bytes in size.  If the buffer is not
 * large enough to hold the data, this function resizes it with
 * realloc(), updating @p *ppData and @p *pcbData as necessary.
 * In either case, on a successful call, @p *ppData and @p
 * *pcbData will be updated to reflect the buffer address and
 * allocated size respectively.
 *
 * @param[in] pDb The SYNOBDB handle.  Should not be NULL.
 * @param[in] pKey The key.  Should not be NULL.
 * @param[in] cbKey The size or length of key.  Should be a positive number.
 * @param[out] ppData The pointer to data buffer. Should not be NULL.
 * @param[out] pcbData The pointer to data buffer length. Should not be NULL.
 *
 * @retval 0 On success.
 * @retval -1 On failure and @p ppData unchanged.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_BDB_GET_FAILED
 * @exception ERR_DISK_IO_FAILED
 * @exception ERR_INTERRUPTED
 * @exception ERR_KEY_NOT_FOUND
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCBdbFree()
 */
int SLIBCBdbGet(const PSYNOBDB pDb, const void *pKey, const size_t cbKey, void **ppData, size_t *pcbData);

/**
 * Checks the modify time of configure file @p timeConfModify is
 * newer than the sync time of this SYNOBDB @p pDb and returns 1
 * when rebuild is needed.  After rebuild done, caller should
 * mark this db as deprecated by calling SLIBCBdbDeprecatedSet()
 * to inform other process that using this db to reload.
 * 
 * This function calls SLIBCBdbConfSyncTimeGet() to get sync
 * time of this db then checks.  Only when @p timeConfModify
 * newer than sync time, 1 is returned.
 *
 * @param[in] pDb The SYNOBDB handle that to be checked.
 * @param[in] timeConfModify The modify time of configure file.
 *
 * @retval 1 Need to rebuild this Db file.
 * @retval 0 Check successful, but no rebuild is need.
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCBdbConfSyncTimeGet()
 * @see SLIBCBdbConfSyncTimeSet()
 */
int SLIBCBdbIsNeedToRebuild(const PSYNOBDB pDb, const time_t timeConfModify);

/**
 * Opens or creates Database File @p szDBPath.
 * SLIBCBdbOpen() allocates Synology Database File Handle and
 * sets the SYNOBDB::dbCursor to
 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_NEXT.
 *
 * The underlying operation is implemented by the BTREE of
 * DB-1.85.
 *
 * @param[in] szDBPath The string contains db file path. Should not be NULL.
 * @param[in] flags    The flags are as specified to the
 *                     open(2) routine, however, only the following flags are meaningful.
 *                     - O_CREAT create file if it does not exist
 *                     - O_EXCL error if create and file exists
 *                     - O_EXLOCK atomically obtain an exclusive lock
 *                     - O_NONBLOCK do not block on open
 *                     - O_RDONLY open for reading only
 *                     - O_RDWR open for reading and writing
 *                     - O_SHLOCK atomically obtain a shared lock
 *                     - O_TRUNC truncate size to 0
 * @param[in] blDupKey Set the allowance of duplicated key when TRUE.
 *
 * @retval !NULL a vaild Synology Database File Handle.
 * @retval NULL on failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_BDB_FILE_BAD_FORMAT
 * @exception ERR_ACCESS_DENIED
 * @exception ERR_NOT_ENOUGH_SPACE
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who has @p flags permission on @p szDBPath
 *
 * @apparmor None.
 *
 * @see SLIBCBdbClose()
 */
PSYNOBDB SLIBCBdbOpen(const char *szDBPath, const int flags, BOOL blDupKey);

/**
 * Sets a record represented by @p pKey and @p pData to database
 * @p pDb. On success, returns 0. On failure, returns -1.
 * 
 * The @p pKey is existed in @p pDb already, then the data
 * will be overwritten by @p pData.
 *
 * the key with prefix "#" means metadata, and it's need to be
 * removed before metadata update.
 *
 * @param[in] pDb The SYNOBDB handle.  Should not be NULL.
 * @param[in] pKey The key.  Should not be NULL.
 * @param[in] cbKey The size or length of key.  Should be a positive number.
 * @param[in] pData The data.  Should not be NULL.
 * @param[in] cbData The data length.  Should be a positive.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_BDB_FILE_DEPRECATED
 * @exception ERR_BDB_SET_FAILED
 * @exception ERR_DISK_IO_FAILED
 * @exception ERR_INTERRUPTED
 * @exception ERR_NOT_ENOUGH_SPACE
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCBdbSet(const PSYNOBDB pDb, const void *pKey, const size_t cbKey, void *pData, size_t cbData);

/**
 * The function to encrypt or decrypt buffer and
 * the length of input buffer is equal to the length of output
 * buffer. If input buffer is an encrypted string, output buffer
 * will be an plain string. If input buffer is a plain string,
 * output buffer will be an encrypted string.
 *
 * @param[in] pVoidDbt the input string
 * @param[out] ppData the output string after encrypt or decrypt
 * @param[in,out] pcbData the length is needed by output buffer
 *
 * @retval 0 success
 * @retval -1 failed
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDBTEncode(const void *pVoidDbt, void *ppData, size_t *pcbData);

/**
 * Obtains the last sync time of @p szFileName that this @p pDb Database
 * file has been sync to and stores into the pointer @p pptimeSync.
 *
 * @param[in] pDb  The SYNOBDB handle.  Should not be NULL.
 * @param[in] szFileName  file name for sync. Should not be NULL.
 * @param[out] pptimeSync The pointer to store last sync time. Should not be NULL.
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_READ_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCBdbFileSyncTimeSet()
 */
int SLIBCBdbFileSyncTimeGet(const PSYNOBDB pDb, const char *szFileName, time_t *ptimeSync);

/**
 * Marks that this @p pDb Database file has been sync to the
 * associated file.
 *
 * The sync time is stored as key ::SYNO_BDB_SZK_CONF_SYNC_TIME
 * append by @p szFileName.
 *
 * @param[in] pDb  The SYNOBDB handle. Should not be NULL.
 * @param[in] szFileName  file to sync with mtime
 *
 * @retval 0 On success
 * @retval -1 On failure
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 * @exception SLIBCBdbSet()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCBdbFileSyncTimeGet()
 * @see SLIBCBdbIsNeedToRebuild()
 */
int SLIBCBdbFileSyncTimeSet(const PSYNOBDB pDb, const char *szFileName);

/**
 * @}
 */
