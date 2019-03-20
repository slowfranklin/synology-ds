/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_ARP_IGNORE_CHANGE_HOOK_HPP_
#define _SYNO_WIRELESS_UTILS_ARP_IGNORE_CHANGE_HOOK_HPP_

#include <synonetsdk/hook/base_hook.hpp>

#define SZD_NET_ARP_IGNORE_CHANGE_PLUGIN	"net/arp_ignore_change"
#define SZK_HOOK_NEW_VALUE				"NEW_VALUE"

namespace synowireless {
namespace hook {

class ArpIgnoreChangeHook: public synonetsdk::hook::BaseHook {
	public:
		ArpIgnoreChangeHook(bool blNewValue);
		virtual ~ArpIgnoreChangeHook();
};

} /* namespace hook */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_ARP_IGNORE_CHANGE_HOOK_HPP_ */
