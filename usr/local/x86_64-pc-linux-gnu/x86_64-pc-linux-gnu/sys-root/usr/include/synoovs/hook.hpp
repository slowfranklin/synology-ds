/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_HOOK_HPP_
#define __SYNO_OVS_HOOK_HPP_

#include <synonetsdk/hook/base_hook.hpp>

#define SZD_NET_OVS_CHANGE_PLUGIN	"net/ovs_change"
#define SZK_HOOK_OVS_ACTION		"ACTION"
#define SZK_HOOK_OVS_CREATE		"create"
#define SZK_HOOK_OVS_DELETE		"delete"

namespace SYNO {
namespace OVS {
	/**
	 * This object is used to provide the hook event for OpenvSwitch.
	 * We provide the pre-hook event and post-hook event. the pre-hook means the OVS will be destroyed and the post-hook means the OVS will be constructed.
	 **/
	class OVSChangeHook: public synonetsdk::hook::BaseHook {
		public:
			OVSChangeHook(const std::string &action);
			virtual ~OVSChangeHook();

	}; //OVSChangeHook
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_HOOK_HPP_
