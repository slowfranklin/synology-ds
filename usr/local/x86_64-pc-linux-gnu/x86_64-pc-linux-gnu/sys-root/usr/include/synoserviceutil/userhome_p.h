/* userhome_disable.c */
int SYNOUserHomeDisable();
/* userhome_disable_pure.c */
int SYNOUserHomeDisablePure(AUTH_TYPE authType);
/* userhome_enable_pure.c */
int SYNOUserHomeEnablePure(const char *szNewVolPath, AUTH_TYPE authType, PFUNC_Prog pfSetProgress, PFUNC_ErrReport pfErrReport);
/* userhome_reload.c */
int SYNOUserHomeReload(BOOL blStartHome);
/* userhome_action.c */
int SYNOUserHomeAction(SERVICE_ACTION iAct);
/* userhome_prepare_folder.c */
int SYNOUserHomePrepareFolder(const PSYNOUSER pUser);
/* userhome_check_all_folders.c */
int SYNOUserHomeCheckAllFolders(const AUTH_TYPE authType);
