// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLDAP_HOST_H__
#define __SYNOLDAP_HOST_H__

#include <sys/cdefs.h>
#include <availability.h>
#include <synocore/list.h>
#include <synocore/synoglobal.h>
#include <synosdk/ldap.h>

__BEGIN_DECLS;

/**
 * @addtogroup host
 *
 * @brief Define host structure which represent target LDAP server for LDAP
 *        search or modify operations.
 *
 * @{
 */

/**
 * @brief Fields in @a LDAP_HOST.
 *
 * @sa LDAP_HOST, SYNOLDAPHostSet()
 */
typedef enum {
	LDAP_HOST_ATTR_MIN = -1,
	LDAP_HOST_URI = 0,
	LDAP_HOST_BASE_DN,
	LDAP_HOST_BIND_DN,
	LDAP_HOST_BIND_PW,
	LDAP_HOST_LOGIN_SUFFIX,
	LDAP_HOST_PROVIDER_ADDR,
	LDAP_HOST_SERVER_TYPE,
	LDAP_HOST_ATTR_MAX,
} LDAP_HOST_ATTR;

/**
 * @brief Types of LDAP servers.
 */
typedef enum {
	LDAP_SERVER_MIN = -1,
	/** @brief Follow RFC 2307. */
	LDAP_SERVER_POSIX = 0,
	/** @brief Synology Directory Server. */
	LDAP_SERVER_SYNO,
	/** @brief Apple Open Directory. */
	LDAP_SERVER_MAC,
} LDAP_SERVER_TYPE;

/**
 * @brief Represent object classes as bitwise flags.
 */
typedef struct __tag__LDAP_SCHEMA {
#define LDAP_SCHEMA_REC(objclass, objname) unsigned objclass : 1
#include <synoldap/schema.def>
#undef LDAP_SCHEMA_REC
} LDAP_SCHEMA;

/**
 * @brief Host handle which contains information about some LDAP server as
 *        target of search or modify operations.
 *
 * @note Some fields are Synology Directory Server only, __DO NOT__ use them.
 *       Use standard ports, i.e. 398 for ldap:// and 636 for ldaps://, custom
 *       port is not supported. Protocol (ldap:// or ldaps://) is decided by
 *       `sslType`, hence not in `szUri`.
 */
typedef struct __tag__LDAP_HOST {
	PSLIBSZLIST plistBuffer;
	/** @brief LDAP server URI. */
	const char *szUri;
	/** @brief Base DN. */
	const char *szBaseDN;
	/** @brief Bind DN. */
	const char *szBindDN;
	/** @brief Bind password. */
	const char *szBindPW;
	/** @brief Login suffix. */
	const char *szLoginSuffix;
	/** @brief "provider" or "consumer", Synology Directory Server only */
	const char *szServType;
	/** @brief Address of provider, Synology Directory Server only */
	const char *szProviderAddr;
	/** @brief LDAP server type. */
	LDAP_SERVER_TYPE serverType;
	/** @brief Supported object classes */
	LDAP_SCHEMA supported;
	/** @brief `LDAP_SSL_NONE`, `LDAP_SSL_ON` or `LDAP_SSL_TLS` */
	LDAP_SSL_TYPE sslType;
	/** @brief SSL type for connection to provider, Synology Directory Server only */
	LDAP_SSL_TYPE sslTypeRepl;
} LDAP_HOST;

/**
 * @brief Check whether @p pHost can be used for connect, return @p err_ret if not.
 */
#define SYNOLDAP_CHECK_HOST_CAN_CONN(err_ret, pHost) \
	SYNOSDK_CHECK_ARGS(2, err_ret, NULL != pHost, NULL != pHost->szUri)

/**
 * @brief Check whether @p pHost can be used for bind, return @p err_ret if not.
 */
#define SYNOLDAP_CHECK_HOST_CAN_BIND(err_ret, pHost) \
	SYNOSDK_CHECK_ARGS(3, err_ret, NULL != pHost, NULL != pHost->szUri, NULL != pHost->szLoginSuffix)

