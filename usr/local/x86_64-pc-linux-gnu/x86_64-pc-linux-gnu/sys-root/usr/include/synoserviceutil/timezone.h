// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_SERVICE_TIMEZONE_H__
#define __SYNO_SERVICE_TIMEZONE_H__

#include <sys/cdefs.h>
#include <sys/param.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZF_TZTABLE                                     "/usr/share/zoneinfo/Timezone/synotztable.json"
#define SZD_TIMEZONE                                    "/usr/share/zoneinfo/Timezone/"
#define SZD_ZONEINFO                                    "/usr/share/zoneinfo/"
#define SZF_ETC_TZ                                      "/etc/TZ"

#ifndef NO_PROTO
#include <synoserviceutil/timezone_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_SERVICE_TIMEZONE_H__
