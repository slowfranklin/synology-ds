#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifndef __SYNO_HWCTL_DISK_H_
#define __SYNO_HWCTL_DISK_H_

#include <synocore/synotype.h>
#include <synosdk/fs.h>
#include <hwctl/smartctl.h>
#include <hwctl/external.h>
#include <hwctl/sgio.h>
#include <unistd.h>

__BEGIN_DECLS;
#define NODE_DISK_CTL_CONFIG	"disk_control"
#define NODE_DISK_CTL_CUSTOM	"disk_control_custom"
#define NODE_DISK_CONFIG		"disk"
#define NODE_DISK_MODEL			"model"
#define NODE_DISK_SERIAL		"serial"
#define NODE_DISK_FIRMWARE		"firmware"
#define NODE_DISK_EUNIT			"eunit"
#define NODE_DISK_INTERNAL      "internal"
#define NODE_DISK_OPERATING_TEMPERATURE  "disk_operating_temperature"

#define ACTION_HDPARM_254		"APM_254"
#define ACTION_HDPARM_255		"APM_255"
#define ACTION_NCQ_OFF			"NCQ_OFF"
#define ACTION_NCQ_ON			"NCQ_ON"
#define ACTION_WDIDLE			"WD_IDLE_CHECK"
#define ACTION_WRITE_CACHE_OFF		"WCACHE_OFF"
#define ACTION_DSLEEP_WRITE_CACHE_OFF	"DSLEEP_WCACHE_OFF"
#define ACTION_WDIDLE_OFF		"WD_IDLE_OFF"
#define ACTION_DSLEEP_OFF		"DSLEEP_OFF"
/* Customize SCSI command timeout */
#define ACTION_TIMEOUT_15		"TIMEOUT_15"	// When timeout = 15s, timeout issue is gone with most disks.
#define ACTION_TIMEOUT_23		"TIMEOUT_23"	// Seagate suggestion use timeout = 23s for their disks.
#define ACTION_SEC_ERASE_OFF		"SECERA_OFF"
#define DISK_MODEL_ALL			"ALL"
#define EUNIT_MODEL_ALL			"ALL"

#define DO_HDPARM_254           "/usr/syno/bin/DiskApmSet.sh 254 "
#define DO_HDPARM_255           "/usr/syno/bin/DiskApmSet.sh 255 "
#define DO_NCQ_OFF				"/usr/syno/bin/syno_disk_ctl --ncq-off "
#define DO_NCQ_ON				"/usr/syno/bin/syno_disk_ctl --ncq-on "
#define DO_WDIDLE				"/usr/syno/bin/syno_disk_ctl --wd-idle -d"
#define DO_WRITE_CACHE_OFF		"/usr/bin/hdparm -W 0 "
#define DO_DSLEEP_WRITE_CACHE_OFF	"/usr/syno/bin/syno_disk_ctl --wcache-off "
#define DO_TIMEOUT_15			"/usr/syno/bin/syno_disk_ctl --scmd-timeout 15 "
#define DO_TIMEOUT_23			"/usr/syno/bin/syno_disk_ctl --scmd-timeout 23 "

#define SZ_DISK_CONFIG_FILE		"/usr/syno/etc.defaults/scemd.xml"
#define SZ_WCACHE_OFF_DISKDEV   "/tmp/wcache_off_diskdev"
#define SZ_FORCE_WCACHE_ENABLE  "/.force_wcache_enable"
/* Disk blacklist file locations */
#define SZ_DSLEEP_OFF_DISKDEV	"/tmp/.block_deep_sleep"
#define SZ_SECERA_OFF_DISKDEV	"/tmp/.disable_sec_erase"
#define SZ_WDIDLE_OFF_BLACKLIST_DEV   "/tmp/.block_wd_idle"

#define ACTION_EPC_OFF                  "EPC_OFF"
#define SZF_SG_SAT_SET_FEATURES         "/usr/syno/bin/sg_sat_set_features"

typedef struct _tag_SYNO_FILE_LIST {
        const char *szName;
        const char *szLocation;
}SYNO_FILE_LIST;

extern const SYNO_FILE_LIST gFileListDiskBlackList[];

#define SZK_SAS					"SAS"
#define SZK_ENCLOSURE			"Enclosure"
#define SZ_SYS_CLASS_PATH		"/sys/class/scsi_host/"
#define SZ_SYSFS_PORT_THAW		"syno_port_thaw"
#define SZ_SYSFS_DISKNAME_TRANS	"syno_diskname_trans"
#define SZ_PORT_DISABLE_TAB		"/tmp/port_disable_tab"
#define	SZ_TITLE_DISK_POWER_RST "disk_info:disk_recovery_notify"

#define SZ_DISK_THRESHOLD_KEY               "disk_warning_percent"
#define SZ_DISK_INODE_THRESHOLD_KEY			"disk_inode_warning_percent"
#define SZ_ESATA_DISK_THRESHOLD_KEY         "esata_disk_warning_percent"
#define SZ_ESATA_PARTITION_THRESHOLD_KEY    "esata_partition_warning_percent"
#define SZ_USB_DISK_THRESHOLD_KEY           "usb_disk_warning_percent"
#define SZ_USB_PARTITION_THRESHOLD_KEY      "usb_partition_warning_percent"
#define SZ_SDCARD_THRESHOLD_KEY             "sdcard_warning_percent"
#define SZ_SDCARD_PARTITION_THRESHOLD_KEY   "sdcard_partition_warning_percent"

#define SZF_DISK_HEALTH_RECORD	"/usr/syno/etc/disk_health_record_time"
#define SZF_DISK_OVERVIEW_XML	"/var/log/disk_overview.xml"
#define SZF_DISK_LOG_XML		"/var/log/disk_log.xml"
#define SZF_DISK_PERF_LOG_XML	"/var/log/disk_perf_log.xml"
#define SZF_DISK_SMART_LOG_XML	"/var/log/disk_smart_test_log.xml"
#define SZF_DISK_SMART_ACTION_XML	"/var/log/disk_smart_action.xml"
#define SZF_DISK_ADV_TEST_LOG_XML	"/var/log/disk_adv_test_log.xml"
#define SZF_ENUM_DETAIL_LIST	"/tmp/enumlist_det"
#define SZF_ENUM_DETAIL_LIST_TMP "/tmp/enumlist_det.tmp"
#define SZK_DISK_XML_OVERVIEW	"overview"
#define SZK_DISK_XML_MODEL		"model"
#define SZK_DISK_XML_PATH		"path"
#define SZK_DISK_XML_CONTAINER	"container"
#ifdef MY_DEF_HERE
#define SZK_DISK_XML_UNIQUE		"unique"
#endif /* MY_DEF_HERE */
#define SZK_DISK_XML_SLOT		"slot"
#define SZK_DISK_XML_UNC		"unc"
#define SZK_DISK_XML_ICRC		"icrc"
#define SZK_DISK_XML_IDNF		"idnf"
#define SZK_DISK_XML_RETRY		"retry"
#define SZK_DISK_XML_REMAIN_LIFE "remainLife"
#define SZK_DISK_XML_SERROR		"serror"
#define SZK_DISK_XML_ERROR		"error"
#define SZK_DISK_XML_NULL		"null"
#define SZK_DISK_XML_LOG		"log"
#define SZK_DISK_XML_SHOW		"show"
#define SZK_DISK_XML_HOTPLUG	"hotplug"
#define SZK_DISK_XML_KERNEL		"kernel"
#define SZK_DISK_XML_TESTFAIL	"testfail"
#define SZK_DISK_XML_SN			"SN"
#define SZK_DISK_XML_TYPE		"type"
#define SZK_DISK_XML_TIME		"time"
#define SZK_DISK_XML_PLUGIN		"plugin"
#define SZK_DISK_XML_PLUGOUT	"plugout"
#define SZK_DISK_XML_RAW		"raw"
#define SZK_DISK_XML_TEXT		"text"
#define SZK_DISK_XML_HISTORY	"history"
#define SZK_DISK_XML_QUICK		"quick"
#define SZK_DISK_XML_EXTEND		"extend"
#define SZK_DISK_XML_PERF		"performance"
#define SZK_DISK_XML_READ_IOPS	"readIops"
#define SZK_DISK_XML_READ_BW	"readBw"
#define SZK_DISK_XML_READ_BW_UNIT	"readBwUnit"
#define SZK_DISK_XML_READ_LATENCY	"readLatency"
#define SZK_DISK_XML_READ_LATENCY_UNIT	"readLatencyUnit"
#define SZK_DISK_XML_WRITE_IOPS	"writeIops"
#define SZK_DISK_XML_WRITE_BW	"writeBw"
#define SZK_DISK_XML_WRITE_BW_UNIT	"writeBwUnit"
#define SZK_DISK_XML_WRITE_LATENCY	"writeLatency"
#define SZK_DISK_XML_WRITE_LATENCY_UNIT	"writeLatencyUnit"
#define SZK_DISK_XML_BUILD_VERSION "buildVersion"
#define SZK_DISK_XML_DISK_UTILIZATION "diskUtilization"
#define SZK_DISK_XML_SMART		"smart"
#define SZK_DISK_XML_RESULT		"result"
#define SZK_DISK_XML_ID			"id"
#define SZK_DISK_XML_CURRENT	"current"
#define SZK_DISK_XML_THRESHOLD	"threshold"
#define SZK_DISK_XML_WORST		"worst"
#define SZK_DISK_XML_RAW		"raw"
#define SZK_DISK_XML_ADV		"advance"
#define SZK_DISK_XML_STATUS		"status"
#define SZK_DISK_XML_SECTION	"section"
#define SZK_DISK_XML_KEY		"key"
#define SZK_DISK_XML_DAMAGE_WEIGHT "damageWeight"
#define SZK_DISK_XML_LIFE		"life"
#define SZK_DISK_XML_MODIFIABLE	"modifiable"
#define SZK_DISK_XML_TEST_CODE "testCode"

