#ifndef __SYNO_HWCTL_HIBERNATION_H_
#define __SYNO_HWCTL_HIBERNATION_H_

#include <synocore/synotype.h>
__BEGIN_DECLS;

enum {
	DELAY_MSG_SRC_UNKNOW,
	DELAY_MSG_SRC_SCEMD_CONNECTOR,
	DELAY_MSG_SRC_FINDHOSTD,
	DELAY_MSG_SRC_SAMBA
};

typedef struct _tag_DEEP_SLEEP_DELAY_MSG {
	int msgSource;
	int seconds;
} DEEP_SLEEP_DELAY_MSG, *PDEEP_SLEEP_DELAY_MSG;

#define FINDHOSTD_DELAY_SECONDS 60
#define SAMBA_DELAY_SECONDS 60
#define SZ_PROC_IGNORE_NETBIOS_PATH "/proc/sys/kernel/syno_ignore_netbios_broadcast"
#define SZV_IGNORE_NETBIOS 1
#define SZV_NOT_IGNORE_NETBIOS 0
#define SZK_IGNORE_NETBIOS_BROADCAST "ignoreNetBIOSBroadcast"
#define SZK_IGNORE_DEFAULT_GATEWAY_ARP "ignoreDefaultGatewayARP"
#define SZF_SCEMD_KEY_CACHE "/tmp/scemd_key_cache"

int SYNODeepSleepDelayMsg(int msgSource, int seconds);
int SYNOSysDeepSleepIgnoreNetbios(int isIgnore);

__END_DECLS;

#endif /* __SYNO_HWCTL_DISK_H_ */
