// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_SPACE_H__
#define __SYNO_STGCORE_SPACE_H__

#include <sys/types.h>

#include <synoflashcache/synoflashcache.h>
#include <synosdk/fs.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include <synosdk/volume.h>
#include <synostoragecore/lvm.h>
#include <synostoragecore/raid.h>
#include <hwctl/disk.h>

__BEGIN_DECLS;

#define SZ_SPACE_TMP_FOLDER "/tmp/space"
#define SZF_SPACE_LOCK_FOLDER SZ_SPACE_TMP_FOLDER "/lock"
#define SZF_SPACE_BUSY "/run/synostorage/space_busy"
#define SZF_SPACE_OPERATION_ERROR_LOG "/var/log/space_operation_error.log"

//Data scrubbing suggestion
#define SZF_SYNO_DATA_SCRUBBING_NOTIFICATION_TOOL "/usr/syno/bin/synodatascrubbingnotify"
#define SZF_SYNO_DATA_SCRUBBING_CONF "/usr/syno/etc/datascrubbing.conf"
#define SZF_SYNO_DATA_SCRUBBING_TMP_CONF "/tmp/datascrubbingmd.conf"
#define SZK_SYNO_DATA_SCRUBBING_KEY "raid5datascrubbingchecked"
#define SZK_SYNO_DATA_SCRUBBING_CHECKED "raid5datascrubbingcheckeduntil"
#define SZK_SYNO_DATA_SCRUBBING_SCHED_TIME "raid5datascrubbingscheduledtime"
#define SZK_SYNO_DATA_SCRUBBING_SCHED "raid5datascrubbingschedule"
#define SZK_SYNO_DATA_SCRUBBING_TIMESTAMP "scrubbingtimestamp"
#define SZK_SYNO_DATA_SCRUBBING_STATUS "scrubbingstatus"
#define SZK_SYNO_DATA_SCRUBBING_PROGRESS "scrubbingprogress"
#define SZK_SYNO_DATA_SCRUBBING_GENERAL_SECTION "ScrubbingGeneral"
#define SZ_SYNO_DATA_SCRUBBING_NOTIFICATION_TAG "RaidSuggestDataScrubbing"

//Mapping status
#define SZF_SPACE_MAPPING SZ_SPACE_TMP_FOLDER "/space_mapping.xml"
#define SZF_SPACE_MAPPING_TMP SZF_SPACE_MAPPING ".tmp"
#define SZF_SPACE_WARN_DISK_CONTAIN_CRASHED ".warn_disks_contain_crashed_space"
#define MAX_LEN_SPACE_PATH (MAX_LEN_VGPATH >= MAX_LEN_RAID_PATH) ? MAX_LEN_VGPATH : MAX_LEN_RAID_PATH//  for /dev/md, /dev/vg/lv, /dev/vg1
#define MAX_LEN_SPACE_SNAPSHOT_PATH (MAX_LEN_SPACE_PATH + 32) // length of volume path.
#define MAX_LEN_DRBD_PATH (MAX_LEN_SPACE_PATH + 10) // /dev/drbd.xxx
#define MAX_LEN_SPACE_REFERENCE_PATH (MAX_LEN_ISCSITRG_NAME >= MAX_LEN_ISCSI_NAME) ? (MAX_LEN_ISCSITRG_NAME + 1) : (MAX_LEN_ISCSI_NAME + 1)
#define MAX_LEN_UUID (MAX_LEN_VGUUID > MAX_LEN_RAID_UUID) ? MAX_LEN_VGUUID : MAX_LEN_RAID_UUID

//History status
#define SZD_SPACE_CONFIG_FOLDER "/etc/space"
#define MIN_SYSDEF_DATA_PROTECTED 2
#define MIN_SYSDEF_2_DATA_PROTECTED 4

#define SDK_MAX_DISK_COUNT 1024

#define SZ_MAGIC_SYNO_BLOCK "SYNOLOGY_SUPER_BLOCK"
#define SYNO_BLOCK_VERSION 5
#define SYNO_BLOCK_OFFSET 20480 //40 sectors, left 23 sectors for SYNO-BLOCK
#define SYNO_BLOCK_OFFSET_V2 512000 // 1000 sectors

#define SSDCACHE_PARTITION_OFFSET P1OFFSET_V8

#define SZ_DD_TOOL "/bin/synodd"
#define SZF_SPACE_TOOL "/usr/syno/bin/spacetool"
#define SZF_SPACE_TOOL_SHARED "/usr/syno/bin/spacetool.shared"
#define SZ_STORAGE_POOL "@storage_pool"
#define SZ_SSD_CACHE "@ssd_cache"
#define SZ_UNUSED "@unused"
#define SZ_UNUSED_SPACE_MAGIC "SYNOLOGY_UNUSED_SPACE"

#define SZ_PREFIX_REUSE_SPACE_ID "reuse_"
#define SZ_PREFIX_VOLUME_PATH "/volume"
#define SZ_PREFIX_LUN_PATH "LUN"
#define SZ_PREFIX_SSDID		"ssd_"
#define MAX_SSDID_LENGTH	64
#define MAX_SSDCACHE_NUM	128

