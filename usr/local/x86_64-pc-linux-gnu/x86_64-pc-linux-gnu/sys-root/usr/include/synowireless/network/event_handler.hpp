/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_MODULE_MANAGER_EVENT_HANDLER_HPP_
#define _SYNO_NETWORK_MODULE_MANAGER_EVENT_HANDLER_HPP_

#include <synowireless/network/define.h>
#include <synowireless/network/base_event.hpp>
#include <synowireless/network/base_module.hpp>

namespace synonetwork {
namespace network {
namespace module {

class EventHandler {
public:
	EventHandler();
	EventHandler(MODULE_TYPE ,BaseModule::ON_EVENT_HANDLER);

	MODULE_TYPE GetModule() const { return module_; }
	BaseModule::ON_EVENT_HANDLER GetHandler() const { return handler_; }

	bool IsValid() const { return BaseModule::IsValidModule(module_) && NULL != handler_; }
	bool IsModule(MODULE_TYPE) const;
	bool operator== (const EventHandler &) const;
private:
	MODULE_TYPE module_;
	BaseModule::ON_EVENT_HANDLER handler_;
};/* class EventHandler */

} /* namespace event */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_MODULE_MANAGER_EVENT_HANDLER_HPP_ */
