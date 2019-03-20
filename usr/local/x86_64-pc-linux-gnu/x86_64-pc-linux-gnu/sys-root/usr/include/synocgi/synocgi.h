#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifndef _SYNOCGI_H_
#define _SYNOCGI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <string.h>
#include <syslog.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/syno.h>
#include <synocore/list.h>
#include <synocore/hash.h>
#include <synocore/file.h>
#include <synosdk/log.h>
#include <synocurconn/curconn.h>
#include <synosdk/dsinfo.h>
#include <json-c/json.h>
#ifdef __cplusplus
extern "C" {
#endif

#define	MSEC_LOCK			60000
#define	TIME_OUT_WEBCGI		15  //mins
#define	TIME_OUT_NEVER 		-1

//for cgi
#define	SZ_ALERT_MESSAGE		"alert"
#define	SZ_CONFIRM_MESSAGE		"confirm"

//button ID
#define		ID_BTN_APPLY		1
#define		ID_BTN_CANCEL		2
#define		ID_BTN_HELP			3
#define		ID_BTN_RESTART		4
#define		ID_BTN_BACK			5
#define		ID_BTN_NEXT			6
#define		ID_BTN_EXIT			7
#define		ID_BTN_START		8
#define		ID_BTN_FINISH		9
#define		ID_BTN_CONTINUE		10
#define		ID_BTN_REFRESH		11
#define		ID_BTN_CLOSE		12

#define		CGI_PATH			"path"
#define		SZV_HTTP				"http"
#define		SZV_HTTPS				"https"

#define	INDENT1_TAG				0x0008
#define	INDENT2_TAG				0x0010
#define	INDENT3_TAG				0x0020

#define SZ_DEFUSER				"admin"
#define	SZ_KEY_CMPY				"company"
#define	SZ_KEY_LANG				"language"
#define	SZ_KEY_SUPPLANG			"supplang"
#define SZ_KEY_MAILLANG			"maillang"
#define	SZ_KEY_RESC				"resource"

/* define some useful string type */
#ifndef _PSTRING
#define PSTRING_LEN 1024
#define FSTRING_LEN 128
typedef char pstring[PSTRING_LEN];
typedef char fstring[FSTRING_LEN];
#define _PSTRING
#endif

//Title for each station
#define SZ_STATION_TITLE_MANAGE  "Management"
#define SZ_STATION_TITLE_AUDIO  "Audio Station"
#define SZ_STATION_TITLE_FILE  "File Station"
#define SZ_STATION_TITLE_PHOTO  "Photo Station"
#define SZ_STATION_TITLE_WEB  "Web Station"
#define SZ_STATION_TITLE_SURVEILLANCE  "Surveillance Station"
#define SZ_STATION_TITLE_DOWNLOAD "Download Station"

//browser type
#define		WINIE		"WinIE"
#define		MACIE		"MacIE"
#define		SAFARI		"Safari"
#define		FIREFOX		"Firefox"

#define MAX_LEN_SESSION_ID (64 + MAX_SN_SIZE)
#define SZK_SESSION_ID "id"
#define SZK_DEVICE_ID "did"
#define SZK_DEVICE_TOKEN "smid"
#define SZK_HTTP_HEADER_CNTTYPE "Content-type"
#define SZK_HTTP_HEADER_CNTLANG "Content-Language"
#define SZ_CNTTYPE_UTF8	"charset=\"UTF-8\""
#define SZ_CNTTYPE_PLAINTEXT "text/plain; " SZ_CNTTYPE_UTF8
#define SZ_CNTTYPE_HTML "text/html; " SZ_CNTTYPE_UTF8
#define SZ_CNTTYPE_XML "text/xml; " SZ_CNTTYPE_UTF8
#define SZ_CNTTYPE_JAVASCRIPT "application/javascript; " SZ_CNTTYPE_UTF8
#define SZ_CNTTYPE_JSON "application/json; " SZ_CNTTYPE_UTF8

#define SZK_HTTP_HEADER_P3P "P3P"
#define SZ_P3P_CONTENT "CP=\"IDC DSP COR ADM DEVi TAIi PSA PSD IVAi IVDi CONi HIS OUR IND CNT\""

#define SZK_PARAM_SYNO_TOKEN "SynoToken"
#define SZK_ENABLE_SYNO_TOKEN "enable_syno_token"
#define SZV_DISABLE_TOKEN "--------"

#define SZK_CIPHERTEXT				"__cIpHeRtExT"
#define SZK_CIPHERTOKEN				"__cIpHeRtOkEn"
#define CIPHERTOKEN_VALID_DURATION	360

#define ALLOW_USER_WEBMAN			(CGI_USER_ADMIN | CGI_USER_LOCAL_NORMAL | CGI_USER_DOMAIN | CGI_USER_LDAP)
#define ALLOW_USER_AUDIO			(CGI_USER_ADMIN | CGI_USER_LOCAL_NORMAL)
#define ALLOW_USER_SURVEILLANCE		(CGI_USER_ADMIN | CGI_USER_LOCAL_NORMAL)
#define ALLOW_USER_DOWNLOAD			(CGI_USER_ADMIN | CGI_USER_LOCAL_NORMAL)

//yaka
#define SZ_WEBMAN_WEBPATH "/webman"
#define SZ_WEBMAN_MODULES_WEBPATH	SZ_WEBMAN_WEBPATH "/modules"
#define SZ_WEBMAN_JS_WEBPATH	SZ_WEBMAN_WEBPATH "/jslib"
#define SZ_MANAGEMENT_WEBPATH "/webman/index.cgi"
#define SZ_AUDIOSTATION_WEBPATH "/audio/index.cgi"
#define	SZ_SURVEILLANCE_WEBPATH	"/surveillance/cgi/index.cgi"
#define	SZ_DOWNLOAD_WEBPATH	"/download/index.cgi"

#define SZ_LOGIN_WEBPATH "/index.cgi"

#define SZF_TMP_PATH			"/tmp"
#define SZ_SESSION_PATH			"/usr/syno/etc/private/session"
#define SZD_SESSION_TIME_PREFIX	".access.time"
#define USER_CACHE_TIME			60 * 10
#define SZF_DOMAIN_LDAP_SESSION			SZ_SESSION_PATH "/current.users"
#define SZF_DOMAIN_LDAP_SESSION_LOCK	SZF_DOMAIN_LDAP_SESSION ".lock"
#define SZF_DOMAIN_VALIDSHARE_CACHE_PREFIX			"cgi.domain.validshare"
#define SZF_DOMAIN_VALIDSHARE_CACHE_PREFIX_PATH	SZF_TMP_PATH "/" SZF_DOMAIN_VALIDSHARE_CACHE_PREFIX

#define SZF_LDAP_VALIDSHARE_CACHE_PREFIX			"cgi.ldap.validshare"
#define SZF_LDAP_VALIDSHARE_CACHE_PREFIX_PATH	SZF_TMP_PATH "/" SZF_LDAP_VALIDSHARE_CACHE_PREFIX

#define LOG_DISK_STATION 			"DiskStation Manager"
#define LOG_FILE_STATION			"File Station"
#define LOG_AUDIO_STATION			"Audio Station"
#define LOG_SURVEILLANCE_STATION	"Surveillance Station"
#define LOG_DOWNLOAD_STATION		"Download Station"
#define LOG_STATION_LENGTH			32
#define LENGTH_OF_TIME_FORMAT		20 //i.e. 2009/08/05 17:56:03
#define NO_OTP_AUTH "syno_no_otp_auth"

#define SZD_SSO_SUPPORT "sso_support"
#define SZD_SSO_DEFAULT_LOGIN "sso_default_login"
#define SZD_SSO_SERVER "sso_server"
#define SZD_SSO_APPID "sso_appid"

#define SZD_DEVICE_TOKEN "DEVICE_TOKEN"
#define SZK_SID                      "_sid"

#define SZD_SYNOCGID_DAEMON_NAME	"synocgid"
#define SZD_SYNOCGID_DAEMON		"/usr/syno/sbin/" SZD_SYNOCGID_DAEMON_NAME
#define SZD_SYNOCGID_PID_PATH "/var/run/" SZD_SYNOCGID_DAEMON_NAME ".pid"

#define SZF_SYNOCGI_SOCKET_PATH "/run/synocgid.socket"

//session
#define SZF_SESSION_CHECK "/tmp/.sess.timeout.check"
#define SESSION_CHECK_INTERVAL 60

typedef enum _tag_cgi_position {
	CGI_CLIENT_NULL = 0,					//current user position not init
	CGI_CLIENT_DISK_STATION = 1,			//current user in disk station
	CGI_CLIENT_FILE_STATION = 2,			//current user in file station
	CGI_CLIENT_AUDIO_STATION = 3,			//current user in audio station
	CGI_CLIENT_SURVEILLANCE_STATION = 4,	//current user in surveillance station
	CGI_CLIENT_DOWNLOAD_STATION = 5,	//current user in download station
}CGI_CLIENT;

typedef enum _tag_cgi_options {
	CGI_OPT_TIMEOUT = 0,
	CGI_OPT_SKIP_CHECK_IP,
	CGI_OPT_SYNO_TOKEN,
	CGI_OPT_USER_TYPE,
	CGI_OPT_UID,
	CGI_OPT_GID,
	CGI_OPT_WEBAPI,
	CGI_OPT_APP,
	CGI_OPT_HOST,
	CGI_OPT_EXTRA,
	CGI_OPT_DURATION,
	CGI_OPT_UI,
	CGI_OPT_MAX
}CGI_OPTIONS;

typedef struct _tag_SynoCgi {
	PSLIBSZHASH phIn;			// Hash for CGI parameters
	PSLIBSZHASH phText;		// Hash for Text
	PSLIBSZHASH phInfo;		// Hash for /etc/synoinfo.conf
	PSLIBSZHASH phDef;		// Hash for /etc.default/synoinfo.conf
	PSLIBSZHASH phSetCookies;	// Hash for Set-Cookie:
	PSLIBSZHASH phCookies;	// Hash for Cookie:
	PSLIBSZHASH phHttpHdr;	// Hash for HTTP header
	PSLIBSZHASH phOptions;	// Hash for DSM options
	char *szSessFile;	// String for the path of Session File
	char *szTimeDir;	// String for the directory of session access time
	char *szLockFile;	// String for the path of Lock File
	char *szTempFile;	// String for the path of Temp File
	char *szTextDir;	// String for the path of Text Directory
	int cgitimeout;		// timeout value in seconds
	BOOL bSkipCheckIP;	// TRUE to skip checking source IP cross session
}SYNOCGI;

//If you change the number of LOGIN_WEB_FILE_MANAGER,
//please change LOGIN_WEB_FILE_MANAGER at /webfm/js/define.js
typedef enum {
	LOGIN_ADMIN_MANAGE = 1,
	LOGIN_FILE_STATION,
	LOGIN_AUDIO,
	LOGIN_SURVEILLANCE,
	LOGIN_DOWNLOAD,
	LOGIN_WEB,
	LOGIN_PHOTO,
}LOGIN_SERVICE;

typedef enum {
	HTTP_METHOD_POST = 1,
	HTTP_METHOD_GET,
	HTTP_METHOD_HEAD
}HTTP_METHOD;

typedef enum {
	LOGIN_SUCCESS = 1,
	LOGIN_ERR_EXPIRED = -1,
	LOGIN_ERR_PASSWD = -2, //username or password is wrong.
	LOGIN_ERR_INVALID = -3,
	LOGIN_ERR_SYSTEM = -4,
#ifdef MY_ABC_HERE
	LOGIN_ERR_OTP_REQUIRE = -5,
	LOGIN_ERR_OTP_ERR = -6,
	LOGIN_ERR_OTP_ENFORCED = -7,
#endif
	LOGIN_ERR_MAX_TRIES = -8,
	LOGIN_ERR_SHARING_PASSWD = -9,
	LOGIN_ERR_SHARING_USER = -10,
	LOGIN_ERR_SHARING_EXPIRE_TIMES = -11,
	LOGIN_ERR_PWD_EXPIRED = -12,
	LOGIN_ERR_PWD_MUSTCHANGE = -13,
	LOGIN_ERR_ACCT_LOCK = -14,
}CGI_LOGIN_RESULT;

typedef enum _tag_authorized_result_ {
	CGI_AUTH_SUCCESS_ADMIN=2,
	CGI_AUTH_SUCCESS_NORMAL=1,
	CGI_AUTH_ERR_TIMEOUT=-1,
	CGI_AUTH_ERR_INVALIDUSER=-2,
	CGI_AUTH_ERR_REPEAT_LOGIN=-3,
	CGI_AUTH_ERR_SYS=-4,
	CGI_AUTH_ERR_SID_NOTFOUND=-5, //not found Session-ID from cookies or CGI parameters.
	CGI_AUTH_ERR_SERVICE_DISABLE=-6,
	CGI_AUTH_ERR_TOKEN=-7,
	CGI_AUTH_ERR_IP=-8
}CGI_AUTH_RESULT;

typedef enum _tag_user_type_ {
	CGI_USER_ADMIN=0x01,
	CGI_USER_LOCAL_NORMAL=0x02,
	CGI_USER_DOMAIN=0x04,
	CGI_USER_LDAP=0x08,
	CGI_DISABLE_LOG=0x10
}CGI_USER_TYPE;

typedef struct _tag_login_params {
	const char* szUserName;
	const char* szPasswd;
	const char* szPamConfig;
	int allowUsers;
	BOOL bRememberMe;
}CGI_LOGIN_PARAMS;

typedef struct _tag_confirm_policy {
	int allowUsers;
	BOOL bSkipTimeout;
}CGI_CONFIRM_POLICY;

typedef enum {
	INDEX_HOST = 0,		//index of current user host
	INDEX_NAME,			//index of current user name
	INDEX_SID,			//index of current user UID
	INDEX_TIME,			//index of current user login time
	INDEX_LAST_UPDATE,	//index of current user access time
	INDEX_POSTION,		//index of current user CGI Client position
	INDEX_REMEMBERME,	//index of current user stay_login flag
	INDEX_TOKEN,		//index of current user csrf token
	INDEX_SKIP_CHECK_IP,//index of current user check ip flag
	INDEX_USER_TYPE,	//index of current user type
	INDEX_UID,			//index of current user uid
	INDEX_GID,			//index of current user gid
	INDEX_WEBAPI,		//index of current user available webapi
	INDEX_APP,			//index of current user login application
	INDEX_EXTRA,		//index of current user extra information
	INDEX_DURATION,		//index of current user timeout duration
	INDEX_UI,			//index of current user ui configuration
	INDEX_HOSTS,        //index of current user used hosts
	CURRENT_USER_NUM	//current user index number
} CURRENT_USER_INDEX;

/**************************************
 *  Function Prototype                *
 *                                    *
 **************************************/

BOOL SynoCgiInit(const char *szTextDir, SYNOCGI *pCgi);
BOOL SynoCgiInitEx(SYNOCGI *pCgi, int timeout, BOOL blSkipIPCheck, const char *szSessionFile, const char *szTextDir);
BOOL SynoCgiSetSessionParam(SYNOCGI *pCgi, int timeout, BOOL blSkipIPCheck, const char *szSessionFile, const char *szTextDir);
void SynoCgiFree(SYNOCGI *pCgi);

// load in parameters, configurations, informations and strings
char *SynoCgiGetParamLine();
BOOL SynoCgiLoadCGIParam(SYNOCGI *pCgi);
BOOL SynoCgiParseCGIParam(SYNOCGI *pCgi, char *szParamsLine);
BOOL SynoCgiLoadInfo(SYNOCGI *pCgi);
BOOL SynoCgiLoadText(SYNOCGI *pCgi, const char *szSect1, ...);
const char *SynoCgiGetCGIParam(SYNOCGI *pCgi, const char *szKey, const char *szDef);
const char *SynoCgiGetInfo(SYNOCGI *pCgi, const char *szKey, const char *szDef);
const char *SynoCgiGetDef(SYNOCGI *pCgi, const char *szKey, const char *szDef);
const char *SynoCgiGetText(SYNOCGI *pCgi, const char *szKey, const char *szDef);
const char *SynoCgiGetEncodeText(SYNOCGI *pCgi, const char *szKey, const char *szDef);
const char *SynoCgiGetRequestParam(SYNOCGI *pCgi, const char *szKey, const char *szDef);
BOOL SynoCgiSetText(SYNOCGI *pCgi, const char *szKey, const char *szVal);
BOOL SynoCgiSetCGIParam(SYNOCGI *pCgi, const char *szKey, const char *szVal);
const char *SynoCgiGetLang(SYNOCGI *pCgi);
const char *SynoCgiGetDefaultLang();
int SynoCgiSetMailLang(SYNOCGI *pCgi, const char *szMailLang);
const char *SynoCgiGetBrowserType(void);
char *SynoCgiGetGETParamLine();

// login/logout authenication functions
CGI_LOGIN_RESULT SynoCgiTestLogin(CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode);
CGI_LOGIN_RESULT SynoCgiTestLoginEx(CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode, const char *szService);
CGI_LOGIN_RESULT SynoCgiTestLoginEx2(CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode, const char *szService, BOOL blAuthOTP);
CGI_LOGIN_RESULT SynoCgiLogin(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *loginParams);
CGI_LOGIN_RESULT SynoCgiLoginWithOTPAuth(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode);
CGI_LOGIN_RESULT SynoCgiLoginEx(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *pLoginParams);
CGI_LOGIN_RESULT SynoCgiLoginNoAuth(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *pLoginParams);
CGI_LOGIN_RESULT SynoCgiLoginEx2(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode);
const char *SynoCgiLoginUIJsonConfigTemplate();
CGI_LOGIN_RESULT SynoCgiLoginWithUIJsonConfig(SYNOCGI *pCgi, char *szSID, int sizeSID, CGI_LOGIN_PARAMS *pLoginParams, const char *szOTPcode, const char *szUIJsonConfig);
CGI_AUTH_RESULT SynoCgiIsAuthorized(SYNOCGI *pCgi, char *szName, int nameSize, CGI_CONFIRM_POLICY *confirmPolicy, CGI_CLIENT cgiClient);
CGI_AUTH_RESULT SynoCgiIsAuthorizedEx(SYNOCGI *pCgi, const char *szUnsavedId, char *szName, int nameSize, CGI_CONFIRM_POLICY *confirmPolicy, const char *pszPrivilege);
BOOL SynoCgiLogout(SYNOCGI *pCgi, char *szName);
BOOL SynoCgiLogoutEx(SYNOCGI *pCgi, const char *szID, char *szName);
BOOL SynoCgiChangeAuthorizeTime(SYNOCGI *pCgi, int iDiff);
BOOL SynoCgiHasRecord(SYNOCGI *pCgi, char *szName, int nameSize);

BOOL SynoCgiPrintHTTPHeader(SYNOCGI *pCgi);
BOOL SynoCgiSetHTTPHeader(SYNOCGI *pCgi, const char *szKey, const char *szVal);
BOOL SynoCgiSetCookies(SYNOCGI *pCgi, const char *szName, const char *szVal, long minutes, const char *szPath, const char *szDomain, BOOL blSecure);
BOOL SynoCgiSetCookieWithHttpOnly(SYNOCGI *pCgi, const char *szName, const char *szVal, long minutes, const char *szPath, const char *szDomain, BOOL blSecure, BOOL blHTTPOnly);
BOOL SynoCgiDelCookies(SYNOCGI *pCgi, const char *szName, const char *szPath, const char *szDomain);
BOOL SynoCgiLoadInCookies(SYNOCGI *pCgi);
const char *SynoCgiGetInCookies(SYNOCGI *pCgi, const char *szName, const char *szDef);
char *SynoCgiSelectDefLang();
BOOL SynoCgiRefererMatch(const char *szInputPattern, BOOL blExact);
BOOL SynoCgiIsTokenEnable(SYNOCGI* pCgi);

// autoblock functions
BOOL SynoCgiIsDeniedIP(const char *szAddr);
void AutoBlockFailLoginSet(const char *szAddr, const char* szService);
BOOL IsAutoBlockMaxTries(const char *szAddr, const char *szService);

// get client IP address
int SynoCgiGetRemoteIP(char* pszIPBuf, int buflen);

/*
 * For Domain User
 */
//Domain User GID/UID cache.
uid_t SynoCgiDomUidGet(const char *szSID);
gid_t SynoCgiDomGidGet(const char *szSID);
int SynoCgiDomainCacheCleanLogout(const char *szSID);
int SynoCgiLDAPCacheCleanLogout(const char *szUID);

//Domain User Share cache.
int SynoCgiDomValidShareWrite(const char *szUser, const char *szSID);
int SynoCgiLDAPValidShareWrite(const char *szUser, const char *szUID);
BOOL SynoCgiDomValidShareCacheIsExist(const char *szSID);
BOOL SynoCgiLDAPValidShareCacheIsExist(const char *szUID);
int SynoCgiDomValidShareClean(const char *szSID);
int SynoCgiLDAPValidShareClean(const char *szUID);
int SynoCgiDomValidShareTimeoutClean(const char *szSessionFile);
int SynoCgiLDAPValidShareTimeoutClean(const char *szSessionFile);
int SynoCgiDomGetPrivilege(const char *szShare, const char *szUser, const char *szSID, int *share_pri);
int SynoCgiLDAPGetPrivilege(const char *szShare, const char *szUser, const char *szUID, int *share_pri);

//for getting UID/GID
int SynoCgiUidSet(const char *szSID, const char *szUser);
int SynoCgiGidSet(const char *szSID, const char *szUser);
uid_t SynoCgiUIDGet(const char *szSID, const char *szUser);
gid_t SynoCgiGIDGet(const char *szSID, const char *szUser);
int SynoCgiEGidSet(const char *szSID, const char *szUser);
int SynoCgiEUidSet(const char *szSID, const char *szUser);

// CGI encode/decode functions
int SynoCgiDecodeParam(char *szCode);
int SynoCgiURLEncode(const char *s, char *str, int BufLen);

// other function
int SynoCgiBeginCriticalSection(const char *szfLock, int msec);
int SynoCgiEndCriticalSection(int fd);
int SynoCgiLoginWriteLogByLoginResult(CGI_LOGIN_RESULT loginResult, const char *szUserName, const char *szStationTitle);
int SynoCgiLoginWriteLog(BOOL blLoginSuccess, const char *szUserName, const char *szStationTitle);
int SYNOCgiLoginUserCurrentLog(const char *szSessionFile, PSYNOCURCONN *ppData );
int SynoCgiGetSessPath(SYNOCGI *pCgi, char *szSessionFile, int SessionFilePathSize);

BOOL SynoCgiIsAuthorizedUser(SYNOCGI *pCgi, const char *szRedirect, const char *szName, int *UserType);
BOOL SynoCgiRedirect(SYNOCGI *pCgi, const char *szUrl);

void SynoCgiRemoveCharset(char *szString, const char *szCharset);

// descryption
char *SynoCgiGetRSAPublicKey();
char *SynoCgiGetRSAPublicKeyEx();
char *SynoCgiGetRSAModulusEx();
char *SynoCgiGetRSAModulus();
char *SynoCgiDetectAndDecryptParamLine(char *pszParam);
BOOL SynoCgiDecryptParam(char *pszParam);
BOOL SynoCgiDecrypt(const char *pszJsonText, size_t inLen, char *pszPlaintext, size_t *pOutLen);
BOOL SynoCgiDecryptEx(const char *pszJsonText, size_t inLen, char *pszPlaintext, size_t *pOutLen);

// json support
BOOL SynoCgiJsonRecordInit(json_object **joRecord, const char* szInput);
BOOL SynoCgiJsonRecordAdd(json_object* jObj, const char *pszIp, const char *pszUser, const char *pszId,
	 const char *pszPos, const char *bRememberMe, const char *pszToken);
BOOL SynoCgiJsonRecordUpdate(json_object *jObj, CURRENT_USER_INDEX index, const char* szVal);
BOOL SynoCgiJsonRecordParse(json_object *joRecord, const char **ppszIp, const char **ppszUser,
							   const char **ppszId, const char **ppszPos, const char **ppszRememberMe);
BOOL SynoCgiJsonRecordGet(json_object *jObj, CURRENT_USER_INDEX index, char *szVal, int cbVal);
BOOL SynoCgiJsonRecordGetBySID(SYNOCGI *pCgi, const char *szSID, CURRENT_USER_INDEX index, char *szVal, int cbVal);
BOOL SynoCgiJsonRecordAddOptions(json_object *joRecord, SYNOCGI *pCgi);
BOOL SynoCgiOptionsAddJsonRecord(SYNOCGI *pCgi, json_object *joRecord);

const char *SynoCgiGetOption(SYNOCGI *pCgi, CGI_OPTIONS opt, const char *szDef);
BOOL SynoCgiCheckOption(SYNOCGI *pCgi, CGI_OPTIONS opt, const char *szVal);
BOOL SynoCgiSetOption(SYNOCGI *pCgi, CGI_OPTIONS opt, ...);
BOOL SynoCgiSetSzOption(SYNOCGI *pCgi, CGI_OPTIONS opt, const char *szVal);

// SSO support
int SynoCgiSSOExchange(const char *szToken, char *szUsername, int cbUsername);

// system_time_to_seed.c
char SLIBSystemTimeToSeed(time_t curTime);

// PAM support
CGI_LOGIN_RESULT Auth_PAM(const char *szUser, const char *szPass, const char *szRemoteHost,const char *szfPamConfig);
CGI_LOGIN_RESULT Auth_PAM_OTP(const char *szUser, const char *szPass, const char *szOtp, BOOL blOtpSkip, const char *szDeviceId, const char *szRemoteHost, const char *szfPamConfig);
CGI_LOGIN_RESULT Auth_PAM_OTP_SmartBlock(const char *szUser, const char *szPass, const char *szOtp, BOOL blOtpSkip, const char *szDeviceId, const char *szDeviceToken, const char *szDeviceAgent, const char *szRemoteHost, const char *szfPamConfig);

// Session Support
long GetSystemUpTime();
CGI_AUTH_RESULT SynoCgiCheckSessionFile(SYNOCGI *pCgi,const char *szCgiId, char *szName, int nameSize, CGI_CONFIRM_POLICY *confirmPolicy, const char *pszPrivilege,const char *szEnvIp);
BOOL SynoCgiUpdateSessionFile(SYNOCGI *pCgi, PSLIBSZLIST pslSess);
BOOL SynoCgiUpdateSessionFileEx(SYNOCGI *pCgi, json_object *joArray);
BOOL SynoCgiRemoveSessionByIndex(SYNOCGI *pCgi, CURRENT_USER_INDEX index, const char *pszValue);
BOOL SynoCgiRemoveSessionByIndexEx(SYNOCGI *pCgi, CURRENT_USER_INDEX index, const char *pszValue);
BOOL SynoCgiSessionExistByIndex(SYNOCGI *pCgi, CURRENT_USER_INDEX index, const char *pszValue);
BOOL SynoCgiSessionExistByIndexEx(SYNOCGI *pCgi, CURRENT_USER_INDEX index, const char *pszValue);
BOOL SynoCgiAddSession(SYNOCGI *pCgi, const char *szId, const char *szTmp);
BOOL SynoCgiGetSessionId(SYNOCGI *pCgi, char *szPw, long *lUptime, char *szId, int cbId);
BOOL SynoCgiGetSession(SYNOCGI *pCgi, json_object **joArray);

void SynoCgiCheckExpired(SYNOCGI *pCgi);
BOOL SynoCgiRemoveSessionBySID(SYNOCGI *pCgi, const char *szSID);
int SynoCgiRemoveSessionByFunc(SYNOCGI *pCgi, BOOL (*isKeep)(json_object *jObj, void *pData), void *pData);
int SynoCgiRemoveSessionByFuncEx(SYNOCGI *pCgi, BOOL (*isKeep)(json_object *jObj, void *pData), void *pData);
int SynoCgiGetSessionByFunc(SYNOCGI *pCgi, BOOL (*isNeed)(json_object *jObj, void *pData), void *pData, json_object **joArray);
void SynoCgiSessionCleanCache();
BOOL SynoCgiSessionReloadCache(SYNOCGI *pCgi);
void SynoCgiSessionDumpCacheToLog();

BOOL SynoCgiGetSessionBySID(SYNOCGI *pCgi, const char *szSID, json_object **joRecord);

// for root daemon
BOOL SynoCgiLoginRemoveUser(SYNOCGI *pCgi, const char *szSID, char *szName);
#ifdef __cplusplus
}
#endif

#endif //_SYNOCGI_H_
