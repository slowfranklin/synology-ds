/* volume_blk_dev_readahead_set.c */
int SLIBVolumeBlkDevReadAheadSet(const char *szDevPath, const unsigned int value);
/* volume_create.c */
int SYNOVolumeCreate(const SPACE_INFO *pSpace, FSTYPE fsType);
/* volume_create_fs.c */
int SYNOVolumeCreateFS(const SPACE_INFO *pSpace, FSTYPE fsType);
/* volume_create_tmp_dir.c */
int VolumeCreateTmpDir(const char *szVolPath);
/* volume_dev_location_to_str.c */
/* volume_expand.c */
int SYNOVolumeExpand(const SPACE_INFO *pSpace);
/* volume_external_decide_mount_opt.c */
/* volume_external_disk_map_set.c */
/* volume_external_mount.c */
int SLIBVolumeExternalMount(const char *szDevName, const char *szDevNumber, const char *szGUID);
/* volume_external_part_mount.c */
int SLIBVolumeExternalPartMount(void *pvPartition, int iFSType, BOOL blOnlyOnePartition, int noSerial, DISK_PORT_TYPE DiskPortType);
/* volume_external_part_unmount.c */
int SLIBVolumeExternalPartUnmount(const char *szDevName, PSYNOPARTSHAREINFO pPartShareInfo, BOOL blStopService, BOOL blUSBDev, BOOL blDoShareDelete, BOOL blSupportUSBVolume);
/* volume_external_share_bin_create.c */
int SYNOVolumeExternalShareBinCreate(const char *szShareBinPath);
/* volume_external_unmount.c */
int SLIBVolumeExternalUnmount(const char *szDevName, BOOL blStopService);
/* volume_external_vol_init.c */
int SLIBVolumeExternalVolInit(const char *szDevName, int iFSType);
/* volume_fs_cache_alloc.c */
SYNOVOL_FS_CACHE_INFO *SYNOVolFSCacheAlloc(void);
/* volume_fs_cache_dump.c */
int SYNOVolFSCacheDump(void);
/* volume_fs_cache_enum.c */
int SYNOVolFSCacheEnum(SYNOVOL_FS_CACHE_FILETER *pFilter, SYNOVOL_FS_CACHE_INFO **ppOutFSCache);
/* volume_fs_cache_free.c */
void SYNOVolFSCacheFree(SYNOVOL_FS_CACHE_INFO *pFSCache);
/* volume_fs_cache_push.c */
void SYNOVolFSCachePush(SYNOVOL_FS_CACHE_INFO **ppFSCacheDst, SYNOVOL_FS_CACHE_INFO *pFSCacheSrc);
/* volume_fs_cache_search.c */
int SYNOVolFSCacheSearch(SYNOVOL_FS_CACHE_FILETER *pFilter, SYNOVOL_FS_CACHE_INFO *pFSCache, SYNOVOL_FS_CACHE_INFO **ppOutFSCache);
/* volume_manage_with_temp_dev.c */
/* volume_mount.c */
int VolumeMountNoPlugin(const char *szDevPath, const char *szVolPath);
int VolumeMount(const char *szDevPath, const char *szVolPath);
/* volume_mount_all.c */
int SYNOVolumeMountAll(void);
/* volume_mount_opts_detect.c */
int SLIBVolumeMountOptsDetect(const char *szDevPath, char *szOpts, const size_t cbSize, FSTYPE *retFsType);
/* volume_plugin.c */
int SLIBVolumeMountPluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeUnmountPluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeRemountPluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeMountAllPluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeUnmountAllPluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeCreatePluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumeDeletePluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBVolumePluginSetArgs(PSLIBPLUGIN pPlugin, SYNOVOLPLUGARG *pPluginArg);
int SLIBVolumePluginSetAllArgs(PSLIBPLUGIN pPlugin, SYNOVOLPLUGARG *pPluginArg);
int SLIBVolumePluginAction(SDK_PLUGIN_ACTION action, PSLIBPLUGIN pPlugin, int iRet);
int SLIBVolumePluginPrepareArgs(const char *szVolPath, SYNOVOLPLUGARG **ppPluginArg);
int SLIBVolumePluginPrepareAllArgs(SYNOVOLPLUGARG **ppPluginArgs);
void SLIBVolumePluginArgsFree(SYNOVOLPLUGARG *pPluginArgs);
/* volume_readahead_allset.c */
void VolumeReadaheadAllset(void);
/* volume_readahead_get.c */
int VolumeReadaheadGet(const char *szDevPath);
/* volume_remount.c */
int SYNORemount(const char *szVolPath, FS_ACCCESS_STATUS st);
int SYNOVolRemount(const char *szVolPath, FS_ACCCESS_STATUS st);
/* volume_single_part_mount.c */
int SLIBVolumeSinglePartMount(const char *szDiskName, int iPartitionNumber, int iFSType, DISK_PORT_TYPE portType);
/* volume_single_part_unmount.c */
int SLIBVolumeSinglePartUnmount(const char *szDiskName, int part_no);
/* volume_unmount.c */
int VolumeUnmountNoPlugin(const char *szVolPath, FSTYPE fsType);
int VolumeUnmountAfterPostHook(const char *szVolPath);
int VolumeUnmount(const char *szVolPath);
/* volume_unmount_all.c */
int SYNOVolumeUnmountAll(void);
/* volume_conf_set.c */
int SYNOVolumeConfSet(const char *szVolPath, const PSYNOVOLCONF pVolConf);
/* volume_conf_get.c */
int SYNOVolumeConfGet(const char *szVolPath, PSYNOVOLCONF pVolConf);
/* volume_atime_opt_apply.c */
int SYNOVolumeAtimeOptApply(const char *szVolPath, const BOOL blEnable);
/* volume_path_set_for_vdsm.c */
int SYNOVolumePathSetForVDSM(const char *szVolPath);
/* volume_path_get_for_vdsm.c */
int SYNOVolumePathGetForVDSM(char *szVolPath, const size_t cbSize);
/* volume_max_size_get.c */
int SYNOVolMaxSizeGet(const char *szVolPath, unsigned long long *pUllMaxSizeBytes, BOOL blFromCache);
