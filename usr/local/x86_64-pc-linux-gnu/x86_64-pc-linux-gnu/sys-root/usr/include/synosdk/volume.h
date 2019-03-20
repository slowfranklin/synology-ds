// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_VOLUME_H__
#define __SYNO_VOLUME_H__

#include <sys/cdefs.h>
#include <sys/statfs.h>

#include <synocore/synotype.h>

#include <synosdk/fs.h>
#include <synosdk/plugin.h>
#include <synocore/file.h>

__BEGIN_DECLS;

/**
 * @addtogroup VOLUME
 *
 * @brief The structure and operation of Volume. More features in libsynostoragecore.
 *
 * @{
 */

typedef enum _tag_VOL_STATUS {
	VOL_STATUS_NORMAL = 1,
	VOL_STATUS_CRASH = 2,
} VOL_STATUS;

typedef enum _tag_VOL_TASK {
	VOL_TASK_NONE = 1,
	VOL_TASK_BUILDING = 2,
} VOL_TASK;

typedef struct _tag_VOL_TAB_ENT {
	char szDevPath[128];
	char szMntPoint[128];
	VOL_STATUS status;
	VOL_TASK task;
	SPACE_CONTAINER_TYPE cnrType;
	DEV_LOCATION loc;
	struct _tag_VOL_TAB_ENT *pNext;
} VOL_TAB_ENT;

typedef int (*PFUNC_VOL_TAB_ENT_SELECTOR)(const VOL_TAB_ENT *pVolTabEnt, void *pData);
typedef struct {
	PFUNC_VOL_TAB_ENT_SELECTOR pSelector;
	void *pData;
} VOLTABENUMFUNC, *PVOLTABENUMFUNC;

typedef enum _tag_VOL_TAB_ENUM_FUNCTION_RET {
	/** select the volume table entry */
	VOL_TAB_ENUM_SELECT,
	/** not select the volume table entry */
	VOL_TAB_ENUM_NOT_SELECT,
	/** stop select and return success */
	VOL_TAB_ENUM_SUCCESS_STOP,
	/** stop select and return error */
	VOL_TAB_ENUM_ERROR_STOP
} VOL_TAB_ENUM_FUNCTION_RET;

typedef struct {
	/** Volume ID */
	int             svi_id;
	/** Volume Location */
	DEV_LOCATION    svi_loc;
	/** Space container type */
	SPACE_CONTAINER_TYPE svi_cnrtype;
	/** File system type */
	FSTYPE          svi_fsType;
	/** Underlying device node path */
	char            svi_devpath[32];
	/** Indicate if volume is mounted */
	int             svi_mounted;
	/** mountpath, if mounted */
	char            svi_mountpoint[32];
	unsigned long long svi_freesize;
	unsigned long long svi_totalsize;
	/** if volume is read-only or writeable */
	int                svi_writeable;
} SYNOVOLInfo, *PSYNOVOLInfo;

enum{
	VOLUME_NOT_MOUNTED = 0,
	VOLUME_MOUNTED,
};

typedef struct tag_SYNOVOLINFOLIST {
	SYNOVOLInfo sInfo;
	struct tag_SYNOVOLINFOLIST *next;
} SYNOVOLINFOLIST;

typedef struct {
	BOOL *pIsWritable;
	int *pLoc;
	char *szVolPath;
} SYNOVOL_FILTER;

#define SZ_VOL_TMPDIR "@tmp"
#define RESERVE_DATA_NO        FALSE
#define RESERVE_DATA            TRUE

#define SZF_MOUNT "/bin/mount"
#define SZD_RUN_SYNOSTORAGE "/run/synostorage"
#define SZF_VOLUME_TABLE SZD_RUN_SYNOSTORAGE"/volumetab"
#define SZF_VOLUME_TABLE_TMP SZF_VOLUME_TABLE".tmp"
#define SZV_VOLUME_STATUS_NORMAL "normal"
#define SZV_VOLUME_STATUS_CRASH "crashed"
#define SZV_VOLUME_TASK_BUILDING "building"
#define SZV_VOLUME_TASK_NOT_BUILDING "not-building"
#define SZV_VOLUME_LOC_INTERNAL "loc-internal"
#define SZV_VOLUME_LOC_USB "loc-usb"
#define SZV_VOLUME_LOC_ESATA "loc-esata"
#define SZV_VOLUME_LOC_EUNIT "loc-eunit"
#define SZV_VOLUME_CNRTYPE_CROSS "cnr-cross"
#define SZV_VOLUME_CNRTYPE_INTERNAL "cnr-internal"
#define SZV_VOLUME_CNRTYPE_EUNIT "cnr-eunit"
#define SZV_VOLUME_CNRTYPE_NONE "cnr-none"

#define VOLUME_TABLE_COLUMN_NUMBER 6
#define VOLUME_TABLE_DEV_PATH_COLUMN_IDX 0
#define VOLUME_TABLE_MNT_POINT_COLUMN_IDX 1
#define VOLUME_TABLE_STATUS_COLUMN_IDX 2
#define VOLUME_TABLE_TASK_COLUMN_IDX 3
#define VOLUME_TABLE_LOC_COLUMN_IDX 4
#define VOLUME_TABLE_CNR_TYPE_COLUMN_IDX 5

#define EACH_VOLUME(vol) for (; vol; vol = vol->next)

typedef struct {
	int id;
	DEV_LOCATION loc;
} VOL_ID;

typedef struct {
	char szPath[128];
	DEV_LOCATION loc;
} VOL_INFO;

typedef enum _tag_vol_unavail_status_ {
	VOL_BUILDING_FOREGROUND=0x01,
	VOL_NOT_FOUND=0x02,
	VOL_NOT_ENOUGH_SPACE=0x04,
	VOL_READONLY=0x08,
	VOL_UNMOUNTED=0x10,
	VOL_CRASH=0x20
} VOL_UNAVAIL_STATUS;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/volume_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_VOLUME_H__
