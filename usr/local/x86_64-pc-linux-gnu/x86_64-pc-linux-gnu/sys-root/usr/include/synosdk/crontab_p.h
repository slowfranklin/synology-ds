/**
 * @addtogroup CRONTAB
 *
 * @{
 */

/**
 * To get an entry from /etc/crontab:
 * - It will get the line that key is equal to @p szCommand.
 * - If key is not found in the crontab, then return 0.
 *
 * @param[in]   szCommand  The key of an entry.
 * @param[out]  pSchedule  An entry in /etc/crontab , must bzero first.
 *
 * @retval    1    Get an entry successfully.
 * @retval    0    The entry is not found.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS if parameter is illegal
 * @exception ERR_KEY_NOT_FOUND  if no entry is found
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOScheduleGet(const char *szCommand, PSYNOSCHEDULE pSchedule);

/**
 * To remove an entry in /etc/crontab:
 * - It will remove the line that key is equal to @p szCommand.
 * - If command is not found in the crontab, then nothing happened.
 *
 * @param[in]   szCommand   The command string.
 *
 * @retval    0    Remove an entry successfully, or key is not found.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS if parameter is illegal
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOScheduleRemove(const char *szCommand);

/**
 * To add or set an entry in /etc/crontab:
 * - It will replace the line that key is equal to @p pSchedule->szCommand .
 * - If key is not found in the crontab, We will just add an new line.
 *
 * @param[in]   pSchedule  A pointer to SYNOSCHEDULE, prepared to be set or added.
 * @param[in]   bAppend    Whether to append schedule.
 *
 * @retval    0    Set an entry successfully
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS if parameter is illegal
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOScheduleSet(PSYNOSCHEDULE pSchedule, int bAppend);

/**
 * Update /etc/crontab.
 *
 * 1. To add or set an entry:
 *    We will replace the line that szKey presents by the szLine.
 *    If the szKey is not found in the crontab, We will just add an new line.
 * 2. To remove an entry:
 *    The szKey is the key of the remove line.
 *    The szLine is NULL.
 *
 * @param[in]     szKey         The key in crontab.
 * @param[in]     szKey         The line in crontab.
 * @param[in]     blIsHupCrond  Whether to send SIGHUP to crond.
 *
 * @retval    0    On success
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUpdateCrontab(const char *szKey, const char *szLine, BOOL blIsHupCrond);

/**
 * @}
 */
