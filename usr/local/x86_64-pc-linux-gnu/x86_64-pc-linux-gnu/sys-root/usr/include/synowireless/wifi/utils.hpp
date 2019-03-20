/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_UTILS_HPP_
#define _SYNO_WIRELESS_WIFI_UTILS_HPP_

#include <string>
#include <vector>
#include <json/value.h>

#include <synowireless/wifi/adapter_capability.hpp>
#include <synowireless/wifi/adapter_config.hpp>
#include <synowireless/wifi/bridge_base.hpp>
#include <synowireless/wifi/bridge_config.hpp>
#include <synowireless/wifi/define.hpp>
#include <synowireless/utils/ip_address.hpp>
#include <synowireless/utils/mac_address.hpp>

namespace synowireless {
namespace wifi {
namespace utils {

int Get215AirWlanMacAddress(synowireless::utils::MacAddress &mac);
int RemoveRLTKernelModule(const std::string &strKernelFileName);
int InsertRLTKernelModule(const std::string &strKernelFileName);
bool Is215AirBuiltInWlan(const std::string &strIfName);
bool Is213AirBuiltInWlan(const std::string &strIfName);
bool IsAirBuiltInWlan(const std::string &strIfName);
int SetSupportNetTopology(bool blEnabled);
std::string GetBssid(const std::string &strIfName);
int GetAdapterNum();
int SetScheduleValue(bool schedule[], const std::string &strSchedule);
Json::Value GetJsonValue(const synowireless::wifi::AdapterConfig &config);
Json::Value GetJsonValue(const synowireless::wifi::AdapterCapability &capability);
Json::Value GetJsonValue(synowireless::wifi::BridgeBase *bridge);
int GetConfig(const std::string &strConfig, synowireless::wifi::AdapterConfig &config);
int GetConfig(const std::string &strConfig, synowireless::wifi::BridgeConfig &config);
int IsSectionExist(const std::string &strFile, const std::string &strSecName);
std::string itoa(const int value);
std::string rgbltoa(const bool ary[], const size_t size);
int GetWirelessIndex(const std::string &strIfName);
int GetGuestBridgeIndex(const std::string &strIfName);
std::string GetBridgeName(const WIFI_TOPOLOGY &topology);
int GetBridgeConfigName(const WIFI_TOPOLOGY &topology, std::stringstream &strBridgeConfigName);
bool IsNetActivate(const std::string strIfName);
WIFI_TOPOLOGY ReadTopology();
int WriteTopology(WIFI_TOPOLOGY newTopology);
int EncryptPlainText(const std::string &strPlainText, std::string &strCipherText);
int DecryptCipherText(const std::string &strCipherText, std::string &strPlainText);
int GetTopologyString(std::string &strTopology);
bool IsSupportTopology();
bool HasWifiDongle();
bool IsGuestNetworkSupport(const std::string &strIfName);

struct ConnectionInfo{
	std::string strNetIF;
	std::string strHostName;
	synowireless::utils::IPAddress ipAddress;
	synowireless::utils::MacAddress mac;
	std::string strAssoTime;
};

int GetDHCPInfoByMAC(const synowireless::utils::MacAddress &macAddr, synowireless::utils::IPAddress &ipAddr, std::string &strHostName);
int GetArpInfoByMAC(const synowireless::utils::MacAddress &macAddr, synowireless::utils::IPAddress &ipAddr, std::string &strHostName);
Json::Value ParseConnectionList(const std::vector<ConnectionInfo> &connectionList);
int GetSignalStrength(const std::string &strIfName);
int GetConnectedAPInfo(const synowireless::wifi::AdapterConfig &config, Json::Value &value);
Json::Value StationInfoToJson(const synowireless::wifi::AdapterConfig::StationInfo &staInfo);
int ConnectionJsonToStationInfo(const Json::Value &value, synowireless::wifi::AdapterConfig::StationInfo &staInfo);

int GetFirstExistentSlaveByBridge(const std::string &strIfName, std::string &strSlaveName);
int GetSupportedMode(std::string &strOut);
} /* namespace utils */
} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_UTILS_HPP_ */
