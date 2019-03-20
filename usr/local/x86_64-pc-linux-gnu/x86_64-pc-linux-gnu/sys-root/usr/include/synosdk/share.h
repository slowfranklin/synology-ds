// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_SHARE_H__
#define __SYNO_SHARE_H__

#include <sys/cdefs.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/bdb.h>
#include <synocore/error.h>
#include <synocore/hash.h>
#include <synocore/list.h>
#include <synocore/mresult.h>
#include <synocore/file.h>
#include <limits.h>
#include <unistd.h>

__BEGIN_DECLS;

/**
 * @addtogroup SHARE
 *
 * @brief Some basic structure and operation of Share information. More features in libsynoshare.
 *
 * @{
 */

#define SZ_RECYCLE_FOLDER "#recycle"
#define SZF_RECYCLE_WIN_ICON "desktop.ini"
#define SZK_ENCRYPTION		"encryption"
#define SZK_AUTODECRYPT		"autodecrypt"
#define SZK_EDIT_ACL		"edit synoacl"
#define SZK_WIN_SHARE		"win share"
#define SZK_SKIP_SMB_PERM		"skip smb perm"
#define SZD_SERVICE_SYMLINK     "/var/services"
#define SZD_PHOTO_SHARE		"photo"
#define SZD_WEB_SHARE		"web"
#define SZD_MUSIC_SHARE		"music"
#define SZD_VIDEO_SHARE		"video"
#define SZD_NETBKP_SHARE	"NetBackup"
#define SZD_SURVEILLANCE_SHARE	"surveillance"
#define SZ_SATA_NORMAL_SHARE	"satashare"
#define SZD_PFX_USB_DEFSHARE	"usbshare"
#define SZD_PFX_SD_DEFSHARE	    "sdshare"
#define SZD_SD_DEFSHARENO        1   // FIXME: This number is set 1 and used for serial number of SD share
									 //        since the current number of SD device is 1.
									 //        And Note that the serial number of mount path is shared with the USB device.
									 //        If the number of SD increases in the future, the SD serial number mush be modified
/**
 * define reserved section name
 */
#define SZK_RSECTION_GLOBAL	"global"
#define SZK_RSECTION_HOME	"home"
#define SZK_RSECTION_PRINTERS	"printers"
#define SZK_RSECTION_DOT	"."
#define SZK_RSECTION_2DOTS	".."
#define SZK_RSECTION_SYSVOL	"sysvol"
#define SZK_RSECTION_NETLOGON	"netlogon"

#define SZK_SECTION_HOMES	"homes"

#define SZK_EXTERNAL_UUID	"guid"
#define SZK_EXTERNAL_INDEXED "indexed"

#define SZF_SMBCONF			"/etc/samba/smb.conf"
#define SZF_DEF_SMBCONF		"/usr/syno/etc.defaults/smb.conf"
#define SZF_SMBCONF_TMP		SZF_SMBCONF ".tmp"
#define SZF_SMBCONF_SHARE   "/etc/samba/smb.share.conf"
#define SZF_SMBCONF_RESERVED    "/etc/samba/smb.reserved.conf"
#define SZF_ENC_SHARE_LOCK	"/tmp/enc.share.lock"

#define SYNO_SHARENAME_UTF8_MAX		492
#define SYNO_SHARENAME_UTF32_MAX	32
#define SYNO_SHAREDESC_UTF8_MAX		64

#define SHARE_RO	0x0001
#define SHARE_RW	0x0002
#define SHARE_NA	0x0004

typedef struct {
	int user_priv;
	int group_priv;
	int all_priv;
} SHARE_PRIVILEGE;

#define SZ_SHAREMOVE_TMP_DIR	"@tmp"

#define SZ_CLEAN_RECYCLE_PID_FILE	"/tmp/cleanrecycle.pid"

#define SZ_DEFAULT_SHARED_FOLDER "System default shared folder"

