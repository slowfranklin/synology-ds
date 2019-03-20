// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_WIRELESS_H_
#define __SYNO_HWCTL_WIRELESS_H_

#include <syslog.h>

__BEGIN_DECLS;

#define SZ_SYSFS_IEEE80211 "/sys/class/ieee80211"
#define SZ_SYSFS_NET "/sys/class/net"
#define SZ_SYSFS_PHY80211 "/phy80211"
#define SZ_SYSFS_RFKILL_PREFIX "rfkill"
#define SZ_SYSFS_RFKILL_STATE "/state"

int SYNOWirelessSetRFBlock(const char *szIfName, int unblock);

__END_DECLS;
#endif /* __SYNO_HWCTL_WIRELESS_H_ */
