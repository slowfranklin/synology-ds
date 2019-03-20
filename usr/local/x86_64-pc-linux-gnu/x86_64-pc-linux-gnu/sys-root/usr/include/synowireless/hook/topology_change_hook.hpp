/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_TOPOLOGY_CHANGE_HOOK_HPP_
#define _SYNO_WIRELESS_UTILS_TOPOLOGY_CHANGE_HOOK_HPP_

#include <synonetsdk/hook/base_hook.hpp>

#define SZD_NET_TOPOLOGY_CHANGE_PLUGIN	"net/topology_change"
#define SZK_HOOK_OLD_TOPOLOGY			"OLD_TOPOLOGY"
#define SZK_HOOK_NEW_TOPOLOGY			"NEW_TOPOLOGY"

namespace synowireless {
namespace hook {

class TopologyChangeHook: public synonetsdk::hook::BaseHook {
	public:
		TopologyChangeHook(const std::string &old_topology, const std::string &new_topology);
		virtual ~TopologyChangeHook();
	private:
		virtual bool IsValid();
};

} /* namespace hook */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_TOPOLOGY_CHANGE_HOOK_HPP_ */
