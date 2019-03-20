/**
 * @addtogroup LIST
 *
 * @{
 */

/**
 * Allocates @p size bytes of for the struct
 * SLIBSZLIST, initializes members in this struct and set
 * SLIBSZLIST::fMode to LIST_SORT_OP::OP_UNSORTED.
 *
 * @param[in]    size    The number of memory you want to allocate.
 *                       If @p size is less than 512 bytes, set it to 512. (avoid too many expansion of memory)
 *
 * @retval !NULL  A pointer to the new struct success
 * @retval NULL   Failed to allocate.
 *
 * @exception ERR_OUT_OF_MEMORY if SYNOMAlloc() fail to allocate @p size bytes.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCSzListAlloc(int size);

/**
 * Uses binary search to find a specified string
 * @p szPtn in this SzList @p pList and
 * return the index of matched item.
 *
 * If @p blCaseless is not zero, this function will
 * perform a caseless searching by invoking
 * SLIBCUnicodeUTF8StrCaseCmp(). However, the
 * SLIBSZLIST::fMode must be LIST_SORT_OP::OP_SORTED or
 * LIST_SORT_OP::OP_UNICODE_SORTED.
 *
 * @param[in] pList the SzList to be searched.
 * @param[in] iHigh the higher boundary to search.
 * @param[in] iLow the lower boundary be search.
 * @param[in] szPtn the string to be matched.
 * @param[in] blCaseless the boolean flag to use caseless search or not. Non-zero value will lead to caseless search.
 *
 * @retval  >=0  index of the found item
 * @retval  <0  -1 * (the position of the not-found item should be) - 1
 *
 * @exception SLIBCUnicodeUTF8StrCaseCmp()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListFindIndex(const PSLIBSZLIST pList, int iHigh, int iLow, const char *szPtn, const BOOL blCaseless);

/**
 * Finds a specified string @p szPtn(ignore case) in
 * this SzList @p pList and returns its index. If
 * error occurs, return NULL.
 *
 * This function only performs a search when SLIBSZLIST::fMode
 * is LIST_SORT_OP::OP_UNICODE_SORTED or
 * LIST_SORT_OP::OP_UNSORTED. If SLIBSZLIST::fMode is
 * LIST_SORT_OP::OP_SORTED, please use SLIBCSzListFind() instead.
 *
 * When fMode of this SzList is OP_UNICODE_SORTED, this function
 * will perform a binary search by SLIBCSzListFind(). Otherwize,
 * it will do a linear seach by call SLIBCUnicodeUTF8StrCaseCmp()
 * to each SzList items.
 *
 * @param[in] pList the SzList to be searched. Can not be Null.
 * @param[in] szPtn the string to be matched. Can not be Null.
 *
 * @retval  >=0 the index of matched pattern in this SzList
 * @retval  -1 not found
 *
 * @exception ERR_BAD_PARAMETERS if @p pList or @p szPtn is NULL.
 * @exception ERR_BAD_PARAMETERS if the @p fMode in @p pList is OP_SORTED.
 * @exception SLIBCSzListFindIndex()
 * @exception SLIBCUnicodeUTF8StrCaseCmp()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListCaseFind(PSLIBSZLIST pList, const char *szPtn);

/**
 * Defragments a SzList @p pList and make it ready for
 * sorting. A sorted list can not have unspecified items in the
 * SLIBSZLIST::pszItem array. So this function will wipe
 * out the unspecified items from @p pszItem[0] to
 * @p pszItem[pList->nItem].
 *
 * This fucntion will update SLIBSZLIST::nFree and
 * SLIBSZLIST::nItem in SzList @p pList
 * according to the number of unspecified items that was wiped
 * out.
 *
 * @param[in,out] pList the SzList to be defragment.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzListClean(PSLIBSZLIST pList);

/**
 * Transforms a SLIBSZLIST pList into SYNOPACKEDLIST.
 *
 * @param[in] pList The SLIBSZLIST that to be transformed. Should not be NULL.
 * @param[in] cbListSize The length of SLIBSZLIST. Should be positive.
 *
 * @retval !NULL a SYNOPACKEDLIST
 * @retval NULL On error
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SYNOListDBUnPack()
 */
PSYNOPACKEDLIST SLIBCListDBPack(const PSLIBSZLIST pList, const size_t cbListSize);

