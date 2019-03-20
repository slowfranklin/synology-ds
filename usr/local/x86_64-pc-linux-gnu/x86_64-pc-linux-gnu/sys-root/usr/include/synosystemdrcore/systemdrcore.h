/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_EXT_H__
#define __SYNOSYSDRCORE_EXT_H__

#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZ_SYSDR_ROLE_UNKNOWN    "unknown"
#define SZ_SYSDR_ROLE_MAINSITE   "main_site"
#define SZ_SYSDR_ROLE_DRSITE     "recovery_site"
#define SZ_SYSDR_ROLE_STANDALONE "standalone"
#define SZ_SYSDR_ROLE_TEST       "test"

typedef enum {
	SYSDR_ROLE_UNKNOWN = 0,
	SYSDR_ROLE_MAINSITE,
	SYSDR_ROLE_DRSITE,
	SYSDR_ROLE_STANDALONE,
	SYSDR_ROLE_TEST
} SYSDR_ROLE;

BOOL SYNOSysDRSetRestore();
BOOL SYNOSysDRIsRestore();
BOOL SYNOSysDRClearRestore();

SYSDR_ROLE SYNOSystemDRGetLocalRole();
const char *SYNOSystemDRGetLocalRoleStr();

int SYNOSystemDRGetSerialNumber(BOOL isCustom, char *szSerial, unsigned cbSerial);
int SYNOSystemDRGetMac(unsigned int idx, char *szMac, unsigned int cbMac);

int SYNOSystemDRUpdateRemoteDSM(int version);
int SYNOSystemDRUpdateRemoteCU();
int SYNOSystemDRUpdateRemoteStart();

BOOL SYNOSystemDRCanAutoUpdate();

__END_DECLS;

#endif //__SYNOSYSDRCORE_EXT_H__
