/* Service */
BOOL SYNOServiceIsApp(const char* szService);
BOOL SYNOServiceIsFileProtocol(const char* szService);
BOOL SYNOServiceIsPackage(const char* szService);
BOOL SYNOServiceIsSetStopOnBootup(const char* szService);
BOOL SYNOServiceIsUserControllable(const char* szService);
BOOL SYNOServiceSupportOneClickEnable(const char* szService);
BOOL SYNOServiceSkipBootupCheck(const char* szService);
int SYNOServiceListByType(SLIB_SERVICE_TYPE type, PSLIBSZLIST *ppslOutService);
int SYNOServiceTypeAction(SLIB_SERVICE_TYPE type, SLIB_SERVICECFG_ACTION action);
int SYNOServiceTypePauseByReason(SLIB_SERVICE_TYPE type, const char *szReason);
int SYNOServiceTypeResumeByReason(SLIB_SERVICE_TYPE type, const char *szReason);
int SYNOServiceTypeReload(SLIB_SERVICE_TYPE type);
int SYNOServiceTypeRestart(SLIB_SERVICE_TYPE type);
int SYNOServicePauseAllByReason(const char *szReason, const char *szEvent, BOOL blAction);
int SYNOServicePauseAllByReasonEx(const char *szReason, const char *szEvent, BOOL blAction, BOOL blPackage);
int SYNOServiceResumeAllByReason(const char *szReason);
int SYNOServiceResumeAllByReasonEx(const char *szReason, BOOL blPackage, BOOL blMatched);
int SYNOServiceOnOffALL(SLIB_SERVICE_ACTION act);
int SYNOServiceOnOffALLByType(SLIB_SERVICE_ACTION act, const char *szType, PSLIBSZLIST pParamList);
int SYNOServiceThirdPartyAll(BOOL blStart);
int SYNOServiceThirdPartyAllByType(BOOL blStart, const char *szType, PSLIBSZLIST pParamList);
int SYNOServiceResourceForbid(const char *szResource, SLIB_SERVICECFG_CATEGORY type);
int SYNOServiceResourcePermit(const char *szResource, SLIB_SERVICECFG_CATEGORY type);
int SYNOServiceResourceRemove(const char *szResource, SLIB_SERVICECFG_CATEGORY type);
int SYNOServiceResourceRename(const char *szOriResource, const char *szNewResource, SLIB_SERVICECFG_CATEGORY category);
int SYNOServiceResourceReverseTraversal(const char *szResource, SLIB_SERVICECFG_CATEGORY type, PPSLIBSZLIST ppOutList);
int SYNOServiceSortStartList(PPSLIBSZLIST ppServList);