#define SZ_DISK_NODE_PREFIX		"SN_"

// critical smart field
#define SZV_SPIN_RETRY_COUNT		"Spin_Retry_Count" //#10
#define SZV_REPORTED_UNCORRECT		"Reported_Uncorrect" //#187
#define SZV_COMMAND_TIMEOUT			"Command_Timeout" //#188
#define SZK_OFFLINE_UNCORRECTABLE	"Offline_Uncorrectable" //#198
#define SZV_UNCORRECTABLE_SECTOR_CT	"Uncorrectable_Sector_Ct" //#198
#define SZK_REALLOCATED_SECTOR_CT	"Reallocated_Sector_Ct" //#5

#define SZK_CURRENT_PENDING_SECTOR	"Current_Pending_Sector"
#define SZK_UDMA_CRC_ERROR_COUNT	"UDMA_CRC_Error_Count"

#define SZV_WEAR_LEVELING_COUNT     "Wear_Leveling_Count"
#define SZV_PERCENT_LIFETIME_USED   "Percent_Lifetime_Used"
#define SZV_PERCENT_LIFETIME_REMAIN "Percent_Lifetime_Remain"
#define SZV_REMAINING_LIFETIME_PERC "Remaining_Lifetime_Perc"
#define SZV_SSD_LIFE_LEFT           "SSD_Life_Left"
#define SZV_MEDIA_WEAROUT_INDICATOR "Media_Wearout_Indicator"
#define SZV_REMAINING_LIFETIME_PERC "Remaining_Lifetime_Perc"

typedef enum _tag_SYNO_DISK_THR_TYPE {
	THR_TYPE_BAD_SECTOR = 0,
	THR_TYPE_REMAIN_LIFE,
	THR_TYPE_MAX
} THR_TYPE;

#define SZK_BAD_SECTOR_THR_ENABLED	"BS_Thr_Enable"
#define SZK_BAD_SECTOR_THR_VALUE	"BS_Thr_Value"

#define SZK_REMAIN_LIFE_THR_ENABLED "remain_life_thr_enable"
#define SZK_REMAIN_LIFE_THR_VALUE "remain_life_thr_value"

#define SZF_SCEMD_STOP_CHECK_MD0_FILE "/tmp/.scemd_stop_check_md0"
#define SZF_SCEMD_STOP_CHECK_MD1_FILE "/tmp/.scemd_stop_check_md1"

#define DISK_PERFORMANCE_MAX_RUNTIME	180 	// 3 minutes for each test run
#define DISK_PERFORMANCE_NUM_JOBS 		1  		// only use one io thread per test to reduce unwanted random access
#define DISK_PERFORMANCE_MAX_IO_Depth 	256		// 256 requests on-the-fly to keep target disk busy
#define DISK_PERFORMANCE_MIN_IO_Depth 	1		// 1 requests on-the-fly to keep target disk not busy
#define DISK_PERFORMANCE_SEQ_BLK_SIZE 	"64k" 	// 64kb request size for sequential IO test
#define DISK_PERFORMANCE_RND_BLK_SIZE 	"4k"	// 4kb request size for random IO test
#define DISK_PERFORMANCE_DEFAULT_SIZE 	"2g"	// 2GB size limitation for quick test

#define SZK_DISK_PERFORMANCE_PID "pid"
#define SZK_DISK_PERFORMANCE_DISK_REMOVE "diskRemove"
#define SZK_DISK_PERFORMANCE_MD1_REMOVE "md1Remove"

// For mail notification
#define SZK_DISK_MAIL_MAILLANG					"maillang"
#define SZK_DISK_MAIL_MAILLANG_DEFAULT			"enu"
#define SZK_DISK_MAIL_STRING_DISK				"volume_disk_info"
#define SZK_DISK_MAIL_STRING_UNC_CT				"disk_bad_sector_ct"
#define SZK_DISK_MAIL_STRING_IDNF_CT			"disk_identify_failed_ct"
#define SZK_DISK_MAIL_STRING_RETRY_CT			"disk_retry_ct"
#define SZK_DISK_MAIL_STRING_REMAIN_LIFE		"disk_remain_life"
#define SZK_DISK_MAIL_STRING_DISK_HEALTH_NOTE	"disk_health_report_support_note"
#define SZK_DISK_MAIL_STRING_SSDCACHE			"dedicated_ssd_cache"
#define SZK_DISK_MAIL_STRING_TB					"size_tb"
#define SZK_DISK_MAIL_STRING_GB					"size_gb"
#define SZK_DISK_MAIL_STRING_MB					"size_mb"
#define SZK_DISK_MAIL_STRING_KB					"size_kb"
#define SZK_DISK_MAIL_STRING_BYTE				"size_byte"
#define SZK_DISK_MAIL_STRING_SMART_NORMAL		"disk_smart_status_normal"
#define SZK_DISK_MAIL_STRING_SMART_DEGRADED		"disk_smart_status_degraded"
#define SZK_DISK_MAIL_STRING_SMART_FAILING		"disk_smart_status_failing"
#define SZK_DISK_MAIL_STRING_SMART_UNKNOWN		"disk_status_unknown"
#define SZK_DISK_MAIL_STRING_NORMAL				"disk_status_normal"
#define SZK_DISK_MAIL_STRING_WARNING			"disk_status_warning"
#define SZK_DISK_MAIL_STRING_CRITICAL			"disk_status_critical"
#define SZK_DISK_MAIL_STRING_FAILING			"disk_status_failing"
#define SZK_DISK_MAIL_STRING_DISK_ADV_NOT_TEST	"disk_adv_status_not_test"

#define SZ_REMAINING_LIFE_DESC "Percentage used endurance indicator:"
#define SZF_SG_LOGS "/usr/syno/sbin/sg_logs"

#define DISK_SIZE_BYTE_PER_KB 1024
#define DISK_SIZE_BYTE_PER_MB 1048576 //1024 * 1024
#define DISK_SIZE_BYTE_PER_GB 1073741824 //1024 * 1024 * 1024
#define DISK_SIZE_BYTE_PER_TB 1099511627776 //1024 * 1024 * 1024 * 1024

#define SZF_SCSI_GENRIC_PATH "/sys/block/%s/device/scsi_generic/sg*"

typedef enum _tag_SYNO_DISK_PERFORMANCE_TEST_OP_TYPE {
	PERFORMANCE_TEST_OP_TYPE_UNKNOWN,
	PERFORMANCE_TEST_OP_TYPE_READ,
	PERFORMANCE_TEST_OP_TYPE_WRITE,
} PERFORMANCE_TEST_OP_TYPE;

