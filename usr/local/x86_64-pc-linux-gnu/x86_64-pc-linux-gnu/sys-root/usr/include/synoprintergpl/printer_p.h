/* printer_device_info_get.c */
int SYNOPrinterGPLDevInfoGet(const char *szPrinterID, const long dev_type, PSYNOUSBIP pusbipInfo);
/* printer_cups_name_to_printer_id.c */
int SYNOPrinterGPLCupsNameToPrinterId(const char *szCupsPrinterName, char *szPrinterId, int cbPrinterId);
/* printer_conf_string_id_get.c */
int SYNOPrinterGPLConfStringIdGet(const char *szPrinterId, char *szOutBuf, int cbOutBuf);
/* printer_net_conf_get.c */
int SYNOPrinterGPLNetConfGet(const char *szPrinterID, PSYNO_NETPRINTER_CONF pNPConf);
