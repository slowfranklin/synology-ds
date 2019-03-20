// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

/* system_check_space_busy.c */
BOOL SYNOPowerOffSystemCheckSpaceBusy(void);
/* system_is_safe_shutdown.c */
BOOL SYNOPowerOffSystemIsSafeShutdown(void);
/* system_safe_shutdown_set.c */
int SYNOPowerOffSystemSafeShutdownSet(BOOL blSet);
/* system_set_boot_seq.c */
int SYNOPowerOffSystemSetBootStep(const SYNO_BOOT_SEQ iStep);
/* system_poweroff_sys_init.c */
int SYNOPowerOffSystemInit(SLIB_INIT_OPT opt, int type);
