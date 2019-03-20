/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_DEFINE_HPP_
#define _SYNO_WIRELESS_WIFI_DEFINE_HPP_

#include <synowireless/wifi/enum.hpp>

#define SZ_SET_TXPOWER_CMD "iwconfig %s txpower %d"
#define SZ_MAX_TXPOWER_CMD "iw phy0 info | grep \"dBm)$\" | grep \"\\[%d\\]\" | cut -d\"(\" -f2 | cut -d\"d\" -f1"
#define SZ_MAX_TXPOWER_CMD_AUTO "iw phy0 info | grep \"dBm)$\" | awk 'NR==1' | cut -d\"(\" -f2 | cut -d\"d\" -f1"

#define SZF_TOPOLOGY_LOCK				"/tmp/topology.lock"

// The PiD File
#define SZF_WIFID_PID_FILE      "/var/run/synowifid.pid"
#define SZF_NETD_PID_FILE       "/var/run/synonetd.pid"
#define SZF_USBMODEMD_PID_FILE  "/var/run/synousbmodemd.pid"
#define SZF_SCEMD_PID					"/var/run/scemd.pid"
#define SZF_SYNO_WIRELESS_PID			"/tmp/synowireless.pid"

#define SZV_WLAN0						"wlan0"
#define SZV_WLAN1						"wlan1"

#define SZV_DEFAULT_AP_IP_ADDRESS		"10.1.14.1"
#define SZV_DEFAULT_AP_NETMASK			"255.255.255.0"
#define SZV_DEFAULT_DHCP_RANGE_BEGIN	"10.1.14.2"
#define SZV_DEFAULT_DHCP_RANGE_END		"10.1.14.254"
//#define SZV_DEFAULT_SLAVE_LIST			"wlan0"

#define SZV_DEFAULT_GUEST_IP_ADDRESS		"10.1.15.1"
#define SZV_DEFAULT_GUEST_DHCP_RANGE_BEGIN	"10.1.15.2"
#define SZV_DEFAULT_GUEST_DHCP_RANGE_END	"10.1.15.254"

#define SZV_DEFAULT_SSID				"DiskStation"
#define DEFAULT_MAX_NUM_CLIENT			256
#define SZV_DEFAULT_SCHEDULE_ONE_DAY	"000000000000000000000000"
#define SZV_DEFAULT_SCHEDULE			SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY\
										SZV_DEFAULT_SCHEDULE_ONE_DAY

#define SZV_DEFAULT_GUEST_SSID			"DiskStationGuest"

#define DEFAULT_CHANNEL					0
#define MAC_ADDR_LENGTH					17
#define SSID_MAX_LENGTH					32

