/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_OVS_BRIDGE_HPP_
#define _SYNO_WIRELESS_WIFI_OVS_BRIDGE_HPP_

#include <synowireless/wifi/bridge_base.hpp>

namespace synowireless {
namespace wifi {

class OVSBridge : public BridgeBase {
public:
	int CreateConfig();
	int DisableTopology();
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
	int AddSlaveEth();
	int AddSlaveWlan();
	int AddSlaveGwlan();
	int RemoveSlaveEth();
	int RemoveSlaveWlan();
	int RemoveSlaveGwlan();

	~OVSBridge();

private:
	OVSBridge(const std::string &strName);

	/* Following functions c'tor should not be called */
	BridgeBase &operator=(const BridgeBase &);

	friend class BridgeBase;
}; /* clase OVSBridge */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_OVS_BRIDGE_HPP_ */
