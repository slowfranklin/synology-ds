/**
 * @addtogroup CONF
 *
 * @{
 */

/**
 * This function gets the codepage for the specified protocol.
 *
 * @param[in] iType specified protocol
 * @param[out] pCodePage the codepage got on return
 *
 * @retval -1 On error.
 * @retval 0 On success.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCodePageGet(const int iType, SYNO_CODEPAGE *pCodePage);

/**
 * Check RAID support from default synoinfo
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support, default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportRAID(void);

/**
 * This function consider the argument @param szKey to check if
 * the system support the function of the @param szKey to in
 * synoinfo. If the system support that, it will return TRUE,
 * otherwise return FALSE. If the argument @param szKey to is
 * NULL, this function return FALSE, otherowise return if
 * support the function.
 *
 * @param[in] szKey The string szKey is used to test if the system support this function.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCFileGetKeyValue()
 */
BOOL SLIBCSupportGet(const char *szKey);

/**
 * To get max disk count.
 *
 * @note Please never call LNXSDK in these Max function, unless raidtool don't use them.
 *
 * @retval 0 On error
 * @retval >0 The value of maxdisks in /etc.defaults/synoinfo.conf
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMaxDiskGet(void);

/**
 * Set key value into infoinfo
 *
 * @retval 0 success
 * @retval -1 fail
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor abstractions/libsynocore/conf
 */
int SLIBCINFOSetKeyValue(const char *szKey, const char *szValue);

/**
 * Config UART device node on @p fd.
 *
 * @retval 0 success
 * @retval -1 fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCConfigUart2(int fd);

/**
 * To get the UART2 is supported in this model or not.  This
 * function will call SLIBCFileGetKeyValue() to lookup the key
 * (SZK_SUPPORT_UART2) in file (SZF_DEF_SYNOINFO).  However,
 * in order to reduce the heavy IO, this function will keep a
 * static variable and read SZF_DEF_SYNOINFO only once.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @see SLIBCFileGetKeyValue()
 * @see SZF_DEF_SYNOINFO
 * @see SZK_SUPPORT_UART2
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportUart2(void);

/**
 * Indicate if this machine is USBStation or not
 *
 * @note If you modify this function, you must also modify libsynosdk_cs/4.3/conf/conf_is_usbstation.c
 *
 * @retval TRUE This machine is USBStation.
 * @retval FALSE This machine is DiskStation.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCIsUSBStation(void);

/**
 * Set code page info in synoinfo.conf
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor abstractions/libsynocore/conf
 */
int SLIBCCodePageSet(const int iType, const char *szCodePage);

/**
 * Get webUI timeout in the system configration file.
 *
 * @retval >0 The timeout value in minutes.
 * @retval -1 The operation failed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCConfGetDSMTimeout(void);

/**
 * Set webUI timeout in the system configration file.
 *
 * @param[in] timeout timeount value in minutes
 *
 * @retval -1 If the operation failed
 * @retval 0 If the operation succeeded.
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor abstractions/libsynocore/conf
 */
int SLIBCConfSetDSMTimeout(int timeout);

/**
 * To get disk count.
 *
 * @note Please never call LNXSDK in these Max function, unless raidtool don't use them
 *
 * @return the value of maxlanport in /etc.defaults/synoinfo.conf
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMaxLanPortGet(void);

/**
 * Check SAS support
 *
 * @retval TRUE  Supports.
 * @retval FALSE Does not support. Default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportSAS(void);

/**
 * Remve the Key @p szKey from /etc/synoinfo.conf
 * It will only remove the first key it find.
 *
 * @param[in] szKey The key tobe reomved
 *
 * @retval  >=0 on success.
 * @retval  -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCFileRemoveKey()
 * @exception SLIBCFileLock()
 * @exception SLIBCFileUnlock()
 *
 * @grantable Yes
 * @user root
 *
 * @apparmor abstractions/libsynocore/conf
 *
 * @see SLIBCINFOSetKeyValue()
 */
int SLIBCINFORemoveKey(const char *szKey);

/**
 * Check if supports raid group.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportRAIDGroup(void);

/**
 * Copy key value from /etc/synoinfo.conf to tmp, and make a file whose name is the same as the key value
 *
 * @param[in] szKey the key value that we want to copy to tmp
 *
 * @retval 0 On success
 * @retval -1 On error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCInfoCopyKeyValToTmp(const char *szKey);

/**
 * Get key value from /tmp/@key, which is to prevent from annonying disk
 *
 * @param[in] szKey the key that we want to Get from tmp
 * @param[out] szBuf the value we got
 * @param[in] leng the length of return buffer size
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCInfoGetKeyValFromTmp(const char *szKey, char *szBuf, int leng);

/**
 * Get cache or conf from /etc.default/synoinfo.conf for this model is support advance ha or not.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportDualhead(void);

/**
 * To get disk count.
 *
 * @note Please never call LNXSDK in these Max function, unless raidtool don't use them
 *
 * @retval 0 Error
 * @retval >0 The value of maxdisks in /etc.defaults/synoinfo.conf
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMaxSysRaidDiskGet(void);

/**
 * Get cache or conf from /etc.default/synoinfo.conf for this model is support advance ha or not.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportESata(void);

/**
 * Get synobios value to decide if it's vDSM env.
 *
 * @retval TRUE if value of synobios is kvmx64.
 * @retval FALSE otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCIsVDSM(void);

/**
 * Get c2_dsm value to decide if it's cDSM env.
 *
 * @retval TRUE if value of c2_dsm is yes.
 * @retval FALSE otherwise.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCIsCDSM(void);

/**
 * Determine is this model support system RAID customization by max disk count or dualhead.
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportSysRaidCustomization(void);

/**
 * Get cache or conf from /etc.default/synoinfo.conf for this model is support advance ha or not.
 *
 * @retval TRUE DR is running.
 * @retval FALSE DR is not running.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCIsSystemDRRunning(void);

/**
 * Check buzzer support from default synoinfo
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support, default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportBuzzer(void);

/**
 * Check LED brightness adjustment support from default synoinfo
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support, default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportLEDBrightnessAdjust(void);

/**
 * check if dynamic adjust system partition is supported
 *
 * @retval TRUE Supports.
 * @retval FALSE Does not support, default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportSysAdjust(void);

/**
 * check if performance event is supported
 * @retval TRUE Supports.
 * @retval FALSE Does not support, default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportPerfEvent(void);

/**
 * Check NVME support
 *
 * @retval TRUE  Supports.
 * @retval FALSE Does not support. Default value.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSupportNVMe(void);
/**
 * @}
 */
