/* swap_file_create.c */
int SYNOSwapFileCreate(const char *szFilePath, int sizeMB);
/* swap_is_enable.c */
BOOL SYNOIsSwapEnable(const char *szDevPath);
/* swap_on.c */
int SYNOSwapOn(const char *szDevPath, BOOL blOn);
