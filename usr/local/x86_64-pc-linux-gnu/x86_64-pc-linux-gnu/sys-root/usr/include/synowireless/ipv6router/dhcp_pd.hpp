/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_DHCP_PD_
#define _NET_IPV6_ROUTER_DHCP_PD_

#include <string>
extern "C" {
#include <synocore/proc.h>
}
#include <synowireless/ipv6router/router6_attr.hpp>
#include <synowireless/ipv6router/router6_base.hpp>

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

	class DHCPPD : public Router6Base {
	public:
		DHCPPD(const Router6Attr &);
	public:
		bool operator==(const Router6Base &rhs) const { return false; }
		bool operator!=(const Router6Base &rhs) const { return true; }
		bool Create() const;
		bool Destroy() const;
		bool ValidateAttr() const;
	private:
		bool StartDHCPPD() const;
		bool StopDHCPPD() const;
	}; // class DHCPPD

} // namespace router
} // namespace ipv6
} // namespace network
} // namespace syno

#endif // _NET_IPV6_ROUTER_DHCP_PD_
