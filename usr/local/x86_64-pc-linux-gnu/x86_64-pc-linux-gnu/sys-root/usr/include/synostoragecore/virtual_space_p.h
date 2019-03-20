/* virtual_space_can_do.c */
BOOL SYNOVSpaceCanDo(const SPACE_INFO *pSpace, VSPACE_ACTION act, VSPACE_TYPE spaceType, BOOL *pblStopOccupied);
/* virtual_space_change_all.c */
int SYNOVSpaceChangeAll(const VSPACE_CHG_ALL_INPUT *pIn);
/* virtual_space_common_input_free.c */
/* virtual_space_common_input_get.c */
/* virtual_space_conf_check.c */
int SYNOVSpaceConfCheck(VSPACE_CONFIG_CHK_INPUT *pIn);
/* virtual_space_conf_enum.c */
int SYNOVSpaceConfEnum(VSPACE_CONFIG **ppConfigAlloc);
/* virtual_space_conf_free.c */
void SYNOVSpaceConfFree(VSPACE_CONFIG *pConfigAlloc);
/* virtual_space_create.c */
int SYNOVSpaceCreate(SPACE_INFO *pSpace, VSPACE_TYPE spaceType, const void *pConfig, char *szOutTopPath, int cbPath);
/* virtual_space_create_all.c */
int SYNOVSpaceCreateAll(SPACE_INFO *pSpace, FSTYPE fsType, char *szOutTopPath, int cbPath);
/* virtual_space_delete.c */
int SYNOVSpaceDelete(const SPACE_INFO *pSpace, VSPACE_TYPE spaceType, char *szOutTopPath, int cbPath, BOOL blFastRemove);
/* virtual_space_delete_all.c */
int SYNOVSpaceDeleteAll(const SPACE_INFO *pSpace, char *szOutTopPath, int cbPath);
/* virtual_space_implement.c */
/* virtual_space_implement_op_lib.c */
/* virtual_space_info_check.c */
int SYNOVSpaceInfoCheck(SPACE_INFO *pSpace);
/* virtual_space_info_free.c */
void LayerConfFree(VSPACE_LAYER_INFO **ppLayerInfo);
/* virtual_space_layer_archive.c */
/* virtual_space_layer_close.c */
/* virtual_space_layer_delete.c */
/* virtual_space_layer_entry_parse.c */
/* virtual_space_layer_entry_tostr.c */
/* virtual_space_layer_get.c */
int  LayerConfGet(const char *szFilePath, const VSPACE_LAYER_CONF_FILTER *pF, PSLIBSZHASH *ppshVSpaces, VSPACE_LAYER_INFO **ppLayerInfo);
/* virtual_space_layer_info_free.c */
/* virtual_space_layer_init.c */
/* virtual_space_layer_lock.c */
/* virtual_space_layer_num_get.c */
int SYNOVSpaceLayerNumGet(const SPACE_INFO *pSpace, int *pLayerType);
/* virtual_space_layer_open.c */
/* virtual_space_layer_path_get.c */
int SYNOVSpaceLayerPathGet(VSPACE_TYPE spaceType, VSPACE_LAYER_FILTER *pf, char *szOutVSpacePath, int cbPath);
/* virtual_space_layer_set.c */
int  SYNOVSpaceLayerConfSet(const char *szSpaceUUID, const PSLIBSZHASH pshVSpaces);
/* virtual_space_layer_spacepath_get.c */
int SYNOVSpaceLayerSpacePathGet(const char *szVSpaceOrSpacePath, char *szOutSpacePath, int cbPath);
/* virtual_space_layer_write.c */
/* virtual_space_load.c */
int SYNOVSpaceLoad(SPACE_INFO *pSpace, VSPACE_TYPE spaceType, const void *pConfig, char *szOutTopPath, int cbPath);
/* virtual_space_load_all.c */
int SYNOVSpaceLoadAll(SPACE_INFO *pSpace, const VSPACE_CONFIG *pConfigList, char *szOutTopPath, int cbPath);
/* virtual_space_load_in_stage.c */
int SYNOVSpaceLoadInStage(SPACE_INFO *pSpace, VSPACE_STAGE stage, VSPACE_TYPE spaceType, VSPACE_CONFIG *pConfigList, char *szOutTopPath, int cbPath);
/* virtual_space_path_info_get.c */
int SYNOVSpacePathInfoGet(SPACE_INFO *pSpace, VSPACE_TYPE spaceType, char *szOutVSpacePath, int cbVSpacePath, char *szOutUnderPath, int cbUnderPath);
/* virtual_space_reload.c */
int SYNOVSpaceReload(const SPACE_INFO *pSpace, VSPACE_TYPE spaceType, char *szOutTopPath, int cbPath);
/* virtual_space_resize_all.c */
int SYNOVSpaceResizeAll(const VSPACE_RESIZE_ALL_INPUT *pIn, char *szUnderDevPath, int cbPath);
/* virtual_space_trigger_event.c */
int SYNOVSpaceTriggerEvent(int vType, VSPACE_EVENT e);
/* virtual_space_under_dev_path_get.c */
int SLIBVSpaceUnderDevPathGet(const SPACE_INFO *pSpace, VSPACE_TYPE vspaceType, char *szUnderDevPath, int cbUnderDevPath);
/* virtual_space_unload.c */
int SYNOVSpaceUnload(SPACE_INFO *pSpace, VSPACE_TYPE spaceType, char *szOutTopPath, int cbPath);
/* virtual_space_unload_all.c */
int SYNOVSpaceUnloadAll(SPACE_INFO *pSpace, char *szOutTopPath, int cbPath);
/* virtual_space_unload_in_stage.c */
int SYNOVSpaceUnLoadInStage(SPACE_INFO *pSpace, VSPACE_STAGE stage, VSPACE_TYPE spaceType, char *szOutFinalTopPath, int cbPath);
