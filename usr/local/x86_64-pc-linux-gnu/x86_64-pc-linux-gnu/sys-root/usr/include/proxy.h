// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_PROXY_H_
#define __SYNO_PROXY_H_

#include <stdio.h>
#include <stdlib.h>

__BEGIN_DECLS;

#ifndef _HAVE_BOOL
#define _HAVE_BOOL
#undef BOOL
#undef FALSE
#undef TRUE
typedef enum{
	FALSE=0,
	TRUE=1
}BOOL;

#endif /* _HAVE_BOOL */

typedef enum {
	PROXY_ERR_SUCCESS = 0,            /**  0 success. */
	PROXY_ERR_BAD_PARAMETERS,         /**  1 Parameters incorrect. */
	PROXY_ERR_NOT_ENOUGH_MEMORY,      /**  2 Not enough storage to process. */
	PROXY_ERR_OUT_OF_MEMORY,          /**  3 allocate resource failed. */
	PROXY_ERR_PATH_NOT_FOUND,         /**  4 Path not found. */
	PROXY_ERR_FILE_NOT_FOUND,         /**  5 File not found. */
	PROXY_ERR_FILE_EXISTS,            /**  6 The file exists. */
	PROXY_ERR_FILE_OPEN_FAILED,       /**  7 Open file failed. */
	PROXY_ERR_READ_FAILED,            /**  8 Read data from the device failed. */
	PROXY_ERR_WRITE_FAILED,           /**  9 Write data to the device failed. */
	PROXY_ERR_CREATE_FAILED,          /** 10 Create file or directory failed. */

	PROXY_ERR_UNKNOWN = 99,           /** 99 for default error. */
} SYNO_PROXY_ERR;

typedef enum _tag_SYNO_PROXY_TYPE_ {
	PROXY_TYPE_HTTP,
	PROXY_TYPE_HTTPS,
} SYNO_PROXY_TYPE;

typedef enum _tag_SYNO_PROXY_SETTING_ATTR_STR_ {
	PROXY_USER,
	PROXY_PASSWORD,
} SYNO_PROXY_SETTING_ATTR_STR;

typedef enum _tag_SYNO_PROXY_SETTING_ATTR_BOOL_ {
	PROXY_ENABLED,
	PROXY_ADV_ENABLED,
	PROXY_BYPASS_ENABLED,
	PROXY_AUTH_ENABLED,
} SYNO_PROXY_SETTING_ATTR_BOOL;

typedef enum _tag_SYNO_PROXY_INFO_ATTR_ {
	PROXY_HOST,
	PROXY_PORT,
} SYNO_PROXY_INFO_ATTR;

typedef struct _tag_SYNO_PROXY_SETTING_ *PSYNO_PROXY_SETTING;
typedef struct _tag_SYNO_PROXY_INFO_ *PSYNO_PROXY_INFO;
typedef struct _tag_PROXY_KEY_VALUE_ *PPROXY_KEY_VALUE;

#ifndef NO_PROTO
#include "synoproxy_p.h"
#endif // NO_PROTO

__END_DECLS;

#endif // __SYNO_PROXY_H_
