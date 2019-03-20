/* usb_usbip_ap_check_lock_and_queue.c */
int SYNOPrinterGPLUsbipApCheckLockAndQueue(const char *szPrinterId);
/* usb_usbip_ap_lock_release.c */
int SYNOPrinterGPLUsbipApLockRelease(const char *szPrinterId, char *szApName);
/* usb_usbip_ap_lock_get.c */
int SYNOPrinterGPLUsbipApLockGet(char *szPrinterId, char *szApName);
/* usb_usbdev_conf_lock.c */
int SYNOPrinterGPLUsbdevConfLock();
/* usb_usbdev_conf_unlock.c */
BOOL SYNOPrinterGPLUsbdevConfUnlock(int fdLock);
