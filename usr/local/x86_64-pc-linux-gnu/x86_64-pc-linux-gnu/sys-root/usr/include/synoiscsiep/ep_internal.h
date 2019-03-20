/* Copyright (c) 2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_EP_INTERNAL_H_
#define _SYNOISCSIEP_EP_INTERNAL_H_

#include <synoiscsiep/ep.h>
#include <synoiscsiep/iscsi_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_EP_TRASH_CLEAN_BLOCK            "/tmp/ep_trash_clean_block"
#define ISCSI_EP_DIR_FORMAT_VOL_ID            "/volume%d/" ISCSI_DIR_NAME "/" ISCSI_EP_DIR_NAME
#define ISCSI_EP_CFS_TRASH_PATH_FORMAT        "%s/UNMAP_%s"
#define ISCSI_EP_JNL_FILE_NAME                "EP_JNL"
#define ISCSI_EP_TBL_FILE_NAME                "EP_TBL"
#define ISCSI_EP_FRI_FILE_NAME                "EP_FRI"
#define ISCSI_EP_DAT_FILE_NAME                "EP_DAT"
#define ISCSI_EP_TBL_PATH_FORMAT              ISCSI_EP_DIR_FORMAT "/" ISCSI_EP_TBL_FILE_NAME
#define ISCSI_EP_FRI_PATH_FORMAT              ISCSI_EP_DIR_FORMAT "/" ISCSI_EP_FRI_FILE_NAME
#define ISCSI_EP_DAT_PATH_FORMAT              ISCSI_EP_DIR_FORMAT "/" ISCSI_EP_DAT_FILE_NAME "_%05d"
#define ISCSI_EP_TBL_PATH_FORMAT_VOL_ID       ISCSI_EP_DIR_FORMAT_VOL_ID "/" ISCSI_EP_TBL_FILE_NAME
#define ISCSI_EP_FRI_PATH_FORMAT_VOL_ID       ISCSI_EP_DIR_FORMAT_VOL_ID "/" ISCSI_EP_FRI_FILE_NAME
#define ISCSI_EP_DAT_PATH_FORMAT_VOL_ID       ISCSI_EP_DIR_FORMAT_VOL_ID "/" ISCSI_EP_DAT_FILE_NAME  "_%05d"
#define ISCSI_EP_BUF_PATH_FORMAT_VOL_ID       ISCSI_EP_DIR_FORMAT_VOL_ID "/" ISCSI_EP_BUF_FILE_NAME
#define ISCSI_EP_ROD_PATH_FORMAT_VOL_ID       ISCSI_EP_DIR_FORMAT_VOL_ID "/" ISCSI_EP_ROD_FILE_NAME
#define ISCSI_EP_JNL_DEFAULT_ROOT_PATH        "/var/db/iscsi"
#define ISCSI_EP_JNL_ROOT_PATH_KRY            "vaai_journal_rootpath"
#define ISCSI_EP_JNL_FILE_SIZE_KEY            "vaai_journal_size_in_megabyte"
#define ISCSI_EP_CONFIGFS_ROOT                ISCSI_CONFIGFS_ROOT_PATH "/pool"
#define ISCSI_EP_CONFIGFS_DIR_NAME            "EP_%d"
#define ISCSI_EP_CONFIGFS_DIR_PATH_FORMAT     ISCSI_EP_CONFIGFS_ROOT "/" ISCSI_EP_CONFIGFS_DIR_NAME

/*** constants ***/
#define ISCSI_EP_HEADER_MAX_SIZE              4096
#define ISCSI_EP_DEFAULT_JNL_SIZE_IN_MBYTES   64
#define ISCSI_EP_VERSION_MAJOR                1
#define ISCSI_EP_VERSION_MINOR                0
#define ISCSI_EP_VERSION                      ((ISCSI_EP_VERSION_MAJOR << 16) + ISCSI_EP_VERSION_MINOR)
#define ISCSI_EP_MAGIC_CODE                   0x0886255218140633ULL
#define ISCSI_EP_DEFALUT_TBL_SIZE             (1ULL << 42)	//2^42 = 4T
#define ISCSI_EP_DEFALUT_FRI_SIZE             (1ULL << 32)	//2^32 = 4G
#define ISCSI_EP_TBL_ENTRY_SIZE               2
#define ISCSI_EP_FRI_ENTRY_SIZE               8
#define ISCSI_EP_TBL_LIST_SIZE                4096
#define ISCSI_EP_HEAD_CHECKSUM_SIZE           4
#define ISCSI_EP_HEAD_PADDING_SIZE            4
#define ISCSI_EP_FRI_ENTRY_PER_SECTOR         ((ISCSI_EP_SECTOR_SIZE - ISCSI_EP_HEAD_CHECKSUM_SIZE - ISCSI_EP_HEAD_PADDING_SIZE)/ ISCSI_EP_FRI_ENTRY_SIZE)
#define ISCSI_EP_TBL_ENTRY_PER_SECTOR         (ISCSI_EP_FRI_ENTRY_PER_SECTOR * 4)	//this value should be multiple of ISCSI_EP_FRI_ENTRY_PER_SECTOR
#define ISCSI_EP_MAP_ENTRY_PER_SECTOR         ((ISCSI_EP_SECTOR_SIZE - ISCSI_EP_HEAD_CHECKSUM_SIZE - ISCSI_EP_HEAD_PADDING_SIZE)/ ISCSI_EP_MAP_ENTRY_SIZE)
#define ISCSI_EP_TOTAL_FREE_COUNT             ((ISCSI_EP_DEFALUT_TBL_SIZE / ISCSI_EP_SECTOR_SIZE) * ISCSI_EP_TBL_ENTRY_PER_SECTOR)
#define ISCSI_EP_GROUP_COUNT                  (ISCSI_EP_TOTAL_FREE_COUNT / ISCSI_EP_TBL_LIST_SIZE)
#define ISCSI_EP_EXTENT_SIZE_MIN              (4 * 1024)
#define ISCSI_EP_EXTENT_SIZE_MAX              (16 * 1024 * 1024)
#define ISCSI_EP_MAX_FILE_SIZE                (4ULL << 50) //1P = 2^50
#define ISCSI_EP_MAX_UNMAP_BUF_SIZE           (1ULL << 52) //2^52 = 4P
#define ISCSI_EP_UNMAP_BUF_SPACE_REQUIREMENT  (1ULL << 30) //1G
#define ISCSI_EP_MAX_ROD_SIZE                 (1ULL << 52) //2^52 = 4P
#define ISCSI_EP_ROD_SPACE_REQUIREMENT        (1ULL << 30) //1G

