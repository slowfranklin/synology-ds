// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_MYDS_H__
#define __SYNO_MYDS_H__

#include <sys/cdefs.h>

#include <curl/curl.h>

#include <synocore/synotype.h>
#include <synocore/synoglobal.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include "synomyds/synomyds_err.h"
#include <sys/types.h>
#include <dirent.h>

__BEGIN_DECLS;

#define MAX_MYDS_USERNAME 4096
#define MAX_MYDS_PWD 4096
#define MAX_MYDS_ID_SERIAL 4096
#define MAX_MYDS_AUTH_KEY 4096
#define MAX_MYDS_FULLNAME 1024
#define MAX_MYDS_COUNTRY 256
#define MAX_MYDS_TIMEZONE 256
#define MAX_MYDS_NOTIFY_LANGUAGE 256
#define MAX_MAC_SIZE 24
#define MAX_MYDS_CRITICAL_VERSION_LIST 1024
#define MAX_MYDS_CRITICAL_VERSION_DOMAIN 1024
#define CB_MYDS_BUF_SIZE 256
#define CB_MYDS_MD5_MAX  64

// Conf path
#define SZ_MYDS_CONF	"/etc/myds.conf"

// Field name
#define SZ_MYDS_USERNAME "mydsID"
#define SZ_MYDS_PASSWD "mydsPW"
#define SZ_MYDS_SERIAL "ds_sn"
#define SZ_MYDS_TOKEN "ds_token"
#define SZ_MYDS_AUTH_KEY "ds_auth_key"
#define SZ_MYDS_ID_SERIAL "mydsIDSerial"
#define SZ_MYDS_FULLNAME "full_name"
#define SZ_MYDS_COUNTRY "country"
#define SZ_MYDS_TMZONE "timezone"
#define SZ_MYDS_NOTIFY_LANGUAGE "notify_language"
#define SZ_MYDS_ACTIVATED "activated"
#define SZ_MYDS_DISABLED "disabled"
#define SZ_MYDS_ENEWS "enews"
#define SZ_MYDS_CRITICAL_RELEASE "critical_release"
#define SZ_MYDS_ENEWS_LOCAL_PROMOTION "enews_local_promotion"
#define SZ_MYDS_LAST_QUERY_TIME "last_query_time"

// Server info
#define PATH_DNS_AUTH_HANDLER "dnsauth.php"
#define PATH_ACCOUNT_HANDLER "account.php"
#define PATH_QUERY_HANDLER "api/query.php"
#define PATH_OAUTH_LOGIN_HANDLER "good/user/launch"

// CGI field name
#define SZ_CGI_ACTION "action"
#define SZ_CGI_TYPE "type"
#define SZ_CGI_EMAIL "email"
#define SZ_CGI_PASSWD "passwd"
#define SZ_CGI_PASSWD_NEW "passwd_new"
#define SZ_CGI_PASSWD_CONFIRMATION "passwd_confirmation"
#define SZ_CGI_FULLNAME "full_name"
#define SZ_CGI_ACCESS_TOKEN "access_token"
#define SZ_CGI_SERIAL_NO "serial_no"
#define SZ_CGI_LANG_NOTIFY "notify_lang"
#define SZ_CGI_LANGUAGE_NOTIFY "notify_language"
#define SZ_CGI_LANGUAGE "language"
#define SZ_CGI_TOKEN "token"
#define SZ_CGI_TMZONE "timezone"
#define SZ_CGI_COUNTRY "country"
#define SZ_CGI_MAC "mac"
#define SZ_CGI_AUTH_KEY "auth_key"
#define SZ_CGI_API_KEY "api_key"
#define SZ_CGI_MYDS_ID "id"
#define SZ_CGI_DATES "dates"
#define SZ_CGI_PAYPALS "paypals"
#define SZ_CGI_SERIALS "serials"
#define SZ_CGI_APPS "apps"
#define SZ_CGI_PRICES "prices"
#define SZ_CGI_ACTIVATED "activated"
#define SZ_CGI_DISABLED "disabled"
#define SZ_CGI_MERGE_LIST "merge_list[%u][%s]"
#define SZ_CGI_ENEWS "enews"
#define SZ_CGI_CRITICAL_RELEASE "critical_release"
#define SZ_CGI_ENEWS_LOCAL_PROMOTION "enews_local_promotion"
#define SZ_CGI_CRITICAL_VERSION_LIST "critical_version_list"
#define SZ_CGI_CRITICAL_VERSION_DOMAIN "critical_version_domain"
#define SZ_CGI_DS_INFO "ds_info"
#define SZ_CGI_ALIAS "alias"
#define SZ_CGI_DDNS "ddns"

// Actions
#define SZ_CGI_REGISTER "register"
#define SZ_CGI_GET_AUTH_KEY "get_auth_key"
#define SZ_CGI_DESTROY "destroy"
#define SZ_CGI_QUERY "query"
#define SZ_CGI_GET_HISTORY "get_history"
#define SZ_CGI_UPDATE "update"
#define SZ_CGI_CHECK "check"

// Auth types
#define SZ_CGI_ACNT_PW_APIKEY "acnt_pw_apikey"
#define SZ_CGI_ACNT_APIKEY "acnt_apikey"

#define PAYMENT_SYNOPAYMENT_PUBLICKEY_LENGTH 2105
#define PAYMENT_PURCHASE_PUBLICKEY_LENGTH 1097

// Command
#define SZ_REPORT_MYDS_INFO_CMD "/usr/syno/bin/synomyds --report_info"

// Plugin
#define SZD_MYDS_LOGOUT_PLUGIN   "myds/logout"
#define SZD_MYDS_LOGIN_PLUGIN    "myds/login"

// Conf key
#define SZK_MYDS_DISABLE_REPORT "myds_disable_report"
#define SZK_MYDS_DISABLE_NOTIFY "myds_disable_notify"

typedef struct _tag_myds_INFO_ {
	char            szUser[MAX_MYDS_USERNAME];
	char            szPasswd[MAX_MYDS_PWD];
	char            szMyDSIDSerial[MAX_MYDS_ID_SERIAL];
	char            szAuthKey[MAX_MYDS_AUTH_KEY];
	char            szFullName[MAX_MYDS_FULLNAME];
	char            szCountry[MAX_MYDS_COUNTRY];
	char            szTimeZone[MAX_MYDS_TIMEZONE];
	char            szNotifyLanguage[MAX_MYDS_NOTIFY_LANGUAGE];
	char            szCUList[MAX_MYDS_CRITICAL_VERSION_LIST];
	char            szCUDomain[MAX_MYDS_CRITICAL_VERSION_DOMAIN];
	BOOL            blActivated;
	BOOL            blDisabled;
	BOOL            blEnews;
	BOOL            blCriticalRelease;
	BOOL            blEnewsLocalPromotion;
	time_t          iLastQueryTime;
} MYDS_ACCOUNT;

typedef struct _tag_libmyds_syno_req_ {
        const char		*pszUrl;
        const char		*pszPath;
        PSLIBSZHASH     pShQuery;
        MYDS_ACCOUNT	auth;
        BOOL            blUseGet;
        BOOL            blFastMode;
} LIBMYDS_SYNO_REQUEST;

typedef struct _tag_libmyds_syno_response_ {
	CURLcode curlCode;
	long httpCode;
	char *pszData;
} LIBMYDS_SYNO_RESPONSE;

typedef struct _tag_myds_server_INFO_ {
	char            szPaymentBaseURL[2048];
	char            szMyDSBaseURL[2048];
} MYDS_SERVER_INFO;

typedef struct _tag_payment_INFO_ {
	char            szBaseURL[2048];
} PAYMENT_INFO;

#include <synomyds/synomyds_p.h>

__END_DECLS;
#endif // __SYNO_MYDS_H__
