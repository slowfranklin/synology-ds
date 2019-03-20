#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_LIBUTIL_H
#define __SYNOHACORE_LIBUTIL_H

#ifdef MY_ABC_HERE

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <synocore/synoglobal.h>

#define HA_NET_IF_IS_BOND(type) (HA_NET_IF_BOND == type || HA_NET_IF_OVSBOND == type)

typedef struct _tag_HA_NETIF {
	char szName[SYNO_IFNAME_MAX];  /* interface name fec0, fxp1 */
	char szDes[64];   /* IP address */
	_tag_HA_NETIF(const char* szIf, const char* szIp) {
		memset(szName, 0, sizeof(szName));
		memset(szDes, 0, sizeof(szDes));
		snprintf(szName, sizeof(szName), "%s", szIf);
		snprintf(szDes, sizeof(szDes), "%s", szIp);
	}
} HANETIF, *PHANETIF;

typedef enum {
	HA_NET_IF_ETH,
	HA_NET_IF_BOND,
	HA_NET_IF_OVSETH,
	HA_NET_IF_OVSBOND,
	HA_NET_IF_UNKNOW
} HA_NET_IF_TYPE;

typedef struct {
	HA_NET_IF_TYPE type;
	unsigned int idx;
} HA_IF_NAME_INFO;

std::string FormattedString(const char* fmt, ...) __attribute__ ((format(printf,1,2)));
std::string GetLocalHostname();
int GetLocalHostname(char*);
HA_NET_IF_TYPE HAGetInterfaceType(const char *szIf);
int HAGetInterfaceTypeAndIndex(const char *szIf, HA_IF_NAME_INFO &IF);
int HASnprintf(char *str, size_t size, const char *format, ...) __attribute__ ((format(printf,3,4)));

/**
 * Transform any type to std::string
 */
template<typename T>
inline std::string ToString(const T& value)
{
	std::ostringstream oss;
	oss << std::boolalpha << value << std::noboolalpha;
	return oss.str();
}

int HAEnvPathInit(void);
int FileRemoveFirstLine(const char *szFile, char *szLine, unsigned int cbLine);

int HAProcNameGetByPid(const pid_t pid, char *szName, size_t cbName);

#endif /* MY_ABC_HERE */

#endif
