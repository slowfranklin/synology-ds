#ifndef _SYNOISCSIEP_UTIL_INTERNAL_H_
#define _SYNOISCSIEP_UTIL_INTERNAL_H_

#include <time.h>
#include <synocore/synoglobal.h>
#include <synocore/conf.h>
#include <synoiscsiep/iscsi_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/

/*** constants ***/
#define ISCSI_SPARSE_COPY_AUTO   0
#define ISCSI_SPARSE_COPY_NEVER  1
#define ISCSI_SPARSE_COPY_ALWAYS 2

/*** keys ***/

/*** etc ***/

/*** types ***/
typedef enum {
	KERNEL_MODULES_NONE = 0,
	ISCSI_KERNEL_MODULES,
	VHOST_KERNEL_MODULES,
	TCM_KERNEL_MODULES,
	LOOPBACK_KERNEL_MODULES,
	KERNEL_MODULES_BOUND
} KERNEL_MODULE_SET;

typedef enum {
	ISCSI_FILE_UNKNOWN = 0,
	ISCSI_FILE_TRUNC,
	ISCSI_FILE_DD,
	ISCSI_FILE_FALLOC,
} ISCSI_FILE_TRUNC_MODE;

/*** macro or inline functions ***/
static inline bool is_valid_module_set(KERNEL_MODULE_SET module_set)
{
	return KERNEL_MODULES_NONE < module_set && KERNEL_MODULES_BOUND > module_set;
}

// UUID: 16-byte array => XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
static inline int SYNOiSCSIGetUuidStr(char *szUUIDStr, const uint8_t *szUUIDHex)
{
	int iRet = ERR_ISCSI_DEFAULT_ERROR_CODE;

	if ( ! szUUIDStr || ! szUUIDHex) {
		SetiRetAndGoToEND(ERR_ISCSI_NULL_POINTER);
	}

	iRet = snprintf(szUUIDStr, ISCSI_UUID_STRING_SIZE, "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		(unsigned char)szUUIDHex[0],  (unsigned char)szUUIDHex[1],  (unsigned char)szUUIDHex[2],  (unsigned char)szUUIDHex[3],
		(unsigned char)szUUIDHex[4],  (unsigned char)szUUIDHex[5],  (unsigned char)szUUIDHex[6],  (unsigned char)szUUIDHex[7],
		(unsigned char)szUUIDHex[8],  (unsigned char)szUUIDHex[9],  (unsigned char)szUUIDHex[10], (unsigned char)szUUIDHex[11],
		(unsigned char)szUUIDHex[12], (unsigned char)szUUIDHex[13], (unsigned char)szUUIDHex[14], (unsigned char)szUUIDHex[15]);

	if ((ISCSI_UUID_STRING_SIZE - 1) != iRet) {
		SetiRetAndGoToEND(ERR_ISCSI_FAILED_TO_GET_UUID);
	}

	iRet = ERR_ISCSI_SUCCESS;
END:
	return iRet;
}

// UUID: 16-byte array => XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
static inline int SYNOiSCSIGetUuidStrWithoutHyphen(char *szUUIDStr, const char *szUUIDHex)
{
	int iRet = ERR_ISCSI_DEFAULT_ERROR_CODE;

	if ( ! szUUIDStr || ! szUUIDHex) {
		SetiRetAndGoToEND(ERR_ISCSI_NULL_POINTER);
	}

	iRet = snprintf(szUUIDStr, ISCSI_UUID_STRING_SIZE_SHORT, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
		(unsigned char)szUUIDHex[0],  (unsigned char)szUUIDHex[1],  (unsigned char)szUUIDHex[2],  (unsigned char)szUUIDHex[3],
		(unsigned char)szUUIDHex[4],  (unsigned char)szUUIDHex[5],  (unsigned char)szUUIDHex[6],  (unsigned char)szUUIDHex[7],
		(unsigned char)szUUIDHex[8],  (unsigned char)szUUIDHex[9],  (unsigned char)szUUIDHex[10], (unsigned char)szUUIDHex[11],
		(unsigned char)szUUIDHex[12], (unsigned char)szUUIDHex[13], (unsigned char)szUUIDHex[14], (unsigned char)szUUIDHex[15]);

	if ((ISCSI_UUID_STRING_SIZE_SHORT - 1) != iRet) {
		SetiRetAndGoToEND(ERR_ISCSI_FAILED_TO_GET_UUID);
	}

	iRet = ERR_ISCSI_SUCCESS;
END:
	return iRet;
}

