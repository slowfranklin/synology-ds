/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_H_
#define _SYNO_WIRELESS_H_

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synonetsdk/net.h> // for CB_SZ_IP_MAX

#ifndef IW_MODE_AUTO	/* IW_MODE_AUTO defined in linux/wireless.h */
#define IW_MODE_AUTO 0
#endif

__BEGIN_DECLS;

/*For parental control*/
#define SZD_PARENTAL				"/etc/parental"
#define SZF_TIME_CONTROL_INFO		SZD_PARENTAL"/timectrl.info"
#define SZF_TIME_CONTROL_UI_CONF	SZD_PARENTAL"/timectrl.ui.conf"
#define SZF_TIME_CONTROL_CONF		SZD_PARENTAL"/timectrl.conf"
#define SZF_TMP_TIME_CONTROL_CONF	"/tmp/timectrl.conf"
#define SZK_CLIENT_NAME				"name"
#define SZK_TC_SCHEDULE				"tc_sched"
#define SZ_TIME_CTRL_FORMAT			"\t%s=%s\n"
#define CH_TIME_CTRL_ALLOW			'1'
#define CH_TIME_CTRL_DISALLOW		'0'
#define SZV_TIME_CTRL_ALLOW			1
#define SZV_TIME_CTRL_DISALLOW		0

#define SZF_TIME_CTRL_BINARY		"/usr/syno/sbin/synotimecontrol"
#define SZF_TIME_CTRL_BINARY_TMP	"/tmp/synotimecontrol"
#define SZK_APPLY					"--apply"
#define SZK_SCHEDULE				"--schedule"
#define SZK_DISABLE					"--disable"
#define SZ_TIME_CTRL_SCHED_CMD		SZF_TIME_CTRL_BINARY_TMP " " SZK_SCHEDULE
#define SZF_IPTABLES_TOOL			"/usr/syno/bin/iptablestool"
#define SZ_SERVIVE_NAME				"timectrl"
#define SZ_INSMOD					"--insmod"
#define SZ_RMMOD					"--rmmod"

#define SZK_UNBLOCK					"unblock"

#define SZK_GATEWAY_DATABASE_GATEWAY	"gateway"
#define SZK_GATEWAY_DATABASE_DNS		"dns"

#ifndef SYNO_YOTAWIMAX_ETHERNET_NAME
#define WIMAX_INTERFACE_NAME        "wm0"
#else
#define WIMAX_INTERFACE_NAME        SYNO_YOTAWIMAX_ETHERNET_NAME"0"
#endif

/**
 * This is for wifi ap.
 *
 */
#define SZF_RC_NETWORK_SCRIPT	"/etc/rc.network"
#define SZ_WIFI_SCHED_CMD 	SZF_TMP_WIFI_SCHEDULER
#define SZF_WIRELESS_AP_CONFIG	"/usr/syno/etc/wireless_ap.conf"
#define SZF_TMP_WIFI_SCHEDULER	"/tmp/synowifischeduler"

#define SZF_DEF_WIRELESS_AP_CONFIG	"/usr/syno/etc.defaults/wireless_ap.conf"
#define SZD_HOSTAP		"/etc/hostapd"
#define SZD_DEF_HOSTAP		"/etc.defaults/hostapd"
#define SZK_SUPPORT_PCI_WIFI	"support_pci_wifi"

/*
 * It's compatible with struct qelem in <search.h>
 * You may need to include <search.h> or implement your own insque/remque
 * when using it. Please refer to insque/remque manpages for more details.
 */
typedef struct _tag_WIRELESS_LIST_ {
	struct _tag_WIRELESS_LIST_* q_forw;
	struct _tag_WIRELESS_LIST_* q_back;
} WIRELESS_LIST;

#define LIST_HEAD_INIT(ptr)                        \
	do {                                             \
		(ptr)->q_forw = (ptr); (ptr)->q_back = (ptr);  \
	} while(0)

