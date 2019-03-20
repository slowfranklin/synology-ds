/* Copyright (c) 2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_EP_H_
#define _SYNOISCSIEP_EP_H_

#include <synoiscsiep/iscsi.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_EP_DIR_NAME                     "EP"
#define ISCSI_EP_DIR_FORMAT                   "%s/" ISCSI_DIR_NAME "/" ISCSI_EP_DIR_NAME
#define ISCSI_EP_BUF_FILE_NAME                "EP_BUF"
#define ISCSI_EP_ROD_FILE_NAME                "EP_ROD"
#define ISCSI_EP_BUF_PATH_FORMAT              ISCSI_EP_DIR_FORMAT "/" ISCSI_EP_BUF_FILE_NAME
#define ISCSI_EP_ROD_PATH_FORMAT              ISCSI_EP_DIR_FORMAT "/" ISCSI_EP_ROD_FILE_NAME
#define ISCSI_EP_TRASH_DIR_NAME               "EP_unmap"
#define ISCSI_EP_TRASH_DIR_FORMAT             "%s/" ISCSI_DIR_NAME "/" ISCSI_EP_TRASH_DIR_NAME
#define ISCSI_EP_TRASH_PATH_FORMAT            ISCSI_EP_TRASH_DIR_FORMAT "/%s"

/*** constants ***/
#define ISCSI_EP_RODSP_KEY_SIZE               13
#define ISCSI_EP_SUPER_SIZE                   (1ULL << 20)
#define ISCSI_EP_SECTOR_BIT_SHIFT             9
#define ISCSI_EP_SECTOR_SIZE                  (1ULL << ISCSI_EP_SECTOR_BIT_SHIFT)
#define ISCSI_EP_MAP_ENTRY_SIZE               8
#define ISCSI_EP_EXTENT_SIZE_DEFAULT          8192

// EP meta data related define
#define ISCSI_EP_HEAD1_ATTR_CHILD             (0x00000001)
#define ISCSI_EP_HEAD1_ATTR_VIRTUAL           (0x00000002)
#define ISCSI_EP_HEAD1_ATTR_SINK_BIT          (0x00000004)
// TODO: should we remove child flags from source ?
#define ISCSI_EP_HEAD1_ATTR_NORMAL            (0x0)                                                                   // Non-cloned ADV LUN
#define ISCSI_EP_HEAD1_ATTR_VIRTUAL_SOURCE    (ISCSI_EP_HEAD1_ATTR_CHILD | ISCSI_EP_HEAD1_ATTR_VIRTUAL)               // Cloned LUN or snapshot
#define ISCSI_EP_HEAD1_ATTR_VIRTUAL_SINK      (ISCSI_EP_HEAD1_ATTR_VIRTUAL_SOURCE | ISCSI_EP_HEAD1_ATTR_SINK_BIT)     // Sink LUN
#define ISCSI_EP_HEAD1_ATTR_VIRTUAL_BIDI      (ISCSI_EP_HEAD1_ATTR_VIRTUAL_SOURCE | ISCSI_EP_HEAD1_ATTR_VIRTUAL_SINK)
#define ISCSI_EP_HEAD1_ATTR_VIRTUAL_MASK      (0x00000007)

/*** keys ***/

/*** etc ***/

/*** types ***/
typedef struct __iscsi_vaai_extent_pool_files_config
{
	int extent_size;
} ISCSI_EXTENTPOOL_FILES_CONFIG;

/*** macro or inline functions ***/

/*** function declarations ***/
int  SYNOiSCSIEpChildLunSyncProgressGet(const char *szFullPath, uint64_t *pParentTotalCount, uint64_t *pSyncedCount);
int  SYNOiSCSIEpExtentSizeAndShiftGet(const char *szRootPath, int *pextent_size, int *pextent_size_bit_shift);
int  SYNOiSCSIEpFileUuidGet(const char *szPath, char *szUUID);
int  SYNOiSCSIEpJournalRootPathChange(const char *szNewRootPath);
int  SYNOiSCSIEpJournalRootPathGet(char *szJournalRootPath, int cLen, bool blDefault);
int  SYNOiSCSIEpMapFileAttributeSet(const char *szPath, uint32_t attrib);
int  SYNOiSCSIEpMapFileBaseVersionGet(const char *szPath, char *szTrackVersion);
int  SYNOiSCSIEpMapFileMappedSizeGet(const char *szPath, const char *szRootPath, uint64_t *pMappedSize);
int  SYNOiSCSIEpMapFileSyncedCountGet(const char *szPath, uint64_t *pSyncCnt);
int  SYNOiSCSIEpMapFileTotalCountGet(const char *szPath, uint64_t *pTotalCount);
int  SYNOiSCSIEpMapFileVersionInfoGet(const char *szPath, ISCSI_VERSION_INFO *versionInfo);
int  SYNOiSCSIEpMetaFilesCreate(const char *szVolPath, ISCSI_EXTENTPOOL_FILES_CONFIG *pConfig);
int  SYNOiSCSIEpMetaFilesPin(const char *szVolPath, bool force);
int  SYNOiSCSIEpMetaFilesPrealloc(const char *szVolPath);
int  SYNOiSCSIEpRodKeyGet(char *szKey, size_t cbKey);
int  SYNOiSCSIEpUsedSpaceGet(const char *szRootPath, uint64_t *u64EPPoolUsed);

// For compatibility in project: libsynodr
#define SYNOExtentPoolFileUUIDGet(szPath, szUUID) SYNOiSCSIEpFileUuidGet(szPath, szUUID)

__END_DECLS

#endif // _SYNOISCSIEP_EP_H_
