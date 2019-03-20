/* snapshot_create.c */
int SYNOShareSnapCreate(const PSYNOSHARE pShare, char *szSnapName, size_t cbSnapName, PSLIBSZHASH *ppAttrHash);
int SYNOShareSnapCreateNoShareInfo(const PSYNOSHARE pShare, char *szSnapName, size_t cbSnapName, PSLIBSZHASH *ppAttrHash);
int SYNOShareSnapCreateLogSet(const PSYNOSHARE pShare, const char *szSnapName, const char *callerType, BOOL success);
int SYNOShareSnapCheckReachMaxSnapshot(const PSYNOSHARE pShare);
int SYNOShareSnapMaximumGet();
int SYNOShareSnapGlobalMaximumGet();
/* snapshot_delete.c */
int SYNOShareSnapDelete(const PSYNOSHARE pShare, const PSLIBSZLIST pListSnap, PSLIBCMRESULT *ppMResult);
int SYNOShareSnapDeleteLogSet(const PSYNOSHARE pShare, const char *szSnapName, const char *callerType, const BOOL success);
/* snapshot_list.c */
int SYNOShareSnapList(const PSYNOSHARE pShare, PSLIBSZLIST *ppListSnap, PSYNOSHARESNAPENUM pSYNOShareSnapEnum);
/* snapshot_attr.c */
int SYNOShareSnapAttrSet(const PSYNOSHARE pShare, const char *szSnapName, const char *szAttr, const char *szValue);
int SYNOShareSnapAttrGet(const PSYNOSHARE pShare, const char *szSnapName, const char *szAttr, char *szValue, size_t cbValue);
int SYNOShareSnapAttrDelete(const PSYNOSHARE pShare, const char *szSnapName, const char *szAttr);
int SYNOShareSnapAttrList(const PSYNOSHARE pShare, const char *szSnapName, PSLIBSZHASH *ppHash);
int SYNOShareSnapAttrMultiSet(const PSYNOSHARE pShare, const char *szSnapName, PSLIBSZHASH pAttrHash);
/* snapshot_utils.c */
int SYNOShareSnapDefaultAttr(PSLIBSZHASH *ppAttrHash);
int SYNOShareSnapCheckSupport(const PSYNOSHARE, FSTYPE *pFSType, SNAPSHOT_ACTION action);
int SYNOShareSnapGetSnapPath(const PSYNOSHARE pShare, const char *szSnapshot, char *szBuf, size_t cbBuf);
int SYNOShareSnapSendNotification(const char* tag, const char* szShareName, PSLIBSZHASH *ppHash);
int SYNOSnapFillSubvolInfoWithPath(const char* szSubvolPath, PSLIBSZHASH *ppHash);
int SYNOShareSnapGetLatest(const PSYNOSHARE pShare, char *szSnapshot, const size_t cbSnapshot);
int SYNOShareSnapNameGetByTime(const PSYNOSHARE pShare, char *szSnapshot, const size_t cbSnapshot, const time_t snapshotTime);
int SYNOShareSnapTimeGet(const char *szSnapName, time_t *snapshotTime);
/* snapshot_filter.c */
int SYNOShareSnapSelectorAdd(PPSYNOSHARESNAPENUM ppSYNOShareSnapEnum, PSNAP_SELECTOR_FUNC pSelector, uintptr_t pData);
void SYNOShareSnapEnumFree(PSYNOSHARESNAPENUM pSYNOShareSnapEnum);
SNAP_ENUM_FUNC_RET SYNOShareSnapAttrSelector(const char *szSnapName, PSLIBSZHASH pHash, uintptr_t pData);
SNAP_ENUM_FUNC_RET SYNOShareSnapTimeSelector(const char *szSnapName, PSLIBSZHASH pHash, uintptr_t pData);
SNAP_ENUM_FUNC_RET SYNOShareSnapCommonSelector(const char *szSnapName, PSLIBSZHASH pHash, uintptr_t pData);
/* snapshot_blacklist.c */
int SYNOShareSnapBlackList(const PSYNOSHARE pShare, SNAPSHOT_ACTION *action);
/* snapshot_config.c */
int SYNOShareSnapConfList(const char *szShareName, PSLIBSZHASH *ppHash);
int SYNOShareSnapConfGet(const char *szShareName, const char *szKey, char *szValue, size_t cbValue);
int SYNOShareSnapConfSet(const char *szShareName, const char *szKay, const char *szValue);
int SYNOShareSnapConfUpdate(const char *szOrigShareName, const char *szNewShareName, PSLIBSZHASH pUpdateHash);
int SYNOShareSnapConfEnumSection(PPSLIBSZLIST ppList);
int SYNOShareSnapConfDeleteShare(const char *szShareName);
int SYNOShareSnapHasShareInfoFile(const PSYNOSHARE pShare, const char *szSnap);
int SYNOShareSnapUserQuotaDBPathGet(const PSYNOSHARE pShare, char *szPath, size_t cbPath);
int SYNOShareSnapGetShareNameByTaskId(const char *szTaskId, char *szShareNameBuf, size_t cbShareNameBuf);
/* snapshot_size_calculate.c */
int SYNOShareSnapCalculateTotalSize(const PSLIBSZLIST pListSnapPath, const PSLIBSZLIST pListCloneSources, const char* szParentPath, unsigned long long *totalSize, FILE** ppFile);
/* snapshot_action_plugin.c */
int SYNOShareSnapshotPluginInit(PPSLIBPLUGIN ppPlugin);
int SYNOShareSnapshotPluginAction(const SDK_PLUGIN_ACTION action, PSLIBPLUGIN pPlugin, const PSYNOSHARE pShare, const PSYNOSHARE pNewShare, const PSLIBSZLIST pListSnap, const char *szAction, int iResult);
/* snapshot_utils.c */
int SYNOShareSnapGetOrCreateDir(const PSYNOSHARE pShare, const char *szDir, char *szPath, size_t cbPath, BOOL blCreate);
int SYNOShareSnapGetOrCreateSnapDir(const PSYNOSHARE pShare, char* szSnapDir, size_t cbSnapDir, BOOL blCreate);
int SYNOShareSnapCreateRunLockShareSnapDir();
int SYNOShareSnapCreateTmpShareSnapDir();
int SYNOShareSnapLockMetaFile(const PSYNOSHARE pShare, BOOL blExclusive);
int SYNOShareGetSnapSize(const PSYNOSHARE pShare, const char *szSnapshot, unsigned long long *ullSnapshotSize);
/* snapshot_clone.c */
int SYNOShareSnapClone(const PSYNOSHARE pOrigShare, const PSYNOSHARE pNewShare, const char *szSnapName);
/* snapshot_share_config.c */
int SYNOShareSnapShareInfoSet(const PSYNOSHARE pShare);
int SYNOShareSnapShareInfoGet(const PSYNOSHARE pShare, PShareSnapInfo *ppShareInfo);
int SYNOShareSnapShareInfoGetFromShare(const PSYNOSHARE pShare, PSLIBSZHASH *ppHash, SNAP_SHARE_INFO_FLAG flags);
int SYNOShareSnapShareInfoGetByHash(const PSYNOSHARE pShare, PSLIBSZHASH pHash, PShareSnapInfo *ppShareInfo);
void SYNOShareSnapShareInfoClear(const PSYNOSHARE pShare);
/* snapshot_delete_lock.c */
int SYNOShareSnapSysLockDecrement(const PSYNOSHARE pShare, const char *szSnap, const char *szInitiator);
int SYNOShareSnapSysLockIncrement(const PSYNOSHARE pShare, const char *szSnap, const char *szInitiator);
int SYNOShareSnapSysLockRemove(const PSYNOSHARE pShare, const char *szSnap, const char *szInitiator);
int SYNOShareSnapSysLockGet(const PSYNOSHARE pShare, const char *szSnap, const char *szInitiator, unsigned *lockCount);
int SYNOShareSnapSysLockInitiatorList(const PSYNOSHARE pShare, const char *szSnap, PSLIBSZLIST *ppList);
/* snapshot_meta.c */
int SYNOShareSnapMetaSectionAdd(const PSYNOSHARE pShare, const char *szSnapName, PSLIBSZHASH pshHash);
/* snapshot_snapcount.c */
int SYNOShareSnapGetSnapCount(const PSYNOSHARE pShare, int * snapCount, const BOOL blForceCount);
int SYNOShareSnapUpdateSnapCount(const PSYNOSHARE pShare, const int value);
int SYNOShareSnapSyncSnapCount(const PSYNOSHARE pShare);
int SYNOShareSnapGetGlobalSnapCount(void);
void SYNOShareSnapSyncGlobalSnapCount(void);
