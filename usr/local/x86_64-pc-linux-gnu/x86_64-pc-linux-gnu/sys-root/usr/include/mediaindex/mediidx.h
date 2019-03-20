// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_MEDIA_INDEX_H
#define _SYNO_MEDIIDX_MEDIA_INDEX_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
#include <json/json.h>
extern "C" {
#endif

//--------------------------------------------------

void SYNOMediaIndexGetSortAndSearchProperty(const char *szProperty, char *szSearchProperty, int cbSearchSize, char *szSortProperty, int cbSortSize);
uid_t SYNOMediaIndexGetUserIdFromName(const char *szName);
uid_t SYNOMediaIndexGetUserIdFromPath(const char *szPath);
BOOL SYNOMediaIndexIsUnderPersonalLibPath(const char *szHomePath, const char *szPath);
BOOL SYNOMediaIndexGetAllUserDefinedSongRating(const char *szPath, PSLIBSZHASH *ppHashRating);

int SYNOMediaintIndexIsShareIndexed(const char *szSharePath);
int SYNOMediaIndexIsIndexPath(const char *szPath, MEDIA_TABLE_TYPE type);
int SYNOMediaIndexAdd(SYNO_MEDIA_INFO *pMediaInfo, MEDIA_TABLE_TYPE type);
int SYNOMediaIndexDirAdd(SYNO_DIR_INFO *pDirInfo);
int SYNOMediaIndexDelete(const char *szPath);
int SYNOMediaIndexDirDelete(const char *szPath);
int SYNOMediaIndexRename(SYNO_MEDIA_INFO *pNewMediaInfo, MEDIA_TABLE_TYPE type, const char *szOldPath);
int SYNOMediaIndexDirRename(SYNO_DIR_INFO *pNewDirInfo, const char *szOldPath);
int SYNOMediaIndexPreReindex(const char *szPath);
int SYNOMediaIndexPreReindexAll();
int SYNOMediaIndexReindexUpdate(SYNO_MEDIA_INFO *pMediaInfo, MEDIA_TABLE_TYPE type);
int SYNOMediaIndexReindexDirUpdate(SYNO_DIR_INFO *pDirInfo);
int SYNOMediaIndexDBGetOne(MEDIA_TABLE_TYPE TableType, const char *szPath, SYNO_MEDIA_INFO *pMediaInfo);
int SYNOMediaIndexDBVacuum();
int SYNOMediaIndexDBClose();

//--------------------------------------------------

//void SYNOMediaIndexPluginLoad(PKG_PLUGIN **plugin);

//--------------------------------------------------

#ifdef __cplusplus
int SYNOMediaIndexAdd_Json(Json::Value *pMedia, MEDIA_TABLE_TYPE type);
int SYNOMediaIndexRename_Json(Json::Value *pMedia, MEDIA_TABLE_TYPE type, const char *szOldPath);
int SYNOMediaIndexReindexUpdate_Json(Json::Value *pMedia, MEDIA_TABLE_TYPE type);
}
#endif

#endif