typedef enum _tag_SYNO_DISK_PERFORMANCE_TEST_METHOD_TYPE {
	PERFORMANCE_TEST_METHOD_TYPE_UNKNOWN,
	PERFORMANCE_TEST_METHOD_TYPE_IOPS,
	PERFORMANCE_TEST_METHOD_TYPE_BW,
	PERFORMANCE_TEST_METHOD_TYPE_LATENCY,
} PERFORMANCE_TEST_METHOD_TYPE;

typedef enum _tag_SYNO_DISK_PERFORMANCE_TEST_TYPE {
	PERFORMANCE_TEST_TYPE_UNKNOWN,
	PERFORMANCE_TEST_TYPE_EXTEND,
	PERFORMANCE_TEST_TYPE_QUICK,
} PERFORMANCE_TEST_TYPE;

typedef struct _tag_SYNO_DISK_PERFORMANCE_TEST_FIO_PARAM {
	char szIOEngine[32];
	char szNumJobs[32];
	char szIODepth[32];
	char szSize[32];
	char szDirect[32];
	char szRuntime[32];
	char szFilename[64];
	char szName[32];
	char szBlkSize[32];
	char szRWType[32];
	char szStonewall[32];
	char szGroup[32];
	char szCompress[64];
} PERFORMANCE_TEST_FIO_PARAM;

typedef struct _tag_SYNO_DISK_PERFORMANCE_TEST_RESULT {
	int iIops;
	int iBw;
	double dLatency;
	char szBwUnit[8];
	char szLatencyUnit[8];
} PERFORMANCE_TEST_RESULT;

typedef struct _tag_SYNO_DISK_PERFORMANCE_TEST_SCEMD_INFO {
	char szDevice[16];
	char szModel[32];
	char szSerial[32];
	int iDiskUtilization;
	PERFORMANCE_TEST_TYPE testType;
	PERFORMANCE_TEST_RESULT readResult;
	PERFORMANCE_TEST_RESULT writeResult;
} PERFORMANCE_TEST_SCEMD_INFO;

// for db update
#define SZ_DISK_UPDATE_SERVER_URL "https://diskupdate.synology.com/getSSDsInfo/v2"
#define SZ_DISK_UPDATE_TEST_SERVER_URL "https://diskupdatetest.synology.com/getSSDsInfo/v2"

#define SZ_DISK_DB_UPDATE_TIMEOUT "10"
#define SZ_DISK_DB_UPDATE_RETRY "2"

#define SZF_DISK_SERVER_TMP_INFO "/tmp/diskserver.info"
#define SZF_DISK_UPDATE_TIME "/tmp/.disk_db_update_time"

#define SZF_DISK_SMART_DB "/var/lib/smartmontools/synodrivedb.db"
#define SZF_DISK_OPENSOURCE_SMART_DB "/var/lib/smartmontools/drivedb.db"
#define SZF_DISK_SMART_DB_VERSION "/var/lib/smartmontools/synodrivedb.version"
#define SZF_DISK_OPENSOURCE_SMART_DB_VERSION "/var/lib/smartmontools/drivedb.version"

#define SZF_DISK_TEMPERATURE_DB "/var/lib/temperature/disk_temperature.xml"
#define SZF_DISK_TEMPERATURE_DB_VERSION "/var/lib/temperature/disk_temperature.version"

#define SZK_DISK_DISK_SERVER_SMART "smart"
#define SZK_DISK_DISK_SERVER_TEMPERATURE "temperature"
#define SZK_DISK_DISK_SERVER_OPENSOURCE "opensource"

#define SZK_DISK_DISK_SERVER_DB_VERSION "ver"
#define SZK_DISK_DISK_SERVER_URL "url"

#define SZK_DISK_SERVER_TYPE "synodisk_server"
#define SZV_DISK_SERVER_TEST "test"

typedef enum _tag_DISK_DB_TYPE {
	DISK_DB_SMART,
	DISK_DB_OPENSOURCE_SMART,
	DISK_DB_TEMPERATURE
} DISK_DB_TYPE;

//Copied from kernel: include/linux/ata.h
#define	ATA_ICRC		(1 << 7)	/* interface CRC error */
#define ATA_UNC			(1 << 6)	/* uncorrectable media error */
#define ATA_IDNF		(1 << 4)	/* ID not found */
#define ATA_ABORTED		(1 << 2)	/* command aborted */

#define SERR_DATA_RECOVERED	(1 << 0) /* recovered data error */
#define SERR_COMM_RECOVERED	(1 << 1) /* recovered comm failure */
#define SERR_DATA			(1 << 8) /* unrecovered data error */
#define SERR_PERSISTENT		(1 << 9) /* persistent data/comm error */
#define SERR_PROTOCOL		(1 << 10) /* protocol violation */
#define SERR_INTERNAL		(1 << 11) /* host internal error */
#define SERR_PHYRDY_CHG		(1 << 16) /* PHY RDY changed */
#define SERR_PHY_INT_ERR	(1 << 17) /* PHY internal error */
#define SERR_COMM_WAKE		(1 << 18) /* Comm wake */
#define SERR_10B_8B_ERR		(1 << 19) /* 10b to 8b decode error */
#define SERR_DISPARITY		(1 << 20) /* Disparity */
#define SERR_CRC			(1 << 21) /* CRC error */
#define SERR_HANDSHAKE		(1 << 22) /* Handshake error */
#define SERR_LINK_SEQ_ERR	(1 << 23) /* Link sequence error */
#define SERR_TRANS_ST_ERROR	(1 << 24) /* Transport state trans. error */
#define SERR_UNRECOG_FIS	(1 << 25) /* Unrecognized FIS */
#define SERR_DEV_XCHG		(1 << 26) /* device exchanged */

#define SZ_MAILTAG_DISK_PORT_DISABLED	"DriveSlotDisabled"

#define NUMBER_OF_WARN_PERCENT_TYPE 8

#define DISK_CONTROL_XPATH 		"/scemd/"NODE_DISK_CTL_CONFIG"/"NODE_DISK_CONFIG
#define DISK_CONTROL_CUSTOM_XPATH	"/scemd/"NODE_DISK_CTL_CUSTOM"/"NODE_DISK_CONFIG
#define DISK_TEMPERATURE_XPATH  "/"NODE_DISK_OPERATING_TEMPERATURE"/"NODE_DISK_CONFIG

#define SZ_ADD_DISK			  "add"
#define SZ_REMOVE_DISK		  "remove"

#define DEFAULT_COMMON_PERIOD      0
#define DEFAULT_COMMON_THRESHOLD   0
#define DEFAULT_TIME_LAST_UPDATE   0
#define DEFAULT_MIN_OPERATING_TEMP -1000
#define DEFAULT_MAX_OPERATING_TEMP 1000
#define DEFAULT_M2_MIN_OPERATING_TEMP 0
#define DEFAULT_M2_MAX_OPERATING_TEMP 70

#define	MAX_USB_SHARE_NUMBER	16 //For usb share postfix number
#define	SIZE_GUID_BUF			256 //size for buffer storing GUID
#define SZF_ESATAGUID_MAP		"/tmp/esataguidtab"
#define SZF_ESATAGUID_SHARENO_MAP	"/usr/syno/etc/esatano_guid.map"
#define SZ_SATA_GUID "HAKULAMATATA" // for backforwarding of old esata strategy,
									// it should be removed if we don't maintain kernel 2.6.24 & 2.6.15 anymore
#define	MAX_CPRINTER_USB	1
#define	SZ_HDC                  "hdc"
#define	OP_USBLIST_ADD 0
#define	OP_USBLIST_REMOVE 1

#define BYTES_PER_SECTOR  512
#define FOUR_KN_DISK_BLOCK_SIZE 4096

#define MAX_HD_MODEL_LENGTH 40
#define MAX_DISK_ID_LENGTH 64

#define SZF_DISK_ERASING_PID	"/tmp/diskerasingpid"
#define SZ_HDPARM_CMD_PATH	"/usr/bin/hdparm"
#define SZK_HEALTH_REPORT_ENABLED	"health_report_enabled"