// UUID: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX (long) ==> XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX (short)
static inline int SYNOiSCSIGetUuidStrShort(char *szUUIDStrShort, const char *szUUIDStrLong)
{
	int iRet = ERR_ISCSI_DEFAULT_ERROR_CODE;

	if ( ! szUUIDStrShort || ! szUUIDStrLong) {
		SetiRetAndGoToEND(ERR_ISCSI_NULL_POINTER);
	}

	for (int i = 0; i < ISCSI_UUID_STRING_SIZE_SHORT; ++i) {
		if (8 > i) {
			szUUIDStrShort[i] = szUUIDStrLong[i];
		} else if (8 <= i && 12 > i) {
			szUUIDStrShort[i] = szUUIDStrLong[i + 1];
		} else if (12 <= i && 16 > i) {
			szUUIDStrShort[i] = szUUIDStrLong[i + 2];
		} else if (16 <= i && 20 > i) {
			szUUIDStrShort[i] = szUUIDStrLong[i + 3];
		} else if (20 <= i && ISCSI_UUID_STRING_SIZE_SHORT > i) {
			szUUIDStrShort[i] = szUUIDStrLong[i + 4];
		}
	}

	iRet = ERR_ISCSI_SUCCESS;
END:
	return iRet;
}

// UUID: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX => 16-byte array
static inline int SYNOiSCSIGetUuidHex(uint8_t *szUUIDHex, const char *szUUIDStr)
{
	int iRet = ERR_ISCSI_DEFAULT_ERROR_CODE, cMatch = 0;
	unsigned int uuidBuf[ISCSI_UUID_SIZE * 2] = {0};
	char cEndCheck = -1;

	if ( ! szUUIDHex || ! szUUIDStr) {
		SetiRetAndGoToEND(ERR_ISCSI_NULL_POINTER);
	}

	cMatch = sscanf(szUUIDStr, "%1x%1x%1x%1x%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%c",
		&uuidBuf[0],  &uuidBuf[1],  &uuidBuf[2],  &uuidBuf[3],  &uuidBuf[4],  &uuidBuf[5],  &uuidBuf[6],  &uuidBuf[7],
		&uuidBuf[8],  &uuidBuf[9],  &uuidBuf[10], &uuidBuf[11], &uuidBuf[12], &uuidBuf[13], &uuidBuf[14], &uuidBuf[15],
		&uuidBuf[16], &uuidBuf[17], &uuidBuf[18], &uuidBuf[19], &uuidBuf[20], &uuidBuf[21], &uuidBuf[22], &uuidBuf[23],
		&uuidBuf[24], &uuidBuf[25], &uuidBuf[26], &uuidBuf[27], &uuidBuf[28], &uuidBuf[29], &uuidBuf[30], &uuidBuf[31], &cEndCheck);

	if (ISCSI_UUID_SIZE * 2 != cMatch) {
		SetiRetAndGoToEND(ERR_ISCSI_FAILED_TO_GET_UUID);
	}

	for (int i = 0; i < ISCSI_UUID_SIZE; ++i) {
		szUUIDHex[i] = (uuidBuf[i * 2] << 4) | uuidBuf[i * 2 + 1];
	}

	iRet = ERR_ISCSI_SUCCESS;
END:
	return iRet;
}

