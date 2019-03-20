/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_MTD_H__
#define __SYNO_MTD_H__

#include <linux/syno.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <mtd/mtd-user.h>

__BEGIN_DECLS;

#define MAX_PART_NAME 15  // max length of partition name
#define	SZF_VENDER_DEV				"/dev/mtd_vender"
#define	SZ_VENDER_NAME				"vendor"
#define SZ_REBOOT_CONFIG_NAME 			"RedBoot Config"
#define	SZ_FISDIR_NAME				"FIS directory"
#define SZF_VENDER_DEV_JUNIOR 		"/dev/mtd3" /* mtd3 */
#define MAX_SN_SIZE 36	//this lengh is including '\0' of SN, for array size we needn't +1
#define MAX_MTD_SN_SIZE 32	//max lengh of SN size in MTD
#define SYNO_MEM_CFG_MAGIC_HEADER "SYNO!!!!" //there is a same one in u-boot-monaco-2014.01/include/environment.h
#define SYNO_MEM_CFG_MAGIC_HEADER_SIZE 8

struct fis_image_desc {
    unsigned char name[16];      // Null terminated name
    uint32_t      flash_base;    // Address within FLASH of image
    uint32_t      mem_base;      // Address in memory where it executes
    uint32_t      size;          // Length of image
    uint32_t      entry_point;   // Execution entry point
    uint32_t      data_length;   // Length of actual data
    unsigned char _pad[256-(16+7*sizeof(uint32_t))];
    uint32_t      desc_cksum;    // Checksum over image descriptor
    uint32_t      file_cksum;    // Checksum over image data
};

#define MAC_LENGTH		6
#define CUSTOM_SN_LENGH		31
#define TEST_FLAG_LENGTH	92

#define SYNO_SN_TAG "SN="
#define SYNO_CHKSUM_TAG "CHK="
#define SYNO_SN_13_SIG SYNO_SN_TAG  // signature for 13 serial number

// mac address for synomanutil.c
typedef struct _tag_SYNO_MAC_ADDR_ {
		unsigned char	rgAddr[MAC_LENGTH];
		unsigned char	bChkSum;
} __attribute__((packed)) SYNO_MAC_ADDR, *PSYNO_MAC_ADDR;

// serial number for synomanutil.c
typedef struct _tag_SYNO_SN_ {
		char	rgSN[10];
		unsigned char	bChkSum;
} __attribute__((packed)) SYNO_SN, *PSYNO_SN;

// serial number for synomanutil.c
typedef struct _tag_SYNO_SN_FROM_MTD_ {
		char	rgSN[MAX_MTD_SN_SIZE];
		unsigned int	bChkSum;
} __attribute__((packed)) SYNO_SN_FROM_MTD, *PSYNO_SN_FROM_MTD;

typedef struct _tag_SYNO_CUSTOM_SN_ {
		char		rgCustomSN[CUSTOM_SN_LENGH];
		unsigned char	bChkSum;
} __attribute__((packed)) SYNO_CUSTOM_SN, *PSYNO_CUSTOM_SN;

typedef struct _tag_SYNO_TEST_FLAG_ {
		unsigned uiPTBurninMemoryCounter;   // P/T Burn-in Memory Test Time Counter
		unsigned uiPTBurninDMACounter;      // P/T Burn-in DMA Test Time Counter
		unsigned uiFTBurninCounter;         // F/T Burn-in DMA Test Time Counter
		char     rgPTFuncTestError[16];     // P/T Procomm Test Error Flag
		char     rgPTBurninError[16];       // P/T Burn-in Error Flag
		char     rgFTFuncTestError[32];     // F/T Test Error Flag
		char     rgFTBurninError[16];       // F/T Burn-in Error Flag
} __attribute__((packed)) SYNO_TEST_FLAG, *PSYNO_TEST_FLAG;

typedef struct _tag_SYNO_MTD_VENDER_SN_PART_ {
		char	rgSN[32];	//This is mappign to mtd flash the size cannot be modified
} __attribute__((packed)) SYNO_MTD_VENDER_SN_PART, *PSYNO_MTD_VENDER_SN_PART;

#define SYNO_MAC_MAX_V1 4
// actually this is VENDER_MAC_V1, reserve the structure name of SYNO_MTD_VENDER for compatibility
typedef struct _tag_SYNO_MTD_VENDER_MAC_V1_ {
		SYNO_MAC_ADDR	macAddr1;
		SYNO_MAC_ADDR	macAddr2;
		SYNO_MAC_ADDR	macAddr3;
		SYNO_MAC_ADDR	macAddr4;
} __attribute__((packed)) SYNO_MTD_VENDER_MAC_V1, *PSYNO_MTD_VENDER_MAC_V1;

