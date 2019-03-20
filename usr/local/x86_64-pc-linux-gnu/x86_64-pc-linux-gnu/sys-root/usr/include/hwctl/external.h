#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_HWCTL_EXTERNAL_H_
#define __SYNO_HWCTL_EXTERNAL_H_

#include <hwctl/ebox.h>
#include <synosdk/fs.h>
#include <unistd.h>
#include <dirent.h>
#ifdef MY_DEF_HERE
#include <synosas/enclosure.h>
#endif
#ifdef MY_DEF_HERE
#include <synonvme/synonvme.h>
#endif

__BEGIN_DECLS;

#ifdef MY_DEF_HERE
#define SZ_SAS_USB_DEVICE_PREFIX "usb"
#define SZ_SAS_DEVICE_PREFIX "sas"
#define SZ_SAS_ISCSI_DEVICE_PREFIX "iscsi"
#endif

#define SZ_SATA_DEVICE_PREFIX "sd"
#define SZ_M2SATA_DEVICE_PREFIX "nvc"
#define M2SATA_DEVICE_INDEX_START 300 /* reference to kernel include/linux/synolib.h */

#define SZ_ISCSI_DEVICE_PREFIX "isd"
#define SZ_USB_FLASH_DEVICE_NAME "synoboot"
#define SZ_SDCARD_DEVICE "mmcblk"
#define SZF_HW_VERSION "/proc/sys/kernel/syno_hw_version"
#define SZF_HW_REVISION "/proc/sys/kernel/syno_hw_revision"
#define SSD_TEMPERATURE_HIGHEST_VALID 100
#define SZF_PCI_DEVICES_PATH "/sys/bus/pci/devices/"
#define SZF_PCI_EXTENSION "/etc.defaults/extensionDevices"
#define SZF_PCI_EXTENSION_PORT "/etc.defaults/extensionPorts"
#define SZF_NIC_DEVICE "/sys/class/net/%s/device"
#define SZK_PCI_SECTION "pci"
#define SZD_DISK_DEV SZ_SATA_DEVICE_PREFIX

#define SZF_SYS_HAS_DYN_MODULE "/proc/sys/kernel/syno_dyn_module"
#define SZK_SYS_BUZZER_OFF_CONFIG "buzzeroffcfg"
#define SZK_SYS_BUZZER_OFF_ENABLE "buzzeroffen"
#define SZF_BUZZER_CURRENT_BIT_MAP "/tmp/buzzerCurrentBitMap"
#define SZK_BUZZER_CURRENT_BIT_MAP "buzzerCurrentBitMap"
#define SZK_INTERNAL_PORT_CONFIG "internalportcfg"
#define SZK_ESATA_PORT_CONFIG "esataportcfg"
#define SZK_USB_PORT_CONFIG "usbportcfg"
#define SZK_CACHE_PORT_CONFIG "cacheportcfg"
#define SZK_USB_PORT_NUM "usbportnum"
#define BCD2DEC(val) ((val)=((val)&15) + ((val)>>4)*10)
#define DEC2BCD(dec) ((((dec)/10)*16)+((dec)%10))
#define SZF_POWER_SCHED_CONF "/etc/power_sched.conf"
#define SZF_POWER_SCHED_CONF_TMP "/tmp/power_sched.conf.tmp"
#define SZ_POWER_ON_SCHEDULE "Power On schedule"
#define SZ_POWER_OFF_SCHEDULE "Power Off schedule"
#define NUM_AUTO_POWERON_WEEKDAY_FIELDS 7
#define SZF_SCEMD_BEEP "/tmp/scemd_beep"

#define FLAG_SIGTERM                     0x01
#define SZK_DEVICE_NAME_LENG 32
#define SZK_DEVICE_PATH_LENG 128
#define HW_VERSION_LEN 32 /* ex. Synology-DX510 */
#define HW_REVISION_LEN 4 /* ex. r2 */
#define SZ_SCEMD_SERVER_SOCK_FILE "/tmp/scemd.socket"
#define PORT_CFG_LEN 64

#if defined(MY_DEF_HERE)
#define SZF_RTD_FACTORY_TOOL  "/usr/lib/firmware/rtd1296/factory.bin"
#endif

/* Logic device number(LDN) */
#define ENV_CTL_CONF_REG        0x04

/* Addresses when ENV_CTL_CONF_REG is set */
#define ECCR_SPECIAL_CONF_REG   0xfa

