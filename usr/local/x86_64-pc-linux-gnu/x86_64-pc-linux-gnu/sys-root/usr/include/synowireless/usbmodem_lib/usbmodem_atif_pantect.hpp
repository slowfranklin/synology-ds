/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_ATIF_PANTECH_HPP_
#define _SYNO_WIRELESS_USBMODEN_ATIF_PANTECH_HPP_
#include "usbmodem_atif.hpp"

namespace synowireless {
namespace usbmodem_lib {

class USBModem_ATIF_Pantech: public USBModem_ATIF {
public:
	std::string GetATCommandPINAttempt();
	std::string GetATCommandPUKAttempt();

	int ParseRetStringPINRemainAttempt(const std::string &strInString, std::string &strOutString);
	int ParseRetStringPUKRemainAttempt(const std::string &strInString, std::string &strOutString);

private:
	USBModem_ATIF_Pantech();
	~USBModem_ATIF_Pantech();

	friend class USBModem_ATIF;

private: /* following operation should not be invoked */
	USBModem_ATIF_Pantech(const USBModem_ATIF_Pantech &);
	USBModem_ATIF_Pantech &operator=(const USBModem_ATIF_Pantech &);
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif
