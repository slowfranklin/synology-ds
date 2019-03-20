// Copyright (c) 2000-2011 Synology Inc. All rights reserved.
#ifndef __SYNO_NETSDKIF_H_
#define __SYNO_NETSDKIF_H_

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/hash.h>
#include <synocore/list.h>
#include <synosdk/plugin.h>

__BEGIN_DECLS;

/**
 * DSM#40982 - inet_ntoa() is buggy with dlopen() before glibc-2.4
 */
#if !__GLIBC_PREREQ(2, 5)
#undef inet_ntoa
#define inet_ntoa SYNONetNtoa
#endif

/** 
 * @addtogroup NET The structure and operation of NET. 
 * @{  */

/*
flag avaliable and bits 

IFF_UP		0x1		 interface is up 
IFF_BROADCAST	0x2		broadcast address valid 
IFF_DEBUG	0x4		 turn on debugging 
IFF_LOOPBACK	0x8		is a loopback net 
IFF_POINTOPOINT	0x10	    interface is point-to-point link 
IFF_SMART	0x20		 interface manages own routes 
IFF_RUNNING	0x40		 resources allocated 
IFF_NOARP	0x80		 no address resolution protocol 
IFF_PROMISC	0x100		receive all packets 
IFF_ALLMULTI	0x200		 receive all multicast packets 
IFF_OACTIVE	0x400		 transmission in progress 
IFF_SIMPLEX	0x800		 can't hear own transmissions 
IFF_LINK0	0x1000		 per link layer defined bit 
IFF_LINK1	0x2000		 per link layer defined bit 
IFF_LINK2	0x4000		 per link layer defined bit 
IFF_ALTPHYS	IFF_LINK2	 use alternate physical connection 
IFF_MULTICAST	0x8000		 supports multicast 
*/

#define MAX_LENGTH_IP   16
#define SZF_RUN_DDNS                    "/run/ddns"
#define SZF_EXTERNAL_IP_RESULT                  SZF_RUN_DDNS "/externalIP.result"
#define SZK_EXTERNAL_IP                                 "externalIP"

#define CB_SZ_DHCPD_TAG_MAX 20
#define CB_SZ_DHCPD_OPT_NAME_MAX 50

#define NET_DISABLE     0
#define NET_ENABLE      1

#define SZF_PPPOE_TMP_FILE				"/tmp/synopppoe.intf"

#define IFM_ACTIVE                              0x00000002 // Jeng Wu
#define NUM_MAXIFACES                           32
#define SZ_DEFAULT_IF                           "eth0"
#define SZ_DEFAULT_GUEST_NET_IF         "gwlan"
#define SZ_DOCKER_IF_PREFIX                     "docker"
#define SZ_DDSM_IF_PREFIX                       "ddsm"
#define SZ_TAP_IF_PREFIX                        "tap"
#define SZ_DEFAULT_GUEST_NET_BRIDGE_IF          "gbr"
#define SZF_DHCPCLIENT_V4                       "/etc/dhclient/ipv4/dhcpcd-"
#define SZD_NETWORK_SCRIPTS_LNX                 "/etc/sysconfig/network-scripts"
#define SZD_IFCFG_PREFIX                "ifcfg-"
#define SZF_IFCFG_LNX                           SZD_NETWORK_SCRIPTS_LNX "/" SZD_IFCFG_PREFIX
#define SZ_KEY_VAL_SEPARATOR            "="
#define SZ_KEY_VAL_FORMAT                       "%s" SZ_KEY_VAL_SEPARATOR "%s\n"
#define SZ_8021Q_VLAN_MODULE "8021q"

