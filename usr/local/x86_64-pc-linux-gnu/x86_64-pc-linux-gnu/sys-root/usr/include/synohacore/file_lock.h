#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef SYNOHA_FILE_LOCK_H
#define SYNOHA_FILE_LOCK_H

#define SPACE_CHECK_LOCK_TIMEOUT 5

#ifdef MY_ABC_HERE

#include <stdio.h>

typedef enum {
	HA_LOCK_SPACE = 0,          // lock for space/flashcache operation, check data sync done, unbind, or switch over
	HA_LOCK_INFO,               // lock for the info under "/tmp/ha/"
	HA_LOCK_UPGRADE,            // lock for upgrade
	HA_LOCK_LOG_SEND,           // lock for send ha log message to remote
	HA_LOCK_SPACE_CHECK_TASK,   // lock for space check task of UI Overview page information
	HA_LOCK_LOAD_OVERVIEW,      // lock for update SFZ_HA_LOAD_OVERVIEW_JSON under "/tmp/ha/"
	HA_LOCK_LOAD_SPACE,         // lock for update SFZ_HA_LOAD_SPACE_JSON under "/tmp/ha/"
	HA_LOCK_CRM_OPERATION,      // lock for crm operation
	HA_LOCK_DISK_INFO,          // lock for update SZF_HA_DISK_INFO
	HA_LOCK_HB_OPERATION,       // lock for heartbeat operation
} HA_FILE_LOCK_TYPE;

typedef struct _tag_HA_FILE_LOCK_ {
	HA_FILE_LOCK_TYPE  lockType;
	const char		   *szFile;
} HA_FILE_LOCK;

int HAFileLock(FILE **ppFile, HA_FILE_LOCK_TYPE lockType, unsigned int timeoutSec);
int HAFileUnlock(FILE **ppFile);

#endif /* MY_ABC_HERE */

#endif
