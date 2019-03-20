// Copyright (c) 2000-2013 Synology Inc. All rights reserved.

#ifndef __SYNO_SMBCONF_H__
#define __SYNO_SMBCONF_H__
#include <synocore/synotype.h>
#include <synocore/hash.h>

__BEGIN_DECLS;

/**
 * @addtogroup SMBCONF
 *
 * @brief Some macros of keys in smb.conf.
 *
 * @{
 */

#define SZF_SYNOSMB_OPTIONS		"/etc/samba/smbinfo.conf"
#define SZK_SYNOSMB_SECTION		"global"

#define SZK_FOLLOW_SYMLINKS		"follow symlinks"
#define SZK_WIDE_LINKS			"wide links"
#define SZK_VETO_FILES			"veto files"
#define SZK_ENABLE_VETO_FILES	"enable veto files"
#define SZK_MSDFS_ROOT			"msdfs root"
#define SZK_LOG_LEVEL			"log level"
#define SZK_SERVER_SIGNING		"server signing"
#define SZK_DIR_SORT			"dirsort"
#define SZK_NT4_ENUM			"enable nt4 enum"
#define SZK_DNS_REGISTER_NIC	"register nic"
#define SZK_VFS_OBJECTS			"vfs objects"
#define SZK_INSECURE_WIDELINKS	"allow insecure widelinks"
#define SZK_DOMAIN_ADVOPT		"advanced_domain_option"
#define SZK_RESET_ON_ZERO_VC	"reset on zero vc"
#define SZK_NESTED_EXPAND_GROUP	"winbind expand groups"
#define SZK_DIRECTORY_MASK		"directory mask"
#define SZK_DISABLE_SHADOW_COPY			"disable shadow copy"
#define SZK_CREATE_MASK			"create mask"
#define SZK_DISABLE_DOMAIN_ADMIN	"disable domain admins"
#define SZK_SMB_ENCRYPT                "smb encrypt"
#define SZK_STRICT_ALLOCATE             "strict allocate"
#define SZK_WILDCARD_SEARCH		"syno wildcard search"
#define SZK_SPOTLIGHT_DAEMON_TYPE	"rpc_daemon:mdssd"
#define SZK_SPOTLIGHT_SERVER_TYPE	"rpc_server:mdssvc"
#define SZK_DURABLE_HANDLES		"durable handles"
#define SZK_POSIX_LOCKING		"posix locking"
#define SZK_KERNEL_SHARE_MODE	"kernel share modes"
#define SZK_SMB2_LEASES			"smb2 leases"
#define SZK_BTRFS_CLONE			"btrfs clone"
#define SZK_SYNO_CATIA			"syno catia"

#define SZV_CREATE_MASK			"0744"
#define SZV_DIRECTORY_MASK		"0755"

#define SZV_RPC_DAEMON_TYPE_FORK	"fork"
#define SZV_RPC_SERVER_TYPE_EXTERN	"external"

/** CTDB setting for smb.conf */
#define SZK_CLUSTERING			"clustering"
#define SZK_IDMAP_BACKEND		"idmap backend"
#define SZK_NETBIOS_NAME		"netbios name"
#define SZK_CLUSTERING_ADDR		"cluster addresses"

/**
 * @}
 */

__END_DECLS;
#endif /* __SYNO_SMBCONF_H__ */
