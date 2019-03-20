/* partition_check_layout.c */
BOOL BlSYNOCheckPartitionLayout(const char *szDev, BOOL blRaidType, PARTITITON_LAYOUT_VERSION *pPartitionLayout);
/* partition_check_special_device.c */
int SYNOCheckSpecialDevice(const char *szDev);
/* partition_clean.c */
int PartitionClean(const char *szDevPath, PARTITION_LAYOUT flag);
int PartitionCleanRAID(const char *szPath, const int partNum);
/* partition_create.c */
int PartitionCreate(const char *szDevPath, PARTITION_LAYOUT flag, const PARTITITON_LAYOUT_VERSION *pLayout);
/* partition_create_for_vdsm.c */
int PartitionCreateForVDSM(const char *szDevPath);
/* partition_disk_partition_layout_get.c */
int DiskPartitionsLayoutGet(const char *szDevName, SYNO_DISK_PARTITION_LAYOUT *pSynoPartitionLayout);
/* partition_exec.c */
int PartitionExec(PARTITION_ACTION act, const char *szDevPath, PARTITION_OPTION *pOpt);
/* partition_init.c */
int SYNOPartitionLayoutIdxGet(PARTITITON_LAYOUT_VERSION version, BOOL blSupportRaid);
/* partition_is_extended.c */
BOOL PartitionIsExtended(const char *szDevPath);
/* partition_layout_get.c */
int PartitionLayoutGet(PARTITITON_LAYOUT_VERSION *pLayout);
/* partition_layout_get_by_disk.c */
int PartitionLayoutGetByDisk(const PSLIBSZLIST pslDisks, PARTITITON_LAYOUT_VERSION *pOutLayout);
/* partition_layout_get_max.c */
int PartitionLayoutGetMax(PARTITITON_LAYOUT_VERSION *pLayout, int blGetMaxPartitionLayout);
/* partition_logical_create.c */
int PartitionLogicalCreate(const char *szDiskPath, const PARTITITON_LAYOUT_VERSION *pVersion, int partNo, unsigned long long ullSectors, int partType);
/* partition_modify_partition_fs_type.c */
int SYNOPartitionModifyPartitionFSType(const char *szDevPath, int iPartiionNumber, int iFSType);
/* partition_path_enum.c */
int PartitionPathEnum(const PARTITION_FILTER *pFilter, PSLIBSZLIST *ppOutList);
/* partition_rc_partition_configs.c */
long long RCPartitionConfigs(int PartNo, const char *szDevName, unsigned long long *pStartOffset, unsigned long *pFsType);
/* partition_start_size_get.c */
int SYNOStgCorePartitionStartSizeGet(const char *szDev, unsigned int partNo, unsigned long long *pUllStartSector, unsigned long long *pUllSizeSector);
/* partition_table_add.c */
int PartitionAddTable(const char *szDiskPath);
/* partition_table_type_get.c */
int PartitionTableTypeGet(const char *szDiskPath, PARTITION_TABLE *pTable);
