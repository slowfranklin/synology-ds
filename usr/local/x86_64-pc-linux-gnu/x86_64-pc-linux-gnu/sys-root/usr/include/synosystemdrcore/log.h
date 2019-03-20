/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSDR_LOG_H__
#define __SYNOSDR_LOG_H__
#include <syslog.h>

#define _sdrlog(priority, szPriority, fmt, ...) syslog(priority, "[SDR-%s] %s:%d(%s): " fmt, szPriority, __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define SZ_SDR_LOG_LEVEL_EMERG "EMERG"
#define SZ_SDR_LOG_LEVEL_ALERT "ALERT"
#define SZ_SDR_LOG_LEVEL_CRIT "CRIT"
#define SZ_SDR_LOG_LEVEL_ERROR "ERR"
#define SZ_SDR_LOG_LEVEL_WARN "WARN"
#define SZ_SDR_LOG_LEVEL_NOTICE "NOTICE"
#define SZ_SDR_LOG_LEVEL_INFO "INFO"
#define SZ_SDR_LOG_LEVEL_DEBUG "DEBUG"

#define SDR_LOG_EMERG(fmt, ...)  _sdrlog(LOG_EMERG,   SZ_SDR_LOG_LEVEL_EMERG,  fmt, ##__VA_ARGS__)
#define SDR_LOG_ALERT(fmt, ...)  _sdrlog(LOG_ALERT,   SZ_SDR_LOG_LEVEL_ALERT,  fmt, ##__VA_ARGS__)
#define SDR_LOG_CRIT(fmt, ...)   _sdrlog(LOG_CRIT,    SZ_SDR_LOG_LEVEL_CRIT,   fmt, ##__VA_ARGS__)
#define SDR_LOG_ERR(fmt, ...)    _sdrlog(LOG_ERR,     SZ_SDR_LOG_LEVEL_ERROR,  fmt, ##__VA_ARGS__)
#define SDR_LOG_WARN(fmt, ...)   _sdrlog(LOG_WARNING, SZ_SDR_LOG_LEVEL_WARN,   fmt, ##__VA_ARGS__)
#define SDR_LOG_NOTICE(fmt, ...) _sdrlog(LOG_NOTICE,  SZ_SDR_LOG_LEVEL_NOTICE, fmt, ##__VA_ARGS__)
#define SDR_LOG_INFO(fmt, ...)   _sdrlog(LOG_INFO,    SZ_SDR_LOG_LEVEL_INFO,   fmt, ##__VA_ARGS__)
#define SDR_LOG_DEBUG(fmt, ...)  _sdrlog(LOG_DEBUG,   SZ_SDR_LOG_LEVEL_DEBUG,  fmt, ##__VA_ARGS__)

#endif //__SYNOSDR_LOG_H__
