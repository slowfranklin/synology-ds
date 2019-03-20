/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_MANAGER_HPP_
#define __SYNO_OVS_MANAGER_HPP_

extern "C" {
#include <synonetsdk/net.h> //PSYNOLINKAGGROPT
}

#include<set>
#include<map>
#include<string>

namespace SYNO {
namespace OVS {
	/**
	 * This object is used to operate the OpenvSwitch.
	 * Since the OpenvSwitch does not provide the library to control it directly,
	 * We modify the ifcfg config and use the ovs-* tools to manage the OpenvSwtich
	 **/
	class OVSManager {
		public:
			OVSManager();
			virtual ~OVSManager();

			bool CreateAll();
			bool DeleteAll();

			bool Start();
			bool Stop();

			int GetSwitchList(std::set<std::string> &sSwitchList);

			bool DetachPort(const std::string &strSwitch, const std::string &strPort) const;
			bool AttachPort(const std::string &strSwitch, const std::string &strPort) const;

			//For heart beat only.
			int DestroyOVS(const std::string &strInterface) const;
			int CreateOVS(const std::string &strInterface) const;
			//For bonding convert
			int InitBondOpt(const std::string &strMaster, const std::string &strNewMode);
		private:

			int CreateOVSForGeneral(const std::string& ifName, const char *szOVSIfs, const char *szfInfCfg, const char *szfOVSCfg) const;

			int GetInterface();

			//Vlan Handler
			int RemoveLinuxVlan() const;
			int RemoveOVSVlan() const;
			int CreateLinuxVlan() const;
			int CreateOVSVlan() const;

			//Bond Handler
			int RemoveLinuxBond();
			int RemoveOVSBond();
			int CreateLinuxBond();
			int CreateOVSBond();

			int InitBondOpt(const std::string &strMaster);

			std::set<std::string> _sIfs;
			std::map<std::string, SLIBVLAN> _mIfVid; //Interface to vlanInfo
			std::map<std::string, SYNOLINKAGGROPT> _mIfBondOpts;
	}; //OVSManager
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_MANAGER_HPP_
