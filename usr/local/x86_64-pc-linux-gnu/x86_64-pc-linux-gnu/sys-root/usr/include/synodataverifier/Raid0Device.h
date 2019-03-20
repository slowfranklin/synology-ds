#ifndef RAID0_DEVICE_H
#define RAID0_DEVICE_H

#include "RaidDevice.h"

struct Zone {
	/*
	 *  0  1  2  3 - device number
	 * ------------
	 *  0  1  2  3 - zone 0 start chunk num = 0
	 *  4  5  6  7 - zone 0 hight (in chunk) = 2, total chunks = 8
	 * ------------
	 *  9    10  8 - zone 1 start chunk num = 8, hight (in chunk) = 1, total chunks = 3
	 * ------------
	 *       12 11 - zone 2 start chunk num = 11
	 * ------------
	 *          13 - zone 3
	 * zone 1 num of sub devices = 3
	 * zone 1 sorted device numbers = {3, 0, 2} (sorted by chunk numbers in the same stripe)
	 *
	 * Note: In zone 1, linux kernel will put the first chunk in this zone (chunk number = 8) in device 3, not device 0,
	 *       it use 8 (chunk num in raid) % 3 (num device in this zone) to get 2, then store in device number 2 of this zone
	 *       (device 1 is not in this zone, so the device 3 in raid is device 2 in this zone).
	 *       So, we make a list of mapping device number to raid of zone named sortedDeviceNums,
	 *       and stores {3, 0, 2} in zone 1. (the order of original sub device number in this zone)
	 */
	Zone() : numSubDevices(0), startChunkNum(0), startStripeNum(0), hightInChunk(0), totalChunks(0) {}
	int numSubDevices;
	uint64_t startChunkNum;
	uint64_t startStripeNum;
	uint64_t hightInChunk;
	uint64_t totalChunks;
	// Store the device numbers of devices in this zone, sorted by chunk numbers in the same stripe
	std::vector<int> sortedDeviceNums;
};

class Raid0Device : public RaidDevice {
public:
	Raid0Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID0; }
private:
	std::vector<Zone> _zones;
	std::vector<uint64_t> _numChunksInSubDevices;
	int GetMappingSector(uint64_t startSector, std::vector<MappingSector> &mappingSectors) const;
	REV_MAP_RESULT GetReverseMappingInfoByDeviceNumber(int subDeviceNumber, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	CHECK_DATA_RESULT CheckDataConsistencyByMappingTable(const MappingTable &mappingTable, CheckDataErrorInfo &checkDataErrorInfo) const { return CHECK_DATA_NOT_SUPPORT;}
};

#endif /* RAID0_DEVICE_H */
