/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_ATIF_ZOOM_HPP_
#define _SYNO_WIRELESS_USBMODEN_ATIF_ZOOM_HPP_
#include "usbmodem_atif.hpp"

namespace synowireless {
namespace usbmodem_lib {

class USBModem_ATIF_Zoom: public USBModem_ATIF {
public:
	std::string GetATCommandPINAttempt();	//AT*EPINR=1
	std::string GetATCommandPUKAttempt();	//AT*EPINR=3
	std::string GetATCommandSetSIMPIN(const std::string &strPIN);	//AT+CPIN=\"{PIN}\"
	std::string GetATCommandSetSIMPUK(const std::string &strPuk, const std::string &strPIN);	//AT+CPIN=\"{PUK}\",\"{PIN}\"
	std::string GetATCommandGetRSSI();	//AT+CIND?

	int ParseRetStringPINRemainAttempt(const std::string &strInString, std::string &strOutString);
	int ParseRetStringPUKRemainAttempt(const std::string &strInString, std::string &strOutString);
	int ParseRetStringGetSignalLevel(const std::string &strInString, int &iSignalStrength);

private:
	USBModem_ATIF_Zoom();
	~USBModem_ATIF_Zoom();

	friend class USBModem_ATIF;

private: /* following operation should not be invoked */
	USBModem_ATIF_Zoom(const USBModem_ATIF_Zoom &);
	USBModem_ATIF_Zoom &operator=(const USBModem_ATIF_Zoom &);
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif
