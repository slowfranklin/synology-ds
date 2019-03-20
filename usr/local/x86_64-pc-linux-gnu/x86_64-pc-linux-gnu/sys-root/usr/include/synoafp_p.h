/** Clear the zone value in afpd.conf
 *
 * @retval  0 success
 * @retval -1 fail
 *
 * @grantable   NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAppleClearZoneValue(void);

/** Get the zone value in afpd.conf
 *
 * @param[in]  szZone
 * @param[in]  max
 *
 * @retval  0  success
 * @retval -1  fail
 *
 * @grantable   NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAppleGetZoneValue(char *szZone, int max);

/** SLIBAppleSetZone() set the zone on szIfName to szNewZone
 *
 * @param[in]  szIfName
 * @param[in]  szNewZone
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable   NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBAppleSetZone(const char *szIfName, const char *szNewZone);

/** Set the zone value in afpd.conf
 *
 * @param[in]  szZone
 *
 * @retval  0  success
 * @retval -1  fail
 *
 * @grantable   NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAppleSetZoneValue(const char *szZone);

/**
 * Check whether apfd is running
 *
 * 1. The key SZ_RUNAFP = 'yes':
 *    (1) afpd is running, ruturn 1.
 * 2. Otherwise. return 0, we look it as afpd is not running.
 *
 * @retval  1  afpd is running
 * @retval  0  otherwise.
 *
 * @grantable   NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOAppleTestAppleRunning(void);

/**
 * Free the SYNO_APPLE_ZONE linked list created by SYNOAppleZoneGet()
 *
 * @param[in] pHead  SYNO_APPLE_ZONE linked list created by SYNOAppleZoneGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOAppleZoneFree(SYNO_APPLE_ZONE *pHead);

/**
 * Enumerate all AppleTalk zones and put it in a linked list.
 * Caller should call SYNOAppleZoneFree() to free the *ppHead
 * after success reture.
 *
 * When error occurs, the ppHead will not be touch and no need
 * to free it.
 *
 * @param[in] szIf     The interface name (e.g. eth0, eth1) that the zone belongs to.
 *                     If szIf is NULL, we will enumerate all zones in all interfaces.
 * @param ppHead[out]  The double pointer of the head of linked list.
 *
 * @retval  0   Success (no zone file is also treated as success)
 *         -1   Failed
 * @grantable NO
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAppleZoneGet(const char *szIf, SYNO_APPLE_ZONE **ppHead);

/**
 * Delete time machine share configuration if matched.
 *
 * @param[in]   szShareName  share name
 *
 * @retval  0 success
 *         -1 failed
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAFPTimeMachineDel(const char *szShareName);

/**
 * Rename time machine share configuration if matched.
 *
 * @param[in] szOrgShareName  original share name
 * @param[in] szNewShareName  new share name
 *
 * @retval  0  success
 * @retval -1  failed
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAFPTimeMachineSet(const char *szOrgShareName, const char *szNewShareName);

/**
 * Get time machine share configuration.
 *
 * @param[out] szShareName  share name
 * @param[in]  cbShareName  length of share name
 *
 * @retval   1  found
 * @retval   0  not found
 * @retval  -1  failed
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOAFPTimeMachineGet(char *szShareName, int cbShareName);

/**
 * To Set System AFP , but not enable or disable the service
 *
 * @param[in]  newRunAFP   1 to set TimeMachineShare, 0 to do nothing
 * @param[in]  *zNewTimeMachineShare   New TimeMachineShare name
 * @param[in]  *szNewAppleZone    New AppleTalkZone name
 *
 * @return   0  success
 * @retval  -1  fail
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUISetAFP(int newRunAFP, const char *szNewTimeMachineShare, char *szNewAppleZone);

/**
 * To Set System Bonjour Support
 *
 * @param[in]  newBonjour : 1 to enable, 0 to disable
 * @param[out] *pRestartmDNS : flag to restart DAEMON_mDNS
 *
 * @retval   0  success
 * @retval  -1  fail
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOUISetBonjourSupport(int newBonjour, int *pRestartmDNS);

/**
 * Get afp.conf "disconnect time"
 *
 * @param[out] pEnable   1 to enable, 0 to disable
 *
 * @retval   0  success
 * @retval  -1  fail
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SYNOAFPDisconnectQuickGet(BOOL* pEnable);

/**
 * Set afp.conf "disconnect time"
 *
 * @param[in] blEnable   1 to enable, 0 to disable
 *
 * @retval   0  success
 * @retval  -1  fail
 *
 * @grantable No
 * @apparmor abstractions/libsynoafp
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SYNOAFPDisconnectQuickSet(BOOL blEnable);