#define SZK_FTP_DISABLE_LIST "ftp disable list"
#define SZK_FTP_DISABLE_MODIFY "ftp disable modify"
#define SZK_FTP_DISABLE_DOWNLOAD "ftp disable download"
#define SZK_ENABLE_RECYCLE_BIN "enable recycle bin"
#define SZK_RECYCLE_BIN_ADMIN_ONLY "recycle bin admin only"
#define SZK_HIDE_UNREADABLE "hide unreadable"
#define	FTP_PRIV_DISABLE_LIST	0x1
#define	FTP_PRIV_DISABLE_MODIFY	0x2
#define	FTP_PRIV_DISABLE_DOWNLOAD	0x4

/**
 * Used in smb.conf to indicate if this share support file/media indexing.
 */
#define SZK_FILEINDEX		"fileindex"
#define SZK_MEDIAINDEX		"mediaindex"
#define SZK_ENABLE_ACL		"edit synoacl"

/**
 * defined for share & file name length in encryption share
 */
#define SYNO_ENCRYPT_MAX_COMPONENT_LENGTH	143

#ifdef SYNOSDK_USE_SHARE_DB

/**
 * The Synology Share DB File Handle.
 * Only two projects are allowed to use it: libsynoshare and lnxsdk.
 * We prevent others to use it by the flag SYNOSDK_USE_SHARE_DB.
 * @struct SYNOSHAREDB share.h <synosdk/share.h>
 */
typedef struct {
	/**
	 * The Primary DB Handle of Share DB.
	 * The key index here is the upper case of SHARE::szName.
	 */
	PSYNOBDB pShareDBPrimary;
} SYNOSHAREDB, *PSYNOSHAREDB;
#endif // SYNOSDK_USE_SHARE_DB

/**
 * bit0: disable or not
 * bit1: enable encryption or not
 * bit2: auto decrypt or not, should exist with bit1
 * bit3: forbidden when moving or encrypting/decrypting share
 */
typedef enum _tag_share_status_ {
	SHARE_STATUS_NORMAL = 0x0,	/* 0000 */
	SHARE_STATUS_DISABLE = 0x1,	/* 0001 */
	SHARE_STATUS_DEC  = 0x2,	/* 0010 */
	SHARE_STATUS_ENC  = 		/* 0011 */
		(SHARE_STATUS_DEC | SHARE_STATUS_DISABLE),
	/** should not exist alone, should exist with bit1 */
	SHARE_STATUS_AUTODEC = 0x4,
	SHARE_STATUS_FORBIDDEN = 0x8,	/* 1000 */

	SHARE_STATUS_MASK =
		(SHARE_STATUS_DISABLE | SHARE_STATUS_DEC | SHARE_STATUS_AUTODEC | SHARE_STATUS_FORBIDDEN),

//	SHARE_STATUS_SERVICE = 0x10,	/* service related, deprecated */
	/** synoindexed share */
	SHARE_STATUS_INDEXED = 0x20,
//	SHARE_STATUS_FILEINDEXED = 0x40,/* fileindexd share, deprecated */
	/** Enable ACL editing */
	SHARE_STATUS_ACL_ENABLE = 0x80,
	/** Recycle bin enabled */
	SHARE_STATUS_RECYCLE_BIN_ENABLED = 0x100,
	/** Recycle bin accessed by admin only */
	SHARE_STATUS_RECYCLE_BIN_ADMIN_ONLY = 0x200,
	/** Hide Unreadable enabled */
	SHARE_STATUS_HIDE_UNREADABLE_ENABLED = 0x400,
	/** All ACL mode share */
	SHARE_STATUS_WIN_SHARE = 0x800,
	/** SKIP SMB perm */
	SHARE_STATUS_SKIP_SMB_PERM = 0x1000,
	/** Export snapshot directory */
	SHARE_STATUS_SNAPSHOT_BROWSING = 0x2000,
	/** readonly by others */
	SHARE_STATUS_READONLY = 0x4000,
	/** clustered share */
	SHARE_STATUS_CLUSTER = 0x8000,
	/** the next bit */
	SHARE_STATUS_MAX = 0x10000
} SHARE_STATUS;

