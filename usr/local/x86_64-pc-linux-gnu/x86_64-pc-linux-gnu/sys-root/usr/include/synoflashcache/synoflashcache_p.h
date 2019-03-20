/* flashcache_cache_size_get.c */
int SYNOFlashCacheCacheSizeGet(const FLASHCACHE_STAT_FILTER *pFilter, unsigned long long *pUllSizeByte);
/* flashcache_cache_used_mem_get.c */
int SYNOFlashcacheUsedMemGet(const FLASHCACHE_STAT_FILTER *pFilter, long long *pllMemByte);
/* flashcache_config_delete.c */
int SYNOFlashCacheConfigDelete(const FLASHCACHE_CONF_FILTER *pF);
/* flashcache_config_free.c */
void SYNOFlashCacheConfigFree(FLASHCACHE_CONFIG *pC);
/* flashcache_config_get.c */
int SYNOFlashCacheConfigGet(const FLASHCACHE_CONF_FILTER *pF, FLASHCACHE_CONFIG **ppConfig);
int SYNOFlashCacheConfigTmpGet(const FLASHCACHE_CONF_FILTER *pF, FLASHCACHE_CONFIG **ppConfig);
/* flashcache_config_search.c */
int SYNOFlashCacheConfSearch(FLASHCACHE_CONF_FILTER *pF, FLASHCACHE_CONFIG *pConf, FLASHCACHE_CONFIG **ppConfOut);
/* flashcache_config_set.c */
int SYNOFlashCacheConfigTmpUpdate(void);
int SYNOFlashCacheConfigSet(const FLASHCACHE_CONFIG *pConfig);
/* flashcache_create.c */
int CheckAndInsertSingleModule(char *szModuleName);
int CheckAndInsertKernelModule(void);
char *FlashCacheWriteModeToStr(FLASHCACHE_WRITE_MODE mode);
int SYNOFlashCacheCreate(const FLASHCACHE_CREATE_INPUT *pIn, char *szFlashCachePath, int cbPath);
/* flashcache_delete.c */
int SYNOFlashCacheDelete(const char *szCachePath, const FLASHCACHE_STAT *pStat);
/* flashcache_destroy.c */
int SYNOFlashCacheDestroy(const char *szSSDPath);
int SYNOFlashCacheForceDestroy(const char *szSSDPath);
/* flashcache_execute_command.c */
int ModelSupportPin(void);
int FlashcacheExecuteCommand(const char *szOption, const char *szMountPath);
/* flashcache_expand.c */
int SYNOFlashCacheExpand(const char *szDiskPath);
/* flashcache_file_statistics.c */
int FlashcacheFileStatistics(const char *szVolumeName, const char *szPathToStatistics, const int iStrLen);
int FlashcacheFileStatisticsGetAndParse(FCACHE_FILE_STATISTICS fileStat[], const int iArraySize, char *szName, const int cbName, char *szTime, const int cbTime);
BOOL FlashcacheFileStatisticsIsProcessing(void);
BOOL FlashcacheCheckFileStatisticsProgressFile(char *szVolumeId, int cbVolumeId);
BOOL FlashcacheFileStatisticsDataIsExist(void);
int FlashcacheDoStatistics(const char *szSpaceId, const char *szSpacePath);
/* flashcache_get_cache_memory_comsumption_kb.c */
int SYNOFlashCacheGetCacheMemoryComsuptionKb(const FLASHCACHE_CONF_FILTER *pF);
/* flashcache_get_flush_progress.c */
float SYNOFlashCacheGetFlushProgress(const char *szSSDDev, const char *szSpaceDev);
int SYNOFlashCacheDirtyBlockGet(const char *szSSDDev, const char *szSpaceDev);
/* flashcache_get_total_memory_consumption_byte.c */
int SYNOFlashCacheGetTotalMemoryConsumptionByte(unsigned long long *pMemByte);
/* flashcache_is_kmodule_loaded.c */
BOOL SYNOFlashCacheIsKModuleLoad(char *szModuleName);
/* flashcache_is_ssd_support.c */
BOOL SYNOFlashCacheIsSSDSupport(const char *szSSDModel);
BOOL SYNOFlashCacheCheckSSDSupport(const FCACHE_SUPPORT_SSD_FILTER *filter);
/* flashcache_load.c */
int SYNOFlashCacheLoad(const char *szCacheDevPath, const char *szUnderDevPath, char *szFlashCachePath, int cbFlashCachePath);
/* flashcache_pin_add_files.c */
int FlashCachePinAddOrRemoveFiles(const char *szFiles, const char *szMountPath, int isAdd);
int SYNOFlashCachePinAddFiles(const char *szFiles, const char *szMountPath);
/* flashcache_pin_delete_volume_bitmap.c */
int SYNOFlashCachePinDeleteVolumeBitmap(const char *szMountPath);
/* flashcache_pin_get_bitmap_size_byte.c */
int SYNOFlashCachePinGetBitmapSizeByte(const char *szMountPath, unsigned long long *pBitmapByte);
/* flashcache_pin_handle_volume_mount.c */
int SYNOFlashCachePinHandleVolumeMount(const char *szMountPath);
/* flashcache_pin_handle_volume_umount.c */
int SYNOFlashCachePinHandleVolumeUmount(const char *szMountPath);
/* flashcache_pin_is_file_pin.c */
int SYNOFlashCachePinIsFileAdded(const char *szFilePath, int *pIsAdded);
/* flashcache_pin_is_volume_support.c */
int SYNOFlashCachePinIsVolumeSupport(const char *szMountPath);
/* flashcache_pin_remove_files.c */
int SYNOFlashCachePinRemoveFiles(const char *szFiles, const char *szMountPath);
/* flashcache_pin_send_volume_bitmap.c */
int SYNOFlashCachePinSendVolumeBitmap(const char *szMountPath);
/* flashcache_ssd_path_get.c */
int SYNOFlashCacheSSDPathGet(const char *szCachePath, char *szSSDPath, int cbPath);
/* flashcache_stat_free.c */
void SYNOFlashCacheStatFree(FLASHCACHE_STAT **ppS);
/* flashcache_stat_get.c */
int SYNOFlashcacheGetCachePath(const char *szDevPath, char *szCachePath, int cachePathLen);
int SYNOFlashCacheStatGet(const FLASHCACHE_STAT_FILTER *pF, FLASHCACHE_STAT **ppStat);
/* flashcache_support_ssd_free.c */
void SYNOFlashCacheSupportSSDFree(FCACHE_SUPPORT_SSD_LIST *pSSDList);
/* flashcache_support_ssd_get.c */
int SYNOFlashCacheSupportSSDGet(FCACHE_SUPPORT_SSD_LIST **ppSSDList);
/* flashcache_support_ssd_update.c */
int SYNOFlashCacheSupportSSDUpdate(void);
/* flashcache_sysctl_get.c */
int SYNOFlashCacheSysctlGet(FLASHCACHE_SYSCTLS_OPERATE fCacheOp, const char *szCacheDevPath, const char *szUnderDevPath, int *value);
/* flashcache_sysctl_set.c */
char *SYNOFlashCacheSysctlDevNameGet(const char *szCacheDevPath, const char *szTrgDevPath);
int SYNOFlashCacheSysctlSet(const FLASHCACHE_OPTION *pS, const char *szCacheDevPath, const char *szTrgDevPath);
int SYNOFlashCacheDoSysctlSet(FLASHCACHE_SYSCTLS_OPERATE fCacheOp, int value, const char *szCacheDevPath, const char *szUnderDevPath);
/* flashcache_unload.c */
int SYNOFlashCacheUnload(const char *szDevPath);
/* flashcache_version_get.c */
FLASHCACHE_VERSION SYNOFlashCacheVersionGet(const char *szSSDPath);