#define LIST_EMPTY(ptr) ((ptr)->q_forw == (ptr))

/**
 * insert a new entry after the specified head.
 */
#define LIST_ADD(ptr, head) insque(ptr, head)

/**
 * insert a new entry before the specified head.
 */
#define LIST_ADD_TAIL(ptr, head) insque(ptr, (head)->q_back)

/**
 * delete entry from list
 */
#define LIST_DEL(ptr) remque(ptr)

/**
 * get the structruct for this entry
 */
#define LIST_ENTRY(ptr, type, member) ({                         \
	const __typeof__(((type*)0)->member)*__mptr = (ptr);           \
	(type*)((char*)__mptr - OFFSET_OF(type, member));})

/**
 * iterate over a list of given type
 */
#define LIST_FOR_EACH_ENTRY(pos, head, member)                        \
	for (pos = LIST_ENTRY((head)->q_forw, __typeof__(*pos), member);    \
			&pos->member != (head);                                         \
			pos = LIST_ENTRY(pos->member.q_forw, __typeof__(*pos), member))

/**
 * iterate over a list safe against removal of list entry
 */
#define LIST_FOR_EACH_ENTRY_SAFE(pos, n, head, member)                   \
	for (pos = LIST_ENTRY((head)->q_forw, __typeof__(*pos), member),       \
			n = LIST_ENTRY(pos->member.q_forw, __typeof__(*pos), member);      \
			&pos->member != (head);                                            \
			pos = n, n = LIST_ENTRY(n->member.q_forw, __typeof__(*n), member))

#define LIST_FREE(head, type, member)                           \
	while (!LIST_EMPTY(head)) {                                   \
		type* __lptr = LIST_ENTRY((head)->q_forw, type, member);    \
		LIST_DEL((head)->q_forw);                                   \
		free(__lptr);                                               \
	}

#define SZV_DHCP                       "DHCP"
#define SZF_WIRELESS_CONFIG            "/usr/syno/etc/wireless.conf"
#define SZF_WIRELESS_CONNECTING        "/var/tmp/.wireless_connecting"
#define SZF_WIRELESS_INFO			   "/tmp/wireless.info"
#define SZF_USBMODEM_INFO              "/tmp/usbmodem.info"
#define WIRELESS_ESSID_LENGTH_MAX      32
#define WIRELESS_ESSID_LENGTH_MIN      1
#define WIRELESS_BSSID_LENGTH          6
#define WIRELESS_KEY_LENGTH_MAX        256
#define WIRELESS_KEY_LENGTH_MIN        8
#define WIRELESS_ROUTUNG_METRIC        0                   // Prepare for multiple gateways
#define MAX_WPA_EAP_USER_LEN           256

typedef enum _tag_WIRELESS_PROTOCOL_ {
	WIRELESS_PROTO_UNKNOWN,
	WIRELESS_PROTO_LEGACY_11BG,
	WIRELESS_PROTO_LEGACY_11B,
	WIRELESS_PROTO_LEGACY_11A,
	WIRELESS_PROTO_LEGACY_11ABG,
	WIRELESS_PROTO_LEGACY_11G,
	WIRELESS_PROTO_11ABGN,
	WIRELESS_PROTO_11N,
	WIRELESS_PROTO_11GN,
	WIRELESS_PROTO_11AN,
	WIRELESS_PROTO_11BGN,
	WIRELESS_PROTO_11AGN,
	WIRELESS_PROTO_11BN,
} WIRELESS_PROTOCOL;

