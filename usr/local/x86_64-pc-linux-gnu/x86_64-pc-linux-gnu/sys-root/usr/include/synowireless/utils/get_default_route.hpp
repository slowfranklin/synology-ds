/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_GET_DEFAULT_ROUTE_HPP_
#define _SYNO_WIRELESS_UTILS_GET_DEFAULT_ROUTE_HPP_

#include <string>
#include <vector>

namespace synowireless {
namespace utils {

namespace routeparse {

struct Route {
	bool operator<(const Route &rhs) const { return metric < rhs.metric; }
	int metric;
	std::string gw;
	std::string ifname;
};

struct ParseV4 {
	std::string formatAddress(const std::string &) const;
	void operator()(const char *, std::vector<Route> &) const;

	static const char *RouteFile;
};

struct ParseV6 {
	std::string formatAddress(const std::string &) const;
	void operator()(const char *, std::vector<Route> &) const;

	static const char *RouteFile;
};

} /* namepsace routeparse */

template<int AF>
std::string GetDefaultRoute();
template<int AF>
int GetNumDefaultRoutes();

} /* namespace utils */
} /* namespace synowireless */

#endif // _SYNO_WIRELESS_UTILS_GET_DEFAULT_ROUTE_HPP_
