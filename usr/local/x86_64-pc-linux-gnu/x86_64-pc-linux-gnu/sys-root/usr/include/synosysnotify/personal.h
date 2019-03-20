// Copyright (c) 2000-2013 Synology Inc. All rights reserved.

#ifndef __PERSONAL_DB_H__
#define __PERSONAL_DB_H__

#include <synocore/hash.h>
#include <synocore/proc.h>
#include <unistd.h>
#include <sys/types.h>
#include <synosysnotify/mail.h>

struct _tag_syno_nevent_ {
	struct _tag_syno_nevent_ *pNext;
	BOOL available;
	/* Members*/
	long id;
	long sent_time;
	long status;
	char *tag;
	char *username;
	char *pkg_name;
	char *extra_info;
	char *subject;
	char *content;
	char *filter;
};
typedef struct _tag_syno_nevent_ SYNO_NEVENT, *SYNO_NEVENT_LIST;

struct _tag_syno_ndevice_ {
	struct _tag_syno_ndevice_ *pNext;
	BOOL available;
	/* Members*/
	long id;
	long sns_target_id;
	char *username;
	char *pkg_name;
	char *mobile_info;
	char *type;
	char *identity;
};
typedef struct _tag_syno_ndevice_ SYNO_NDEVICE, *SYNO_NDEVICE_LIST;

typedef enum _tag_NOTIFICATION_EVENT_STATUS_ {
	NOTIFICATION_EVENT_STATUS_SENT = 1
} NOTIFICATION_EVENT_STATUS;

#ifdef __cplusplus
extern "C" {
#endif

// personal_db/event.c
int SYNONEventAlloc(SYNO_NEVENT **pNEvent);
int SYNONEventFree(SYNO_NEVENT *pNEvent);
int SYNONeventPop(SYNO_NEVENT **ppNEvent);
int SYNONeventPush(SYNO_NEVENT *pNEvent);
int SYNONeventSetCString(char **pszColumn, const char *szValue);
int SYNONeventLogSave(SYNO_NEVENT *pNEvent);
int SYNONeventLogList(const char *szUsername, const char *szPkgName, SYNO_NEVENT_LIST *pNEventList);
void SYNONEventListFree(SYNO_NEVENT_LIST *pNEventList);

// personal_db/device.c
int SYNONdeviceCreate(SYNO_NDEVICE *pNDevice);
int SYNONdeviceRead(SYNO_NDEVICE *pNDevice);
int SYNONdeviceUpdate(SYNO_NDEVICE *pNDevice);
int SYNONdeviceDelete(long id);
int SYNONdeviceList(const char *szUsername, const char *szPkgName, SYNO_NDEVICE_LIST *pNDeviceList);
int SYNONdeviceSetCString(char **pszColumn, const char *szValue);
int SYNONdeviceSetLInt(long *pColumn, const char *szValue);
int SYNONDeviceFree(SYNO_NDEVICE *pNDevice);
int SYNONDeviceAlloc(SYNO_NDEVICE **pNDevice);
void SYNONDeviceListFree(SYNO_NDEVICE_LIST *pNDeviceList);

// personal/device.c
int SYNOPersonalNotifictionDevicePair(SYNO_NDEVICE *pNDevice);
int SYNOPersonalNotifictionDeviceUnPair(SYNO_NDEVICE *pNDevice);
int SYNOPersonalNotifictionDeviceStat(SYNO_NDEVICE *pNDevice);
int SYNOPersonalNotifictionDeviceUpdate(SYNO_NDEVICE *pNDevice);
int SYNOPersonalNotifictionDeviceList(const char *szUsername, const char *szPkgName, SYNO_NDEVICE_LIST *pNDeviceList);

// utils/utils.c
int SYNOHashToJsonString(PSLIBSZHASH *ppHashParam, char **pszJson);
int SYNOJsonStringToHash(const char *szJsonString, PSLIBSZHASH *ppHashParam);
BOOL SYNONEventSuspend(const char *szMsg, long duration);

// personal_db/stopwatch.c
int SYNONStopwatchWatch(const char *key, long *time);
int SYNONStopwatchFresh(const char *key);
void SYNONStopwatchSetBoundary(long time);
#ifdef __cplusplus
};
#endif

#endif // __PERSONAL_DB_H__
