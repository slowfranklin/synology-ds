// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_UNICODE_H
#define _SYNO_IDX_UNICODE_H

#include <synocore/unicode.h>
#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

int TryUTF8ToUTF16(const char *szStr);
int IsUnicodeString(const char *szStr);
void ShortenString(const char *szStr, char *szOutput, int cbOutput);
SYNO_CODEPAGE SYNOIndexCodePageGet();
void MediaInfoValid(SYNO_MEDIA_INFO *pMediaInfo);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
