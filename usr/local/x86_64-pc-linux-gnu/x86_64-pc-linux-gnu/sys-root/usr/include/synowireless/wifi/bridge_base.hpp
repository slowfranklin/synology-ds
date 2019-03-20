/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_BRIDGE_BASE_HPP_
#define _SYNO_WIRELESS_WIFI_BRIDGE_BASE_HPP_

// There are too many shadow copy in boost::ptr_vector
#pragma GCC diagnostic ignored "-Wshadow"

#include <string>

#include <boost/ptr_container/ptr_vector.hpp>

extern "C" {
#include <synonetsdk/net.h>
}

#include <synowireless/wifi/enum.hpp>
#include <synowireless/wifi/define.hpp>
#include <synowireless/wifi/bridge_config.hpp>

namespace synowireless {
namespace wifi {

struct BRIDGE_RELOAD_STATUS {
	bool nat;
	bool dhcp;
	bool ipv6;
	bool dhcpv6;
};

class BridgeBase {
public:
	/* static */
	static int SwitchTopology(synowireless::wifi::WIFI_TOPOLOGY topology);
	static synowireless::wifi::WIFI_TOPOLOGY GetTopology();
	static int AddSlaveWlan(const std::string &strIfName);
	static int RemoveSlaveWlan(const std::string &strIfName);
	static int EnableAll();
	static int DisableAll();
	static int RestartTopologyAll();
	static BridgeBase *GetBridge(const std::string &strBridgeName);
	static BridgeBase *FindBridgeFromSlave(const std::string &strSlaveName);
	static int AddModifiedIfName(const std::string &strIfName);
	static int ClearModifiedIfName();
	static bool IsBridge(const std::string &strBridgeName);
	static bool IsLocalBridge(const std::string &strBridgeName);
	static bool IsGuestBridge(const std::string &strBridgeName);
	static bool IsOVSBridge(const std::string &strBridgeName);
	static int Initialize();
	static boost::ptr_vector<BridgeBase> &GetList();
	static int GetWlanSlaveCount(const std::string &strBridgeName);
	static int RefreshWlanSlaveList();
	static void ResetToDefault();

	/* non-static */
	std::string GetName() const;
	const char *GetNameC() const;
	BridgeConfig GetConfig();
	int SetConfig(const BridgeConfig &config);
	int SetDefaultConfig(const BridgeConfig &config);
	const std::vector<std::string> GetSlaveList() const;
	int SetOnBoot(bool blValue);
	int Apply(const BridgeConfig &config);
	int GetV4DnsServerList(std::string &) const;
	int GetV6DnsServerList(std::string &) const;

	/* virtual */
	virtual int CreateConfig();
	virtual int RemoveSlave();
	virtual BridgeConfig GetNextConfig(const BridgeConfig &config);
	virtual int Enable();
	virtual int Disable();
	virtual int EnableTopology();
	virtual int EnableTopologyAll();
	virtual int DisableTopology();
	virtual int DisableTopologyAll();
	virtual int EnableIPv6();
	virtual int DisableIPv6();
	virtual int EnableSlaveTopology();
	virtual int CreateGatewayInfo();
	virtual int ResetGatewayInfo();
	virtual int AddSlaveEth();
	virtual int AddSlaveWlan();
	virtual int AddSlaveGwlan();
	virtual int RemoveSlaveEth();
	virtual int RemoveSlaveWlan();
	virtual int RemoveSlaveGwlan();

	virtual int EnableNat() = 0;
	virtual int DisableNat() = 0;
	virtual int EnableDhcp() = 0;
	virtual int DisableDhcp() = 0;
	virtual int EnableDhcpv6() = 0;
	virtual int DisableDhcpv6() = 0;
	virtual int EnableSecurityConf() = 0;
	virtual int DisableSecurityConf() = 0;
	virtual int ResetBridgeIP() = 0;
	virtual int SetTopologyFile(const BridgeConfig &config) = 0;

	virtual ~BridgeBase();

protected:
	BridgeBase(const std::string &strName);

	int ConvertToBridgeInfo(PBRIDGE_INFO pInfo,
							const std::string &strIfName,
							const std::string &strIfName2,
							const BR_TYPE type);
	std::vector<std::string> GetDnsServerList(BOOL (*)(const char *)) const;

private:
	/* static */
	static BridgeBase *CreateBridge(const std::string &strBridgeName);
	static int ClearBridgeList();
	static int AddSlave(const std::string &strSlave);
	static int RemoveSlave(bool (*pFunction)(const std::string &));

	static synowireless::wifi::WIFI_TOPOLOGY topology;
	static boost::ptr_vector<BridgeBase> bridgeList;
	static std::vector<std::string> modifiedIfNameList;
	static int RestoreActualTopologyFile();

	void FillDhcpConf(PSYNO_DHCPD_CONF pDhcpConf);
	void FillDhcpConfv6(PSYNO_DHCPD_CONF pDhcpConf);

	/* non-static */
	int ResetReloadStatus();
	std::string strBridgeName;
	synowireless::wifi::BridgeConfig bridgeConfig;
	std::vector<std::string> slaveList;
	BRIDGE_RELOAD_STATUS reloadStatus;

	/* Following functions c'tor should not be called */
	BridgeBase &operator=(const BridgeBase &);

}; /* clase BridgeBase */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_BRIDGE_BASE_HPP_ */
