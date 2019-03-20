/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_USBMODEN_DEVICENODEHANDLER_HPP_
#define _SYNO_WIRELESS_USBMODEN_DEVICENODEHANDLER_HPP_

// There are too many shadow copy in wvmodem.h
#pragma GCC diagnostic ignored "-Wshadow"

#include <string>
#include <vector>

#include <synowireless/semaphore/semaphore.hpp>
#include <wvmodem.h>

namespace synowireless {
namespace usbmodem_lib {

class USBModem_DeviceNodeHandler {
public:
	//Construct/Destruct and init
	USBModem_DeviceNodeHandler(unsigned int inIfid);
	virtual ~USBModem_DeviceNodeHandler();

	int InitHandler(const std::string &strInputFilePath, const std::string &strQueryCommand);
	int SendCommand(const std::string &strInCommand, std::string &strOutString);
	int GetConnectNode(std::string &strNodePath);
	void ReleaseConnectNode();

private:
	// device node
	int DrainDeviceBuffer();
	int OpenFileDevice(const std::string &strInDevice);
	void CloseFileDevice();
	void CloseDeviceAndQueryNode();
	int ModemCmd(const std::string &strInCommand, std::string &strOutString);
	int InitDeviceNodeList();
	int AssignQuaryNode();
	int AssignConnectNode();
	int TestNode(const std::string &strDevPath, std::string &strRet);
	int GetModemCmdRetryTimes(int &cRetry);

private:
	//semaphore
	synowireless::semaphore::Semaphore _semaphore;

	// modem pointer for quary information
	WvModem *_pModem;

	// private member variables
	std::vector<std::string> _vDeviceNodeList;
	bool _blMultiNodeDevice;
	std::string _strNodePathPrefix;
	std::string _strQueryCommand;
	std::string _strInfoPath;
	std::string _strConnectDevNode;
	std::string _strQuaryDevNode;
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_USBMODEN_DEVICENODEHANDLER_H_ */
