// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETLINK_HPP__
#define __SYNO_NETWORK_NETLINK_HPP__

#include <map>
#include <string>
#include <pthread.h>
#include <synowireless/hook/ip_change_event.hpp>
#include <synowireless/network/base_module.hpp>
#include <synowireless/network/if_map.hpp>

/*
  define HIBERNATION_WAKEUP_INTERRUPT_WORKROUND on 628x, AXP and A370 platform, reason is in below:

  DSM #In 628x,
  RTNetlink receives one interrupt of interface down in hibernation and two interrupts of interface down/up when wakeup.
  These interrupts are abnormal and should be skip.
  The workaround is to avoid this interrupt to wakeup service abnormally if the status of interface is not changed.

  DSM #In AXP, A370,
  In some of Marvell phy, link status change when we turn off phy led.
  The link status change event will interrupt hibernation.
*/

namespace synonetwork {
namespace network {
namespace module {

class NetlinkModule : public BaseModule {

public:
	NetlinkModule();
	virtual ~NetlinkModule();
	static BaseModule *Create();
	virtual int StartPolling();
private:
	int fd_;
	pthread_t netlinkPthread_;
	IFMap<std::string> ipv4AddrsMap_;
	std::map<std::string, std::vector<std::string> > ipv6AddrsMap_;
	IFMap<bool> linkStatus_;

	int InitialModule();
	int StartModule();
	int TerminateModule();

	int AnalysisNetlinkMessage();

	int CheckIPChangeEvent(struct nlmsghdr *pNlmsg);
	int CheckNewLinkEvent(struct nlmsghdr *pNlmsg);
	int CheckRouteChangeEvent(struct nlmsghdr *pNlmsg);
	int RequestDHCPIP(const std::string &interface) const;
	int OnInterfaceStatusChange(const std::string &interface, bool running, bool slave);

	int InitInterface();
	void ProcessIPv4Event(const std::string &ifname, const std::string &address, int prefixlen, bool isNewAddrEvent);
	void ProcessIPv6Event(const std::string &ifname, const std::string &address, int prefixlen, bool isNewAddrEvent);
#ifdef HIBERNATION_WAKEUP_INTERRUPT_WORKROUND
	bool IsSkipEvent();
	void CheckNetlinkReady();
#endif
	void InitLinkState();
	int HandleLinkEvent(const std::string &interface, short ifi_flags);
	int HandleIpEvent(const std::string &interface);
}; /* class NetlinkModule */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETLINK_HPP__ */
