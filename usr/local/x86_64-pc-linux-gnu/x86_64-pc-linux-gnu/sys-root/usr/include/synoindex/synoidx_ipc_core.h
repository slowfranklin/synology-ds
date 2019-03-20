// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_IPC_CORE_H
#define _SYNO_IDX_IPC_CORE_H

// standard
#include <string.h>
#include <stdint.h>

// library
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>

//--------------------------------------------------

// General
#define BUFFER_MAX 				4096
#define BUFFER_MAX_BIG 			BUFFER_MAX * 4
#define PACKET_MAGIC_NUMBER 	5566

// Message buffer size
#define MSG_BUFFER_SIZE			1024
#define MSG_BUFFER_BIG_SIZE		MSG_BUFFER_SIZE * 4
#define MSG_BUFFER_HUGE_SIZE	MSG_BUFFER_SIZE * 8    // msgsnd() can't exceed MSGMAX(8192), ipcs -l

// Message type
#define MSG_TYPE_NORMAL			1
#define MSG_TYPE_BACKUP			2

//--------------------------------------------------

struct PacketHeader
{
	uint16_t magic_number;
	uint16_t data_length;
};

struct MessageBuffer {
	long mtype;
	char mtext[MSG_BUFFER_SIZE];
};

struct MessageBufferBig {
	long mtype;
	char mtext[MSG_BUFFER_BIG_SIZE];
};

struct MessageBufferHuge {
	long mtype;
	char mtext[MSG_BUFFER_HUGE_SIZE];
};

//--------------------------------------------------

int ConnectPeer(const char* socket_path, bool handshake = true, int retry = 5);
int DisconnectPeer(int fd);

int Readn(int fd, void* buf, size_t n);
int Writen(int fd, const void* buf, size_t n);

int RecvPacket(int fd, Json::Value &message);
int SendPacket(int fd, Json::Value &message);

int AutoSendRecvPacket(const char* socket_path, int fd, Json::Value &msg, int retry = 1800);
int AutoSendPacket(const char* socket_path, Json::Value &msg, int retry = 1800);

//--------------------------------------------------

#endif
