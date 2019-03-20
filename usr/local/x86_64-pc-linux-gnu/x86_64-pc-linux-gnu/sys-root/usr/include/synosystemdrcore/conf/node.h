/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNOSYSDRCORE_CONF_NODE_H__
#define __SYNOSYSDRCORE_CONF_NODE_H__

#include <string>
#include <json/value.h>
#include <synosystemdrcore/conf/conf_def.h>

namespace SynoSysDRCore {
namespace Conf {

class Node {
public:
	Node();

	bool fromJson(const Json::Value &);
	Json::Value toJson() const;
	std::string _SN;
	std::string _nodeID;
};

}//Conf
}//SynoSysDRCore

#endif //__SYNOSYSDRCORE_CONF_NODE_H__
