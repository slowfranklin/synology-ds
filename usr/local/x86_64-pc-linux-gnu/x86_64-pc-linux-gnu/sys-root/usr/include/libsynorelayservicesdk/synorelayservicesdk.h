// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_RELAY_SDK_H__
#define __SYNO_RELAY_SDK_H__

#include <sys/cdefs.h>
#include <sys/types.h>
#include <stdint.h>

__BEGIN_DECLS;

#define SZF_RELAY_SERVICE_TCP_MAP "/tmp/.synorelayd_relay_tcp_map"

typedef enum _tag_RELAY_CONNECTION_ENUM_TYPE {
	RELAY_CONNECTION_ENUM_UNKNOWN       = 0,
	RELAY_CONNECTION_ENUM_DIRECT        = 16,
	RELAY_CONNECTION_ENUM_RELAY         = 32,
	RELAY_CONNECTION_ENUM_HOLE_PUNCHING = 64
} RELAY_CONNECTION_ENUM_TYPE;

typedef struct _tag_RELAY_CONNECTION_INFO {
	uint32_t                   iLocalIp;
	uint16_t                   iLocalPort;
	uint32_t                   iRemoteIp;
	uint16_t                   iRemotePort;
	RELAY_CONNECTION_ENUM_TYPE eType;
} RELAY_CONNECTION_INFO;

typedef struct _tag_RELAY_ADDR_INFO {
	unsigned char              rgszLocalIp[16];  /* network byte order */
	uint16_t                   iLocalPort;       /* host byte order */
	unsigned char              rgszRemoteIp[16]; /* network byte order */
	uint16_t                   iRemotePort;      /* host byte order */
	int                        iFamily;
	RELAY_CONNECTION_ENUM_TYPE eType;
} RELAY_ADDR_INFO;

#ifndef NO_PROTO
#include <availability.h>
#include <libsynorelayservicesdk/synorelayservicesdk_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif
