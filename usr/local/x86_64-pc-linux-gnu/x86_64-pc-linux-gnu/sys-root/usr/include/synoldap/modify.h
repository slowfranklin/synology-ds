// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_MODIFY_H__
#define __SYNOLDAP_MODIFY_H__

#include <stdarg.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <availability.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

/**
 * @addtogroup modify
 *
 * @brief Provides structures and APIs for LDAP modify operations.
 *
 * @{
 */

typedef struct __tag__LDAP_HOST LDAP_HOST;

/**
 * @brief LDIF handle, use `SYNOLDAPLdif*()` to update underlying LDIF file
 *        for later ldapmodify command.
 *
 * Most fields, except `exit_code`, are for internal use so callers don't have
 * to inspect them.
 *
 * @sa SYNOLDAPModify()
 */
typedef struct __tag__LDAP_LDIF {
	/** @brief File handle of `szFileName`. */
	FILE *pFile;
	/** @brief Underlying LDIF file. */
	char szFileName[256];
	int total_attr;
	int count_attr;
	int count_dn;
	/** @brief Exit code of ldapmodify command. */
	int exit_code;
	int error_code;
} LDAP_LDIF;

/**
 * @brief Check whether @p pLDIF readable, return @p err_ret if not.
 *
 * @note Underlying LDIF file will be closed if it's readable.
 *
 * @sa SYNOLDAPLdifClose()
 */
#define SYNOLDAP_CHECK_LDIF_CAN_READ(err_ret, pLDIF) do { \
	SYNOSDK_CHECK_ARGS(2, err_ret, NULL != pLDIF, 0 != strlen(pLDIF->szFileName)); \
	SYNOLDAPLdifClose(pLDIF);                                                      \
} while (0)

/**
 * @brief Initialize @p pLDIF and open @p szFileName for write as underlying
 *        LDIF file.
 *
 * @param[out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]  szFileName  Underlying LDIF file,
 *                         default `/tmp/${pid}_${count}.ldif` if NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifInit(LDAP_LDIF *pLDIF, const char *szFileName);

/**
 * @brief Write (next) target DN @p szDN to @p pLDIF.
 *
 * @param[in,out] pLDIF  LDIF handle, must not be NULL.
 * @param[in]     szDN   Target DN, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifTargetDN(LDAP_LDIF *pLDIF, const char *szDN);

/**
 * @brief Write changeType @p szType to @p pLDIF.
 *
 * @param[in,out] pLDIF   LDIF handle, must not be NULL.
 * @param[in]     szType  Change type, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifChangeType(LDAP_LDIF *pLDIF, const char *szType);

/**
 * @brief Write an arbitrary line to @p pLDIF with specified format
 *        @p szValueFmt and arguments.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szValueFmt  Format string, NULL to write an empty line.
 * @param[in]     ...         Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifLine(LDAP_LDIF *pLDIF, const char *szValueFmt, ...);

/**
 * @brief Write "-" as a line to @p pLDIF, it's separator for attributes in
 *        one LDAP entry. If there's no previous attribute, nothing is done.
 *
 * @param[in,out] pLDIF  LDIF handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifSepAttr(LDAP_LDIF *pLDIF);

/**
 * @brief Write a line with specified format @p szValueFmt and arguments to
 *        @p pLDIF as base64-encoded value for @p szAttr. If the encoding
 *        failed, non-encoded value is written.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute, must not be NULL.
 * @param[in]     szValueFmt  Format string, must not be NULL.
 * @param[in]     ...         Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCBase64SzEncodeOneLine()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifAttr64(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, ...);

/**
 * @brief Write a line with specified format @p szValueFmt and @p ap to
 *        @p pLDIF as base64-encoded value for @p szAttr. If the encoding
 *        failed, non-encoded value is written.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute, must not be NULL.
 * @param[in]     szValueFmt  Format string, must not be NULL.
 * @param[in]     ap          Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCBase64SzEncodeOneLine()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifVAttr64(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, va_list ap);

/**
 * @brief Write a line with specified format @p szValueFmt and arguments to
 *        @p pLDIF as value for @p szAttr.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute, must not be NULL.
 * @param[in]     szValueFmt  Format string, must not be NULL.
 * @param[in]     ...         Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifAttr(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, ...);

/**
 * @brief Write a line with specified format @p szValueFmt and @p ap to
 *        @p pLDIF as value for @p szAttr.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute, must not be NULL.
 * @param[in]     szValueFmt  Format string, must not be NULL.
 * @param[in]     ap          Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifVAttr(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, va_list ap);

/**
 * @brief Update @p pLDIF to replace @p szAttr with value specified by format
 *        @p szValueFmt and arguments.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute to replace, must not be NULL.
 * @param[in]     szValueFmt  Format string, must not be NULL.
 * @param[in]     ...         Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifAttrReplace(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, ...);

/**
 * @brief Update @p pLDIF to delete all @p szAttr or those with value
 *        specified by format @p szValueFmt and arguments.
 *
 * @p szValueFmt should be something like the second parameter for printf().
 *
 * @param[in,out] pLDIF       LDIF handle, must not be NULL.
 * @param[in]     szAttr      LDAP attribute to delete, must not be NULL.
 * @param[in]     szValueFmt  Format string, NULL to delete all values of @p szAttr.
 * @param[in]     ...         Arguments for @p szValueFmt.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifAttrDelete(LDAP_LDIF *pLDIF, const char *szAttr, const char *szValueFmt, ...);

/**
 * @brief Check whether @p pLDIF "empty" which means no underlying LDIF file or
 *        no attribute is written.
 *
 * @param[in] pLDIF  LDIF handle, must not be NULL.
 *
 * @return Empty or not.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOLDAPLdifIsEmpty(const LDAP_LDIF *pLDIF);

/**
 * @brief Close underlying LDIF file of @p pLDIF.
 *
 * @param[in,out] pLDIF  LDIF handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifClose(LDAP_LDIF *pLDIF);

/**
 * @brief Unlink underlying LDIF file of @p pLDIF if not in debug mode.
 *
 * @param[in,out] pLDIF  LDIF handle, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @sa SYNOLDAPDebugEnabled()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPLdifUnlink(LDAP_LDIF *pLDIF);

/**
 * @brief Start ldapmodify with given @p pHost and @p pLDIF.
 *
 * If @p pLDIF is empty, nothing is done.
 *
 * @note Underlying LDIF file of @p pLDIF will be closed.
 *
 * @param[in] pHost  Host handle, must not be NULL.
 * @param[in] pLDIF  LDIF handle, must be initialized by @a SYNOLDAPLdifInit().
 * @param[in] blAdd  TRUE to add new entry.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @sa SYNOLDAPLdifClose(), SYNOLDAPLdifIsEmpty()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPModify(const LDAP_HOST *pHost, LDAP_LDIF *pLDIF, BOOL blAdd);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_MODIFY_H__
// vim:ts=4 sts=4 sw=4
