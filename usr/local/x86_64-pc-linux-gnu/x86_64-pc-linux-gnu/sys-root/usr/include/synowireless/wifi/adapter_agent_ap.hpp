/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_AP_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_AP_HPP_

#include <string>
#include <json/value.h>

#include <synowireless/wifi/adapter_agent.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentAP : public AdapterAgent {
public:
	/* static methods */
	static bool SetCountryCode(const std::string &code);
	static std::string GetCountryCode();
	static Json::Value ListCountryCode();
	static bool InitCountryCode();
	/* common operations */
	virtual int Enable(const AdapterConfig &config) = 0;
	virtual int Disable(const AdapterConfig &config) = 0;
	virtual int Recover(const AdapterConfig &config) = 0;
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status) = 0;

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const = 0;
	virtual int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList) = 0;
	virtual int EnableWPSWithPBC() = 0;
	virtual int EnableWPSWithPinCode(const std::string &strPin) = 0;
	virtual bool SetCountryCodeImpl(const std::string &code) const;

protected:
	AdapterAgentAP();
	virtual ~AdapterAgentAP();

	virtual int EnableAP(const AdapterConfig &config) = 0;
	virtual int DisableAP(const AdapterConfig &config) = 0;
	virtual int SetTXPower(const AdapterConfig &config) = 0;

	virtual int EnableRuleGuest(const AdapterConfig &config);
	virtual int DisableRuleGuest(const AdapterConfig &config);
	virtual int SetSchedule(const AdapterConfig &config);
	virtual int RemoveSchedule(const AdapterConfig &config);
private:
	/* Following functions/c'tor should not be called */
	AdapterAgentAP &operator=(const AdapterAgentAP &);

}; /* clase AdapterAgentAP */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_AP_HPP_ */