typedef enum _tag_WIRELESS_AUTH_ {
	WIRELESS_AUTH_UNKNOWN,
	WIRELESS_AUTH_OPEN,                                       // For open system
	WIRELESS_AUTH_SHARED,                                     // For shared key system
	WIRELESS_AUTH_WEPAUTO,                                    // Auto switch between OPEN and SHARED
	WIRELESS_AUTH_WPAPSK,                                     // For WPA pre-shared key  (Infra)
	WIRELESS_AUTH_WPA2PSK,                                    // For WPA2 pre-shared key (Infra)
	WIRELESS_AUTH_WPANONE,                                    // For WPA pre-shared key  (Adhoc)
	WIRELESS_AUTH_WPAEAP,                                     // For WPA EAP
	WIRELESS_AUTH_WPA2EAP,                                    // For WPA2 EAP
} WIRELESS_AUTH;

typedef enum _tag_WIRELESS_ENCRYPT_ {
	WIRELESS_ENCRYPT_UNKNOWN	= 0x00,
	WIRELESS_ENCRYPT_NONE		= 0x01,                                    // For AuthMode=OPEN
	WIRELESS_ENCRYPT_WEP		= 0x02,                                    // For AuthMode=OPEN or SHARED
	WIRELESS_ENCRYPT_TKIP		= 0x04,                                    // For AuthMode=WPAPSK or WPAPSK2
	WIRELESS_ENCRYPT_AES		= 0x08,                                    // For AuthMode=WPAPSK or WPAPSK2
} WIRELESS_ENCRYPT;

/* Please see linux/wireless.h for Modes of operation ex.IW_MODE_XXX */
typedef enum _tag_WIRELESS_OPMODE_ {
	WIRELESS_OPMODE_AUTO = IW_MODE_AUTO,
	WIRELESS_OPMODE_ADHOC,
	WIRELESS_OPMODE_MANAGED,                                  // Managed mode = Infrastructure mode
	WIRELESS_OPMODE_MASTER,                                   // Master mode = AP mode
	WIRELESS_OPMODE_REPEATER,
	WIRELESS_OPMODE_SECONDEARY,
	WIRELESS_OPMODE_MONITOR,
	WIRELESS_OPMODE_UNKNOWN,
	WIRELESS_OPMODE_MAX,
} WIRELESS_OPMODE;

typedef enum _tag_WIRELESS_SCAN_ {
	WIRELESS_SCAN_LAST,
	WIRELESS_SCAN_RENEW,
} WIRELESS_SCAN;

typedef enum _tag_WIRELESS_FILTER_ {
	WIRELESS_FILTER_ESSID,
	WIRELESS_FILTER_BSSID,
} WIRELESS_FILTER;

typedef enum _tag_WIRELESS_STATUS_ {
	WIRELESS_STATUS_UNKNOWN,
	WIRELESS_STATUS_NOT_SUPPORTED,
	WIRELESS_STATUS_NO_ADAPTER,
	WIRELESS_STATUS_DOWN,
	WIRELESS_STATUS_DISCONNECTED,
	WIRELESS_STATUS_CONNECTED_MANAGED,
	WIRELESS_STATUS_CONNECTED_ADHOC,
	WIRELESS_STATUS_MONITOR,                                  // RT2870 doesn't support it
} WIRELESS_STATUS;

typedef enum _tag_WIRELESS_REQUEST {
	REQUEST_ESSID,
	REQUEST_PROTOCOL,
	REQUEST_AUTH,
	REQUEST_MODE,
	REQUEST_STATUS,
} WIRELESS_REQUEST;

typedef union _tag_WIRELESS_INFO {
	char                szEssid[WIRELESS_ESSID_LENGTH_MAX + 1];
	WIRELESS_PROTOCOL   protocol;
	WIRELESS_AUTH       auth;
	WIRELESS_OPMODE     opmode;
	WIRELESS_STATUS     status;
} WIRELESS_INFO, *PWIRELESS_INFO;

typedef struct _tag_WIRELESS_LITERAL_MAPPING_ {
	const char*             str;
	union {
		WIRELESS_PROTOCOL   protocol;
		WIRELESS_AUTH       auth;
		WIRELESS_ENCRYPT    encrypt;
		WIRELESS_OPMODE     opmode;
	}                       type;
} WIRELESS_LITERAL_MAPPING;

