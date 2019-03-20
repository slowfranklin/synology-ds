// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_QUOTA_H__
#define __SYNO_QUOTA_H__

#include <synosdk/share.h>
#include <synosdk/volume.h>
#include <sys/types.h>
#include <dirent.h>
#include <synofileop/ea.h>

__BEGIN_DECLS;

#define QUOTA_MAX	0
#define QUOTA_LIMIT_MAX	4096  /*GB*/

typedef struct _tag_SYNO_QUOTA_ {
	float quota; /*MB*/
	unsigned long long used; /*bytes*/
} SYNOQUOTA, *PSYNOQUOTA;

typedef struct _tag_SYNO_USER_QUOTA_ {
	uid_t uid;
	SYNOQUOTA quota;
}SYNOUSERQUOTA, *PSYNOUSERQUOTA;

typedef enum _tag_SYNO_UNIT_TRANS_ {
	UNIT_MB_B,
	UNIT_B_MB,
	UNIT_MB_GB,
	UNIT_GB_MB,
	UNIT_MB_KB,
	UNIT_KB_MB,
	UNIT_MB_TB,
	UNIT_TB_MB
} UNIT_TRANS;

__END_DECLS;

#ifndef NO_PROTO
#include <synoquota/synoquota_p.h>
#endif  // NO_PROTO

#endif // __SYNO_QUOTA_H__
