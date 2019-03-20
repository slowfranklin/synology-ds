/* printer_reset_printer.c */
int SYNOResetPrinter(char *szDevName);
/* printer_device_open.c */
int SYNOPrinterDevOpen(const char *szDevName, int maxRetry);
/* printer_get_string_id.c */
int SYNOPrinterGetStringId(const char *szDevName, char *szOutBuf, int iOutSize);
/* printer_clean_spool.c */
int SYNOPrinterCleanSpool(void);
/* printer_enable_ext.c */
int SYNOPrinterEnableExt(BOOL blAction, const char *szDevName, const char *szDevice);
/* printer_is_active.c */
BOOL SYNOPrinterIsActive(void);
/* printer_conf_setup.c */
int SYNOPrinterConfSetup(PSYNOUSBIP pusbipInfo, BOOL blAllowEmpty);
/* printer_model_detect.c */
int SYNOPrinterModelDetect(SYNOUSBIP *usbipInfo);
/* printer_google_info_set.c */
int SYNOPrinterGoogleInfoSet(SYNOGCP_INFO *pGcpInfo);
/* printer_google_info_get.c */
int SYNOPrinterGoogleInfoGet(SYNOGCP_INFO *pGcpInfo);
/* printer_cups_get_ppd.c */
char *SYNOCupsGetPPD(char *szPrinterId);
/* printer_cups_job_wait_complete.c */
int SYNOPrinterCupsJobWaitComplete(char *szPrinterId, char *szJobId);
/* printer_cups_name_get.c */
int SYNOPrinterCupsNameGet(const char *szPrinterId, char *szCupsPrinterName, int cbCupsPrinterName);
/* printer_cups_print_file.c */
int SYNOPrinterCupsPrintFile(const char *szPrinterId, char *szFile, char *szJobId, BOOL blRemoveFile);
/* printer_usbtab_enum.c */
int SYNOPrinterUsbtabEnum(char ***pPrinterList, int *pcDevUSB);
/* printer_proc_usbtab_id_enum.c */
int SYNOPrinterProcUsbtabIdEnum(PPSLIBSZLIST ppList);
/* printer_cups_printer_add.c */
int SYNOPrinterCupsAdd(const char *szPrinterId, const char *szPpdPath);
/* printer_cups_name_check.c */
int SYNOPrinterCupsNameCheck(const char *szPrinterId, const char *szCupsPrinterName);
/* printer_cups_printer_enable.c */
int SYNOPrinterCupsPrinterEnable(char *szCupsPrinterName, BOOL blEnable);
/* printer_cups_printer_rm.c */
int SYNOPrinterCupsRm(const char *szPrinterId);
/* printer_cups_printer_rm_by_name.c */
int SYNOPrinterCupsRmByName(const char *szCupsPrinterName);
/* printer_cups_print_test_page.c */
int SYNOPrinterCupsPrintTestPage(const char *szPrinterId);
/* printer_conf_string_id_parse.c */
int SYNOPrinterConfStringIdGetVendor(char *szStringId, char *szBuf, int cbBuf);
int SYNOPrinterConfStringIdGetModel(char *szStringId, char *szBuf, int cbBuf);
int SYNOPrinterConfStringIdGetCmd(char *szStringId, char *szBuf, int cbBuf);
int SYNOPrinterConfStringIdParse(char *szStringId, const char *szType, char *szBuf, int cbBuf);
/* printer_queue_get.c */
int SYNOPrinterQueueGet(const char *szPrinterId, char *szBuf, int cbBuf);
/* printer_net_info_get_by_ip.c */
int SYNOPrinterNetInfoGetByIP(const char *szIP, PSYNO_NETPRINTER_INFO pNPInfo);
/* printer_net_get_string_id.c */
int SYNOPrinterNetGetStringId(const char *szIP, char *szOutBuf, int iOutSize);
/* printer_net_get_string_backend.c */
int SYNOPrinterNetGetStringBackend(const char *szIP, char *szBackend, int cBSize, char *szQName, int cQSize);
/* printer_net_update_conf.c */
int SYNOPrinterNetUpdateConf(BOOL blAction, const PSYNO_NETPRINTER_CONF pNPConf);
/* printer_net_conf_setup.c */
int SYNOPrinterNetConfSetup(PSYNO_NETPRINTER_CONF pNPConf, BOOL blAllowEmpty);
/* printer_net_cups_add.c */
int SYNOPrinterNetCupsAdd(const PSYNO_NETPRINTER_CONF pNPConf, const char *szPpdPath);
/* printer_net_nptab_enum.c */
int SYNOPrinterNetNptabEnum(PPSLIBSZLIST ppList);
/* printer_net_cups_rm.c */
int SYNOPrinterNetCupsRm(const char *szPrinterId);
/* printer_net_ping_status.c */
int SYNOPrinterNetPingStatus(const char *szIP, char *szStatus, int size);
/* printer_net_cups_name_and_ip_check.c*/
int SYNOPrinterNetCupsNameAndIPCheck(const char *szIP, const char *szCupsPrinterName);
/* printer_net_ip_check.c */
int SYNOPrinterNetIPCheck(const char *szIP);
/* printer_net_avahi_info_get.c */
int SYNOPrinterNetAvahiInfoGet(const char *szIP, PSYNO_NETPRINTER_INFO pNPInfo);
/* printer_smb_conf_setup.c */
__attribute__((visibility("hidden"))) int SYNOPrinterSmbConfSetup();
/* printer_backup_ppd.c */
__attribute__((visibility("hidden"))) int SYNOPrinterBackupPpd(const char *szPpdFile, const char *szPrinterId);
/* printer_net_bjnp_info_get.c */
int SYNOPrinterNetBjnpInfoGet(const char *szIP, PSYNO_NETPRINTER_INFO pNPInfo);
/* printer_enum_count.c */
int SYNOPrinterEnumCount(TYPE_PRINTER type, PPSLIBSZLIST pplist);
/* printer_cups_usb_conf_rm_all.c */
int SYNOPrinterCupsUsbConfRmAll();
/* printer_conf_lock.c */
int SYNOPrinterPrinterConfLock();
/* printer_conf_unlock.c */
BOOL SYNOPrinterPrinterConfUnlock(int fdLock);
