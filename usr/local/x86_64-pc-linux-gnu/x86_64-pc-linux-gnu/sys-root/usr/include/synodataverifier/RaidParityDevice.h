#ifndef RAID_PARITY_DEVICE_H
#define RAID_PARITY_DEVICE_H

#include "RaidDevice.h"
#include "StripeGroup.h"

class RaidParityDevice : public RaidDevice {
public:
	RaidParityDevice(const std::string &devicePath, bool blHasParityQ, RAID_LEVEL raidLevel);
private:
	bool _blHasParityQ;
	int _numDataDevice;
	int _numParityDevice;
	StripeGroup _stripeGroup;

	int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const;
	REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const;
	CHECK_DATA_RESULT CheckConsistencyInStripe(const MappingEntry &entry, CheckDataErrorInfo &checkDataErrorInfo) const;
};

#endif /* RAID_PARITY_DEVICE_H */
