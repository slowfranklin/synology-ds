// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_UNICODE_H__
#define __SYNO_UNICODE_H__

#include <sys/cdefs.h>
#if !defined(SYNO_JUNIOR_INSTALLER) && !defined(SLIBC_DISABLE_UNICODE)
#include <unicode/utypes.h>
#endif
#undef TRUE
#undef FALSE

#include <synocore/error.h>

__BEGIN_DECLS;

/**
 * @addtogroup UNICODE
 *
 * @brief Functions about unicode.
 *
 * @{
 */

enum {
	SYNO_CODEPAGE_WIN = 1,
	SYNO_CODEPAGE_DOS,
	SYNO_CODEPAGE_MAC,
	SYNO_CODEPAGE_DMS
};

/* You would need to modified the unicode_open_convertor.c's rgSynoCodepageICUMapping
 */
typedef enum _tag_SYNO_CODEPAGE {
	SYNO_CP_UTF8 = 0,
	SYNO_CP_UTF16,

	SYNO_CP_WIN_437,
	SYNO_CP_WIN_737,
	SYNO_CP_WIN_850,
	SYNO_CP_WIN_852,
	SYNO_CP_WIN_857,
	SYNO_CP_WIN_861,
	SYNO_CP_WIN_862,
	SYNO_CP_WIN_866,
	SYNO_CP_WIN_932,
	SYNO_CP_WIN_936,
	SYNO_CP_WIN_949,
	SYNO_CP_WIN_950,
	SYNO_CP_WIN_1250,
	SYNO_CP_WIN_1251,
	SYNO_CP_WIN_1252,
	SYNO_CP_WIN_1253,
	SYNO_CP_WIN_1254,
	SYNO_CP_WIN_1255,
	SYNO_CP_WIN_1256,

#define	SYNO_CODEPAGE_WIN2MAC_OFFSET (SYNO_CP_MAC_437 - SYNO_CP_WIN_437)

	SYNO_CP_MAC_437,
	SYNO_CP_MAC_737,
	SYNO_CP_MAC_850,
	SYNO_CP_MAC_852,
	SYNO_CP_MAC_857,
	SYNO_CP_MAC_861,
	SYNO_CP_MAC_862,
	SYNO_CP_MAC_866,
	SYNO_CP_MAC_932, SYNO_CP_MAC_936,
	SYNO_CP_MAC_949,
	SYNO_CP_MAC_950,
	SYNO_CP_MAC_1250,
	SYNO_CP_MAC_1251,
	SYNO_CP_MAC_1252,
	SYNO_CP_MAC_1253,
	SYNO_CP_MAC_1254,
	SYNO_CP_MAC_1255,
	SYNO_CP_MAC_1256,

	SYNO_CP_NUM
} SYNO_CODEPAGE;

/* The protocol codepage keys in /etc/synoinfo.conf */
#define SZK_CP_WINDOWS  "codepage"
#define SZK_CP_DMS      "codepage_mediaservice"

/**
 * @}
 */

#if !defined(NO_PROTO) && !defined(SYNO_JUNIOR_INSTALLER) && !defined(SLIBC_DISABLE_UNICODE)
#include <synocore/unicode_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif /* __SYNO_UNICODE_H__ */
