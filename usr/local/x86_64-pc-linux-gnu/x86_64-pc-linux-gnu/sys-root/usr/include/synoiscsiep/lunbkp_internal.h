/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_LUNBKP_INTERNAL_H_
#define _SYNOISCSIEP_LUNBKP_INTERNAL_H_

#include <synoiscsiep/lunbkp.h>
#include <synoiscsiep/lun_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define SZK_BACKUP_PATH                         "syno_backup_lun_path"
#define SZK_RESTORE_PATH                        "syno_restore_lun_path"
#define SZK_ENABLE_THREAD                       "lunbkp_thread_enable"
#define SZK_LUNBKP_PARAM                        "lunbkp_param"
#define SZK_SMARTDD_STATE                       "lunbkp_state"
#define SZK_SMARTDD_OFFSET                      "smartdd_offset"
#define SZK_LUNBKP_NR_WRITE_THREAD              "nr_write_thread"

/*** constants ***/

/*** keys ***/
#define SZK_ISCSI_LST_BKP_TIME                  "last_bkp_time"
#define SZK_ISCSI_LST_BKP_RESULT                "last_bkp_result"
#define SZK_ISCSI_STAGE                         "stage"
#define SZK_ISCSI_BKP_SERVER                    "bkp_server"
#define SZK_ISCSI_BKP_IP                        "bkp_ip"
#define SZK_ISCSI_SVR_PWD                       "server_passwd"
#define SZK_ISCSI_SCH_ID                        "schedule_id"
#define SZK_ESTIMATE_NODE                       "estimate_copy"

/*** etc ***/

/*** types ***/

/*** macro or inline functions ***/

/*** function declarations ***/

__END_DECLS

#endif // _SYNOISCSIEP_LUNBKP_INTERNAL_H_
