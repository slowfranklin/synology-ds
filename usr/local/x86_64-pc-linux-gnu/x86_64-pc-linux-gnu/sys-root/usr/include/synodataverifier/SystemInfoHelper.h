/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef SYSTEM_INFO_HELPER_H
#define SYSTEM_INFO_HELPER_H

#include <string>
#include <inttypes.h>
#include <stdlib.h>
#include <synocore/proc.h>
#include "Global.h"

class RwBuffer {
public:
	RwBuffer(unsigned int size, bool blDirect);
	~RwBuffer() {free(_pData);}
	bool IsValid() const {return _blIsValid;}
	bool IsDirect() const {return _blDirect;}
	unsigned int GetSize() const {return _size;}
	char *GetDataPointer() {return _pData;}
	char GetDataChar(unsigned int iterator) const;
private:
	char *_pData;
	unsigned int _size;
	bool _blDirect;
	bool _blIsValid;
};

typedef enum _tag_GET_PATH_FLAG {
	GET_PATH_FILE_TO_DEVICE,
	GET_PATH_DEVICE_TO_MOUNT
} GET_PATH_FLAG;

typedef enum _tag_FILE_SYSTEM_TYPE {
	FILE_SYSTEM_ERROR = -1,
	FILE_SYSTEM_NOT_FOUND,
	FILE_SYSTEM_NOT_SUPPORT,
	FILE_SYSTEM_EXT4,
	FILE_SYSTEM_BTRFS
} FILE_SYSTEM_TYPE;

struct DevMapping {
	DevMapping() : next(NULL) {major = 0; minor = 0;}
	int major, minor;
	std::string path;
	struct DevMapping *next;
};

typedef enum _tag_GET_PATH_RESULT {
	GET_PATH_ERROR = -1,
	GET_PATH_SUCCESS = 0,
	GET_PATH_NOT_FOUND
} GET_PATH_RESULT;

class SystemInfoHelper {
public:
	SystemInfoHelper(){}
	~SystemInfoHelper(){}
	static int ReadData(const std::string &path, uint64_t &output);
	static int ReadData(const std::string &path, int &output);
	static int ReadData(const std::string &path, char *szData, int cbData);
	// Return -1 on error, 0 on success, use loop to read enough data.
	static int ReadDeviceData(const std::string &devicePath, uint64_t numBytesSeeked, RwBuffer &readBuffer, uint64_t bytesToRead);
	static int BuildDeviceList(DevMapping *&pDeviceList);
	static void DeleteDeviceList(DevMapping *pDeviceList);
	static bool IsFileExisted(std::string absoluteFilePath);
	static GET_PATH_RESULT GetFileSystemPathAndType(const std::string &fromPath, GET_PATH_FLAG getPathFlag, std::string &resultString, FILE_SYSTEM_TYPE &fileSystemType);
	static int GetInodeNum(const std::string absoluteFilePath, uint64_t &inodeNum);
	static int GetFileSizeByte(const std::string absoluteFilePath, uint64_t &size);
	// Get real path of /dev/root in /proc/cmdline
	static int GetRootDevicePath(std::string &rootDevicePath);
};
#endif /* SYSTEM_INFO_HELPER_H */
