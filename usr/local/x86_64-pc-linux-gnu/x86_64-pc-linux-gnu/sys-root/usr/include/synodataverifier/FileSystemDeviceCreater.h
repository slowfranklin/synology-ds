/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef FILE_SYSTEM_DEVICE_CREATER_H
#define FILE_SYSTEM_DEVICE_CREATER_H

#include "FileSystemDevice.h"
#include "SystemInfoHelper.h"

class FileSystemDeviceCreater{
public:
	static FileSystemDevice* Create(const std::string &devicePath);
private:
	static FILE_SYSTEM_TYPE GetFileSystemType(const std::string &devicePath);
};

#endif /*FILE_SYSTEM_DEVICE_CREATER_H*/
