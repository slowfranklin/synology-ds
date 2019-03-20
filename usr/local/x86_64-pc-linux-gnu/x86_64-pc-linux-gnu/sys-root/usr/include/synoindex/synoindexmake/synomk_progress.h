// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_PROGRESS_H
#define _SYNO_SYNOMK_PROGRESS_H

#include <synofileop/index.h>

#include "synomake.h"

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

int ThumbConvProgressGet(FILE_TYPE type, const char *szKey);
void ThumbConvProgressSet(FILE_TYPE type, const char *szKey, int cProgress);
void ThumbConvProgressUpdate(FILE_TYPE type, const char *szKey, int cProgress);
void ThumbConvProgressPrint();

BOOL IsThumbConvertPaused();
BOOL IsThumbConvertResumeTimeExpired();
time_t GetThumbConvertResumeTime();
int GetThumbConvertResumeTimeout(struct timeval *timeout);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
