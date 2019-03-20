/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_VLAN_MANAGER_HPP_
#define __SYNO_OVS_VLAN_MANAGER_HPP_

#include <vector>
#include <string>

extern "C" {
#include <synonetsdk/net.h>
}

namespace SYNO {
namespace OVS {
namespace VlanManager {

	/**
	 * Those function are used to operate the vlan tag of OpenvSwitc interface.
	 * Since the OpenvSwitch does not provide the library to control it directly,
	 * We modify the ifcfg config and use the ovs-* tools to manage the OpenvSwtich
	 **/

	/* Main Operation.
	 */
	int Get(const std::string &strVlanInterface, PSLIBVLAN pVlanInfo);
	int Set(const std::string &strInterface, const std::string &ID);
	int Clear(const std::string &strInterface);
	int Remove(const std::string &strInterface);
	int Create(const std::string &strInterface, const std::string &strID);

}; /* VLANManager */
} /* OVS */
} /* SYNO */

#endif //__SYNO_OVS_VLAN_MANAGER_HPP_
