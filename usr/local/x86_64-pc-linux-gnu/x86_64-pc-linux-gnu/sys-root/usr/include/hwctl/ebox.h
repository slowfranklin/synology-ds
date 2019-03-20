/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_HWCTL_EBOX_H_
#define __SYNO_HWCTL_EBOX_H_

#include <sys/types.h>
#include <linux/limits.h>

#include <synobios/synobios.h>
#include <synocore/synotype.h>
#include <synocore/list.h>

__BEGIN_DECLS;
#define	EBOX_BUF_SIZE	32
#define	EBOX_DISK_PATH_BUF_SIZE	128
#define SYNO_DX5		"Synology-DX5"
#define SYNO_DX510		"Synology-DX510"
#define SYNO_DX513		"Synology-DX513"
#define SYNO_RX4		"Synology-RX4"
#define SYNO_RX410		"Synology-RX410"
#define SYNO_RX413		"Synology-RX413"
#define SYNO_DXC		"Synology-DX1211"
#define SYNO_RXC		"Synology-RX1211"
#define SYNO_RXCRP		"Synology-RX1211rp"
#define SYNO_RX1214		"Synology-RX1214"
#define SYNO_RX1217		"Synology-RX1217"
#define SYNO_RX1214RP	"Synology-RX1214rp"
#define SYNO_RX1217RP	"Synology-RX1217rp"
#define SYNO_DX213		"Synology-DX213"
#define SYNO_RX415		"Synology-RX415"
#define SYNO_DX1215		"Synology-DX1215"
#define SYNO_DX517		"Synology-DX517"
#define SYNO_NOT_REC	"Unknown"
#define SZ_SYNOLOGY_PREFIX "Synology-"

#define EBOX_DISK_PATH_PREFIX	"/dev/"
#define EBOX_PORT_NUM_MAX	4
#define EBOX_UNIQUE_ID_KEY "EUnitModel"
#define EBOX_DISKNAME_KEY  "EUnitDisks"

#define EBOX_3XXX_IS_RP1_FAILED(x)      (0 == (x&(1<<5)))
#define EBOX_3XXX_IS_RP2_FAILED(x)      (0 == (x&(1<<6)))

#define SET_PSU_STATUS(stat, psu) (stat |= (1 << (psu - 1)))
#define GET_PSU_STATUS(stat, psu) ((stat >> (psu - 1)) & 1 )

#define EBOX_9705_RW_CTL(read, write)	((read << 9) | (write << 8))

#define EUNIT_IN_EH 0xff

#define EBOX_INFO_FILENAME_PREFIX "/tmp/eunitinfo_"
/**
 *  This is instruction enum set
 */ 
typedef enum _tag_EBOX_GPIO {
	/* issue command */
	EBOX_CMD_ISSUE		=	0x0,

	/* get information for chip 3726/3826 */
	EBOX_FAN_STATUS		=	0x1,
	EBOX_UNIQUE_ID		=	0x2,
	EBOX_HDD_LED_STATUS	=	0x3,
	EBOX_SYSTEM_STATUS	=	0x4,
	EBOX_RAID_LED_STATUS	=	0x5,
	EBOX_XXC_SLAVE_HDD_LED_STATUS	=	0x6,
	EBOX_XXC_MASTER_FAN_STATUS =    0x6,

	/* get information for chip 9705 */
	EBOX_9705_START				=	0x10,
	EBOX_9705_UNIQUE_ID			=	0x10,
	EBOX_9705_HDD_LED_STATUS	=	0x11,
	EBOX_9705_FAN_STATUS		=	0x12,
	EBOX_9705_SYSTEM_STATUS		=	0x13,
	EBOX_9705_SYSTEM_CTL		=	0x14,
	EBOX_9705_END				=	0x1f,

	/* add other chips' instruction set here */

	/* command error */
	EBOX_CMD_ERR				=	0xff,
} EBOX_GPIO;

/**
 * This is the ebox led instruction set
 */
