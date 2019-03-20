// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETLINK_IF_MAP_HPP__
#define __SYNO_NETWORK_NETLINK_IF_MAP_HPP__

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <synocore/synoglobal.h>

namespace synonetwork {
namespace network {
namespace module {

template<typename V>
class IFMap {
public:
	IFMap(): def_()
	{}
	IFMap(const V &def): def_(def)
	{}

	bool IsEqual(const std::string &ifname, const V &value) const
	{
		typename std::map<std::string, V>::const_iterator iter = interfaces_.find(ifname);
		if (interfaces_.end() == iter) {
			return false;
		} else {
			return iter->second == value;
		}
	}

	void Set(const std::string &ifname, const V &value)
	{
		typename std::map<std::string, V>::iterator iter = interfaces_.find(ifname);
		if (interfaces_.end() == iter) {
			interfaces_.insert(std::make_pair(ifname, value));
		} else if (value != iter->second) {
			iter->second = value;
		}
	}

	std::string ToStr() const
	{
		std::stringstream ssInfo;

		for (typename std::map<std::string, V>::const_iterator iter = interfaces_.begin();
				iter != interfaces_.end(); iter++) {
				ssInfo << "[" << iter->first << "]: [" << iter->second << "]/";
		}
		return ssInfo.str();
	}

	bool IsExist(const std::string &ifname) const
	{
		return interfaces_.end() != interfaces_.find(ifname);
	}

	const V &Get(const std::string &ifname) const
	{
		typename std::map<std::string, V>::const_iterator iter = interfaces_.find(ifname);
		if (interfaces_.end() == iter) {
			return def_;
		} else {
			return iter->second;
		}
	}
	void Clear()
	{
		interfaces_.clear();
	}
	void Copy(IFMap &other) const
	{
		other.Clear();
		for (typename std::map<std::string, V>::const_iterator iter = interfaces_.begin();
				iter != interfaces_.end(); iter++) {
			other.Set(iter->first, iter->second);
		}
	}
	std::vector<std::string> GetIfnames() const
	{
		std::vector<std::string> ifnames;
		for (typename std::map<std::string, V>::const_iterator iter = interfaces_.begin();
				iter != interfaces_.end(); iter++) {
			ifnames.push_back(iter->first);
		}
		return ifnames;
	}
	bool operator==(const IFMap &other) const
	{
		std::vector<std::string> ifnames = GetIfnames();
		std::vector<std::string> ifnames2 = other.GetIfnames();

		if (!std::equal(ifnames.begin(), ifnames.end(), ifnames2.begin())) {
			return false;
		}
		for (typename std::map<std::string, V>::const_iterator iter = interfaces_.begin();
				iter != interfaces_.end(); iter++) {
			if (iter->second != other.Get(iter->first)) {
				return false;
			}
		}
		return true;
	}
private:
	V def_;
	std::map<std::string, V> interfaces_;

}; /* class IFMap */

} /* namespace module */
} /* namespace network */
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETLINK_IF_MAP_HPP__ */
