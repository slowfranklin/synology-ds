// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICECONF_H__
#define __SYNO_SERVICECONF_H__

#include <inttypes.h>
#include <stddef.h>

#include <linux/syno.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

#include <synocore/list.h>
#include <synocore/dlist.h>
#include <synosdk/service.h>
#include <synocore/conf.h>
#include <netinet/tcp.h>

__BEGIN_DECLS;

#define SZD_FIREWALL_SERVICE_DIRECTORY "/usr/syno/etc/services.d/"

// MFP daemon listening port and client connection port range.
#define PORT_MFP_LOW	3240 // Be consistent with definintion of USBIP_PORT @ usbip-0.1.7/src/cmd/usbip_network.h and
#define PORT_MFP_HIGH	3259 // SYNO_USBIP_DATA_PORT_START, SYNO_USBIP_DATA_PORT_END @ usbip-0.1.7/src/cmd/synofunc.h

// avahi bonjour listening port
#define SZ_AVAHI_UDP_PORT	"5353"

typedef struct _tag_mapping_protocol_ {
	const char * szWordStr;
	int wordNum;
} WORD_MAP;

//Services
typedef int (*PFUNC_FwPorts) (PSLIBSZLIST *ppslPorts);

typedef struct _tag_syno_firewall_service_ports_{
	BOOL blHasPort;
	int protocol;  // FW_PROTOCOL_TCP | FW_PROTOCOL_UDP
	char *szPorts; //split by ',' ; NULL means to use function pointer
	PFUNC_FwPorts pPortsFunc;
} SYNO_FW_SERVICE_PORTS;

typedef struct _tag_syno_firewall_string_{
	char szApp[256];
	char szSection[64];
	char szKey[128];
	char szDefaultStr[128];
	char szExtraStr[128];
} SYNO_FW_STRING;

typedef struct _tag_syno_firewall_ports_{
	int protocol;  // FW_PROTOCOL_TCP | FW_PROTOCOL_UDP
	PSLIBSZLIST pslPorts;
} SYNO_FW_PORTS;

typedef struct _tag_syno_firewall_service_{
	char szName[64]; 	//service id: e.g. "web", "ftp", ...
	BOOL blSupported;	//support this service or not
	BOOL blPortFwd;		//show in router page or not
	SYNO_FW_STRING uiName;	//title (desc)
	SYNO_FW_STRING uiDesc;	//protocol's description
	SYNO_FW_PORTS dstPorts;	//destination port (portocol's destination)
	SYNO_FW_PORTS srcPorts;	//source port
	struct _tag_syno_firewall_service_ *pNext;
} SYNO_FW_SERVICES;

// Service conf section
typedef enum {
	SERV_PORT_TARGET_SRC = 0,
	SERV_PORT_TARGET_DST
} SYNO_SERV_PORT_TARGET;

typedef enum {
	SERV_PORT_TYPE_SINGLE = 0,
	SERV_PORT_TYPE_PORTRANGE
} SYNO_SERV_PORT_TYPE;

typedef struct _tag_SYNO_SERVICE_CONF_PORT_ {
	SYNO_SERV_PORT_TARGET target; //can be SERV_PORT_TARGET_SRC or SERV_PORT_TARGET_DST
	SYNO_SERV_PORT_TYPE portType; //can be SERV_PORT_TYPE_SINGLE or SERV_PORT_TYPE_PORTRANGE
	unsigned int protocol; //can be SERV_PROTOCOL_UDP, SERV_PROTOCOL_TCP, SERV_PROTOCOL_UDP|SERV_PROTOCOL_TCP
	unsigned int port1; //Single port or the start port of port range
	unsigned int port2; //End port of port range
	struct _tag_SYNO_SERVICE_CONF_PORT_ * pNext;
} SYNO_SERVICE_CONF_PORT;

typedef struct _tag_port_range_ {
	int nItem;
	SYNO_SERVICE_CONF_PORT * pFirst;
} SYNO_PORT_RANGE;

