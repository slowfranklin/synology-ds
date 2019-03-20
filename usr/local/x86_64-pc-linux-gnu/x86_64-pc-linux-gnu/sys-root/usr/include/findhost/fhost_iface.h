// Copyright (c) 2000-2009 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_INTERFACE_H
#define SYNO_FHOST_INTERFACE_H

#include <time.h>
#include <sys/types.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define FHOST_IFACE_MAX 8
#define FHOST_IFNAME_MAX 64
#define FHOST_HWADDR_MAX 6

struct FHOSTNETIF {
	/**
	 * The device name, ie, eth0, ...
	 */
	char        szName[FHOST_IFNAME_MAX];

	/**
	 * The mac address of this device.
	 */
	unsigned char rgbMac[FHOST_HWADDR_MAX];

	/**
	 * The IP address in network endian.
	 */
	u_int32_t   ulIP;

	/**
	 * The subnet mask in network endian.
	 */
	u_int32_t   ulMask;

	/**
	 * The broad cast in network endian.
	 */
	u_int32_t   ulBroadCast;

	/**
	 * The IP address of gateway in network endian.
	 */
	u_int32_t   ulGateway;

	/**
	 * The IP address of DNS server in network endian.
	 */
	u_int32_t   ulDNS;

	/**
	 * The IP is manual configured or DHCP. 0: DHCP.
	 */
	int         blManual;

	/**
	 * The device is active or not. 1: Active.
	 */
	int         blActive;
};
#ifdef  __cplusplus
}
#endif
#endif				// SYNO_FHOST_INTERFACE_H
