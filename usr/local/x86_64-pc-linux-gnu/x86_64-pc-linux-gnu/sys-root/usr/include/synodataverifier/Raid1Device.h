#ifndef RAID1_DEVICE_H
#define RAID1_DEVICE_H

#include "RaidDevice.h"

class Raid1Device : public RaidDevice {
public:
	Raid1Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID1; }
private:
	int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const;
	REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const;
};

#endif /* RAID1_DEVICE_H */
