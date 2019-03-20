// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/* enc_key_salt_get.c */
int SYNOShareEncKeySaltGet(const char *szName, char *szSalt, int cbSalt);
/* enc_key_file_read.c */
int SYNOShareEncKeyFileRead(const char* szFile, const char* szSalt, char* szContent, size_t cbContent);
/* enc_key_file_write.c */
int SYNOShareEncKeyFileWrite(const char* szFile, const char* szSalt, const char* szContent);
/* enc_key_verify.c */
int SYNOShareEncKeyVerify(const PSYNOSHARE pShare, const char* szPassword);
/* enc_share_mount.c */
int SYNOShareEncShareMount(const char* szShareName, const char* szPassword);
/* enc_share_unmount.c */
int SYNOShareEncShareUnmount(const char* szShareName);
/* enc_share_unmount_pure.c */
int SYNOShareEncShareUnmountPure(PSYNOSHARE pShare);
/* enc_key_save.c */
int SYNOShareEncKeySave(PSYNOSHARE pShare, const char* szPassword);
/* enc_rename_key_file.c */
int SYNOShareEncRenameKeyFile(const char* szOldShareName, const char* szNewShareName);
/* enc_key_file_unlink.c */
void SYNOShareEncKeyFileUnlink(const PSYNOSHARE pShare);
/* enc_defualt_key_file_read.c */
int SYNOShareEncDefaultKeyFileRead(const char* szShareName, char* szEncFileContent, size_t cbEncFileContent);
/* enc_is_valid_password.c */
BOOL SYNOShareEncIsValidPassword(const char* szPassword);
/* enc_export_key_salt_get.c */
const char* SYNOShareEncExportKeySaltGet();
/* enc_key_file_get.c */
int SYNOShareEncKeyFileGet(const PSYNOSHARE pShare, char *szPath, int cbPath);
/* enc_auto_key_file_get.c */
int SYNOShareEncAutoKeyFileGet(const PSYNOSHARE pShare, char *szPath, int cbPath);
/* enc_key_file_import.c */
int SYNOShareEncKeyFileImport(const char *szTmpFile, BOOL blAutoDecrypt, PSYNOSHARE pShare);
/* enc_key_file_safe_remove.c */
int SYNOShareEncKeyFileSafeRemove(const char *szShareName);
/* enc_writebio_disable.c */
int SYNOShareEncWriteBioDisable(const char *szSharePath);
