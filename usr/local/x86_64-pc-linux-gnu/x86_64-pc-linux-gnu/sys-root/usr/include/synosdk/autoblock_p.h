/**
 * @addtogroup AUTOBLOCK
 *
 * @{
 */

/**
 *  This function is deprecated,
 *  please use SYNOAutoBlockCheckDenied in project libsynoautoblock instead
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOAutoBlockIsDeniedIP(const char *szAddr);

/**
 *  This function is deprecated,
 *  please use SYNOAutoBlockFailRest in project libsynoautoblock instead
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAutoBlockResetByIP(const char *szAddr);

/**
 *  This function is deprecated,
 *  please use SYNOAutoBlockFailLoginSetWithService in project libsynoautoblock instead
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAutoBlockFailLoginSet(const char *szAddr);

/**
 * check IP or hostname in autoblock white list.
 *
 * @param[in]   szAddr   IP or hostname.
 *
 * @retval TRUE in white list.
 * @retval FALSE not in white list.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SLIBAutoBlockInWhiteList(const char *szAddr);

/**
 * @}
 */