/* Bits in SPECIAL_CONF_REG */
#define SCR_5VSB_CTRL           (1 << 1)
#define SCR_EUP_WAKEUP_EVENT    (1 << 4)

#define SIGUSBCAM1                                   40
#define SIGUSBCAM2                                   41
#define SIG_VOLUME_BEEP_OFF                          42
#define SIG_HIBERNATION_TIMER_CHANGE                 43
#define SIG_FAN_TEST_BEGIN                           44
#define SIG_NOCPLD_FAN_TEST_BEGIN                    45
#define SIG_FAN_CONFIG_DUAL_MODE_CHANGE_INTERNAL     46
#define SIG_KILL_MANUTILD                            47
#define SIG_FAN_CONFIG_DUAL_MODE_CHANGE_EBOX         48
#define SIG_BEEP_OFF_CONFIG_CHANGE                   49
#define SIG_SPEEDUP_HW_POLLING_MEM_LEAK_TEST         50
#define SIG_SATA_DEEP_SLEEP_TIMER_CHANGE             51
#define SIG_EUNIT_DEEP_SLEEP_TIMER_CHANGE            52
#define SIG_FIND_ME_START                            53
#define SIG_FIND_ME_STOP                             54
#define SIG_LCM_START                                55
#define SIG_LCM_STOP                                 56
#define SIG_SAS_ENC_ID_UPDATE                        57
#define SIG_CROND_EXECUTE                            58
#define SIG_SERVICE_READY_BEEP                       59
#define SIG_FAN_CONFIG_DUAL_MODE_CHANGE_ENCLOSURE    60
#define SIG_READ_HOTPLUGD_PID                        61
#define SIG_SYSTEM_READY                             62 // Used by dualhead model
#define SIG_AUTO_POWEROFF_TIMER_CHANGE               63
#define SIG_POWERCOPY_ACTION                         64
#define SIG_POWERCOPY_TERM                           65
#define SIG_USBCOPY_ACTION                           66
#define SIG_LED_BRIGHTNESS_CONFIG_UPDATE             67

#define UART2_CMD_BUTTON_POWER              0x30
#define UART2_CMD_SHUTDOWN                  0x31
#define UART2_CMD_BUZZER_SHORT              0x32
#define UART2_CMD_BUZZER_LONG               0x33
#define UART2_CMD_LED_POWER_ON              0x34
#define UART2_CMD_LED_POWER_BLINK           0x35
#define UART2_CMD_LED_POWER_OFF             0x36
#define UART2_CMD_LED_HD_OFF                0x37
#define UART2_CMD_LED_HD_GS                 0x38
#define UART2_CMD_LED_HD_GB                 0x39
#define UART2_CMD_LED_HD_AS                 0x3A
#define UART2_CMD_LED_HD_AB                 0x3B
#define UART2_CMD_LED_HD_BREATH             0x3D
#define UART2_CMD_LED_USB_ON                0x40
#define UART2_CMD_LED_USB_BLINK             0x41
#define UART2_CMD_LED_USB_OFF               0x42
// control by microp, echo J to ttyS1 to light on the 10G led, echo K to ttyS1 to turn off the 10G led
#define UART2_CMD_LED_10G_LAN_ON            0x4A
#define UART2_CMD_LED_10G_LAN_OFF           0x4B
#define UART2_CMD_SWITCH_MICROP_VERSION     0x4F
#define UART2_CMD_LED_MIRROR_OFF            0x50
#define UART2_CMD_LED_MIRROR_GS             0x51
#define UART2_CMD_LED_MIRROR_GB             0x52
#define UART2_CMD_LED_MIRROR_AS             0x53
#define UART2_CMD_LED_MIRROR_AB             0x54
#define UART2_CMD_TOGGLE_FAN_RPS_REPORT     0x55 /* 'U' */
#define UART2_CMD_SET_PWM_DUTY              0x56 /* 'V' */
#define UART2_CMD_SET_PWM_FREQ              0x57 /* 'W' */
#define UART2_CMD_BUTTON_USB                0x60
#define UART2_CMD_BUTTON_RESET              0x61
// control by up, must echo u first! uP #1
#define UART2_CMD_FAN_FAILURE               0x66 /* 'f' */
// control by up, must echo EC1 first! uP #17
#define UART2_CMD_CPUFAN_FAILURE            0x67 /* 'g' */
#define UART2_CMD_RCPOWEROFF                0x70
#define UART2_CMD_RCPOWERON                 0x71
#define UART2_CMD_DISABLE_SCHEDULE_POWERON  0x72
#define UART2_CMD_ENABLE_SCHEDULE_POWERON   0x73
#define UART2_CMD_DISABLE_FANCHECK          0x74
#define UART2_CMD_ENABLE_FANCHECK           0x75
#define UART2_CMD_DISABLE_CPUFANCHECK       "EC0"
#define UART2_CMD_ENABLE_CPUFANCHECK        "EC1"
#define UART2_CMD_ENABLE_POWERBTN_WAKEUP    "SW1"
#define UART2_CMD_DISABLE_POWERBTN_WAKEUP   "SW0"
#define UART2_CMD_ALARM_LED_ON              "LA1"
#define UART2_CMD_ALARM_LED_BLINKING        "LA2"
#define UART2_CMD_ALARM_LED_OFF             "LA3"
#define UART2_CMD_SWITCH_LED_CONTROL        "M"  //Switch the led control between status and power
#define UART2_CMD_WOL_ENABLE                "l"
#if defined(MY_DEF_HERE) || defined(MY_ABC_HERE)
#define UART2_CMD_GET_UNIQUE_CMD            0x52 /* 'R' */
#endif

