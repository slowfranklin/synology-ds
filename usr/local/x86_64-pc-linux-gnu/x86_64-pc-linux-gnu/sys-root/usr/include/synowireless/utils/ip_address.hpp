/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_IP_ADDRESS_HPP_
#define _SYNO_WIRELESS_UTILS_IP_ADDRESS_HPP_

extern "C" {
#include <netinet/in.h>
}

#include <string>
#include <vector>

#define ADDRESS_1	"0.0.0.1"

namespace synowireless {
namespace utils {

class IPAddress {
public:
	IPAddress();
	IPAddress(const IPAddress &other);
	IPAddress(const std::string &strAddress);
	~IPAddress();

	IPAddress &operator=(const IPAddress &other);
	IPAddress &operator=(const std::string &strAddress);
	bool operator==(const IPAddress &other) const;
	bool operator!=(const IPAddress &other) const;

	std::string ToString() const;
	const char *ToCString() const;
	operator std::string() const;
	operator const char *() const;

	bool IsEmpty() const;

	static std::vector<std::pair<std::string, int> > GetIPv4Address(const std::string &ifname);
	static std::vector<std::pair<std::string, int> > GetIPv6Address(const std::string &ifname);
	static std::vector<std::pair<std::string, int> > GetIPv4Network(const std::string &ifname);
	static std::vector<std::pair<std::string, int> > GetIPv6Network(const std::string &ifname);
	static std::string GetIPv6NetworkPart(const std::string &ip, int prefixLength);

	friend IPAddress GetNetwork(const IPAddress &ipAddress, const IPAddress &netMask);
	friend IPAddress GetIpAddressBegin(const IPAddress &network, const IPAddress &netMask);
	friend IPAddress GetIpAddressEnd(const IPAddress &network, const IPAddress &netMask);
	friend IPAddress GetNextNetwork(const IPAddress &network, const IPAddress &netMask);
	friend std::istream &operator>>(std::istream &is, IPAddress &ipAddress);

private:
	template<int AF>
	static const char *addrToString(const struct sockaddr *sa, const struct sockaddr *nop, char *s);

	template<int AF>
	static const char *networkToString(const struct sockaddr *sa, const struct sockaddr *mask, char *s);

	template<int AF>
	static int netmaskToPrefixLength(struct sockaddr *sa);

	template<int AF, int ADDRLEN, typename AddressTransformFunc>
	static std::vector<std::pair<std::string, int> > GetIPAddress(const std::string &ifname, AddressTransformFunc func);

	in_addr address;
	std::string strAddress;
}; /* class IPAddress */

std::istream &operator>>(std::istream &is, IPAddress &ipAddress);

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_IP_ADDRESS_HPP_ */
