/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_BOND_CHANGE_HOOK_HPP_
#define _SYNO_WIRELESS_UTILS_BOND_CHANGE_HOOK_HPP_

#include <synonetsdk/hook/base_hook.hpp>

#define SZD_NET_BOND_CHANGE_PLUGIN	"net/bond_change"
#define SZK_HOOK_BOND_SLAVES		"SLAVES"
#define SZK_HOOK_BOND_MASTER		"MASTER"
#define SZK_HOOK_BOND_ACTION		"ACTION"
#define SZV_HOOK_BOND_CREATE		"create"
#define SZV_HOOK_BOND_DELETE		"delete"
#define SZK_HOOK_BOND_TYPE          "TYPE"
#define SZV_HOOK_BOND_LINUX         "linux"
#define SZV_HOOK_BOND_OVS           "ovs"

namespace synowireless {
namespace hook {

class BondChangeHook: public synonetsdk::hook::BaseHook {
	public:
		BondChangeHook(const std::string &action);
		virtual ~BondChangeHook();
};

} /* namespace hook */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_BOND_CHANGE_HOOK_HPP_ */
