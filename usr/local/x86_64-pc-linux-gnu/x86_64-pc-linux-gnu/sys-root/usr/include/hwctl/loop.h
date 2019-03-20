/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_HWCTL_LOOP_H_
#define __SYNO_HWCTL_LOOP_H_

__BEGIN_DECLS;

#define LOOP_FORMAT "/dev/loop%d"
#define SZ_TEMP_DIR_TEMPLATE "/tmp/loop.XXXXXX"
#define SZF_LOSETUP "/sbin/losetup"
#define SZF_LSMOD   "/sbin/lsmod"

int LoopDevAlloc(const char *szLoopPath, const int offset, const char *szPath);
int LoopDevFree(const char *szLoopPath);
int LoopEmptyDevGet(void);
int LoopModuleInsmod(void);
int LoopPartitionOffsetGet(const char *szPath, int partitionNum, int *pOffset);

__END_DECLS;
#endif /* __SYNO_HWCTL_FAN_H_ */