/**
 * Sets PSLIBSZLIST into PSYNOBDB pDb by key szKeyName.
 * The szKeyName is transfroms to upper case and treats as db key.
 *
 * @param[in] pDb The PSYNOBDB handler. Should not be NULL.
 * @param[in] szKeyName The string of the key name. Should not be NULL.
 * @param[in] pList The list that to be stored in DB. Should not be NULL.
 *
 * @retval  0 On success.
 * @retval -1 On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCListDBSet(const PSYNOBDB pDb, const char *pszKey, const PSLIBSZLIST pList);

/**
 * @see SLIBCListDBSet.
 */
int SLIBCListDBSet1(const PSYNOBDB pDb, const char *pszKey, const PSLIBSZLIST pList, BOOL blAsMetadata);

/**
 * Gets PSLIBSZLIST from PSYNOBDB pDb by key szKeyName.
 * The szKeyName is transfroms to upper case and treats as db key.
 *
 * @param[in] pDb The PSYNOBDB handler. Should not be NULL.
 * @param[in] pszKey The string of the key name. Should not be NULL.
 *
 * @retval  NULL On success, should be freed by SLIBCSzListFree().
 * @retval !NULL On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCListDBGet(const PSYNOBDB pDb, const char *pszKey);

/**
 * @see SLIBCListDBGet.
 */
PSLIBSZLIST SLIBCListDBGet1(const PSYNOBDB pDb, const char *pszKey, BOOL blAsMetadata);

/**
 * Transforms a SYNOPACKEDLIST @p pData with size @p
 * cbPackedListSize into a mallocd SLIBSZLIST.  Caller should
 * return this resource by SLIBCSzListFree().
 *
 * @param[in] pData The SYNOPACKEDLIST that to be transformed. Should not be NULL.
 * @param[in] cbListSize The length of SYNOPACKEDSHARE. Should be positive.
 *
 * @retval !NULL a SLIBSZLIST.
 * @retval NULL On error.
 *
 * @see SLIBCListDBPack()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCListDBUnpack(const void *pData, const size_t cbListSize);

/**
 *  Expands SzList @p pList to double size, and copy
 *  the value to new list, and return a pointer to new list
 * 
 *  @note Implementation-Specific:
 *        1. Calls SYNOMAlloc() to allocate double size of original SzList for @p pslNew.
 *        2. Assigns value to elements in the pslNew.
 *        3. Copy the members in the original SzList to pslNew and do garbage collection.
 *        4. Calls SLIBCSzListFree() to free original SzList.
 *
 * @param[in,out] pList the SzList to expand. Cannot be NULL.
 *
 * @retval  !NULL  A pointer to the new struct success
 * @retval  NULL   Fail to allocate.
 *
 * @exception ERR_OUT_OF_MEMORY  if SYNOMAlloc() fails to allocate double size of @p pList
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCISzListExpand(PSLIBSZLIST pList);

/**
 * Finds a specified string @p szPtn in this SzList
 * @p pList and returns its index. NOTE: Allow
 * LIST_SORT_OP::OP_SORTED and unspecified sorted list to use. If
 * SLIBSZLIST::fMode is LIST_SORT_OP::OP_UNICODE_SORTED, please use
 * SLIBCSzListCaseFind().
 *
 * @param[in] pList the SzList to be searched.
 * @param[in] szPtn the string to be matched.
 *
 * @retval  >=0 the index of matched item.
 * @retval  -1 No item found or error.
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL
 *                               or @p szPtn is NULL
 *                               or @p pList->fMode is OP_UNICODE_SORTED.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListFind(const PSLIBSZLIST pList, const char *szPtn);

/**
 * Causes the allocated memory referenced by SzList
 * @p pList to be available for future allocation.
 *
 * @param[out]  pList    The SzList to be free
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzListFree(PSLIBSZLIST pList);

/**
 * Gets the @p idx-th item in the @p pList and
 * returns a pointer to the string. If the arguments are wrong,
 * returns NULL pointer. If the @p idx-th item has not
 * been specified, returns an empty string.
 *
 * @param[in] pList the SzList to reference.
 * @param[in] idx the index of specified item.
 *
 * @retval !NULL Success, pointer to the specified item.
 * @retval NULL  Error, @p pList is NULL or @p idx out of bound.
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL or @p idx out of bound.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzListGet(const PSLIBSZLIST pList, const int idx);

/**
 * Inserts the string @p szInsert from the
 * end of free space, and set @p pList->pszItem[idx]
 * point to it.
 *
 * If we try to insert a string whose @p index >=
 * @p nItem, it may cause some elements in the
 * SLIBSZLIST::pszItem array unspecified. We assign
 * unspecified one an empty string.
 *
 * If this SzList is sorted, the @p idx argument will
 * be ignored.
 *
 * @param[in,out] ppList the pointer of SzList to be inserted.
 * @param[in] idx the specified index to insert.
 * @param[in] szInsert the string to insert.
 *
 * @retval  >=0 the real index of newly inserted item. It may differ from @p idx if this SzList is sorted.
 * @retval  -1 fail and errno is seted to indicate the errnor.
 *
 * @exception ERR_BAD_PARAMETERS if NULL pointer as argument.
 * @exception ERR_OUT_OF_MEMORY if free space is not enough and memory allocation fails.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListInsert(PSLIBSZLIST *ppList, int idx, const char *szInsert);
/**
 * Adds string @p szNew to this SzList
 * @p ppList. The total number of items will add one.
 * If the list structure is sorted, the item may not add to the
 * last.
 *
 * The underlying operation is implemented by
 * SLIBCSzListInsert().
 *
 * @param[in,out] ppList the SzList to be added. Cannot be NULL.
 * @param[in] szNew the string to insert. Cannot be NULL.
 *
 * @retval  >=0 The index of successful added item.
 * @retval  -1 Failure, and sets errno to indicate the error.
 *
 * @exception ERR_BAD_PARAMETERS if @p ppList or @p szNew is NULL.
 * @exception SLIBCSzListInsert()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCSzListInsert()
 */
