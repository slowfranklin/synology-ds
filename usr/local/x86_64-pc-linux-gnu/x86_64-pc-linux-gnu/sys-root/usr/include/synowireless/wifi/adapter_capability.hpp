/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_HPP_

#include <map>
#include <string>
#include <vector>

#include <synowireless/wifi/enum.hpp>

#define SZK_FEATURE					"feature"
#define SZK_CHANNEL_ID				"id"
#define SZK_CHANNEL_FREQUENCY		"frequency"

namespace synowireless {
namespace wifi {

class AdapterConfig;

class AdapterCapability {
public:
	struct Channel {
		unsigned int id;
		std::string strFrequency;

		Channel()
		: id(0), strFrequency()
		{}
		Channel(unsigned int otherId, const std::string &strOtherFrequency)
		: id(otherId), strFrequency(strOtherFrequency)
		{}
		~Channel() {}
	};

public:
	static AdapterCapability *Create(const std::string &strIfName, const AdapterConfig &config);
	static int Delete(const AdapterCapability *pCapability);

	virtual int Verify(const AdapterConfig &config) const;

	/* Get general options */
	virtual std::vector<WIFI_TOPOLOGY> GetTopology() const;
	virtual std::vector<WIFI_FEATURE> GetFeature() const;

	/* Get ap options */
	virtual std::vector<WIFI_MODE> GetMode() const;
	virtual std::vector<WIFI_BANDWIDTH> GetBandwidth() const;
	virtual std::vector<Channel> GetChannel() const;
	virtual std::vector<WIFI_POWER> GetPower() const;
	virtual unsigned int GetMaxNumClient() const;

	/* Get securtiy options */
	virtual std::vector<WIFI_SECURITY> GetSecurity() const;
	virtual std::vector<WIFI_ENCRYPTION> GetEncryption() const;

	/* Get MAC filter options */
	virtual std::vector<WIFI_MAC_FILTER_POLICY> GetMacFilterPolicy() const;

	/* Get guest network options */
	virtual unsigned int GetGuestNetworkMaxNumClient() const;
	virtual std::vector<WIFI_SECURITY> GetGuestNetworkSecurity() const;
	virtual std::vector<WIFI_ENCRYPTION> GetGuestNetworkEncryption() const;

protected:
	AdapterCapability();
	AdapterCapability(const std::string &strName);
	virtual ~AdapterCapability();

private:
	static bool initializeModeMap();
	static std::vector<WIFI_MODE> GetMode(const std::string &strMode);
	int Enable5GMode(const WIFI_MODE &CfgMode) const;

private:
	std::string strIfName;

	static std::map<std::string, WIFI_MODE> modeMap;

}; /* clase AdapterCapability */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_HPP_ */
