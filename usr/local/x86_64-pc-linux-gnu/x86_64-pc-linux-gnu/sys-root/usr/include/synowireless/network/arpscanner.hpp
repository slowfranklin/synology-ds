/* Copyright (c) 2000-2010 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_ARPSCANNER_HEADER_
#define _NET_AIRROUTER_ARPSCANNER_HEADER_

#include <json/value.h>
#include <synonetsdk/net.h> //topology

#include "clientlist.hpp"

class ArpScanner {
public:
	int Start();
	void Stop();
	Json::Value GetData();

public:
	static ArpScanner* Inst();

private:
	ArpScanner();
	~ArpScanner();

	int GetDHCPInfoByMAC(const std::string &strMac, std::string &strHostName);
	int GetNmbInfoByIP(const std::string &strIP, std::string &strHostName);
	int AppendClientList(const std::string &strLine);
	int GetArpTable();

	static ArpScanner *_gArpScanner;
	ClientList _clientlist;
	TOPOLOGY_MODE _Topology;
};
#endif
