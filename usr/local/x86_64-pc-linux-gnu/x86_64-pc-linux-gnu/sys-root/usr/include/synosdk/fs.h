#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_FS_H__
#define __SYNO_FS_H__
#include <linux/syno.h>

#include <limits.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/statfs.h>
#include <sys/stat.h>

#include <synocore/synotype.h>
#include <synocore/error.h>
#include <synocore/hash.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synosdk/share.h>
#include <synocore/list.h>
#include <synosdk/servicecfg.h>

__BEGIN_DECLS;

/**
 * @addtogroup FS
 *
 * @brief Some basic structure and operation of Filesystem. More features in libsynostoragecore.
 *
 * @{
 */

/**
 * man "statfs" for the details of these magic numbers
 */
#define FS_MAGIC_MSDOS	0x4d44
#define FS_MAGIC_NTFS	0x5346544E
#define FS_MAGIC_EXT3	0xEF53
#define FS_MAGIC_NFS	0x6969
#define FS_MAGIC_FUSE	0x65735546
#define FS_MAGIC_CIFS	0xFF534D42
#define FS_MAGIC_TMPFS	0x01021994
#define FS_MAGIC_ISO	0x9660
#define FS_MAGIC_UDF	0x15013346
#define FS_MAGIC_HFSPLUS  0x482b
#define FS_MAGIC_HFSPLUS_CASE 0x4858
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define FS_MAGIC_BTRFS_HI 0x5248425F
#define FS_MAGIC_BTRFS_LO 0x4D5F5366
#else
#define FS_MAGIC_BTRFS_HI 0x4D5F5366
#define FS_MAGIC_BTRFS_LO 0x5248425F
#endif
#define FS_MAGIC_BTRFS_STATFS 0x9123683E
#define FS_MAGIC_UBIFS	0x24051905
#define FS_MAGIC_ECRYPTFS 0xF15F
#define FS_MAGIC_AUFS 0x61756673
#define FS_MAGIC_EXFAT 0x2011BAB0L

#define DEVICE_PATH_MAX 64 // moved from fs_get_ext_type.c

#define SZF_FSCK "/sbin/fsck"
#define SZF_NTFS3G	"/bin/ntfs-3g"
#define SZF_BTRFS_TOOL "/sbin/btrfs"
#define SZF_MKFS_PREFIX "/sbin/mkfs"
#define SZK_MKFS_EXT3	"/sbin/mkfs.ext3"
#define SZK_MKFS_EXT4	"/sbin/mkfs.ext4"
#define SZF_MKFS_BTRFS "/sbin/mkfs.btrfs"
#define SZF_MKFS_VFAT "/sbin/mkfs.vfat"
#define SZF_MKFS_EXFAT "/usr/local/bin/mkfs.exfat"
#define SZK_RESIZE2FS	"/sbin/resize2fs"
#define SZF_ZPOOL      "/sbin/zpool"
#define SZF_PROC_MOUNTS_PATH	"/proc/mounts"
#define SZF_FSTAB		"/etc/fstab"
#define SZ_AUFS			"aufs"
#define SZ_EXT4			"ext4"
#define SZ_BTRFS		"btrfs"
#define SZ_ECRYPTFS		"ecryptfs"
#define SZ_GLUSTERFS		"fuse.glusterfs"
#define SZ_GVFS		      "fuse.gvfsd-fuse"
#define SZ_NTFS_BLK		  "fuseblk.ntfs"
#define SZ_NTFS			  "fuse.ntfs"
#define BTRFS_SB_OFFSET 65536
/**
 * for default mount options
 */
#define SZ_DEFAULTS             "defaults"
#define SZ_MKFS_CMD_FMT "%s %s"
/**
 * ext4, ext3, ntfs
 */
#define MAX_LEN_FS_TYPE  32
#define SZD_DEV	"/dev"

#define BTRFS_LABEL_SIZE 256

#define SZ_CMD_UUID_GEN "/usr/bin/uuidgen"
#define SZF_UUID_FILE ".fsuuid"
#define SZK_UUID "uuid"
#define SZF_VOLUME_UUID_MAP "/usr/syno/etc/volume_uuid.map"

#define SZF_TRIGGER_VSCAN_FILEPATH "/.trigger_vscan_dialog"
#define SZF_TRIGGER_FORCE_FILEPATH "/.trigger_force_dialog"
#define SZF_TRIGGER_WCACHE_FILEPATH "/.trigger_wcache_dialog"
#define SZF_TRIGGER_FSCK_FILEPATH "/.trigger_fsck_dialog"
#define SZF_TRIGGER_REMIND_FSCK_FILEPATH "/.trigger_remind_fsck_dialog"
#define SZF_DATA_SCRUBBING_FILEPATH "/.doing_data_scrubbing"
#define SZF_FSCK_FILEPATH "/.do_fsck"
#define SZF_DISK_DATA_SCRUBBING_FILEPATH "/tmp/.data_scrubbing_"
#define SZF_VSCAN_CONFIRM_FILEPATH "/.vscan_confirmed"

