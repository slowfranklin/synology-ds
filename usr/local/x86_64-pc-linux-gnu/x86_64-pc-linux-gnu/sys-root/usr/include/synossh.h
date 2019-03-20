// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_LIB_SSH_H__
#define __SYNO_LIB_SSH_H__

#include <sys/cdefs.h>

#include <synocore/list.h>
#include <synosdk/share.h>
#include <unistd.h>
#include <limits.h>

__BEGIN_DECLS;

typedef struct _tag_SYNO_SSH_CONF_ {
	unsigned int port;
	char szCipher[1024];
	char szKex[1024];
	char szMac[1024];
} SYNO_SSH_CONF;

#define SZK_SSH_PORT            "ssh_port"
#define SSH_DEFAULT_PORT		22
#define SZF_SSHD_CONFIG			"/etc/ssh/sshd_config"

#ifndef NO_PROTO
#include <availability.h>
#include "synossh_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_LIB_SSH_H__
