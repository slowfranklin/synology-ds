// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_PERSONAL_H
#define _SYNO_IDX_PERSONAL_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

int SYNOIndexPersonalPathGet(const char *pszUserName, const char *pszFolder, char *pszPath, const int cbBufLen);
int SYNOIndexPersonalPhotoPathGet(const char *pszUserName, char *pszPath, const int cbBufLen);
int SYNOIndexPersonalAlbumDefRightGet(const char *pszUserName, BOOL *blIsPublic);
int SYNOIndexPersonalAlbumDefRightSet(const char *pszUserName, int op);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
