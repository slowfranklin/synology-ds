// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_DDNS_CLIENT_H__
#define __SYNO_DDNS_CLIENT_H__

#include <sys/cdefs.h>

#include <curl/curl.h>

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <synocore/hash.h>

__BEGIN_DECLS;

//%s, %d, %x => strerror(errno), errno, SLIBCErrGet()
#define DDNS_DBG(fmt, args...)	syslog(LOG_ERR, "%s(%s:%d): "fmt, __func__, __FILE__, __LINE__, ##args);

#define MAX_DDNS_SERVICE		8	//Enable, Disable
#define MAX_DDNS_NAME 			(32+8)	//provider name, user defined USER_xxxxx
#define MAX_DDNS_HOSTNAME 		128
#define MAX_DDNS_USERNAME 		(256+1)	//1 for '\0'
#define MAX_DDNS_PWD 			(128+1)	//1 for '\0'
#define MAX_DDNS_HEARTBEAT		8	//Enable, Disable
#define MAX_DDNS_STATUS			64
#define MAX_DDNS_MASK_LENGTH 	128
#define MAX_DDNS_MODULEPATH 	512
#define MAX_AUTH_KEY            512
#define MAX_LEN_MAC				18
#define MAX_LEN_SN				18

#define SZ_EMPTY_IP				"0.0.0.0"
#define SZ_EMPTY_IPV4			"0.0.0.0"
#define SZ_EMPTY_IPV6			"0:0:0:0:0:0:0:0"

//key for ddns.conf
#define SZK_DDNS_SERVICE		"service"
#define SZK_DDNS_PROVIDER		"provider"
#define SZK_DDNS_HOSTNAME		"hostname"
#define SZK_DDNS_USER			"username"
#define SZK_DDNS_PASSWD			"passwd"
#define SZK_DDNS_NET			"net"
#define SZK_DDNS_IP				"ip"
#define SZK_DDNS_IPV6			"ipv6"
#define SZK_DDNS_HEARTBEAT		"enable_heartbeat"
#define SZK_DDNS_STATUS			"status"
#define SZK_DDNS_LASTUPDATED	"lastupdated"

#define SZK_TMP_PROVIDER		"Temp.Provider"

//value for service status
#define SZ_DDNS_STATUS_LOADING			"loading"
#define SZ_DDNS_STATUS_DISABLE			"disabled"
#define SZ_DDNS_STATUS_CHECK_NETWORK	"check_network"

//value for SZK_DDNS_NET in ddns.conf
#define SZ_NET_MANUAL	    "MANUAL"
#define SZ_NET_MANUAL_V4	"MANUAL_V4"
#define SZ_NET_MANUAL_V6	"MANUAL_V6"
#define SZ_NET_DEFAULT	    "DEFAULT"

#define SZK_DDNS_HOSTMASK		"hostmask"
#define SZK_DDNS_USERMASK		"usermask"
#define SZK_DDNS_PASSWDMASK		"passwdmask"

#define SZK_IN_PROCESS "service_status_inprocess"
#define SZK_DDNS_UPDATE		"ddns_update"
#define SZK_DDNS_SELECT		"ddns_select"
#define SZK_DDNS_RECLAIM_INTERVAL_MINS	"ddns_reclaim_interval_mins"
#define SZF_DDNS_PROVIDER_DNSPOD_CN				"DNSPod.cn"
#define SZF_DDNS_PROVIDER_DNSPOD_COM			"DNSPod.com"
#define SZF_DDNS_PROVIDER_SYNO					"Synology"
#define SZF_DEBUG_DDNS_CLIENT	"/tmp/debug_ddns"
#define SZF_DDNS_FORCE_UPDATE	"/tmp/ddns_force_update"
#define MAX_CONNECT_TIMEOUT_SECONDS	30
#define MAX_CURL_TIMEOUT_SECONDS	60
#define MIN_HEARTBEAT_SECONDS	(10 * 60)
#define MAX_HEARTBEAT_SECONDS	(25 * 60)
#define MAX_AUTH_STR            (100)
#define MAX_DOMAIN_LEN          (128)
#define MAX_SUB_DOMAIN_LEN      (128)

