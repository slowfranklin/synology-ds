/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_CONF_HPP_
#define __SYNO_OVS_CONF_HPP_

#include<set>
#include<string>

namespace SYNO {
namespace OVS {
	/**
	 * This object is used to record the usage of the OpenvSwitch.
	 * The caller should register its name before it use the OpenvSwitch functions.
	 * Otherwise, the behavior of the OpenvSwitch is undefined. The caller also should
	 * unregister its name when it doesn't need the OpenvSwitch any more.
	 **/
	class OVSRegConf {
		public:
			OVSRegConf();
			virtual ~OVSRegConf();

			bool IsUsed() const { return _sRegNames.size() != 0; }
			int Register(const std::string &strName);
			int UnRegister(const std::string &strName);
			int IsRegister(const std::string &strName);

			int GetRegNames(std::set<std::string> &sRegNames);

			int LoadFromConfig();
		private:
			int CheckAndMkdir() const;
			int WriteToConfig() const;
			std::set<std::string> _sRegNames;
	}; //OVSRegConf
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_CONF_HPP_
