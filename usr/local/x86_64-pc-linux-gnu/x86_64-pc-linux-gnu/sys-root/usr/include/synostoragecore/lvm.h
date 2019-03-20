// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_LVM_H__
#define __SYNO_STGCORE_LVM_H__

#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include <synosdk/plugin.h>

__BEGIN_DECLS;

#define SZD_LVM_VG "vg"
#define PATH_LVM_STATUS "/tmp/lvm.status"
#define PATH_LVM_CONF "/etc/lvm.conf"
#define PATH_LVM_VG "/dev/" SZD_LVM_VG
#define SZD_LVM_LV "lv"
#define SZD_DEV_MAPPER "/dev/mapper"
#define SZD_UUID "uuid"
#define SZD_PVS_OPTION "pv_name,vg_name,vg_uuid,pv_count"
#define PATH_PVS "/sbin/pvs"
#define PATH_LVM "/sbin/lvm"
#define PATH_PVRESIZE "/sbin/pvresize"
#define PATH_VGEXTEND "/sbin/vgextend"
#define PATH_VGREDUCE "/sbin/vgreduce"
#define PATH_LVRESIZE "/sbin/lvextend"
#define MAX_LEN_VGNAME 64
#define MAX_LEN_VGPATH 128
#define MAX_LEN_VGUUID 256
#define MAX_LEN_LVNAME 128
#define MAX_LEN_LVPATH (MAX_LEN_VGPATH + MAX_LEN_LVNAME + 1)
#define MAX_LEN_LV_MAPPER_PATH (MAX_LEN_VGPATH + MAX_LEN_LVNAME + 12 + 1) // /dev/mapper/
#define MAX_LEN_LV_REFERENCE_PATH 1024
#define NUM_VG_ID_START 1
#define NUM_LVM_SHR_VG_START 1000
#define MAX_VG_ID 2048

#define LVM_VG_PESIZE 4ULL //MB
#define LVM_VG_PERM (S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)//755
#define PV_META_DATA_SIZE_KB (ALIGN_DISK_UNIT_KB * 32)

#define SZ_VGS_OPTION "--noheading", "-o", "vg_name,vg_uuid,vg_size,vg_free,vg_extent_size", "--separator", "|", "--unit", "b"

#define EACH_LV(lv) EACH_ELEMENT(lv)
#define EACH_VG(vg) EACH_ELEMENT(vg)
#define EACH_PV(pv, idx) EACH_LIST_MEMBER(pv, idx)

/* PV related */
typedef enum _lvm_lv_reference_type_ {
	LVM_LV_VOLUME=0x01,
	LVM_LV_ISCSI=0x02,
} LVM_LV_REFERENCE_TYPE;

typedef struct _tag_lvm_path_info_{
	unsigned int vgID;
	char szVgPath[MAX_LEN_VGPATH];
	char szVgName[MAX_LEN_VGNAME];
	char szLvName[MAX_LEN_LVPATH];
} LVM_PATH_INFO;

typedef struct _tag_pv_superblock_{
	char szPvPath[128];
	char szVgPath[MAX_LEN_VGPATH];
	char szVgUUID[MAX_LEN_VGUUID];
	int designedPVCount;
} LVM_PV_SB; //superblock

typedef struct _tag_pv_superblock_list_{
	LVM_PV_SB *pSB;
	struct _tag_pv_superblock_list_ *pNext;
} LVM_PV_SB_LIST;

/* LV related */
typedef struct _tag_lv_info_{
	char szName[MAX_LEN_LVNAME]; //lv name
	char szPath[MAX_LEN_LVPATH]; //lv full path
	char szUUID[MAX_LEN_VGUUID];
	char szMapperPath[MAX_LEN_LV_MAPPER_PATH]; // /dev/mapper/vg1-lv
	char szReferencePath[MAX_LEN_LV_REFERENCE_PATH]; // /volume1, LUN-1
	LVM_LV_REFERENCE_TYPE referenceType;
	unsigned long long ullSize;  //bytes
	struct _tag_lv_info_ *pNext;
} LVM_LV_INFO;

/* VG related */
typedef struct _tag_vg_info_{
	unsigned int counter;
	char szName[MAX_LEN_VGNAME]; //vg path
	char szPath[MAX_LEN_VGPATH]; //vg path
	char szUUID[MAX_LEN_VGUUID]; //vg uuid
	int designedPVcount;
	unsigned long long ullTotalSize;  //bytes
	unsigned long long ullFreeSize;  //bytes
	unsigned long long ullPeSize;  //bytes
	BOOL blActive;
	PSLIBSZLIST pPVPathList;
	LVM_LV_INFO *pLVInfoList; // single volune does not have this info (see SYNOSpaceInfoFilter)
	struct _tag_vg_info_ *pNext;
	BOOL blExpansible;
	unsigned long long ullMaxSizeKB;
} LVM_VG_INFO;

typedef struct _tag_vg_superblock_{
	char szName[MAX_LEN_VGNAME];
	char szPath[MAX_LEN_VGPATH]; //vg path
	char szVgUUID[MAX_LEN_VGUUID];
	unsigned long long ullTotalSize; //bytes
	unsigned long long ullFreeSize; //bytes
	unsigned long long ullPeSize;  //bytes
	PSLIBSZLIST pPVPath;
	LVM_LV_INFO *pLVInfoList;
} LVM_VG_SB; //superblock

typedef struct _tag_vg_superblock_list_{
	LVM_VG_SB *pSB; // VG Info
	struct _tag_vg_superblock_list_ *pNext;
} LVM_VG_SB_LIST;

typedef struct _tag_vg_search_param_{
	const char *szVgUUID;
	const char *szPvPath;
} LVM_VG_SEARCH_PARAM;

static inline void RemoveSlashN(char *szLine)
{
	char *pSlashN = NULL;

	if (szLine && (NULL != (pSlashN = strchr(szLine, '\n')))) {
		*pSlashN = '\0';
	}
}

#include <synostoragecore/lvm_p.h>

__END_DECLS;

#endif // __SYNO_STGCORE_LVM_H__
