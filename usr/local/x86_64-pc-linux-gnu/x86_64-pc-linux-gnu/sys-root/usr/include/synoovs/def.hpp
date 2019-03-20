/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_OVS_DEFINE_H_
#define __SYNO_OVS_DEFINE_H_

#define SZF_COPY		"/bin/cp"
#define SZF_SYNO_MODULE_TOOL	"/usr/syno/bin/synomoduletool"
#define SZF_SBIN_SYNONETDTOOL	"/usr/syno/sbin/synonetdtool"
#define SZF_RC_NETWORK_SCRIPT	"/etc/rc.network"
#define SZF_OVS_VSCTL		"/usr/bin/ovs-vsctl"

#define SZ_SERVICE_SYNOWIFID	"synowifid"
#define SZ_LIST_BRIDGE		"list-br"
#define SZ_DELETE_PORT		"del-port"
#define SZ_ADD_PORT			"add-port"
#define SZ_SYNOOVS_DB		"synoovs-db"
#define SZ_SYNOOVS_VSWITCH	"synoovs-vswitch"
#define SZ_OVS_PREFIX		"ovs_"
#define SZ_WLAN_PREFIX		"wlan"
#define SZ_PPP_PREFIX		"ppp"
#define SZ_TUN_PREFIX		"tun"
#define SZ_LINUX_BOND_PREFIX "bond"
#define SZ_OVS_BOND_PREFIX  SZ_OVS_PREFIX"bond"

#define SZK_OVS_VLAN_ID		"OVS_VLAN_ID"

//Bonding
#define BOND_MAX_NUMBER		 10

#define SZK_OVS_BOND_MOD	 "bond_mode"
//Although the OVS/Linux use the same name "active-backup" in its config.
//the HA want to distiguish the OVS bond and Linux Bond. We force modify the ovs active-backup to 'ovs-active-backup' and only use the 'active-backup' in OVS config.
#define SZ_OVS_FAILOVER_CONFIG "active-backup"
#define SZ_IFCFG_BOND_FAILOVER "\""SZK_OVS_BOND_MOD"=" SZ_OVS_FAILOVER_CONFIG" lacp=off\""
#define SZ_IFCFG_BOND_SLB "\""SZK_OVS_BOND_MOD"=" SZV_OVS_BOND_SLB" lacp=off\""
#define SZ_IFCFG_BOND_TCP "\""SZK_OVS_BOND_MOD"=" SZV_OVS_BOND_TCP" lacp=active\""

#define SZF_SYNO_OVS_DIR "/usr/syno/etc/synoovs"
#define SZF_SYNO_OVS_REG_CONF SZF_SYNO_OVS_DIR"/ovs_reg.conf"
#define SZF_SYNO_OVS_IFS_CONF SZF_SYNO_OVS_DIR"/ovs_interface.conf"
#define SZF_SYNO_OVS_IGNORE_CONF SZF_SYNO_OVS_DIR"/ovs_ignore.conf"

namespace SYNO {
namespace OVS {
typedef enum{
	OVS_INTERNAL_ERR = -1,
	OVS_SUCCESS,
	OVS_NAME_HAS_EXIST,
	OVS_NAME_NO_EXIST,
	OVS_NOT_SUPPORTED_PLATFORM,

	// DSM #82883
	OVS_NOT_SUPPORTED_BONDING = 4370,
} OVS_ERROR;
} // OVS
} // SYNO

#endif //__SYNO_OVS_DEFINE_H_
