// Copyright (c) 2000-2013 Synology Inc. All rights reserved.

#ifndef _SYNO_SYNOMK_INET_H
#define _SYNO_SYNOMK_INET_H

#include <synoindex/synoidx.h>
#include <synoindex/synoidx_ipc.h>

//--------------------------------------------------
// Get Info From Plugind
//--------------------------------------------------

int GetMediaFromPluginDB(MEDIA_TABLE_TYPE type, const char* path, SYNO_MEDIA_INFO* pMediaInfo);
int GetIndexVersion(const char* path);
bool IsDisableConvertVideo();
bool IsDisableConvertPhoto();
void PostPhotoConvert(const char *path);
void PostVideoConvert(const char *path);

//--------------------------------------------------

#endif
