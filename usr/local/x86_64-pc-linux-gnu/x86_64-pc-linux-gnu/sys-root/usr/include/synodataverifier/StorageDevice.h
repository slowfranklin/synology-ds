/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef STORAGE_DEVICE_H
#define STORAGE_DEVICE_H

#include <string>
#include <vector>
#include <cinttypes>
#include <libgen.h>
#include <stdexcept>
#include <sys/types.h>
#include "OutputFunctions.h"
#include "ReverseMappingInfo.h"
#include "MathTool.h"
#include "Global.h"

#define SZD_SYS_DEV_BLOCK_DIR "/sys/dev/block/"
#define SZ_NULL_DEVICE_PATH "/"

// Raid 6 use a GaliosField(2^8), so raid can support 255 data disk + 2 parity disks, not over 300
#define MAX_NUM_SUBDEVICE 300

// When add a new device type, please updata the mapping strings in GetDeviceTypeString() function.
typedef enum _tag_TYPE_DEVICE {
	TYPE_ERROR,
	TYPE_PARTITION,
	TYPE_DISK,
	TYPE_RAID0,
	TYPE_RAID1,
	TYPE_RAID5,
	TYPE_RAID6,
	TYPE_RAIDF1,
	TYPE_RAID10,
	TYPE_RAID_LINEAR,
	TYPE_LOGICAL_VOLUME,
	TYPE_LOOP,
	TYPE_SSD_CACHE,
	TYPE_NULL,
	TYPE_DRBD
} TYPE_DEVICE;

typedef enum _tag_REV_MAP_RESULT {
	REV_MAP_NOT_SUPPORT = -2,
	REV_MAP_ERROR = -1,
	REV_MAP_SUCCESS = 0,
	REV_MAP_RAID_PARITY,
	REV_MAP_RAID_METADATA,
	REV_MAP_RAID_HOLD_NOT_USED,
	REV_MAP_LVM_METADATA,
	REV_MAP_LVM_HOLD_NOT_USED
} REV_MAP_RESULT;

typedef enum _tag_CHECK_DATA_RESULT {
	CHECK_DATA_ERROR = -1,
	CHECK_DATA_SUCCESS = 0,
	CHECK_DATA_NOT_CONSISTENT,
	CHECK_DATA_NOT_SUPPORT
} CHECK_DATA_RESULT;

typedef enum _tag_STATE_MAPPING_ENTRY {
	STATE_NORMAL,
	STATE_UNCACHED,
	STATE_CACHED,
	STATE_DIRTY,
	STATE_DIRTY_PIN,
	STATE_CACHED_PIN
} STATE_MAPPING_ENTRY;

class StorageDevice;

// Location in subdevice
struct MappingLocation {
	MappingLocation() : pSubDevice(NULL), startSector(0) {}
	StorageDevice *pSubDevice;
	uint64_t startSector;
};

// Location in device
struct MappingEntry {
	MappingEntry() : startSector(0), numSectors(0), state(STATE_NORMAL) {}
	uint64_t startSector;
	uint64_t numSectors;
	STATE_MAPPING_ENTRY state;
	std::vector<MappingLocation> locations;
};

struct MappingTable {
	MappingTable() : pMainDevice(NULL) {}
	// Reserved design
	//unsigned char *pWrittenData;
	//long int ioSeqNum;
	StorageDevice *pMainDevice;
	std::vector<MappingEntry> entries;
};

struct SubDeviceErrorLocation {
	SubDeviceErrorLocation() : pSubDevice(NULL), sector(0) {}
	StorageDevice *pSubDevice;
	uint64_t sector;
};

struct CheckDataErrorInfo {
	CheckDataErrorInfo() : errorSector(0), byteNum(0) {}
	uint64_t errorSector;
	// First error byte in error sector
	uint64_t byteNum;
	std::vector<SubDeviceErrorLocation> subDeviceErrorLocation;
};

class StorageDevice{
public:
	StorageDevice(const std::string &devicePath);
	virtual ~StorageDevice();
	/*
	 * Return > 0: Number of entries in mapping table.
	 *        0: No sub device
	 *        -1: On error
	 */
	virtual int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const = 0;
	virtual REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const = 0;
	// For raid device
	virtual CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const = 0;
	const std::string& GetDevicePath() const { return _devicePath; }
	const std::string& GetDeviceInfoDir() const { return _deviceInfoDir; }
	virtual TYPE_DEVICE GetDeviceType() const = 0;
	const std::string& GetDeviceTypeString() const;
	int GetSubDevices(std::vector<StorageDevice *> &pSubDevices) const;
	uint64_t GetSize() const {return _sizeInSector;}
	dev_t GetDeviceId() const {return _deviceId;}
	int GetMajor() const {return major(_deviceId);}
	int GetMinor() const {return minor(_deviceId);}
protected:
	dev_t _deviceId;
	uint64_t _sizeInSector;
	std::string _deviceInfoDir;
	std::string _deviceName;
	std::string _devicePath;
	std::vector<StorageDevice *> _pSubDevices;
	CHECK_DATA_RESULT CheckConsistencyInDataByEntry(const MappingEntry &entry, CheckDataErrorInfo &checkDataErrorInfo) const;
};

#endif /*STORAGE_DEVICE_H*/
