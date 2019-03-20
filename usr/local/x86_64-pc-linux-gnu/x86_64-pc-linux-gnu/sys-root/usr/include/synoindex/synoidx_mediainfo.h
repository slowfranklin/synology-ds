// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_MEDIAINFO_H
#define _SYNO_IDX_MEDIAINFO_H

#include <json/value.h>

#include <synoindex/synoidx.h>

//--------------------------------------------------

void MediaInfoObject2Json(SYNO_MEDIA_INFO& obj, Json::Value& json);
void MediaInfoJson2Object(Json::Value& json, SYNO_MEDIA_INFO& obj);
void SyslogMediaInfoObject(SYNO_MEDIA_INFO& obj);
void PrintMediaInfoObject(SYNO_MEDIA_INFO& obj);

void VideoMetadataObject2Json(VIDEO_METADATA& obj, Json::Value& json);
void VideoMetadataJson2Object(Json::Value& json, VIDEO_METADATA& obj);
void MediaInfoFillTitleAndAlbum(Json::Value &media);

//--------------------------------------------------

#endif