#define NUM_SYNOINFO_DNS_MAX 30
#define NUM_SYNOINFO_DOMAIN_MAX 14
#define DHCP_TIMEOUT	30
#define DHCPCD_UP_SCRIPT				"/etc/iproute2/script/dhcpcd-up"
#define USBMODEM_START_NUM			100
#define SZ_IF_PPP				"ppp0"
#define SZ_IF_PPP_PREFIX			"ppp"
#define SZ_IF_WIRELESS				"wlan"
#define SZ_DEFAULT_WIRELESS_IF		SZ_IF_WIRELESS"0"
#define SZ_IF_AP					SZ_DEFAULT_WIRELESS_IF
#define SZ_DEFAULT_ROUTER_IF		"lbr0"
#define SZ_DEFAULT_BRIDGE_IF		"br0"
#define SZ_ETH_IF_PREFIX			"eth"
#define SZ_BOND_IF_PREFIX			"bond"
#define SZ_OVS_IF_PREFIX			"ovs_"
#define SZ_OVS_BOND_IF_PREFIX			"ovs_bond"
#define SZ_GUEST_IF_DHCP_SERVER 		SZ_DEFAULT_GUEST_NET_BRIDGE_IF
#define SZ_IF_DHCP_SERVER			SZ_DEFAULT_ROUTER_IF
#define SZ_ID_PPPOE				"pppoe"
#define SZF_HOSTS_LNX				"/etc/hosts"
#define SZF_DHCPCD_LNX				"/etc/dhcpc/dhcpcd-"
#define SZF_DHCLIENT_SCRIPT			"/tmp/dhclient-script"
#define SZF_DHCLIENT_LEASE_V4			"/tmp/dhcpv4.leases."
#define SZF_NETWORK_LNX				"/etc/sysconfig/network"
#define SZF_PPPOE_RELAY_LNX			"/etc/sysconfig/pppoe-relay/"
#define SZ_PPPOE_RELAY_BIN			"/usr/sbin/pppoe-relay"
#define SZD_DEF_NETWORK_SCRIPTS "/etc.defaults/sysconfig/network-scripts/"
#define SZD_IFCFG_ETH_PREFIX		SZD_IFCFG_PREFIX SZ_IF_PREFIX
#define SZD_IFCFG_BOND_PREFIX		SZD_IFCFG_PREFIX SZ_BOND
#define SZF_IFCFG_ETH0_LNX			SZF_IFCFG_LNX SZ_DEFAULT_IF
#define SZF_IFCFG_LBR0_LNX			SZF_IFCFG_LNX SZ_DEFAULT_ROUTER_IF
#define SZF_IFCFG_GBR_LNX           SZF_IFCFG_LNX SZ_DEFAULT_GUEST_NET_BRIDGE_IF
#define SZD_DHCPD					"/etc/dhcpd"
#define SZF_DHCPD_LNX				SZD_DHCPD"/dhcpd"
#define SZF_DHCPD6_LNX				SZD_DHCPD"/dhcpd6"
#define SZF_DHCPD_INFO_FILE		SZF_DHCPD_LNX".info"
#define SZF_DHCPD_GBR_LNX			SZF_DHCPD_LNX"-"SZ_GUEST_IF_DHCP_SERVER"-"SZ_GUEST_IF_DHCP_SERVER".conf"
#define SZF_DHCPD_GBR_LNX_INFO		SZF_DHCPD_LNX"-"SZ_GUEST_IF_DHCP_SERVER"-"SZ_GUEST_IF_DHCP_SERVER".info"
#define SZF_DHCPD_DNS_CONF          SZF_DHCPD_LNX"-dns-dns.conf"
#define SZF_DHCPD_DNS_INFO          SZF_DHCPD_LNX"-dns-dns.info"
#define SZF_DHCPD_STATIC_CONF		SZF_DHCPD_LNX"-static-static.conf"
#define SZF_DHCPD_STATIC_INFO		SZF_DHCPD_LNX"-static-static.info"
#define SZF_IPV6_LNX "/proc/net/if_inet6"
#define SZF_PING		"/bin/ping"
#define SZF_IP			"/sbin/ip"
#define SZF_IPCALC		"/bin/ipcalc"
#define SZF_SYNONET		"/usr/syno/sbin/synonet"
#define SZF_IFCONFIG		"/sbin/ifconfig"
#define SZF_SYNONETDTOOL	"/usr/syno/sbin/synonetdtool"
#define SZF_SYNO_OVS_BONDS "/sys/class/net/syno_ovs_bonds"

#define SZF_NETWORK_SCRIPT "/etc/rc.network"
#define LEN_NETWORK_SCRIPT_ACTION 16
#define SZV_NETWORK_SCRIPT_ACTION_START "start"
#define SZV_NETWORK_SCRIPT_ACTION_STOP "stop"
#define SZV_NETWORK_SCRIPT_RESTART_DHCPD "nat-restart-dhcp"
#define SZV_NETWORK_SCRIPT_START_DHCPD "nat-start-dhcp"

