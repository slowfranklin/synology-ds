// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_DAEMON_H
#define _SYNO_IDX_DAEMON_H

// standard
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <map>
#include <vector>

// system
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/msg.h>
#include <sys/inotify.h>

// library
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>
#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>

// syno
#include <synocore/proc.h>

// project
#include <synoindex/synoidx_ipc_core.h>
#include <synoindex/synoidx_system.h>

using std::string;
using std::map;
using std::vector;

//--------------------------------------------------

class DaemonInfo
{
public:
	DaemonInfo();
	string get(const char* daemon, const char* type);
	string get(string daemon, const char* type);

private:
	map<string, string> m_pid_map;
	map<string, string> m_bin_map;
	map<string, string> m_sock_map;
};

//--------------------------------------------------

struct EventArgs
{
	const char* name;
	struct event_base* base;
	int (*fn)(Json::Value&, Json::Value&, void*);
};

//--------------------------------------------------

int GetCurrentConnCount();
int BecomeDaemon(const char* pid_path);
int BecomeProcess(const char* pid_path);
int DeletePidFile(const char* pid_path);
int BuildServer(struct event_base *base, const char* socket_path, EventArgs* event_args);
int StopServer(const char* socket_path);

int CreateMessageQueue(const char* pathname, int proj_id, int kbytes);
int DeleteMessageQueue(const char* pathname, int proj_id);
int GetMessageQueue(const char* pathname, int proj_id);
int PushTaskToQueue(int queue_id, Json::Value msg, int type);
int PopTaskFromQueue(int queue_id, int type, bool block, int retry, Json::Value &msg);
int GetNumOfMessageInQueue(int queue_id);

int SendPacketEv(struct bufferevent *bufev, Json::Value &message);
int RecvPacketEv(struct bufferevent *bufev, Json::Value &message);
Json::Value MakeResponse(bool success, const char* reason = NULL);

void CheckIn(const char* path);
void CheckOut(const char* path);
bool CheckBufferevent(struct bufferevent *bufev);
int GetExecutionTime(const char* path);

#endif
