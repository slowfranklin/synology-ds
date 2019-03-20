// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FINDHOST_H
#define SYNO_FINDHOST_H

#include <time.h>
#include <sys/types.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define NUM_MAXIFACES 32

#ifndef _MSC_VER
#define INVALID_SOCKET (-1)
#endif
#define FHOST_IPADDR_LEN			16
#define BROADCAST_ADDR "255.255.255.255"
#define PKT_MAX_STRING_LEN 			255
#define ANY_ADDR "0.0.0.0"

#define STRING_DHCP "DHCP"
#define STRING_MANUAL "Manual"

#define SZF_FSCK_VOLUME	"/.e2fs_volume"
#define SZF_FSCK_PROGRESS_PREFIX "/tmp/e2fsck.progress."

typedef enum {
	FHOSTQC_FALSE = 0,
	FHOSTQC_DONE,
	FHOSTQC_NOTINSTALL,
	FHOSTQC_UPDATING,
	FHOSTQC_SYS_CRASH,
	FHOSTQC_BOOTING,
	FHOSTQC_QUOTA_CHECKING,
	FHOSTQC_SERVICE_STARTING,
	FHOSTQC_NETSET,
	FHOSTQC_MEM_TESTING,
	FHOSTQC_NET_TESTING,
	FHOSTQC_SYS_RECOVERABLE,
	FHOSTQC_OFF_LINE,
	FHOSTQC_INSTALLING_QCONFIGING,
	FHOSTQC_SYS_MIGRAT,
	FHOSTQC_NUM
} FHOSTQC_STATUS;

/**
 * Fhost errors.  
 */
typedef enum FHOSTERR {
	FHOST_NO_ERR = 0,
	FHOST_PASSWORD_ERR,
	FHOST_SUBNET_ERR,
	FHOST_LOCKFAIL_ERR,
	FHOST_DHCPSERVER_ERR,
	FHOST_QUICKCONF_ERR,
	FHOST_SERVER_ERR,
	FHOST_NO_SUCH_USER,
	FHOST_USER_EXPIRED,
	FHOST_DOMAIN_USER_ERR,
} FHOSTERR;

/**
 * The priorities of logging messages.  Priorities are ordered.
 */
typedef enum FHOSTLOG_PRIOR {
	FHOSTLOG_MIN,
	FHOSTLOG_ERR,
	FHOSTLOG_DEBUG,
	FHOSTLOG_NUM,
} FHOSTLOG_PRIOR;

/**
* The endian enumeration for read/write integer using
*/
typedef enum FHOSTPKT_ENDIAN {
	FHOSTPKT_LITTLE_ENDIAN,
	FHOSTPKT_HOST_ENDIAN,
	FHOSTPKT_KEEP_ENDIAN,
} FHOSTPKT_ENDIAN;

typedef enum FHOST_PKT_MASK {
	PKT_MASK_PKTTYPE = 0x0001,
	PKT_MASK_PKTVER = 0x0002,
	PKT_MASK_HAVE_DHCP = 0x0004,
	PKT_MASK_HAVE_NAME = 0x0008,
	PKT_MASK_HAVE_MAC = 0x0010,
	PKT_MASK_REQ_QUERY = (PKT_MASK_PKTTYPE | PKT_MASK_PKTVER),
	PKT_MASK_REQ_SETTING = (PKT_MASK_PKTTYPE | PKT_MASK_PKTVER
				| PKT_MASK_HAVE_DHCP | PKT_MASK_HAVE_NAME |
				PKT_MASK_HAVE_MAC),
} FHOST_PKT_MASK;

/* possible packet type vaule */
typedef enum FHOST_PKT_PTYPE {
	PKT_ID_PTYPE_MIN,
	PKT_ID_PTYPE_BROADCAST_QUERY,
	PKT_ID_PTYPE_BROADCAST_RESPONSE,
	PKT_ID_PTYPE_NETSETTING,
	PKT_ID_PTYPE_QUICKCONF,
	PKT_ID_PTYPE_SHAREACCESS_QUERY,
	PKT_ID_PTYPE_BROADCAST_JUNIOR_RESPONSE,
	PKT_ID_PTYPE_REDIRECTOR_SHARE_QUERY,
	PKT_ID_PTYPE_SHARE_QUERY_RESPONSE,
	PKT_ID_PTYPE_DRAUTH_QUERY,
	PKT_ID_PTYPE_DRAUTH_QUERY_RESPONSE,
	PKT_ID_PTYPE_GROUP_INSTALL,
	PKT_ID_PTYPE_MEM_TEST,
	PKT_ID_PTYPE_SHARE_ENUM,
	PKT_ID_PTYPE_SHARE_ENUM_RESPONSE,
	PKT_ID_PTYPE_BROADCAST_RECOVER,
	PKT_ID_PTYPE_BROADCAST_RECOVER_RESPONSE,
	PKT_ID_PTYPE_MAX,
} FHOST_PKT_PTYPE;

