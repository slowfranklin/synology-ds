/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_PKG_ENABLED_INFO_H__
#define __SYNOSYSDRCORE_CONF_PKG_ENABLED_INFO_H__

#include <string>
#include <json/value.h>

namespace SynoSysDRCore {
namespace Conf {
namespace PkgEnabledInfo {

bool getConf(Json::Value &appEnabledList);
bool setConf(const Json::Value &appEnabledList);
bool resetConf();

} // PkgEnabledInfo
} // Conf
} // SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_PKG_ENABLED_INFO_H__
