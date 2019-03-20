/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_UTILS_H__
#define __SYNOSYSDRCORE_UTILS_H__
#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf.h>

typedef enum {
	DISPATCH_TARGET_UNKNOWN = 0,
	DISPATCH_TARGET_MAINSITE,
	DISPATCH_TARGET_DRSITE,
	DISPATCH_TARGET_LOCAL,
	DISPATCH_TARGET_REMOTE,
} DISPATCH_TARGET;

namespace SynoSysDRCore {
namespace Utils {

std::string getNodeID(const DISPATCH_TARGET &);
std::string getRemoteNodeID();
std::string getRemoteCredID();
std::string getLocalNodeID();
std::string getMainSiteNodeID();
std::string getDRSiteNodeID();
bool getRoleData(SynoSysDRCore::Conf::Role& role);
bool isLocalNode1();
bool isLocalMainSite();
bool isLocalDRSite();
bool isLocalCDSM();
SYSDR_ROLE getLocalRole();
SYSDR_ROLE getRemoteRole();
bool setLocalRole(SYSDR_ROLE);
bool setRemoteRole(SYSDR_ROLE);
SynoSysDRCore::Conf::Node getLocalNodeData();
SynoSysDRCore::Conf::Node getRemoteNodeData();
SynoSysDRCore::Conf::Node getMainSiteNode();
SynoSysDRCore::Conf::Node getDRSiteNode();
const std::string &getNode1TunnelAddress();
const std::string &getNode2TunnelAddress();

bool getStringValue(const Json::Value &, const std::string &, std::string &output);
bool getUnsignedValue(const Json::Value&, const std::string &, unsigned &output);
bool getUnsigned64Value(const Json::Value&, const std::string &, unsigned long long &output);
bool getIntValue(const Json::Value &, const std::string &, int &output);
bool getBoolValue(const Json::Value &, const std::string &, bool &output);
bool getJsonValue(const Json::Value &, const std::string &, Json::Value &output);

}//Utils
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_UTILS_H__
