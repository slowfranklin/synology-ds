/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_ATIF_HUAWEI_HPP_
#define _SYNO_WIRELESS_USBMODEN_ATIF_HUAWEI_HPP_
#include "usbmodem_atif.hpp"

namespace synowireless {
namespace usbmodem_lib {

class USBModem_ATIF_Huawei: public USBModem_ATIF {
public:
	std::string GetATCommandPINAttempt();	//AT^CPIN?
	std::string GetATCommandPUKAttempt();	//AT^CPIN?
	std::string GetATCommandGetUnsolicitedReports();    //AT^CURC?
	std::string GetATCommandSetUnsolicitedReports(const bool bEnable);    //AT^CURC={num}

	int ParseRetStringPINRemainAttempt(const std::string &strInString, std::string &strOutString);
	int ParseRetStringPUKRemainAttempt(const std::string &strInString, std::string &strOutString);

private:
	USBModem_ATIF_Huawei();
	~USBModem_ATIF_Huawei();

	friend class USBModem_ATIF;

private: /* following operation should not be invoked */
	USBModem_ATIF_Huawei(const USBModem_ATIF_Huawei &);
	USBModem_ATIF_Huawei &operator=(const USBModem_ATIF_Huawei &);
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif
