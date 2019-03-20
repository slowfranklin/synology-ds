// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETWORK_ROUTE_MODULE__
#define __SYNO_NETWORK_NETWORK_ROUTE_MODULE__

#include <string>
#include <vector>
#include <pthread.h>
#include "base_module.hpp"
#include <synowireless/utils/ip_address.hpp>

#define SZK_GATEWAY_LIST_IPTYPE		"iptype"

#define SZK_GATEWAY_LIST_TYPE       "type"
#define SZV_GATEWAY_LIST_TYPE_WAN   "wan"
#define SZV_GATEWAY_LIST_TYPE_LAN   "lan"
#define SZV_GATEWAY_LIST_TYPE_ALL   "all"

#define SZK_ROUTE_PRIORITY			"priority"
#define SZK_ROUTE_INTERFACE			"ifname"
#define SZK_ROUTE_IP				"ip"
#define SZK_ROUTE_MASK				"mask"
#define SZK_ROUTE_GATEWAY			"gateway"
#define SZK_ROUTE_GATEWAY_V6		"gateway_v6"
#define SZK_ROUTE_DNS				"dns"
#define SZK_ROUTE_DNS_V6            "dns_v6"
#define SZK_ROUTE_SLAVE				"slave"
#define SZK_ROUTE_ENABLE			"enable"
#define SZK_ROUTE_TYPE				"type"
#define SZK_ROUTE_ACTIVE			"active"
#define SZK_ROUTE_CLASS				"class"
#define SZK_ROUTE_PREFIX_LENGTH		"prefix_length"
#define SZK_ROUTE_EXIST				"exist"
#define SZV_CLASS_ETHERNET			"ethernet"
#define SZV_CLASS_LAN				"lan"
#define SZV_CLASS_3G				"3g"
#define SZV_CLASS_VPN				"vpn"
#define SZV_CLASS_PPPOE				"pppoe"
#define SZV_CLASS_IPV6TUNNEL		"ipv6tunnel"
#define SZV_CLASS_DEFAULT			"unknown"
#define SZV_ROUTE_FIRST_PRIORITY	0
#define SZV_ROUTE_LAST_PRIORITY		-1
#define SZV_ROUTE_ORIGINAL_PRIORITY	-2
#define SZV_ROUTE_DEFAULT_GATEWAY	""
#define SZV_ROUTE_DEFAULT_DNS		""
#define SZK_ROUTE_NAMESERVER		"nameserver"
#define SZK_DHCPC_DNS				"DNS"
#define SZK_IS_DEFAULT_GATEWAY		"is_default_gateway"
#define SZK_INTERFACE_DESTINATION	"interface_destination"
#define SZK_INTERFACE_SOURCE		"interface_source"
#define SZK_INTERFACE_SOURCE_DELETE	"interface_source_delete"
#define SZ_ROUTE_BR0				"br0"
#define SZ_ROUTE_BR0_PRIMARY_SLAVE	"eth0"
#define SZ_ROUTE_LBR0				"lbr0"

#define SZF_SYNONETDTOOL			"/usr/syno/sbin/synonetdtool"
#define SZF_DEFAULT_GATEWAY_FILE	"/etc/iproute2/config/default-gateway"
#define SZF_DEFAULT_GATEWAY_V6_FILE	"/etc/iproute2/config/default-gateway-v6"

namespace synonetwork {
namespace network {
namespace module {

enum GATEWAY_TYPE {
	GTYPE_V4,
	GTYPE_V6,
};

struct GatewayInfo {
	std::string strIfName;
	std::string strClass;
	synowireless::utils::IPAddress gateway;
	synowireless::utils::IPAddress dns;
	bool blSlave;
};

class RouteModule : public BaseModule{
public:
	RouteModule();
	virtual ~RouteModule();
	static BaseModule* Create();

	virtual int ProcessRequest(const Json::Value &input, Json::Value &output);
private:
	virtual int InitialModule();
	virtual int TerminateModule();
	virtual int StartModule();
	int WriteGatewayListToFile(const GATEWAY_TYPE type);
	int AddGatewayInfo(const Json::Value &input);
	int DelGatewayInfo(const Json::Value &input);
	int GetGatewayListData(const Json::Value &input, Json::Value &output);
	int GetGatewayDataByInterface(const Json::Value &input, Json::Value &output);
	int WriteDnsFile(const GATEWAY_TYPE type);
	int SetSlaveForGatewayInfo(const Json::Value &input);
	int CopyGatewayData(const Json::Value &input);
	int RefreshDefaultGateway(const Json::Value &input);
	int RefreshDefaultGatewayV4();
	int RefreshDefaultGatewayV6();
	int ReadGatewayListFromFile(const GATEWAY_TYPE type);
	int WriteGatewayToDatabase(const GATEWAY_TYPE type);
	int IsGatewayConfigChanged(const Json::Value &input);
	int IsDnsConfigChanged(const Json::Value &input);
	int IsDatabaseChanged(std::string strInterface, std::string strKey, std::string strValue);

	std::vector<GatewayInfo> gatewayList_v4;
	std::vector<GatewayInfo> gatewayList_v6;
	pthread_mutex_t _mRouter;
};

} /* namespace module */
} /* namespace network*/
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETWORK_ROUTE MODULE__ */
