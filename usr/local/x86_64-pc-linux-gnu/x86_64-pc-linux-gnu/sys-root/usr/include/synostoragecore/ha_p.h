/* ha_check_remote_hdd_dl.c */
int SYNOHACheckRemoteHddDL(const PSLIBSZLIST hddListRequire, PPSLIBSZLIST hddListMiss, BOOL blStrict);
/* ha_check_remote_memory_size_dl.c */
int SYNOHACheckRemoteMemorySizeDL(unsigned int remoteMemorySize);
/* ha_check_remote_space_dl.c */
int SYNOHACheckRemoteSpaceDL(const char *szSpacePath, HA_REMOTE_CHECK_TYPE validType);
/* ha_chk_passive_ssd_cache.c */
int SYNOHAChkPassiveSSDCacheDL(PPSLIBSZLIST ppslCacheListMismatch, BOOL blNotify, PSLIBSZLIST pslDisks);
/* ha_data_scrubbing_req_dl.c */
int SYNOHADataScrubbingReqDL(SPACE_REFERENCE_TYPE type, const char *szPath, DATA_SCRUBBING_OPERATION operation);
/* ha_drbd_check_dl.c */
int SYNODrbdNameGetDL(const SPACE_INFO *pSpace, char *szDevName, int cbDevName);
/* ha_drbd_load.c */
int SYNOHADrbdLoadDL(const SPACE_INFO *pSpace, const char *szUnderDevPath, char *szDrbdPath, unsigned int cbPath);
/* ha_drbd_unload.c */
int SYNOHADrbdUnloadDL(const SPACE_INFO *pSpace);
/* ha_drbd_wait_connect.c */
int SYNOHADrbdWaitConnectDL(const SPACE_INFO *pSpace);
/* ha_dump_disk_conf_dl.c */
int SYNOHADumpDiskConfDL(const SPACE_INFO *pSpaceList);
/* ha_dump_disk_conf_ex_dl.c */
int SYNOHADumpDiskConfExDL(const SPACE_INFO *pSpaceList, const PSLIBSZLIST pslAppendDisks);
/* ha_filter_partition.c */
int SYNOHAFilterPartition(PSLIBSZLIST pslParts);
/* ha_flashcache_create_dl.c */
int SYNOHAFlashcacheCreateDL(const SPACE_INFO *pSpace, const FLASHCACHE_CONFIG *pConfig);
/* ha_flashcache_remove_dl.c */
int SYNOHAFlashcacheRemoveDL(const SPACE_INFO *pSpace);
/* ha_flashcache_repair_dl.c */
int SYNOHAFlashcacheRepairDL(const char *szReferencePath);
/* ha_flashcache_sysctl_set_dl.c */
int SYNOHAFlashcacheDoSysctlSetDL(const FLASHCACHE_SYSCTLS_OPERATE fCacheOp, const int value, const char *szCacheDevPath, const char *szUnderDevPath);
/* ha_get_partition_size_dl.c */
unsigned long long SYNOHAGetPartitionSizeDL(const char *devPath, unsigned int partNum);
/* ha_get_remote_ssdcache_part_offset_dl.c */
unsigned long long SYNOHAGetRemoteSSDCachePartOffsetDL(const char *devPath);
/* ha_space_create_dl.c */
int SYNOHASpaceCreateDL(const SPACE_INFO *pSpace, char *szUnderDevPath);
/* ha_space_delete_dl.c */
int SYNOHASpaceDeleteDL(const SPACE_INFO *pSpace);
/* ha_space_expand_adddisk_dl.c */
int SYNOHASpaceExpandAdddiskDL(const SPACE_ADD_DISK_INPUT *pInput);
/* ha_space_expand_resize_dl.c */
int SYNOHASpaceExpandResizeDL(const SPACE_INFO *pSpace, const char *szUnderDevPath);
/* ha_space_expand_resize_post.c */
int SYNOHASpaceExpandResizePost(void);
/* ha_space_expand_resize_pre.c */
int SYNOHASpaceExpandResizePre(const char *szSpacePath);
/* ha_space_expand_unalloc_dl.c */
int SYNOHASpaceExpandUnallocDL(const SPACE_ADD_DISK_INPUT *pInput);
/* ha_space_meta_set_dl.c */
int SYNOHASpaceMetaSetDL(const SPACE_INFO *pSpace);
/* ha_space_repair_dl.c */
int SYNOHASpaceRepairDL(const SPACE_INFO *pSpace, BOOL keepOnline);
/* ha_space_repair_res_dl.c */
int SYNOHASpaceRepairResDL(int result);
/* ha_space_resize_drbd_dl.c */
int SYNOHASpaceResizeDRBDDL(const SPACE_INFO *pSpace);
/* ha_space_unused_undeploy.c */
int SYNOHASpaceUnusedUndeployDL(const SPACE_INFO *pSpace);
