/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_USBMODEN_LIST_HPP_
#define _SYNO_WIRELESS_USBMODEN_LIST_HPP_

#include <string>
#include <vector>

#include <synowireless/usbmodem_lib/usbmodem_null.hpp>

namespace synowireless {
namespace usbmodem_lib {

class USBModemList : public std::vector<USBModem> {
public:
	USBModemList();
	virtual ~USBModemList();

	int SearchInfoPath();
	int Update();

	USBModem &FindUSBModem(int iIfid);
	USBModem &FindUSBModem(const std::string &strDevId);

private:
	static synowireless::usbmodem_lib::USBModemNull nullObject;

}; /* class USBModemList */

} /* using usbmodem_lib */
} /* using synowireless */

#endif /* _SYNO_WIRELESS_USBMODEN_LIST_HPP_ */
