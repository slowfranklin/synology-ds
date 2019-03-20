/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ENUM_HPP_
#define _SYNO_WIRELESS_WIFI_ENUM_HPP_

#include <string>
#include <map>

extern "C" {
#include <synocore/synoglobal.h>
}

#define SZV_ENUM_ERROR			"error"

/* WIFI_FEATURE */
#define SZV_FEATURE_MAC_FILTER			"mac_filter"
#define SZV_FEATURE_GUEST_NETWORK		"guest_network"
#define SZV_FEATURE_PARENTAL_CONTROL	"parental_control"
#define SZV_FEATURE_CONNECTION_LIST		"connection_list"

/* WIFI_DRIVER */
#define SZV_DRIVER_Nl80211		"nl80211"

/* WIFI_TOPOLOGY */
#define SZV_TOPOLOGY_NONE		"none"
#define SZV_TOPOLOGY_BRIDGE		"bridge"
#define SZV_TOPOLOGY_ROUTER		"router"
#define SZV_TOPOLOGY_CLIENT		"client"
#define SZV_TOPOLOGY_REPEATER	"repeater"

/* WIFI_MODE */
#define SZV_MODE_A				"a"
#define SZV_MODE_B				"b"
#define SZV_MODE_G				"g"
#define SZV_MODE_N				"n"
#define SZV_MODE_BN				"bn"
#define SZV_MODE_GN				"gn"
#define SZV_MODE_AN				"an"
#define SZV_MODE_BG				"bg"
#define SZV_MODE_BGN			"bgn"
#define SZV_MODE_AC				"ac"
#define SZV_MODE_ANAC			"an+ac"

#define SZV_RLT_WIFI_MODE_80211A			"11a"
#define SZV_RLT_WIFI_MODE_80211B			"11b"
#define SZV_RLT_WIFI_MODE_80211G			"11g"
#define SZV_RLT_WIFI_MODE_80211N			"11n"
#define SZV_RLT_WIFI_MODE_80211AN		"11a/n"
#define SZV_RLT_WIFI_MODE_80211BN		"11b/n"
#define SZV_RLT_WIFI_MODE_80211GN		"11g/n"
#define SZV_RLT_WIFI_MODE_80211BG		"11b/g"
#define SZV_RLT_WIFI_MODE_80211BGN		"11b/g/n"
#define SZV_RLT_WIFI_MODE_80211ANAC		"11a/n/ac"

/* WIFI_BANDWIDTH */
#define SZV_BANDWIDTH_20MHZ				"20MHZ"
#define SZV_BANDWIDTH_20_40MHZ			"20_40MHZ"
#define SZV_BANDWIDTH_20_40_80MHZ		"20_40_80MHZ"

/*  WIFI_POWER */
#define SZV_POWER_HIGH			"high"
#define SZV_POWER_MEDIUM		"medium"
#define SZV_POWER_LOW			"low"

/* WIFI_SECURITY */
#define SZV_SECURITY_DISABLED				"disabled"
#define SZV_SECURITY_WEP					"WEP"
#define SZV_SECURITY_PERSONAL_WPA			"PERSONAL_WPA"
#define SZV_SECURITY_PERSONAL_WPA2			"PERSONAL_WPA2"
#define SZV_SECURITY_PERSONAL_WPA_MIXED		"PERSONAL_WPA_MIXED"
#define SZV_SECURITY_ENTERPRISE_WPA			"ENTERPRISE_WPA"
#define SZV_SECURITY_ENTERPRISE_WPA2		"ENTERPRISE_WPA2"
#define SZV_SECURITY_ENTERPRISE_WPA_MIXED	"ENTERPRISE_WPA_MIXED"

/* WIFI_ENCRYPTION */
#define SZV_ENCRYPTION_NONE			"NONE"
#define SZV_ENCRYPTION_TKIP			"TKIP"
#define SZV_ENCRYPTION_AES			"AES"
#define SZV_ENCRYPTION_TKIP_AES		"TKIP_AES"

/* WIFI_OPMODE */
#define SZV_OPMODE_AUTO						"Auto"
#define SZV_OPMODE_ADHOC					"Ad-Hoc"
#define SZV_OPMODE_MANAGED					"Managed"
#define SZV_OPMODE_MASTER					"Master"
#define SZV_OPMODE_REPEATER					"Repeater"
#define SZV_OPMODE_SECONDEARY				"Secondary"
#define SZV_OPMODE_MONITOR					"Monitor"
#define SZV_OPMODE_MANAGED_RT2870_GET		"In"
#define SZV_OPMODE_ADHOC_RT2870_GET			"Ad"
#define SZV_OPMODE_MANAGED_RT2870_SHOW		"Infra"
#define SZV_OPMODE_ADHOC_RT2870_SHOW		"Adhoc"
#define SZV_OPMODE_MANAGED_RT2870_SHOW_ANY	"Any"

