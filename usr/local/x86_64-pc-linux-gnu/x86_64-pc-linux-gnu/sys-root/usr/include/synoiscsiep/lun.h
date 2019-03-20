/* Copyright (c) 2015 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_LUN_H_
#define _SYNOISCSIEP_LUN_H_

#include <ctype.h>
#include <synofeasibilitycheck/check.h>
#include <synoiscsiep/ep.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_LUN_FILE_NAME_FORMAT           "%s_%05d"
#define ISCSI_LUN_TOP_DIR_NAME               "LUN"
#define ISCSI_LUN_TOP_DIR_FORMAT             "%s/" ISCSI_DIR_NAME "/" ISCSI_LUN_TOP_DIR_NAME
#define ISCSI_LUN_TYPE_DIR_FORMAT            ISCSI_LUN_TOP_DIR_FORMAT "/%s"
#define ISCSI_LUN_DIR_FORMAT                 ISCSI_LUN_TYPE_DIR_FORMAT "/%s"
#define ISCSI_LUN_PATH_FORMAT                ISCSI_LUN_DIR_FORMAT "/" ISCSI_LUN_FILE_NAME_FORMAT
#define ISCSI_LUN_TMP_DIR_FORMAT             ISCSI_VOLUME_TMP_DIR_FORMAT "/%s"
#define ISCSI_LUN_TMP_PATH_FORMAT            ISCSI_LUN_TMP_DIR_FORMAT "/" ISCSI_LUN_FILE_NAME_FORMAT
#define ISCSI_LUN_IMPORT_PROG_PATH_FORMAT    ISCSI_TMP_DIR_PATH "/L%d.import_progress"
#define ISCSI_LUN_HBA_DIR_NAME_PREFIX_NORMAL "LUN_"
#define ISCSI_LUN_BLUN_SUPPORT_KEY           "support_iscsi_btrfs_lun"

/*** constants ***/
#define ISCSI_LUN_MIN_LID                    1
#define ISCSI_LUN_MAX_LID                    1024
#define ISCSI_LUN_MIN_LOGICAL_UNIT_NUMBER    0
#define ISCSI_LUN_MAX_LOGICAL_UNIT_NUMBER    255
#define ISCSI_LUN_DEFAULT_BLOCK_SIZE         512
#define ISCSI_LUN_4K_NATIVE_BLOCK_SIZE       4096
#define ISCSI_LUN_ADV_LUN_UNIT_SIZE          (1ULL << 30) //1G
#define ISCSI_LUN_MIN_FILE_INDEX             0

#define ISCSI_LUN_USE_TRASH                  (0b1)
#define ISCSI_LUN_USE_REMOVE_VOLUME          (0b10)
#define ISCSI_LUN_USE_UNSYNC_SIZE            (0b100)
#define ISCSI_LUN_USE_RESTORE                (0b1000)
#define ISCSI_LUN_USE_ALREADY_LOCKED         (0b10000)
#define ISCSI_LUN_USE_TMP_FOLDER             (0b100000)
#define ISCSI_LUN_USE_NO_LUN_DIR             (0b1000000)
#define ISCSI_LUN_USE_OVERWRITE              (0b10000000)
#define ISCSI_LUN_USE_THIRD_PARTY            (0b100000000)

#define ISCSI_LUN_ATTR_LUN                   (0b1)
#define ISCSI_LUN_ATTR_FILE                  (0b10)
#define ISCSI_LUN_ATTR_THIN                  (0b100)
#define ISCSI_LUN_ATTR_ADV                   (0b1000)
#define ISCSI_LUN_ATTR_SINK                  (0b10000)
#define ISCSI_LUN_ATTR_VDISK                 (0b100000)
#define ISCSI_LUN_ATTR_BACKUP                (0b1000000)
#define ISCSI_LUN_ATTR_CINDER                (0b10000000)
#define ISCSI_LUN_ATTR_BLUN                  (0b100000000)

