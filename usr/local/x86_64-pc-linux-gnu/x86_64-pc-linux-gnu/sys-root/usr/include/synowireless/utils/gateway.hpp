/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_GATEWAY_HPP_
#define _SYNO_WIRELESS_UTILS_GATEWAY_HPP_

#include <synowireless/utils/ip_address.hpp>

namespace synowireless {
namespace utils {

class Gateway : public IPAddress {
public:
	Gateway();
	~Gateway();

	int Get(IPAddress &gateway) const;
	int GetConfig(IPAddress &gatewayConf) const;
	int Set(const IPAddress &gateway);

	int Backup();
	int Restore();

private:
	IPAddress gatewayBak;
}; /* class Gateway */

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_GATEWAY_HPP_ */
