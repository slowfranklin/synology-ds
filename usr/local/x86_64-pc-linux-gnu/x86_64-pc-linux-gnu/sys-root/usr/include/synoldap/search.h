// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_SEARCH_H__
#define __SYNOLDAP_SEARCH_H__

#include <stdarg.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <availability.h>
#include <synocore/list.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

/**
 * @addtogroup search
 *
 * @brief Provides structures and APIs for LDAP search operation.
 *
 * @{
 */

typedef struct __tag__LDAP_HOST LDAP_HOST;
typedef struct __tag__LDAP_SCHEMA LDAP_SCHEMA;

#define MAX_FILTER_LEN 2048

/**
 * @brief Request handle for later ldapsearch command, refer ldapsearch's
 *        man page for details.
 *
 * @sa SYNOLDAPSearchInit()
 */
typedef struct __tag__LDAP_SEARCH_REQUEST {
	/** @brief RDN for search. */
	const char *szRDN;
	/** @brief Search filter. */
	const char *szFilter;
	/** @brief Sort result entries by this attribute. */
	const char *szSortAttr;
	/** @brief Search scope. */
	const char *szScope;
	/** @brief Attributes to query. */
	PSLIBSZLIST plistAttr;
	/** @brief Do not append base DN to `szRDN` if TRUE. */
	BOOL blIgnoreBaseDN;
	/** @brief Local paging offset. */
	int offset;
	/** @brief Local paging size limit, offset=0 & limit=0 for no limit. */
	int limit;
	/** @brief Max number of entries to return, 0 means no limit. */
	int sizeLimit;
} LDAP_SEARCH_REQUEST;

/**
 * @brief Result handle for some result entry returned by ldapsearch command.
 *
 * @sa SYNOLDAPSearchInit()
 */
typedef struct __tag__LDAP_RESULT {
	/** @brief File handle returned by `popen("/usr/bin/ldapsearch ...")`. */
	FILE *pfSearchResult;
	int cResponseObject;
	/** @brief List of attributes of result entry. */
	PSLIBSZLIST plistAttr;
	/** @brief Values of `plistAttr` respectively. */
	PSLIBSZLIST plistValue;
	/** @brief Exit code of ldapsearch command. */
	int exit_code;
	/** @brief Not used. */
	int error_code;
	/** @brief Not used. */
	char szErrorOut[256];
} LDAP_RESULT;

/**
 * @brief Check whether @p pResult initialized, return @p err_ret if not.
 */
#define SYNOLDAP_CHECK_RESULT_INITED(err_ret, pResult) \
	SYNOSDK_CHECK_ARGS(3, err_ret, NULL != pResult, NULL != pResult->plistAttr, NULL != pResult->plistValue);

