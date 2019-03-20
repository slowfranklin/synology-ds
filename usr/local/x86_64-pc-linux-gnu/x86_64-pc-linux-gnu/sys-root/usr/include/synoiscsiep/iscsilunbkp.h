#ifndef _ISCSILUNBKP_H_
#define _ISCSILUNBKP_H_

#include <synoiscsiep/lun.h>

__BEGIN_DECLS;

#define ISCSI_LUNBKP_RESET_BITMAP_NAME          "reset-bitmap"

/**
 * define the lunbackup's defination
 * The definition is alos defined in synobackup/include/synobackup.h
 */
#define SZF_PROG_SYNOLUNBKP	                    "/usr/syno/bin/synolunbkp"
#define SZ_LUNBKP_CMD_FORMAT                    "%s --eq \"%s\""
#define LUNBKP_BITMAP_PATH                      "/usr/syno/etc/lunbkp"
#define LUNBKP_TASK_CONFIG                      LUNBKP_BITMAP_PATH "/lunbkptask.conf"
#define SZV_LUNBKP_UNKNOWN                      "unknown"
#define SZV_LUNBKP_NETWORK                      "network"
#define SZV_LUNBKP_INTERNAL                     "internal"
#define SZV_LUNBKP_EXTERNAL                     "external"

// lun backup config
#define SZK_ISCSI_LUNNAME                       "lunname"
#define SZK_ISCSI_FULL_PATH                     "full_path"
#define SZK_ISCSI_BKP_USER                      "backup_user"
#define SZK_ISCSI_DST_TYPE                      "dest_type"
#define SZK_ISCSI_LUNSIZE                       "lunsize"
#define SZK_ISCSI_BKP_DONE                      "bkp_done"
#define SZK_ISCSI_SN                            "serial_number"

enum {
	LUNBKP_UNKNOWN = 0,
	LUNBKP_NETWORK,
	LUNBKP_INTERNAL,
	LUNBKP_EXTERNAL,
};

enum {
	LUN_BKP_NONE = 0,
	LUN_BKP_FAIL,
	LUN_BKP_SUCCESS,
	LUN_BKP_CANCEL,
};

enum {
	LUN_BKP_END = 0,
	LUN_BKP_GOING,
};

typedef struct _tag_iscsi_lunbkptask_ {
	char szName[MAX_LEN_ISCSI_NAME];// lun name
	char szPath[MAX_PATH_LEN]; // location of this lun file
	char szUser[SYNO_DOMAIN_USERNAME_MAX]; // rsync synology mode support domain user
	char szTime[24];
	char szServer[MAX_FQDN_LEN];
	char szIP[CB_SZ_IP_MAX];
	char szPwd[SYNO_DOMAIN_PASS_MAX];
	int last_result;
	int stage;
	int dest_type;
	uint64_t lunsize;
	long schedule_id;
	int blocksize;
	ISCSI_LUN_TYPE luntype;
} ISCSI_LUNBKPTASK, *PISCSI_LUNBKPTASK;

long SYNOiSCSILunTaskGetSchIdByName(const char *szLunName);
int SYNOiSCSIGetTaskByLunName(const char *szLun, PISCSI_LUNBKPTASK pLunbkptask);
int lunbkp_taskconfig_get(const char *szUnique, PISCSI_LUNBKPTASK pLunbkptask);
int lunbkp_taskconfig_remove(const char *szTaskName);
int lunbkp_taskconfig_set(const char *szUnique, PISCSI_LUNBKPTASK pLunbkptask);
int lunbkp_taskconfig_update(ISCSI_LUN *pNewLun, ISCSI_LUN *pOldLun);

__END_DECLS

#endif
