#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_FLASHCACHE_H__
#define __SYNO_FLASHCACHE_H__
#include <sys/cdefs.h>

__BEGIN_DECLS;

#include <synocore/synotype.h>
#include <synocore/list.h>
#include <sys/types.h>

#define MAX_CACHE_DEV_PATH 64
#define MAX_SSD_PATH 64
#define MAX_DEV_UUID 128
#define MAX_SSD_CACHE_NUMBER 128
#define SKIP_DEFAULT_KB 1024

#define SZK_MAX_TEST_CACHE_SIZE "max_cache_gb"
#define SZF_FLASHCACHE_LIB "libsynoflashcache.so"
#define SYS_MEM_FOR_CACHE_PERCENT 0.25
#define SYS_FREE_RESERVED_MB 200
#define SYS_RESERVED_MEM_MB 1000
#define MIN_CACHE_SIZE_MB 10240 //10GB
#define SZ_CACHE_SERVICE_NAME "synocachepinfiletool"

#define MEM_KB_PER_GB_CACHE_ORIGINAL 4096
#define MEM_KB_PER_GB_CACHE_SYNO 416

#ifdef MY_DEF_HERE
// 1GB SSD Cache needs 416KB Memory, make Alpine only able to create about 930GB Cache to prevent memory alllocation failure
#define CACHE_MAX_VMALLOC_BYTE (378*1024*1024)
#else
/* 256MB cache need 1MB memory (1GB need 4 MB) */
#define CACHE_MEM_PROPORTION 256
#endif

#define CACHE_BLOCK_SIZE_KB_NEW 64
#define CACHE_BLOCK_SIZE_KB_ORIGINAL 4
#define MEM_BYTE_PER_CACHE_BLOCK_ORIGINAL 16
#define MEM_BYTE_PER_CACHE_BLOCK_NEW 26

#define SZ_VALUE_WRITE_THROUGH "thru"
#define SZ_VALUE_WRITE_BACK "back"
#define SZ_VALUE_WRITE_AROUND "around"
#define SZ_VALUE_WRITE_NONE "none"
#define SZ_VALUE_WRITE_BACK_BYPASS "back_bypass"
#define SZ_VALUE_WRITE_BACK_CRASH "back_crash"

/* define for flashcache_file_statistics.c */
#define FILE_STATISTICS_DAY 7
#define FILE_STATISTICS_HEAT_LEVEL 4
#define SZF_STATISTICS_REPORT_FILE "/etc/flashcache_file_statistics"
#define SZF_STATISTICS_IS_PROCESSING "/tmp/flashcache_file_statistics_processing"
#define BYTE_TO_M_BYTE(SIZE) (SIZE/(1024*1024))
#define DAY_TO_SECOND(TIME) (TIME*24*60*60) /* convert time unit from day to second */
#define SZ_STATIS_VOLUME "Volume="
#define SZ_STATIS_TIME "Time="
#define SZ_STATIS_DAY "Day="
#define SZ_STATIS_FILE_COUNT "FileCount="
#define SZ_STATIS_FILE_SIZE_SUM "FileSizeSum="
#define SZ_STATIS_PID "process_id="
#define SZ_STATIS_PROCESS_NAME "process_name="
#define SZK_STATIS_PID "pid"
#define SZK_STATIS_CMD "cmd"
#define SZK_STATIS_VOL_ID "volume_id"
#define SZK_STATIS_TIME "Time"
#define SZK_STATIS_DAY "Day"
#define SZK_STATIS_HEAT_LEVEL "Level_"
/* flag for workaround */
#define SZF_SCEMD_STOP_HANDLE_DEGRADE_PREFIX "/tmp/scemd-stop-handle-degrade"

typedef enum FlashCacheWriteType {
	FLASHCACHE_WRITE_UNKNOWN = -1,
	FLASHCACHE_WRITE_THROUGH = 0,
	FLASHCACHE_WRITE_BACK	 = 1,
	FLASHCACHE_WRITE_AROUND  = 2,
	FLASHCACHE_WRITE_NONE = 3,
	FLASHCACHE_WRITE_BACK_BYPASS = 4,
	FLASHCACHE_WRITE_BACK_CRASH = 5
} FLASHCACHE_WRITE_MODE;

