#ifndef NULL_DEVICE_H
#define NULL_DEVICE_H

#include "StorageDevice.h"

class NullDevice : public StorageDevice {
public:
	NullDevice(const std::string &devicePath);
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const {return 0;}
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const { return REV_MAP_NOT_SUPPORT; }
	TYPE_DEVICE GetDeviceType() const { return TYPE_NULL; }
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const {return CHECK_DATA_NOT_SUPPORT;}
private:
};
#endif /* NULL_DEVICE_H */
