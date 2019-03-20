/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_ATIF_DLINK_HPP_
#define _SYNO_WIRELESS_USBMODEN_ATIF_DLINK_HPP_
#include "usbmodem_atif.hpp"

namespace synowireless {
namespace usbmodem_lib {

class USBModem_ATIF_DLink: public USBModem_ATIF {
public:
	std::string GetATCommandPINAttempt();	//AT+EPINC?
	std::string GetATCommandPUKAttempt();	//AT+EPINC?
	std::string GetATCommandSetSIMPIN(const std::string &strPIN);	//AT+CPIN=\"{PIN}\"
	std::string GetATCommandSetSIMPUK(const std::string &strPuk, const std::string &strPIN);	//AT+CPIN=\"{PUK}\",\"{PIN}\"

	int ParseRetStringPINRemainAttempt(const std::string &strInString, std::string &strOutString);
	int ParseRetStringPUKRemainAttempt(const std::string &strInString, std::string &strOutString);

private:
	USBModem_ATIF_DLink();
	~USBModem_ATIF_DLink();

	friend class USBModem_ATIF;

private: /* following operation should not be invoked */
	USBModem_ATIF_DLink(const USBModem_ATIF_DLink &);
	USBModem_ATIF_DLink &operator=(const USBModem_ATIF_DLink &);
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif
