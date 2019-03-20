#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_SMARTCTL_H_
#define __SYNO_HWCTL_SMARTCTL_H_

#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZD_DISKS_STATUS_CACHE "/run/synostorage/disks/"
#define SZF_DISK_STATUS_UPDATING_FLAG "updating"
#define SZF_DISK_FIRM_CACHE_FILE "firm"
#define SZF_DISK_SERIAL_CACHE_FILE "serial"
#define SZF_DISK_SMART_CACHE_FILE "smart"
#define SZF_DISK_SMART_PROGRESS_CACHE_FILE "smart_progress"
#define SZF_DISK_TEMPERATURE_CACHE_FILE "temperature"
#define SZF_DISK_ERASE_TIME_CACHE_FILE "erase_time"
#define SZF_DISK_ERASE_START_TIME_CACHE_FILE "erase_start_time"
#define SZF_DISK_TYPE_CACHE_FILE "type"
#define SZF_DISK_SMART_TESTING_FLAG "smart_testing"
#define SZF_DISK_REMAIN_LIFE_CACHE_FILE "remain_life"
#define SZF_DISK_BELOW_REMAIN_LIFE_THR_CACHE_FILE "below_remain_life_thr"
#define SZF_DISK_BAD_SEC_CT_CACHE_FILE "bad_sec_ct"
#define SZF_DISK_EXC_BAD_SEC_CT_CACHE_FILE "exc_bad_sec_ct"
#define SZF_DISK_PERF_TEST_PID_CACHE_FILE "perf_test"
#define SZF_DISK_ADV_STATUS_CACHE_FILE "adv_status"
#define SZF_DISK_ADV_PROGRESS_CACHE_FILE "adv_progress"
#define SZF_DISK_ADV_TEST_CACHE_FILE "adv_test"
#define SZF_DISK_ADV_STATUS_DAMAGE_WEIGHT_CACHE_FILE "adv_damage_weight"
#define SZF_DISK_SMART_DAMAGE_WEIGHT_CACHE_FILE "smart_damage_weight"
#define SZF_DISK_IRONWOLF_CACHE_FILE "ironwolf"
#define SZF_DISK_MODEL_CACHE_FILE "model"
#define SZF_DISK_VENDOR_CACHE_FILE "vendor"
#define SZF_DISK_SMART_NVME_CRIT_WARN_CACHE_FILE "critical_warning"

#define DISK_HEALTH_WEIGHT_SMART_TEST_NORMAL 0
#define DISK_HEALTH_WEIGHT_SMART_TEST_NORMAL_PAST 0
#define DISK_HEALTH_WEIGHT_SMART_TEST_FAIL 60
#define DISK_HEALTH_WEIGHT_SMART_INFO_NORMAL 0
#define DISK_HEALTH_WEIGHT_SMART_INFO_NORMAL_PAST 0
#define DISK_HEALTH_WEIGHT_SMART_INFO_FAIL_NON_CRITICAL 16
#define DISK_HEALTH_WEIGHT_SMART_INFO_FAIL_CRITICAL 50
#define DISK_HEALTH_WEIGHT_SSD_LIFE_DANGER 31
#define DISK_HEALTH_WEIGHT_SSD_LIFE_EXCEED_THR 1
#define DISK_HEALTH_WEIGHT_UNC_EXCEED_THR 10
#define NVME_HEALTH_WEIGHT_SMART_INFO_NORMAL 0
#define NVME_HEALTH_WEIGHT_SMART_INFO_DEGRADED 16
#define NVME_HEALTH_WEIGHT_SMART_INFO_FAIL 50
#define NVME_HEALTH_WEIGHT_SSD_LIFE_EXCEED_THR 1
#define NVME_HEALTH_WEIGHT_CRIT_WARN_OVER_HEART 1

