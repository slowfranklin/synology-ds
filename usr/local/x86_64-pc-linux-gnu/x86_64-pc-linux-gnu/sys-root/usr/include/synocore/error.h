// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_ERROR_H_ 
#define __SYNO_ERROR_H_ 

#include <errno.h>
#include <sys/cdefs.h>

__BEGIN_DECLS;

/**
 * @addtogroup  ERROR
 *
 * When a function call returns an error, it returns
 * -1 and sets the global variable synoerrno
 * accordingly. Successful calls never set errno. once
 * set, it remains until another error occurs. It should
 * only be examined after an error. The follwing list is
 * a list of possible errors in SYNOLIB. We assign error
 * value multiple of 256 to aovid having the same value
 * with those in libc's errno.h.
 *
 * @note Those fuctions are Thread-Safe only in disk mode.
 *
 * @brief The define and operation of Synology error codes in SynoLib.
 *
 * @{
 */

#define SLIBERR_FMT	"[0x%04X %s:%d]"
#define SLIBERR_ARGS	SLIBCErrGet(), SLIBCErrorGetFile(), SLIBCErrorGetLine()

/** 
 * Definition of Synology Error codes.  When a Synology SDK 
 * function call enconters an error, it returns 
 * -1 and sets the Synology Error by calling 
 * SLIBCErrSet() accordingly.  Successful calls never set error 
 * number.  Once set, it remains until another error occurs.  It
 * should only be examined after an error.  The follwing list is
 * a list of possible errors in SYNOLIB.  We assign error value 
 * multiple of 256 to aovid having the same value with those in 
 * libc's errno.h.
 * 
 * @note Those fuctions are Thread-Safe only in disk mode.
 *  
 * @see SLIBCErrGet() 
 * @see SLIBCErrSet() 
 */