#define SZF_FS_EXT4_PERFIX "/sys/fs/ext4"
#define SZF_FS_BTRFS_PREFIX "/sys/fs/btrfs"
#define SZ_FS_EXT4_ERROR_EVENT "syno_fs_error_new_event_flag"
#define SZ_FS_EXT4_ERROR_MOUNTED "syno_fs_error_mounted"
#define SZ_DELALLOC "delalloc"
#define SZ_NODELALLOC "nodelalloc"

#define SZK_DEFAULT_FS	"defaultfs"
#define SZK_SUPPORT_BTRFS "support_btrfs"
#define SZV_DEFAULT_FS  "ext4"

#define SZ_FAT_SPCHAR	"\\/:*?\"><|\r\n"

#ifndef BLKGETSIZE64

/**
 * we define ourself since including <linux/fs.h> will
 * conflict with statfs for <sys/vfs.h>
 *
 * return device size in bytes (u64 *arg)
 */
#define BLKGETSIZE64 _IOR(0x12,114,size_t)
#endif

/**
 * INTERNAL_DEVICE including sata and sas
 */
typedef enum {
	UNKNOWN_DEVICE = 0,
	INTERNAL_DEVICE,
	EXTERNAL_SATA_DEVICE,
	EUNIT_DEVICE,
	EXTERNAL_USB_DEVICE,
	SYNOBOOT_DEVICE,
	ISCSI_DEVICE,
	CACHE_DEVICE,
	/**
	 * this is used for #37785, to mount usb disk in hub, define it for future use
	 */
	USB_HUB_DEVICE,
	SDCARD_DEVICE,
	DISK_PORT_TYPE_END,
} DISK_PORT_TYPE;

/**
 * @deprecate in DSM 5.1
 */
enum {
	/** convert from ext2/3/4 to FAT/NTFS */
	EA_EADIR_TO_FSEA = 0,
	/** convert from FAT/NTFS to ext2/3/4 */
	EA_FSEA_TO_EADIR,
	/** convert from ext2/3/4 to ext2/3/4 */
	EA_EADIR_TO_EADIR,
	/** convert from FAT/NTFS to FAT/NTFS */
	EA_FSEA_TO_FSEA
};

enum {
	/** convert from ext2/3 to FAT/NTFS */
	EA_13_ENTRY_TO_2_ENTRY = 0,
	/** convert from FAT/NTFS to ext2/3 */
	EA_2_ENTRY_TO_13_ENTRY,
	/** convert from ext2/3 to ext2/3 */
	EA_13_ENTRY_TO_13_ENTRY,
	/** convert from FAT/NTFS to FAT/NTFS */
	EA_2_ENTRY_TO_2_ENTRY
};

/**
 *  Disk inode status
 */
typedef enum {
	INODE_STATUS_NORMAL,
	INODE_STATUS_ABOVE_LIMIT,
	INODE_STATUS_TOTAL_FULL,
	INODE_STATUS_FAIL,
	INODE_STATUS_NONE,
} INODESTATUS;

typedef enum _tag_FSTYPE{
	FSTYPE_ERR = -1,
	FSTYPE_FAT = 0,
	FSTYPE_EXT3,
	FSTYPE_EXT4,
	FSTYPE_BTRFS,
	/* FSTYPE_ZFS is deprecated*/
	FSTYPE_NTFS = 5,
	FSTYPE_CIFS,
	/**
	 * 1. HFS+ are not supported in older kernel before 2.6.32
	 * 2. HFS+ are not supported in any synology disk format named backup disk
	 * 3. so, when implementing HFS+ codes, we only need to consider multiple-(usb/esata) with multiple-partition
	 */
	FSTYPE_HFSPLUS,
	FSTYPE_ISO,
	FSTYPE_UDF,
	FSTYPE_GLUSTERFS,
	FSTYPE_UBIFS,
	FSTYPE_GVFS,
	FSTYPE_AUFS,
	FSTYPE_NFS,
	/** The number of filesystems supported, should be the least one. */
	FSTYPE_NUM,
	FSTYPE_DEFAULT,
	FSTYPE_UNKOWN,
	/* FSTYPE_EXFAT, FSTYPE_EXT2 are added on 6.0.1. To maintain the ABI consistency between 6.0 and 6.X, just add it at the tail.*/
	FSTYPE_EXFAT,
	FSTYPE_EXT2,
	FSTYPE_BKPFUSE = 20,
	// If you add anything here, make sure FSTYPE_MAX in fs_int.h is also increased!
 } FSTYPE;

typedef enum _tag_RESIZE_QUERY_CMD{
	ONLINE_RESIZABLE = 1,
	EXPANSIABLE = 2,
	HAS_64BIT = 3,
	HAS_META_BG = 4
} RESIZE_QUERY_CMD;

