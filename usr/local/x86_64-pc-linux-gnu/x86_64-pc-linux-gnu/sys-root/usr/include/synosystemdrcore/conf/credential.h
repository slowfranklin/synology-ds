/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_CREDENTIAL_H__
#define __SYNOSYSDRCORE_CONF_CREDENTIAL_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>

namespace SynoSysDRCore {
namespace Conf {

class Credential {
public:
	Credential();
	Credential(const std::string &local, const std::string &remote);
	~Credential();

	bool set(const std::string &local, const std::string &remote);
	bool fromJson(const Json::Value &);
	Json::Value toJson();
	Json::Value toRemoteJson();

	bool read();
	bool write();
	static bool reset();
	bool isValid() const;

	std::string getRemoteCredential() const;
	std::string getRemoteCredential();
	std::string getLocalCredential() const;
	std::string getLocalCredential();
	bool updateLocalCredential(const std::string &);
	bool updateRemoteCredential(const std::string &);
private:
	bool _hasBeenRead;
	Json::Value _credential;
	std::string _localCredential;
	std::string _remoteCredential;
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_CREDENTIAL_H__
