#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef SYNOHA_CONF_H
#define SYNOHA_CONF_H

#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synohacore/node.h>
#include <sys/param.h>

// must sync with HAUtil.js `SYNO.SDS.HA.CONF_MAX_HA_IF_NUM`
#define MAX_HA_IF_NUM 12

#define MAX_IF_NUM  MAX_HA_IF_NUM
#define SZF_HA_CONF SZD_HA_PREFIX"/etc/ha.conf"
#define SZF_HA_CONF_DEFAULT SZD_HA_PREFIX"/etc.defaults/ha.conf"
#define SZF_HA_TMP_CONF "/tmp/.ha.conf"
#define SZ_HA_DRBD_MTU_VALUE "9000"
#define COROSYNC_KEY_SIZE (10)
#define MAX_HA_MODEL_SIZE (16)
#define MAX_HA_UNIQUE_SIZE (64)
#define MAC_STR_SIZE (18) // xx:xx:xx:xx:xx:xx
#define HA_MTU_STR_SIZE (6) // TCP max packet size 65535
#define HA_DRBD_MTU_VALUE (9000)
#define SZF_HA_DRBD_OVS_BOND_MODE_CONF  "/usr/syno/etc/synoha/ha_drbd_ovs_bond.conf"
#define SZK_HA_DRBD_OVS_BOND_MODE       "drbd_ovs_bond_mode_origin"

/**
 * Used in @ref SYNOHAGetConf
 */
typedef enum {
	/** DRBD interface */
	HA_CONF_DRBD_IF,
	/** Original DRBD interface */
	HA_CONF_DRBD_IF_ORIGIN,
	/** DRBD IP address of node 0, not always remote or local node */
	HA_CONF_DRBD_IP0,
	/** DRBD IP address of node 1, not always remote or local node */
	HA_CONF_DRBD_IP1,
	/** Netmask of DRBD interface, shared between nodes */
	HA_CONF_DRBD_NETMASK,
	/** Original NIC Bonding mode of DRBD interface, if applicable. */
	HA_CONF_DRBD_BOND_MODE_ORIGIN,
	/** Original MTU value of DRBD interface, if applicable. */
	HA_CONF_DRBD_MTU_ORIGIN,

	/** Host name of node 0, not always remote or local */
	HA_CONF_HOST0,
	/** Host name of node 1, not always remote or local */
	HA_CONF_HOST1,
	/** Main IP address of node 0, not always remote or local */
	HA_CONF_IP0,
	/** Main IP address of node 1, not always remote or local */
	HA_CONF_IP1,

	/** Corosync key */
	HA_CONF_COROSYNC_KEY,
	/** HA serial number, used for S2S client id generation */
	HA_CONF_SN,
	/** HA customized serial number, used for DDNS id generation */
	HA_CONF_SN_CUSTOM,
	/** HA model, used for surveillance license checking */
	HA_CONF_MODEL,
	/** HA unique */
	HA_CONF_UNIQUE,

	/** HA host name */
	HA_CONF_HA_HOST,
	/** HA main interface */
	HA_CONF_HA_IF_MAIN,
	/** HA gateway */
	HA_CONF_HA_GATEWAY,
	/** The time HA was built */
	HA_CONF_BEGIN_TIME,
	/** Is hybrid HA */
	HA_CONF_IS_HYBRID,
	/** Hybrid HA model group number */
	HA_CONF_MODEL_GROUP,
	/** Model of node 0, only available in hybrid mode */
	HA_CONF_MODEL0,
	/** Model of node 1, only available in hybrid mode */
	HA_CONF_MODEL1,
	/** Number of LAN ports usable in HA */
	HA_CONF_LAN_NUM,

	// IF/IP/NETMASK pair max is MAX_IF_NUM
	/** For internal use */
	HA_CONF_HA_NETINFO_START,
	/** HA native interface */
	HA_CONF_HA_IF = HA_CONF_HA_NETINFO_START,
	/** HA IP address of native interface */
	HA_CONF_HA_IP,
	/** HA IP netmask of native interface */
	HA_CONF_HA_NETMASK,
	/** HA interface enable status of native interface */
	HA_CONF_HA_IF_ENABLED,
	/** HA bonding interface */
	HA_CONF_HA_BOND_IF,
	/** HA IP address of bonding interface */
	HA_CONF_HA_BOND_IP,
	/** HA IP netmask of bonding interface */
	HA_CONF_HA_BOND_NETMASK,
	/** HA interface enable status of bonding interface */
	HA_CONF_HA_BOND_IF_ENABLED,
	/** For internal use */
	HA_CONF_HA_NETINFO_END = HA_CONF_HA_BOND_IF_ENABLED,

	//mac array, size is MAX_IF_NUM
	/** HA MAC address */
	HA_CONF_HA_MAC,
	/** MAC address of node 0, in format xx:xx:xx:xx:xx:xx */
	HA_CONF_MAC0,
	/** MAC address of node 1, in format xx:xx:xx:xx:xx:xx */
	HA_CONF_MAC1,

	// bond special type (not in conf file): to get the relative local and remote
	/** For internal use */
	HA_CONF_VIRTUAL_START,
	/** Local IP address on DRBD interface */
	HA_CONF_DRBD_IP_LOCAL = HA_CONF_VIRTUAL_START,
	/** Remote IP address on DRBD interface */
	HA_CONF_DRBD_IP_REMOTE,
	/** Local hostname */
	HA_CONF_HOST_LOCAL,
	/** Remote hostname */
	HA_CONF_HOST_REMOTE,
	/** Local IP address on main interface */
	HA_CONF_IP_LOCAL,
	/** Remote IP address on main interface */
	HA_CONF_IP_REMOTE,
	/** Local MAC address */
	HA_CONF_MAC_LOCAL,
	/** Remote MAC address */
	HA_CONF_MAC_REMOTE,
	/** For internal use */
	HA_CONF_VIRTUAL_END = HA_CONF_MAC_REMOTE,

	/** For internal use */
	HA_CONF_TYPE_MAX,
} HA_CONF_TYPE;

