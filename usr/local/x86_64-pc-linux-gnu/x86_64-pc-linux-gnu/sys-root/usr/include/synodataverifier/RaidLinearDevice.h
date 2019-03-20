#ifndef RAID_LINEAR_DEVICE_H
#define RAID_LINEAR_DEVICE_H

#include "RaidDevice.h"

class RaidLinearDevice : public RaidDevice {
public:
	RaidLinearDevice(const std::string &devicePath) : RaidDevice(devicePath) {}
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID_LINEAR; }
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
private:
	int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const;
	REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const { return CHECK_DATA_ERROR;}
};

#endif /* RAID_LINEAR_DEVICE_H */