/**
 * @brief Initialize @p pResult.
 *
 * @param[out] pResult  Result handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultInit(LDAP_RESULT *pResult);

/**
 * @brief Clone @p pSrc to @p pDst.
 *
 * @note @p pDst->szErrorOut will be empty string and
 *       @p pDst->pfSearchResult will be NULL.
 *
 * @param[out] pDst  Destination, must be initialized by
 *                   @a SYNOLDAPResultInit().
 * @param[in]  pSrc  Source, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultClone(LDAP_RESULT *pDst, const LDAP_RESULT *pSrc);

/**
 * @brief Push @p szAttr with @p szValue into @p pResult.
 *
 * @param[in,out] pResult  Result handle, must be initialized by
 *                         @a SYNOLDAPResultInit().
 * @param[in]     szAttr   LDAP attribute, must not be NULL.
 * @param[in]     szValue  Value for @p szAttr, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultSet(LDAP_RESULT *pResult, const char *szAttr, const char *szValue);

/**
 * @brief Concatenate last pushed value in @p pResult with @p szValue.
 *
 * @param[in,out] pResult  Result handle, must be initialized by
 *                @a SYNOLDAPResultInit().
 * @param[in]     szValue  Value for @p szAttr, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultConcateAttr(LDAP_RESULT *pResult, const char *szValue);

/**
 * @brief Get value of first occurence of @p szAttr from @p pResult.
 *
 * @param[in] pResult  Result handle, must be initialized by
 *                     @a SYNOLDAPResultInit().
 * @param[in] szAttr   LDAP attribute, must not be NULL.
 *
 * @return Value of first occurence of @p szAttr, NULL if not found.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) const char *SYNOLDAPResultGetFirst(const LDAP_RESULT *pResult, const char *szAttr);

/**
 * @brief Get all values of @p szAttr from @p pResult.
 *
 * @param[in]  pResult       Result handle, must be initialized by
 *                           @a SYNOLDAPResultInit().
 * @param[in]  szAttr        LDAP attribute, must not be NULL.
 * @param[out] pplistValues  List of result values, must not be NULL.
 *
 * @return Number of values or -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultGetAll(const LDAP_RESULT *pResult, const char *szAttr, PSLIBSZLIST *pplistValues);

/**
 * @brief Get LDAP attribute and corresponding value at @p index from @p pResult.
 *
 * @note Non-NULL @p *pszValue causes memory leak if it originally points to
 *       some buffer which is not refered by others.
 *
 * @param[in]  pResult   Result handle, must be initialized by
 *                       @a SYNOLDAPResultInit().
 * @param[in]  index     Index, must >=0.
 * @param[out] pszValue  Corresponding value, must not be NULL.
 *
 * @return LDAP attribute at @p index or NULL if out of range.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) const char *SYNOLDAPResultGetAt(const LDAP_RESULT *pResult, int index, const char **pszValue);

/**
 * @brief Get number of LDAP attributes in @p pResult.
 *
 * @param[in] pResult  Result handle, must be initialized by
 *                     @a SYNOLDAPResultInit().
 *
 * @return Number of LDAP attributes or -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultGetAttrCount(const LDAP_RESULT *pResult);

/**
 * @brief Remove all LDAP attributes and values from @p pResult.
 *
 * @param[in,out] pResult  Result handle, must be initialized by
 *                         @a SYNOLDAPResultInit().
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultRemoveAll(LDAP_RESULT *pResult);

/**
 * @brief Free @p pResult.
 *
 * @param[in] pResult  Result handle, NULL is ignored.
 *
 * @return Always 0.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPResultFree(LDAP_RESULT *pResult);

/**
 * @brief Build ldapsearch command @p szCmd from @p pHost and @p pRequest for
 *        ease of debugging.
 *
 * @param[in]  pHost       Host handle, must not be NULL.
 * @param[in]  pRequest    Request handle, must not be NULL.
 * @param[out] szCmd       Result command, must not be NULL.
 * @param[in]  cbCmd       Size of @p szCmd, must >0.
 * @param[in]  szErrorOut  Not used.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchBuildRequestCmd(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, char *szCmd, size_t cbCmd, const char *szErrorOut);

/**
 * @brief Start ldapsearch with given @p pHost and @p pRequest, set temporary
 *        information and result to @p pRequest.
 *
 * Use @a SYNOLDAPSearchFree() to release resources in @p pRequest and @p pRequest.
 *
 * After the search command complete, you can check the ldapsearch exit code in
 * @p pResult->exit_code.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  pRequest  Request handle, must not be NULL.
 * @param[out] pResult   Result handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchInit(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, LDAP_RESULT *pResult);

/**
 * @brief Get next LDAP entry from @p pResult->pfSearchResult in the range
 *        specified by @p pRequest->offset and @p pRequest->limit, then
 *        stored it in @p pResult.
 *
 * @param[in]     pRequest  Request handle, must not be NULL.
 * @param[in,out] pResult   Result handle, must be initialized by
 *                          @a SYNOLDAPSearchInit().
 *
 * @retval  1 Success.
 * @retval  0 No more results.
 * @retval -1 Error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_READ_FAILED
 * @exception SLIBCBase64Decode()
 * @exception SYNOLDAPResultConcateAttr()
 * @exception SYNOLDAPResultSet()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchGetNext(const LDAP_SEARCH_REQUEST *pRequest, LDAP_RESULT *pResult);

/**
 * @brief Free @p pRequest and @p pRequest.
 *
 * @param[in] pRequest  Request handle, NULL is ignored.
 * @param[in] pResult   Result handle, NULL is ignored.
 *
 * @return Always 0
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchFree(LDAP_SEARCH_REQUEST *pRequest, LDAP_RESULT *pResult);

/**
 * @brief Start ldapsearch with given @p pHost and @p pRequest, invoke
 *        @p pResultHandler for each LDAP entry returned.
 *
 * @p pResultHandler returns 0 to process next entry, positive value to stop,
 * negative value on error. Negative value also stops the process and is taken
 * as return of this function.
 *
 * @param[in] pHost           Host handle, must not be NULL.
 * @param[in] pResuest        Request handle, must not be NULL.
 * @param[in] pResultHandler  Callback function, must not be NULL.
 * @param[in] pTrunk          User data for @p pResultHandler.
 *
 * @return 0 on success, otherwise, return code of @p pResultHandler.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchInit()
 * @exception SYNOLDAPSearchGetNext()
 *
 * @sa SYNOLDAPSearchInit()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchResultGet(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, int (*pResultHandler)(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, const LDAP_RESULT *pResult, void *pTrunk), void *pTrunk);

/**
 * @brief Initialize @p pRequest, allocate for query attributes if
 *        @p blAllocAttrList is TRUE.
 *
 * @param[out] pRequest         Request handle, must not be NULL.
 * @param[in]  blAllocAttrList  Allocate for query attributes or not.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchRequestInit(LDAP_SEARCH_REQUEST *pRequest, BOOL blAllocAttrList);

/**
 * @brief Free @p pRequest.
 *
 * @param[in] pRequest  Request handle, NULL is ignored.
 *
 * @return Always 0.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchRequestFree(LDAP_SEARCH_REQUEST *pRequest);

/**
 * @brief Clone @p pRequestDst to @p pRequestSrc.
 *
 * @note All `const char *` fields are shared by @p pRequestDst and @p pRequestSrc,
 *       __DO NOT__ change them.
 *
 * @param[out]  pRequestDst  Destination, must not be NULL.
 * @param[in]   pRequestSrc  Source, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchRequestClone(LDAP_SEARCH_REQUEST *pRequestDst, const LDAP_SEARCH_REQUEST *pRequestSrc);

/**
 * @brief Start ldapsearch with given @p pHost and @p pRequest, get @p szAttr
 *        for each returned LDAP entry. Result DN and value are pushed to
 *        @p pplistDN and @p pplistValue respectively.
 *
 * If some entry has multiple values for @p szAttr, the first one is taken.
 * If some entry has no @p szAttr, empty value is pushed to @p pplistValue.
 *
 * @param[in]  pHost        Host handle, must not be NULL.
 * @param[in]  pRequest     Request handle, must not be NULL.
 * @param[in]  szAttr       Attribute to query, must not be NULL.
 * @param[out] pplistDN     Result DNs, must not be NULL.
 * @param[out] pplistValue  Result values, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchResultGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchEachValue(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, const char *szAttr, PSLIBSZLIST *pplistDN, PSLIBSZLIST *pplistValue);

/**
 * @brief Start ldapsearch with given @p pHost and @p pRequest, get all values
 *        of @p szAttr.
 *
 * @param[in]  pHost        Host handle, must not be NULL.
 * @param[in]  pRequest     Request handle, must not be NULL.
 * @param[in]  szAttr       Attribute to query, must not be NULL.
 * @param[out] pplistValue  Result values, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchResultGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchMultiValue(const LDAP_HOST *pHost, const LDAP_SEARCH_REQUEST *pRequest, const char *szAttr, PSLIBSZLIST *pplistValue);

/**
 * @brief Start ldapsearch with given @p pHost, @p pRequest and @p szFilter,
 *        get first @p szAttr of @p szDN. If no @p szAttr found, set @p szValue
 *        as empty string.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  szDN      DN, must not be NULL.
 * @param[in]  szFilter  Search filter, NULL means no filter.
 * @param[in]  szAttr    Attribute to query, must not be NULL.
 * @param[out] szValue   Result first value, must not be NULL.
 * @param[in]  cbValue   Size of @p szValue, must >0.
 *
 * @return Number of @p szAttr in @p szDN, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchMultiValue()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchGetValueByDN(const LDAP_HOST *pHost, const char *szDN, const char *szFilter, const char *szAttr, char *szValue, size_t cbValue);

/**
 * @brief Start ldapsearch with given @p pHost and @p szFilter, get object
 *        classes of @p szDN.
 *
 * @param[in]  pHost     Host handle, must not be NULL.
 * @param[in]  szDN      DN, must not be NULL.
 * @param[in]  szFilter  Search filter, NULL means no filter.
 * @param[out] pSchema   Result object classes, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOLDAPSearchResultGet()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPSearchObjectClasses(const LDAP_HOST *pHost, const char *szDN, const char *szFilter, LDAP_SCHEMA *pSchema);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_SEARCH_H__
// vim:ts=4 sts=4 sw=4