#define DISK_HEALTH_WEIGHT_SMART_DEGRADED_THRE 1 /* 1 ~ 30 */
#define DISK_HEALTH_WEIGHT_SMART_FAILING_THRE 31 /* 31 ~ */
#define DISK_HEALTH_WEIGHT_ADV_WARNING_THRE 1 /* 1 ~ 30 */
#define DISK_HEALTH_WEIGHT_ADV_CRITICAL_THRE 31 /* 31 ~ 59*/
#define DISK_HEALTH_WEIGHT_ADV_FAILING_THRE 60 /* 60 ~ */
#define DISK_HEALTH_WEIGHT_OVERVIEW_WARNING_THRE 1 /* 1 ~ 30 */
#define DISK_HEALTH_WEIGHT_OVERVIEW_CRITICAL_THRE 31 /* 31 ~ 59 */
#define DISK_HEALTH_WEIGHT_OVERVIEW_FAILING_THRE 60 /* 60 ~ */

#define DISK_HEALTH_WEIGHT_SMART_TEST_THRE 60

typedef enum {
	SMART_COMMAND_SET_ATA_ENABLE,
	SMART_COMMAND_SET_ATA_READ_VALUES,
	SMART_COMMAND_SET_ATA_READ_THRESHOLDS,
	SMART_COMMAND_SET_ATA_READ_LOG,
	// returns 1 byte of data
	SMART_COMMAND_SET_ATA_CHECK_POWER_MODE,
	// writes 512 bytes of data:
	SMART_COMMAND_SET_ATA_IDLE,
	SMART_COMMAND_SET_ATA_STANDBY_IMMEDIATE,
	SMART_COMMAND_SET_ATA_IDENTIFY,
	SMART_COMMAND_SET_ATA_PIDENTIFY,
	/* this is a virtual command, no such ata command */
	SMART_COMMAND_SET_ATA_WAIT_FLUSH,
	SMART_COMMAND_SET_SCSI_INQUIRY,
	SMART_COMMAND_SET_SCSI_INQUIRY_VPD,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_READ_ERROR_COUNTER_LPAGE,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_WRITE_ERROR_COUNTER_LPAGE,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_VERIFY_ERROR_COUNTER_LPAGE,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_TEMP,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_BACKGROUND,
	SMART_COMMAND_SET_SCSI_LOG_SENSE_SELFTEST_LOG,
	SMART_COMMAND_SET_SCSI_MODE_SELECT,
	SMART_COMMAND_SET_SCSI_MOD_SENSE_CURRENT,
	SMART_COMMAND_SET_SCSI_MOD_SENSE_CHANGABLE,
	SMART_COMMAND_SET_SCSI_MOD_SENSE_TEST_TIME,
	SMART_COMMAND_SET_SCSI_REQUEST_SENSE,
	SMART_COMMAND_SET_SCSI_START_STOP,
	SMART_COMMAND_SCSI_SYNCHRONIZE_CACHE,
	SMART_COMMAND_SCSI_TEST_UNIT_READY,
	SMART_COMMAND_SET_ATA_READ_LOG_DIR,
} SMART_COMMAND_SET;

#define STRANGE_BUFFER_LENGTH (4+512*0xf8)
#define NUMBER_ATA_SMART_ATTRIBUTES     30
#define ASSERT_SIZEOF_STRUCT(s, n) \
  typedef char assert_sizeof_struct_##s[(sizeof(struct s) == (n)) ? 1 : -1]

/* Vendor attribute of SMART Threshold (compare to ata_smart_attribute above) */
struct ata_smart_threshold_entry {
	unsigned char id;
	unsigned char threshold;
	unsigned char reserved[10];
} __attribute__((packed));

/* Format of Read SMART THreshold Command */
/* Compare to ata_smart_values above */
struct ata_smart_thresholds_pvt {
	unsigned short int revnumber;
	struct ata_smart_threshold_entry thres_entries[NUMBER_ATA_SMART_ATTRIBUTES];
	unsigned char reserved[149];
	unsigned char chksum;
} __attribute__((packed));

