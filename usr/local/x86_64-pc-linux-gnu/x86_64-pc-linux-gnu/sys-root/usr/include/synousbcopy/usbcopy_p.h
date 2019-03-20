/* usbcopy_cancel_task.c */
int USBCOPYCancelTask(void);
/* usbcopy_change_scemd_light.c */
int USBCOPYChangeScemdLight(const int signo);
/* usbcopy_check_def_folder_exist.c */
int USBCopyCheckDefFolderExist(const USB_DEVICE_TYPE type, char *szDefFolder, const int cbDefFolder);
/* usbcopy_get_dest_folder.c */
int USBCopyGetDestFolder(const USB_DEVICE_TYPE type, char *szDestDir, const int cbDestDir);
/* usbcopy_is_copy_performing.c */
int USBCOPYIsCopyPerforming(void);
/* usbcopy_is_device_at_front_port.c */
int USBCOPYIsDeviceAtFrontPort(PSYNOUSB1 psynousb);
/* usbcopy_reset_share_folder.c */
int USBCopyResetShareFolder(const USB_DEVICE_TYPE type, char *szShareFolder, char *szUSBCopyFolder);
/* usbcopy_set_dest_folder.c */
int USBCopySetDestFolder(const USB_DEVICE_TYPE type, const PSYNOSHARE pShare);
/* usbcopy_set_usb_copy_folder_to_default.c */
int SetUSBCopyFolderToDefault(const USB_DEVICE_TYPE type);