#define ISCSI_LUN_TYPE_STR_UNKNOWN           "UNKNOWN"
#define ISCSI_LUN_TYPE_STR_BLOCK             "BLOCK"
#define ISCSI_LUN_TYPE_STR_FILE              "FILE"
#define ISCSI_LUN_TYPE_STR_THIN              "THIN"
#define ISCSI_LUN_TYPE_STR_ADV               "ADV"
#define ISCSI_LUN_TYPE_STR_SINK              "SINK"
#define ISCSI_LUN_TYPE_STR_BKP_THIN          "BKP_THIN"
#define ISCSI_LUN_TYPE_STR_BKP_ADV           "BKP_ADV"
#define ISCSI_LUN_TYPE_STR_CINDER            "CINDER"
#define ISCSI_LUN_TYPE_STR_BLUN              "BLUN"
#define ISCSI_LUN_TYPE_STR_VDISK_ADV         "VDISK_ADV"
#define ISCSI_LUN_TYPE_STR_VDISK_BLUN        "VDISK_BLUN"

#define ISCSI_LUN_CATEGORY_STR_FILE          "FILE"
#define ISCSI_LUN_CATEGORY_STR_THIN          "THIN"
#define ISCSI_LUN_CATEGORY_STR_ADV           "ADV"
#define ISCSI_LUN_CATEGORY_STR_BKP           "BKP"
#define ISCSI_LUN_CATEGORY_STR_CINDER        "CINDER"
#define ISCSI_LUN_CATEGORY_STR_BLUN          "BLUN"
#define ISCSI_LUN_CATEGORY_STR_VDISK         "VDISK"

/*** keys ***/

/*** etc ***/

/*** types ***/
typedef enum _tag_iscsi_lun_category {
    ISCSI_LUN_CATEGORY_UNKNOWN = 0,
    ISCSI_LUN_CATEGORY_FILE    = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE,                                                // 000000011
    ISCSI_LUN_CATEGORY_THIN    = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN,                          // 000000111
    ISCSI_LUN_CATEGORY_ADV     = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_ADV,     // 000001111
	ISCSI_LUN_CATEGORY_SINK    = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_SINK,    // 000010111
	ISCSI_LUN_CATEGORY_VDISK   = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_VDISK,   // 000100111
    ISCSI_LUN_CATEGORY_BACKUP  = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_BACKUP,  // 001000111
    ISCSI_LUN_CATEGORY_CINDER  = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_CINDER,  // 010000111
    ISCSI_LUN_CATEGORY_BLUN    = ISCSI_LUN_ATTR_LUN | ISCSI_LUN_ATTR_FILE | ISCSI_LUN_ATTR_THIN | ISCSI_LUN_ATTR_BLUN,    // 100000111
} ISCSI_LUN_CATEGORY;                                                                                                     // BCbVSATFL

typedef enum _tag_iscsi_lun_type {
	ISCSI_LUN_TYPE_UNKNOWN    = 0,                                                // 000000000
	ISCSI_LUN_TYPE_BLOCK      = ISCSI_LUN_ATTR_LUN,                               // 000000001
	ISCSI_LUN_TYPE_FILE       = ISCSI_LUN_CATEGORY_FILE,                          // 000000011
	ISCSI_LUN_TYPE_THIN       = ISCSI_LUN_CATEGORY_THIN,                          // 000000111
	ISCSI_LUN_TYPE_ADV        = ISCSI_LUN_CATEGORY_ADV,                           // 000001111
	ISCSI_LUN_TYPE_SINK       = ISCSI_LUN_CATEGORY_ADV  | ISCSI_LUN_ATTR_SINK,    // 000011111
	ISCSI_LUN_TYPE_BKP_THIN   = ISCSI_LUN_CATEGORY_THIN | ISCSI_LUN_ATTR_BACKUP,  // 001000111
	ISCSI_LUN_TYPE_BKP_ADV    = ISCSI_LUN_CATEGORY_ADV  | ISCSI_LUN_ATTR_BACKUP,  // 001001111
	ISCSI_LUN_TYPE_CINDER     = ISCSI_LUN_CATEGORY_ADV  | ISCSI_LUN_ATTR_CINDER,  // 010001111
	ISCSI_LUN_TYPE_BLUN       = ISCSI_LUN_CATEGORY_THIN | ISCSI_LUN_ATTR_BLUN,    // 100000111
	ISCSI_LUN_TYPE_VDISK_ADV  = ISCSI_LUN_CATEGORY_ADV  | ISCSI_LUN_ATTR_VDISK,   // 000101111
	ISCSI_LUN_TYPE_VDISK_BLUN = ISCSI_LUN_CATEGORY_BLUN | ISCSI_LUN_ATTR_VDISK,   // 100100111
	// If adding a new type here, you must add it to LUN Type Tools as well.         BCbVSATFL
} ISCSI_LUN_TYPE;

