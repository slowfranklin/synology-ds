/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_USBMODERN_UILIB_HPP_
#define _SYNO_USBMODERN_UILIB_HPP_

#include <vector>
#include <string>

namespace synowireless {
namespace usbmodem_ui {
	typedef std::vector<std::string> USBModemNameList;
	typedef USBModemNameList::iterator USBModemNameListIter;
	typedef std::vector<std::string> USBModemIfNameList;
	typedef USBModemNameList::iterator USBModemIfNameListIter;

	int Connect(const std::string &devid);
	int Disconnect(const std::string &devid);
	int GetUSBModemList(USBModemNameList &modemList);
	int GetUSBModemIfList(USBModemNameList &modemList);
	std::string GetUSBModem(const std::string &devid);
	std::string GetSimInfo(const std::string &devid);
	int UnlockSIM(const std::string &devid, const std::string &pin);
	int UnlockPIN(const std::string &devid, const std::string &puk, const std::string &pin);
	int SetPIN(const std::string &devid, const std::string &oldPin, const std::string &newPin, bool bEnableProtection);
	int SetProfile(const std::string &devid, const std::string &content);
	std::string GetProfile(const std::string &devid);
	int GetDevIdByIfName(const std::string &strIfName, std::string &strDevId);

}
}

#endif /* _SYNO_USBMODERN_UILIB_HPP_ */