/** Used in @ref SYNOHAGetConfByIF */
typedef enum {
	/** Interface */
	HA_NETWORK_IF,
	/** IP address */
	HA_NETWORK_IP,
	/** Netmask */
	HA_NETWORK_NETMASK,
	/** Enable status */
	HA_NETWORK_ENABLED,
	/** For internal use */
	HA_NETWORK_MAX,
} HA_CONF_NETWORK;

// hold the ha config
/** Used in @ref HAConfStructGet and @ref HAConfStructSet */
typedef struct {
	char szDrbdIF[SYNO_IFNAME_MAX];
	char szDrbdIFOrigin[SYNO_IFNAME_MAX];
	char szDrbdIP0[CB_SZ_IP_MAX];
	char szDrbdIP1[CB_SZ_IP_MAX];
	char szDrbdMask[CB_SZ_IP_MAX];
	char szDrbdBondModeOrigin[2];
	char szDrbdMtuOrigin[HA_MTU_STR_SIZE];

	char szHost0[MAXHOSTNAMELEN];
	char szHost1[MAXHOSTNAMELEN];
	char szIP0[CB_SZ_IP_MAX];
	char szIP1[CB_SZ_IP_MAX];

	char szCorosyncKey[COROSYNC_KEY_SIZE]; // unsigned int (ha.cc:HAActivate)
	char szHASN[MAX_SN_SIZE];
	char szHASNCustom[CUSTOM_SN_LENGH + 1];
	char szHAModel[MAX_HA_MODEL_SIZE];
	char szHAUnique[MAX_HA_UNIQUE_SIZE];

	char szHAHost[MAXHOSTNAMELEN];

	char szHAIFMain[SYNO_IFNAME_MAX]; // the first one ha interface, used by corosync, so should not be disabled
	char szGateway[CB_SZ_IP_MAX];

	char szHAIF[MAX_IF_NUM][SYNO_IFNAME_MAX];
	char szHAIP[MAX_IF_NUM][CB_SZ_IP_MAX];
	char szHAMask[MAX_IF_NUM][CB_SZ_IP_MAX];
	char szEnabled[MAX_IF_NUM][8]; // 'true' or 'false'
	char szHABondIF[MAX_IF_NUM][SYNO_IFNAME_MAX];
	char szHABondIP[MAX_IF_NUM][CB_SZ_IP_MAX];
	char szHABondMask[MAX_IF_NUM][CB_SZ_IP_MAX];
	char szBondEnabled[MAX_IF_NUM][8]; // 'true' or 'false'

	char szHAMac[MAX_IF_NUM][MAC_STR_SIZE];
	char szHAMac0[MAX_IF_NUM][MAC_STR_SIZE];
	char szHAMac1[MAX_IF_NUM][MAC_STR_SIZE];

	char szBeginTime[32];
	char szIsHybrid[8];
	char szModelGroup[16];
	char szModel0[64];
	char szModel1[64];
	char szLANNum[8];
} HA_CONF_STRUCT;

#define SZ_HA_CONF_DRBD_IF       "drbd_if"
#define SZ_HA_CONF_DRBD_IF_ORIGIN "drbd_if_origin"
#define SZ_HA_CONF_DRBD_IP0      "drbd_ip0"
#define SZ_HA_CONF_DRBD_IP1      "drbd_ip1"
#define SZ_HA_CONF_DRBD_NETMASK  "drbd_netmask"
#define SZ_HA_CONF_DRBD_BOND_MODE_ORIGIN "drbd_bond_mode_origin"
#define SZ_HA_CONF_DRBD_MTU_ORIGIN "drbd_mtu_origin"
#define SZ_HA_CONF_HOST0         "host0"
#define SZ_HA_CONF_HOST1         "host1"
#define SZ_HA_CONF_IP0           "ip0"
#define SZ_HA_CONF_IP1           "ip1"
#define SZ_HA_CONF_COROSYNC_KEY  "corosync_key"
#define SZ_HA_CONF_HA_HOST       "ha_hostname"
#define SZ_HA_CONF_HA_IF_MAIN    "ha_if_main"
#define SZ_HA_CONF_HA_GATEWAY    "ha_gateway"
#define SZ_HA_CONF_HA_IF         "ha_if"
#define SZ_HA_CONF_HA_IP         "ha_ip"
#define SZ_HA_CONF_HA_NETMASK    "ha_netmask"
#define SZ_HA_CONF_HA_IF_ENABLED "ha_if_enabled"
#define SZ_HA_CONF_HA_BOND_IF         "ha_bond_if"
#define SZ_HA_CONF_HA_BOND_IP         "ha_bond_ip"
#define SZ_HA_CONF_HA_BOND_NETMASK    "ha_bond_netmask"
#define SZ_HA_CONF_HA_BOND_IF_ENABLED "ha_bond_if_enabled"
#define SZ_HA_CONF_HA_SN         "ha_sn"
#define SZ_HA_CONF_HA_SN_CUSTOM  "ha_sn_custom"
#define SZ_HA_CONF_HA_MODEL      "ha_model"
#define SZ_HA_CONF_HA_UNIQUE     "ha_unique"
#define SZ_HA_CONF_HA_MAC        "ha_mac_"
#define SZ_HA_CONF_MAC0          "mac0_"
#define SZ_HA_CONF_MAC1          "mac1_"
#define SZ_HA_CONF_BEGIN_TIME    "begin_time"
#define SZ_HA_CONF_IS_HYBRID     "is_hybrid"
#define SZ_HA_CONF_MODEL_GROUP   "model_group"
#define SZ_HA_CONF_MODEL0        "model0"
#define SZ_HA_CONF_MODEL1        "model1"
#define SZ_HA_CONF_LAN_NUM       "lan_num"
#define SZ_HA_CONF_COROSYNC_IP1  "corosync_ip1"
#define SZ_HA_CONF_COROSYNC_IP2  "corosync_ip2"

#define SZK_HA_TMP_CONF_MAC           "mac_"
#define SZK_HA_TMP_CONF_HA_SN         SZ_HA_CONF_HA_SN
#define SZK_HA_TMP_CONF_HA_SN_CUSTOM  SZ_HA_CONF_HA_SN_CUSTOM

#define SZ_HA_CGI_MAC            "mac" // used for ha enable, passive will fill this and active will save this in ha.conf

/** Predefined IP address on DRBD interface of node 0 */
#define SZ_DRBD_CONF_IP_0     "169.254.1.1"
/** Predefined IP address on DRBD interface of node 1 */
#define SZ_DRBD_CONF_IP_1     "169.254.1.2"
/** Predefined IP netmask on DRBD interface */
#define SZ_DRBD_CONF_NETMASK  "255.255.255.252"
#define SZ_INT_DRBD_CONF_IP_0 "16907945"
#define SZ_INT_DRBD_CONF_IP_1 "33685161"

