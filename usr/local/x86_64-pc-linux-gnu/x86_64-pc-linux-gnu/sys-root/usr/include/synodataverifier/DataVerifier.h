/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef DATA_VERIFIER_H
#define DATA_VERIFIER_H

#include <stdio.h>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "OutputFunctions.h"
#include "SystemInfoHelper.h"
#include "Global.h"

#define NUM_BUFFER_SECTORS 128

typedef enum _tag_CHECK_FILE_RESULT {
	CHECK_FILE_ERROR = -1,
	CHECK_FILE_SUCCESS,
	CHECK_FILE_WRONG_ROUND_NUM,
	CHECK_FILE_WRONG_SECTOR_NUM,
	CHECK_FILE_WRONG_FILE_NAME,
	CHECK_FILE_CHECK_SUM_ERROR
} CHECK_FILE_RESULT;

#define NUM_RANDOM_BYTES 360
#define MAX_PATH_LENGTH 64

struct SectorFormat {
	SectorFormat() : sectorNum(0), timeStamp(0), testRoundNum(0), checkSum(0) {}
	char szFullLocalFilePath[MAX_PATH_LENGTH];
	// XXX: Reserved design
	char szFullRemoteFilePath[MAX_PATH_LENGTH];
	uint64_t sectorNum;
	uint64_t timeStamp;
	uint32_t testRoundNum;
	unsigned char randomBytes[NUM_RANDOM_BYTES];
	uint32_t checkSum;
};

class DataVerifier {
public:
	DataVerifier();
	~DataVerifier();
	int DumpSectorInfo(const std::string &absolutePath, uint64_t sector, bool blDumpHex);
	int WriteFile(const std::string &absolutePath, uint64_t fileSizeInSector, uint32_t testRoundNum, const char *szFullLocalFilePath, const char *szFullRemoteFilePath);
	// If there are two or more check fail types occur, this function will return first result in order of enum.
	// Stop at first error sector, num handled sectors will be equal to error sector if check error.
	CHECK_FILE_RESULT CheckFile(const std::string &absolutePath, uint32_t testRoundNum, bool blSkipFileName, uint64_t &numHandledSectors);
	int DumpSectorHex(const std::string &absolutePath, uint64_t sector);

private:
	SectorFormat _bufferSectors[NUM_BUFFER_SECTORS];
	unsigned char _displayBuffer[SECTOR_SIZE];
	unsigned int _sectorSize;

	void PrintSector(const std::string &absolutePath, uint64_t sector);
	int LoadSectorToBuffer(const std::string &absolutePath, uint64_t sector);
};
#endif /* DATA_VERIFIER_H */
