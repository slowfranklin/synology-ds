/* Copyright (c) 2000-2010 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_UPNPSCANNER_HEADER_
#define _NET_AIRROUTER_UPNPSCANNER_HEADER_

#include <string>
#include <vector>
#include <map>

#include <pthread.h>
#include <upnp.h>

#include <json/writer.h>
#include <json/reader.h>
#include <json/value.h>

#include "clientlist.hpp"

class UpnpScanner {
public:
	int Start();
	void Stop();
	Json::Value GetData();
	static UpnpScanner* Inst();

private:
	UpnpScanner(unsigned short port = 0);
	~UpnpScanner();

	int StartUpnp();
	int StopUpnp();
	static int CallbackEventHandler(Upnp_EventType EventType, void *Event, void *Cookie);
	int HandleDiscovery(INOUT struct Upnp_Discovery *ca_event, Upnp_EventType eventType);
	std::string SearchValueByTagName(IXML_Document *ixmlDoc, const DOMString tagName);
	void BoardcastUpnp();
	static void *WaitBoardcastFinish(void *ptr);

	static UpnpScanner* _gUpnpScanner;
	unsigned short _serverport;
	UpnpClient_Handle _hClient;
	ClientList _clientlist;
	pthread_t _upnpThread;
	static bool IsBoardCasting;
};
#endif
