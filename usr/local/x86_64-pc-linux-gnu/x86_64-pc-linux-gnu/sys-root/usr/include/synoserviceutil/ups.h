// Copyright (c) 2000-2010 Synology Inc. All rights reserved.
#ifndef __SYNO_UPS_H__
#define __SYNO_UPS_H__

#include <sys/cdefs.h>
#include <synousb/usb.h>
#include <synocore/synoglobal.h>

__BEGIN_DECLS;

#define BIN_FILE_UPSC	"/usr/bin/upsc"

#define SZF_UPS_INFO	"/tmp/ups/ups.info"
#define SZF_UPSMON	"/usr/syno/etc/ups/upsmon.conf"
#define SZF_UPS_SCHED	"/usr/syno/etc/ups/upssched.conf"

#define SZK_UPS_MASTER	"upsmaster"
#define SZK_UPS_MODE	"ups_mode"
#define SZK_UPS_ENABLE	"ups_enabled"
#define SZK_UPS_WAITTIME	"ups_wait_time"
#define SZK_UPS_SAFESHUTDOWN	"ups_safeshutdown"
#define SZK_UPS_SLAVE_ENABLE	"upsslave_enabled"
#define SZK_UPS_SLAVE_SERVER	"upsslave_server"
#define SZK_UPS_ACL		"ups_acl"
#define SEP_UPS_ACL		'|'

#define SZK_UPS_SNMP_IP             "ups_snmp_ip"
#define SZK_UPS_SNMP_COMMUNITY      "ups_snmp_community"
#define SZK_UPS_SNMP_VERSION		"ups_snmp_version"
#define SZK_UPS_SNMP_MIB		    "ups_snmp_mib"
#define SZK_UPS_SNMP_USER		    "ups_snmp_user"
#define SZK_UPS_SNMP_AUTH		    "ups_snmp_auth"
#define SZK_UPS_SNMP_AUTH_TYPE	    "ups_snmp_auth_type"
#define SZK_UPS_SNMP_AUTH_KEY		"ups_snmp_auth_key"
#define SZK_UPS_SNMP_PRIVACY		"ups_snmp_privacy"
#define SZK_UPS_SNMP_PRIVACY_TYPE   "ups_snmp_privacy_type"
#define SZK_UPS_SNMP_PRIVACY_KEY	"ups_snmp_privacy_key"

#define SZV_UPS_MODE_MASTER_USB     "usb"
#define SZV_UPS_MODE_MASTER_SNMP    "snmp"
#define SZV_UPS_MODE_SLAVE          "slave"

#define MAX_UPS_ACL	5
#define MAX_UPS_ACL_KEY_LEN 64
#define MAX_UPS_COMMUNITY	128 //Max length = 64, so define it to 128
#define MAX_UPS_VERSION		8	//v1, v2c
#define MAX_UPS_MIB		    32
#define MAX_SNMP_TYPE       8
#define MAX_SNMP_KEY        64
#define MAX_SNMP_USER       64

typedef enum {
	UPS_MODE_MASTER_USB = 0,
	UPS_MODE_MASTER_SNMP,
	UPS_MODE_SLAVE
} SYNO_UPS_MODE;

typedef struct _tag_SYNO_UPS_INFO {
	/* Enable UPS service : master & slave */
	BOOL blEnabled;
	/* Accept Network UPS ACL : master */
	BOOL blAcceptACL;
	/* Shutdown UPS when enter safe mode : master, default: TRUE */
	BOOL blShutdownUPS;
	/* Time to safemode : master & slave, default: -1 */
	int iWaitTime;
	/* UPS info : master & slave */
	int iStatus;
	int iLoad;
	int iRuntime;
	int iBattCharge;
	char szManufacturer[MAX_USB_INFO_LEN];
	char szModel[MAX_USB_INFO_LEN];
	/* upsmon server : slave */
	char szUpsmonServer[CB_SZ_IPv6];
	/* array of ACL : master */
	char rgszACL[MAX_UPS_ACL][CB_SZ_IPv6];
	/* USB Master, SNMP Master or Slave */
	SYNO_UPS_MODE upsMode;
	/* snmp server : snmp master */
	char szSnmpIp[CB_SZ_IPv6];
	char szCommunity[MAX_UPS_COMMUNITY];
	char szSnmpVersion[MAX_UPS_VERSION];
    char szSnmpMib[MAX_UPS_MIB];
    BOOL blSnmpAuthEnabled;
    BOOL blSnmpPrivacyEnabled;
    char szSnmpAuthType[MAX_SNMP_TYPE];
    char szSnmpAuthKey[MAX_SNMP_KEY];
    char szSnmpPrivacyType[MAX_SNMP_TYPE];
    char szSnmpPrivacyKey[MAX_SNMP_KEY];
    char szSnmpUser[MAX_SNMP_USER];
} SYNO_UPS_INFO;

enum {
	UPS_STATUS_ONLINE = 1,
	UPS_STATUS_ONBATT,
	UPS_STATUS_LOWBATT,
};

#ifndef NO_PROTO
#include <synoserviceutil/ups_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_UPS_H__