/* key of wifi_ap_{mac address}.conf */
#define SZV_SECTION_GENERAL				"general"
#define SZV_SECTION_DHCP				"dhcp"
#define SZV_SECTION_GUEST_DHCP			"guest_dhcp"
#define SZK_IF							"interface"
#define SZK_IFNAME						"ifname"
#define SZK_NETIF						"netif"
#define SZK_BSSID						"bssid"
#define SZK_STATUS						"status"
#define SZK_DRIVER						"driver"
#define SZK_BRIDGE_TYPE					"bridge_type"
#define SZV_BRIDGE_TYPE					"bridge"
#define SZV_LOCAL_BRIDGE_TYPE			"local_bridge"
#define SZV_GUEST_BRIDGE_TYPE			"guest_bridge"
/* SZK_NETMASK is redefine in libsynonetsdk "netmask" */
/* because this reason, we change IP's define together */
#define SZK_AP_IP_ADDRESS					"ap_ip_address"
#define SZK_AP_NETMASK						"ap_netmask"
#define SZK_IPV6_PREFIX					"ap_ipv6_prefix"
#define SZK_IPV6_PRIMARY_DNS			"ipv6_pdns"
#define SZK_IPV6_SECONDARY_DNS			"ipv6_sdns"
#define SZK_DHCP_ENABLED				"dhcp_enabled"
#define SZK_DHCP_RANGE_BEGIN			"dhcp_range_begin"
#define SZK_DHCP_RANGE_END				"dhcp_range_end"
#define SZK_DHCPV6_TYPE					"dhcpv6_type"
#define SZK_DHCPV6_RANGE_BEGIN			"dhcpv6_range_begin"
#define SZK_DHCPV6_RANGE_END			"dhcpv6_range_end"
#define SZK_SLAVE_LIST					"slave_list"
#define SZK_ENABLED						"enabled"
#define SZK_CLIENTENABLED				"clientenabled"
#define SZK_DISABLED					"disabled"
#define SZK_SSID						"ssid"
#define SZK_DISPLAY_SSID				"display_ssid"
#define SZK_MODE						"mode"
#define SZK_BANDWIDTH					"bandwidth"
#define SZK_CHANNEL						"channel"
#define SZK_TX_POWER					"tx_power"
#define SZK_MAX_NUM_CLIENT				"max_num_client"
#define SZK_WMM_ENABLED					"wmm_enabled"
#define SZK_SCHEDULE_ENABLED			"schedule_enabled"
#define SZK_SCHEDULE_ALLOW				'1'
#define SZK_SCHEDULE_DISALLOW			'0'
#define SZK_IS_PCI_INTERFACE			"is_pci_interface"
#ifndef SZK_SCHEDULE
#define SZK_SCHEDULE					"schedule"
#endif
#define SZK_SECURITY					"security"
#define SZK_ENCRYPTION					"encryption"
#define SZK_PASSWORD					"password"
#define SZK_AUTH_SERVER_IP				"auth_server_ip"
#define SZK_AUTH_SERVER_PORT			"auth_server_Port"
#define SZK_AUTH_SERVER_SHARED_SECRET	"auth_server_shared_secret"
#define SZK_GUEST_SUPPORT				"guest_support"
#define SZK_GUEST_ENABLED				"guest_enabled"
#define SZK_GUEST_SSID					"guest_ssid"
#define SZK_GUEST_DISPLAY_SSID			"guest_display_ssid"
#define SZK_GUEST_BSSID					"guest_bssid"
#define SZK_GUEST_MAX_NUM_CLIENT		"guest_max_num_client"
#define SZK_GUEST_SECURITY				"guest_security"
#define SZK_GUEST_ENCRYPTION			"guest_encryption"
#define SZK_GUEST_PASSWORD				"guest_password"
#define SZK_GUEST_ALLOW_ACCESS_GUEST	"guest_allow_access_guest"
#define SZK_GUEST_ALLOW_ACCESS_LAN		"guest_allow_access_lan"
#define SZK_GUEST_ALLOW_ACCESS_HTTP_HTTPS_ONLY "guest_allow_access_http_https_only"
#define SZK_GUEST_SCHEDULE_ENABLED		"guest_schedule_enabled"
#define SZK_GUEST_SCHEDULE				"guest_schedule"
#define SZK_GUEST_IP_ADDRESS            "guest_ip_address"
#define SZK_GUEST_NETMASK               "guest_netmask"
#define SZK_GUEST_DHCP_ENABLED          "guest_dhcp_enabled"
#define SZK_GUEST_DHCP_RANGE_BEGIN      "guest_dhcp_range_begin"
#define SZK_GUEST_DHCP_RANGE_END        "guest_dhcp_range_end"
#define SZK_MAC_FILTER_ENABLED			"mac_filter_enabled"
#define SZK_MAC_FILTER_POLICY			"mac_filter_policy"
#define SZK_MAC_FILTER_LIST				"mac_filter_list"
#define SZK_MAC_FILTER_MAC				"mac"
#define SZK_MAC_FILTER_DESC				"desc"
#define SZK_PARENTAL_CONTROL_ENABLED	"parental_control_enabled"
#define SZK_PARENTAL_CONTROL_LIST		"parental_control_list"
#define SZK_PARENTAL_CONTROL_NAME		"name"
#define SZK_PARENTAL_CONTROL_MAC		"mac"
#define SZK_PARENTAL_CONTROL_SCHEDULE	"tc_sched"

