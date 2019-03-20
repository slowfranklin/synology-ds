/**
 * @addtogroup HASHSET
 *
 * @{
 */

/**
 * Add a @p szValue to @p ppHashSet.
 *
 * @param[in,out] ppHashSet the pointer to PSLIBSZHASHSET
 * @param[in] szValue the value string that will be added.
 *
 * @retval -1 on error.
 * @retval 0 on success.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetAdd(PSLIBSZHASHSET *ppHashSet, const char *szValue);

/**
 * Allocates @p BufferSize bytes for SLIBSZHASHSET and
 * initializes number of entries as @p nHashSlots.
 *
 * @param[in] nHashsetSlots the number of hash slots you want to
 *                   allocate.
 * @param[in] BufferSize the number of memory you want to
 *                   allocate.
 *
 * @retval !NULL success
 * @retval NULL fail to allocate memory.
 *
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASHSET SLIBCSzHashSetAllocator(const int nHashSlots, const int BufferSize);

/**
 * Allocates size bytes for SLIBSZHASHSET, initializes
 * number of table slots as 31.
 *
 * @param[in] size the number of memory you want to allocate. Set to 512 if less than 512.
 *
 * @retval !NULL success
 * @retval NULL on error.
 *
 * @exception SLIBCSzHashSetAllocator()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZHASHSET SLIBCSzHashSetAlloc(int size);

/**
 * Check if @p szValue is a member of @p pHashSet
 *
 * @param[in] pHashSet the hashset to find.
 * @param[in] szValue the string to be finded.
 *
 * @retval TRUE is a member.
 * @retval FALSE is not a member.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCSzHashSetContains(const PSLIBSZHASHSET pHashSet, const char *szValue);

/**
 * free for @p pHashSet
 *
 * @param[in] pHashSet the poiniter to be free
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzHashSetFree(PSLIBSZHASHSET pHashSet);

/**
 * Returns the number of items in this pHashSet.
 *
 * @param[in] pHashSet the hashset to be referenced.
 *
 * @retval -1 on error.
 * @retval >=0 the number of items in this hashset.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetItemNum(const PSLIBSZHASHSET pHashSet);

/**
 * Looks up value @p szValue from hashset @p pHashSet
 * and returns the slot number of match entry.
 * If not entry match, return an empty slot number.
 *
 * @param[in] pHashSet the hashset to look up
 * @param[in] szVlaue the value to be looked up
 *
 * @retval >=0 slot number.
 * @retval -1 on error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetLookDict(const PSLIBSZHASHSET pHashSet, const char *szValue);

/**
 * Push all hashset @pHashSet items to list @p ppslList.
 *
 * @param[in] pHashSet the hashset to be exported
 * @param[in,out] ppslList the list to stored into. should not be NULL.
 *
 * @retval 0 on sucess.
 * @retval -1 on error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetToList(const PSLIBSZHASHSET pHashSet, PSLIBSZLIST *ppslList);

/**
 * Removes all items in this hashset @p pHashSet.
 *
 * @param[in,out] pHash the hashset to be cleaned up.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzHashSetRemoveAll(PSLIBSZHASHSET pHashSet);

/**
 * Removes the item @p szValue in the hashset @p pHashSet.
 *
 * @param[in,out]   pHashSet    The hashset to be modified.
 * @param[in]       szValue     The value to be removed.
 *
 * @retval 0 on success.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzHashSetRemove(PSLIBSZHASHSET pHashSet, const char *szValue);

/**
 * @}
 */
