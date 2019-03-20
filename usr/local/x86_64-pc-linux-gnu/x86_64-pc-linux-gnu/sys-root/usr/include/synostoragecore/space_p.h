/* space_1bay_vol_alloc.c */
SPACE_INFO *SYNOSpace1bayVolAlloc(void);
/* space_block_alloc.c */
SYNO_BLOCK *SYNOSpaceBlockAlloc(void);
/* space_block_clean.c */
void SYNOSpaceBlockClean(SYNO_BLOCK *pBlk);
/* space_block_free.c */
void SYNOSpaceBlockFree(SYNO_BLOCK *pBlk);
/* space_block_get.c */
int SYNOSpaceBlockGet(const SPACE_INFO *pSpace, SYNO_BLOCK *pBlk);
/* space_block_init.c */
char *SYNOSpaceRaidGroupLimitMagicGet(int raidGroupLimitNum);
int SYNOSpaceBlockInit(const SYNO_BLOCK_INIT_PARAMS *pParams, SYNO_BLOCK *pBlk);
/* space_block_is_valid.c */
BOOL SYNOSpaceBlockIsValid(SYNO_BLOCK *pBlk, PSLIBSZLIST pslRAIDUUID);
/* space_block_remove.c */
int SYNOSpaceBlockRemove(const SPACE_INFO *pSpace);
/* space_block_set.c */
int SYNOSpaceBlockSet(const SPACE_INFO *pSpace, const SYNO_BLOCK *pBlk);
/* space_block_update.c */
int SYNOSpaceBlockUpdate(const SPACE_BLOCK_UPDATE_INPUT *pInput);
/* space_build_file_get.c */
int SYNOSpaceBuildFileGet(SPACE_BUILD_OBJ **ppSpaceBuild);
/* space_build_file_object_alloc.c */
SPACE_BUILD_OBJ *SYNOSpaceBuildFileObjAlloc(void);
/* space_build_file_object_free.c */
void SYNOSpaceBuildFileObjFree(SPACE_BUILD_OBJ *pObj);
/* space_build_file_object_init.c */
int SYNOSpaceBuildFileObjInit(int order, SPACE_BUILDING_TASK task, SPACE_BUILDING_STEP firstStep, const char *szSpacePath, SPACE_REFERENCE_TYPE spaceType, SPACE_DEV_TYPE devType, SPACE_BUILD_OBJ *pBuildProgress);
/* space_build_file_object_push.c */
void SYNOSpaceBuildFileObjPush(SPACE_BUILD_OBJ **ppList, SPACE_BUILD_OBJ *pObj);
/* space_build_file_remove.c */
void SYNOSpaceBuildFileRemove(const SPACE_BUILD_OBJ *pSpaceBuild);
/* space_build_file_search.c */
SPACE_BUILD_OBJ *SYNOSpaceBuildFileSearch(SPACE_BUILD_OBJ *pBuildList, SPACE_BUILD_FILTER *pFilter);
/* space_build_file_set.c */
int SYNOSpaceBuildFileSet(const SPACE_BUILD_OBJ *pSpaceBuild);
/* space_build_file_update.c */
void SYNOSpaceBuildFileUpdate(SPACE_BUILDING_STEP step, const char *szBuildDevPath, SPACE_BUILD_OBJ *pBuildProgress);
/* space_build_status_all_normal.c */
int RAIDBuildStatusAllNormal(void);
/* space_cache_info_delete.c */
int SLIBSpaceCacheInfoDelete(const SPACE_INFO *pSpace);
/* space_cache_info_set.c */
int SLIBSpaceCacheInfoSet(const SPACE_INFO *pSpace, const FLASHCACHE_CONFIG *pConfig);
/* space_can_do.c */
int SYNOSpaceCanDo(SPACE_BUILDING_TASK task, const SPACE_INFO *pSpace, SPACE_DISK_LIMIT *pDiskLimit);
/* space_can_enable.c */
int SYNOSpaceCanEnable(const char *szReferencePath);
/* space_cancel_data_scrubbing.c */
BOOL SYNOCancelDataScrubbing(const RAID_INFO_LIST *pRaidList);
/* space_check_sys_status.c */
int SYNOSpaceCheckSystemStatus(const SPACE_INFO *pSpace);
/* space_convert_shr_volume_to_pool.c */
int SYNOStgCoreSpaceConvertSHRVolumeToPool(const SPACE_CONVERT_SHR_TO_POOL_INPUT *pInput);
/* space_create.c */
int SYNOSpaceCreate(const SPACE_CREATE_INPUT *pInput, char *szOutDevPath, int sizeOutDevPath);
int SYNOSpaceDD(const char *szDevPath, BOOL blRead);
/* space_create_for_vdsm.c */
int SYNOSpaceCreateForVDSM(const SPACE_CREATE_INPUT *pInput);
/* space_delete.c */
int SYNOSpaceDelete(const char *szSpacePath);
int SYNOSpaceDeleteByInfo(SPACE_INFO *pSpace);
/* space_device_size_get.c */
int SYNOSpaceDevSizeGet(const char *szDevPath, unsigned long long *pUllSize);
/* space_disk_block_get.c */
int SYNOSpaceDiskBlockGet(const char *szDevPath, SYNO_BLOCK *pBlk);
int SLIBSpaceDiskBlockGetByOffset(const char *szDevPath, off_t offset, SYNO_BLOCK *pBlk);
/* space_disk_block_remove.c */
int SYNOSpaceDiskBlockRemove(const PSLIBSZLIST pslDisks);
/* space_disk_block_set.c */
int SYNOSpaceDiskBlockSet(const PSLIBSZLIST pslDisks, const SYNO_BLOCK *pBlk);
/* space_disk_check_limit.c */
int SYNOSpaceDiskLimitCheck(const PSLIBSZLIST pslDisks, const SPACE_DISK_LIMIT *pDiskLimit);
/* space_disk_check_sys_status.c */
int SYNOSpaceDiskCheckSystemStatus(const char *szDiskPath, const RAID_FOR_SYSTEM *pSysRAID, RAID_DEV_STAT *pSt);
/* space_disk_data_partition_clean.c */
int SYNOSpaceDiskDataPartitionClean(const SPACE_PARTITION_LIST *pPartList);
/* space_disk_data_partition_create.c */
int SYNOSpaceDiskDataPartitionCreate(const SPACE_PARTITION_TYPE partType, const SPACE_PARTITION_LIST *pPartList);
/* space_disk_data_partition_layout_get.c */
int SYNOSpaceDiskDataPartitionLayoutGet(const SPACE_INFO *pSpace, SPACE_DISK_PARTITION_LAYOUT **ppDiskPartLayout);
/* space_disk_data_partition_plan.c */
int SYNOSpaceDiskDataPartitionPlan(const SPACE_DISK_LAYOUT_PLAN_PARAMS *p, SPACE_PARTITION_LIST **ppPartList, SPACE_PARTITION_TYPE *pPartType);
/* space_disk_data_partition_type_get.c */
int SYNOSpaceDiskDataPartitionTypeGet(SPACE_DEV_TYPE devType, const RAID_INFO *pRAID, SPACE_PARTITION_TYPE *pType);
/* space_disk_enum.c */
int SYNOSpaceDiskEnum(const SPACE_INFO *pSpace, PSLIBSZLIST *ppSpaceDisks);
/* space_disk_failure_number_get.c */
int GetSpaceDiskFailureCount(const SPACE_INFO *pSpace);
/* space_disk_init.c */
int SYNOSpaceDiskInit(const SPACE_DISK_LAYOUT_PLAN_PARAMS *pInput, PSLIBSZLIST *ppslPartPaths, SPACE_PARTITION_LIST **ppPartList);
/* space_disk_is_in_use.c */
int SYNOSpaceDiskIsInUse(const PSLIBSZLIST pslDisks);
/* space_disk_is_size_enough.c */
int SYNOSpaceDiskIsSizeEnough(const SPACE_INFO *pSpace, const PSLIBSZLIST pslDisks);
/* space_disk_is_size_enough_for_action.c */
int SYNOSpaceDiskIsSizeEnoughForAction(SPACE_BUILDING_TASK task, const SPACE_INFO *pSpace, const PSLIBSZLIST pslDisks);
/* space_disk_list_container_type.c */
int SYNOSpaceDiskListContainerType(const PSLIBSZLIST pslDisk, SPACE_CONTAINER_REPORT *pRep);
/* space_disk_list_split_by_loc.c */
int SYNOSpaceDiskListSplitByLoc(const PSLIBSZLIST pslDisks, PSLIBSZLIST *ppslInternalDisks, PSLIBSZLIST *ppslEBoxDisks);
/* space_disk_partition_get.c */
int SLIBSpaceDiskPartitionGet(const SPACE_INFO *pSpaceInfo, PARTITITON_LAYOUT_VERSION *pPartLayoutVer);
/* space_disk_reserved_size_get.c */
unsigned long long SYNOSpaceDiskReservedSizeGet(SPACE_RESERVED_SIZE_PARAMS *pParams);
/* space_disk_size_enum.c */
int SYNOSpaceDiskSizeEnum(const PSLIBSZLIST pslDisks, PARTITITON_LAYOUT_VERSION layout, SPACE_DISK_SIZE **ppNewDiskSize);
/* space_disk_status_get.c */
int SYNOSpaceDiskStatusGet(const SPACE_PARAMS_DISK_STATUS *p, SPACE_DISK_STATUS *pSt);
/* space_disk_sys_partition_create_join.c */
int SYNOSysRaidAdjust(void);
int SYNOSpaceDiskSysPartitionSelectAndCreate(void);
int SYNOSpaceDiskSysPartitionCreateAndJoin(const PSLIBSZLIST pslDisks, PARTITITON_LAYOUT_VERSION partLayoutVer);
/* space_do_data_scrubbing.c */
BOOL SYNODoDataScrubbing(const RAID_INFO_LIST *pRaidList);
/* space_error_log.c */
int SYNOStgCoreSpaceErrorLog(FILE *fp, char *cmd);
/* space_execl.c */
int SYNOStgCoreSpaceExecl(const char *szPath, ...);
/* space_expand.c */
int SYNOSpaceExpand(const SPACE_ADD_DISK_INPUT *pInput);
/* space_expand_by_create_raid.c */
int SYNOSpaceExpandByCreateRAID(const SPACE_INFO *pSpace, const char *szRAIDPath, RAID_LEVEL raidLevel, const PSLIBSZLIST pPartPaths);
/* space_expand_unallocated.c */
int SYNOSpaceExpandUnalloc(const SPACE_ADD_DISK_INPUT *pInput);
/* space_expand_unfinished_shr.c */
int SYNOSpaceExpandUnfinishedSHR(const SPACE_ADD_DISK_INPUT *pInput, const SPACE_SHR_ACTION action);
/* space_failed_disk_info_free.c */
void SpacePartInfoFree(SPACE_PART_INFO *pInfoList);
void SYNOStgCoreSpaceFailedDiskInfoFree(SPACE_FAILED_DISK_INFO *pInfoList);
/* space_failed_disk_info_get.c */
int SYNOStgCoreSpaceFailedDiskInfoGet(const SPACE_INFO *pSpaceInfo, SPACE_FAILED_DISK_INFO **ppInfoList);
/* space_failed_disk_info_push.c */
int SYNOStgCoreSpaceFailedDiskInfoPush(SPACE_FAILED_DISK_INFO **ppInfoList, SPACE_FAILED_DISK_INFO *pInfo);
/* space_file_path_gen.c */
int SYNOSpaceFilePathGen(const char *szPrefixPath, const char *szDevPath, char *szFilePath, int iFilePath);
/* space_filter_match.c */
BOOL SYNOSpaceFilterMatch(const SPACE_FILTER *pFilter, SPACE_INFO *pSpace);
/* space_info_alloc.c */
SPACE_INFO *SYNOSpaceInfoAlloc(void);
/* space_info_enum.c */
int SYNOSpaceInfoFilter(SPACE_FILTER *pFilter, SPACE_INFO **ppSpaceOut);
int SYNOSpaceInfoEnum(unsigned int spaceType, SPACE_INFO **ppSpaceOut);
/* space_info_free.c */
void SYNOSpaceInfoFree(SPACE_INFO *p);
/* space_info_get.c */
int SYNOSpaceInfoGet(const char *szSpacePath, SPACE_INFO **ppSpace);
/* space_info_push.c */
int SYNOSpaceInfoPush(SPACE_INFO **ppSpaceList, SPACE_INFO *pSpaceInfo);
/* space_info_search.c */
int SYNOSpaceInfoSearch(const SPACE_INFO *pSpaceList, const SPACE_FILTER *pFilter, SPACE_INFO **ppSpace);
/* space_internal_lib.c */
/* space_is_acting.c */
BOOL SYNOSpaceIsActing(const SPACE_INFO *pSpace, SPACE_BUILDING_TASK *pTask);
/* space_is_crashed.c */
BOOL SYNOSpaceIsCrashed(const SPACE_INFO *pSpace);
/* space_is_cross_ebox.c */
BOOL SYNOSpaceIsCrossEBox(const PSLIBSZLIST pslDiskPath);
/* space_is_degrade.c */
BOOL SYNOSpaceIsDegrade(const SPACE_INFO *pSpace);
/* space_is_need_data_scrubbing.c */
BOOL SYNOSpaceIsNeedDataScrubbing(const SPACE_INFO *pSpaceInfo);
/* space_is_normal.c */
BOOL SYNOSpaceIsNormal(const SPACE_INFO *pSpace);
/* space_is_raid_can_do.c */
BOOL SYNOSpaceIsRAIDCanDo(SPACE_BUILDING_TASK task, const RAID_INFO *pRAID, SPACE_DISK_LIMIT *pLimit);
/* space_lock.c */
int SYNOSpaceLock(SPACE_LOCK_TYPE lockType, int timeOut);
/* space_lock_del.c */
int SYNOSpaceLockDel(const char *szFilePath);
/* space_lock_file_get.c */
const char *SYNOLockFileGet(SPACE_LOCK_TYPE lockType);
/* space_lock_get.c */
int SYNOSpaceLockGet(const char *szFilePath, SPACE_LOCK_INFO *pLock);
/* space_lock_multi.c */
int SYNOSpaceLockMulti(int lockType, int timeOut, int *pSemid, unsigned int cntSemid);
/* space_map_file_dump.c */
int SYNOSpaceMapFileDump(void);
/* space_map_file_parse.c */
int SYNOSpaceMapFileParse(const char *szFilePath, SPACE_INFO **ppSpaces);
/* space_maximal_disk_size_get.c */
int SYNOSpaceMaxDiskSizeGet(const SPACE_INFO *pSpace, unsigned long long *pUllSize);
/* space_meta_alloc.c */
SPACE_META *SYNOSpaceMetaAlloc(void);
/* space_meta_can_have_reuse_id.c */
BOOL SYNOSpaceMetaCanHaveReuseID(SPACE_REFERENCE_TYPE referenceType, BOOL IsPoolChild);
/* space_meta_dump2file.c */
int SYNOSpaceMetaDump2File(const SPACE_META *pMeta);
/* space_meta_enum.c */
int SYNOSpaceMetaEnum(SPACE_META_FILTER *pF, SPACE_META **ppMeta);
/* space_meta_free.c */
void SYNOSpaceMetaFree(SPACE_META *pMeta);
/* space_meta_get.c */
int SYNOSpaceMetaGet(const SPACE_INFO *pSpace, SPACE_META **ppMeta);
/* space_meta_push.c */
int SYNOSpaceMetaPush(SPACE_META **pSpaceMetaList, SPACE_META *pSpaceMeta);
/* space_meta_register.c */
int SYNOSpaceMetaRegister(const char *szSpacePath, const SPACE_META *pMeta);
/* space_meta_remove.c */
int SYNOSpaceMetaRemove(const SPACE_INFO *pSpace);
/* space_meta_search.c */
BOOL SYNOSpaceMetaSearch(SPACE_META_FILTER *pF, SPACE_META *pMeta, SPACE_META **ppMeta);
/* space_meta_set.c */
int SYNOSpaceMetaSet(const SPACE_INFO *pSpace, const SPACE_META *pMeta);
/* space_meta_unregister.c */
int SYNOSpaceMetaUnregister(const char *szSpacePath);
/* space_meta_update.c */
int SYNOSpaceMetaUpdate(const SPACE_INFO *pSpace, SPACE_META *pMeta);
/* space_migrate.c */
int SYNOSpaceMigrate(const SPACE_ADD_DISK_INPUT *pInput, SPACE_BUILDING_TASK migrateType);
/* space_migrate_raid1_to_5.c */
int SYNOSpaceMigrateRAID1To5(const SPACE_MIGRATE_1TO5_INPUT *pInput);
/* space_minimal_disk_size_get.c */
int SYNOSpaceMinDiskSizeGet(const SPACE_MINDISK_SIZE_INPUT *pIn, unsigned long long *pUllSize);
/* space_multi_diskgroup_adddisk_input.c */
SPACE_ADD_DISK_PARAMS *SYNOSpaceMultiRAIDAddDiskInAlloc(const char *szRAIDPath, BOOL blCreateNewRAID);
void SYNOSpaceMultiRAIDAddDiskInFree(void *pIn);
/* space_multi_diskgroup_input.c */
SPACE_MULTI_DISKGROUP_INPUT *SYNOSpaceMultiDiskGroupInAlloc(void);
SPACE_MULTI_DISKGROUP_INPUT *SYNOSpaceMultiDiskGroupInPush(SPACE_MULTI_DISKGROUP_INPUT *pEl, SPACE_MULTI_DISKGROUP_INPUT *pList);
void SYNOSpaceMultiDiskGroupInFree(SPACE_MULTI_DISKGROUP_INPUT *pList, PFuncFreeParams pFuncFree);
/* space_partition_dump_2_list.c */
int SYNOSpacePartitionDump2List(const SPACE_PARTITION_LIST *pPart, PSLIBSZLIST *ppOutList);
/* space_partition_layout_count.c */
int SYNOSpacePartitionLayoutCount(const SPACE_PARTITION_LIST *pPart);
/* space_partition_list_alloc.c */
SPACE_PARTITION_LIST *SYNOSpacePartitionListAlloc(void);
/* space_partition_list_free.c */
void SYNOSpacePartitionListFree(SPACE_PARTITION_LIST *pList);
/* space_partition_list_push.c */
void SYNOSpacePartitionListPush(SPACE_PARTITION_LIST **ppList, SPACE_PARTITION_LIST *pInsert);
/* space_path_unused_get.c */
int SYNOSpacePathUnusedGet(SPACE_UNUSED_PATH_FLAG type, int pathCount, PSLIBSZLIST *ppOutList);
/* space_pool_lv_add.c */
int SYNOSpacePoolLvAdd(const SPACE_POOL_ADD_LV_INPUT *p, char *szOutDevPath, int cbDevPath);
/* space_pool_lv_delete.c */
int SYNOSpacePoolLvDelete(const char *szVgPath, const char *szLvNameOrPath);
/* space_pool_lv_expand.c */
int SYNOSpacePoolLvExpand(const char *szVgPath, const char *szLvNameOrPath, unsigned long long ullSize);
/* space_pool_lv_name_parse.c */
int SYNOSpacePoolLvNameParse(const SPACE_LVNAME_PARSE_INPUT *p, char *szReferencePath, int cbPath, LVM_LV_REFERENCE_TYPE *pReferenceType);
int SYNOSpacePoolLvNameGet(const SPACE_LVNAME_GET_INPUT *p, char *szLvName, int cbLvName);
/* space_pool_meta_add.c */
int SYNOSpacePoolMetaAdd(const char *szVgPath, const char *szKey, const char *szVal);
/* space_pool_meta_close.c */
void SYNOSpacePoolMetaClose(SPACE_POOL_META_INFO *pMeta);
/* space_pool_meta_create.c */
int SYNOSpacePoolMetaCreate(const char *szVgPath);
/* space_pool_meta_delete.c */
int SYNOSpacePoolMetaDelete(const char *szVgPath, const char *szKey);
/* space_pool_meta_enum.c */
int SYNOSpacePoolMetaEnum(const char *szVgPath, PSLIBSZHASH *ppshMeta);
/* space_pool_meta_get.c */
int SYNOSpacePoolMetaGet(const char *szVgPath, SPACE_POOL_META_GET_INPUT *p, char *szOut, int cbOut);
/* space_pool_meta_header_read.c */
int SYNOSpacePoolMetaHeaderRead(int fd, SPACE_POOL_META_HEADER *pHdr);
/* space_pool_meta_header_set.c */
int SYNOSpacePoolMetaHeaderSet(SPACE_POOL_META_INFO *pMeta);
/* space_pool_meta_init.c */
int SYNOSpacePoolMetaInit(const char *szVgPath, int openFlags, SPACE_POOL_META_INFO *pMeta);
/* space_pool_meta_open.c */
int SYNOSpacePoolMetaOpen(const char *szVgPath, int openFlags, SPACE_POOL_META_INFO *pMeta, SPACE_POOL_META_OPERATOR *pOp);
/* space_pool_meta_set.c */
int SYNOSpacePoolMetaSet(const char *szVgPath, const char *szKey, const char *szVal);
/* space_raid_action_alloc.c */
SPACE_RAID_ACTION *SYNOSpaceRAIDActionAlloc(void);
/* space_raid_action_decide.c */
int SYNOSpaceRAIDActionDecide(SPACE_BUILDING_TASK task, const SPACE_INFO *pSpace, const SPACE_PARTITION_LIST *pPartList, SPACE_RAID_ACTION **ppRAIDAction, BOOL blKeepOnline);
/* space_raid_action_free.c */
void SYNOSpaceRAIDActionFree(SPACE_RAID_ACTION *pAction);
/* space_raid_action_push.c */
void SYNOSpaceRAIDActionPush(SPACE_RAID_ACTION **ppList, SPACE_RAID_ACTION *pObj);
/* space_raid_add_disk.c */
int SYNOSpaceRAIDAddDisk(const SPACE_ADD_DISK_INPUT *pInput, const char *szRAIDPath, const PSLIBSZLIST pslPartitions);
/* space_raid_block_get.c */
int SYNOSpaceRAIDBlockGet(const RAID_INFO *pRAID, SYNO_BLOCK *pBlk);
/* space_raid_enum.c */
int SYNOSpaceRAIDPathEnum(const SPACE_INFO *pSpace, PSLIBSZLIST *ppslRAIDPath);
/* space_raid_limit_count.c */
void SYNOSpaceRAIDLimitCount(RAID_LEVEL raidLevel, SPACE_DISK_LIMIT *pLimit);
/* space_raidgroup_split_unit.c */
int SYNOSpaceRAIDGroupSplitUnit(void);
/* space_rebuild_trigger.c */
int SYNOSpaceRebuildTrigger(const SPACE_INFO *pSpace);
/* space_reference_path_change.c */
int SYNOSpaceReferencePathChg(const SPACE_INFO *pSpace, const char *szNewReferencePath, BOOL blDumpMapFile);
/* space_reference_path_update.c */
int SYNOSpaceReferencePathUpdate(SPACE_INFO *pSpace, SPACE_REFERENCE_TYPE spaceType, const char *szReferencePath);
/* space_repair.c */
int SYNOSpaceRepair(const SPACE_ADD_DISK_INPUT *pInput);
/* space_reuse_id_parse.c */
int SYNOSpaceReuseIDParse(const char *szReuseID, int *pRid);
/* space_service_lock.c */
int SYNOSpaceLockService(SPACE_SERVICE_ACTION action, unsigned int *pServAction);
void SYNOSpaceServiceUnLock(int semid, SPACE_SERVICE_ACTION action);
/* space_shr_add_disk.c */
int SYNOSpaceSHRAddDisk(const SPACE_ADD_DISK_INPUT *pInput, const SPACE_SHR_ACTION action);
/* space_shr_disk_protected_get.c */
int SYNOSpaceSHRDiskProtectGet(const SPACE_INFO *pSpace);
/* space_shr_is_fake_normal.c */
BOOL SYNOStgCoreSpaceIsSHRFakeNoraml(const SPACE_INFO *pSpaceInfo, int *failedCount);
/* space_shr_unused_partition_get.c */
int SYNOSpaceSHRUnusedPartitionGet(const SPACE_INFO *pSpace, const PSLIBSZLIST pslDisks,
		const PSLIBSZLIST pslPartitionList, SPACE_PARTITION_LIST **ppUnusedPartitionList);
