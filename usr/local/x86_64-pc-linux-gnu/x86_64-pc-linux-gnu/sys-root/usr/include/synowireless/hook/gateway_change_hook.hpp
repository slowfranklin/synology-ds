/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_GATEWAY_CHANGE_HOOK_HPP_
#define _SYNO_WIRELESS_UTILS_GATEWAY_CHANGE_HOOK_HPP_

#include <synonetsdk/hook/base_hook.hpp>

#define SZD_NET_GATEWAY_CHANGE_PLUGIN	"net/gateway_change"
#define SZK_HOOK_ACTION					"ACTION"
#define SZK_HOOK_IFNAME					"IFNAME"
#define SZK_HOOK_DESTINATION			"DESTINATION"
#define SZK_HOOK_GATEWAY				"GATEWAY"

namespace synowireless {
namespace hook {

class GatewayChangeHook: public synonetsdk::hook::BaseHook {
	public:
		GatewayChangeHook(const std::string &action,
						  const std::string &ifname,
						  const std::string &destination,
						  const std::string &gateway);
		virtual ~GatewayChangeHook();
	private:
		virtual bool IsValid();
};

} /* namespace hook */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_GATEWAY_CHANGE_HOOK_HPP_ */
