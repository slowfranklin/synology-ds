#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOHA_SYSLOG_H__
#define __SYNOHA_SYSLOG_H__

#ifdef MY_ABC_HERE

#include <syslog.h>

#define _halog(priority, szPriority, fmt, ...) __halog(priority, "[HA-%s] %s:%d: " fmt, szPriority, __FILE__, __LINE__, ##__VA_ARGS__)
#define HA_LOG_EMERG(fmt, ...)   _halog(LOG_EMERG,   "EMERG",  fmt, ##__VA_ARGS__)
#define HA_LOG_ALERT(fmt, ...)   _halog(LOG_ALERT,   "ALERT",  fmt, ##__VA_ARGS__)
#define HA_LOG_CRIT(fmt, ...)    _halog(LOG_CRIT,    "CRIT",   fmt, ##__VA_ARGS__)
#define HA_LOG_ERR(fmt, ...)     _halog(LOG_ERR,     "ERROR",  fmt, ##__VA_ARGS__)
#define HA_LOG_WARN(fmt, ...)    _halog(LOG_WARNING, "WARN",   fmt, ##__VA_ARGS__)
#define HA_LOG_NOTICE(fmt, ...)  _halog(LOG_NOTICE,  "NOTICE", fmt, ##__VA_ARGS__)
#define HA_LOG_INFO(fmt, ...)    _halog(LOG_INFO,    "INFO",   fmt, ##__VA_ARGS__)
#define HA_LOG_DEBUG(fmt, ...)   _halog(LOG_DEBUG,   "DEBUG",  fmt, ##__VA_ARGS__)

void __halog(int priority, const char *fmt, ...) __attribute__((format(printf, 2, 3)));

#endif /* MY_ABC_HERE */

#endif