#define DDNS_RESPONSE_APIKEY_NOT_FOUND  "apikey_not_found"
#define DDNS_RESPONSE_APIKEY_EXPIRED	"apikey_expired"

// config file ddns.conf
#define SZF_DEF_DDNSCONF		    "/etc.defaults/ddns.conf"
#define SZF_DDNSCONF		        "/etc/ddns.conf"

// config file ddns_provider.conf
#define SZF_DEF_DDNS_PROVIDER	    "/etc.defaults/ddns_provider.conf"
#define SZF_DDNS_PROVIDER		    "/etc/ddns_provider.conf"
// key for ddns_provider.conf
#define USER_DEFINED_PREFIX         "USER_"
#define SZK_DDNS_MODULEPATH	        "modulepath"
#define SZK_DDNS_QUERYURL	        "queryurl"
#define SZK_DDNS_PROVIDER_WEBSITE   "website"
#define SZK_DDNS_HEARTBEAT_INTERVAL	"heartbeat_loop_interval"

// binary file
#define SZF_BIN_GET_EXT_IP      "/usr/syno/bin/ddns/get_ext_ip.sh"
#define SZF_TMP_GET_EXT_IP      "/tmp/get_ext_ip.sh"

//files of daemon
#define SZF_HEARTBEATD			"/usr/syno/sbin/heartbeatd"
#define SZF_DDNSD				"/usr/syno/sbin/ddnsd"

//files for ddns information
#define SZF_DDNS_INFO			"/tmp/ddns.info"
#define SZF_DDNS_LASTUPDATED	"/tmp/ddns.lastupdated"
#define SZF_DDNS_SOCKET_ADDR	"/tmp/ddns.socket"
#define SZF_DDNS_STATUS			"/tmp/ddns.status"
#define SZF_DDNS_TMP			"/tmp/ddns.tmp"

#define SZK_IP_MANUAL		"IP_MANUAL"
#define SZK_IPV4            "IPv4"
#define SZK_IPV6            "IPv6"

#define SZK_EXPIRED			"Expired"
#define MAX_TIME_STR		(20)
#define SEC_OF_DAY			(24*60*60)
#define TIME_TO_UPDATE		SEC_OF_DAY
#define TIME_TO_CHECK_IP	(3*60)
#define TIME_FOR_DELAY		(3)
#define MAX_IP_LEN			(16)
#define MAX_IPV4_LEN		(16)
#define MAX_IPV6_LEN		(40)

// TWNIC param
#define SZ_TWNIC			"TWNIC"
#define SZ_TWNIC_CGI_PATH	"cgi-bin/dsm/reg.cgi"
#define	SZ_TWNIC_DNAME		"dname"
#define	SZ_TWNIC_SLD		"sld"
#define	SZ_TWNIC_PASSWD		"passwd"
#define	SZ_TWNIC_SERIAL		"serial"
#define	SZ_TWNIC_MAIL		"mail"
#define	SZ_TWNIC_IPV4		"ip"
#define	SZ_TWNIC_IPV6		"ip6"
#define	SZ_TWNIC_TYPE		"type"
#define	SZ_TWNIC_TYPE_FORCE	"force"

#define SZF_DNS_ACCOUNT_HANDLER "account.php"
#define SZF_DNS_REGISTER_MAIL_HANDLER "support/register_activate_email.php"

#define SZF_DDNS_REG_CONFIG	"/usr/syno/etc/ddnsreg.conf"
#define SZ_DDNS_NOIP_SEC	"NoIP.com"

#define IS_HTTP_SUCCESS(x) 	(200 == x)

#define URL_DDNS_SERVER "ddns.synology.com"

//key for ddns_provider.conf
#define SZK_REGISTER_MODULE	"register_module"

// operation for ddns_provider.conf
typedef enum TAG_DDNS_CONFIG_OPERATION_TYPE {
    ACTION_DEL = 0,
    ACTION_ADD,
    ACTION_EDIT
} DDNS_CONFIG_OPERATION_TYPE;

// use to get provider list
typedef enum TAG_DDNS_PROVIDER_TYPE {
    PROVIDER_SYNO_DEFINED = 1,
    PROVIDER_USER_DEFINED,
    PROVIDER_ALL
} DDNS_PROVIDER_TYPE;

// use to get system information
typedef enum TAG_DDNS_SYS_INFO_TYPE {
    SYS_MAC = 0,
    SYS_SN,
    SYS_API_KEY,
    SYS_MY_DS_ACCOUNT_EMAIL,
    SYS_MY_DS_ACCOUNT_ID,
    SYS_MY_DS_ACCOUNT_AUTH_KEY,
	SYS_MACHINE_KEY
} DDNS_SYS_INFO_TYPE;

typedef enum _tag_UPDATE_TYPE {
	IP_CHANGE = 0,
	EXPIRED,
	HUP_SIGNAL,
	USER_UPDATE
} DDNS_UPDATE_TYPE;

typedef struct _tag_DDNS_MYDS_ACCOUNT_ {
    int     id;
    char    szEmail[MAX_DDNS_USERNAME];
    char    szAuthKey[MAX_AUTH_KEY];
} DDNS_MYDS_ACCOUNT;

typedef struct _tag_DDNS_INFO_ {
	char			szService[MAX_DDNS_SERVICE];
	char			szProvider[MAX_DDNS_NAME];
	char            szName[MAX_DDNS_NAME];			//del
	char            szHostName[MAX_DDNS_HOSTNAME];
	char            szUser[MAX_DDNS_USERNAME];
	char            szPasswd[MAX_DDNS_PWD];
	char			szNet[MAX_IP_LEN];
	char			szIP[MAX_IP_LEN];
	char			szHeartbeat[MAX_DDNS_HEARTBEAT];
	char			szStatus[MAX_DDNS_STATUS];
	char			szLastupdated[MAX_TIME_STR];
	BOOL 			blEnableHeartbeat;				//del
	char			szIPv6[MAX_IPV6_LEN];
} DDNS_INFO;

typedef struct _tag_DDNS_PROVIDER_CONF_ {
	char            szName[MAX_DDNS_NAME];
	char            szModulePath[MAX_DDNS_MODULEPATH];
	char            szURLQuery[MAX_DDNS_MODULEPATH];
    char            szWebsite[MAX_DDNS_MODULEPATH];
	int 			intervalHeartBeat; //minutes, 0 means not specified
} DDNS_PROVIDER_CONF;

typedef struct _tag_DDNS_ENUM_ {
	char             szName[MAX_DDNS_NAME];
	struct _tag_DDNS_ENUM_ *      pNext;
} DDNS_ENUM;

typedef struct _tag_ddns_auth_info_ {
	const char *szUsername;
	const char *szPassword;
} DDNS_AUTH_INFO;

typedef struct _tag_ddns_syno_req_ {
	const char *szUrl;
	const char *szPath; //path of CGI
	PSLIBSZHASH	pShQuery;
	BOOL blDebug;
	DDNS_AUTH_INFO auth;
} DDNS_SYNO_REQUEST;

typedef struct _tag_ddns_syno_response_ {
	long httpCode;
	char *szData;
} DDNS_SYNO_RESPONSE;

typedef struct _tag_ddns_syno_host_update_ {
	BOOL blDebug; //Optional, It will output debug message when calling curl function.
	BOOL blForceUpdate;
	const char *szIP;
	const char *szHostname;
	const char *szUserName;
	const char *szPasswd;
	const char *szServerURL; //Optional
	const char *szSerialNo;
	const char *szIPv6;
} DDNS_SYNO_HOST_UPDATE;

typedef struct _tag_ddns_syno_enum_domain_ {
	BOOL blDebug;		//Optional
	const char *szServerURL; //Optional
} DDNS_SYNO_ENUM_DOMAIN;

typedef struct _tag_ddns_syno_acnt_register_ {
	BOOL blDebug;		//Optional
	const char *szServerURL; //Optional
	const char *szUserName;
	const char *szPasswd;
	const char *szFullName;
	const char *szSerialNo;
} DDNS_SYNO_ACCOUNT_REG;

