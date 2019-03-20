#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_LCM__
#define __SYNO_HWCTL_LCM__

#include <hwctl/external.h>

#define LCM_MAX_DISPLAY_LINE                    (2)
#define LCM_MAX_DISPLAY_CHARS                   (48)
#define LCM_MAX_DISPLAY_CHARS_WITHOUT_SCROLL    (17)
#define LCM_MAX_CMD_LENGTH                      (LCM_MAX_DISPLAY_CHARS*2+6)
#define LCM_MAX_BUFFER_SIZE                     (128)
#define LCM_MAX_PASSWORD_LENGTH                 (8)
#define LCM_SERVER_NAME_MAX_LEN                 (256)
#define LCM_MODEL_NAME_MAX_LEN                  (256)
#define LCM_VERSION_MAX_LEN                     (256)
#define LCM_MAX_ERR_MSG_BUF                     (128)
#define LCM_DEFAULT_SCROLL_SPEED                (3)
#define PRINT_SHIFT                             (15)
#define LCM_CURSOR_SET_ROW2                     (2)

#define INTERFACE_NUMBER int
#define SZF_ENC_SHARE_LOCK    "/tmp/enc.share.lock"
#define SZF_LCM_TIME_OUT      "/tmp/lcm_timeout"

/* following defines are for share memory. */
/* see also "busybox-1.16.1/init/halt.c" */
#define SZ_LCM_SHARE_PATH "/tmp/lcm/sharemem"
#define LCM_SHARE_ID 1

/* if system is under memory testing by Synology Assistant, there are a file as follow.
 * see also "memtester/memtester.c"
 */
#define SZ_MEM_TEST_FILE "/.memtest"

#define LCM_CMD_WAIT_FILM_ON 			"-Fo"
#define LCM_CMD_WAIT_FILM_OFF 			"-Ff"

#define LCM_CMD_ALERT_LED_OFF 			"3"
#define LCM_CMD_STATUS_ALL_LED_OFF 		"7"

typedef enum {
	STATUS_NEED_REFRESH  = 0x01,
	STATUS_NO_DISK = 0x02,
	STATUS_NO_LINK = 0x04,
} SYNO_LCM_SYS_STATUS;

#define LCM_MAX_ERROR_PRINT_TIMES 		(5)
#define IFM_ACTIVE 0x00000002

/* see "busybox-1.16.1/init/halt.c" */
#define SZ_LCM_SHARE_PATH "/tmp/lcm/sharemem"
#define LCM_SHARE_ID 1
#define LCM_IF_NUM_DISPLAY_SHIFT(IF_NUM) (IF_NUM + 1)
#define LCM_LINK_DISPLAY_SHIFT(LINK_NUM) (LINK_NUM + 1)
#define LCM_FAN_NUM_DISPLAY_SHIFT(FAN_NUM) (FAN_NUM + 1)

/* define for ui password setting. */
#define SZF_ETC_LCM_CONF "/etc/lcm.conf"
#define SZ_LCM_PASSWORD "lcm_password"
#define SZ_LCM_PASSWORD_ENABLE "lcm_password_enable"

/* This is for juniorinstaller wait  500000n sec = 0.5sec pre command */
#define JUNIOR_LCM_CMD_WAIT_TIME (500000000)
/* wait  200000u sec = 0.2sec pre command */
#define LCM_CMD_WAIT_TIME (200000)
/* wait  0.2sec pre command */
#define LCM_CMD_WAIT_TIME_IN_SEC (0.2)

#define SZ_ENC_UPLINK   "Uplink"
#define SZ_ENC_DOWNLINK "Downlink"
#define ENC_UPLINK_MAX (2)

typedef enum {
	BTN_NONE  = 0x00,
	BTN_UPDATE= 0x01,
	BTN_ENTER = LCM_BUTTON_EN_CHAR,
	BTN_BACK  = LCM_BUTTON_BK_CHAR,
	BTN_UP    = LCM_BUTTON_UP_CHAR,
	BTN_DOWN  = LCM_BUTTON_DN_CHAR
} SYNO_LCM_BTN_EVENT;

typedef enum {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_BACK,
	DIRECTION_ENTER
} INSERT_DIRECTION;

typedef enum {
	MESSAGE_SUCCESS,
	MESSAGE_FAILED,
	MESSAGE_CANCEL,
	MESSAGE_REBOOT,
	MESSAGE_POWER_OFF,
	MESSAGE_SUBNET_CONFLICT_CONT,
	MESSAGE_SUBNET_CONFLICT_WARN,
	MESSAGE_IP_CONFLICT_WARN,
	MESSAGE_WRONG_PASSWORD,
	MESSAGE_DISK_WAKEUP,
	MESSAGE_UPS_SAFEMODE,
	MESSAGE_MEM_TEST,
} LCM_MESSAGE_TYPE;

typedef enum {
	EDIT_ERROR    = 0x1,
	EDIT_CANCEL   = 0x2,
	EDIT_FINISH   = 0x4,
	EDIT_CONTINUE = 0x8,
} LCM_PASSWORD_EDIT_STATUS;

