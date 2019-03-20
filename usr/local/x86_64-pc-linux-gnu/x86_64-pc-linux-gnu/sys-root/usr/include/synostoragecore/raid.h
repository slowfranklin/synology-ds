#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_RAID_H__
#define __SYNO_STGCORE_RAID_H__

#include <limits.h>
#include <linux/raid/md_u.h>
#include <sys/cdefs.h>
#include <sys/param.h>

#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/list.h>
#include <hwctl/disk.h>

__BEGIN_DECLS;

/**
 * @addtogroup RAID The structure and operation of RAID.
 * @{
 * @defgroup RAID_int The internal structure and functions for RAID.
 */

#define SZ_DEVICE_RAID  "/dev/md"
#define SZ_SYSBLOCKS_RAID  "/sys/block/md"
#define MAX_LEN_RAID_UUID 64
#define MAX_LEN_RAID_PATH 64
#define RAID_REMOVE_RETRY_TIME 3
#define RAID_SYNC_SPEED_MAX_DEFAULT_KB 200000
#define SZ_RAID_GLOBAL_SYNC_SPEED_MAX_PATH "/proc/sys/dev/raid/speed_limit_max"
#define SZ_RAID_GLOBAL_SYNC_SPEED_MIN_PATH "/proc/sys/dev/raid/speed_limit_min"

#define SZ_SYS_RAID_CONF "system_raid.conf"
#define SZF_SYS_RAID_CONF "/usr/syno/etc/" SZ_SYS_RAID_CONF
#define SZF_SYS_RAID_CONF_TMP "/tmp/" SZ_SYS_RAID_CONF
#define SZF_REBOOT_AFTER_REBUILD   "/tmp/.reboot_after_rebuild"
#define SZF_FOLDER_RAID_CONF "/etc/raid"
#define SZF_FOLDER_RAID_BKP SZF_FOLDER_RAID_CONF "/bkp_reshape"
#define SZF_FOLDER_RAID_PROGRESS SZF_FOLDER_RAID_CONF "/progress_repair"
#define SYNORAID_CMDPATH_MDADM "/sbin/mdadm"
#define SYNORAID_CMDPATH_SFDISK "/sbin/sfdisk"
#define SZ_RAID_STATE_CLEAN "clean"
#define SZ_RAID_STATE_ACTIVE "active"
#define SZ_RAID_STATE_ACTIVE_IDLE "active-idle"

#if defined(MY_DEF_HERE)
#define SYNORAID_STRIPE_CACHE_SIZE 4096
#elif defined(MY_DEF_HERE)
#define SYNORAID_STRIPE_CACHE_SIZE 512
#else
#define SYNORAID_STRIPE_CACHE_SIZE 1024
#endif

#define SYNORAID_CMDLINE_BUFSIZE 512
#define SYNORAID_VOL_DATA_IDBEGIN 2	/* ID follows system volumes */
#define SYNORAID_VOL_ID_SYSTEM 0
#define SYNORAID_VOL_ID_SWAP 1

/* data partition is the third partition */
#define SYNORAID_PART_SYSTEM 0
#define SYNORAID_PART_SWAP 1
#define SYNORAID_PART_DATA 2

#define SYNORAID_PART_MAX 4
#define SYNORAID_VOL_MD_MAP    1
#define SYNORAID_VOL_ID_SYSTEM 0
#define SYNORAID_MD_SUPERBLOCK_RESERVE	256 //sectors

#define MIN_RAID_DEVICE_SIZE_SECTORS  2097152 // 1GB

/* New RAID definition */
#ifndef MY_DEF_HERE
#define RAID_ID_MIN_EBOX 100 // /dev/md101
#endif
#define RAID_ID_E2FSPROGS 9999
#define MAX_RAID_1_DISK_COUNT 4
#define MIN_RAID_0_DISK_COUNT 2
#define MIN_RAID_LINEAR_DISK_COUNT 1
#define MIN_RAID_5_DISK_COUNT 3
#define MIN_RAID_6_DISK_COUNT 4
#define MIN_RAID_10_DISK_COUNT 4
#define SZ_RAID_ROOT "/dev/md0"
#define SZ_RAID_SWAP "/dev/md1"
#define SZ_RAID_DATA_VOL		"/dev/md2"

