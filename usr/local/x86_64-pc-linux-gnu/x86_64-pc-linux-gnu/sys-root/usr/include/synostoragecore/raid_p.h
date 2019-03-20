/* raid_add.c */
int RAIDAdd(const char *szRAIDPath, const char *szDevPath);
/* raid_add_robust_check.c */
int RAIDAddRobustCheck(const char *szRAIDPath, const char *szDevPath);
/* raid_allow_rmw_check.c */
BOOL RAIDAllowRMWCheck(const char *szRAIDPath);
/* raid_allow_rmw_remove.c */
int RAIDAllowRMWRemove(const char *szRAIDPath);
/* raid_allow_rmw_set.c */
int RAIDAllowRMWSet(const char *szRAIDPath);
/* raid_assemble.c */
int RAIDAssemble(const RAID_ASSEMBLE_PARAMS *p);
/* raid_assemble_by_info.c */
int RAIDAssembleByInfo(const RAID_INFO *pRAID);
/* raid_bad_sector_remap.c */
int RAIDBadSectorRemap(const char *szRAIDPath, BOOL isOpen);
/* raid_check_active.c */
int SLIBRaidCheckActive(const char *szRaidPath);
/* raid_clean_superblock.c */
int RAIDSBCleanByUUID(const RAID_INFO *pRAID, const char *szUUID);
int RAIDSBCleanByUUIDUsingHash(const RAID_INFO *pRAID, const char *szUUID, PSLIBSZHASH pshRaidUUID);
int RAIDSBClean(const char *szPartition);
/* raid_create.c */
int RAIDCreate(const RAID_CREATE_PARAMS *p);
/* raid_dev_count_change.c */
int RAIDDevCountChange(const char *szRAIDPath, const int addDiskCount);
/* raid_disk_count.c */
int RAIDDiskCount(RAID_DEV_LIST *pDiskList, int st);
/* raid_disk_create.c */
int RAIDDiskCreate(char *szPath, RAID_DEV_LIST **ppDisk);
/* raid_disk_initiate.c */
int RAIDDiskInit(const char *szDiskPath, const DEV_LOCATION diskSrc);
/* raid_disk_is_used_by_raid.c */
int RAIDDiskIsUsedByRAID(const char *szDiskPath, int *pMDID);
/* raid_disk_list_alloc.c */
RAID_DEV_LIST *RAIDDiskListAlloc(void);
/* raid_disk_list_free.c */
void RAIDDiskListFree(RAID_DEV_LIST *pDiskList);
/* raid_disk_list_get.c */
int RAIDDiskListGet(const char *szRAIDPath, RAID_DEV_LIST **ppDiskList);
/* raid_disk_list_push.c */
void RAIDDiskListPush(RAID_DEV_LIST **ppDiskList, RAID_DEV_LIST *pDisk);
/* raid_disk_list_search.c */
int RAIDDiskListSearch(RAID_DEV_LIST *pDiskList, const char *szDiskPath, RAID_DEV_LIST **ppDisk);
/* raid_enable_multithread.c */
int RAIDEnableMultithread(const char *szRAIDPath);
/* raid_enable_rmw.c */
int RAIDEnableRMW(const char *szRAIDPath, BOOL enable);
/* raid_enable_rmw_check.c */
BOOL RAIDEnableRMWCheck(const char *szRAIDPath);
/* raid_expand.c */
int RAIDExpand(const char *szRAIDPath, const unsigned long long ullSize);
/* raid_expansible.c */
int RAIDExpansible(const RAID_INFO *pRAID, unsigned long long *pullSize);
/* raid_gen_data_scrubbing_file_path.c */
int RAIDGenDataScrubbingFilePath(const char *szDevPath, char *szFilePath, int iFilePath);
/* raid_global_sync_speed_max_get.c */
int RAIDGlobalSyncSpeedMaxGet(void);
/* raid_global_sync_speed_max_set.c */
int RAIDGlobalSyncSpeedMaxSet(int syncSpeedMaxKb);
/* raid_global_sync_speed_min_get.c */
int RAIDGlobalSyncSpeedMinGet(void);
/* raid_info_alloc.c */
RAID_INFO *RAIDInfoAlloc(void);
/* raid_info_dup.c */
RAID_INFO *RAIDInfoDup(const RAID_INFO *pRAIDIn);
/* raid_info_enum.c */
int RAIDInfoEnum(RAID_INFO_LIST **ppRAIDList);
/* raid_info_free.c */
void RAIDInfoFree(RAID_INFO *pInfo);
/* raid_info_get.c */
int RAIDInfoGet(const char *szRAIDPath, RAID_INFO **ppRaid);
int RAIDSyncStatusGet(int iMdId, RAID_SYNC_STATUS *status);
/* raid_ioctl_info.c */
int RAIDIoctlInfo(const int fd, mdu_array_info_t *pArray);
/* raid_ioctl_size.c */
int RAIDIoctlSize(const int fd, unsigned long long *pTotalSize);
/* raid_ioctl_status.c */
int RAIDIoctlStatus(const int fd, RAID_STATUS *pStatus);
/* raid_is_detected.c */
int RAIDIsDetected(const char *szPath);
/* raid_is_disk_belong_to.c */
BOOL RAIDIsDiskBelongTo(RAID_INFO *pRAID, int partNum, const char *szDiskPath);
/* raid_list_count.c */
int RAIDListCount(const RAID_INFO_LIST *pRAIDList);
/* raid_list_free.c */
void RAIDListFree(RAID_INFO_LIST *pRAIDList);
/* raid_list_push.c */
int RAIDListPush(RAID_INFO_LIST **ppRAIDList, const RAID_INFO *pRAIDInfo);
/* raid_list_search.c */
int RAIDListSearch(RAID_INFO_LIST *pRAIDList, const RAID_SEARCH_FILTER *pFilter, RAID_INFO **ppRAID);
/* raid_md_stripe_cache_memory_usage_get.c */
int SYNORAIDMdStripeCacheMemoryUsageGet(const char *szDevPath);
/* raid_md_stripe_cache_size_get.c */
int SYNORAIDMdStripeCacheSizeGet(const char *szDevPath);
/* raid_md_stripe_cache_size_set.c */
int SYNORAIDMdStripeCacheSizeSet(const char *szDevPath, int size);
/* raid_md_stripe_cache_size_tune.c */
int SYNORAIDStripeCacheTune(void);
/* raid_md_stripe_size_get.c */
int RAIDMdStripeSizeGet(const char *szRAIDPath);
/* raid_mdadm_lib.c */
unsigned long long get_component_size(int fd);
/* raid_migrate_2_raid6.c */
int RAIDMigrate2RAID6(const RAID_INFO *pRAID, const PSLIBSZLIST pPartPaths);
/* raid_parity_disk_count.c */
int RAIDParityDiskCount(RAID_LEVEL raidLevel, int designedDiskCount);
/* raid_path_enum.c */
int RAIDPathEnum(PSLIBSZLIST *ppList);
/* raid_rebuild_progress_caculate.c */
int RAIDRebuildProgressCalculate(const PSLIBSZLIST pDevList, unsigned long long *pullDone, unsigned long long *pullTotal);
/* raid_rebuild_status_get.c */
int RAIDRebuildStatusGet(const int fd, RAID_REBUILD_STATUS *pSt);
/* raid_rebuild_wait.c */
int RAIDRebuildingWait(const char *szRAIDPath, unsigned int expectStatus);
/* raid_rebuild_wait_multiple.c */
int RAIDRebuildingMultiWait(const PSLIBSZLIST pRAIDPathList);
/* raid_remove.c */
int RAIDRemove(const RAID_INFO *pRAID);
/* raid_remove_data_scrubbing.c */
int RAIDRemoveDataScrubbing(const char *szDevPath);
/* raid_remove_disk.c */
int RAIDRemoveDisk(const char *szRAIDPath, const char *szDevPath, int forceRemoveFlag);
/* raid_remove_disk_from_system.c */
int SYNOStgRaidRemoveDiskFromSystem(char *szDevPath);
/* raid_remove_multiple.c */
int RAIDRemoveMultiple(const PSLIBSZLIST pRAIDPathList);
/* raid_reserved_size_get.c */
unsigned long long RAIDReservedSizeGet(const RAID_INFO *pRAID);
/* raid_scan_free.c */
void RAIDScanFree(RAID_SB_LIST *pList);
/* raid_set_data_scrubbing.c */
int RAIDSetDataScrubbing(const char *szDevPath);
/* raid_set_partition_fail.c */
int SYNOStgCoreRAIDSetPartFail(char *szRAIDPath, char *szPartPath);
/* raid_size_limit_get.c */
int RAIDSizeLimitGet(unsigned long long *pullRestrictSizeInKB);
/* raid_size_unalloc_get.c */
int RAIDSizeUnallocGet(const RAID_INFO *pRAID, unsigned long long *pUllSize);
/* raid_stop.c */
int RAIDStop(const char *szRAIDPath);
/* raid_superblock_enum.c */
int RAIDSBEnum(const PSLIBSZLIST pDiskList, RAID_SB_LIST **ppMDSBList);
/* raid_superblock_enum_free.c */
void RAIDSBEnumFree(RAID_SB_LIST *pList);
/* raid_superblock_get.c */
int RAIDSBGet(const char *szDevPath, RAID_SB_INFO *pSB);
/* raid_superblock_push.c */
int RAIDSBPush(RAID_SB_LIST **ppList, RAID_SB_INFO *pSB);
/* raid_swap_disk_set.c */
int SLIBRaidSwapDiskSet(const PSLIBSZLIST pslAddDiskList, const PSLIBSZLIST pslRemoveDiskList);
/* raid_system_add.c */
int RAIDSystemAdd(const char *szDevPath);
/* raid_system_disk_status_detail_get.c */
int RAIDSystemDiskStatusDetailGet(const RAID_FOR_SYSTEM *pSys, const char *szDiskPath, RAID_DEV_STAT *statusInRoot, RAID_DEV_STAT *statusInSwap);
/* raid_system_disk_status_get.c */
int RAIDSystemDiskStatusGet(const RAID_FOR_SYSTEM *pSys, const char *szDiskPath, RAID_DEV_STAT *st);
/* raid_system_free.c */
void RAIDSystemFree(RAID_FOR_SYSTEM *pSys);
/* raid_system_get.c */
int RAIDSystemGet(RAID_FOR_SYSTEM *pSys);
/* raid_system_raid_conf_get.c */
int SYNOStgCoreRAIDSysRaidConfGet(const DISK_ID *diskId, BOOL *pblJoin);
/* raid_system_raid_conf_set.c */
int SYNOStgCoreRAIDSysRaidConfSet(int num, int cnrIdx, BOOL blJoin);
/* raid_system_repair.c */
int RAIDSystemRepair(const RAID_FOR_SYSTEM *pSys, const char *szDiskPath);
/* raid_uuid_get.c */
int RAIDUUIDGet(const char *szRAIDPath, char *szUUID, int cbUUID);
/* raid_uuid_hash_for_remove_get.c */
int RAIDUUIDHashForRemoveGet(PSLIBSZHASH *ppshRaidUUID);
/* raid_schedule_data_scrubbing_init.c */
int RAIDScheduleDataScrubbingInit(RAID_INFO_LIST **ppRaidList);
/* raid_schedule_data_scrubbing_get.c */
int RAIDScheduleDataScrubbingGet(RAID_INFO_LIST **ppScrubbingRaidList, const int iMaxScheRaid);
/* raid_schedule_data_scrubbing_run.c */
int RAIDScheduleDataScrubbingRun(const int iMaxScheRaid);
/* raid_schedule_data_scrubbing_update.c */
int RAIDScheduleDataScrubbingUpdate(const int md_minor, const int blFinishSync, const int blTriggerNext);
/* raid_schedule_data_scrubbing_set_md_section.c */
int RAIDScheduleDataScrubbingSetMdSection(const char *szMdName, const char *szMdUUID, const char *szTimestamp);
/* raid_schedule_data_scrubbing_add_schedule.c */
int RAIDScheduleDataScrubbingAddSchedule(const char *szMdName, const BOOL blAlreadyLocked);
