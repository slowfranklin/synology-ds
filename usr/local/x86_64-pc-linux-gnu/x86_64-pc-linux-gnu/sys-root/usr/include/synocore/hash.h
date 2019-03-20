// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_HASH_H__
#define __SYNO_HASH_H__

#include <stdio.h>
#include <sys/cdefs.h>

#include <synocore/list.h>

__BEGIN_DECLS;

/**
 * @addtogroup HASH
 *
 * @brief The structure and operation of Hash Table in SynoLib.
 *
 * @{
 */
 
/**
 * The SLIBSZPAIR defines the key-pair structure used in SLIBSZHASH.
 */
typedef struct {
	/** The key string that associates to value string szVal. */
	char *szKey;
	/** The value string that is associated by string szKey. */
	char *szVal;
} SLIBSZPAIR, *PSLIBSZPAIR ;

/**
 * The SLIBSZHASH structure implements a hash table, constructs
 * by @c SLIBCSzHashAlloc() and free by @c SLIBCSzHashFree().
 *
 * @note This structure does not provide any caseless related
 * operations. So that if caller wants to archive a caseless
 * SzHash, you will be required to transfrom input string to an
 * unifrom case before you insert it into a SzHash. For example:
 * @code{.c}
 * static void AddStringToHash(SLIBSZHASH pHash, const char *szName, const size_t bufflen)
 * {
 *   char *szUName = malloc(bufflen);
 *   if (NULL == szName || NULL == szUName) {
 *      return;
 *   }
 *   if (SLIBCUnicodeUTF8StrUpper(szName, szUName, bufflen) < 0) {
 *      return;
 *   }
 *   SLIBCSzHashSetValue(pHash, szUName, "");
 * }
 *
 * static BOOL IsStringInHash(SLIBSZHASH pHash, const char *szName, const size_t bufflen)
 * {
 *   char szUName[UTF8_MAX];
 *   char *szUName = malloc(bufflen);
 *   if (NULL == szName || NULL == szUName) {
 *      return;
 *   }
 *   if (SLIBCUnicodeUTF8StrUpper(szName, szUName, sizeof(szUName)) < 0) {
 *     return FALSE;
 *   }
 *   if (NULL == SLIBCSzHashGetValue(g_pshShare, szUName)) {
 *     return FALSE;
 *   }
 *   return TRUE;
 * }
 * @endcode
 */
typedef struct {
	/**
	 * The size(in bytes) allocated for hash string space.
	 */
	int nSize;
	/**
	 * The size (in bytes) of free string space.
	 */
	int nFree;
	/**
	 * The number of allocated hashtable entries.
	 */
	int nHash;
	/**
	 * The number of occupied pairs in the hash table.
	 */
	int nPair;
	/**
	 * Pointer to the first free string space.
	 */
	char* pNextFree;
	/**
	 * Pointer to the key-value pair array.
	 */
	SLIBSZPAIR pPairs[1];
} SLIBSZHASH , *PSLIBSZHASH;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/hash_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif // __SYNO_HASH_H__
