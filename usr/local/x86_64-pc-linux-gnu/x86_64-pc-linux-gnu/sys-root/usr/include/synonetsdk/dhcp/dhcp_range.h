#ifndef _SYNO_NETSDK_DHCP_RANGE_H_
#define _SYNO_NETSDK_DHCP_RANGE_H_

#define SZF_DHCPD_RANGE_CONFIG SZF_DHCPD_LNX"-range.conf"

int DHCPRangeConfSetRange(const char *szIfName, const char *szStartIP, const char *szEndIP, BOOL isAppend);
int DHCPRangeConfSetRanges(const char *szIfName, const PSLIBSZLIST pRangeList, BOOL isAppend);
int DHCPRangeCheckConflict(const char *szStartIP, const char *szEndIP);

#endif // _SYNO_NETSDK_DHCP_RANGE_H_
