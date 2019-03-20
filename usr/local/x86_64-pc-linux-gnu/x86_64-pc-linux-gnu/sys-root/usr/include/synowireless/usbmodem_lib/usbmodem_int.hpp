/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_USBMODEM_INT_HPP_
#define _SYNO_WIRELESS_USBMODEM_INT_HPP_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <csignal> //SIGTERM
#include <cmath> //ceil
#include <fstream>
#include <map>

extern "C" {
// define for libsynosdk function
#include <synocore/file.h>
#include <synocore/error.h>
#include <synocore/proc.h>

// define for modem cmd
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
}

//define else header for cpp
#include <iostream>
#include <sstream>

// define file and path
#define SZF_WVDIAL_BINARY					"/usr/bin/wvdial"
#define SZD_USBMODEM_CONF					"/var/lib/usbmodem"
#define SZF_USBMODEM_CONF					SZD_USBMODEM_CONF"/usbmodem.conf."
#define SZF_USBMODEM_PIDFILE				"/tmp/usbmodem.pid."
#define SZF_USBMODEM_PROFILE				SZD_USBMODEM_CONF"/usbmodem.profile."
#define SZF_USBMODEM_PPP_WVDIAL				"/etc/ppp/peers/wvdial"

#define SZF_APN_LIST_FILE					"/usr/share/usbmodem/wcdma_list.json"

// Key for device info
#define USBMODEM_KEY_IFID					"InterfaceID"
#define USBMODEM_KEY_QUARYUSBNODE			"QuaryUSB"
#define USBMODEM_KEY_CONNECTUSBNODE			"ConnectUSB"
#define USBMODEM_KEY_PIN_VERIFIED			"PINVerified"
#define USBMODEM_KEY_ISCONNECTED			"isConnected"

// define for device node
#define USBMODEM_GETDEVNODE_MAXATTEMPT		3
#define USBMODEM_READCOUNT_MAX				512

// KEY for SIM info
#define USBMODEM_KEY_PIDFILE				"PidFile"

// usbmodem data key
#define SZ_USBMODEM_DATA_KEY_PRODUCT			"product"
#define SZ_USBMODEM_DATA_KEY_VENDOR				"vendor"
#define SZ_USBMODEM_DATA_KEY_SIGNAL				"signal"
#define SZ_USBMODEM_DATA_KEY_CARRIER			"carrier"
#define SZ_USBMODEM_DATA_KEY_SIM_STATUS			"sim_status"
#define SZ_USBMODEM_DATA_KEY_PIN_PROTECTED		"pin_protected"
#define SZ_USBMODEM_DATA_KEY_PIN_REMAINS		"pin_remains"
#define SZ_USBMODEM_DATA_KEY_PUK_REMAINS		"puk_remains"
#define SZ_USBMODEM_DATA_KEY_DEFAULT_APN_LIST	"default_apn_list"
#define SZ_USBMODEM_DATA_KEY_PROFILE			"profile"

// usbmodem data value
#define USBMODEM_DATA_VALUE_UNAVAILABLE			-1

// Profile define
#define SZ_PROFILE_SECTION					"USBModem Profile"
#define SZ_PROFILE_KEY_APN					"apn"
#define SZ_PROFILE_KEY_PHONE				"number"
#define SZ_PROFILE_KEY_USERNAME				"user"
#define SZ_PROFILE_KEY_PASSWORD				"pass"
#define SZ_PROFILE_KEY_IMSI					"IMSI"
#define SZ_PROFILE_KEY_LOCATION				"location"
#define SZ_PROFILE_KEY_ISP					"isp"
#define SZ_PROFILE_KEY_DEFAULTGW			"default_gw"

// Profile default value
#define SZ_PROFILE_KEY_DEFAULT_PHONE		"*99***1#"
#define SZ_PROFILE_KEY_DEFAULT_USERNAME		"Unknown"
#define SZ_PROFILE_KEY_DEFAULT_PASSWORD		"Unknown"

// wvdial args
#define SZF_WVDIAL_LOG                      SZD_USBMODEM_CONF"/wvdial.log"
#define SZ_WVDIAL_KEY_STUPID_MODE_1			"Stupid Mode=1"

// ppp define key
#define SZ_PPP_NODEFAULTROUTE				"nodefaultroute"

// ppp insert module
#define SZF_INSMOD_CMD						"/sbin/insmod"
#define SZF_PPP_SLHC						"slhc.ko"
#define SZF_PPP_GENERIC						"ppp_generic.ko"
#define SZF_PPP_ASYNC						"ppp_async.ko"
#define SZF_MODULE_PPP_SLHC					"slhc"
#define SZF_MODULE_PPP_GENERIC					"ppp_generic"
#define SZF_MODULE_PPP_ASYNC					"ppp_async"
#define SZ_USBMODEM_SERVERICE_NAME				"usbmodem_service"

// RSSI define
#define RSSI_ERROR							99
#define RSSI_MAX							31
#define RSSI_MIN							0

// default gateway backup file
#define SZF_DEFAULT_GATEWAY_FILE			"/etc/ppp/usbmodem_backup_gw"

// wait time or sleep time define
#define SIMHANDLER_PINUNLOCK_WAITTIME_MAX	10

#endif /* _SYNO_WIRELESS_USBMODEM_INT_HPP_ */
