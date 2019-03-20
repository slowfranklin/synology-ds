/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_CLIENTLIST_HEADER_
#define _NET_AIRROUTER_CLIENTLIST_HEADER_

#include <json/writer.h>
#include <json/reader.h>
#include <json/value.h>
#include <ithread.h>

class ClientList {
public:
	ClientList();
	bool Load(const std::string &strClientListPath);
	bool UpdateKeysByMac(const std::string &strMac, const Json::Value &jvData, const bool &blAddIfNotExist);
	bool UpdateKeysByIP(const std::string &strIP, const Json::Value &jvData, const bool &blAddIfNotExist);
	std::string FindKey(const std::string &strMac, const std::string &strKey);
	std::string FindMacByIP(const std::string &strIP);
	bool EraseObject(const std::string &strMac);
	void EraseList();
	bool WriteToFile(const std::string &strFilePath);
	Json::Value GetClientList();
	bool GetObject(const std::string &strMac, Json::Value &jvData);

private:
	bool LoadClientList(const std::string &strFilePath);
	bool VerifyMacIsExist(const std::string &strMac, unsigned int &index);
	bool VerifyIPIsExist(const std::string &strIP, unsigned int &index);
	void DetermineDisplayName(const Json::Value &jObject, std::string &strDisplayName);
	std::string GetLocalTime();

	ithread_mutex_t _clientListMutex;
	Json::Value _jClientList;
};

#endif
