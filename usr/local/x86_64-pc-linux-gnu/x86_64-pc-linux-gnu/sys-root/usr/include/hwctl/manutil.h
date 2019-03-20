// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_MANUTIL_H_
#define __SYNO_HWCTL_MANUTIL_H_

#include <sys/cdefs.h>
#include <synocore/list.h>
#include <hwctl/mtd.h>

__BEGIN_DECLS;

#define SZF_VENDER_DEV_JUNIOR 		"/dev/mtd3" /* mtd3 */
// use for stress.c burnin-net.c scandisk.c
#define		SZF_DEFAULT_MANUTIL_CONF	"/usr/syno/etc.defaults/manutil.conf"

#define VDSM_SYNOBOOT2_PARTITION_NUM 2

/* Parameters string for manutil test utility */
#define SZ_PT_MEM_CNT          "pt_mem_cnt"
#define SZ_PT_DMA_CNT          "pt_dma_cnt"
#define SZ_FT_BURNIN_CNT       "ft_burnin_cnt"
#define SZ_FT_FUNC_ERROR       "ft_func_error"
// Pre Test Functional Error
#define SZ_PTF_BEGIN           "PTF_BEGIN"
#define SZ_PTF_COMPLETE        "PTF_COMPLETE"
// Pre Test Burnin Error
#define SZ_PTB_TESTED          "PTB_TESTED"
#define SZ_PTB_MEMORY_TEST     "PTB_MEMORY_TEST"
#define SZ_PTB_FILE_CHECKSUM   "PTB_FILE_CHECKSUM"
#define SZ_PTB_NETWORK_CRC     "PTB_NETWORK_CRC"
#define SZ_PTB_AV_STRESS       "PTB_AV_STRESS"
// Final Test Functional Error
#define SZ_FTF_TESTED          "FTF_TESTED"
#define SZ_FTF_TEST_COMPLETE   "FTF_TEST_COMPLETE"
#define SZ_FTF_MODEL           "FTF_MODEL"
#define SZ_FTF_VERSION         "FTF_VERSION"
#define SZ_FTF_USB             "FTF_USB"
#define SZ_FTF_ESATA           "FTF_ESATA"
#define SZ_FTF_RTC             "FTF_RTC"
#define SZ_FTF_FAN             "FTF_FAN"
#define SZ_FTF_LED             "FTF_LED"
#define SZ_FTF_BUTTON          "FTF_BUTTON"
#define SZ_FTF_FILE_COPY       "FTF_FILE_COPY"
#define SZ_FTF_REBOOT          "FTF_REBOOT"
#define SZ_FTF_SERIAL_NUMBER   "FTF_SERIAL_NUMBER"
#define SZ_FTF_NETWORK_SPEED   "FTF_NETWORK_SPEED"
#define SZ_FTF_MAC_ADDRESS     "FTF_MAC_ADDRESS"
#define SZ_FTF_REDUNDANT_POWER "FTF_REDUNDANT_POWER"
#define SZ_FTF_ESATA2          "FTF_ESATA2"
#define SZ_FTF_HDD_SEQ         "FTF_HDD_SEQ"
#define SZ_FTF_CPU_NAME        "FTF_CPU_NAME"
#define SZ_FTF_MEMORY_SIZE     "FTF_MEMORY_SIZE"
#define SZ_FTF_FUSE            "FTF_FUSE"
#define SZ_FTF_TRANSCODING     "FTF_TRANSCODING"
#define SZ_FTF_SAS_CONTROLLER_PHY     "FTF_SAS_CONTROLLER_PHY"
#define SZ_FTF_SATA_SPEED      "FTF_SATA_SPEED"
#define SZ_FTF_TEN_GIGA_NIC    "FTF_TEN_GIGA_NIC"
#define SZ_FTF_GROUP_UPDATE    "FTF_GROUP_UPDATE"
// Final Test Burnin Error
#define SZ_FTB_TESTED          "FTB_TESTED"
#define SZ_FTB_FILE_COPY       "FTB_FILE_COPY"
#define SZ_FTB_FILE_CHECKSUM   "FTB_FILE_CHECKSUM"
#define SZ_FTB_SATA            "FTB_SATA"
#define SZ_FTB_NETWORK_CRC     "FTB_NETWORK_CRC"
#define SZ_FTB_ATA_DRDY        "FTB_ATA_DRDY"

