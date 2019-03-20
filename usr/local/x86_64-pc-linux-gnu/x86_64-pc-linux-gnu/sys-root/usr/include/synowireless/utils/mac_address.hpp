/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_MAC_ADDRESS_HPP_
#define _SYNO_WIRELESS_UTILS_MAC_ADDRESS_HPP_

#include <string>

namespace synowireless {
namespace utils {

class MacAddress {
public:
	MacAddress();

	MacAddress(const MacAddress &macAddress);
	MacAddress(const std::string &strIfMac);

	~MacAddress();

	MacAddress &operator=(const std::string &strIfMac);
	MacAddress operator+(int offset) const;
	bool operator==(const MacAddress &macAddress) const;

	std::string ToString() const;
	const char *ToCString() const;
	operator std::string();
	operator const char *();

	friend std::istream &operator>>(std::istream &is, MacAddress &macAddress);

	bool IsFormalized() const;

private:
	int Formalize();
	bool IsFormalizable() const;

private:
	std::string strMac;
}; /* class MacAddress */

std::istream &operator>>(std::istream &is, MacAddress &macAddress);

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_MAC_ADDRESS_HPP_ */
