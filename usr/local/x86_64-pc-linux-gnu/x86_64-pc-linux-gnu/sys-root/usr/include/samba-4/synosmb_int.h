// Copyright (c) 2000-2016 Synology Inc. All rights reserved.

//Use samba internal lib function
#include <tdb.h>

//Plugin env struct
typedef struct {
	PSLIBSZLIST plistNewName;
	PSLIBSZLIST plistOldName;
	PSLIBSZLIST plistUGid;
}RENAME_INFO;

typedef struct {
	PSLIBSZLIST plistNewName;
	PSLIBSZLIST plistUGid;
}DELETE_INFO;

typedef struct _tag_DOMAINPLUGIN {
	char szDomain[MAX_WORKGROUP_LEN];
	char szDomSid[SYNO_MAX_SID_LEN];
	RENAME_INFO rename_info;
	DELETE_INFO delete_info;
	PSLIBSZHASH pHash;		//[IN] new rid <--> name hash
	TDB_CONTEXT *idmap_tdb;
}DOMAIN_PLUGIN;

// for single change
#define CHANGE_FLAG_RENAME 1
#define CHANGE_FLAG_DELETE 2
struct ChangeInfo {
	DOMAIN_PLUGIN *pDomPlugin;
	int flag;
	uint32_t rid;
	const char *pNewName;
};
/* domain_idmap.c */
uint32_t SYNOSMBDomainIdMapping(TDB_CONTEXT *tdb, const char *szDomSid, const char *szRid);
