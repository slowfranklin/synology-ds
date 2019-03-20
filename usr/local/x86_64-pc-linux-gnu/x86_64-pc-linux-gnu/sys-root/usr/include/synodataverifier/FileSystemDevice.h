/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef FILE_SYSTEM_DEVICE_H
#define FILE_SYSTEM_DEVICE_H

#include "Global.h"
#include "StorageDevice.h"
#include "SystemInfoHelper.h"

#define MAX_NUMBER_LENGTH 100

typedef enum _tag_STATE_FILE_MAPPING_ENTRY {
	STATE_FILE_NORMAL,
	STATE_FILE_UNINIT
} STATE_FILE_MAPPING_ENTRY;

struct FileMappingEntry {
	FileMappingEntry() : fileStartSector(0), numSectors(0), deviceStartSector(0), state(STATE_FILE_NORMAL) {}
	uint64_t fileStartSector;
	uint64_t numSectors;
	uint64_t deviceStartSector;
	STATE_FILE_MAPPING_ENTRY state;
};

struct BtrfsInlineDataInfo {
	BtrfsInlineDataInfo() : deviceStartByte(0), numBytes(0) {}
	uint64_t deviceStartByte;
	uint64_t numBytes;
};

typedef enum _tag_MAP_DATA_TYPE {
	MAP_TO_NORMAL_DATA,
	MAP_TO_BTRFS_INLINE_DATA
} MAP_DATA_TYPE;

struct FileMappingTable {
	FileMappingTable() : pStorageDevice(NULL), mapDataType(MAP_TO_NORMAL_DATA) {}
	std::string filePath;
	StorageDevice *pStorageDevice;
	std::vector<FileMappingEntry> entries;
	// Etb is only for ext4
	std::vector<uint64_t> etbs;
	BtrfsInlineDataInfo btrfsInlineDataInfo;
	MAP_DATA_TYPE mapDataType;
};

struct FileReverseMappingInfo {
	FileReverseMappingInfo() : fileStartSector(0) {}
	std::string filePath;
	uint64_t fileStartSector;
};

struct QueryFileMappingTable {
	QueryFileMappingTable() : fileStartSector(0), numSectors(0) {}
	uint64_t fileStartSector;
	uint64_t numSectors;
	FileMappingTable mappingResult;
};

typedef enum _tag_REVERSE_FILE_MAPPING_RESULT {
	REVERSE_MAPPING_ERROR = -1,
	REVERSE_MAPPING_SUCCESS = 0,
	REVERSE_MAPPING_NO_FILE,
	// ETB = extent block, when there is too many extents in the inode, it uses extra blocks (which are etbs) to store extents
	REVERSE_MAPPING_ON_ETB
} REVERSE_FILE_MAPPING_RESULT;

class FileSystemDevice {
public:
	FileSystemDevice(const std::string &devicePath);
	virtual ~FileSystemDevice();
	/*
	 * When success, we need to check mapDataType in table to comfirm mapping to normal data or not.
	 *
	 * Return >= 0: Number of entries in mapping table.
	 *        -1: On error
	 */
	virtual int GetMapping(const std::string &absoluteFilePath, FileMappingTable &table) const = 0;
	/*
	 * If a file is in /volume1/map/dir1/readme, we should use /volume1/map/dir1 or /volume1/map/dir1/readme for absoluteDirPath.
	 * If we only input /volume1, we may get wrong file of this inode because of mount path or btrfs sub volume issue.
	 */
	virtual int GetMappingByInode(const std::string &absoluteDirPath, uint64_t inodeNum, FileMappingTable &table) const = 0;
	int GetMapping(const std::string &absoluteFilePath, std::vector<QueryFileMappingTable> &tables) const;
	int GetMapping(const std::string &absoluteFilePath, uint64_t startSector, uint64_t numSectors, FileMappingTable &table) const;
	// Only support mapping one sector to a file
	virtual REVERSE_FILE_MAPPING_RESULT GetReverseMapping(uint64_t deviceStartSector, std::vector<FileReverseMappingInfo> &fileReverseMappingInfos) const = 0;
	CHECK_DATA_RESULT CheckDataConsistency(const std::string &absoluteFilePath, uint64_t startSector, uint64_t numSectors) const {return CHECK_DATA_NOT_SUPPORT;}
	const std::string &GetDevicePath() const {return _devicePath;}
	// Trans from /volume1/public/test to /dev/md2, absolutePath may be a dir.
	static GET_PATH_RESULT GetDevicePath(const std::string &absolutePath, std::string &devicePath, bool blNoCheck = false);
	static GET_PATH_RESULT GetMountPath(const std::string &devicePath, std::string &mountPath);
	// Return 1 on found, 0 on no file system, -1 on error
	// XXX: use exception to check from constructor
	static int checkFileSystemExist(const std::string &devicePath);

protected:
	std::string _mountPath;
	std::string _devicePath;
	StorageDevice *_pDevice;

private:
	void CutMappingResult(uint64_t startSector, uint64_t numSectors, const FileMappingTable &originTable, FileMappingTable &resultTable) const;
};

#endif /*FILE_SYSTEM_DEVICE_H*/