// TODO: remove ISCSI_VDISK_FORMAT when lib/vdisk is deleted
typedef enum _tag_iscsi_virtual_disk_format {
	VDISK_FORMAT_BOOT = 0,
	VDISK_FORMAT_SYSTEM,
	VDISK_FORMAT_DATA,
} ISCSI_VDISK_FORMAT;

typedef struct _tag_iscsi_lun_ {
	int                lid;                                 // LUN ID.
	int                fdLock;                              // File descriptor of LUN's lock.
	int                use;                                 // Current use of LUN. (Defined in ISCSI_LUN_USE_OOXX)
	int                blocksize;                           // Block size of LUN. (Only for 4K block LUN)
	unsigned int       extent_size;                         // Extent size of LUN. (Mandatory required input for ISCSI_LUN_CATEGORY_ADV LUN)
	uint64_t           u64Size;                             // Size of LUN. (Mandatory required input if fileio)
	time_t             restoredTime;                        // Last restored time.
	ISCSI_LUN_TYPE     type;                                // Type of LUN. (Mandatory required input)
	ISCSI_VDISK_FORMAT format;                              // Format type of LUN. (Only for ISCSI_LUN_TYPE_VDISK LUN)
	char               szUUID[ISCSI_UUID_STRING_SIZE];      // UUID of LUN.
	char               szVPDUnitSerial[ISCSI_UUID_STRING_SIZE];  // wwn/vpd_unit_serial
	char               szRootPath[MAX_PATH_LEN];            // Location of LUN or path of block-device. (Mandatory required input)
	char               szName[MAX_LEN_ISCSI_NAME];          // Name of LUN. (Mandatory required input)
	SYNO_LINKED_LIST   list;
} ISCSI_LUN;

typedef struct _tag_iscsi_lun_import_progress_state_ {
	int lid;
	int st;
	uint64_t doneBytes;
	uint64_t totalBytes;
} ISCSI_LUN_IMPORT_PROGRESS_STATE;

/*** macro or inline functions ***/
// refert to target_core_file.h
#define ISCSI_LUN_MAX_SINGLE_FILE_SIZE_SHIFT(type)	 (type ? 32 : 40) // normal file size is 1T = 2^40, lunbkp file size is 4G
#define ISCSI_LUN_MAX_SINGLE_FILE_SIZE(type)         (1ULL << ISCSI_LUN_MAX_SINGLE_FILE_SIZE_SHIFT(type))
#define ISCSI_LUN_MAX_FILE_INDEX(size, type)         ((size - 1) >> ISCSI_LUN_MAX_SINGLE_FILE_SIZE_SHIFT(type))
#define ISCSI_LUN_FILE_INDEX_WIDTH(type)             (type ? 5 : 3) // Index width of all LUN types are 5 now

static inline bool valid_lid_index(int id) { return (ISCSI_LUN_MIN_LID <= id) && (ISCSI_LUN_MAX_LID >= id); }
static inline bool valid_lun_index(int id) { return (ISCSI_LUN_MIN_LOGICAL_UNIT_NUMBER <= id) && (ISCSI_LUN_MAX_LOGICAL_UNIT_NUMBER >= id); }

// LUN Type Tools
static inline ISCSI_LUN_TYPE SYNOiSCSILunTypeGet(int lunType)
{
	switch (lunType) {
	case ISCSI_LUN_TYPE_BLOCK:
		return ISCSI_LUN_TYPE_BLOCK;
	case ISCSI_LUN_TYPE_FILE:
		return ISCSI_LUN_TYPE_FILE;
	case ISCSI_LUN_TYPE_THIN:
		return ISCSI_LUN_TYPE_THIN;
	case ISCSI_LUN_TYPE_ADV:
		return ISCSI_LUN_TYPE_ADV;
	case ISCSI_LUN_TYPE_SINK:
		return ISCSI_LUN_TYPE_SINK;
	case ISCSI_LUN_TYPE_BKP_THIN:
		return ISCSI_LUN_TYPE_BKP_THIN;
	case ISCSI_LUN_TYPE_BKP_ADV:
		return ISCSI_LUN_TYPE_BKP_ADV;
	case ISCSI_LUN_TYPE_CINDER:
		return ISCSI_LUN_TYPE_CINDER;
	case ISCSI_LUN_TYPE_BLUN:
		return ISCSI_LUN_TYPE_BLUN;
	case ISCSI_LUN_TYPE_VDISK_ADV:
		return ISCSI_LUN_TYPE_VDISK_ADV;
	case ISCSI_LUN_TYPE_VDISK_BLUN:
		return ISCSI_LUN_TYPE_VDISK_BLUN;

	default:
		return ISCSI_LUN_TYPE_UNKNOWN;
	}
}

