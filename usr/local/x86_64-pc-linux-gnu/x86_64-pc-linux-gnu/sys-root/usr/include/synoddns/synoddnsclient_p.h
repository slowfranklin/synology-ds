/* ddns_config_del.c */
int SYNODDNSConfigDel(const char *pszName);
/* ddns_config_get.c */
int SYNODDNSConfigGet(const char *pszName, DDNS_INFO *pInfo);
/* ddns_config_set.c */
int SYNODDNSConfigSet(const char *pszName, DDNS_INFO *pInfo);
/* ddns_enum_config.c */
int SYNODDNSProviderEnum(DDNS_ENUM **ppDDNSEnum);
/* ddns_enum_config_free.c */
void SYNODDNSConfigEnumFree(DDNS_ENUM *pDDNSEnum);
/* ddns_enum_section.c */
int SYNODDNSEnumSection(const char *pszFile, DDNS_ENUM **ppDDNSEnum);
void SYNODDNSEnumSectionFree(DDNS_ENUM *pDDNSEnum);
/* ddns_expired_time_get.c */
int SYNODDNSExpiredTimeGet(char *pBuf);
/* ddns_get_syno_hostname.c */
int SYNODDNSGetSynoHostname(char *buf, int bufSize);
/* ddns_get_sys_info.c */
int SYNODDNSGetSysInfo(DDNS_SYS_INFO_TYPE type, char *buf, int bufSize);
/* ddns_info_update.c */
int SYNODDNSUpdate(const char *szTarget);
/* ddns_ip_get.c */
int SYNODDNSIpGet(const char *pszName, char *pszIp, int len);
/* ddns_is_external_ip.c */
BOOL SYNOIsExternalIP(char *szIP);
/* ddns_is_heartbeat_enable.c */
int SYNODDNSIsHeartbeatEnable(void);
/* ddns_is_in_debug_mode.c */
BOOL SYNODDNSIsInDebugMode(void);
/* ddns_is_registrable.c */
BOOL SYNODDNSIsRegistrable(const char *provider);
/* ddns_is_service_enable.c */
int SYNODDNSIsServiceEnable(void);
/* ddns_provider_config_get.c */
int SYNODDNSProviderConfigGet(const char *pszName, DDNS_PROVIDER_CONF *pInfo);
/* ddns_provider_config_set.c */
int SYNODDNSProviderConfigSet(DDNS_PROVIDER_CONF *pInfo, DDNS_CONFIG_OPERATION_TYPE action);
/* ddns_provider_list.c */
int SYNODDNSGetProviderList(DDNS_PROVIDER_TYPE type, DDNS_ENUM **ppDDNSEnum);
/* ddns_reg_config_get.c */
int SYNODDNSRegConfigGet(const char *szName, DDNS_REG_CONF *pConfig);
/* ddns_status_get.c */
int SYNODDNSStatusGet(char *pszName, char *status, int sizeSt);
/* ddns_syno_account_get.c */
int SYNODDNSAccountGet(char *buf, int size);
/* ddns_syno_agent_name_get.c */
int SYNODDNSSynoUserAgentNameGet(char *szAgent, int cbAgent);
/* ddns_syno_domain_enum.c */
int SYNODDNSSynoDomainEnum(DDNS_SYNO_ENUM_DOMAIN *pReq, DDNS_SYNO_RESPONSE *pResp);
/* ddns_syno_get_report.c */
BOOL SYNODDNSSynoGetReport(char *szMsg, DDNS_MULTILANG_REPORT *pReport);
/* ddns_syno_heartbeat_api.c */
void SYNODDNSSYNOHeartBeatCurlCleanUp(void);
int SYNODDNSSynoHeartbeatPulse(DDNS_SYNO_HEARTBEAT_API *pIn, DDNS_SYNO_RESPONSE *pResp);
int SYNODDNSSynoHeartbeatStop(DDNS_SYNO_HEARTBEAT_API *pIn, DDNS_SYNO_RESPONSE *pResp);
/* ddns_syno_heartbeatd_is_alive.c */
BOOL SYNODDNSSynoHeartBeatdIsAlive(void);
/* ddns_syno_heartbeatd_start.c */
int SYNODDNSSynoHeartBeatdStart(void);
/* ddns_syno_heartbeatd_stop.c */
int SYNODDNSSynoHeartBeatdStop(void);
/* ddns_syno_hostname_api.c */
int SYNODDNSSynoHostnameCreate(DDNS_SYNO_HOSTNAME_API *pIn, DDNS_SYNO_RESPONSE *pResp);
int SYNODDNSSynoHostnameUpdate(DDNS_SYNO_HOSTNAME_API *pIn, DDNS_SYNO_RESPONSE *pResp);
/* ddns_syno_https_req_send.c */
int SYNODDNSSYNOHttpsReuseRequestSend(CURL **ppCurl, const DDNS_SYNO_REQUEST *pReq, DDNS_SYNO_RESPONSE *pResponse);
int SYNODDNSSYNOHttpsRequestSend(const DDNS_SYNO_REQUEST *pReq, DDNS_SYNO_RESPONSE *pResponse);
void SYNODDNSSYNOHttpsResponseFree(DDNS_SYNO_RESPONSE *pResponse);
/* ddns_syno_verification_mail_send.c */
int SYNODDNSSynoVerificationMailSend(DDNS_SYNO_VERIFICATION_MAIL_SEND *pIn, DDNS_SYNO_RESPONSE *pResp);
/* ddns_time_set.c */
int SYNODDNSTimeSet(const char *pszFile, const char *pszKey, unsigned int offset, char *pszTime);
/* ddns_twnic_hostname_api.c */
int SYNODDNSTWNICHostnameCreate(DDNS_SYNO_REQUEST *pReq, DDNS_SYNO_RESPONSE *pResp);
int parseTWNICMsg(int respCode, char *szReport, int sizeReport);
int UpdateTWNIC(DDNS_INFO *pDDNS, char *szURL, char *szReport, int sizeReport);
/* ddns_utf8ToPuny.c */
int TransferToPunycode(const char *src, char *dest, int destLen);