#define SZ_DISK_TYPE_HDD "HDD"
#define SZ_DISK_TYPE_SSD "SSD"

// for USB hibernation
#define SZF_STANDBY_TIME   "/tmp/standbytime"
#define	SZF_USB_DISKAPPLYING	"/tmp/usbdiskapplying"
#define	SZF_USBGUID_MAP		"/tmp/usbguidtab"//device name - GUID Map
#define	SZF_USBGUID_SHARENO_MAP	"/usr/syno/etc/usbno_guid.map" //GUID - share number Map
#define	SZF_USBINFOALL		"/tmp/usbinfoall"
#define	SZV_USB_USED	"used"
#define SZV_ESATA_USED	"esataused"
#define	SZV_USB_DISKFORMATTING	"formatting"
#define	SZV_USB_FAIL			"fail"
#define	SZV_USB_SUCCESS			"success"
#define	SZV_USB_FSCK			"fsck"
#define	SZV_USB_INIT			"init"
#define SZK_LAST_ROTATE			"last_rotate"
#define SZF_EXTERNAL_DEVICE_SETTING "/tmp/external_device_setting"

#define SZD_USB_DISK	"USB Disk "
#define SZD_SD_CARD		"SD Card "
#define SZF_PROC_PARTITIONS_PATH	"/proc/partitions"
#define	SZF_BAD_RQSIZE_DISK_LIST	"/proc/sys/kernel/syno_has_bad_rqsize_disk"
#define SZK_SYS_BLOCK_PATH 			"/sys/block"
#define SZK_DISK_STATE_RUNNING		"running"
#define SZF_SYSBLOCK_QUEUE_ROTATIONAL	"queue/rotational"
/* these sys/block/sdx/device/ files is defined in kernel drivers/ata/libata-scsi.c  */
#define SZF_SYSBLOCK_DEEPSLEEP_SUPPORT	"syno_deep_sleep_support"
#define SZF_SYSBLOCK_DEEPSLEEP_CTL		"syno_deep_sleep_ctrl"
#define SZF_SYSBLOCK_WCACHE_CTL			"syno_wcache"
#define SZF_SYSBLOCK_PWRRESET_COUNT		"syno_pwr_reset_count"

#define SZK_DISCARD_MAX_BYTES	"discard_max_bytes"
#define SZK_DISCARD_ZEROES_DATA	"discard_zeroes_data"

#define SZK_NORMAK_STANDBY_EN_KEY 	"standby_force"
#define SZK_SATA_DEEP_SLEEP_EN_KEY 	"sata_deep_sleep_en"
#define SZK_NORMAK_STANDBY_TIMER_KEY 	"standbytimer"
#define SZK_SATA_DEEP_SLEEP_TIMER_KEY 	"satadeepsleeptimer"
#define SZK_EUNIT_DEEP_SLEEP_TIMER_KEY 	"eunitdeepsleeptimer"
#define SZK_AUTO_POWEROFF_TIMER_KEY	"auto_poweroff_timer"
#define SZK_USB_STANDBY_TIMER_KEY	"usb_standbytimer"
#define SZK_SUPPORT_DISK_HIBERNATION_KEY "support_disk_hibernation"
#define SZK_DISK_WAKEUP_LOG_ENABLE_KEY		"disk_wakeup_log_en"
#define SZK_DISK_CACHE_EN_KEY	"diskcache"
#define SZF_SYSBLOCK_IDLE_TIME "syno_idle_time"
#define SZF_SYSBLOCK_STANDBY_SYNCING "syno_standby_syncing"
#define ISPARTITION(k) ('p' == *k && '0' <= (*(k+1)) && (*(k+1)) <= '9')
#define ISMMCBLK(s) (NULL != strstr(s,SZ_SDCARD_DEVICE))
#define ISM2CACHEDEV(s) (NULL != strstr(s,SZ_M2SATA_DEVICE_PREFIX))

#ifdef MY_DEF_HERE
#define ISNVMEDEV(s) (NULL != strstr(s,SZ_NVME_DEVICE_PREFIX))
#else
#define ISNVMEDEV(s) 0
#endif

#define SZF_SYNO_DISKNAME_TRANS		"syno_diskname_trans"
#define SZF_SCSI_HOST_PATH			"/sys/class/scsi_host/host"
#define SZD_ATA				"ata"
#define DISK_BUF_SIZE				256
#define FILEOP_RETRY_MAX	5

//for hotplug support multiple-partition mounts
#define HOTPLUG_SUPPORT_MULTIPLE_PARTITION	(1)
#define MAX_SYNO_DISK_PARTITION_COUNT (512)
#define MAX_SYNO_EXTERNAL_DISK_PARTITION_COUNT (16)
#define SYNO_PARTITION_LAYOUT_DATA_PARTITION_INDEX	(3)

#define SZK_SWAP_DISK "swap_disks"
#define SZ_RAID_DATA_VOL "/dev/md2"

#define SYNO_XML_FREE(node) \
do { \
	if (node) { \
		xmlFree(node); \
	} \
} while (0)

#define SZF_DHM_TOOL "/usr/syno/sbin/dhm_tool"
#define SZD_ADV_TEST "/var/log/healthtest/"

#define SYNO_DISK_IS_IRONWOLF 50
#define SYNO_DISK_IS_PRO_IRONWOLF 51
#define SZK_SUPPORT_IHM "support_ihm"

typedef enum _tag_SYNO_DISK_CODE {
	SYNO_DISK_CODE_NONE,
	SYNO_DISK_CODE_IRONWOLF,
	SYNO_DISK_CODE_IRONWOLF_PRO,
} SYNO_DISK_CODE;

// disk status debug tool related
#define SZF_DISK_STATUS_DEBUG_FILE "/tmp/.disk_status_debug"
#define SZK_DISK_STATUS_DEBUG_SMART_INFO "smart_info"
#define SZK_DISK_STATUS_DEBUG_SMART_TEST "smart_test"
#define SZK_DISK_STATUS_DEBUG_ADV_CODE "adv_code"
#define SZK_DISK_STATUS_DEBUG_UNC "unc"
#define SZK_DISK_STATUS_DEBUG_LIFE "life"
#define SZK_DISK_STATUS_DEBUG_SUPPORT_KEY "support_disk_status_debug"
#define SZK_NVME_STATUS_DEBUG_CRIT_WARN "crit"

//Not only for scsi disk protocol type
typedef enum _scsi_disk_scsi_protocol_type {
	SYNO_DISK_PROTOCOL_TYPE_NONE,
	SYNO_DISK_PROTOCOL_TYPE_SATA,
	SYNO_DISK_PROTOCOL_TYPE_SAS,
	SYNO_DISK_PROTOCOL_TYPE_NVME
}SYNO_DISK_SCSI_PROTOCOL_TYPE;

typedef enum _tag_SYNO_DISK_STATE_ {
	DISK_STATE_EMPTY,
	DISK_STATE_ABSENT,
	DISK_STATE_INIT,
	DISK_STATE_STATIC,
	DISK_STATE_FAILED,
#ifdef SYNO_BAD_SECTOR
	DISK_STATE_BADSYS,
	DISK_STATE_BADSECTOR,
#endif /* SYNO_BAD_SECTOR */
#ifdef SYNO_DISK_BADSECTOR
	DISK_STATE_BADSYSANDSECTOR,
	DISK_STATE_BADSECTOR,
	DISK_STATE_BADSYS,
#endif /* SYNO_DISK_BADSECTOR */
	DISK_STATE_NORMAL,
	DISK_STATE_REBUILT,
	DISK_STATE_HEALTHY,
} DISK_STATE;

typedef enum _tag_SYNO_DISK_SWAP_ACTION {
	DISK_INSERT_TO_SWAP,
	DISK_REMOVE_FROM_SWAP,
} SYNO_DISK_SWAP_ACTION;

typedef struct _tag_SYNO_USBDISK_INFO_ {
	int64_t cmbDiskSize;
} SYNOUSBDISKINFO, *PSYNOUSBDISKINFO;

typedef struct _tag_SYNO_LNX_DISK_INFO_ {
       char szDevice[128];
       char szModel[128];
       float usedSize;
       float totalSize;
       int temperature;
} SYNOLNXDISKINFO, *PSYNOLNXDISKINFO;

