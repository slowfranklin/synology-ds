// Copyright (c) 2000-2009 Synology Inc. All rights reserved.

#ifndef __SYNO_ROUTER_SCRIPT_H__
#define __SYNO_ROUTER_SCRIPT_H__

#include "synopf.h"

__BEGIN_DECLS;

//section name
#define SZK_RDB_SECTION_LOGIN							"login"
#define SZK_RDB_SECTION_LOGOUT							"logout"
#define SZK_RDB_SECTION_PF_ADD_PORT						"PF add port"
#define SZK_RDB_SECTION_PF_ADD_RANGE			"PF add range"
#define SZK_RDB_SECTION_PF_DEL_PORT						"PF delete port"
#define SZK_RDB_SECTION_PF_DEL_RANGE			"PF delete range"

// variable
#define SZ_PF_OP_HTTP_USER						"${user}"
#define SZ_PF_OP_HTTP_PASS						"${pass}"
#define SZ_PF_OP_HTTP_CONN_TYPE			"${http}"
#define SZ_PF_OP_HTTP_HEADER			"${http_header}"
#define SZ_PF_OP_HTTP_CONN_PORT			"${router_port}"
#define SZ_PF_OP_ROUTER_IP						"${router_ip}"
#define SZ_PF_OP_SRC_IP_NETWORK			"${src_ip_network}"             //192.168.5
#define SZ_PF_OP_SRC_IP_1						"${src_ip1}"                    //192
#define SZ_PF_OP_SRC_IP_2						"${src_ip2}"                    //168
#define SZ_PF_OP_SRC_IP_3						"${src_ip3}"                    //5
#define SZ_PF_OP_SRC_IP_4						"${src_ip4}"                    //220, alias name of SZ_PF_OP_SRC_IP_HOST
#define SZ_PF_OP_SRC_IP_HOST			"${src_ip_host}"                //220
#define SZ_PF_OP_SRC_IP							"${src_ip}"                             //192.168.5.220
#define SZ_PF_OP_RULE_ID						"${rule_id}"
#define SZ_PF_OP_COMMENT						"${comment}"
#define SZ_PF_OP_PROTO							"${proto}"
#define SZ_PF_OP_SRC_PORT_START			"${sport_start}"
#define SZ_PF_OP_SRC_PORT_END			"${sport_end}"
#define SZ_PF_OP_SRC_PORT_NUM			"${sport_num}"
#define SZ_PF_OP_SRC_PORT						"${sport}"
#define SZ_PF_OP_ROUTER_PORT_START		"${rport_start}"
#define SZ_PF_OP_ROUTER_PORT_END		"${rport_end}"
#define SZ_PF_OP_ROUTER_PORT_NUM		"${rport_num}"
#define SZ_PF_OP_ROUTER_PORT			"${rport}"
#define SZ_PF_OP_ID_NUM_PREFIX			"${num"                                 //${num1-20} or ${num1-last}
#define SZ_PF_OP_ID_NUM_HEX 			"0x"                                    //${num0x1-20} hexadecimal int
#define SZ_PF_OP_ID_NUM_OCT 			"oct"                                   //${numoct1-20} octal int
#define SZ_PF_OP_ID_NUM_LAST_ENTRY		"last"                                  //${num1-last}
#define SZ_PF_OP_ID_NUM_MAX_RULE		"max"                                   //${num1-max},  synax version 002
#define SZ_PF_OP_ID_NUM_CURRENT 		"curr"                                  //${num1-curr}, synax version 005
#define SZ_PF_OP_PF_ADD_JOB_NUM			"${pf_add_job_num}"
#define SZ_PF_OP_DEFAULT_VALUE			":"                                             //${sport:0} , 0 is default value

#define SZ_PF_OP_VALUE_COMMENT			"syno"

__END_DECLS;

#endif // __SYNO_ROUTER_SCRIPT_H__