static inline bool IsUuidString(const char *szStr)
{
	int cMatch = 0;
	unsigned int uuidBuf[ISCSI_UUID_SIZE * 2] = {0};
	char cEndCheck = -1;

	if ( ! szStr) {
		return false;
	}

	cMatch = sscanf(szStr, "%1x%1x%1x%1x%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x-%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%1x%c",
		&uuidBuf[0],  &uuidBuf[1],  &uuidBuf[2],  &uuidBuf[3],  &uuidBuf[4],  &uuidBuf[5],  &uuidBuf[6],  &uuidBuf[7],
		&uuidBuf[8],  &uuidBuf[9],  &uuidBuf[10], &uuidBuf[11], &uuidBuf[12], &uuidBuf[13], &uuidBuf[14], &uuidBuf[15],
		&uuidBuf[16], &uuidBuf[17], &uuidBuf[18], &uuidBuf[19], &uuidBuf[20], &uuidBuf[21], &uuidBuf[22], &uuidBuf[23],
		&uuidBuf[24], &uuidBuf[25], &uuidBuf[26], &uuidBuf[27], &uuidBuf[28], &uuidBuf[29], &uuidBuf[30], &uuidBuf[31], &cEndCheck);

	if (ISCSI_UUID_SIZE * 2 != cMatch) {
		return false;
	}

	return true;
}

static inline bool is_valid_volume_id(int volId)
{
	return 0 < volId;
}

/*** function declarations ***/
int  SYNOiSCSIConfigfsBlockLunHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsBlockControlPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsBlockEnablePath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsBlockInfoPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsChangeCurrentVersion(ISCSI_SUPPORT_TYPE version);
int  SYNOiSCSIConfigfsFileLunHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsFileControlPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsFileEnablePath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsFileInfoPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsEpLunHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsEpControlPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsEpEnablePath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsEpInfoPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsPipe(const char* szCmd, const char *szPath);
int  SYNOiSCSIConfigfsSymlink(const char *szSrcPath, const char *szDstPath);
int  SYNOiSCSIConfigfsTrashLunHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsTrashControlPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsTrashEnablePath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsTrashInfoPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsVlunHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIConfigfsVdiskHbaPath(const char *szConfigfsDirName, char *szPath, size_t pathLen);
int  SYNOiSCSIFileAlloc(const char *szFilePath, const uint64_t u64PlanTruncBytes, uint64_t *pu64RealTruncBytes);
int  SYNOiSCSIFileCopy(const char *szSrcPath, const char *szDstPath, int sparseCopyType);
uint32_t SYNOiSCSIFileCRC32CksumCompute(const void *input, unsigned int len);
int  SYNOiSCSIFileProgressWrite(unsigned long long ui64Inc, unsigned long long ui64Done);
int  SYNOiSCSIFileRename(const char *szSrcPath, const char *szDstPath, bool isAcrossSubvolume);
int  SYNOiSCSIFileTruncModeGet(bool blPrealloc, FSTYPE fsType, ISCSI_FILE_TRUNC_MODE *truncMode);
int  SYNOiSCSIFileTrunc(const char *szFilePath, const uint64_t u64NewTruncBytes, uint64_t *pu64FinalBytes, ISCSI_FILE_TRUNC_MODE mode);
int  SYNOiSCSILoadModules(KERNEL_MODULE_SET module_set);
int  SYNOiSCSILoadModulesWithoutLock(KERNEL_MODULE_SET module_set);
int  SYNOiSCSIMkdir(const char *szDirPath, bool blIsSubvolume);
int  SYNOiSCSIPutSectionToConfig(const char *szConfPath, const char *szSection, const PSLIBSZHASH pSectionAttributes);
int  SYNOiSCSIRemoveSectionList(const char *szFile, PSLIBSZLIST pSectionToRemove);
int  SYNOiSCSIRmdir(const char *szDirPath);
int  SYNOiSCSIUnloadModules(KERNEL_MODULE_SET module_set);
int  SYNOiSCSIUnloadModulesWithoutLock(KERNEL_MODULE_SET module_set);
int  SYNOiSCSIUuidGen(uint8_t *uuidHex);
const char* getTCMHBAEPIO();
const char* getTCMHBATrash();

__END_DECLS

#ifdef __cplusplus

#include <vector>
#include <string>

typedef std::vector<std::string> moduleset_t;

extern const moduleset_t& getTcmModuleSet();
extern const moduleset_t& getiSCSIModuleSet();

#endif // __cplusplus

#endif // _SYNOISCSIEP_UTIL_INTERNAL_H_
