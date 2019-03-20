// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_SCEMD_STATUS_H_
#define __SYNO_HWCTL_SCEMD_STATUS_H_

#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZF_SCEMD_READY "/tmp/.scemd_ready"

typedef enum {
	SCEMD_UNKNOWN,
	SCEMD_TERM,
	SCEMD_START,
	SCEMD_RESTART,
} SCEMD_STAT;

BOOL SYNOIsScemdReady(void);
int SYNOSetScemdStatus(SCEMD_STAT Status);

__END_DECLS;
#endif /* __SYNO_HWCTL_SCEMD_STATUS_H_ */