typedef struct _tag_ddns_syno_host_delete_ {
	BOOL blDebug;		//Optional
	const char *szServerURL; //Optional
	const char *szHostname;
	const char *szUserName;
	const char *szPasswd;
	const char *szSerialNo;
} DDNS_SYNO_HOST_DELETE;

typedef struct _tag_ddns_syno_host_create_ {
	BOOL blDebug;		//Optional
	const char *szServerURL; //Optional
	const char *szHostname;
	const char *szUserName;
	const char *szPasswd;
	const char *szIP;
	const char *szSerialNo;
	const char *szIPv6;
} DDNS_SYNO_HOST_CREATE;

typedef struct _tag_ddns_syno_hostname_api_ {
	BOOL blDebug;		        //Optional: default FALSE
	BOOL blForcedUpdate;        //Optional: default FALSE
	BOOL blNotice;
    BOOL blCreateHostname;
	const char *szServerURL;
	const char *szHostname;
	const char *szIPv4;
	const char *szIPv6;
} DDNS_SYNO_HOSTNAME_API;

typedef struct _tag_ddns_syno_heartbeat_api_ {
	BOOL blDebug;		        //Optional: default FALSE
	const char *szServerURL;
	const char *szHeartbeat;    //?
} DDNS_SYNO_HEARTBEAT_API;

//FIXME: remove all
typedef struct _tag_ddns_syno_heartbeat_update_ {
	BOOL blDebug;		//Optional
	BOOL blHeartbeatEnable;	//FIXME: remove me
	const char *szServerURL; //Optional
	const char *szUserName;
	const char *szPasswd;
	const char *szSerialNo;
	const char *szHeartbeat;
} DDNS_SYNO_HEARTBEAT_UPDATE;

typedef struct _tag_ddns_syno_verification_mail_send_ {
	BOOL blDebug;		//Optional
	const char *szServerURL; //Optional
	const char *szUserName;
	const char *szPasswd;	//Optional
	const char *szSerialNo;	//Optional
} DDNS_SYNO_VERIFICATION_MAIL_SEND;

struct MemoryStruct {
	char *data;
	size_t size;
};

/******************************
For No-IP.com API
*******************************/
#define ALIGN_SIZE 4
#define ALIGN_MEM(N) ((N + ALIGN_SIZE -1) & ~(ALIGN_SIZE-1))

#define MAX_NOIP_HOST_NAME 32
#define MAX_NOIP_DOMAIN_NAME 32
#define MAX_NOIP_USER_ID 32
#define MAX_NOIP_USER_KEY 33

#define MAX_NOIP_USERNAME 16
#define MAX_NOIP_EMAIL 128
#define MAX_NOIP_PASSWORD 32
#define MAX_NOIP_FIRSTNAME 30
#define MAX_NOIP_LASTNAME 30
#define MAX_NOIP_POSTALCODE 30

#define NOIP_PROVIDER_ID 1

typedef enum _tag_DDNS_MESSAGE {
	NONE = 0,
	USER_FOUND,
	USER_NOT_FOUND,
	USER_DISABLED,
	DUPLICATE_EMAIL,
	ACCOUNT_IN_USED_BY_YOU,
	DUPLICATE_USERNAME,
	DUPLICATE_ALL,
	AVAILABLE_TO_CREATE,
	CANT_LOGIN,
	SUCCESS_LOGIN,
	HOSTNAME_EXISTED,
	HOSTNAME_USED_BY_YOURHOST,
	MAX_ACCOUNT_REACHED,
	HOSTNAME_CREATED,
	HOSTNAME_NOTFOUND,
	USER_CREATE_CONFLICT,
	USER_CREATED,
	INVALID_EMAIL,
	REG_MODULE_SYSFAIL,
	REG_MODULE_DNSFAIL,
	REG_MODULE_CONNFAIL,
	SERVICE_DOWN,
	UNKNOWN_SYS_ERR,
	INVALID_SN,
	EMAIL_UNVERIFIED,
	INVALID_PARAM,
	CALL_TWNIC_SUPPORT,
	HOSTNAME_BAD_FORMAT,
	NEED_VERIFIED,
	INTERNAL_ERR,
	LAST_ITEM
} DDNS_MESSAGE;

