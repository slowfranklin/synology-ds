/* Copyright (c) 2000-2010 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_WIFISCANNER_HEADER_
#define _NET_AIRROUTER_WIFISCANNER_HEADER_

#include <json/value.h>
#include <synonetsdk/net.h> //topology

#include "clientlist.hpp"

class WifiScanner {
public:
	int Start();
	void Stop();
	Json::Value GetData();

public:
	static WifiScanner* Inst();

private:
	WifiScanner();
	~WifiScanner();

	int AppendClientList(const std::string &strMac, const std::string &strIfName);
	int GetHostapdData();
	int GetStationByIfName(const std::string &strIfName);
	int GetIwDevInfo(Json::Value &jvdata);
	int ConvertDbmToPercent(int iDbm);
	bool RegMatch(const char *string, const char *pattern);

	static WifiScanner *_gWifiScanner;
	ClientList _clientlist;
	TOPOLOGY_MODE _Topology;
};
#endif