#pragma pack(1)
struct ata_smart_attribute {
	unsigned char id;
	// meaning of flag bits: see MACROS just below
	// WARNING: MISALIGNED!
	unsigned short flags; 
	unsigned char current;
	unsigned char worst;
	unsigned char raw[6];
	unsigned char reserv;
};
#pragma pack()
ASSERT_SIZEOF_STRUCT(ata_smart_attribute, 12);

#pragma pack(1)
struct ata_smart_values {
	unsigned short int revnumber;
	struct ata_smart_attribute vendor_attributes [NUMBER_ATA_SMART_ATTRIBUTES];
	unsigned char offline_data_collection_status;
	unsigned char self_test_exec_status;  //IBM # segments for offline collection
	unsigned short int total_time_to_complete_off_line;	// IBM different
	unsigned char vendor_specific_366; // Maxtor & IBM curent segment pointer
	unsigned char offline_data_collection_capability;
	unsigned short int smart_capability;
	unsigned char errorlog_capability;
	unsigned char vendor_specific_371;	// Maxtor, IBM: self-test failure checkpoint see below!
	unsigned char short_test_completion_time;
	unsigned char extend_test_completion_time;
	unsigned char conveyance_test_completion_time;
	unsigned short extend_test_completion_time_w;
	unsigned char reserved_377_385[9];
	unsigned char vendor_specific_386_510[125];	// Maxtor bytes 508-509 Attribute/Threshold Revision #
	unsigned char chksum;
};
#pragma pack()
ASSERT_SIZEOF_STRUCT(ata_smart_values, 512);

// Table 45 of T13/1321D Rev 1 spec (Self-test log descriptor entry)
struct ata_smart_selftestlog_struct {
	unsigned char selftestnumber; // Sector number register
	unsigned char selfteststatus;
	unsigned short int timestamp;
	unsigned char selftestfailurecheckpoint;
	unsigned int lbafirstfailure;
	unsigned char vendorspecific[15];
} __attribute__((packed));

// Table 44 of T13/1321D Rev 1 spec (Self-test log data structure)
struct ata_smart_selftestlog {
	unsigned short int revnumber;
	struct ata_smart_selftestlog_struct selftest_struct[21];
	unsigned char vendorspecific[2];
	unsigned char mostrecenttest;
	unsigned char reserved[2];
	unsigned char chksum;
} __attribute__((packed));

// SMART LOG DIRECTORY Table 52 of T13/1532D Vol 1 Rev 1a
struct ata_smart_log_entry {
	unsigned char numsectors;
	unsigned char reserved;
} __attribute__((packed));

struct ata_smart_log_directory {
	unsigned short int logversion;
	struct ata_smart_log_entry entry[255];
} __attribute__((packed));

// Needed parts of the ATA DRIVE IDENTIFY Structure. Those labeled
// word* are NOT used.
struct ata_identify_device {
	unsigned short words000_009[10];
	unsigned char  serial_no[20];
	unsigned short words020_022[3];
	unsigned char  fw_rev[8];
	unsigned char  model[40];
	unsigned short words047_079[33];
	unsigned short major_rev_num;
	unsigned short minor_rev_num;
	unsigned short command_set_1;
	unsigned short command_set_2;
	unsigned short command_set_extension;
	unsigned short cfs_enable_1;
	unsigned short word086;
	unsigned short csf_default;
	unsigned short words088_255[168];
} __attribute__((packed));

typedef int (*smart_interface)(int, SMART_COMMAND_SET, unsigned char *);

// ATA Specification Command Register Values (Commands)
#define ATA_STANDBY_IMMEDIATE		0xe0
#define ATA_IDLE			0xe3
#define ATA_CHECK_POWER_MODE		0xe5
// ATA Specification Feature Register Values (SMART Subcommands).
// Note that some are obsolete as of ATA-7.
#define ATA_SMART_READ_VALUES           0xd0
#define ATA_SMART_READ_LOG_SECTOR       0xd5
#define ATA_SMART_READ_THRESHOLDS       0xd1
#define ATA_SMART_ENABLE                0xd8
#define ATA_IDENTIFY_DEVICE             0xec
#define ATA_IDENTIFY_PACKET_DEVICE      0xa1

// SFF 8035i Revision 2 Specification Feature Register Value (SMART
// Subcommand)
#define ATA_SMART_AUTO_OFFLINE          0xdb

#define HDIO_DRIVE_CMD            0x031f

#define ATA_SMART_CMD                   0xb0

/* SMART attributes, you can reference
 * http://en.wikipedia.org/wiki/S.M.A.R.T. for more details */
#define SMART_ATTR_SPIN_UP_TIME 3
#define SMART_ATTR_MSEC24_HOUR32 9
#define SMART_ATTR_REALLOCATED_SECTOR_CT 5
#define SMART_ATTR_TEMP 194
#define SMART_ATTR_AIRFLOW_TEMP 190
#define SMART_ATTR_REALLOCATED_Event_Count 196

// This value should be larger than ata_smart_values.
#define SMART_READ_VALUE_BUF_SIZE 512

/* ANSI SCSI-3 Log Pages retrieved by LOG SENSE. */
#define SUPPORTED_LPAGES                        0x00
#define BUFFER_OVERRUN_LPAGE                    0x01
#define WRITE_ERROR_COUNTER_LPAGE               0x02
#define READ_ERROR_COUNTER_LPAGE                0x03
#define READ_REVERSE_ERROR_COUNTER_LPAGE        0x04
#define VERIFY_ERROR_COUNTER_LPAGE              0x05
#define NON_MEDIUM_ERROR_LPAGE                  0x06
#define LAST_N_ERROR_LPAGE                      0x07
#define FORMAT_STATUS_LPAGE                     0x08
#define TEMPERATURE_LPAGE                       0x0d
#define STARTSTOP_CYCLE_COUNTER_LPAGE           0x0e
#define APPLICATION_CLIENT_LPAGE                0x0f
#define SELFTEST_RESULTS_LPAGE                  0x10
#define BACKGROUND_RESULTS_LPAGE                0x15   /* SBC-3 */
#define IE_LPAGE                                0x2f

/**
 * offline_data_collection_capability save disk smart capability.  0x10 means self test supported or not.
 * 
 * @param data smart value
 * 
 * @return 1:support self test
 *         0:not implement self test
 */
static inline
int isSupportSelfTest (struct ata_smart_values *data){
   return data->offline_data_collection_capability & 0x10;
}

#define SZF_SMART_SCHEDULE_INFO "/usr/syno/etc/smarttasks.info"
#define SZF_QUICK_TEST_LOG "/var/log/smart_quick_log"
#define SZF_EXTEND_TEST_LOG "/var/log/smart_extend_log"
#define SZK_SMART_LOG_TIME "_TIME"
#define SZK_SMART_LOG_STATUS "_STATUS"
#define SZK_SMART_LOG_NEW "_NEW"
#define SZK_SMART_DESC_QUICK_SEL "\"#smart:smart_desc_quick_sel#\""
#define SZK_SMART_DESC_QUICK_ALL "\"#disk_info:disk_smart_test_quick_all#\""
#define SZK_SMART_DESC_EXTEND_SEL "\"#smart:smart_desc_extend_sel#\""
#define SZK_SMART_DESC_EXTEND_ALL "\"#disk_info:disk_smart_test_extend_all#\""
#define SZP_SMART_TEST "/usr/syno/bin/syno_smart_test"
#define SZK_SMART_NAMESPACE "\"SYNO.SDS.TaskScheduler.SMART\""
#define SZK_SMART_APP_NAME "\"#smart:smart_toolbar_smart_test#\""
#define SZF_SMARTCTL "/usr/bin/smartctl"