/* key of wifi_client_{mac address}.conf */
#define SZK_STATION_LIST				"station_list"
#define SZK_STATION_ESSID				"essid"
#define SZK_STATION_BSSID				"bssid"
#define SZK_STATION_OPMODE				"opmode"
#define SZK_STATION_SECURITY			"security"
#define SZK_STATION_ENCRYPTION			"encryption"
#define SZK_STATION_USER				"user"
#define SZK_STATION_PASSWORD			"password"
#define SZK_STATION_ACCESS_TIME			"access_time"
#define SZK_STATION_ISDHCP				"is_dhcp"
#define SZK_STATION_IP_ADDRESS			"ip"
#define SZK_STATION_NETMASK				"netmask"
#define SZK_STATION_GATEWAY				"gateway"
#define SZK_STATION_CHANNEL				"channel"
#define SZK_STATION_SIGNAL				"signal"
#define SZK_STATION_HWMODE				"hwmode"

#define SZD_USR_SYNO_ETC_WIFI		"/usr/syno/etc/wifi/"
#define SZF_AP_CONF_PREFIX 			SZD_USR_SYNO_ETC_WIFI"wifi_ap_"
#define SZF_CLIENT_CONF_PREFIX		SZD_USR_SYNO_ETC_WIFI"wifi_client_"
#define SZF_TOPOLOGY_CONF_PREFIX	SZD_USR_SYNO_ETC_WIFI"wifi_topology_"
#define SZF_TOPOLOGY_CONF_OBSOLETE	SZD_USR_SYNO_ETC_WIFI"wifi_client_obsolete"
#define SZF_TOPOLOGY_CLIENT			SZF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_CLIENT
#define SZF_TOPOLOGY_ROUTER			SZF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_ROUTER
#define SZF_TOPOLOGY_BRIDGE			SZF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_BRIDGE
#define SZF_TOPOLOGY_ROUTER_DS		SZF_TOPOLOGY_ROUTER"_ds"
#define SZF_TOPOLOGY_BRIDGE_DS		SZF_TOPOLOGY_BRIDGE"_ds"
#define SZF_TOPOLOGY_ROUTER_AIR		SZF_TOPOLOGY_ROUTER"_air"
#define SZF_TOPOLOGY_BRIDGE_AIR		SZF_TOPOLOGY_BRIDGE"_air"
#define SZF_TOPOLOGY_BRIDGE_OVS		SZF_TOPOLOGY_BRIDGE"_ovs_ds"

#define SZD_USR_SYNO_ETC_DEF_WIFI		"/usr/syno/etc.defaults/wifi/"
#define SZF_DEF_TOPOLOGY_CONF_PREFIX	SZD_USR_SYNO_ETC_DEF_WIFI"wifi_topology_"
#define SZF_DEF_TOPOLOGY_CLIENT			SZF_DEF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_CLIENT
#define SZF_DEF_TOPOLOGY_ROUTER			SZF_DEF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_ROUTER
#define SZF_DEF_TOPOLOGY_BRIDGE			SZF_DEF_TOPOLOGY_CONF_PREFIX SZV_TOPOLOGY_BRIDGE
#define SZF_DEF_TOPOLOGY_ROUTER_DS		SZF_DEF_TOPOLOGY_ROUTER"_ds"
#define SZF_DEF_TOPOLOGY_BRIDGE_DS		SZF_DEF_TOPOLOGY_BRIDGE"_ds"
#define SZF_DEF_TOPOLOGY_ROUTER_AIR		SZF_DEF_TOPOLOGY_ROUTER"_air"
#define SZF_DEF_TOPOLOGY_BRIDGE_AIR		SZF_DEF_TOPOLOGY_BRIDGE"_air"

