/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_NETWORK_DBUS_CLIENT_HPP_
#define _SYNO_NETWORK_DBUS_CLIENT_HPP_

#include <json/value.h>

#include <synonetsdk/dbus/dbus_client.hpp>

namespace synonetwork {
namespace dbus {

class NetClient : public synonetsdk::dbus::DBusClient {
public:
	NetClient();
	virtual ~NetClient();

	virtual bool IsServerReady() const;

	int GetDeviceListData(const std::string &strType, Json::Value &outdata);
	int SetDeviceListData(const Json::Value &data);
	int DelDeviceListData(const std::string &strMac);
	int GetGatewayListData(Json::Value &info, Json::Value &outdata);
	int AddGatewayData(Json::Value &info);
	int DelGatewayData(Json::Value &info);
	int GetGatewayDataByInterface(Json::Value &info, Json::Value &outdata);
	int SetSlaveData(Json::Value &info);
	int CopyGatewayData(Json::Value &info);
	int RefreshGateway(Json::Value &info);
	int ResetIPv6Module(const std::string &ifname);

private: /* They will not be implemented. Do NOT use them */
	NetClient(const NetClient &);
	NetClient operator=(const NetClient &);

}; /* class NetClient */

} /* namespace dbus */
} /* namespace synonetwork */

#endif /* _SYNO_NETWORK_DBUS_CLIENT_HPP_ */