#define SZF_ADV_TEST "/usr/syno/bin/syno_adv_test"
#define SZK_ADV_TEST_APP_NAME "\"#disk_info:disk_ironwolf_test#\""
#define SZK_ADV_TEST_DESC_ALL "\"#disk_info:disk_ironwolf_test_action_type_all#\""
#define SZK_ADV_TEST_DESC_SEL "\"#disk_info:disk_ironwolf_test_action_type_sel#\""

#define SZK_HEALTH_TEST_APP_NAME "\"#disk_info:disk_health_test#\""
#define SZK_HEALTH_TEST_DESC_QUICK_ALL "\"#disk_info:disk_health_test_action_quick_type_all#\""
#define SZK_HEALTH_TEST_DESC_EXTEND_ALL "\"#disk_info:disk_health_test_action_extend_type_all#\""
#define SZK_HEALTH_TEST_DESC_QUICK_SEL "\"#disk_info:disk_health_test_action_quick_type_sel#\""
#define SZK_HEALTH_TEST_DESC_EXTEND_SEL "\"#disk_info:disk_health_test_action_extend_type_sel#\""

typedef struct {
	char szDevPath[16];
	char szAction[16];
	int  iWeekDays;
	int  iHour;
	int  iMinute;
} SMARTTASK;

typedef enum {
	DISK_SMART_ATTR_STATUS_OK,
	DISK_SMART_ATTR_STATUS_IN_THE_PAST,
	DISK_SMART_ATTR_STATUS_FAILED,
} DISK_SMART_ATTR_STATUS;

typedef enum {
	DISK_SMART_TEST_RESULT_UNKNOWN,
	DISK_SMART_TEST_RESULT_COMPLETE,
	DISK_SMART_TEST_RESULT_ABORTED,
	DISK_SMART_TEST_RESULT_INTERRUPT,
	DISK_SMART_TEST_RESULT_DAMAGE,
	DISK_SMART_TEST_RESULT_PROGRESS,
	DISK_SMART_TEST_RESULT_NORESULT,
} DISK_SMART_TEST_RESULT;

typedef enum {
	DISK_SMART_TOTAL_STATUS_UNKNOWN,
	DISK_SMART_TOTAL_STATUS_NORMAL,
	DISK_SMART_TOTAL_STATUS_DEGRADED,
	DISK_SMART_TOTAL_STATUS_FAILING,
} DISK_SMART_TOTAL_STATUS;

typedef enum {
	DISK_SMART_TEST_STATUS_UNKNOWN,
	DISK_SMART_TEST_STATUS_NORMAL,
	DISK_SMART_TEST_STATUS_NORMAL_PAST, // fail in the past but normal now
	DISK_SMART_TEST_STATUS_FAIL,
} DISK_SMART_TEST_STATUS;

typedef enum {
	DISK_SMART_INFO_STATUS_UNKNOWN,
	DISK_SMART_INFO_STATUS_NORMAL,
	DISK_SMART_INFO_STATUS_NORMAL_SUPPRESS, // fail in the past but suppress now
	DISK_SMART_INFO_STATUS_NORMAL_PAST, // fail in the past but normal now
	DISK_SMART_INFO_STATUS_NORMAL_DISABLE, // fail in the past but disable now
	DISK_SMART_INFO_STATUS_FAIL_SOFT,
	DISK_SMART_INFO_STATUS_FAIL_HARD,
	DISK_SMART_INFO_STATUS_NORMAL_REPEAT_SUPPRESS, // fail in the past but repeatedly suppress now
} DISK_SMART_INFO_STATUS;

typedef enum {
	DISK_SMART_OVERVIEW_STATUS_UNKNOWN,
	DISK_SMART_OVERVIEW_STATUS_NORMAL,
	DISK_SMART_OVERVIEW_STATUS_UNC,
	DISK_SMART_OVERVIEW_STATUS_WARNING,
	DISK_SMART_OVERVIEW_STATUS_CRITICAL,
	DISK_SMART_OVERVIEW_STATUS_FAILING,
	DISK_SMART_OVERVIEW_STATUS_ACCESS_ERR,
} DISK_SMART_OVERVIEW_STATUS;

