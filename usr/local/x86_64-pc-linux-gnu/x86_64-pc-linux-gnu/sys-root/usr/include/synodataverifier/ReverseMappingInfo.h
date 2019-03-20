/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef REVERSE_MAPPING_INFO_H
#define REVERSE_MAPPING_INFO_H

#include <cinttypes>
#include <string>

typedef enum _tag_PARITY_TYPE {
	PARITY_TYPE_UNKNOWN,
	PARITY_TYPE_P,
	PARITY_TYPE_Q
} PARITY_TYPE;

class ReverseMappingInfo {
public:
	ReverseMappingInfo(const std::string &holderPath) : holderDevicePath(holderPath) {}
	virtual ~ReverseMappingInfo() {}
	// For mapping to LVM non-data, this string is empty
	std::string holderDevicePath;
};

class ReverseMappingInfoNormal : public ReverseMappingInfo  {
public:
	ReverseMappingInfoNormal(const std::string &holderPath, uint64_t sector) : ReverseMappingInfo(holderPath), mappingStartSector(sector) {}
	uint64_t mappingStartSector;
};

class ReverseMappingInfoRaidNonData : public ReverseMappingInfo {
public:
	ReverseMappingInfoRaidNonData(const std::string &holderPath) : ReverseMappingInfo(holderPath) {}
};

class ReverseMappingInfoRaidParity : public ReverseMappingInfo {
public:
	ReverseMappingInfoRaidParity(const std::string &holderPath, PARITY_TYPE parity, uint64_t start, uint64_t end)
	: ReverseMappingInfo(holderPath), parityType(parity), chunkNumStart(start), chunkNumEnd(end) {}
	PARITY_TYPE parityType;
	uint64_t chunkNumStart;
	uint64_t chunkNumEnd;
};

class ReverseMappingInfoLvmNonData : public ReverseMappingInfo {
public:
	ReverseMappingInfoLvmNonData(const std::string &holderPath, const std::string &devicePath) : ReverseMappingInfo(holderPath), devicePath(devicePath) {}
	std::string devicePath;
};

#endif /* REVERSE_MAPPING_INFO_H */
