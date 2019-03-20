/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_BASE_
#define _NET_IPV6_ROUTER_BASE_

#include <string>
extern "C" {
#include <synocore/proc.h>
}
#include <synowireless/ipv6router/router6_attr.hpp>
#define IPCMD(cmd, subcmd, args ...) \
	SLIBCExecl("/sbin/ip", SLIBC_PROC_FORK_DEFAULT, cmd, subcmd, args, NULL)

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

	class Router6Base {
	public:
		Router6Base(const Router6Attr &);
		virtual ~Router6Base();
	public:
		virtual bool operator==(const Router6Base &rhs) const { return mAttr == rhs.mAttr; }
		virtual bool operator!=(const Router6Base &rhs) const { return mAttr != rhs.mAttr; }
		virtual bool Create() const = 0;
		virtual bool Destroy() const = 0;
		virtual bool ValidateAttr() const = 0;

		Router6Attr &getAttr() { return mAttr; }
		const Router6Attr &getAttr() const { return mAttr; }

	protected:
		Router6Attr mAttr;

	private:
		bool SetSysConfig(bool) const;
	}; // Router6Base

} // namespace router
} // namespace ipv6
} // namespace network
} // namespace syno

#endif // _NET_IPV6_ROUTER_BASE_
