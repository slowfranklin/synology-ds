/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_USBMODEN_NULL_HPP_
#define _SYNO_WIRELESS_USBMODEN_NULL_HPP_

#include <synowireless/usbmodem_lib/usbmodem.hpp>

namespace synowireless {
namespace usbmodem_lib {

class USBModemNull : public USBModem {
public:
	USBModemNull();
	~USBModemNull();

	// Null version functions
	std::string GetDevId() const;
	bool IsNull() const;
	bool IsInited() const;
	bool IsInfoExist() const;

}; /* class USBModemNull */

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEN_NULL_HPP_ */
