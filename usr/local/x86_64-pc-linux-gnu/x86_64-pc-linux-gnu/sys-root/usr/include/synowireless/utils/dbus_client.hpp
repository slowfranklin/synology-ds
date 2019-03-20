/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_DBUS_CLIENT_HPP_
#define _SYNO_WIRELESS_UTILS_DBUS_CLIENT_HPP_

#include <string>

namespace synowireless {
namespace utils {

int GetGatewayPriority(const std::string &ifname, const std::string &type);
bool SetGatewayInfo(const std::string &ifname,
					const std::string &type,
					const std::string &gateway,
					const std::string &dns,
					const std::string &cls,
					int priority,
					bool refresh);
bool DelGatewayInfo(const std::string &ifname, const std::string &type, bool refresh);
bool RefreshGateway(const std::string &type);

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_DBUS_CLIENT_HPP_ */
