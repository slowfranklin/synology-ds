// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNOPRINTER_PRINTER_H__
#define __SYNOPRINTER_PRINTER_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <synousb/usb.h>
#include <synoprintergpl/printer.h>

__BEGIN_DECLS;

typedef struct _SYNOGCP_INFO {
	char szGoogleAccount[255]; // In IETF email address size limit is 254
	char szGooglePass[128]; //FIXME deprecated for OAuth
	char szGoogleRefreshToken[256];
} SYNOGCP_INFO, *PSYNOGCP_INFO;

typedef struct _SYNO_NETPRINTER_INFO {
	char szIP[MAX_IP_LENGTH];
	char szBackend[BUFSIZ];
	char szQName[BUFSIZ];
	char szBrand[BUFSIZ];
	char szModel[BUFSIZ];
	char szStringId[BUFSIZ];
} SYNO_NETPRINTER_INFO, *PSYNO_NETPRINTER_INFO;

typedef enum _tag_type_printer {
	TYPE_NONE = 0x00,
	TYPE_USB_PRINTER = 0x01,
	TYPE_NET_PRINTER = 0x02,
} TYPE_PRINTER;

// Network printer
#define SZ_NETPRINTER_UNINSTALL     "uninstall_np"
#define SZ_NETPRINTER               "networkprinter"
#define SZV_NETPRINTER_MODE         "netPrinter"
#define CUPS_BACKEND_LPD            "lpd"
#define CUPS_BACKEND_IPP            "ipp"
#define CUPS_BACKEND_SOCKET         "socket"
#define CUPS_BACKEND_BJNP           "bjnp"

#define SZD_SPOOL                   "/var/services/printer"
#define SZV_LPR                     "lpr"
#define SZV_LPR_FAVOR               "favor_lpr"
#define SZ_BIND_DRIVER_COMMAND      "/usr/bin/bind_driver"
#define SZ_USBIP_PRINTERID_FORMAT   SZ_USB_DEVICEID_FORMAT
#define SZ_USBPRINTER_NEW_NAME      "usbprinter1"
#define SZ_USBPRINTER_OLD_NAME      "usbprinter"
#define SZ_USBLP_INSTALL            "install"
#define SZ_USBLP_UNINSTALL          "uninstall"

// CUPS system V related command
#define SZF_PRINTERCMD_LPADMIN      "/usr/bin/lpadmin"
#define SZF_PRINTERCMD_LPSTAT       "/usr/bin/lpstat"
#define SZF_PRINTERCMD_LPC          "/usr/bin/lpc"
#define SZF_PRINTERCMD_LPQ          "/usr/bin/lpq"
#define SZF_PRINTERCMD_LPR          "/usr/bin/lpr"
#define SZF_PRINTERCMD_LPRM         "/usr/bin/lprm"
#define SZF_PRINTERCMD_LPOPTIONS    "/usr/bin/lpoptions"
#define SZF_PRINTERCMD_CUPS_DISABLE "/usr/bin/cupsdisable"
#define SZF_PRINTERCMD_CUPS_ENABLE  "/usr/bin/cupsenable"
#define SZD_CUPS_PATH_PPD           "/etc/cups/ppd/"
#define SZF_CUPS_PRINTER_CONFIG     "/etc/cups/printers.conf"
#define SZF_CUPS_LPOPTIONS          "/etc/cups/lpoptions"

//printer.conf
#define SZK_USBLP_CUPS_PRINTER_NAME "cups printer name"
#define SZK_USBLP_GOOLGE_CLOUD_PRINTER_ID "google cloud printer id"

//Cloud Print Section
#define SZK_GOOGLE_CLOUD_PRINT_SECTION       "Google Cloud Print"
#define SZK_USBLP_GOOGLE_CLOUD_ACCOUNT       "google account"
#define SZK_USBLP_GOOGLE_CLOUD_PASS          "google pass"
#define SZK_USBLP_GOOGLE_CLOUD_REFRESH_TOKEN "refresh token"

//define ieee1284 record
// Ref: http://www.undocprint.org/formats/communication_protocols/ieee_1284
#define SZK_PRINTER_1284_CMD   "CMD:"
#define SZK_PRINTER_1284_DES   "DES:"
#define SZK_PRINTER_1284_MFG   "MFG:"
#define SZK_PRINTER_1284_MFR   "MFR:"
#define SZK_PRINTER_1284_MDL   "MDL:"

#define SZK_PRINTER_1284_COMMAND_SET    "COMMAND SET:"
#define SZK_PRINTER_1284_DESCRIPTION    "DESCRIPTION:"
#define SZK_PRINTER_1284_MANUFACTURER   "MANUFACTURER:"
#define SZK_PRINTER_1284_MODEL          "MODEL:"

#define INT_MAX_RETRY_TIMES 10
#define CUPS_CMD_RETRY      3

#define SZF_PRINTER_CONF_LOCK                SZ_LOCK_DIR "lock_printer"

#ifndef NO_PROTO
#include <synoprinter/printer_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOPRINTER_PRINTER_H__
