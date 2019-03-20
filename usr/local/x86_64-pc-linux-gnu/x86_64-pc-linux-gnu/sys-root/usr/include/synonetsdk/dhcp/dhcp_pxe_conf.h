/* Copyright (c) 2000-2020 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DHCP_PXE_CONF_H_
#define _SYNO_NETSDK_DHCP_PXE_CONF_H_

#include "dhcp_utils.h"
#include <synonetsdk/net.h>

#define SZF_DHCPD_PXE_VENDOR_OPT			"dhcp-vendorclass=set:pxe,PXEClient"

#define SZK_DHCPD_OPT_BOOT		"dhcp-boot"
#define SZK_DHCPD_PXE_IS_REMOTE_TFTP		"is_remote_tftp"
#define SZK_DHCPD_PXE_REMOTE_TFTP_SERVER_IP	"remote_tftp_server_ip"
#define SZK_DHCPD_PXE_REMOTE_BOOTLOADER		"remote_bootloader"
#define SZK_DHCPD_PXE_LOCAL_BOOTLOADER		"local_bootloader"

#define SZ_BOOT_FORMAT_WITHOUT_SERVER		SZK_DHCPD_OPT_BOOT"="SZK_DHCPD_USE_TAG"%s,%s\n"
#define SZ_BOOT_FORMAT_WITH_SERVER		SZK_DHCPD_OPT_BOOT"="SZK_DHCPD_USE_TAG"%s,%s,bootserver,%s\n"

#define SZK_DHCPD_IF_PXE_CONF_FORMAT	SZF_DHCPD_LNX"-%s-pxe.conf"
#define SZK_DHCPD_IF_PXE_INFO_FORMAT	SZF_DHCPD_LNX"-%s-pxe.info"
#define SZK_DHCPD_PXE_CONF_FORMAT	SZF_DHCPD_LNX"-pxe.conf"
#define SZK_DHCPD_PXE_INFO_FORMAT	SZF_DHCPD_LNX"-pxe.info"
#define SZK_DHCPD_PXE_SETTING	SZF_DHCPD_LNX"-pxe-setting"

#define DHCPD_DHCP_BOOT_OPT_LEN_WITHOUT_SERVER 2
#define DHCPD_DHCP_BOOT_OPT_LEN_WITH_SERVER 4
/*
typedef struct _tag_SYNO_DHCPD_PXE_CONF {
	SYNO_DHCPD_CONF dhcpConf;
	char szBootLoader[PATH_MAX];
} SYNO_DHCPD_PXE_CONF, *PSYNO_DHCPD_PXE_CONF;
*/
typedef struct _tag_SYNO_DHCPD_PXE_CONF {
	BOOL blEnable;
	BOOL blIsRemoteTFTP;
	char szLocalBootLoader[PATH_MAX];
	char szRemoteBootLoader[PATH_MAX];
	char szRemoteTFTPServerIP[CB_SZ_IP_MAX];
} SYNO_DHCPD_PXE_CONF, *PSYNO_DHCPD_PXE_CONF;

int DHCPPXEConfGet(PSYNO_DHCPD_PXE_CONF pPxeConf);
int DHCPPXEConfGetEnable(BOOL *pBlIsEnabled);
int DHCPPXEConfSet(const PSYNO_DHCPD_PXE_CONF pPxeConf);
int DHCPPXEConfSetEnable(BOOL blEnable);

#endif // _SYNO_NETSDK_DHCP_PXE_CONF_H_
