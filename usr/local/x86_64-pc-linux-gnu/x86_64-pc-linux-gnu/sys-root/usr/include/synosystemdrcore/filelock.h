/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_UTILS_FILE_LOCK_H__
#define __SYNOSYSDRCORE_UTILS_FILE_LOCK_H__

#include <string>
#include <synosystemdrcore/filelock_common.h>

namespace SynoSysDRCore {
#define DEFAULT_TIMEOUT_SEC 10

class FileLock : public SynoDRCommon::FileLock {
public:
	FileLock(const std::string &lockFile);
	virtual ~FileLock();
	bool keepLockAfterDestructor();
protected:
	bool _keepLockAfterDestructor;
};//FileLock

class FileLockGuard : public SynoSysDRCore::FileLock {
public:
	FileLockGuard(const std::string &lockFile, unsigned int timeoutSec = DEFAULT_TIMEOUT_SEC);
	virtual ~FileLockGuard();
	bool isLockSuccess() const;
	virtual void unlock();
private:
	bool _isLockSuccess;
};

}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_UTILS_FILE_LOCK_H__
