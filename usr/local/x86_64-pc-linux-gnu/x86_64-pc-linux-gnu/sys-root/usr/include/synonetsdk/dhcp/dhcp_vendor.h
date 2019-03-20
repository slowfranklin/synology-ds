/* Copyright (c) 2000-2020 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DHCP_VENDOR_H_
#define _SYNO_NETSDK_DHCP_VENDOR_H_

#define SZF_DHCPD_VENDOR_CONF SZF_DHCPD_LNX"-vendor.conf"

#define SZ_DHCPD_VENDOR_OPT_PREFIX "dhcp-option=vendor:"
#define SZ_DHCPD_VENDOR_OPT_FORMAT "dhcp-option=vendor:%s,%s,%s"

#define SZK_DHCPD_VENDOR_LIST "vendorList"
#define SZK_DHCPD_VENDOR_NAME "vendorName"
#define SZK_DHCPD_VENDOR_OPTIONS "options"
#define SZK_DHCPD_VENDOR_OPTION_NUMBER "optNum"
#define SZK_DHCPD_VENDOR_OPTION_VALUE "optValue"

int DHCPVendorGetVendor(const char *szVendor, PSLIBSZHASH *ppVendorHash);
int DHCPVendorGetVendorOpt(const char *szVendor, int optNum, char *szValue, int valSize);
int DHCPVendorSetVendor(const char *szVendor, const PSLIBSZHASH pVendorHash);
int DHCPVendorSetVendorOpt(const char *szVendor, int optNum, const char *szValue);
int DHCPVendorEnum(PSLIBSZLIST *ppVendorList);
BOOL DHCPVendorCheckOptNum(const char *szOptNum);

#endif // _SYNO_NETSDK_DHCP_VENDOR_H_
