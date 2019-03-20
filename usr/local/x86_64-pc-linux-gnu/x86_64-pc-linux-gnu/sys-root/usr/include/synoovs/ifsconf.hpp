/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_INTERFACE_CONF_HPP_
#define __SYNO_OVS_INTERFACE_CONF_HPP_

#include<set>
#include<string>

namespace SYNO {
namespace OVS {
	/**
	 * This object is used to record the related interface of the OpenvSwitch.
	 * It should be one the USAGE or IGNORE type accroding to the file path.
	 **/
	class OVSIfsConf {
		public:
			OVSIfsConf(const std::string strPathName);
			virtual ~OVSIfsConf();

			int WriteToConfig(const std::set<std::string> &sUseIfs) const;
			int Write(const std::string &strInterface);
			int Remove(const std::string &strInterface);

		private:
			int CheckAndMkdir() const;
			int LoadFromConfig();
			std::string _strPathName;
			std::set<std::string> _sIfsNames;

	}; //OVSIfsConf
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_INTERFACE_CONF_HPP_
