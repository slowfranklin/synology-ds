// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_MEDIA_DB_DIRTY_H
#define _SYNO_MEDIIDX_MEDIA_DB_DIRTY_H

#include <synocore/synotype.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

void SYNOIndexMusicTableDirtySet(BOOL blDirty);
void SYNOIndexVideoTableDirtySet(BOOL blDirty);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
