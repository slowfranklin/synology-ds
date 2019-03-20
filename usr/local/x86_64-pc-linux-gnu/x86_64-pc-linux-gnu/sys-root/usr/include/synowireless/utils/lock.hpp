/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_LOCK_HPP_
#define _SYNO_WIRELESS_UTILS_LOCK_HPP_

#include <string>

#define MAX_WAIT_COUNT 30

namespace synowireless {
namespace utils {

class FileLock {
public:
	FileLock(const std::string &lockFile, bool blExclusive);
	virtual ~FileLock();

	bool Lock();
	bool Unlock();
private:
	int fd;
	bool exclusive;
	std::string strFile;

	bool createParentDir();
};

} /* namespace utils */
} /* namespace synowireless */

#endif // _SYNO_WIRELESS_UTILS_LOCK_HPP_
