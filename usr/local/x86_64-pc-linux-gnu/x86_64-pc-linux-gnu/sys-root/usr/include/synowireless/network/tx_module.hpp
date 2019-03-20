#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifdef MY_DEF_HERE
// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_TX_MODULE_HPP__
#define __SYNO_NETWORK_TX_MODULE_HPP__

#include <map>
#include <string>
extern "C" {
#include <pthread.h>
}
#include <synowireless/network/define.h>
#include <synowireless/network/base_module.hpp>

namespace synonetwork {
namespace network {
namespace module {

class TxModule : public BaseModule {
public:
	TxModule();
	virtual ~TxModule();
	static BaseModule *Create();

	void StartPolling();
private:
	pthread_t _txPthread;

	int InitialModule();
	int StartModule();
	int TerminateModule();

	int getTx(const std::string &ifname) const;
}; /* class TxModule */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_TX_MODULE_HPP__ */
#endif /* MY_DEF_HERE */