typedef enum {
	/** The operation executes successfully. */
	ERR_SUCCESS			= 0x0000,
	/** The user doesn't specify enough storage to process the operation. */
	ERR_NOT_ENOUGH_MEMORY		= 0x0100,
	/** The system can't get more resource to process the operation. */
	ERR_OUT_OF_MEMORY		= 0x0200,
	/** Access is denied. */
	ERR_ACCESS_DENIED		= 0x0300,
	/** Unable to lock a file. */
	ERR_LOCK_FAILED			= 0x0400,
	/** Unable to unlock a file. */
	ERR_UNLOCK_FAILED		= 0x0500,
	/** The system can't find the path you specify. */
	ERR_PATH_NOT_FOUND		= 0x0600,
	/** The system can't find the file you specify. */
	ERR_FILE_NOT_FOUND		= 0x0700,
	/** The file exists. */
	ERR_FILE_EXISTS			= 0x0800,
	/** The system can't open the file you specify. */
	ERR_OPEN_FAILED			= 0x0900,
	/** The system can't read data from specified device. */
	ERR_READ_FAILED			= 0x0A00,
	/** The system can't write data to specified device. */
	ERR_WRITE_FAILED		= 0x0B00,
	/** The system can't create file or directory */
	ERR_CREATE_FAILED		= 0x0C00,
	/** The specified parameters are incorrect. */
	ERR_BAD_PARAMETERS		= 0x0D00,
	/** The specified server name is invalid. */
	ERR_INVALID_SERVERNAME		= 0x0E00,
	/** The specified domain name is invalid. */
	ERR_INVALID_DOMAINNAME		= 0x0F00,
	/** The specified IP format is invalid. */
	ERR_INVALID_NETNAME		= 0x1000,
	/** The system can't find the NT domain controller. */
	ERR_SERVER_UNREACHABLE		= 0x1100,
	/** The specified share name is invalid. */
	ERR_INVALID_SHARENAME		= 0x1200,
	/** The specified share exists. */
	ERR_SHARE_EXISTS		= 0x1300,
	/** The specified share doesn't exist. */
	ERR_NO_SUCH_SHARE		= 0x1400,
	/** The share number exceeds the limitation. */
	ERR_TOO_MANY_SHARES		= 0x1500,
	/** The specified group name is invalid. */
	ERR_INVALID_GROUPNAME		= 0x1600,
	/** The specified group name exists. */
	ERR_GROUP_EXISTS		= 0x1700,
	/** The specified group doesn't exist. */
	ERR_NO_SUCH_GROUP		= 0x1800,
	/** The group number exceeds the limitation. */
	ERR_TOO_MANY_GROUPS		= 0x1900,
	/** The specified user name is invalid. */
	ERR_INVALID_USERNAME		= 0x1A00,
	/** The specified password format is invalid. */
	ERR_INVALID_PASSWORDNAME	= 0x1B00,
	/** The specified user exists. */
	ERR_USER_EXISTS			= 0x1C00,
	/** The specified user doesn't exist. */
	ERR_NO_SUCH_USER		= 0x1D00,
	/** The specified password is incorrect. */
	ERR_WRONG_PASSWORD		= 0x1E00,
	/** The user nuber exceeds the limitation. */
	ERR_TOO_MANY_USERS		= 0x1F00,
	/** The specified keyword doesn't find. */
	ERR_KEY_NOT_FOUND		= 0x2000,
	/** The specified keyword exists. */
	ERR_KEY_EXISTS			= 0x2100,
	/** The specified section doesn't find. */
	ERR_SECTION_NOT_FOUND		= 0x2200,
	/** The specified section exists. */
	ERR_SECTION_EXISTS		= 0x2300,
	/** The user's free quota is not enough. */
	ERR_NOT_ENOUGH_QUOTA		= 0x2400,
	/** The free volume space is not enough. */
	ERR_NOT_ENOUGH_VOLUME_SPACE	= 0x2500,
	/** Seek operation is failed. */
	ERR_SEEK_FAILED			= 0x2600,
	/** Stat operation is failed. */
	ERR_STAT_FAILED			= 0x2700,
	/** Rename operation is failed. */
	ERR_RENAME_FAILED		= 0x2800,
	/** The file system's free space is not enough. */
	ERR_NOT_ENOUGH_SPACE		= 0x2900,
	/** Failed to execute the specified operation. */
	ERR_OP_FAILURE			= 0x2A00,
	ERR_DEV_UNCONFIG		= 0x2B00,
	ERR_DEV_UNMOUNTED		= 0x2C00,
	ERR_OP_UNREGISTERED		= 0x2D00,
	ERR_TIMER_EXPIRED		= 0x2E00,
	ERR_USER_BATCH_CONFLICT		= 0x2F00,

	/** Failed to read geometry from the specified (disk) device. */
	ERR_READ_GEO			= 0x3000,
	/** Wrong usage of paramters. */
	ERR_USAGE			= 0x3100,
	/** Illegal offset was specified when verifying the checksum of patch files. */
	ERR_UPDATE_OFFSET		= 0x3200,
	/** Illegal checksum (of a patch file). */
	ERR_CHECKSUM			= 0x3300,
	/** Failed to open the specified raw device. */
	ERR_OPEN_RAWDEVICE		= 0x3400,
	/** Failed to open the configuration file of installation. */
	ERR_OPEN_OPTFILE		= 0x3500,
	/** Failed to read data from the specified raw device. */
	ERR_READ_RAWDEVICE		= 0x3600,
	/** Failed to write data to the specified raw device. */
	ERR_WRITE_RAWDEVICE		= 0x3700,
	/** Illegal patch file. */
	ERR_BADPATCH			= 0x3800,
	ERR_REMOVE_FAILED		= 0x3900,
	ERR_MOVE_FAILED			= 0x3A00,
	ERR_COPY_FAILED			= 0x3B00,
	ERR_MKDIR_FAILED		= 0x3C00,
	ERR_MMAP_FAILED			= 0x3D00,
	ERR_FORMAT_ERROR		= 0x4000,
	/** The backup set doesn't exist. */
	ERR_NO_BACKUP_SET		= 0x5000,
	/**The dest id in local (/etc/synolocalbkp.conf) doesn't exist. */
	ERR_NO_DEST_ID				= 0x5100,
	/** Fail to get backup info in shared memory.*/
	ERR_BACKUP_INFO_FAIL		= 0x5200,
	/** The format of local backup destination is invalid.*/
	ERR_BAD_DEST_PATH		= 0x5300,
	/** Fail to remove shared memory id */
	ERR_RM_SHM_FAIL			= 0x5400,
	/** Failed to export application.  */
	ERR_EXPORT_APPLICATION	= 0x5500,
	/** Failed to import application.  */
	ERR_IMPORT_APPLICATION	= 0x5600,
	/** The volume ID can't be found. */
	ERR_NO_VOLUME_ID		= 0x6000,
	/** The disk ID can't be found. */
	ERR_NO_DISK_ID			= 0x6100,
	/** The amount of input sd is not enough. */
	ERR_NOT_ENOUGH_SD		= 0x6200,
	/** The input sds don't have the same capacity. */
	ERR_SD_SIZE_NOT_ALIGN		= 0x6300,
	/** Cannot destroy a volume because it is opened by someone. */
	ERR_DEVICE_BUSY			= 0x6400,
	/** The input sd is invalid. */
	ERR_INVALID_SD			= 0x6500,
	/** Disk formating fails. */
	ERR_FORMAT_FAIL			= 0x6600,
	/** Cannot accomplish disk rebuilding. */
	ERR_CANNOT_REBUILD_DISK		= 0x6700,
	/** RAID information of system is not correct. */
	ERR_BROKEN_RAID_CONF		= 0x6800,
	/** The specified disk is too small. */
	ERR_DISK_TOO_SMALL		= 0x6900,
	/** Cannot get mount information. */
	ERR_CANNOT_GET_MNTINFO		= 0x6A00,
	/** Disk information of system is not correct. */
	ERR_BROKEN_DISK_INFO		= 0x6B00,
	/** Disk I/O fails. */
	ERR_DISK_IO_FAILED		= 0x6C00,
	/** Disk has bad sectors. */
	ERR_BAD_DISKSECTOR		= 0x6D00,
	/** The specified handle is invalid. */
	ERR_UDPD_INVALID_HANDLE		= 0x7100,
	/** The specified handle is in running state. */
	ERR_UDPD_RUNNING_HANDLE		= 0x7200,
	/** The specified event is invalid. */
	ERR_UDPD_INVALID_EVENT   	= 0x7300,
	/** The specified parameters are illegal. */
	ERR_UDPD_INVALID_PARAMETER	= 0x7400,
	/** The daemon exits abnormally. */
	ERR_UDPD_EXIT_ABNORMAL		= 0x7500,
	/** The given space is not enough. */
	ERR_UDPD_NOT_ENOUGH_SPACE	= 0x7600,
	/** Time expires before receiving complete packet. */
	ERR_UDPD_TIMEOUT		= 0x7700,
	/** Cannot initialize the specified handle. */
	ERR_UDPD_INIT_FAIL		= 0x7800,
	/** Cannot send the specified data. */
	ERR_UDPD_SEND_FAIL		= 0x7900,
	/** Cannot receive the specified data. */
	ERR_UDPD_RECV_FAIL		= 0x7A00,
	/** The specified burn-in function is invalid. */
	ERR_MANUTIL_PERM		= 0x7B00,

	/** The error can't be determined by the function you called. */
	ERR_UNKNOWN			= 0x8000,
	/** System encounters a error, but the function you called can't tell you the real error. */
	ERR_SYS_UNKNOWN			= 0x8100,
	/** The request size of the volume to be created is too large. */
	ERR_VOLUME_SIZE_TOO_LARGE	= 0x8200,
	/** The specified volume doesn't find. */
	ERR_VOLUME_NOT_FOUND		= 0x8300,
	/** The specified volume is in read-only state. */
	ERR_VOLUME_READ_ONLY		= 0x8400,

	/** Ypbind occurs error when you join NIS domain. */
	ERR_YP_BIND			= 0x9000,
	/** No disc quota is found for the indicated user. */
	ERR_QUOTA_NOT_FOUND		= 0x9100,
	/** The quota file is corrupted or quota command or qouta type is invalid. */
	ERR_QUOTA_PARAM_INVALID		= 0x9200,
	/** Failed to remount the file system in order to enable user/group quota. */
	ERR_QUOTA_MOUNTING		= 0x9300,
	/** Failed to execute quotacheck. */
	ERR_QUOTA_QUOTACHECK		= 0x9400,
	/** Failed to execute quotaon. */
	ERR_QUOTA_QUOTAON		= 0x9500,
	/** Failed to execute quotaoff. */
	ERR_QUOTA_QUOTAOFF		= 0x9600,
	/** Fork operation is failed. */
	ERR_FORK_FAIL			= 0x9700,
	/** Failed to enumerate system RAID devices. */
	ERR_RAID_ENUM_FAIL		= 0x9800,
	ERR_ENUM_FAIL			= 0x9900,
	/** The path you specified is invalied for volume. */
	ERR_INVALID_PATHNAME		= 0x9A00,
	/** The path you specified is not an directory. */
	ERR_NOT_DIRECTORY		= 0xA000,
	/** The directory you specified doesn't exist. */
	ERR_DIRECTORY_NOT_EXISTS	= 0xA100,
	/** The path you specified is an directory. */
	ERR_IS_DIRECTORY		= 0xA200,
	/** source and destination file are identical (same file name or hard link). */
	ERR_PATH_CONFLICT      		= 0xA300,
	/** The file size exceed 4GB at FAT file system. */
	ERR_FAT_FILESIZE_TOO_LARGE	= 0xA400,
	/** The file contains illeagle char in FAT file system. */
	ERR_FAT_FILENAME_ILLEGAL  	= 0xA500,
	/** Action cancel by user . */
	ERR_USER_CANCEL  		= 0xA600,
	/** Interrupted by a signal */
	ERR_INTERRUPTED			= 0xA700,
	/** Share Encryption: Incorrect encryption key */
	ERR_ENCKEY_VERIFY		= 0xA800,
	/** Share Encryption: encryption key local copy lost */
	ERR_ENCKEY_LOST			= 0xA900,

	/** The BDb file has been deprecated. */
	ERR_BDB_FILE_DEPRECATED		= 0xB000,
	/** The file opened for BDb is incorrectly formatted. */
	ERR_BDB_FILE_BAD_FORMAT		= 0xB100,
	/** The BDb gets failed. Please see errno for detail. */
	ERR_BDB_GET_FAILED		= 0xB200,
	/** The BDb sets failed. Please see errno for detail. */
	ERR_BDB_SET_FAILED		= 0xB300,
	/** The BDb deletes failed. Please see errno for detail. */
	ERR_BDB_DELETE_FAILED		= 0xB400,
	/** The BDb CursorGet has finished. */
	ERR_BDB_CURSOR_FINISH		= 0xB500,
	/** No scuh fType value */
	ERR_NO_SUCH_FTYPE		= 0xB600,
	/** The gid is less than GID_MIN */
	ERR_RESERVED_GROUP		= 0xB700,
	/** The uid is less than UID_MIN */
	ERR_RESERVED_USER		= 0xB800,
	/** wbinfo -g timeout when building domain group db */
	ERR_LOOKUP_DOMAIN_GROUP		= 0xB900,
	/** wbinfo -u timeout when building domain user db */
	ERR_LOOKUP_DOMAIN_USER		= 0xBA00,
	/** The specified interface exists. */
	ERR_INTERFACE_EXISTS		= 0xBB00,
	/** The specified interface doesn't exist. */
	ERR_NO_SUCH_INTERFACE		= 0xBC00,
	/** The interfaces exceeds the limitation. */
	ERR_TOO_MANY_INTERFACE		= 0xBD00,
	/** Invalide path. */
	ERR_INVALID_PATH		= 0xBE00,

	/** The specified disk is too small. */
	ERR_SIZE_TOO_SMALL		= 0xBF00,
	ERR_NAME_EXISTS		= 0xC000,
	ERR_EXCEED_ISCSI_SIZE_IN_VOLUME		= 0xC100,
	ERR_FS_NOT_FOUND		= 0xC200,

	/** File name is too long. */
	ERR_NAME_TOO_LONG		= 0xC300,
	
	/** The service you specified exists. */
	ERR_SERVICE_EXISTS			= 0xD000,
	/** The service you specified doesn't exist. */
	ERR_SERVICE_NOT_EXISTS		= 0xD100,
	/** The service you sepcified doesn't set. */
	ERR_SERVICE_NOT_SET			= 0xD200,
	/** The service is invalid. It doesn't have either runkey or script. */
	ERR_SERVICE_INVALID			= 0xD300,
	/** Fail to execute service script. */
	ERR_SERVICE_SCRIPT			= 0xD400,
	/** Fail to remove service share */
	ERR_SERVICE_RMSHARE			= 0xD500,
	/** ACL can NOT change */
	ERR_SYNOACL_NOT_VALID_TO_CHG	= 0xD600,
	/** ACL NOT support */
	ERR_SYNOACL_NOT_SUPPORT	= 0xD700,
	/** No ACL permission */
	ERR_SYNOACL_NO_PERM	= 0xD800,
    	/** Not supported action */
	ERR_NOT_SUPPORT = 0xD900,
    	/** Disk in use */
    	ERR_DISK_IN_USE = 0xDA00,
    	/** wbinfo -n Converts name to sid fail */
    	ERR_LOOKUP_DOMAIN_SID = 0xDB00,
	/** delete or expire local admin fail */
	ERR_NOT_ENOUGH_VALID_ADMIN = 0xDC00,
	/** The volume is building. */
	ERR_SPACE_BUILDING_FOREGROUND	= 0xDD00,
	/** auth type is invalid */
	ERR_AUTH_TYPE = 0xDE00,
	/** The volume is recovering. */
	ERR_SPACE_RECOVERING	= 0xDF00,
	/** Ths encrypt share is acting */
	ERR_ENC_SHARE_ACTING	= 0xE000,
	/** Ths package center is acting */
	ERR_PKG_CENTER_ACTING	= 0xE100,
	/** This path is not a symbolic link */
	ERR_NOT_A_SYMLINK = 0xE200,
	/** The system can't close the file you specify. */
	ERR_CLOSE_FAILED = 0xE300,
	/** This action is illegel */
	ERR_FORBIDDEN_ACTION = 0xE400,
	/** The db is building.*/
	ERR_DB_BUILDING = 0xE500,
	/** The input string too long */
	ERR_STRING_TOO_LONG = 0xE600,
	/** The directory you specified exist. */
	ERR_DIRECTORY_EXISTS	= 0xE700,
	/** Ths encrypt share is not support */
	ERR_ENC_NOT_SUPPORT	= 0xE800,
	/** The traversal dependency contail loop */
	ERR_DEPENDENCY_CONTAIN_LOOP = 0xE900,
	/** Required dependency is not complete */
	ERR_INCOMPLETE_DEPENDENCY = 0xEA00,
	/** Required resource is not ready */
	ERR_RESOURCE_NOT_READY = 0xEB00,
	/** Conflict service is enabled */
	ERR_CONFLICT_SERV_ENABLED = 0xEC00,
	/** dependent service and conflict service have overlap*/
	ERR_FORBIDDEN_DEPENDENCY_LOGIC = 0xED00,
	/* Conflict on group batch operations */
	ERR_GROUP_BATCH_CONFLICT = 0xEE00,
	/** Exceed the upper bound of Max ACL entry number */
	ERR_SYNOACL_ENTRY_EXCEED	= 0xEF00,
	/** Disk is performing secure erase */
	ERR_DISK_SECURE_ERASING = 0xF000,
	/** Invalid row format in volume table */
	ERR_INVALID_VOLUME_TABLE_ENTRY = 0xF100,
	/** The dsm is upgrading. */
	ERR_DSM_UPGRADING	= 0xF200,
	/** Failed to send mail. */
	ERR_SMTP_SEND_MAIL_FAIL	= 0xF300,
	/** Resource is occupied by someone. */
	ERR_RESOURCE_OCCUPIED	= 0xF400,
	/** The specified mount point is not mounted*/
	ERR_VOLUME_NOT_MOUNTED = 0xF500,
	/** The specified encryption share is not mounted*/
	ERR_ENC_NOT_MOUNTED = 0xF600,
	/** Password is in history */
	ERR_PASSWORD_IN_HISTORY = 0xF700,
	/** Password is too common */
	ERR_PASSWORD_TOO_COMMON = 0xF800,
	/** Service is offline */
	ERR_SERVICE_OFFLINE = 0xF900,
	/** Chown file error */
	ERR_CHOWN_FAILED = 0xFA00,
} SYNOERR;

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/error_p.h>
#endif //NO_PROTO

/**
 * Sets the global variable synoerrno to the SYNOERR @p err.
 *
 * @param[in] err The SYNOERR error code.
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @return None.
 *
 * @grantable No
 */
#define SLIBCErrSet(err) SLIBCErrSetEx(err, __FILE__, __LINE__);

/**
 * Sets the global variable synoerrno according to errno.
 * If no matching errno was found, set to the SYNOERR @p defaultSynoErrno.
 *
 * @param[in] defaultSynoErrno The default SYNOERR error code.
 *
 * @note This function is Thread-Safe only in disk mode.
 *
 * @return None.
 *
 * @grantable No
 */
#define SLIBCErrSetByErrno(defaultSynoErrno) \
do { \
	switch (errno) { \
	case EDQUOT: \
		SLIBCErrSet(ERR_NOT_ENOUGH_QUOTA); \
		break; \
	default: \
		SLIBCErrSet(defaultSynoErrno); \
		break; \
	} \
} while(0) \

/** @} */

__END_DECLS;
#endif /* __SYNO_ERROR_H_ */
