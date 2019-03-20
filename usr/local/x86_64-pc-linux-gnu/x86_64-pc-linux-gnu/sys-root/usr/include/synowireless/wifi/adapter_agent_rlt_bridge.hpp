/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_BRIDGE_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_BRIDGE_HPP_

#include <string>

#include <synowireless/wifi/adapter_agent_rlt.hpp>

namespace synowireless {
namespace wifi {

class AdapterAgentRLTBridge : public AdapterAgentRLT {
public:

protected:
	virtual ~AdapterAgentRLTBridge();
	virtual std::string GetWanIfName();

private:
	AdapterAgentRLTBridge();

	/* Following functions/c'tor should not be called */
	AdapterAgentRLTBridge &operator=(const AdapterAgentRLTBridge &);

	friend class AdapterAgent;

}; /* clase AdapterAgentRLTBridge */

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_AGENT_RLT_BRIDGE_HPP_ */
