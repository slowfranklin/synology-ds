/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_FW_H__
#define __SYNO_FW_H__

#include <synocore/synotype.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synocore/conf.h>
#include <json/json.h>
#include <vector>
#include <map>
#include <boost/assign/list_of.hpp>
#include <synonetsdk/net.h>

#include "synofirewall/fwDB.hpp"
#include "synofirewall/fwIptables.hpp"

#define FW_SERV_NAME					"firewall"
#define FW_PROFILE_DB_DIR				"/usr/syno/etc/firewall.d/"
#define SZ_ADAPTER_GLOBAL				"global"

#define FW_CONFIG_PATH					FW_PROFILE_DB_DIR "firewall_settings.json"
#define FW_PROFILE_DB_PROFILE_META		FW_PROFILE_DB_DIR "/meta.json"
#define FW_DEFAULT_PROFILE_NAME			"default"

// Config Key
#define FW_CONFIG_PROFILE				"profile"
#define FW_CONFIG_STATUS				"status"

#define MAX_NUM_EXECV_ARGS				256

#define FW_IPTABLES_EXEC_LOCK			"/tmp/firewall_iptables_exec.lock"
#define TIMEOUT_FW_IPTABLES_EXEC_LOCK	30

namespace FW {
	//Almost the services use TCP or UDP. If some services need to set extra protocols, ex. VPN, record it by this structure.
	typedef struct _tag_syno_fw_extra_serv_protocol_map_ {
		const char *szService; //unique service name
		unsigned int protocols[4]; //protocols used by szService, represented by decimal
	} SYNO_FW_EXTRA_SERV_PROTOCOL_MAP;

	typedef Json::Value											config_t;
	typedef std::map<adapter_t, FW_POLICY>						port_check_result_t;

	const std::vector<std::string> gPreDefineAdapter = boost::assign::list_of(SZ_ADAPTER_GLOBAL)(SZ_ID_PPPOE)(SZ_ADAPTER_VPN);
	const std::vector<std::string> gDefaultRuleChain = boost::assign::list_of(FIREWALL_IPTABLES_CHAIN)(FIREWALL_IPTABLES_FORWARD_CHAIN);

	struct PortCompareST {
		FW_PORT_DIRECT portDirect;
		FW_PORT_PROTOCOL portProtocol;
		string port;

		PortCompareST(const FW_PORT_DIRECT &direct,
				const FW_PORT_PROTOCOL &protocol,
				const string &_port):portDirect(direct), portProtocol(protocol), port(_port) {}
	};
	struct PortCompareSrcST {
		FW_PORT_DIRECT portDirect;
		FW_PORT_PROTOCOL portProtocol;
		port_list_t portList;

		PortCompareSrcST(const FW_PORT_DIRECT &direct,
				const FW_PORT_PROTOCOL &protocol,
				const port_list_t &ports):portDirect(direct), portProtocol(protocol), portList(ports) {}
	};

	// Firewall operations
	class SYNOFW {
		public:
			SYNOFW();
			~SYNOFW();

			bool fwEnable();
			bool fwDisable();
			bool fwReload(const bool blAllowEstabledConn = true);
			bool fwReset();
			bool fwStatus(bool &fwEnabled);
			bool fwUpdate();

			// Config
			bool configGet(Json::Value &jConfig);
			bool configSet(const config_t &config);

			bool fwAdapterEnum(adapter_list_t &adapterList);
			bool fwIptablesRulesEnum(profile_name_t, Json::Value &jIptablesRuleCmd, const bool blAllowEstabledConn = true);
			bool fwProfileConfigGet(profile_name_t &pName);
			bool fwProfileConfigSet(const profile_name_t &name, bool fwReload);

			bool TestApplyingProfile(profile_name_t oriProfileName);

			bool fwServIsBlocked(const std::string &servName, const adapter_t &adapter,
					port_check_result_t &portCheckResult);
			bool fwPortIsBlocked(const PortCompareST &portTarget, const adapter_t &adapter,
					port_check_result_t &portCheckResult);
		private:
			void initJconfig(Json::Value &jConfig);
			bool cmdExec(const string &cmd);
			bool fwExec(const Json::Value jIptablesRuleCmd);
			bool fwClear();
	};

	class SYNOFW_PROFILE {
		public:
			SYNOFW_PROFILE();
			~SYNOFW_PROFILE();

			// profile operation
			bool profileCreate(const profile_name_t &profileName);
			bool profileGet(const profile_name_t &profileName, FWPROFILE &profile);
			bool profileSet(const profile_name_t &profileName, const FWPROFILE &profile);
			bool profileDelete(const profile_name_t &profileName);
			bool profileExist(const profile_name_t &profileName);
			bool profileEnum(profile_list_t &profileList);
			bool profileEnum(std::vector<profile_name_t> &profileNameList);
			bool profileRename(const profile_name_t &profileName, const profile_name_t &newProfileName);
			bool CreateTestProfile(profile_name_t oriProfileName, const FWPROFILE &profile);
			bool AdoptTestProfile(profile_name_t oriProfileName);
			bool RemoveTestProfile(profile_name_t oriProfileName);

			// Rules
			bool profileAddServToReserve(const adapter_t &adapter, const string &servName, const FW_POLICY policy, bool fwReload);
			bool profileRemoveServ(const std::string &servName);
			bool profileChangeAdapter(const adapter_t &oriAdapterName, const adapter_t &newAdapterName, bool fwReload);
		private:
			SYNOFW_JSON_DB m_dbObj;
	};

	// TODO: writer validator
	class SYNOFW_RULE_VALID {
		public:
			SYNOFW_RULE_VALID();
			~SYNOFW_RULE_VALID();
			bool ruleValid(const FWRULE &rule);
		private:
			bool adapterValid(const adapter_t &adapter);
			bool labelListValid(const label_list_t &labelList);
			bool ruleNameValid(const std::string &name);

			bool ipValid(const FWRULE &rule);
			bool ipTypeValid(const FWRULE &rule);

			bool portValid(const FWRULE &rule);
	};
} /* FW */

#endif /* __SYNO_FW_H__ */
