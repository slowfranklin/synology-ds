// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_MATRIX_H
#define SYNO_FHOST_MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <synocore/hash.h>
#include <netinet/in.h>

__BEGIN_DECLS;

#define SZF_FINDHOSTD_PID      "/var/run/findhostd.pid"
#define SZF_HOST_LIST          "/tmp/synods.list"
#define SZF_HOST_LIST_TMP      "/tmp/synods.list.tmp"
#define FINDHOST_PORT		9999
#define RSYNC_VER		240

#ifndef NO_PROTO
#include "fhost_socket_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif
