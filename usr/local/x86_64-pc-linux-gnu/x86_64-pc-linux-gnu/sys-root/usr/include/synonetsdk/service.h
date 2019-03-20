// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNONET_SERVICE_H__
#define __SYNONET_SERVICE_H__

#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synosdk/share.h>
#include <synosdk/volume.h>
#include <synosdk/plugin.h>
#include <synocore/conf.h>
#include <synosdk/service.h>
__BEGIN_DECLS;

// copy from service_int.h
#define MAX_PROC 256

typedef	struct	_tag_SYNO_PPPOE_CONFIG_ {
	char szInterface[16];
	char szUser[256];
	char szPassword[32];
	char szMTU[8];
	BOOL blDefaultGateway;
} PPPOECONFIG;

typedef struct	_tag_SYNO_TUNNEL_CONFIG_ {
	char blAnonymous;
	char szServer[256];
	char szUser[256];
	char szPassword[TUNNEL_PASSWD_MAX_LEN];
} TUNNELCONFIG;

#ifndef NO_PROTO
#include <availability.h>
#include <synonetsdk/service_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNONET_SERVICE_H__
