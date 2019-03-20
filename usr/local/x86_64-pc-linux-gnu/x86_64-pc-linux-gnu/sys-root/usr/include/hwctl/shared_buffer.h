#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_HWCTL_SHARED_BUFFER__
#define __SYNO_HWCTL_SHARED_BUFFER__

#include <synocore/synotype.h>
#include <hwctl/disk.h>
#if defined(MY_DEF_HERE)
#include <synosas/enclosure.h>
/**
 * This struct is for LCM enclosure temperature alarm
 */
typedef struct _tag_EncTempList {

	ENCLOSURE_UNIQUE_ID enclosureUnique;

	BOOL				IsTemperatureAlarm;

	struct _tag_EncTempList *pNextNode;
} EncTempList;
#endif

typedef enum _tag_SCEMD_LCM_CLOSE_TYPE {
	LCM_CLOSE_TYPE_NONE,
	LCM_POWEROFF,
	LCM_REBOOT,
	LCM_SAFEMODE,
	LCM_CLOSE_TYPE_MAX,
} SCEMD_LCM_CLOSE_TYPE;

/**
 * This struct is the shared variables between modules.
 */
typedef struct _tag_SHARED_BUFFER_T {
	/**
	 * This variable is used to store new synobios event.
	 */
	SYNOBIOSEVENT  synoEvent;
	/**
	 * This array store the disk leds status.
	 */
	unsigned int*  rguiBitMapLedDisk;
	unsigned int   iBitMapLedDiskLen;

	/**
	 * This variable contains the status of "status led".
	 */
	unsigned int   uiBitMapLedStatus;
	/**
	 * This variable is used to store a UART2 command.
	 */
	char           cUart2Cmd;
	/**
	 * This variable is used to store a CDC ACM command.(for LCM module)
	 */
	char           cCdcAcmCmd;
	/**
	 * This variable is used to indicate whether the "beep stop 
	 * button" of RS408RP has been pressed or not.
	 */
	BOOL           blBtnRPBeepStopPressed:1;
	/**
	 * This variable is used to indicate whether the "beep off"
	 * button of LCM module has been pressed or not.
	 */
	BOOL           blBtnFanFailBeepStopPressed:1;
	/**
	 * This variable indicates whether the disks are in hibernation.
	 */
	BOOL           blDiskInHibernation:1;
	/**
	 * This variable is true if any ebox wakeup.
	 */
	BOOL           blEboxInWakeup:1;
	/**
	 * When this variable is TRUE, it means there are new event
	 * recored in variable "synoEvent".
	 * 
	 * @see synoEvent
	 */
	BOOL           blSynoEventNew:1;
	/**
	 * When this variable is TRUE, there is new UART2 command
	 * stored in the variable "cUart2Cmd".
	 * 
	 * @see cUart2Cmd
	 */
	BOOL           blUart2CmdNew:1;
	/**
	 * When this variable is TRUE, there is new CDC LCM command
	 * stored in the variable "cCdcAcmCmd".
	 *
	 * @see cCdcAcmCmd             */
	BOOL           blCdcAcmCmdNew:1;
	/**
	 * This bool will be true if select timeout, and flase
	 * if there is any event new.
	 *
	 * @see source/lnxscemd-2.0/event_listener.c    */
	BOOL           blSelcetTimeOut:1;
	/**
	 * This bit map variable contains the requests from other
	 * modules, to determine whether the buzzer needs to beep.
	 * 
	 * @see BUZZER_MASK_T
	 */
	unsigned int   uiBitMapBuzzer:8;
	/**
	 * This bit map variable contains the requests from other
	 * modules, to determine whether the alarm led needs to blink.
	 * 
	 * @see LED_ALARM_MASK_T
	 */
	unsigned int   uiBitMapLedAlarm:8;
	/**
	 * This bit map variable indicate which power supply is failed.
	 * It is always zero if model doesn't support muti power supply.
	 *
	 * @see POWER_FAIL_MASK_T in source/lnxscemd-2.0
	 */
	unsigned int   uiBitMapPowerFail:8;

	/**
	 * When this variable is TRUE, there is new RT Netlink event
	 */
	BOOL           blNetlinkNew:1;
	/**
	 * This is for LCM close type (poweroff, reboot, safemode)
	 */
	SCEMD_LCM_CLOSE_TYPE  lcmCloseType;
	/**
	 * sharedResourceHandle is used to maintain the shared disk info list
	 */
	SHARED_RESOURCE_HANDLE   sharedResourceHandle;

#if defined(MY_DEF_HERE)
	/**
	 * this structure if for LCM enclosure temperature alarm
	 */
	EncTempList* EnclosureTempAlarm;
#endif

#ifdef MY_DEF_HERE
	/**
	 * If scemd wakes from system deep sleep, delay checking volume
	 * The value of this variable is delay time
	 */
	unsigned int   uiDelayChkVol;
#endif

} __attribute__((packed)) shared_buffer_t;

#endif /* __SYNO_HWCTL_SHARED_BUFFER__ */