/**
 * support 8 lan now
 * to expand the number of lans support, the vender structure is modified
 * SYNO_MTD_VENDER and SYNO_MTD_VENDER_ALL is older version
 * SYNO_MTD_VENDER_MAC and SYNO_MTD_VENDER_V2 is current version
 */
#define SYNO_MAC_MAX_V2 8
typedef struct _tag_SYNO_MTD_VENDER_MAC_V2_ {
                SYNO_MAC_ADDR   macAddr[SYNO_MAC_MAX_V2];
} __attribute__((packed)) SYNO_MTD_VENDER_MAC_V2, *PSYNO_MTD_VENDER_MAC_V2;

#define SYNO_MTD_VENDER_MAC_COMMON SYNO_MTD_VENDER_MAC_V2
#define SYNO_MAC_MAX_COMMON SYNO_MAC_MAX_V2

#define SYNO_MAGIC_LENGTH 8
#define SYNO_MAGIC_HEADER "SYNO!!!!"
typedef struct _tag_SYNO_MTD_VENDER_IDENTIFICATION_ {
                char   magicHeader[SYNO_MAGIC_LENGTH];
                unsigned char   version;
} __attribute__((packed)) SYNO_MTD_VENDER_IDENTIFICATION, *PSYNO_MTD_VENDER_IDENTIFICATION;

typedef struct _tag_SYNO_MTD_VENDER_SN_ {
		SYNO_SN serialNumber;
} __attribute__((packed)) SYNO_MTD_VENDER_SN, *PSYNO_MTD_VENDER_SN;

typedef struct _tag_SYNO_MTD_VENDER_SN_FROM_MTD_ {
		SYNO_SN_FROM_MTD serialNumber;
} __attribute__((packed)) SYNO_MTD_VENDER_SN_FROM_MTD, *PSYNO_MTD_VENDER_SN_FROM_MTD;

typedef struct _tag_SYNO_MTD_VENDER_CUSTOM_SN_ {
		SYNO_CUSTOM_SN serialCustomNumber;
} __attribute__((packed)) SYNO_MTD_VENDER_CUSTOM_SN, *PSYNO_MTD_VENDER_CUSTOM_SN;

typedef struct _tag_SYNO_MTD_VENDER_TEST_FLAG_ {
		SYNO_TEST_FLAG testFlag;
} __attribute__((packed)) SYNO_MTD_VENDER_TEST_FLAG, *PSYNO_MTD_VENDER_TEST_FLAG;

typedef struct _tag_SYNO_MTD_VENDER_V1_ {
		SYNO_MTD_VENDER_MAC_V1 stMac;
		unsigned char Pad1[32-sizeof(SYNO_MTD_VENDER_MAC_V1)];
		SYNO_MTD_VENDER_SN_PART stSerial;
		unsigned char Pad2[32-sizeof(SYNO_MTD_VENDER_SN_PART)];
		SYNO_MTD_VENDER_CUSTOM_SN stCustomSerial;
		unsigned char Pad3[32-sizeof(SYNO_MTD_VENDER_CUSTOM_SN)];
		SYNO_MTD_VENDER_TEST_FLAG stTestFlag;
} __attribute__((packed)) SYNO_MTD_VENDER_V1, *PSYNO_MTD_VENDER_V1;

/* for setting/getting transcoding channel number for STM_MONACO(DS216play) */
typedef struct _tag_SYNO_MTD_REDBOOT_CONFIG_ {
                char magic_header[8];
                int target_mode;
		unsigned char xhci_reset_counter;
} __attribute__((packed)) SYNO_MTD_CUSTOM_CFG;
// the space reserved for mac address in v1 is not enough, so move mac to the tail
#define SYNO_VENDER_CURRENT_VERSION 2
typedef struct _tag_SYNO_MTD_VENDER_V2_ {
		SYNO_MTD_VENDER_IDENTIFICATION stIdentification;
		unsigned char Pad1[16-sizeof(SYNO_MTD_VENDER_IDENTIFICATION)];
		SYNO_MTD_VENDER_SN_PART stSerial;
		unsigned char Pad2[32-sizeof(SYNO_MTD_VENDER_SN_PART)];
		SYNO_MTD_VENDER_CUSTOM_SN stCustomSerial;
		unsigned char Pad3[32-sizeof(SYNO_MTD_VENDER_CUSTOM_SN)];
		SYNO_MTD_VENDER_TEST_FLAG stTestFlag;
		unsigned char Pad4[128-sizeof(SYNO_MTD_VENDER_TEST_FLAG)];
		SYNO_MTD_VENDER_MAC_V2 stMac;
} __attribute__((packed)) SYNO_MTD_VENDER_V2, *PSYNO_MTD_VENDER_V2;

