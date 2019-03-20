/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_HELLO_EVENT_HPP_
#define _SYNO_NETWORK_HELLO_EVENT_HPP_

#include <string>
#include <synowireless/network/define.h>
#include <synowireless/network/base_event.hpp>

namespace synonetwork {
namespace network {
namespace event {

class HelloEvent : public BaseEvent {
	public:
		HelloEvent(const std::string &msg);
		virtual ~HelloEvent();

		virtual bool IsValid() const;
		const std::string &GetMessage() const { return msg_; }

		virtual std::string ToStr() const;
	private:
		std::string msg_;

		virtual int ProcessEvent();
}; /* class HelloEvent */

} /* namespace event */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_HELLO_EVENT_HPP_ */
