/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef RAID_DEVICE_H
#define RAID_DEVICE_H

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <vector>
#include <cinttypes>
#include <cctype>
#include "StorageDevice.h"
#include "SystemInfoHelper.h"

// Reference to Linux/drivers/md/raid5.h
typedef enum _tag_RAID_PARITY_ALGORITHM {
	ALGORITHM_LEFT_ASYMMETRIC = 0,
	ALGORITHM_RIGHT_ASYMMETRIC = 1,
	ALGORITHM_LEFT_SYMMETRIC = 2,
	ALGORITHM_RIGHT_SYMMETRIC = 3,
	ALGORITHM_PARITY_N = 5,
	ALGORITHM_LEFT_ASYMMETRIC_6 = 16,
	ALGORITHM_RIGHT_ASYMMETRIC_6 = 17,
	ALGORITHM_LEFT_SYMMETRIC_6 = 18,
	ALGORITHM_RIGHT_SYMMETRIC_6 = 19,
	ALGORITHM_RAID_F1_0 = ALGORITHM_LEFT_SYMMETRIC,
	ALGORITHM_RAID_F1_1 = 32,
	ALGORITHM_RAID_F1_2 = 33,
	ALGORITHM_RAID_F1_3 = 34,
	ALGORITHM_RAID_F1_4 = 35,
} RAID_PARITY_ALGORITHM;

class RaidDevice : public StorageDevice {
public:
	RaidDevice(const std::string &devicePath);
	virtual ~RaidDevice();
	virtual int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const;
protected:
	struct MappingSector {
		MappingSector() : startSector(0), deviceNum(0) {}
		uint64_t startSector;
		int deviceNum;
	};

	// Save RAID_PARITY_ALGORITHM or a int value in raid10 (0 in raid0 and raid1)
	int _layout;
	uint64_t _chunkSizeByte;
	uint64_t _sectorSize;
	uint64_t _sectorsInChunk;
	std::vector<uint64_t> _subDeviceDataOffsets;

	int AddMappingEntry(uint64_t startSector, uint64_t numSectors, std::vector<MappingEntry> &entries) const;
	virtual int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const = 0;
	virtual REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const = 0;
	REV_MAP_RESULT HandleReverseMappingInfoNormalOrNotUsed(uint64_t mappingSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	// For raid1 and raid10
	CHECK_DATA_RESULT CheckConsistencyInData(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const;
	int GetSubDeviceNumber(const std::string &subDevicePath) const;
private:
	struct DiskInfo {
		int number;
		int major;
		int minor;
		int raid_disk;
		int state;
	};

	int InitializeDeviceInfo();
	int InitializeSubDeviceInfo();
	int GetDiskInfo(int numDevice, std::vector<DiskInfo> &disks) const;
	int InitializeSubDeviceDataOffset();
	virtual CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const = 0;
};

#endif /* RAID_DEVICE_H */
