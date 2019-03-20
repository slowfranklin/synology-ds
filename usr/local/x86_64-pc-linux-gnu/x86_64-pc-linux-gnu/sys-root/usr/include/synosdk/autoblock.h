// Copyright (c) 2000-2012 Synology Inc. All rights reserved.

#ifndef __SYNO_AUTOBLOCK_H__
#define __SYNO_AUTOBLOCK_H__

#include <netinet/in.h>
#include <sys/cdefs.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <time.h>

#include <synocore/error.h>

__BEGIN_DECLS;

/**
 * @defgroup AUTOBLOCK
 *
 * @brief Some basic functions of AutoBlock. More features in libsynoautoblock.
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/autoblock_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_AUTOBLOCK_H__
