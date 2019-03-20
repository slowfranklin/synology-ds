#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_AIS_MSG_H
#define __SYNOHACORE_AIS_MSG_H

#ifdef MY_ABC_HERE

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char cmd[8];
	char data[64];
} HA_AIS_HEADER;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char pid[8];
	char cmd[512];
} HA_AIS_SEND_WEBAPI, HA_AIS_PATCH_CHECK;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char cmd[8];
} HA_AIS_UPG_HEADER;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char data[16];
} HA_AIS_HEADER_CHANGE_VER;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char data[1024];
} HA_AIS_TRIM, HA_AIS_SMART_TEST;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
} HA_AIS_HEADER_SEND_MAC, HA_AIS_LOG_HEADER, HA_AIS_COMM;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	HA_AIS_LOG_HEADER header;
} HA_AIS_LOG_REQ;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	HA_AIS_LOG_HEADER header;
	char result[8];
} HA_AIS_LOG_RESP;

// must be initialized by ' ', because crm_node treats this as string
typedef struct __attribute__((packed)) {
	char mark[8];
	char type;
} HA_AIS_INFO_REQ;

/**
 * Send message to remote server through AIS (Application Interface Specification)
 *
 * The message is treated as a string and is sent to remote server using AIS,
 * and optional file @p szFilePath is also appended as part of the string.
 *
 * Remote server will handle this message by the script handle_ais.sh.
 *
 * NOTE: maximum size of message is 4096
 *
 * @param [in] aisReq     pointer to structure that contains message to be sent to remote server
 * @param [in] cbAisReq   size of @p aisReq
 * @param [in] szFilePath path to file that contain data to be sent to remote server along with @p aisReq
 * @retval 0 success
 * @retval -1 error
 */
int SendAisMsg(void *aisReq, unsigned int cbAisReq, const char* szFilePath);

#endif /* MY_ABC_HERE */

#endif