typedef enum _tag_EBOX_LED {
	/* RAID Ready */
	EBOX_LED_RAID_READY_OFF,
	EBOX_LED_RAID_READY_BLINKING_GREEN,
	EBOX_LED_RAID_READY_SOLID_GREEN,

	/* Disk status */
	EBOX_LED_DISK_STATUS_GREEN,
	EBOX_LED_DISK_STATUS_YELLOW,

	/* RAID Ready */
	EBOX_LED_RAID_READY_SOLID_YELLOW,
} EBOX_LED;

/** 
 * This class is used to control port multiplier 
 */
typedef struct _tag_EBOX_HANDLE {
	/* sysfs of gpio path; /sys/class/scsi/scsi_host?/syno_pm_gpio */
	char szGPIOSysfs[PATH_MAX];

	/* sysfs path of host info; /sys/class/scsi/scsi_host?/syno_pm_info */
	char szHostInfoSysfs[PATH_MAX];

	/* physical port number , zero base */
	unsigned int portIndex;

	/* semaphore id. eliminate from overuse the semget while multi-task  */
	int semid;

	/* tid, just for debug use */
	pid_t tid;

	/* List of Chip Handlers*/
	struct _tag_EBOX_HANDLE *pHandleList;

	/**
	 * Encoding gpio command. This is optional.
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param gpio    [IN] The raw gpio data from below functions 
	 *  
	 * @return encode result. 
	 *  
	 * @see SYNOEBoxGPIOInfoSet
	 */
	EBOX_GPIO (*EncodeCmd)(struct _tag_EBOX_HANDLE *pHandle, EBOX_GPIO gpio);

	/**
	 * Encoding gpio data. This is optional.
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param gpio    [IN] The raw gpio data from below functions 
	 *  
	 * @return encode result. 
	 *  
	 * @see SYNOEBoxGPIOInfoSet
	 */
	EBOX_GPIO (*EncodeData)(struct _tag_EBOX_HANDLE *pHandle, EBOX_GPIO gpio);

	/**
	 * Read GPIO data.
	 * The read machanism may be different among different models.
	 * Refer to HW CPLD spec and design the corresponding read flow.
	 * You may need to design EncodeCmd and EncodeData too.
	 *
	 * @param pHandle     [IN]  Chip handle. Should not be NULL.
	 * @param gpio        [IN]  The input gpio. You could design the format you want.
	 * @param pResultGpio [OUT] The corresponding gpio result.
	 *
	 * @return TRUE on sucess, FALSE otherwise.
	 */
	BOOL (*ReadGpio)(struct _tag_EBOX_HANDLE *pHandle, const EBOX_GPIO gpio, EBOX_GPIO *pResultGpio);

	/**
	 * Write GPIO data.
	 * The write machanism may be different among different models.
	 * Refer to HW CPLD spec and design the corresponding write flow.
	 * You may need to design EncodeCmd and EncodeData too.
	 *
	 * @param pHandle [IN] Chip handle. Should not be NULL.
	 * @param gpio    [IN] The input gpio. You could design the format you want.
	 *
	 * @return TRUE on sucess, FALSE otherwise.
	 */
	BOOL (*WriteGpio)(struct _tag_EBOX_HANDLE *pHandle, const EBOX_GPIO gpio);

	/**
	 * query the power status of result_gpio
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param pInput_gpio
	 *                [IN] If caller provide this, we would use
	 *                     it instead of send a new gpio command.
	 * 
	 * @return 1: Fan error
	 *          0:Fan fine. If the power not on, fan is always fine
	 *          -1: fail
	 */
	int (*IsPowerOn)(struct _tag_EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);

	/**
	 * query the fan status of result_gpio.
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param pInput_gpio
	 *                [IN] If caller provide this, we would use
	 *                     it instead of send a new gpio command.
	 * @return 1: Fan error
	 *         0:Fan fine. If the power not on, fan is always fine
	 *         -1: fail
	 */
	int (*IsFanErr)(struct _tag_EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);

	/**
	 * query the fan speed of result_gpio.
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * 
	 * @return FAN_SPEED default is OFF if the there has some err 
	 *         while get status
	 *  
	 * @see hwctl/external.h
	 */
	FAN_SPEED (*FanSpeedGet)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * query the unique of result_gpio
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * 
	 * @return the Synology unoque of port multiplier
	 *  
	 */
	char *(*UniqueGet)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * issue power request
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param poweron [IN] Indicate the action is power on or off 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*PowerCTL)(struct _tag_EBOX_HANDLE *pHandle, BOOL poweron);

	/**
	 * raid led control
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param led_op  [IN] Indicate the action of led
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*RaidLedCTL)(struct _tag_EBOX_HANDLE *pHandle, EBOX_LED led_op);

	/**
	 * Disk led control
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param led_op  [IN] Indicate the action of led 
	 * @param led_idx [IN] Indicate the target port  
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*DiskStatLedCTL)(struct _tag_EBOX_HANDLE *pHandle, EBOX_LED led_op, unsigned int led_idx);

	/**
	 * Disk led control. Set all led to specify status. main for 
	 * manutild 
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param led_op  [IN] Indicate the action of led 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*DiskStatLedAllCTL)(struct _tag_EBOX_HANDLE *pHandle, EBOX_LED led_op);

	/**
	 * Fan control
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param fan_op  [IN] Indicate the action of fan 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*FanCTL)(struct _tag_EBOX_HANDLE *pHandle, FAN_SPEED fan_op);

	/**
	 * Vendor Name get
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param szDest  [IN] The result buffer. Should not be NULL.
	 * @param len     [IN] The len of szDest. Should greater than 0.
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*VendorGet)(struct _tag_EBOX_HANDLE *pHandle, char *szDest, const int len);

	/**
	 * Device ID get
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * @param szDest  [IN] The result buffer. Should not be NULL.
	 * @param len     [IN] The len of szDest. Should greater than 0.
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*DeviceIDGet)(struct _tag_EBOX_HANDLE *pHandle, char *szDest, const int len);

	/**
	 * Get the status of redundant power units
	 *
	 * @param pHandle  [IN] chip handle. Should not be NULL.
	 *        pPSUStat [OUT] The bit map of redundant power status,
	 *                       bit [n...0] stands for power [(n-1)...1].
	 *                       0 is failed, 1 is ok.
	 *
	 * @return >0: supporting redundants power,
	 *             the number of working power units.
	 *          0: no redundant power units.
	 *         -1: failed
	 */
	int (*RedundantPowerStatGet)(struct _tag_EBOX_HANDLE *pHandle, int *pPSUStat);

	/**
	 * Disk Path get
	 * 
	 * @param pHandle        [IN] chip handle. Should not be NULL. 
	 * @param szDiskPathBuf  [IN] The result buffer. Should not be 
	 *                            NULL.
	 * @param len            [IN] The len of szDest. Should at least
	 *                            more than EBOX_DISK_PATH_BUF_SIZE.
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*DiskPathGet)(struct _tag_EBOX_HANDLE *pHandle, char *szDiskPathBuf, const int len);

	/**
	 * Device status get. 
	 * 
	 * @param pHandle        [IN] chip handle. Should not be NULL. 
	 * @param pblProcess     [OUT] eh process information. Should 
	 *                          not be NULL.
	 * 
	 * @return  TRUE Operation success 
	 * 			FALISE Operation fail 
	 *  
	 */
	BOOL (*IsEHProcessing)(struct _tag_EBOX_HANDLE *pHandle, BOOL *pblProcess);

	/**
	 * Query the whether port multiplier is remain in system
	 * 
	 * @param pHandle        [IN] chip handle. Should not be NULL. 
	 * 
	 * @return  TRUE  port multiplier is remain in system
	 * 			FALISE port multiplier is not in the system
	 *  
	 */
	BOOL (*IsPMPresent)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Max Disk Count Get
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 
	 * 
	 * @return >0 is the max disk number. <0 is fail
	 *  
	 */
	int (*MaxDiskGet)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Fan Number Get
	 *
	 * @param pHandle [IN] chip handle. Sould not be NULL.
	 *
	 * @return >0 is the fan number that the unit can detect. <0 is fail
	 */
	int (*FanNumberGet)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Wait function of this chip. Used to synchronize operation
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 	 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*Wait)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Signal function of this chip. Used to synchronize operation
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 	 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*Signal)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Set the buzzer to mute
	 * 
	 * @param pHandle [IN] chip handle. Should not be NULL. 	 
	 * 
	 * @return TRUE on success FALISE on fail
	 *  
	 */
	BOOL (*PSUBuzzerMute)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * disable power button to avoid shutdown EUnit
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param iPowerDisable  [IN] Indicate whether power button disable or not
	 *
	 * @return TRUE on success FALISE on fail
	 *
	 */
	BOOL (*PowerBtnDisableSet)(struct _tag_EBOX_HANDLE *pHandle, const int iPowerDisable);

	/**
	 * Query whether the power button is disable
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 *
	 * @return 1: power button disabled, if eh is processing, power always disabled,
	 *         0: power button enabled.
	 *         -1: fail
	 */
	int (*IsPowerBtnDisabled)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * check if eunit supports power button disability
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 *
	 * @return 1: support
	 *         0: not support
	 *         -1: fail
	 */
	int (*IsSupportPowerBtnDisable)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Query whether the backplane switch mode
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 *
	 * @return 1: Default Mode,if eh is processing, always return default mode,
	 *         0: Manual Mode,
	 *         -1: fail
	 *         -2: eh is processing
	 */
	int (*SwitchModeGet)(struct _tag_EBOX_HANDLE *pHandle);

	/**
	 * Deep sleep led control
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param isDeepSleep [IN] Indicate the action of deep sleep led
	 *
	 * @return TRUE on success FALSE on fail
	 *
	 */
	BOOL (*DeepSleepLedCTL)(struct _tag_EBOX_HANDLE *pHandle, BOOL isDeepSleep);

	/**
	 * Disk Led Light on control
	 *
	 * @param pHandle [IN] chip handle. Should not be NULL.
	 * @param isDiskLEDLightOn [IN] Indicate the action of disk led light
	 *
	 * @return TRUE on success FALSE on fail
	 *
	 */
	BOOL (*DiskLedLightCTL)(struct _tag_EBOX_HANDLE *pHandle, BOOL isDiskLEDLightOn);

} EBOX_HANDLE;

