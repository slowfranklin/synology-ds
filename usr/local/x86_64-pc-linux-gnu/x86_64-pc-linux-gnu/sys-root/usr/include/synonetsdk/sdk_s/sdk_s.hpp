/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef __SYNO_SDK_S_HPP__
#define __SYNO_SDK_S_HPP___

extern "C" {
#include <pthread.h>
#include <synosdk/plugin.h>
#include <synonetsdk/net.h>
}

namespace synonetsdk {
namespace sdk_s {

int SYNONetSetCard1_S(PNETINFO pNetInfo, PNETINFO pNetInfoOld);
int SYNONetDNSUpdate_S();
BOOL BlSYNOLnxIsDHCP_S(const char *szDevice);
int SYNONetIFGetInfo_S(const char *szIfname, PSLIBNETIF pIF, PNETINFO pNetInfo);
int NetRoutetableHandler_S(const int type, const char *szInterface);
int SLIBPluginAction_S(SDK_PLUGIN_ACTION action, PSLIBPLUGIN pPlugin);
int SLIBNetIfLinkUpEvent_S(const char *szIfName);
int SLIBNetIfLinkDownEvent_S(const char *szIfName);
int SLIBCExec_S(const char *szPath, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4);

} /* namespace sdk_s */
} /* namespace synonetsdk */

#endif //__SYNO_SDK_S_HPP__
