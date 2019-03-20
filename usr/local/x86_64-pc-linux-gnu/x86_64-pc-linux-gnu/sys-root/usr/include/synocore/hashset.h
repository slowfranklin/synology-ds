// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_HASHSET_H__
#define __SYNO_HASHSET_H__
#include <stdio.h>
#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <synocore/list.h>

__BEGIN_DECLS;

/**
 * @addtogroup HASHSET
 *
 * @brief Hash set implementation.
 *
 * @{
 */
 
typedef struct {
	char *szValue;
	BOOL blUsed;
} SLIBSZHASHSET_SLOT, *PSLIBSZHASHSET_SLOT;

typedef struct {
	/** The size(in bytes) allocated for hash string space */
	int nSize;
	/** The size (in bytes) of free string space */
	int nFree;
	/** The number of allocated hashtable entries */
	int nHash;
	/** The number of occupied pairs in the hash table */
	int nItem;
	/** pointer to the first free string space */
	char* pNextFree;
	/** pointer to the entity array. */
	SLIBSZHASHSET_SLOT pSlots[1];
} SLIBSZHASHSET , *PSLIBSZHASHSET;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/hashset_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif
