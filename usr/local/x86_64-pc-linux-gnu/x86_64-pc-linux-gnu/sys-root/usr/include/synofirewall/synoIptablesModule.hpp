/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_SYNOMODULE_H__
#define __SYNO_SYNOMODULE_H__

#include <string>
#include <vector>

namespace FW {
class SYNO_IPTABLES_MODULES {
	public:
		static bool iptablesModListGet(const std::string &key, std::vector<std::string> &moduleList);
		static bool iptablesCoreModLoad(const std::string &servName);
		static bool iptablesCoreModUnload(const std::string &servName);
		static bool iptablesNATModLoad(const std::string &servName);
		static bool iptablesNATModUnload(const std::string &servName);
		static bool moduleInsert(const std::string &servName, const std::vector<std::string> &moduleList);
		static bool moduleRemove(const std::string &servName, const std::vector<std::string> &moduleList);
		static bool isModuleLoad(const std::string &servName);

//	privstatic ate: FIXME should be private but for test
		static bool coreCommonModuleLoad(std::vector<std::string> &moduleList);
		static bool natModuleLoad(std::vector<std::string> &moduleList);
};
}

#endif /* __SYNO_SYNOMODULE_H__ */