typedef struct _tag_SYNO_SERVICE_STRING_{
	char szApp[SERVICE_SECTION_NAME_MAX];
	char szSection[UISTRING_SECTION_MAX];
	char szKey[UISTRING_KEY_MAX];
	char szDefaultStr[SERVICE_DEF_STR_MAX];
	char szExtraStr[SERVICE_DEF_STR_MAX];
} SYNO_SERVICE_STRING;

typedef struct _tag_SYNO_SERVICE_CONF_SECTION_ {
	char szSectionName[SERVICE_SECTION_NAME_MAX];
	SYNO_SERVICE_STRING uiTitle;
	SYNO_SERVICE_STRING uiDesc;
	BOOL blPortFwd;
	SYNO_SERVICE_CONF_PORT * pSrcPortList;
	SYNO_SERVICE_CONF_PORT * pDstPortList;
	struct _tag_SYNO_SERVICE_CONF_SECTION_ * pNext;
} SYNO_SERVICE_CONF_SECTION;

typedef struct _tag_SYNO_SERVICE_CONF_ {
	unsigned int version;
	char szSupportKey[UISTRING_KEY_MAX];
	char szRunKey[UISTRING_KEY_MAX];
	SYNO_SERVICE_CONF_SECTION * pSectionList;
	struct _tag_SYNO_SERVICE_CONF_ * pNext;
} SYNO_SERVICE_CONF;

typedef struct _tag_SYNO_SET_VAR_ {
	int postAction; //1: POST_ACTION_NORESTART, 2: POST_ACTION_RESTART. (restart after the last configure setting)
	int restartServ; //services want to do restart action after setting can be ORed together (ex: SERVINDEX_FIREWALL | SERVINDEX_ROUTER)
	int setFlag; //WRITE_ACTION_OVERWRITE or WRITE_ACTION_APPEND
	int targetSettingConf; //Indicate which conf to set. It can be ORed together. (ex: SERVINDEX_ROUTER | SERVINDEX_CONF_FILE)
	char szFileName[SERVICE_SECTION_NAME_MAX]; //configure file name
	char szSectionName[SERVICE_SECTION_NAME_MAX]; //configure section name
	unsigned int servType; //SERV_PACKAGE, SERV_BUILDIN
	SYNO_SERVICE_CONF_PORT * pSrcPortList;
	SYNO_SERVICE_CONF_PORT * pDstPortList;
} SYNO_SET_VAR;

typedef struct _tag_SYNO_NOTIFY_VAR_ { // for update .sc
	const char *szfOldScFilePath;
	const char *szfNewScFilePath;
	BOOL blNotifyFirewall;
	BOOL blNotifyPortForward;
} SYNO_NOTIFY_VAR;

typedef struct _tag_SYNO_REMOVE_NOTIFY_VAR_ { // for remove .sc
	const char *szfConfPath;
	BOOL blNotifyFirewall;
	BOOL blNotifyPortForward;
} SYNO_REMOVE_NOTIFY_VAR;

// Config Port Conflict Check
typedef PSLIBCDLIST PSYNO_CONF_PORT_CONFLICT_RESULT_LIST;
typedef struct _tag_SYNO_CONF_PORT_CONFLICT_RESULT{
    uint16_t Port;
    uint16_t Protocol;
    char *ServiceName;
    BOOL IsConflict;
} SYNO_CONF_PORT_CONFLICT_RESULT, *PSYNO_CONF_PORT_CONFLICT_RESULT;

// Runtime Port Conflict Check
typedef PSLIBCDLIST PSYNO_RUNTIME_PORT_CONFLICT_RESULT_LIST;
typedef struct {
    uint16_t Port;
    uint16_t Protocol;
    uint32_t Pid;
    uint32_t State;
    char *ProgramCommand;
    BOOL IsConflict;
} SYNO_RUNTIME_PORT_CONFLICT_RESULT, *PSYNO_RUNTIME_PORT_CONFLICT_RESULT;

#ifndef NO_PROTO
#include <availability.h>
#include <synoserviceconf/synoserviceconf_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_SERVICECONF_H__