#define RAID10_PARITY_COUNT 2

#define MIN_DISK_FOR_DYNAMIC_ADJUST 15

/* RAID Level */
#define SZ_RAID_1 "raid1"
#define SZ_RAID_0 "raid0"
#define SZ_RAID_5 "raid5"
#define SZ_RAID_6 "raid6"
#define SZ_RAID_10 "raid10"
#define SZ_RAID_JBOD "linear"
#define SZ_RAID_F1 "raidf1"
#define SZ_RAID_ADD_SPARE "+spare"
#define SZK_SWAP_DISK "swap_disks"

typedef enum _tag_raid_type_{
	RAID_0 = 0x01,
	RAID_1 = 0x02,
	RAID_5 = 0x04,
	RAID_6 = 0x08,
	RAID_10 = 0x10,
	RAID_LINEAR = 0x20, //JBOD
	RAID_F1 = 0x40,
} RAID_LEVEL;

#define RAID_WITH_PROTECTION (RAID_1 | RAID_5 | RAID_6 | RAID_10 | RAID_F1)
#define RAID_NEED_DD_READ(lvl, dcount) (!(lvl & RAID_WITH_PROTECTION) || 1 == dcount)
#define RAID_IS_ALIGN_64K(raid) (0 == raid->ullMinDevSize % (64*1024))

#define RAID_LEVEL_WITH_PARITY (RAID_5 | RAID_6 | RAID_F1)
#define RAID_LEVEL_FORCE_RESYNC RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_RMW_MODE RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_STRIPE_CACHE_TUNE RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_SSD_TRIM_PARTIALLY_SUPPORT RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_DISABLE_MBLK_IO_SUBMIT RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_SUPPORT_SCRUBBING RAID_LEVEL_WITH_PARITY
#define RAID_LEVEL_FORCE_ASSEMBLE_SCRUBBING RAID_LEVEL_WITH_PARITY

/* shouldn't change these RAID_STATUS order, we have use this enum order to compared
 * ex. ScemEBoxRaidReadyCheck(..) in lnxscemd-2.0
 */
typedef enum _tag_raid_status_{
	RAID_NORMAL = 0x01,
	RAID_DEGRADE = 0x02,
	RAID_CRASHED = 0x04,
} RAID_STATUS;

typedef enum _tag_raid_sync_status_{
	MD_IDLE,
	MD_FROZEN,
	MD_RESHAPE,
	MD_RESYNC,
	MD_CHECK,
	MD_REPAIR,
	MD_RECOVER,
} RAID_SYNC_STATUS;

typedef enum _tag_raid_rebuild_mode_{
	REBUILD_NONE,
	REBUILD_PROGRESS,
	REBUILD_WAIT,
} RAID_REBUILD_MODE;

typedef struct _tag_raid_rebuild_status_{
	RAID_REBUILD_MODE buildStatus;
	unsigned long long ullDoneSectors;
	unsigned long long ullTotalSectors;
} RAID_REBUILD_STATUS;

typedef enum _tag_enum_raid_disk_status_{
	RAID_DEV_NORMAL=0x01,  //normal used
	RAID_DEV_FAILED=0x02, // degraded disk.
	RAID_DEV_CRASHED=0x04, // crashed disk.
	RAID_DEV_REBUILD=0x08, // rebuilding disk.
	RAID_DEV_SPARE=0x10, // spare disk.
	RAID_DEV_NONE=0x20	//not found
} RAID_DEV_STAT;

typedef struct _tag_raid_disk_list_{
	char szPath[128]; // device path
	RAID_DEV_STAT status;
    int slot;  //order of disk in RAID
	struct _tag_raid_disk_list_ *pNext;
} RAID_DEV_LIST;

typedef struct _tag_raid_version_{
	int major;
	int minor;
} RAID_SB_VERSION;

