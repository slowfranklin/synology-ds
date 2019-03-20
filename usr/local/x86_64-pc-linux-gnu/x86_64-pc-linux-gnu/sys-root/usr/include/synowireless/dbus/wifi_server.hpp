/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_WIFI_SERVER_HPP_
#define _SYNO_WIRELESS_WIFI_SERVER_HPP_

#include <synonetsdk/dbus/dbus_server.hpp>

namespace synowireless {
namespace dbus {

class WifiServer : public synonetsdk::dbus::DBusServer {
public:
	WifiServer();
	virtual ~WifiServer();

private:
	GObject *pObject;

private: /* They will not be implemented. Do NOT use them */
	WifiServer &operator=(const WifiServer &);

}; /* class WifiServer */

} /* namespace dbus */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEM_SERVER_HPP_ */
