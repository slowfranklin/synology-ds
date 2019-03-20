
// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETWORK_DEVICELIST_MODULE_FD__
#define __SYNO_NETWORK_NETWORK_DEVICELIST_MODULE_FD__

#include <synowireless/network/base_module.hpp>
#include <synowireless/network/upnpscanner.hpp>
#include <synowireless/network/dsscanner.hpp>
#include <synowireless/network/wifiscanner.hpp>
#include <synowireless/network/arpscanner.hpp>
#include <synowireless/network/clientlist.hpp>

namespace synonetwork {
namespace network {
namespace module {

class DeviceListModule : public BaseModule {
public:
	DeviceListModule();
	~DeviceListModule();
	static BaseModule* Create();
	int ProcessRequest(const Json::Value &input, Json::Value &output);

private:
	int InitialModule();
	int TerminateModule();
	int StartModule();

private:

	void StartUpnpScanner();
	void StopUpnpScanner();
	void StartDSScanner();
	void StopDSScanner();
	void StartWifiScanner();
	void StopWifiScanner();
	void StartArpScanner();
	void StopArpScanner();

	void InitClientList();
	void TerminateClientList();

	int GetUpnpScannerData(Json::Value &data);
	int GetDSScannerData(Json::Value &data);
	int GetWifiScannerData(Json::Value &data);
	int GetArpScannerData(Json::Value &data);
	int GetAllScannerData(Json::Value &data);
	int MergeList(const Json::Value &data, const bool &blAddIfExist);

	// method
	int GetDataByScannerType(const Json::Value &indata, Json::Value &outdata);
	int SetData(const Json::Value &indata);
	int DeleteData(const Json::Value &indata);

	UpnpScanner *_upnpscanner;
	DSScanner *_dsscanner;
	WifiScanner *_wifiscanner;
	ArpScanner *_arpscanner;

	ClientList _clientlist;
};

} /* namespace module */
} /* namespace network*/
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETWORK_DEVICELIST_MODULE_FD__ */
