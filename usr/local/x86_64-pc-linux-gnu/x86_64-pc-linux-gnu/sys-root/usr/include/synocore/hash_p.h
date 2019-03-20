/**
 * @addtogroup HASH
 *
 * @{
 */

/**
 * Allocates @p size bytes for SLIBSZHASH, initializes
 * number of table entries as 31.
 *
 * The underlying operation is implemented by
 * SLIBCIHashAllocator().
 *
 * @param[in] size the number of memory you want to allocate.
 *             If @p size is less than 512 bytes, set
 *             it to 512 (avoid too many expansion of memory).
 *
 * @retval  !NULL a pointer to the new struct success
 * @retval  NULL fail to allocate memory.
 *
 * @exception SLIBCIHashAllocator()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCSzHashAlloc(int size);

/**
 * Allocates @p BufferSize bytes for SLIBSZHASH and
 * initializes number of HashPair entries, SLIBSZHASH::nHash, as
 * @p nHashSlots.
 *
 * @param[in] nHashSlots the number of hash slots you want to
 *                   allocate.
 * @param[in] BufferSize the number of memory you want to
 *                   allocate.
 *
 * @retval  !NULL a pointer to the new struct success
 * @retval  NULL fail to allocate memory.
 *
 * @exception ERR_OUT_OF_MEMORY fail to allocate memory.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCIHashAllocator(const int nHashSlots, const int BufferSize);

/**
 * Checks the free string space of this SzHash
 * @p pHash is satisfied with the requested buffer
 * size @p nRequestSize, and returns the pointer of
 * (may be new) SzHash that is satisfied with the requested
 * buffer size. The function may return a new hash table pointer
 * different from the given hash table. Caller must in turn use
 * the returned hash pointer since we will resize this hashtable
 * (by creating new one) with more space if we have no free
 * space to satisfy the requested size.
 *
 * The resizing policy is as follows: if the free slots number
 * is less than 10% or the free string space is less than
 * @p nRequestSize we add these space accordingly.
 *
 * The underlying operation is implemented by
 * SLIBCSLIBIReSizeHash().
 *
 * @param[in] pHash the SzHash to be checked
 * @param[in] nRequestSize the SzHash buffer size that caller
 *                     requested
 *
 * @retval NULL malloc fail
 * @retval !NULL a pointer to SzHash a SzHash that satisfies the requested size.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCICheckSpace(PSLIBSZHASH pHash, const int nRequestSize);

/**
 * Copies the components of SzHash @p pHashFrom into
 * the specified SzHash @p pHashTo.
 *
 * Be careful that caller should make sure the size of
 * @p pHashTo must be larger than
 * @p pHashFrom both in stringbuffer
 * (SLIBSZHASH::nSize) and number of hashtable entries
 * (SLIBSZHASH::nHash).
 *
 * Note the entry in the old hash must be "rehashed" to new
 * hashtable by re-computing the newhash code.
 *
 * @param[in] pHashFrom the SzHash to be copied from
 * @param[out] pHashTo the SzHash to copy into
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCCopyHash(const PSLIBSZHASH pHashFrom, PSLIBSZHASH pHashTo);

/**
 * Exports the key strings of this SzHash @p pHash
 * into the given SzList @p ppslList and returns the
 * number of exported key strings.
 *
 * If caller just want to know how many key-value pairs in this
 * SzHash, caller can just assign the @p ppslList as
 * NULL.
 *
 * @param[in] pHash the SzHash to be exported
 * @param[out] ppslList the SzList that exported key strings
 *                 are stored into. May be NULL.
 *
 * @retval  -1 this SzHash is an invalid hash or fail to insert string into SzList
 * @retval  0 this SzHash is empty
 * @retval  >0 the number of exported key strings
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashEnumKey(const PSLIBSZHASH pHash, PSLIBSZLIST *ppslList);

/**
 * Writes a section @p szSection whose content stored
 * in SzHash @p pHash to a file output stream
 * @p pfOutput.
 *
 * If the @p szFormat is not specified, then default
 * output format is "%s=%s\n". For example:
 *
 * @code
 * [SzSection]
 * key1=value1
 * ...
 * keyN=valueN
 * @endcode
 *
 * @param[in,out] pfOutput the file output stream
 * @param[in] szSection the string that contains section name
 * @param[in] pHash the SzHash that contains key-value pairs to
 *              be outputed
 * @param[in] szFormat the string that presents the line format
 *                 will be outputed. May be NULL.
 *
 * @retval  -1 invalid format or write error
 * @retval  ERR_SUCCESS success
 *
 * @exception ERR_BAD_PARAMETERS @p szFormat is not a
 *                               valid "key=value" format
 * @exception ERR_WRITE_FAILED fprintf to output stream fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCFileHash2File(FILE *pfOutput, const char *szSection, const PSLIBSZHASH pHash, const char *szFormat);

/**
 * Causes the allocated memory referenced by SzHash
 * @p pHash to be available for future allocation
 *
 * @param[in,out] pHash the SzHash to be free
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzHashFree(PSLIBSZHASH pHash);

/**
 * Gets the slot number associated with key string
 * @p szKey in this SzHash @p pHash. If
 * this key can not be found in this hash, return -1.
 *
 * @param[in] pHash the SzHash to find.
 * @param[in] szKey the string of keyword that to be hashed and
 *              lookup.
 *
 * @retval -1  invalid arguments or can not find @p szKey in this SzHash.
 * @retval >=0 the slot number that @p szKey associated to in this SzHash.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCGetLookDict(const PSLIBSZHASH pHash, const char *szKey);

/**
 * Gets the associated value string in this SzHash
 * @p pHash by given key @p szKey. The
 * return value is a pointer to the value string if successful.
 * If this key can not be found in this hash, return NULL.
 *
 * @note In the slot may have such cases:
 *       - @p szKey is NULL and @p szValue is not NULL: this slot was removed before.
 *       - @p szKey is NULL and @p szValue is NULL: this slot is never be used.
 *
 * We can not sure the @p szKey is not exists in this
 * SzHash by just finding the szKey is NULL (maybe pre-occupied
 * by another key with the same hashcode and then deleted) , we
 * must proceed to find the matched key.
 *
 * @param[in] pHash the SzHash to find.
 * @param[in] szKey the string of keyword that to be hashed and
 *              lookup.
 *
 * @retval NULL   Invalid arguments or can not find @p szKey in this SzHash.
 * @retval !NULL  A string that @p szKey associated to in this SzHash.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzHashGetValue(const PSLIBSZHASH pHash, const char *szKey);

/**
 * Inserts a new key-value pair @p szKey and
 * @p szVal with the given slot number
 * @p piSlot into this SzHash @p pHash,
 * allocates space when necessary and returns (maybe new)
 * hashtable pointer. If the new hash is different from old
 * hash, the @p piSlot will be modified as new iSlot number.
 *
 * The underlying operation is implemented by SLIBCInsertPair(),
 * this function checks the free space in this SzHash and extend
 * if necessary before calling.
 *
 * @param[in,out] pHash the SzHash to be updated
 * @param[in] szKey the key string associates to szVal
 * @param[in] szVal the value string associated to szKey
 * @param[in,out] piSlot the pointer stored slot number and may
 *               be modified if the SzHash expends.
 *
 * @retval NULL memory allocation fail
 * @retval !NULL a pointer to SzHash the updated SzHash
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCInsertNewPair(PSLIBSZHASH pHash, const char *szKey, const char *szVal, int *piSlot);

/**
 * Inserts a new key-value pair @p szKey and
 * @p szVal with the given slot number
 * @p iSlot into this SzHash @p pHash. The
 * key and value strings are copied and SLIBSZHASH::nFree,
 * SLIBSZHASH::nPair and SLIBSZHASH::pNextFree fields of
 * @p pHash are modified.
 *
 * This function will not check the fullness of hashtable, so
 * caller should check the free space in this SzHash and extend
 * if necessary before calling.
 *
 * @param[in,out] pHash the SzHash to be updated
 * @param[in] szKey the key string associates to szVal
 * @param[in] szVal the value string associated to szKey
 * @param[in] iSlot the slot number to be inserted into
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCInsertPair(PSLIBSZHASH pHash, const char *szKey, const char *szVal, const int iSlot);

/**
 * Calculates the hash value from input string
 * @p szInput and hash table size @p modulo.
 *
 * This function calculates hash value by following steps:
 *     1. Given a sting: "a1b2c3d4e5", this function will
 *        divide this string into some substings that length equals to
 *        sizeof(int). Such as:
 *        @code
 *        String: a  1  b  2  c  3  d  4  e  5
 *               -- -- -- -- -- -- -- -- -- --
 *        Hex:   61 31 62 32 63 33 64 34 65 35
 *        @endcode
 *     2. After that, we get three integers, 0x61316232, 0x63336434, and 0x65350000
 *     3. To sum up and return the modulus by @p modulo as hash value.
 *
 * @param[in] szInput the string to be hashed
 * @param[in] modulo the hash table size
 *
 * @retval -1 invalid arguments
 * @retval >=0 the hash value
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCRadixHashCode(const char *szInput, const unsigned int modulo);

/**
 * Removes all key-value pairs in this SzHash @p pHash
 * and resets all fields of SzHash.
 *
 * @param[in,out] pHash the SzHash to be removed.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCHashRemoveAll(PSLIBSZHASH pHash);

/**
 * Removes the found key-value pair by key string
 * @p szKey from this SzHash @p pHash, and
 * returns the value string that matched. Returns NULL if the
 * key string doest not exists.
 *
 * @note
 * The removed key-value will be garbage collected if
 * there is no enough space for hashing. So the returning szVal
 * pointer is not suitable for long time used.
 *
 * @param[in,out] pHash the SzHash to be maintained.
 * @param[in] szKey the key string to find
 *
 * @retval NULL  The key string doest not exists in this SzHash or invalid arguments.
 * @retval !NULL A temp string that associated to key string.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzHashRemoveKey(PSLIBSZHASH pHash, const char *szKey);

/**
 * Resizes this SzHash @p pHash according to arguments
 * @p nNewHashEntries/@p nNewStringSize and return
 * newly created hashtable. The memoey hold by old hash will be
 * free. if the allocation of new hash fails, returns NULL and
 * the old hash will be left unchanged.
 *
 * @param[in,out] pHash the SzHash to be resized
 * @param[in] nNewHashEntries the number of hash slots you want to
 *                   allocate.
 * @param[in] nNewStringSize the number of memory you want to
 *                   allocate.
 *
 * @retval NULL malloc fail
 * @retval !NULL a pointer to SzHash a SzHash that satisfies the requested size.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCSLIBIReSizeHash(PSLIBSZHASH pHash, const int nNewHashEntries, const int nNewStringSize);

/**
 * Looks up entry by key string @p szKey in this
 * SzHash @p pHash and returns the slot number of
 * matched entry.
 *
 * Note we can return a first "unused" slot but not the first
 * free slot. Only we found there is no matching slot can we
 * return a free slot (unused or removed).
 *
 * @param[in] pHash the SzHash to look up
 * @param[in] szKey the key string to match
 *
 * @retval >=0 The slot number whether match or not.
 * @retval -1 On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSetLookDict(const PSLIBSZHASH pHash, const char *szKey);

/**
 * Updates the key-value pair @p szKey and
 * @p szVal into this SzHash @p ppHash and
 * returns the slot number (hashcode) in this hashtable. If the
 * key string can not exist in this SzHash, just adds it. If the
 * key is in this SzHash, replace the value string associcated
 * to @p szKey with @p szVal.
 *
 * @param[in,out] ppHash the pointer to SzHash to update
 * @param[in] szKey the key string that associates to szVal.
 * @param[in] szVal the value string that associated with
 *              szKey.
 *
 * @retval  -1 invalid arguments, malloc error, or SLIBCSetLookDict error
 * @retval  >=0 the slot number (hashcode) in this hashtable
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetValue(PSLIBSZHASH *ppHash, const char *szKey, const char *szVal);

/**
 * Updates the slot @p piSlot of this SzHash
 * @p pHash with the given key-value string pair
 * @p szKey and @p szVal, allocates new hash
 * when necessary and returns (maybe newly created) hashtable.
 * if the new hash is different from old hash, the
 * @p piSlot will be modified as new iSlot
 * number.
 *
 * @param[in,out] pHash the SzHash to be updated
 * @param[in] szKey the key string associates to szVal
 * @param[in] szVal the value string associated to szKey
 * @param[in,out] piSlot the pointer stored slot number and may
 *               be modified if the SzHash expends.
 *
 * @retval NULL memory allocation fail
 * @retval !NULL a pointer to SzHash the updated SzHash
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASH SLIBCSLIBIUpdateValue(PSLIBSZHASH pHash, const char *szKey, const char *szVal, int *piSlot);

/**
 * Returns the number of items in this SzHash
 * @p pHash.
 *
 * @param[in] pHash the SzHash to be referenced.
 *
 * @retval  -1 the @p pHash is NULL
 * @retval  >=0 the number of items in this SzHash
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashPairNum(const PSLIBSZHASH pHash);

/**
 * Returns the number of items in this SzHash
 * @p pHash.
 *
 * @param[in] pHash the SzHash to be referenced.
 *
 * @retval  -1 the @p pHash is NULL
 * @retval  >=0 the number of items in this SzHash
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashGetLength(const PSLIBSZHASH pHash);

/**
 * Serialize the hash structure by transferring every pointer
 * in the hash structure from storing absolute address
 * to relative address from structure head
 *
 * @note the hash structure after serialized must be
 * deserialized by calling SLIBCSzHashDeserialize() before use
 *
 * @param[in,out] pHash the SzHash to be serialized
 *
 * @retval  -1 this SzHash is an invalid hash or fail to serialize
 * @retval  0 success
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSerialize(PSLIBSZHASH pHash);

/**
 * Deerialize the hash structure by transferring every pointer
 * in the hash structure from storing relative address from
 * structure head to absolute address
 *
 * @note the hash structure after serialized must be
 * deserialized by calling SLIBCSzHashDeserialize() before use
 *
 * @param[in,out] pHash the SzHash to be deserialized
 *
 * @retval  -1 this SzHash is an invalid hash or fail to deserialize
 * @retval  0 success
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashDeserialize(PSLIBSZHASH pHash);

/**
 * @}
 */
