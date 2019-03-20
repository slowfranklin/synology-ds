/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef LOGICAL_VOLUME_DEVICE_H
#define LOGICAL_VOLUME_DEVICE_H

#include "StorageDevice.h"

struct DmTargetEntry {
	DmTargetEntry() : lvStartSector(0), length(0) {}
	uint64_t lvStartSector;
	uint64_t length;
	std::string type;
	std::string args;
};

struct DmTable {
	std::vector<DmTargetEntry> dmTargetEntries;
};

class LogicalVolumeDevice : public StorageDevice {
public:
	LogicalVolumeDevice(const std::string &devicePath);
	virtual ~LogicalVolumeDevice();
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	TYPE_DEVICE GetDeviceType() const { return TYPE_LOGICAL_VOLUME; }
	static bool IsSubDeviceSectorInLogicalVolume(dev_t subDeviceId, uint64_t subDeviceStartSector, dev_t lvDeviceId);
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const {return CHECK_DATA_NOT_SUPPORT;}
	static int GetDmTable(dev_t lvDeviceId, DmTable &dmTable);
private:
	struct LvMappingEntry {
		LvMappingEntry() : lvStartSector(0), numSectors(0), subDeviceStartSector(0), pSubDevice(NULL) {}
		uint64_t lvStartSector;
		uint64_t numSectors;
		uint64_t subDeviceStartSector;
		StorageDevice *pSubDevice;
	};

	uint64_t _sectorSize;
	std::vector<uint64_t> _minEntryStartSectorInSubDevices;
	std::vector<LvMappingEntry> _lvMappingEntries;
	void AddMappingEntry(uint64_t startSector, uint64_t numSectors, int subDeviceNum, std::vector<MappingEntry> &entries) const;
	int InitializeDeviceInfo();
};

#endif /* LOGICAL_VOLUME_DEVICE_H */
