// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_VOLUME_H__
#define __SYNO_STGCORE_VOLUME_H__

#include <synosdk/fs.h>
#include <synosdk/plugin.h>
#include <synostoragecore/space.h>
//#include <hwctl/disk.h>
//#include <hwctl/external.h>

__BEGIN_DECLS;

#define SYNO_FORMAT_VOL_OPT ""
#define SZF_FILESYSTEM_CACHE "/tmp/space/cache_filesystem_info"

#define SZV_RELATIME "relatime"
#define SZV_RELATIME_MONTHLY "monthly"
#define SZV_NOATIME "noatime"

typedef struct tag_SYNOVOL_FS_CACHE_FILETER {
    const char *szMountDevPath;
} SYNOVOL_FS_CACHE_FILETER;

typedef struct tag_SYNOVOL_FS_CACHE_INFO {
    char *szMountDevPath;
    BOOL isExpansible;
    BOOL is64Bit;
    struct tag_SYNOVOL_FS_CACHE_INFO *pNext;
	unsigned long long ullExpansibleSizeLimit;
} SYNOVOL_FS_CACHE_INFO;

typedef enum _tag_SYNO_USBVOL_STATE {
    STATE_NORMAL = 0,
    STATE_FATCORRUPT,
    STATE_HDDFAIL,
} USBVOL_STATE;

typedef struct _tag_SYNO_USBVOL_INFO_ {
    int64_t cmbtotal;
    int64_t cmbused;
    USBVOL_STATE status;    /* status of this disk */
    char szShareName[128];  /* share name */
    char szSharePath[128];  /* share path */
    char szFSName[64];  /* file system name. e.g. fat, ext3... */
    char szName[64];    /* name of the external disk. for example: "USB disk 1" */
    char szPath[128];   /* path of the mount point */
} SYNOUSBVOLINFO, *PSYNOUSBVOLINFO;

typedef struct _tag_SYNO_PARTITION_SHARE_INFO_ {
	//replace the section describ in SYNOUSBVOLINFO
	int part_no;
	int64_t cmbtotal;
	int64_t cmbused;
	USBVOL_STATE status;    /* status of this disk */
	char szShareName[128];  /* share name */
	char szSharePath[128];  /* share path */
	char szFSName[64];  /* file system name. e.g. fat, ext3... */
	char szName[64];    /* name of the external disk. for example: "USB disk 1" */
	char szPath[128];   /* path of the mount point */
	BOOL blMounted;
} SYNOPARTSHAREINFO, *PSYNOPARTSHAREINFO;

typedef struct _tag_SYNO_PARTITION_VOL_INFO_ {
	int64_t cmbtotal;
	int64_t cmbused;
	USBVOL_STATE status;    /* status of this disk */
	BOOL blBackup;
	unsigned int uiPartShareCnt;/*indicate count of part-share info. of this disk.*/
	int noSerial;
	char szName[64];    /* name of the external disk. for example: "USB disk 1" */
	char szShareName[128];
	char szSharePath[128];  /* share path */
	char szFSName[64];  /* file system name. e.g. fat, ext3... */
	char szPath[128];   /* path of the mount point */
	char *pszShareName[MAX_SYNO_DISK_PARTITION_COUNT+1]; //point to rgPartShareInfo->szShareName
	SYNOPARTSHAREINFO rgPartShareInfo[MAX_SYNO_DISK_PARTITION_COUNT];
} SYNOPARTVOLINFO, *PSYNOPARTVOLINFO;

typedef struct _tag_SYNO_VOL_PLUGIN_BASIC_ARG_LIST_ {
	char szDevice[128];
	char szMountPoint[128];
	char szFsType[32]; // e.g. "ext4", "btrfs"
	char szLocation[32]; // e.g. "INTERNAL", "EUNIT", "USB", "ESATA"
	FSTYPE fsType;
	struct _tag_SYNO_VOL_PLUGIN_BASIC_ARG_LIST_ *pNext;
} SYNOVOLPLUGARG;

typedef struct _tag_SYNO_VOL_CONF {
	char szAtimeOpt[16];	// "relatime", "monthly", "noatime"
	BOOL blAtimeChecked;	// Whether the volume was suggested to turn off relatime before
} SYNOVOLCONF, *PSYNOVOLCONF;

#include <synostoragecore/volume_p.h>

__END_DECLS;

#endif
