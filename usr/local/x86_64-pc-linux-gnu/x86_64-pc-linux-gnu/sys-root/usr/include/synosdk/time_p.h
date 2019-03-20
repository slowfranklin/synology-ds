/**
 * @addtogroup TIME
 *
 * @{
 */

/**
 * Get description of timezone @p szZone.
 *
 * @param[in]   szZone   The timezone name. Should not be NULL.
 * @param[out]  szDesc   A buffer to store timezone description. May be NULL.
 * @param[in]   cbSize   The number of bytes in @p szDesc. When @p szDesc is NULL, @p cbSize should be 0.
 * @param[out]  pcbNeed  The number of bytes needed. Should not be NULL.
 *
 * @retval    1   On success, and the timezone description is filled in @p szDesc.
 * @retval    0   On success, but @p szDesc is NULL.
 * @retval    -1  On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOZoneDesc(char *szZone, char *szDesc, int cbSize, int *pcbNeed);

/**
 * Get tzinfo hash of @p szZone from SZF_TZTABLE.
 *
 * @param[in]    szZone    The timezone name. Should not be NULL.
 * @param[out]   ppTZInfo  The tzinfo of @p szZone.
 *
 * @retval   1    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SYNOZoneGetInfo(char *szZone, PSLIBSZHASH *ppTZInfo);

/**
 * Get system timezone.
 *
 * @param[out]   szZone    The timezone name to get. May be NULL.
 * @param[in]    cbSize    The number of bytes in @p szZone. When @p szZone is NULL, @p cbSize should be NULL.
 * @param[out]   pcbNeed   The number of bytes needed to store timezone name in @p szZone.
 *
 * @retval   0   On success.
 * @retval   -1  On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOZoneGet(char *szZone, int cbSize, int *pcbNeed);

/**
 * List all timezones.
 *
 * @param[out]    ptzlist    The list to store all timezones.
 *
 * @retval   0   On success.
 * @retval   -1  On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SYNOZoneEnumList(PSLIBSZLIST *ptzlist);

/**
 * @}
 */