// EP File Child Attribute
#define ISCSI_EP_VAR2_CHILD_ATTR_CHILD        0x00000001
#define ISCSI_EP_VAR2_CHILD_ATTR_MIRROR       0x00000002
#define ISCSI_EP_VAR2_CHILD_ATTR_PROMOTED     0x00000004
#define ISCSI_EP_VAR2_CHILD_ATTR_FULL_TRACK   0x00000100
#define ISCSI_EP_VAR2_CHILD_ATTR_CBT_CHANGED  0x00000200

/*** keys ***/
#define ISCSI_EP_CHILD_CLONE_ONGOING          "clone_ongoing"

/*** etc ***/

/*** types ***/
typedef enum _tag_ep_file_type_ {
	EP_FILE_TYPE_TBL = 0x01,
	EP_FILE_TYPE_FRI = 0x02,
	EP_FILE_TYPE_DAT = 0x03,
	EP_FILE_TYPE_MAP = 0x04,
	EP_FILE_TYPE_JNL = 0x05
} EP_FILE_TYPE;

typedef struct {
	uint32_t checksum;
	uint32_t version;
	uint64_t magicCode;
	uint32_t type;
	uint8_t uuid[ISCSI_UUID_SIZE];
	uint64_t dataStartOffset;
	uint32_t createTime;
	uint8_t reserved[16];
} __attribute__((packed)) EPFILE_HEADER;

typedef struct {
	uint32_t checksum;
	uint32_t attribute;
	uint32_t blockSize;
	uint64_t totalCount;
	uint8_t parentUUID[ISCSI_UUID_SIZE];
	uint64_t parentTotalCount;
	uint8_t reserved[20];
} __attribute__((packed)) EPFILE_MAP_HEADER;

typedef struct {
	uint32_t checksum;
	uint64_t mappedCount;
	uint8_t reserved[52];
} __attribute__((packed)) EPFILE_MAP_VAR0;

