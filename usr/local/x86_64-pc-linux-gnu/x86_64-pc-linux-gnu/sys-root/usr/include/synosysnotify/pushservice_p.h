/* pushservice_utils.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSendSnsRequest(const char *szScript, const PSLIBSZHASH pDataHash, PSLIBSZHASH *pUploadHash, char *szOut, int cbOut);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetDsToken(char *szSerialOut, int cbSerial, char *szToken, int cbToken);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetResponseValue(const char *szInput, const char *szKey, char *szValue, int cbValue);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetDsSerial(char *szSerialOut, int cbSerialOut);
/* pushservice_update_ds_info.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUpdateDsInfo(char *szOut, int cbOut);
/* pushservice_update_msn_account.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUpdateMsnAccount(const char *szAccount, const char *szCategory, char *szOut, int cbOut);
/* pushservice_update_skype_account.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUpdateSkypeAccount(const char *szAccount, const char *szCategory, char *szOut, int cbOut);
/* pushservice_get_auth_token.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetAuthToken(char *szOut, int cbOut);
/* pushservice_unpair_mobile.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUnpairMobile(const char *szCategory, const char *szMobileTargetIdList);
/* pushservice_get_mobile_list.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetMobileList(const char *szCategory, char *szOut, int cbOut);
/* pushservice_send_notification.c */
SDK_STARTING_FROM(SDK_VER_6_0) void CheckSendingInterval(void);
SDK_STARTING_FROM(SDK_VER_6_0) int GetSendingInterval(const char *szInput, char *szOutput, int cbOutput);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOPushserviceSendNotification(const char *szCategory, const char *szTargetFilter, const char *szNotificationTag, PSLIBSZHASH *ppHashParam, PSLIBSZHASH *ppExtraDataHashParam);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOPushserviceSendNotificationWithFile(const char *szCategory, const char *szTargetFilter, const char *szNotificationTag, PSLIBSZHASH *ppHashParam, PSLIBSZHASH *ppExtraDataHashParam, PSLIBSZHASH *ppUploadHashParam);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOPushserviceSendNotificationEx(const char *szCategory, const char *szTargetFilter, const char *szNotificationTag, PSLIBSZHASH *ppHashParam, PSLIBSZHASH *ppExtraDataHashParam, PSLIBSZHASH *ppUploadHashParam, BOOL blWithBlock);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOPushserviceSendNotificationCustomized(const char *szCategory, const char *szNotificationTag, const char *szTextFilePath, const char *szTargetFilter, PSLIBSZHASH *ppHashParam, PSLIBSZHASH *ppExtraDataHashParam, PSLIBSZHASH *ppUploadHashParam, BOOL blWithBlock);
SDK_STARTING_FROM(SDK_VER_6_0) int CheckDsInfoUpdated();
SDK_STARTING_FROM(SDK_VER_6_0) int AddParamToHash(PSLIBSZHASH *ppHash, const char *szCategory, const char *szTargetFilter);
/* pushservice_update_ds_token.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUpdateDsToken(char *szOut, int cbOut);
/* pushservice_update_mail_account.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceUpdateMailAccount(const char *szAccount, const char *szCategory, BOOL blResendVerify, char *szOut, int cbOut);
/* pushservice_get_enabled_services.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceGetEnabledServices(PSLIBSZHASH *ppHash);
/* pushservice_revoke.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOPushserviceRevoke();
