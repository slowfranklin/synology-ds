/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_NETWORK_H__
#define __SYNOSYSDRCORE_CONF_NETWORK_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>
#include <vector>

namespace SynoSysDRCore {
namespace Conf {

class Network {
public:
	Network();

	bool read();
	bool write() const;
	bool isValid() const;
	bool fromJson(const Json::Value &);
	Json::Value toJson() const;
	enum NetworkMode {
		SDR_NETWORK_MODE_UNKNOWN = 0x00,
		SDR_NETWORK_MODE_NONE    = 0x01,
		SDR_NETWORK_MODE_HA_IP   = 0x02,
		SDR_NETWORK_MODE_DDNS    = 0x03,
	};
	NetworkMode getMode() const {
		return _mode;
	}
protected:
	NetworkMode _mode;
	Json::Value _setting;
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_NETWORK_H__
