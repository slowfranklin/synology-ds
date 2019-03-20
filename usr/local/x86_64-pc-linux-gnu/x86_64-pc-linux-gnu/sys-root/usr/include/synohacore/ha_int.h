// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_HA_INT_H__
#define __SYNO_HA_INT_H__

#include <limits.h>

#include <synohacore/priority.h>
#include <synohacore/strings_sdk.h>

#define PRIORITY_DECLARE \
	int cpuPriority = 0; \
	int ioPriority = 0; \
	int oomscorePriority = INT_MIN; \
	int oomPriority = INT_MIN; \
	BOOL blHasChangedPriority = FALSE;

#define PRIORITY_BACKUP \
	if (SYNOHAChkIfChangePriority() && \
		SYNOHAGetPriority(&cpuPriority, &ioPriority, &oomscorePriority, &oomPriority)) { \
		SYNOHASetPriority(SYNOHA_CPU_PRIORITY, SYNOHA_IO_PRIORITY, SYNOHA_OOM_SCORE_PRIORITY, SYNOHA_OOM_PRIORITY); \
		blHasChangedPriority = TRUE; \
	}

#define PRIORITY_RESTORE \
	if (blHasChangedPriority) { \
		SYNOHASetPriority(cpuPriority, ioPriority, oomscorePriority, oomPriority); \
	}

#endif /* __SYNO_HA_INT_H__ */
