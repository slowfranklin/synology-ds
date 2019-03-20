/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNOFIREWALL_C_H__
#define __SYNOFIREWALL_C_H__

#include <synocore/synoglobal.h>
#include <synocore/string.h>

#define SZ_SEC_RULE  "RULE"
#define SZ_SEC_ADAPTER  "ADAPTER"
#define SZK_ADAPTER "adapter"
#define SZ_SEC_SETTINGS  "SETTINGS"

#define SZ_ALL "ALL"
#define SZV_SELF "SELF"
#define SZ_SELF SZV_SELF":"
#define SZV_SYS "SYS"
#define SZ_SYS SZV_SYS":"
#define SZV_RESERVED "RESERVED"
#define SZ_RESERVED SZV_RESERVED":"
#define SZ_ICMP_PATTERN SZ_SELF":"
#define SZ_SOURCE "src"
#define SZ_DESTINATION "dest"
#define SZ_DESTPORTS "--dport"
#define SZ_SRCPORTS "--sport"
#define FWOPTSIZE 32
#define SZV_SRC_ALL "all"
#define SZV_TCP "tcp"
#define SZV_UDP "udp"
#define SZV_ICMP "icmp"
#define SZV_ALLOW  "allow"
#define SZV_DROP  "drop"
#define SZV_NONE  "none"
#define SZV_YES "yes"

#define MAX_PORTS_IN_A_RULE 15	//iptables' rule limit, it can not apply more than 15 ports each rule
#define MAX_FIREWALL_RULES 100
#define MAX_SECTION_LENGTH 512
#define VALUE_BUFSIZ 256

#define SZK_POLICY  "policy"
#define SZK_ID  "id"
#define SZK_RULES "rules"
#define SZK_PORT_ID "port_id"
#define SZK_STATUS "status"
#define SZK_SERV_POLICY "service_policy"
#define SZK_TOTAL "total"
#define SZK_STEP "step"
#define SZK_PORTS  "ports"
#define SZK_PORT_TYPE "port_type"
#define SZK_PORT_NUM  "port_num"
#define SZK_PORT_DIRECTION  "port_direction"
#define SZK_SAVE_DONE "save_done"
#define SZV_CONF "conf"
#define SZV_RULES "rules"
#define SZV_SAVE_STATUS_UNKNOWN "unknown"
#define SZV_SERV_ID_STATUS_UNKNOWN "unknown"
#define SZV_SERV_ID_STATUS_ALLOW "allow"
#define SZV_SERV_ID_STATUS_DENY "deny"
#define SZV_SERV_ID_STATUS_PARTIAL "partial"
#define SZK_ENABLED  "enabled"
#define SZK_SOURCE  "source"
#define SZK_PROTOCOL  "protocol"
#define SZK_ALLOW  "allow"
#define SZK_MINRATE  "minrate"
#define SZK_MAXRATE  "maxrate"
#define SZK_SYNO_INFO "/etc/synoinfo.conf"
#define SZK_PORT_CHECK "portcheck"

#define SZK_IP_DIRECTION  "ip_direction"
#define SZ_INTERFACE_GLOBAL	"global"

// DOS script
#define SZ_SECURITY_SCRIPT "/etc/fw_security/sysconf/iptables_security.sh"

#ifdef __cplusplus
extern "C" {
#endif

int SYNOFwRuleHup(void);
void SYNOFwReset(void);
int SYNOFwPortsCheckAllowByAdapter(const char *szAdapter, const char *szServ);
int SLIBFwRuleReserveServInsert(const char *szServ, BOOL blAllow, BOOL blReload);

//SYNOFwReset (libsynoserviceutil)
//SLIBFwRuleReserveServInsert (dsm-PortEnable)

// libsynoserviceconf used
int SLIBFwServRemoveRec(char *szService);
int SLIBFwChangeAdatper(const char *szOriAdapterName, const char *szAdapterName, BOOL blFwReload);

int SYNOIptablesCodeModeLoad(const char *servName);
int SYNOIptablesCoreModUnload(const char *servName);
int SYNOIptablesNATModLoad(const char *servName);
int SYNOIptablesNATModUnload(const char *servName);

#ifdef __cplusplus
}
#endif

#endif /* __SYNOFIREWALL_C_H__ */
