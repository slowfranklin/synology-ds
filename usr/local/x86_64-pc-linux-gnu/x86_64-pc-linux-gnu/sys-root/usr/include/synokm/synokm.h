// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_KM_H__
#define __SYNO_KM_H__

#include <linux/syno.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

#include <synocore/list.h>
#include <synosdk/service.h>

__BEGIN_DECLS;

#define SZD_MODULE_BASE "/lib/modules"
#define SZF_IPTABLES_SERV_MOD_MAP "/tmp/iptables_serv_mod_map"
#define SZF_IPTABLES_SERV_MOD_MAP_LOCK "/tmp/iptables_serv_mod_map.lock"

//#36595, Set /proc/sys/kernel/syno_netfilter_status for kernel short cut usage
#define SZF_IPTABLES_NETFILTER_SHORTCUT "/proc/sys/kernel/syno_netfilter_status"

#ifndef NO_PROTO
#include <availability.h>
#include "synokm/synokm_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_KM_H__
