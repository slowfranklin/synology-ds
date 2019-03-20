// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_TIME_H__
#define __SYNO_TIME_H__

#include <sys/cdefs.h>
#include <sys/param.h>
#include <synocore/synotype.h>
#include <synocore/hash.h>
#include <synocore/list.h>

__BEGIN_DECLS;

/**
 * @addtogroup TIME
 *
 * @brief The structure and operation of Time Zone.
 *
 * @{
 */

#define SZF_NTPDATE					"/usr/sbin/ntpdate"
#define SZF_NTPCONF					"/etc/ntp.conf"
#define SZF_TZTABLE					"/usr/share/zoneinfo/Timezone/synotztable.json"
#define SZ_TIMEZONE_FIELD_GMTOFF    "gmtoff"
#define SZ_TIMEZONE_FIELD_NAMEINTZDB   "nameInTZDB"
#define SZ_TIMEZONE_FIELD_UISTRING  "uistring"
#define	SZF_ETC_TZ					"/etc/TZ"

#define SZ_TIMEZONE_POSIX_TZ        "POSIX_TZ"
#define SZ_TIMEZONE_GMT_OFFSET      "gmtoff"

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/time_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_TIME_H__