/* WIFI_STATUS */
#define SZV_STATUS_ENABLED					"Enabled"
#define SZV_STATUS_IP_CONFLICT				"IPConflict"
#define SZV_STATUS_IP_FAILED				"IPFailed"
#define SZV_STATUS_DISABLED					"Disabled"
#define SZV_STATUS_ENABLING					"Enabling"
#define SZV_STATUS_AUTOENABLING				"AutoEnabling"

/* WIFI_MAC_FILTER_POLICY */
#define SZV_MAC_FILTER_POLICY_DENY			"deny"
#define SZV_MAC_FILTER_POLICY_ALLOW			"allow"

namespace synowireless {
namespace wifi {

enum WIFI_FEATURE {
	WIFI_FEATURE_ERROR,
	WIFI_FEATURE_MAC_FILTER,
	WIFI_FEATURE_GUEST_NETWORK,
	WIFI_FEATURE_PARENTAL_CONTROL,
	WIFI_FEATURE_CONNECTION_LIST
};

enum WIFI_TYPE {
	WIFI_TYPE_ERROR,
	WIFI_TYPE_HOSTAPD
};

enum WIFI_STATUS {
	WIFI_STATUS_ERROR,
	WIFI_STATUS_ENABLED,
	WIFI_STATUS_IP_CONFLICT,
	WIFI_STATUS_IP_FAILED,
	WIFI_STATUS_DISABLED,
	WIFI_STATUS_ENABLING,
	WIFI_STATUS_AUTOENABLING
};

enum WIFI_TOPOLOGY {
	WIFI_TOPOLOGY_ERROR,
	WIFI_TOPOLOGY_BRIDGE,
	WIFI_TOPOLOGY_ROUTER,
	WIFI_TOPOLOGY_CLIENT,
	WIFI_TOPOLOGY_REPEATER
};

enum WIFI_MODE {
	WIFI_MODE_ERROR,
	WIFI_MODE_80211A,
	WIFI_MODE_80211B,
	WIFI_MODE_80211G,
	WIFI_MODE_80211N,
	WIFI_MODE_80211AN,
	WIFI_MODE_80211BN,
	WIFI_MODE_80211GN,
	WIFI_MODE_80211BG,
	WIFI_MODE_80211BGN,
	WIFI_MODE_80211AC,
	WIFI_MODE_80211ANAC
};

enum WIFI_BANDWIDTH {
	WIFI_BANDWIDTH_ERROR,
	WIFI_BANDWIDTH_20MHZ,
	WIFI_BANDWIDTH_20_40MHZ,
	WIFI_BANDWIDTH_20_40_80MHZ
};

enum WIFI_POWER {
	WIFI_POWER_ERROR,
	WIFI_POWER_HIGH = 10,
	WIFI_POWER_MEDIUM = 6,
	WIFI_POWER_LOW = 2
};

enum WIFI_DRIVER {
	WIFI_DRIVER_ERROR,
	WIFI_DRIVER_Nl80211
	// and others
};

enum WIFI_AUTHENTICATION_ALGORITHM {
	WIFI_AUTHENTICATION_ALGORITHM_ERROR,
	WIFI_AUTHENTICATION_ALGORITHM_OPEN,
	WIFI_AUTHENTICATION_ALGORITHM_SHARED
};

enum WIFI_SECURITY {
	WIFI_SECURITY_ERROR,
	WIFI_SECURITY_DISABLED,
	WIFI_SECURITY_WEP,
	WIFI_SECURITY_PERSONAL_WPA,
	WIFI_SECURITY_PERSONAL_WPA2,
	WIFI_SECURITY_PERSONAL_WPA_MIXED,
	WIFI_SECURITY_ENTERPRISE_WPA,
	WIFI_SECURITY_ENTERPRISE_WPA2,
	WIFI_SECURITY_ENTERPRISE_WPA_MIXED
};

enum WIFI_ENCRYPTION {
	WIFI_ENCRYPTION_ERROR,
	WIFI_ENCRYPTION_NONE,
	WIFI_ENCRYPTION_TKIP,
	WIFI_ENCRYPTION_AES,
	WIFI_ENCRYPTION_TKIP_AES
};

enum WIFI_MAC_FILTER_POLICY {
	WIFI_MAC_FILTER_POLICY_ERROR,
	WIFI_MAC_FILTER_POLICY_DENY,
	WIFI_MAC_FILTER_POLICY_ALLOW
};

// reference to linux/wireless.h IW_MODE_XXXXX
enum WIFI_OPMODE {
	WIFI_OPMODE_ERROR = -1,
	WIFI_OPMODE_AUTO = 0,
	WIFI_OPMODE_ADHOC = 1,
	WIFI_OPMODE_MANAGED = 2,                                  // Managed mode = Infrastructure mode
	WIFI_OPMODE_MASTER = 3,                                   // Master mode = AP mode
	WIFI_OPMODE_REPEATER = 4,
	WIFI_OPMODE_SECONDEARY = 5,
	WIFI_OPMODE_MONITOR = 6,
	WIFI_OPMODE_MESH = 7
};

enum WIFI_CLIENT_MODE_STATUS {
	WIFI_CLIENT_MODE_STATUS_ERROR,
	WIFI_CLIENT_MODE_STATUS_DISABLED,
	WIFI_CLIENT_MODE_STATUS_NO_ADAPTER,
	WIFI_CLIENT_MODE_STATUS_IFDOWN,
	WIFI_CLIENT_MODE_STATUS_ENABLED_ADHOC,
	WIFI_CLIENT_MODE_STATUS_ENABLED_MANAGED
};

bool CreateMap(std::map<std::string, WIFI_FEATURE> &map);
bool CreateMap(std::map<std::string, WIFI_STATUS> &map);
bool CreateMap(std::map<std::string, WIFI_DRIVER> &map);
bool CreateMap(std::map<std::string, WIFI_TOPOLOGY> &map);
bool CreateMap(std::map<std::string, WIFI_MODE> &map);
bool CreateMap(std::map<std::string, WIFI_BANDWIDTH> &map);
bool CreateMap(std::map<std::string, WIFI_POWER> &map);
bool CreateMap(std::map<std::string, WIFI_SECURITY> &map);
bool CreateMap(std::map<std::string, WIFI_ENCRYPTION> &map);
bool CreateMap(std::map<std::string, WIFI_OPMODE> &map);
bool CreateMap(std::map<std::string, WIFI_MAC_FILTER_POLICY> &map);

template<typename Type>
class EnumMap {
public:
	friend bool CreateMap(std::map<std::string, WIFI_FEATURE> &map);
	friend bool CreateMap(std::map<std::string, WIFI_STATUS> &map);
	friend bool CreateMap(std::map<std::string, WIFI_DRIVER> &map);
	friend bool CreateMap(std::map<std::string, WIFI_TOPOLOGY> &map);
	friend bool CreateMap(std::map<std::string, WIFI_MODE> &map);
	friend bool CreateMap(std::map<std::string, WIFI_BANDWIDTH> &map);
	friend bool CreateMap(std::map<std::string, WIFI_POWER> &map);
	friend bool CreateMap(std::map<std::string, WIFI_SECURITY> &map);
	friend bool CreateMap(std::map<std::string, WIFI_ENCRYPTION> &map);
	friend bool CreateMap(std::map<std::string, WIFI_OPMODE> &map);
	friend bool CreateMap(std::map<std::string, WIFI_MAC_FILTER_POLICY> &map);

	static void initializeMap()
	{
		if (!blInitialized) {
			blInitialized = CreateMap(enumMap);
		}
	}

	static std::string EnumToString(Type value)
	{
		typename std::map<std::string, Type>::iterator it;

		initializeMap();

		for (it = enumMap.begin(); enumMap.end() != it; it++) {
			if (it->second == value) {
				return it->first;
			}
		}

		return SZV_ENUM_ERROR;
	}

	static Type StringToEnum(const std::string &strValue)
	{
		typename std::map<std::string, Type>::iterator it;

		initializeMap();

		it = enumMap.find(strValue);
		if (enumMap.end() == it) {
			SYSLOG(LOG_ERR, "Failed to find key(%s)", strValue.c_str());
			return enumMap.find(SZV_ENUM_ERROR)->second;
		}

		return it->second;
	}

private:
	static bool blInitialized;
	static std::map<std::string, Type> enumMap;

private:
	EnumMap();
	~EnumMap();
};

template<typename Type> bool EnumMap<Type>::blInitialized = false;
template<typename Type> std::map<std::string, Type> EnumMap<Type>::enumMap;

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ENUM_HPP_ */
