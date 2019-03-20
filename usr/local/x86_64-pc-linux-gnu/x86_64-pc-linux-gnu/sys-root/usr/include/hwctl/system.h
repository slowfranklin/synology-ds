/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_HWCTL_SYSTEM_H_
#define __SYNO_HWCTL_SYSTEM_H_

#include <synobios/synobios.h>

__BEGIN_DECLS;

int SYNOSysStatusAdd(sys_comp_stat_t *pComp_stat, SYNO_SYS_STAT_SIGNATURE signature, unsigned char is_comp_fail, unsigned int comp_index);
int SYNOSysStatusGet(SYNO_SYS_STATUS *pSysStatus);
int SYNOSysStatusCommit(sys_comp_stat_t comp_stat);
int SYNOSysStatusCompLookUp(SYNO_SYS_STATUS *pSysStatus, SYNO_SYS_STAT_SIGNATURE signature, sys_comp_stat_t *pCom_stat);
int SYNOIsComponentFail(SYNO_SYS_STATUS *pSysStatus, SYNO_SYS_STAT_SIGNATURE signature, sys_comp_stat_t *pComp_stat);

__END_DECLS;
#endif /* __SYNO_HWCTL_SYSTEM_H_ */