typedef struct _tag_WIRELESS_NETWORK_ {
	/* Extended network name. 0-z,1-32 ascii code */
	char                    szEssid[WIRELESS_ESSID_LENGTH_MAX + 1];
	/* MAC Address */
	unsigned char           bssid[WIRELESS_BSSID_LENGTH];
	int                     channel;
	int                     signal;
	WIRELESS_OPMODE         opmode;
	WIRELESS_PROTOCOL       protocol;
	WIRELESS_AUTH           auth;
	WIRELESS_ENCRYPT        encrypt;
	WIRELESS_LIST           list;
} WIRELESS_NETWORK;

typedef struct _tag_WIRELESS_NETWORK_CONFIG_ {
	char                    szKey[WIRELESS_KEY_LENGTH_MAX + 1];
	char                    szIp[CB_SZ_IP_MAX];
	char                    szMask[CB_SZ_IP_MAX];
	char                    szGateway[CB_SZ_IP_MAX];
	time_t                  atime;
	WIRELESS_NETWORK        network;
	WIRELESS_LIST           list;
	int                     noneBssid;
	/* For WPA1/WPA2 Enterprise*/
	char                    szUser[MAX_WPA_EAP_USER_LEN + 1];
} WIRELESS_NETWORK_CONFIG;

typedef struct _tag_WIRELESS_REPORT_ {
	WIRELESS_STATUS         status;
	/* if status is WIRELESS_STATUS_CONNECTED_MANAGED,
	 * network will contain needed information */
	WIRELESS_NETWORK        network;
} WIRELESS_REPORT;

/**
 * This is for yota wimax define.
 *
 */
#ifndef SYNO_YOTAWIMAX_ETHERNET_NAME
#define WIMAX_INTERFACE_NAME        "wm0"
#else
#define WIMAX_INTERFACE_NAME        SYNO_YOTAWIMAX_ETHERNET_NAME"0"
#endif

/**
 * This is for wifi ap.
 *
 */
#define SZ_WIRELESS_IF				SZ_DEFAULT_WIRELESS_IF
#define SZ_AP_START_CMD				"start-ap"
#define SZ_AP_STOP_CMD				"stop-ap"
#define WIFI_SCHED_NUM			(7 * 24)
#define MAX_WIFI_SCHED_LEN 		(WIFI_SCHED_NUM + 1)
#define CH_SCHED_WIFI_OFF 		'0'
#define CH_SCHED_WIFI_ON 		'1'
#define WIFI_SCHED_ALL_ON		-1
#define WIFI_SCHED_ALL_OFF 		-2
#define MAX_SECTION_NAME_LEN		32
#define MAX_SSID_LEN				128
#define MAX_WEP_NUM					4
#define MAX_WEP_PWD_LEN				1024
#define MAX_WPA_PSK_PWD_LEN			256
#define MAX_WPA_EAP_SECRET_LEN		128
#define SZF_WIRELESS_AP_CONNECTING		"/var/tmp/.wireless_ap_connecting"
#define SZF_TMP_WIRELESS_AP_CONFIG		"/tmp/wireless_ap.conf"
#define SZF_WIFI_SCHEDULER			"/usr/syno/sbin/synowifischeduler"

#define SZF_AP_PREFIX					SZD_HOSTAP"/hostapd-"

#define SZ_WIRELESS_AP_CONFIG_SEC_NAME_FORMAT "%s:%s"
#define SZK_TXPOWER				"txpower"
#define SZK_SSID				"ssid"
#define SZK_HIDE_SSID			"ignore_broadcast_ssid"
#define SZK_MAC_ADDR_ACL		"macaddr_acl"
#define SZK_HW_MODE				"hw_mode"
#define SZK_REQUIRE_HT				"require_ht"
#define SZK_INTERFACE			"interface"
#define SZK_DRIVER				"driver"
#define SZK_AUTH_ALGS			"auth_algs"
#define	SZK_CHANNEL				"channel"
#define	SZK_BRIDGE				"bridge"
#define SZK_WIFI_SCHED			"wifi_sched"
#define SZK_WIFI_SCHED_ENABLED		"wifi_sched_enabled"
#define SZK_MAX_NUM_STA			"max_num_sta"

