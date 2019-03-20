// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_PLAYLIST_PARSER_H
#define _SYNO_MEDIIDX_PLAYLIST_PARSER_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

int ABSPlayListPath(const char *parentpath, char *relpath, char *abspath);
int GetExtInfoM3U(const char *szLine, SYNO_MEDIA_INFO *pInfo);
PLAYLIST_REC* ParsePlayListByFieldGivenPath(const char *szPath, int *row, int start, int count, const char *szField, int includeType);
PLAYLIST_REC* ParsePlayListByField(const char *listID, int *row, int start, int count, const char *szField, int includeType);
PLAYLIST_REC* ParsePlayList(const char *listID, int *row, int start, int count);
int SYNOParseCueByPath(PLAYLIST_REC **pRecList, const char *szPlaylistPath);
void SYNOPlaylistRecFree(PLAYLIST_REC *pPlaylist);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
