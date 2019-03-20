/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_NETWORK_UTILS_HPP_
#define _SYNO_NETWORK_NETWORK_UTILS_HPP_

#include <string>
#include <json/value.h>

namespace synonetwork {
namespace network {

int GetSubnetFormat(const std::string &strIp, const std::string &strMask, std::string &strSubnet);
int FilterList(std::string strType, Json::Value &list);
bool IsEthernetLinkDetected(const std::string &strIfName);

} /* namespace network */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_NETWORK_UTILS_HPP_ */
