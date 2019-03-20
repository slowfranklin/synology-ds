/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_MODULE_MANAGER_HPP_
#define _SYNO_NETWORK_MODULE_MANAGER_HPP_

#include <map>
#include <string>
#include "define.h"
#include "base_module.hpp"
#include "event_table.hpp"
#include "base_event.hpp"

namespace synonetwork {
namespace network {
namespace module {

class ModuleManager {
public:
	~ModuleManager();
	static ModuleManager &GetInstance();

	bool Initialize();
	bool Start();
	void Dump() const;

	int ProcessRequest(MODULE_TYPE type, const Json::Value &input, Json::Value &output);

	int HookEvent(event::EVENT_TYPE, MODULE_TYPE, BaseModule::ON_EVENT_HANDLER);
	int UnHookEvent(event::EVENT_TYPE, MODULE_TYPE);
	int NotifyEvent(const event::BaseEvent *);

private:
	struct MODULE_INFO {
		MODULE_TYPE module;
		bool required;
		BaseModule *(*createFunc)();
	};

	typedef std::map<MODULE_TYPE, BaseModule *> MODULE_MAP;
	typedef MODULE_MAP::iterator MODULE_MAP_ITER;
	typedef MODULE_MAP::const_iterator MODULE_MAP_CONST_ITER;

private:
	MODULE_MAP modules_;
	EventTable events_;

	static MODULE_INFO module_info[];

	ModuleManager();

	bool InitModules();
	bool AddModule(const MODULE_INFO &info);
	bool RemoveModule(MODULE_TYPE type);
	MODULE_MAP_ITER FindModule(MODULE_TYPE type);
	bool IsModuleExist(MODULE_TYPE type);
	BaseModule *GetModule(MODULE_TYPE type);

}; /* class ModuleManager */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_MODULE_MANAGER_HPP_ */
