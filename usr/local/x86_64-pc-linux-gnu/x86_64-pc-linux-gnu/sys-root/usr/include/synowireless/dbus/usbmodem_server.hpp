/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_USBMODEM_SERVER_HPP_
#define _SYNO_WIRELESS_USBMODEM_SERVER_HPP_

#include <synonetsdk/dbus/dbus_server.hpp>
#include <synowireless/usbmodem_lib/usbmodem_list.hpp>

namespace synowireless {
namespace dbus {

typedef struct USBModemObject
{
	GObject parent;
	synowireless::usbmodem_lib::USBModemList list;
} USBModemObject;

typedef struct USBModemObjectClass
{
	GObjectClass parent;
} USBModemObjectClass;

class USBModemServer : public synonetsdk::dbus::DBusServer {
public:
	USBModemServer();
	virtual ~USBModemServer();

	int Initialize();
	synowireless::usbmodem_lib::USBModemList &GetList();
	void StartPollingTimer();

private:
	USBModemObject *pObject;

private: /* They will not be implemented. Do NOT use them */
	USBModemServer &operator=(const USBModemServer &);

}; /* class USBModemServer */

} /* namespace dbus */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEM_SERVER_HPP_ */