typedef enum FlashCachePolicy {
	FLASHCACHE_POLICY_UNKNOWN = -1,
	FLASHCACHE_LRU = 0,
	FLASHCACHE_FIFO
} FLASHCACHE_POLICY;

typedef enum FlashCacheFilterType {
	FLASHCACHE_SSD_UUID = 1,
	FLASHCACHE_SPACE_UUID,
	FLASHCACHE_SSD_PATH,
	FLASHCACHE_SPACE_PATH,
	FLASHCACHE_REFERENCE_PATH,
	FLASHCACHE_CACHE_PATH
} FCACHE_FILTER_TYPE;

typedef struct FlashCacheSetting {
	FLASHCACHE_WRITE_MODE wMode;
	FLASHCACHE_POLICY policy;
	int fallowDelaySeconds;
	int dirtyThreshPercent;
	BOOL skipSeqIO;
} FLASHCACHE_OPTION;

typedef struct FlashCacheFilter {
	/*
	 * *** IMPORTANT ***
	 * You should use szSpaceUUID or szSSDUUID to get cache config because there
	 * may be some cache config is not deleted properly, and you will get wrong one
	 * by using other condition.
	 */
	FCACHE_FILTER_TYPE type;
	const char *szSSDUUID;
	const char *szSSDPath;
	const char *szSpaceUUID;
	const char *szReferencePath; /* e.g. /volume1 */
	const char *szSpacePath; /* e.g. /dev/vg1/volume2 */
} FLASHCACHE_CONF_FILTER;

typedef struct FlashCacheStatFilter {
	FCACHE_FILTER_TYPE type;
	const char *szSSDPath;
	const char *szSpacePath;
	const char *szCachePath;
} FLASHCACHE_STAT_FILTER;

typedef enum FlashCacheVersion {
	FLASHCACHE_VERSION_UNKNOWN = -1,
	FLASHCACHE_VERSION_ORIGINAL,
	FLASHCACHE_VERSION_SYNO
} FLASHCACHE_VERSION;

/*
 * Use SYNOFlashcacheGetCachePath to get cache path
 */
typedef struct FlashCacheConfig {
	char *szSSDUUID;
	char *szSSDPath;	/* e.g. /dev/md3 */
	char *szSpaceUUID;
	char *szSpacePath;	/* Volume's Space, ex /dev/vg1/volume2  */
	char *szReferencePath;
	FLASHCACHE_OPTION opt;
	struct FlashCacheConfig *pNext;
	char *szSSDID;
	char *szDiskLocInfo;
	BOOL cacheMissing;
	BOOL spaceMissing;
	BOOL loaded;
	unsigned long long ullCacheSizeByte;
	FLASHCACHE_VERSION cacheVersion;
	BOOL createCritSection;
} FLASHCACHE_CONFIG;

typedef struct FlashCacheStat {
	char *szSSDPath;
	char *szSpacePath;
	FLASHCACHE_OPTION opt;
	int readHitPercent;
	int writeHitPercent;
	unsigned long long ullTotalBlk;
	unsigned long long ullCachedBlk;
	unsigned long long ullReads;
	unsigned long long ullWrites;
	unsigned long long ullReadHits;
	unsigned long long ullWriteHits;
	int supportPin;
	struct FlashCacheStat *pNext;
	int blockSizeKb;
} FLASHCACHE_STAT;

typedef struct FlashCacheCreateInput {
	const char *szSSDPath;
	const char *szUnderDevPath;
	const char *szEnforceCachePath;
	unsigned long long ullMaxCacheKB;
	FLASHCACHE_OPTION opt;
	FLASHCACHE_VERSION cacheVersion;
} FLASHCACHE_CREATE_INPUT;

typedef struct FlashCacheSupportSSD {
	char *szModel;
	char *szBrand;
	char *szSize;
	char *szSince;
	char *szSupportModels;
} FCACHE_SUPPORT_SSD;

