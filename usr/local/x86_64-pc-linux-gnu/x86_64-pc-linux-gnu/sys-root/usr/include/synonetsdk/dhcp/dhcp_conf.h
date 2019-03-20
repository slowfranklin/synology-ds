/* Copyright (c) 2000-2020 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DHCP_CONF_H_
#define _SYNO_NETSDK_DHCP_CONF_H_

#include <synonetsdk/net.h>
#include <synonetsdk/dhcp/dhcp_define.h>

#define PDNS_INDEX 3
#define SDNS_INDEX 4
#define DOMAIN_NAME_SIZE 255

#define SZK_DHCPD_RANGE				"dhcp-range"
#define SZK_DHCPD_INTERFACE			"interface"
#define SZK_DHCPD_OPT				"dhcp-option"
#define SZK_DHCPD_OPT_DNS			"option:dns-server"
#define SZK_DHCPD_OPT_ROUTER		"option:router"
#define SZK_DHCPD_OPT_DOMAIN		"option:domain-search"
#define SZK_DHCPD_OPT_DOMAIN_NAME	"option:domain-name"
#define SZK_DHCPD_SET_TAG			"set:"

#define SZK_DHCPD_OPTIONS			"options"
#define SZK_DHCPD_OPT_NUMBER		"optNum"
#define SZK_DHCPD_OPT_NAME			"optName"
#define SZK_DHCPD_OPT_VALUE			"optValue"

#define SZ_RANGE_FORMAT			SZK_DHCPD_RANGE"="SZK_DHCPD_SET_TAG"%s,%s,%s,%s,%d\n"
#define SZ_CONF_FORMAT			"%s=%s\n"
#define SZ_OPT_FORMAT				SZK_DHCPD_OPT"="SZK_DHCPD_USE_TAG"%s,%s,%s\n"
#define SZ_DHCPD_OPT_FORMAT				SZK_DHCPD_OPT"="SZK_DHCPD_USE_TAG"%s,option:%s,%s\n"
#define SZ_OPT_SDNS_FORMAT			SZK_DHCPD_OPT"="SZK_DHCPD_USE_TAG"%s,%s,%s,%s\n"

#define SZ_DHCPD_OPT_PREFIX_FORMAT	SZK_DHCPD_OPT"=tag:%s,option:"
#define SZ_DHCPD_OPTION_COLON	"option:"

#define DHCPV6_RANGE_TOKEN_NUM_RA		6
#define DHCPV6_RANGE_TOKEN_NUM_STATEFUL	5

#define SZV_DHCPV6_OFF              "off"
#define SZV_DHCPV6_RAONLY           "ra-only"
#define SZV_DHCPV6_RASTATELESS      "ra-stateless"
#define SZV_DHCPV6_STATEFUL         "stateful"

#define SZK_DHCPV6_TYPE					"dhcpv6_type"
#define SZK_DHCPV6_RANGE_BEGIN			"dhcpv6_range_begin"
#define SZK_DHCPV6_RANGE_END			"dhcpv6_range_end"

#define SZK_DHCPD_OPT6_DNS              "option6:dns-server"
#define SZV_DHCPD_ENABLE_RA             "enable-ra\n"
#define SZ_RANGE6_RA_FORMAT             SZK_DHCPD_RANGE"="SZK_DHCPD_SET_TAG"%s,::,constructor:%s,%s,64,%d\n"

void DHCPOptionFree(PSYNO_DHCPD_OPTION pOptions);

int DHCPTagConfGet(const char *szIfName, unsigned int tagNum, DHCPD_IPTYPE ipType, PSYNO_DHCPD_CONF pDhcpServerConf);
int DHCPTagConfGetEnable(const char *szIfname, unsigned int tagNum, DHCPD_IPTYPE ipType, BOOL *pBlIsEnabled);

int DHCPTagConfSet(const char *szIfName, unsigned int tagNum, DHCPD_IPTYPE ipType, const PSYNO_DHCPD_CONF pConf);
int DHCPTagConfSetEnable(const char *szInterface, unsigned int tagNum, DHCPD_IPTYPE ipType, BOOL blEnable);
int DHCPTagConfSetConfig(const char *szIfName, unsigned int tagNum, DHCPD_IPTYPE ipType, const PSYNO_DHCPD_CONF pConf);

int DHCPDLinkAggrSet(int isCreate, const char *szBondIfName, const PSLIBSZLIST szSlaveList);

BOOL DHCPOptionIsListValue(int optNum);

#endif // _SYNO_NETSDK_DHCP_CONF_H_
