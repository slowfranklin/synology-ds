// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_WINS_H__
#define __SYNO_WINS_H__

#include <sqlite3.h>
#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/hash.h>
#include <limits.h>

__BEGIN_DECLS;

/**
 * @addtogroup WINS
 *
 * @brief The structure and operation of Wins.
 *
 * @{
 */

#define SZF_WINSTATE				"/var/log/winlock.state"
#define SZF_DOMAIN_JOIN_INFO		"/usr/syno/etc/private/last_join_info"
#define SZF_DOMAIN_DNS_QUERY		"/usr/syno/etc/private/dns_query"
#define SZF_DOMAIN_USER "/usr/syno/etc/private/domain_user"
#define SZF_DOMAIN_USER_BAK "/usr/syno/etc/private/domain_user.bak"
#define SZF_DOMAIN_USER_TMP "/usr/syno/etc/private/domain_user.tmp"
#define SZF_DOMAIN_GRP "/usr/syno/etc/private/domain_group"
#define SZF_DOMAIN_GRP_BAK "/usr/syno/etc/private/domain_group.bak"
#define SZF_DOMAIN_GRP_TMP "/usr/syno/etc/private/domain_group.tmp"
#define SZF_DOMAIN_GRP_MEM "/usr/syno/etc/private/domain_group_member"
#define SZF_DOMAIN_GRP_MEM_BAK "/usr/syno/etc/private/domain_group_member.bak"
#define SZF_TRUST_DOMAIN_LIST "/usr/syno/etc/private/domain_list"
#define SZF_WINBIND_DOMAIN_LIST "/run/samba/winbind_domain_list"
#define SZF_TRUST_DOMAIN_INFO "/usr/syno/etc/private/trust_domain_info"
#define SZK_TRUST_FQDN "FQDN"
#define SZF_DOMAIN_OU_LIST "/usr/syno/etc/private/domain_ou"
#define SZK_DOMAIN_OU_DN "distinguishedName"
#define SZK_DOMAIN_JOINED	"domainjoined"
#define SZV_WIN_USER_NAME_UTF8_MAX	384
#define SZV_WIN_USER_FULLNAME_UTF8_MAX	1536
#define SZV_WIN_GROUP_NAME_UTF8_MAX	384
#define SZV_TRUST_DOMAIN_MAX	2048

#define SZF_DC_OFFLINE_FLAG "/usr/syno/etc/private/.cannot_connect_to_dc"

#define SZK_WINSTATE_FUNC "winstate_func"
#define SZK_WINSTATE_ERROR "winstate_error"
#define SZF_ADSINFO	"/usr/syno/etc/private/adsinfo"
#define SZF_ERROR_SYSTEM "Error System."
#define SZF_INVALID_NAME "Invalid workgroup name."
#define SZF_MISS_DC	"Neither LDAP server nor PDC can be found."
#define SZF_PORT_UNREACHABLE "445/tcp is unreachable for DC. Please check the network and firewall settings."
#define SZF_ERROR_ACC_RPC "The username or password was not correct."
#define SZF_ERROR_ACC_ADS	"Preauthentication failed while getting initial credential"
#define SZF_NO_SUCH_ACC "Client not found in Kerberos database while getting initial credentials"
#define SZF_ACC_REVOKED_ADS "Clients credentials have been revoked while getting initial credentials"
#define SZF_ACC_REVOKED_RPC "The account was disabled"
#define SZF_ERROR_PRIVILEGE_RPC "Unable to join domain"
#define SZF_ERROR_PRIVILEGE_ADS "ads_join_realm: Insufficient access"
#define SZF_ERROR_DOM_NAME "Wbinfo fail. It might be domain name error."
#define SZF_NEED_CHANGE_PASSWD "Password has expired while getting initial credentials"
#define SZF_ERROR_MISC_RPC	"Could not connect to server"
#define SZF_ERROR_WG	"Can't get domain workgroup."
#define SZF_BAD_KDC	"Invalid KDC ip."
#define SZF_WORKGROUP "/usr/syno/etc/private/workgroup"
#define SZF_SMB_DIAGNOSE_PATH "/usr/syno/etc/private/diagnose"
#define SZF_SMB_DIAGNOSE_TARGET "/usr/syno/etc/private/diagnose/target"
#define SZF_SMB_DIAGNOSE_PS "/usr/syno/etc/private/diagnose/ps"
#define SZF_SMB_DIAGNOSE_IFCONFIG "/usr/syno/etc/private/diagnose/ifconfig"
#define SZF_SMB_DIAGNOSE_LOCAL_NMBLOOKUP "/usr/syno/etc/private/diagnose/local_nmblookup"
#define SZF_SMB_DIAGNOSE_LOCAL_SMBCONN "/usr/syno/etc/private/diagnose/local_smbconn"
#define SZF_SMB_DIAGNOSE_DOMAIN_NSLOOKUP "/usr/syno/etc/private/diagnose/domain_nslookup"
#define SZF_SMB_DIAGNOSE_DOMAIN_NMBLOOKUP "/usr/syno/etc/private/diagnose/domain_nmblookup"
#define SZF_SMB_DIAGNOSE_TEST_JOIN "/usr/syno/etc/private/diagnose/testjoin"
#define SZF_SMB_DIAGNOSE_DOMAIN_PING "/usr/syno/etc/private/diagnose/domain_ping"
#define SZF_SMB_DIAGNOSE_DATE "/usr/syno/etc/private/diagnose/date"
#define SZF_SMB_DIAGNOSE_LDAP "/usr/syno/etc/private/diagnose/lookup_ldap"
#define SZF_SMB_DIAGNOSE_KDC "/usr/syno/etc/private/diagnose/lookup_kdc"
#define SZF_SMB_DIAGNOSE_DC "/usr/syno/etc/private/diagnose/lookup_dc"
#define SZF_SMB_DIAGNOSE_PDC "/usr/syno/etc/private/diagnose/lookup_pdc"
#define SZF_SMB_DIAGNOSE_DOMAIN_MASTER "/usr/syno/etc/private/diagnose/lookup_domain_master"
#define SZF_SMB_DIAGNOSE_LOCAL_MASTER "/usr/syno/etc/private/diagnose/lookup_local_master"
#define SZF_SMB_DIAGNOSE_KLIST "/usr/syno/etc/private/diagnose/klist"
#define SZF_DOMAIN_USER_DB "/usr/syno/etc/private/.db.domain_user"
#define SZF_DOMAIN_GROUP_DB "/usr/syno/etc/private/.db.domain_group"

