// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_TC_H__
#define __SYNO_TC_H__

#include <linux/syno.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

#include <synocore/list.h>
#include <synosdk/service.h>
#include <synoserviceconf/synoserviceconf.h>
#include <synofirewall/synofirewall.h>

__BEGIN_DECLS;

#define SZD_TC "/etc/tc"
#define SZD_TC_TMP "/etc/tc_tmp"
#define SZF_SCRIPTS_TC "/usr/syno/bin/synotc_common"

#define SZF_TC_RULES_DUMP "/etc/tc_rules.dump"
#define SZF_TC_6_RULES_DUMP "/etc/tc_6_rules.dump"
#define SZF_TC_CMD_DUMP "/etc/tc_cmd.sh"
#define SZF_TC_CMD_RESET "/etc/tc_cmd.sh.reset"

#define TC_ROOT_BASE 11
#define TC_LEVEL1_CLASS_BASE 1
#define TC_LEVEL2_CLASS_BASE 101
#define TC_LEAF_CLASS_BASE 1001
#define TC_LEAF_CLASS_DEFAULT 5000
#define TC_DEFAULT_HANDLE 500
#define TC_DEFAULT_RATE_MIN 200000
#define TC_DEFAULT_RATE_MAX 200000
#define TC_VALUE_MAX 4294967 // 4294967295 / 1000 (kbytes)
#define TC_FIELD_LEN 32
//#36079: Default r2q is 10, but we should set to 1 to allow user input 1kb as min rate, or kernel will print something like "HTB: quantum of class ??? is small"
#define TC_R2Q 1
//#36079: Set quantum to ignore r2q computing so that if set max rate larger than 20000, kernel will not print something like HTB: quantum of class ??? is big"
#define TC_QUANTUM 2048
#define SZF_IPTABLES_WIRELESS_INFO "/tmp/wireless.info"
#define SZF_IPTABLES_WIRELESS_AP_CONF "/usr/syno/etc/wireless_ap.conf"
#define SZK_MINRATE  "minrate"
#define SZK_MAXRATE  "maxrate"
#define SZV_TC_HTB  "htb"
#define SZV_TC_SFQ  "sfq"
#define SZV_TC_PFIFO  "pfifo"
#define SZK_TC_DOWNLOAD "download"
#define SZK_TC_UPLOAD "upload"
#define SZK_TC_DIRECTION "direction"

#define SZV_TC_ROUTER_UPLOAD_INTERFACE "upload"
#define CH_IPRANGE_TOKEN '-'

typedef enum _tag_syno_ip_direct_type_{
	IP_DESTINATION = 0,
	IP_SOURCE,
} SYNO_IP_DIRECT_TYPE;
typedef enum _tag_syno_firewall_ports_class_{
	FW_PORTS_SERVICE=1,
	FW_PORTS_CUSTOM,
	FW_PORTS_ALL,
	FW_PORTS_RESERVED
} SYNO_FW_PORTS_CLASS;
typedef enum _tag_syno_firewall_port_type_{
	FW_PORT_DESTINATION,
	FW_PORT_SOURCE,
} SYNO_FW_PORT_TYPE;

typedef struct _tag_syno_firewall_tc_rate_{
	unsigned int min;
	unsigned int max;
} SYNO_FW_TC_RATE;
typedef struct _tag_syno_firewall_tc_rule_{
	int id;
	BOOL isEnabled;
	char szSource[128];
	char *szDstPorts; //'21,24,.. or 21-1024'
	SYNO_FW_PROTOCOL protocol;
	SYNO_FW_TC_RATE tcrate;
	SYNO_IP_DIRECT_TYPE ipDirect;
	struct _tag_syno_firewall_tc_rule_ *pNext;
} SYNO_FW_TC_RULES;
typedef struct _tag_syno_firewall_tc_iptable_rule_ {
	char szInterface[SYNO_IFNAME_MAX];
	char szSource[128]; //192.168.1.X/255.255.0.0
	char *szDstPorts;
	char szProtocol[TC_FIELD_LEN];
} SYNO_FW_TC_IPTABLE_RULE;
typedef struct _tag_syno_firewall_tc_adapter_{
	char szName[SYNO_IFNAME_MAX]; //eth0, eth1, ...
	SYNO_FW_TC_RULES *pRules;
} SYNO_FW_TC_ADAPTER;
typedef struct _tag_syno_firewall_tc_rule_dump_option_ {
	char szTrgv4Path[PATH_MAX];
	char szTrgv6Path[PATH_MAX];
	char szTrgTcCmdPath[PATH_MAX];
} SYNO_FW_TC_RULEDUMP_OPT;

typedef struct _tag_syno_firewall_tc_class_ {
	char szParent[TC_FIELD_LEN];
	char szClassID[TC_FIELD_LEN];
	char szHandle[TC_FIELD_LEN];
	char szQdisc[TC_FIELD_LEN];
	unsigned int minrate; //unit: Kb
	unsigned int maxrate; //unit: Kb
	unsigned int priority;
	struct _tag_syno_firewall_tc_qdisc_ *pLeafQdisc;
	struct _tag_syno_firewall_tc_class_ *pNext;
} SYNO_FW_TC_CLASS;

typedef struct _tag_syno_firewall_tc_qdisc_ {
	char szInterface[SYNO_IFNAME_MAX]; //ex: eth0, wlan0
	char szParent[TC_FIELD_LEN];
	char szHandle[TC_FIELD_LEN];
	char szQdisc[TC_FIELD_LEN];
	int classNum; //only count L2Class
	SYNO_FW_TC_CLASS *L1Class;
	SYNO_FW_TC_CLASS *L2Class;
	struct _tag_syno_firewall_tc_qdisc_ *pNext;
} SYNO_FW_TC_QDISC;

#ifndef NO_PROTO
#include <availability.h>
#include <synotc/synotc_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_TC_H__
