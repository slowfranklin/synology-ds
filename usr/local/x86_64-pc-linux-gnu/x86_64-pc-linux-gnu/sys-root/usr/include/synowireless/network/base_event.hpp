/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_BASE_EVENT_HPP_
#define _SYNO_NETWORK_BASE_EVENT_HPP_
#include <string>
#include <synowireless/network/define.h>

namespace synonetwork {
namespace network {
namespace event {
enum EVENT_TYPE {
	MIN_EVENT,
	HELLO_EVENT,
	IP_CHANGE,
	MAX_EVENT
};

class BaseEvent {
public:
	BaseEvent(EVENT_TYPE event);
	virtual ~BaseEvent();

	static bool IsValidEvent(EVENT_TYPE event);

	int Process();

	EVENT_TYPE GetEventType() const { return event_; }
	virtual bool IsValid() const = 0;
	virtual std::string ToStr() const;
protected:
	virtual int ProcessEvent();
private:
	EVENT_TYPE event_;
	bool isNotified_;
	bool isProcessed_;

	int NotifyModuleManager();
	int PostProcess();
}; /* class BaseEvent */

} /* namespace event */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_BASE_EVENT_HPP_ */