/**
 * The Synology Share Folder Information.
 *
 * You cannot define a SYNOSHARE variable and use the pointer
 * to refer the data directly. For example, if you consider the
 * following step to construct the SYNOSHARE struct, the struct
 * will not be a continuum struct and the system will pack with
 * wrong data to put into the database.
 *
 * Example:
 * **** Wrong use case ****
 * @code{.c}
 *     SYNOSHARE pShare;
 *     pShare.fType = SHARE_RW;
 *     pShare.szRW = szRW;
 *     pShare.szRO = szRO;
 *     pShare.szDeny = szDeny;
 *     pShare.szName = szShareName;
 *     pShare.szPath = szSharePath;
 *     pShare.szComment = szShareComment;
 *     pShare.fBrowseable = 1;
 *     pShare.fFTPPrivilege = 0;
 * @endcode
 *
 * Example:
 * **** Correct use case ****
 * @code{.c}
 *     PSYNOSHARE pTempShare = NULL;
 *     pTempShare = SYNOShareAlloc (szShareName, szShareCommen,
 *         szSharePath, szDeny, szRW, szRO, SHARE_RW, 1);
 * @endcode
 *
 * Use this method to construct the SYNOSHARE struct can ensure
 * that the data is a continuum struct and can be packed
 * correctly and put into the database.
 */
typedef struct _tag_SYNOSHARE {
	/**
	 *  The UTF-8 string pointer to the position of Share Name.
	 *  The maximum length is ::SYNO_SHARENAME_UTF32_MAX in Unicode
	 *  characters or ::SYNO_SHARENAME_UTF8_MAX in bytes.  Should not
	 *  be NULL.
	 */
	char *szName;
	/**
	 *  The UTF-8 string pointer to the position of Share Comments.
	 *  The maximum length of this string is 64 in Unicode
	 *  characters.  May be NULL.
	 */
	char *szComment;
	/**
	 *  The UTF-8 string pointer to the position of the mounted path
	 *  of Share.
	 *
	 *  The format is
	 *  `/volumeX/SYNOSHARE::szName/`.
	 */
	char *szPath;
	/**
	 *  The UTF-8 string pointer to the position that contains user
	 *  names and group names that are denied to access this Share.
	 */
	char *szDeny;
	/**
	 *  The UTF-8 string pointer to the position that contains user
	 *  names and group names that are readable and writeable to
	 *  this Share.
	 */
	char *szRW;
	/**
	 *  The UTF-8 string pointer to the position that contains user
	 *  names and group names that are read only and not writeable
	 *  to this Share.
	 */
	char *szRO;
	/**
	 * This is a deprecated member data.
	 * Please refer to DSM#53979.
	 */
	int fType;
	/**
	 *  The flag that indicates this Share is visitable in SMB. When
	 *  this field is set to 0, it means to hide this share folder
	 *  in "My Network Places" on Windows.
	 */
	int fBrowseable;
	/**
	 * Whether the share is a write only share in FTP and File Station.
	 * 0: not write only
	 * 1: write only share
	 */
	int fFTPPrivilege;
	/**
	 * The status of this share.
	 * Please refer ::SHARE_STATUS
	 */
	SHARE_STATUS status;
	/**
	 *  The amount of allocated bytes of this Share
	 */
	size_t nAlloc;
	/**
	 * lenEncKey record encryptioin share's enc key length for aes, (only have 16 or 32)
	 */
	int lenEncKey;
} *PSYNOSHARE;

typedef enum _tag_share_type_{
	/** service used */
	SHARE_FOR_SERVICE=0x01,
	/** system reserved share name */
	SHARE_RESERVED=0x02,
	SHARE_FOR_USB=0x08,
	SHARE_FOR_SATA=0x10,
}SHARE_NAME_CHECK;

/**
 * Enumerate the share names that locate on specified storage.
 */
