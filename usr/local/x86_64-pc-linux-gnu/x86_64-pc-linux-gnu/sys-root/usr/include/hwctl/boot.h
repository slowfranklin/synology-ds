#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_BOOT_H__
#define __SYNO_BOOT_H__

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS;

#define SZF_BOOT_LOCK			"/proc/sys/kernel/syno_install_flag"
#define SZF_BOOT_DEV                    "/dev/synoboot"
#define SZF_BOOT_FACTORY                "/dev/synoboot1"
#define SZF_BOOT_CUSTOM                 "/dev/synoboot2"

#define SZF_BOOT_MNT			"/tmp/bootmnt"
#define SZF_ESP_MNT				"/boot/efi"
#define SZF_UPDATE_BOOT_FACTORY 	".update_synoboot1"
#if defined(MY_ABC_HERE)
#define SZF_VENDER_FILE                 SZF_BOOT_MNT"/vender"
#else
#define SZF_VENDER_FILE                 SZF_BOOT_MNT"/vendor"
#endif
#define SZF_VDSM_VENDER_FILE_NAME       "vender"

#define SYNO_BOOT_LOCK 1
#define SYNO_BOOT_UNLOCK 0

int SYNOBootLockFactory(void);
int SYNOBootUnlockPartition(void);
int SYNOBootUnlockFactory(void);
int SYNOBootLockPartition(void);
int SYNOBootILock(char *szTargetPartiton, int fLock);
int SYNOBootLockEsp(int fLock);

__END_DECLS;
#endif // __SYNO_BOOT_H__