int SYNOManutilGetAllSNFromLoop(char *szImagePath, SYNO_MTD_VENDER_SN_PART *pMtdVenderSNPart);

int SYNOManutilIIsJunior(void);
int SYNOManutilIsUsbBoot(void);
int ErrMANInitStressTitle(PSLIBSZLIST pslList);
int SYNOManutilVenderOpen(int mode);
void SYNOManutilVenderClose(int fd);

// get the format information of the vender partition from kernel
int SYNOManutilGetVenderFormatVersion(void);

int SYNOManutilGetMacAddr(SYNO_VENDER_MAC *pMac);
int SYNOManutilGetSN(SYNO_VENDER_SN *pSN);
int SYNOManutilGetTestFlag(PSYNO_MTD_VENDER_TEST_FLAG pMtdTestFlag);
int SYNOManutilGetCustomSN(SYNO_VENDER_CUSTOM_SN *pCustomSN);

int SYNOManutilSetMacAddr(SYNO_VENDER_MAC *pMac);
int SYNOManutilSetSN(SYNO_VENDER_SN *pSN);
int SYNOManutilSetVersion(int iVersion);
int SYNOManutilSetCustomSN(SYNO_VENDER_CUSTOM_SN *pCustomSN);

int SYNOManutilVenderSemaphoreEnter(void);
int SYNOManutilVenderSemaphoreRelease(void);
int SYNOManutilCorrectVenderVersion(SYNO_VENDER *pVender, int iVersion);
int SYNOManutilMACAddressIsDuplicate(SYNO_VENDER_MAC *pMac, int iMacCnt);
int SYNOManutilMACAddressChecksum(unsigned char rgMacChksum[], int iMacChksumCnt, SYNO_VENDER_MAC *pMac);

int SYNOManutilTestFlagReset(BOOL bInit);
int SYNOManutilTestFlagList(void);
int SYNOManutilTestFlagGet(char *szErrorName);
int SYNOManutilTestFlagSet(char *szErrorName, char *szValue);
int SYNOManutilSerialNumberSetFromLoop(char *szImagePath, char *pData, int len);

int SYNOManutilReadLoopDev(char *szImagePath, char *pDst, int cbDst, const int cbSkip);
int SYNOManutilWriteLoopDev(char *szImagePath, const char *pSrc, int cbSrc);
int SYNOManutilVenderOpenByLoopDev(char *szImagePath, int partitionNum, int mode, char *szLoopPath, int cbLoopPath, char *szMountDir, int cbMountDir);
int SYNOManutilSerialNumberSetFromLoopWrapper(char *szImagePath, char *pData, int len);
int SYNOManutilGetSNFromLoop(char *szImagePath, SYNO_MTD_VENDER_SN_FROM_MTD *pMtdVenderSN);
void SYNOManutilVenderCloseByLoopDev(int fd, char *szLoopPath, char *szMountDir);
int SYNOManutilGetVenderAllV2FromLoop(char *szImagePath, SYNO_MTD_VENDER_V2 *pMtdVenderAllV2);
int SYNOManutilSetSNFromLoop(char *szImagePath, SYNO_MTD_VENDER_SN_FROM_MTD *pMtdVenderSN);

int SYNOManutilMACAddressSet(int num, void *pData, int len);
int SYNOManutilSerialNumberSet(char *pData, int len);
int SYNOManutilCustomSerialNumberSet(void *pData, int len);

int SYNOManutilReadVender(char *pDst, int cbDst, const int cbSkip);
int SYNOManutilWriteVender(const char *pSrc, int cbSrc);

__END_DECLS;
#endif // __SYNO_MANUTIL_H__
