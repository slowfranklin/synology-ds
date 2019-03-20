/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_HPP_
#define _SYNO_WIRELESS_USBMODEN_HPP_

#include <string>
#include <json/value.h>

#include <synowireless/usbmodem_lib/usbmodem_atif.hpp>
#include <synowireless/usbmodem_lib/usbmodem_atif_huawei.hpp>
#include <synowireless/usbmodem_lib/usbmodem_atif_dlink.hpp>
#include <synowireless/usbmodem_lib/usbmodem_enum.hpp>
#include <synowireless/usbmodem_lib/usbmodem_devicenodehandler.hpp>
#include <synowireless/usbmodem_lib/usbmodem_simhandler.hpp>

namespace synowireless {
namespace usbmodem_lib {

class USBModem {
public:
	//Construct/Destruct and init
	USBModem(unsigned int inIfid, const std::string &inInfoPath);
	USBModem(const USBModem &um);
	virtual ~USBModem();
	int InitInfo();

	virtual std::string GetDevId() const;
	virtual bool IsNull() const;
	virtual bool IsInited() const;
	virtual bool IsInfoExist() const;

	bool IsError();
	int IncreaseErrorCounter();

	//Network API
	int NetConnect(unsigned int iDialAttempt = 1);
	int NetDisconnect();
	int NetTryAutoConnect();

	//PIN and PUK API
	int PINUnlock(const std::string &strPIN);
	int PINSet(const std::string &strOrigPin, const std::string &strNewPin, bool bEnableProtection);
	int PINGetEnableProtection();
	int PUKSet(const std::string &strPUK, const std::string &strNewPin);

	// Get Device info
	int GetIfid() const;
	bool IsNewPlugIn();

	// Get PIN info
	std::string GetPINStatus(bool &bIsError);

	// Get Net info
	std::string GetNetStatus(bool &bIsError);
	bool IsNetDisconnected(bool &bIsError);
	int UpdateNetStatus();
	std::string GetNetIFName(bool &bIsError);
	std::string GetNetLocalIP(bool &bIsError);
	std::string GetNetLocalMask(bool &bIsError);

	// Get Profile info
	Json::Value GetProfile(bool &blError);
	Json::Value GetUSBModemData(bool &blError);
	Json::Value GetSimInfo(bool &blError);

	// Set Profile info
	int SetProfile(const Json::Value &profile);

public:
	enum USBMODEM_INIT_STATS {
		PS_INIT_NO,
		PS_INIT_OK,
		PS_INIT_ERROR
	};

	enum USBMODEM_NET_STATS {
		PS_CONNECTED,
		PS_RECONNECTING,	// cutoff durnig connection, try to reconnect
		PS_CONNECTING,		// attempt to dial, set up connection
		PS_DISCONNECTED,
		PS_CONNECTION_LOST,
		PS_NET_ERROR
	};

private:
	// connection
	unsigned int KeyCountInText(const std::string &strText ,const std::string &strKey);
	int AssignConnectInfo();
	int BackgroundExec(
			const std::string &strWvdialPath,
			const std::string &strArgInit1,
			const std::string &strArgBaud,
			const std::string &strArgModem,
			const std::string &strArgPhone,
			const std::string &strArgUser,
			const std::string &strArgPwd,
			const std::string &strPidPath,
			const std::string &strLogPath);
	void InsertPPPModules();
	int UpdateIP();
	int GetLinkStats();
	bool IsWvdialUp() const;

	// device info
	int SetDefaultRoute(const std::string &strIsDefaultGW);

	//usbmodem variable
	unsigned int iIfid;
	USBMODEM_INIT_STATS initStatus;
	USBMODEM_NET_STATS netStatus;
	std::string strInfoPath;
	std::string strPidFile;
	unsigned int iConnectFailedAttempt;
	unsigned int _iDialAttempt;

	//Net variables
	std::string strIFName;
	std::string strLocalIP;
	std::string strLocalMask;
	static const int MAX_PROCESS_WAITTIME	= 5;

	//isBusy
	bool bIsBusy;

	bool bIsNewPlugIn;

	int cError;

	static const int MAX_ERROR_COUNT		= 5;

	// sim handler
	USBModem_SIMHandler _simHandler;
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEN_H_ */
