// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

#ifndef __SYNO_GLOBAL_H__
#define __SYNO_GLOBAL_H__

/**
 * @addtogroup SYNOGLOBAL
 *
 * @brief Some basic macro and enum.
 *
 * @{
 */

typedef enum {
	SEQ_BOOT_NONE = 0,
	SEQ_START_ETCRC,
	SEQ_CHECK_FS,
	SEQ_START_SERVICE,
	SEQ_BOOT_DONE,
	SEQ_SHUTTING_DOWN,
} SYNO_BOOT_SEQ;

typedef enum {
	BOOT_ROOTFS_READY,
	BOOT_VOLUME_READY,
	BOOT_SHARE_READY,
	BOOT_EVENT_ALL
} SYNO_BOOT_EVENT;

/**
 * The directory of UI strings.
 */
#define SZD_TEXTS		"/usr/syno/synoman/webman/texts/"
#define SZK_FTPPORT		"ftpport"
#define SZK_SYSLOG_SVR_PORT     "syslogport"
#define SZ_DS_SUPP_MTD_SERIAL	"support_mtd_serial"
#define SZ_DS_MODELNAME		"upnpmodelname"
#define SZF_DEFAULT_VERSION	"/etc.defaults/VERSION"
#define SZD_WEBMAN_LANG_LIST	SZD_TEXTS
#define SZ_STEP			"STEP"
#define MAX_IP_LENGTH		16

#define SYNO_MAXPATH	4095
#define SYNO_MAXNAME	491
#define MAX_PATH_LEN	SYNO_MAXPATH

#define VOL_PREFIX_MAXLEN	16
#define SZD_VOL			"/volume"
#define SZD_VOLX		"/volumeX"
#define SZD_USB_VOL		"/volumeUSB"
#define SZD_SATA_VOL		"/volumeSATA"
#define SZD_TMP			"/tmp"
#define SZD_GLUSTER_VOL	"/volumeGluster"

#define SZF_ATLOG		"/tmp/apple/AT_LOG"
#define SZF_AFPD_CONF_PATH	"/usr/syno/etc/afpd.conf"
#define SZK_MAXDISKS		"maxdisks"
#define SZK_MAX_SYSRAID_DISKS "max_sys_raid_disks"

#define SZK_SUPPORT_DUAL_CHAIN	"support_dual_chain"
#define SZK_SAS_SECOND_CHAIN	"sas_second_chain"
#define SZK_SUPPORT_DUAL_HEAD "support_dual_head"
#define SZK_HOST_WIDE_PORT_COUNT "host_wide_port_count"
#define SZF_TMP_DUALHEAD      "/tmp/.dualhead"
#define SZF_TMP_NOT_DUALHEAD  "/tmp/.not.dualhead"

#define SZF_TMP_SYSTEMDR_RUNNING      "/tmp/.systemdr.running"
#define SZF_TMP_SYSTEMDR_NOT_RUNNING  "/tmp/.systemdr.not.running"

#define SZF_MD_STAT		"/proc/mdstat"
#define SZ_SYSBLOCKS_RAID "/sys/block/md"
#define SZ_RAID_ROOT "/dev/md0"

#define CH_FILE_COMMENT		'#'
#define SZF_BOOT_SEQ		"/tmp/boot_seq.tmp"
#define SZF_PGSQL_UPGRADE_FLAG	"/tmp/.UpgradePGSQLDatabase"

#define SZD_CIFS_RECYCLE_BIN_NAME	"#recycle"

#define SZ_ACLTOOL_OPT_SET_EA_ACL "-set-eadir-acl"
#define SZ_ACLTOOL_OPT_ENFORCE_INHERIT "-enforce-inherit"

#define SZF_NMBLOOKUP	"/usr/bin/nmblookup"

#define SZF_UPDATER_FOR_CONFIG_UPGRADE ".updater"
/**
 * The sector that partition 1 starting from.
 * Duplicated from cvs:sfdisk/synorcvol.c
 */
