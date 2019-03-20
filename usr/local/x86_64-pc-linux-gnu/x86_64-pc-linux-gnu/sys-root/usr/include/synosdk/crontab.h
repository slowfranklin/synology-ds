// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_CRONTAB_H__
#define __SYNO_CRONTAB_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

/**
 * @addtogroup CRONTAB
 *
 * @brief The structure and operation of Crontab.
 *
 * @{
 */

#define SZF_CRONTAB		"/etc/crontab"
#define SZF_CRONTAB_TMP		"/etc/crontab.tmp"
#define SZF_DEF_CRONTAB		"/etc.defaults/crontab"

#define SYNO_SCHEDULE_SUN       0x01
#define SYNO_SCHEDULE_MON       0x02
#define SYNO_SCHEDULE_TUE       0x04
#define SYNO_SCHEDULE_WED       0x08
#define SYNO_SCHEDULE_THU       0x10
#define SYNO_SCHEDULE_FRI       0x20
#define SYNO_SCHEDULE_SAT       0x40
#define SYNO_SCHEDULE_EVERYDAY       (SYNO_SCHEDULE_SUN|SYNO_SCHEDULE_MON|SYNO_SCHEDULE_TUE|SYNO_SCHEDULE_WED|SYNO_SCHEDULE_THU|SYNO_SCHEDULE_FRI|SYNO_SCHEDULE_SAT)

enum {
	CRONTAB_DEF_MODE_T = 0644,
};

typedef struct {
	/** day of week, 0-7, 0 is Sun, 7 is everyday */
	int iWDays;
	/** 0-23 */
	int iHourStart;
	/** 0-23 */
	int iHourInterval;
	/** 0-23 */
	int iHourLast;
	/** 0-59 */
	int iMinStart;
	/** 1-24 */
	int iIteration;
	/** crontab command, cannot be NULL */
	char szCommand[1024];
}SYNOSCHEDULE, *PSYNOSCHEDULE;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/crontab_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_CRONTAB_H__
