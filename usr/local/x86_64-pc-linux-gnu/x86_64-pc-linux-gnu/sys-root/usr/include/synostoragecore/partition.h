// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_PARTITION_H__
#define __SYNO_STGCORE_PARTITION_H__

#include <sys/cdefs.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

#include <synocore/list.h>
#include <hwctl/disk.h>
#include <hwctl/external.h>

__BEGIN_DECLS;

#define MAX_SYNO_DISK_PARTITION_NAME_LEN (128)

typedef enum _disk_partition_layout_type {
	SYNO_PARTITION_LAYOUT_NONEUSED = 0,
	SYNO_PARTITION_LAYOUT_NORMAL,
	SYNO_PARTITION_LAYOUT_SYNO,
	SYNO_PARTITION_LAYOUT_IPOD,
} SYNO_DISK_PARTITION_LAYOUT_TYPE;

typedef enum _disk_partition_type {
	SYNO_PARTITION_ROOT = 1,
	SYNO_PARTITION_REGULAR,
	SYNO_PARTITION_DATA_PARTITION,
	SYNO_PARTITION_IPOD,
} SYNO_DISK_PARTITION_TYPE;

typedef struct _disk_partition {
	int major;
	int minor;
	int iPartNumber;
	SYNO_DISK_PARTITION_TYPE iPartType;
	BOOL blMounted;
	unsigned long long ullBlockCount;
	char szDevName[MAX_SYNO_DISK_PARTITION_NAME_LEN];
	char szDevPartName[MAX_SYNO_DISK_PARTITION_NAME_LEN];
	char szFullPath[MAX_SYNO_DISK_PARTITION_NAME_LEN];
} SYNO_DISK_PARTITION, *PSYNO_DISK_PARTITION;

typedef struct _disk_partition_layout {
	SYNO_DISK_PARTITION_LAYOUT_TYPE iLayoutType;
	int partitionCount;
	char szDevName[MAX_SYNO_DISK_PARTITION_NAME_LEN];
	SYNO_DISK_PARTITION rgPartitions[MAX_SYNO_DISK_PARTITION_COUNT+1];
} SYNO_DISK_PARTITION_LAYOUT, *PSYNO_DISK_PARTITION_LAYOUT;

typedef struct {
	unsigned long long ullOffset; // in sectors
	unsigned long long ullSize;	// in sectors
	unsigned long ulfsId;
} SYNOPARTITION, *PSYNOPARTITION;

#define LAYOUT_PART_NUM 3
#define DATA_PARTITION_PRIMARY 3
#define DATA_PARTITION_EXTEND DATA_PARTITION_PRIMARY
#define DATA_PARTITION_LOGICAL_START 5
#define MAX_SYNO_DISK_PARTITIONS 15
#define MAX_SYNO_DISK_GPT_PARTITIONS 128
#define ALIGN_DISK_UNIT_KB 16
#define ALIGN_DISK_UNIT_SECTORS (ALIGN_DISK_UNIT_KB * 2)
#define ALIGN_DISK_OUT_BOUND(sector) (sector % ALIGN_DISK_UNIT_SECTORS)
#define ALIGN_DISK_SECTORS(sector) (sector - ALIGN_DISK_OUT_BOUND(sector))
#define ALIGN_CYLINDER_OUT_BOUND(sector) (sector % SYNORAID_PART_MBR_RESERVE)
#define ALIGN_CYLINDER_SECTORS(sector) (sector - ALIGN_CYLINDER_OUT_BOUND(sector))
#define ALIGN_EXTEND_PART_SECTORS(sector) ALIGN_DISK_SECTORS(ALIGN_CYLINDER_SECTORS(sector))

typedef struct {
	PARTITITON_LAYOUT_VERSION version;
	BOOL blRaidType;
	unsigned long long ullSize[LAYOUT_PART_NUM];
	SYNOPARTITION part[LAYOUT_PART_NUM];
	BOOL blBuildinStorage;
} SYNOPARTITIONLAYOUT, *PSYNOPARTITIONLAYOUT;

#define LAYOUT_VERSION_NUM 14
extern SYNOPARTITIONLAYOUT grgAllSynoPartLayout[LAYOUT_VERSION_NUM];

//new definition
#define PARTITION_TOOL "/sbin/sfdisk"

typedef enum _tag_partition_layout_ {
	PARTITION_SYSTEM = 0x01,
	PARTITION_DATA = 0x02,
	PARTITION_ALL = PARTITION_SYSTEM | PARTITION_DATA,
} PARTITION_LAYOUT;

typedef enum _tag_partition_table_ {
	PARTITION_UNKNOWN = 1,
	PARTITION_MBR,
	PARTITION_GPT,
} PARTITION_TABLE;

typedef enum _tag_partition_action_ {
	PARTITION_CREATE = 1,
	PARTITION_DELETE,
} PARTITION_ACTION;

typedef struct _tag_partition_filter_ {
	const char *szPrefix;	// please set this to NULL if you don't require a specific disk
	DEV_LOCATION loc;  //0 means no partition list
}PARTITION_FILTER;

typedef struct _tag_partition_option_ {
	int partitionNum;  // >=1
	int usageType;  // >=1
	unsigned long long ullReserveSectors;  // >0
	unsigned long long ullTotalSectors;  // >0
} PARTITION_OPTION;

#include <synostoragecore/partition_p.h>

__END_DECLS;

#endif // __SYNO_STGCORE_PARTITION_H__
