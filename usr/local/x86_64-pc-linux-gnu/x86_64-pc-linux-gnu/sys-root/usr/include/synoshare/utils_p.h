// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/* attr_uuid_get.c */
int SYNOShareUuidGet(const PSYNOSHARE pShare, char *szUuid, size_t cbUuid);

/* share_create.c */
int SYNOShareCreate(const PSYNOSHARE pShare, const PSYNOSHAREARGS pArgs);
int SYNOShareClone(const PSYNOSHARE pOrigShare, const PSYNOSHARE pNewShare, const char *szSnapName);
/* share_delete.c */
int SYNOShareDelete(const PSLIBSZLIST pShareNameList, BOOL blCleanData, PSLIBCMRESULT *ppMResult);
/* share_move.c */
int SYNOShareMove(const char *szOldShareName, const char *szNewShareBin, PFUNC_Prog pfuncSetProgress, PFUNC_ErrReport pfuncErrReport, PSYNOSHAREARGS pArgs);
PSYNOSHAREARGS SYNOShareArgsAlloc();
int SYNOShareArgsSetNodatacow(PSYNOSHAREARGS pArgs, BOOL blNodatacow);
int SYNOShareArgsGetNodatacow(const PSYNOSHAREARGS pArgs);
int SYNOShareArgsSetCompression(PSYNOSHAREARGS pArgs, BOOL blCompression);
int SYNOShareArgsGetCompression(const PSYNOSHAREARGS pArgs);
int SYNOShareArgsSetEncryptPassword(PSYNOSHAREARGS pArgs, const char *szPassword);
char * SYNOShareArgsGetEncryptPassword(const PSYNOSHAREARGS pArgs);
/* share_transform.c */
int SYNOShareTransform(const char *szOldShareName, const char *szNewShareBin,
PFUNC_Prog pfuncSetProgress, PFUNC_ErrReport pfuncErrReport, PSYNOSHAREARGS pArgs);
/* share_rename.c */
int SYNOShareRename(const char *szOldShareName, const char *szNewShareName);
/* share_update.c */
int SYNOShareUpdate(const PSYNOSHARE pShare);
/* share_validate */
int SYNOShareValidate(const PSYNOSHARE pShare);
/* share_restore */
int SYNOShareRestore(const char *szVolPath);
int SYNOShareRestoreSingle(const char *szVolPath, char *szShareName);
/* share_external_vol_export.c */
int SYNOShareExternalVolExport(const char *szDevicePath, const char *szMountPoint, int fDevType);
/* share_get_new_share_path.c */
BOOL SYNOShareGetNewSharePath(const PSYNOSHARE pOldShare, const char* szNewShareBinPath, char* szNewSharePath, size_t cbNewSharePath);
/* share_default_get.c */
int SYNOShareAllocExternalDefaultPermissionStr(char **szDeny, char **szRW, char **szRO);
int SYNOShareDefaultGet(SHARE_DEF_OPTION *pOpt, PSYNOSHARE *ppShare);
/* share_default_set.c */
int SYNOShareSetExternalDefaultPermissionStr(const char *szDeny, const char *szRW, const char *szRO);
/* share_default_share_create.c */
int SYNOShareDefaultShareCreate(const char* szShareName, const char* szSharePath, const PSYNOSHAREARGS pArgs);
/* share_permit_access.c */
int SYNOSharePermitAccess(PSYNOSHARE pShare, BOOL blPermit);
/* share_permit_access_by_name.c */
int SYNOSharePermitAccessByName(const char *szShareName, BOOL blPermit);
/* share_service_link_remove.c */
int SYNOShareServiceLinkRemove(const char *szLinkName);
/* share_service_link_set.c */
int SYNOShareServiceLinkSet(const char *szLinkName, const char *szServicePath);
/* share_service_restore.c */
int SYNOShareServiceRestore(const char *szVolPath);
/* share_is_sd_section.c */
BOOL SYNOShareIsSdShare(const char *szName);

/* share_snapshot_restore.c */
int SYNOShareSnapRestore(const PSYNOSHARE pShare, const char *szSnapName, BOOL blRestoreShareConfig);
int SYNOShareSnapRestoreNoReadOnlyReg(const PSYNOSHARE pShare, const char *szSnapName, BOOL blRestoreShareConfig);

/* share_snapshot_bind_ubind.c */
int SYNOShareSnapBind(const PSYNOSHARE pShare);
int SYNOShareSnapUnbind(const PSYNOSHARE pShare);
int SYNOShareSnapUnbindPure(const PSYNOSHARE pShare);

#ifdef SYNOSHARE_ENABLE_CUSTOM_OPERATIONS
/* share_create.c */
int SYNOShareCustomCreate(const PSYNOSHARE pShare,
		PFUNC_SHARE_CREATE pCreateFunc, void *pData);
/* share_rename.c */
int SYNOShareCustomRename(const char *szOldShareName, const char *szNewShareName,
		PFUNC_SHARE_RENAME pRenameFunc, void *pData);
/* share_delete.c */
int SYNOShareCustomDelete(const PSLIBSZLIST pShareNameList, BOOL blCleanData,
		PSLIBCMRESULT *ppMResult, PFUNC_SHARE_DELETE pDeleteFunc, void *pData);
/* share_move.c */
int SYNOShareCustomMove(const char *szShareName, const char *szNewShareBinPath,
		PFUNC_Prog pProgFunc, PFUNC_ErrReport pErrFunc,
		PFUNC_SHARE_MOVE pMoveFunc, void *pData);
/* share_transform.c */
int SYNOShareCustomTransform(const char *szShareName, const char *szNewShareBinPath,
		PFUNC_Prog pProgFunc, PFUNC_ErrReport pErrFunc,
		PFUNC_SHARE_MOVE pMoveFunc, void *pData);
#endif   // SYNOSHARE_ENABLE_CUSTOM_OPERATIONS
