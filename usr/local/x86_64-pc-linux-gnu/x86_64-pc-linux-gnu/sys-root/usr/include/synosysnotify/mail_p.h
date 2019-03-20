/* mail_free.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOMailFree(SYNOMAIL *pMailSetting);
/* mail_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailGet(SYNOMAIL *pMailSetting);
/* mail_set.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailSet(SYNOMAIL *pMailSetting);
/* mail_read_by_tag_and_convert.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailReadByTagAndConvertReal(const char *szLang, const char *szTag, char *szSubject, int SubjectLen, char *szContent, int ContentLen, PSLIBSZHASH *ppHashParam, const char *szTextDir);
SDK_DEPRECATED_SINCE(SDK_VER_4_0, SDK_VER_5_1) int SYNOMailReadByTagAndConvert(const char *szLang, const char *szTag, char *szSubject, int SubjectLen, char *szContent, int ContentLen, PSLIBSZHASH *ppHashParam);
/* mail_smtp_error_call_back.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOMailSMTPErrorCallBack(const char *szErrStr);
/* mail_fill_smtp_struct.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailFillSMTPStruct(SYNO_SMTP *pSMTP, const SYNOMAIL *pMailSetting, const char *szFromName, const char *szReceiveMail);
/* mail_set_text_dir.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailSetTextDir(SYNOMAIL *pMailSetting, const char *szTextDir);
/* mail_send_message.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOMailSendMessage(const char *szTag, PSLIBSZHASH *ppHashParam, char *szReceiveMail, SYNOMAIL *pMailSetting);
/* mail_send_message_without_block.c */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOMailSendMessageWithoutBlock(const char *szTag, PSLIBSZHASH *ppHashParam, char *szReceiveMail, SYNOMAIL *pMailSetting);
/* mail_read_by_tag_and_convert.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailReadByTagAndConvertRealEx(const char *szLang, const char *szTag, char *szSubject, int SubjectLen, char **pszContent, PSLIBSZHASH *ppHashParam, const char *szTextDir);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailGetReplacePattens(PSLIBSZHASH * ppHashParam);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOMailReadByTag(const char *szLang, const char *szTag, char *szSubject, int SubjectLen, char **pszContent, PSLIBSZHASH *ppHashParam, const char *szTextDir);