typedef enum {
	FHOST_SERVICE_SMB,
	FHOST_SERVICE_AFP,
	FHOST_SERVICE_NFS,
	FHOST_SERVICE_PHOTO,
	FHOST_SERVICE_RSRC_MON,
	FHOST_SERVICE_MEM_TEST,
	FHOST_SERVICE_SYS_MIGRAT,
	FHOST_SERVICE_CREATE_DEFAULT_SHR,
	FHOST_SERVICE_FSCK,
	FHOST_SERVICE_FSCK_CANCEL,
	/** The	first service */
	FHOST_SERVICE_START = FHOST_SERVICE_SMB,
	FHOST_SERVICE_END = FHOST_SERVICE_FSCK_CANCEL,
	/** bits of(NASINFO::ulSupportBitmapN) */
	FHOST_SERVICE_MAX = 128,
} FHOST_SERVICE;

typedef enum _tag_MIGRATION_ISSUE_
{
	MIGRATION_ENDIAN_ISSUE = 0x01,
	MIGRATION_ALIGNMENT_ISSUE = 0x02,
	MIGRATION_TOOLCHAIN_ISSUE = 0x04,
	MIGRATION_64_TO_32_ISSUE = 0x08
} MIGRATION_ISSUE;
	
typedef enum FHOST_PKT_ID {
	/** The lower bound of FHOST_PKT_ID. */
	PKT_ID_MIN = 0x00,
	PKT_ID_PACKET_TYPE = 0x01,
	PKT_ID_DHCP = 0x10,
	PKT_ID_NAME = 0x11,
	PKT_ID_IP = 0x12,
	PKT_ID_NETMASK = 0x13,
	PKT_ID_GATEWAY = 0x14,
	PKT_ID_DNS = 0x15,
	PKT_ID_DNS2 = 0x16,
	PKT_ID_DOMAIN = 0x17,
	PKT_ID_CONNECT = 0x18,
	PKT_ID_MAC = 0x19,
	PKT_ID_PASSWD = 0x1a,
	PKT_ID_WINS = 0x1b,
	PKT_ID_REMOTE_IP = 0x1e,
	PKT_ID_ERROR_CODE = 0x1f,
	PKT_ID_NEW_DHCP = 0x20,
	PKT_ID_NEW_NAME = 0x21,
	PKT_ID_NEW_IP = 0x22,
	PKT_ID_NEW_NETMASK = 0x23,
	PKT_ID_NEW_GATEWAY = 0x24,
	PKT_ID_NEW_DNS = 0x25,
	PKT_ID_NEW_DNS2 = 0x26,
	PKT_ID_NEW_DOMAIN = 0x27,
	PKT_ID_NEW_MAC = 0x29,
	PKT_ID_NEW_PASSWD = 0x2a,
	PKT_ID_NEW_WINS = 0x2b,
	PKT_ID_NEW_APPLET_PASSWD = 0x2c,
/* The following IDS are expaned for QuickConf */
	PKT_ID_NEW_DOMAIN2 = 0x2d,
	PKT_ID_NEW_DOMAIN3 = 0x2e,
	PKT_ID_NEW_DOMAIN4 = 0x2f,
	PKT_ID_NEW_DNS3 = 0x30,
	PKT_ID_NEW_DATETIME = 0x31,
	PKT_ID_NEW_TIMEZONE = 0x32,
	PKT_ID_NEW_ENABLE_NTP = 0x33,
	PKT_ID_NEW_NTP_PERIOD = 0x34,
	PKT_ID_NEW_NTP_ADDR1 = 0x35,
	PKT_ID_NEW_NTP_ADDR2 = 0x36,
	PKT_ID_NEW_LANG_DIPSPLAY = 0x37,
	PKT_ID_NEW_LANG_SORT = 0x38,
	PKT_ID_NEW_LANG_MAIL = 0x39,
	/** windows/apple/novell codepage. */
	PKT_ID_NEW_CODEPAGE = 0x40,
	PKT_ID_NEW_CP_NFS = 0x41,
	PKT_ID_NEW_CP_FTP = 0x42,
	PKT_ID_NEW_SMTP_ADDR = 0x43,
	PKT_ID_NEW_ADM_MAIL1 = 0x44,
	PKT_ID_NEW_ADM_MAIL2 = 0x45,
	/** send test mail, boolean. */
	PKT_ID_NEW_MAIL_TEST = 0x46,
	/** boolean. */
	PKT_ID_NEW_ENABLE_DISK_CACHE = 0x47,
	PKT_ID_MODEL = 0x48,
	PKT_ID_BUILD_NUMBER = 0x49,
//for Data Mirror
	PKT_ID_USER_NAME = 0x4a,
	PKT_ID_SHARE_NAME = 0x4b,
	PKT_ID_SHARE_RIGHT = 0x4c,
//system migration type
	PKT_ID_SYSMIGRAT_TYPE = 0x4d,
//for Add Printer
	PKT_ID_USB_DEVICE1 = 0x50,
	PKT_ID_USB_DEVICE2 = 0x51,
	PKT_ID_USB_DEVICE_MODEL1 = 0x52,
	PKT_ID_USB_DEVICE_MODEL2 = 0x53,
	PKT_ID_USB_DEVICE_TYPE1 = 0x54,
	PKT_ID_USB_DEVICE_TYPE2 = 0x55,
	PKT_ID_USB_PTR_ID1 = 0x56,
	PKT_ID_USB_PTR_ID2 = 0x57,
	PKT_ID_USB_PTR_STATUS1 = 0x58,
	PKT_ID_USB_PTR_STATUS2 = 0x59,
	PKT_ID_USB_PTR_MODE1 = 0x5A,
	PKT_ID_USB_PTR_MODE2 = 0x5B,
	PKT_ID_USB_PTR_MANU_TIMEOUT1 = 0x5C,
	PKT_ID_USB_PTR_MANU_TIMEOUT2 = 0x5D,
// for Redirector
	PKT_ID_UID = 0x60,
//for all
	PKT_ID_UNIQUE = 0x70,
	PKT_ID_SUPPORT_RAID = 0x71,	//alias is "PKT_SUPPORT_RAID" in other projects
	PKT_ID_NEW_PASSWD_LONG = 0x72,
	PKT_ID_SERIAL = 0x73,
	PKT_ID_SPAREDISK = 0x74,
	PKT_ID_ADMIN_HTTP = 0x75,
	PKT_ID_ADMIN_HTTPS = 0x76, 
	PKT_ID_DSM_VERSION = 0x77,
	PKT_ID_DSM_MODEL = 0x78,
	PKT_ID_PROGRESS = 0x79,
	PKT_ID_GUEST = 0x7A, // Depricated. DSM #62780
	PKT_ID_SUPPORT_WOL = 0x7B,
	PKT_ID_SRC_NIC_MAC = 0x7C,
	PKT_ID_DISK_BUILD_NUMBER = 0x7D,
	PKT_ID_DISK_DSM_VERSION = 0X7E,
	PKT_ID_DISK_DSM_MODEL = 0x7F,

//for centralize management of Surveillance
	PKT_ID_CMS_SLAVE = 0x80,
	
// for Support Critical update
	PKT_ID_CRITICAL_VERSION = 0x90,

/* filer current status string and stringid */
	PKT_ID_FILER_STATUS_ID = 0xa0,
	PKT_ID_FILER_STATUS = 0xa1,
	PKT_ID_FIRST_NIC_MAC = 0xa2,
	PKT_ID_OUTIF_INDEX = 0xa3,
	PKT_ID_FINDHOST_VERSION = 0xa4,
	PKT_ID_SERVICE_BITMAP = 0xa5,
	PKT_ID_INFORMATION_TIMEOUT = 0xa6,
	PKT_ID_QUICKCONF_DONE = 0xa7,
	
// for Supported Service Bitmaps (0xb0~0xb7)
	PKT_ID_SUPPORT_BITMAP1 = 0xb0,
	PKT_ID_SUPPORT_BITMAP2 = 0xb1,
// for Running Service Bitmaps (0xb8~0xbf)
	PKT_ID_RUNNING_BITMAP1 = 0xb8,
	PKT_ID_RUNNING_BITMAP2 = 0xb9,
/* for Support WebInstall */
	PKT_ID_SUPPORT_WEBINST = 0xba,

// for Support Network Printer
	PKT_ID_NETPRINTER_COUNT = 0xbb,
	PKT_ID_NETPRINTER_BRAND = 0xbc,
	PKT_ID_NETPRINTER_MODEL = 0xbd,
	PKT_ID_NETPRINTER_NAME = 0xbe,
	PKT_ID_NETPRINTER_MODE = 0xbf,

// for Support new serial number
	PKT_ID_NEW_SERIAL = 0xc0,

// for new os such as SRM
	PKT_ID_OS_NAME = 0xc1,
// for Assistant Build Number
	PKT_ID_ASSISTANT_BUILD_NUMBER = 0xc2,

/** The upper bound of FHOST_PKT_ID. */
	PKT_ID_MAX = 0x100
} FHOST_PKT_ID;

