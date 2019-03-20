/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_WIFI_CLIENT_HPP_
#define _SYNO_WIRELESS_WIFI_CLIENT_HPP_

#include <json/value.h>

#include <synonetsdk/dbus/dbus_client.hpp>

#define APPLY_ADAPTER_TIMEOUT_MS 60000
#define SET_COUNTRY_CODE_TIMEOUT_MS 60000

namespace synowireless {
namespace dbus {

class WifiClient : public synonetsdk::dbus::DBusClient {
public:
	WifiClient();
	virtual ~WifiClient();

	virtual bool IsServerReady() const;

	int GetAdapterList(Json::Value &adapterList);
	int GetAdapterConfig(const std::string &strIfName, Json::Value &config);
	int GetAdapterCapability(const std::string &strIfName, Json::Value &capability);
	int GetAdapterStatus(const std::string &strIfName, Json::Value &status);
	int EnableAdapter(const std::string &strIfName);
	int DisableAdapter(const std::string &strIfName);
	int ExecSchedule(const std::string &strIfName);
	int ApplyAdapter(const std::string &strIfName, const Json::Value &config);
	int SwitchTopology(const std::string &strTopology);
	int SwitchAdapterTopology(const std::string &strIfName, const std::string &strTopology);
	int AddAdapter(const std::string &strIfName);
	int RemoveAdapter(const std::string &strIfName);
	int RefreshAdapterList();
	int ForceRemoveAllAdapters();
	int GetConnectionList(const std::string &strIfName, Json::Value &config);
	int GetConnectedAPInfo(const std::string &strIfName, Json::Value &config);
	int GetBridgeList(Json::Value &bridgeList);
	int GetBridgeConfig(const std::string &strIfName, Json::Value &config);
	int ApplyBridge(const std::string &strIfName, const Json::Value &config);
	int ScanNetworks(const std::string &strIfName, Json::Value &config);
	int RefreshWlanSlaveList();
	int EnableWPSWithPBC(const std::string &strIfName);
	int EnableWPSWithPinCode(const std::string &strIfName, const std::string &strPin);
	int SwitchWifiOnOff();
	int ResetToDefault();
	int SetCountryCode(const std::string &strCountry);

private: /* They will not be implemented. Do NOT use them */
	WifiClient(const WifiClient &);
	WifiClient operator=(const WifiClient &);

}; /* class WifiClient */

} /* namespace dbus */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_CLIENT_HPP_ */
