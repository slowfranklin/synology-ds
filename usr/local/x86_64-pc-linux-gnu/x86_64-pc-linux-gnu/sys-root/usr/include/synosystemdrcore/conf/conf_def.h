/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_DEF_H__
#define __SYNOSYSDRCORE_CONF_DEF_H__

#include <string>

#include <synosystemdrcore/systemdrcore.h>
#define SZD_SYSDR_ETC                 "/usr/syno/etc/synosystemdr"
#define SZD_SYSDR_TMP                 "/tmp/synosystemdr"

namespace SynoSysDRCore {
namespace Conf {

const std::string SZK_SDR_CUSTOM_SN = "SystemDRCustomSN";
const std::string SZK_SDR_SN        = "SystemDRSN";
const std::string SZK_SDR_MAC       = "SystemDRMac";
const std::string SZK_NODE1         = "node1";
const std::string SZK_NODE2         = "node2";
const std::string SZK_NODEID        = "nodeID";
const std::string SZK_CREDID        = "credID";
const std::string SZK_IP            = "IP";
const std::string SZK_SN            = "SN";
const std::string SZK_NETWORK       = "network";
const std::string SZK_SDR_MODE      = "mode";
const std::string SZK_SETTING       = "setting";
const std::string SZK_SCHED         = "sched";
const std::string SZK_SCHED_ID      = "sched_id";
const std::string SZK_SELECTED_VOLUME = "SelectedVolume";
const std::string SZK_IS_APPAWARED  = "is_appawared";
const std::string SZK_IS_ENCRYPT    = "is_encrypt";
const std::string SZK_BIND_TARGET   = "bind_target";
const std::string SZK_ACCOUNT       = "account";
const std::string SZK_CREATE_TIME   = "create_time";

const std::string SZK_ID = "id";
const std::string SZK_VDISK_ID = "vdisk_id";
const std::string SZK_SELECTED_STATUS = "selected_status";

const std::string SZK_ROLE          = "Role";
const std::string SZK_HEALTHY       = "Healthy";
const std::string SZK_LOCAL         = "Local";
const std::string SZK_REMOTE        = "Remote";
const int MAX_MAC_STR_SIZE          = 18;
const int MAX_SUPPORT_VOLUME        = 4;

typedef enum {
	SYSDR_NODE_UNKNOWN = 0,
	SYSDR_NODE1        = 0x1,
	SYSDR_NODE2        = 0x2,
	SYSDR_SDR_CLUSTER  = 0x4,

	SYSDR_NODE_ALL     = 0xF,
} SYSDR_NODE;

enum SDR_BIND_MODE {
	SDR_BIND_MODE_UNKNOWN    = 0x00,
	SDR_BIND_MODE_VDSM       = 0x01,
	SDR_BIND_MODE_PDSM       = 0x02,
	SDR_BIND_MODE_HYPERVISOR = 0x04,
	SDR_BIND_MODE_CLOUD      = 0x08,

	SDR_BIND_MODE_VDSM_WITH_HYPERVISOR = SDR_BIND_MODE_HYPERVISOR | SDR_BIND_MODE_VDSM,
	SDR_BIND_MODE_VDSM_WITH_CLOUD = SDR_BIND_MODE_CLOUD | SDR_BIND_MODE_VDSM,
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_DEF_H__