typedef enum FHOSTUSBINFO {
	FHOST_IS_OFFLINE = 0,
	FHOST_IS_ONLINE,
	FHOST_IS_PRINTER,
	FHOST_IS_DISK,
	FHOST_IS_UNKNOWN
} FHOSTUSBINFO;

typedef enum SYNO_MODEL_ {
	SYNO_DISK_STATION = 1,
} SYNO_MODEL;

typedef enum IPUNKNOWN_STATUS {
	SERVER_CONNECTION_NOT_TESTED = 0,
	SERVER_CONNECTION_TESTED,
	SERVER_DISPLAYED,
} IPUNKNOWN_STATUS;

typedef struct FHOSTLOG FHOSTLOG;

/** 
 * The common connection options for TCP/UDP.
 */
typedef struct FHOSTCONN FHOSTCONN;

/**
 * The operations when receiving NASINFO packets are needed.
 */
typedef struct FHOSTRECV FHOSTRECV;

/**
 * The operations when sending NASINFO packets are needed.
 */
typedef struct FHOSTSEND FHOSTSEND;

typedef struct NASINFO NASINFO;

typedef struct FHOSTNETIF FHOSTNETIF;

/**
 * The function pointer for checking exiting criteria callback function.
 * This type used in struct FHOSTCONN.  When client of library needs to stop
 * UDP/TCP server, let this function returns 1.  When next packet is coming or
 * select() timeouted, this function will be called and exit directly.
 * 
 * @return <ul>
 *         <li>1: This server should be stopped.
 *         <li>0: noop.
 *         </ul>
 */