static inline ISCSI_LUN_TYPE SYNOiSCSILunTypeGetFromString(const char *szLUNType)
{
	char *ptr = NULL;
	char szTmpLUNType[64] = {0};

	snprintf(szTmpLUNType, sizeof(szTmpLUNType), "%s", szLUNType);
	ptr = szTmpLUNType;
	while ('\0' != *ptr) {
		*ptr = toupper(*ptr);
		++ptr;
	}

	if ( ! strcmp(ISCSI_LUN_TYPE_STR_BLOCK, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_BLOCK;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_FILE, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_FILE;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_THIN, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_THIN;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_ADV, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_ADV;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_SINK, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_SINK;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_BKP_THIN, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_BKP_THIN;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_BKP_ADV, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_BKP_ADV;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_CINDER, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_CINDER;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_BLUN, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_BLUN;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_VDISK_ADV, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_VDISK_ADV;
	} else if ( ! strcmp(ISCSI_LUN_TYPE_STR_VDISK_BLUN, szTmpLUNType)) {
		return ISCSI_LUN_TYPE_VDISK_BLUN;
	}

	switch (atoi(szLUNType)) {
	case ISCSI_LUN_TYPE_BLOCK:
		return ISCSI_LUN_TYPE_BLOCK;
	case ISCSI_LUN_TYPE_FILE:
		return ISCSI_LUN_TYPE_FILE;
	case ISCSI_LUN_TYPE_THIN:
		return ISCSI_LUN_TYPE_THIN;
	case ISCSI_LUN_TYPE_ADV:
		return ISCSI_LUN_TYPE_ADV;
	case ISCSI_LUN_TYPE_SINK:
		return ISCSI_LUN_TYPE_SINK;
	case ISCSI_LUN_TYPE_BKP_THIN:
		return ISCSI_LUN_TYPE_BKP_THIN;
	case ISCSI_LUN_TYPE_BKP_ADV:
		return ISCSI_LUN_TYPE_BKP_ADV;
	case ISCSI_LUN_TYPE_CINDER:
		return ISCSI_LUN_TYPE_CINDER;
	case ISCSI_LUN_TYPE_BLUN:
		return ISCSI_LUN_TYPE_BLUN;
	case ISCSI_LUN_TYPE_VDISK_ADV:
		return ISCSI_LUN_TYPE_VDISK_ADV;
	case ISCSI_LUN_TYPE_VDISK_BLUN:
		return ISCSI_LUN_TYPE_VDISK_BLUN;

	default:
		return ISCSI_LUN_TYPE_UNKNOWN;
	}
}

static inline const char * SYNOiSCSILunTypeToString(ISCSI_LUN_TYPE lunType) {
	switch (lunType) {
	case ISCSI_LUN_TYPE_BLOCK:
		return ISCSI_LUN_TYPE_STR_BLOCK;
	case ISCSI_LUN_TYPE_FILE:
		return ISCSI_LUN_TYPE_STR_FILE;
	case ISCSI_LUN_TYPE_THIN:
		return ISCSI_LUN_TYPE_STR_THIN;
	case ISCSI_LUN_TYPE_ADV:
		return ISCSI_LUN_TYPE_STR_ADV;
	case ISCSI_LUN_TYPE_SINK:
		return ISCSI_LUN_TYPE_STR_SINK;
	case ISCSI_LUN_TYPE_BKP_THIN:
		return ISCSI_LUN_TYPE_STR_BKP_THIN;
	case ISCSI_LUN_TYPE_BKP_ADV:
		return ISCSI_LUN_TYPE_STR_BKP_ADV;
	case ISCSI_LUN_TYPE_CINDER:
		return ISCSI_LUN_TYPE_STR_CINDER;
	case ISCSI_LUN_TYPE_BLUN:
		return ISCSI_LUN_TYPE_STR_BLUN;
	case ISCSI_LUN_TYPE_VDISK_ADV:
		return ISCSI_LUN_TYPE_STR_VDISK_ADV;
	case ISCSI_LUN_TYPE_VDISK_BLUN:
		return ISCSI_LUN_TYPE_STR_VDISK_BLUN;
	default:
		return ISCSI_LUN_TYPE_STR_UNKNOWN;
	}
}

// LUN Category Tools
static inline bool IsLUNCategoryBLOCK(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_TYPE_BLOCK == pLun->type;
}
static inline bool IsLUNCategoryFILE(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_FILE == (pLun->type & ISCSI_LUN_CATEGORY_FILE);
}
static inline bool IsLUNCategoryTHIN(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_THIN == (pLun->type & ISCSI_LUN_CATEGORY_THIN);
}
static inline bool IsLUNCategoryADV(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_ADV == (pLun->type & ISCSI_LUN_CATEGORY_ADV);
}
static inline bool IsLUNCategoryBACKUP(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_BACKUP == (pLun->type & ISCSI_LUN_CATEGORY_BACKUP);
}
static inline bool IsLUNCategoryCINDER(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_CINDER == (pLun->type & ISCSI_LUN_CATEGORY_CINDER);
}
static inline bool IsLUNCategoryBLUN(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_BLUN == (pLun->type & ISCSI_LUN_CATEGORY_BLUN);
}
static inline bool IsLUNCategoryVDISK(const ISCSI_LUN *pLun) {
	return ISCSI_LUN_CATEGORY_VDISK == (pLun->type & ISCSI_LUN_CATEGORY_VDISK);
}
static inline bool IsLUNCategoryDR(const ISCSI_LUN *pLun) {
	return (ISCSI_LUN_TYPE_ADV == pLun->type |
			ISCSI_LUN_TYPE_BLUN == pLun->type |
			ISCSI_LUN_TYPE_SINK == pLun->type |
			ISCSI_LUN_TYPE_CINDER == pLun->type);
}
static inline bool IsLUNCategoryNonAdvFile(const ISCSI_LUN *pLun) {
	return IsLUNCategoryFILE(pLun) && ! IsLUNCategoryADV(pLun);
}

static inline ISCSI_LUN_CATEGORY SYNOiSCSILunCategoryGetFromString(const char *szLUNCategory)
{
	char *ptr = NULL;
	char szTmpLUNCategory[64] = {0};

	snprintf(szTmpLUNCategory, sizeof(szTmpLUNCategory), "%s", szLUNCategory);
	ptr = szTmpLUNCategory;
	while ('\0' != *ptr) {
		*ptr = toupper(*ptr);
		++ptr;
	}

	if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_FILE, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_FILE;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_THIN, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_THIN;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_ADV, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_ADV;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_BKP, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_BACKUP;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_CINDER, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_CINDER;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_BLUN, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_BLUN;
	} else if ( ! strcmp(ISCSI_LUN_CATEGORY_STR_VDISK, szTmpLUNCategory)) {
		return ISCSI_LUN_CATEGORY_VDISK;
	}

	switch (atoi(szLUNCategory)) {
	case ISCSI_LUN_CATEGORY_FILE:
		return ISCSI_LUN_CATEGORY_FILE;
	case ISCSI_LUN_CATEGORY_THIN:
		return ISCSI_LUN_CATEGORY_THIN;
	case ISCSI_LUN_CATEGORY_ADV:
		return ISCSI_LUN_CATEGORY_ADV;
	case ISCSI_LUN_CATEGORY_BACKUP:
		return ISCSI_LUN_CATEGORY_BACKUP;
	case ISCSI_LUN_CATEGORY_CINDER:
		return ISCSI_LUN_CATEGORY_CINDER;
	case ISCSI_LUN_CATEGORY_BLUN:
		return ISCSI_LUN_CATEGORY_BLUN;
	case ISCSI_LUN_CATEGORY_VDISK:
		return ISCSI_LUN_CATEGORY_VDISK;
	default:
		return ISCSI_LUN_CATEGORY_UNKNOWN;
	}
}