#define NOTIFY_ASSISTANT_CREATE_VOL "/.assistant_install_create_vol"
#define NOTIFY_ASSISTANT_VOL_CREATING "/.assistant_install_vol_creating_notify"

//SSD TRIM
#define SZF_VOLUME_TRIM_TBL "/usr/syno/etc/volume_trim_tbl"
#define SZF_SPACE_TMP_TRIM_PREFIX SZ_SPACE_TMP_FOLDER "/ssd_trimming"

/* Don't change it! It'll effect SYNO_BLOCK write/read */
#define MAX_LEN_BLK_MAGIC	64
#define MAX_LEN_BLK_SPACE_PATH	256
#define MAX_LEN_BLK_VG_PATH	128
#define MAX_LEN_BLK_VG_UUID	256
#define MAX_LEN_BLK_RAID_UUID	64
#define MAX_LEN_BLK_REUSE_SPACE_ID 128
#define MAX_LEN_BLK_SPACE_DESCRIPTION 512
#define MAX_LEN_DESCRIPTIONS_UNICODE_MAX 32
#define MAX_LEN_BLK_RAID_GROUP_LIMIT 16
#define SZ_MAGIC_LIMIT_6 "SYNO_06"
#define SZ_MAGIC_LIMIT_12 "SYNO_12"
#define SZ_MAGIC_LIMIT_24 "SYNO_24"
#define SZ_MAGIC_LIMIT_UNKNOW "SYNO_UNKNOW"

#define RAIDGROUP_DISK_LIMIT_NUM_DEFAULT 12

#define EACH_RAID(raid) EACH_ELEMENT(raid)
#define EACH_SPACE(space) EACH_ELEMENT(space)
#define EACH_DISK(disk) EACH_ELEMENT(disk)
#define EACH_RAID_ACTION(action) EACH_ELEMENT(action)
#define EACH_PARTITION(parts, idx) EACH_LIST_MEMBER(parts, idx)
#define EACH_SPACE_DISK(disk, idx) EACH_LIST_MEMBER(disk, idx)

#define SPACE_GET_VG(space) space->pVGInfo
#define SPACE_GET_LV(space) space->pVGInfo->pLVInfoList
#define SPACE_GET_RAIDLIST(space) space->pRAIDList
#define SPACE_GET_FIRST_RAID(space) space->pRAIDList->pInfo
#define SPACE_IS_USED_BY_VOLUME(space) (SPACE_VOLUME == space->spaceType)
#define SPACE_IS_NORMAL(space) (0 == space->st.status)
#define SPACE_HAS_ABNORMAL_STATUS(space, abn_st) (space->st.status & abn_st)
#define SPACE_SNAPSHOTORG_IS_ACTIVE(space) (0 < strlen(space->szSnapshotOrgPath))
#define SPACE_SNAPSHOTORG_PATH(space) space->szSnapshotOrgPath
#define SPACE_MOUNT_PATH(space) (0 < strlen(space->szDrbdPath))?space->szDrbdPath:space->szPath

#define SZD_LVM_LV_PREFIX_VOL "volume_"
#define SZD_LVM_LV_PREFIX_ISCSI "iscsi_"
#define LV_PREFIX_BY_LV(lv_name) !strncmp(lv_name, SZD_LVM_LV, strlen(SZD_LVM_LV)) //For SHR check lv name
#define LV_PREFIX_BY_VOL(lv_name) !strncmp(lv_name, SZD_LVM_LV_PREFIX_VOL, strlen(SZD_LVM_LV_PREFIX_VOL))
#define LV_PREFIX_BY_ISCSI(lv_name) !strncmp(lv_name, SZD_LVM_LV_PREFIX_ISCSI, strlen(SZD_LVM_LV_PREFIX_ISCSI))
#define LV_GET_VOL_ID(lv_name) (lv_name + strlen(SZD_LVM_LV_PREFIX_VOL))

#define IS_SHR(space) (SPACE_SYSDEF_RAID == space->devType)
#define IS_STORAGE_POOL_CHILD(space) (0 != strcmp(space->szPath, space->szPoolPath))
#define IS_POOL_PATH(path, poolID) (1 == sscanf(path, PATH_LVM_VG "%d", &poolID))
#define HAS_LVM(space) (space->pVGInfo)

#define IS_SPACE_FILE_SYSTEM_EXPANDING(space) (SYNOSpaceIsActing(space, NULL) && (SPACE_STEP_FS_EXPAND == space->st.step))
#define IS_SPACE_FILE_SYSTEM_CREATING(space) (SYNOSpaceIsActing(space, NULL) && (SPACE_STEP_FS_MKFS == space->st.step))
#define IS_SPACE_MD1_IN_USE(space) (IS_SPACE_FILE_SYSTEM_EXPANDING(space) || IS_SPACE_FILE_SYSTEM_CREATING(space))
#define IS_SPACE_WAITING_OR_PARTITION_DISK(space) (SYNOSpaceIsActing(space, NULL) && ((SPACE_STEP_START == space->st.step) || (SPACE_STEP_DISK_PARTITION == space->st.step)))

#define GET_ACTIONING_STEP(space) space->st.step

#define CURRENT_SYNOBLOCK_VERSION 5

