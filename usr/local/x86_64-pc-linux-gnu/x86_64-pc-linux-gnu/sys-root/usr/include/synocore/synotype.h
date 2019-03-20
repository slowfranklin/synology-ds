// Copyright (c) 2000-2003 Synology Inc. All rights reserved.
#include <string.h>

#ifndef __SYNO_TYPE_H__
#define __SYNO_TYPE_H__

/**
 * @addtogroup SYNOTYPES
 *
 * @brief The global typedefs for libsynocore.
 *
 * @{
 */

/**
 * End of c-styled string.
 */
#define EOFSTRING '\0'

/**
 * Equivilent to @c void*
 */
typedef void* PVOID;
/**
 * Equivilent to @c void**
 */
typedef PVOID* PPVOID;

#ifndef _HAVE_BOOL
/**
 * @cond INTERNAL
 */
#define _HAVE_BOOL
/**
 * @endcond
 */
#undef BOOL
#undef FALSE
#undef TRUE
/**
 * C-styled boolean values.
 */
typedef enum{
	/**
	 * False value.
	 */
	FALSE=0,
	/**
	 * True value.
	 */
	TRUE=1
}BOOL;

#endif /* _HAVE_BOOL */

/**
 * Enumerates the user/group names that locate on specified 
 * server. 
 */
typedef enum {
	/** 
	 *  The lower bound of AUTH_TYPE
	 */
	AUTH_MIN = 0,
	/** 
	 *  Enumerates users/groups on local server.
	 */ 
	AUTH_LOCAL = 0x1,
	/** 
	 *  Enumerates users/groups on joined domain server.
	 */
	AUTH_DOMAIN = 0x2,
	/** 
	 *  Enumerates users/groups on joined domain server and has
	 *  entries in smb.conf .
	 */
	AUTH_DOMAIN_USED = 0x4,
	/** 
	 *  Enumerates users/groups on joined ldap server.
	 */
	AUTH_LDAP = 0x8,
	/** 
	 *  Enumerates users/groups on all server.
	 */
	AUTH_ALL = (AUTH_LOCAL | AUTH_DOMAIN | AUTH_LDAP),
	/** 
	 *  The upper bound of AUTH_TYPE.
	 */
	AUTH_MAX,
} AUTH_TYPE;

/**
 * Gets AUTH_TYPE by the user/group name that has a backslash or at symbol or not.
 *
 * @param[in] szName The user/group name to check. Should not be NULL.
 *
 * @retval AUTH_MIN    On error.
 * @retval AUTH_LOCAL  If the @p szName has no backslash and no at symbol.
 * @retval AUTH_DOMAIN If the @p szName has a backslash.
 * @retval AUTH_LDAP   If the @p szName has an at symbol.
 *
 * @grantable No
 *
 * @see AUTH_TYPE
 */
static inline AUTH_TYPE
SYNOGetAuthType(const char *szName)
{
	if (NULL == szName) {
		return AUTH_MIN;
	}
	if (strchr(szName, '\\')) {
		return AUTH_DOMAIN;
	} else if (strchr(szName, '@')) {
		return AUTH_LDAP;
	}
	return AUTH_LOCAL;
}

/**
 * @}
 */

#endif // __SYNO_TYPE_H__
