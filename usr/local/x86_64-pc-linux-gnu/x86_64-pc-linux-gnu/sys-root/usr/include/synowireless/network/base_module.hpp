#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_BASE_MODULE_HPP_
#define _SYNO_NETWORK_BASE_MODULE_HPP_

#include <set>
#include <vector>
#include <string>
#include <json/value.h>
#include "define.h"
#include "pthread_mutex.hpp"
#include "base_event.hpp"

namespace synonetwork {
namespace network {
namespace module {
enum MODULE_TYPE {
	MIN_MODULE,
	TEST_MODULE,
	IPV6_MODULE,
	ROUTE_MODULE,
	DEVICELIST_MODULE,
	RTNETLINK_MODULE,
#ifdef MY_DEF_HERE
	TX_MODULE,
#endif
	MAX_MODULE
};

class BaseModule {
public:
	typedef int(BaseModule::*ON_EVENT_HANDLER)(const event::BaseEvent *);
public:
	BaseModule(MODULE_TYPE type);
	virtual ~BaseModule();

	static bool IsValidModule(MODULE_TYPE);

	int Initialize();
	int Terminate();
	int Start();

	virtual int ProcessRequest(const Json::Value &input, Json::Value &output);

	MODULE_TYPE GetType() const { return type_; }

	virtual std::string ToStr() const;
protected:
	bool Lock();
	bool Unlock();
	bool Trylock();

	virtual int InitialModule() = 0;
	virtual int TerminateModule() = 0;
	virtual int StartModule() = 0;

	virtual int HookEvents() const;
	int HookEvent(event::EVENT_TYPE event, ON_EVENT_HANDLER handler) const;
	int UnHookEvent(event::EVENT_TYPE event) const;
private:
	typedef enum {
		UNKNOWN = 0,
		CREATED,
		INITIALIZED,
		STARTED,
	} STATUS;
private:
	STATUS status_;
	MODULE_TYPE type_;
	PthreadMutex mutex_; // mutex for accessing variable

	bool IsInitailed() const { return INITIALIZED == status_; }
	bool IsStarted() const { return STARTED == status_; }

}; /* class BaseModule */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_BASE_MODULE_HPP_ */
