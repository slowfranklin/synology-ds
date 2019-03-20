/**
 * @addtogroup FHS
 *
 * @{
 */

/**
 * Check whether a given path exist in snapshot or not.
 *
 * @param[in]   pszFullPath     The fullVolumePath to be checked.
 * @param[out]  pblInSnapshot   Whether a given path exist in snapshot or not.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBFhsPathInSnapshot(const char *pszFullPath, BOOL *pblInSnapshot);

/**
 * @}
 */