typedef struct {
	uint32_t checksum;
	uint32_t metaSeg0Checksum;
	uint32_t metaSeg0PoolCount;
	uint8_t session_uuid[ISCSI_UUID_SIZE];
	uint32_t promotion_time;
	uint8_t reserved[32];
} __attribute__((packed)) EPFILE_MAP_VAR1;

typedef struct {
	uint32_t checksum;
	uint64_t syncCount;
	uint32_t child_attr;
	uint8_t base_version[ISCSI_UUID_SIZE];
	uint8_t previous_version[ISCSI_UUID_SIZE];
	uint8_t current_version[ISCSI_UUID_SIZE];
} __attribute__((packed)) EPFILE_MAP_VAR2;

typedef struct {
	uint32_t checksum;
	uint32_t extentSize;
	uint32_t entrySize;
	uint64_t totalCount;
	uint8_t reserved[44];
} __attribute__((packed)) EPFILE_TBL_HEADER;

typedef struct {
	uint32_t checksum;
	uint32_t entrySize;
	uint32_t totalGroupCount;
	uint8_t reserved[52];
} __attribute__((packed)) EPFILE_FRI_HEADER;

typedef struct {
	uint32_t checksum;
	uint64_t totalFreeCount;
	uint64_t indexHead;
	uint8_t reserved[44];
} __attribute__((packed)) EPFILE_FRI_VAR0;

typedef struct {
	uint32_t checksum;
	uint32_t serialNum;
	uint8_t reserved[56];
} __attribute__((packed)) EPFILE_DAT_HEADER;

typedef struct {
	uint32_t checksum;
	uint64_t totalCount;
	uint8_t reserved[52];
} __attribute__((packed)) EPFILE_JNL_HEADER;

typedef struct {
	uint32_t checksum;
	uint32_t shutdownTag;
	uint32_t syncCount;
	uint8_t  compression;
	uint8_t  reserved[51];
} __attribute__((packed)) EPFILE_JNL_VAR0;

typedef struct {
	uint32_t checksum;
	uint32_t lastTransID;
	uint64_t lastRecoedStart;
	uint32_t lastFlushError;
	uint32_t lastRecoveryError;
	uint64_t emptyRecordStart;
	uint8_t reserved[32];
} __attribute__((packed)) EPFILE_JNL_VAR1;

typedef struct {
	EPFILE_HEADER     header0;
	EPFILE_MAP_HEADER header1;
	uint8_t reserved[ISCSI_EP_HEADER_MAX_SIZE - sizeof(EPFILE_HEADER) - sizeof(EPFILE_MAP_HEADER)];
	EPFILE_MAP_VAR0   var0;
	EPFILE_MAP_VAR1   var1;
	EPFILE_MAP_VAR2   var2;
} __attribute__((packed)) EPFILE_MAP;

/*** macro or inline functions ***/
//EP macro for file size translation
static inline uint64_t ep_size_to_lea_cnt(uint64_t x, uint32_t extent_size_bit_shift) { return x >> extent_size_bit_shift; }
static inline uint64_t ep_lea_cnt_to_sector_cnt(uint64_t x) { return (x + (ISCSI_EP_MAP_ENTRY_PER_SECTOR - 1)) / ISCSI_EP_MAP_ENTRY_PER_SECTOR; }
static inline uint64_t ep_sector_cnt_to_bytes(uint64_t x) { return x << ISCSI_EP_SECTOR_BIT_SHIFT; }
static inline uint64_t ep_bytes_to_sector_cnt(uint64_t x) { return x >> ISCSI_EP_SECTOR_BIT_SHIFT; }
static inline uint64_t ep_sector_cnt_to_lea_cnt(uint64_t x) { return x * ISCSI_EP_MAP_ENTRY_PER_SECTOR; }
static inline uint64_t ep_lea_cnt_to_size(uint64_t x, uint32_t extent_size_bit_shift) { return x << extent_size_bit_shift; }
static inline uint64_t ep_map_file_size(uint64_t usersize, uint32_t extent_size_bit_shift) {
	return ep_sector_cnt_to_bytes(ep_lea_cnt_to_sector_cnt(ep_size_to_lea_cnt(usersize, extent_size_bit_shift))) + ISCSI_EP_SUPER_SIZE;
}

