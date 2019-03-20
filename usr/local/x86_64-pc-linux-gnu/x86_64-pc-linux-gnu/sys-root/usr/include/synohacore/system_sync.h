#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2012-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_SYSTEM_SYNC_H
#define __SYNOHACORE_SYSTEM_SYNC_H

#ifdef MY_ABC_HERE

#include <string>
#include <vector>
#include <map>

#include <synohacore/strings.h>

// when modify this definition, we need to modify lsyncd/synolsyncd.h also.
#define SZF_LSYNCD_FIFO_CMD "/tmp/ha.lsyncd.fifoCmd"
#define SZF_LSYNCD_FIFO_DATA "/tmp/ha.lsyncd.fifoData"
#define SZF_LSYNCD_PID_FILE SZD_HA_VAR_RUN_FOLDER"lsyncd.pid"
#define SZD_LSYNCD SZD_HA_PREFIX"/etc/confsync"
#define SZF_LSYNCD_PASSWORD_FILE SZD_LSYNCD"/rsync.pw"
#define SZF_LSYNCD_SECRETS_FILE  SZD_LSYNCD"/rsyncd.secrets"
#define SZ_RSYNC_PORT "874"

#define SZF_LSYNCD_LOCK_FILE "/tmp/ha.lsyncd.lock"

enum LsyncdCmd {
	LSYNCD_CMD_GET_STATUS = 1,
	LSYNCD_CMD_GET_EVENTS,
	LSYNCD_CMD_GET_ABONDONED_EVENTS,
	LSYNCD_CMD_CHECK_CONSISTENCY,
	LSYNCD_CMD_MAX
};

#define SSYNC_ERR_NONE 0
#define SSYNC_ERR_UNDEFINED 1
#define SSYNC_ERR_LSYNCD_IS_NOT_RUNNING 2
#define SSYNC_ERR_FAILED_TO_AQUIRE_LOCK 3
#define SSYNC_ERR_FAILED_TO_OPEN_DATA_FIFO 4
#define SSYNC_ERR_FAILED_TO_OPEN_CMD_FIFO 5
#define SSYNC_ERR_PSELECT_FAILED 6
#define SSYNC_ERR_PSELECT_TIMEOUT 7
#define SSYNC_ERR_READ_FIFO_TIMEOUT 8
#define SSYNC_ERR_READ_FAILED 9
#define SSYNC_ERR_INVALID_PARAMETER 10
#define SSYNC_ERR_FAILED_TO_OPEN_LOCK 11
#define SSYNC_ERR_FLOCK_FAILED 12

struct LsyncdEvent {
	std::string event_type;
	std::string event_path;
};

struct LsyncdStatus {
	std::map<std::string, bool> states;
	std::vector<std::string> error_msgs;
};

int HASystemSyncGetStatus(LsyncdStatus &status);
int HASystemSyncGetEvents(std::vector<LsyncdEvent> &vec_events);
int HASystemSyncGetAbondonedEvents(std::vector<LsyncdEvent> &vec_events);
int HASystemSyncClrAbondonedEvents(void);
int HASystemSyncCheckConsistency(void);
int HASystemSyncGenPWFile(unsigned int key);

#endif /* MY_ABC_HERE */

#endif // SYNOHA_SYSTEM_SYNC_H
