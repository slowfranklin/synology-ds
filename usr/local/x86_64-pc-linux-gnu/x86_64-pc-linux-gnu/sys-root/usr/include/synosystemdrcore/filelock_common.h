/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNODR_COMMON_UTILS_FILE_LOCK_H__
#define __SYNODR_COMMON_UTILS_FILE_LOCK_H__

#include <string>
#include <synocore/file.h>

namespace SynoDRCommon {
#define DR_COMMON_CREATE_FILE_DEFAULT_MODE 644

class FileLock {
public:
	FileLock(const std::string &lockPath, const std::string &lockFile, const mode_t &mode = DR_COMMON_CREATE_FILE_DEFAULT_MODE);
	~FileLock();

	const std::string &getLockFile() const { return _lockFile; }
	bool isValid() const { return !_lockFile.empty(); }
	bool isLocked() const { return 0 <= _lockFd; };

	bool lock(int lockMode = LOCK_EX_NB, unsigned int timeoutSec = LOCK_TIMEOUT);
	bool tryLock(int lockMode = LOCK_EX_NB);
	virtual void unlock();
private:
	int _lockFd;
	const std::string _filePath;
	std::string _lockFile;
	const mode_t _mode;

	bool checkLockDir() const;
	bool openLockedFile();
	std::string getLockFilePath(const std::string &file);
};//FileLock
}//SynoDRCommon

#endif //__SYNODR_COMMON_UTILS_FILE_LOCK_H__