__BEGIN_DECLS

/**
 * Get HA configuration
 *
 * @param [in]  type  conf type
 * @param [in]  idx   index for ha if/ip/mask only
 * @param [out] szBuf buffer to store conf result
 * @param [in]  cbBuf size of szBuf
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetConf(HA_CONF_TYPE type, unsigned int idx, char *szBuf, int cbBuf);

/**
 * Set HA configuration
 *
 * @param [in] type  conf type
 * @param [in] idx   index for ha if/ip/mask only
 * @param [in] szBuf buffer to store conf result
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASetConf(HA_CONF_TYPE type, unsigned int idx, const char *szBuf);

/**
 * Get HA hostname
 *
 * @param [out] szHostname HA hostname
 * @param [in]  cbHostname size of @p szHostname
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetHAHostname(char *szHostname, unsigned int cbHostname);

/**
 * Get original hostname. HA aware.
 *
 * @param [out] szHostname original hostname
 * @param [in]  cbHostname size of szHostname size, MUST >= MAXHOSTNAMELEN
 * @param [in]  isLocal    TRUE: to get local original hostname, FALSE: to get remote original hostname
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetOriginalHostname(char *szHostname, unsigned int cbHostname, BOOL isLocal);

/**
 * Get HA configuration and determine to get eth* or bond* interface * data by the interface name (@p szIFName)
 *
 * @param [in]  network_type information type
 * @param [in]  szIFName     interface name, i.e., eth0, bond1, eth2.234, bond2.123
 * @param [out] szBuf        buffer to store result
 * @param [in]  cbBuf        size of @p szBuf
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @see HA_CONF_NETWORK
 */
int SYNOHAGetConfByIF(HA_CONF_NETWORK network_type, const char *szIFName, char *szBuf, int cbBuf);

/**
 * Set HA hostname
 *
 * @param [in] szHostname HA hostname
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASetHAHostname(const char *szHostname);

/**
 * Get HA main interface
 *
 * @param [out] szHAIFMain the HA main interface (eg. eth0, bond0)
 * @param [in]  cbHAIFMain size of @p szHAIFMain
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetIFMain(char *szHAIFMain, int cbHAIFMain);

/**
 * Get specific HA interface information
 *
 * @param [in]  szIF      interface name
 * @param [out] szHAIP    the HA IP on @p szIF
 * @param [in]  cbHAIP    size of @p szHAIP
 * @param [out] szNetmask the netmask on @p szIF
 * @param [in]  cbNetmask size of @p szNetmask
 * @param [out] blEnabled interface @p szIF is enabled or not
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetIFConfInfo(const char *szIF, char *szHAIP, int cbHAIP, char *szNetmask, int cbNetmask, BOOL* blEnabled);

/**
 * Get HA MAC address, for services that use mac as identifier
 *
 * @param [in]  idx   index
 * @param [out] szMac HA MAC addres in format: xx:xx:xx:xx:xx:xx
 * @param [in]  cbMac size of @p szMac
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetMac(unsigned int idx, char *szMac, unsigned int cbMac);

/**
 * Set HA interface information
 *
 * @param [in] szIF      interface name
 * @param [in] szHAIP    HA IP address on @p szIF
 * @param [in] szNetmask Netmask on @p szIF
 * @param [in] blEnabled szIF is enabled or not in ha.conf
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASetIFConfInfo(const char *szIF, const char *szHAIP, const char *szNetmask, BOOL blEnabled);

/**
 * Get local host direction (left or right)
 *
 * @retval 1 host is right node
 * @retval 0 host is left node
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetHostDirection();

__END_DECLS

#ifdef MY_ABC_HERE

int HAConfStructGet(HA_CONF_STRUCT *structConf);
int HAConfStructSet(const HA_CONF_STRUCT *structConf);
int SYNOHAResetConf();
int SYNOHACleanConfRemote();
HA_CONF_TYPE SYNOHANodeTypeToConfType(NODE_TYPE nodeType);
int HAGetHeartbeatIF(char *szHeartbeatIF, int cbHeartbeatIF);

#endif /* MY_ABC_HERE */

#endif
