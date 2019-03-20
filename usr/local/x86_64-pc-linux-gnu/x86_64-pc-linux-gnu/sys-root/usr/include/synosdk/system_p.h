/**
 * @addtogroup SYSTEM
 *
 * @{
 */

/**
 * Gets Booting stage.
 *
 * @return  Boot stage.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) SYNO_BOOT_SEQ SYNOSystemGetBootStep(void);

/**
 * Get system memory info: total, free, buffers, cached
 * from /proc/meminfo
 *
 * @param[in] pMemInfo  The memory info to get.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOSysMemInfoGet(MEM_INFO *pMemInfo);

/**
 * Get Bit based on cache file or
 * current system.
 *
 * @param[in]   kernelInfo   get kernel image info.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOKernelInfoGet(KERNEL_INFO *kernelInfo);

/**
 * To check the kernel version is newer
 * than given.
 *
 * @param[in]   kernel_version   kernel version
 * @param[in]   patch_level      kernel patch level
 * @param[in]   sub_level        kernel sub level
 *
 * @retval   TRUE newer than input
 * @retval   FALSE older than input or error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_2) BOOL SYNOKernelVersionCheck(int kernel_version, int patch_level, int sub_level);

/**
 * Get Physical Memory size in KB.
 *
 * @retval  0      error, get physical memory failed.
 * @retval  >=0   total physical memory size in KB
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_3) unsigned int SLIBSystemPhysMemSizeGet(void);

/**
 * This function is used to check if the module @p szModuleName has been removed before
 *
 * @param[in]   szModuleName   The module name to check.
 *
 * @retval   -1 error when open/read the file "/proc/modules"
 * @retval    0 module has been removed before
 * @retval    1 module exist
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNOCheckModule(const char * szModuleName);

/**
 * Get first synology vender mac address
 * the first vender mac is store in /proc/sys/kernel/syno_mac_address1
 *
 * @param[out]   macAddr   a pointer to SLIB_VENDER_MAC_ADDR.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_FORMAT_ERROR
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBSystemFirstVenderMacAddrGet(SLIB_VENDER_MAC_ADDR *macAddr);

/**
 * To obtain crypto algorithm list which is supported by hardware acceleration.
 * This function parses the file /proc/synobios/syno_crypto_hw and creates the list.
 *
 * For example:
 *
 * @code
 * > cat /proc/synobios/syno_crypto_hw
 * AES_CBC, 3DES_CBC, SHA1_HMAC, SHA256_HMAC, MD5_HMAC
 * @endcode
 *
 * The output list would be:
 *
 * @code
 * ["AES_CBC", "3DES_CBC", "SHA1_HMAC", "SHA256_HMAC", "MD5_HMAC"]
 * @endcode
 *
 * @param[out]   ppslHwCrypto   The string list of hw crypto algorithms
 *
 * @retval    -1 fail
 * @retval   >=0 the length of the output list
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_2) int SYNOSystemHardwareCryptoGet(PSLIBSZLIST* ppslHwCrypto);

/**
 * @}
 */
