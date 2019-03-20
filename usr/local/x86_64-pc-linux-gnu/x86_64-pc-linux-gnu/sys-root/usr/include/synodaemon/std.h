/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNO_DAEMON_STD_H__
#define __SYNO_DAEMON_STD_H__

#include <unistd.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <exception>

namespace synodaemon {

using std::string;
using std::vector;
using std::queue;
using std::map;
using std::set;
using std::unordered_set;
using std::unordered_map;
using std::stringstream;

using std::find_if;
using std::ptr_fun;
using std::not1;
using std::isspace;

template<typename IDType, typename Container>
vector<Container>& operator << (vector<Container>& vals, map<IDType, Container>& source)
{
	vals.clear();
	vals.reserve(source.size());

	for (const auto &val : source) {
		vals.push_back(val.second);
	}
	return vals;
}

template<typename IDType, typename Container>
vector<Container>& operator << (vector<Container>& vals, map<IDType, Container>&& source)
{
	vals.clear();
	vals.reserve(source.size());

	for (const auto &val : source) {
		vals.push_back(std::move(val.second));
	}
	return vals;
}

inline string& LTrim(string& s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
	return s;
}

inline string& RTrim(string& s) {
	s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

inline string& Trim(string& s) {
	return LTrim(RTrim(s));
}

typedef std::function<void(int)> WorkerFunc;
typedef void(*WorkerFuncPtr)(int);
typedef void(*KillHandler)(int);

} //end of synodaemon

#endif
