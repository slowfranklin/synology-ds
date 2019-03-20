/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent_ap.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentHostapd : public AdapterAgentAP {
public:
	virtual int Enable(const AdapterConfig &config) = 0;
	virtual int Disable(const AdapterConfig &config) = 0;
	virtual int Recover(const AdapterConfig &config) = 0;
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status) = 0;

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const = 0;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);
	virtual int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList);
	virtual int EnableWPSWithPBC();
	virtual int EnableWPSWithPinCode(const std::string &strPin);
	virtual bool SetCountryCodeImpl(const std::string &code) const;

protected:
	AdapterAgentHostapd();
	virtual ~AdapterAgentHostapd();

	virtual int GenerateMacFilterConfig(const AdapterConfig &config);
	virtual int GenerateHostapdConfig(const AdapterConfig &config);
	virtual int EnableAP(const AdapterConfig &config);
	virtual int DisableAP(const AdapterConfig &config);
	virtual int SetTXPower(const AdapterConfig &config);
private:
	/* Following functions/c'tor should not be called */
	AdapterAgentHostapd &operator=(const AdapterAgentHostapd &);

}; /* clase AdapterAgentHostapd */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_HPP_ */
