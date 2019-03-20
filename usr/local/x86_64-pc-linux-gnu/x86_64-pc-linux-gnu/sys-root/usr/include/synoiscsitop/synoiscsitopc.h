#ifndef SYNOISCSITOPC_H
#define SYNOISCSITOPC_H

#include <synoiscsiep/lun.h>

__BEGIN_DECLS;

typedef struct _tag_LunIostatInfo {
	char szUUID[ISCSI_UUID_STRING_SIZE + 5];	// format: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX
	char szName[MAX_LEN_ISCSI_NAME];		// Name of LUN. (Mandatory required input)
	uint64_t throughputRead;
	uint64_t throughputWrite;
	uint64_t iopsRead;
	uint64_t iopsWrite;
	uint64_t diskLatencyRead;
	uint64_t diskLatencyWrite;
	uint64_t iSCSILunNetworkLatencyTx;
	uint64_t iSCSILunNetworkLatencyRx;
	uint64_t ioSizeRead;
	uint64_t ioSizeWrite;
	uint64_t queueDepth;
	ISCSI_LUN_TYPE lunType;
} LunIostatInfo;

/**
 * Open iscsi iostat of all loaded LUNs in configfs,
 * and collect there throughput, latency, queue info and so on.
 * It will collect and return these data in LunIostatInfo structure.
 *
 * @brief Get iscsitop info from configfs in LunIostatInfo structure.
 * @param[out] total number of luns in return list, set to -1 on error.
 * @retval head pointer of a lun iostat info list on success.
 * @retval NULL on error.
 * @exception no exception throw in this function.
 * @grantable Y
 * @user root
 * @apparmor abstractions/synoiscsitop
 */
LunIostatInfo* GetSynoiscsitopInfoStructs(int *numTotalLuns);

static inline void FreeSynoiscsitopInfoStructs(LunIostatInfo *lunIostatInfos)
{
	free(lunIostatInfos);
}

__END_DECLS;

#endif /* SYNOISCSITOPC_H */
