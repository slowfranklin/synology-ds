#ifndef RAID10_DEVICE_H
#define RAID10_DEVICE_H

#include "RaidDevice.h"

typedef enum _tag_RAID10_MODE {
	RAID10_UNKNOWN,
	RAID10_NEAR,
	RAID10_FAR,
	RAID10_OFFSET
} RAID10_MODE;

class Raid10Device : public RaidDevice {
public:
	Raid10Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID10; }
private:
	RAID10_MODE _mode;
	int _numDataCopy;

	int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const;
	REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const;
};

#endif /* RAID10_DEVICE_H */