static inline bool is_valid_extent_size(uint32_t extent_size)
{
	//check if it's in range and if it's pow of 2
	return (ISCSI_EP_EXTENT_SIZE_MIN <= extent_size && ISCSI_EP_EXTENT_SIZE_MAX >= extent_size &&
		((extent_size != 0) && !(extent_size & (extent_size - 1))));
}

static inline int SYNOiSCSIEpTBLPath(const char *szVolPath, char *szPath, size_t cbPath)
{
	const int sret = snprintf(szPath, cbPath, ISCSI_EP_TBL_PATH_FORMAT, szVolPath);
	if (0 > sret || (int)cbPath <= sret) {
		ISCSIERR("snprintf() failed with buffer size %zu", cbPath);
		return -1;
	}
	return 0;
}

/*** function declarations ***/
bool SYNOiSCSIEpChildLunIsMirror(const char *szFullPath);
bool SYNOiSCSIEpChildLunIsPromoted(const char *szFullPath);
int  SYNOiSCSIEpCloneFileTrunc(const char *szSrcFilePath, const char *szDstFilePath, uint64_t u64TruncSize, char *uuid, time_t createTime);
int  SYNOiSCSIEpCloneMapMetaDataFillUp(const char *szSrcFilePath, const char *szDstFilePath, char *szUUID, time_t createTime);
int  SYNOiSCSIEpCreateRod(const int volId);
int  SYNOiSCSIEpDisable(const int volId);
int  SYNOiSCSIEpEnable(const int volId);
int  SYNOiSCSIEpExtentPoolLoad(const char *szFilePath, const char *szUUID, const bool blLoadVsys, const bool blTrash);
int  SYNOiSCSIEpFileCreateTimeGet(const char *szPath, time_t *pCreateTime);
int  SYNOiSCSIEpFileHeaderFill(const char *szPath, char *szUUID, EP_FILE_TYPE EPFileType, time_t createTime);
int  SYNOiSCSIEpFileHeaderGet(const char *szPath, EPFILE_HEADER *pBuf);
int  SYNOiSCSIEpFileHeaderSet(const char *szPath, const EPFILE_HEADER *pBuf);
int  SYNOiSCSIEpFileMapHeaderGet(const char *szPath, EPFILE_MAP_HEADER *pBuf);
int  SYNOiSCSIEpFileMapHeaderSet(const char *szPath, const EPFILE_MAP_HEADER *pBuf);
int  SYNOiSCSIEpFileDatHeaderGet(const char *szPath, EPFILE_DAT_HEADER *pBuf);
int  SYNOiSCSIEpFileDatHeaderSet(const char *szPath, const EPFILE_DAT_HEADER *pBuf);
int  SYNOiSCSIEpFileJnlHeaderGet(const char *szPath, EPFILE_JNL_HEADER *pBuf);
int  SYNOiSCSIEpFileJnlHeaderSet(const char *szPath, const EPFILE_JNL_HEADER *pBuf);
int  SYNOiSCSIEpFileFriHeaderGet(const char *szPath, EPFILE_FRI_HEADER *pBuf);
int  SYNOiSCSIEpFileFriHeaderSet(const char *szPath, const EPFILE_FRI_HEADER *pBuf);
int  SYNOiSCSIEpFileTblHeaderGet(const char *szPath, EPFILE_TBL_HEADER *pBuf);
int  SYNOiSCSIEpFileTblHeaderSet(const char *szPath, const EPFILE_TBL_HEADER *pBuf);
int  SYNOiSCSIEpFileMapGetVar0(const char *szPath, EPFILE_MAP_VAR0 *pBuf);
int  SYNOiSCSIEpFileMapGetVar1(const char *szPath, EPFILE_MAP_VAR1 *pBuf);
int  SYNOiSCSIEpFileMapGetVar2(const char *szPath, EPFILE_MAP_VAR2 *pBuf);
int  SYNOiSCSIEpFileMapSetVar0(const char *szPath, const EPFILE_MAP_VAR0 *pBuf);
int  SYNOiSCSIEpFileMapSetVar1(const char *szPath, const EPFILE_MAP_VAR1 *pBuf);
int  SYNOiSCSIEpFileMapSetVar2(const char *szPath, const EPFILE_MAP_VAR2 *pBuf);
int  SYNOiSCSIEpFileJnlGetVar0(const char *szPath, EPFILE_JNL_VAR0 *pBuf);
int  SYNOiSCSIEpFileJnlGetVar1(const char *szPath, EPFILE_JNL_VAR1 *pBuf);
int  SYNOiSCSIEpFileJnlSetVar0(const char *szPath, const EPFILE_JNL_VAR0 *pBuf);
int  SYNOiSCSIEpFileJnlSetVar1(const char *szPath, const EPFILE_JNL_VAR1 *pBuf);
int  SYNOiSCSIEpFileFriGetVar0(const char *szPath, EPFILE_FRI_VAR0 *pBuf);
int  SYNOiSCSIEpFileFriSetVar0(const char *szPath, const EPFILE_FRI_VAR0 *pBuf);
int  SYNOiSCSIEpFileMapGetAll(const char *szPath, EPFILE_MAP *pBuf);
int  SYNOiSCSIEpIsCloneDone(const char *szMapFilePath, bool *blIsCloneDone);
bool SYNOiSCSIEpIsLoaded(const char *szLoadName);
int  SYNOiSCSIEpIsMapFile(const char *szPath, bool *isMapFile);
int  SYNOiSCSIEpIsJournalEnabled(bool *pBool);
int  SYNOiSCSIEpJournalFileCreate(void);
int  SYNOiSCSIEpJournalLock(int *fd);
int  SYNOiSCSIEpJournalUnlock(int *fd);
int  SYNOiSCSIEpMapFileAttributeGet(const char *szPath, uint32_t *pAttrib);
int  SYNOiSCSIEpMapFileChildAttributeGet(const char *szPath, uint32_t *childAttribute);
int  SYNOiSCSIEpMapFileCloneStart(const char *szSrcMapFilePath, const char *szSrcConfigfsPath, const char *szDstConfigfsPath);
int  SYNOiSCSIEpMapFileCloneStatus(const char *szMapFilePath, const char *szConfigfsDirPath);
int  SYNOiSCSIEpMapFileIsStable(const char *szFilePath, bool *pIsStable);
int  SYNOiSCSIEpMapFileIsVirtual(const char *szPath, bool *pIsVirtual);
int  SYNOiSCSIEpMapFileMetaSizeSet(const char *szPath, uint64_t size);
int  SYNOiSCSIEpMapFileMetaInit(const char *szPath, char *szUUID, uint64_t size);
int  SYNOiSCSIEpMapFileMirrorPromote(const char *szSrcMapFilePath, const char *szDstConfigfsPath);
int  SYNOiSCSIEpMapFileMirrorStart(const char *szSrcMapFilePath, const char *szSrcConfigfsPath, const char *szDstConfigfsPath);
int  SYNOiSCSIEpMapFileParentTotalCountGet(const char *szPath, uint64_t *parentTotalCount);
int  SYNOiSCSIEpMapFileParentUuidGet(const char *szPath, char *szUUID);
int  SYNOiSCSIEpMapFileTrunc(const char *szFilePath, const char *szRootPath, char *szUUID,
		const uint64_t u64LunSize, uint64_t *pu64FinalBytes, bool blThinProvisioning);
void SYNOiSCSIEpPinFileForFlashCache(const char *szFile, const char *szVolPath, bool force);
int  SYNOiSCSIEpTrashLock(int *fd, const char *szRootPath);
int  SYNOiSCSIEpTrashUnlock(int *fd);
int  SYNOiSCSIEpTrashMkdir(const char *szRootPath);
int  SYNOiSCSIEpUnmapBufferCheckAndEnable(void);
int  SYNOiSCSIEpVolumePin(const char *szVolPath);
bool SYNOiSCSIEpVsysIsLoaded(const char *szLoadName);
int  SYNOiSCSIEpVsysUnload(const char *szName);

__END_DECLS

#ifdef __cplusplus

class SYNOiSCSIEpJournalLockGuard {
public:
	SYNOiSCSIEpJournalLockGuard();
	~SYNOiSCSIEpJournalLockGuard();
private:
	int fd;
};

class SYNOiSCSIEpLockGuard {
public:
	SYNOiSCSIEpLockGuard(int volId);
	SYNOiSCSIEpLockGuard(const char *szVolPath);
	~SYNOiSCSIEpLockGuard();
private:
	int fd;
};

#endif // __cplusplus

#endif // _SYNOISCSIEP_EP_INTERNAL_H_