int SLIBCSzListPush(PSLIBSZLIST *ppList, const char *szNew);
/**
 * Shifts these itmes backwardly and add the string
 * @p szNew to the first position of this SzList
 * @p ppList. The return value is the index of the
 * item that puts the @p szNew argument. If this
 * SzList @p ppList is sorted, the function may not
 * put the string at the first position.
 *
 * The underlying operation is implemented by SLIBCSzListInsert().
 *
 * @param[in,out] ppList the pointer of SzList to be inserted
 * @param[in] szNew the string to insert
 *
 * @retval  >=0 returns the item's real index if successful,
 * @retval  -1 failure, and sets errno to indicate the error.
 *
 * @exception ERR_BAD_PARAMETERS if @p ppList is NULL or @p szNew is NULL
 * @exception SLIBCSzListInsert()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListUnshift(PSLIBSZLIST *ppList, const char *szNew);

/**
 * Removes the @p idx-th item from this SzList
 * @p pList, and returns the removed string. The items
 * behind the @p idx-th item will shift forwardly. For
 * example, if you have three items and call this function to
 * remove the second item, then the item2 will become item1. The return value is
 * the pointer to the original item0. After this operation, the
 * total number of items will subtract one.
 *
 * If you try to remove an empty list or a item that does not
 * exit in list, return NULL.
 *
 * @param[in,out] pList the SzList to maintain
 * @param[in] idx the index of specified string.
 *
 * @retval !NULL  Success, pointer to the removed item.
 * @retval NULL   If @p pList is NULL or @p idx out of bound.
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL or @p idx out of bound.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzListRemove(PSLIBSZLIST pList, const int idx);
/**
 * Shifts these items forwardly and returns the first item of
 * SzList @p pList if successful. For example, if you
 * have three items and call this function to remove the second
 * item, then the item2 will become item1. The return value is
 * the pointer to the original item0.
 *
 * The underlying operation is implemented by SLIBCSzListRemove().
 *
 * @param[in,out] pList the SzList to be maintained.
 *
 * @retval !NULL  a pointer to removed item success
 * @retval NULL   @p pList is NULL or operation fail
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzListShift(PSLIBSZLIST pList);
/**
 * Removes the last item of SzList @p pList and
 * returns a pointer to the string. After this operation, the
 * total number of items will subtract one. If error occurs,
 * return NULL.
 *
 * The underlying operation is implemented by SLIBCSzListRemove().
 *
 * @param[in,out] pList the SzList to maintain
 *
 * @retval !NULL   Success, pointer to the removed item.
 * @retval NULL    If @p pList is NULL or @p idx out of bound.
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL
 *                               or @p idx out of bound.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCSzListPop(PSLIBSZLIST pList);

/**
 * Removes all items stored in this SzList @p pList
 * and resets all members except SLIBSZLIST::fMode. We
 * leave it unchanged, because you may insert something into the
 * list again.
 *
 * @param[out] pList the SzList that to be clean up.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 */
