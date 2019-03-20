#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/**
 * @addtogroup AHA_CORE
 *
 * @brief The operations of AHA_CORE.
 *
 * @{
 */

// Public haeder
#ifndef __SYNO_AHA_CORE_H
#define __SYNO_AHA_CORE_H

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <time.h>

__BEGIN_DECLS;

/*
 * If MY_DEF_HERE is not defined,
 * libsynoahacore will not be built.
 * It will cause a building failure due to UNDEF reference.
 * So we give it a dummy implement just return the default value
 * when MY_DEF_HERE is not defined.
 */
#ifdef MY_DEF_HERE
#define AHA_FUNCTION_HWDEP(FUNCTION_PROT, DEFAULT_VALUE) FUNCTION_PROT
#else
#define	AHA_FUNCTION_HWDEP(FUNCTION_PROT, DEFAULT_VALUE) static inline FUNCTION_PROT { return DEFAULT_VALUE; }
#endif

#define gettid() syscall(__NR_gettid)

#define AHA_SYNOBOOT3       "/dev/synoboot3"
#define SZ_AHA_HB_IFNAME    "mon.hb0"

#define SZ_AHA_SHADOW_DELIMITER  ":"

#define SZ_AHA_IS_MIGRATE     "migrate"
#define SZD_AHA_DUAL_GLIBC    "/dual_glibc"
#define SZ_AHA_OVS_IF_PREFIX  "ovs_"
#define SZF_AHA_CHROOT        "/usr/sbin/chroot"
#define SZF_AHA_BIN_SYNOAHA   "/usr/syno/synoaha/bin/synoaha"

#define MAX_NOTIFY_HASH_PAIR_LIMIT 10
#define MAX_LEN_OF_NOTIFY_KEY      256
#define MAX_LEN_OF_NOTIFY_VALUE    256
#define AHA_MAX_RUNNING_TASK_LENGTH 1024

// These defines is used in aha_boot_check_daemon_version.c.
// Please make sure boot daemon can work if need to modify
#define AHA_MAX_BUILD_VERSION_SIZE     32
#define AHA_MAX_SMALLFIX_VERSION_SIZE  4
#define AHA_MAX_DAEMON_VERSION_SIZE    64
#define AHA_NEW_DAEMON_VERSION_FORMAT  "%d0%03d"
#define AHA_OLD_DAEMON_VERSION_FORMAT  "%s0%s"
#define AHA_FLASH_VERSION_LENGTH       AHA_MAX_DAEMON_VERSION_SIZE
#define AHA_NEW_FLASH_VERSION_FORMAT   AHA_NEW_DAEMON_VERSION_FORMAT
#define AHA_OLD_FLASH_VERSION_FORMAT   AHA_OLD_DAEMON_VERSION_FORMAT

// use in ha.conf and ha.status and ha.hwinfo
// this enum be used by UI,
// !!! Do not change its number !!!
typedef enum {
	AHA_NODE_ROLE_UNKNOWN = 0x00,
	AHA_NODE_ROLE_HA      = 0x01,
	AHA_NODE_ROLE_LOCAL   = 0x02,
	AHA_NODE_ROLE_REMOTE  = 0x04,
	AHA_NODE_ROLE_HOST0   = 0x08,
	AHA_NODE_ROLE_HOST1   = 0x10,
} AHA_NODE_ROLE;

typedef struct {
	int logClass;
	int eventType;
	unsigned long eventID;
	char szArg1[128];
	char szArg2[128];
	char szArg3[128];
	char szArg4[128];
	char szSerialNumber[MAX_SN_SIZE];
} AHALogData;

typedef struct {
	char szKey[MAX_LEN_OF_NOTIFY_KEY];
	char szValue[MAX_LEN_OF_NOTIFY_VALUE];
} AHANotifyHashPair;

typedef struct {
	char szTag[BUFSIZ];
	AHANotifyHashPair rgHashPair[MAX_NOTIFY_HASH_PAIR_LIMIT];
	int iPairCount;
	BOOL blWithBlock;
} AHANotifyData;

// We use the value directly in almost situation,
// UI may be indicate the "active" or "passive" or "active and passive" to do something,
// then use ||
typedef enum {
	AHA_ROLE_UNKNOWN = 0x00,
	AHA_ROLE_ACTIVE  = 0x01,
	AHA_ROLE_PASSIVE = 0x02,
	AHA_ROLE_JUNIOR  = 0x04,
} AHA_ROLE_STATUS;

typedef struct {
	BOOL blIsHard;
	char szRunningTask[AHA_MAX_RUNNING_TASK_LENGTH];
} AHA_HALT_CHECK_RESULT;

/**
 * Get AHA (Custom) Serial Number
 *
 * @param[in]  isCustom  TRUE to get custom SN, FALSE to get SN
 * @param[out] szSerial  The output SN buffer. Should not be @ref NULL.
 * @param[in]  cbSize    The size of @p szSerial
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetSerialNumber(BOOL isCustom, char *szSerial, unsigned int cbSize), -1);

/**
 * Get the original serial number
 *
 * @param[out] szSerial  The output SN buffer. Should not be NULL.
 * @param[in]  cbSize    The size of @p szSerial
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetOriginalSN(char *szSerial, int cbSize), -1);

/**
 * Get the custom serial number
 *
 * @param[out] szSerial  The output SN buffer. Should not be NULL.
 * @param[in]  cbSize    The size of @p szSerial
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetCustomSN(char *szSerial, int cbSize), -1);

/**
 * Get AHA MAC address
 *
 * @param[in]  idx    The index of target interface.
 * @param[out] szMac  The output MAC buffer. Should not be NULL.
 * @param[in]  cbMac  The size of @p szMac.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable N
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetMac(unsigned int idx, char *szMac, unsigned int cbMac), -1);

/**
 * Do AHA upgrade tasks
 *
 * @param[in] szVersion  The upgrade version with format [BuildNum + "0" + SmallfixNum] @n
 *                       e.g. DSM v7608 smallfix 2, szVersion="760802"
 *
 * @retval  0 Success
 * @retval -1 Error
 * @retval -2 Net error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAUpgrade(const char *szVersion), -1);

/**
 * Do AHA upgrade failed tasks
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAUpgradeFail(), -1);

/**
 * Do AHA small update tasks
 *
 * @param[in] szVersion          The upgrade version with format [BuildNum + "0" + SmallfixNum] @n
 *                               e.g. DSM v7608 smallfix 2, szVersion="760802"
 * @param[in] blNeedUpdateFlash  Whether this update need update to flash or not
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHASmallUpdate(const char *szVersion, BOOL blNeedUpdateFlash), -1);

/**
 * Do AHA samll update failed tasks
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHASmallUpdateFail(), -1);

/**
 * Do reboot on passive (or junior) server
 *
 * @note This function must be called on passive (or junior) server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAPassiveReboot(), -1);

/**
 * Do poweroff on passive (or junior) server
 *
 * @note This function must be called on passive (or junior) server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAPassivePoweroff(), -1);

/**
 * Send log data to remote server
 *
 * @note  The remote server must be active server.
 *
 * @param[in] logData  The log data to be sent to remote server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHASendLogToRemote(AHALogData logData), -1);

/**
 * Send notification data to remote server
 *
 * @note  The remote server must be active server.
 *
 * @param[in] pNotifyData  The notification data to be sent to remote server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHASendNotifyDataToRemote(AHANotifyData *pNotifyData), -1);

/**
 * Check if should append SN corresponding to the @p eventID
 *
 * @param[in] eventID  Log event ID. @n
 *                     For example: 0x1110000F  <=>  "CPU overheat: CPU had reached @1°C, shutdown system now."
 *
 * @retval TRUE   Yes
 * @retval FALSE  No
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (BOOL SYNOAHAShouldAppendSNToLog(unsigned long eventID), (BOOL)FALSE);

/**
 * Check if should send notify data to remote
 *
 * @param[in] szTag  Notification tag. @n
 *                   For example: "OverheatShutdownCPU"
 *
 * @retval TRUE   Yes
 * @retval FALSE  No
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (BOOL SYNOAHAShouldSendNotifyDataToRemote(const char *szTag), (BOOL)FALSE);

/**
 * Get role of the local host
 *
 * @return One of AHA role in @ref AHA_ROLE_STATUS enum structure.
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (AHA_ROLE_STATUS SYNOAHAGetLocalRole(), AHA_ROLE_UNKNOWN);

/**
 * Get role of the remote host
 *
 * @return One of AHA role in @ref AHA_ROLE_STATUS enum structure.
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (AHA_ROLE_STATUS SYNOAHAGetRemoteRole(), AHA_ROLE_UNKNOWN);

/**
 * Get is remove alive or not
 *
 * @param[out] blIsAlive  TRUE or FALSE corresponds to remote is alive or not
 *
 * @retval  0 Success to get remote alive status
 * @retval -1 Error
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAIsRemoteAlive(BOOL *blIsAlive), -1);

/**
 * Send buzzer off cfg to remote server
 *
 * @note The remote server must be passive server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHASendBuzzerOffCfgToRemote(), -1);

/**
 * Shut down remote server and wait until remote disconnected on active server.
 *
 * The timeout for waiting remote disconnected is 30 seconds. If remote is not
 * powered on, both shutdown and waiting actions will be skipped.
 *
 * @note This function must be called on active server.
 *
 * @retval  0  Success
 * @retval -1  Other errors
 * @retval -2  Communication error (Sending command failed)
 * @retval -3  Active not ready
 * @retval -4  Wait remote shutdown timeout
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAShutdownRemoteAndWaitDisconnectedOnActive(), -1);

/**
 * Sync password to remote
 *
 * The admin password on active server will be synced to remote and overwrite
 * the original password.
 *
 * @note This function must be called on active server.
 *
 * @retval  0  Success
 * @retval -1  Errors
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHASyncPasswdToRemote(), -1);

/**
 * Adjust the fan speed on remote host.
 *
 * @param[in] szFanSpeed  A string value transfered from one of value in ref@ FAN_CONFIG_TYPE_T enum structure
 * @param[in] cbFanSpeed  The size of @p szFanSpeed
 *
 * @retval  0  Success
 * @retval -1  Errors
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHARemoteFanAdjust(const char *szFanSpeed, int cbFanSpeed), -1);

/**
 * Get AHA overview status
 *
 * Used for System Health Widget
 *
 * @param[out] szStatus  HA status
 * @param[in]  cSize     The size of @p szStatus
 *
 * @return None
 *
 * @grantable N
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (void SYNOAHAGetOverviewStatus(char* szStatus, unsigned int cSize), );

/**
 * Do AHA bonding tasks before bonding enable/disable start
 *
 * In order to prevent failover during enable/disable bonding, this function is
 * used to disable monitoring of every slave in @p szSlaveIFList.
 *
 * @param[in] szSlaveIFList  The slaves of the enabled/disabled bonding @n
 *                           e.g. bond0 with eth0 and eth1, szSlaveIFList="eth0,eth1"
 * @param[in] cbSlaveIFList  The size of @p szSlaveIFList
 *
 * @retval  0  Success
 * @retval -1  Errors
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHABonding(const char *szSlaveIFList, unsigned int cbSlaveIFList), -1);

/**
 * Do AHA bonding done tasks before bonding enable/disable finish
 *
 * If the given @p blSuccess is FALSE, the origianl monitor setting will be
 * restore. In contrast, just pass this function.
 *
 * @param[in] blSuccess  Whether the task of enable/disable bonding is success
 *
 * @retval  0  Success
 * @retval -1  Errors
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHABondingDone(BOOL blSuccess), -1);

/**
 * Get or free the adjust system raid lock.
 *
 * This function will lock the AHA auto system disk adjusting.
 * Use STNOAHAAdjustingSystemRaidLock(pFile, TRUE); to get the lock of system adjusting.
 *
 * @note Must call SYNOAHAAdjustSystemRaidLock(pFile, FALSE) on check system raid end.
 *
 * @param[in,out] ppFile       The file lock for adjust system disk. Should not be NULL.
 * @param[in]     blIsGetLock  TRUE or FALSE corresoponds to get or free the adjust lock.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHAAdjustSystemRaidLock(FILE **ppFile, BOOL blIsGetLock), -1);

/**
 * Ask system to adjust system raid by system raid config.
 *
 * @note This function must be called on active server.
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAAdjustSystemDisk(), -1);

/**
 * Set system disk list to ha.status
 *
 * @note This function must be called on active server.
 *
 * @param[in] pslSysDisks  The system disk list that each element should be a disk path (e.g. /dev/sas1)
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHASetSystemDiskList(const PSLIBSZLIST pslSysDisks), -1);

/**
 * Get system disk list from ha.status
 *
 * @note This function must be called on active server.
 *
 * @param[out] ppslSysDisks  The system disk list that each element should be a disk path (e.g. /dev/sas1)
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable N
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetSystemDiskList(PSLIBSZLIST *ppslSysDisks), -1);

/**
 * Do AHA Bios upgrade tasks before bios upgrade start
 *
 * In the case of active/passive on DSM 6.0 or after, a lock is needed to
 * prevent HB all lost promotion and it will be assigned to @p ppFile.
 * Otherwise, @p ppFile stays unchanged.
 *
 * @param[out] ppFile  The lock to prevent HB all lost promotion
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHABiosUpgradeStart(FILE **ppFile), -1);

/**
 * Do AHA Bios upgrade tasks after bios upgrade finish
 *
 * @param[in] ppFile  The lock to prevent HB all lost promotion
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 *
 * @apparmor abstractions/libsynoahacore
 */
AHA_FUNCTION_HWDEP (int SYNOAHABiosUpgradeEnd(FILE **ppFile), -1);

/**
 * Do AHA reset button presses tasks
 *
 * This function will reset (disable) the monitoring of all interfaces
 *
 * @retval  0 Success
 * @retval -1 Error
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAResetButtonPress(), -1);

__END_DECLS;

#endif

/**
 * @}
 */
