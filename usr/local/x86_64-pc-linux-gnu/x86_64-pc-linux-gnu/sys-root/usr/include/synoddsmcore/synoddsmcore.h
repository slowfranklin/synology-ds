// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

#ifndef __SYNO_DDSM_CORE_H__
#define __SYNO_DDSM_CORE_H__

#include <synocore/synoglobal.h>
#include <synocore/conf.h>

#define SZD_SYNO_ETC_DDSM "/usr/syno/etc/synoddsm/"
#define SZF_DDSM_SERIAL SZD_SYNO_ETC_DDSM "serial"
#define SZF_DDSM_MAC SZD_SYNO_ETC_DDSM "mac_address"

__BEGIN_DECLS;

BOOL SYNOIsDockerDSM(void);
BOOL SYNODDSMIsPrivilegedMode(void);
int SYNODDSMGetSerialNumber(char *szSerial, int cbSize);
int SYNODDSMSetHostname(const char *szHostname);
int SYNODDSMGetUptime(int *uptime);

__END_DECLS;

#endif
