/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_RLT_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_RLT_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent_client_base.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentClientRLT : public AdapterAgentClientBase {
public:
	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const;
	virtual int ScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);
	virtual int QuickScanNetworks(const AdapterConfig &config, std::vector<AdapterConfig::StationInfo> &apList);

	virtual ~AdapterAgentClientRLT();

private:
	AdapterAgentClientRLT();
	friend class AdapterAgent;

	virtual int ClientRecover(const AdapterConfig &config);

	virtual int AdHocEnable(const AdapterConfig &config);
	virtual int AdHocRecover(const AdapterConfig &config);
	virtual int AdHocDisable(const AdapterConfig &config);

	virtual int DoConnecting();
	virtual int DoDisconnect();

	int NetworkConnect();
	int CheckConnComplete();
	int PostProcessing();
	int RestartInterface();
	int CreateAdHoc();

	int ConnectToAPOpen();
	int ConnectToAPShared();
	int ConnectToAPWPAPSK();
	int ConnectToAPWPA();

	int DoNetworkScan(const std::string &strIfName, std::vector<AdapterConfig::StationInfo> &apList);
	WIFI_MODE ParseHWMode(const std::string &strHWMode);

private:
	/* Following functions/c'tor should not be called */
	AdapterAgentClientRLT &operator=(const AdapterAgentClientRLT &);

}; /* clase AdapterAgentClientRLT */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_CLIENT_RLT_HPP_ */