//For Multitask
#define LOCK_SPACE_MIDDLE_TIMEOUT 180 //seconds
#define LOCK_SPACE_SHORT_TIMEOUT 10 //seconds
#define LOCK_SPACE_NO_LIMIT -1 //seconds

typedef enum _space_service_action_{
	SERVICE_ACTION_START = 1,
	SERVICE_ACTION_STOP,
} SPACE_SERVICE_ACTION;

typedef enum _space_service_lock_result_{
	SERVICE_LOCK_DO = 1,
	SERVICE_LOCK_SKIP,
} SPACE_SERVICE_LOCK_RESULT;

typedef enum _tag_space_lock_type_{
	LOCK_BATCH_TASK_ACTION=0x01,
	LOCK_LVM_VG_ACTION=0x02,
	LOCK_ISCSI_PROGRESS_ACTION=0x04,
	LOCK_ISCSI_LUN_CONF_ACTION=0x08,
	LOCK_ISCSI_TRG_CONF_ACTION=0x10,
	LOCK_ISCSI_MAPPING_CONF_ACTION=0x20,
	LOCK_ISCSI_ACL_CONF_ACTION=0x40,
	LOCK_SERVICE_ACTION=0x80,
	LOCK_LUNBKP_FILE_CONF=0x100,
	LOCK_ISCSI_FAM_CONF_ACTION=0x200,
	LOCK_ISCSI_SNAPSHOT_PROGRESS_ACTION=0x400,
	LOCK_GET_SEQ_ACTION=0x800,
	LOCK_ISCSI_SST_CONF_ACTION=0x1000,
	LOCK_ISCSI_VIRTUAL_LUN_CONF_ACTION=0x2000,
	LOCK_ISCSI_TASK_CONF_ACTION=0x4000,
	LOCK_VIRTUAL_REPO_CONF_ACTION=0x8000,
	LOCK_VIRTUAL_DISK_CONF_ACTION=0x10000,
	LOCK_ISCSI_SNAPSHOT_CONF_ACTION=0x20000,
	LOCK_ISCSI_TASK_PROGRESS_CONF_ACTION=0x40000,
	LOCK_ISCSI_ALL_CONF_ACTION=0x80000,
	LOCK_ISCSI_SNAPSHOT_ID_ACTION=0x100000,
	LOCK_ISCSI_TASK_UNSYNC_CONF_ACTION=0x200000,
	LOCK_ISCSI_SUBVOL_CONV_PROGRESS_CONF_ACTION=0x400000,
	LOCK_DATA_SCRUBBING_CONF_ACTION=0x800000,
} SPACE_LOCK_TYPE;

/* General space type */
typedef enum _space_reference_type_ {
	SPACE_VOLUME=0x01,
	SPACE_ISCSI=0x02,
	SPACE_STORAGE_POOL=0x04,
	SPACE_SSDCACHE=0x08,
	SPACE_UNUSED=0x10,
	SPACE_ALL = SPACE_VOLUME | SPACE_ISCSI | SPACE_STORAGE_POOL,
} SPACE_REFERENCE_TYPE;

#define SPACE_ENHANCE_BY_SSDCACHE (SPACE_VOLUME | SPACE_ISCSI)

typedef enum _space_dev_type_ {
	SPACE_SYSDEF_RAID = 1, // SHR
	SPACE_CUSTOMIZE_RAID,
	SPACE_SINGLE_DISK,
	SPACE_OLD_EBOX_SINGLE_RAID,
	SPACE_OLD_EBOX_EXPANSION_RAID,
	SPACE_MULTI_RAID
} SPACE_DEV_TYPE;

typedef enum _space_drive_type_ {
	SPACE_DRIVE_TYPE_UNKNOWN = -1,
	SPACE_DRIVE_HDD = 0,
	SPACE_DRIVE_SSD = 1,
	SPACE_DRIVE_HYBRID = 2, // mix SSD/HDD
}SPACE_DRIVE_TYPE;

typedef enum _space_disk_status_type_ {
	SPACE_DISK_DATA_USED=0x01,
	SPACE_DISK_DATA_FAILED=0x02,
	SPACE_DISK_SYS_USED=0x04, //USED BY system RAID
	SPACE_DISK_SYS_FAILED=0x08,
} SPACE_DISK_STATUS_TYPE;

typedef enum _space_unused_path_flag_ {
	SPACE_UNUSED_VOLUME=1,
	SPACE_UNUSED_RAID,
	SPACE_UNUSED_LVM_POOL,
	SPACE_UNUSED_LVM_SHR,
	SPACE_UNUSED_REUSE_SPACE_ID,
	SPACE_UNUSED_SSDCACHE_ID,
} SPACE_UNUSED_PATH_FLAG;

typedef enum _space_component_ {
	SPACE_ELM_VOLUME=0x01,
	SPACE_ELM_ISCSI=0x02,
	SPACE_ELM_RAID=0x04,
	SPACE_ELM_LVM=0x08,
	SPACE_ELM_DISK=0x10, //Disk Partition
	SPACE_ELM_FILE=0x20, //Description file
	SPACE_ELM_BLOCK=0x40 //SYNO Block
} SPACE_ELEMENT;

/* Space Building File */
typedef enum _space_building_type_ {
	SPACE_BUILDING_NONE=1, //space is not building
	SPACE_BUILDING_BACKGROUND,
	SPACE_BUILDING_FOREGROUND,
} SPACE_BUILDING_TYPE;

