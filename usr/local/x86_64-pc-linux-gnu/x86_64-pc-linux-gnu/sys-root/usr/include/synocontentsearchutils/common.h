//Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __CONTENT_SEARCH_UTILS_COMMON_H__
#define __CONTENT_SEARCH_UTILS_COMMON_H__

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/select.h>

__BEGIN_DECLS;

/** Search result record structure*/
typedef struct _tag_search_record {
	/** file full path*/
	char szPath[PATH_MAX + 1];
	/** file name*/
	char szName[PATH_MAX + 1];
	/** file extension*/
	char szExt[16];
	/** file is directory*/
	int blIsDir;
} SYNOSearchRecord;

/** Search callback function proto, it will be called for each result*/
typedef bool (*SYNOSearchCallback)(const SYNOSearchRecord *pRecord, void *cbData);

/** Deamon connection error code*/
typedef enum _tag_connection_error {
	CONNECTION_ERR_NONE              = 0,
	CONNECTION_ERR_BAD_PARAMETER     = -1,
	CONNECTION_ERR_SOCKET            = -2,
	CONNECTION_ERR_TIMEOUT           = -3,
	CONNECTION_ERR_RESP_FORMAT       = -4,
	CONNECTION_ERR_PATH_NOT_FOUND    = -5,
	CONNECTION_ERR_SOCKET_WRITE      = -6,
	CONNECTION_ERR_SOCKET_READ       = -7,
	/** For SYNOQueryConnection */
	CONNECTION_ERR_MALLOC_CONNECTION = -8
} ConnectionErr;

/** SYNOQueryConnection is used for c*/
typedef struct _query_connection {
	/** daemon connection socket*/
	int sockfd;
	fd_set readFdSet;
} SYNOQueryConnection;

__END_DECLS;

#endif
