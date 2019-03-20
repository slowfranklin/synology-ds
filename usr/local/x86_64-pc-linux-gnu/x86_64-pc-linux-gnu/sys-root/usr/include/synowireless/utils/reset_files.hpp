/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_RESET_FILES_HPP_
#define _SYNO_WIRELESS_UTILS_RESET_FILES_HPP_

namespace synowireless {
namespace utils {

void RemoveFile(const char *szFile);
void RemoveFiles(const char *szPath, const char *szPrefix);
void ResetFiles(const char *szSrc, const char *szDst);

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_RESET_FILES_HPP_ */
