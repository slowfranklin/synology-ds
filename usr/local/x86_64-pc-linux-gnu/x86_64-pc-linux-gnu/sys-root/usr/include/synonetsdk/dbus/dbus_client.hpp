/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_NETSDK_DBUS_CLIENT_HPP_
#define _SYNO_NETSDK_DBUS_CLIENT_HPP_

extern "C" {
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-lowlevel.h>
}

#include <string>
#include <vector>

namespace synonetsdk {
namespace dbus {

class DBusClient {
public:
	DBusClient(const char *szDestination, const char *szPath, const char *szInterface, DBusBusType type);
	virtual ~DBusClient();

	virtual bool IsServerReady() const;

	int NewMessage(const char *szName);
	int Append(bool blValue);
	int Append(const std::string &strValue);
	int Append(const char *szValue);
	int SendMessage(bool blReply, int timeout = DBUS_TIMEOUT_USE_DEFAULT);
	int GetReply(std::string &strReply);
	int GetReply(std::vector<std::string> &replyList);

	void AddSignalHandler();

private:
	std::string strDestination;
	std::string strPath;
	std::string strInterface;
	DBusBusType busType;
	DBusGConnection *pGConnection;
	DBusMessage *pMessage;
	DBusMessage *pReplyMessage;

private: /* They will not be implemented. Do NOT use them */
	DBusClient();
	DBusClient(const DBusClient &);
	DBusClient &operator=(const DBusClient &);

}; /* class DBusClient */

} /* namespace dbus */
} /* namespace synonetsdk */

#endif /* _SYNO_NETSDK_DBUS_CLIENT_HPP_ */
