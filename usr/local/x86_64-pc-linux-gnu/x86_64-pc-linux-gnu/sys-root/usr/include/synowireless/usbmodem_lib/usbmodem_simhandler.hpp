
/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_SIMHANDLER_HPP_
#define _SYNO_WIRELESS_USBMODEN_SIMHANDLER_HPP_

#include <string>
#include <json/value.h>

#include <synowireless/usbmodem_lib/usbmodem_atif.hpp>
#include <synowireless/usbmodem_lib/usbmodem_atif_huawei.hpp>
#include <synowireless/usbmodem_lib/usbmodem_atif_dlink.hpp>
#include <synowireless/usbmodem_lib/usbmodem_devicenodehandler.hpp>
#include <synowireless/usbmodem_lib/usbmodem_enum.hpp>

namespace synowireless {
namespace usbmodem_lib {

class USBModem_SIMHandler {
public:
	USBModem_SIMHandler();
	~USBModem_SIMHandler();
	int InitHandler(const unsigned int &iId);

	//PIN and PUK API
	int PINUnlock(const std::string &strPIN);
	int PINSet(const std::string &strOrigPin, const std::string &strNewPin, bool bEnableProtection);
	int PINGetEnableProtection();
	int PUKSet(const std::string &strPUK, const std::string &strNewPin);
	std::string GetPINStatus(bool &bIsError);

	// Profile and SIM Data info
	Json::Value GetProfile(bool &blError);
	Json::Value GetUSBModemData(bool &blError);
	Json::Value GetSimInfo(bool &blError);
	std::string GetIMSI(bool &bIsError);
	int SetProfile(const Json::Value &profile);

	// Get connection info
	int GetConnectNode(std::string &strNodePath);
	void ReleaseConnectNode();

private:
	int ModemCmd(const std::string &strInCommand, std::string &strOutString);
	int InitAfterUnlocked();

	// SIM init
	int SetUnsolicitedReports(const bool bEnable);
	int SetHardwareFuncLvl(const std::string &strLvl);

	// sub handler stuff
	int SetSubHandler(const unsigned int &iId);
	void UnsetSubHandler();

	// PIN PUK stuff
	void UpdateSIMStatus();
	int GetPINEnable();
	int ChangePIN(const std::string &strOrigPin, const std::string &strNewPin);
	int ChangePINEnable(const std::string &strPin, bool bEnableProtection);
	int ChangePINWithPUK(const std::string &strPuk, const std::string &strPin);
	int PINGetAttemptRemain();
	int PUKGetAttemptRemain();

	// profile stuff
	int InitProfile();
	int ResetProfile();
	std::string GetProfileWithKey(const std::string &strKey, bool &bIsError);
	int SetProfileWithKey(const std::string &strKey, const std::string &strValue);

	// Get Device info
	int GetSignalQuality(bool &bIsError);
	std::string GetVendorName(bool &bIsError);
	std::string GetProductName(bool &bIsError);
	std::string GetRoaming(bool &bIsError);
	bool ReadAPNData(Json::Value &data);
	std::string GetDefaultLocation(bool &bIsError);
	std::string GetDefaultISP(bool &bIsError);
	std::string GetDefaultAPN(bool &bIsError);
	Json::Value GetDefaultAPNList(bool &bIsError);

	// Set Device info
	int CheckAndWriteAPN(const std::string &strPhone, const std::string &strAPN);

private:
	std::string _strUSBModemId;
	SIM_PROTECTION_STATS _PINStatus;

	// SIM data
	std::string _strIMSI;
	int _iSignalStrength;
	std::string _strVendorName;
	std::string _strProductName;
	std::string _strRoaming;
	std::string _strDefaultISP;
	std::string _strDefaultAPN;
	Json::Value _jvDefaultAPNList;

	//Profile variables
	std::string _strProfilePath;

	// AT command for particular vendor
	USBModem_ATIF *_pATIF;

	// device node handler
	USBModem_DeviceNodeHandler *_pdevHandler;
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEN_SIMHANDLER_HPP_ */
