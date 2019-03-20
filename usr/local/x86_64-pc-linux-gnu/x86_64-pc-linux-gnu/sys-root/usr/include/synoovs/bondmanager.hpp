/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_BOND_MANAGER_HPP_
#define __SYNO_OVS_BOND_MANAGER_HPP_

#include <vector>
#include <string>

extern "C" {
#include <synonetsdk/net.h> //SYNOLINKAGGRMODE

}
namespace SYNO {
namespace OVS {
namespace BondManager {

	/**
	 * Those functiojn are used to operate the Bonding behavior of OpenvSwitch.
	 * Since the OpenvSwitch does not provide the library to control it directly,
	 * We modify the ifcfg config and use the ovs-* tools to manage the OpenvSwtich
	 **/

	/* Main Operation.
	 */
	bool Create(SYNOLINKAGGRMODE mode, const std::string &strMaster, std::vector<std::string> &vSlaveIfs, bool blRestart = true);
	bool Remove(const std::string &strMaster, PSYNOLINKAGGROPT laOpt, bool blRestart = true);
	bool Get(const std::string &strMaster, PSYNOLINKAGGROPT laOpt);
	bool BondChMode(SYNOLINKAGGRMODE newMode, const std::string &strMaster);
	bool GetUniqueName(std::string &strName);

	/*
	 * Bonding Mode operation.
	 */
	SYNOLINKAGGRMODE StrToMode(const std::string &strMode);
	void ModeToStr(SYNOLINKAGGRMODE mode, std::string &strMode);
	void ModeToBondOPT(SYNOLINKAGGRMODE mode, std::string &strBondOpt);
	bool CheckModeSupport(SYNOLINKAGGRMODE mode);

	SYNOLINKAGGRMODE DefaultModeConvert(SYNOLINKAGGRMODE mode);

	}; /* BondManager */
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_BOND_MANAGER_HPP_