/**
 * @brief Convert @p szSSL to corresponding @a LDAP_SSL_TYPE.
 *
 * Return @a LDAP_SSL_NONE if @p szSSL is unknown. The mappings are
 * "no" => `SZ_SSL_NO`, "yes" => `SZ_SSL_YES`, "start_tls" => `SZ_SSL_TLS`.
 *
 * @param[in] szSSL  "yes", "no" or "start_tls", must not be NULL.
 *
 * @return Result @a LDAP_SSL_TYPE.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @sa `<synosdk/ldap.h>`
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) LDAP_SSL_TYPE SYNOLDAPSSLToType(const char *szSSL);

/**
 * @brief Convert @p sslType to corresponding string.
 *
 * @param[in]  sslType  @a LDAP_SSL_TYPE to be converted.
 * @param[out] szSSL    Result string, must not be NULL.
 * @param[in]  cbSSL    Size of @p szSSL, must >0.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @sa SYNOLDAPSSLToType()
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLDAPSSLToString(LDAP_SSL_TYPE sslType, char *szSSL, size_t cbSSL);

/**
 * @brief Initialize @p pHost.
 *
 * @param[out] pHost  Host handle, must not be NULL.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostInit(LDAP_HOST *pHost);

/**
 * @brief Set @a LDAP_HOST_ATTR @p attr with @p szValue in @p pHost.
 *
 * @param[in,out] pHost    Host handle, must not be NULL.
 * @param[in]     attr     @a LDAP_HOST_ATTR to be set.
 * @param[in]     szValue  Value for @p attr, NULL means empty value.
 *
 * @return 0 on success, -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostSet(LDAP_HOST *pHost, LDAP_HOST_ATTR attr, const char *szValue);

/**
 * @brief Free @p pHost.
 *
 * @param[in] pHost  Host handle.
 *
 * @return 0 on success, -1 if @p pHost is NULL.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostFree(LDAP_HOST *pHost);

/**
 * @brief Clone @p pHostSrc to @p pHostDst.
 *
 * @note All `const char *` fields are shared by @p pHostSrc and @p pHostDst,
 *       __DO NOT__ change them.
 *
 * @param[out] pHostDst  Destination, must not be NULL.
 * @param[in]  pHostSrc  Source, must not be NULL.
 *
 * @return 0 on success, -1 on error.
 *
 * @grantable No
 * @apparmor None
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostClone(LDAP_HOST *pHostDst, const LDAP_HOST *pHostSrc);

/**
 * @brief Get DN of subschemaSubentry under RootDSE of @p pHost by ldapsearch.
 *
 * The command is something like `ldapsearch -x -D dc=a -w 1 -H ldap://192.168.32.31 -s baseObject subschemaSubentry`.
 *
 * @param[in]  pHost       Host handle, must not be NULL.
 * @param[out] szSchemaDN  Result DN, must not be NULL.
 * @param[in]  cbSchemaDN  Size of @p szSchemaDN, must >0.
 *
 * @return 0 on success, -1 on error or not found.
 *
 * @exception SYNOLDAPSearchMultiValue()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostGetSchemaDN(const LDAP_HOST *pHost, char *szSchemaDN, size_t cbSchemaDN);

/**
 * @brief Get supported object class then fill @p pHost->supported.
 *
 * @param[in,out] pHost  Host handle, must not be NULL.
 *
 * @retval  0 Success.
 * @retval -1 Error.
 * @retval -2 Failed to get schema DN, we don't know its location.
 * @retval -3 Failed to list content of schema.
 *
 * @exception SYNOLDAPSearchMultiValue()
 * @exception SYNOLDAPHostGetSchemaDN()
 *
 * @grantable No
 * @apparmor abstractions/libsynoldap
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLDAPHostGetSupportedSchema(LDAP_HOST *pHost);

/**
 * @}
 */

__END_DECLS;

#endif  // __SYNOLDAP_HOST_H__
// vim:ts=4 sts=4 sw=4