#define LCM_BUTTON_UP_CHAR          'u'
#define LCM_BUTTON_DN_CHAR          'd'
#define LCM_BUTTON_BK_CHAR          'b'
#define LCM_BUTTON_EN_CHAR          'e'

#define LCM_CMD_ALERT_LED_ON            "1"
#define LCM_CMD_ALERT_LED_BLINK         "2"
#define LCM_CMD_ALERT_LED_OFF           "3"
#define LCM_CMD_STATUS_GREEN_LED_ON         "8"
#define LCM_CMD_STATUS_GREEN_LED_BLINK      "9"
#define LCM_CMD_STATUS_ORANGE_LED_ON        ":"
#define LCM_CMD_STATUS_ORANGE_LED_BLINK     ";"
#define LCM_CMD_STATUS_ALL_LED_OFF      "7"
#define LCM_CMD_WAIT_FILM_ON            "-Fo"
#define LCM_CMD_WAIT_FILM_OFF           "-Ff"
#define LCM_CMD_VERSION_ON          "-Oo"
#define LCM_CMD_VERSION_OFF             "-Of"

typedef enum _tag_BUZZER_MASK_T {
    BUZZER_FAN_FAIL      = 0x01,
    BUZZER_RAID_FAIL     = 0x02,
    BUZZER_EUNIT_FAN_FAIL= 0x04,
    BUZZER_POWER_ON      = 0x08,
    BUZZER_POWER_OFF     = 0x10,
    BUZZER_RESET_BTN     = 0x20,
    BUZZER_SAS_LINK_FAIL = 0x40,
    BUZZER_SSD_CACHE_FAIL= 0x80,
    BUZZER_ENC_MODULE_FAIL = 0x100,
} BUZZER_MASK_T;

typedef enum {
    FIELD_ENABLED = 0,
    FIELD_WEEKDAYS,
    FIELD_HOUR,
    FIELD_MIN
} POWER_TASK_FIELD_TYPE;

typedef enum {
    AUTO_POWER_ACTION_ON,
    AUTO_POWER_ACTION_OFF
} AUTO_POWER_ACTION;

typedef enum{
    TIMER_NONE = 0,
    TIMER_NORMAL_STANDBY,
    TIMER_SATA_DEEP_SLEEP,
    TIMER_EUNIT_DEEP_SLEEP
} TIMER_TYPE;

// use bitwise expression for POWERON_SCHEDULE fields
typedef struct _tag_POWER_SCHEDULE {
    char enabled;       // enable/disable
    char weekday;       // Saturday to Sunday ( [6:0] = [Sat,Fri,Thu,Wed,Tue,Mon,Sun] )  (Sun: 0x01, Mon: 0x02, ¡K , Sat: 0x40)
    char hour;          // decimal formatted hour ( local time )
    char min;           // decimal formatted min ( local time )
} POWER_SCHEDULE, POWERON_SCHEDULE;