#define SYNO_MAC_MAX 8
typedef struct _tag_SYNO_VENDER_MAC_ {
        unsigned int uiMacCnt;
        SYNO_MAC_ADDR rgMacAddr[SYNO_MAC_MAX];
} SYNO_VENDER_MAC, *PSYNO_VENDER_MAC;

// the structure stored in memory is not required to contain checksum
#define SYNO_SN_MAX 32
typedef struct _tag_SYNO_VENDER_SN_ {
        char szSN[SYNO_SN_MAX];
} SYNO_VENDER_SN, *PSYNO_VENDER_SN;

typedef struct _tag_SYNO_VENDER_CUSTOM_SN_ {
        char szCustomSN[SYNO_SN_MAX];
} SYNO_VENDER_CUSTOM_SN, *PSYNO_VENDER_CUSTOM_SN;

// SYNO_VENDER_ALL is defined to represent the information of 
// SYNO_MTD_VENDER_V1 or SYNO_MTD_VENDER_V2 in memory
typedef struct _tag_SYNO_VENDER_ {
        int iVersion;
        SYNO_VENDER_MAC Mac;
        unsigned int uiSNLength;
        SYNO_VENDER_SN SN;
        SYNO_VENDER_CUSTOM_SN CustomSN;
        SYNO_MTD_VENDER_TEST_FLAG TestFlag;
} SYNO_VENDER, *PSYNO_VENDER;

typedef struct struct_syno_uboot_env_image {
	unsigned int crc32;
	char buf[];
} SYNO_UBOOT_ENV_IMAGE, *PSYNO_UBOOT_ENV_IMAGE, **PPSYNO_UBOOT_ENV_IMAGE;

#define SZF_SYNOCFG_DEV         "/dev/mtd5"

int SYNOMTDLockPartition(char *szDev);
int SYNOMTDILock(char *szDev, int fLock);
int SYNOMTDModifyFISEntry(char *szDev, struct SYNO_MTD_FIS_INFO *pSynoMtdFisInfo);
int SYNOMTDErasePartition(char *szDev);
int SYNOMTDErasePartitionRange(char *szDev, u_int32_t start, u_int32_t len);
int SYNOMTDUnlockPartition(char *szDev);
int SYNOMTDGetDeviceInfo(char *szDev, struct mtd_info_user *pmtd, int size);
int SYNOMTDModifyPartitionSize(char *szDev, u_int32_t uiStart, u_int32_t uiLength);
int SYNOMTDGetPartitionInfo(char *szDev, void *pData, int cbSize, int *pcbNeed);
int SYNOMTDFindPartByName(const char *szName);
int SYNOMTDOpenMemCfg(int mode);
int SYNOMTDCloseMemCfg(int fd);
int SYNOMTDWriteMemCfg(const char *pSrc, int cbSrc);
int SYNOMTDReadMemCfg(char *pDst, int cbDst, const int cbSkip);
int SYNOMTDGetMemCfg(SYNO_MTD_CUSTOM_CFG *pmtdMemCfg);
int SYNOMTDSetMemCfg(int mem_mode);
int SYNOMTDUbootFlashEnvRead(char *szDev, PPSYNO_UBOOT_ENV_IMAGE ppImage, size_t size);
int SYNOMTDUbootFlashEnvWrite(char *szDev, PPSYNO_UBOOT_ENV_IMAGE ppImage, size_t size);
int SYNOMTDUbootEnvGet(PSYNO_UBOOT_ENV_IMAGE pImage, size_t size, const char *pKey, char **ppValue, char **ppCurPos);
int SYNOMTDUbootEnvSet(PSYNO_UBOOT_ENV_IMAGE pImage, size_t size, const char *pKey, const char *pValue);
int SYNOMTDUbootEnvCrc(unsigned int *pCrc, const void *pBuf, size_t size);
int SYNOMTDUbootFlashTypeCheck(char *szDev, unsigned int flash_type);

__END_DECLS;
#endif // __SYNO_MTD_H__
