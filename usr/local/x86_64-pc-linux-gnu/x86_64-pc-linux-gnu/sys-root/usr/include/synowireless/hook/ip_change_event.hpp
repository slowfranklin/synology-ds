/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_IP_CHANGE_EVENT_HPP_
#define _SYNO_WIRELESS_UTILS_IP_CHANGE_EVENT_HPP_

#include <string>
#include <synonetsdk/net.h>

namespace synowireless {
namespace hook {

int NetIPChangeEvent(const IPTYPE type,
					 const std::string &ifname,
					 const std::string &oriAddr,
					 const std::string &newAddr,
					 const int prefixlen);

} /* namespace hook */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_IP_CHANGE_EVENT_HPP_ */
