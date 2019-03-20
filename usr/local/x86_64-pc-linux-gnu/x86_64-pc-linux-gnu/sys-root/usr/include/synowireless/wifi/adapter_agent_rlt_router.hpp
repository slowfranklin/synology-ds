/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_ROUTER_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_ROUTER_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent_rlt.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentRLTRouter : public AdapterAgentRLT {
public:

protected:
	virtual ~AdapterAgentRLTRouter();
	virtual std::string GetWanIfName();
	virtual int ResetBridgeIP(const synowireless::wifi::AdapterConfig&);

private:
	AdapterAgentRLTRouter();

	/* Following functions/c'tor should not be called */
	AdapterAgentRLTRouter &operator=(const AdapterAgentRLTRouter &);

	friend class AdapterAgent;

}; /* clase AdapterAgentRLTRouter */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_ROUTER_HPP_ */
