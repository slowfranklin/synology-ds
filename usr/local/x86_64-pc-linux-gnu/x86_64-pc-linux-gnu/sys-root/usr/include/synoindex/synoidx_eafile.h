// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_EAFILE_H
#define _SYNO_IDX_EAFILE_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

const char* IsEAFileExist(const char *pszEADir, off_t *pFilesize, const char *pszFile1, const char *pszFile2);
int IsEAFileExist2(const char *szPath, const char *pszFile1, const char *pszFile2);
int RemoveEAFile(const char *pszEADir, const char *pszFile1, const char *pszFile2);
int RemoveEAFile2(const char *szPath, const char *pszFile1, const char *pszFile2);
int GetEADirPath(const char *szPath, char *szEADir, int cbEADir);
int GetEAFilePath(const char *szPath, const char *pszFile1, const char *pszFile2, char *szEAFile, size_t cbEAFile);
int MakeEADir(const char *szPath, char *szEADir, const int cbEADir);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
