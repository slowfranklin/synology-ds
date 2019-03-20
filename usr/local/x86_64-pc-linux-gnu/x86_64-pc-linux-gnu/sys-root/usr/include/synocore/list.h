// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_LIST_H__
#define __SYNO_LIST_H__

#include <stdio.h>
#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/error.h>
#include <synocore/bdb.h>

__BEGIN_DECLS;

/**
 * @addtogroup LIST
 *
 * @brief The structure and operation of Linking List in SynoLib.
 *
 * @{
 */

#define OP_CREATED 0x1000

/**
 * The sorting mode of SLIBSZLIST.
 */
typedef enum {
	/** This SLIBSZLIST is not sorted. */
	OP_UNSORTED = 0x0000,
	/** This SLIBSZLIST is sorted in ASCII alphbetic. */
	OP_SORTED = 0x0001,
	/** This SLIBSZLIST is sorted in UTF-8 caseless
	 *  alphbetic. */
	OP_UNICODE_SORTED = 0x0010,
} LIST_SORT_OP;

/**
 * The SLIBSZLIST structure implements a growable array of
 * strings, constructed by SLIBCSzListAlloc() and free by
 * SLIBCSzListFree().  Like an array, it contains components that
 * can be accessed using an integer index.  However, the size of
 * a SLIBSZLIST can grow or shrink as needed to accommodate
 * adding and removing items after the SLIBSZLIST has been
 * created.
 *
 * Each szList tries to optimize storage management by
 * maintaining SLIBSZLIST::nSize and SLIBSZLIST::nFree.  The
 * SLIBSZLIST::nSize is always at least as large as the szList
 * size; it is usually larger because as strings are added to
 * the szList, the szList's storage increases in chunks the size
 * of current SLIBSZLIST::nSize.  An application can construct
 * the szList by calling SLIBCSzListAlloc() with a big enough
 * parameter before inserting a large number of strings; this
 * reduces the amount of incremental reallocation.
 *
 * The data structure can use to save a lot of relative strings,
 * such as share data, user data, etc.
 *
 * @see SYNOPACKEDLIST
 * @struct SLIBSZLIST list.h <synocore/list.h>
 * @dotfile szlist.dot
 */
typedef struct {
	/** The amount of allocated bytes of this SzList. */
	int nSize;
	/** The number of items in this SzList. */
	int nItem;
	/** The amount of free bytes in this SzList. */
	int nFree;
	/** The flag that indicate whether this SzList is sorted. The
 	 *  initial state of SzList is LIST_SORT_OP::OP_UNSORTED. A
	 *  sorted SzList has two kinds of statues, LIST_SORT_OP::OP_SORTED and
	 *  LIST_SORT_OP::OP_UNICODE_SORTED. */
	LIST_SORT_OP fMode;
	/** The pointer to the end of free space. */
	char *pchEndOfFree;
	/** The pointer to end of this struct. */
	char *pchEnd;
	/** The array of pointers that hold address of strings. */
	char *pszItem[1];
}SLIBSZLIST,*PSLIBSZLIST,**PPSLIBSZLIST;

/**
 * The Transformed list structure that to be
 * stored into DB file.
 *
 * @see SLIBSZLIST
 * @struct SYNOPACKEDLIST list.h <synocore/list.h>
 * @dotfile szpackedlist.dot
 */
typedef struct {
	/** The real nSize. */
	int nSize;
	/** The real nItem. */
	int nItem;
	/** The real nFree. */
	int nFree;
	/** The real fMode. */
	LIST_SORT_OP fMode;
	/** The offset to the pchEndOfFree. */
	size_t offpchEndOfFree;
	/** The offset to the pchEnd. */
	size_t offpchEnd;
	/** The offset to the pszItem[1]. */
	size_t offpszItem[1];
} SYNOPACKEDLIST, *PSYNOPACKEDLIST;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/list_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif // __SYNO_LIST_H__
