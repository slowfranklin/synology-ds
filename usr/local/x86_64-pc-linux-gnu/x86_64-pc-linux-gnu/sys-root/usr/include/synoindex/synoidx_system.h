// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_SYSTEM_H
#define _SYNO_IDX_SYSTEM_H

// standard
#include <syslog.h>

// library
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>

// syno
#include <synocore/proc.h>

// project
#include <synoindex/synoidx.h>
#include <synoindex/synoidx_applog.h>

//--------------------------------------------------

void WaitSystemReady();

int ForkExecv(const char *szPath, char *const ppszArgv[]);

int RenameFile(const char* oldname, const char* newname);
int FileRemoveHeadingLine(const char *szFile, int num);
char* GetRealPath(const char *path);

int WriteIndexQueue(const char * szPath, const char * szQueuePath);
int WriteThumbQueue(const char* path, THUMB_TYPE type);

int GetTotalMemory(long* memtotal_kb);
int GetMemoryUsagekb(int pid, long* vmrss_kb, long* vmsize_kb);
int GetFileDescriptorNum(int pid);

//--------------------------------------------------

#endif
