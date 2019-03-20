#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef SYNOHA_LIBCRM_H
#define SYNOHA_LIBCRM_H

#ifdef MY_ABC_HERE

#include <synohacore/node.h>
#include <synohacore/strings.h>

#define SZK_CRM_CONF_DRBD_PREFIX        "DRBD"
// dummy resource start and end
#define SZ_DUMMY_START                  "DUMMY_START"
#define SZ_DUMMY_END                    "DUMMY_END"
#define SZ_CONF_SYNC                    "CONF_SYNC"
#define SZ_INFO_SET                     "INFO_SET"
#define SZ_CHECKPOINT_LAST              "CHECKPOINT_LAST"
#define SZ_PING                         "PING_SERVER"

typedef enum {
	CRM_CONSTRAINT_SYNC_DONE,
	CRM_CONSTRAINT_SPACE_SYNC,
	CRM_CONSTRAINT_SERV_FAIL,
	CRM_CONSTRAINT_MEMSIZE,
	CRM_CONSTRAINT_PING,
	CRM_CONSTRAINT_SB_HOST,
	CRM_CONSTRAINT_VER_MISMATCH,
	CRM_CONSTRAINT_MAX,
} CRM_CONSTRAINT_TYPE;

#define SZK_CRM_CONSTRAINT_SYNC_DONE  "RULE_SYNC_DONE"
#define SZK_CRM_CONSTRAINT_SPACE_SYNC "RULE_SPACE_SYNC"
#define SZK_CRM_CONSTRAINT_SERV_FAIL  "RULE_SERV_FAIL"
#define SZK_CRM_CONSTRAINT_MEMSIZE    "RULE_MEMSIZE"
#define SZK_CRM_CONSTRAINT_PING       "RULE_PING_SERVER"
#define SZK_CRM_CONSTRAINT_SB_HOST    "RULE_SB_%s"
#define SZK_CRM_CONSTRAINT_VER_MISMATCH "RULE_VER_MISMATCH"

int HACrmConfInit(BOOL isEraseAll);
int HACrmConfReset(BOOL isEraseAll);
BOOL HACrmHasFailedOp(NODE_TYPE type);
BOOL HACrmOnline(NODE_TYPE type);
BOOL HACrmIsResourceRunningAt(const char* szHost, const char* szResourceName);
BOOL HACrmStandby(NODE_TYPE type);
BOOL HACrmHasAnyConstraintOnNode(NODE_TYPE type);
BOOL HACrmHasConstraintOnNode(NODE_TYPE type, CRM_CONSTRAINT_TYPE constraintType);
int HACrmSetConstraintOnNode(BOOL isAdd, NODE_TYPE nodeType, CRM_CONSTRAINT_TYPE constraintType);
int HACrmRemoveConstraint(NODE_TYPE nodeType);
int HACrmRemoveRemote(const char *szUnbindType);
BOOL HACrmIsNodeExist(NODE_TYPE type);
BOOL HACrmIsResourceConfigured(const char* resourceName);
int HACrmRestartIP();
int HACrmUnmanageIP();
int HACrmManageIP();
BOOL HACrmIsIPUnmanaged();
int HACrmCleanState();
BOOL HAWaitCrmDone();
int HACrmIncreaseAdminEpoch();

#endif /* MY_ABC_HERE */

#endif
