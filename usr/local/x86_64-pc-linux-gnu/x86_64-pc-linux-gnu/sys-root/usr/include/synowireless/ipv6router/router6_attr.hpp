/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_IPV6_ROUTER_ATTR_
#define _NET_IPV6_ROUTER_ATTR_
/*
 * This attribute is a super-set for all IPv6 router types.
 * Validation should be done in individual implementation.
 * */

#include <string>
#include <vector>
#include <json/writer.h>
extern "C" {
#include <synocore/hash.h>
}
#include <synowireless/ipv6router/router6_common.hpp>

namespace syno {
namespace network {
namespace ipv6 {
namespace router {

	class Router6Attr {
	public:
		typedef std::pair<std::string, std::string> V6LanType;
	public:
		Router6Attr();
		Router6Attr(const std::string &, bool);	// native
		Router6Attr(const std::string &, const std::string &, const std::string &,
				const std::string &, const std::string &, const std::string &, bool);
		bool operator==(const Router6Attr &) const;
		bool operator!=(const Router6Attr &rhs) const { return !(*this == rhs); }

	public:
		bool isActive() const { return !_type.empty () && _type != SZV_TYPE_INACTIVE; }
		std::string &getType() { return _type; }
		const std::string &getType() const { return _type; }
		void setWan(const std::string &w) { _wanif = w; };
		const std::string getWan() const { return ConvertInterface(_wanif); }
		void setPrefix(const std::string &p) { _prefix = p; }
		std::string &getPrefix() { return _prefix; }
		const std::string &getPrefix() const { return _prefix; }
		void setLocalV4Addr(const std::string &addr) { _v4local = addr; };
		std::string &getLocalV4Addr() { return _v4local; }
		const std::string &getLocalV4Addr() const { return _v4local; }
		std::string &getRemoteV4Addr() { return _v4remote; }
		const std::string &getRemoteV4Addr() const { return _v4remote; }
		void setLocalV6Addr(const std::string &addr) { _v6local = addr; };
		std::string &getLocalV6Addr() { return _v6local; }
		const std::string &getLocalV6Addr() const { return _v6local; }
		std::vector<V6LanType> &getV6Lan() { return _v6lan; }
		const std::vector<V6LanType> &getV6Lan() const { return _v6lan; }
		bool getDefgw() const { return _defgw; }

		static std::string ConvertInterface(const std::string &);
		void AddLan(const std::string &, const std::string &);
		void RemoveLan(const std::string &, const std::string &);
		int LoadConfig();
		int SaveConfig() const;
		int RemoveConfig() const;
		Json::Value ToJson() const;

	private:
		std::string _type;
		std::string _wanif;
		std::string _prefix;
		std::string _v4local;
		std::string _v4remote;
		std::string _v6local;
		std::vector<V6LanType> _v6lan;
		bool _defgw;
	private:
		int GenConfSection(PSLIBSZHASH *) const;
		int GenAddrSection(PSLIBSZHASH *) const;
		int GenPrefSection(PSLIBSZHASH *) const;
		int GetConfSection(PSLIBSZHASH);
		int GetAddrSection(PSLIBSZHASH);
		int GetPrefSection(PSLIBSZHASH);
		std::string GetConfigName() const;

		friend class Router6Prefix;	// for accessing raw wan interface name
	}; // Router6Attr

} // namespace router
} // namespace ipv6
} // namespace network
} // namespace syno
#endif // _NET_IPV6_ROUTER_ATTR_