// For 802.11n
#define SZK_WMM					"wmm_enabled"
#define	SZK_IEEE_80211N			"ieee80211n"
#define	SZK_HT_CAPAB			"ht_capab"
#define SZK_WIRELESS_WIDTH		"ieee80211n_wireless_width"
#define SZV_HOSTAP_DRIVER		"nl80211"
#define SZV_MAC_ADDR_ACL		"0"
#define SZV_CHANNEL_24MHZ		24
#define SZV_CHANNEL_57MHZ		57
#define SZK_ENCRYPTION			"encryption"
//for wep
#define SZK_WEP_DEF_KEY			"wep_default_key"
#define SZK_WEP_KEY				"wep_key0"
//for wpa_psk in hostapd.conf
#define SZK_WPA					"wpa"
#define SZK_WPA_PASSPHRASE		"wpa_passphrase"
#define SZK_WPA_KEY_MGNT		"wpa_key_mgmt"
#define SZK_WPA_ENCRYPT_TYPE	"wpa_encrypt_type"
#define SZK_WPA_PAIRWISE		"wpa_pairwise"
#define SZK_RSN_PAIRWISE		"rsn_pairwise"

//for 802.1X
#define SZK_IEEE_8021X			"ieee8021x"
#define SZK_AUTH_IP				"auth_server_addr"
#define SZK_AUTH_PORT			"auth_server_port"
#define SZK_AUTH_SHARED_SECRET	"auth_server_shared_secret"
#define SZV_IEEE_8021X			1

#define SZV_WPA_EAP				"WPA-EAP"
#define SZV_WPA_PSK				"WPA-PSK"
#define SZV_WPA_ALGO_TKIP		"TKIP"
#define	SZV_WPA_ALGO_CCMP		"CCMP"
#define SZV_WPA_ALGO_TKIP_CCMP	"TKIP CCMP"
#define SZV_HW_MODE_80211A		"a"
#define SZV_HW_MODE_80211B		"b"
#define SZV_HW_MODE_80211G		"g"
#define SZV_HT_CAPAB_20MHZ		"[SHORT-GI-20][DELAYED-BA]"
#define SZV_HT_CAPAB_40MHZ		SZV_HT_CAPAB_20MHZ"[SHORT-GI-40][MAX-AMSDU-7935]"
#define SZV_HT40_PLUS			"[HT40+]"
#define SZV_HT40_MINUS			"[HT40-]"

#define SZV_DEF_WEP_KEY				0
#define SZV_AUTH_OPEN				1
#define SZV_AUTH_ENCRYPTION			2

#define SZK_AP_WPA_PSK_KEY				"wpa_psk_file"
#define SZV_AP_WPA_PSK					"/etc/hostapd.psk"
#define SZK_AP_WPS_STATE_KEY			"wps_state"
#define SZV_AP_WPS_STATE				2
#define SZK_AP_SETUP_LOCKED_KEY			"ap_setup_locked"
#define SZV_AP_SETUP_LOCKED				1
#define SZK_AP_CTRL_INTERFACE_KEY		"ctrl_interface"
#define SZV_AP_CTRL_INTERFACE			"/var/run/hostapd"
#define SZK_AP_EAP_SERVER_KEY			"eap_server"
#define SZV_AP_EAP_SERVER				1
#define SZV_AP_EXTERNAL_EAP_SERVER		0
#define SZK_AP_WPS_CONFIG_METHOD_KEY	"config_methods"
#define SZV_AP_WPS_CONFIG_METHOD		"label display push_button keypad"

