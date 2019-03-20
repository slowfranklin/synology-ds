// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_THUMB_STATUS_H
#define _SYNO_SYNOMK_THUMB_STATUS_H

#include <synoindex/synoidx.h>
#include "synomake.h"

//--------------------------------------------------

int GetNumberOfFilesInDir(const char* dirpath);

void GetFileThumbStatus(const char* path, int& incomplete_thumb_num, int& complete_thumb_num, int size_map = -1);
void GetDirThumbStatus(const char* dirpath, int& incomplete_photo_num, int& incomplete_thumb_num);
void GetDirThumbStatusRecursive(const char* dirpath, int& incomplete_photo_num, int& incomplete_thumb_num);

//--------------------------------------------------

bool IsMakingVideoThumb(const char *path);
int GetDirVideoThumbStatusRecursive(const char* dirpath);
int GetQueueVideoThumbStatus(const char* queue_file);

//--------------------------------------------------

#endif