#define SZK_IFCFG_IPADDR            "IPADDR"
#define SZK_IFCFG_OLD_IPADDR        "OLD_IPADDR"
#define SZK_IFCFG_NETMASK           "NETMASK"
#define SZK_IFCFG_DEVICE            "DEVICE"
#define SZK_IFCFG_PRIMARY           "PRIMARY"
#define SZK_IFCFG_TYPE              "TYPE"
#define SZV_IFCFG_TYPE_BRIDGE       "bridge"
#define SZK_IFCFG_BRIDGE            "BRIDGE"
#define SZK_IFCFG_SLAVE		    "SLAVE"
#define SZK_IFCFG_LOCAL_LAN         "LOCAL_LAN"
#define SZK_IFCFG_ONBOOT			"ONBOOT"
#define SZK_IFCFG_IPTYPE			"BOOTPROTO"
#define SZK_IFCFG_GATEWAY			"GATEWAY"
#define SZK_IFCFG_DNS				"DNS"
#define SZK_IFCFG_BLOCK_CNT			"BLOCK_CNT"
#define SZK_IFCFG_BLOCK_HA			"BLOCK_HA"
#define SZK_IFCFG_BLOCK_AHA			"BLOCK_AHA"
#define SZK_IFCFG_BLOCK_VIRTUAL		"BLOCK_VIRTUAL"
#define SZK_IFCFG_BLOCK_MAILPLUS	"BLOCK_MAILPLUS"
#define SZV_IFCFG_IPTYPE_MANUAL		"static"
#define SZV_IFCFG_IPTYPE_SLAVE		"none"
#define SZV_IFCFG_IPTYPE_DHCP		"dhcp"
#define SZK_IFCFG_MASTER            "MASTER"
#define SZK_IFCFG_SLAVE_LIST        "SLAVE_LIST"
#define SZK_IFCFG_BONDING_OPTS      "BONDING_OPTS"
#define SZK_IFCFG_USERCTL		"USERCTL"
#define SZK_IFCFG_BOND_MODE			"BOND_MODE"
#define SZV_PPPOE_RELAY_SERVER		"server"
#define SZK_ENABLE					"enable"
#define SZV_BOND_MODE_ALB_STR       "balance-alb"
#define SZV_BOND_MODE_ALB_INT       "6"
#define SZV_BOND_MODE_8023AD_STR    "802.3ad"
#define SZV_BOND_MODE_8023AD_INT    "4"
#define SZV_BOND_MODE_XOR_STR       "balance-xor"
#define SZV_BOND_MODE_XOR_INT       "2"
#define SZV_BOND_MODE_FAILOVER_STR  "active-backup"
#define SZV_BOND_MODE_FAILOVER_INT  "1"
#define SZV_BOND_MODE_RR_STR        "balance-rr"
#define SZV_BOND_MODE_RR_INT        "0"
#define SZV_OVS_BOND_FAILOVER       "ovs-active-backup"
#define SZV_OVS_BOND_SLB            "balance-slb"
#define SZV_OVS_BOND_TCP            "balance-tcp"

/* For topology, used in synoinfo.conf */
#define SZK_SUPPORT_TOPOLOGY	"support_net_topology"
#define SZK_CURRENT_TOPOLOGY	"net_topology"

#define SZ_MODE_UNKNOWN  "unknown"
#define SZ_MODE_AP       "bridge"
#define SZ_MODE_STA      "client"
#define SZ_MODE_ROUTER   "router"

//For DNS
#define SZF_RESOLV_LNX		"/etc/resolv.conf"

/* for bug #14475 of DSM
 * SZF_DO_NOT_RESTART_SERVICES: 
 *   "lanman.cgi" will touch this file to tell "dhcpcd" or other process use 
 *   "servicetool" do not restart ip sensitive service. "lanman.cgi" will
 *   restart them later. */
#define SZF_DO_NOT_RESTART_SERVICES	"/tmp/do_not_restart_services"
/* SZF_RESTART_SERVICES_PID:
 *   "lanman.cgi" and "servicetool" use this pid file to notify each other.
 *   This file flag like a lock for service restart. "lanman.cgi" create this
 *   file before it call SYNOService to avoid other process (dhcpcd) call 
 *   SYNOService and lock synoinfo.conf. Because SYNOService will lock for a
 *   long period, any setting after dhcp can not get lock for synoinfo.conf. */
#define SZF_RESTART_SERVICES_PID	"/tmp/restart_services_pid"

#define SZF_PROCCONF_IPV6 "/proc/sys/net/ipv6/conf/"
#define SZF_DISABLE_IPV6 "/disable_ipv6"
#define SZF_IPV6_DHCP "/etc/wide-dhcpv6/dhcp6c.conf."
#define SZV_IPV6_DHCP_CLIENT_JOB	"dhcp-client6"
#define SZV_IPV6_DHCP_ACTION_PD		"pd"
#define SZV_IPV6_DHCP_ACTION_INFO	"info"
#define SZV_IPV6_DHCP_ACTION_CLIENT	"client"

