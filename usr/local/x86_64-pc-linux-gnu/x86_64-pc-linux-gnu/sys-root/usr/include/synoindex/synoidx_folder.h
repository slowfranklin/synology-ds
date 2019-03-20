// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_FOLDER_H
#define _SYNO_IDX_FOLDER_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------
// Basic Folder Operator
//--------------------------------------------------

int GetDirInfo(const char *szPath, SYNO_DIR_INFO *pDirInfo);

//--------------------------------------------------
// Share Folder
//--------------------------------------------------

int SYNOIndexSharePathGet(const char *szPath, char *szSharePath, int cbSharePath);
BOOL IsDefaultShare(const char* szShare);

int ShareIndexStatusSet(const char *szShare);
int ShareIndexStatusClear(const char *szShare);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