typedef enum {
	DISK_SMART_INFO_STATUS_FAIL_TYPE_NORMAL,
	DISK_SMART_INFO_STATUS_FAIL_TYPE_CRITICAL,
	DISK_SMART_INFO_STATUS_FAIL_TYPE_REPEAT,
} DISK_SMART_INFO_STATUS_FAIL_TYPE;

typedef enum {
	DISK_SMART_INFO_ACTION_UNKNOWN,
	DISK_SMART_INFO_ACTION_SUPPRESS,
	DISK_SMART_INFO_ACTION_DISABLE,
	DISK_SMART_INFO_ACTION_REMOVE,
	DISK_SMART_INFO_ACTION_ENABLE,
} DISK_SMART_INFO_ACTION_TYPE;

typedef enum {
	DISK_SMART_INFO_WARNING_UNKNOWN,
	DISK_SMART_INFO_WARNING_SMART,
	DISK_SMART_INFO_WARNING_UNC,
	DISK_SMART_INFO_WARNING_LIFE,
	DISK_SMART_INFO_WARNING_ADV,
	DISK_SMART_INFO_WARNING_ALL,
} DISK_SMART_INFO_WARNING_TYPE;

typedef struct _tag_DISK_SMART_INFO_FAIL_LIST {
	int id;
	char szName[64];
	DISK_SMART_INFO_STATUS_FAIL_TYPE type;
	struct _tag_DISK_SMART_INFO_FAIL_LIST *pNext;
} DISK_SMART_INFO_FAIL_LIST;

typedef struct _tag_disk_smart_info_list_ {
	char *szName;
	char *szInfoId;
	char *szCurrent;
	char *szWorst;
	char *szThreshold;
	char *szRaw;
	DISK_SMART_ATTR_STATUS status;
	struct _tag_disk_smart_info_list_ *pNext;
} DISK_SMART_INFO_LIST;

typedef struct _tag_disk_smart_test_log_report_ {
	int blQuickErrorBefore;
	int blExtendErrorBefore;
	char szQuickTime[32];
	char szExtendTime[32];
	char szRemainTime[32];
	DISK_SMART_TEST_RESULT quickResult;
	DISK_SMART_TEST_RESULT extendResult;
	DISK_SMART_TEST_RESULT currentStatus;
} DISK_SMART_TEST_LOG_REPORT;

typedef struct _tag_DISK_SMART_TEST_LOG_INFO {
	char szTime[32];
	char szDevice[32];
	char szModel[32];
	char szSerial[32];
	char szTestType[32];
	DISK_SMART_TEST_RESULT result;
} DISK_SMART_TEST_LOG_INFO;

typedef struct _tag_DISK_SMART_TEST_LOG_LIST {
	DISK_SMART_TEST_LOG_INFO testInfo;
	struct _tag_DISK_SMART_TEST_LOG_LIST *pNext;
} DISK_SMART_TEST_LOG_LIST;

typedef struct _tag_DISK_SMART_INFO_ACTION {
	char szTime[32];
	char szDevice[128];
	char szModel[32];
	char szSerial[32];
	char szInfoId[4];
	char szCurrent[8];
	char szThreshold[8];
	char szWorst[8];
	char szRaw[32];
	char szTestCode[32];
	int iUncCt;
	int iLife;
	DISK_SMART_INFO_ACTION_TYPE type;
} DISK_SMART_INFO_ACTION;

typedef struct _tag_DISK_SMART_INFO_ACTION_LIST {
	DISK_SMART_INFO_ACTION actionInfo;
	DISK_SMART_INFO_WARNING_TYPE warningType;
	struct _tag_DISK_SMART_INFO_ACTION_LIST *pNext;
} DISK_SMART_INFO_ACTION_LIST;

