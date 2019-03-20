// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_BACKUP_H__
#define __SYNO_BACKUP_H__

#include <stdint.h>
#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <linux/syno.h>
#include <synocore/hash.h>
#include <synocore/list.h>
#include <synosdk/share.h>
#include <unistd.h>

__BEGIN_DECLS;
// For hidrive
#define SZF_BACKUP_DO_RECOVER	"/tmp/do_recover.chk"

// for backup application
#define	SZF_BACKUP_DO_RECOVER_STATUS	"/tmp/do_recover_status.chk"

#ifndef NO_PROTO
#include <availability.h>
#include <synofileop/backup_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_BACKUP_H__
