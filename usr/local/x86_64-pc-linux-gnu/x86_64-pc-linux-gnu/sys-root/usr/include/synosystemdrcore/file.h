/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNODR_COMMON_FILE_H__
#define __SYNODR_COMMON_FILE_H__

#include <string>
#include <map>
#include <vector>
#include <set>
#include <json/value.h>
#include <fstream>
#define DEFAULT_DIR_MODE 0755

namespace SynoDRCommon {
namespace File {

	template<typename T1, typename T2>
	int Read(const std::string &file, std::map<T1, T2> &keyValues);

	bool IsRegularFile(int fd);
	bool CreateDir(const std::string &dirPath, const int mode = DEFAULT_DIR_MODE);
	bool RemoveDir(const std::string &dirPath);
	std::string GetParentDir(const std::string &path);
	bool Read(const std::string &, Json::Value &);
	bool Write(const std::string &, const Json::Value &);

}//namespace File
}//namespace SynoDRCore

#endif //__SYNODR_COMMON_FILE_H__
