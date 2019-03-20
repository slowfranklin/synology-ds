// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_DLIST_H__
#define __SYNO_DLIST_H__

#include <stdio.h>
#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/error.h>
#include <synocore/bdb.h>

__BEGIN_DECLS;

/**
 * @addtogroup DLIST
 *
 * @brief Double linked list implementation.
 *
 * @{
 */

typedef int  (*PSLIBCDLIST_FUNC) (void *pData, void *pUserData);
typedef void (*PSLIBCDLIST_FREE_FUNC) (void *pData);
typedef void* (*PSLIBCDLIST_COPY_FUNC) (void *pData);

typedef struct _SLIBCDLIST_NODE SLIBCDLIST_NODE, *PSLIBCDLIST_NODE;
struct _SLIBCDLIST_NODE
{
	void * pData;
	SLIBCDLIST_NODE *pNext;
	SLIBCDLIST_NODE *pPrev;
};

typedef struct
{
	PSLIBCDLIST_NODE pFirst;
	PSLIBCDLIST_NODE pLast;
	unsigned int count;

	PSLIBCDLIST_COPY_FUNC pCopyFunc;
	PSLIBCDLIST_FREE_FUNC pFreeFunc;
} SLIBCDLIST, *PSLIBCDLIST;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/dlist_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif // __SYNO_DLIST_H__
