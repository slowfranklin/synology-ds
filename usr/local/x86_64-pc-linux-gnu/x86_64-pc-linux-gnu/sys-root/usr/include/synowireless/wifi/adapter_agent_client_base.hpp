/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_BASE_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_BASE_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentClientBase : public AdapterAgent {
public:
	virtual int Enable(const AdapterConfig &config);
	virtual int Recover(const AdapterConfig &config);
	virtual int Disable(const AdapterConfig &config);
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status);

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const = 0;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList) = 0;
	virtual int QuickScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList) = 0;
	virtual int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList);
	virtual int EnableWPSWithPBC();
	virtual int EnableWPSWithPinCode(const std::string &strPin);
	virtual bool SetCountryCodeImpl(const std::string &code) const;

protected:
	AdapterAgentClientBase();
	virtual ~AdapterAgentClientBase();

	WIFI_CLIENT_MODE_STATUS GetConnectionStatus(const std::string &strIfName);
	WIFI_CLIENT_MODE_STATUS GetConnectionStatusManaged(const std::string &strIfName);
	WIFI_OPMODE GetOpmode(const std::string &strIfName);
	int SetOpmode(const std::string &strIfName, const WIFI_OPMODE opmode);
	int DelGatewayInfo(const std::string strIfName);

	// for ad-hoc
	bool DoCreateAdHoc(const AdapterConfig &config);
	int GetAdHocConfig(const AdapterConfig &config);

	// for client
	virtual int GetClientConfig(const AdapterConfig &config);
	virtual int ClientEnable(const AdapterConfig &config);
	virtual int ClientRecover(const AdapterConfig &config);
	virtual int ClientDisable(const AdapterConfig &config);

	// variables from config object
	synowireless::wifi::AdapterConfig::StationInfo _siCurrentInfo;

	// control status
	bool _blIPConflict;
	bool _blIPSetFailed;
	bool _blDoAutoConnect;

	virtual int AdHocEnable(const AdapterConfig &config) = 0;
	virtual int AdHocRecover(const AdapterConfig &config) = 0;
	virtual int AdHocDisable(const AdapterConfig &config) = 0;

	virtual int DoConnecting() = 0;
	virtual int DoDisconnect() = 0;

	// service restart's private function
	void PreNetServiceRestart();
	void PostNetServiceRestart();
	int Redirect2WiredInterfaces();

	int ParseSecurityEncryption(const std::string &strIn, WIFI_SECURITY &security, WIFI_ENCRYPTION &encryption);
	int SetInfraIPAddress();
	bool NoIPConflict();
	int SetIPAddress();
	int SetAdhocIPAddress();
	int UpdateAPConnectionList();
	int DisconnectKillDhcp();

private:
	/* Following functions/c'tor should not be called */
	AdapterAgentClientBase &operator=(const AdapterAgentClientBase &);

}; /* clase AdapterAgentClientBase */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_BASE_HPP_ */
