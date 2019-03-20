/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#include <sys/stat.h>
#include <string>

namespace synowireless {
namespace utils {

#define DEFAULT_MODE S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH

int CheckAndMakeDir(const std::string &strDir, mode_t mode = DEFAULT_MODE);
int CopyIfcfgIPv6Attrs(const std::string &srcIf, const std::string &dstIf);
std::string FileToStr(const std::string &strFile);

} /* namespace utils */
} /* namespace synowireless */
