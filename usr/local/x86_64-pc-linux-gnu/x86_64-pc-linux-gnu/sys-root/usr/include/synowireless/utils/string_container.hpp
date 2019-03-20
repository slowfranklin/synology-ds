/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_STRING_CONTAINER_HPP_
#define _SYNO_WIRELESS_UTILS_STRING_CONTAINER_HPP_

#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <json/value.h>
#include <synocore/list.h>

namespace synowireless {
namespace utils {
		void Print(const std::vector<std::string> &strVector);
		void Print(const Json::Value &jsondata);
		void Print(const std::set<std::string> &strSet);

		std::string ConvertToString(const Json::Value &jsondata);
		std::string ConvertToString(const Json::Value &jsonArray, const std::string &strSep, int start = 0, int count = -1);
		std::string ConvertToString(const std::vector<std::string> &strVector, const std::string &strSep = std::string(","), int start = 0, int count = -1);
		std::string ConvertToString(const std::set<std::string> &strSet, const std::string &strSep = std::string(","), int start = 0, int count = -1);

		std::vector<std::string> ConvertToVector(const std::set<std::string> &strSet);
		std::vector<std::string> ConvertToVector(const Json::Value &jsonArray);
		std::vector<std::string> ConvertToVector(const PSLIBSZLIST pslibList);

		std::set<std::string> ConvertToSet(const Json::Value &jsonArray);
		std::set<std::string> ConvertToSet(const PSLIBSZLIST pslibList);
		std::set<std::string> ConvertToSet(const std::vector<std::string> &strVector);

		int ConvertToSLIBList(const std::set<std::string> &strSet, PSLIBSZLIST &pslibList);
		int ConvertToSLIBList(const std::vector<std::string> &strVector, PSLIBSZLIST &pslibList);

		Json::Value ConvertToJsonArray(const PSLIBSZLIST pslibList);
		Json::Value ConvertToJsonArray(const std::vector<std::string> &strVector);
		Json::Value ConvertToJsonArray(const std::set<std::string> &strSet);

		Json::Value ParseToJsonArray(const char *szValue, const char *szSep);
		std::set<std::string> ParseToSet(const char *szValue, const char *szSep);
		std::vector<std::string> ParseToVector(const char *szValue, const char *szSep);

		int GetUniqueStrVector(std::vector<std::string> &strVector);
		std::set<std::string> GetDiff(const std::set<std::string> &set1, const std::set<std::string> &set2);
		std::vector<std::string> GetDiff(const std::vector<std::string> &vector1, const std::vector<std::string> &vector2);
		std::vector<std::string> GetElementInRange(const std::vector<std::string> &vstrSrc, int offset, int limit);
		std::vector<std::string> GetIntersection(const std::vector<std::string> &vector1, const std::vector<std::string> &vector2);

		int Find(const std::string &element, const std::vector<std::string> &strVector);
		bool IsExist(const std::string &element, const std::vector<std::string> &strVector);
		void Remove(const std::string &element, std::vector<std::string> &strVector);

} //utils
} //synowireless
#endif //_SYNO_WIRELESS_UTILS_STRING_CONTAINER_HPP_
