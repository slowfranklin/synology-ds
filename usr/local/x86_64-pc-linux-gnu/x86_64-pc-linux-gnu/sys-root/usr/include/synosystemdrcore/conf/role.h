/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_ROLE_H__
#define __SYNOSYSDRCORE_CONF_ROLE_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>

namespace SynoSysDRCore {
namespace Conf {

class Role {
public:
	Role(const std::string& localNodeID, SYSDR_ROLE localRole);
	Role();
	~Role();

	bool reload();
	bool write();
	static bool reset();
	bool fromJson(const Json::Value&);
	Json::Value toJson() const;
	bool isValid() const;

	std::string getLocalNodeID() const;
	SYSDR_ROLE getLocalRole() const;
	SYSDR_ROLE getRemoteRole() const;
	bool setLocalRole(SYSDR_ROLE);
	bool setRemoteRole(SYSDR_ROLE);
private:
	std::string _localNodeID;
	SYSDR_ROLE _localRole;
	SYSDR_ROLE _remoteRole;
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_ROLE_H__
