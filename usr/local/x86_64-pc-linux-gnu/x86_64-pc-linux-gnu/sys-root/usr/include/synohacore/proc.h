/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNOHA_PROC_H__
#define __SYNOHA_PROC_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS

/**
 * Check whether parent is synoschedtask
 *
 * @retval TRUE synoschedtask
 * @retval FALSE Not synoschedtask
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
BOOL SYNOHAIsRunBySynoschedtask();

__END_DECLS

#endif