/* external_led_aha_led_set.c */
int SYNOLedAHALedSet(SYNO_AHA_LED ledStatus);
/* external_hw_pci_ext_nic_exist.c */
BOOL SYNOHWPciExtNicExist(void);
/* external_hw_get_event.c */
int SYNOHWGetEvent(SYNOBIOSEVENT *pEvent, int timeout);
/* external_auto_power_on_set.c */
int SYNOAutoPoweronSet(void);
/* external_hw_capability_get.c */
int SYNOHWCapabilityGet(SYNO_HW_CAPABILITY hw_capability);
/* external_auto_power_conf_set.c */
int SYNOAutoPowerConfSet(AUTO_POWER_ACTION act, int num, const POWER_SCHEDULE *pSchedule);
/* external_auto_power_conf_get.c */
int SYNOAutoPowerConfGet(AUTO_POWER_ACTION act, int num, POWER_SCHEDULE *pSchedule);
/* external_auto_power_on_hw_get.c */
int SYNOAutoPoweronHWGet(SYNO_AUTO_POWERON *pSchedule);
/* external_auto_power_on_hw_set.c */
int SYNOAutoPoweronHWSet(const SYNO_AUTO_POWERON *pSchedule);
/* external_auto_power_on_support_get.c */
BOOL SYNOAutoPoweronSupportGet(void);
/* external_redundant_power_status_get.c */
int SYNORedundantPowerStatusGet(BOOL *pblPowerOneFail, BOOL *pblPowerTwoFail);
/* external_redundant_power_support.c */
BOOL SYNORedundantPowerSupport(void);
/* external_hw_version_get.c */
int SynoHWVersionGet(char *szBuf, size_t uiBufLength);
/* external_buzzer_off_config_get.c */
unsigned int SYNOBuzzerCurrentBitmapGet(void);
/* external_buzzer_off_config_set.c */
int SYNOBuzzerOffConfigSet(BUZZER_MASK_T BuzzerMaskBit, BOOL blSetBit);
/* external_buzzer_off_enable_bit_get.c */
unsigned int SYNOBuzzerOffEnableBitGet(void);
/* external_buzzer_current_bitmap_get.c */
unsigned int SYNOBuzzerOffConfigGet(void);
/* external_is_find_me_support.c */
BOOL ExternalIsFindMeSupport(void);
/* external_disk_port_enum_all.c */
int SYNODiskPortEnumAll(const DISK_PORT_TYPE portType, PSLIBSZLIST *pListDevNames);
/* external_hw_is_PCI_extension_device_exist.c */
BOOL SYNOHWIsPCIExtensionDeviceExist(void);
/* external_microp_id_check.c */
int SYNOCheckMicropId(void);
/* external_hw_revision_get.c */
int SynoHWRevisionGet(char *szBuf, size_t uiBufLength);
/* external_hw_is_device_on_PCI_extension_port.c */
int SYNOExternalHWIsDeviceOnPCIExtensionPort(const char *szPCIDevID);
/* external_hw_find_NIC_PCI_name.c */
int SYNOExternalHWFindNICPCIName(const char *szNICName, char *szPCIName, int leng);
/* external_hw_is_device_on_PCI_port.c */
BOOL SYNOExternalHWIsPCIDeviceOnPCIPort(const char *szPCIDevID, const char *szPCIPortPath);
/* external_superio_eup_control.c */
int SYNOSuperioEUPControl(int iIsEnable);
/* external_superio_check_all_wake_on_lan_enabled.c */
int SYNOSuperioCheckAllWakeOnLanEnabled(void);
/* external_modify_eup_status.c */
int SYNOModifyEUPStatus(void);
/* external_hw_vendor_get.c */
int SYNOHWVendorGet(const char *szPCIName, char *szVendor, const int leng);

/* external_disk_port_check.c */
DISK_PORT_TYPE SYNODiskPortCheck(const char *szDevNamePath);
/* external_disk_port_enum.c */
int SYNODiskPortEnum(const DISK_PORT_TYPE portType, PSLIBSZLIST *pListDevNames);
/* external_disk_port_enum_eunit.c */
int SYNOEnumAllEUnitsDisks(const BOOL blUsed, char *szBuf, const int bufLen);
/* external_esata_port_get.c */
int SYNOExternalEsataPortGet(const int esataIdx, char *szEsataName, int leng);
/* external_disk_fast_wake.c */
int SYNODiskFastWake(void);
/* external_hw_external_control.c */
int SYNOHWExternalControl(int MsgId, int MsgLen, char *szMsg);
/* external_open_bios_dev.c */
int OpenBiosDev(void);
/* external_scemd_notify.c */
int SLIBScemdNotify(int signo);

__END_DECLS;
#endif /* __SYNO_HWCTL_EXTERNAL_H_ */
