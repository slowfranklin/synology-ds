/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_HPP_

#include <string>
#include <sstream>

#include <synowireless/utils/ip_address.hpp>
#include <synowireless/utils/mac_address.hpp>
#include <synowireless/wifi/adapter_agent_client_base.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentClient : public AdapterAgentClientBase {
public:
	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);
	virtual int QuickScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);

protected:
	virtual ~AdapterAgentClient();

private:
	AdapterAgentClient();

	/* Following functions/c'tor should not be called */
	AdapterAgentClient &operator=(const AdapterAgentClient &);

	friend class AdapterAgent;

	//==========client==============
	// client private api
	int ClientRecover(const AdapterConfig &config);
	int ClientDisable(const AdapterConfig &config);

	// client private function
	int DoConnecting();
	int CheckConnComplete();
	int WriteSupConfig(const std::stringstream &ssIn);
	int SetWpaSupplicantConfig();
	int PostProcessing();
	int NetworkConnect();

	//==========adhoc==============
	// adhoc private api
	int AdHocEnable(const AdapterConfig &config);
	int AdHocRecover(const AdapterConfig &config);
	int AdHocDisable(const AdapterConfig &config);

	// adhoc private function
	int GetClientConfig(const AdapterConfig &config);
	int SetAdHocMode();
	int CreateAdHoc();

	// =========== common private function =============
	int DoDisconnect();
	int DisconnectDownInterface();
	int DisconnectKillWpa();
	int TerimateWPAProcess();
	// update ap's arp list
	int UpdateAPConnectionList();

	// scan ap
	int CountWordsInString(const std::string &strIn);
	int NetworkScanParse(const std::string &strIfName, std::vector<AdapterConfig::StationInfo> &apList);
	int NetworkScanCheck(const std::string &strIfName, std::vector<AdapterConfig::StationInfo> &apList);
	int DoNetworkScan(const std::string &strIfName, std::vector<AdapterConfig::StationInfo> &apList);

	// ===========common private variables==============
	// file for WPA Supplicant
	std::string _strConfFile;
	std::string _strPidFile;

}; /* clase AdapterAgentClient */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_HPP_ */
