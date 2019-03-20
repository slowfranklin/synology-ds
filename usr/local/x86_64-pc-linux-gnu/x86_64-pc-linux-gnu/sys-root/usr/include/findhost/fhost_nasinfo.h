// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_NASINFO_H
#define SYNO_FHOST_NASINFO_H

#include <time.h>
#include <sys/types.h>

#ifdef  __cplusplus
extern "C" {
#endif

extern unsigned char stFHOSTHeader[];
extern unsigned int FHOSTHeaderSize;
extern unsigned char stFHOSTBroadCast[];
extern unsigned int FHOSTBroadCastSize;

#define FHOST_NASNAME_LEN			32
#define	FHOST_PASSWD_UTF32_MAX 			127
#define	FHOST_PASSWD_UTF8_MAX 			(FHOST_PASSWD_UTF32_MAX * 6)
#if FHOST_PASSWD_UTF8_MAX > 0
#define	FHOST_PASSWD_MATRIX_MAX (((FHOST_PASSWD_UTF8_MAX -1)/8 + 1) * 16)
#else
#error  FHOST_PASSWD_MATRIX_MAX Should greater than zero.
#endif
#define FHOST_PASSWD_LEN_OLD			12

#define FHOST_DOMAIN_LEN			256
#define FHOST_STATUS_LEN			64
#define	FHOST_DEVICE_NAME_LEN			16
#define	FHOST_MODEL_NAME_LEN			256
#define FHOST_UNIQUE_LEN			64
#define FHOST_SERIAL_LEN			11
#define FHOST_MAX_SERIAL_LEN			32
#define FHOST_MAX_OS_NAME_LEN		8
#define IS_HAVE_NEW_SERIAL(version) if(version >= 3177 || (version >= 2676 && verison <= 2699))
#define SN_LEN_10					10

#ifndef SYNO_USER_PLAIN_PWD_UTF8_MAX
#define SYNO_USER_PLAIN_PWD_UTF8_MAX 		768	// With \0
#endif

#ifndef SYNO_USERNAME_UTF8_MAX
#define SYNO_USERNAME_UTF8_MAX			492
#endif

#ifndef SYNO_USERNAME_UTF32_MAX
#define SYNO_USERNAME_UTF32_MAX			64
#endif

#define FHOST_FILER_STATUS_LEN 			64
#define FHOST_PASSWORD_LEN	(((SYNO_USER_PLAIN_PWD_UTF8_MAX -1) /8 +1)* 16)
#define FHOST_DATATIME_LEN 			19
#define FHOST_TIMEZONE_LEN 			128
#define FHOST_NTP_PERIOD_LEN 			9
#define FHOST_LANGDISP_LEN 			32
#define FHOST_LANGMAIL_LEN 			32
#define FHOST_MAILADDR_LEN 			128
#define FHOST_USERNAME_LEN 			SYNO_USERNAME_UTF8_MAX
#define FHOST_DSM_VERSION_LEN			7
#define FHOST_DSM_MODEL_LEN			47
#define FHOST_PKT_MAX_OUTPUT_LEN 			(8192)
#define FHOST_USBIP_PTR_DATA_LEN	128
#define FHOST_USBIP_PTR_TIME_LEN	4	
#define NASINFO_TIMEOUT 			120	/* seconds */

#define	FHOST_VERSION				0x01020000	// version 2.0
#define FHOST_VERSION_MAJOR			0x01000000	// major number, imply DS series

#define PKT_FIELDHDR_LEN 			2
#define PKT_DATALENHDR_LEN 			2

#define FHOST_NETPRINTER_MAX		32
#define FHOST_NETPRINTER_DATA_LEN	64

struct NPInfo {
	unsigned int cElement;
	char szNPBrand[FHOST_NETPRINTER_MAX][FHOST_NETPRINTER_DATA_LEN];
	char szNPModel[FHOST_NETPRINTER_MAX][FHOST_NETPRINTER_DATA_LEN];
	char szNPName[FHOST_NETPRINTER_MAX][FHOST_NETPRINTER_DATA_LEN];
	char szNPMode[FHOST_NETPRINTER_MAX][FHOST_NETPRINTER_DATA_LEN];
};

/**
 * NASINFO struct
 */
struct NASINFO {
	/**
	 * test connection or displayed
	 * ID: none
	 * Endian: Host endian
	 */
	u_int32_t         iIPUnknownStatus;
	/**
	 * displayed in list 
	 * ID: none
	 * Endian: Host endian
	 */
	u_int32_t         iDisplayed;
	/**
	 * server name 
	 * ID: PKT_ID_NAME, PKT_ID_NEW_NAME 
	 */
	char        szName[FHOST_NASNAME_LEN+4];
	/**
	 * MAC address (used to record DS MAC address)
     *  ID: PKT_ID_MAC 
	 */
	char        szMac[FHOST_NASNAME_LEN+4];
	/**
	 * PC Source-NIC MAC address 
	 *  ID: PKT_ID_SRC_NIC_MAC
     */
	char		szSrcNICMac[FHOST_NASNAME_LEN+4];
	/**
	 * admins. password 
	 * ID: PKT_ID_NEW_PASSWD, PKT_ID_NEW_PASSWD_LONG 
	 */
	char        szPasswd[FHOST_PASSWORD_LEN + 4];
	/**
	 * USBDevice1 
	 * ID: PKT_ID_USB_DEVICE1 
	 */
	char        szUSBDevice1[FHOST_DEVICE_NAME_LEN+4];
	/**
	 * USBDevice2 
	 * ID: PKT_ID_USB_DEVICE2 
	 */
	char        szUSBDevice2[FHOST_DEVICE_NAME_LEN+4];
	/**
	 * USBDevice1 model 
	 * ID: PKT_ID_USB_DEVICE_MODEL1 
	 */
	char        szUSBDeviceModel1[FHOST_MODEL_NAME_LEN+4];
	/**
	 * USBDevice2 model 
	 * ID: PKT_ID_USB_DEVICE_MODEL2 
	 */
	char        szUSBDeviceModel2[FHOST_MODEL_NAME_LEN+4];
	/**
	 * USBPrinter1 ID 
     * ID: PKT_ID_USB_PTR_ID1 
	 */
	char		szUSBPtrID1[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter2 ID 
     * ID: PKT_ID_USB_PTR_ID2 
	 */
	char		szUSBPtrID2[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter1 Status 
     * ID: PKT_ID_USB_PTR_STATUS1 
	 */
	char		szUSBPtrStatus1[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter2 Status 
     * ID: PKT_ID_USB_PTR_STATUS2 
	 */
	char		szUSBPtrStatus2[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter1 Mode 
     * ID: PKT_ID_USB_PTR_MODE1 
	 */
	char		szUSBPtrMode1[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter2 Mode 
     * ID: PKT_ID_USB_PTR_MODE2 
	 */
	char		szUSBPtrMode2[FHOST_USBIP_PTR_DATA_LEN];
	/**
	 * USBPrinter1 Manual-Timeout 
     * ID: PKT_ID_USB_PTR_MANU_TIMEOUT1 
	 */
	char		szUSBPtrManuTimeout1[FHOST_USBIP_PTR_TIME_LEN];
	/**
	 * USBPrinter2 Manual-Timeout 
     * ID: PKT_ID_USB_PTR_MANU_TIMEOUT2 
	 */
	char		szUSBPtrManuTimeout2[FHOST_USBIP_PTR_TIME_LEN];
	/**
	 * szUnique 
	 * ID: PKT_ID_UNIQUE 
	 */
	char        szUnique[FHOST_UNIQUE_LEN+4];
	/**
	 * szSerial 
	 * ID: PKT_ID_SERIAL 
	 */
	char        szSerial[FHOST_SERIAL_LEN+1];
	/**
	 * szFirstNicMac 
	 * ID: PKT_ID_FIRST_NIC_MAC 
	 * note: In DSAssistant and DownloadRedirector, alias is 
	 * "szMacId"
	 */
	char        szFirstNicMac[FHOST_NASNAME_LEN+4];
	/**
	 * szUserName 
	 * ID: PKT_ID_USER_NAME 
	 */
	char        szUserName[FHOST_USERNAME_LEN + 4];
	/**
	 * szDsmVersion
	 * ID: PKT_ID_DSM_VERSION
	 */
	char        szDsmVersion[FHOST_DSM_VERSION_LEN + 1];
	/**
	 * szDiskDsmVersion
	 * ID: PKT_ID_DISK_DSM_VERSION
	 */
	char        szDiskDsmVersion[FHOST_DSM_VERSION_LEN + 1];
	/**
	 * szDsmModel
	 * ID: PKT_ID_DSM_MODEL
	 */
	char        szDsmModel[FHOST_DSM_MODEL_LEN + 1];
	/**
	 * szDiskDsmModel
	 * ID: PKT_ID_DISK_DSM_MODEL
	 */
	char        szDiskDsmModel[FHOST_DSM_MODEL_LEN + 1];

	/**
	 * ulUSBDeviceType1 
	 * ID: PKT_ID_USB_DEVICE_TYPE1 
	 * Endian: Host endian 
	 */
	u_int32_t ulUSBDeviceType1;
	/**
	 * ulUSBDeviceType2 
	 * ID: PKT_ID_USB_DEVICE_TYPE2 
	 * Endian: Host endian 
	 */
	u_int32_t ulUSBDeviceType2;
	/**
	 * is dhcp or not 
	 * ID: PKT_ID_DHCP, PKT_ID_NEW_DHCP 
	 * Endian: Host endian 
	 */
	u_int32_t ulDhcp;
	/**
	 * IP address 
	 * ID: PKT_ID_IP, PKT_ID_NEW_IP
	 * Endian: Network endian
	 */
	u_int32_t ulIP;
	/**
	 * subnet mask 
	 * ID: PKT_ID_NETMASK, PKT_ID_NEW_NETMASK 
	 * Endian: Network endian
	 */
	u_int32_t ulNetMask;
	/**
	 * subnet gateway 
	 * ID: PKT_ID_GATEWAY, PKT_ID_NEW_GATEWAY 
	 * Endian: Network endian
	 */
	u_int32_t ulGateway;
	/**
	 * primary DNS 
	 * ID: PKT_ID_DNS, PKT_ID_NEW_DNS 
	 * Endian: Network endian 
	 */
	u_int32_t ulDNS;
	/**
	 * is ping alived 
	 * ID: PKT_ID_CONNECT 
	 * Endian: Host endian 
	 */
	u_int32_t ulConnect;
	/**
	 * error code (see enum "FHOSTERR") 
	 * ID: PKT_ID_ERROR_CODE 
	 * Endian: Host endian
	 */
	u_int32_t ulErrCode;
	/**
	 * ulRemoteIP 
	 * ID: PKT_ID_REMOTE_IP 
	 * Endian: Network endian 
	 */
	u_int32_t ulRemoteIP;
	/**
	 * ulAdminHttp 
	 * ID: PKT_ID_ADMIN_HTTP 
	 * Endian: Host endian
	 */
	u_int32_t ulAdminHttp;
	/**
	 * ulAdminHttps 
	 * ID: PKT_ID_ADMIN_HTTPS 
	 * Endian: Host endian 
	 */
	u_int32_t ulAdminHttps;
	/**
	 * is the server configured(server's configure status) 
	 * ID: PKT_ID_QUICKCONF_DONE 
	 * Endian: Host endian 
	 */
	u_int32_t ulConfigured;
	/**
	 * model name 
	 * ID: ulModel 
	 * Endian: Host endian 
	 */
	u_int32_t ulModel;
	/**
	 * build number 
	 * ID: PKT_ID_BUILD_NUMBER 
	 * Endian: Host endian 
	 */
	u_int32_t ulBuild;
	/**
	 * build number on disk 
	 * disk ID: PKT_ID_DISK_BUILD_NUMBER 
     * Endian: Host endian
	 */
	u_int32_t ulDiskBuild;
	/**
	 * ulSupportRAID 
	 * ID: PKT_ID_SUPPORT_RAID 
	 * Endian: Host endian 
	 */
	u_int32_t ulSupportRAID;
	/**
	 * Assistant (received) or findhostd version (xmit) 
	 * ID: PKT_ID_FINDHOST_VERSION 
	 * Endian: Host endian 
	 * note: In DSAssistant and DownloadRedirector, alias is 
	 * "ulVersion" 
	 */
	u_int32_t ulFindHostVersion;
	/**
	 * ulFilerStatusID 
	 * ID: PKT_ID_FILER_STATUS_ID 
	 * Endian: Host endian 
	 * note: In DSAssistant and DownloadRedirector, alias is 
	 * "ulStatus" 
	 */
	u_int32_t ulFilerStatusID;
	/**
	 * interface number 
	 * ID: PKT_ID_OUTIF_INDEX 
	 * Endian: Host endian 
	 * note: In DSAssistant and DownloadRedirector, alias is 
	 * "ulIndex" 
	 */
	u_int32_t ulOutIfIndex;
	/**
	 * Packet Type 
	 * ID: PKT_ID_PACKET_TYPE 
	 * Endian: Host endian 
	 * note: In DSAssistant and DownloadRedirector, alias is 
	 * "ulPktId" 
	 */
	u_int32_t ulPacketType;
	/**
	 * Expire Time 
	 * ID: PKT_ID_INFORMATION_TIMEOUT 
	 * Endian: Host endian 
	 */
	u_int32_t ulExpireTime;
	/**
	 * uid 
	 * ID: PKT_ID_UID 
	 * Endian: Host endian 
	 */
	u_int32_t uid;

	/**
	 * ID: PKT_ID_PROGRESS
	 * Endian: Host endian
	 */
	u_int32_t ulProgress;

	/**
	 * ID: PKT_ID_CMS_SLAVE 
     * Endian: Host endian 
	 */
	u_int32_t ulCmsSlave;

	/**
	* ID: PKT_ID_SUPPORT_WOL
	* Endian: Host endian
	* 0: don't support WOL
	* 1: support WOL
	*/
	u_int32_t ulSupportWOL;
	
	/**
	* ID: PKT_ID_SUPPORT_BITMAP1 
	* Endian: Host endian 
	*/
	TYPE_BITMAP ullbmapSupport1;
	
	/**
	* ID: PKT_ID_SUPPORT_BITMAP2 
	* Endian: Host endian 
	*/
	TYPE_BITMAP ullbmapSupport2;
	
	/**
	* ID: PKT_ID_RUNNING_BITMAP1 
	* Endian: Host endian 
	*/
	TYPE_BITMAP ullbmapRunning1;
	
	/**
	* ID: PKT_ID_RUNNING_BITMAP2 
	* Endian: Host endian 
	*/
	TYPE_BITMAP ullbmapRunning2;

	/**
	* ID: PKT_ID_SYSMIGRAT_TYPE 
    * Endian: Host endian 
	*/
	u_int32_t ulSysMigratType;

	/**
	 * ID: PKT_ID_SUPPORT_WEBINST
	 * Endian: Host endian
	 * 0: not support webinstall
	 * 1: support webinstall
	 */
	u_int32_t ulSupportWebInst;

	/**
	 * NetPrntrInfo
	 * ID: PKT_ID_NETPRINTER_INFO
	 */
	struct NPInfo NetPrntrInfo;
	/**
	 * szNewSerial
	 * ID: PKT_ID_NEW_SERIAL
	 */
	char        szNewSerial[FHOST_MAX_SERIAL_LEN];
	/**
	 * ulCritical
	 * ID: PKT_ID_CRITICAL_VERSION
	 * Endian: Host endian 
	 */
	u_int32_t ulCritical;
	/**
	 * szOsName
	 * ID: PKT_ID_OS_NAME
	 */
	char        szOsName[FHOST_MAX_OS_NAME_LEN];
	/**
	 * build number of Synology Assistant
	 * ID: PKT_ID_ASSISTANT_BUILD_NUMBER
	 */
	u_int32_t ulAssistantBuild;
};

#ifdef  __cplusplus
}
#endif
#endif // SYNO_FHOST_NASINFO_H
