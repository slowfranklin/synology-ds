/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_WIFI_ADAPTER_DATA_HPP_
#define _SYNO_WIRELESS_WIFI_ADAPTER_DATA_HPP_

#include <string>
#include <vector>

extern "C" {
#include <synocore/hash.h>
}

namespace synowireless {
namespace wifi {

struct RELOAD_STATUS {
	bool ap;
	bool txPower;
	bool schedule;
	bool scheduleGuest;
	bool ruleGuest;
};

class AdapterConfig;

class AdapterData {
public:
	static AdapterData *Create(const std::string &strIfName);
	static int Delete(const AdapterData *pData);

	int Read();
	int Write();

	int SetConfig(const AdapterConfig &config);
	const AdapterConfig &GetConfig() const;

	bool NeedReload() const;
	RELOAD_STATUS GetReloadStatus() const;
	int ResetReloadStatus();
	int EnableReloadStatus();

private:
	AdapterConfig *pConfig;
	RELOAD_STATUS reloadStatus;

private:
	AdapterData();
	~AdapterData();
	int SetAPConfig(const AdapterConfig &newConfig);
	int SetParentalControl(const AdapterConfig &newConfig);
	int SetClientConfig(const AdapterConfig &newConfig);

	/* Following functions/c'tor should not be called */
	AdapterData(const AdapterData &);
	AdapterData &operator=(const AdapterData &);

}; /* clase AdapterData */

/**
 * This function template is used to set
 * the new config to old config.
 *
 * @return 0 : not need reload
 *         1 : need reload
 */
template <typename T>
bool SetReloadData(T &oldData, const T &newData)
{
	if (oldData == newData) {
		return false;
	}

	oldData = newData;

	return true;
}

} /* namespace wifi */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_WIFI_ADAPTER_DATA_HPP_ */
