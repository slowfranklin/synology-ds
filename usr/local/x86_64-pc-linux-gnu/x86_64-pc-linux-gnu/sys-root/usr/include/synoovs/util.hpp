/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_UTIL_HPP_
#define __SYNO_OVS_UTIL_HPP_

#include <string>
#include <vector>

namespace SYNO {
namespace OVS {
	bool IsDaemonAlive();
	bool StartOVSDaemon();
	bool StopOVSBaemon();

	bool StartNetwork(const std::vector<std::string> &_vIfs);
	bool StopNetwork(const std::vector<std::string> &_vIfs);

	bool IsInterfaceExist(const std::string &strIf);

	//Gateway
	int RemoveGateWayInfo(const char *szOVSIfs);
	int CopyGatewayInfo(const char *szIfsName, const char *szOVSIfs);
} /* OVS */
} /* SYNO */

#endif // __SYNO_OVS_UTIL_HPP_