enum _space_estimate_action_ {
	SPACE_EXPAND_SIZE = 0x01,
	SPACE_MIGRATE_2_RAID5 = 0x02,
};

typedef enum _space_building_task_ {
	SPACE_CREATE = 1,
	SPACE_ALLOC,
	SPACE_DEL,
	SPACE_REPAIR,
	SPACE_EXPAND_BY_DISK,
	SPACE_EXPAND_UNALLOCATED,
	SPACE_MIGRATE_TO_RAID1,
	SPACE_MIGRATE_TO_RAID5,
	SPACE_MIGRATE_TO_RAID6,
	SPACE_MIGRATE_ADD_MIRROR,
	SPACE_MIGRATE_TO_RAID5_ADD_SPARE,
	SPACE_RAID_SYNCING,		//Background RAID building
	SPACE_RAID_PARITY_CHECKING,
	SPACE_RAID_DISK_CHECKING,
	SPACE_RAID_ASSEMBLE,
	SPACE_CANCEL,
	SPACE_DEPLOY,
	SPACE_UNDEPLOY,
	SPACE_MOUNT_CACHE,
	SPACE_UNMOUNT_CACHE,
	SPACE_DATA_SCRUBBING,
	SPACE_EXPAND_UNFINISHED_SHR,
	SPACE_SSD_TRIMMING,
	SPACE_REPLACE_PARTITION,
	SPACE_CONVERT_SHR_TO_POOL,
	SPACE_MIGRATE_SHR1_TO_SHR2,
} SPACE_BUILDING_TASK;

typedef enum _space_building_step_ {
	SPACE_STEP_DISK_PARTITION=1,
	SPACE_STEP_DISK_CHECKING,
	SPACE_STEP_RAID_SYNCING,
	SPACE_STEP_RAID_PARITY_CHECKING,
	SPACE_STEP_RAID_RESHAPING,
	SPACE_STEP_FS_MKFS,
	SPACE_STEP_FS_EXPAND,
	SPACE_STEP_STOP_ALL_SERVICE,
	SPACE_STEP_START_ALL_SERVICE,
	SPACE_STEP_UNMOUNT_SPACE,  //stop using space, unmount or stop iSCSI
	SPACE_STEP_MOUNT_SPACE,
	SPACE_STEP_ALLOC_SPACE,
	SPACE_STEP_ENDING,
	SPACE_STEP_START,
	SPACE_STEP_DEPLOY,
	SPACE_STEP_UNDEPLOY,
} SPACE_BUILDING_STEP;

typedef enum _tag_enum_space_part_status_ {
	SPACE_PART_NORMAL = 1, // normal in MD
	SPACE_PART_FAILED,     // failed in MD
	SPACE_PART_REMOVE,     // remove form MD but have superblock
	SPACE_PART_UNUSED,     // this partition have no MD superblock on it
	SPACE_PART_SPARE,      // spare in MD
} SPACE_PART_STATUS;

typedef enum _tag_enum_space_shr_action_ {
	SHR_ACTION_ADD_DISK = 1,
	SHR_ACTION_MIGRATE_TO_SHR2,
} SPACE_SHR_ACTION;

typedef struct _space_part_info_ {
	char szPartPath[64];
	int partNum;
	SPACE_PART_STATUS status;
	struct _space_part_info_ *pNext;
} SPACE_PART_INFO;

typedef struct _space_failed_disk_info_ {
	char szDiskPath[64];
	int partNormalCount; // include normal and rebuilding partition
	int partSpareCount;
	int partFailedCount; // include failed and removed partition (must have MD superblock)
	int partUnusedCount; // any partitions without MD superblock
	SPACE_PART_INFO *pPartList;
	struct _space_failed_disk_info_ *pNext;
} SPACE_FAILED_DISK_INFO;

typedef struct _space_building_create_info_ {
	char szPoolPath[MAX_LEN_VGPATH];
	RAID_LEVEL raidLevel;
	BOOL blIsAddSpare;
} SPACE_BUILDING_CREATE_INFO;

typedef struct _space_build_obj_ {
	pid_t pid;
	int order;	//order of building, for 1 process want to do multiple volume actions.
	SPACE_REFERENCE_TYPE spaceType;
	SPACE_DEV_TYPE devType;
	SPACE_BUILDING_TASK task;
	SPACE_BUILDING_STEP step;
	char szPath[MAX_LEN_SPACE_REFERENCE_PATH]; // volume path or iSCSI lun Name
	PSLIBSZLIST pslBuildingDevice; //Device which is building
	PSLIBSZLIST pslDisks;
	SPACE_BUILDING_CREATE_INFO createInfo;
	char szReuseSpaceID[MAX_LEN_BLK_REUSE_SPACE_ID];
	struct _space_build_obj_ *pNext;
	char szTargetSpacePath[MAX_LEN_SPACE_REFERENCE_PATH];
} SPACE_BUILD_OBJ;

typedef struct _space_build_filter_ {
	const char *szSpaceReferPath;
	const char *szDiskPath;
} SPACE_BUILD_FILTER;

