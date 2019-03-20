// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_MYDS_CPP_H__
#define __SYNO_MYDS_CPP_H__
#include <json/value.h>
#include <synomyds/synomyds.h>

typedef enum PAYMENT_ACTION {
	PAYMENT_ACTION_AUTH,
	PAYMENT_ACTION_GETITEMLIST,
	PAYMENT_ACTION_GETAPPITEMINFO,
	PAYMENT_ACTION_NONE
} PAYMENT_ACTION;

/**
 * @addtogroup MYDS
 *
 * @{
 */

/**
 * @apparmor abstractions/mydscenter
 */
PAYMENT_ACTION SYNOPaymentParseAction(const char *szAction);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentHTTPSSendWithJSONAndAccount(const PAYMENT_ACTION action, const Json::Value &data, const MYDS_ACCOUNT *pAccount,
                                LIBMYDS_SYNO_RESPONSE * pResp);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentHTTPSSendWithJSON(const PAYMENT_ACTION action, const Json::Value &data, LIBMYDS_SYNO_RESPONSE * pResp);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentHTTPSAuth(const char *szMyDSID, const char *szMyDSPW, const char *szLang, LIBMYDS_SYNO_RESPONSE * pResp);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentHTTPSDownloadPurchaseInfo(const char *szPkgName, const char* szPurDir, const char *szLang, const char *szMydsID);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountRegister(const char *szEmail, const char *szPassword, const char *szFullName, bool blCriticalRelease);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountLogin(const char *szEmail, const char *szPassword, Json::Value &jsonOutput, bool blAttemptOnly = false);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountOauthLogin(Json::Value &jsonOutput, const char *szAccessToken);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSGetIframeInfo(Json::Value &jsonOutput);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSHandleApiKeyError(Json::Value &jsonOutput, const char *szApiKeyError);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountQueryInfo(Json::Value &jsonOutput, bool blRealTime, bool blFastMode);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountSetInfo(const char *szFullname, const char *szEmail, const char *szCurrentPassword, const char *szNewPassword,
		const char *szCountry, const char *szNotifyLanguage, const char *szTimeZone, BOOL blEnews, BOOL blCriticalRelease, BOOL blLocalPromotion, const char *szCUList);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountLogout(bool blNotifyServer = true);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountPurchaseList(const char *szLang, const char* szDateFrom, const char* szDateTo, Json::Value &jsonApps,
		Json::Value &jsonSerials, Json::Value &jsonPrices, Json::Value &jsonPaypals, Json::Value &jsonOutput);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSReportInfo(void);

/**
 * @}
 */

#endif // __SYNO_MYDS_H__
