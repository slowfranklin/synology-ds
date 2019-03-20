#ifndef _SYNOISCSIEP_TARGET_INTERNAL_H_
#define _SYNOISCSIEP_TARGET_INTERNAL_H_

#include <synoiscsiep/target.h>
#include <synoiscsiep/lun_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/
#define ISCSI_TARGET_CONF_PATH                  "/usr/syno/etc/iscsi_target.conf"
#define ISCSI_TARGET_MAPPING_CONF_PATH          "/usr/syno/etc/iscsi_mapping.conf"
#define ISCSI_TARGET_ACL_CONF_PATH              "/usr/syno/etc/iscsi_acl.conf"
#define ISCSI_TARGET_CONF_LOCK_PATH             ISCSI_TMP_DIR_PATH "/iscsi_target.conf.lock"
#define ISCSI_TARGET_MAPPING_CONF_LOCK_PATH     ISCSI_TMP_DIR_PATH "/iscsi_mapping.conf.lock"
#define ISCSI_TARGET_ACL_CONF_LOCK_PATH         ISCSI_TMP_DIR_PATH "/iscsi_acl.conf.lock"

/*** constants ***/
#define ISCSI_TARGET_DEFAULT_CMDSN_DEPTH        16

/*** keys ***/
#define ISCSI_TARGET_CMDSN_DEPTH                "iscsitrg_cmdsn_depth"

/*** etc ***/
#define ISCSI_TARGET_SECTION_FORMAT             ISCSI_TAG "T%d"
#define ISCSI_TARGET_MAP_SECTION_FORMAT         ISCSI_TAG "MAP_T%d_L%d"
#define ISCSI_TARGET_ACL_SECTION_FORMAT         ISCSI_TAG "ACL_T%d_%s"
#define ISCSI_TARGET_DEFAULT_INITIATOR          "iqn.2000-01.com.synology:default.acl"
#define QUEUE_MODE_MULTI_STRING                 "multi"

/*** types ***/
typedef struct _tag_struct_iscsi_target_acl_list_ {
	int tid;
	int acl_cnt;
	SYNO_LINKED_LIST acls;
} ISCSI_TARGET_ACL_LIST;

/*** macro or inline functions ***/
static inline bool valid_auth_type(ISCSI_TARGET_AUTHORITY type) { return (ISCSI_TARGET_AUTH_NONE <= type) && (ISCSI_TARGET_AUTH_RW >= type); }

