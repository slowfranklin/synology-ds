/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef STORAGE_DEVICE_CRATER_H
#define STORAGE_DEVICE_CRATER_H

#include <cctype>
#include <libgen.h>
#include "StorageDevice.h"
#include "SystemInfoHelper.h"

#define SZK_TYPE_NAME_LOOP "loop"
#define SZK_TYPE_NAME_SD "sd"
#define SZK_TYPE_NAME_MD "md"
#define SZK_TYPE_NAME_DEVICE_MAPPER "device-mapper"
#define SZK_TYPE_NAME_DRBD "drbd"

typedef enum _tag_UPPER_DEVICE_RESULT {
	UPPER_DEVICE_ERROR = -1,
	UPPER_DEVICE_FOUND,
	UPPER_DEVICE_NONE,
	// Holded by LVM, but assigned sector is not mapping to any Lv device.
	UPPER_DEVICE_LVM_HOLD_NOT_USE
} UPPER_DEVICE_RESULT;

class StorageDeviceCreater {
public:
	StorageDeviceCreater(){}
	~StorageDeviceCreater(){}
	//TODO: support numSector
	static UPPER_DEVICE_RESULT GetUpperDevicePath(const StorageDevice *pDevice, uint64_t startSector, std::string &upperDevicePath);
	static StorageDevice* Create(const std::string &devicePath);
	static StorageDevice* Create(int major, int minor, const DevMapping *pDeviceList);
	static std::string GetDevicePathByDeviceList(int major, int minor, const DevMapping *pDeviceList);
	// Return 0 on error
	static dev_t GetDeviceId(const std::string &path);
	static int GetMajor(const std::string &path);
	static int GetMinor(const std::string &path);
	static bool IsRaidDevice(dev_t deviceId);
	static bool IsLoopDevice(dev_t deviceId);
	// For SATA device / M.2 SATA device / SAS device
	static bool IsPartitionDevice(dev_t deviceId);
	// For SATA device / M.2 SATA device / SAS device
	static bool IsDiskDevice(dev_t deviceId);
	// For NVMe Device
	static bool IsNVMePartitionDevice(const std::string &path, dev_t deviceId);
	// For NVMe Device
	static bool IsNVMeDiskDevice(const std::string &path, dev_t deviceId);
	static bool IsLogicalVolumeDevice(dev_t deviceId);
	static bool IsSsdCacheDevice(dev_t deviceId);
	static bool IsDrbdDevice(dev_t deviceId);
private:
};
#endif /* STORAGE_DEVICE_CRATER_H */
