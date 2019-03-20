/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_EXT_CPP_H__
#define __SYNOSYSDRCORE_EXT_CPP_H__

#include <json/value.h>

Json::Value SYNOSystemDRGetPkgEnabledInfo();
bool SYNOSystemDRIsRemoteFailover();

#endif //__SYNOSYSDRCORE_EXT_CPP_H__
