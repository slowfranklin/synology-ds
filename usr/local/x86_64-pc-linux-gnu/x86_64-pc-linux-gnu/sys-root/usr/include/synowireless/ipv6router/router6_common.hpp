/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_COMMON_
#define _NET_IPV6_ROUTER_COMMON_

// config file
#define SZ_SECT_FORMAT "\t%s=%s\n"
#define SZ_CONF_FORMAT "%s=%s\n"
#define SZF_IPV6_CONF_DIR "/etc/sysconfig/networking"
#define SZF_IPV6_CONF_FILE_PREFIX "ipv6-"
#define SZF_IPV6_CONF_PREFIX SZF_IPV6_CONF_DIR"/"SZF_IPV6_CONF_FILE_PREFIX

// config section & keys
#define SZK_SECT_CONF "conf"
#define SZK_SECT_ADDR "addr"
#define SZK_SECT_LAN "lan"
#define SZK_CONF_TYPE "type"
#define SZK_CONF_WAN "wan"
#define SZK_CONF_DEF_GW "is_default_gateway"
#define SZK_CONF_PREFIX "prefix"
#define SZK_ADDR_LOCAL_V4 "local_addr_v4"
#define SZK_ADDR_REMOTE_V4 "remote_addr_v4"
#define SZK_ADDR_LOCAL_V6 "local_addr_v6"
#define SZK_DSM_CONF_ROUTER "IPV6ROUTER"

// webapi entry
#define SZK_WEBAPI_TYPE "type"
#define SZK_WEBAPI_CONFIG "config"
#define SZK_WEBAPI_CONFIG_WAN "wan"
#define SZK_WEBAPI_CONFIG_PREFIX "prefix"
#define SZK_WEBAPI_CONFIG_ADDR_REMOTE_V4 SZK_ADDR_REMOTE_V4
#define SZK_WEBAPI_CONFIG_ADDR_LOCAL_V6 SZK_ADDR_LOCAL_V6
#define SZK_WEBAPI_PREFIX "prefix"
#define SZK_WEBAPI_PREFIX_PREFIX "prefix"
#define SZK_WEBAPI_PREFIX_IFNAME "ifname"
#define SZK_WEBAPI_PREFIX_WAN "wan"
#define SZK_WEBAPI_PREFIX_LAN "lan"
#define SZK_WEBAPI_CONFIG_DEF_GW "is_default_gateway"

// webapi special value
#define SZV_WEBAPI_CONFIG_WAN_PPPOE "pppoe"

// operation type
#define SZV_TYPE_6IN4 "6in4"
#define SZV_TYPE_6TO4 "6to4"
#define SZV_TYPE_NATIVE "native"
#define SZV_TYPE_INACTIVE "off"

// 6to4 invariants
#define SZV_6TO4_TB_ANYCAST "192.88.99.1"
#define SZV_6TO4_FMT "2002:%02x%02x:%02x%02x"
#define SZV_6TO4_ADDR_FMT SZV_6TO4_FMT"::1/16"
#define SZV_6TO4_PREFIX_FMT SZV_6TO4_FMT"::/48"

// DHCP-PD
#define SZF_DHCLIENT6_EXEC "/usr/sbin/dhclient"
#define SZF_DHCLIENT6_PID_FMT "/tmp/dhclient6-%s.pid"
#define SZF_DHCLIENT6_LEASE_FILE_FMT "/etc/dhclient/ipv6/dhcpv6.lease.%s"
#define SZF_DHCLIENT6_LEASE_FMT "default-duid \"%s\";"

// tunnel device name
#define TUN_6IN4_DEV_PREFIX "6in4-"

// proc entry
#define SZF_PROC_IPV6_FORWARDING "/proc/sys/net/ipv6/conf/all/forwarding"
#define SZF_PROC_IPV6_ACCEPT_RA_FMT "/proc/sys/net/ipv6/conf/%s/accept_ra"

#endif // _NET_IPV6_ROUTER_COMMON_