typedef enum SYNO_SHARE_ENUM {
	/**
	 *  The lower bound of SYNO_SHARE_ENUM.
	 */
	SYNO_SHARE_ENUM_MIN   = 0,
	/**
	 *  Enumerate shares on local storages.
	 */
	SYNO_SHARE_ENUM_LOCAL = 0x1,
	/**
	 *  Enumerate shares on USB storages.
	 */
	SYNO_SHARE_ENUM_USB   = 0x2,
	/**
	 *  Enumerate shares on SATA storages.
	 */
	SYNO_SHARE_ENUM_SATA  = 0x4,
	/**
	 *  Enumerate shares on Gluster storages.
	 */
	SYNO_SHARE_ENUM_GLUSTER  = 0x8,
	/**
	 *  Enumerate shares on all storages.
	 */
	SYNO_SHARE_ENUM_ALL   =
		(SYNO_SHARE_ENUM_LOCAL | SYNO_SHARE_ENUM_USB | SYNO_SHARE_ENUM_SATA),

	/**
	 *  Enumerate encrypted shares.
	 */
	SYNO_SHARE_ENUM_ENCRYPT_ENC = 0x100,
	/**
	 *  Enumerate decrypted shares.
	 */
	SYNO_SHARE_ENUM_ENCRYPT_DEC = 0x200,
	/**
	 *  Enumerate all encrypted/decrypted shares.
	 */
	SYNO_SHARE_ENUM_ENCRYPT_ALL =
		(SYNO_SHARE_ENUM_ENCRYPT_ENC | SYNO_SHARE_ENUM_ENCRYPT_DEC),
	/**
	 *  Enumerate disable cluster shares.
	 */
	SYNO_SHARE_ENUM_CLUSTER_DISABLE = 0x400,
	/**
	 *  Enumerate enable shares.
	 */
	SYNO_SHARE_ENUM_CLUSTER_ENABLE = 0x800,
	/**
	 *  Enumerate all cluster shares.
	 *  cluster share use white paper, if you want to use, please use it.
	 */
	SYNO_SHARE_ENUM_CLUSTER_ALL =
		(SYNO_SHARE_ENUM_CLUSTER_DISABLE | SYNO_SHARE_ENUM_CLUSTER_ENABLE),

	/**
	 *  The upper bound of SYNO_SHARE_ENUM.
	 */
	SYNO_SHARE_ENUM_MAX =
		(SYNO_SHARE_ENUM_ALL | SYNO_SHARE_ENUM_ENCRYPT_ALL | SYNO_SHARE_ENUM_GLUSTER | SYNO_SHARE_ENUM_CLUSTER_ALL),
	/**
	 *  The default value of share type
	 *  will not list gluster share and cluster share,
	 */
	SYNO_SHARE_ENUM_DEF =
		(SYNO_SHARE_ENUM_ALL | SYNO_SHARE_ENUM_ENCRYPT_ALL)
} SYNOSHAREENUM;

typedef int (*PFUNC_SELECTOR)(const PSYNOSHARE pShare, void* pData);
typedef struct _tag_SYNO_SHARE_ENUM_FUNCTION {
	PFUNC_SELECTOR pSelector;
	void* pData;
} SYNOSHAREENUMFUNC, *PSYNOSHAREENUMFUNC;

typedef enum _tag_share_enum_function_ret {
	/** select the share */
	SHARE_ENUM_SELECT,
	/** not select the share */
	SHARE_ENUM_NOT_SELECT,
	/** stop select and return success */
	SHARE_ENUM_SUCCESS_STOP,
	/** stop select and return error */
	SHARE_ENUM_ERROR_STOP
} SHARE_ENUM_FUNCTION_RET;

typedef enum _tag_share_loc_type {
	SHARE_LOC_UNKOWN,
	/** /volume1/ */
	SHARE_LOC_INTERNAL,
	/** /volumeUSB1/usbshare/ */
	SHARE_LOC_EXT_DEVICE,
	/** /volumeUSB1/usbshare/@sharebin/ */
	SHARE_LOC_EXT_SHAREBIN,
	/** /volumeGluster1/ */
	SHARE_LOC_REMOTE
} SHARE_LOC_TYPE;

/** Share access right of hot plug disk */
#define	SZF_SHARE_RIGHT_MAP	"/usr/syno/etc/share_right.map"
/** Default share access right of new external disk */
#define	SZF_SHARE_RIGHT_EXTERNAL_DEFAULT_MAP "/usr/syno/etc/share_right_external_default.map"

typedef enum SHARE_ATTRS {
	SHARE_ATTR_NAME,
	SHARE_ATTR_PATH,
	SHARE_ATTR_MAX,
} SHARE_ATTRS;

typedef struct {
        const char *szShareName;
        const char *szServiceName;
} SERVICE_SHARE_MAP;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/share_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif // __SYNO_SHARE_H__