// For guest network
#define GUEST_NET_PREFIX 		"guest_net_"
#define SZK_GUEST_NET_ENABLE		GUEST_NET_PREFIX "enable"
#define SZK_GUEST_NET_SSID		GUEST_NET_PREFIX SZK_SSID
#define SZK_GUEST_NET_HIDE_SSID		GUEST_NET_PREFIX SZK_HIDE_SSID
#define SZK_GUEST_NET_MAX_NUM_STA	GUEST_NET_PREFIX SZK_MAX_NUM_STA
#define SZK_GUEST_NET_BSS		"bss"
#define SZK_GUEST_NET_BSSID		"bssid"
#define SZK_GUEST_NET_AP_ISOLATE	"ap_isolate"
#define SZV_GUEST_NET_AP_ISOLATE	1
#define SZK_GUEST_NET_LAN_BLOCK		GUEST_NET_PREFIX "lan_block"
#define SZK_GUEST_NET_ACCESS_DS		GUEST_NET_PREFIX "access_ds"
#define SZK_GUEST_NET_INTERNET_BLOCK	GUEST_NET_PREFIX "internet_block"
#define SZK_GUEST_NET_ALLOW_HTTP	GUEST_NET_PREFIX "allow_http"
#define SZK_GUEST_NET_SCHED		GUEST_NET_PREFIX "sched"
#define SZK_GUEST_NET_SCHED_ENABLE	GUEST_NET_PREFIX "sched_enable"
// For guest network security
#define SZK_GUEST_NET_ENCRYPTION		GUEST_NET_PREFIX  SZK_ENCRYPTION
#define SZK_GUEST_NET_WEP_KEY			GUEST_NET_PREFIX  SZK_WEP_KEY
#define SZK_GUEST_NET_WPA_PASSPHRASE    	GUEST_NET_PREFIX  SZK_WPA_PASSPHRASE
#define SZK_GUEST_NET_WPA               	GUEST_NET_PREFIX  SZK_WPA
#define SZK_GUEST_NET_WPA_ENCRYPT_TYPE  	GUEST_NET_PREFIX  SZK_WPA_ENCRYPT_TYPE
#define SZK_GUEST_NET_WPA               	GUEST_NET_PREFIX  SZK_WPA
#define SZK_GUEST_NET_WPA_ENCRYPT_TYPE  	GUEST_NET_PREFIX  SZK_WPA_ENCRYPT_TYPE
#define SZK_GUEST_NET_AUTH_IP           	GUEST_NET_PREFIX  SZK_AUTH_IP
#define SZK_GUEST_NET_AUTH_PORT         	GUEST_NET_PREFIX  SZK_AUTH_PORT
#define SZK_GUEST_NET_AUTH_SHARED_SECRET	GUEST_NET_PREFIX  SZK_AUTH_SHARED_SECRET

typedef enum _tag_SYNO_AP_ENCRYPT {
	AP_ENCRYPT_OPEN,
	AP_ENCRYPT_WEP,
	AP_ENCRYPT_WPA_PSK,
	AP_ENCRYPT_WPA_EAP,
	AP_ENCRYPT_MAX
} SYNO_AP_ENCRYPT;

typedef enum _tag_SYNO_AP_WPA_PSK_TYPE {
	TYPE_WPA = 0x1,
	TYPE_WPA2 = 0x2,
} SYNO_AP_WPA_PSK_TYPE;

typedef enum _tag_SYNO_AP_MODE {
	AP_MODE_80211A = 0x1,
	AP_MODE_80211B = 0x2,
	AP_MODE_80211G = 0x4,
	AP_MODE_80211N = 0x8,
} SYNO_AP_MODE;

typedef enum _tag_SYNO_AP_FREQ {
	AP_FREQ_20_MHZ = 0x1,
	AP_FREQ_40_MHZ = 0x2,
	AP_FREQ_ALL = (AP_FREQ_20_MHZ | AP_FREQ_40_MHZ),
} SYNO_AP_FREQ;