/** 
 *  EBOX info.
 */
typedef struct _tag_EBOX_INFO {
	/* Port Multiplier vendor id */
	char szVendorName[EBOX_BUF_SIZE];

	/* Port Multiplier chip id */
	char szDeviceID[EBOX_BUF_SIZE];

	/* sysfs prefix path of control; /sys/class/scsi/scsi_host?/ */
	char szPrefixSysfs[PATH_MAX];

	/* physical port number , zero base */
	unsigned int portIndex;	

	/* Unit index, one base*/
	unsigned int unitIndex;
	
	/* Is deep sleep support? 0: not support, 1: support */
	int iIsSupportDeepSleep;

	/* devices path which derived from ebox */
	PSLIBSZLIST pDiskPath;

	/* low level driver for ebox */
	EBOX_HANDLE handle;
} EBOX_INFO;

/**
 * Simply a linked list for Ebox
 */
typedef struct _tag_EBOX_INFO_LIST {
	EBOX_INFO eboxInfo;
	struct _tag_EBOX_INFO_LIST *pNext;
} EBOX_INFO_LIST;

/* ebox_info_free.c */
void SYNOEBoxInfoFree(EBOX_INFO *pEboxInfo);
/* ebox_3xxx_all_input_info_get.c */
BOOL SYNOEBox3xxxAllInputInfoGet(EBOX_HANDLE *pHandle, EBOX_GPIO *pResult_gpio);
/* ebox_3xxx_encode_cmd.c */
EBOX_GPIO SYNOEBox3xxxEncodeCmd(EBOX_HANDLE *pHandle, EBOX_GPIO gpio);
/* ebox_3xxx_fan_control.c */
BOOL SYNOEBox3xxxFanCTL(EBOX_HANDLE *pHandle, FAN_SPEED fan_op);
/* ebox_3xxx_fanspeed_get.c */
FAN_SPEED SYNOEBox3xxxFanSpeedGet(EBOX_HANDLE *pHandle);
/* ebox_3xxx_is_fan_err.c */
int SYNOEBox3xxxIsFanErr(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_3xxx_is_power_on.c */
int SYNOEBox3xxxIsPowerOn(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_3xxx_led_disk_status_all_control.c */
BOOL SYNOEBox3xxxLedDiskStatAllCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_3xxx_led_disk_status_control.c */
BOOL SYNOEBox3xxxLedDiskStatCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op, unsigned int led_idx);
/* ebox_3xxx_led_raid_ready_control.c */
BOOL SYNOEBox3xxxLedRaidReadyCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_3xxx_power_control.c */
BOOL SYNOEBox3xxxPowerCTL(EBOX_HANDLE *pHandle, BOOL blPoweron);
/* ebox_3xxx_psu_buzzer_mute.c */
BOOL SYNOEBox3xxxPSUBuzzerMute(EBOX_HANDLE *pHandle);
/* ebox_3xxx_redandant_power_stat_get.c */
int SYNOEBox3xxxRedundantPowerStatGet(EBOX_HANDLE *pHandle, int *pPSUStat);
/* ebox_3xxx_semaphore_get.c */
BOOL SYNOEBox3xxxSemGet(EBOX_HANDLE *pHandle, int *pSemid);
/* ebox_3xxx_signal.c */
BOOL SYNOEBox3xxxSignal(EBOX_HANDLE *pHandle);
/* ebox_3xxx_unique_get.c */
BOOL SYNOEUnit3xxxChip(const char *szDeviceID);
char *SYNOEBox3xxxUniqueGet(EBOX_HANDLE *pHandle);
/* ebox_3xxx_wait.c */
BOOL SYNOEBox3xxxWait(EBOX_HANDLE *pHandle);
/* ebox_all_host_info_get.c */
BOOL SYNOEBoxAllHostInfoGet(EBOX_INFO *pEboxInfo);
/* ebox_device_id_fill.c */
BOOL SYNOEBoxDeviceIDFill(EBOX_INFO *pEboxInfo, char *szDevID, const int len);
/* ebox_device_is_ebox.c */
BOOL SYNOEBoxSysfsDevIs(const char *szSysfsPrefix);
/* ebox_disk_count_get.c */
int SYNOEBoxMaxDiskGet(EBOX_HANDLE *pHandle);
/* ebox_disk_path_fill.c */
BOOL SYNOEBoxDiskPathFill(EBOX_INFO *pEboxInfo, char *szBuf, const int len);
/* ebox_disk_set_standby.c */
int SYNOEBoxDiskSetStandby(EBOX_INFO *pEboxInfo);
int SYNOEBoxDeepSleep(EBOX_INFO *pEboxInfo);
/* ebox_fan_number_get.c */
int SYNOEBoxFanNumberGet(EBOX_HANDLE *pHandle);
/* ebox_gpio_info_get.c */
BOOL SYNOEBoxGPIOInfoGet(EBOX_GPIO gpio, EBOX_HANDLE *pHandle, EBOX_GPIO *pResult_gpio, BOOL blLockNeed);
/* ebox_gpio_info_set.c */
BOOL SYNOEBoxGPIOInfoSet(BOOL blInfoGet, EBOX_HANDLE *pHandle, EBOX_GPIO input_gpio, BOOL blLockNeed);
/* ebox_handle_get.c */
BOOL SYNOEBoxHandleGet(const char *szSysfsPrefix, EBOX_HANDLE *pHandle, unsigned int portIndex);
/* ebox_handle_list_free.c */
void SYNOEBoxHandleListFree(EBOX_HANDLE *pEBoxHandleList);
/* ebox_host_info_device_emid_get.c */
BOOL SYNOEBoxHostInfoDeviceEMIDGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_host_info_device_id_get.c */
BOOL SYNOEBoxHostInfoDeviceIDGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_host_info_device_unique_get.c */
BOOL SYNOEBoxHostInfoDeviceUniqueGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_host_info_disk_path_get.c */
BOOL SYNOEBoxHostInfoDiskPathGet(EBOX_HANDLE *pHandle, char *szDiskPathBuf, const int len);
/* ebox_host_info_error_process_get.c */
BOOL SYNOEBoxHostInfoEHProcessGet(EBOX_HANDLE *pHandle, BOOL *pblProcess);
/* ebox_host_info_get.c */
BOOL SYNOEBoxHostInfoGet(char *szInfoKey, const char *szHostInfoSysfs, char *szBuf, const int length);
/* ebox_host_info_merge.c */
EBOX_INFO_LIST *SYNOEBoxHostInfoMerge(EBOX_INFO_LIST *pEBoxInfoList);
/* ebox_host_info_portno_get.c */
BOOL SYNOEBoxHostInfoDevicePortNOGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_host_info_satahost_get.c */
BOOL SYNOEBoxHostInfoDeviceSataHostGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_host_info_vendor_name_get.c */
BOOL SYNOEBoxHostInfoVendorNameGet(EBOX_HANDLE *pHandle, char *szDest, const int len);
/* ebox_info_enum.c */
int SYNOEBoxInfoEnum(EBOX_INFO_LIST **ppEBoxInfoList);
/* ebox_info_enum_free.c */
void SYNOEBoxInfoEnumFree(EBOX_INFO_LIST *pEBoxInfoList);
/* ebox_info_get.c */
BOOL SYNOEBoxInfoGet(const char *szSCSIHostName, EBOX_INFO *pEboxInfo);
/* ebox_is_active.c */
BOOL SYNOEBoxIsActive(const int portIndex);
/* ebox_is_pm_present.c */
BOOL SYNOEBoxIsPMPresent(EBOX_HANDLE *pHandle);
/* ebox_is_poweron.c */
BOOL SYNOEBoxIsPoweron(EBOX_INFO *pEBox);
/* ebox_power_control.c */
BOOL SYNOEBoxPowerControl(unsigned int portIndex, BOOL blPoweron);
/* ebox_unit_disk_count_get.c */
int SYNOEBoxUnitMaxDiskGet(EBOX_HANDLE *pHandle);
/* ebox_unit_disk_path_get.c */
BOOL SYNOEBoxUnitDiskPathGet(EBOX_HANDLE *pHandle, char *szDiskPathBuf, const int len);
/* ebox_unit_fan_control.c */
BOOL SYNOEBoxUnitFanCTL(EBOX_HANDLE *pHandle, FAN_SPEED fan_op);
/* ebox_unit_fan_number_get.c */
int SYNOEBoxUnitFanNumberGet(EBOX_HANDLE *pHandle);
/* ebox_unit_fanspeed_get.c */
FAN_SPEED SYNOEBoxUnitFanSpeedGet(EBOX_HANDLE *pHandle);
/* ebox_unit_handle_get.c */
BOOL SYNOEBoxUnitHandleGet(const char *szSysfsPrefix, EBOX_HANDLE *pHandle, unsigned int portIndex);
/* ebox_unit_is_fan_err.c */
int SYNOEBoxUnitIsFanErr(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_unit_is_power_on.c */
int SYNOEBoxUnitIsPowerOn(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_unit_led_disk_status_all_control.c */
BOOL SYNOEBoxUnitLedDiskStatAllCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_unit_led_disk_status_control.c */
BOOL SYNOEBoxUnitLedDiskStatCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op, unsigned int led_idx);
/* ebox_unit_led_raid_ready_control.c */
BOOL SYNOEBoxUnitLedRaidReadyCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_unit_power_control.c */
BOOL SYNOEBoxUnitPowerCTL(EBOX_HANDLE *pHandle, BOOL blPoweron);
/* ebox_unit_psu_buzzer_mute.c */
BOOL SYNOEBoxUnitPSUBuzzerMute(EBOX_HANDLE *pHandle);
/* ebox_unit_redundant_power_stat_get.c */
int SYNOEBoxUnitRedundantPowerStatGet(EBOX_HANDLE *pHandle, int *pPSUStat);
/* ebox_unit_signal.c */
BOOL SYNOEBoxUnitSignal(EBOX_HANDLE *pHandle);
/* ebox_unit_unique_get.c */
char *SYNOEBoxUnitUniqueGet(EBOX_HANDLE *pHandle);
/* ebox_unit_wait.c */
BOOL SYNOEBoxUnitWait(EBOX_HANDLE *pHandle);
/* ebox_vendor_name_fill.c */
BOOL SYNOEBoxVendorNameFill(EBOX_INFO *pEboxInfo, char *szVendor, const int len);
/* ebox_3xxx_which_fan_err.c */
int SYNOEBox3xxxWhichFanErr(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_deep_sleep_fill.c */
BOOL SYNOEBoxDeepSleepFill(EBOX_INFO *pEboxInfo, char *szDeepSleep, const int len);
/* ebox_unit_unique_get_by_devpath_inner.c */
int SYNOEBoxUnitUniqueGetByDevPathInner(const char *szDevPath, char *szUnique, const int len, EBOX_INFO_LIST *pList_head);
/* ebox_unit_unique_get_by_devpath.c */
int SYNOEBoxUnitUniqueGetByDevPath(const char *szDevPath, char *szUnique, const int len);
/* ebox_unit_info_error_process_get.c */
BOOL SYNOEBoxUnitInfoEHProcessGet(EBOX_HANDLE *pHandle, BOOL *pblEBoxIsProcessing);
/* ebox_unit_power_btn_disable_set.c */
BOOL SYNOEBoxUnitPowerBtnDisableSet(EBOX_HANDLE *pHandle, const int iPowerDisable);
/* ebox_unit_is_power_btn_disabled.c */
int SYNOEBoxUnitIsPowerBtnDisabled(EBOX_HANDLE *pHandle);
/* ebox_3826_power_btn_disable_set.c */
BOOL SYNOEBox3826PowerBtnDisableSet(EBOX_HANDLE *pHandle, const int iPowerDisable);
/* ebox_3826_is_powerbtn_disabled.c */
int SYNOEBox3826IsPowerBtnDisabled(EBOX_HANDLE *pHandle);
/* ebox_unit_is_support_power_btn_disable.c */
int SYNOEBoxUnitIsSupportPowerBtnDisable(EBOX_HANDLE *pHandle);
/* ebox_3826_switch_mode_get.c */
int SYNOEBox3826SwitchModeGet(EBOX_HANDLE *pHandle);
/* ebox_unit_switch_mode_get.c */
int SYNOEBoxUnitSwitchModeGet(EBOX_HANDLE *pHandle);
/* ebox_unit_read_gpio.c */
BOOL SYNOEBoxUnitReadGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio, EBOX_GPIO *pResultGpio);
/* ebox_unit_write_gpio.c */
BOOL SYNOEBoxUnitWriteGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio);
/* ebox_write_gpio_core.c */
BOOL SYNOEBoxWriteGpioCore(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio);
/* ebox_3xxx_read_gpio.c */
BOOL SYNOEBox3xxxReadGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio, EBOX_GPIO *pResultGpio);
/* ebox_3xxx_write_gpio.c */
BOOL SYNOEBox3xxxWriteGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio);
/* ebox_9705_read_gpio.c */
BOOL SYNOEBox9705ReadGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio, EBOX_GPIO *pResultGpio);
/* ebox_9705_write_gpio.c */
BOOL SYNOEBox9705WriteGpio(EBOX_HANDLE *pHandle, const EBOX_GPIO gpio);
/* ebox_9705_unique_get.c */
BOOL SYNOEUnit9705Chip(const char *szDeviceID);
char *SYNOEBox9705UniqueGet(EBOX_HANDLE *pHandle);
/* ebox_unit_encode_cmd.c */
EBOX_GPIO SYNOEBoxUnitEncodeCmd(EBOX_HANDLE *pHandle, EBOX_GPIO gpio);
/* ebox_9705_encode_cmd.c */
EBOX_GPIO SYNOEBox9705EncodeCmd(EBOX_HANDLE *pHandle, EBOX_GPIO gpio);
/* ebox_9705_fanspeed_get.c */
FAN_SPEED SYNOEBox9705FanSpeedGet(EBOX_HANDLE *pHandle);
/* ebox_9705_which_fan_err.c */
int SYNOEBox9705WhichFanErr(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_9705_fan_control.c */
BOOL SYNOEBox9705FanCTL(EBOX_HANDLE *pHandle, FAN_SPEED fan_op);
/* ebox_9705_is_power_on.c */
int SYNOEBox9705IsPowerOn(EBOX_HANDLE *pHandle, EBOX_GPIO *pInput_gpio);
/* ebox_9705_power_control.c */
BOOL SYNOEBox9705PowerCTL(EBOX_HANDLE *pHandle, BOOL blPoweron);
/* ebox_9705_led_raid_ready_control.c */
BOOL SYNOEBox9705LedRaidReadyCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_9705_led_disk_status_control.c */
BOOL SYNOEBox9705LedDiskStatCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op, unsigned int led_idx);
/* ebox_9705_led_disk_status_all_control.c */
BOOL SYNOEBox9705LedDiskStatAllCTL(EBOX_HANDLE *pHandle, EBOX_LED led_op);
/* ebox_9705_is_powerbtn_disabled.c */
int SYNOEBox9705IsPowerBtnDisabled(EBOX_HANDLE *pHandle);
/* ebox_9705_power_btn_disable_set.c */
BOOL SYNOEBox9705PowerBtnDisableSet(EBOX_HANDLE *pHandle, const int iPowerDisable);
/* ebox_9705_switch_mode_get.c */
int SYNOEBox9705SwitchModeGet(EBOX_HANDLE *pHandle);
/* ebox_9705_psu_buzzer_mute.c */
BOOL SYNOEBox9705PSUBuzzerMute(EBOX_HANDLE *pHandle);
/* ebox_9705_redandant_power_stat_get.c */
int SYNOEBox9705RedundantPowerStatGet(EBOX_HANDLE *pHandle, int *pPSUStat);
/* ebox_unit_deep_sleep_led_ctl.c */
BOOL SYNOEBoxUnitDeepSleepLedCTL(EBOX_HANDLE *pHandle, BOOL isDeepSleep);
/* ebox_9705_deep_sleep_led_ctl.c */
BOOL SYNOEBox9705DeepSleepLedCTL(EBOX_HANDLE *pHandle, BOOL isDeepSleep);
/* ebox_unit_deep_sleep_led_ctl.c */
BOOL SYNOEBoxUnitLedDiskLightCTL(EBOX_HANDLE *pHandle, BOOL isDiskLEDLightOn);
/* ebox_9705_led_disk_ready.c */
BOOL SYNOEBox9705LedDiskLightCTL(EBOX_HANDLE *pHandle, BOOL isDiskLEDLightOn);
/* ebox_support_ebox.c */
BOOL SupportEBox(void);

__END_DECLS;

#endif //__SYNO_HWCTL_EBOX_H_
