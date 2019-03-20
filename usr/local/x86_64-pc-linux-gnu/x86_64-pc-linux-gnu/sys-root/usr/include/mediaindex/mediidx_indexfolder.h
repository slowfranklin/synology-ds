// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_INDEXFOLDER_H
#define _SYNO_MEDIIDX_INDEXFOLDER_H

#include <synoindex/synoidx.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

void IndexFolderConfLock();
void IndexFolderConfUnLock();

void IndexFolderInit();
void IndexFolderFree();
void IndexFolderUpdate();
void IndexFolderConfDelFolder(const char *szFolder);

int IndexFolderIsCoveredByShare(const char *szSharePath);
int IndexFolderIsPathIndexed(const char *szPath, MEDIA_TABLE_TYPE type);
int IndexFolderIsFolderIndexed(const char *szPath);
int IndexFolderIsFolderHasParent(const char *szPath);
int IndexFolderIsIndexTypeAt(unsigned int index, MEDIA_TABLE_TYPE type);
int IndexFolderSizeGet();

int IndexFolderPositionGet(const char *szPath);
int IndexFolderPathAt(unsigned int index, char *szPath, size_t length);
int IndexFolderShareNameGet(const char *szPath, char *szShareName, size_t length);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
