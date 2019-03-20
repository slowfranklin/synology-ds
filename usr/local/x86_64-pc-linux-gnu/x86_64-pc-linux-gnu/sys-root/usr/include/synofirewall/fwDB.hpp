/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_FWRULE_H__
#define __SYNO_FWRULE_H__

#include <synocore/synotype.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synocore/conf.h>
#include <synonetsdk/net.h>
#include <json/value.h>

#include <vector>
#include <map>
#include <set>

using std::string;

namespace FW {
	#define FIREWALL_IPTABLES_CHAIN				"INPUT_FIREWALL"
	#define FIREWALL_IPTABLES_FORWARD_CHAIN		"FORWARD_FIREWALL"
	#define FIREWALL_IPTABLES_TABLE				"filter"

	#define SZ_SERV_RESERVE_RULE_NAME			"Service"

	#define SZ_ADAPTER_VPN						"vpn"

	enum FW_ADAPTER_DIRECT {
		FW_ADAPTER_DIRECT_DEST = 0,
		FW_ADAPTER_DIRECT_SRC,
	};
	enum FW_POLICY {
		FW_POLICY_ALLOW = 0,
		FW_POLICY_DROP,
		FW_POLICY_NONE,
		FW_POLICY_PARTIAL, // This is for port blocked check result

		// this is only used in internal
		FW_POLICY_PARTIAL_ALLOW, // This is for port blocked check result
		FW_POLICY_PARTIAL_DROP, // This is for port blocked check result
	};
	enum FW_IP_TYPE {
		FW_IP_TYPE_IPV4 = 0,
		FW_IP_TYPE_IPV6,
		FW_IP_TYPE_ALL,
	};
	enum FW_IP_DIRECT{
		FW_IP_DIRECT_DEST = 0,
		FW_IP_DIRECT_SRC,
	};
	enum FW_IP_GROUP {
		FW_IP_GROUP_IP, //ipList: ["1.1.1.1"]
		FW_IP_GROUP_NETMASK, //ipList: ["1.1.1.1", "255.255.255.0"]
		FW_IP_GROUP_IPSET, //ipList: ["1.1.1.1", "2.2.2.2", "3.3.3.3" ....]
		FW_IP_GROUP_GEOIP, //ipList: ["CN", "TW" ....]
		FW_IP_GROUP_IPRANGE, //ipList: ["1.1.1.1", "2.2.2.2"]
		FW_IP_GROUP_ALL, //ipList: []
	};
	// The same as SYNO_FW_PROTOCOL for compitability of service section port file
	enum FW_PORT_PROTOCOL {
		FW_PORT_PROTOCOL_TCP = 0x01,
		FW_PORT_PROTOCOL_UDP = 0x02,
		FW_PORT_PROTOCOL_ICMP = 0x04,
		FW_PORT_PROTOCOL_ALL = FW_PORT_PROTOCOL_TCP|FW_PORT_PROTOCOL_UDP, // includes protocols out of icmp
	};
	enum FW_PORT_DIRECT {
		FW_PORT_DIRECT_DEST = 0,
		FW_PORT_DIRECT_SRC,
	};
	enum FW_PORT_GROUP {
		FW_PORT_GROUP_SERVICE = 0, //portList: ["nfs", "afp" ...]
		FW_PORT_GROUP_CUSTOM, //portList: ["123", "234", "1234", "1234-1240", ...]
		FW_PORT_GROUP_RESERVED, //portList: ["nfs", "afp" ...]
		FW_PORT_GROUP_ALL, //portList: []
	};
	enum RULE_OP {
		RULE_BACKUP,
		RULE_BACKUP_DELETE,
		RULE_REVERT,
	};
	enum PROFILE_OP {
		PROFILE_BACKUP,
		PROFILE_BACKUP_DELETE,
		PROFILE_REVERT,
	};

	typedef std::vector<std::string>			ip_list_t;
	typedef std::vector<std::string>			label_list_t;
	typedef std::set<std::string>				chain_list_t;
	typedef std::string							adapter_t;
	typedef std::string							mac_t;
	typedef std::vector<std::string>			port_list_t;
	typedef int									rule_id_t;
	typedef std::string							profile_name_t;
	typedef std::set<adapter_t>					adapter_list_t;
	typedef std::pair<std::string, std::string>	iprange_t;
	typedef std::map<adapter_t, FW_POLICY>		adapter_policy_t;

