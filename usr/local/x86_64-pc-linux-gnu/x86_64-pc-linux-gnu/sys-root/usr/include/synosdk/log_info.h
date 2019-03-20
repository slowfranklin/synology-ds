#ifndef __SYNO_LOGCENTER_INFO_TABLE_H__
#define __SYNO_LOGCENTER_INFO_TABLE_H__

/**
 * @addtogroup LOGINFO
 *
 * @brief The struct and operations of Log Info.
 *
 * @{
 */

#include <synosdk/log.h>
typedef enum _LOGCENTER_BACKEND_tag {
	LOGCENTER_BACKEND_TEXT = 0,
	LOGCENTER_BACKEND_SQLITE3,
	LOGCENTER_BACKEND_NUM
} LOGCENTER_BACKEND;

typedef struct {
	int SynoFacility;
	char *szTag;
	char *szSynoLogFilePath;
	BOOL blInLatest50Logs;
	LOGCENTER_BACKEND Backend;
} LOGCENTER_INFO;

extern LOGCENTER_INFO g_logcenter_info_table[];
extern int g_logcenter_info_table_count;

/**
 * @}
 */

#endif
