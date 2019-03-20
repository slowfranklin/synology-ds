/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_TEST_MODULE_HPP_
#define _SYNO_NETWORK_TEST_MODULE_HPP_

#include <string>
#include <json/value.h>
#include "base_module.hpp"
#include "base_event.hpp"

namespace synonetwork {
namespace network {
namespace module {

class TestModule : public BaseModule {
	public:
		TestModule();
		virtual ~TestModule();
		static BaseModule* Create();

		virtual int ProcessRequest(const Json::Value &input, Json::Value &output);
		int OnHelloEvent(const event::BaseEvent *pEvent);
	private:
		virtual int InitialModule();
		virtual int TerminateModule();
		virtual int StartModule();

		virtual int HookEvents() const;
};/* class TestModule */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_TEST_MODULE_HPP_ */
