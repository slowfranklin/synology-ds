/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_OVS_HPP_
#define __SYNO_OVS_HPP_

#include <set>
#include <map>
#include <vector>
#include <string>

extern "C"{
#include <synonetsdk/net.h> // PSLIBVLAN
}

namespace SYNO {
namespace OVS {
	typedef std::map<std::string, std::string> mBondMode;

	int ListInterface(std::set<std::string> &sOVSIfs);
	int AttachPort(const std::string &strIfsName, const std::string &strPortName);
	int DetachPort(const std::string &strIfsName, const std::string &strPortName);

	// Register
	int IsRegister(const std::string &strName);
	int Register(const std::string &strName, const mBondMode& = mBondMode() );
	int UnRegister(const std::string &strName, const mBondMode& = mBondMode() );
	//Ignore the specific interface for HA heartbeat only.
	int RemoveInterface(const std::string &strName);
	int AddInterface(const std::string &strName);

	// OVS Usage
	int GetAllRegister(std::set<std::string> &sRegNames);
	int IsOVSRunning();
	int IsOVSSupport();

	// vlan function.
	int OVSVlanGet(const std::string &strVlanInterface, PSLIBVLAN pVlanInfo);
	int OVSVlanSet(const std::string &strVlanInterface, const std::string &strVlanID);
	int OVSVlanClear(const std::string &strVlanInterface);
	int OVSVlanCreate(const std::string &strVlanInterface, const std::string &strVlanID);
	int OVSVlanRemove(const std::string &strVlanInterface);

	// Bonding functions.
	int OVSBondCreate(SYNOLINKAGGRMODE mode, const std::string &strMaster, std::vector<std::string> &vSlaveIfs);
	int OVSBondRemove(const std::string &strMaster, PSYNOLINKAGGROPT laOpt);
	int OVSBondGet(const std::string &strMaster, PSYNOLINKAGGROPT laOpt);
	int OVSBodChMode(SYNOLINKAGGRMODE newMode, const std::string &strMaster);
	int GetUniqueBondName(std::string &strMode);
	SYNOLINKAGGRMODE StrToMode(const char *szMode);
	void ModeToStr(SYNOLINKAGGRMODE mode, std::string &strMode);
	bool CheckModeSupport(SYNOLINKAGGRMODE mode);

	// Reset OVS
    void OVSSetDefault();

} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_HPP_
