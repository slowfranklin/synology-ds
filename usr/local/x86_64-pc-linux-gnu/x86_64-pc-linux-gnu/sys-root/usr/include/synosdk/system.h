#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */

#ifndef __SYNO_SYS_H__
#define __SYNO_SYS_H__

#include <sys/cdefs.h>

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <time.h>

__BEGIN_DECLS;

/**
 * @addtogroup SYSTEM
 *
 * @brief The structure and operation of System.
 *
 * @{
 */

typedef struct {
	unsigned long totalKB;
	unsigned long freeKB;
	unsigned long buffersKB;
	unsigned long cachedKB;
} MEM_INFO;

typedef struct {
	int kernel_version;
	int patch_level;
	int sub_level;
	int syno_version;
	char szArch[16];
} KERNEL_INFO;

typedef unsigned char SLIB_VENDER_MAC_ADDR[6];

#define SZ_MEM_INFO	"/proc/meminfo"

#define MAX_PARTITION 9
#define MAX_PATCH_FILES 32

#define SZ_TMP_ROOT			"/tmpRoot"
#define SZF_SYNO_IMAGE_BACKUP	"/.syno/patch"

/**
 * partition names
 */
#define SZ_REDBOOT "RedBoot"
#define SZ_ZIMAGE "zImage"
#define SZ_RD_GZ  "rd.gz"
#define SZ_ALLLIB_TGZ "AllLib.tgz"
#define SZ_VENDOR "vendor"
#define SZ_GRUB_CKSUM "grub_cksum.syno"
#define SZ_BOOT_CKSUM "boot_cksum.syno"
#define SZ_BLUECORE "bluecore"
#define SZ_BOOT_LOGO   "BootLogo.bmp"
#define SZ_REDBOOT_CFG "RedBoot Config"
#define SZ_FIS_DIRECTORY "FIS Directory"
#define SZ_UBIFS_ROOT "ubi0:rootfs"
#define SZ_UBIFS_PATCH "ubi0:patch"
#define SZ_UBIFS_VOLUME "ubi0:volume1"
#define SZ_EMMC_PATCH "/dev/sda4"

/**
 * Name of the scripts that do the uBoot Update check.
 * This must be identical to "UBootUpdScriptName" macro
 * in lnxscripts/SynoModel
 */
#define SZF_REDBOOT_UPD_SCRIPT "uboot_do_upd.sh"

/** name of the new patch file */
#define SZF_REDBOOT "RedBoot.msys"
#define SZF_UPDATER "updater"
#define SZF_ZIMAGE "zImage"
#define SZF_VERSION "VERSION"
#define SZF_BLUECORE "bluecore.audio"
#define SZF_GRUB_VERSION "GRUB_VER"
#define SZ_GRUB_VERSION "GRUB_VERSION"
#define SZF_CKSUM "checksum.syno"
#define SZF_SYNOSIG "Synology.sig"
#if defined(MY_ABC_HERE)
	#define SZF_RD_GZ   "rd.gz"
	#define SZF_VENDOR "vender"
	#define SZF_GRUB_CKSUM  "grub_cksum.syno"
	#define SZF_BIOS		"bios.ROM"
#else
	#define SZF_RD_GZ  "rd.bin"
	#define SZF_VENDOR "vendor"
	#define SZF_BOOT_CKSUM  "boot_cksum.syno"
	#define SZF_BOOT_LOGO   "BootLogo.bmp"
#endif
#define SZF_ALLLIB_TGZ "AllLib.tgz"
#define SZF_REDBOOT_CFG "RedBoot Config"
#define SZF_DTB_BIN "dtb.bin"
#define SZF_FIS_DIRECTORY "FIS Directory"
#define SZF_JUNIOR_PAT_TAR_GZ	"hda1.tgz"
#define SZF_SYNOUPGRADE_TAR_GZ	"SynoUpgrade.tar.gz"
#define SZF_SYNOUPGRADE_TAR	"SynoUpgrade.tar"
#define SZF_INDEX_DB "indexdb.txz"
#define SZF_SYNOHDPACK_IMG "synohdpack_img.txz"
#define SZF_PACKAGES_FOLDER "packages"

#define LENGTH_MAX_DEVICE_NAME  16

#define SZF_PROC_MODULES "/proc/modules"
#define SZF_MODULES_PATH    "/lib/modules"
#define SZF_X_TABLES        "x_tables.ko"
#define SZF_IP_TABLES       "ip_tables.ko"
#define SZF_IPTABLE_FILTER  "iptable_filter.ko"
#define SZF_XT_MAC          "xt_mac.ko"
#define SZF_XT_TCPUDP		"xt_tcpudp.ko"
#define SZF_SBIN_IPTABLES   "/sbin/iptables"
#define SZ_MODULE_X_TABLES  "x_tables"
#define SZ_MODULE_IP_TABLES "ip_tables"
#define SZ_MODULE_IPTABLE_FILTER    "iptable_filter"
#define SZ_MODULE_XT_MAC    "xt_mac"
#define SZ_MODULE_XT_TCPUDP	"xt_tcpudp"

#define SZF_INSMOD          "/sbin/insmod"
#define SZF_RMMOD           "/sbin/rmmod"

#define SZF_SWAPACTION "/usr/syno/bin/swapaction"
#define SZF_UPGRADE_DSM_LOCK "/tmp/upgdsmlock"

#define SZF_SPACE_BUSY "/run/synostorage/space_busy"

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/system_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif /* __SYNO_SYS_H__ */
