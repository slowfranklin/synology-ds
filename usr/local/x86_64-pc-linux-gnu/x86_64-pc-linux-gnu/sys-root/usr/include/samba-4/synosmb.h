#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef _SYNO_DOMAIN_H
#define _SYNO_DOMAIN_H

#include <stdint.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include <synosdk/plugin.h>
#include <synosdk/wins.h>

__BEGIN_DECLS;

#define SZF_WINBINDD_IDMAP_TDB "/var/lib/samba/winbindd_idmap.tdb"

#define SZV_TYPE_USER  0
#define SZV_TYPE_GROUP 1
#define SZV_TYPE_OU    2
#define MAX_UGID_LENGTH 11	//strlen("4294967295") + 1

//domain list define
#define SZF_TRUST_DOMAIN_LIST_USER	"/usr/syno/etc/private/domain_list.user"
#define SZF_TRUST_DOMAIN_LIST_GROUP	"/usr/syno/etc/private/domain_list.group"

//domain basic db
#define SZ_DOMAIN_DB_SOCK_PATH  "/run/samba/dom_sock"
#define BASICDB_FLAG_ADD   1
#define BASICDB_FLAG_DONE  2
typedef struct {
	int32_t flag;
	char szRid[MAX_UGID_LENGTH];
	char szDomain[MAX_WORKGROUP_LEN];
	char szName[256];
	char szDN[1024];
} BASICDB_ENTRY;

//domain full db fields
#define SZ_DOM_FIELD_NAME       "Name"
#define SZ_DOM_FIELD_DN         "distinguishedName"
#define SZ_DOM_FIELD_RID        "rid"
#define SZ_DOM_FIELD_FULLNAME   "FullName"
#define SZ_DOM_FIELD_EMAIL      "Email"
#define SZ_DOM_FIELD_LOCKOUT    "LockoutTime"
#define SZ_DOM_FIELD_EXPIRE     "AccountExpires"
#define SZ_DOM_FIELD_DESC       "Description"
#define SZ_DOM_FIELD_OFFICE     "Office"
#define SZ_DOM_FIELD_TEL        "Telephone"
#define SZ_DOM_FIELD_TITLE      "Title"
#define SZ_DOM_FIELD_DEPARTMENT "Department"
#define SZ_DOM_FIELD_COMPANY    "Company"
#define SZ_DOM_FIELD_MANAGEDBY  "ManagedBy"
#define SZ_DOM_FIELD_PWDLAST    "pwdLastSet"
#define SZ_DOM_FIELD_PWDNEXPIRE "PwdNeverExpire"
#define SZ_DOM_FIELD_UAC        "userAccountControl"
#define SZ_DOM_FIELD_ENABLE     "AccountEnable"
#define SZ_DOM_FIELD_SID        "SID"
#define SZ_DOM_FIELD_UPN        "userPrincipalName"
#define SZ_DOM_FIELD_DOMAIN     "domain"
#define SZ_DOM_FIELD_SID        "SID"
#define SZ_DOM_FIELD_UPDATETIME	"UpdateTime"

//For Idmap
#define SYNO_NUM_BIT_FOR_RID 21
#define SYNO_NUM_BIT_FOR_DOMAIN_ID (32 - SYNO_NUM_BIT_FOR_RID)
#define SYNO_DOMAIN_RID_NUM (1 << SYNO_NUM_BIT_FOR_RID) // 2^21 = 2097152
#define SYNO_DOMAIN_RID_MIN 0
#define SYNO_DOMAIN_RID_MAX SYNO_DOMAIN_RID_NUM - 1
#define SYNO_DOMAIN_ID_NUM ((1 << SYNO_NUM_BIT_FOR_DOMAIN_ID) -1) // 2^11 - 1 = 2047
#define SYNO_DOMAIN_ID_MAX SYNO_DOMAIN_ID_NUM
#define SYNO_DOMAIN_ID_MIN 1
#define SYNO_BASE_MAGIC 900919
#define SYNO_DOM_IDX_KEY_PREFIX "MY_ABC_HERE DOMIDX"
#define SYNO_BULTIN_NUM_BIT_FOR_RID 8
#define SYNO_BUILTIN_RID_NUM (1 << SYNO_BULTIN_NUM_BIT_FOR_RID) // 2^8 = 256

//For net_syno to build fulldb
struct syno_dom_info {
	char domain[64];
	char realm[256];
	char addr[INET6_ADDRSTRLEN];
	char DomSid[256];
	int64_t lockoutDuration;
	uint32_t updatetime;
	int64_t maxPwdAge;
};

//extern declare at synosmb_int.c
extern const char *arDominfoAttrs[];
extern const char *arUGAttrs[];
extern const char *arUGFields[];

#define MAX_SYNO_USER_ATTRS	16
#define MAX_SYNO_USER_FIELDS	(MAX_SYNO_USER_ATTRS+2)
extern const char *arUserFullAttrs[];
extern const char *arUserFullFields[];

#define SZ_USER_SQL_ATTRS   "Name VARCHAR(128),"\
                            "distinguishedName VARCHAR(256),"\
                            "rid INTEGER PRIMARY KEY,"\
                            "userPrincipalName VARCHAR(128),"\
                            "FullName VARCHAR(64),"\
                            "Email VARCHAR(256),"\
                            "LockoutTime INTEGER,"\
                            "AccountExpires INTEGER,"\
                            "Description VARCHAR(256),"\
                            "Office VARCHAR(64),"\
                            "Telephone VARCHAR(16),"\
                            "Title VARCHAR(16),"\
                            "Department VARCHAR(64),"\
                            "Company VARCHAR(64),"\
                            "pwdLastSet INTEGER,"\
                            "UserAccountControl INTEGER,"\
                            "AccountEnable BOOLEAN,"\
                            "PwdNeverExpire BOOLEAN,"\
                            "UpdateTime INTEGER"

#define SZ_USER_INDEX_ATTRS "Name,"\
                            "distinguishedName,"\
                            "rid,"\
                            "FullName,"\
                            "Email,"\
                            "Description,"\
                            "Office,"\
                            "Telephone,"\
                            "Title,"\
                            "Department,"\
                            "Company,"\
                            "pwdLastSet,"\
                            "UserAccountControl,"\
                            "AccountEnable,"\
                            "PwdNeverExpire,"\
                            "UpdateTime"

#define MAX_SYNO_GROUP_ATTRS	7
#define MAX_SYNO_GROUP_FIELDS	MAX_SYNO_GROUP_ATTRS
extern const char *arGroupFullAttrs[];
extern const char *arGroupFullFields[];
#define SZ_GROUP_SQL_ATTRS      "Name VARCHAR(128),"\
                                "distinguishedName VARCHAR(256),"\
                                "rid INTEGER PRIMARY KEY,"\
                                "FullName VARCHAR(64),"\
                                "Email VARCHAR(256),"\
                                "Description VARCHAR(256),"\
                                "ManagedBy VARCHAR(64),"\
                                "UpdateTime INTEGER"

#define SZ_GROUP_INDEX_ATTRS    "Name,"\
                                "distinguishedName,"\
                                "rid,"\
                                "FullName,"\
                                "Email,"\
                                "Description,"\
                                "ManagedBy,"\
                                "UpdateTime"

#define SZ_BASICDB_INSERT_CMD   "INSERT INTO %Q ('rid', 'Name', 'NameUpper', 'distinguishedName') "\
                                "SELECT %q,%Q,%Q,%Q "\
                                "WHERE NOT EXISTS (SELECT 1 FROM %Q WHERE rid=%q);"

typedef struct _tag_DOMAINPLUGIN DOMAIN_PLUGIN;

/* domain_plugin.c */
int SYNOSMBDomainPluginInfoSetDomain(DOMAIN_PLUGIN *pDomPlugin, const char *szDomain);
int SYNOSMBDomainPluginSetHash(DOMAIN_PLUGIN *pDomPlugin, PSLIBSZHASH pHash);
int SYNOSMBInitDomainPluginInfo(DOMAIN_PLUGIN *pDomPlugin);
void SYNOSMBReleaseDomainPluginInfo(DOMAIN_PLUGIN *pDomPlugin);
int SYNOSMBReadDbRidName(const char *szDomain, const char *szDBPath, int (*SQLite_callback)(void*,int,char**,char**), void *data);
int SYNOSMBCheckDbChange(DOMAIN_PLUGIN *pPlugin, const char *szDomain, const char *szDBPath);
void SYNOSMBDomainPluginDomainMemberChange(DOMAIN_PLUGIN *pDomPlugin, int iType);
int SYNOSMBDomainPluginSetChange(sqlite3 *pDb, DOMAIN_PLUGIN *pDomPlugin, uint32_t rid, const char *szNewName, int changeFlag);

/* domain_build_db.c */
void SYNOSMBTuningSQLite(sqlite3 *db);
int SYNOSMBBuildBasicDBInit(int iType, PSLIBSZLIST pListDomain);
int SYNOSMBBuildBasicDBDone(int iType, PSLIBSZLIST pListDomain);
int SYNOSMBBuildBasicDBSocketCreate(int iType, BOOL blIsServer);
int SYNOSMBBuildBasicDBSocketSend(int sock_fd, BASICDB_ENTRY *pEntry);
int SYNOSMBBuildBasicDBSocketRecv(int iType, int sock_fd, int *pids, int iNumDomain);

__END_DECLS;
#endif  /* _SYNO_DOMAIN_H */