#define SZF_ARP_IGNORE              "/proc/sys/net/ipv4/conf/all/arp_ignore"

#define NETWORKING_IPV6 "NETWORKING_IPV6"
#define IPV6ADDR "IPV6ADDR"
#define IPV6_DEFAULTGW "IPV6_DEFAULTGW"
#define IPV6DNS			"IPV6DNS"
#define IPV6INIT "IPV6INIT"
#define IPV6PREFIXLENG "IPV6PREFIXLENG"
#define IPV6_MAX_ADDRESSES 16
#define IPV6_ADDRESS_VALIDATION_TIMEOUT 5

//For DNS
#define SZF_RESOLV_LNX_STATIC		"/etc/resolv.conf.static"
#define SZF_RESOLV_LNX_OPTION		"/etc/resolv.conf.option"
#define SZK_DNS_MODE				"dns_mode"
#define SZV_DNS_MODE_AUTO			"auto"
#define SZV_DNS_MODE_STATIC			"static"

//For 5.1 DNS
#define SZD_IPROUTE2                "/etc/iproute2/"
#define SZD_IPROUTE2_SCRIPT         SZD_IPROUTE2"script/"
#define SZD_IPROUTE2_CONFIG         SZD_IPROUTE2"config/"
#define SZF_GATEWAY_V4_PRIORITY     SZD_IPROUTE2_CONFIG"gateway_v4_priority"
#define SZF_GATEWAY_V6_PRIORITY     SZD_IPROUTE2_CONFIG"gateway_v6_priority"
#define SZF_RESOLV_V4               SZD_IPROUTE2_CONFIG"resolv4.conf"
#define SZF_RESOLV_V6               SZD_IPROUTE2_CONFIG"resolv6.conf"
#define SZF_GATEWAY_DATABASE		SZD_IPROUTE2_CONFIG"gateway_database"

// dhcp client upstart job name
#define SZV_NET_DHCP_CLIENT_JOB		"dhcp-client"

//For pppoe default gateway backup
#define SZF_PPPOE_GW_BACKUP			"/tmp/pppoe_gw_backup"

//For IP change hook
#define SZD_NET_IPV4_CHANGE_PLUGIN      "net/ipv4_change"
#define SZD_NET_IPV6_CHANGE_PLUGIN      "net/ipv6_change"
#define SZK_HOOK_IFNAME                         "IFNAME"
#define SZK_HOOK_ORIGIN_ADDRESS         "ORIGIN_ADDRESS"
#define SZK_HOOK_NEW_ADDRESS            "NEW_ADDRESS"
#define SZK_HOOK_PREFIX_LENGTH          "PREFIX_LENGTH"
#define SZK_HOOK_IS_LINK                "IS_LINK"

//For mtu change hook
#define SZD_NET_MTU_CHANGE_PLUGIN	"net/mtu_change"
#define SZK_HOOK_MTU_DEVICE		"IFACE"
#define SZK_HOOK_MTU_VALUE		"MTU_VALUE"

//For hostname change hook
#define SZD_NET_HOSTNAME_CHANGE_PLUGIN	"net/hostname_change"
#define SZK_HOOK_HOSTNAME		"HOSTNAME"

//For dns change hook
#define SZD_NET_DNS_CHANGE_PLUGIN	"net/dns_change"
#define SZK_HOOK_DNS_NITEMS		"NITEMS"

//For dns config change hook
#define SZD_NET_DNS_CONFIG_CHANGE_PLUGIN	"net/dns_config_change"
#define SZK_HOOK_DNS_CONFIG_INTERFACE		"INTERFACE"

//For gateway config change hook
#define SZD_NET_GW_CONFIG_CHANGE_PLUGIN		"net/gateway_config_change"
#define SZK_HOOK_GW_CONFIG_TYPE				"TYPE"
#define SZK_HOOK_GW_CONFIG_INTERFACE		"INTERFACE"
#define SZK_HOOK_GW_CONFIG_GATEWAY_OLD		"GATEWAY_OLD"
#define SZK_HOOK_GW_CONFIG_GATEWAY_NEW		"GATEWAY_NEW"

