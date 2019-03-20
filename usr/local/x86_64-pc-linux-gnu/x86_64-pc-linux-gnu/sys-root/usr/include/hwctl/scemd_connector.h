#ifndef __SYNO_HWCTL_SCEMD_CONNECTOR_H_
#define __SYNO_HWCTL_SCEMD_CONNECTOR_H_

#include <synocore/synotype.h>
#include <hwctl/shared_buffer.h>
#include <synocore/file.h>
#include <stdbool.h>

__BEGIN_DECLS;

/**
 * FIXME
 * There are the same define and structure in project "libhwcontrol", "samba-3.2.2", "smartmontools" if any change for this stuff
 * these projects need be changed too.
 */
#define SCEMD_CONNECTOR_BUF_LEN 512
#define SZ_SCEMD_SOCK_CLIENT_FILE "/tmp/scemd_connector.sock_client"
#define SZ_SCEMD_SOCK_SERVER_FILE "/tmp/scemd_connector.sock_server"
#define SZ_MSG_TEST "test message from client"
#define SZ_MSG_TEST_AND_REPLY "test and reply message from client"
#define SZ_MSG_FROM_SERVER "scemd:ConnectorTestNeedReply() get the message"

typedef enum {
	CONNECTOR_NUM_TEST=1,					/* scemd connector client testing request from "syno_scemd_connector --test" */
	CONNECTOR_NUM_TEST_NEED_REPLY,			/* scemd connector client testing request from "syno_scemd_connector --test_reply" */
	CONNECTOR_NUM_SCEMD_BUF_GET,			/* the request to get the share buffer information in scemd. */
	CONNECTOR_NUM_DEFER_DEEP_SLEEP,			/* the request to defer DEEP SLEEP time from network, only used on QORIQ platform. */
	CONNECTOR_NUM_SCEMD_DISK_REFRESH,		/*notify scemd to refresh disk list info while a disk is hotpluged*/
	CONNECTOR_NUM_SCEMD_DISK_CACHED_UPDATE,		/*notify scemd to refresh disk cached include USB, EBOX and internal hdd*/
	CONNECTOR_NUM_SCEMD_LIST,				/*notify the scemd to handle scem list*/
	CONNECTOR_NUM_SMART_TEST_START,			/* FIXME: the request to polling test results after user arrange a S.M.A.R.T. test
											   please note that "#define CONNECTOR_NUM_SMART_TEST_START 8" is hard coded in "smartmontools-svn",
											   if you change the order, you should fix it in "smartmontools-svn", too.*/
	CONNECTOR_NUM_IGNORE_NETBIOS_BROADCAST,	/* the request to ignore netbios name query package */
	CONNECTOR_NUM_NTP_SETTING_NOTIFY,		/*the request to notify scemd that run_ntp_client in /etc/synoinfo.conf may change*/
	CONNECTOR_NUM_HA_STOP_BEEP,				/* notify scemd to stop beep and this is only for HA */
	CONNECTOR_NUM_SPACE_THRESHOLD,			/* notify scemd to load space threshold */
	CONNECTOR_NUM_LCM_CLOSE_MODE,			/* notify lcm close mode  */
	CONNECTOR_NUM_DISK_LED_SET,				/* notify disk led change */
	CONNECTOR_NUM_ALL_DISK_LED_SET,			/* notify disk led all change */
	CONNECTOR_NUM_SIGNAL_REPLACEMENET,		/* notify scemd and used to replace original signal handler */
	CONNECTOR_NUM_SAFEMODE_EBOX_POWEROFF,	/* poweroff ebox when DS into safe mode  */
	CONNECTOR_NUM_RAISE_EVENT,				/* Raise scemd event from outside world */
	CONNECTOR_NUM_NET_CHANGE,				/* notify scemd to update network interface list */
	CONNECTOR_NUM_SFP_INFO_CHECK,			/* notify scemd to check sfp+ module unsupport information */
	CONNECTOR_NUM_SYNOBIOS,					/* notify scemd to raise synobios event */
	CONNECTOR_NUM_HOSTNAME_CHANGE,			/* notify scemd that hostname changed */
	CONNECTOR_NUM_SCEMD_DISK_PERF_LOG_RECORD,	/* notify scemd to record performance test log */
	CONNECTOR_MSG_NUM_MAX,
}SCEMD_CONNECTOR_NUM;

#define SLEEP_TRY_TIMES_MAX 5
#define SCEMD_LIST_OP_TEMP_REFRESH  "operating_temp_refresh"
#define SCEMD_LIST_DEBUG_ENABLE     "debug_enable"
#define SCEMD_LIST_DEBUG_DISABLE    "debug_disable" 

/* for file lock lockf() */
#define SZF_SCEMD_SOCK_CLIENT_LOCK SZ_LOCK_DIR"lock_scemd_connector"
	/* sleep time unit micro sec */
#define LOCK_FAIL_SLEEP_TIME 50000
#define LOCK_TRY_TIMES_MAX 5

typedef struct _tag_SCEMD_CONNECTOR_MSG_IN {
	/* the number of scemd connector */
	int iConnectNum;
	/* if connection need to output */
	bool blNeedOutput;
	/* the size in byte of szData */
	int iDataLen;
	/* the message that scemd connector get from client */
	char szData[SCEMD_CONNECTOR_BUF_LEN];
} SCEMD_CONNECTOR_MSG_IN;

typedef struct _tag_SCEMD_CONNECTOR_MSG_OUT {
	/* the number of scemd connector */
	int iConnectNum;
	/* the connection return */
	int iConnectReturn;
	/* the size in byte of szData */
	int iDataLen;
	/* the message that scemd connector get from client */
	char szData[SCEMD_CONNECTOR_BUF_LEN];
} SCEMD_CONNECTOR_MSG_OUT;

typedef enum _tag_SCEMD_STATUS_TYPE {
	TYPE_UNKNOWN          = 0,
	TYPE_DISK_HIBERNATION = 1,
} SCEMD_STATUS_TYPE;

typedef enum _tag_STATUS_DISK_HIBERNATION {
	DISK_UNKNOWN            = 0,
	DISK_NOT_IN_HIBERNATION = 1,
	DISK_IN_HIBERNATION     = 2,
} STATUS_DISK_HIBERNATION;

int SYNOScemdConnectorClient(SCEMD_CONNECTOR_MSG_IN *pMsgIn, SCEMD_CONNECTOR_MSG_OUT *pMsgOut);
int SYNOScemdStatusGet(SCEMD_STATUS_TYPE type, int *pStatus);
int SYNOScemdCopy2MsgOut(const int iConnectNum, SCEMD_CONNECTOR_MSG_OUT *pMsgOut, const void *pSrcData, const int SrcDataLen);
int SYNOScemdCopy2MsgIn(const int iConnectNum, SCEMD_CONNECTOR_MSG_IN *pMsgIn, const void *pSrcData, const int SrcDataLen, const bool blNeedReply);

__END_DECLS;

#endif /* __SYNO_HWCTL_SCEMD_CONNECTOR_H_ */
