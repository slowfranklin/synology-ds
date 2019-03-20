// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETWORK_IPV6_MODULE_FD__
#define __SYNO_NETWORK_NETWORK_IPV6_MODULE_FD__

#include <string>
#include <map>
#include <synonetsdk/net.h>
#include <synowireless/network/base_module.hpp>

#define MSG_SIZE_RECV	1500

namespace synonetwork {
namespace network {
namespace module {

enum DHCP6_STATE {
	DHCP6_NONE,
	DHCP6_STATEFUL,
	DHCP6_STATELESS_AUTO,
	DHCP6_STATELESS_DHCP,
};

struct InterfaceContext {
	std::string gateway;
	time_t timeStamp;
	DHCP6_STATE state;

	InterfaceContext() : timeStamp(0), state(DHCP6_NONE) {}
	InterfaceContext(const std::string &Gateway, time_t TimeStamp, const DHCP6_STATE State)
	: gateway(Gateway), timeStamp(TimeStamp), state(State) {}
};

class IPv6Module: public BaseModule {
public:
	IPv6Module();
	virtual ~IPv6Module();
	static BaseModule* Create();

	void ProcessRA(const std::string &addr,
				   const std::string &interface,
				   unsigned char *msg, int len,
				   bool flag_managed, bool flag_other);

	int recv_rs_ra(unsigned char *msg, struct sockaddr_in6 *addr, struct in6_pktinfo **pkt_info);
	void print_addr(struct in6_addr *addr, char *str);

	virtual int ProcessRequest(const Json::Value &input, Json::Value &output);

private:
	int Fd;
	std::map<std::string, InterfaceContext> ifCtx;

	virtual int InitialModule();
	virtual int TerminateModule();
	virtual int StartModule();

	bool open_icmpv6_socket(int &fd);

	bool Ipv6Enable(const std::string &interface);
	bool IsRaValid(unsigned char *msg, int len, const std::string &interface, bool flag_managed);
	bool IsRaStateChange(const std::string &interface, bool flag_managed, bool flag_other);
	std::vector<std::string> RaAutoPrefixGet(unsigned char *msg, int len, const char *interface);
	bool IsGatewayReachable(const std::string &interface);
	bool IsRaExchangeable(const std::string &interface);
};

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETWORK_IPV6_MODULE_FD__ */