/* Space SYNO-BLOCK */
typedef struct _syno_block_space_ {
	SPACE_REFERENCE_TYPE      spaceType;
	char szPath[MAX_LEN_BLK_SPACE_PATH];
	char szReuseSpaceID[MAX_LEN_BLK_REUSE_SPACE_ID];
	char szDescriptions[MAX_LEN_BLK_SPACE_DESCRIPTION];
	BOOL	blCrossEBox; /* Don't fill it yourselves, it will decide by system */
	FLASHCACHE_WRITE_MODE cacheMode;
	char szCacheUUID[MAX_LEN_BLK_SPACE_PATH];
}SYNO_BLOCK_SPACE;

typedef struct _syno_block_lvm_ {
	BOOL blHasLVM;
	char szVgPath[MAX_LEN_BLK_VG_PATH];
	char szVgUUID[MAX_LEN_BLK_VG_UUID];
	u_int32_t designedPVcount;
} SYNO_BLOCK_LVM;

typedef struct _syno_block_raid_ {
	PSLIBSZLIST pslUUID;
} SYNO_BLOCK_RAID;

typedef struct _syno_block_ {
	char szMagic[MAX_LEN_BLK_MAGIC];
	u_int32_t version;
	SYNO_BLOCK_SPACE space;
	SYNO_BLOCK_LVM lvm;
	SYNO_BLOCK_RAID raid;
	char szRaidGroupLimit[MAX_LEN_BLK_RAID_GROUP_LIMIT]; // SZ_MAGIC_LIMIT_6/12/24
} SYNO_BLOCK;

typedef struct _space_lvname_parse_input_ {
	SYNO_BLOCK *pSYNOBlk;
	const char *szLvName;
	const char *szVgPath;
} SPACE_LVNAME_PARSE_INPUT;

typedef struct _space_lvname_get_input_ {
	const char *szReferencePath;
	const char *szVgPath;
	const char *szLvName;
} SPACE_LVNAME_GET_INPUT;

typedef struct _space_pool_add_lv_input_{
	const char *szVgPath;
	const char *szReferencePath;
	const char *szVolDesc;
	unsigned long long ullSize;
	const char *szLvName;
	BOOL isSingleSHR;
} SPACE_POOL_ADD_LV_INPUT;

/* Space Information */
typedef struct _space_status_ {
	int status;	// 0 means normal. >0 means abnormal. Use '&' with SPACE_ABNORMAL_STATUS to know detail.
	SPACE_BUILDING_TYPE buildType;
	SPACE_BUILDING_TASK task;
	SPACE_BUILDING_STEP step;
	unsigned long long ullDone;
	unsigned long long ullTotal;
	pid_t pid; //process pid of building
} SPACE_STATUS;

typedef enum _space_abnormal_status_ {
	SPACE_RAID_CRASHED=0x01,
	SPACE_RAID_DEGRADE=0x02,
	SPACE_LVM_CRASHED=0x04,
	SPACE_STOP_OPERATION=0x08, //e.g. during operation of create, delete, migrate.
	SPACE_CACHE_NOT_MOUNT=0x10,
	SPACE_VG_INCOMPLETE=0x20, // part of pv is unknown device
} SPACE_ABNORMAL_STATUS;

typedef struct _space_container_report_{
	SPACE_CONTAINER_TYPE cnrType;
	int internalDiskCount;
	int eboxDiskCount;
} SPACE_CONTAINER_REPORT;

typedef struct _space_info_ {
	char szPath[MAX_LEN_SPACE_PATH]; // e.g. /dev/md2, /dev/vg2/lv, /dev/vg1
	char szReferencePath[MAX_LEN_SPACE_REFERENCE_PATH]; // e.g. /volume1, LUN-1
	char szPoolPath[MAX_LEN_SPACE_PATH]; // If space is built-on storage pool, it means pool path, e.g. /dev/vg1. If not, it's the same with SPACE_INFO->szPath.
	char szSnapshotOrgPath[MAX_LEN_SPACE_SNAPSHOT_PATH]; //If no snapshot, the path is empty
	char szDrbdPath[MAX_LEN_DRBD_PATH]; //If no drbd, the path is empty. This path is also used as top virtual space path
	SPACE_DEV_TYPE devType;
	SPACE_DRIVE_TYPE driveType;
	SPACE_STATUS st;
	SPACE_CONTAINER_TYPE cnrType;
	SPACE_REFERENCE_TYPE spaceType;
	unsigned int cRedundantDisk; // only available in SHR, value is 1 or 2
	unsigned long long ullDevSize;	// size of RAID or LVM
	LVM_VG_INFO *pVGInfo; //LVM information. if NULL, means no LVM.
	RAID_INFO_LIST *pRAIDList; //RAID list information. if NULL, means no RAID.
	struct _space_info_ *pNext;
	int raidGroupLimitNum;
	char szUUID[MAX_LEN_UUID];
} SPACE_INFO;

typedef enum _space_trim_support_type_ {
	SPACE_TRIM_SUPPORT_UNKNOWN,
	SPACE_TRIM_NOT_SUPPORT,
	SPACE_TRIM_PARTIAL_SUPPORT, //support all raid type except raid4/5/6
	SPACE_TRIM_FULL_SUPPORT,
} SPACE_TRIM_SUPPORT_TYPE;

