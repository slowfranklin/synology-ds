// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNO_NFS_H__
#define __SYNO_NFS_H__

#include <synocore/synotype.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synosdk/share.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include <synosdk/servicecfg.h>
#include <synocore/conf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

__BEGIN_DECLS;

#define SZF_NFS_EXPORTS "/etc/exports"
#define SZF_NFS_EXPORTS_MAP "/etc/exports_map"
#define SZF_NFS_EXPORTS_SYNO "/etc/exports_syno"
#define SZF_NFS_EXPORTFS     "/usr/sbin/exportfs"

#define MAX_NFS_TARGETPATH_LENGTH SYNO_SHARENAME_UTF8_MAX + VOL_PREFIX_MAXLEN // "/volumeX/" and '\0'
#define MAX_NFS_HOST_LENGTH 1024 //equal to 'NFSCLNT_IDMAX' like nfs-utils-1.1.0

#define SZ_KLIST_BINARY "/usr/bin/klist"

#define SZ_KERBEROS "krb5"
#define SZ_KERBEROS_INTEGRITY "krb5i"
#define SZ_KERBEROS_PRIVACY "krb5p"

#define SZ_NFS_SYS "sys"
#define SZF_NFS_IDMAP_CONF "/etc/idmapd.conf"
#define SZF_NFS_DEFAULT_DOMAIN "localdomain"
#define SZK_IDMAP_GENERAL "General"
#define SZK_IDMAP_STATIC "Static"
#define SZK_IDMAP_Mapping "Mapping"
#define SZK_IDMAP_TRANSLATION "Translation"
#define SZK_IDMAP_DOMAIN "Domain"
#define SZK_IDMAP_NOBODYUSER "Nobody-User"
#define SZK_IDMAP_NOBODYGROUP "Nobody-Group"
#define SZK_IDMAP_METHOD "Method"
#define SZK_IDMAP_GSS_METHOD "GSS-Methods"
#define SZK_NFS_KERBEROS_PRINCIPAL "kerberos_principal"
#define SZK_KRB5_LIBDEF "libdefaults"
#define SZK_KRB5_DEFREALM "default_realm"

#define SZK_UDP_PREFER_READ_SIZE "udp_read_size"
#define SZK_UDP_PREFER_WRITE_SIZE "udp_write_size"

#define DEFAULT_NFS_UDP_SIZE 8192
#define MAX_NFS_UDP_SIZE 32768
#define MIN_NFS_UDP_SIZE 4096
#define MAX_NFS_ENC_TYPE_LEN 64
#define MAX_UDP_SIZE_CHARACTER_LEN 5
#define MAX_KRB5_PRINCIPAL_LEN 256
#define MAX_KRB5_REALM_LEN 256
#define MAX_KRB5_PRINCIPAL_REALM_LEN MAX_KRB5_PRINCIPAL_LEN+MAX_KRB5_REALM_LEN+2

#define SZK_SUPPORT_NFS "supportNFS"
#define SZK_SUPPORT_NFS_KERBEROS "supportNFSKerberos"

typedef enum{
  NFS_ACCESS_RO,
  NFS_ACCESS_RW
}NFS_ACCESS_RIGHT;

typedef enum{
  NFS_SQUASH_ROOT,
  NFS_SQUASH_ADMIN,
  NFS_SQUASH_GUEST,
  NFS_ALL_SQUASH_ADMIN
}NFS_ROOT_SQUASH;

typedef enum{
	NFS_WRITE_ASYNC,
	NFS_WRITE_SYNC,
}NFS_WRITE_TYPE;

typedef enum{
	NFS_DENY_INSECURE_PORT,
	NFS_ALLOW_INSECURE_PORT,
}NFS_SECURITY;

typedef enum{
	NFS_DENY_CROSSMNT,
	NFS_ALLOW_CROSSMNT,
}NFS_CROSSMNT;

typedef struct _tag_nfs_option_{
    char szHost[MAX_NFS_HOST_LENGTH];
    NFS_ACCESS_RIGHT right;
    NFS_ROOT_SQUASH root_squash;
	NFS_WRITE_TYPE write_sync;
    struct _tag_nfs_option_ *pNext;
}NFS_OPTION;

typedef struct _tag_nfs_option_extend_{
	char szHost[MAX_NFS_HOST_LENGTH];
	NFS_ACCESS_RIGHT right;
	NFS_ROOT_SQUASH root_squash;
	NFS_WRITE_TYPE write_sync;
	NFS_SECURITY allow_port;
	NFS_CROSSMNT allow_crossmnt;
	BOOL blKrb5;
	BOOL blKrb5i;
	BOOL blKrb5p;
	BOOL blAuthSYS;
	struct _tag_nfs_option_extend_ *pNext;
}NFS_OPTION_EXTEND;

typedef struct _tag_nfs_rule_{
    char szTargetPath[MAX_NFS_TARGETPATH_LENGTH];
    NFS_OPTION *opts;
}NFS_RULE;

typedef struct _tag_nfs_rule_extend_{
	char szTargetPath[MAX_NFS_TARGETPATH_LENGTH];
	NFS_OPTION_EXTEND *opts;
}NFS_RULE_EXTEND;

typedef struct _tag_nfs_rule_map_option_ {
	const char * szShareName;
	const char * szSharePath;
	const char * szGUID; //device name for USB/SATA device
}NFS_MAP_OPTION;

typedef struct _tag_nfs_id_map_{
	char *szDomain;
	char *szNobodyUser;
	char *szNobodyGroup;
	char *szMethod;
	char *szGSSMethod;
	PSLIBSZHASH pStaticMap;
}NFS_ID_MAP, *PNFS_ID_MAP;

typedef struct _tag_nfs_syno_conf_{
	int udpReadSize;
	int udpWriteSize;
	char szPrincipalName[MAX_KRB5_PRINCIPAL_REALM_LEN];
	BOOL blNFSv4Enable;
	BOOL blUNIXPriEnable;
	int statdPort;
	int nlmPort;
	BOOL blCustomPort;
}NFS_SYNO_CONF;

typedef struct _tag_nfs_krbkey_info_{
	int version;
	char szPrincipalName[MAX_KRB5_PRINCIPAL_REALM_LEN];
	char szEncType[MAX_NFS_ENC_TYPE_LEN];
	struct _tag_nfs_krbkey_info_ *pNext;
}NFS_KRB5_KEY_INFO;

typedef void * (*SETEXPORTENT) (const char *fname, char *type);
typedef void * (*ENDEXPORTENT) (void);
typedef void * (*GETEXPORTENT) (int fromkernel,int fromexports);

#ifndef NO_PROTO
#include <availability.h>
#include "synonfs/synonfs_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_NFS_H__
