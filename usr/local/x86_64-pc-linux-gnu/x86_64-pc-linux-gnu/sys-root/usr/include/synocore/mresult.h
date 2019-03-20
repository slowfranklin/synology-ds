// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_MRESULT_H__
#define __SYNO_MRESULT_H__

#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/error.h>

__BEGIN_DECLS;

/**
 * @addtogroup MRESULT
 *
 * @brief Multiple result struction and its related operations.
 *
 * @{
 */

struct SLIBCMRESULT;
typedef struct SLIBCMRESULT *PSLIBCMRESULT;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/mresult_p.h>
#endif //NO_PROTO

__END_DECLS;

#endif /* __SYNO_MRESULT_H__ */
