/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_CREDENTIALS_HPP__
#define __SYNO_CREDENTIALS_HPP__

#ifndef __cplusplus
# error "this library is for C++ ONLY"
#endif

#include "synocredentials.h"

#include <cstdlib>
#include <string>
#include <stdexcept>
#include <sstream>

#undef setresuid
#undef setresgid

struct runas_error: public std::runtime_error {
    template <typename T>
    runas_error(const T& msg): std::runtime_error(msg) {}
};

namespace _________ {

class __ {
    public:
        __(const char* file, const int line, const char* prototype):
            uid(geteuid()), gid(getegid()), file(file), line(line), prototype(prototype) {}

        ~__() {
            if (!seteid(uid, gid)) {
                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_CRIT), "%s:%d ERROR: ~%s(%d, %d)", file, line, prototype, uid, gid);
            }
        }

    protected:
        bool seteid(const uid_t uid, const gid_t gid) {
            const uid_t euid = geteuid();
            const gid_t egid = getegid();

            if (uid == euid && gid == egid) {
                return true;
            }

            if (euid != uid && euid != DSM_ROOT_UID && setresuid(-1, DSM_ROOT_UID, -1) < 0) {
                return false;
            }

            if ((gid == GID_NOT_BE_CHANGED || gid == egid || setresgid(-1, gid, -1) == 0) &&
                (uid == UID_NOT_BE_CHANGED || uid == euid || setresuid(-1, uid, -1) == 0)) {
                return true;
            } else {
                return false;
            }
        }

        bool getugid(const char *name, uid_t &uid, gid_t &gid) {
            long bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
            if (bufsize == -1) {
                bufsize = 16384;
            }

            char strerrbuf[BUFSIZ] = {0}, *strbuf = NULL;
            if ((strbuf = (char*) malloc(bufsize)) == NULL) {
                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: malloc(%ld) [%s]",
                        file, line, bufsize, strerror_r(errno, strerrbuf, BUFSIZ));
                return false;
            }

            struct passwd pwd, *result = NULL;
            int retval = getpwnam_r(name, &pwd, strbuf, bufsize, &result);
            free(strbuf);

            if (result == NULL) {
                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: getpwnam(%s) [%s]", file, line, name,
                        (retval == 0) ? "Name not found" : strerror_r(retval, strerrbuf, BUFSIZ));
                return false;
            }

            uid = pwd.pw_uid;
            gid = pwd.pw_gid;

            return true;
        }

    protected:
        const uid_t uid;
        const gid_t gid;
        const char* file;
        const int   line;
        const char* prototype;
};

template <bool throw_exception> class _: protected __ {
    public:
        _(const uid_t uid, const gid_t gid, const char* file, const int line, const char* prototype): __(file, line, prototype) {
            if (!seteid(uid, gid)) {
                std::ostringstream os;
                os << prototype << "(" << uid << ", " << gid << ")";
                std::string _ = os.str();

                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: %s", file, line, _.c_str());

                throw runas_error(_);
            }
        }

        _(const char* name, const char* file, const int line, const char* prototype): __(file, line, prototype) {
            uid_t uid = UID_NOT_BE_CHANGED;
            gid_t gid = GID_NOT_BE_CHANGED;

            if (!getugid(name, uid, gid) || !seteid(uid, gid)) {
                std::ostringstream os;
                os << prototype << "(\"" << name << "\")";
                std::string _ = os.str();

                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: %s", file, line, _.c_str());

                throw runas_error(_);
            }
        }

        operator bool() const {
            return false;
        }
};

// explicit template specialization
template <> class _<false>: protected __ {
    public:
        _(const uid_t uid, const gid_t gid, const char* file, const int line, const char* prototype): __(file, line, prototype) {
            success = seteid(uid, gid);
            if (!success) {
                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: %s(%d, %d)", file, line, prototype, uid, gid);
            }
        }

        _(const char* name, const char* file, const int line, const char* prototype): __(file, line, prototype) {
            uid_t uid = UID_NOT_BE_CHANGED;
            gid_t gid = GID_NOT_BE_CHANGED;

            if (!(success = getugid(name, uid, gid)) || !(success = seteid(uid, gid))) {
                syslog(LOG_MAKEPRI(LOG_AUTH, LOG_ERR), "%s:%d ERROR: %s(\"%s\")", file, line, prototype, name);
            }
        }

        operator bool() const {
            return success;
        }

    private:
        bool success;
};

} // namespace _________

#define IF_RUN_AS(uid, gid) if (_________::_<false> _ = _________::_<false>((uid), (gid), __FILE__, __LINE__, "IF_RUN_AS"))
#define RUN_AS(uid, gid) if (_________::_<true> _ = _________::_<true>((uid), (gid), __FILE__, __LINE__, "RUN_AS")) {} else

#define IF_RUN_AS2(name) if (_________::_<false> _ = _________::_<false>((name), __FILE__, __LINE__, "IF_RUN_AS2"))
#define RUN_AS2(name) if (_________::_<true> _ = _________::_<true>((name), __FILE__, __LINE__, "RUN_AS2")) {} else

#endif
