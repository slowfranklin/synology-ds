// Copyright (c) 2000-2003 Synology Inc. All rights reserved.
#ifndef __synostr_h__
#define __synostr_h__

#include <synocore/list.h>

#include <sys/cdefs.h>

__BEGIN_DECLS;

/** 
 * @addtogroup STRING
 *
 * @brief The operations of Strings.
 *
 * The utility functions below must be carefully used.  We do
 * not relocate memory in these funcitons.  Programmers "must" be aware of 
 * whether enough memory space is allocated for where variables 
 * szInput/szOutput points to Otherwise, it might leads to a core dump. 
 *
 * @{ 
 */

#define EOFSTRING '\0'

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/string_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif 