// LUN Use Tools
static inline void SYNOiSCSILunUseAdd(ISCSI_LUN *pLun, int use) {
	pLun->use |= use;
}
static inline void SYNOiSCSILunUseRemove(ISCSI_LUN *pLun, int use) {
	pLun->use &= ~use;
}

static inline bool IsLunUsedForTrash(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_TRASH);
}
static inline bool IsLunUsedForRemovingVolume(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_REMOVE_VOLUME);
}
static inline bool IsLunUsedForUnsyncSize(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_UNSYNC_SIZE);
}
static inline bool IsLunUsedForRestore(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_RESTORE);
}
static inline bool IsLunUsedForAlreadyLocked(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_ALREADY_LOCKED);
}
static inline bool IsLunUsedForTmpFolder(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_TMP_FOLDER);
}
static inline bool IsLunUsedForNoLunDir(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_NO_LUN_DIR);
}
static inline bool IsLunUsedForOverwrite(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_OVERWRITE);
}
static inline bool IsLunUsedForThirdParty(const ISCSI_LUN *pLun) {
	return pLun && (pLun->use & ISCSI_LUN_USE_THIRD_PARTY);
}

static inline void SYNOiSCSILunFilePathWithIndex(const ISCSI_LUN *pLun, char *szPath, const int cbPath, const int iIndex)
{
	if (IsLunUsedForTrash(pLun)) {
		snprintf(szPath, cbPath, ISCSI_EP_TRASH_PATH_FORMAT, pLun->szRootPath, pLun->szUUID);
	} else if (IsLunUsedForTmpFolder(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_TMP_PATH_FORMAT, pLun->szRootPath, pLun->szUUID, pLun->szName, iIndex);
	} else if ( ! IsLUNCategoryBLOCK(pLun)) {
		snprintf(szPath, cbPath, ISCSI_LUN_PATH_FORMAT, pLun->szRootPath, SYNOiSCSILunTypeToString(pLun->type),
				pLun->szUUID, pLun->szName, iIndex);
	}
}