/* Copy from ethtool.h */
/* Indicates what features are advertised by the interface. */
#define ADVERTISED_10baseT_Half     (1 << 0)
#define ADVERTISED_10baseT_Full     (1 << 1)
#define ADVERTISED_100baseT_Half    (1 << 2)
#define ADVERTISED_100baseT_Full    (1 << 3)
#define ADVERTISED_1000baseT_Half   (1 << 4)
#define ADVERTISED_1000baseT_Full   (1 << 5)
#define ADVERTISED_Autoneg      (1 << 6)
#define ADVERTISED_TP           (1 << 7)
#define ADVERTISED_AUI          (1 << 8)
#define ADVERTISED_MII          (1 << 9)
#define ADVERTISED_FIBRE        (1 << 10)
#define ADVERTISED_BNC          (1 << 11)
#define ADVERTISED_10000baseT_Full  (1 << 12)
#define ADVERTISED_Pause        (1 << 13)
#define ADVERTISED_Asym_Pause       (1 << 14)
#define ADVERTISED_2500baseX_Full   (1 << 15)
#define ADVERTISED_Backplane        (1 << 16)
#define ADVERTISED_1000baseKX_Full  (1 << 17)
#define ADVERTISED_10000baseKX4_Full    (1 << 18)
#define ADVERTISED_10000baseKR_Full (1 << 19)
#define ADVERTISED_10000baseR_FEC   (1 << 20)
#define ADVERTISED_20000baseMLD2_Full   (1 << 21)
#define ADVERTISED_20000baseKR2_Full    (1 << 22)
#define ADVERTISED_40000baseKR4_Full    (1 << 23)
#define ADVERTISED_40000baseCR4_Full    (1 << 24)
#define ADVERTISED_40000baseSR4_Full    (1 << 25)
#define ADVERTISED_40000baseLR4_Full    (1 << 26)

typedef struct _tag_LINKMODE_ {
	int speed;      /* The forced speed, 10Mb, 100Mb, gigabit */
	int duplex;     /* 0 : half or 1 : full */
	char medium[16];  /* String describes support mediums e.g. baseKX4 */
} LINKMODE;

typedef struct _tag_ETHINFO_ {
	int speed;		/* The forced speed, 10Mb, 100Mb, gigabit */
	int duplex;		/* 0 : half or 1 : full */
	int MTUValue;		/* MTU value, 1500, 4074 or 9000 */
	int supported;	/* Bitmap of supported link modes*/
	LINKMODE max_supported_mode;
} ETHINFO;

typedef struct _tag_SYNOIPLIST {
        char szIP[CB_SZ_IPv6]; /* ipv4 or ipv6 addr*/
        int addrType; /* AF_INET, or AF_INET6 */
} SYNOIPLIST, *PSYNOIPLIST;

typedef struct _tag_NETINFO_ {
        BOOL blManual;
        BOOL blActive;
        char szInterface[SYNO_IFNAME_MAX];
        unsigned char rgbMac[6];
        char szIp[CB_SZ_IP_MAX];
        char szMask[CB_SZ_IP_MAX];
} NETINFO, *PNETINFO;

typedef struct _tag_NETIPV6_ {
        char ipv6Addr[CB_SZ_IPv6];
        unsigned int prefixLeng;
        unsigned int addrType;
        unsigned short int flags;
} NETIPV6, *PNETIPV6;

typedef struct _tag_SLIB_NETIF {
        char szName[SYNO_IFNAME_MAX];  /* interface name fec0, fxp1 */
        /**
          * This mac address will change after switchover/failover on HA-like environment.
          * Call SLIBNetGetMacAddr or SLIBNetGetMacAddrByInterface for HA Mac.
          */
        u_char rgbMac[6]; /* mac address */
        char szDes[64];   /* IP address */
        int active;   /* IFM_100_TX, IFM_10_T, IFM_FDX */
        int status;   /* IFM_ACTIVE */
        int flag;
        int rcPkt;
        int sndPkt;
        int isIpConflict ;
        char szMask[CB_SZ_IP_MAX];
} SLIBNETIF, *PSLIBNETIF;

typedef struct tag_SYNONETIFMAPPING {
    int ifcount ; /* number of interfaces to be mapped*/
    int interfaces[NUM_MAXIFACES];
    
} SYNONETIFMAPPING, *PSYNONETIFMAPPING;

/**
 * This structure is for pppoe-relay configure.
 */
typedef struct _tag_PPPOERELAYCONFIG {
	/* Enable pppoe-relay */
	BOOL blEnabled;
	/* server interface */
	char szIfServer[SYNO_IFNAME_MAX];
} PPPOERELAYCONFIG, *PPPPOERELAYCONFIG;

/**
 * This enumerate for ipv6 address modes selection from UI
 * @ingroup NET
 */