typedef struct _tag_raid_info_{
	int id; // md id
	char szDevPath[128];
	char szUUID[MAX_LEN_RAID_UUID]; // Get this information by using RAIDUUIDGet(). Get UUID will wake-up disk from sleep mode.
	RAID_LEVEL raidLevel;
	RAID_SB_VERSION raidVersion;
	RAID_STATUS raidStatus;
	RAID_REBUILD_STATUS buildStatus;
	unsigned long long ullTotalSize;	 //Bytes
	unsigned long long ullMinDevSize; 	//Bytes, 0 means no redundant data.
	int designedDiskCount;
	/*
	 * active disk includes the disk which status is error because the disk is
	 * still use in md for data rescue. If you want to get failed disk count by
	 * substracting activeDiskCount from designedDiskCount, you must subtract
	 * count of error status disk as well or just accumulate each status of disk.
	 */
	int activeDiskCount;
	int spareDiskCount;
	RAID_DEV_LIST *pDiskList;
} RAID_INFO;

typedef struct _tag_raid_info_list_{
	RAID_INFO *pInfo;
	struct _tag_raid_info_list_ *pNext;
	int refCounts;		//Put here for API compatability of SynoHA.
} RAID_INFO_LIST;

typedef enum _tag_raid_device_type_{
	RAID_RAID = 0x01,
	RAID_DISK = 0x02,
} RAID_DEVICE_TYPE;

/* RAID superblock */
typedef struct _tag_raid_sb_{
	RAID_SB_VERSION version;
	char szUUID[MAX_LEN_RAID_UUID];
	char szRAIDPath[64];
	RAID_LEVEL level;
	int designedDiskCount;
	int devOrder; //zero-base
	int events;
} RAID_SB_INFO;

typedef struct _tag_raid_sb_list_{
	RAID_SB_INFO *pInfo;
	struct _tag_raid_sb_list_ *pNext;
} RAID_SB_LIST;

//If field is NULL, it means not to search by the filter.
typedef struct _tag_raid_search_filter_{
	const char *szDevPath;	 //Device Path.
	const int *isBuilding; //If RAID is building.
	const int *pPartNo;	   //Match partition number
	RAID_DEVICE_TYPE type;
} RAID_SEARCH_FILTER;

typedef struct _tag_raid_for_system_{
	RAID_INFO *pRoot;
	RAID_INFO *pSwap;
} RAID_FOR_SYSTEM;

typedef enum _tag_raid_action_type_{
	RAID_CREATE = 1,
	RAID_REPAIR,
	RAID_EXPAND_DISK, //expand by add disk
	RAID_EXPAND_SIZE, //expand with unallocated size
	RAID_MIGRATE,
	RAID_DELETE,
	RAID_ADD_SPARE
} RAID_ACTION_TYPE;

typedef struct _tag_raid_assemble_params_{
	const char *szRAIDPath;
	const char *szUUID;
	BOOL blUpdateSB; //update superblock
	BOOL blForce;
	PSLIBSZLIST pDiskList;
} RAID_ASSEMBLE_PARAMS;

typedef struct _tag_raid_create_params_{
	const char *szRAIDPath;
	const RAID_SB_VERSION *pVer;
	RAID_LEVEL raidLevel;
	int cSpareDisk;
	int cDesignedDisk;
	unsigned long long ullMinDevSize;
	PSLIBSZLIST pDevList;
	BOOL blBuilding;
} RAID_CREATE_PARAMS;

static inline unsigned long long SYNORAID_GET_RESERVE_SIZE(PARTITITON_LAYOUT_VERSION version) {
	switch (version) {
	case PARTITITON_LAYOUT_V1: return SYNORAID_RESERVE_SIZE;
	case PARTITITON_LAYOUT_V2: return SYNORAID_RESERVE_SIZE_V2;
	case PARTITITON_LAYOUT_V6: return SYNORAID_RESERVE_SIZE_V6;
	case PARTITITON_LAYOUT_V7: return SYNORAID_RESERVE_SIZE_V7;
	case PARTITITON_LAYOUT_V8:
	default: return SYNORAID_RESERVE_SIZE_V8;
	}
}

#include <synostoragecore/raid_p.h>

__END_DECLS;

#endif // __SYNO_STGCORE_RAID_H__
