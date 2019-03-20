// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_RTC_H_
#define __SYNO_HWCTL_RTC_H_

#include <syslog.h>
#include <sys/time.h>

__BEGIN_DECLS;

int SYNORTCSet(time_t timeBySec);
int SYNORTCGet(time_t *pTimeBySec);

__END_DECLS;
#endif /* __SYNO_HWCTL_RTC_H_ */
