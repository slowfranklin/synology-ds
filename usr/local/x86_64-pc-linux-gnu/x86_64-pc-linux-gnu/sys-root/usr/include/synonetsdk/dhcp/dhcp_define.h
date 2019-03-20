/* Copyright (c) 2000-2020 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DHCP_DEFINE_H_
#define _SYNO_NETSDK_DHCP_DEFINE_H_

#define SZK_MAC						"mac"
#define SZK_CLID					"clid"
#define SZK_IP						"ip"
#define SZK_DHCPD_HOSTNAME				"hostname"
#define SZK_DHCPD_EXPIRE					"expire"
#define SZK_DHCPD_LEASE_IPV4				"ipv4"
#define SZK_DHCPD_LEASE_IPV6				"ipv6"

#define CB_SZ_MAC_MAX 20
#define CB_SZ_CLID_MAX BUFSIZ

#define SZK_DHCPD_INFO_ENABLE			"enable"
#define SZK_DHCPD_KEY_FORMAT			"%s=\"%s\"\n"
#define SZ_INFO_FORMAT					"%s=\"%s\"\n"
#define SZV_YES							"yes"
#define SZV_NO							"no"

#define DEFAULT_LEASETIME			3600
#define DEFAULT_LEASETIME_STATIC	86400

#define SZK_DHCPD_IFNAME					"ifname"
#define SZK_DHCPD_ENABLE					"enable"
#define SZK_DHCPD_ENABLE_V6				"enable_v6"
#define SZK_DHCPD_STARTIP					"startip"
#define SZK_DHCPD_ENDIP					"endip"
#define SZK_DHCPD_GATEWAY					"gateway"
#define SZK_DHCPD_NETMASK					"netmask"
#define SZK_DESC					"desc"
#define SZK_DHCPD_BOOTLOADER				"bootloader"
#define SZK_DHCPD_DNS						"dns"

#define FIRST_TAG_NUM 0

#define SZK_DHCPD_USE_TAG			"tag:"

// #define SZK_DHCPD_FILE_FORMAT				"%s-%s-%s"
// replace with SZK_DHCPD_IF_SUBNET_INFO/CONF_FORMAT
// #define SZK_DHCPD_OBSOLETE_FILE_FORMAT				"%s-%s-%s"
#define SZK_DHCPD_IF_GLOBAL_INFO_FORMAT			SZF_DHCPD_LNX"-%s.info"
#define SZK_DHCPD_IF_SUBNET_INFO_FORMAT			SZF_DHCPD_LNX"-%s-subnet%u.info"
#define SZK_DHCPD_IF_SUBNET_CONF_FORMAT			SZF_DHCPD_LNX"-%s-subnet%u.conf"
#define SZK_DHCPD6_IF_GLOBAL_INFO_FORMAT			SZF_DHCPD6_LNX"-%s.info"
#define SZK_DHCPD6_IF_SUBNET_INFO_FORMAT			SZF_DHCPD6_LNX"-%s-subnet%u.info"
#define SZK_DHCPD6_IF_SUBNET_CONF_FORMAT			SZF_DHCPD6_LNX"-%s-subnet%u.conf"

typedef enum DHCPD_IPTYPE {
	DHCPD_IPTYPE_V4,
	DHCPD_IPTYPE_V6
} DHCPD_IPTYPE;

#define SZK_PXE								"pxe"
#define SZK_DHCPD_PXE_TAG					"pxe"

#endif // _SYNO_NETSDK_DHCP_DEFINE_H_
