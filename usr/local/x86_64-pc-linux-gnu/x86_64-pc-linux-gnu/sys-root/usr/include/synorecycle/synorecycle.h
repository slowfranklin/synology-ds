// Copyright (c) 2000-2012 Synology Inc. All rights reserved.

#ifndef __SYNO_RECYCLE_H__
#define __SYNO_RECYCLE_H__

#include <linux/syno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/stat.h>
#include <dirent.h>
#include <asm/unistd.h>
#include <dlfcn.h>
#include <synosdk/share.h>
#include <synosdk/user.h>
#include <synocore/string.h>
#include <synocore/proc.h>
#include <synocore/file.h>
#include <synofileop/index.h>
#include <synofileop/copy.h>
#include <synosdk/fs.h>

__BEGIN_DECLS;

typedef struct _SYNO_RECYCLE_POLICY_CLEAN_ {
	int iPolicy;
	int nLimitDay;
	int nOrderby;
	int nLimitSizePercent;
	unsigned long long nLimitSizeByte;
	unsigned long long nFileSizeMore;
	unsigned long long nFileSizeLess;
	PSLIBSZLIST pListFileExt;
} SYNO_RECYCLE_POLICY_CLEAN;

#ifndef NO_PROTO
#include "synorecycle_p.h"
#endif // NO_PROTO

__END_DECLS;

#endif	// __SYNO_RECYCLE_H__