typedef enum _tag_SYNO_IPV6_CONF_MODE {
	/**
	 * IPv6 auto stateless configuration
	 */
	IPV6_CONF_AUTO,
	/**
	 * Switch off ipv6
	 */
	IPV6_CONF_OFF,
	/**
	 * IPv6 auto stateful configuration, via dhcp6c
	 */
	IPV6_CONF_DHCP,
	/**
	 * IPv6 manual configuration
	 */
	IPV6_CONF_STATIC,
	/**
	 * IPv6 auto stateless configuration and DHCPv6
	 */
	IPV6_CONF_AUTO_DHCP,
} SYNOIPV6CONFMODE;

/**
 * This enumerate for ipv6 ip command to add or delete ip & gw
 * @ingroup NET
 */
typedef enum _tag_SYNO_IPV6_IP_CMD {
	/**
	 * Add ipv6 address or gateway
	 */
	IPV6_CMD_ADD,
	/**
	 * Delete ipv6 address or gateway
	 */
	IPV6_CMD_DELETE,
} SYNOIPV6IPCMD;

typedef enum _tag_SLIB_IF_QUERY {
	IF_QUERY_ALL,		// all logical interface
	IF_QUERY_WAN,		// ppp0, wm0, ra0, br0,
				// non local ethX|bondX
	IF_QUERY_LAN,		// local ethX|bondX
	//////////////////////////////////////////////////////
	// Following flag will be used by bitwise operation //
	//////////////////////////////////////////////////////
	/**
	 * Append `IF_QUERY_HA_DATA` to enumerate the interfaces which has HA IP & Mask when HA enabled,
	 * when HA is not enabled, this flag can be seem as not be appended.
	 * It can always be used no matter HA is enabled or not.
	 */
	IF_QUERY_HA_DATA = 0x10,
} SLIB_IF_QUERY;

/**
 * The enumerate for selected modes to support in DiskStation.
 * The underlying operation is implemented by linux bonding.
 * @ingroup NET
 * @author \$Author: thlu $
 * @version \$Revision: 1.21 $
 */
typedef enum SYNO_LINK_AGGR_MODE {
        /**
         * Link Aggregation is disabled.  lower bound of Link
         * Aggregation Mode Enumerates.
         */
        LINK_AGGR_DISABLE,
        /** Link Aggregation is Balance-alb(Adaptive load balancing). */
        LINK_AGGR_ALB,
        /** Link Aggregation is IEEE 802.3ad.  */
        LINK_AGGR_8023AD,
        /** Link Aggregation is Balance-xor. */
        LINK_AGGR_XOR,
        /** Link Aggregation is Active-backup(failover only). */
        LINK_AGGR_FAILOVER,
        /** Link Aggregation is Balance-rr(Round-Robin). */
        LINK_AGGR_RR,
        /** OVS Link Aggregation is Active-Backup(failover only). */
        LINK_OVS_AGGR_FAILOVER,
        /** OVS Link Aggregation is Balance-SLB. */
        LINK_OVS_AGGR_SLB,
        /** OVS Link Aggregation is Balance-TCP (with LACP). */
        LINK_OVS_AGGR_TCP,
        /**
         * The number of Link Aggregation Mode DS supported.  Upper
         * bound of Link Aggregation Mode Enumerates.
         */
        LINK_AGGR_MODE_NUM,
} SYNOLINKAGGRMODE;

/**
 * The information of Link Aggregation enabled device.
 * The underlying operation is implemented by linux bonding.
 * @ingroup NET
 * @struct SYNOLINKAGGROPT net.h <synonetsdk/net.h>
 * @author \$Author: thlu $
 * @version \$Revision: 1.21 $
 * @see SYNONetLinkAggrOptSlsaveAdd()
 */
typedef struct SYNOLINKAGGROPT {
        /** Short device name of aggregated NIC, ie, bond0. */
        char szDev[SYNO_IFNAME_MAX];
        /** Mode of this aggregated NIC. */
        SYNOLINKAGGRMODE laMode;
        /** Is any error occuried detected. */
        BOOL blErrorSet;
        /** Number of physical NIC aggregated to this device. */
        int nSlaves;
        /**
         * Sorted short device names of physical NIC aggregated
         * to this device.  Should invoke
         * SYNONetLinkAggrOptSlsaveAdd() to add slave devices.
         */
        char rgszSlaves[NUM_MAXIFACES][SYNO_IFNAME_MAX];
} SYNOLINKAGGROPT, *PSYNOLINKAGGROPT;

