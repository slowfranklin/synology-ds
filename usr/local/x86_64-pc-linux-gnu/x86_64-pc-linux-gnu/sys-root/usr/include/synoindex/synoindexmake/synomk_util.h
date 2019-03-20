// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_UTIL_H
#define _SYNO_SYNOMK_UTIL_H

#include <synoindex/synoidx.h>
#include "synomake.h"

//--------------------------------------------------

typedef struct __tag_thumb_info {
	EA_THUMB_TYPE type;
	const char *pszSize;
	const char *pszFilename;
	const char *pszOldFilename;
} THUMB_INFO;

//--------------------------------------------------

int GetThumbInfo(THUMB_INFO** ppEAThumbInfo);
const char* SYNOEAThumbSizeGet(EA_THUMB_TYPE type);
bool EAFileIsExpired(const char *szPath, const char *szEAFileName);
bool IsMakeThumb(const char* filename, int size_map);

int IsEAVideosMobileReady(const char *szPath);
int IsEAVideosWebReady(const char *szPath);
int IsEAVideosReady(const char *szPath);
int IsEAThumbsReady(const char *szFile, int thumbSizeMap);

int RemoveFilesByGlob(const char *szGlobPattern);

//--------------------------------------------------

#endif
