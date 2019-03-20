// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_ERROR_H__
#define __SYNOLDAP_ERROR_H__

#include <sys/cdefs.h>
#include <availability.h>

__BEGIN_DECLS;

/**
 * @addtogroup error
 *
 * @brief Define error codes which might be standard exit code of LDAP commands
 *        or Synology error defines (i.e. `SYNOLDAP_ERR_*`), the former are
 *        positive values and the latter are negative.
 *
 * @{
 */

#define SYNOLDAP_ERR_BASE                       0xffff0000

#define SYNOLDAP_ERR_OP_FAILED                  (SYNOLDAP_ERR_BASE - 0)
#define SYNOLDAP_ERR_SERVER_NOT_SUPPORT         (SYNOLDAP_ERR_BASE - 1)
#define SYNOLDAP_ERR_USERNAME_ALREADY_EXISTS    (SYNOLDAP_ERR_BASE - 2)
#define SYNOLDAP_ERR_GROUPNAME_ALREADY_EXISTS   (SYNOLDAP_ERR_BASE - 3)
#define SYNOLDAP_ERR_UID_ALREADY_EXISTS         (SYNOLDAP_ERR_BASE - 4)
#define SYNOLDAP_ERR_GID_ALREADY_EXISTS         (SYNOLDAP_ERR_BASE - 5)
#define SYNOLDAP_ERR_LOCK_FAILED                (SYNOLDAP_ERR_BASE - 6)
#define SYNOLDAP_ERR_BACKUP_RUNNING             (SYNOLDAP_ERR_BASE - 7)
#define SYNOLDAP_ERR_RESTORE_RUNNING            (SYNOLDAP_ERR_BASE - 8)
#define SYNOLDAP_ERR_INVALID_BKP_DEST           (SYNOLDAP_ERR_BASE - 9)
#define SYNOLDAP_ERR_INVALID_BKP_FILE           (SYNOLDAP_ERR_BASE - 10)
#define SYNOLDAP_ERR_DSM_VERSION                (SYNOLDAP_ERR_BASE - 11)
#define SYNOLDAP_ERR_PKG_VERSION                (SYNOLDAP_ERR_BASE - 12)
#define SYNOLDAP_ERR_DISK_FULL                  (SYNOLDAP_ERR_BASE - 13)
#define SYNOLDAP_ERR_ROOT_FULL                  (SYNOLDAP_ERR_BASE - 14)

/*
 * LDAP Result Codes
 */

#define SYNOLDAP_SUCCESS   0x00

#define SYNOLDAP_RANGE(n,x,y) (((x) <= (n)) && ((n) <= (y)))

#define SYNOLDAP_OPERATIONS_ERROR            0x01
#define SYNOLDAP_PROTOCOL_ERROR              0x02
#define SYNOLDAP_TIMELIMIT_EXCEEDED          0x03
#define SYNOLDAP_SIZELIMIT_EXCEEDED          0x04
#define SYNOLDAP_COMPARE_FALSE               0x05
#define SYNOLDAP_COMPARE_TRUE                0x06
#define SYNOLDAP_AUTH_METHOD_NOT_SUPPORTED   0x07
#define SYNOLDAP_STRONG_AUTH_NOT_SUPPORTED   SYNOLDAP_AUTH_METHOD_NOT_SUPPORTED
#define SYNOLDAP_STRONG_AUTH_REQUIRED        0x08
#define SYNOLDAP_STRONGER_AUTH_REQUIRED      SYNOLDAP_STRONG_AUTH_REQUIRED
#define SYNOLDAP_PARTIAL_RESULTS             0x09 /* LDAPv2+ (not LDAPv3) */

#define SYNOLDAP_REFERRAL                         0x0a /* LDAPv3 */
#define SYNOLDAP_ADMINLIMIT_EXCEEDED              0x0b /* LDAPv3 */
#define SYNOLDAP_UNAVAILABLE_CRITICAL_EXTENSION   0x0c /* LDAPv3 */
#define SYNOLDAP_CONFIDENTIALITY_REQUIRED         0x0d /* LDAPv3 */
#define SYNOLDAP_SASL_BIND_IN_PROGRESS            0x0e /* LDAPv3 */

