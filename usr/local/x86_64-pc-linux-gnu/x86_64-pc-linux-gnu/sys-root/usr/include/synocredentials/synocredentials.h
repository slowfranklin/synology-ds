#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_CREDENTIALS_H__
#define __SYNO_CREDENTIALS_H__

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

#ifdef __cplusplus
# include <string>
#else
# include <stdbool.h>
#endif

#define DSM_ROOT_UID    0
#define DSM_ROOT_GID    0
#define DSM_SYSTEM_UID  1
#define DSM_SYSTEM_GID  1
#define DSM_HTTP_UID    1023
#define DSM_HTTP_GID    1023
#define DSM_ADMIN_UID   1024
#define DSM_ADMIN_GID   101
#define DSM_GUEST_UID   1025
#define DSM_WHEEL_GID   10
#define DSM_USERS_GID   100

#define UID_NOT_BE_CHANGED ((uid_t) - 1)
#define GID_NOT_BE_CHANGED ((gid_t) - 1)

#ifdef DEBUG_CREDENTIALS
# define _DEBUG(...) __VA_ARGS__
#else
# define _DEBUG(...)
#endif

#define _SYSLOG(priority, format, ...) \
    syslog(LOG_MAKEPRI(LOG_AUTH, priority), "%s:%d " format, __FILE__, __LINE__, ## __VA_ARGS__)

#define __wrap_setresid(PROTOTYPE, TYPE, rid, eid, sid) \
__extension__ \
({ \
    _DEBUG( \
        TYPE old_rid, old_eid, old_sid; \
        get##PROTOTYPE(&old_rid, &old_eid, &old_sid); \
    ) \
    int result = set##PROTOTYPE(rid, eid, sid); \
    if (result == 0) { \
        if (eid == 0) { \
            _SYSLOG(LOG_INFO, "WARNING: set%s(%d, %d, %d)", #PROTOTYPE, rid, eid, sid); \
        } \
        _DEBUG( \
            TYPE new_rid, new_eid, new_sid; \
            get##PROTOTYPE(&new_rid, &new_eid, &new_sid); \
            _SYSLOG(LOG_DEBUG, "set%s: (%d, %d, %d) -> (%d, %d, %d)", #PROTOTYPE, \
                    old_rid, old_eid, old_sid, new_rid, new_eid, new_sid); \
        )\
    } else { \
        char _[BUFSIZ] = {0}; \
        _SYSLOG(LOG_ERR, "ERROR: set%s(%d, %d, %d) [%s]", #PROTOTYPE, rid, eid, sid, \
                strerror_r(errno, _, BUFSIZ)); \
    } \
    result; \
})

#define setresuid(ruid, euid, suid) __wrap_setresid(resuid, uid_t, ruid, euid, suid)
#define setuid(uid)                 setresuid(uid, uid, uid)
#define seteuid(uid)                setresuid(-1, uid, -1)

#define setresgid(rgid, egid, sgid) __wrap_setresid(resgid, gid_t, rgid, egid, sgid)
#define setgid(gid)                 setresgid(gid, gid, gid)
#define setegid(gid)                setresgid(-1, gid, -1)

#define ENTERCriticalSection \
{ \
    const uid_t __uid__ = geteuid(); \
    const gid_t __gid__ = getegid(); \
    if ((__gid__ == DSM_ROOT_GID || setresgid(-1, DSM_ROOT_GID, -1) == 0) && \
        (__uid__ == DSM_ROOT_UID || setresuid(-1, DSM_ROOT_UID, -1) == 0)) { \
        errno = 0; \
        _DEBUG( \
            _SYSLOG(LOG_INFO, "ENTERCriticalSection"); \
        ) \
    } else { \
        errno = EPERM; \
        _SYSLOG(LOG_ERR, "ERROR: ENTERCriticalSection"); \
    } \

#define LEAVECriticalSection \
    { \
        const uid_t __euid__ = geteuid(); \
        const gid_t __egid__ = getegid(); \
        if ((__uid__ == __euid__ || setresuid(-1, DSM_ROOT_UID, -1) == 0) && \
            (__gid__ == __egid__ || setresgid(-1, __gid__, -1) == 0) && \
            (__uid__ == __euid__ || setresuid(-1, __uid__, -1) == 0)) { \
            errno = 0; \
            _DEBUG( \
                _SYSLOG(LOG_INFO, "LEAVECriticalSection"); \
            ) \
        } else { \
            errno = EPERM; \
            _SYSLOG(LOG_ERR, "ERROR: LEAVECriticalSection"); \
        } \
    } \
}

#define InitCredentialsAs(name) \
    InitCredentialsByName(name, true)

#define InitCredentialsAsSystem() \
    InitCredentialsByName("system", true)

#define ResetCredentialsAs(name) \
    ResetCredentialsByName(name, true)

__BEGIN_DECLS
#ifdef MY_ABC_HERE
bool IsGrantable(const uid_t, const gid_t);
#endif
bool InitCredentials(const struct passwd, const bool);
bool InitCredentialsByName(const char *, const bool);
bool InitCredentialsByExecutable(const char *, const bool);
bool ResetCredentials(const struct passwd, const bool);
bool ResetCredentialsByName(const char *, const bool);
bool ResetCredentialsByExecutable(const char *, const bool);
__END_DECLS

#ifdef __cplusplus
bool InitCredentialsByName(const std::string, const bool grantable = true);
bool InitCredentialsByExecutable(const std::string, const bool followLink = true);
bool ResetCredentialsByName(const std::string, const bool grantable = true);
bool ResetCredentialsByExecutable(const std::string, const bool followLink = true);
#endif

#endif