/*** function declarations ***/
bool SYNOiSCSILioIsTargetAlive(const char *szIQN, int tpgt);
int  SYNOiSCSILioMappingAdd(const ISCSI_TARGET *pTrg, ISCSI_LUN *pLun, const int mapLun, const ISCSI_TARGET_ACL_LIST *pACLList);
int  SYNOiSCSILioTargetAclAdd(const ISCSI_TARGET *pTrg);
int  SYNOiSCSILioTargetAllow(const ISCSI_TARGET *pTrg);
int  SYNOiSCSILioTargetChapAuthAdd(ISCSI_AUTH_TYPE type, const char *szIQN, const int tpgt, const char *szUserName, const char *szPassword);
int  SYNOiSCSILioTargetDisable(ISCSI_TARGET *pTrg);
int  SYNOiSCSILioTargetDisallow(const ISCSI_TARGET *pTrg);
int  SYNOiSCSILioTargetDummyTest();
int  SYNOiSCSILioTargetEnable(ISCSI_TARGET *pTrg, ISCSI_TARGET_ACL_LIST *pACLList);
int  SYNOiSCSILioTargetLoad(ISCSI_TARGET *pTrg, bool blDummy);
int  SYNOiSCSILioTargetLunAclInitiatorAdd(const char *szIQN, const int tpgt, const char *szInitiatorIQN, const int lun);
int  SYNOiSCSILioTargetLunAclInitiatorRemove(const char *szIQN, const int tpgt, const char *szInitiatorIQN, const int lun);
int  SYNOiSCSILioTargetLunInitiatorRw(const char *szIQN, const int tpgt, const ISCSI_ACL *pACL, const int lun);
int  SYNOiSCSILioTargetMaskingsChapAuthAdd(const ISCSI_TARGET *pTrg, const int tpgt);
int  SYNOiSCSILioTargetNetworkPortalLoad(const ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetAclStructCreate(const PSLIBSZHASH pshHash, ISCSI_ACL **ppACL);
int  SYNOiSCSITargetConfAclAdd(const int tid, const char *szInitiatorIQN, ISCSI_TARGET_AUTHORITY type);
int  SYNOiSCSITargetConfAclIsExist(const int tid, const char *szInitiatorIQN);
int  SYNOiSCSITargetConfAclLoad(const int tid, ISCSI_TARGET_ACL_LIST *pACLList);
int  SYNOiSCSITargetConfAclRemove(const int tid, const char *szInitiatorIQN);
int  SYNOiSCSITargetConfAclsRemove(const int tid);
int  SYNOiSCSITargetConfAdd(const ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetConfMappingAdd(const int tid, const int lid, const int mapLun);
int  SYNOiSCSITargetConfMappingMake(ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSITargetConfMappingRemove(int tid, int lid);
int  SYNOiSCSITargetConfRemove(const ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetDefaultAclEnable(const ISCSI_TARGET *pTrg, ISCSI_TARGET_AUTHORITY authRW);
int  SYNOiSCSITargetGetByFilter(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pTargetConfig);
int  SYNOiSCSITargetGetByTid(const int targetId, const int additionalFlag, ISCSI_TARGET *pTrg);
bool SYNOiSCSITargetIsAlive(const int tid);
int  SYNOiSCSITargetIsertControl(const ISCSI_TARGET *pTrg, const char *szIP, const bool blEnable);
int  SYNOiSCSITargetIsLunMapped(int tid, int mapLun, bool *pblMapped);
int  SYNOiSCSITargetIsNameUsed(const char *szName);
int  SYNOiSCSITargetiSNSDeregister(const ISCSI_TARGET* target);
int  SYNOiSCSITargetiSNSRegister(const ISCSI_TARGET* target);
int  SYNOiSCSITargetLoad(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetLunIsMapped(const ISCSI_MAPPING *pMapping, bool *pRet);
int  SYNOiSCSITargetMappingObjectCreate(const PSLIBSZHASH pshHash, ISCSI_MAPPING **ppMapping);
int  SYNOiSCSITargetMappingRemove(int tid, int lid);
int  SYNOiSCSITargetMappingUnload(const int tid, const int lid, const ISCSI_MAPPING *pMapping);
int  SYNOiSCSITargetMaskingCreate(const ISCSI_ACL *pACL);
int  SYNOiSCSITargetMaskingRemove(const ISCSI_ACL *pACL);
int  SYNOiSCSITargetMaskingUpdate(const ISCSI_ACL *pACL);
int  SYNOiSCSILioTargetNetworkPortalAdd(const ISCSI_TARGET *pTrg, const char *szIP, int port);
int  SYNOiSCSILioTargetNetworkPortalRemove(ISCSI_TARGET *pTrg, const char *szIP, int port);
int  SYNOiSCSITargetStructCreate(const PSLIBSZHASH pshHash, ISCSI_TARGET **ppTrg);
int  SYNOiSCSITargetUnload(ISCSI_TARGET *pTrg);
int	 SYNOiSCSITargetUnusedNameFind(const char *szPrefix, char *szUnusedName, int cbUnusedName);
int  SYNOiSCSITargetUnusedTidFind(int *unusedTid);

__END_DECLS

#ifdef __cplusplus

#include <string>
#include <vector>

int  SYNOiSCSILioTargetNodeAclAdd(const std::string &IQN, const int tpgt, const std::string &initiatorIQN);
int  SYNOiSCSITargetAclIsIncluded(const int tid, const std::vector<ISCSI_ACL> &vACLs, bool &rBool);
int  SYNOiSCSITargetConfAclUpdate(const int tid, const std::string &initiatorIQN, ISCSI_TARGET_AUTHORITY type);
int  SYNOiSCSITargetPortalGroupLunRemoveEntry(const std::string &targetPortalGroupLUNEntryPath);
int  SYNOiSCSITargetPortalGroupNodeAclRemove(const std::string &nodeACLPath);
int  SYNOiSCSITargetPortalGroupNpUnload(const std::string &targetPortalGroupPath);
int  SYNOiSCSITargetUnloadByIqn(const std::string &IQN);
int  SYNOiSCSITargetUnloadByConfigfsPath(const std::string &targetPath);

#endif // __cplusplus

#endif // _SYNOISCSIEP_TARGET_INTERNAL_H_
