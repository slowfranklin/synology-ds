#ifndef _SYNOISCSIEP_SYNOCOMM_MACRO_INTERNAL_H_
#define _SYNOISCSIEP_SYNOCOMM_MACRO_INTERNAL_H_

#ifndef WIN32
#define __SYNO_BEGIN_DECLS __BEGIN_DECLS
#define __SYNO_END_DECLS   __END_DECLS

#define HAVE_DESIGNATED_INITIALIZER
#else // WIN32
#include "time.h"
#include "stdio.h"
#include "stdlib.h"

#define __SYNO_BEGIN_DECLS extern "C" {
#define __SYNO_END_DECLS }
#endif // WIN32

#ifdef __cplusplus
__SYNO_BEGIN_DECLS
#endif // __cplusplus

#ifndef WIN32

#include <pthread.h>

#define MSG(format, a...) SYSLOG(LOG_INFO, "synocomm: " format, ##a)
#define EMSG(format, a...) SYSLOG(LOG_ERR, "synocomm: " format, ##a)

//#define USEDFOR_MULTITHREAD //used getrandpid for getpid in multi-threading process

#else // WIN32

#define MAX_PATH_LEN _MAX_PATH
#define snprintf(o, l, format, ...)  _snprintf_s(o, l, l, format, __VA_ARGS__)
#define sscanf    sscanf_s
#define strtok_r  strtok_s
#define strdup    _strdup
#define sleep(t)  Sleep((t) * 1000)
#define close(fd) _close(fd)
#define unlink _unlink

#define USEDFOR_MULTITHREAD //used getrandpid for getpid in multi-threading process

//#define LOGMSG_ENABLE
//#define MSG_DEBUG
#ifdef MSG_DEBUG
#define LMSG(format, ...)                                                                 \
{                                                                                         \
	FILE *synocomm_log_file = NULL;                                                       \
	fopen_s(&synocomm_log_file, "C:\\synocomm_log.txt", "a");                             \
	if (synocomm_log_file) {                                                              \
		fprintf(synocomm_log_file, "(%s:%d) - "format, __FILE__, __LINE__, __VA_ARGS__);  \
		fclose(synocomm_log_file);                                                        \
	}                                                                                     \
}

#ifdef LOGMSG_ENABLE
#define MSG  LMSG
#define EMSG LMSG
#define TMSG(format, ...)
#else // LOGMSG_ENABLE
#define MSG(format, ...)                                             \
{                                                                    \
	printf("(%s:%d) - "format, __FILE__, __LINE__, __VA_ARGS__);     \
}

#define EMSG(format, ...)                                             \
{                                                                     \
	printf("(%s:%d) ERROR - "format, __FILE__, __LINE__, __VA_ARGS__);\
}

#define TMSG(format, ...)
#endif // LOGMSG_ENABLE

#else // MSG_DEBUG
#define LMSG(format, ...)
#define MSG(format, ...)
#define EMSG(format, ...)
#define TMSG(format, ...)
#endif // MSG_DEBUG

#endif // WIN32

#ifdef HAVE_DESIGNATED_INITIALIZER
#define SFINIT(f, v) f = v
#else // HAVE_DESIGNATED_INITIALIZER
#define SFINIT(f, v) v
#endif // HAVE_DESIGNATED_INITIALIZER

extern int getrandpid(void);

/*
 * getpid is used for each channel's response in a process
 * If each thread in a multiple thread(s) process need a
 * separate channel, please use define 'USEDFOR_MULTITHREAD'
 * It will provide a mean to generate random id for channel
 */
#ifdef USEDFOR_MULTITHREAD //used getrandpid for getpid in multi-threading process
#define getcommpid getrandpid
#else // USEDFOR_MULTITHREAD
#define getcommpid getpid
#endif // USEDFOR_MULTITHREAD

#ifdef __cplusplus
__SYNO_END_DECLS
#endif // __cplusplus

#endif // _SYNOISCSIEP_SYNOCOMM_MACRO_INTERNAL_H_
