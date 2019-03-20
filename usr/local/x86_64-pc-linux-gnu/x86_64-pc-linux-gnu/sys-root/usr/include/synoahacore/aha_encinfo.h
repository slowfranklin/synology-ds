// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/**
 * @addtogroup AHA_ENCINFO
 *
 * @brief The operations of AHA_ENCINFO.
 *
 * @{
 */

#ifndef __SYNO_AHA_ENCINFO_H_
#define __SYNO_AHA_ENCINFO_H_

#include <sys/cdefs.h>
#include <synosas/enclosure.h>
#include <synoahacore/aha_core.h>
#include <sys/param.h>

#define AHA_HOST_MAX          2
#define AHA_ENC_MAX           15
#define AHA_MAX_DISK_COUNT    180

#define AHA_ENC_POWER_MAX     2
#define AHA_ENC_FAN_MAX       8
#define AHA_ENC_DISK_MAX      15
#define AHA_ENC_OUT_LINK_MAX  2
#define AHA_HOST_OUT_LINK_MAX 1

#define AHA_POWER_STATUS_UNKNOWN -1

#define MAX_ENC_DISK_SN_LIST_LENGTH   (MAX_SN_SIZE * AHA_ENC_DISK_MAX + AHA_ENC_DISK_MAX)
#define MAX_AHA_DISK_PATH_LIST_LENGTH (16 * AHA_MAX_DISK_COUNT + AHA_MAX_DISK_COUNT)
// (strlen(/dev/sas180) < 16)  Use 16 * 180 + 180 as max disk path list size

#define AHA_MAX_RAID_SIZE 180

/* 180*UUID + space and ,
   AllSpaceRAID=172a0244:66ce11a8:80ebcaf3:11f1d7bf,8cc13d42:e5eccc45:c69de3af:22ddbed7 */
#define AHA_MAX_STR_LENGTH_SPACE_RAID (MAX_LEN_RAID_UUID * AHA_MAX_RAID_SIZE + AHA_MAX_RAID_SIZE)
#define AHA_MAX_STR_LENGTH_ENC_SN_LIST (MAX_SN_SIZE * AHA_ENC_MAX)

__BEGIN_DECLS

typedef enum {
	AHA_ENC_LINK_STATUS_UNKNOWN = 0,
	AHA_ENC_LINK_STATUS_OK,
	AHA_ENC_LINK_STATUS_HOST_LINK_ERROR,
	AHA_ENC_LINK_STATUS_ENC_LINK_ERROR,
	AHA_ENC_LINK_STATUS_ENC_NOT_MATCH,
	AHA_ENC_LINK_STATUS_ENC_NOT_FOUND,
} AHA_ENC_LINK_STATUS;

typedef enum {
	AHA_OUT_LINK_TYPE_NONE = 0,
	AHA_OUT_LINK_TYPE_INVALID,
	AHA_OUT_LINK_TYPE_EXP,
	AHA_OUT_LINK_TYPE_HOST,
} AHA_OUT_LINK_TYPE;

typedef struct {
	int thermal;
	int power_status;
	int fan_status;
	char szModelname[64]; // 10 + (passive)
	char szLocalSN[MAX_SN_SIZE];
	AHA_OUT_LINK_TYPE LinkStatus[AHA_HOST_OUT_LINK_MAX];
	AHA_NODE_ROLE HostType;
} AHA_HOST_INFO;

typedef enum {
	AHA_DISK_TYPE_EMPTY  = 0x0,
	AHA_DISK_TYPE_FREE   = 0x1, // someone see the disk
	AHA_DISK_TYPE_HOST0  = 0x2, // host0 can see the disk
	AHA_DISK_TYPE_HOST1  = 0x4, // host1 can see the disk
	AHA_DISK_TYPE_USED   = 0x8, // this disk is used (md)
	AHA_DISK_TYPE_HOME   = 0x10,
	AHA_DISK_TYPE_PAIR   = 0x20,
} AHA_DISK_TYPE;

typedef struct {
	int iTemperature;
	int iMaxDisk;
	char szEncSN[MAX_SN_SIZE];
	SYNO_SAS_ENC_MODEL_ID ModelID;
	AHA_OUT_LINK_TYPE LinkStatus[AHA_ENC_OUT_LINK_MAX];
	SYNO_POWER_STATUS PowerStatus[AHA_ENC_POWER_MAX];
	FAN_STATUS FanStatus[AHA_ENC_FAN_MAX];
	AHA_DISK_TYPE DiskType[AHA_ENC_DISK_MAX];
} AHA_ENC_INFO;

typedef struct {
	char szModelname[64];
    char szLocalSN[MAX_SN_SIZE];
    AHA_ENC_INFO EncList[AHA_ENC_MAX];
    AHA_ENC_LINK_STATUS LinkStatus;
    AHA_NODE_ROLE HostType;
	int cRepairableDisk;
    int cUsedDisk;
    int cDisk;
    int iEncListLength;
    int iLastCorrectPos;
    int iMemory;
    BOOL blIsLocalCooret;
} AHA_HW_ENC_LIST_INFO;

typedef struct {
	AHA_ENC_LINK_STATUS LinkStatus;
	int cHostInfo;
	int cEncInfo;
	AHA_HOST_INFO HostInfo[AHA_HOST_MAX];
	AHA_ENC_INFO EncInfo[AHA_ENC_MAX];
} AHA_HOST_AND_ENC_INFO;

/**
 * Get host info and enclosure info from both active and passive servers
 *
 * @param[out] pHostEncInfo  The structure of host and enclosure info. Should not be NULL.
 *
 * @retval  0 Success.
 * @retval -1 Error.
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAHostEncInfoGet(AHA_HOST_AND_ENC_INFO *pHostEncInfo), -1);

/**
 * Get the fan status of enclosure with @p iEncID on local host
 *
 * @param[in]  iEncID        The target enclosure's ID
 * @param[out] rgFanStatus   Fan status array. Should not be NULL.
 * @param[in]  iNumOfFan     The number of fan module in the target enclosure. Should be the array length of @p rgFanStatus.
 *
 * @retval  0 Success.
 * @retval -1 Error.
 *
 * @grantable Y
 *
 * @user root
 */
AHA_FUNCTION_HWDEP (int SYNOAHAGetEncFanStatus(int iEncID, FAN_STATUS *rgFanStatus, int iNumOfFan), -1);

__END_DECLS

#endif

/**
 * @}
 */
