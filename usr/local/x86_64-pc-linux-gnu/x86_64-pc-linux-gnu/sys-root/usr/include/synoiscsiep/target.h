#ifndef _SYNOISCSIEP_TARGET_H_
#define _SYNOISCSIEP_TARGET_H_

#include <synoiscsiep/lun.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/

/*** constants ***/
#define ISCSI_TARGET_DEFAULT_RECV_SEG_BYTES     262144
#define ISCSI_TARGET_DEFAULT_SEND_SEG_BYTES     262144
#define ISCSI_TARGET_DEFAULT_MAX_SESSIONS       1
#define ISCSI_TARGET_MAX_USER_NAME_SIZE         64
#define ISCSI_TARGET_MAX_PASSWORD_SIZE          64
#define ISCSI_TARGET_MAX_USERNAME_LENGTH        12
#define ISCSI_TARGET_MIN_USERNAME_LENGTH        1
#define ISCSI_TARGET_MAX_PASSWORD_LENGTH        16
#define ISCSI_TARGET_MIN_PASSWORD_LENGTH        12
#define ISCSI_TARGET_MAX_MAPPING_LUN            256
#define ISCSI_TARGET_MIN_TID                    1
#define ISCSI_TARGET_MAX_TID                    256
#define ISCSI_TARGET_DEFAULT_TPGT_NUMBER        1

#define MAX_NETWORK_PORTALS                     32   // IPV6 max len 46 section entry 512
#define MAX_LEN_NETWORK_PORTALS                 2048 // IPV6 max len 46 section entry 512
#define ISCSI_TARGRT_NP_DEFAULT_PORT            3260

/*** keys ***/
#define ISCSI_TARGET_AUTH_STR_UNKNOWN           "unknown"
#define ISCSI_TARGET_AUTH_STR_NONE              "-"
#define ISCSI_TARGET_AUTH_STR_READ              "r"
#define ISCSI_TARGET_AUTH_STR_WRITE             "w"
#define ISCSI_TARGET_AUTH_STR_RW                "rw"

/*** etc ***/

/*** types ***/
typedef enum {
	ISCSI_AUTH_NONE = 0,
	ISCSI_AUTH_SINGLE_CHAP,
	ISCSI_AUTH_MUTUAL_CHAP,
} ISCSI_AUTH_TYPE;

typedef struct _tag_iscsi_auth_ {
	ISCSI_AUTH_TYPE type;
	char szUserName[ISCSI_TARGET_MAX_USER_NAME_SIZE];
	char szPassword[ISCSI_TARGET_MAX_PASSWORD_SIZE];
	char szMutualUserName[ISCSI_TARGET_MAX_USER_NAME_SIZE];
	char szMutualPassword[ISCSI_TARGET_MAX_PASSWORD_SIZE];
} ISCSI_AUTH;

typedef struct _tag_iscsi_target_ {
	int tid;
	bool blEnabled;
	bool blPrevEnabledState;//record the previous enable state
	bool blHeaderChksum;
	bool blDataChksum;
	bool blBkpObj;		// this target is for lun backup only
	char szName[MAX_LEN_ISCSI_NAME];//name of target, could be edited by user. required input
	char szIQN[MAX_LEN_ISCSI_NAME];//iqn number, could be allow edited by user. required input
	char szNP[MAX_LEN_NETWORK_PORTALS];//network portals
	int maxRecvSegBytes;
	int maxSendSegBytes;
	int maxSessions;
	ISCSI_AUTH authType;
	SYNO_LINKED_LIST list;
} ISCSI_TARGET;

typedef enum {
	ISCSI_TARGET_AUTH_NONE    = 0,
	ISCSI_TARGET_AUTH_READ    = 0x01,
	ISCSI_TARGET_AUTH_WRITE   = 0x02,
	ISCSI_TARGET_AUTH_RW      = 0x03,
	ISCSI_TARGET_AUTH_UNKNOWN = 0x04,
} ISCSI_TARGET_AUTHORITY;

typedef struct _tag_struct_iscsi_acl_ {
	int tid;
	char szInitiatorIQN[MAX_LEN_ISCSI_NAME];
	ISCSI_TARGET_AUTHORITY authRW;
	SYNO_LINKED_LIST list;
} ISCSI_ACL;

typedef struct _tag_iscsi_mapping_ {
	int lun;//for mapping lun, -1 indicate generate automatic, others indicate mapped lun
	int lid;//for lun id, mandatory required input
	int tid;//for target id, mandatory  required input
	struct _tag_iscsi_lun_ *pLun;
	struct _tag_iscsi_target_ *pTrg;
	SYNO_LINKED_LIST list;
} ISCSI_MAPPING;

typedef struct _tag_struct_iscsi_network_portal_ {
	int tid;
	char szIP[CB_SZ_IPv6];
	int port;
	SYNO_LINKED_LIST list;
} ISCSI_NETWORK_PORTAL;

typedef struct _tag_struct_iscsi_network_portal_list_ {
	int tid;
	int np_cnt;
	SYNO_LINKED_LIST nps;
} ISCSI_TARGET_NETWORK_PORTAL_LIST;

typedef enum {
	ISCSI_COMPONENT_STATUS_NONE    = 0,
	ISCSI_COMPONENT_TARGET_ONLOAD  = 0x0001,
	ISCSI_COMPONENT_TARGET_ENABLE  = 0x0002,
} ISCSI_COMPONENT_STATUS;

