/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_H__
#define __SYNOSYSDRCORE_CONF_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>
#include <synosystemdrcore/conf/role.h>
#include <synosystemdrcore/conf/node.h>
#include <synosystemdrcore/conf/network.h>
#include <synosystemdrcore/conf/credential.h>
#include <synosystemdrcore/conf/volume.h>
#include <synosystemdrcore/conf/pkg_enabled_info.h>

namespace SynoSysDRCore {
namespace Conf {

const unsigned int SDR_MAX_SUPPORT_VOLUME = 4;

class ConfBase {
public:
	ConfBase();
	ConfBase(const std::string &lockFile, const std::string &confFile);
	~ConfBase();
	bool setConf(const std::string &key, const Json::Value &value);
	bool getConf(const std::string &key, Json::Value &value);
	bool initConf(const Json::Value& ConfKeyValue);
	bool getAllConf(Json::Value& ConfKeyValue);
	bool setAllConf(const Json::Value& ConfKeyValue);
	bool resetConf();
protected:
	virtual bool checkConfCanSet();
private:
	std::string _LockFile;
	std::string _ConfFile;
};

bool setConf(const std::string &key, const Json::Value &value);
bool getConf(const std::string &key, Json::Value &value);
bool initConf(const Json::Value& ConfKeyValue);
bool getAllConf(Json::Value& ConfKeyValue);
bool setAllConf(const Json::Value& ConfKeyValue);
bool resetConf();
bool setSystemDRRunning(bool blRunning);
bool setEncrypt(const bool isEncrypt);
bool setAppAwared(const bool isAppAwared);
bool isEncrypt(bool &isEncrypt);
bool isAppAwared(bool &isAppAwared);
bool getAccount(std::string &account);

SDR_BIND_MODE getBindMode();

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_H__
