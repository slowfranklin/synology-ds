/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_HPP_

#include <fstream>

#include <string>

#include <synowireless/wifi/adapter_agent_ap.hpp>
#include <synowireless/utils/ip_address.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentRLT : public AdapterAgentAP {
public:
	virtual int Enable(const AdapterConfig &config);
	virtual int Disable(const AdapterConfig &config);
	virtual int Recover(const AdapterConfig &config);
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status);

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);
	virtual int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList);
	virtual int EnableWPSWithPBC();
	virtual int EnableWPSWithPinCode(const std::string &strPin);

protected:
	AdapterAgentRLT();
	virtual ~AdapterAgentRLT();

	virtual int GenerateMacFilterConfig(const AdapterConfig &config);
	virtual int GenerateRLTConfig(const AdapterConfig &config);
	virtual int EnableAP(const AdapterConfig &config);
	virtual int DisableAP(const AdapterConfig &config);
	virtual int EnableAPGuest(const AdapterConfig &config);
	virtual int DisableAPGuest(const AdapterConfig &config);
	virtual int SetTXPower(const AdapterConfig &config);
	virtual int ResetBridgeIP(const AdapterConfig &config);

	virtual std::string GetWanIfName() = 0;

private:
	int SetAuth(const AdapterConfig &config, std::ofstream &conf);
	int SetAuthDetail(const AdapterConfig &config, std::ofstream &conf);
	synowireless::utils::IPAddress GetWanIPAddress();
	int ReloadKernelModule();

private:
	bool blAPEnabled;
	bool blAPGuestEnabled;
private:
	/* Following functions/c'tor should not be called */
	AdapterAgentRLT &operator=(const AdapterAgentRLT &);

}; /* clase AdapterAgentRLT */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_HPP_ */
