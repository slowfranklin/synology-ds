/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETSDK_DBUS_SERVER_HPP_
#define _SYNO_NETSDK_DBUS_SERVER_HPP_

extern "C" {
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-lowlevel.h>
}

#include <string>

#define CHECK_PARAM(condition)									\
	do {														\
		if (condition) {										\
			SYSLOG(LOG_ERR, "Bad parameter");					\
			*ppError = g_error_new (							\
				g_quark_from_static_string("badparameter"),		\
				1,												\
				"Bad parameter");								\
			return FALSE;										\
		}														\
	} while(0)

namespace synonetsdk {
namespace dbus {

class DBusServer {
public:
	DBusServer(const char *szDestination, const char *psPath, DBusBusType type);
	virtual ~DBusServer();

	virtual void StartLoop();
	virtual void QuitLoop();

	virtual int NewSignal(const char *szName);
	virtual int SendSignal();

	virtual bool IsInitialized() const;

private:
	const char *GetConnectionName() const;
	const char *GetBusName() const;
	const char *GetPath() const;
	const char *GetInterface() const;

protected: /* tools for subclass */
	int Initialize(GType object_type, const DBusGObjectInfo *pInfo, GObject *pObject);

private:
	GMainLoop *pLoop;
	DBusGProxy *pProxy;
	DBusGConnection* pGConnection;
	DBusBusType busType;
	std::string strDestination;
	std::string strPath;
	DBusMessage *pSignal;
	bool blInited;

private: /* They will not be implemented. Do NOT use them */
	DBusServer();
	DBusServer(const DBusServer &);
	DBusServer &operator=(const DBusServer &);
}; /* class DBusServer */

} /* namespace dbus */
} /* namespace synonetsdk */

#endif /* _SYNO_NETSDK_DBUS_SERVER_HPP_ */
