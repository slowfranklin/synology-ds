/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_RLT_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_RLT_HPP_

#include <synowireless/wifi/adapter_capability.hpp>

namespace synowireless {
namespace wifi {

class AdapterCapabilityRLT : public AdapterCapability {
public:
	virtual int Verify(const AdapterConfig &config) const;

	/* Get customized capability */
	virtual std::vector<WIFI_FEATURE> GetFeature() const;
	virtual std::vector<WIFI_MODE> GetMode() const;
	virtual std::vector<Channel> GetChannel() const;
	virtual std::vector<WIFI_BANDWIDTH> GetBandwidth() const;

protected:
	AdapterCapabilityRLT(const std::string &strName, const AdapterConfig &config);
	~AdapterCapabilityRLT();

private:
	const AdapterConfig &config;
	friend class AdapterCapability;

}; /* clase AdapterCapabilityRLT */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_RLT_HPP_ */
