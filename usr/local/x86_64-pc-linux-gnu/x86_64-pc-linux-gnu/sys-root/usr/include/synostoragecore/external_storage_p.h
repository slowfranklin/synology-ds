/* external_storage_disk_can_sleep.c */
int SYNOExtStgDiskCanSleep(char *szName);
/* external_storage_parts_vol_info_get.c */
int SYNOExtStgPartsVolInfoGet(const char *szDevName, SYNOPARTVOLINFO *pUSBPartVolInfo, BOOL blUSBDev);
/* external_storage_pull_out.c */
int SYNOExtStgPullOut(char *szDevName, int iDevType, BOOL blRemoveDev);
/* external_storage_serial_number_get.c */
int SYNOExtStgSerialNumberGet(const char *szDevName, int *pNumber, DISK_PORT_TYPE diskport);
/* external_storage_serial_number_register.c */
int SYNOExtStgSerialNumberRegister(const char *szDevName, int *pnumber, char *szOldGUID, int bufsize, int number, DISK_PORT_TYPE portType);
/* external_storage_vol_info_get.c */
int SYNOExtStgVolInfoGet(const char *szDevName, SYNOUSBVOLINFO *pvinfoUSB);
