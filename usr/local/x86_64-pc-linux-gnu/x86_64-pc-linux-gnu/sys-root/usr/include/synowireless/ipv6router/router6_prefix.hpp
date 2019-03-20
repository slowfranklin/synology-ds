/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_PREFIX_
#define _NET_IPV6_ROUTER_PREFIX_
#include <string>
#include <vector>
#include <synowireless/ipv6router/router6_attr.hpp>

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

struct Router6PrefixAttr {
	Router6PrefixAttr(const std::string &p, const std::string &w, const std::string &l)
		: prefix(p), wan(w), lan(l) {}

	std::string prefix;
	std::string wan;
	std::string lan;
};

class Router6Prefix {
public:
	Router6Prefix();

	std::vector<Router6PrefixAttr> List() const;
	bool Allocate(const std::string &, const std::string &);
	bool Deallocate(const std::string &, const std::string &);

	static std::vector<std::string> EnumPrefix64(const std::string &, int);
	static std::string NormalizePrefix(const std::string &);

private:
	std::vector<Router6Attr> mAttrs;
private:
	bool Load();
	std::string AllocatedTo(const std::string &, const Router6Attr &) const;
};

} // router
} // ipv6
} // network
} // syno

#endif // _NET_IPV6_ROUTER_PREFIX_
