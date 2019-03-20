/* lvm_clean_illegal.c */
int LVMCleanIllegal(void);
/* lvm_create.c */
int LVMCreate(const PSLIBSZLIST pDevList, const char *szVGPath, const char *szLVName, char *szVgUUID, int lenVgUUID);
/* lvm_get_lvpath.c */
int LVMGetLVPath(char *szDevPath, char *szLVPath, int cbLVPath);
/* lvm_is_dev_pv.c */
BOOL LVMIsDevPV(const char *szDevPath);
/* lvm_is_support.c */
BOOL LVMIsSupport(void);
/* lvm_lv_alloc.c */
LVM_LV_INFO *LVMLvAlloc(void);
/* lvm_lv_create.c */
int LVMLvCreate(const char *szVGPath, const char *szLVName, unsigned long long ullSize);
/* lvm_lv_dup.c */
LVM_LV_INFO *LVMLvDup(const LVM_LV_INFO *pLV);
/* lvm_lv_exist.c */
int LVMLvExist(const char *szVGPath, const char *szLVName);
/* lvm_lv_expand.c */
int LVMLvExpand(const char *szVGPath, const char *szLVName, unsigned long long ullSize);
/* lvm_lv_free.c */
void LVMLvFree(LVM_LV_INFO *pLV);
/* lvm_lv_list_push.c */
void LVMLvListPush(LVM_LV_INFO **ppLvList, LVM_LV_INFO *pLv);
/* lvm_lv_remove.c */
int LVMLvRemove(const char *szVGPath, const char *szLVName);
/* lvm_lv_rename.c */
int LVMLvRename(const char *szVGPath, const char *szOldLVName, const char *szNewLVName);
/* lvm_lv_uuid_get.c */
int LVMLvUUIDGet(PSLIBSZHASH *ppshLvUUIDHash);
/* lvm_path_parse.c */
int LVMPathParse(const char *szPath, LVM_PATH_INFO *pInfo);
/* lvm_poweroff.c */
int LVMPoweroff(void);
/* lvm_pv_create.c */
int LVMPvCreate(const char *szDevPath);
/* lvm_pv_expand.c */
int LVMPvExpand(const LVM_VG_INFO *pVGInfo);
/* lvm_pv_expansible.c */
int LVMPvExpansible(PSLIBSZHASH *ppshPvExpansibleHash, PSLIBSZHASH *ppshPvMaxSizeKBHash);
/* lvm_pv_parse_line.c */
int LVMPvParseLine(char *szLine, LVM_PV_SB *pSB);
/* lvm_pv_remove.c */
int LVMPvRemove(const char *szDevPath);
/* lvm_pv_sb_enum.c */
int LVMPvSBEnum(LVM_PV_SB_LIST **ppSBList);
/* lvm_pv_sb_get.c */
int LVMPvSBGet(const char *szPath, LVM_PV_SB **ppSB);
/* lvm_pv_sb_list_free.c */
void LVMPvSBListFree(LVM_PV_SB_LIST *pSBList);
/* lvm_pv_sb_list_push.c */
void LVMPvSBListPush(LVM_PV_SB_LIST **ppSBList, LVM_PV_SB *pSB);
/* lvm_pvscan.c */
int LVMPvScan(void);
/* lvm_remove.c */
int LVMRemove(const char *szVGPath, const PSLIBSZLIST pPVList);
/* lvm_remove_dev.c */
void LVMRemoveDev(const char *szVGPath);
/* lvm_rm_lvpath.c */
int LVMRemoveLV(char *szDevPath);
/* lvm_vg_activate.c */
int LVMVgActivate(const char *szVGPath);
/* lvm_vg_create.c */
int LVMVgCreate(const char *szVGPath, const PSLIBSZLIST pDevList);
/* lvm_vg_deactivate.c */
int LVMVgDeActivate(const char *szVGPath);
/* lvm_vg_deactivate_plugin.c */
int SLIBLVMVgDeActivatePluginInit(PPSLIBPLUGIN ppPlugin);
int SLIBLVMVgDeActivatePluginSetArgs(PSLIBPLUGIN pPlugin, const char *szDevice);
int SLIBLVMVgDeActivatePluginAction(SDK_PLUGIN_ACTION action, PSLIBPLUGIN pPlugin, int iRet);
/* lvm_vg_expand.c */
int LVMVgExpand(const char *szVGPath, const char *szPVPath);
/* lvm_vg_expansible.c */
BOOL LVMVgExpansible(const LVM_VG_INFO *pVGInfo, unsigned long long *pMaxVgSizeKB);
/* lvm_vg_info_alloc.c */
LVM_VG_INFO *LVMVgInfoAlloc(void);
/* lvm_vg_info_free.c */
void LVMVgInfoFree(LVM_VG_INFO *pVg);
/* lvm_vg_reduce.c */
int LVMVgReduce(const char *szVGPath, const char *szPVPath);
/* lvm_vg_remove.c */
int LVMVgRemove(const char *szVGPath);
/* lvm_vg_rename.c */
int LVMVgRename(const char *szOrgVgPath, const char *szUUID, const char *szNewVgPath);
/* lvm_vg_sb_2_info.c */
int LVMVgSB2Info(const LVM_VG_SB *pSB, LVM_VG_INFO **ppVg);
/* lvm_vg_sb_alloc.c */
LVM_VG_SB *LVMVgSBAlloc(void);
/* lvm_vg_sb_enum.c */
int LVMVgSBEnum(LVM_VG_SB_LIST **ppSBList);
int LVMVgSBParseLine(char *szLine, int cbLine, LVM_VG_SB *pSB);
/* lvm_vg_sb_enum_lv.c */
int LVMVgSBEnumLv(const char *szVGPath, LVM_LV_INFO **ppLVList);
/* lvm_vg_sb_enum_pv.c */
int LVMVgSBEnumPv(const char *szVGPath, PSLIBSZLIST *ppPVPath);
/* lvm_vg_sb_free.c */
void LVMVgSBFree(LVM_VG_SB *pSB);
/* lvm_vg_sb_get.c */
int LVMVgSBGet(const char *szPath, LVM_VG_SB **ppSB);
/* lvm_vg_sb_list_free.c */
void LVMVgSBListFree(LVM_VG_SB_LIST *pSBList);
/* lvm_vg_sb_list_search.c */
int LVMVgSBListSearch(const LVM_VG_SB_LIST *pVgSB, const LVM_VG_SEARCH_PARAM *p, LVM_VG_SB **ppSB);
