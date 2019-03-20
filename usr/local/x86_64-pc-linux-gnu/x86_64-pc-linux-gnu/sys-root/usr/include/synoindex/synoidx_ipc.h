// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_IPC_H
#define _SYNO_IDX_IPC_H

// library
#include <json/value.h>

// project
#include <synoindex/synoidx.h>
#include <synoindex/synoidx_ipc_core.h>

//--------------------------------------------------
// Common
//--------------------------------------------------

bool IsSynoindexAlive();

//--------------------------------------------------
// Get Info From Plugind
//--------------------------------------------------

int SYNOIDX_IsVideoNeedConvert(const char* path);
int SYNOIDX_GetDirThumbSizeMap(const char* path, THUMB_TYPE type, int* size_map);
int SYNOIDX_GetThumbSizeMap(const char* path, THUMB_TYPE type, int* size_map);
int SYNOIDX_GetAllPluginName(Json::Value &plugin_names);
int SYNOIDX_IndexConvertAdd(SYNO_MEDIA_INFO* MediaInfoSrc, SYNO_MEDIA_INFO* MediaInfoConvert, Json::Value package = Json::objectValue);

//--------------------------------------------------
// Get Info From Mediad
//--------------------------------------------------

int SYNOIDX_GetMediaInfo(const char* path, SYNO_MEDIA_INFO *pMediaInfo);
int SYNOIDX_GetMediaResolution(const char* path, Resolution *pResolution);
int SYNOIDX_GetVideoMetadata(const char* path, VIDEO_METADATA* pVideoMetadata);

//--------------------------------------------------

#endif
