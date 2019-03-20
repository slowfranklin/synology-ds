// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_APPLOG_H
#define _SYNO_IDX_APPLOG_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

#define APPLOG(priority, format, ...) AppLogError(priority, "%s:%d "format, __FILE__, __LINE__, ## __VA_ARGS__);
#define APPLOGJSON(priority, msg, format, ...) AppLogJson(priority, msg, "%s:%d "format, __FILE__, __LINE__, ## __VA_ARGS__);

//--------------------------------------------------

void ChageLogLevel(int level);
void AppLogError(int priority, const char *format, ...);
void AppLogJson(int priority, Json::Value msg, const char *format, ...);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