#define SYNOLDAP_ATTR_ERROR(n) SYNOLDAP_RANGE((n),0x10,0x15) /* 16-21 */

#define SYNOLDAP_NO_SUCH_ATTRIBUTE        0x10
#define SYNOLDAP_UNDEFINED_TYPE           0x11
#define SYNOLDAP_INAPPROPRIATE_MATCHING   0x12
#define SYNOLDAP_CONSTRAINT_VIOLATION     0x13
#define SYNOLDAP_TYPE_OR_VALUE_EXISTS     0x14
#define SYNOLDAP_INVALID_SYNTAX           0x15

#define SYNOLDAP_NAME_ERROR(n) SYNOLDAP_RANGE((n),0x20,0x24) /* 32-34,36 */

#define SYNOLDAP_NO_SUCH_OBJECT        0x20
#define SYNOLDAP_ALIAS_PROBLEM         0x21
#define SYNOLDAP_INVALID_DN_SYNTAX     0x22
#define SYNOLDAP_IS_LEAF               0x23 /* not LDAPv3 */
#define SYNOLDAP_ALIAS_DEREF_PROBLEM   0x24

#define SYNOLDAP_SECURITY_ERROR(n) SYNOLDAP_RANGE((n),0x2F,0x32) /* 47-50 */

#define SYNOLDAP_PROXY_AUTHZ_FAILURE   0x2F /* LDAPv3 proxy authorization */
#define SYNOLDAP_INAPPROPRIATE_AUTH    0x30
#define SYNOLDAP_INVALID_CREDENTIALS   0x31
#define SYNOLDAP_INSUFFICIENT_ACCESS   0x32

#define SYNOLDAP_SERVICE_ERROR(n) SYNOLDAP_RANGE((n),0x33,0x36) /* 51-54 */

#define SYNOLDAP_BUSY                   0x33
#define SYNOLDAP_UNAVAILABLE            0x34
#define SYNOLDAP_UNWILLING_TO_PERFORM   0x35
#define SYNOLDAP_LOOP_DETECT            0x36

#define SYNOLDAP_UPDATE_ERROR(n) SYNOLDAP_RANGE((n),0x40,0x47) /* 64-69,71 */

#define SYNOLDAP_NAMING_VIOLATION         0x40
#define SYNOLDAP_OBJECT_CLASS_VIOLATION   0x41
#define SYNOLDAP_NOT_ALLOWED_ON_NONLEAF   0x42
#define SYNOLDAP_NOT_ALLOWED_ON_RDN       0x43
#define SYNOLDAP_ALREADY_EXISTS           0x44
#define SYNOLDAP_NO_OBJECT_CLASS_MODS     0x45
#define SYNOLDAP_RESULTS_TOO_LARGE        0x46 /* CLDAP */
#define SYNOLDAP_AFFECTS_MULTIPLE_DSAS    0x47 /* LDAPv3 */
#define SYNOLDAP_LDAP_SERVER_DOWN         0xFF // FIXME ldap.h use -1 instead of 0xFF

#define SYNOLDAP_OTHER                    0x50

/* LCUP operation codes (113-117) - not implemented */
#define SYNOLDAP_CUP_RESOURCES_EXHAUSTED   0x71
#define SYNOLDAP_CUP_SECURITY_VIOLATION    0x72
#define SYNOLDAP_CUP_INVALID_DATA          0x73
#define SYNOLDAP_CUP_UNSUPPORTED_SCHEME    0x74
#define SYNOLDAP_CUP_RELOAD_REQUIRED       0x75

/* Cancel operation codes (118-121) */
#define SYNOLDAP_CANCELLED           0x76
#define SYNOLDAP_NO_SUCH_OPERATION   0x77
#define SYNOLDAP_TOO_LATE            0x78
#define SYNOLDAP_CANNOT_CANCEL       0x79

/* Experimental result codes */
#define SYNOLDAP_E_ERROR(n) SYNOLDAP_RANGE((n),0x1000,0x3FFF) /* experimental */
#define SYNOLDAP_X_ERROR(n) SYNOLDAP_RANGE((n),0x4000,0xFFFF) /* private use */

