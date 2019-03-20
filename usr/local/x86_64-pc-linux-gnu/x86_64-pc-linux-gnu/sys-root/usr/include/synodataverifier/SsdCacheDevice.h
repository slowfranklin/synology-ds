#ifndef SSD_CACHE_DEVICE_H
#define SSD_CACHE_DEVICE_H

#include "StorageDevice.h"

class SsdCacheDevice : public StorageDevice {
public:
	SsdCacheDevice(const std::string &devicePath);
	~SsdCacheDevice();
	int GetMappingTable(uint64_t startSector, uint64_t numSectors, MappingTable &table) const;
	// Can't do reverse mapping from ssd device now.
	REV_MAP_RESULT GetReverseMappingInfo(const std::string &subDevicePath, uint64_t subDeviceStartSector, ReverseMappingInfo *&pReverseMappingInfo) const;
	TYPE_DEVICE GetDeviceType() const { return TYPE_SSD_CACHE; }
	// Only check cache blocks on cached state. If all queried data are not cached, we will return sucess.
	CHECK_DATA_RESULT CheckDataConsistency(uint64_t startSector, uint64_t numSectors, CheckDataErrorInfo &checkDataErrorInfo) const;
private:
	std::string _queryPath;
	// Will put _ssdDevice and _diskDevice into sub device list.
	StorageDevice *_ssdDevice;
	StorageDevice *_diskDevice;

	int AppendQueriedCacheMappingToEntries(uint64_t startSector, uint64_t numSectors, std::vector<MappingEntry> &entries) const;
	void ConstructMappingEntry(uint64_t startSector, uint64_t numSectors, uint64_t ssdStartSector, STATE_MAPPING_ENTRY state, MappingEntry &entry) const;
};

#endif /* SSD_CACHE_DEVICE_H */
