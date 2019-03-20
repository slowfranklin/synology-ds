/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBDevBusnoGetInfo(char *szDeviceBusno, PSYNOUSB1 psynousb);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBDevEnum(int type, char **pszDevList, int cbSize, int *pcbNeed);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBIDevGetInfo(const char *szDevName, PSYNOUSB1 psynousb, long bus, long dev);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBDevGetInfo(const char *szDevName, PSYNOUSB1 psynousb);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBDevListGetInfo(PSYNOUSB1 *ppsynousb);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBIDevLookup(long lVendor, char *szVendor, int lenVendor, long lProduct, char *szProduct, int lenProduct);

/**
 * @apparmor abstractions/synousb
 */
int SYNOUSBGetDeviceId(const char *szDevice, char *szUsbDeviceId, int cbUsbDeviceId);

/**
 * @apparmor None.
 */
int SYNOUSBGetLocation(PSYNOUSB1 psynousb);

/**
 * @apparmor None.
 */
int SYNOUSBIGetNumByName(const char *szDevName, long *plBusNum, long *plDevNum);

/**
 * @apparmor None.
 */
char *SzSYNOUSBIGetValue(PSLIBSZLIST pList, char *szKey);

/**
 * @apparmor None.
 */
int SYNOUsbIsCardreader(const char *szDev);