typedef struct _space_meta_ {
	char szSpacePath[MAX_LEN_SPACE_PATH];
	char szReuseSpaceID[MAX_LEN_BLK_REUSE_SPACE_ID];
	char szDescriptions[MAX_LEN_BLK_SPACE_DESCRIPTION];
	struct _space_meta_ *pNext;
} SPACE_META;

typedef struct _space_meta_filter_ {
	const char *szSpacePath;
	const char *szReuseSpaceID;
	const char *szDescriptions;
} SPACE_META_FILTER;

typedef struct _space_unuse_deploy_input_ {
	const char *szSpacePath;
	const char *szReferencePath;
	SPACE_INFO *pSpace;
	SPACE_REFERENCE_TYPE spaceType;
	FSTYPE fsType; // volume create reference for snapshot
} SPACE_UNUSE_DEPLOY_INPUT;

/* Space meta: SYNO-BLOCK and mapping-file */
typedef struct _space_synoblk_update_input_ {
	const SPACE_INFO *pSpace;
	const char *szAddDiskPath;
	const char *szAddRAIDPath;
	const char *szOrgRAIDUUID;
	const char *szNewRAIDUUID;
	PSLIBSZLIST pslAddDisks;
} SPACE_BLOCK_UPDATE_INPUT;

typedef enum _syno_block_init_type_ {
	BLOCK_INIT_CHG,				//Update synoblock when space info change
	BLOCK_INIT_CREATE,			//Update synoblock when space create
	BLOCK_INIT_NEW_VERSION_BLK,	//Update old synoblock to newest version
	BLOCK_INIT_VOL_NO_BLK,		//If space has no synoblock
	BLOCK_INIT_VOL_SINGLE_DISK,
	BLOCK_INIT_VOL_SINGLE_DISK_VDSM,
} SYNO_BLOCK_INIT_TYPE;

typedef struct _syno_block_init_params_ {
	SYNO_BLOCK_INIT_TYPE type;
	const SPACE_INFO *pSpace;
	const char *szRAIDPath;
	SYNO_BLOCK_SPACE space;
	SYNO_BLOCK_LVM lvm;
	PSLIBSZLIST pslRAIDUUID;
	PSLIBSZLIST pslRAIDPath;
	PSLIBSZLIST pslDiskPath;
	const char *szRAIDUUID;
	const char *szOrgDevPath;
	int raidGroupLimitNum;
} SYNO_BLOCK_INIT_PARAMS;

/* Space can-do disk limit check */
typedef struct _space_disk_limit_ {
	int maxDisks;	//-1 means no limit, >=0 means disk limit
	int minDisks;
	unsigned long long ullMinDiskSize; //bytes
}SPACE_DISK_LIMIT;

typedef struct _space_disk_layout_decide_params_ {
	unsigned int cRedundantDisk;
	SPACE_DEV_TYPE devType;
	PSLIBSZLIST pslDisks;
	const SPACE_INFO *pSpace;
	const RAID_INFO *pRAID;
	const RAID_LEVEL *pRAIDLevel;
	PARTITITON_LAYOUT_VERSION partLayoutVer;
	BOOL blNotReserveMoreAtTheEnd;
} SPACE_DISK_LAYOUT_PLAN_PARAMS;

/* Disk partition type for space */
typedef enum _space_partition_type_ {
	SPACE_PART_PRIMARY=1,// 2 system partitions, 1 primary data partition.
	SPACE_PART_LOGICAL,	  // 2 system partitions, 1 extended partition and >=1 logical data partitions.
	SPACE_PART_NONE				// No system partition and data partition.
} SPACE_PARTITION_TYPE;

typedef struct _space_partition_list_ {
	int partNo;					// -1 mean no partitions. primary must be 3, logical must start from 5
	unsigned long long ullSectors; // Partition size
	PSLIBSZLIST pslDisks;			// Disk path
	struct _space_partition_list_ *pNext;
	BOOL blUseRemaining;
} SPACE_PARTITION_LIST;

/*
 * Utils for searching space list.
 * If NULL means not to filter.
 */
typedef struct _space_filter_ {
	const char *szReferencePath;
	const char *szSpacePath;
	const char *szDiskPath;
	const char *szVgPath;
	const char *szVgUUID;
	const char *szRAIDPath;
	const char *szPoolPath;
	const SPACE_BUILDING_TYPE *pBuildType;
	unsigned int *pSpaceType;
} SPACE_FILTER;

/* RAID action done by space */
typedef struct _space_raid_action_ {
	char szRAIDPath[64];
	RAID_LEVEL raidLevel;
	SPACE_BUILDING_TASK task;
	PSLIBSZLIST pPartitions;
	unsigned long long ullPartSectors;
	struct _space_raid_action_ *pNext;
	char szReplacePath[64]; // replace a partition with another parition
} SPACE_RAID_ACTION;

/* SDK Parameters */
typedef struct _space_create_progress_ {
	SPACE_BUILDING_STEP step;
	PSLIBSZLIST pslBuildingDev;
} SPACE_CREATE_PROGRESS;

typedef struct _space_multi_diskgroup_input_ {
	PSLIBSZLIST pslDisks;
	void *pParams;
	struct _space_multi_diskgroup_input_ *pNext;
} SPACE_MULTI_DISKGROUP_INPUT;