/* space_size_estimate.c */
int SYNOSpaceSizeEstimate(const SPACE_PARAMS_SIZE_ESTIMATE *p, unsigned long long *pUllSize, int *pActionType);
/* space_snapshot_origin.c */
char *SYNOSnapOriginMapDevPathGet(const char *szVolPath);
void SYNOSnapOriginMapDevPathPut(char *szDevMapperPath);
int SYNOSnapOriginInit(void);
int SYNOSnapOriginCreateInternal(const char *szDevPath, const char *szVolPath, char *szNewDevPath, int size);
int SYNOSnapOriginCreateForVSpace(SPACE_INFO *pSpace, const char *szUnderDevPath);
int SYNOSnapOriginCreate(SPACE_INFO *pSpace);
int SYNOSnapOriginRemoveInternal(const char *szVolPath, char *szSnapshotDevPath);
int SYNOSnapOriginRemove(SPACE_INFO *pSpace);
int SYNOSnapOriginRemoveForVSpace(SPACE_INFO *pSpace);
int SYNOSnapOriginUpdateSize(SPACE_INFO *pSpace);
int SYNOSnapOriginUpdateSizeForVSpace(SPACE_INFO *pSpace, const char *szUnderDevPath);
int SYNOSnapOriginCheck(SPACE_INFO *pSpaceList);
int SYNOSnapOriginCreateAll(void);
int SYNOSnapOriginRemoveAll(void);
/* space_split_from_list.c */
SPACE_INFO *SYNOSpaceSplitFromList(SPACE_INFO **ppSpaceList, SPACE_INFO *pSpaceSplited);
/* space_ssd_cache_conf_check.c */
int SLIBSpaceSsdCacheConfCheck(BOOL sendNotification);
/* space_ssd_cache_create.c */
int SYNOSpaceSSDCacheCreate(const SPACE_SSDCACHE_CREATE_INPUT *pIn, char *szOutDevPath, int cbPath);
/* space_ssd_cache_delete.c */
int SYNOSpaceSSDCacheDelete(const char *szSpacePath);
/* space_ssd_cache_disk_init.c */
int SYNOSpaceSSDCacheDiskInit(const PSLIBSZLIST pslDisks, PSLIBSZLIST *ppslPartitions);
/* space_ssd_cache_info_get.c */
int SYNOSpaceSSDCacheInfoGet(const SPACE_SSDCACHE_FILTER *pF, SPACE_INFO **ppSpace);
/* space_ssd_cache_max_size_get.c */
int SLIBSpaceSsdCacheMaxSizeGet(unsigned long long *pUllAllowableCacheByte, BOOL *pCanCreate);
/* space_ssd_cache_size_evaluate.c */
int SLIBSpaceSsdCacheSizeEvaluateCommon(unsigned long long *pUllAllowableCacheByte, BOOL *pCanCreate, BOOL bBaseOnMaxMem);
int SLIBSpaceSsdCacheSizeEvaluate(unsigned long long *pUllAllowableCacheByte, BOOL *pCanCreate);
/* space_system_raid_repair.c */
int SYNOStgCoreSpaceSystemRaidRepair(void);
/* space_tmp_folder_create.c */
int SYNOSpaceTmpFolderCreate(void);
/* space_trim_enable_get.c */
int SYNOSpaceTrimEnableGet(const char *szPath, BOOL *pblEnable, long *pId);
/* space_trim_enable_set.c */
int SYNOSpaceTrimEnableSet(const char *szPath, const BOOL blEnable, const long id);
/* space_trim_support.c */
int SYNOSpaceTrimSupport(const SPACE_INFO *pSpace, SPACE_TRIM_SUPPORT_TYPE *pType);
/* space_ui_str_identity_get.c */
int SYNOSpaceUIStrIdentityGet(const SPACE_INFO *pSpace, char *szUIStr, unsigned int cbUIStr);
int SYNOSpaceUIIDGet(const SPACE_INFO *pSpace, BOOL blGetVolume, char *szUIStr, unsigned int cbUIStr);
int SYNOSpacePoolPathParse(const char *szSpacePath, LVM_PATH_INFO *pPathInfo);
/* space_unlock.c */
void SYNOSpaceUnLock(int semid);
/* space_unlock_multi.c */
void SYNOSpaceUnLockMulti(int *pSemid, unsigned int cntSemid);
/* space_unused_block_device_clean.c */
void SYNOSpaceUnusedBlockDeviceClean(void);
/* space_unused_raid_deploy.c */
int SYNOSpaceUnusedRAIDDeploy(SPACE_UNUSE_DEPLOY_INPUT *pIn, char *szOutTopPath, int cbPath);
/* space_unused_raid_undeploy.c */
int SYNOSpaceUnusedRAIDUnDeploy(SPACE_UNUSE_DEPLOY_INPUT *pIn, char *szOutTopPath, int cbPath);
/* space_uuid_get.c */
char *SYNOSpaceUUIDGet(const SPACE_INFO *pSpace);
/* space_vdsm_vol_alloc.c */
SPACE_INFO *SYNOSpaceVDSMVolAlloc(const char *szSpacePath, const char *szVolPath);
/* space_volume_table_update.c */
int SYNOSpaceVolumeTableUpdate(void);
/* space_shr_migrate_min_disk_count_get.c */
int SYNOStgCoreSpaceSHRMigrateMinDiskCountGet(const SPACE_INFO *pSpace);