#define P1OFFSET	63
/**
 * The sectors that partition 1 and partition 2 has.
 * Duplicated from cvs:sfdisk/synorcvol.c
 */
//unit: sectors, 1 sector = 512 bytes, 1 cylinder = 16065 sectors = 8032.5KB, about 7.8M
#define RAID_P1SIZE		1574307	// 98*16065-63, about 768M
#define NRAID_P1SIZE		273042	// 17*16065-63, about 133M
#define P2SIZE			787185	// 49*16065, about 384M
#define RESERVESIZE		273105	// 17*16065, about 133M

#define RAID_SYS_FS_TYPE	0xFD
#define RAID_SWAP_FS_TYPE	0xFD
#define RAID_DATA_FS_TYPE	0xFD
#define NRAID_SYS_FS_TYPE	0x83
#define NRAID_SWAP_FS_TYPE	0x82
#define NRAID_DATA_FS_TYPE	0x83

// The new sector size of partition 1 and 2, since March 2008 (v0583).
#define P1SIZE_V2	4980087	// 310*16065-63, about 2.37G, (2432M/512/16065=310.x)
#define P2SIZE_V2	1044225	//  65*16065, about 510M, (512M/512/16065=65.x)
#define RESERVESIZE_V2	257040	//  16*16065, about 125M, (128M/512/16065=16.x)
// Enlarge SWAP size to 2G since November 2009 (v1030/v1074)
#define P2SIZE_V3	4192965	// 261*16065, about 2G, (2048M/512/16065=261.x)

// Due to the sector size should align to 16KB, please refer bug#12860. Since January 2010 (v1117)
#define P1OFFSET_V7	256	// 8*16K = 128K
#define P1SIZE_V7	4980480	// 155640*16K = 2431.875M
#define P2SIZE_V7	4194304	// 131072*16K = 2048M
#define RESERVESIZE_V7	262144	//   8192*16K = 128M

#define SYNORAID_RESERVE_SIZE    (RAID_P1SIZE + P2SIZE + RESERVESIZE + P1OFFSET)
#define SYNORAID_RESERVE_SIZE_V2 (P1SIZE_V2 + P2SIZE_V2 + RESERVESIZE_V2 + P1OFFSET)
#define SYNORAID_RESERVE_SIZE_V6 (P1SIZE_V2 + P2SIZE_V3 + RESERVESIZE_V2 + P1OFFSET)
#define SYNORAID_RESERVE_SIZE_V7 (P1SIZE_V7 + P2SIZE_V7 + RESERVESIZE_V7 + P1OFFSET_V7)
#define SYNORAID_RESERVE_SIZE_V8 (P1SIZE_V8 + P2SIZE_V8 + RESERVESIZE_V8 + P1OFFSET_V8)

// NRAID_P1SIZE has been not enough, so use RESERVESIZE since July 2008 (v0685)
#define NRAID_P1SIZE_V3		530082	// 33*16065-63, about 258M, NRAID_P1SIZE + RESERVESIZE - 16065
#define RESERVESIZE_V3		16002	// 16065 - 63

// NRAID_P1SIZE_V3 has been not enough, so borrow 12 cylinders from P2SIZE since May 2009 (v0879)
#define NRAID_P1SIZE_V5		722862	// 45*16065-63, about 353M, NRAID_P1SIZE_V3 + 12*16065
#define NRAID_P2SIZE_V5		594405	// 37*16065, about 298M, P2SIZE - 12*16065

//to support native 4K disk
#define P1OFFSET_V8 2048 // 1M
#define P1SIZE_V8 P1SIZE_V7
#define P2SIZE_V8 P2SIZE_V7
#define RESERVESIZE_V8 260352 // RESERVESIZE_V7 - (2048 - 256)

//eMMC boot partition config
#define SZ_EMMC_DEV_NAME "sda"

#define EMMC_SYS_PART_SIZE_V7 2097152ULL
#define EMMC_VOL_PART_SIZE_V7 5105569ULL
#define EMMC_PAT_PART_SIZE_V7 524288ULL

#define EMMC_SYS_PART_OFFSET_V7 256ULL
#define EMMC_VOL_PART_OFFSET_V7 2097408ULL
#define EMMC_PAT_PART_OFFSET_V7 7202977ULL

#define EMMC_PART_COUNT 3

// UPnP M-Search source port range
#define PORT_UPNP_MSEARCH_LOW	55900
#define PORT_UPNP_MSEARCH_HIGH	55910

#define BZERO_STRUCT(p) bzero(&p, sizeof(p))
#define BZERO_POINTER(p) bzero(p, sizeof(p))
#define StrCP(A, B) snprintf(A, sizeof(A), "%s", B)
#define StrnCP(A, B, C) snprintf(A, B, "%s", C)
#define StrfCP(A, F, ...) snprintf(A, sizeof(A), F, ##__VA_ARGS__)
#define EACH_ELEMENT(el) for (; el; el = el->pNext)
#define EACH_LIST_MEMBER(lists, idx) for (idx = 0; lists && (idx < lists->nItem); idx++)

#define SECTORS_TO_BYTES(sector) (sector << 9)

#define MAX_LEN_VOL_PATH	64
#define MAX_LEN_ISCSITRG_NAME   256
#define MAX_LEN_ISCSI_NAME      256

#define SYNORAID_PART_MBR_RESERVE	16065	// for cylinder boundary.
#define SYNORAID_PART_RESERVE	16096	// for 16k boundary.

//endian
#define SZD_BIG_ENDIAN 		"big"
#define SZD_LITTLE_ENDIAN 	"little"
#define SZ_SYS_ENDIAN 		"endian"
#define SZ_SYS_PGSQL_ALIGN "pgsql_alignment"
#define SZ_SYS_BITS 		"bits"

//If you change the following value, remember to change /etc/rc.
#define SZF_ORG_PATCH_DIR 	"/.old_patch_info"
#define SZD_SYSTEM_INFO 	"/.system_info"

// Used to know the platform information before migration
#define SZF_ENDIAN 		SZD_SYSTEM_INFO "/" SZ_SYS_ENDIAN
#define SZF_PGSQL_ALIGN SZD_SYSTEM_INFO "/" SZ_SYS_PGSQL_ALIGN
#define SZF_BITS 		SZD_SYSTEM_INFO "/" SZ_SYS_BITS

#define SZF_ORG_SYNOINFO 	SZF_ORG_PATCH_DIR"/synoinfo.conf"

typedef enum _tag_endian_type_{
	ENDIAN_TYPE_BIG=1,
	ENDIAN_TYPE_LITTLE,
}ENDIAN_TYPE;

/**
 * Created Partition Layouts by Synology
 */
typedef enum _tag_PARTITION_LAYOUT_VERSION {
	PARTITITON_LAYOUT_ERR = 0,
	/**
	 * - NRAID_P1SIZE P2SIZE NRAID_P1SIZE DATA	// the RESERVESIZE misused by NRAID_P1SIZE
	 * - RAID_P1SIZE P2SIZE RESERVESIZE DATA
	 */
	PARTITITON_LAYOUT_V1,
	/**
	 * both: P1SIZE_V2 P2SIZE_V2 RESERVESIZE_V2 DATA
	 */
	PARTITITON_LAYOUT_V2,
	/**
	 * NRAID_P1SIZE_V3 P2SIZE RESERVESIZE_V3 DATA
	 */
	PARTITITON_LAYOUT_V3,
	/**
	 * NRAID_P1SIZE P2SIZE DATA	// PARTITITON_LAYOUT_V1 without RESERVESIZE
	 *
	 * NOT a formal type, only used in juniorinstaller/synopartition.c
	 */
	PARTITITON_LAYOUT_V4,
	/**
	 * NRAID_P1SIZE_V5 NRAID_P2SIZE_V5 RESERVESIZE_V3 DATA
	 */
	PARTITITON_LAYOUT_V5,
	/**
	 * both: P1SIZE_V2 P2SIZE_V3 RESERVESIZE_V2 DATA
	 *
	 * Depend on PARTITITON_LAYOUT_V2 and change P2SIZE_V2 to P2SIZE_V3
	 */
	PARTITITON_LAYOUT_V6,
	/**
	 * both: P1OFFSET_V7 P1SIZE_V7 P2SIZE_V7 RESERVESIZE_V7 DATA
	 *
	 * Due to the partition size should align to 16KB. Please refer bug#12860.
	 */
	PARTITITON_LAYOUT_V7,
	/**
	 * P1OFFSET_V8 P1SIZE_V8 P2SIZE_V8 RESERVESIZE_V8 DATA 
	 *  
	 * in order to support native 4K disk 
	 */
	PARTITITON_LAYOUT_V8,
	/**
	 * Current Layout Version, usually the maximum version.
	 */
	PARTITITON_LAYOUT_CURR = PARTITITON_LAYOUT_V8
} PARTITITON_LAYOUT_VERSION;

