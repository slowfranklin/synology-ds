/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_USBMODEM_CLIENT_HPP_
#define _SYNO_WIRELESS_USBMODEM_CLIENT_HPP_

#include <synonetsdk/dbus/dbus_client.hpp>

namespace synowireless {
namespace dbus {

class USBModemClient : public synonetsdk::dbus::DBusClient {
public:
	USBModemClient();
	virtual ~USBModemClient();

	virtual bool IsServerReady() const;

	int Connect(const std::string &strDevId);
	int Disconnect(const std::string &strDevId);
	int GetUSBModemList(std::string &strList);
	int GetUSBModem(const std::string &strDevId, std::string &strUSBModem);
	int GetSimInfo(const std::string &strDevId, std::string &strSimInfo);
	int UnlockSIM(const std::string &strDevId, const std::string &strPIN);
	int SetPIN(const std::string &strDevId, const std::string &strPINOld, const std::string &strPINNew, bool blProtection);
	int GetProfile(const std::string &strDevId, std::string &strProfile);
	int SetProfile(const std::string &strDevId, const std::string &strProfile);
	int UnlockPIN(const std::string &strDevId, const std::string &strPUK, const std::string &strPIN);
	int GetUSBModemIfList(std::string &strList);
	int GetDevIdByIfName(const std::string &strIfName, std::string &strDevId);

private: /* They will not be implemented. Do NOT use them */
	USBModemClient(const USBModemClient &);
	USBModemClient operator=(const USBModemClient &);

}; /* class USBModemClient */

} /* namespace dbus */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEM_CLIENT_HPP_ */
