// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_FILE_H
#define _SYNO_IDX_FILE_H

#include <time.h>

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------
// Basic File Operator
//--------------------------------------------------

int IsFileExist(const char *path, off_t *filesize);
int IsDirExist(const char *path);
const char* SYNOIndexExtGet(const char *szPath);

//--------------------------------------------------
// File Time
//--------------------------------------------------

time_t SYNOIndexModifyTimeGet(const char *pszPath);
void SYNOIndexCTimeMTimeGet(const char *pszPath, char *pCTimeBuf, const int cCTimeBuf, char *pMTimeBuf, const int cMTimeBuf);

//--------------------------------------------------
// File Location
//--------------------------------------------------

int SYNOPathUnderRecyle(const char *szPath);
BOOL EntryNameShouldIndex(const char *pszName);

BOOL IndexIsPathRemoteMount(const char *szPath);
BOOL IndexIsPathRemoteOrImageMount(const char *szPath);
BOOL IndexIsPathSupportEAWrite(const char *szPath);

//--------------------------------------------------
// Check File Type
//--------------------------------------------------

BOOL BlSYNOIndexIsMusicFile(const char *szPath);
BOOL BlSYNOIndexIsMultiplePagePhotoFile(const char *szPath);
BOOL BlSYNOIndexIsPhotoOnWebFile(const char *szPath);
BOOL BlSYNOIndexIsPhotoOnWebConvertFile(const char *szPath);
BOOL BlSYNOIndexIsVideoOnWebFile(const char *szPath);
BOOL BlSYNOIndexIsVideoFile(const char *szPath);
BOOL BlSYNOIndexIsSubtitleFile(const char *szPath);
BOOL BlSYNOIndexIsMusic(const char *szExt);
BOOL BlSYNOIndexIsPlaylist(const char *szExt);
BOOL BlSYNOIndexIsPhoto(const char *szExt);
BOOL BlSYNOIndexIsVideo(const char *szExt);
BOOL BlSYNOIndexIsJpeg(const char *szExt);
BOOL BlSYNOIndexIsRawImage(const char *szExt);
BOOL BlSYNOIndexIsPhotoOnWeb(const char *szExt);
BOOL BlSYNOIndexIsVideoOnWeb(const char *szExt);

//--------------------------------------------------
// Other
//--------------------------------------------------
int ConvertVideoTypeGet(const char *szName, char *szType, int cbType);
MEDIA_TABLE_TYPE GetMediaTableTypeFromExt(const char* ext);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
