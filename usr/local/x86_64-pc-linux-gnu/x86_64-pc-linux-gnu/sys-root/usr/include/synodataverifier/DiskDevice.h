#ifndef DISK_DEVICE_H
#define DISK_DEVICE_H

#include "StorageDevice.h"

class DiskDevice : public StorageDevice {
public:
	DiskDevice(const std::string &devicePath);
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const {return 0;}
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const { return REV_MAP_NOT_SUPPORT; }
	TYPE_DEVICE GetDeviceType() const { return TYPE_DISK; }
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const {return CHECK_DATA_NOT_SUPPORT;}
private:
};
#endif /* DISK_DEVICE_H */
