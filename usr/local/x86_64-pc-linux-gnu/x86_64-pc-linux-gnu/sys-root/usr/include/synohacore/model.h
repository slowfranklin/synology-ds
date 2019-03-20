// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOHACORE_MODEL_H
#define __SYNOHACORE_MODEL_H

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS

/**
 * Get the HA serial number, for services that use serial number as identifier, for internal use
 * SHOULD NOT use this function directly
 *
 * @param [in]  isCustom TRUE: custom serial number, FALSE: mtd serial number
 * @param [out] szSN     HA serial number
 * @param [in]  cbMac    size of @p szSN
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetSN(BOOL isCustom, char *szSN, unsigned int cbSN);

/**
 * Get the HA model, for services that use model name as identifier
 *
 * @param [out] szModel pointer to storage for HA model
 * @param [in]  cbModel size of @p szModel
 * @retval 0 success
 * @retval -1 error
 * @grantable N
 * @apparmor abstractions/libsynohacore
 */
int SYNOHAGetModel(char *szModel, size_t cbModel);

__END_DECLS

#endif
