/* Copyright (c) 2000-2020 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DHCP_UTILS_H_
#define _SYNO_NETSDK_DHCP_UTILS_H_

#include <synonetsdk/dhcp/dhcp_define.h>

BOOL DHCPIsEnabled();

int DHCPServerRestart();
int DHCPServerStart();

int DHCPInterfaceIsEnabled(const char *szInterface, DHCPD_IPTYPE ipType);
int DHCPInterfaceSetEnabled(const char *szInterface, DHCPD_IPTYPE ipType, BOOL blEnable);

#endif     // _SYNO_NETSDK_DHCP_UTILS_H_
