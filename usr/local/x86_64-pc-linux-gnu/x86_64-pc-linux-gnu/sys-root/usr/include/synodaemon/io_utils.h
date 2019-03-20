/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNO_DAEMON_IO_UTILS_H_
#define _SYNO_DAEMON_IO_UTILS_H_

#include "std.h"

namespace synodaemon {
namespace io {

bool ReliableWrite(int fd, uint8_t* buf, size_t len);
bool ReliableRead(int fd, uint8_t* buf, size_t len);
bool PacketWrite(int fd, const string& data);
bool PacketRead(int fd, string& data);
int RecvFd(int sockfd);
bool SendFd(int sockfd, int fd);
bool IsSocketFdAlive(int fd);

} // namespace io
} // namespace synodaemon

#endif
