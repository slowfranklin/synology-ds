/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_BRIDGE_CONFIG_HPP_
#define _SYNO_WIRELESS_WIFI_BRIDGE_CONFIG_HPP_

#include <string>
#include <vector>

#include <synowireless/utils/ip_address.hpp>

namespace synowireless {
namespace wifi {

struct BridgeConfig {
	synowireless::utils::IPAddress ip;
	synowireless::utils::IPAddress netmask;
	bool blDHCPEnabled;
	synowireless::utils::IPAddress dhcpRangeBegin;
	synowireless::utils::IPAddress dhcpRangeEnd;
	std::string v6prefix;
	std::string v6pdns;
	std::string v6sdns;
	std::string dhcpv6Type;
	std::string dhcpv6RangeBegin;
	std::string dhcpv6RangeEnd;
	std::vector<std::string>  slaveList;
}; /* struct BridgeConfig */

} /* namespace wifi */
} /* namespace synowireless */

#endif
