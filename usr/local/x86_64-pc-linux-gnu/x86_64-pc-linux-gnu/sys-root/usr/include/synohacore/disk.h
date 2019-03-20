// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_DISK_H
#define __SYNOHACORE_DISK_H

#include <sys/cdefs.h>

__BEGIN_DECLS

/**
 * Start to do remote disk S.M.A.R.T test
 *
 * @param [in] szArg of syno_smart_test
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHASmartRemoteRun(const char *szArg);

__END_DECLS

#endif
