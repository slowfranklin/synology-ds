/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNO_UT_TYPE_MAP_C_
#define _SYNO_UT_TYPE_MAP_C_

#include <sys/cdefs.h>

__BEGIN_DECLS;

/**
 * Get extensions of a given UTType (from mapping tree build with default plist)
 *
 * @apparmor abstractions/synospotlightutils
 * @grantable no
 *
 * @param[in] szUTType  UTType Id to get description
 *
 * @return list of extensions included in the UTType (concat with whitespace separating them)
 *         empty string if type not found
 * @code{.c}
 * char *szExts = NULL;
 * szExts = SYNOUTTypeGetExts("public.image");
 * free(szExts);
 * szExts = NULL;
 * @endcode
 */
char *SYNOUTTypeGetExts(const char *szUTType);

__END_DECLS;

#endif
