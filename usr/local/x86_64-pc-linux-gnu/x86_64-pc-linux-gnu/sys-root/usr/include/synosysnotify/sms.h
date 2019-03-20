// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

#ifndef __SYNO_SMS_H__
#define __SYNO_SMS_H__

#include <synocore/hash.h>

__BEGIN_DECLS;

//#define SMS_DEBUG
#ifdef SMS_DEBUG
#include <syslog.h>
#define DBGMSG(x...)  SYSLOG(LOG_DEBUG, x);
#else
#define DBGMSG(x...)  
#endif

#define SZK_SMS_PHONE1_PREFIX		"sms_phone1_prefix"
#define SZK_SMS_PHONE2_PREFIX		"sms_phone2_prefix"

#define SMS_PHONE_PREFIX_MODE_NONE 0
#define SMS_PHONE_PREFIX_MODE_PLUS 1
#define SMS_PHONE_PREFIX_MODE_CHECK 2

#define SZF_SMS_CONF	"/usr/syno/etc/synosms.conf"
#define SZF_DEFAULT_SMS_CONF	"/usr/syno/etc.defaults/synosms.conf"
#define SZK_SMS_ENABLE		"sms_enable"
#define SZK_SMS_SERVER			"server"
#define SZK_SMS_PORT			"port"
#define SZK_SMS_TEMPLATE		"template"
#define SZK_SMS_SEPCHAR			"sepchar"
#define SZK_SMS_USER			"user"
#define SZK_SMS_PASS			"passwd"
#define SZK_SMS_PHONE1_CODE			"phone1code"
#define SZK_SMS_PHONE1_NUM			"phone1num"
#define SZK_SMS_PHONE2_CODE			"phone2code"
#define SZK_SMS_PHONE2_NUM			"phone2num"
#define SZK_SMS_NEED_SSL				"needssl"
#define SZK_SMS_INTERVAL		"interval"
#define SZK_SMS_DEFAULT_PROVIDER "clickatell"
#define SZK_SMS_PROVIDER_URL	"url"
#define SZK_SMS_SYNO_TEST_ACCOUNT	"SynoNotification"
#define SZK_SMS_SYNO_API_ID	"3148203"
#define SZK_SMS_API_ID			"api_id="
#define SZ_PHONE_SEP_CHAR	"-"
#define SMS_PASS_PLAIN_PWD_MAX		192

// SMS tag for management UI
#define SZ_SMS_TEST	"Sms_Test"
#define SZ_SMS_DDNS_FAIL		"Sms_DDNSFail"
#define SZ_SMS_EBOX_FAN_STOP	"Sms_EboxFanStop"
#define SZ_SMS_EBOX_RAID_VOLUME_CRASHED		"Sms_EboxRaidVolumeCrashed"
#define SZ_SMS_EBOX_RAID_VOLUME_DEGRADE		"Sms_EboxRaidVolumeDegrade"
#define SZ_SMS_EBOX_RAID_VOLUME_MISSING		"Sms_EboxRaidVolumeMissing"
#define SZ_SMS_EUNIT_POWER_RESUME		"Sms_EUnitPowerResume"
#define SZ_SMS_EUNIT_POWER_FAILURE		"Sms_EUnitPowerFail"
#define SZ_SMS_POWER_RESUME		"Sms_PowerResume"
#define SZ_SMS_POWER_FAILURE		"Sms_PowerFail"
#define SZ_SMS_INTERNAL_DISK_FAIL		"Sms_InternalDiskFail"
#define SZ_SMS_INTERNAL_FAN_STOP		"Sms_InternalFanStop"
#define SZ_SMS_CPU_FAN_STOP		"Sms_CpuFanStop"
#define SZ_SMS_RAID_SYSTEM_VOLUME_CRASHED		"Sms_RaidSystemVolumeCrashed"
#define SZ_SMS_RAID_SYSTEM_VOLUME_DEGRADE		"Sms_RaidSystemVolumeDegrade"
#define SZ_SMS_STORAGE_POOL_CRASHED      "Sms_StoragePoolCrashed"
#define SZ_SMS_STORAGE_POOL_DEGRADED     "Sms_StoragePoolDegraded"
#define SZ_SMS_RAID_VOLUME_CRASHED		"Sms_RaidVolumeCrashed"
#define SZ_SMS_RAID_VOLUME_DEGRADE		"Sms_RaidVolumeDegrade"
#define SZ_SMS_UPS_DISCONNECT		"Sms_UPSDisconnect"
#define SZ_SMS_OVERHEAT_SHUTDOWN		"Sms_OverheatShutdown"

#define SZ_SMS_CONF_SEC_NAME	"synosms"
#define SZF_SYNO_LAST_SS_SMS		"/tmp/LastSmsTime.Surveillance"
#define SZF_SYNO_LAST_MANAGEMENT_SMS		"/tmp/LastSmsTime.Management"

#define SZ_SMS_PARAM_TAG_USER		"@@USER@@"
#define SZ_SMS_PARAM_TAG_PASSWORD		"@@PASS@@"
#define SZ_SMS_PARAM_TAG_PHONE		"@@PHONE@@"
#define SZ_SMS_PARAM_TAG_MSG		"@@TEXT@@"
#define SZ_SMS_PARAM_TAG_FROM		"@@FROM@@"
#define SZ_SMS_PARAM_TAG_ID		"@@ID@@"
#define PARAM_NUM_MIN		4

typedef enum _tag_SYNO_SMS_TYPE_ {
	SMS_SS = 0,
	SMS_MANAGEMENT
}SYNOSMSTYPE;

typedef enum _tag_SYNO_SMS_PARAM_TYPE_ {
	PARAM_TYPE_OTHER = 0,
	PARAM_TYPE_USER,
	PARAM_TYPE_PASSWORD,
	PARAM_TYPE_PHONE,
	PARAM_TYPE_MSG,
	PARAM_TYPE_FROM,
	PARAM_TYPE_ID
}SYNOSMSPARAMTYPE;

typedef struct _tag_SYNO_SMS_ {
	char *szServer;
	char *szUrlTemplate;
	char *szSepChar;
	char *szUser;
	char *szPass;
	char *szPhone1;
	char *szPhone2;
	int Port;
	int NeedSSL;
	int Interval;
	int NeedInterval;
	char *szTextDir;
} SYNOSMS;

typedef struct _tag_SYNO_SMS_CONF_ {
	int smsenable;
	int interval;
	char *szServer;
	char *szUser;
	char *szPass;
	char *szPhone1Code;
	char *szPhone1Num;
	char *szPhone2Code;
	char *szPhone2Num;
}SYNOSMSCONF, *PSYNOSMSCONF;

typedef struct _tag_SYNO_SMS_PROVIDER_ {
	int port;
	int needSSL;
	char *szServer;
	char *szSepChar;
	char *szUrl;
	char *szTemplate;
}SYNOSMSPROVIDER, *PSYNOSMSPROVIDER;

#ifndef NO_PROTO
#include <availability.h>
#include <synosysnotify/sms_p.h>
#endif

__END_DECLS;

#endif // __SYNO_SMS_H__