	// Rule
	struct FWRULE {
		rule_id_t			ruleID;
		bool				enable;
		FW_ADAPTER_DIRECT	adapterDirect;
		FW_POLICY			policy;		//accept,deny,none
		bool				blLog;
		label_list_t		labelList;
		std::string			name;
		std::string			table;		// table in iptables ex: INPUT
		chain_list_t		chainList;		// chain in iptables ex: FIREWALL

		// IP
		FW_IP_TYPE			ipType;
		FW_IP_DIRECT		ipDirect;
		FW_IP_GROUP			ipGroup;
		ip_list_t			ipList;

		// Port
		FW_PORT_DIRECT		portDirect;
		FW_PORT_GROUP		portGroup;
		FW_PORT_PROTOCOL	portProtocol;	//tcp,udp,icmp,all
		port_list_t			portList;

		FWRULE() : ruleID(0), // ruleID is useless for now
				   enable(true),
				   adapterDirect(FW_ADAPTER_DIRECT_SRC),
				   policy(FW_POLICY_ALLOW),
				   blLog(false), //blLog is useless for now
				   table(FIREWALL_IPTABLES_TABLE),
				   ipType(FW_IP_TYPE_IPV4),
				   ipDirect(FW_IP_DIRECT_SRC),
				   ipGroup(FW_IP_GROUP_IP),
				   portDirect(FW_PORT_DIRECT_DEST),
				   portGroup(FW_PORT_GROUP_SERVICE),
				   portProtocol(FW_PORT_PROTOCOL_TCP)

		{
			chainList.insert(FIREWALL_IPTABLES_CHAIN);
			chainList.insert(FIREWALL_IPTABLES_FORWARD_CHAIN);
		}
	};
	typedef std::vector<FWRULE>					fwrule_list_t;
	typedef std::map<adapter_t, fwrule_list_t>	fwrule_map_t;

	struct FWPROFILE {
		profile_name_t name;
		fwrule_map_t rules;
		adapter_policy_t adapterPolicyMap;
	};
	typedef std::map<profile_name_t, FWPROFILE>	profile_list_t;

	class SYNOFW_JSON_DB {
		public:
			SYNOFW_JSON_DB();
			~SYNOFW_JSON_DB();
			bool profileExist(const profile_name_t &profileName);
			bool profileEnum(profile_list_t &profileList);
			bool profileEnum(std::vector<profile_name_t> &profileNameList);
			bool profileGet(const profile_name_t &profileName, FWPROFILE &profile);
			bool profileSet(const profile_name_t &profileName, const FWPROFILE &profile);;
			bool profileCreate(const profile_name_t &profileName);
			bool profileCreate(const profile_name_t &profileName, const FWPROFILE &profile);
			bool profileDelete(const profile_name_t &profileName);
			bool profileRename(const profile_name_t &profileName, const profile_name_t &newProfileName);
		private:
			void jsonToProfile(const Json::Value &jProfile, FWPROFILE &profile);
			void profileToJson(const FWPROFILE &profile, Json::Value &jProfile);
			void jsonToRuleList(const Json::Value jRuleList, fwrule_map_t &fwRuleList);
			void ruleListToJson(const fwrule_map_t &ruleList, Json::Value &jRuleList);
			bool profileMetaLoad(Json::Value &jMeta);
			bool profileMetaDump(const Json::Value &jMeta);
			bool profileDbDump(const profile_name_t &profileName, const Json::Value &jDB);
			bool profileDbLoad(const profile_name_t &profileName, Json::Value &jDB);
			bool profileDbRemove(const profile_name_t &profileName);
			bool ipTypeGet(const FWRULE &rule, FW_IP_TYPE &type);
			string profilePathGet(const profile_name_t &proto);
			string profilePathNameGen(const Json::Value &jMeta);
	};
} /* FW */

#endif /* __SYNO_FWRULE_H__ */