static inline void SYNOiSCSILunMapFilePath(const ISCSI_LUN *pLun, char *szPath, size_t cbPath)
{
	SYNOiSCSILunFilePathWithIndex(pLun, szPath, cbPath, ISCSI_LUN_MIN_FILE_INDEX);
}

/*** function declarations ***/
int  SYNOiSCSILunAllocatedSizedGet(const ISCSI_LUN *pLun, uint64_t *pAllocatedSize);
int  SYNOiSCSILunAsyncJobProgressGet(ISCSI_LUN *pLun, uint64_t *pTotal, uint64_t *pDone, int *pError);
int  SYNOiSCSILunClone(ISCSI_LUN *pParentLun, ISCSI_LUN *pChildLun);
int  SYNOiSCSILunConfGetAll(ISCSI_CONFIG *pLunConfig, const int additionalFlag);
int  SYNOiSCSILunConfGetByUuid(const char *szUUID, ISCSI_LUN *pLun);
int  SYNOiSCSILunConfGetByLunName(const char *lunName, const int additionalFlag, ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSILunConfLoad(const ISCSI_FILTER *pLunFilter, ISCSI_CONFIG *pLunConfig);
int  SYNOiSCSILunConfigfsAttrPath(const ISCSI_LUN* pLun, const char *szAttrib, char* szPath, const size_t cbSize);
int  SYNOiSCSILunConvertAdvToSink(ISCSI_LUN *pLun);
int  SYNOiSCSILunConvertSinkToAdv(ISCSI_LUN *pLun);
int  SYNOiSCSILunConvertAdvToVdiskAdv(ISCSI_LUN *pLun);
int  SYNOiSCSILunCreate(ISCSI_LUN *pLun);
int  SYNOiSCSILunDelete(ISCSI_LUN *pLun);
int  SYNOiSCSILunDeleteWithVolume(const char *szVolPath);
int  SYNOiSCSILunFeasibilityCheck(ISCSI_LUN *pSrcLun, ISCSI_LUN *pDstLun,
		SYNO_FEASIBILITY_TYPE feasibilityType, bool blIgnoreSoft, PSLIBSZLIST pslMsg);
int  SYNOiSCSILunFileChangeType(const ISCSI_LUN *pLun, ISCSI_LUN_TYPE lunType);
int  SYNOiSCSILunGetByLid(const int lunId, const int additionalFlag, ISCSI_LUN *pLun);
int  SYNOiSCSILunGetByName(const char *lunName, const int additionalFlag, ISCSI_LUN *pLun);
int  SYNOiSCSILunImport(ISCSI_LUN *pLun, const char *szImportPath);
int  SYNOiSCSILunImportCancel(ISCSI_LUN *pLun);
int  SYNOiSCSILunIsBound(ISCSI_LUN *pLun, bool *pRet);
int  SYNOiSCSILunIsLocked(ISCSI_LUN *pLun, bool *blIsLocked);
int  SYNOiSCSILunIsNameExist(const char *szLunName, bool *pDoesLUNNameExist);
int  SYNOiSCSILunLoad(ISCSI_LUN *pLun);
int  SYNOiSCSILunLoadWithTargets(ISCSI_LUN *pLun);
int  SYNOiSCSILunLock(ISCSI_LUN *pLun, ISCSI_PROGRESS_STEP step);
int  SYNOiSCSILunLoopbackMount(ISCSI_LUN *pLun, char *szDevPath, int cbDevPath);
int  SYNOiSCSILunLoopbackUnmount(const ISCSI_LUN *pLun);
int  SYNOiSCSILunMappingsAdd(const int *tid, const int lid, const int map_count);
int  SYNOiSCSILunMappingsRemove(const int *tid, const int lid, const int tid_count);
int  SYNOiSCSILunProgressGet(ISCSI_LUN *pLun, ISCSI_PROGRESS_STATE *pProgress);
int  SYNOiSCSILunRepairBLOCK(const SPACE_INFO *pSpace);
int  SYNOiSCSILunRepairFILE(const char *szVolPath);
int  SYNOiSCSILunSinkForceLogout(ISCSI_LUN *pLun, bool blForceAll);
int  SYNOiSCSILunSinkWhitelistSet(ISCSI_LUN *pLun, const char *ip1, const char *ip2);
int  SYNOiSCSILunSinkWhitelistGet(ISCSI_LUN *pLun, char *szIP1, size_t cbIP1, char *szIP2, size_t cbIP2);
long SYNOiSCSILunTaskGetSchIdByName(const char *szLunName);
int  SYNOiSCSILunUnload(ISCSI_LUN *pLun);
int  SYNOiSCSILunUnlock(ISCSI_LUN *pLun);
int  SYNOiSCSILunUnusedLidGet();
int  SYNOiSCSILunUpdate(ISCSI_LUN *pLun);
int  SYNOiSCSILunVdiskBind(const char *szPVLunUUID, const char *szIP, const char *szRodKey, const char *szInterfaceName);
int  SYNOiSCSILunVdiskRetryStop(const char *szPVLunUUID);
int  SYNOiSCSILunVdiskUnbind(const char *szPVLunUUID);
int  SYNOiSCSILunVhostIsMapped(ISCSI_LUN *pLun, bool *pRet);
int  SYNOiSCSILunVhostMap(ISCSI_LUN *pLun, char *szInterface, int cbInterface, bool bUseIov);
int  SYNOiSCSILunVhostUnmap(const ISCSI_LUN *pLun);
int  SYNOiSCSILunWaitUntilUnlock(ISCSI_LUN *pLun, unsigned int timeout);

// TODO: These SDK functions should be in the internal header when all callers are migrate to webapi or something else.
int  SYNOiSCSILunConfigUpgradeForCompatibility();
int  SYNOiSCSILunConfRemove(const ISCSI_LUN *pLun);
int  SYNOiSCSILunConfSet(const ISCSI_LUN *pLun);
int  SYNOiSCSILunConfigfsDirPath(const ISCSI_LUN* pLun, char* szPath, size_t cbSize);

// For compatibility in project: libsynodr
#define SYNOiSCSILunGetByLunId(lunId, additionalFlag, pLun) SYNOiSCSILunGetByLid(lunId, additionalFlag, pLun)
#define SYNOiSCSILUNTypeToString(lunType) SYNOiSCSILunTypeToString(lunType)

__END_DECLS

#endif // _SYNOISCSIEP_LUN_H_