typedef struct FlashCacheSupportSSDList {
	FCACHE_SUPPORT_SSD *pSupportSSD;
	struct FlashCacheSupportSSDList *pNext;
} FCACHE_SUPPORT_SSD_LIST;

typedef struct FlashCacheFileStatistics {
	unsigned int year;
	unsigned int mon;
	unsigned int mday;
	unsigned long long ullFileCount;
	unsigned long long ullFileSizeSum;
} FCACHE_FILE_STATISTICS;

typedef struct FlashCacheSupportSSDFilter {
	const char *szSSDModel;
	unsigned long long ullSizeByte;
} FCACHE_SUPPORT_SSD_FILTER;

typedef enum FlashCacheSysctlsOperate {
	FCACHE_OP_NONE,
	FCACHE_OP_FALLOW_DELAY,
	FCACHE_OP_FALLOW_CLEAN_SPEED,
	FCACHE_OP_CACHE_ALL,
	FCACHE_OP_FAST_REMOVE,
	FCACHE_OP_ZERO_STATS,
	FCACHE_OP_RECLAIM_POLICY,
	FCACHE_OP_PID_EXPIRY_SECS,
	FCACHE_OP_MAX_PIDS,
	FCACHE_OP_DO_PID_EXPIRY,
	FCACHE_OP_MAX_CLEAN_IOS_SET,
	FCACHE_OP_MAX_CLEAN_IOS_TOTAL,
	FCACHE_OP_DIRTY_THRESH_PCT,
	FCACHE_OP_STOP_SYNC,
	FCACHE_OP_DO_SYNC,
	FCACHE_OP_IO_LATENCY_HIST,
	FCACHE_OP_SKIP_SEQ_THRESH_KB,
} FLASHCACHE_SYSCTLS_OPERATE;

typedef int (*PFunc_FCacheCreate)(const FLASHCACHE_CREATE_INPUT *pIn, char *szFlashCachePath, int cbPath);
typedef int (*PFunc_FCacheConfGet)(const FLASHCACHE_CONF_FILTER *pF, FLASHCACHE_CONFIG **ppConfig);
typedef int (*PFunc_FCacheConfSet)(const FLASHCACHE_CONFIG *pConfig);
typedef int (*PFunc_FCacheConfDel)(const FLASHCACHE_CONF_FILTER *pF);
typedef int (*PFunc_FCacheConfSearch)(FLASHCACHE_CONF_FILTER *pF, FLASHCACHE_CONFIG *pConf, FLASHCACHE_CONFIG **ppConfOut);
typedef void (*PFunc_FCacheConfFree)(FLASHCACHE_CONFIG *pC);
typedef int (*PFunc_FCacheStatGet)(const FLASHCACHE_STAT_FILTER *pF, FLASHCACHE_STAT **ppStat);
typedef void (*PFunc_FCacheStatFree)(FLASHCACHE_STAT **ppS);
typedef int (*PFunc_FCacheDelete)(const char *szCachePath, const FLASHCACHE_STAT *pStat);
typedef int (*PFunc_FCacheCacheSizeGet)(const FLASHCACHE_STAT_FILTER *pF, unsigned long long *pUllSizeByte);
typedef int (*PFunc_FCacheCacheUsedMemGet)(const FLASHCACHE_STAT_FILTER *pF, long long *pUllMemByte);
typedef int (*PFunc_FCacheUnload)(const char *szDevPath);
typedef int (*PFunc_FCacheExpand)(const char *szDiskPath);
typedef int (*PFunc_FCacheDoSysctls)(FLASHCACHE_SYSCTLS_OPERATE fCacheOp, int value, const char *szCacheDevPath, const char *szUnderDevPath);
typedef int (*PFunc_FCacheDestroy)(const char *szSSDPath);
typedef int (*PFunc_FCacheLoad)(const char *szCacheDevPath, const char *szUnderDevPath, char *szFlashCachePath, int cbFlashCachePath);
typedef FLASHCACHE_VERSION (*PFunc_FCacheVerGet)(const char *szSSDPath);

#include <synoflashcache/synoflashcache_p.h>

__END_DECLS;

#endif // __SYNO_FLASHCACHE_H__