void SLIBCSzListRemoveAll(PSLIBSZLIST pList);

/**
 * Sets the sort order of SzList @p pList as specified
 * as @p sorting. If the flag @p sorting is
 * LIST_SORT_OP::OP_SORTED or LIST_SORT_OP::OP_UNICODE_SORTED,
 * all elements in this list must in alphbetic order at any
 * time. A sorted list does not have unspecified items in the
 * SLIBSZLIST::pszItem array.
 *
 * @param[in,out] pList the SzList to be sorted
 * @param[in] sorting the enumerate of sorting methods.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSzListSortItems(PSLIBSZLIST pList, const LIST_SORT_OP sorting);

/**
 * Compares the two strings @p p1 and @p p2
 * in case sensitive by strcmp(), used by qsort().
 *
 * @param[in] p1 the pointer of string to be compared
 * @param[in] p2 the pointer of string to be compared
 *
 * @retval <0  @p p1 is less than @p2.
 * @retval 0   @p p1 is equal to @p2.
 * @retval >0  @p p1 is greater than @p2.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListStrcmp(const void *p1, const void *p2);

/**
 * Compares the two strings @p p1 and @p p2
 * in caseless by SLIBCUnicodeUTF8StrCaseCmp(), used by qsort().
 *
 * @param[in] p1 the pointer of string to be compared
 * @param[in] p2 the pointer of string to be compared
 *
 * @retval <0  @p p1 is less than @p2 caselessly.
 * @retval 0   @p p1 is equal to @p2 caselessly.
 * @retval >0  @p p1 is greater than @p2 caselessly.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListUTF8StrCasecmp(const void *p1, const void *p2);

/**
 * Dump list into string split by specified delim
 *
 * Ex: "synology,RD,QC,...,PM"
 *
 * @note if error occurred, @p szStr may contain incomplete string
 *
 * @param[in]   pslList   List
 * @param[in]   pDelim    Delimiter of string
 * @param[out]  szStr     Output string
 * @param[in]   cbStr     Number of bytes in @p szStr
 *
 * @retval >=0 output size
 * @retval -1 error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListDump2Str(const PSLIBSZLIST pslList, const char *pDelim, char *szStr, int cbStr);

/**
 * join list into string split by specified delim
 *
 * Ex: "synology,RD,QC,...,PM"
 *
 * @note if error occurred, szStr maybe contains incomplete string
 *
 * @param[in]  pslList  List
 * @param[in]  szDelim  Delimiter of string
 * @param[out] pszStr   Output string. if not enough, try to realloc.
 * @param[in]  pcbStr   Number of bytes in @p szStr.
 *
 * @retval >=0 output size
 * @retval -1 error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListJoin(const PSLIBSZLIST pslList, const char *szDelim, char **pszStr, int *pcbStr);

/**
 * Obtains a new SzList that is the union of two SzList
 * @p ppList1 and @p pList2. If
 * @p fOp is ::OP_CREATED, this funtion will allocate
 * a new memory block to hold the result. Otherwise, the result
 * is saved to @p ppList1. The return value is the
 * pointer to the result SzList if successful.
 *
 * @note
 * 1. If @p fOp is OP_CREATED, @p fMode of output SzList is set to LIST_SORT_OP::OP_UNSORTED except two SzLists are sorted.
 * 2. If @p fOp is not OP_CREATED, @p fMode is the same as List1 before operation.
 * 3. Assume that no duplicate elements in an input list.
 *
 * @param[in,out] ppList1 the pointer of SzList to be merged into
 * @param[in] pList2 the SzList to check only
 * @param[in] fOp if @p OP_CREATED, this function creates new SzList to hold the result.
 *
 * @retval !NULL a pointer to the result on success.
 * @retval NULL operation fail
 *
 * @exception ERR_BAD_PARAMETERS if SzList @p ppList1 or @p pList2 is NULL
 * @exception ERR_BAD_PARAMETERS if the @p fMode of SzList @p ppList1 and @p pList2 are not matched.
 * @exception SLIBCSzListAlloc()
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCSzListOr(PSLIBSZLIST *ppList1, const PSLIBSZLIST pList2, const int fOp);

/**
 * Obtains a new SzList that is the join of two SzList
 * @p pList1 and @p pList2. If
 * @p fOp is ::OP_CREATED, this funtion will
 * allocate a new memory block to hold the result. Otherwise,
 * the result is saved to @p pList1. The return value is the
 * pointer to the result SzList if successful.
 *
 * @note
 * 1. If @p fOp is OP_CREATED, @p fMode of output SzList is set to LIST_SORT_OP::OP_UNSORTED except two SzLists are sorted.
 * 2. If @p fOp is not OP_CREATED, @p fMode is the same as List1 before operation.
 * 3. Assume that no duplicate elements in an input list.
 *
 * @param[in,out] pList1 the SzList to modified
 * @param[in] pList2 the SzList to check only
 * @param[in] fOp if @p OP_CREATED, this function creates new SzList to hold the result.
 *
 * @retval !NULL a pointer to the result on success.
 * @retval NULL operation fail
 *
 * @exception ERR_BAD_PARAMETERS if SzList @p pList1 or @p pList2 is NULL
 * @exception ERR_BAD_PARAMETERS if the @p fMode of SzList @p pList1 and @p pList2 are not matched.
 * @exception SLIBCSzListAlloc()
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCSzListAnd(PSLIBSZLIST pList1, const PSLIBSZLIST pList2, const int fOp);

/**
 * Dumps each string items and SzList statistics of this SzList
 * @p p to standard output.
 *
 * @param[in] p the SzList to retrieve information
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCISzListDump(const PSLIBSZLIST p);

/**
 * Sets the value of @p idx-th item in SzList
 * @p ppList to new value that stored in string
 * @p szNew. The index @p idx will be
 * ignored if SzList @p ppList is sorted. The return
 * value is its index if successful.
 *
 * If this SzList is sorted, the value of that item located at
 * @p idx will be set to @p szNew first.
 * Then this SzList will be sorted again. The return value will
 * be the new position not @p idx.
 *
 * @param[in,out]   ppList   the pointer of SzList to insert.
 * @param[in]       idx      the index of new string, will be ignored if @p ppList is sorted.
 * @param[in]       szNew    the string to be inserted.
 *
 * @retval  >=0 the index of newly inserted items.
 * @retval  -1 error
 *
 * @exception ERR_BAD_PARAMETERS if @p ppList is NULL or @p szNew is NULL or @p idx is out of bound.
 * @exception SLIBCSzListFind()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListSet(PSLIBSZLIST *ppList, int idx, const char *szNew);

/**
 * Detects whether the SzList @p pList is sorted and
 * returns the value of @p fMode. The mode of list is
 * changed by programmers themselves except that (AND/OR/SUB)
 * two sorted list also produce a "SORTED" list.
 *
 * @param[in] pList the SzList to be detected
 *
 * @retval  >=0 the enumerate of OP_SORTED, OP_UNICODE_SORTED, or OP_UNSORTED
 * @retval  -1 the pList is NULL.
 *
 * @exception ERR_BAD_PARAMETERS if @p pList is NULL.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSzListSorted(const PSLIBSZLIST pList);

/**
 * Obtains a new SzList that is the subtraction of two SzList
 * @p pList1 and @p pList2
 * (@p pList1 - @p pList2). If
 * @p fOp is ::OP_CREATED, this funtion will allocate
 * a new memory block to hold the result. Otherwise, the result
 * is saved to @p pList1. The return value is the
 * pointer to the result SzList if successful.
 *
 * @note
 * 1. If @p fOp is OP_CREATED, @p fMode of output SzList is set to LIST_SORT_OP::OP_UNSORTED except two SzLists are sorted.
 * 2. If @p fOp is not OP_CREATED, @p fMode is the same as List1 before operation.
 * 3. Assume that no duplicate elements in an input list.
 *
 * @param[in,out] pList1 the SzList to modified
 * @param[in] pList2 the SzList to check only
 * @param[in] fOp if @p OP_CREATED, this function creates new SzList to hold the result.
 *
 * @retval !NULL A pointer to the result on success.
 * @retval NULL  Operation fail
 *
 * @exception ERR_BAD_PARAMETERS if SzList @p ppList1 or @p ppList2 is NULL
 * @exception ERR_BAD_PARAMETERS if the @p fMode of SzList @p ppList1 and @p ppList2 are not matched.
 * @exception SLIBCSzListAlloc()
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBSZLIST SLIBCSzListSub(PSLIBSZLIST pList1, const PSLIBSZLIST pList2, const int fOp);

/**
 * @}
 */
