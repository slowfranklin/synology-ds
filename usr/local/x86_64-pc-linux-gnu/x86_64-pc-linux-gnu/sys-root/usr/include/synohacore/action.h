// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_ACTION_H
#define __SYNOHACORE_ACTION_H

#include <sys/cdefs.h>

__BEGIN_DECLS

/**
 * Stop HA cluster
 *
 * @retval >=0 the returned value of init script
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAStop(void);

__END_DECLS

#endif