typedef struct _tag_DDNS_ACCOUNT_AUTH {
	int providerID;
	char szUserID[ALIGN_MEM(MAX_NOIP_USER_ID)];
	char szUserKey[ALIGN_MEM(MAX_NOIP_USER_KEY)];
} DDNS_ACCOUNT_AUTH;

typedef struct _tag_DDNS_ACCOUNT_INFO {
	int providerID;
	char szUsername[ALIGN_MEM(MAX_NOIP_USERNAME)];
	char szEmail[ALIGN_MEM(MAX_DDNS_USERNAME)];
	char szPassword[ALIGN_MEM(MAX_DDNS_PWD)];
	char szFirstname[ALIGN_MEM(MAX_DDNS_USERNAME)];
	char szLastname[ALIGN_MEM(MAX_NOIP_LASTNAME)];
	char szServerURL[ALIGN_MEM(MAX_DDNS_MODULEPATH)];
} DDNS_ACCOUNT_INFO;

typedef struct _tag_DDNS_HOSTNAME_INFO {
	char szHostname[ALIGN_MEM(MAX_NOIP_HOST_NAME)];
	char szDomainName[ALIGN_MEM(MAX_NOIP_DOMAIN_NAME)];
	char szIPAddr[ALIGN_MEM(MAX_IP_LENGTH)];
	BOOL bHeartBeat;
} DDNS_HOSTNAME_INFO;

// operation code for ddns registration
typedef enum _tag_DDNS_REG_OP_ {
	DDNS_REG_OP_MIN = 0,
	DDNS_REG_OP_ENUM_DOMAIN,
	DDNS_REG_OP_ADD_USER,
	DDNS_REG_OP_LOGIN,
	DDNS_REG_OP_ADD_HOST,
	DDNS_REG_OP_MAX
} DDNS_REG_OP;
// ddns registration config structure
typedef struct _tag_DDNS_REG_CONF_ {
	char				szName[MAX_DDNS_NAME];
	char				szModulePath[MAX_DDNS_MODULEPATH];
	char				szStateCode[MAX_DDNS_MODULEPATH];
	struct {
		char			szEnumDomain[MAX_DDNS_MODULEPATH];
		char			szAddUser[MAX_DDNS_MODULEPATH];
		char			szAddHost[MAX_DDNS_MODULEPATH];
	} query;
	DDNS_ACCOUNT_INFO		info;
	DDNS_HOSTNAME_INFO		host;
} DDNS_REG_CONF;
// ddns registration result structure
typedef struct _tag_DDNS_REG_RESULT_ {
	DDNS_REG_OP			operation;
	DDNS_MESSAGE			status;
	char				szStateCode[MAX_DDNS_MODULEPATH];
	union {
		char szExtIPAddr[ALIGN_MEM(MAX_IP_LENGTH)];		// external IP for the occupied hostname
		char szMaxAccount[ALIGN_MEM(MAX_IP_LENGTH)];		// max accounts in one day
		DDNS_ACCOUNT_AUTH	auth;
		PSLIBSZLIST		pslDomains;
	} response;
} DDNS_REG_RESULT;

typedef enum _tag_ddns_report_type_{
	REPORT_SUCCESS=1,
	REPORT_FAILED_RETRY, //retry to send DDNS request in next loop.
	REPORT_FAILED_RETRY_LIMITED, //retry to send DDNS request in next loop, but has limited.
	REPORT_FAILED_NOT_RETRY
}DDNS_REPORT_TYPE;

typedef struct _tag_ddns_multi_report_ {
	BOOL blExactCompare;
	char *szMsg;
	char *szStringKey;
	char *szErrReason;
	DDNS_REPORT_TYPE rType;
	DDNS_MESSAGE rMsg;
} DDNS_MULTILANG_REPORT;

#ifndef DO_PROTO
#include "synoddnsclient_p.h"
#endif // DO_PROTO

__END_DECLS;
#endif // __SYNO_DDNS_CLIENT_H__
