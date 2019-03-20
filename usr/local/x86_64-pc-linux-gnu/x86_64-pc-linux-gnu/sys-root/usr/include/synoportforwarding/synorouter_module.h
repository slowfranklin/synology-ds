//Copyright (c) 2000-2010 Synology Inc. All rights reserved.

#ifndef __SYNO_ROUTER_MODULE_H__
#define __SYNO_ROUTER_MODULE_H__

#include "synopf.h"

__BEGIN_DECLS;

//module name list
#define SYNO_PF_MODULE_WEBPAGE_GET              	"syno_webpage_get"
#define SYNO_PF_MODULE_WEBPAGE_PARSE_INPUT_PARAM	"syno_webpage_parse_input_param"
#define SYNO_PF_MODULE_EXEC_AND_GET_RETURN      	"syno_exec_and_get_return"
#define SYNO_PF_MODULE_EXEC_AND_GET_OUTPUT      	"syno_exec_and_get_output"
#define SYNO_PF_MODULE_MD5                      	"syno_md5"
#define SYNO_PF_MODULE_MD5_HEX                  	"syno_md5_hex"
#define SYNO_PF_MODULE_MD5_BASE64               	"syno_md5_base64"

//flow control module name list
#define SYNO_PF_FLOW_MODULE_IF_GREATER_THAN     "syno_if_greater_than"
#define SYNO_PF_FLOW_MODULE_SLEEP				"syno_sleep"

//customize operation prefix
#define SYNO_PF_OP_CUSTOMIZE_PREFIX             "${syno_custom"

//customize macro prefix
#define SYNO_PF_OP_CUSTOMIZE_MACRO_PREFIX       "${syno_macro"

//parameter function misc
#define SYNO_PF_MAX_NUM_FUNC_PARAMETER          32
#define SYNO_PF_MAX_PARAM_SIZE			        1024

//syno_webpage_get, return path
#define SYNO_PF_TMP_FILE_WEB_PAGE               "/tmp/pfWebPageGet"

__END_DECLS;

#endif // __SYNO_ROUTER_MODULE_H__
