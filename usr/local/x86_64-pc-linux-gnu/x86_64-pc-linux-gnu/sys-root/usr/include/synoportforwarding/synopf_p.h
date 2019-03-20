/* lib/gwconf.c */
int SYNOGwRouterConfSet(SYNO_PF_CONF *pRouter);
SYNO_PF_CONF *SYNOPFGwRouterConfGet(void);
/* lib/rule.c */
SYNO_PF_CONF *SYNOPFRuleGetByIp(const SYNO_PF_CONF *pRuleHead, const char *szIp);
SYNO_PF_CONF *SYNOPFRuleGetByIdList(char *szRuleIdList);
SYNO_PF_CONF *SYNOPFTestRuleGetByIdList(char *szRuleIdList);
SYNO_PF_CONF *SYNOPFRuleGet(void);
SYNO_PF_CONF *SYNOPFTestRuleGet(void);
int SYNOPFRuleBuildByPath(SYNO_PF_CONF *pRuleHead, const char *szFilePath);
int SYNOPFRuleBuild(SYNO_PF_CONF *pRuleHead);
int SYNOPFTestRuleBuild(SYNO_PF_CONF *pRuleHead);
int SYNOPFRulePortTypeGet(const char *szPortSrc);
void SYNOPFRuleConfFree(PSYNO_RULECONF pRuleConf);
BOOL SYNOPFIsValidPortNo(long port);
BOOL SYNOPFIsValidProto(char *szProto);
int SYNOPFCountRuleByPath(BOOL blSupportRange, const char *szFilePath);
int SYNOPFCountRuleConf(BOOL blSupportRange);
int SLIBPFCountRuleConf(SYNO_PF_CONF *pRule, BOOL blSupportRange);
int SYNOPFRuleConfGet(PSYNO_RULECONF *ppRuleConf, BOOL blSupportRange);
int SYNOPFTestRuleConfGet(PSYNO_RULECONF *ppRuleConf, BOOL blSupportRange);
/* lib/crypt.c */
FILE *SYNOPFFileCrypt(const char *szInputFile);
/* lib/routerdb.c */
char *GetRouterDBPath(void);
int SYNOPFRouterDBUpdate(void);
int SYNOPFRouterDBVersionGet(void);
int RouterDBList(SLIBSZLIST **pslRouter);
int SYNOPFRouterDBLoadDescAndOpsByIp(SYNO_PF_CONF *pRouter, SYNO_PF_CONF **pRouterDesc, SYNO_PF_SCRIPT **pRouterScript);
void SYNORouterScriptFree(SYNO_PF_SCRIPT *pHead);
int RouterDBLoad(const char *szRouterPath, SYNO_PF_SCRIPT **pRouter, BOOL blEncrypt);
SYNO_PF_SCRIPT *RouterDBOpsGetSection(SYNO_PF_SCRIPT *pConf, const char *szSection);
/* lib/misc.c */
void SYNOPFInit(void);
void SYNOPFFree(void);
void SYNOPFReportProgress(char *szSecName, int iJobId);
int SYNOPFGetFunctionParam(char *szSrc, char szOut[][1024], int nElement);
char *SYNOPFGetDescPageByUrl(SYNO_PF_SCRIPT *pUrl);
int SYNOPFCountJobNumber(const SYNO_PF_CONF *pRuleList, const char *szRouterIp, const char *szJobName);
int SYNOPFHashNodeAppend(SYNO_PF_CONF **pList, SYNO_PF_CONF *pNew);
SYNO_PF_SCRIPT *SYNOPFListNodeNew(const char *szSecName);
SYNO_PF_CONF *SYNOPFHashNodeNew(const SYNO_PF_CONF *pNodeSrc, const char *szSecName);
int SYNOPFFileEnumSectionByFd(FILE *pfInput, PSLIBSZLIST *ppList);
int SYNOPFFileGetSectionByFd(FILE *pfInput, const char *szSection, PSLIBSZHASH *ppHash);
int SYNOPFFileGetSectionByFdWithList(FILE *pfInput, const char *szSection, PSLIBSZLIST *ppList);
void SYNOPFCopyHash(PSLIBSZHASH pFrom, PSLIBSZHASH *ppTo);
void SYNNOPFAddRuleId(const SYNO_PF_CONF *pCurrJob);
int SYNOPFGetCurrentRuleId(const SYNO_PF_CONF *pCurrJob, SYNO_PF_CONF *pDesc, char *szNewId, int iNewId);
void SYNOPFInitRouterVar(SYNO_PF_ROUTER_VAR *pRouterVar);
int SYNOPFCountNodeNumber(const SYNO_PF_CONF *pJobList, const char *szSecName);
int SYNOPFCountAlignmentSize(int iSize);
int SYNOPFReplaceString(char *szIn, char *szOut, int cbOut, char *szOld, char *szNew);
int SYNOPFAppendString(char **szSrc, int iSrc, const char *szNew);
int SYNOPFCountPortNum(const char *szPortToken);
/* lib/cgiclient.c */
int CGIReplaceVarOneByCustomOp(const char *szUrl, char *szOut, int cbOut, char *szCustomType);
int SYNOPFCGISplitUrlAndParam(char *szSrc, char *szUrl, int nUrl, char *szParam, int nParam);
int SYNOPFCGIReplaceVarByUrl(char *szOpCmd, char **szCmdUrl, const SYNO_PF_CONF *pJob, int iJobId, SYNO_PF_CONF *pCurrRouter, SYNO_PF_CONF *pDesc);
int SYNOPFCGIRunJobList(const SYNO_PF_CONF *pJobList, SYNO_PF_CONF *pRouter, int iStartJobId);
int SYNOPFCGIAppendParam(int iPos, char **szUrl, int iUrl, const char *szNew);
/* lib/job.c */
int SYNOPFRuleToJobList(SYNO_PF_CONF *pRouterDesc, SYNO_PF_CONF *pRuleCurr, SYNO_PF_CONF **pJobList);
int SYNOPFRunSpecificJob(SYNO_PF_CONF *pRuleCurr, SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc, const char *szJobName);
/* lib/cgicurl.c */
int SYNOPFCurlRunParamContainer(SYNO_PF_PARAMETER_CONTAINER *pContainer, char *szfCGIOutput);
FILE *SYNOPFPopenParamContainer(SYNO_PF_PARAMETER_CONTAINER *pContainer);
SYNO_PF_PARAMETER_CONTAINER *SYNOPFCreateParamContainer(void);
void SYNOPFFreeParamContainer(SYNO_PF_PARAMETER_CONTAINER *pContainer);
int SYNOPFPushParam(SYNO_PF_PARAMETER_CONTAINER *pContainer, char *szParam);
int SYNOPFCGIUrlToCurlCmd(char *szOpCmd, SYNO_PF_PARAMETER_CONTAINER **pOutCurlCmd, SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc, const char *szOpSectionName);
/* lib/router_desc.c */
BOOL SYNOPFblUsePost(const char *szOpSectionName, SYNO_PF_CONF *pDesc);
BOOL SYNOPFIsAddPerRule(SYNO_PF_CONF *pRouterDesc, const char *szPage);
int SYNOPFRouterPortTypeGet(SYNO_PF_CONF *pRouterDesc, const char *szPage);
int SYNOPFRouterUserPassGet(SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc, char **szUser, char **szPass);
/* lib/router_script.c */
void SYNOPFRemoveReduant(PSLIBSZLIST *ppScript, const SYNO_PF_CONF *pJob, int iJobId, SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc);
void SYNOPFExpandScript(PSLIBSZLIST *ppScript, const SYNO_PF_CONF *pJob, int iJobId, const SYNO_PF_CONF *pDesc);
/* lib/pf_config.c */
char *SYNOPFConfGetValueByKey(const SYNO_PF_CONF *pConf, const char *szSection, const char *szKey);
int SYNOPFConfGet(SYNO_PF_CONF **ppConf, const char *szFile, BOOL blRouterDB, BOOL blEncrypt, const char *szSection);
int SYNOPFConfSet(SYNO_PF_CONF *pConf, const char *szFile);
void SYNOPFConfFree(SYNO_PF_CONF *pHead);
const char *SYNOPFRuleConfPathGet(void);
/* module/module_webpage_get.c */
int SYNOPFModuleWebPageGet(char *szParam, SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc, char *szOpSectionName);
/* module/flow_module_if_greater_than.c */
int SYNOPFModuleFlowIfGreaterThan(char *szUrl);
/* module/module_run.c */
int SYNOPFModuleInit(void);
int SYNOPFModuleFree(void);
int WebpageInputGet(char *szFilePath, char *szParamName, char *szOut, int cbOut);
int Str2Md5Hex(char *szInput, char *szOutput, int cbOutput);
int Str2Md5Base64(char *szInput, char *szOutput, int cbOutput);
int SYNOPFModuleRun(char *szCustomOpName, SYNO_PF_CONF *pRouter, SYNO_PF_CONF *pDesc, char *szPage, char *szOpSectionName, const SYNO_PF_CONF *pCurrJob, int iJobId);
/* module/flow_module_sleep.c */
int SYNOPFModuleFlowSleep(char *szUrl);