#ifdef BUFSIZ
#undef BUFSIZ
#endif
#define BUFSIZ	1024
#define BUF_LENGTH	256

#ifdef  __USE_MISC
	#define st_ctimensec	st_ctim.tv_nsec
	#define st_atimensec	st_atim.tv_nsec
#endif

typedef enum _tag_vol_location_{
	DEV_LOC_INTERNAL=0x01,
	DEV_LOC_EBOX=0x02, //Expansion Box
	DEV_LOC_USB=0x04,
	DEV_LOC_SATA=0x08,
	DEV_LOC_TMPFS=0x10,
	DEV_LOC_SSDCACHE=0x20,
	DEV_LOC_GLUSTERFS=0x40,
} DEV_LOCATION;

typedef enum _space_container_type_ {
	SPACE_CROSS_EBOX=0x01,
	SPACE_INTERNAL=0x02, 
	SPACE_EBOX=0x04,
	SPACE_UNDEFINED=0x08,  //undefined type for USB/SATA, those device is not belongs to space now.
} SPACE_CONTAINER_TYPE;

typedef enum _tag_volume_info_option_ {
	INCLUDE_GLUSTERFS_USED=0x01
} VOLUME_INFO_OPTION;

typedef enum _tag_dev_type_{
	DEV_TYPE_RAID = 1,
	DEV_TYPE_LVM_VG,
}DEV_TYPE;

/**
 * Gets the offset that between the struct field @p field pointers to and
 * the struct @p pointer.
 */
#define STRUCT_OFFSET_GET(pointer, field) (((size_t)(pointer->field)) - ((size_t)(pointer)));

/**
 * Sets the field name @p field of this struct @p pointer to the offset @p
 * offset from struct @p pointer.
 */
#define STRUCT_OFFSET_SET(pointer, field, offset) (((pointer->field)) = (void *)((size_t)(pointer)) + (offset));

#define SYNO_DB_STRUCT_SET(dst_db, src_mem, field) do { 				\
	dst_db->off##field = STRUCT_OFFSET_GET(src_mem, field);	\
} while (0)
#define SYNO_DB_STRUCT_GET(dst_mem, src_db, field) do { 				\
	STRUCT_OFFSET_SET(dst_mem, field, src_db->off##field); \
} while (0)

/**
 * Converts Marco Value or Constants to C String literal.  Uses TO_STR() to
 * expand Marco Value as Constants.
 * @see TO_STR()
 */
#define SYNO_STRING(s) TO_STR(s)

/**
 * Converts Marco Name or Constants to C String literal.
 * @see SYNO_STRING()
 */
#define TO_STR(s) #s