/**
 * `grgBondDesc` is a mapping between our enumerate
 * `SYNO_LINK_AGGR_MODE` to its bonding description.
 * @ingroup NET
 * @struct SYNOBOND_DESC net.h <synonetsdk/net.h>
 * @see `grgBondDesc` definition in net_link_aggr_set.c
 */
typedef struct _type_SYNOBOND_DESC {
    const char *     szBOND_MODE;
    const char *     szBOND_NAME;
    const char *     szBOND_OPTS;
} SYNOBOND_DESC;
extern SYNOBOND_DESC grgBondDesc[LINK_AGGR_MODE_NUM];

/**
 * Enumerates for getting network interface.
 * @ingroup NET
 * @author \$Author: thlu $
 * @version \$Revision: 1.21 $
 */
typedef enum SYNO_NIC_ENUM {
        /** lower bound of NIC Enumerates.  */
        NIC_MIN = 0,
        /**
         * Enumerates only physical devices, including slave
         * devices.
         */
        NIC_PHYSICAL = 0x1,
        /**
         * Enumerates logical devices and non-slave
         * physical devices.
         */
        NIC_LOGICAL = 0x2,
        /**
         * Enumerates logical devices and all physical
         * devices.
         */
        NIC_ALL = (NIC_PHYSICAL | NIC_LOGICAL),
        /**
         * Enumerates NIC_PHYSICAL, NIC_LOGICAL, or NIC_ALL without
         * filtering the HA heartbeat interface in HA mode
         */
        NIC_HA_HEARTBEAT = 0x4,
        NIC_LOGICAL_PPP = 0x8,
        /**
         * Append `NIC_HA_DATA` to enumerate the interfaces which has HA IP & Mask when HA enabled,
         * when HA is not enabled, this flag can be seem as not be appended.
         * It can always be used no matter HA is enabled or not.
         * sample tool: synonet --show_ha
         */
        NIC_HA_DATA = 0x10,
        /**
         * Upper bound of NIC Enumerates.
         */
        NIC_MAX,
} SYNONICENUM;

enum {
        SLIB_STRUCT_NET_STAT_VERSION = 1,
};
typedef struct _tag_SLIB_NET_STAT {
        int     version;
        char szName[SYNO_IFNAME_MAX];  /* interface name fec0, fxp1 */
        unsigned long long ullcbRXBytes;
        unsigned long long ullcbTXBytes;
        unsigned long long ullcRXPackets;
        unsigned long long ullcTXPackets;
} *PSLIBNETSTAT;

typedef enum _tag_SYNO_GET_MAC_RETURN {
        RET_GET_MAC_SUCCESS = 0,
        RET_GET_MAC_ERR_UNKNOWN,
        RET_GET_MAC_ERR_STANDALONE,
        RET_GET_MAC_ERR_IN_SHA,
        RET_GET_MAC_ERR_IN_AHA,
} SYNO_GET_MAC_RETURN;

typedef struct _tag_SYNO_DHCPD_OPT_VALUE {
	char str[BUFSIZ];
	PSLIBSZLIST pList;
} SYNO_DHCPD_OPT_VALUE, *PSYNO_DHCPD_OPT_VALUE;

typedef struct _tag_SYNO_DHCPD_OPTION {
	int optNum;
	char optName[CB_SZ_DHCPD_OPT_NAME_MAX];
	SYNO_DHCPD_OPT_VALUE optValue;

	struct _tag_SYNO_DHCPD_OPTION *pNext;
} SYNO_DHCPD_OPTION, *PSYNO_DHCPD_OPTION;

typedef struct _tag_SYNO_DHCPD_CONF {
	BOOL	blEnable;
	int		autoTime;
	int		leaseTime;
	char	szRangeStart[CB_SZ_IP_MAX];
	char	szRangeEnd[CB_SZ_IP_MAX];
	char	szInterface[SYNO_IFNAME_MAX];
	char    szDomain[MAXPATHLEN];

	/* Below three member is used for setting DNS server.
	 * If you have less than two DNS server, use szDns and szSDns to set.
	 * But if you have more than two DNS server, please use szDnsList
	 *   instead of szDns and szSDns.
	 *
	 * szDnsList: DNS List, each DNS is separated by comman
	 *   ipv4: ex. ip1,ip2,ip3
	 *   ipv6: ex. [ip1],[ip2],[ip3]
	 */
	char	szDns[CB_SZ_IP_MAX];
	char    szSDns[CB_SZ_IP_MAX];
	char	szDnsList[PATH_MAX];

	char	szSubnet[CB_SZ_IP_MAX];
	char	szRouter[CB_SZ_IP_MAX];
	char	szLeaseFile[MAXPATHLEN];
	char	szTag[CB_SZ_DHCPD_TAG_MAX];

	/* For IPv6, valid type is "off", "ra-only", "ra-stateless", "stateful".
	 * If we szDhcpv6Type has conflict with blEnable, prefer szDhcpv6Type
	 *   "off" -> disable
	 *   "ra-only", "ra-stateless", "stateful" -> enable
	 */
	char	szDhcpv6Type[CB_SZ_IP_MAX];

	PSYNO_DHCPD_OPTION pOptions;
} SYNO_DHCPD_CONF, *PSYNO_DHCPD_CONF;

