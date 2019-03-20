// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_LOG_H
#define SYNO_FHOST_LOG_H

#include <sys/types.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define FHOSTLOG_MAX_MSG_LEN 			(8192)

/**
 * The group of logging extra messages.  This type is used in struct
 * FHOSTCONN.
 */
struct FHOSTLOG {
	/**
	 * The callback function that locks mutex when running in multi-thread
	 * environment.  May be NULL.
	 */
	FUNCLOCKER  pfuncLocker;
	/**
	 * The array of callback function for logging messages.  May be NULL.
	 */
	FUNCLOG     rgpfuncLog[FHOSTLOG_NUM];
};

#define _FHOSTLogInternal(pfhostLog, logPrior, fmt, ...) do {							\
	if (NULL == pfhostLog) {															\
		break;																			\
	}																					\
	if (NULL == pfhostLog->rgpfuncLog[logPrior]) {										\
		break;																			\
	}																					\
	FHOSTLog(pfhostLog, logPrior, "%s:%d " fmt, __FILE__, __LINE__, ##__VA_ARGS__);		\
} while (0)

#define FHOSTLogErr(pLog, fmt, ...) _FHOSTLogInternal(pLog, FHOSTLOG_ERR, fmt, ##__VA_ARGS__)
#define FHOSTLogDebug(pLog, fmt, ...) _FHOSTLogInternal(pLog, FHOSTLOG_DEBUG, fmt, ##__VA_ARGS__)

#ifdef  __cplusplus
}
#endif
#endif // SYNO_FHOST_LOG_H