typedef enum _tag_FSFILTERTYPE{
	FSFILTERTYPE_NONE = 0,
	FSFILTERTYPE_FAT = 0x02,
	FSFILTERTYPE_EXT3 = 0x04,
	FSFILTERTYPE_EXT4 = 0x08,
	FSFILTERTYPE_NTFS = 0x010,
	FSFILTERTYPE_CIFS = 0x020,
	FSFILTERTYPE_HFSPLUS = 0x040,
	FSFILTERTYPE_ISO = 0x080,
	FSFILTERTYPE_UDF = 0x100,
	FSFILTERTYPE_BTRFS = 0x200,
	/* FSFILTERTYPE_ZFS = 0x400 is deprecated */
	FSFILTERTYPE_EXFAT = 0x800,
	FSFILTERTYPE_EXT2 = 0x1000,
	FSFILTERTYPE_NFS = 0x2000,
	FSFILTERTYPE_ISO_REMOTE = (FSFILTERTYPE_CIFS | FSFILTERTYPE_ISO | FSFILTERTYPE_UDF | FSFILTERTYPE_NFS),
} FSFILTERTYPE;

typedef enum _tag_FS_ACCCESS_STATUS{
	FS_READ_WRITE = 0x01,
	FS_READ_ONLY = 0x02,
} FS_ACCCESS_STATUS;

typedef struct {
	const char *szPathPrefix;
	FS_ACCCESS_STATUS st;
} FS_FILTER;

typedef struct {
	char szMountPath[256];
	char szDevPath[256];
	/** bytes */
	unsigned long long ullFreeSize;
	unsigned long long ullTotalSize;
	FS_ACCCESS_STATUS fsStatus;
	FSTYPE fsType;
	unsigned long long ullFreeInode;
	unsigned long long ullTotalInode;
} FS_INFO;

extern const char rgszFsType[][MAX_LEN_FS_TYPE];

extern const char gszFsExFAT[MAX_LEN_FS_TYPE];
extern const char gszFsExt2[MAX_LEN_FS_TYPE];

/**
 * Check the file system which user want to mkfs
 * is valid in our system or not.
 *
 * @param[in]    fsType   The filesystem type.
 *
 * @retval TRUE    Valid to mkfs for our system.
 * @retval FALSE   Otherwise.
 */
static inline BOOL
SYNOFSTypeMKFSSupported(FSTYPE fsType)
{
	if ((FSTYPE_EXT3 == fsType) || (FSTYPE_EXT4 == fsType) ||
			(FSTYPE_FAT == fsType) || (FSTYPE_BTRFS == fsType)) {
		return TRUE;
	}
	return FALSE;
}

/**
 * Check if the external device file system is supported by
 * our system or not.
 *
 * @param[in]    fsType   The filesystem type.
 *
 * @retval TRUE   Supported by our system
 * @retval FALSE  Otherwise.
 */
static inline BOOL
SYNOFSTypeExternalSupported(FSTYPE fsType)
{
	switch (fsType) {
	case FSTYPE_FAT:
	case FSTYPE_EXT3:
	case FSTYPE_EXT4:
	case FSTYPE_NTFS:
	case FSTYPE_HFSPLUS:
	case FSTYPE_BTRFS:
	case FSTYPE_EXFAT:
		return TRUE;
	default:
		return FALSE;
	}
}

/**
 * Check the file system is valid for internal disk or not.
 *
 * @param[in]    fsType   The filesystem type.
 *
 * @retval TRUE   Valid for our system.
 * @retval FALSE  Not valid.
 */
static inline BOOL
SYNOFSTypeIsInternal(FSTYPE fsType)
{
	if ((FSTYPE_EXT3 == fsType) || (FSTYPE_EXT4 == fsType) || (FSTYPE_BTRFS == fsType)) {
		return TRUE;
	}
	return FALSE;
}

/**
 * Mapping FS_MAGIC to FSTYPE.
 *
 * @param[in]   statfs_ftype    The f_type field of struct statfs, you can man statfs to see more info.
 *
 * @retval FSTYPE_ERR  No FS_MAGIC to map.
 * @retval Otherwise   The mapping from FS_MAGIC to FSTYPE.
 */
static inline FSTYPE
SYNOFSMagicToFstype(long statfs_ftype)
{
	switch (statfs_ftype) {
	case FS_MAGIC_MSDOS:
		return FSTYPE_FAT;
	case FS_MAGIC_NTFS:
		return FSTYPE_NTFS;
	case FS_MAGIC_HFSPLUS:
		return FSTYPE_HFSPLUS;
	case FS_MAGIC_AUFS:
		return FSTYPE_AUFS;
	case FS_MAGIC_EXT3:
	case FS_MAGIC_TMPFS:
		return FSTYPE_EXT3;
	case FS_MAGIC_CIFS:
		return FSTYPE_CIFS;
	case FS_MAGIC_ISO:
		return FSTYPE_ISO;
	case FS_MAGIC_UDF:
		return FSTYPE_UDF;
	case FS_MAGIC_BTRFS_STATFS:
		return FSTYPE_BTRFS;
	case FS_MAGIC_UBIFS:
		return FSTYPE_UBIFS;
	case FS_MAGIC_NFS:
		return FSTYPE_NFS;
	case FS_MAGIC_EXFAT:
		return FSTYPE_EXFAT;
	default:
		return FSTYPE_ERR;
	}
}

#define SZV_YES				"yes"
#define SZV_NO				"no"

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/fs_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_FS_H__
