// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNOPRINTERGPL_PRINTER_H__
#define __SYNOPRINTERGPL_PRINTER_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>

__BEGIN_DECLS;

typedef struct _tag_SYNO_USBIP_ {
	char	szManual_timer[4];
	char	szAuto_timer[4];
	char	szMode[128];
	char	szPrinterID[128];
	char	szProducer[128];
	char	szProductName[128];
	char	szStatus[128];
	char	szAirPrint[8];
	char	szGoogleCloudPrint[8];
	char	szBrandName[128];
	char	szDriverName[128];
	char	szUsblpPrinterStringId[1024];
	char	szMFG[128];
	char	szMDL[128];
	char	szFitToPage[8];
} SYNOUSBIP, *PSYNOUSBIP;

typedef struct _SYNO_NETPRINTER_CONF {
	char szIP[MAX_IP_LENGTH];
	char szPrinterName[128];
	char szProtocol[128];
	char szQName[128];
	char	szMFG[128];
	char	szMDL[128];
	char	szAirPrint[8];
	char	szGCP[8];
	char szGCPAccount[1024];
	char szGCPPassword[1024];
	char	szDriverBrand[128];
	char	szDriverModel[128];
	char	szPrinterStringId[1024];
	char	szPrinterID[128];
	char	szFitToPage[8];
} SYNO_NETPRINTER_CONF, *PSYNO_NETPRINTER_CONF;

#define SZ_SERVICE_CUPSD "cupsd"
#define SZ_SERVICE_GCPD  "gcpd"

// Network printer
#define SZ_NETPRINTER_ID_FORMAT   "%s-%s"
#define SZK_NETPRINTER_BACKEND    "Backend"
#define SZK_NETPRINTER_QNAME      "QName"
#define SZK_NETPRINTER_CUPS_NAME  "cups printer name"
#define SZV_USBIP                 "usbip"
#define SZV_ATIMER                "60"
#define SZV_MTIMER                "300"
#define SZ_USBPRINTER_PREFIX      "usbprinter"
#define USBPRINTER_PREFIX_LEN     10
#define SZK_PRINTER_FIT_TO_PAGE   "fit to page"

// CUPS system V related command
#define SZF_PRINTERCMD_LPSTAT     "/usr/bin/lpstat"
#define SZF_CUPS_PATH_USB_DEV     "usb:/dev/usb/"

//printer.conf
#define SZF_USBIP_PRINTER_CONF        "/usr/syno/etc/printer.conf"
#define SZK_USBIP_PRINTER_PRODUCER    "producer"
#define SZK_USBIP_PRINTER_PRODUCTNAME "product name"
#define SZK_USBIP_PRINTER_MODE        "mode"
#define SZK_USBIP_PRINTER_ATIMER      "autolock timer"
#define SZK_USBIP_PRINTER_MTIMER      "manuallock timer"
#define SZK_USBLP_AIRPRINT_ENABLE     "enable airprint"
#define SZK_USBLP_BRAND_NAME          "driver brand"
#define SZK_USBLP_DRIVER_NAME         "driver"
#define SZK_USBLP_STRING_ID           "usblp string id"

#define SZK_USBLP_GOOGLE_CLOUD_PRINT_ENABLE "enable google cloud print"

//network printer
#define SZK_NETPRINTER_IP              "IP"
#define SZK_NETPRINTER_BRAND           "Brand"
#define SZK_NETPRINTER_MODEL           "Model"
#define SZK_NETPRINTER_STRINGID        "string id"
#define SZK_NETPRINTER_AIRPRINT_ENABLE "enable airprint"
#define SZK_NETPRINTER_GCP_ENABLE      "enable google cloud print"
#define SZK_NETPRINTER_DRIVER_BRAND    "driver brand"
#define SZK_NETPRINTER_DRIVER_MODEL    "driver"

#define MAX_PRINTER_SUPPORT  2
#define SZF_MFP_PID_FILE     "/var/run/usbipd.pid"

//MFP status file
/**
 * For bug 15410, implement new printer status file at location /tmp/printer_status, the key
 * is printer id, value is the status of corresponded printer.
 * Printer has 6 status, they should used with define "SYNO_PRINTER_EJECT_RELEASE_CHANGEMODE_15410" that defined in 
 * usbip synodef.h: 
 * 1.lock-IP => means a IP lock this printer, IP is of IPv4 format 
 * 2.SZV_PRINTER_STATUS_REMOVING_LOCK => removing lock, SZ_MFP_DAEMON_NAME still need to close related sockets to finish whole task.
 * 3.SZV_PRINTER_STATUS_EJECT_PROCESSING => ejecting printer, SZ_MFP_DAEMON_NAME still need to close related sockets to finish whole task.
 * 4.SZV_PRINTER_STATUS_EJECT_DONE => SZ_MFP_DAEMON_NAME has finished socket close process and printer is ejected successfully.
 * 5.SZV_PRINTER_STATUS_CHANGING_MODE => changing mode from usbip to lpr, SZ_MFP_DAEMON_NAME still need to close related sockets to finish whole task.
 * 6.SZV_PRINTER_STATUS_FREE => printer is free for using
 */ 
#define SZF_USBIP_STATUS_FILE_PREFIX	"/tmp/usbip_"

#define SZK_USBIP_STATUS_LOCK   "LOCK"
#define SZK_USBIP_STATUS_QUEUE  "QUEUE"

#define SZK_USBIP_OCCUPIED      "Occupied by"

#define SZV_PRINTER_STATUS_FREE "Free"

#ifndef NO_PROTO
#include <synoprintergpl/printer_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOPRINTERGPL_H__