#define SZF_MAC_FILTER_INFO			"/etc/hostapd/mac_filter/mf.info"
#define SZF_MAC_FILTER_CONF			"/etc/hostapd/mac_filter/mf.conf"
#define SZD_ETC_PARENTAL			"/etc/parental/"
#define SZF_IPTABLES_GUEST_RULE		"/usr/syno/etc/iptables_guest_net.sh"
#define SZ_CONFIG_FORMAT			"\t%s=%s\n"
#define SZK_MAC_FILTER_CONF_DESC	"desc"
#define SZK_MAC_FILTER_CONF_MAC		"mac"
#define SZK_POLICY					"policy"
#define SZK_CLIENT_NAME				"name"
#define SZK_TC_SCHEDULE				"tc_sched"
#define SZV_GUEST_BRIDGE			"gbr"
#define SZV_GUEST_INTERFACE			"gwlan"

#define SZ_ADDRESS					"/address"
#define SZD_SYS_CLASS_NET			"/sys/class/net/"
#define SZ_WIRELESS_SYSFS_FORMAT	SZD_SYS_CLASS_NET"wlan*"
#define SZV_BRIDGE					"br0"
#define SZV_LOCAL_BRIDGE			"lbr0"
#define SZK_NAT						"nat"
#define SZV_OVS_BRIDGE					"ovs_eth0"

// command and file
#define SZF_RFKILL_BIN						"/usr/syno/sbin/rfkill"
#define SZF_WPA_SUPPLICANT_CONF				"/usr/syno/etc/wpa_supplicant.conf."
#define SZF_WPA_SUPPLICANT_PID				"/var/run/wpa_supplicant.pid."
#define SZF_WPA_SUPPLICANT					"/usr/sbin/wpa_supplicant"
#define SZF_WPA_CLI							"/usr/sbin/wpa_cli"
#define SZF_WPA_RECONNECT_SH				"/usr/syno/etc.defaults/wifi/wpa_post_reconnect.sh"
#define SZF_IFCONFIG						"/sbin/ifconfig"
#define SZF_IWCONFIG						"/sbin/iwconfig"
#define SZF_IWLIST							"/sbin/iwlist"
#define SZF_IW                                                  "/usr/sbin/iw"
#define SZF_INSMOD_CMD						"/sbin/insmod"
#define SZF_RMMOD_CMD						"/sbin/rmmod"
#define SZF_IWPRIV							"/sbin/iwpriv"
#define SZF_RT2860APD						"/usr/syno/sbin/rt2860apd"
#define SZF_SYNOWIRELESS_CMD				"/usr/syno/bin/synowireless"
#define SZF_SYNOWIRELESS_CMD_TMP			"/tmp/synowireless"
#define SZF_RM								"/bin/rm"
#define SZF_CP								"/bin/cp"
#define SZF_HOSTAPDCLI						"/usr/bin/hostapd_cli"
#define SZF_UDEV_USB_WIFI_UTIL_SH			"/lib/udev/script/usb-wifi-util.sh"

// other define value
#define WIRELESS_CONNECTION_TIMEOUT			30
#define SZ_CHECK_CONNECTION_CMD				SZF_WPA_CLI" -i %s status | grep wpa_state"
#define SZK_CLIENT_SUPPORT_PCI_WIFI			"support_pci_wifi"
#define SZV_CLIENT_ADHOC_BSSID				"00:00:00:00:00:00"
#define SZV_CLIENT_CONNECTION_COMPLETED		"COMPLETED"
#define SZV_CLIENT_ENCRYPTION_TKIP			"TKIP"
#define SZV_CLIENT_ENCRYPTION_CCMP			"CCMP"
#define SZV_CLIENT_ENCRYPTION_TKIP_CCMP		"TKIP CCMP"

