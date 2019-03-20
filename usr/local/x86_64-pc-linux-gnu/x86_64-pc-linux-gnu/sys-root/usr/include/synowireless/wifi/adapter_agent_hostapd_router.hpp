/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_ROUTER_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_ROUTER_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent_hostapd.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentHostapdRouter : public AdapterAgentHostapd {
public:
	virtual int Enable(const AdapterConfig &config);
	virtual int Recover(const AdapterConfig &config);
	virtual int Disable(const AdapterConfig &config);
	virtual int Reload(const AdapterConfig &config, const RELOAD_STATUS status);

	virtual WIFI_STATUS GetStatus(const AdapterConfig &config) const;

protected:
	virtual ~AdapterAgentHostapdRouter();

private:
	AdapterAgentHostapdRouter();

	/* Following functions/c'tor should not be called */
	AdapterAgentHostapdRouter &operator=(const AdapterAgentHostapdRouter &);

	friend class AdapterAgent;

}; /* clase AdapterAgentHostapdRouter */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_HOSTAPD_ROUTER_HPP_ */
