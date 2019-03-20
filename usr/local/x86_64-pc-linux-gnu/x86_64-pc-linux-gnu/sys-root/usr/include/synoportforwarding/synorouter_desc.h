// Copyright (c) 2000-2009 Synology Inc. All rights reserved.

#ifndef __SYNO_ROUTER_DESC_H__
#define __SYNO_ROUTER_DESC_H__

#include "synopf.h"

__BEGIN_DECLS;

//section name
#define SZ_SECTION_GLOBAL						"global"
#define SZ_PORT_PAGE							"PF port page"
#define SZ_RANGE_PAGE							"PF range page"

//key in [global] section
#define SZK_RDESC_DEFAULT_USER			"default user"
#define SZK_RDESC_DEFAULT_PASS			"default pass"
#define SZK_RDESC_CGI_WAIT_TIME			"cgi wait time"
#define SZK_RDESC_POST_LOGIN			"post login"
#define SZK_RDESC_POST_LOGOUT			"post logout"
#define SZK_RDESC_SYNTAX_VERSION		"syntax version"
#define SZK_RDESC_ROUTER_TYPE			"router type"
/* setup http auth method - digest*/
#define SZK_RDESC_LOGIN_DIGEST			"digest"

//other
//#define SZK_RDESC_DMZ_ADD			"DMZ add"
//#define SZK_RDESC_DMZ_DELETE		"DMZ delete"

//key in add single port (cgi)section
//[PF port page ] ,[PF range page]
#define SZK_RDESC_TCP							"tcp"
#define SZK_RDESC_UDP							"udp"
#define SZK_RDESC_TCP_UDP						"tcp_udp"
#define SZK_RDESC_CHANGE_RPORT			"change router port"
#define SZK_RDESC_MAX_RULE						"max rule"
#define SZK_RDESC_START_RULE_ID			"rule id start"
#define SZK_RDESC_DELETE_TYPE			"delete type"           //no, one, all
#define SZK_RDESC_TOKEN_DELIMITER		"token delimiter"       //ex 50,60,70-80 (,)
#define SZK_RDESC_RAMGE_DELIMITER		"range delimiter"       //ex 50-60 (-)
#define SZK_RDESC_SUPPORT_PORT			"support port"          //single or multi
#define SZK_RDESC_SUPPORT_RANGE 		"support range"         //single or multi
#define SZK_RDESC_SUPPORT_MIX			"support mix port and range"    //80,90-100
#define SZK_RDESC_SUBMIT_POST			"submit post"           //yes
#define SZK_RDESC_ADD_TYPE						"add type"                      //all
/* setup customize http header for http request */
#define SZK_RDESC_HTTP_HEADER			"http header"           //syntax version=002

//value
#define SZV_RDESC_YES                   "yes"
#define SZV_RDESC_SUPPORT_TOKEN_SINGLE  "single"
#define SZV_RDESC_SUPPORT_TOKEN_MULTI   "multi"
#define SZV_RDESC_DELETE_TYPE_ONE		"one"
#define SZV_RDESC_ALL					"all"
#define SZV_RDESC_DELETE_TYPE_NO		"no"
#define SZV_RDESC_ADD_TYPE_ALL			"all"

__END_DECLS;

#endif // __SYNO_ROUTER_DESC_H__