#define SZD_ETC_HOSTAPD							"/etc/hostapd/"
#define SZF_HOSTAPD_PREFIX						SZD_ETC_HOSTAPD"hostapd-"
#define SZF_HOSTAPD_INFO_SUFFIX					".info"
#define SZF_HOSTAPD_MACLIST						SZD_ETC_HOSTAPD"hostapd-mac.list"
#define SZF_HOSTAPD_CONF_SUFFIX					"-host.conf"
#define SZF_GUEST_HOSTAPD_INFO_SUFFIX			"-guest.info"
#define SZF_GUEST_HOSTAPD_CONF_SUFFIX			"-guest.conf"

/* For hostapd-wlan0.conf */
#define SZK_HOSTAPD_INTERFACE					"interface"
#define SZK_HOSTAPD_DRIVER						"driver"
#define SZK_HOSTAPD_SSID						"ssid"
#define SZK_HOSTAPD_IGNORE_BROADCAST_SSID		"ignore_broadcast_ssid"
#define SZK_HOSTAPD_WPA_PSK_FILE				"wpa_psk_file"
#define SZK_HOSTAPD_WPS_STATE					"wps_state"
#define SZK_HOSTAPD_AP_SETUP_LOCKED				"ap_setup_locked"
#define SZK_HOSTAPD_CTRL_INTERFACE				"ctrl_interface"
#define SZK_HOSTAPD_CONFIG_METHODS				"config_methods"
#define SZK_HOSTAPD_MAX_NUM_STA					"max_num_sta"
#define SZK_HOSTAPD_BRIDGE						"bridge"
#define SZK_HOSTAPD_CHANNEL						"channel"
#define SZK_HOSTAPD_IEEE80211N					"ieee80211n"
#define SZK_HOSTAPD_HT_CAPAB					"ht_capab"
#define SZK_HOSTAPD_WMM_ENABLED					"wmm_enabled"
#define SZK_HOSTAPD_HW_MODE						"hw_mode"
#define SZK_HOSTAPD_EAP_SERVER					"eap_server"
#define SZK_HOSTAPD_AUTH_ALGS					"auth_algs"
#define SZK_HOSTAPD_WEP_DEFAULT_KEY				"wep_default_key"
#define SZK_HOSTAPD_WEP_KEY0					"wep_key0"
#define SZK_HOSTAPD_WPA							"wpa"
#define SZK_HOSTAPD_WPA_KEY_MGMT				"wpa_key_mgmt"
#define SZK_HOSTAPD_WPA_PASSPHRASE				"wpa_passphrase"
#define SZK_HOSTAPD_WPA_PAIRWISE				"wpa_pairwise"
#define SZK_HOSTAPD_RSN_PAIRWISE				"rsn_pairwise"
#define SZK_HOSTAPD_IEEE8021X					"ieee8021x"
#define SZK_HOSTAPD_AUTH_SERVER_ADDR			"auth_server_addr"
#define SZK_HOSTAPD_AUTH_SERVER_PORT			"auth_server_port"
#define SZK_HOSTAPD_AUTH_SERVER_SHARED_SECRET	"auth_server_shared_secret"
#define SZK_HOSTAPD_REQUIRE_HT					"require_ht"
#define SZK_HOSTAPD_MACADDR_ACL					"macaddr_acl"
#define SZK_HOSTAPD_BSS							"bss"
#define SZK_HOSTAPD_BSSID						"bssid"
#define SZK_HOSTAPD_AP_ISOLATE					"ap_isolate"
#define SZV_HOSTAPD_IGNORE_BROADCAST_SSID_YES	"1"
#define SZV_HOSTAPD_IGNORE_BROADCAST_SSID_NO	"0"
#define SZV_HOSTAPD_WPA_PSK_FILE				"/etc/hostapd.psk"
#define SZV_HOSTAPD_WPS_STATE					"2"
#define SZV_HOSTAPD_AP_SETUP_LOCKED				"1"
#define SZV_HOSTAPD_CTRL_INTERFACE				"/var/run/hostapd"
#define SZV_HOSTAPD_CONFIG_METHODS				"label display push_button keypad"
#define SZV_HOSTAPD_MACADDR_ACL					"0"
#define SZV_HOSTAPD_REQUIRE_HT					"1"