typedef struct _tag_SYNO_FREE_SPACE1_ {
	off_t offset;
	off_t size;
} SYNOFREESPACE1, *PSYNOFREESPACE1;

typedef struct _tag_SYNO_DISK_INFO1_ {
	int id;
	char szName[64];
	DISK_STATE state;
	off_t size;
	int nFree;
	SYNOFREESPACE1 rgFreeList[1];
} SYNODISKINFO1, *PSYNODISKINFO1;

typedef struct _tag_SYNO_DISK_ENUM_FILTER_ {
    const int *pContainer; //refer to DEV_LOCATION
} DISK_ENUM_FILTER;

typedef struct _tag_disk_id_{
	// FIXME: Be careful to use num or cnrIdx as host port index.
	// For some specific machines, the num can't be calculated correctly by its disk name.
	// See http://synowiki.synology.com/wiki/index.php/Platform_Information_Collection for more detail

	// disk number:
	// For an internal disk, sda-->1.
	// For an EUNIT_DEVICE, it indicates the disk number in the Ebox, e,g. sdgb-->2
	// For M.2 SATA / NVMe device, it indicates the card slot number (start from 1) in the card
	int num;
	DEV_LOCATION cnr; //container type
	// container port index.
	// For EUNIT device, it indicates the port number of DS machine (e.g. sdg-->7, sdga->7, sdgb->7)
	// Otherwise it is 0.
	int cnrIdx;
	int partNum;
	/*
	 * Used for those disk on controllor in the form of PCIe cards indxed by
	 * pci slot.
	 * Currently, used by M.2 SATA & NVMe.
	 * Values:
	 * -1: For legacy models don't need this information, include RS3413xs+ and RS10613xs+.
	 *  0: For those M.2 supported models which have solid M.2 slot, e.g. DS918+.
	 * >0: For those M.2 supported models which need M.2 adapter card.
	 */
	int pciSlot;
#ifdef MY_DEF_HERE
	int enclosureId;
#endif
} DISK_ID;

/**
 * Note: If you modify DISK_INFO, please also modify DISK_BASIC_INFO. 
 * The difference between DISK_INFO and DISK_BASIC_INFO is DISK_BASIC_INFO dosen't include temperature, because to get temperature, 
 * we need to do smart control, it's very slow, and in most of cases, we don't need disk temperature at all. (except scemd)
 */
typedef struct _tag_disk_info_ {
	DISK_ID id;
	char szName[16];
	char szPath[128];
	char szModel[128];
	unsigned long long ullTotalSize; //bytes
	int temperature;
#ifdef MY_DEF_HERE
	// FIXME: join enclosureId here to enclosureId in DISK_ID
	int enclosureId;
	// FIXME: join sasDiskOrder here to num in DISK_ID
	int sasDiskOrder;
#endif
	/**
	 * blErasing is true means the disk is running secure erase.
	 * At this time other operation to the disk may cause disk hang.
	 * Therefore, only "szPath" and "id" can be obtained.
	 *
	 * Also noted that we have renamed the device node during erasing.
	 * This is to prevent unexpected operations to the disk.
	 * Therefore, access to szPath will fail.
	 */
	BOOL blErasing;
	//To distinguish 4Kn and non-4Kn disk, for 4Kn disk the value is 4096, for non-4Kn disk the value is 512
	unsigned int logicalBlkSize;
} DISK_INFO;

typedef struct _tag_disk_info_list_ {
	DISK_INFO *pDisk;
	struct _tag_disk_info_list_ *pNext;
} DISK_INFO_LIST;

/**
 * Note: DISK_CACHED_INFO is used to save DISK_INFO, we expand the
 * structure in DISK_INFO
 */
typedef struct _tag_disk_cached_info_ {
//DISK_ID
	int DISK_ID_num;
	int DISK_ID_pciSlot;
	DEV_LOCATION DISK_ID_cnr;
	int DISK_ID_cnrIdx;
	int DISK_ID_partNum;
#ifdef MY_DEF_HERE
	int DISK_ID_enclosureId;
	// FIXME: join enclosureId here to enclosureId in DISK_ID
	int enclosureId;
	// FIXME: join sasDiskOrder here to num in DISK_ID
	int sasDiskOrder;
#endif
	char szName[16];
	char szPath[128];
	char szModel[128];
	unsigned long long ullTotalSize; //bytes
	int temperature;
	//To distinguish 4Kn and non-4Kn disk, for 4Kn disk the value is 4096, for non-4Kn disk the value is 512
	unsigned int logicalBlkSize;
} DISK_CACHED_INFO;

typedef struct _tag_disk_cached_info_list_ {
	DISK_CACHED_INFO *pDisk;
	struct _tag_disk_info_list_ *pNext;
} DISK_CACHED_INFO_LIST;

typedef enum{
	UNKNOWN_HIB_DEVICE = 0,
	EBOX_HIB_DEVICE,
	ENCLOSSURE_HIB_DEVICE,
	EUSB_HIB_DEVICE,
}DISK_HIBERNATION_DEVICE_TYPE;

typedef struct _tag_disk_hibernation_device_ {
	struct _tag_disk_hibernation_device_ * pNext;
	char szDevPath[128];
} DISK_HIBERNATION_DEVICE;

typedef struct _tag_disk_hibernation_info_ {
//DISK_ID
	BOOL blIntHibernation;
	DISK_HIBERNATION_DEVICE *pEboxHibIdxList;
	DISK_HIBERNATION_DEVICE *pEusbHibIdxList;
#ifdef MY_DEF_HERE
	DISK_HIBERNATION_DEVICE *pEnclossureIdxList;
#endif
} DISK_HIBERNATION_INFO;

typedef enum {
	INTERNAL_FULL,
	ESATA_DISK_FULL,
	ESATA_PARTITION_FULL,
	USB_DISK_FULL,
	USB_PARTITION_FULL,
	SD_CARD_FULL,
	SDCARD_PARTITION_FULL,
	INODE_FULL
} THRESHOLD_TYPE;

typedef enum {
	DISK_HISTORY_SINGLE_MONTH,
	DISK_HISTORY_INCREMENTAL
} DISK_HISTORY_TYPE;

typedef enum {
	DISK_OP_TEMP_NORMAL = 0,
	DISK_OP_TEMP_ABNORMAL = 1
} DISK_TEMPERATURE_STATE;

typedef struct __tag_SHARED_DISK_INFO {
	DISK_INFO basicInfo;
	int minTemperature;
	int maxTemperature;
	unsigned int uiThreshold;
	unsigned int uiCurThreshold;
	time_t timeLastUpdate;
	DISK_TEMPERATURE_STATE tempState;
	BOOL blDiskInHibernation;
} SHARED_DISK_INFO;

typedef struct __tag_SHARED_DISK_INFO_LIST {
	SHARED_DISK_INFO *pDisk;
	struct __tag_SHARED_DISK_INFO_LIST *pNext;
} SHARED_DISK_INFO_LIST;

typedef struct __tag_SHARED_RESOURCE_STATUS {
	unsigned int uiThreshold;
	SHARED_DISK_INFO_LIST  *pSharedResourceList;
} SHARED_RESOURCE_STATUS;

typedef struct __tag_DISK_CTL_INFO {
	char szModel[32];
	char szFirmware[32];
	char szSerial[32];
	char szAction[128];
	char szEunit[32];
	BOOL blInternalOnly;
}DISK_CTL_INFO;

typedef struct __tag_SYNO_DISK_CONTROL {
	int num;
	DISK_CTL_INFO *rgDiskControl;
} SYNO_DISK_CONTROL;

typedef struct __tag_SHARED_RESOURCE_HANDLE {
	/**
	 * The disk info list for internal and ebox disk. enclosure may add into it in the future.
	 */
	SHARED_DISK_INFO_LIST  *pSharedDiskList;
} SHARED_RESOURCE_HANDLE;

typedef struct __tag_DISK_HOTPLUG {
	char szAction[16]; //eg: remove or add
	char szPath[16];   //eg: /dev/sda
} DISK_HOTPLUG;

