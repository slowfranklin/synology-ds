#ifndef DRBD_DEVICE_H
#define DRBD_DEVICE_H

#include "StorageDevice.h"

class DrbdDevice : public StorageDevice {
public:
	DrbdDevice(const std::string &devicePath);
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const { return REV_MAP_NOT_SUPPORT; }
	TYPE_DEVICE GetDeviceType() const { return TYPE_DRBD; }
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const {return CHECK_DATA_NOT_SUPPORT;}
private:
	int InitializeSubDevice();
};
#endif /* DRBD_DEVICE_H */
