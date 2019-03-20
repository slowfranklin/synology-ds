// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETWORK_STATIC_ROUTE__
#define __SYNO_NETWORK_NETWORK_STATIC_ROUTE__

#include <string>
#include <synowireless/network/route_module.hpp>
#include <synowireless/network/policy_route.hpp>
#include <synowireless/utils/ip_address.hpp>

namespace synonetwork {
namespace network {

struct StaticRouteRule : public RouteRule{
	bool blEnable;
};

class StaticRoute {
public:
	StaticRoute();
	~StaticRoute();
	int TestRuleVaild(const StaticRouteRule &rule, Json::Value &adjustIp);
	int GetRules(const IP_TYPE &type, Json::Value &rules);
	int SetRules(const IP_TYPE &type, Json::Value &rules);
	int GetRouteTables(const IP_TYPE &type, Json::Value &tables);
	int RefreshIpv4Rules();
	int RefreshIpv6Rules();
	int RefreshRules();
private:
	int AddRule(const StaticRouteRule &rule);
	int DeleteRule(const StaticRouteRule &rule);
	int CheckRuleExist(const StaticRouteRule &rule);
	int GetTableInfo(const IP_TYPE &type, const std::string &strName, Json::Value &table);
};

} /* namespace network*/
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETWORK_STATIC_ROUTE__ */
