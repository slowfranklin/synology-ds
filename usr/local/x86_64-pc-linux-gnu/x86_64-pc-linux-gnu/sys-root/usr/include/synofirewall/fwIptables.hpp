/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_FWIPTABLES_H__
#define __SYNO_FWIPTABLES_H__

#include <synocore/synotype.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synocore/conf.h>
#include <json/json.h>
#include <vector>
#include <synoserviceconf/synoserviceconf.h>

#include <synonetsdk/net.h>
#include "synofirewall/synoFW.hpp"
#include "synofirewall/fwDB.hpp"

#define IPTABLES_ARG_ADAPTER	"adapter"
#define IPTABLES_ARG_IP			"ip"
#define IPTABLES_ARG_PORT		"port"
#define IPTABLES_ARG_CHAIN		"chain"
#define IPTABLES_ARG_TABLE		"table"
#define IPTABLES_ARG_POLICY		"policy"

#define SZ_IF_TUN_PREFIX		"tun"
#define SZ_IF_TUN1000			"tun1000"

#define IPTABLES_CMD_KEY_V4		"v4"
#define IPTABLES_CMD_KEY_V6		"v6"

namespace FW {
	typedef std::map<FW_PORT_PROTOCOL, port_list_t> serv_port_map_t;
	struct ServPort {
		serv_port_map_t srcPortsMap;
		serv_port_map_t dstPortsMap;
	};

	// Firewall to iptables
	class SYNOFW_IPTABLES_RULES {
		public:
			SYNOFW_IPTABLES_RULES();
			~SYNOFW_IPTABLES_RULES();
			bool fwRulesToIptablesRules(const bool &blAllowEstabledConn,
					const fwrule_map_t &ruleList, const adapter_policy_t &adapterPolicyMap, Json::Value &iptablesRuleList);

			void iptablesArgToCmd(const string &adapter, const FWRULE &rule, const Json::Value &jIptablesArg, Json::Value &jIptablesCmd);
			bool jIptablesCmdInit(Json::Value &jIptablesCmd);
			void iptablesRulesInit(Json::Value &jIptablesArg);
			bool adapterToIptablesArg(const string &adapter, const FWRULE &rule, Json::Value &jIptablesArg);
			bool ipToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
			bool servToPorts(const port_list_t &servsList, ServPort &portMap);
			bool servPortToCmd(const port_list_t &servList, Json::Value &jIptablesArg);
			bool portToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
			bool chainToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
			bool tableToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
			bool policyToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
			bool ipTypeToIptablesArg(const FWRULE &rule, Json::Value &jIptablesArg);
		private:
			SYNO_FW_SERVICES *m_pServices;
			std::vector<std::string> m_adapterList;
			std::vector<std::string> m_vpnAdapterList;
			std::string m_pppoeAdatper;

			bool enabledAdapterEnum();
			void pppoeAdaterGet();
			bool vpnAdatperEnum();
			bool adapterIsEnabled(const adapter_t &adatper);
	};
} /* FW */

#endif /* __SYNO_FWIPTABLES_H__ */
