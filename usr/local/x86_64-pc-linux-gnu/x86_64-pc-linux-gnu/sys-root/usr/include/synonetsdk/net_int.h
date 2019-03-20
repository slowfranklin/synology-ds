#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#include <synonetsdk/net.h>

typedef unsigned long long u64;         /* hack, so we may include kernel's ethtool.h */
typedef __uint32_t u32;         /* ditto */
typedef __uint16_t u16;         /* ditto */
typedef __uint8_t u8;   

#if !defined(MY_DEF_HERE)
typedef __uint32_t __u32;         /* ditto */
typedef unsigned long long __u64;
typedef __uint16_t __u16;         /* ditto */
typedef __uint8_t __u8;           /* ditto */
#endif

//#define DEBUG

#ifdef DEBUG
#define DEBUGLOG(a...) syslog(LOG_ERR, a)
#define ASSERT(cond) \
	if (!(cond)) { \
		syslog(LOG_ERR, "%s ASSERT(%s)", __FUNCTION__, #cond); \
		_exit(1); \
	}
#else
#define DEBUGLOG(a...)
#define ASSERT(cond)
#endif /* DEBUG */

#ifndef ASSERT
#define ASSERT(cond) \
	if (!(cond)) { \
		syslog(LOG_ERR, "%s(%d) assert %s", __FILE__, __LINE__, #cond); \
		_exit(1); \
	}
#endif	

#ifndef min
#define min(a,b) (( (a) > (b) ) ? (b):(a))
#endif

#define SZF_SYSFS_NET	"/sys/class/net/"
#define SZF_SYSFS_BOND_MASTER SZF_SYSFS_NET"bonding_masters"
#define SZF_SYSFS_BOND_MODE SZF_SYSFS_NET"%s/bonding/mode"
#define SZF_SYSFS_BOND_SLAVES SZF_SYSFS_NET"%s/bonding/slaves"

#define _BOND_MODE_DESC(STR, INT) STR" "INT
#define SZV_BOND_MODE_DESC_ALB _BOND_MODE_DESC(SZV_BOND_MODE_ALB_STR, SZV_BOND_MODE_ALB_INT)
#define LEN_BOND_MODE_DESC_ALB (sizeof(SZV_BOND_MODE_DESC_ALB)-1)
#define SZV_BOND_MODE_DESC_8023AD _BOND_MODE_DESC(SZV_BOND_MODE_8023AD_STR, SZV_BOND_MODE_8023AD_INT)
#define LEN_BOND_MODE_DESC_8023AD (sizeof(SZV_BOND_MODE_DESC_8023AD)-1)
#define SZV_BOND_MODE_DESC_XOR _BOND_MODE_DESC(SZV_BOND_MODE_XOR_STR, SZV_BOND_MODE_XOR_INT)
#define LEN_BOND_MODE_DESC_XOR (sizeof(SZV_BOND_MODE_DESC_XOR)-1)
#define SZV_BOND_MODE_DESC_FAILOVER _BOND_MODE_DESC(SZV_BOND_MODE_FAILOVER_STR, SZV_BOND_MODE_FAILOVER_INT)
#define LEN_BOND_MODE_DESC_FAILOVER (sizeof(SZV_BOND_MODE_DESC_FAILOVER)-1)
#define SZV_BOND_MODE_DESC_RR _BOND_MODE_DESC(SZV_BOND_MODE_RR_STR, SZV_BOND_MODE_RR_INT)
#define LEN_BOND_MODE_DESC_RR (sizeof(SZV_BOND_MODE_DESC_RR)-1)

#if defined(MY_DEF_HERE) || defined(MY_ABC_HERE)
#define SZV_BONDOPT_GENERIC " use_carrier=1 miimon=100 updelay=100"
#else
#define SZV_BONDOPT_GENERIC " use_carrier=0 miimon=100 updelay=100"
#endif

#define SZV_BONDOPT_ALB "\"mode="SZV_BOND_MODE_ALB_INT SZV_BONDOPT_GENERIC "\""
#define SZV_BONDOPT_8023AD "\"mode="SZV_BOND_MODE_8023AD_INT SZV_BONDOPT_GENERIC " lacp_rate=fast\""
#define SZV_BONDOPT_XOR "\"mode="SZV_BOND_MODE_XOR_INT SZV_BONDOPT_GENERIC "\""
#define SZV_BONDOPT_FAILOVER "\"mode="SZV_BOND_MODE_FAILOVER_INT SZV_BONDOPT_GENERIC "\""
#define SZV_BONDOPT_RR "\"mode="SZV_BOND_MODE_RR_INT SZV_BONDOPT_GENERIC "\""

#define SZK_DHCPD_RANGE				"dhcp-range"
#define SZK_DHCPD_INTERFACE			"interface"
#define SZK_DHCPD_OPT				"dhcp-option"
#define SZK_DHCPD_SET_TAG			"set:"
#define SZK_DHCPD_USE_TAG			"tag:"
#define SZK_DHCPD_OPT_DNS			"option:dns-server"
#define SZK_DHCPD_OPT_ROUTER		"option:router"
#define SZK_DHCPD_OPT_DOMAIN		"option:domain-search"
#define SZK_DHCPD_FILE_FORMAT		"%s-%s-%s"

#define SZK_DHCPD_LEASE_FILE		"dhcp-leasefile"

#ifndef AI_ADDRCONFIG
# define AI_ADDRCONFIG  0x0020 /* Use configuration of this host to choose returned address type. */
#endif
#ifndef AI_NUMERICSERV
# define AI_NUMERICSERV 0x0400 /* Don't use name resolution. */
#endif

#define SZF_PROC_NETDEV			"/proc/net/dev"
#define SZF_PROC_VLAN_CONFIG	"/proc/net/vlan/config"
#define MIN_VLAN_ID 1
#define MAX_VLAN_ID 4094

/* for net module plugins */
#define SZD_NET_IFCHG_PLUGIN 			"net/ifname_change"
#define SZD_NET_IF_LINK_UP_PLUGIN  		"net/if_link_up"
#define SZD_NET_IF_LINK_DOWN_PLUGIN		"net/if_link_down"
/* end for net module plugins */

#define SZF_DHCLIENT6_DEFAULT_CONF		"/etc/dhclient/ipv6/dhclient.conf"

/**
 * Zero the structure @a pNetInfo. If @a pIF is not NULL, copy link up/down,
 * mac addr information to @a pNetInfo.
 *
 * @param pNetInfo    [OUT] can not be NULL
 * @param pIFStatus   [IN]
 *
 * @return <ul>
 *         <li>0: on success
 *         <li>-1: on error
 *         </ul>
 * @ingroup NET_int
 */
static inline int SYNONetInitNetInfo(PNETINFO pNetInfo, const PSLIBNETIF pIFStatus)
{
	SYNOSDK_CHECK_ARGS(1, -1, NULL != pNetInfo);
	
	bzero(pNetInfo, sizeof(NETINFO));

	if (pIFStatus) {
		snprintf(pNetInfo->szInterface, sizeof(pNetInfo->szInterface), "%s", pIFStatus->szName);
		memcpy(pNetInfo->rgbMac, pIFStatus->rgbMac, 6);
		pNetInfo->blActive = (pIFStatus->status & IFM_ACTIVE) ? TRUE : FALSE;
	}

	return 0;
}
