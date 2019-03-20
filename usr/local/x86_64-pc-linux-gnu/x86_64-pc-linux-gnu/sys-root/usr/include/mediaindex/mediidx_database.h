// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_DATABASE_H
#define _SYNO_MEDIIDX_DATABASE_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

void MediaDBConnClose();

int MediaDBUpdateTrackRelatedTables(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);
int MediaDBUpdateTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);
int MediaDBDeleteRecordsInRelatedTables(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);

int MediaDBInsertIntoTrackRelatedTables(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, SYNO_MEDIA_INFO *pCueInfo, BOOL blVirtual, uid_t uid);
int MediaDBInsertIntoTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, SYNO_MEDIA_INFO *pCueInfo, BOOL blVirtual, uid_t uid);
int MediaDBFindInsertedTrackID(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, BOOL blVirtual);
int MediaDBFindRecordsWithSamePath(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, BOOL blVirtual);
int MediaDBUpdateHasVirtualColumn(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);
int MediaDBUpdateVirtualMusicProperties(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, BOOL blVirtual);
int MediaDBInsertOneGenreRecord(DBConnect *pConnection, const char *szGenre, int trackId);
int MediaDBInsertIntoGenreTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, int trackId);
int MediaDBInsertIntoComposerTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, int trackId);
int MediaDBInsertIntoArtistTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, int trackId);
int MediaDBInsertIntoAlbumTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, const char *szArtist, int trackId, BOOL fromAlbumArtist);
int MediaDBInsertIntoVirtualInfoTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pRecInfo, SYNO_MEDIA_INFO *pMediaInfo, int trackId);
int MediaDBInsertIntoRatingTrackTable(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo, int trackId, BOOL blVirtual);
int MediaDBInsertIntoReplayGainTrackTable(DBConnect *pConnection, AUDIO_REPLAYGAIN_METADATA *AudioRGMetadata, int trackId);

int MediaDBFindAlbumCollapseSingleAlbumArtist(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);
int MediaDBUpdateAlbumWithMultipleAlbumArtist(DBConnect *pConnection, SYNO_MEDIA_INFO *pMediaInfo);

int MediaDBUpdateAlbumTrackTable(DBConnect *pConnection, const char *szPath, BOOL blVirtual);
int MediaDBCheckRecordInMultipleAlbumArtist(DBConnect *pConnection, const char *szPath, BOOL blVirtual);
int MediaDBCheckRecordsWithMultipleAlbumArtist(DBConnect *pConnection, const char *szPath, BOOL blVirtual);
int MediaDBRecoverToSingleAlbumArtist(DBConnect *pConnection, const char *szPath, BOOL blVirtual);

int MediaDBFindPersonalDirWithSamePath(DBConnect *pConnection, SYNO_DIR_INFO *pMediaInfo);

int MediaInfoDBSave(MEDIA_TABLE_TYPE TableType, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoAudioRGMetadataDBSave(AUDIO_REPLAYGAIN_METADATA *AudioRGMetadata, int trackId);
int MediaInfoVirtualDBSave(PLAYLIST_REC *pResultList, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoVideoConvertDBSave(SYNO_MEDIA_INFO *pMediaInfo, const char *szConvertedFilePath, const char *szConvertType);
int MediaInfoDBDeleteAll();
int MediaInfoDBDelete(MEDIA_TABLE_TYPE TableType, const char *szPath);
int MediaInfoVirtualDBDelete(const char *szPath);
MEDIA_DB_HANDLER* MediaInfoDBOpenEx(MEDIA_TABLE_TYPE TableType, const char *szFields, const char *szCondition, const char *szGroupBy, const char *szOrderBy, int Offset, int Limit, int fEscapCondition);
MEDIA_DB_HANDLER* MediaInfoDBOpen(MEDIA_TABLE_TYPE TableType, const char *szFields, const char *szCondition, const char *szGroupBy, const char *szOrderBy, int Offset, int Limit, int fEscapCondition);
int MediaInfoDBGet(MEDIA_DB_HANDLER *pDBHandler, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBGetCount(MEDIA_TABLE_TYPE TableType, const char *szFields, const char *szCondition, const char *szGroupBy, int fEscapCondition);
void MediaInfoDBClose(MEDIA_DB_HANDLER *pDBHandler);
int MediaInfoDBGetOneEx(MEDIA_TABLE_TYPE TableType, const char *szPath, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBGetOneEx2(MEDIA_TABLE_TYPE TableType, const char *szPath, SYNO_MEDIA_INFO *pMediaInfo, int fPartial);
int MediaInfoDBGetOne(MEDIA_TABLE_TYPE TableType, const char *szPath, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBGetOneByField(MEDIA_TABLE_TYPE TableType, const char *szPath, const char* szField, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBBatchPara(PSLIBSZLIST *pCandidateList, char *szCandidate);
MEDIA_DB_HANDLER* MediaInfoDBBatchOpen(MEDIA_TABLE_TYPE TableType, const char *szFields, const char *szInField, PSLIBSZLIST *pCandidateList, const char *szGroupBy, const char *szOrderBy, int Offset, int Limit);
int MediaInfoDBBatchFind(MEDIA_DB_HANDLER *pDBHandler, const char *szKeyField, const char *szKeyValue, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBHashFind(MEDIA_DB_HANDLER *pDBHandler, char *szKeyField, char *szKeyValue, SYNO_MEDIA_INFO *pMediaInfo, PSLIBSZHASH pHash);
int MediaInfoDBGenHash(MEDIA_DB_HANDLER *pDBHandler, char *szKeyField, PSLIBSZHASH *ppHash);
void MediaInfoDBBatchClose(MEDIA_DB_HANDLER *pDBHandler);
int MediaDBVacuum();
int MediaInfoDBGetRecoredData(DBResult *pResult, DBRow Row, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBGetRecored(MEDIA_DB_HANDLER *pDBHandler, SYNO_MEDIA_INFO *pMediaInfo);
int MediaInfoDBUpdate(MEDIA_TABLE_TYPE TableType, SYNO_MEDIA_INFO *pMediaInfo);
void MediaInfoDBSetOnline(const char *szPath, BOOL blWild, BOOL blOnline);
void MediaInfoDBUUIDDropOffline(const char *szUUID);
int DirInfoDBSave(SYNO_DIR_INFO *pDirInfo);
char* PlaylistDBGet(MEDIA_DB_HANDLER *pDBHandler);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
