/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_LOCAL_BRIDGE_HPP_
#define _SYNO_WIRELESS_WIFI_LOCAL_BRIDGE_HPP_

#include <synowireless/wifi/bridge_base.hpp>

namespace synowireless {
namespace wifi {

class LocalBridge : public BridgeBase {
public:
	int CreateConfig();
	int EnableNat();
	int DisableNat();
	int EnableDhcp();
	int DisableDhcp();
	int EnableDhcpv6();
	int DisableDhcpv6();
	int EnableSecurityConf();
	int DisableSecurityConf();
	int ResetBridgeIP();
	int SetTopologyFile(const BridgeConfig &config);
	int CreateGatewayInfo();
	int ResetGatewayInfo();

	~LocalBridge();

private:
	LocalBridge(const std::string &strName);

	/* Following functions c'tor should not be called */
	LocalBridge &operator=(const LocalBridge &);

	friend class BridgeBase;
}; /* clase LocalBridge */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_LOCAL_BRIDGE_HPP_ */
