/* sftp_config_free.c */
void SYNOSFTPConfigFree(SYNO_SFTP_CONFIG *pConf);
/* sftp_config_get.c */
int SYNOSFTPConfigGet(SYNO_SFTP_CONF_FILTER filter, SYNO_SFTP_CONFIG *pConf);
/* ftp_config_get.c */
int SYNOFTPConfGet(SYNO_FTP_CONF *pFTPConfig);
int SYNOFTPTimeOutGet(void);
int SYNOFTPFIPSEnabledGet(void);
BOOL SYNOFTPASCIIEnabledGet(void);
BOOL SYNOFTPUmaskEnabledGet(void);
BOOL SYNOFTPUseUTF8Get(void);
/* ftp_ui_set_chrootlist.c */
int SYNOUISetFTPChrootList(char *szList);
/* sftp_service.c */
int SLIBSFTPHup(void);
BOOL SYNOSFTPIsAlive(void);
/* tftp_config_set.c */
int SYNOTFTPConfSet(SYNO_TFTP_CONFIG *pTFTPConfig);
/* tftp_config_get.c */
int SYNOTFTPConfGet(SYNO_TFTP_CONFIG *pTFTPConfig);
/* tftp_service.c */
int SYNOTFTPService(SYNO_TFTP_SERVICE_ACTION act);
BOOL SYNOTFTPIsAlive(void);
/* ftp_config_set.c */
int SYNOFTPConfSet(SYNO_FTP_CONF FTPConfig);
int SYNOFTPTimeOutSet(int timeout);
int SYNOFTPFIPSEnabledSet(BOOL FIPSEnabled);
int SYNOFTPASCIIEnabledSet(BOOL ASCIIEnabled);
int SYNOFTPUmaskEnabledSet(BOOL UmaskEnabled);
int SYNOFTPUseUTF8Set(BOOL blUseUTF8);
/* ftp_share_enum.c */
int SYNOFTPShareEnum(PSLIBSZLIST *pplistFTPShareName, const SYNOSHAREENUM enumOpt);
/* ftp_chroot_rule_enum.c */
int SYNOFTPChrootRuleEnum(PPSLIBSZLIST ppChrootRuleList);
/* ftp_chroot_rule_save.c */
int SYNOFTPChrootRuleSave(PSLIBSZLIST pslChrootRuleList);
/* ftp_chroot_path_get.c */
int SYNOFTPChrootPathGet(const char *pszUserName, char *szChrootPath, int cbChrootPath, BOOL *pblIsHomeShare);
/* ftp_chroot_rule_parse.c */
int SYNOFTPChrootRuleParseToName(const char *pszRule, BOOL *pblRuleForUser, char *pszName, int cbName, char *pszChrootTarget, int cbChrootTarget);
int SYNOFTPChrootRuleParse(const char *pszRule, BOOL *pblRuleForUser, unsigned long int *pulId, char *pszChrootTarget, int cbChrootTarget);
/* ftp_chroot_rule_format.c */
int SYNOFTPChrootRuleFormat(char *pszRule, int cbRule, BOOL blRuleForUser, unsigned long int ulId, const char *pszChrootTarget);
/* ftp_chroot_rule_delete.c */
int SYNOFTPChrootRuleDelete(BOOL blRuleForUser, PSLIBSZLIST pslName);
int SYNOFTPChrootRuleDeleteById(BOOL blRuleForUser, PSLIBSZLIST pslId);
int SYNOFTPChrootDomainRuleDeleteAll(void);
/* ftp_default_pasv_port_get.c */
int SYNOFTPDefaultPassivePortGet(SYNO_FTP_PASVPORT *pPasv);
