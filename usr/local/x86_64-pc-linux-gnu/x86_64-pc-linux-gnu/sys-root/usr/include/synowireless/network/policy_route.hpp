// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_NETWORK_NETWORK_POLICY_ROUTE__
#define __SYNO_NETWORK_NETWORK_POLICY_ROUTE__

#include <string>
#include <json/value.h>
#include <synowireless/utils/ip_address.hpp>
#include <synowireless/utils/lock.hpp>

#define RT_TABLE_LOCK_FILE "/tmp/lock/lock_rt_tables"

namespace synonetwork {
namespace network {

enum IP_TYPE {
	IP_TYPE_V4,
	IP_TYPE_V6,
};

struct RouteRule {
	IP_TYPE type;
	synowireless::utils::IPAddress ip;
	synowireless::utils::IPAddress mask;
	synowireless::utils::IPAddress gateway;
	std::string prefixLength;
	std::string strIfName;
};

struct PolicyRouteRule : public RouteRule{
	std::string strService;
};

class PolicyRoute {
public:
	PolicyRoute();
	~PolicyRoute();
	int EnableTable(const IP_TYPE &type, const std::string &strIfname, const std::string &strSourceIP);
	int DisableTable(const IP_TYPE &type, const std::string &strIfname);
	int GetEnableTables(Json::Value &names);
	int AddRule(const PolicyRouteRule &rule);
	int DeleteRule(const IP_TYPE &type, const std::string &strService, const std::string &strIfName);
private:
	int InitMaxID();
	int ConfigWrite(const IP_TYPE &type, const std::string &strTableName, const std::string &strSourceIP, const bool &blEnable);
	int SetTableLookupRule(const IP_TYPE &type, const std::string &strTableName);
	int SetTableRouteRule(const IP_TYPE &type, const std::string &strRuleTable);
	void FlushTableRule(const IP_TYPE &type, const std::string &strTableName);
	int FlushTableLookupRule(const IP_TYPE &type, const std::string &strTableName);
	bool IsRulesEmpty(const std::string &strRuleTable);

	int maxID;
	synowireless::utils::FileLock mLock;
};

} /* namespace network*/
} /* namespace synonetwork */

#endif /* __SYNO_NETWORK_NETWORK_POLICY_ROUTE__ */
