// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNOUSBCOPY_USBCOPY_H__
#define __SYNOUSBCOPY_USBCOPY_H__

#include <sys/cdefs.h>

#include <synosdk/share.h>
#include <synousb/usb.h>
#include <synosdk/volume.h>
#include <synofileop/ea.h>

__BEGIN_DECLS;

#define SZD_UNKNOWN_DEVICE      "ExternalDevice"
#define SZD_SDCOPY		"SDCopy"
#define SZD_USBCOPY		"USBCopy"
#define SZ_SDCOPY		"SD Copy"
#define SZ_USBCOPY		"USB Copy"

/** Used as key in SZF_USB_DISKAPPLYING to indicate which USB device attached to front port */
#define SZK_SDCOPYDEV       "sdcopydev"
#define SZK_SDCOPYPATH      "sdcopypath"
#define SZK_USBCOPYDEV		"usbcopydev" 
#define SZK_USBCOPYPATH		"usbcopypath" 
#define SZ_USBCOPY_COMMAND		"/usr/syno/bin/synousbcopy"
/** The port location that supported USB Copy (moved to syno.h in kernel)*/
/*#define USBCOPY_PORT_LOCATION		3*/
/** The limit of partition size for USBCopy Spec, FAT16 2G in MB */
#define USBCOPY_FS_LIMIT		( (size_t) 2048 )
/** The keyword will be update in SZF_USB_DISKAPPLYING to indicate Web UI that
 front port USB device is doing USBCopy */
#define	SZV_USB_USBCOPY			"usbcopy"
#define SZK_EMPTY_FOLDER_DEFAULT	""
#define SZK_SDCOPY_FOLDER			"sdcopyfolder"
#define SZK_USBCOPY_FOLDER			"usbcopyfolder"
#define SZK_SDCOPY_FOLDER_DEFAULT	"public"
#define SZK_USBCOPY_FOLDER_DEFAULT	"public"
#define SZF_USBCOPY_PIDFILE		"/var/run/synousbcopy.pid"

#define	SZK_USBCOPY			"usbcopy"
#define	SZK_SDCOPY			"sdcopy"

typedef enum _USB_DEVICE_TYPE_ {
	USB_DEVICE_UNKNOWN,
	USB_DEVICE_FLASH_DISK,
	USB_DEVICE_SD_CARD,
} USB_DEVICE_TYPE;

#include <synousbcopy/usbcopy_p.h>

__END_DECLS;
#endif //__SYNOUSBCOPY_USBCOPY_H__