/*** macro or inline functions ***/
static inline bool valid_tid_index(int id) { return (ISCSI_TARGET_MIN_TID <= id) && (ISCSI_TARGET_MAX_TID >= id); }
static inline bool valid_tpgt_index(int id) { return ISCSI_TARGET_DEFAULT_TPGT_NUMBER <= id; }

static inline const char * SYNOiSCSITargetAuthToString(ISCSI_TARGET_AUTHORITY authType) {
	switch (authType) {
	case ISCSI_TARGET_AUTH_NONE:
		return ISCSI_TARGET_AUTH_STR_NONE;
	case ISCSI_TARGET_AUTH_READ:
		return ISCSI_TARGET_AUTH_STR_READ;
	case ISCSI_TARGET_AUTH_WRITE:
		return ISCSI_TARGET_AUTH_STR_WRITE;
	case ISCSI_TARGET_AUTH_RW:
		return ISCSI_TARGET_AUTH_STR_RW;
	default:
		return ISCSI_TARGET_AUTH_STR_UNKNOWN;
	}
}

static inline ISCSI_TARGET_AUTHORITY
SYNOiSCSITargetAuthGetFromString(const char *szAuth)
{
	char *ptr = NULL;
	char szTmpAuth[64] = {0};

	snprintf(szTmpAuth, sizeof(szTmpAuth), "%s", szAuth);
	ptr = szTmpAuth;
	while ('\0' != *ptr) {
		*ptr = toupper(*ptr);
		++ptr;
	}

	if ( ! strcmp(ISCSI_TARGET_AUTH_STR_RW, szAuth)) {
		return ISCSI_TARGET_AUTH_RW;
	} else if ( ! strcmp(ISCSI_TARGET_AUTH_STR_READ, szAuth)) {
		return ISCSI_TARGET_AUTH_READ;
	} else if ( ! strcmp(ISCSI_TARGET_AUTH_STR_NONE, szAuth)) {
		return ISCSI_TARGET_AUTH_NONE;
	} else {
		return ISCSI_TARGET_AUTH_UNKNOWN;
	}
}

/*** function declarations ***/
int  SYNOiSCSITargetAliveCountGet(void);
int  SYNOiSCSITargetConfGetByName(const char *targetName, const int additionalFlag, ISCSI_CONFIG *pTargetConfig);
int  SYNOiSCSITargetConfGetByTid(const int targetId, const int additionalFlag, ISCSI_CONFIG *pTargetConfig);
int  SYNOiSCSITargetConfLoad(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pIscsiConfig);
int  SYNOiSCSITargetConfUpdate(const ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetConnectionStatusGet(const int tid, ISCSI_STATUS_REPORT *pStatusReport);
int  SYNOiSCSITargetCreate(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetDefaultAclSet(const ISCSI_TARGET *pTrg, ISCSI_TARGET_AUTHORITY authRW);
int  SYNOiSCSITargetDisable(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetDisableByLid(int *enabled_tid, const int lid);
int  SYNOiSCSITargetEnable(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetEnableByLid(int *enabled_tid, const int lid);
int  SYNOiSCSITargetGetByName(const char *targetName, const int additionalFlag, ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetMappingAdd(const int tid, const int lid, int mapLun);
int  SYNOiSCSITargetMappingsAdd(const int tid, const int *lid, const int map_count);
int  SYNOiSCSITargetMappingsRemove(const int tid, const int *lid, const int lid_count);
int  SYNOiSCSITargetNpExternalIPSet(const ISCSI_TARGET *pTrg, const char *szExtIP);
int  SYNOiSCSITargetRemove(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetSessionStateListFree(ISCSI_SESSION_STATE_LIST *pStateList);
int  SYNOiSCSITargetSessionStateListGet(const int tid, ISCSI_SESSION_STATE_LIST *pStateList);
ISCSI_COMPONENT_STATUS SYNOiSCSITargetStatusGet(const int tid, const ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetUpdate(ISCSI_TARGET *pTrg);
int  SYNOiSCSITargetNetworkPortalConfParse(const char *szNPConfEntry, ISCSI_TARGET_NETWORK_PORTAL_LIST *pNPList);
int  SYNOiSCSITargetNetworkPortalsRemove(ISCSI_TARGET *pTrg, ISCSI_TARGET_NETWORK_PORTAL_LIST *pNPList);
int  SYNOiSCSITargetNetworkPortalsAdd(ISCSI_TARGET *pTrg, ISCSI_TARGET_NETWORK_PORTAL_LIST *pNPList);
int  SYNOiSCSITargetConfMappingLoad(const ISCSI_FILTER *pFilter, ISCSI_CONFIG *pIscsiConfig);

__END_DECLS

#ifdef __cplusplus

#include <string>
#include <vector>

int  SYNOiSCSITargetMaskingGet(const int tid, std::vector<ISCSI_ACL> &vACLs);
int  SYNOiSCSITargetMaskingsCreate(const std::vector<ISCSI_ACL> &vACLs);
int  SYNOiSCSITargetMaskingsRemove(const std::vector<ISCSI_ACL> &vACLs);
int  SYNOiSCSITargetMaskingsUpdate(const std::vector<ISCSI_ACL> &vACLs);

#endif // __cplusplus

#endif // _SYNOISCSIEP_TARGET_H_
