#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2010 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_DEFINE_HEADER_
#define _NET_AIRROUTER_DEFINE_HEADER_

// define for package
#define SZF_CLIENT_LIST_CONF "/tmp/connectionlist_upnpscanner.json"

// define for upnp scan
#define SZF_ARP_TABLE "/proc/net/arp"
#define MAX_UPNPSCANNER_TIME 10

// define for static routing
#define SZ_STATIC					"static"
#define SZ_SOURCE_ALL				"all"
#define SZ_STATIC_TABLE				"static-table"
#define SZ_MAIN_TABLE				"main"
#define STATIC_TABLE_ID				2
#define SZF_MULTI_TABLE				"/etc/iproute2/config/multi_table_config"
#define SZF_RT_TABLES				"/etc/iproute2/rt_tables"
#define SZK_ROUTE_TABLE_NAME		"name"
#define SZK_ROUTE_TABLE_ID			"id"
#define SZK_ROUTE_TABLE_ENABLE		"enable"
#define SZK_ROUTE_TABLE_SOURCE		"source"
#define SZK_ROUTE_TABLE_ENABLE_V6	"enable_v6"
#define SZK_ROUTE_TABLE_SOURCE_V6	"source_v6"
#define SZF_IP_TOOL					"/sbin/ip"
#define SZV_IPV4                    "ipv4"
#define SZV_IPV6                    "ipv6"
#define SZF_STATIC_ROUTE_RULE		"/etc/iproute2/config/static-table-rule"
#define SZF_STATIC_ROUTE_RULE_V6	"/etc/iproute2/config/static-table-rule-v6"
#define SZ_STATUS_ENABLED			"Enabled"
#define SZ_STATUS_DISABLED			"Disabled"

// define for upnp callback
#define SZK_XMLDOC_DISPLAYNAME "displayName"
#define SZK_XMLDOC_MODELNAME "modelName"
#define SZK_XMLDOC_MODELDESCRIPTION "modelDescription"
#define SZK_XMLDOC_MANUFACTURER "manufacturer"
#define SZK_XMLDOC_FRIENDLYNAME "friendlyName"
#define SZK_XMLDOC_IPADDR "ipAddr"
#define SZK_XMLDOC_MACADDR "macAddr"
#define SZK_XMLDOC_CLIENTLIST "ClientList"
#define SZK_XMLDOC_GENERALDMA "General DMA"
#define SZK_XMLDOC_DEVICETYPE "deviceType"
#define SZK_XMLDOC_USERDEF_DISPLAYNAME "userdef_displayName"
#define SZK_XMLDOC_USERDEF_DEVICETYPE "userdef_deviceType"
#define SZK_XMLDOC_ASSOTIME "asso_time"
#define SZK_XMLDOC_NETIF "netif"
#define SZK_XMLDOC_CONNECTION "connection"
#define SZK_XMLDOC_TRANSFERRX "transferRX"
#define SZK_XMLDOC_TRANSFERTX "transferTX"
#define SZK_XMLDOC_SIGNALSTRENGTH "signalstrength"

#ifdef MY_DEF_HERE
// define for tx module
#define SZF_CMD_CAT "/bin/cat"
#define SZF_CMD_CAT_TMP "/tmp/cat" // for ALPINE #78074
#define SZF_CMD_CP "/bin/cp"
#define SZF_ETHTOOL_TMP		"/tmp/ethtool" // for ALPINE #78074
#define SZF_TX_PATH_FMT "/sys/class/net/%s/statistics/tx_packets"
#define TX_MONITOR_TIME_INTERVAL 30	// sec
#endif /* MY_DEF_HERE */

// define for ds scan
#define SZF_DSSCANNER_FHOSTLIST "/tmp/networkcenter_dsscanner_list.tmp"
#define SZF_IW			"/usr/sbin/iw"
#define SZF_ETHTOOL		"/usr/bin/ethtool"

// Type for Connection List
#define SZV_CONNECTIONLIST_NAS					"nas"
#define SZV_CONNECTIONLIST_TABLET				"tablet"
#define SZV_CONNECTIONLIST_COMPUTER				"computer"
#define SZV_CONNECTIONLIST_IPCAM				"ipcam"
#define SZV_CONNECTIONLIST_PRINTER				"printer"
#define SZV_CONNECTIONLIST_PLAYER				"player"
#define SZV_CONNECTIONLIST_OTHERS				"others"

// Connection for Connection List
#define SZV_CONNECTIONLIST_ETHERNET				"ethernet"
#define SZV_CONNECTIONLIST_WIFI					"wifi"

// Scanner type for Device List
#define SZK_DEVICELIST_SCANNERTYPE				"scannertype"
#define SZV_DEVICELIST_SCANNERTYPE_ALL			"all"
#define SZV_DEVICELIST_SCANNERTYPE_UPNP			"upnp"
#define SZV_DEVICELIST_SCANNERTYPE_DS			"ds"
#define SZV_DEVICELIST_SCANNERTYPE_WIFI			"wifi"

// Method type for Device List
#define SZK_DEVICELIST_METHOD					"method"
#define SZV_DEVICELIST_METHOD_GET				"get"
#define SZV_DEVICELIST_METHOD_SET				"set"
#define SZV_DEVICELIST_METHOD_DEL				"del"

// debug only: the define to enable or disable scanner
#define SUPPORT_DEVICELIST_UPNPSCANNER
#define SUPPORT_DEVICELIST_DSSCANNER
#define SUPPORT_DEVICELIST_WIFISCANNER

#define SZF_CAT "/bin/cat"
#define SZF_BRCTL "/usr/bin/brctl"

#endif
