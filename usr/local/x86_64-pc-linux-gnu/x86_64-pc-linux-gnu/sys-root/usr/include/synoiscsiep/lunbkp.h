/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_LUNBKP_H_
#define _SYNOISCSIEP_LUNBKP_H_

#include <synoiscsiep/lun.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/

/*** constants ***/
#define LUNBKP_RETRY                            20

/*** keys ***/

/*** etc ***/
// For compatibility
#define ISCSI_TMP_FILE_DIR                      ISCSI_TMP_DIR_PATH

/*** types ***/
typedef enum tag_lunbkp_type {
	LUNBKP_BACKUP = 0,
	LUNBKP_RESTORE,
} LUNBKP_TYPE;

enum tag_syno_lun_backup_state {
	SYNO_HEALTHY                         = 0x000000, /* healthy */
	SYNO_BITMAP_READ_ERROR               = 0x000001, /* A read error has occurred */
	SYNO_BITMAP_WRITE_ERROR              = 0x000002, /* A write error has occurred */
	SYNO_DATA_BITMAP_READ_ERROR          = 0x000004, /* A read error has occurred */
	SYNO_DATA_BITMAP_WRITE_ERROR         = 0x000008, /* A write error has occurred */
	SYNO_BACKUP_READ_ERROR               = 0x000010, /* A read error has occurred */
	SYNO_BACKUP_WRITE_ERROR              = 0x000020, /* A write error has occurred */
	SYNO_RESTORE_READ_ERROR              = 0x000040, /* A read error has occurred */
	SYNO_RESTORE_WRITE_ERROR             = 0x000080, /* A write error has occurred */
	SYNO_DATA_CHANGED_BITMAP_READ_ERROR  = 0x000100, /* A read error has occurred */
	SYNO_DATA_CHANGED_BITMAP_WRITE_ERROR = 0x000200, /* A write error has occurred */
	SYNO_LUN_BACKUP_BUG                  = 0x001000, /* An impossible error cause by BUG */

	SYNO_UNHEALTHY                       = 0x00FFFF, /* any state above */

	SYNO_LUN_BACKUP_READ_DONE            = 0x400000, /* all records had read from source */
	SYNO_LUN_BACKUP_WRITE_DONE           = 0x800000, /* all records had write to destination */
	SYNO_LUN_BACKUP_ALL_DONE             = 0xC00000, /* all records from source to destination is done */
};

/*** macro or inline functions ***/

/*** function declarations ***/
int  SYNOiSCSILunBkpBackupLunMove(ISCSI_LUN *pLun, const char *szDstPath);
int  SYNOiSCSILunBkpBitmapReset(ISCSI_LUN *pLun);
int  SYNOiSCSILunBkpSmartddActivate(ISCSI_LUN *pLun, const char *szDstPath, LUNBKP_TYPE type);
int  SYNOiSCSILunBkpSmartddDeactivate(ISCSI_LUN *pLun, LUNBKP_TYPE type);
int  SYNOiSCSILunBkpSmartddProgressGet(ISCSI_LUN *pLun, int *pProgress,
		unsigned long long *pUllSmartDDOffSet, unsigned long long *pUllTotalSector);
int  SYNOiSCSILunBkpTargetConnect(const char *szIP, const char *szIQN, char *szBlockDev, int cbBlockDev);
int  SYNOiSCSILunBkpTargetDisconnect(const char *szIP, const char *szIQN);
int  SYNOiSCSILunBkpSizeGet(ISCSI_LUN *pLun, unsigned long long *pUllSector);

__END_DECLS

#endif // _SYNOISCSIEP_LUNBKP_H_
