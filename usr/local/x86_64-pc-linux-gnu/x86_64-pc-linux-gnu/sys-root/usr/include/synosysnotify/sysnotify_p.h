/* sysnotify_check_notification_target.c */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOSysNotifyCheckNotificatonTarget(const char *szTag, const char *szTarget);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOSysNotifyCheckNotificationTargetCustomized(const char *szTag, const char *szTarget, const char *szTargetFilterPath);
/* sysnotify_send_notification.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySendNotifiction(const char *szTag, PSLIBSZHASH *ppHashParam);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySendNotifictionEx(const char *szTag, PSLIBSZHASH *ppHashParam, BOOL blWithBlock);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySendNotificationCustomized(const char *szTag, const char *szTextDir, const char *szTargetFilterPath, PSLIBSZHASH *ppHashParam, BOOL blWithBlock);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySendNotificationCustomizedEx(const char *szTag, const char *szTextDir, const char *szTargetFilterPath, PSLIBSZHASH *ppHashParam, BOOL blWithBlock, int iSmsPrefixMode);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySendNotificationCustomizedEx2(const char *szTag, const char *szLang, const char *szTextDir, const char *szTargetFilterPath, PSLIBSZHASH *ppHashParam, BOOL blWithBlock, int iSmsPrefixMode);
/* sysnotify_get_notification_content.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifyGetNotificationContent(const char *szInFile, const char *szTag, char *szSubject, int cbSubject, char *szContent, int cbContent);
/* sysnotify_set_notification_content.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifySetNotificationContent(const char *szTag, const char *szSubject, const char *szContent);
/* sysnotify_delete_notification_content.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSysNotifyDeleteNotificationContent(const char *szTag);
/* personal/send_notification.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOSendPersonalNotifiction(const char *szTag, const char *szUsername, const char *szPkgName, PSLIBSZHASH *ppHashParam);

/* utils/utils.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOHashToJsonString(PSLIBSZHASH *ppHashParam, char **pszJson);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOJsonStringToHash(const char *szJsonString, PSLIBSZHASH *ppHashParam);
