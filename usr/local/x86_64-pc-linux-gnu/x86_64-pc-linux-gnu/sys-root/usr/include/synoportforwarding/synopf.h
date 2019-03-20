// Copyright (c) 2000-2009 Synology Inc. All rights reserved.

#ifndef __SYNO_PF_H__
#define __SYNO_PF_H__

#include <linux/limits.h>
#include <synocore/hash.h>
#include <synosdk/service.h>
#include <synocore/synotype.h>
#include <synocore/bsd.h>

__BEGIN_DECLS;

#define SYNO_PF_DB_SYNTAX_VERSION		"012"

//basic project related path
#define PATH_PF_ROOT			"/etc/portforward"
#define PATH_PF_DB_ROOT			"/var/lib/portforward"
//config & rule save path
#define PATH_ROUTER_CONF		SZD_PF_ROOT "/router.conf"
#define PATH_ROUTER_RULE		SZD_PF_ROOT "/rule.conf"
#define SZF_PF_RULE_TEST		SZD_PF_ROOT "/testrule.conf"

// dnat rule save path
#define SZD_ROUTER_PORTFWD		PATH_PF_ROOT"/routerpf"
#define SZF_ROUTER_PORTFWD_DNAT_DUMP  SZD_ROUTER_PORTFWD"/dnat_rules.dump"
#define SZF_ROUTER_PORTFWD_FILTER_DUMP  SZD_ROUTER_PORTFWD"/filter_rules.dump"
#define SZF_ROUTER_PORTFWD_RULE  SZD_ROUTER_PORTFWD"/rule.conf"

// dmz conf path
#define SZF_ROUTER_DMZ_CONF		SZD_ROUTER_PORTFWD"/dmz.conf"

//Router DB path
#define PATH_ROUTER_DB_ROOT								PATH_PF_DB_ROOT "/routerdb"
#define FILE_ROUTER_DB_VERSION_NAME						"routerdb_version"
#define FILE_ROUTER_SDK_VERSION_NAME						"routersdk_version"
#define FILE_ROUTER_DB_VERSION							PATH_PF_DB_ROOT "/" FILE_ROUTER_DB_VERSION_NAME
#define FILE_ROUTER_SDK_VERSION							PATH_PF_DB_ROOT "/" FILE_ROUTER_SDK_VERSION_NAME
#define FILE_ROUTER_DESC										"router.des"
#define FILE_ROUTER_OPS											"router.syn"
#define FILE_ROUTER_DB_CUSTOMIZE_OPS			PATH_PF_DB_ROOT "/" FILE_ROUTER_OPS
#define FILE_ROUTER_DB_CUSTOMIZE_DESC			PATH_PF_DB_ROOT "/" FILE_ROUTER_DESC

#define BUF_SIZE								1024
#define MAX_SECTION_NAME				1024

//key in routerdb_version
#define SZK_ROUTER_DB_VERSION					"version"

//Keys in router.conf
#define SZK_ROUTER_USER									"user"
#define SZK_ROUTER_PASS									"pass"
#define SZK_ROUTER_CONN_TYPE					"conn_type"
#define SZK_ROUTER_CONN_PORT					"conn_port"
#define SZK_ROUTER_BRAND								"brand"
#define SZK_ROUTER_MODEL								"model"
#define SZK_ROUTER_VERSION								"version"
#define SZK_ROUTER_TYPE						"router_type"
#define SZK_ROUTER_USE_CUSTOM_ACCOUNT	"use_custom_account"

//Value in router.conf
#define SZV_ROUTER_USE_CUSTOM_ACCOUNT_YES		"on"

//File for record generic version
#define SZF_GENERIC		"generic"

#define MAX_VERSION_LEN	(128)
//Key in file generic
#define SZK_VERSION		"version"

typedef enum _tag_syno_pf_rule_status {
	SYNO_PF_RULE_STATUS_DISABLED,
	SYNO_PF_RULE_STATUS_UNKNOWN,
	SYNO_PF_RULE_STATUS_OK,
	SYNO_PF_RULE_STATUS_FAIL,
	SYNO_PF_RULE_STATUS_WAITING,
	SYNO_PF_RULE_STATUS_NO_LISTEN
} SYNO_PF_RULE_STATUS;

//for router.conf, rule.conf, router.des
typedef struct _tag_syno_pf_conf {
	char szSecName[MAX_SECTION_NAME];
	PSLIBSZHASH	pshSection;
	struct _tag_syno_pf_conf *pNext;
} SYNO_PF_CONF, *PSYNO_PF_CONF;

//for rule.conf
typedef struct _tag_syno_ruleconf_ {
	char			*szProtocol;
	char			*szDesc;
	char			*szSecName;
	unsigned int		ds_port;
	unsigned int 		ds_port_end;
	unsigned int		router_port;
	unsigned int 		router_port_end;
	BOOL			enable;
	struct _tag_syno_ruleconf_	*pNext;
} SYNO_RULECONF, *PSYNO_RULECONF;

// output test port connection result of SynoPortConnTest() 
typedef struct __tag_syno_test_connection {
	char szRuleId[MAX_SECTION_NAME];
	SYNO_PF_RULE_STATUS enRuleStatus;
} SYNO_TEST_CONNECTION; 