typedef enum _tag_SYNO_AP_WPA_ENCRYPT_TYPE {
	TYPE_TKIP = 1,
	TYPE_CCMP,
	TYPE_TKIP_CCMP,
} SYNO_AP_WPA_ENCRYPT_TYPE;

typedef struct _tag_SYNO_HOSTAP_WPA_PSK_INFO {
	int wpaType;
	char szPassPhrase[MAX_WPA_PSK_PWD_LEN];
	int encryptType;
} SYNO_HOSTAP_WPA_PSK_INFO, *PSYNO_HOSTAP_WPA_PSK_INFO;

typedef struct _tag_SYNO_HOSTAP_WPA_EAP_INFO {
	int wpaType;
	int encryptType;
	char szAuthIP[CB_SZ_IP_MAX];
	int authPort;
	char szAuthSharedSecret[MAX_WPA_EAP_SECRET_LEN];
} SYNO_HOSTAP_WPA_EAP_INFO;

typedef union _tag_SYNO_HOSTAP_ENCRYPT_INFO{
	char szWepPwd[MAX_WEP_PWD_LEN];
	SYNO_HOSTAP_WPA_PSK_INFO wpaPskInfo;
	SYNO_HOSTAP_WPA_EAP_INFO wpaEapInfo;
} SYNO_HOSTAP_ENCRYPT_INFO, *PSYNO_HOSTAP_ENCRYPT_INFO;

typedef struct _tag_SYNO_AP_Access_Rule {
	BOOL blLanBlock;
	BOOL blAccessDS;
	BOOL blInternetBlock;
	BOOL blAllowHttp;
} SYNO_AP_ACCESS_RULE;

typedef struct _tag_SYNO_HOSTAP_Guest_Net {
	BOOL	blEnable;
	char szSSID[MAX_SSID_LEN];
	char szBSSID[MAX_SSID_LEN];
	int hideSSID;
	int maxStation;
	BOOL blAPIsolate;
	SYNO_AP_ENCRYPT encryption;
	SYNO_HOSTAP_ENCRYPT_INFO encryptInfo;
} SYNO_HOSTAP_GUEST_NET, *PSYNO_HOSTAP_GUEST_NET;

typedef struct _tag_SYNO_HOSTAP_CONF {
	char szSSID[MAX_SSID_LEN];
	char szBridge[SYNO_IFNAME_MAX];
	int hideSSID;
	int hwMode;
	int ieee80211n;
	int wirelessWidth;
	int channel;
	int maxStation;
	int wmm;
	SYNO_AP_ENCRYPT	encryption;
	SYNO_HOSTAP_ENCRYPT_INFO encryptInfo;
	SYNO_HOSTAP_GUEST_NET guestNet;
} SYNO_HOSTAP_CONF, *PSYNO_HOSTAP_CONF;

typedef struct _tag_SYNO_WIFI_SCHED_CONF {
	char szWifiSched[MAX_WIFI_SCHED_LEN];
	int wifiSchedEnabled;
} SYNO_WIFI_SCHED_CONF, *PSYNO_WIFI_SCHED_CONF;

typedef struct _tag_SYNO_AP_INFO {
	BOOL	blEnable;
	int		txpower;
	char	szSecName[MAX_SECTION_NAME_LEN];
	SYNO_HOSTAP_CONF hostapConf;
	BOOL	blWifiUnblock;
	SYNO_WIFI_SCHED_CONF wifiSchedConf;
	SYNO_WIFI_SCHED_CONF guestNetSchedConf;
	SYNO_AP_ACCESS_RULE guestNetAccessRule;
} SYNO_AP_CONF, *PSYNO_AP_CONF;

__END_DECLS;

#endif // _SYNO_WIRELESS_H_
