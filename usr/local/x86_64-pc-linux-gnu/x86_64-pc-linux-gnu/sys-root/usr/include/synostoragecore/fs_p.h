/* fs_btrfs_cmd.c */
int SYNOBtrfsCreateSubVol(const char *szSubVolPath);
int SYNOBtrfsDeleteSubVol(const char *szSubVolPath);
int SYNOBtrfsIsSubVol(const char *szSubVolPath);
int SYNOBtrfsSnapshotTake(const char *szSrcPath, const char *szDstPath);
int SYNOBtrfsReadOnlySnapshotTake(const char *szSrcPath, const char *szDstPath);
int SYNOBtrfsResize(const char *szVolPath);
int SYNOBtrfsResizeQuery(const char *szVolPath);
int SYNOBtrfsScrubbing(const char *szVolPath);
int SYNOBtrfsScrubbingCancel(const char *szVolPath);
int SYNOBtrfsDefrag(const char *szVolPath);
int SYNOBtrfsDeleteSubvolFaultTolerant(const char *szSubVolPath);
int SYNOBtrfsDeleteSubvolListFaultTolerant(const char *szSubVolDir, PSLIBSZLIST pListSnap);
/* fs_btrfs_subvol_info.c */
int SYNOBtrfsSubvolHideAttrSet(const char *szSubvolPath, BOOL blHide);
int SYNOBtrfsSubvolHideAttrGet(const char *szSubvolPath, BOOL *blHide);
int SYNOSnapFillSubvolInfoWithPath(const char *szSubvolPath, PSLIBSZHASH *ppHash);
int SYNOBtrfsListSubvol(const char *szVolPath, const char *szFilter, PSLIBSZLIST *ppListSubvolPath);
/* fs_cancel_data_scrubbing.c */
int SYNOFSCancelDataScrubbing(const char *szVolPath);
/* fs_cancel_defrag.c */
int SYNOFSCancelDefrag(const char *szPath);
/* fs_check_64bit_feature.c */
int FSCheck64bitFeature(const char *szDevPath);
/* fs_check_fs_inode_full.c */
INODESTATUS SLIBFSCheckInodeStatus(FS_INFO *pFSInfo, unsigned long long ullCriticalSize, float fPercent);
/* fs_clear_autocheck.c */
int FSClearNoUsedAutoCheck(void);
/* fs_create.c */
int FSCreate(const char *szDevPath, const FSTYPE fsType);
/* fs_data_scrubbing_status.c */
int SYNOFSDataScrubbingStatus(const char *szVolPath, unsigned long long *ullScrubBytes, unsigned long long *ullTotalBytes);
/* fs_default_type_get.c */
FSTYPE SYNOFSDefaultTypeGet(void);
/* fs_defrag_status.c */
int SYNOFSDefragStatus(const char *szPath, unsigned long long *ullDefragFiles, unsigned long long *ullTotalFiles);
/* fs_delete.c */
int SYNOFSDelete(const char *szDevPath);
/* fs_do_data_scrubbing.c */
int SYNOFSDoDataScrubbing(const char *szVolPath);
/* fs_do_defrag.c */
int SYNOFSDoDefrag(const char *szPath);
/* fs_expand_progress.c */
int FSExpandProgress(const char *szDevPath, float *pPercent);
/* fs_ext3_check_bad_file_archive.c */
int SYNOFSExt3CheckBadFileArchive(const char *szVolPath, BOOL *blHasBadArchive);
/* fs_ext3_clear_bad_file_archive.c */
int SYNOFSExt3ClearBadFileArchive(const char *szVolPath);
/* fs_ext4_lazyinit_info.c */
int FSExt4LazyinitInfo(const char *szDevPath, unsigned int *group_next, unsigned int *group_count);
/* fs_ext_dev_guid_part_num_get.c */
int SLIBExtDevGuidPartNumGet(const char *szVolPath, char *szGuid, int cbGuid, int *pPartNum);
/* fs_fallocate.c */
int SYNOFSFallocate(const int fd, const int mode, const unsigned long long offset, const unsigned long long len);
/* fs_fsck.c */
int SYNOFSCheck(const char *szDevPath);
/* fs_fstab_add_with_opts.c */
int SYNOFstabAddWithOpts(const char *szDevPath, const char *szMount, const char *szFStype, const char *szOpts);
/* fs_fstab_remove.c */
int SYNOFstabRemove(const char *szVolPath);
/* fs_get_disk_name_by_device.c */
int SYNOFSGetDiskNameByDevice(const char *szPath, char *szDiskName, int iDiskName);
/* fs_get_fs_size_limit.c */
int SYNOFSGetFSSizeLimit(unsigned long long *ullMaxFsBytes);
/* fs_get_remap_file_path.c */
int SYNOFsGetRemapFilePath(const char *szDevPath, char *szFilePath, int iFilePath);
/* fs_get_vol_ui_info.c */
int SYNOFSGetVolUIInfo(const char *szVolPath, char *szVolName, int cVolName, char *szVolDesc, int cVolDesc);
/* fs_is_volume_need_fsck.c */
BOOL SYNOFsIsVolumeNeedFsck(const char *szDevPath);
/* fs_mkfs_status_clear.c */
int FSMkfsStatusClear(const char *szDevPath);
/* fs_mkfs_status_get.c */
int FSMkfsStatusGet(const char *szDevPath, unsigned long long *pullDone, unsigned long long *pullTotal);
/* fs_online_resizable.c */
int FSOnlineResizable(const char *szDevPath);
/* fs_reserved_space_for_online_resize_get.c */
int SYNOFSReserveSpaceForOnlineResizeGet(const char *szDevPath, unsigned long long *ullReservedSize);
/* fs_resize_query.c */
int FSResizeQuery(const char *szDevPath, RESIZE_QUERY_CMD cmd);
/* fs_set_autocheck.c */
int FSSetAutoFsck(const char *szDevPath, char **pszOutPath, const int iLen);
/* fs_set_flags.c */
int SYNOFSSetNodatacow(const char *szPath);
int SYNOFSSetCompression(const char *szPath);
/* fs_short_dev_name.c */
int FSShortDevName(const char *szDevPath, char *szShortDevName, const int sizeName);
/* fs_usb_parts_uuid_gen.c */
int SYNOUSBPartsUuidGen(const char *szVolPath);
/* fs_vol_expand.c */
int SYNOFSExpand(const char *szDevPath);
/* fs_vol_expansible.c */
int SYNOVolExpansible(const char *szDevPath);
/* fs_get_fs_expansible_size_limit.c */
int SYNOFSGetExpansibleSizeLimit(const char *szVolPath, unsigned long long *ullLimitSize);