//for router.syn
typedef struct _tag_syno_pf_script {
	char szSecName[MAX_SECTION_NAME];
	PSLIBSZLIST	pListSection;
	struct _tag_syno_pf_script *pNext;
} SYNO_PF_SCRIPT, *PSYNO_PF_SCRIPT;

//global varialbe for router
typedef struct _tag_syno_pf_router_var_ {
	int iRulePortAdd;
	int iRulePortDel;
	int iRuleRangeAdd;
	int iRuleRangeDel;
	int iCgiWaitTime;
	int iRuleAddNum;
	int iJobAddNum;
	BOOL blUseCustomize;
	char szSrcIp[16];
	char szRouterIp[16];
	int iJobAddNumTotal;
	int iJobDelNumTotal;
} SYNO_PF_ROUTER_VAR, *PSYNO_PF_ROUTER_VAR;

//define for rule.conf
#define SZK_RULE_ENABLE					"enabled"
#define	SZK_RULE_SRC_PORT				"s_port"
#define SZK_RULE_ROUTER_PORT	"r_port"
#define SZK_RULE_DAEMON_PORT	"d_port"
#define SZK_RULE_PROTO					"protocol"
#define SZK_RULE_SERVICE_NAME	"service"
#define SZK_RULE_SERVICE_ID	"service_id"
#define SZK_RULE_PROTO_NAME				"protocol name"         //tcp, udp, all
//option
#define SZK_RULE_SRC_IP			"s_ip"
#define SZK_RULE_ROUTER_IP		"r_ip"
#define SZK_DMZ_IP				"dmz_ip"

//value of rule.conf
#define SZV_RULE_ENABLE					"1"
#define SZV_RULE_DISABLE					"0"
#define SZV_RULE_PROTO_TCP				"tcp"
#define SZV_RULE_PROTO_UDP				"udp"
#define SZV_RULE_PROTO_TCP_UDP	"all"

#define MAX_RULE_SERVICE		512
#define MAX_RULE_PORT			512
#define MAX_SIZE_PORTS			512
#define MAX_RULE_ID						99999

//type for rule/router port
#define PF_PORT_MASK			0x000F
#define PF_PORT_SINGLE			0x0001
#define PF_PORT_MULTI			0x0002

#define PF_RANGE_MASK			0x00F0
#define PF_RANGE_SINGLE			0x0010
#define PF_RANGE_MULTI			0x0020

#define PF_MIX_MASK						0x0F00
#define PF_MIX_RANGE_PORT		0x0100

#define			PF_FILE_COOKIE					"/tmp/pfHeader"

//testing tool
#define	SYNO_PF_MAX_PORT_NUM							65536
#define SYNO_PF_RULE_TEST_STATUS_OK				"yes"
#define SYNO_PF_RULE_TEST_STATUS_FAIL			"fail"
#define SYNO_PF_RULE_TEST_STATUS_WAITING		"waiting"
//#define SYNO_PF_RULE_TEST_STATUS_UDP		"udp"		//udp cannot test connection
#define SYNO_PF_RULE_TEST_STATUS_NO_LISTEN		"nolisten"

#define SYNO_PF_TEST_SERVER				"checkport.synology.com"
#define	SYNO_PF_TEST_SERVER_PORT		"82"
#define SYNO_PF_TEST_STATUS_RULE		"/tmp/pfStatusRule"
#define SYNO_PF_TEST_STATUS_STATE		"/tmp/pfNetstate"
#define SYNO_PF_TEST_RULE_NUM_PER_CMD	5
#define SYNO_PF_TEST_TIMEOUT					SYNO_PF_TEST_RULE_NUM_PER_CMD * 10 + 5
#define SYNO_PF_TEST_PORT_FD_NOT_TEST	-1
#define SYNO_PF_TEST_PORT_FD_OK					-2
#define SYNO_PF_TEST_PORT_FD_FAIL				-3

typedef struct _tag_syno_pf_rule_test {
	char szRuleId[BUF_SIZE];
	char szProto[BUF_SIZE];
	int routerPort[SYNO_PF_MAX_PORT_NUM];
	int fd[SYNO_PF_MAX_PORT_NUM];
	struct _tag_syno_pf_rule_test *pNext;
} SYNO_PF_RULE_TEST;

//update DB
#define SYNO_PF_DB_SERVER						"download.synology.com/routerdb"
#define SYNO_PF_DB_FILE							"routerdb2.tgz"
#define SYNO_UPNP_DB_FILE						"router_upnp.db"
#define SYNO_PF_DB_TMP_FILE						"/tmp/pfRouterdbTmp"

//for job
#define SYNO_PF_JOB_START_ID			1

//use other binary
#define	SYNO_PF_BINARY_ECHO				"/bin/echo"

//key in synoinfo
#define SYNO_PF_ROUTER_DB_PATH_KEY		"routerdbpath"

//run time log
#define SYNO_PF_PROGRESS_STATUS			"/tmp/pfProgress"
#define SYNO_PF_CGI_OUTPUT				"/tmp/pfOutput"

/**
 * parameter container for keeping parameters
 * and execute with SLIBCExecv
 *
 */
typedef struct __tag_SYNO_PF_PARAMETER_CONTAINER {
	PSLIBSZLIST pParams;
} SYNO_PF_PARAMETER_CONTAINER;

#ifndef NO_PROTO
#include "synopf_p.h"
#endif // NO_PROTO

__END_DECLS;

#endif // __SYNO_PF_H__
