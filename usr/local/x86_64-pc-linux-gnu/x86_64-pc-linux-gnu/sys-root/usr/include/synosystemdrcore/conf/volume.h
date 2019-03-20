/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_VOLUME_H__
#define __SYNOSYSDRCORE_CONF_VOLUME_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>
#include <vector>

namespace SynoSysDRCore {
namespace Conf {

enum VOLUME_STATUS {
	VOLUME_STATUS_UNKNOWN = 0x00,
	VOLUME_STATUS_UNSELECTED = 0x01,
	VOLUME_STATUS_SELECTED = 0x02,
	VOLUME_STATUS_CANCEL = 0x03
};

class VolumeData {
public:
	VolumeData() : _ID(0), _status(VOLUME_STATUS_UNKNOWN) {};
	Json::Value toJson() const;
	bool fromJson(const Json::Value &);
	bool isInitialized();
	std::string _vDiskID;
	std::string _node1VolUUID;
	std::string _node2VolUUID;
	unsigned int _ID;
	VOLUME_STATUS _status;
};

class Volume {
public:
	Volume();

	bool read();
	bool write();
	bool isValid() const;
	bool fromJson(const Json::Value &);
	Json::Value toJson() const;
	unsigned int size() const;
	VolumeData getData(unsigned int idx) const;
	VOLUME_STATUS getVolumeStatus(unsigned int volumeID) const;
	VolumeData operator[] (unsigned int idx) const;
protected:
	int getVolumeDataIdx (unsigned int volumeID) const;
	bool blInitialized;
	std::vector<VolumeData> _selectedVolume;
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_VOLUME_H__