/* for the LDAP Sync operation */
#define SYNOLDAP_SYNC_REFRESH_REQUIRED   0x4100

/* for the LDAP No-Op control */
#define SYNOLDAP_NO_OPERATION   0x410e

/* for the Assertion control */
#define SYNOLDAP_ASSERTION_FAILED   0x410f

/* for the Chaining Behavior control (consecutive result codes requested;
 * see <draft-sermersheim-ldap-chaining> ) */
#ifdef SYNOLDAP_CONTROL_X_CHAINING_BEHAVIOR
#define SYNOLDAP_NO_REFERRALS_FOUND   0x4110
#define SYNOLDAP_CANNOT_CHAIN         0x4111
#endif

/*
 * LDAP ppolicy return
 */

#define SYNOLDAP_PP_ERRORMASK                         0x00010000

#define SYNOLDAP_PP_PASSWORDEXPIRED                   0x00010000
#define SYNOLDAP_PP_ACCOUNTLOCKED                     0x00010001
#define SYNOLDAP_PP_CHANGEAFTERRESET                  0x00010002
#define SYNOLDAP_PP_PASSWORDMODNOTALLOWED             0x00010003
#define SYNOLDAP_PP_MUSTSUPPLYOLDPASSWORD             0x00010004
#define SYNOLDAP_PP_INSUFFICIENTPASSWORDQUALITY       0x00010005
#define SYNOLDAP_PP_PASSWORDTOOSHORT                  0x00010006
#define SYNOLDAP_PP_PASSWORDTOOYOUNG                  0x00010007
#define SYNOLDAP_PP_PASSWORDINHISTORY                 0x00010008
// synology defined ppolicy error
#define SYNOLDAP_PP_SYNO_PASSWORDWITHNAMEDESC         0x000103E9 // 1001
#define SYNOLDAP_PP_SYNO_PASSWORDWITHOUTMIXEDCASE     0x000103EA // 1002
#define SYNOLDAP_PP_SYNO_PASSWORDWITHOUTNUMBER        0x000103EB // 1003
#define SYNOLDAP_PP_SYNO_PASSWORDWITHOUTSPECIALCHAR   0x000103EC // 1004
// end of synology defined ppolicy error
#define SYNOLDAP_PP_ACCOUNTEXPIRED                    0x0001fffe
#define SYNOLDAP_PP_NOERROR                           0x0001ffff

/**
 * @brief Store error code which can be retrieved later or translated by
 *        @a SYNOLDAPErrGetString().
 *
 * @note This should be thread-safe since the error code is stored in
 *       thread-local storage.
 *
 * @param[in] error_code  Error code.
 *
 * @return @p error_code.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPErrSet(int error_code);

/**
 * @brief Reset stored error code to 0.
 *
 * @return Always 0.
 *
 * @sa SYNOLDAPErrSet()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPErrReset(void);

/**
 * @brief Get stored error code.
 *
 * @return Stored error code.
 *
 * @sa SYNOLDAPErrSet()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPErrGet(void);

/**
 * @brief Get error message of @p error_code which can be used as
 *        `_T(section, key)` in Javascript.
 *
 * @param[in]  error_code  Error code.
 * @param[out] pszSec      Section of multilingual string if not NULL.
 *
 * @return Key of multilinugal string,
 *         empty if not found (and @p *pszSec won't be changed).
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) const char *SYNOLDAPErrGetString(int error_code, const char **pszSec);

/**
 * @breif Format string for printf-like functions to print LDAP error code.
 *
 * @sa SYNOLDAPERR_ARGS
 */
#define SYNOLDAPERR_FMT "%s (%d)"

/**
 * @breif Arguments for @a SYNOLDAPERR_FMT.
 *
 * @sa SYNOLDAPERR_FMT
 */
#define SYNOLDAPERR_ARGS SYNOLDAPErrGetString(SYNOLDAPErrGet(), NULL), SYNOLDAPErrGet()

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_ERROR_H__
// vim:ts=4 sts=4 sw=4