/* smartctl_selftest_log_read.c */
int SMARTSelfTestLogRead(char *szDev, DISK_SMART_TEST_LOG_REPORT *testLogReport);
/* smartctl_ata_smart_info_free.c */
void SYNODiskSmartInfoFree(DISK_SMART_INFO_LIST *smartInfoList);
/* smartctl_total_status_get.c */
DISK_SMART_TOTAL_STATUS SmartTotalStatusGet(char *szDevice, DISK_SMART_TEST_STATUS *testStatus, char *szProgress, int cbProgress, DISK_SMART_INFO_STATUS *infoStatus, DISK_SMART_INFO_FAIL_LIST **ppSmartInfoFailList, int *piWeight, int *piSuppress, int *piDisable);
/* smartctl_ata_self_test_read.c */
int SMARTAtaSelfTestLogRead(int dev_fd, char *szDev, DISK_SMART_TEST_LOG_REPORT *testLogReport);
/* smartctl_scsi_self_test_read.c */
int SMARTScsiSelfTestLogRead(int dev_fd, DISK_SMART_TEST_LOG_REPORT *testLogReport);
/* smartctl_test_result_transfer.c */
BOOL SmartTestResultTransfer(int opStat, DISK_SMART_TEST_RESULT *tmpTestResult);
/* smartctl_scsi_self_test_time_get.c */
int SMARTScsiSelfTestTimeGet(int dev_fd, DISK_SMART_TEST_LOG_REPORT *testLogReport);
/* smartctl_is_selftesting.c */
BOOL SMARTIsSelftesting(char *szDev);
/* smartctl_ata_smart_info_get.c */
int SYNODiskAtaSmartInfoParse(char *szDevice, DISK_SMART_INFO_LIST **smartInfoList);