typedef void (*PFuncFreeParams)(void *pParams);

typedef struct _space_create_input_ {
	SPACE_REFERENCE_TYPE referenceType;
	SPACE_DEV_TYPE devType;
	RAID_LEVEL raidlevel;
	unsigned int cRedundantDisk;  //only for SHR
	unsigned int cSpareDisk;  //only for custom RAID
	unsigned long long ullSize;  //only for lv, size in MB, 0 means use all remaining space
	BOOL isCheckDisk;
	BOOL blNotDumpMapFile;
	char szForceSpacePath[MAX_LEN_SPACE_PATH]; //now only useful for creating pool
	char szReferencePath[MAX_LEN_SPACE_REFERENCE_PATH];
	char szPoolPath[MAX_LEN_SPACE_PATH]; //only for lv
	char szDescriptions[MAX_LEN_BLK_SPACE_DESCRIPTION];
	char *szReuseSpaceID;
	PSLIBSZLIST pslDisks;
	PSLIBSZLIST pslForceRAIDPath;
	SPACE_MULTI_DISKGROUP_INPUT *pDiskGroup;
	int (*pfuncNotifyProgress)(const SPACE_CREATE_PROGRESS *);
	char szForceLvName[MAX_LEN_LVNAME]; // only for lun now
	int raidGroupLimitNum;
	FSTYPE fsType; // volume create reference for snapshot
} SPACE_CREATE_INPUT;

typedef struct _space_ssd_cache_create_input_ {
	RAID_LEVEL raidlevel;
	PSLIBSZLIST pslDisks;
	const char *szSpaceUUID;
	int (*pfuncNotifyProgress)(const SPACE_CREATE_PROGRESS *);
	const char *szForceRaidPath;
	FLASHCACHE_WRITE_MODE cacheMode;
} SPACE_SSDCACHE_CREATE_INPUT;

typedef struct _space_ssd_cache_info_filter_ {
	char *szReferencePath;
	char *szSpacePath;
	char *szSSDSpacePath;
} SPACE_SSDCACHE_FILTER;

typedef struct _space_add_disk_progress_ {
	SPACE_BUILDING_STEP step;
	PSLIBSZLIST pslBuildingDev;
	SPACE_INFO *pSpace;
} SPACE_ADD_DISK_PROGRESS;

typedef struct _space_add_disk_params_ {
	BOOL blCreateNewRAID;
	char szRAIDPath[MAX_LEN_RAID_PATH];
} SPACE_ADD_DISK_PARAMS;

typedef struct _space_create_params_ {
	char szRAIDPath[MAX_LEN_RAID_PATH];
} SPACE_CREATE_PARAMS;

typedef struct _space_add_disk_input_ {
	SPACE_INFO *pSpace;
	RAID_INFO *pRAID; // for old ebox RAID or Multiple RAID
	PSLIBSZLIST pslDisks;  //for adding disks
	unsigned int cSpareDisk;  //Specified how many spare disks
	unsigned long long ullSize;  //only for lv add size, size in MB, 0 means use all remaining space
	SPACE_MULTI_DISKGROUP_INPUT *pDiskGroup;
	int (*pfuncNotifyProgress)(const SPACE_ADD_DISK_PROGRESS *);
	int raidGroupLimitNum;
	BOOL blKeepOnline;
} SPACE_ADD_DISK_INPUT;

typedef struct _space_convert_shr_to_pool_input_ {
	SPACE_INFO *pSpace;
	PSLIBSZLIST pslDisks;  //for adding disks
	int (*pfuncNotifyProgress)(const SPACE_ADD_DISK_PROGRESS *);
	int (*pfuncUpdateSHRSpaceType)(const char *);
} SPACE_CONVERT_SHR_TO_POOL_INPUT;

typedef struct _space_migrate_1to5_input_ {
	SPACE_INFO *pSpace;
	RAID_INFO *pRAID;
	const char *sz1stDiskPath;
	const char *sz2stDiskPath;
	int (*pfuncNotifyProgress)(const SPACE_ADD_DISK_PROGRESS *);
} SPACE_MIGRATE_1TO5_INPUT;

typedef struct _space_estimate_size_params_ {
	char szSpacePath[MAX_LEN_SPACE_PATH];
	unsigned int cRedundantDisk;
	unsigned int cSpareDisk;
	SPACE_BUILDING_TASK task;
	SPACE_DEV_TYPE devType;
	RAID_LEVEL raidlevel;
	PSLIBSZLIST pslDisks;
	SPACE_INFO *pSpace;
	SPACE_MULTI_DISKGROUP_INPUT *pDiskGroup;
	char szReferencePath[MAX_LEN_SPACE_REFERENCE_PATH]; // e.g. /volume1, iSCSI_Lun_name, /dev/vg1
} SPACE_PARAMS_SIZE_ESTIMATE;

typedef struct _SPACE_SYSDEF_ADD_DISK_params_ {
	SPACE_BUILDING_TASK task;
	char szPath[MAX_LEN_SPACE_PATH];
	SPACE_REFERENCE_TYPE spaceType;
	PSLIBSZLIST pslDisks;
} SPACE_PARAMS_ADD_DISK;

