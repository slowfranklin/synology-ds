/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_UTILS_CONFIG_HPP_
#define _SYNO_WIRELESS_UTILS_CONFIG_HPP_

#include <map>
#include <string>

namespace synowireless {
namespace utils {

typedef std::map<std::string, std::string> MapNoSection;
typedef std::map<std::string, std::map<std::string, std::string> > MapSection;

class Config {
public:
	Config();
	Config(const std::string &strConfigName);
	virtual ~Config();

	void SetName(const std::string &strConfigName);
	std::string GetNameString() const;
	const char *GetNameCString() const;
	std::string GetDirName() const;

	virtual int Write() = 0;
	virtual int Read() = 0;

private:
	std::string strName;
}; /* class Config */

class ConfigNoSection : public Config {
public:
	ConfigNoSection();
	ConfigNoSection(const std::string &strConfigName);
	virtual ~ConfigNoSection();

	void AddKeyValue(const std::string &strKey, const std::string &strValue);
	void AddKeyValue(const std::string &strKey, int iValue);
	void AddKeyValue(const std::string &strKey, double value);
	void AddKeyValue(const std::string &strKey, bool blValue);
	int Write();
	int Read();
	std::string GetKeyValue(const std::string &strKey);
	MapNoSection GetKeyValues();

private:
	MapNoSection list;
}; /* class ConfigNoSection */

class ConfigSection : public Config {
public:
	ConfigSection();
	ConfigSection(const std::string &strConfigName);
	virtual ~ConfigSection();

	void AddKeyValue(const std::string &strSection,
					 const std::string &strKey,
					 const std::string &strValue);
	void AddKeyValue(const std::string &strSection,
					 const std::string &strKey,
					 int iValue);
	void AddKeyValue(const std::string &strSection,
					 const std::string &strKey,
					 double value);
	void AddKeyValue(const std::string &strSection,
					 const std::string &strKey,
					 bool blValue);
	void DeleteSection(const std::string &strSection);
	int Write();
	int Read();
	bool Find(const std::string &strSection);
	bool Empty();
	std::string GetKeyValue(const std::string &strSection,
							const std::string &strKey);
	MapSection GetKeyValues();

private:
	int WriteTemp(std::string &strTempFileName);

	MapSection list;
}; /* class ConfigSection */

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_CONFIG_HPP_ */
