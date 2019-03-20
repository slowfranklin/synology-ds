/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_AIR_MODEL_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_AIR_MODEL_HPP_

#include <synowireless/wifi/adapter_capability.hpp>

namespace synowireless {
namespace wifi {

class AdapterCapabilityAirModel : AdapterCapability {
public:
	virtual int Verify(const AdapterConfig &config) const;

	/* Get customized capability */
	virtual std::vector<WIFI_FEATURE> GetFeature() const;

protected:
	AdapterCapabilityAirModel();
	AdapterCapabilityAirModel(const std::string &strName);
	~AdapterCapabilityAirModel();

	friend class AdapterCapability;

}; /* clase AdapterCapabilityAirModel */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_CAPABILITY_AIR_MODEL_HPP_ */