#include <syslog.h>
/**
 * Generates a log message with file and line information ("%s:%d"),
 * which will be distributed by syslogd(8).  The @p priority argument is
 * formed by ORing the facility and the level values (explained below).
 * The remaining arguments are @p format, as in printf(3) and any
 * arguments required by the format, except that the two character
 * sequence @c %m will be replaced by the error message string
 * strerror(errno).  A trailing newline is added when
 * needed.
 *
 * @param[in]   priority    The interger that is formed by ORing the facility and the level values:
 *                          - **facility**: The facility argument is used to specify what type of program is logging the message. The values are:
 *                              - LOG_AUTHPRIV
 *                              - LOG_CRON
 *                              - LOG_DAEMON
 *                              - LOG_FTP
 *                              - LOG_KERN,
 *                              - LOG_LOCAL0 ~ LOG_LOCAL7
 *                              - LOG_LPR
 *                              - LOG_MAIL
 *                              - LOG_NEWS
 *                              - LOG_SYSLOG,
 *                              - LOG_USER (default)
 *                              - LOG_UUCP
 *                          - **level**: This determines the importance of the message. The levels are, in order of decreasing importance:
 *                              - LOG_EMERG
 *                              - LOG_ALERT
 *                              - LOG_CRIT
 *                              - LOG_ERR
 *                              - LOG_WARNING
 *                              - LOG_NOTICE
 *                              - LOG_INFO
 *                              - LOG_DEBUG
 * @param[in]   format      The string that is the produced log output format.
 *                          In this macro, file and line infomation will append to the prefix of
 *                          format automatically.  Caller should **AVOID** appending file and
 *                          line information manully.
 *
 * @return no return
 *
 * @see syslog(3)
 */
#define SYSLOG(priority, format, ...) syslog(priority, "%s:%d " format, __FILE__, __LINE__, ## __VA_ARGS__)

#define _SDK_CKARGS1(es, l, e) do { 					\
if (!(e)) { 								\
	SYSLOG(LOG_ERR, "Invaild Argument (%s)=[%d]\n", #e, e); 	\
	SLIBCErrSet(ERR_BAD_PARAMETERS);					\
	return es; 							\
} } while(0)
#define _SDK_CKARGS2(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS1(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS3(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS2(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS4(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS3(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS5(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS4(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS6(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS5(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS7(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS6(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS8(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS7(es, l, ##__VA_ARGS__)
#define _SDK_CKARGS9(es, l, e, ... ) _SDK_CKARGS1(es, l, e); _SDK_CKARGS8(es, l, ##__VA_ARGS__)

/**
 * Checks @p nr arguments, from expr1 to expr##nr, and log when
 * check failed.  When check failed, this macro will cause the
 * function return immediately.
 *
 * @param[in] nr The number of expressions to be checked.  From
 *  		 1 to 9 now.  Should be numeric literal, can not be
 *  		 varialbe.
 * @param[in] exit_stat The statments to be executed when check
 *                  expression failed. For example, return 0;
 * @param[in] expr1 The first expression to be checked.
 *
 * @return no return
 */
#define SYNOSDK_CHECK_ARGS(nr, exit_stmt, expr1, ... ) _SDK_CKARGS##nr(exit_stmt, pLog, expr1, ##__VA_ARGS__)

/**
 * @}
 */

/**
 * used to define at usb.h, move to synoglobal.h for usbipd
 * usage.
 */
enum{
	USB_DEV_UNKNOWN=0x0001,
	USB_DEV_DISK=0x0002,
	USB_DEV_PRINTER=0x0004,
	USB_DEV_USBIP=0x0008,
	ESATA_DEV_DISK=0x0010,
	USB_DEV_USED=0x8000,
};

#ifdef __compiler_offsetof
#define OFFSET_OF(type, member) __compiler_offsetof(type, member)
#else
#define OFFSET_OF(type, member) ((size_t) &((type*)0)->member)
#endif

#endif // __SYNO_GLOBAL_H__

#define SZ_BOND                            "bond"
#define SZ_IF_PREFIX                               "eth"
#define SYNO_IFNAME_MAX 16

#define CB_SZ_IP_MAX 20
#define CB_SZ_IPv6 46

/*serial number*/
#define MAX_MTD_SN_SIZE 32  //max lengh of SN size in MTD
#define MAX_SN_SIZE 36  //this lengh is including '\0' of SN, for array size we needn't +1
#define CUSTOM_SN_LENGH 31

/**
 * @}
 */
