/*Copyright (c) 2000-2015 Synology Inc. All rights reserved.*/
#ifndef __SYNO_FWGEOIP_H__
#define __SYNO_FWGEOIP_H__

#include <synocore/synotype.h>
#include <sys/types.h>
#include <synocore/synoglobal.h>
#include <synocore/conf.h>
#include <json/value.h>
#include <vector>

namespace FW {
	typedef std::vector<std::string> ip_list_t;
	typedef std::vector<std::string> country_list_t;

	class FW_GEOIP {
		public:
			bool countryEnum(country_list_t &contryList);
			bool countryIPGet(const std::string &countryName, const bool &isV6, Json::Value &ipList);
			static bool geoipSanctify(const country_list_t &countryList, const bool &isIPv6, country_list_t &outputCountries);
		private:
			struct GEOIP_SUBNET4 {
				uint32_t begin;
				uint32_t end;
			};
			struct GEOIP_SUBNET6 {
				struct in6_addr begin, end;
			};

			void ParseV4(uint32_t begin, uint32_t end, Json::Value &rule);
			void Ipv4ToString(uint32_t addr, char *szIp, ssize_t cbIp);
			void Ipv6ToString(struct in6_addr *addr, char *szIp, ssize_t cbIp);
			void ParseV6(struct in6_addr *begin, struct in6_addr *end, Json::Value &rule);
			int geoipFileRead(const std::string &szFileName, Json::Value &rule, Json::Value &rules, bool blIpv6);
	};
}

#endif /* __SYNO_FWGEOIP_H__ */
