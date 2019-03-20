/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_NETWORK_DBUS_SERVER_HPP_
#define _SYNO_NETWORK_DBUS_SERVER_HPP_

#include <synonetsdk/dbus/dbus_server.hpp>

namespace synonetwork {
namespace dbus {

class NetServer : public synonetsdk::dbus::DBusServer {
public:
	NetServer();
	virtual ~NetServer();

private:
	GObject *pObject;

private: /* They will not be implemented. Do NOT use them */
	NetServer &operator=(const NetServer &);

}; /* class WifiServer */

} /* namespace dbus */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_DBUS_SERVER_HPP_ */
