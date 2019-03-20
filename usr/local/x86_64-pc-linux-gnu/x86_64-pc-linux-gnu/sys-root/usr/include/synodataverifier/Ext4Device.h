/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef EXT4_DEVICE_H
#define EXT4_DEVICE_H

#include "FileSystemDevice.h"

class Ext4Device : public FileSystemDevice {
public:
	Ext4Device(const std::string &devicePath);
	int GetMapping(const std::string &absoluteFilePath, FileMappingTable &table) const;
	int GetMappingByInode(const std::string &absoluteDirPath, uint64_t inodeNum, FileMappingTable &table) const;
	// Only support mapping one sector to a file
	REVERSE_FILE_MAPPING_RESULT GetReverseMapping(uint64_t deviceStartSector, std::vector<FileReverseMappingInfo> &fileReverseMappingInfos) const;
private:
	int _blockSizeInSector;

	int InitializeBlockSize();
	int GetMappingCore(FILE *pFile, FileMappingTable &table) const;
	REVERSE_FILE_MAPPING_RESULT GetReverseMappingInodeNum(uint64_t deviceSector, uint64_t &inodeNum) const;
	// Return empty string on error
	int GetReverseMappingFilePath(uint64_t inodeNum, std::string &relativePath) const;
};
#endif /*EXT4_DEVICE_H*/