#define SZV_HOSTAPD_IEEE80211N		"1"
#define SZV_HOSTAPD_REQUIRE_HT		"1"
#define SZV_HOSTAPD_HT_CAPAB_20MHZ	"[SHORT-GI-20][DELAYED-BA]"
#define SZV_HOSTAPD_HT_CAPAB_40MHZ	SZV_HOSTAPD_HT_CAPAB_20MHZ"[SHORT-GI-40][MAX-AMSDU-7935]"
#define SZV_HT40_PLUS						"[HT40+]"
#define SZV_HT40_MINUS						"[HT40-]"
#define SZV_HOSTAPD_EAP_SERVER				"1"
#define SZV_HOSTAPD_EXTERNAL_EAP_SERVER		"0"
#define HOSTAPD_AUTH_OPEN					1
#define HOSTAPD_AUTH_ENCRYPTION				2
#define SZV_HOSTAPD_WEP_DEFAULT_KEY			"0"
#define SZV_HOSTAPD_WPA_KEY_MGMT_PSK		"WPA-PSK"
#define SZV_HOSTAPD_WPA_KEY_MGMT_EAP		"WPA-EAP"
#define HOSTAPD_WPA_1						1
#define HOSTAPD_WPA_2						2
#define SZV_HOSTAPD_PAIRWISE_TKIP			"TKIP"
#define SZV_HOSTAPD_PAIRWISE_CCMP			"CCMP"
#define SZV_HOSTAPD_PAIRWISE_TKIP_CCMP		"TKIP CCMP"
#define SZV_HOSTAPD_IEEE8021X				"1"
#define SZV_HOSTAPD_AP_ISOLATE				"1"
#define SZV_WPS_TIMEOUT						"120"

/* For Hotplug */
#define MAX_WAITTIME						3
#define SZD_LIB_MODULES						"/lib/modules/"

/* For Connection List */
#define SZK_CONNECTIONLIST_MAC				"mac"
#define SZK_CONNECTIONLIST_ASSOTIME			"asso_time"
#define SZK_CONNECTIONLIST_IP				"ip"
#define SZK_CONNECTIONLIST_HOSTNAME			"hostname"
#define SZF_CONNECTIONLIST_PING				"/bin/ping"

/* portforward and dmz */
#define SZD_ROUTER_PORTFWD			"/etc/portforward/routerpf"
#define SZF_ROUTER_PORTFWD_RULE		SZD_ROUTER_PORTFWD"/rule.conf"
#define SZF_ROUTER_DMZ_CONF			SZD_ROUTER_PORTFWD"/dmz.conf"

/* Key in /etc.default/synoinfo.conf */
#define SZK_SYNOINFO_SUPPORT_WIRELESS_NUMBER	"support_wireless_number"

/* Key in /etc/synoinfo.conf */
#define SZK_HAS_WIFI_DONGLE						"has_wifi_dongle"

/* Key in /tmp/wireless.infoxxxx */
#define SZK_WIRELESSINFO_BUSNAME			"BUSNAME"
#define SZK_WIRELESSINFO_BUSNAME_PCIWIFI	"pci-wifi"
#define SZK_WIRELESSINFO_SERVICE_PREFIX		"usb.wireless."
#define SZK_WIRELESSINFO_CLIENT_MODULE		"CLIENT_MODULE"
#define SZK_WIRELESSINFO_AP_MODULE			"AP_MODULE"

