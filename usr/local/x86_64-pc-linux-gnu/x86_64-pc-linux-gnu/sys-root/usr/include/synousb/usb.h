// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_USB_H__
#define __SYNO_USB_H__

#include <linux/syno.h>

#include <sys/cdefs.h>
#include <sys/types.h>
#include <synocore/error.h>
#include <synocore/file.h>
#include <synocore/list.h>

__BEGIN_DECLS;

#define MAX_USB_INFO_LEN	128
typedef struct _tag_SYNO_USB1_ {
	long	dev_type;
	long	busnum;
	long	level;
	long	devnum;
	long	speed;
	long	classid;
	long	subid;
	long	port;
	long    Vendor;
	long    ProdID;
	long	infCount;
	char szDriver[MAX_USB_INFO_LEN];
	char szManufacturer[MAX_USB_INFO_LEN];
	char szProductName[MAX_USB_INFO_LEN];
	char szSerialNumber[MAX_USB_INFO_LEN];
	char szUsbId[MAX_USB_INFO_LEN];
	char szRevision[MAX_USB_INFO_LEN];
} SYNOUSB1, *PSYNOUSB1;

#define SZ_USB_DEVICEID_FORMAT   "%04lx:%04lx:%s"

#define USB_MAJOR			180 //in linux/usb.h
#define SZF_USB_DEVICE	"/proc/bus/usb/devices"
#define SZF_USB_MAP		"/tmp/usbtab"
#define SZF_SATA_MAP "/tmp/satatab"
#define SZF_USB_IDMAP	"/usr/syno/etc.defaults/usb.map"
#define SZF_USB_MISC_INFO	"/usr/syno/etc/usb.info"
#define SZF_RDX_TOOL	"/lib/udev/script/rdx_util.sh"
#define SZK_DEVICE_NAME_LENG 32

#define SZ_PREFIX_PRINTER 	"lp"
#define SZ_SAS_PREFIX_DISK	"usb"
#define SZ_PREFIX_DISK		"sd"
#define SZ_USBIP_PRINTER	"ip"
#define SZ_PREFIX_SDCARD        "mmc"
#define IS_SYNO_FLASH(VENDOR, PROD) ((0xf400 == VENDOR && 0xf400 == PROD) || (0xf401 == VENDOR && 0xf401 == PROD))

#define SZ_CARDREADER_PATH "/tmp/cardreader"
#define SZ_CARDREADER_SYSFS_PATH "/sys"

#include <synousb/usb_p.h>

__END_DECLS;
#endif /* __SYNO_USB_H__ */
