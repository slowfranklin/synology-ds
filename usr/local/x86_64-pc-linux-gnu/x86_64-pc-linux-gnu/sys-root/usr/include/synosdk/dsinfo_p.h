/**
 * @addtogroup DSINFO
 *
 * @{
 */

/**
 * Get User Agent for Synology service.
 *
 * @param[in]   szAppName      Application name for user agent.
 * @param[out]  szUserAgent    Output user agent.
 * @param[in]   cbUserAgent    Size of @szUserAgent.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception SLIBCFileGetKeyValue()
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBDsinfoUserAgentGet(const char* szAppName, char *szUserAgent, size_t cbUserAgent);

/**
 * Get the serial number.
 * Get the HA serial number if in HA mode.
 *
 * @param[out] szSerial   Buffer to store serial number.
 * @param[in]  cbSize     Number of bytes in @p szSerial.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBGetSerialNumber(char *szSerial, int cbSize);

/**
 * Get the original serial number, for internal use.
 * SHOULD NOT this function directly.
 *
 * @param[out] szSerial   Buffer to store serial number.
 * @param[in]  cbSize     Number of bytes in @p szSerial.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SLIBGetOriginalSerialNumber(char *szSerial, int cbSize);

/**
 * Get the customized serial number.
 * Get the HA customized serial number if in HA mode
 *
 * @param[out] szSerial   Buffer to store serial number.
 * @param[in]  cbSize     Number of bytes in @p szSerial.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBGetCustomSerialNumber(char *szSerial, int cbSize);

/**
 * Get the original customized serial number, for internal use.
 * SHOULD NOT this function directly
 *
 * @param[out] szSerial   Buffer to store serial number.
 * @param[in]  cbSize     Number of bytes in @p szSerial.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SLIBGetOriginalCustomSerialNumber(char *szSerial, int cbSize);

/**
 * This API is for synology cloud service to get MAC address.
 * Please use SLIBNetGetMacAddr or SLIBSystemFirstVenderMacAddrGet instead.
 *
 * @param[out]   szMac   The MAC address
 * @param[in]    cbMac   The size of @p szMac
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNODsinfoCloudServiceGetMacAddress(char* szMac, int cbMac);

/**
 * @}
 */