/* smartctl_ata_command_interface.c */
int ata_command_interface(int device, SMART_COMMAND_SET command, unsigned char *data);
/* smartctl_attrib_raw_value_parse.c */
long long SmartAttribRawValueParse(char *szOut, const struct ata_smart_attribute *SmartAttr);
/* smartctl_isbigendian.c */
int isbigendian(void);
/* smartctl_marvell_command_interface.c */
int marvell_command_interface(int device, SMART_COMMAND_SET command, unsigned char *data);
/* smartctl_misc.c */
void SYNOSmartEndianSwap2(char *location);
unsigned char SYNOSmartChecksum(unsigned char *buffer);
/* smartctl_temperature_get.c */
int SmartTemperatureGet(const struct ata_smart_values *data);
int SmartAirflowTempGet(const struct ata_smart_values *data);
/* smartctl_firm_serial_read.c */
int SmartFirmAndSerialRead(char *szDevice, char *szFirmware, int firmLen, char *szSerial, int serialLen);
/* smartctl_data_read.c */
int SmartValuesRead(char *szDevice, int device, struct ata_smart_values *data);
int SmartDataRead(char *szDevice, struct ata_smart_values *curval, struct ata_smart_thresholds_pvt *threval);
/* smartctl_identify_read.c */
int SmartIdentifyRead(char *szDevice, struct ata_identify_device *pBuf);
/* smartctl_sat_command_interface.c */
int sat_command_interface(int device, SMART_COMMAND_SET command, unsigned char *data);
/* smartctl_sas_command_interface.c */
int sas_command_interface(int device, SMART_COMMAND_SET command, unsigned char *data);
/* smartctl_command_interface_get.c */
smart_interface SYNOSmartctlCommandInterfaceGet(char *szDev);
/* smartctl_total_status_string_get.c */
int SmartTotalStatusStringGet(const char *szDevice, char *szStatus, int cbStatus, char *szProgress, int cbProgress, int *piWeight);
/* smartctl_test_result_record.c */
int SmartTestResultRecord(const char *szDiskName);
/* smartctl_test_result_log_get.c */
int SmartTestResultLogGet(const char *szDevice, DISK_SMART_TEST_LOG_LIST **ppDiskSmartLogList);
void SmartTestResultLogFree(DISK_SMART_TEST_LOG_LIST *pDiskSmartLogList);
/* smartctl_test_status_get.c */
DISK_SMART_TEST_STATUS SmartTestStatusGet(char *szDevice, char *szProgress, int progressLen, int *piWeight);
/* smartctl_info_status_get.c */
DISK_SMART_INFO_STATUS SmartInfoStatusGet(char *szDevice, DISK_SMART_INFO_FAIL_LIST **ppSmartInfoFailList, int *piWeight, int *piSuppress, int *piDisable);
/* smartctl_info_fail_list_free.c */
void SmartInfoFailListFree(DISK_SMART_INFO_FAIL_LIST *pSmartInfoFailList);
/* smartctl_total_status_string_transfer.c */
int SmartTotalStatusStringTransfer(DISK_SMART_TOTAL_STATUS status, char *szStatus, int cbStatus);
/* smartctl_test_status_string_transfer.c */
int SmartTestStatusStringTransfer(DISK_SMART_TEST_STATUS status, char *szStatus, int cbStatus);
/* smartctl_info_status_string_transfer.c */
int SmartInfoStatusStringTransfer(DISK_SMART_INFO_STATUS status, char *szStatus, int cbStatus);
/* smartctl_test_result_string_transfer.c */
int SmartTestResultStringTransfer(DISK_SMART_TEST_RESULT result, char *szResult, int cbResult);
/* smartctl_info_action_record.c */
int SmartInfoActionRecord(const char *szDevPath, DISK_SMART_INFO_ACTION_TYPE actionType, DISK_SMART_INFO_WARNING_TYPE warningType, const char* szInfoId);
/* smartctl_info_action_log_get.c */
int SmartInfoActionLogGet(const char* szDevice, DISK_SMART_INFO_ACTION_LIST **ppDiskSmartActionList, DISK_SMART_INFO_WARNING_TYPE warningType);
void SmartInfoActionLogFree(DISK_SMART_INFO_ACTION_LIST *pDiskSmartActionList);
/* smartctl_overview_status_get.c */
#ifdef MY_DEF_HERE
int NVMeSmartOverviewWeightCompute(int iSmartWeight,
								   int isLifeLow,
								   int critWaring);
#endif
DISK_SMART_OVERVIEW_STATUS SmartOverviewStatusGet(const char* szDevice, DISK_SMART_TOTAL_STATUS *status, char *szAdvStatus, int *piOverviewWeight);
/* smartctl_overview_status_cache_get.c */
DISK_SMART_OVERVIEW_STATUS SmartOverviewStatusCacheGet(const char* szDevice, int *piOverviewWeight);
/* smartctl_overview_status_mailkey_get.c */
int SmartOverviewStatusMailkeyGet(DISK_SMART_OVERVIEW_STATUS status, char *szMailKey, int cbMailKey, int *piLogId);
/* smartctl_overview_status_string_transfer.c */
int SmartOverviewStatusStringTransfer(DISK_SMART_OVERVIEW_STATUS status, char *szStatus, int cbStatus);
/* smartctl_overview_status_compute.c */
DISK_SMART_OVERVIEW_STATUS SmartOverviewStatusCompute(int iOverviewWeight);
/* smartctl_test_limit_exceed.c */
BOOL SmartTestLimitExceed(const char *szDevice);
/* smartctl_nvme_critial_warning_cache_update.c */
int SmartNVMeCritialWarnCacheUpdateIfSupport(const char *szDiskName);
/* smartctl_nvme_critial_warning_cache_get.c */
int SmartNVMeCritialWarnCacheGet(const char *szDevice, int *pCritWarn);
__END_DECLS;
#endif /* __SYNO_HWCTL_SMARTCTL_H_ */
