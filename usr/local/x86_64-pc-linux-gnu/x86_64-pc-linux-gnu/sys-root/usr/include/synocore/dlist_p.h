/**
 * @addtogroup DLIST
 *
 * @{
 */

/**
 * Allocate a SLIBCDLIST.
 * When a new element insert into SLIBCDLIST by SLIBCDListPrepend
 * or SLIBCDListAppend, it will "copy" the element if @p func_copy is specified.
 * Hence when @p func_copy is given, it should also give @p func_free.
 *
 * @retval !NULL A new SLIBCLIST.
 * @retval NULL on error.
 *
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCDLIST SLIBCDListAlloc(PSLIBCDLIST_COPY_FUNC func_copy, PSLIBCDLIST_FREE_FUNC func_free);

/**
 * Delete a Node from list and free it and it's data.
 *
 * @param[in] pList the list to be deleted from.
 * @param[in] pNode the node to be deleted.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @see SLIBCDListRemove
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDListDelete(PSLIBCDLIST pList, PSLIBCDLIST_NODE pNode);

/**
 * Traverse the list and stop when finish or @func return not zero.
 *
 * @param[in] pList a pointer to list.
 * @param[in] func the traverse function called with node data.
 * @param[in] pUserData the user data pass to func.
 *
 * @retval 0 success.
 * @retval non-zero the return value by func with break the traverse.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDListForEach(PSLIBCDLIST pList, PSLIBCDLIST_FUNC func, void *pUserData);

/**
 * Allocate one SLIBCDLIST node SLIBCDLISTNODE.
 * It is called by SLIBCDListAppen(), SLIBCDLIstPrepend,
 * SLIBCDLIstInsert().
 *
 * @retval !NULL A new SLIBCLIST node
 * @retval NULL on error.
 *
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCDLIST_NODE SLIBCDListNodeAlloc(void);

/**
 * Free one SLIBCDLISTNODE.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCDListNodeFree(PSLIBCDLIST_NODE pNode);

/**
 * Get the previous Node to this node.
 *
 * @param[in] pNode this node.
 *
 * @retval !NULL the prev node.
 * @retval NULL there is no next node.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCDLIST_NODE SLIBCDListPrevNodeGet(PSLIBCDLIST_NODE pNode);

/**
 * Append pData to the end of the list.
 *
 * @param[in,out] pList the list to be appended.
 * @param[in] pData the data for the new node.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDListAppend(PSLIBCDLIST pList, void *pData);

/**
 * Get First Node from list.
 *
 * @param[in,out] pList a list.
 *
 * @retval !NULL the first list node.
 * @retval NULL there is no first node.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCDLIST_NODE SLIBCDListFirstNodeGet(PSLIBCDLIST pList);

/**
 * Free the entired list and data.
 *
 * @param[in] pList a list to be freed.
 * @param[in] func a free function for node data.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDListFree(PSLIBCDLIST pList);

/**
 * Get the next Node to this node.
 *
 * @param[in] pNode this node.
 *
 * @retval !NULL the next node.
 * @retval NULL there is no next node.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCDLIST_NODE SLIBCDListNextNodeGet(PSLIBCDLIST_NODE pNode);

/**
 * Get the data in this node.
 *
 * @param[in] pNode this node.
 *
 * @retval !NULL the node data.
 * @retval NULL there is no node data.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void *SLIBCDListNodeDataGet(PSLIBCDLIST_NODE pNode);

/**
 * Prepend a element with pData on the start of the list.
 *
 * @param[in,out] pList the list to be prepended.
 * @param[in] pData the data for the new element.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCDListPrepend(PSLIBCDLIST pList, void *pData);

/**
 * Remove a Node from list and retrive the data.
 * The data should be free manually by caller.
 *
 * @param[in] pList the list.
 * @param[in] pNode the node to be removed.
 * @param[out] ppData the node data retrieve from node.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCDListDelete
 */
int SLIBCDListRemoveLink(PSLIBCDLIST pList, PSLIBCDLIST_NODE pNode, void **ppData);

/**
 * @}
 */
