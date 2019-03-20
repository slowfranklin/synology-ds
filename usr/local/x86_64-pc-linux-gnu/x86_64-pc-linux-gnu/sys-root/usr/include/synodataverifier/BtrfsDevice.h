/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef BTRFS_DEVICE_H
#define BTRFS_DEVICE_H

#include <vector>
#include "FileSystemDevice.h"

class BtrfsDevice : public FileSystemDevice {
public:
	BtrfsDevice(const std::string &devicePath);
	int GetMapping(const std::string &absoluteFilePath, FileMappingTable &table) const;
	int GetMappingByInode(const std::string &absoluteDirPath, uint64_t inodeNum, FileMappingTable &table) const;
	// Only support mapping one sector to a file.
	REVERSE_FILE_MAPPING_RESULT GetReverseMapping(uint64_t deviceStartSector, std::vector<FileReverseMappingInfo> &fileReverseMappingInfos) const;
private:
	struct LogicalPhysicalMapping {
		LogicalPhysicalMapping() : logical(0), physical(0), length(0) {}
		uint64_t logical;
		uint64_t physical;
		uint64_t length;
	};

	struct BtrfsReverseMappingFileInfo {
		BtrfsReverseMappingFileInfo() : inodeNum(0), subtreeNum(0), fileOffset(0) {}
		std::string filePath;
		uint64_t inodeNum;
		uint64_t subtreeNum;
		// In bytes
		uint64_t fileOffset;
	};

	int GetPhysicalPos(uint64_t logicalPos, uint64_t &physicalPos) const;
	int GetPhysicalToLogicalMapping(std::vector<LogicalPhysicalMapping> &physicalToLogicalList) const;
	// Return UINT64_MAX on not found.
	uint64_t GetMappingLogicalByte(uint64_t physicalByte, std::vector<LogicalPhysicalMapping> physicalToLogicalList) const;
	REVERSE_FILE_MAPPING_RESULT GetReverseMappingFileInfo(uint64_t logicalByte, std::vector<BtrfsReverseMappingFileInfo> &btrfsReverseMappingFileInfos) const;
	int DoIOSync(const char *szMountPath) const;
};
#endif /*BTRFS_DEVICE_H*/
