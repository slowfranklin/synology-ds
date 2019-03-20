/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_CONFIG_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_CONFIG_HPP_

#include <cstring>
#include <string>
#include <vector>

#include <synowireless/wifi/enum.hpp>
#include <synowireless/utils/ip_address.hpp>
#include <synowireless/utils/mac_address.hpp>

namespace synowireless {
namespace wifi {

struct AdapterConfig {
	static const unsigned int HOURS_PER_DAY = 24;
	static const unsigned int DAYS_PER_WEEK = 7;
	static const unsigned int HOURS_PER_WEEK = HOURS_PER_DAY * DAYS_PER_WEEK;

	/* General */
	std::string strIfName;
	synowireless::utils::MacAddress bssid;
	WIFI_DRIVER driver;

	/* AP */
	bool blAPEnabled;
	std::string strSSID;
	bool blDisplaySSID;
	WIFI_MODE mode;
	WIFI_BANDWIDTH bandwidth;
	unsigned int channel;
	WIFI_POWER power;
	unsigned int maxNumClient;
	bool blWMMEnabled;
	bool blSchedulerEnabled;
	bool rgblScheduler[HOURS_PER_WEEK];
	bool blIsPCIInterface;

	/* For rlt_wifi */
	std::string strCountryCode;
	unsigned int countryRegion;
	unsigned int countryRegionABand;

	/* Security */
	WIFI_SECURITY security;
	WIFI_ENCRYPTION encryption;
	std::string strPassword;

	/* Authentication Server Info*/
	synowireless::utils::IPAddress authServerIP;
	unsigned int authServerPort;
	std::string strAuthServerSharedSecret;

	/* Guest network */
	bool blGuestNetworkSupport;
	bool blGuestNetworkEnabled;
	std::string strGuestNetworkSSID;
	bool blDisplayGuestNetworkSSID;
	synowireless::utils::MacAddress guestNetBssid;
	unsigned int maxNumGuestNetworkClient;
	WIFI_SECURITY guestNetworkSecurity;
	WIFI_ENCRYPTION guestNetworkEncryption;
	std::string strGuestNetworkPassword;
	bool blAllowGuestAccessGuest;
	bool blAllowGuestAccessLan;
	bool blAllowGuestAccessHttpAndHttpsOnly;
	bool blGuestSchedulerEnabled;
	bool rgblGuestScheduler[HOURS_PER_WEEK];

	/* MAC filter */
	struct MacFilterRule {
		bool blMacFilterEnabled;
		synowireless::utils::MacAddress macAddress;
		std::string strDescription;

		bool operator==(const MacFilterRule &rule) const {
			if ((blMacFilterEnabled == rule.blMacFilterEnabled) &&
				(macAddress == rule.macAddress) &&
				(strDescription == rule.strDescription)) {
				return true;
			}

			return false;
		}
		bool operator!=(const MacFilterRule &rule) const {
			return !(*this == rule);
		}

	};

	WIFI_MAC_FILTER_POLICY macFilterPolicy;
	std::vector<MacFilterRule> macFilterList;

	/* Client */
	bool blClientEnabled;
	struct StationInfo {
		std::string strESSID;
		synowireless::utils::MacAddress strBSSID;
		WIFI_OPMODE opmode;
		WIFI_SECURITY security;
		WIFI_ENCRYPTION encryption;
		std::string strUser;
		std::string strPassword;
		unsigned int accessTime;
		bool blIsDHCP;
		synowireless::utils::IPAddress ipAddress;
		synowireless::utils::IPAddress netmask;
		synowireless::utils::IPAddress gateway;

		// for scan network used
		int iScanChannel;
		int iScanSignal;
		WIFI_MODE hwmode;
	};

	std::vector<StationInfo> stationList;
}; /* clase AdapterConfig */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_CONFIG_HPP_ */
