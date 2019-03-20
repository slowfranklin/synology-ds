/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_ATIF_PROTO_HPP_
#define _SYNO_WIRELESS_USBMODEN_ATIF_PROTO_HPP_

#include <json/value.h>

#include <synowireless/usbmodem_lib/error.hpp>
#include <synowireless/usbmodem_lib/usbmodem_enum.hpp>

namespace synowireless {
namespace usbmodem_lib {

class USBModem_ATIF {
public:
	static USBModem_ATIF *CreateATIF(const std::string &strVendorId);
	static void DeleteATIF(USBModem_ATIF *pATIF);

//======AT command======
	virtual std::string GetATCommandQuarySIMStatus();	//AT+CPIN?
	virtual std::string GetATCommandSetSIMPIN(const std::string &strPIN);	//AT+CPIN={pin}
	virtual std::string GetATCommandSetSIMPUK(const std::string &strPuk, const std::string &strPIN);	//AT+CPIN={puk},{pin}
	virtual std::string GetATCommandChangePINCode(const std::string &strOrigPin, const std::string &strNewPin);	//AT+CPWD="SC","{OrigPin}","{NewPin}"
	virtual std::string GetATCommandChangePINEnable(const std::string &strEnable, const std::string &strPin);	//AT+CLCK="SC",strEnable,"strPin"
	virtual std::string GetATCommandGetPINEnable();	//AT+CLCK="SC",2
	virtual std::string GetATCommandGetRSSI();	//AT+CSQ
	virtual std::string GetATCommandGetHardwareFuncLvl();	//AT+CFUN?
	virtual std::string GetATCommandSetHardwareFuncLvl(const std::string& strLvl);	//AT+CFUN={num}
	virtual std::string GetATCommandGetVendorName();	//AT+CGMI
	virtual std::string GetATCommandGetProductName();	//AT+CGMM
	virtual std::string GetATCommandGetIMSI();	//AT+CIMI
	virtual std::string GetATCommandGetRoaming();	//AT+CREG?
	virtual std::string GetATCommandGetDefaultISP();	//AT+COPS?
	virtual std::string GetATCommandGetDefaultAPN();	//AT+CGDCONT?
	virtual std::string GetATCommandPINAttempt();	//AT^CPIN?
	virtual std::string GetATCommandPUKAttempt();	//AT^CPIN?
	virtual std::string GetATCommandGetUnsolicitedReports();	//AT^CURC?
	virtual std::string GetATCommandSetUnsolicitedReports(const bool bEnable);	//AT^CURC={num}
	virtual std::string GetATCommandSetAPN(const std::string &strIndex, const std::string &strAPN); //AT+CGDCONT=1,"ip","internet"

//====parse return string from AT command=====
	virtual SIM_PROTECTION_STATS ParseRetStringQuarySIMStatus(const std::string &strInString);
	virtual int ParseRetStringGetSignalLevel(const std::string &strInString, int &iSignalStrength);
	virtual int ParseRetStringGetRoaming(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringPINRemainAttempt(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringPUKRemainAttempt(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringDefaultISP(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringDefaultAPN(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringDefaultAPNList(const std::string &strInString, Json::Value &jvOutData);
	virtual int ParseRetStringDefaultFormat(const std::string &strInString, std::string &strOutString);
	virtual int ParseRetStringIsOK(const std::string &strInString);

protected:
	USBModem_ATIF();
	virtual ~USBModem_ATIF();
	int GetLineWithDelim(const std::string &strInString, const char cDelim, const int iNum, std::string &strOutString);
	
private:
	static USBModem_ATIF *CreateATIFHuawei();
	static USBModem_ATIF *CreateATIFDLink();
	static USBModem_ATIF *CreateATIFPantech();
	static USBModem_ATIF *CreateATIFZoom();
	static int CreateVendorHash();
	
	static std::map<std::string, USBModem_ATIF*(*)()> vendorTable;
	
private: /* following operation should not be invoked */
	USBModem_ATIF(const USBModem_ATIF &);
	USBModem_ATIF &operator=(const USBModem_ATIF &);
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif
