/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _NET_AUTHENTICATION_8021X_HPP_
#define _NET_AUTHENTICATION_8021X_HPP_
#include <string>
#include <map>

#include <synowireless/utils/config.hpp>

extern "C" {
#include <synocore/proc.h> //SYSLOG, SLIBCExec
}

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum __tag_CERT_TYPE {
	TYPE_SUCCESS = 0,
	TYPE_INTERNEL_ERR = -1,
	TYPE_ILLEGAL_CERT = -2,
	TYPE_ILLEGAL_KEY = -3,
	TYPE_CERT_NOT_UTF8 = -4,
	TYPR_NOT_SUPPORT_DSA = -5,
	TYPE_VERIFY_ERROR = -6,
	TYPE_UNKNOWN_CYPHER = -7
} CERT_TYPE;

typedef enum __tag_CYPHER{
	TYPE_UNKNOWN = 0,
	TYPE_RSA,
	TYPE_DSA
} CYPHER;

enum AUTH_UPLOAD
{
	UPLOAD_CA_CERT = 0,
	UPLOAD_USER_CERT,
	UPLOAD_KEY,
	UPLOAD_PAC
};

#ifdef __cplusplus
}
#endif

namespace synonetwork {
namespace authentication {

// For verify certificate
#define SZK_RSA				"RSA"
#define SZK_DSA				"DSA"
#define SZK_CRT_HEADER			"CERTIFICATE"
#define SZK_KEY_HEADER			"PRIVATE KEY"
#define SZF_OPENSSL			"/usr/bin/openssl"
#define SZF_CP				"/bin/cp"

#define SZD_USR_SYNO_ETC_8021X		"/usr/syno/etc/8021X/"
#define SZF_8021X_CONF_PREFIX		SZD_USR_SYNO_ETC_8021X"cfg-"
#define SZF_WPA_SUPPLICANT_CONF		"/usr/syno/etc/wpa_supplicant.conf."

#define SZF_WPA_CLI                     "/usr/sbin/wpa_cli"
#define SZK_WPA_EAP_STATE               "EAP state"
#define SZV_WPA_SUCCESS                 "SUCCESS"
#define SZV_WPA_FAILURE                 "FAILURE"
#define SZV_WPA_IDLE                    "IDLE"
#define SZV_STATUS_CHECK_TIMEOUT	3

#define SZF_INITCTL			"/sbin/initctl"
#define SZ_8021X_UPSTART		"8021x-client"

#define SZK_ENABLE			"enable"
#define SZK_AUTH_IDENTITY		"identity"
#define SZK_AUTH_ANONYMOUS		"anonymous_identity"
#define SZK_AUTH_PASSWORD		"password"
#define SZK_AUTH_EAP			"eap"
#define SZK_AUTH_PHASE2			"phase2"
#define SZK_AUTH_KEY_PASSWORD		"key_password"
#define SZK_AUTH_CA_CERT		"ca_cert"
#define SZK_AUTH_USER_CERT		"user_cert"
#define SZK_AUTH_KEY			"key"
#define SZK_AUTH_PAC			"pac"
#define SZK_AUTH_CA_CERT_UPDATE		"ca_cert_update_time"
#define SZK_AUTH_USER_CERT_UPDATE	"user_cert_update_time"
#define SZK_AUTH_KEY_UPDATE		"key_update_time"
#define SZK_UPLOAD_FILE_TYPE		"upload_type"
#define SZK_STATUS			"status"

#define SZV_ENUM_ERROR			"error"

/* AUTH_EAP */
#define SZV_EAP_AUTO			"auto"
#define SZV_EAP_PEAP			"peap"
#define SZV_EAP_TTLS			"ttls"
#define SZV_EAP_TLS			"tls"
#define SZV_EAP_FAST			"fast"

/* AUTH_PHASE2 */
#define SZV_PHASE2_PAP			"pap"
#define SZV_PHASE2_GTC			"gtc"
#define SZV_PHASE2_MSCHAP		"mschap"
#define SZV_PHASE2_MSCHAPV2		"mschapv2"

/* AUTH_STATUS */
#define SZV_STATUS_AUTHENTICATED	"authenticated"
#define SZV_STATUS_AUTHENTICATING	"authenticating"
#define SZV_STATUS_UNAUTHENTICATED	"unauthenticated"
#define SZV_STATUS_UNKNOWN		"unknown"

enum AUTH_EAP
{
	EAP_TYPE_AUTO = 0,
	EAP_TYPE_PEAP,
	EAP_TYPE_TTLS,
	EAP_TYPE_TLS,
	EAP_TYPE_FAST
};

enum AUTH_PHASE2
{
	PHASE2_TYPE_PAP = 0,
	PHASE2_TYPE_GTC,
	PHASE2_TYPE_MSCHAP,
	PHASE2_TYPE_MSCHAPV2
};

template<typename Type>
class AuthEnumMap {
public:
	static void initializeMap()
	{
		if (!blInitialized) {
			blInitialized = CreateMap(enumMap);
		}
	}

	static std::string EnumToString(Type value)
	{
		typename std::map<std::string, Type>::iterator it;

		initializeMap();

		for (it = enumMap.begin(); enumMap.end() != it; it++) {
			if (it->second == value) {
				return it->first;
			}
		}

		return SZV_ENUM_ERROR;
	}

	static Type StringToEnum(const std::string &strValue)
	{
		typename std::map<std::string, Type>::iterator it;

		initializeMap();

		it = enumMap.find(strValue);
		if (enumMap.end() == it) {
			SYSLOG(LOG_ERR, "Failed to find key(%s)", strValue.c_str());
			return enumMap.find(SZV_ENUM_ERROR)->second;
		}

		return it->second;
	}
protected:
	static bool CreateMap(std::map<std::string, AUTH_EAP> &map)
	{
		map[SZV_EAP_AUTO] = EAP_TYPE_AUTO;
		map[SZV_EAP_PEAP] = EAP_TYPE_PEAP;
		map[SZV_EAP_TTLS] = EAP_TYPE_TTLS;
		map[SZV_EAP_TLS] = EAP_TYPE_TLS;
		map[SZV_EAP_FAST] = EAP_TYPE_FAST;

		return true;
	}
	static bool CreateMap(std::map<std::string, AUTH_PHASE2> &map)
	{
		map[SZV_PHASE2_PAP] = PHASE2_TYPE_PAP;
		map[SZV_PHASE2_GTC] = PHASE2_TYPE_GTC;
		map[SZV_PHASE2_MSCHAP] = PHASE2_TYPE_MSCHAP;
		map[SZV_PHASE2_MSCHAPV2] = PHASE2_TYPE_MSCHAPV2;

		return true;
	}
private:
	static bool blInitialized;
	static std::map<std::string, Type> enumMap;

private:
	AuthEnumMap();
	~AuthEnumMap();
};

template<typename Type> bool AuthEnumMap<Type>::blInitialized = false;
template<typename Type> std::map<std::string, Type> AuthEnumMap<Type>::enumMap;

int Auth8021XStartDaemon(const std::string &strIfName, bool blTest);
int Auth8021XStopDaemon(const std::string &strIfName, bool blTest);
void Auth8021XGetStatus(const std::string &strIfname, std::string &strStatus);
int WriteWpaConf(const std::string &strIfName, synowireless::utils::ConfigNoSection &authConfig);
int Auth8021XGetConf(const std::string &strIfname, synowireless::utils::ConfigNoSection &authConfig);
int Auth8021XSetConf(const std::string &strIfname, synowireless::utils::ConfigNoSection &authConfig, bool blTest);
CERT_TYPE Auth8021XUploadCert(const std::string &strIfname, const int &iUploadType, const std::string &strUploadTmpPath);
int Auth8021XDeleteCert(const std::string &strIfname, const int &iUploadType);
int Auth8021XChangeInterface(const std::string &srcIfName, const std::string &dstIfName);

} /* authentication */
} /* synonetwork */
#endif /* _NET_AUTHENTICATION_8021X_HPP_ */