typedef enum {
	PAGE_SERVER_NAME,
	PAGE_PASSWORD,
	PAGE_MENU_SYSTEM,
	PAGE_SYSTEM_MODEL,
	PAGE_SYSTEM_VERSION,
	PAGE_SYSTEM_SERIAL_NUM,
	PAGE_SYSTEM_TIME,
	PAGE_MENU_NETWORK,
	PAGE_NET_DNS,
	PAGE_NET_GATEWAY,
	PAGE_ETH_MAC,
	PAGE_ETH_IP,
	PAGE_ETH_MASK,
	PAGE_ETH_DHCP_MANUAL,
	PAGE_ETH_DHCP,
	PAGE_ETH_DHCP_SET,
	PAGE_ETH_MANUAL,
	PAGE_ETH_IP_EDIT,
	PAGE_ETH_MASK_EDIT,
	PAGE_ETH_MANUAL_SET,
	PAGE_NET_DNS_GATEWAY,
	PAGE_NET_DNS_EDIT,
	PAGE_NET_GATEWAY_EDIT,
	PAGE_NET_DNS_GATEWAY_SET,
	PAGE_MENU_REBOOT,
	PAGE_REBOOT_CHECK,
	PAGE_HOST_FAN_FAIL,
	PAGE_HOST_POWER_FAIL,
	PAGE_RAID_FAIL,
	PAGE_SSD_CACHE_FAIL,
	PAGE_HDD_OVER_HEAT,
	PAGE_CPU_OVER_HEAT,
	PAGE_EBOX_FAN_FAIL,
	PAGE_EBOX_HDD_OVER_HEAT,
	PAGE_BEEP_OFF,
	PAGE_MENU_HA,
	PAGE_HA_NAME,
	PAGE_HA_CLUSTER_IP_ADDR,
	PAGE_HA_CLUSTER_IP_MASK,
	PAGE_ERR_MSG,
	PAGE_NULL	//for declare the node_page[] array.
			//when add new page, must keep PAGE_NULL to be the last entry.
} SYNO_LCM_PAGE;

#define PAGE_LCM_START (PAGE_SERVER_NAME)

struct _tag_SYNO_LCM_MENU_NODE;
typedef void (*SYNO_LCM_EXECUTE_FUNC) (struct _tag_SYNO_LCM_MENU_NODE*, SYNO_LCM_BTN_EVENT);

typedef struct _tag_SYNO_LCM_MENU_NODE {
	SYNO_LCM_PAGE NodeName;
	int menuIndex[LCM_MAX_DISPLAY_LINE];
	char szDisplay[LCM_MAX_DISPLAY_LINE][LCM_MAX_DISPLAY_CHARS];
	BOOL blPageIsHided;
	SYNO_LCM_PAGE UpNodeName;
	SYNO_LCM_PAGE DownNodeName;
	SYNO_LCM_PAGE BackNodeName;
	SYNO_LCM_PAGE EnterNodeName;
	struct _tag_SYNO_LCM_MENU_NODE *pUp;
	struct _tag_SYNO_LCM_MENU_NODE *pDown;
	struct _tag_SYNO_LCM_MENU_NODE *pBack;
	struct _tag_SYNO_LCM_MENU_NODE *pEnter;
	SYNO_LCM_EXECUTE_FUNC ExecuteFunc;
	void *PTR; //This is a pointer for each node for their local variables.
} __attribute__((packed)) SYNO_LCM_MENU_NODE;

typedef struct _tag_LCM_PARAM {
	int  turnOffLcmBkLightInSecs;
	int  lcmContrast;
	int  lcmBkLightCntDownVal;
	int  lcmScrollSpeed;
	BOOL blLcmBkLightOn;
	BOOL blLcmBkLightEnable;
	BOOL blLcmBkLightBlink;
	BOOL blLcmNodeLock;
} __attribute__((packed)) LCM_PARAM;

typedef struct _tag_IP_INFO {
	char szDNS[LCM_MAX_DISPLAY_CHARS];
	char szGateWay[LCM_MAX_DISPLAY_CHARS];
	char szName[LCM_MAX_DISPLAY_CHARS];
	char szIPAddr[LCM_MAX_DISPLAY_CHARS];
	char szIPMask[LCM_MAX_DISPLAY_CHARS];
} __attribute__((packed)) LCM_IP_INFO;

typedef enum {
	LCM_INFO_SERVER_NAME = 0x01,
	LCM_INFO_MODEL_NAME = 0x02,
	LCM_INFO_VERSION = 0x04,
	LCM_INFO_DNS = 0x08,
	LCM_INFO_GATEWAY = 0x10,
	LCM_INFO_V4_NET = 0x20,
	LCM_INFO_V6_NET = 0x40,
	LCM_INFO_ALL = 0xff
} LCM_INFO_TYPE;

typedef struct _tag_SYNO_LCM_NODE_DATA {
	char szServerName[LCM_SERVER_NAME_MAX_LEN];
	char szModelName[LCM_MODEL_NAME_MAX_LEN];
	char szVersionInfo[LCM_VERSION_MAX_LEN];
	char szErrMsg[LCM_MAX_ERR_MSG_BUF];
} LCM_NODE_DATA;

#if defined(MY_DEF_HERE)
typedef enum {
	ENCLOSURE_NORMAL,
	ENCLOSURE_FAN_ERROR,
	ENCLOSURE_LINK_ERROR,
	ENCLOSURE_POWER_ERROR,
	ENCLOSURE_TEMPERATURE_ERROR
} LCM_ENCLOSURE_ERROR_TYPE;

typedef struct _tag_ENCLOSURE_ERROR_NODE_DATA {
	ENCLOSURE_UNIQUE_ID EnclosureUnique;
	int EnclosureId;
	LCM_ENCLOSURE_ERROR_TYPE ErrorType;
	int DeviceNumber;
	BOOL blIsHost;
} LCM_ENCLOSURE_ERROR_NODE_DATA;
#endif

#endif /* __SYNO_HWCTL_LCM__ */
