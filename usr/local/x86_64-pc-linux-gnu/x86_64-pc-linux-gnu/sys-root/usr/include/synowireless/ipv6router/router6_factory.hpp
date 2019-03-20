/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_FACTORY_
#define _NET_IPV6_ROUTER_FACTORY_
#include <string>
#include <json/writer.h>
#include <synowireless/ipv6router/router6_attr.hpp>

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

	enum IPV6ROUTER_ERR {
		IPV6ROUTER_NO_ERR = 0,
		IPV6ROUTER_ERR_NOMEM,
		IPV6ROUTER_ERR_BAD_PARAM,
		IPV6ROUTER_ERR_NO_PUBLIC_IP,
	};

	class Router6Factory {
	public:
		Router6Factory();
		Router6Base *newRouterV6Instance(const std::string &, const std::string & = std::string());
		Router6Base *newRouterV6Instance(const Json::Value &);
		Router6Base *newRouterV6Instance(const std::string &, const Json::Value &);
		IPV6ROUTER_ERR GetError() { IPV6ROUTER_ERR err = mErr; mErr = IPV6ROUTER_NO_ERR; return err; }
		bool HasError() const { return IPV6ROUTER_NO_ERR != mErr; }

	private:
		IPV6ROUTER_ERR mErr;
	private:
		void SetError(IPV6ROUTER_ERR err) { mErr = err; }
		Router6Attr *new6in4Attr(const Json::Value &);
		Router6Attr *new6to4Attr(const Json::Value &);
		Router6Attr *newDHCPPDAttr(const Json::Value &);
		Router6Base *newRouterV6InstanceImpl(const Router6Attr &);
		std::string gen6to4Info(const std::string &, const char *);
	}; // Router6Factory

} // namespace router
} // namespace ipv6
} // namespace network
} // namespace syno

#endif // _NET_IPV6_ROUTER_FACTORY_
