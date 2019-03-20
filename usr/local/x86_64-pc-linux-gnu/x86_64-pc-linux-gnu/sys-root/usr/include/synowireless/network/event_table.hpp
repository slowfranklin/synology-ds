/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_MODULE_MANAGER_EVENT_TABLE_HPP_
#define _SYNO_NETWORK_MODULE_MANAGER_EVENT_TABLE_HPP_

#include <map>
#include <vector>
#include <string>
#include <synowireless/network/define.h>
#include <synowireless/network/base_event.hpp>
#include <synowireless/network/base_module.hpp>
#include "event_handler.hpp"

namespace synonetwork {
namespace network {
namespace module {

class EventTable {
public:
	typedef std::vector<EventHandler> EVENT_HANDLER_LIST;
public:
	EventTable();

	bool IsEventExist(event::EVENT_TYPE event) const;

	int Add(event::EVENT_TYPE, const EventHandler &pair);
	int Remove(event::EVENT_TYPE, MODULE_TYPE);
	int RemoveModule(MODULE_TYPE);
	const EVENT_HANDLER_LIST &ListHandlers(event::EVENT_TYPE event);

	std::string ToStr() const;
private:
	typedef std::map<event::EVENT_TYPE, EVENT_HANDLER_LIST> EVENT_MAP;
	typedef EVENT_MAP::iterator EVENT_MAP_ITER;
	typedef EVENT_MAP::const_iterator EVENT_MAP_CONST_ITER;

	typedef EVENT_HANDLER_LIST::iterator HANDLER_ITER;
	typedef EVENT_HANDLER_LIST::const_iterator HANDLER_CONST_ITER;
private:
	std::vector<EventHandler> emptyHandlers_;
	EVENT_MAP events_;

	EVENT_MAP_ITER FindEvent(event::EVENT_TYPE);
	HANDLER_CONST_ITER FindConstModule(const EVENT_HANDLER_LIST &handlers, MODULE_TYPE module) const;
	HANDLER_ITER FindModule(EVENT_HANDLER_LIST &handlers, MODULE_TYPE module) const;
	const EVENT_HANDLER_LIST &ListHandlers(EVENT_MAP_CONST_ITER iter);
	int Remove(EVENT_MAP_ITER iter, MODULE_TYPE module);

}; /* class EventTable */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_MODULE_MANAGER_EVENT_TABLE_HPP_ */
