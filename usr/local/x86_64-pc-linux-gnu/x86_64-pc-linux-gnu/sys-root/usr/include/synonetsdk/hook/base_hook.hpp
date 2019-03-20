/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_NETWORK_UTILS_BASE_HOOK_HPP_
#define _SYNO_NETWORK_UTILS_BASE_HOOK_HPP_

#include <string>
#include <map>

extern "C" {
#include <synocore/synoglobal.h>
#include <synosdk/plugin.h>
}

namespace synonetsdk {
namespace hook {

class BaseHook {
	public:
		bool SetEnv(const std::string &key, const std::string &value);
		std::string GetEnv(const std::string &key);
		bool ExecHook(SDK_PLUGIN_ACTION action);
	protected:
		BaseHook(const std::string &module, const std::string &path);
		virtual ~BaseHook();
	private:
		PSLIBPLUGIN pPlugin;
		std::string mModule;
		std::string mPath;
		std::map<std::string, std::string> mEnvMap;

		void Init();
		virtual bool IsValid();
};

} /* namespace hook */
} /* namespace synonetsdk */

#endif /* _SYNO_NETWORK_UTILS_BASE_HOOK_HPP_ */
