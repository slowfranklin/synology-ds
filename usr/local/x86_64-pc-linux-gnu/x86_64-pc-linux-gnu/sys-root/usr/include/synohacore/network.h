#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_NETWORK_H
#define __SYNOHACORE_NETWORK_H

#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <synocore/synoglobal.h>

typedef struct {
	char szIF[SYNO_IFNAME_MAX];
	char szIP[CB_SZ_IP_MAX];
	char szMask[CB_SZ_IP_MAX];
	BOOL isEnable;
} HA_NETINFO;

__BEGIN_DECLS

/**
 * Gets HA netinfo
 *
 * Caller needs to free @p pHANetinfo after using.
 *
 * @param [out] pHANetinfo pointer to array of HA_NETINFO
 * @param [in]  nMax       max count of pHANetinfo
 * @retval >=0 number of enabled HA netinfo
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetHANetinfo(HA_NETINFO *pHANetinfo, int nMax);

/**
 * Get the interface of HA heartbeat channel
 *
 * @param [out] szHeartbeatIF heartbeat interface
 * @param [in]  cbHeartbeatIF size of @p szHeartbeatIF
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetHeartbeatIF(char *szHeartbeatIF, int cbHeartbeatIF);

/**
 * Get HA IP address & netmask related to @p szDevice
 *
 * @param [in]  szDevice  The device name to get IP Address. Ex: eth0, eth1, or NULL for main HA interface
 * @param [out] szIpAddr  The string buffer to be set IP Address. Should not be NULL.
 * @param [in]  cbIpAddr  The length of string buffer @a szIpAddr. Should be a positive.
 * @param [out] szNetmask The string buffer to be set Netmask. Should not be NULL.
 * @param [in]  cbNetmask The length of string buffer @a szNetmask. Should be a positive.
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetRelatedIFInfo(const char *szDevice, char *szIpAddr, int cbIpAddr, char *szNetmask, int cbNetmask);

/*
 * Check if HA IP conflict with active's or passive's original IP
 *
 * @param [in]  szIP The IP input by user. Should not be NULL.
 * @retval true IP conflicts with active's or passive's original IP
 * @retval false IP conflicts none
 * @grantable N
 * @apparmor abstractions/libsynohacore
*/
BOOL SYNOHAIsHAIPConflict(const char *szIP);

__END_DECLS

#ifdef MY_ABC_HERE

int HASYNOLnxGetHostname(char *szHostname);

#endif /* MY_ABC_HERE */

#endif
