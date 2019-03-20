/**
 * @addtogroup ERROR
 *
 * @{
 */

/**
 * Obtains the latest error code from the @c synoerrno
 * global variable.
 *
 * @return The latest synology errno code.
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCErrSet()
 */
int SLIBCErrGet(void);

/**
 * Gets the file name when latest error occurs.
 *
 * @retval NULL Not supported
 * @retval !NULL A string pointer
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @grantable No
 *
 * @apparmor None.
 */
const char *SLIBCErrorGetFile(void);

/**
 * Gets the file line number when latest error occurs.
 *
 * @retval 0 Not supported
 * @retval >0 A postive The valid line number.
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCErrorGetLine(void);

/**
 * Sets the global variable synoerrno to the SYNOERR
 * @p errCode.
 *
 * These error codes are defined in <synoerr.h> file. And this
 * function will not check the errCode is valid or not.
 *
 * @param[in] errCode The Synology error code to be set.
 * @param[in] szFile The file name to be set.
 * @param[in] nLine The line number code to be set.
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCErrGet()
 */
void SLIBCErrSetEx(SYNOERR errCode, const char *szFile, int nLine);

/**
 * Append the error messages specified by @p szLog parameter
 * to the log file @p szFile.
 *
 * @param[in] szFile The path of log file. Cannot be NULL.
 * @param[in] szLog The log message. Cannot be NULL.
 *
 * @retval 0 success
 * @retval -1 error occurred and call SLIBCErrSet() to set error code appropriately.
 *
 * @exception ERR_BAD_PARAMETERS  if @p szFile or @p szLog is NULL.
 * @exception ERR_OPEN_FAILED     if SYNOFopen() fail to open @p szFile for append mode.
 * @exception ERR_WRITE_FAILED    if fprintf() fail to append @p szLog to @p szFile.
 *
 * @grantable No
 * @user Who can write to @p szFil.
 *
 * @apparmor None.
 */
int SLIBCErrLogSet(char *szFile, char *szLog);

/**
 * @}
 */
