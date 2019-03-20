/* sms_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsGet(SYNOSMS *pSmsSetting);
/* sms_free.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOSmsFree(SYNOSMS *pSmsSetting);
/* sms_read_by_tag_and_convert.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsReadByTagAndConvert(const char *szLang, const char *szTag, const char *szSepChar, char *szContent, int ContentLeng, PSLIBSZHASH *ppHashParam, const char *szTextDir);
/* sms_interval_check.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsIntervalCheck(int NeedInterval, int Interval, SYNOSMSTYPE smstype);
/* sms_conf_free.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOSmsConfFree(PSYNOSMSCONF pSmsConf);
/* sms_conf_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOSMSCONF SYNOSmsConfGet(void);
/* sms_conf_set.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsConfSet(PSYNOSMSCONF pSmsConf);
/* sms_provider_free.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOSmsProviderFree(PSYNOSMSPROVIDER pSmsProvider);
/* sms_provider_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNOSMSPROVIDER SYNOSmsProviderGet(const char *szProviderName);
/* sms_provider_set.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsProviderSet(PSYNOSMSPROVIDER pSmsProvider, const char *szOldServer);
/* sms_is_enabled.c */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOSmsIsEnabled(void);
/* sms_provider_enum.c */
SDK_STARTING_FROM(SDK_VER_6_0) PSLIBSZLIST SYNOSmsProviderEnum(void);
/* sms_set_text_dir.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsSetTextDir(SYNOSMS *pSmsSetting, const char *szTextDir);
/* sms_template_replace_api_id.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSmsTemplateReplaceApiId(const char *szProvider, const char *szApiId);
/* sms_send_message.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOSmsSendMessage(const char *szTag, PSLIBSZHASH *ppHashParam, SYNOSMS *pSmsSetting, SYNOSMSTYPE smstype, int iSmsPrefixMode);
/* sms_send_message_without_block.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOSmsSendMessageWithoutBlock(const char *szTag, PSLIBSZHASH *ppHashParam, SYNOSMS *pSmsSetting, SYNOSMSTYPE smstype, int iSmsPrefixMode);
