// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNOPOWEROFF_SYSTEM_H__
#define __SYNOPOWEROFF_SYSTEM_H__

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>

__BEGIN_DECLS;

typedef enum _tag_SLIB_INIT_OPT_ {
	SLIB_SHUTDOWN = 0,
	SLIB_REBOOT,
	SLIB_KEXEC,
} SLIB_INIT_OPT;

#ifndef NO_PROTO
#include <synopoweroff/system_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif /* __SYNOPOWEROFF_SYSTEM_H__ */