typedef struct __tag_DISK_HOTPLUG_QUEUE {
	DISK_HOTPLUG hotplugInfo;
	struct __tag_DISK_HOTPLUG_QUEUE *pNext;
} DISK_HOTPLUG_QUEUE;

typedef struct __tag_DISK_KERNEL_ERR {
	BOOL blShow; //show on UI or not
	char szErrorType[16]; //SZK_DISK_XML_RETRY,SERROR,ERROR
	unsigned int uiValue; //raw value
	char szText[256]; //text form
} DISK_KERNEL_ERR;

typedef struct __tag_DISK_LOG_LIST {
	char szTime[32];
	char szModel[32];
	char szSerial[32];
	char szPath[16];
	char szSlot[16];
	char szContainer[32];
#ifdef MY_DEF_HERE
	char szUnique[32];
#endif /* MY_DEF_HERE */
	char szEvent[32];
	struct __tag_DISK_LOG_LIST *pNext;
} DISK_LOG_LIST;

typedef struct _tag_DISK_PERF_LOG_LIST {
	char szTime[32];
	PERFORMANCE_TEST_SCEMD_INFO testInfo;
	struct _tag_DISK_PERF_LOG_LIST *pNext;
} DISK_PERF_LOG_LIST;

typedef struct __tag_DISK_KERNEL_ERR_CT {
	int iUncCt;
	int iIcrcCt;
	int iIdnfCt;
	int iRetryCt;
} DISK_KERNEL_ERR_CT;

typedef struct __tag_DISK_HEALTH_ATTR {
	int iUncCt; //include SMART attribute 5, 197, 198
	int iIdnfCt; //include kernel idnf count
	int iRetryCt; //include SMART attribute 199, kernel icrc count and kernel retry count
	int iRemainLife; // include SMART attribute 169, 173, 177, 202, 209, 231, 233
	char szRemainLifeAttr[64]; // represent remain life is got from which attribute
} DISK_HEALTH_ATTR;

// NOTE: Do not change the order or you should change /etc.defaults/disk_adv_status.conf
typedef enum _tag_DISK_ADV_STATUS_TYPE {
	DISK_ADV_STATUS_UNKNOWN,
	DISK_ADV_STATUS_NORMAL,
	DISK_ADV_STATUS_WARNING,
	DISK_ADV_STATUS_CRITICAL,
	DISK_ADV_STATUS_FAILING,
	DISK_ADV_STATUS_NOT_SUPPORT,
	DISK_ADV_STATUS_NOT_TEST,
} DISK_ADV_STATUS_TYPE;

#define SZF_DISK_ADV_STATUS_TABLE "/etc.defaults/disk_adv_status.conf"

typedef struct _tag_DISK_ADV_TEST_LOG_INFO {
	char szTime[32];
	char szDevice[32];
	char szModel[32];
	char szSerial[32];
	char szTestCode[32];
	char szDescSection[32];
	char szDescKey[32];
	DISK_ADV_STATUS_TYPE status;
	int iDamageWeight;
	BOOL blModifiable;
} DISK_ADV_TEST_LOG_INFO;

typedef struct _tag_DISK_ADV_TEST_LOG_LIST {
	DISK_ADV_TEST_LOG_INFO testInfo;
	struct _tag_DISK_ADV_TEST_LOG_LIST *pNext;
} DISK_ADV_TEST_LOG_LIST;

int DiskDeepSleepSupport(const char *szDevName);
int SYNODiskConfigAll(void);
int SYNOGetYearMonth(void);
int SYNODiskXmlParseHistory(char *szDevPath, DISK_HEALTH_ATTR *pDiskHealthAttr, const int iArraySize);
int SharedDiskInfoGet(const char *szDiskPath, SHARED_DISK_INFO **ppDisk);
int SYNOSetWcacheOffDiskDev(char *szDev);
int SharedDiskInfoNodeGetByPath(const char *szPath, SHARED_DISK_INFO_LIST *pDiskList, SHARED_DISK_INFO_LIST **pDiskNode);
int SharedDiskInfoNodeAdd(char *szPath, SHARED_DISK_INFO_LIST **ppDiskList);
int SharedDiskInfoNodeDelete(char *szPath, SHARED_DISK_INFO_LIST **ppDiskList);
int SYNODiskParseXmlOperatingTemp(char *szFile, SHARED_DISK_INFO *pDisk);
int SYNODiskXmlLogGet(DISK_LOG_LIST **ppDiskLogList);
void SYNODiskXmlLogFree(DISK_LOG_LIST *pDiskLogList);
void SharedDiskInfoEnumFree(SHARED_DISK_INFO_LIST **ppDiskList);
void SharedDiskListPush(SHARED_DISK_INFO_LIST **ppDiskList, SHARED_DISK_INFO *pDisk);
int SYNODiskConfigSingleDisk(char *szDev);
int SYNODiskParseConfigEnum(char *szFile, SYNO_DISK_CONTROL *pDiskControl, char *szDiskCtrlXpath, BOOL blAllowEmpty);
int SmartEnable(char *szDevice);
int SYNODiskHealthHistoryGet(char *szDevPath, DISK_HEALTH_ATTR *pDiskHealthAttr, const int iArraySize, const DISK_HISTORY_TYPE type);
int SYNODiskParseConfigEnumFree(SYNO_DISK_CONTROL *pDisk_ctl);
int SYNODiskParsingAction(char *szRaw, char *szDes, int len);
/* disk_current_health_get.c */
int SYNODiskCurHealthAttrGet(char *szDevice, DISK_HEALTH_ATTR *pDiskHealthAttr);
int SYNODiskCurHealthSmartAttrGet(char *szDevice, DISK_HEALTH_ATTR *pDiskHealthAttr);
int SynoWDIdleTimerSet(const char *szDev, unsigned char ucWDIdleTimer);
int SynoWDIdleTimerGet(char *szDev, unsigned char *pucWDIdleTimer);
int SYNODiskXmlKernelErrCtGet(char *szDevice, DISK_KERNEL_ERR_CT *pDiskKernelErrCt);
int SharedDiskListTransform(SHARED_DISK_INFO_LIST **ppSharedDiskList, DISK_INFO_LIST *pDiskList);
int SharedDiskInfoEnum(SHARED_DISK_INFO_LIST **ppSharedDiskList, const int iFilter);
int SharedResourceHandleCopy(SHARED_RESOURCE_HANDLE *pSourceHandle, SHARED_RESOURCE_HANDLE *pDestHandle);
/* disk_cache_enable_write.c */
int SYNODCacheEnableWrite(int flag);
/* disk_cache_is_write_enabled.c */
BOOL SYNODCacheIsWriteEnabled(void);
/* disk_enum.c */
int SYNODiskEnum(int level, PPVOID ppData);
/* disk_get_info.c */
int SYNODiskGetInfo(int level, int idDisk, PPVOID ppData);
/* disk_lnx_disk_get_info.c */
int SYNOLnxDiskGetInfo(PSYNOLNXDISKINFO pDiskInfo);
/* disk_get_file_wc_setting.c */
int SYNODiskGetFileWCSetting(void);
/* disk_is_ssd.c */
int SYNODiskIsSSD(char *szDev);
/* disk_set_standby_timer.c */
int SYNODiskGetStandbyTimer(int *pval, TIMER_TYPE TimerType);
/* disk_set_standby_timer.c */
int SYNODiskSetSleepTimer(const int iMin, TIMER_TYPE TimerType);
int SYNODiskSetStandbyTimer(const int minutes);
/* disk_get_usb_standby_timer.c */
int SYNODiskGetUSBStandbyTimer(int *pval);
/* disk_set_file_wc_setting.c */
int SYNODiskSetFileWCSetting(int flag);
/* disk_set_rc_power_config.c */
int SYNOSetRCPowerConfig(const int fRCPowerEnable);
/* disk_set_standby.c */
int SYNODiskSetDiskStandby(char *szDevPath, BOOL blFlush);
int SYNODiskSetStandby(BOOL esata);
int SYNODiskSetDeepSleep(void);
int SYNOCheckDeepSleep(void);
/* disk_set_usb_standby_timer.c */
int SYNODiskSetUSBStandbyTimer(int minutes);
/* disk_spinup_queue_set.c */
int SYNODiskSpinupQueueSet(char *szDevName);
/* disk_max_ssd_cache_get.c */
int SYNODiskMaxSSDCacheGet(void);
/* disk_is_spindown.c */
int SYNODiskIsSpindown(const char *szDevNamePath);
/* disk_all_idle_timer_get.c */
int SYNODiskAllIdleTimerGet(unsigned long *minidle);
/* disk_all_idle_timer_set.c */
int SYNODiskAllIdleTimerSet(unsigned long idletime);
/* disk_lnx_disk_get_vendor.c */
int SYNOLnxDiskGetVendor(char *szDevice, char *szVendor, int iLength);
/* disk_secure_erase_time_get.c */
int SLIBDiskSecureEraseTimeGet(char *szDevPath);
/* disk_logical_block_size_get.c */
int DiskLogicalBlockSizeGet(const char * szDevPath, int * pBlocksize);
/* disk_get_autopoweroff_timer.c */
int SYNODiskGetAutoPoweroffTimer(int *pval);
/* disk_set_autopoweroff_timer.c */
int SYNODiskSetAutoPoweroffTimer(int minutes);

/* disk_is_exist.c */
BOOL DiskIsExist(const char *szDiskPath);
/* disk_is_exist_in_cache.c */
BOOL DiskIsExistInCache(const char *szDiskPath);
/* disk_check_power.c */
int SYNOIDiskCheckPower(char *szDev, unsigned char *buf);
/* disk_container_get.c */
int DiskContainerGet(const char *szDev, DEV_LOCATION *pCnr);
/* disk_dd_status_get.c */
int DiskDDStatusGet(const char *szDevPath, unsigned long long *pUllDone, unsigned long long *pUllTotal);
/* disk_dev_get_postfix_number.c */
int SYNOIDevGetPostfixNumber(const char *szDevName, int *pNumber, DISK_PORT_TYPE diskport);
/* disk_flush_buffer.c */
int SYNOIDiskFlushBuffer(char *szDev);
/* disk_guid_get_postfix_number.c */
int SYNOIGUIDGetPostfixNumber(const char *szDevGUID, int *pNumber, DISK_PORT_TYPE diskport);
/* disk_info_enum.c */
int DiskInfoEnum(const DISK_ENUM_FILTER *pFilter, DISK_INFO_LIST **ppDiskList);
/* disk_info_enum.c */
int SLIBDiskInfoEnumToCache(DISK_HIBERNATION_INFO *pHibState);
/* disk_info_enum_free.c */
void DiskInfoEnumFree(DISK_INFO_LIST *pDiskList);
/* disk_info_free.c */
void DiskInfoFree(DISK_INFO *pDisk);
/* disk_info_get.c */
int DiskInfoGet(const char *szDiskPath, DISK_INFO **ppDisk);
/* disk_info_get.c */
int DiskInfoGetWithoutSMART(const char *szDiskPath, DISK_INFO **ppDisk);
/* disk_is_mv_soc_driver.c */
int SYNODiskIsMvSocDriver(char *szDev);
/* disk_list_push.c */
void DiskListPush(DISK_INFO_LIST **ppDiskList, DISK_INFO *pDisk);
/* disk_lnx_disk_get_model.c */
int SYNOLnxDiskGetModel(char *szDev, char *szModel, int iLength);
/* disk_modify_external_used_list.c */
int SYNOIModifyExternalUsedList(int number, int action, DISK_PORT_TYPE portType);
/* disk_partition_num_get.c */
int SYNODiskPartitionNumGet(const char *szDevPartName, char *szDevName, const int iLen);
/* disk_partition_num_remove.c */
int DiskPartitionNumRemove(const char *szPartPath, char *szDiskPath, int cbDiskPath);
/* disk_path_parse.c */
int DiskPathParse(const char *szPath, DISK_ID *pDiskID);
/* disk_raw_open.c */
int SYNOIDiskRawOpen(const char *szDev);
/* disk_read_one_sector_from_dev.c */
int SYNOReadOneSectorFromDev(const char *szDevName, unsigned long ulOffset, void *pSector);
/* disk_set_disk_standby.c */
int SYNOIDiskSetDiskStandby(char *szDev);
/* disk_size_get.c */
int DiskSizeGet(const char *szDevPath, unsigned long long *pullSectors);
/* disk_temperature_get.c */
int SYNODiskTemperatureGet(char *szDevice);
int SYNODiskTemperatureGetFromCache(char* szDevice);
/* disk_usb_check_all_dev_unmount.c */
int SYNOUSBCheckAllDevUnmount(void);
/* disk_scsi_protocol_get.c */
SYNO_DISK_SCSI_PROTOCOL_TYPE SYNODiskScsiProtocolGet(char *szDevPath);
/* disk_usb_gen_postfix_number.c */
int SYNOIGenPostfixNumber(const char *szDevName, DISK_PORT_TYPE portType);
/* disk_usb_get_info.c */
int SYNODiskUSBGetInfo(const char *szDevName, SYNOUSBDISKINFO *pdinfoUSB);
/* disk_usb_roll_back_post_fix_number_map.c */
int SYNOUSBRollBackPostFixNumberMap(int number, char *szOrigGUID);
/* disk_write_cache_get.c */
BOOL SYNODiskWriteCacheGet(char *szDev);
/* disk_write_cache_set.c */
int SYNODiskWriteCacheSet(char *szDev, int flag);
/* disk_sys_device_path_get.c */
int SYNODiskSysDevicePathGet(char *szDevPath, int leng);
/* disk_first_data_device_path_get.c */
int SYNODiskFirstDataDevicePathGet(char *szDevPath, int leng);
/* disk_device_partition_path_get.c */
int SYNODiskDevicePartitionPathGet(const char *szDevName, int partitionNum, char *szPartitionPath, int leng);
/* disk_device_path_get_by_position.c */
int SYNODiskDevicePathGetByPosition(const int diskNo, const int enclosureId, char *szDevPath, const int leng);
/* disk_device_partition_name_get.c */
int SYNODiskDevicePartitionNameGet(const char *szDevName, int partitionNum, char *szPartitionPath, int leng);
/* Get disk container type */
int SYNODiskPortToContainer(DISK_PORT_TYPE diskport, DEV_LOCATION *pCnr);
#if defined(MY_DEF_HERE)
/* disk_sas_path_parse.c */
int SYNOSASModelDiskPathParse(const char *szDiskPath, int *diskId, int *enclosureId, int *partitionNum, DISK_PORT_TYPE *portType);
#endif // defined(MY_DEF_HERE)
/* disk_device_path_get_by_index.c */
int SYNODiskDevicePathGetByIndex(const int uiDiskIdx, char *szDevPath, const int leng);
/* disk_is_running.c */
BOOL SYNODiskIsRunning(char *szDevice);
/* disk_serial_get.c */
int DiskSerialGet(const char *szDiskPath, char *szOutSerial, int cbSerial);
/* disk_dd_kill.c */
int DiskDDKill(const char *szDevPath);
/* disk_get_cnridx_shift.c */
int DiskGetLocation(const DISK_ID *diskID, const char *szDevPartName, unsigned int *containerID, unsigned int *diskOrder);
/* disk_is_assigned_to_swap.c */
int SYNODiskIsDiskAssignedToSwap(const char *szDevPath);
/* disk_assign_to_swap.c */
int SYNODiskAssignToSwap(const char *szDevPath, SYNO_DISK_SWAP_ACTION action);
/* disk_external_register_post_fix_number.c */
int SYNOExternalRegisterPostFixNumber(const char *szDevName, int *pnumber, char *szOldGUID, int bufsize, int number, DISK_PORT_TYPE portType);
/* disk_is_secure_erasing.c */
int SLIBDiskIsSecureErasing(char *szDevPath);
/* disk_secure_erase_num_get.c */
int SLIBDiskSecureEraseNumGet(void);
/* disk_get_devname_by_ata_port.c */
int SYNODiskGetDevnamebyAtaPort(char *szDevName, const int len, const char *szAtaPort);
/* disk_flush_buffer fs.c */
int SYNOIDiskFlushBufferFS(char *szDev);
/* disk_hibernation_list_delete.c */
int DiskEnumHibDevDel(char* szPath, DISK_HIBERNATION_INFO **pHibInfo, DISK_HIBERNATION_DEVICE_TYPE DevType);
/* disk_hibernation_list_push.c */
int DiskEnumHibDevPush(char* szPath, DISK_HIBERNATION_INFO **pHibInfo, DISK_HIBERNATION_DEVICE_TYPE DevType);
/* disk_hibernation_list_free.c */
void DiskHibernationInfoFree(DISK_HIBERNATION_INFO *pHibInfo);
/* disk_is_mv_1475_driver.c */
int SYNODiskIsMv1475Driver(char *szDev);
/* disk_is_below_life_thr.c */
int SYNODiskIsBelowLifeThr(const char *szDevice, int *piSuppress, int *piDisable);
/* disk_is_below_life_thr_cache.c */
int SYNODiskIsBelowLifeThrCache(const char *szDevice);
/* disk_remain_life_info_get.c */
int SYNODiskRemainLifeInfoGet(const char *szDevice, char *szRemainLifeAttr, int cbRemainLifeAttr, int *iRemainLife, int *piSuppress, int *piDisable);
/* disk_is_below_life_thr_with_value.c */
int SYNODiskIsBelowLifeThrWithValue(const char *szDevice, int iRemainLife, int *piSuppress, int *piDisable);
/* disk_md1_able_to_remove.c */
int SYNODiskMd1AbleToRemove(const char *szDevice);
/* disk_md1_remove.c */
int SYNODiskMd1Remove(const char *szDevice);
/* disk_update_check_file.c */
int SYNODiskUpdateCheckFile(const char* szFilePath, BOOL blAdd);
/* disk_md1_recover.c */
int SYNODiskMd1Recover(const char *szDevice);
/* disk_exceed_unc_thr.c */
int SYNODiskExceedUncThr(const char *szDevice, int *piSuppress, int *piDisable);
/* disk_exceed_unc_thr_cache.c*/
int SYNODiskExceedUncThrCache(const char *szDevice);
/* disk_exceed_unc_thr_with_value.c*/
int SYNODiskExceedUncThrWithValue(const char* szDevice, int iUncCt, int *piSuppress, int *piDisable);
/* disk_exceed_unc_thr_disk_err_get.c */
int SYNODiskExceedUncThrDiskErrGet(void);
/* disk_fio_performance_unit_test.c */
int SYNODiskFioPerformanceUnitTest(const char *szDevice, int iRuntime, PERFORMANCE_TEST_OP_TYPE opType, PERFORMANCE_TEST_METHOD_TYPE methodType, PERFORMANCE_TEST_TYPE testType, PERFORMANCE_TEST_RESULT *result);
/* disk_performance_test.c */
int SYNODiskPerformanceTest(const char *szDevice, PERFORMANCE_TEST_OP_TYPE opType, PERFORMANCE_TEST_TYPE testType, PERFORMANCE_TEST_RESULT *result);
/* disk_parse_xml_disk_perf_log.c */
int SYNODiskXmlPerfLogGet(DISK_PERF_LOG_LIST **ppDiskPerfLogList);
void SYNODiskXmlPerfLogFree(DISK_PERF_LOG_LIST *pDiskPerfLogList);
/* disk_is_performance_testing.c */
int SYNODiskIsPerformanceTesting(const char *szDevice);
/* disk_index_get.c */
int DiskIndexGet(const char *szDevName);
/* disk_index_pci_slot_get.c */
int DiskIndexAndSlotGet(const char *szDevPath, int *pIndex, int *pPciSlot);
/* disk_dev_name_get_by_idx_slot.c */
int DiskDevNameGetByIdxSlot(int pciSlot, int cardIndex,
							char *szDevName, int cbDevName);
/* disk_update_cache_file.c */
int SYNODiskUpdateIntValueCacheFile(const char *szDiskName, const char *szCacheFileName, int iValue);
int SYNODiskUpdateStrValueCacheFile(const char *szDiskName, const char *szCacheFileName, const char *szValue);
/* disk_performance_test_num_get.c */
int SYNODiskPerformanceTestNumGet(void);
/* disk_sort_by_eboxid_and_diskid.c */
int SYNODiskSortByEboxIdAndDiskId(DISK_INFO_LIST *pDiskList);
/* disk_mail_disk_name_get.c */
int SYNODiskMailDiskNameGet(DISK_INFO *pDisk, char *szDiskName, int cbDiskName);
/* disk_sas_remaining_life_get.c */
int SYNODiskSASRemainingLifeGet(char *szDevice, int *piRemainingLife);
/* disk_mail_send.c */
int SYNODiskMailSend(const char* szDevice);
/* disk_db_update.c */
int DiskDbUpdate(void);
/* disk_db_update_need.c */
BOOL DiskDbUpdateNeed(void);
/* disk_dhm_support.c */
BOOL SYNODiskDHMSupportCheck(char *szDevice);
/* disk_scsi_generic_get.c */
int SYNODiskScsiGenericGet(char *szDiskPath, char *szDevSg, const int cbDevSg);
/* disk_adv_status_get.c */
int SYNODiskAdvStatusGet(const char *szDevice, char *szStatus, int cbStatus, int *piWeight, BOOL *pblModifiable, BOOL *pblModified,
		char *szTestCode, int cbTestCode, char *szDescSection, int cbDescSection, char *szDescKey, int cbDescKey);
/* disk_adv_status_cache_get.c */
int SYNODiskAdvStatusCacheGet(const char *szDevice, char *szStatus, char *szProgress, int *piWeight);
/* disk_adv_status_transfer.c */
int SYNODiskAdvStatusTransfer(DISK_ADV_STATUS_TYPE status, char *szStatus, int cbStatus);
/* disk_adv_status_mapping.c */
DISK_ADV_STATUS_TYPE SYNODiskAdvStatusMapping(const char *testCode, char *szStatus, int cbStatus, char *szDescSection, int cbDescSection, char *szDescKey, int cbDescKey, char *szDamageLevel, int cbDamageLevel, BOOL *blModifiable);
/* disk_adv_test_record.c */
int SYNODiskAdvTestResultRecord(const char *szDevPath, const char *szTestCode);
/* disk_adv_test_get.c */
int SYNODiskAdvTestResultLogGet(const char *szDevice, DISK_ADV_TEST_LOG_LIST **ppDiskAdvLogList);
void SYNODiskAdvTestResultLogFree(DISK_ADV_TEST_LOG_LIST *pDiskAdvLogList);
/* disk_adv_status_init.c */
int SYNODiskAdvStatusInit(const char *szDiskName);
/* disk_status_debug_get.c */
int SYNODiskStatusDebugGet(const char *szDevice, DISK_SMART_INFO_LIST **smartInfoList, DISK_SMART_TEST_RESULT *pSmartTestResult, char *szAdvTestCode, int cbAdvTestCode, int *piUnc, int *piLife);
#ifdef MY_DEF_HERE
/* nvme_status_debug_get.c */
int SYNONVMeStatusDebugGet(const char *szDevice, int *pAvailSpare, int *pCritWaring);
#endif
/* disk_overview_semaphore.c */
BOOL SYNODiskOverviewWait(void);
BOOL SYNODiskOverviewSignal(void);
/* disk_overview_model_check.c */
BOOL SYNODiskOverviewModelCheck(const char *szModel);
/* disk_is_ironwolf.c */
SYNO_DISK_CODE SYNODiskIsIronWolf(const char *szDevice);
/* disk_is_ironwolf_cache.c */
SYNO_DISK_CODE SYNODiskIsIronWolfCache(const char *szDevice);
/* disk_locate_host_get.c */
int SYNODiskLocateHostGet(const char* szDevice, char *szContainer, int cbContainer, BOOL blNeedDsModelName);
/* disk_config_match.c */
BOOL SYNODiskConfigMatch(char *pszModelName, char *pszModelRegularName, const int iComFlags, const int iExecFlags, const BOOL blFullMatch);
/* disk_id_to_string.c */
int DiskIdToString(const DISK_ID *pDiskID, char *szDevName, int cbDevName);
/* disk_ihm_skip.c */
BOOL SYNODiskIhmSkipCheck(const char *szDevice);

__END_DECLS;
#endif /* __SYNO_HWCTL_DISK_H_ */
