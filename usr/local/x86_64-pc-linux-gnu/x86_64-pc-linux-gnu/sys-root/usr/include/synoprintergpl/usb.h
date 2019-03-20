// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNOPRINTERGPL_USB_H__
#define __SYNOPRINTERGPL_USB_H__

#include <linux/syno.h>

#include <sys/cdefs.h>
#include <sys/types.h>
#include <synocore/error.h>
#include <synocore/file.h>
#include <synocore/list.h>
#include <synosdk/volume.h>

__BEGIN_DECLS;

#define SZF_USBIP_USB_DEV_CONF      "/usr/syno/etc/usbdev.conf"
#define SZF_USBIP_BIND_DRIVER       "/usr/bin/bind_driver"
#define SZF_USB_MAP                 "/tmp/usbtab"

#define SZ_PREFIX_PRINTER    "lp"
#define SZ_USBIP_PRINTER     "ip"

//define key value in /usr/syno/etc/usbdev.conf
#define SZK_USBIP_USB_STATUS                "status"
#define SZK_USBIP_USB_INTERFACE_PREFIX      "interface_"
#define SZK_USBIP_USB_GUID_PREFIX           "guid_"
#define SZK_USBIP_USB_INTERFACE_NUMBER      "interface_number"
#define SZK_USBIP_USB_BUS_NUMBER            "bus number"
#define SZK_USBIP_USB_DEV_NODE              "devnode"
#define SZK_USBIP_USB_PROC_DEVICE           "proc_dev"
#define SZK_USBIP_USB_USBTAB_KEY            "usbtab_key"

//value of SZK_USBIP_USB_STATUS
#define SZV_USBIP_USB_STATUS_PLUG_IN        "plug_in"
#define SZV_USBIP_USB_STATUS_USBIP_INIT     "usbip_init"
#define SZV_USBIP_USB_STATUS_USBIP_HANDLE   "usbip_handle"
#define SZV_USBIP_USB_STATUS_PLUG_OUT       "plug_out"
#define SZV_USBIP_USB_STATUS_AP_HANDLE      "ap_handle"

#define SZV_USBIP_USB_INTERFACE_STATUS_ADD  "add"

//USBIP AP pipe special name
#define SZV_USBIP_AP_PIPE_NAME              "USBIP"

#define SZF_USBDEV_CONF_LOCK                SZ_LOCK_DIR "lock_usbdev"

#ifndef NO_PROTO
#include <synoprintergpl/usb_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif /* __SYNOPRINTERGPL_USB_H__ */
