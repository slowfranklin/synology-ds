// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_PRIORITY_H
#define __SYNOHACORE_PRIORITY_H

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS

/**
 * Check calling process name and see if we need to change process priorities
 *
 * Target processes are those with the following name prefix:
 * <ul>
 *   <li> synoscgi_SYNO.Storage.CGI.
 *   <li> synoscgi_SYNO.Core.Storage.
 * </ul>
 *
 * @retval TRUE need to change process priority
 * @retval FALSE do not need to change process priority
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @see SYNOHAGetPriority
 * @see SYNOHASetPriority
 */
BOOL SYNOHAChkIfChangePriority(void);

/**
 * Get the process priorities
 *
 * @param [out] cpuPriority      pointer to int holding CPU priority
 * @param [out] ioPriority       pointer to int holding I/O priority
 * @param [out] oomscorePriority pointer to int holdoing oom_score_adj
 * @param [out] oomPriority      pointer to int holding oom_adj
 * @retval TRUE success
 * @retval FALSE error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 * @see SYNOHAChkIfChangePriority
 */
BOOL SYNOHAGetPriority(int *cpuPriority, int *ioPriority, int* oomscorePriority, int* oomPriority);

/**
 * Set the process priorities
 *
 * @param [in] cpuPriority      int value to be set as CPU priority
 * @param [in] ioPriority       int value to be set as IO priority
 * @param [in] oomscorePriority int value to be set as oom_score_adj priority
 * @param [in] oomPriority      int value to be set as oom_adj priority
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 * @see SYNOHAChkIfChangePriority
 */
void SYNOHASetPriority(int cpuPriority, int ioPriority, int oomscorePriority, int oomPriority);

__END_DECLS

#endif
