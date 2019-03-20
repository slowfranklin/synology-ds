#ifndef PARTITION_DEVICE_H
#define PARTITION_DEVICE_H

#include "StorageDevice.h"

class PartitionDevice : public StorageDevice {
public:
	PartitionDevice(const std::string &devicePath);
	~PartitionDevice();
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	TYPE_DEVICE GetDeviceType() const { return TYPE_PARTITION; }
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const {return CHECK_DATA_NOT_SUPPORT;}
private:
	uint64_t _startSectorInDisk;
	int CreateSubDevice();
	int GetStartSectorInDisk();
};
#endif /* PARTITION_DEVICE_H */