typedef struct _SPACE_PARAMS_DISK_STATUS_params_ {
	const char *szDiskPath;
	const RAID_FOR_SYSTEM *pSysRAID;
	const SPACE_INFO *pSpaces;
} SPACE_PARAMS_DISK_STATUS;

typedef struct _SPACE_DISK_STATUS_params_ {
	char szDiskPath[64];
	char szSpacePath[MAX_LEN_SPACE_PATH];
	SPACE_REFERENCE_TYPE spaceType;
	int stType;	 //SPACE_DISK_STATUS_TYPE
} SPACE_DISK_STATUS;

typedef struct _space_mindisk_size_input_ {
	const SPACE_INFO *pSpace;
	const char *szRAIDPath;
	const PARTITITON_LAYOUT_VERSION *pPartlayout;
} SPACE_MINDISK_SIZE_INPUT;

/* Reserved size of disk */
enum _space_reserved_type_ {
	SPACE_RESERVED_LOGICAL_PARTITION=0x01,
	SPACE_RESERVED_SYNO_SYSTEM=0x02,
	SPACE_RESERVED_OVER_DISK_BOUND=0x04,
	SPACE_RESERVED_RAID_SUPERBLOCK=0x08,
};

typedef struct _space_reserved_caculate_params_ {
	int reservedType;
	unsigned long long ullSize;	// device size
	PARTITITON_LAYOUT_VERSION *pPartLayout;
} SPACE_RESERVED_SIZE_PARAMS;

/* Disk partition type for space */
typedef struct _SPACE_DISK_PARTITION_LAYOUT_ {
	int partNo;					// Partition number
	unsigned long long ullStartOffset; // sectors
	unsigned long long ullEndOffset;  // sectors
	unsigned long long ullTotalSectors;	// Total sectors
} SPACE_DISK_PARTITION_LAYOUT;

typedef struct _space_disk_size_tmp_ {
	char szDiskPath[32];
	unsigned long long ullTotalSectors;
	unsigned long long ullTotalSectorWithCyB; //with cylinder boundary
	unsigned long long ullUnallocSectors;
	unsigned long long ullAllocatableSectors;
} SPACE_DISK_SIZE;

/* Pool meta related */
#define SZ_POOL_MAGIC_SYNOBLOCK "SYNOLOGY_POOL_META_SUPER_BLOCK"
#define SZ_POOL_VG_RESERVED_AREA "syno_vg_reserved_area"
#define SIZE_POOL_VG_RESERVED 12 // MB
#define MAX_POOL_META_KEY 1024
#define MAX_POOL_META_VALUE 1024
#define MAX_POOL_META_BLK_MAGIC	64

typedef enum _space_pool_meta_version_{
	POOL_META_VERSION_1 = 1,
} SPACE_POOL_META_VERSION;

typedef struct _space_pool_meta_header_{ //order can not be changed
	char szMagic[MAX_POOL_META_BLK_MAGIC];
	u_int32_t version;
	u_int32_t counts;
} SPACE_POOL_META_HEADER;

typedef struct _space_pool_meta_body_v1_{
	char szKey[MAX_POOL_META_KEY];
	char szVal[MAX_POOL_META_VALUE];
} SPACE_POOL_META_BODY_V1;

typedef struct _space_pool_meta_info_{
	int fd;
	char szLvPath[MAX_LEN_LVPATH];
	SPACE_POOL_META_HEADER hdr;
} SPACE_POOL_META_INFO;

typedef struct _space_pool_meta_operator_{
	int (*pfuncMetaAdd) (SPACE_POOL_META_INFO *pMeta, const char *szKey, const char *szVal);
	int (*pfuncMetaGet) (SPACE_POOL_META_INFO *pMeta, const char *szKey, char *szVal, unsigned int cbVal);
	int (*pfuncMetaGetByVal) (SPACE_POOL_META_INFO *pMeta, const char *szVal, char *szKey, unsigned int cbKey);
	int (*pfuncMetaSet) (SPACE_POOL_META_INFO *pMeta, const char *szKey, const char *szVal);
	int (*pfuncMetaDelete) (SPACE_POOL_META_INFO *pMeta, const char *szKey);
	int (*pfuncMetaEnum) (SPACE_POOL_META_INFO *pMeta, PSLIBSZHASH *ppshMeta);
} SPACE_POOL_META_OPERATOR;

typedef struct _space_pool_meta_get_input_{
	const char *szKey;
	const char *szVal;
} SPACE_POOL_META_GET_INPUT;

typedef struct _space_lock_info_ {
	int semCnt;
	int semPID;
	int semWaiting;
} SPACE_LOCK_INFO;

typedef struct _space_disk_swap_list_ {
	int status;
	char *szPath;
	struct _space_disk_swap_list_ *pNext;
} SWAP_LIST;

enum _space_swap_device_todo_ {
	SWAP_NONE,
	SWAP_IGNORE,
	SWAP_ADD_TO_MD1
};

typedef enum _space_temp_device_method_ {
	TEMP_DEV_METHOD_NONE,
	TEMP_DEV_METHOD_SWAP,
	TEMP_DEV_METHOD_RAID,
} TEMP_DEV_METHOD;

#include <synostoragecore/space_p.h>

__END_DECLS;

#endif // __SYNO_STGCORE_SPACE_H__