/* For DHCP Config FORMAT */
#define SZ_RANGE_FORMAT             SZK_DHCPD_RANGE"="SZK_DHCPD_SET_TAG"%s,%s,%s,%s,%d\n"
#define SZ_RANGE6_RA_FORMAT         SZK_DHCPD_RANGE"="SZK_DHCPD_SET_TAG"%s,::,constructor:%s,%s,64,%d\n"
#define SZ_CONF_FORMAT				"%s=%s\n"
#define SZ_OPT_FORMAT               SZK_DHCPD_OPT"="SZK_DHCPD_USE_TAG"%s,%s,%s\n"
#define SZK_DHCPD_RANGE             "dhcp-range"
#define SZK_DHCPD_INTERFACE         "interface"
#define SZK_DHCPD_OPT               "dhcp-option"
#define SZK_DHCPD_SET_TAG           "set:"
#define SZK_DHCPD_USE_TAG           "tag:"
#define SZK_DHCPD_OPT_DNS           "option:dns-server"
#define SZK_DHCPD_OPT6_DNS          "option6:dns-server"
#define SZK_DHCPD_OPT_ROUTER        "option:router"
#define SZK_DHCPD_OPT_BOOT          "dhcp-boot"
#define SZV_DHCPD_ENABLE_RA         "enable-ra\n"

/* IPv6 DHCP */
#define SZV_DHCPV6_OFF              "off"
#define SZV_DHCPV6_RAONLY           "ra-only"
#define SZV_DHCPV6_RASTATELESS      "ra-stateless"
#define SZV_DHCPV6_STATEFUL         "stateful"

/* files for rlt_wifi */
#define SZV_RLT_WIFI_AP_NAME		"rlt_wifi"
#define SZV_RLT_WIFI_STA_NAME		"mt7662e_sta"
#define SZV_RT2860APD_NAME			"rt2860apd"

#define SZF_RLT_WIFI_CONF_PATH		"/usr/syno/etc/rlt_wifi/rlt_wifi.conf"
#define SZF_RLT_WIFI_STA_CONF_PATH	"/usr/syno/etc/rlt_wifi/rlt_wifi_sta.conf"

#define SZ_RLT_WIFI_AP_KO			SZV_RLT_WIFI_AP_NAME".ko"
#define SZ_RLT_WIFI_STA_KO			SZV_RLT_WIFI_STA_NAME".ko"

#define SZF_RLT_WIFI_AP_KO_PATH		"/lib/modules/"SZ_RLT_WIFI_AP_KO
#define SZF_RLT_WIFI_STA_KO_PATH	"/lib/modules/"SZ_RLT_WIFI_STA_KO

#define SZ_ASSIGN							"="

#define SZK_RLT_DEFAULT						"Default"
#define SZK_RLT_COUNTRY_REGION				"CountryRegion"
#define SZK_RLT_COUNTRY_REGION_A_BAND		"CountryRegionABand"
#define SZK_RLT_COUNTRY_CODE				"CountryCode"
#define SZK_COUNTRY_CODE				"country_code"
#define SZK_COUNTRY_CODE_TIP				"country_code_tip"
#define SZF_COUNTRY_CODE_FILE				"/usr/syno/etc/wifi/country_code"

#define SZV_RLT_EMPTY								""
#define SZV_RLT_ERROR								"error"
#define RLT_DEFAULT_COUNTRY_REGION					5
#define RLT_DEFAULT_COUNTRY_REGION_A_BAND			7
#define SZV_RLT_DEFAULT_COUNTRY_CODE				SZV_RLT_EMPTY

#define SZF_PROC_PCIE_WIFI_IFNAME	"/proc/pcie_wifi_ifname"
#define SZ_GET_DS215AIR_MAC_CMD		"cat /proc/sys/kernel/syno_mac_address3"

#define SZD_ETC_FW_SECURITY				"/etc/fw_security/"
#define SZD_ETC_TC						"/etc/tc/"

#endif /* _SYNO_WIRELESS_WIFI_DEFINE_HPP_ */
