/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_HPP_

// There are too many shadow copy in boost::ptr_vector
#pragma GCC diagnostic ignored "-Wshadow"

#include <string>
extern "C" {
#include <pthread.h>
}

#include <boost/ptr_container/ptr_vector.hpp>

#include <synowireless/wifi/enum.hpp>
#include <synowireless/wifi/utils.hpp>
#include <synowireless/wifi/adapter_config.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgent;
class AdapterData;
class AdapterCapability;
class AdapterConfig;

class Adapter {
public:
	static int RefreshAdapterList();
	static int AddAdapter(const std::string &strIfName);
	static Adapter *GetAdapter(const std::string &strIfName);
	static Adapter *GetPCIAdapter();
	static int RemoveAdapter(const std::string &strIfName);
	static boost::ptr_vector<Adapter> &GetList();
	static int SwitchNetTopology(WIFI_TOPOLOGY newTopology);
	static WIFI_TOPOLOGY GetTopology();
	static int GetEnabledAdapterCount();
	static int EnableAll();
	static int DisableAll();
	static int SwitchOnOff();
	static int ResetToDefault();

	int Apply(const AdapterConfig &config);
	int Initialize();
	int Terminate();
	int SwitchTopology(WIFI_TOPOLOGY newTopology);
	int ScanNetworks(std::vector<AdapterConfig::StationInfo> &apList);
	int LoadStationConnData(std::vector<synowireless::wifi::utils::ConnectionInfo> &connectionList);
	int EnableWPSWithPBC();
	int EnableWPSWithPinCode(const std::string &strPin);
	int ExecSchedule();
	bool SetCountryCodeImpl(const std::string &code) const;

	const AdapterConfig &GetConfig() const;
	const AdapterCapability &GetCapability() const;

	bool IsTopology(WIFI_TOPOLOGY topology) const;
	WIFI_STATUS GetStatus() const;

	~Adapter();

private:
	static Adapter *Create(const std::string &strIfName);
	static int Delete(const Adapter *pAdapter);
	bool HasNullMember() const;
	static int SwitchKernelModule(WIFI_TOPOLOGY oldtopology, WIFI_TOPOLOGY newtopology);
	static synowireless::utils::MacAddress GetAddressByIFName(const std::string &strIfName);
	static int DeleteAdapterAll();
	static int AddAgentAll();
	static int GetDongleCount();

private:
	AdapterAgent *pAgent;
	AdapterData *pData;
	AdapterCapability *pCapability;

	static boost::ptr_vector<Adapter>::iterator FindAdapter(const std::string &strIfName);
	static boost::ptr_vector<Adapter>::iterator FindAdapter(const synowireless::utils::MacAddress &bssid);

	Adapter(AdapterAgent *pAgent,
			AdapterData *pData,
			AdapterCapability *pCapability);

	/* Following functions c'tor should not be called */
	Adapter &operator=(const Adapter &);

	static boost::ptr_vector<Adapter> list;
	static WIFI_TOPOLOGY topology;
	static pthread_mutex_t _wifiMutex;
}; /* clase Adapter */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_HPP_ */
