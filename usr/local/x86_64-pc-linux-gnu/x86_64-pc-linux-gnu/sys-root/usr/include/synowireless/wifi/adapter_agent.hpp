/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HPP_

#include <string>
#include <vector>
#include <synowireless/wifi/utils.hpp>
#include <synowireless/wifi/enum.hpp>
#include <synowireless/wifi/adapter_config.hpp>
#include <synowireless/wifi/adapter_data.hpp>

namespace synowireless {
namespace wifi {

class AdapterConfig;

class AdapterAgent {
public:
	static AdapterAgent *Create(const AdapterConfig &Config);
	static int Delete(const AdapterAgent *pAgent);
	virtual int Enable(const AdapterConfig &config) = 0;
	virtual int Recover(const AdapterConfig &config) = 0;
	virtual int Disable(const AdapterConfig &config) = 0;
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status) = 0;

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const = 0;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList) = 0;
	virtual int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList) = 0;
	virtual int EnableWPSWithPBC() = 0;
	virtual int EnableWPSWithPinCode(const std::string &strPin) = 0;
	virtual bool SetCountryCodeImpl(const std::string &code) const;

protected:
	AdapterAgent();
	virtual ~AdapterAgent();

	std::string _strIfName;

private:
	/* Following functions/c'tor should not be called */
	AdapterAgent &operator=(const AdapterAgent &);

}; /* clase AdapterAgent */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HPP_ */