typedef struct _tag_SLIB_VLAN {
	char szInterface[SYNO_IFNAME_MAX];
	char szDevice[SYNO_IFNAME_MAX];
	int id;
} SLIBVLAN, *PSLIBVLAN;

typedef struct NET_IFNAME_CHANGE_PLUGIN_ENV *PNET_IFNAME_CHANGE_PLUGIN_ENV;

typedef enum _tag_BR_TYPE {
	TYPE_BR_UNKNOWN,
	TYPE_NOT_BR,		// not master and not slave
	TYPE_BR_MASTER,		// pure bridge master
	TYPE_NAT_MASTER,	// bridge master and NAT
	TYPE_SLAVE,
} BR_TYPE;

typedef enum _tag_TOPOLOGY_MODE {
	TOPOLOGY_UNKNOWN = 0, /* This value must not be changed */
	TOPOLOGY_STATION,
	TOPOLOGY_BRIDGE,
	TOPOLOGY_ROUTER,
} TOPOLOGY_MODE;

typedef struct _tag_BRIDGE_INFO {
	BR_TYPE type;
	char szIfName[SYNO_IFNAME_MAX];
	union {
		char szPrimary[SYNO_IFNAME_MAX];
		char szBridge[SYNO_IFNAME_MAX];
	} info;
} BRIDGE_INFO, *PBRIDGE_INFO;

typedef enum _tag_SYNO_WIRELESS_MODE {
	WIRELESS_AP_MODE,
	WIRELESS_CLIENT_MODE,
} SYNO_WIRELESS_MODE;

#define MAX_TOPOLOGY_NAME_LEN  64

typedef struct _tag_TOPOLOGY_INFO {
	TOPOLOGY_MODE mode;
	char szModeName[MAX_TOPOLOGY_NAME_LEN];
	char szExtIfName[SYNO_IFNAME_MAX];
	SYNO_WIRELESS_MODE wirelessMode;
	BR_TYPE	brType;
} TOPOLOGY_INFO, *PTOPOLOGY_INFO;

typedef struct tag_SYNONETETHERWAKEINFO {
  char mac[6];
  char ifName[32];
} SYNONETETHERWAKEINFO;

typedef enum _tag_IFACE_BLOCK_MODE {
	MODE_NONE = 0,
	MODE_HA = 1,
	MODE_AHA = 1 << 1,
	MODE_VIRTUALIZATION = 1 << 2,
	MODE_MAILPLUS = 1 << 3,
} IF_BLOCK_MODE, *PIF_BLOCK_MODE;

/**
 * Checks the enumerate of selected Link Aggregation modes is 
 * RUNNING mode or not.   The following modes are not RUNNING 
 * modes: <UL> 
 *     <LI>LINK_AGGR_DISABLE
 *     <LI>LINK_AGGR_MODE_NUM
 * </UL>
 * 
 * @author \$Author: thlu $
 * @version \$Revision: 1.21 $
 * @ingroup NET 
 * @param laMode [IN] The SYNOLINKAGGRMODE to be checked.
 * 
 * @return <ul>
 *     <LI>TURE: RUNNING mode
 *     <LI>FALSE: The laMode is LINK_AGGR_DISABLE or
 *     LINK_AGGR_MODE_NUM
 * </ul>
 */
static inline BOOL SYNONetLinkAggrModeIsEnabled(SYNOLINKAGGRMODE laMode)
{
	switch (laMode) {
	case LINK_AGGR_DISABLE:
	case LINK_AGGR_MODE_NUM:
		return FALSE;
	default:
		return TRUE;
	}
}

typedef enum _tag_IPTYPE {
	TYPE_IPv4,
	TYPE_IPv6
} IPTYPE;

#ifndef NO_PROTO
#include <availability.h>
#include <synonetsdk/net_p.h>
#endif // NO_PROTO

__END_DECLS;

/**
 * @}
 */

#endif // __SYNO_NETSDKIF_H_
