/* Copyright (c) 2000-2010 Synology Inc. All rights reserved. */
#ifndef _NET_AIRROUTER_DSSCANNER_HEADER_
#define _NET_AIRROUTER_DSSCANNER_HEADER_

#include <pthread.h>
#include <json/value.h>

#include "clientlist.hpp"

class DSScanner {
public:
	int Start();
	void Stop();
	Json::Value GetData();

public:
	static DSScanner* Inst();

private:
	DSScanner();
	~DSScanner();

	void BoardcastFindHost();

	pthread_t _dsThread;
private:
	int ReadFHOSTListFile();
	static void *WaitBoardcastFinish(void *ptr);

	static DSScanner *_gDSScanner;
	ClientList _clientlist;
	static bool IsBoardCasting;
};
#endif
