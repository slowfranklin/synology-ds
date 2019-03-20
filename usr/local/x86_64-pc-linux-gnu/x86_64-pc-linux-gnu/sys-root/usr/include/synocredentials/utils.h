/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_CREDENTIALS_UTILS_H__
#define __SYNO_CREDENTIALS_UTILS_H__

#include <sys/resource.h>

#define SetPriority(nice) \
__extension__ \
({ \
    pid_t pid = getpid(); \
    _DEBUG( \
        int prev_priority = getpriority(PRIO_PROCESS, pid); \
    ) \
    int result = -1; \
    errno = EPERM; \
    ENTERCriticalSection; \
    result = setpriority(PRIO_PROCESS, pid, nice); \
    LEAVECriticalSection; \
    _DEBUG( \
        _SYSLOG(LOG_DEBUG, "SetPriority: %d -> %d", prev_priority, nice); \
    ) \
    if (result != 0) { \
        char _[BUFSIZ] = {0}; \
        _SYSLOG(LOG_ERR, "ERROR: SetPriority(%d) [%s]", nice, strerror_r(errno, _, BUFSIZ)); \
    } \
    result; \
})

#endif
