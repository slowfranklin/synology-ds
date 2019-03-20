/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_6IN4_TUN_
#define _NET_IPV6_ROUTER_6IN4_TUN_

#include <synowireless/ipv6router/router6_base.hpp>
#include <synowireless/ipv6router/router6_attr.hpp>

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

	class Tunnel6in4 : public Router6Base {
	public:
		Tunnel6in4(const Router6Attr &);
	public:
		bool Create() const;
		bool Destroy() const;
		bool ValidateAttr() const;
	}; // class Tunnel6in4

} // namespace router
} // namespace ipv6
} // namespace network
} // namespace syno

#endif // _NET_IPV6_ROUTER_6IN4_TUN_