#define SYNO_OFFLINE_RESUME_TIME 120
#define MAX_WORKGROUP_LEN	128
#define MAX_FQDN_LEN		256
#define SYNO_DOMAIN_USERNAME_MAX	1024
#define SYNO_DOMAIN_PASS_MAX		1024
#define SYNO_MAX_SID_LEN		1024
#define SYNO_BUILD_DOMAIN_USER_DB_RUN	"/tmp/domain_user.pid"
#define SYNO_BUILD_DOMAIN_GROUP_DB_RUN	"/tmp/domain_group.pid"
#define SYNO_BUILD_DOMAIN_LIST_RUN	"/tmp/domain_list.pid"
#define SYNO_DOMAIN_DB_INITIAL_FLAG	"/tmp/domain_updating"

#define SZK_DOMAIN_INFO_ATTR_ADS_MTIME "ads:mtime"
#define SZK_DOMAIN_INFO_ATTR_RPC_MTIME "rpc:mtime"

#define DOMAIN_IDMAP_UID_RANGE SYNO_STRING(DOMAIN_UID_MIN) "-" SYNO_STRING(DOMAIN_UID_MAX)
#define DOMAIN_IDMAP_GID_RANGE SYNO_STRING(DOMAIN_GID_MIN) "-" SYNO_STRING(DOMAIN_GID_MAX)
#define SZ_SID_PREFIX	"S-1-5-21-0-0-0-"

#define SZ_WIN_SERVICE_NAME "samba"
#define SZ_NMB_SERVICE_NAME "nmbd"
#define SZ_WINBIND_SERVICE_NAME "winbindd"

#define SZF_WBINFO	"/usr/bin/wbinfo"
#define SZF_NET		"/usr/bin/net"
#define SZK_MAX_PROTOCOL    "max protocol"
#define SZK_MIN_PROTOCOL    "min protocol"
#define SZV_NT1             "NT1"
#define SZV_SMB2_02			"SMB2"
#define SZV_SMB2_10			"SMB2_10"
#define SZV_SMB3			"SMB3"

/**
 * NT time start from 1601/1/1
 * date time start from 1970/1/1
 */
#define SZV_NT_LINUX_TIME_OFFSET 11644473600

/**
 * The string that represents the key of the time that winbindd
 * expire the domain data. To rebuild domain data db.
 *
 * @see SYNOWinsBdbIsNeedToRebuild()
 */
#define SZK_DOMAIN_EXPIRE_TIME	SYNO_BDB_SZK_PREFIX"SYNO@EXPIRE@TIME"

/**
 * The expire time of winbindd cache. (300sec = 5min)
 * If domain expired time is greater than it, the domain db
 * should rebuild.
 *
 * @see SYNOWinsBdbIsNeedToRebuild()
 */
#define WINBINDD_CACHE_TIME 300
typedef struct {
	BOOL blDomain;
	BOOL blSkipServiceAction;
	char *szDomain;
	char *szUser;
	char *szPasswd;
	char szDCIPListUser[128];
	char szDCIPList[8196];
	char szDomainFQDN[MAX_FQDN_LEN];
	char szDomainNetBIOS[MAX_WORKGROUP_LEN];
	char szDomainRWDC[8196];
	char szDomainOU[8196];
} SYNOWIN2, *PSYNOWIN2;

typedef enum __tag_SYNO_ADVANCE_OPT_STATUS_ {
	UPDATE_SAMBA_ADVOPT=1,
	UPDATE_DOMAIN_ADVOPT,
	UPDATE_ALL
} ADVANCE_OPT_STATUS;

typedef struct {
	int blSymlink;
	int blWidelink;
	int blMSDfs;
	int cLog;
	int blEnableVetofile;
	char szVetofile[BUFSIZ];
	/**
	 * - 0: disable
	 * - 1: auto
	 * - 2: force
	 */
	int blServerSigning;
	int blDirSort;
	int blRPCEnum;
	int blZeroVC;
	int blAdvDomainOptions;
	int cNestedGroup;
	char szRegisterNIC[BUFSIZ];
	int blUnixMask;
	int blDisableDomainAdmins;
	int blDisableShadowCopy;
	char szEncryptTranspose[BUFSIZ];
	int blDisableStrictAllocate;
	int blEnableSpotlight;
	int blEnableWildcardSearch;
	int blEnableDurableHandles;
	int blEnableSmb2Leases;
	int blEnableBtrfsClone;
	int blEnableCatia;
} SYNO_SAMBA_ADVCONF;

/** IP lists with SEP=',' */
#define MAX_IPS_LEN (1024*16)
typedef struct {
	BOOL blClustering;
	char szIdmapBackend[32];
	char szNetbiosName[MAX_WORKGROUP_LEN];
	char szClusteringAddress[MAX_IPS_LEN];
} SYNO_SAMBA_CTDB_CONF;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/wins_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_WINS_H__