typedef int (*FUNCISCANCEL) (void);

/**
 * The function pointer for logging extra messages.  This type is used in
 * struct FHOSTLOG.  The return value is ignored now.
 *
 * @param szMsg [IN] The string that contains one log entry.  Should not be
 * NULL.
 *
 * @return 0
 */
typedef int (*FUNCLOG) (const char *szMsg);

/**
 * The function pointer for lock/unlock callback function.  This type used in
 * struct FHOSTRECV or struct FHOSTLOG.  When passing 1 to this function, it 
 * will lock his mutex. While acquiring the mutex, this fuction may block his 
 * own thread/process. On the other hand, passing 0 to this function, it will 
 * unlock his mutex. 
 * 
 * @param blLock [IN] The integer indicates this function to lock or to
 * unlock.  Passing 1 for lock and 0 for unlock.
 *
 * @return <ul>
 *         <li>0: Lock/unlock successfully.
 *         <li>-1: error.
 *         </ul>
 */
typedef int (*FUNCLOCKER) (int blLock);

/**
 * The function pointer for filtering incoming packets callback function.
 * This type used in struct FHOSTRECV.  When passing a NASINFO packet to this
 * function, it will check the NASINFO::ulPktId is wanted or not.  If @a 
 * pnasInfo is wanted, returns 1.
 * 
 * @param pnasInfo [IN] The NASINFO pointer to be checked.  Should not be
 * NULL.
 *
 * @return <ul>
 *         <li>1: This packet is acceptable.
 *         <li>0: Not my packet.
 *         </ul>
 */
typedef int (*FUNCISACCEPT) (const NASINFO *pnasInfo);

/**
 * The function pointer for recveing incoming NASINFO packets callback
 * function.  This type used in struct FHOSTRECV.  The return code will be
 * used to send reply to UDP/TCP client
 *
 * @param pnasInfo [IN] The NASINFO pointer to be add.  Should not be NULL. 
 *
 * @return <ul>
 *         <li>0: This packet is added successfully.
 *         <li>-1: error.
 *         </ul>
 */
typedef int (*FUNCADD) (const NASINFO *pnasInfo);

typedef int (*FUNCUPDATEPROG) (unsigned long ulTotal, unsigned long ulNow,
			       unsigned long ulInc);

#ifdef WIN32
typedef unsigned long u_int32_t;
typedef unsigned long long u_int64_t;
#endif

typedef u_int64_t TYPE_BITMAP;

#ifndef NO_PROTO
#include "findhost_p.h"
#endif // NO_PROTO

#ifdef  __cplusplus
}
#endif
#endif // SYNO_FINDHOST_H
