/**
 * @addtogroup MRESULT
 *
 * @{
 */

/**
 * Initializes SLIBCMRESULT to contain @p nItems records result.
 * @p pMResult should be inited before use or reuse.
 *
 * @param[in] pMResultNew reference to SLIBCMRESULT
 * @param[in] nItems number of records contained in SLIBCMRESULT
 * @param[in] err inititial value of each core operation error
 *
 * @retval  !NULL a pointer to the new struct success
 * @retval  NULL fail to allocate.
 *
 * @exception SLIBCMResultExpand()
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCMRESULT SLIBCMResultInit(PSLIBCMRESULT pMResult, size_t nItems, SYNOERR err);

/**
 *  Expands SLIBCMRESULT @p pMResult to double size,
 *  and copy the value to new list, and return a pointer to
 *  new list
 *
 * @retval !NULL a pointer to the new struct success
 * @retval NULL fail to allocate.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCMRESULT SLIBCMResultExpand(PSLIBCMRESULT pMResult, size_t iNeeded);

/**
 * Set a plugin action error to SLIBCMRESULT @p pMResult
 *
 * @param[in,out] pMResult the SLIBCMRESULT to be set, should not be NULL.
 *
 * @retval  0 success
 * @retval -1 fail
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMResultSetPluginError(PSLIBCMRESULT pMResult);

/**
 * Set single core action error to @p SLIBCMRESULT pMResult
 *
 * @param[in,out]   pMResult   The SLIBCMRESULT to be set, should not be NULL.
 * @param[in]       idx        The index of the core operation corresponds to the @p errOp
 * @param[in]       errOp      The SYNOERR to be set
 *
 * @retval  0 success
 * @retval -1 fail
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMResultSetCoreError(PSLIBCMRESULT pMResult, size_t idx, SYNOERR errOp);

/**
 * Get errors of a batch of core actions in SLIBCMRESULT @p pMResult
 *
 * @param[in] pMResult the SLIBCMRESULT contains the queried batch action. Should not be NULL.
 *
 * @retval  !NULL A pointer to SYNOERR* success
 * @retval  NULL  Fail
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
const SYNOERR *SLIBCMResultCoreErrorsGet(const PSLIBCMRESULT pMResult);

/**
 * Check if any error occurred in a batch of core actions.
 *
 * @param[in] pMResult the SLIBCMRESULT contains the queried batch action. Should not be NULL.
 *
 * @retval  TRUE no error in a batch of core actions
 * @retval  FALSE at least one error occurred in a batch of core actions
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCMResultCoreSuccess(const PSLIBCMRESULT pMResult);

/**
 * Check if any error occurred in plugin actions.
 *
 * @param[in] pMResult the SLIBCMRESULT contains the queried plugin action. Should not be NULL.
 *
 * @retval  TRUE no error in plugin actions
 * @retval  FALSE at least one error occurred in plugin actions
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCMResultPluginSuccess(const PSLIBCMRESULT pMResult);

/**
 * Get an error of core actions in SLIBCMRESULT @p pMResult by Index idx
 *
 * @param[in] pMResult the SLIBCMRESULT contains the queried batch action. Should not be NULL.
 * @param[in] idx the index of the core operation
 * @param[out] ret the SYNOERR
 *
 * @retval  0 Success
 * @retval  -1 On error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMResultGetCoreErrorByIndex(const PSLIBCMRESULT pMResult, size_t idx, SYNOERR *pRet);

/**
 * Allocates memory for SLIBCMRESULT
 *
 * @retval  !NULL a pointer to the new struct success
 * @retval  NULL fail to allocate.
 *
 * @grantable No
 *
 * @apparmor None.
 */
PSLIBCMRESULT SLIBCMResultAlloc(void);

/**
 * Causes the allocated memory referenced by SLIBCMRESULT
 * @p pMResult to be available for future allocation.
 *
 * @param[in,out] pList the PSLIBCMRESULT to be free
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCMResultFree(PSLIBCMRESULT pMResult);

/**
 * @}
 */
