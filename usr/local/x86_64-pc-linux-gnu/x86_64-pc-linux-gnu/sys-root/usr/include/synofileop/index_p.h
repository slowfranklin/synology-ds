/* index_index_add.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SLIBSynoIndexAdd(const char *szPath, SLIB_INDEX_OP mode);
/* index_index_add_ex.c */
SDK_STARTING_FROM(SDK_VER_4_3) void SLIBSynoIndexAddEx(const char *pszFile1, const char *pszFile2, SLIB_INDEX_OP mode, const char *pszPackage, SLIB_INDEX_PACKAGE_OP pkgMode);
/* index_init_support_value.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOPhotoServiceIsSupport(void);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOMediaServiceIsSupport(void);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOVideoServiceIsSupport(void);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOPPhotoServiceIsSupport(void);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOFileIndexIsSupport(void);
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOInitSupportValue(void);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOIndexIsNeed(void);
/* index_is_personal_package_path.c */
SDK_STARTING_FROM(SDK_VER_4_1) BOOL SYNOIndexIsPersonalPackagePath(const char *pszPath, const char *pszFolder, char *pszUser, int cbUserLen);
/* index_index_utils.c */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOPathResolve(const char *pszPath, char *pszOut, const int cbLen);
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOIndexIsEnabled(const char *pszPath, BOOL *blIsRecycleBinPath);
