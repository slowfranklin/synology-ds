/* proxy_internal_lib_conf.c */
/* proxy_internal_lib_ip.c */
/* proxy_internal_lib_interface.c */
/* proxy_strerror.c */
const char *SYNOProxyStrError(SYNO_PROXY_ERR error);
/* proxy_info_free.c */
int SYNOProxyInfoFree(PSYNO_PROXY_INFO pInfo);
/* proxy_setting_free.c */
int SYNOProxySettingFree(PSYNO_PROXY_SETTING pSetting);
/* proxy_info_init.c */
PSYNO_PROXY_INFO SYNOProxyInfoInit(SYNO_PROXY_TYPE type);
/* proxy_setting_init.c */
PSYNO_PROXY_SETTING SYNOProxySettingInit(void);
/* proxy_info_attr_set.c */
int SYNOProxyInfoAttrSet(PSYNO_PROXY_INFO pInfo, SYNO_PROXY_INFO_ATTR attr, const char *szValue);
/* proxy_info_attr_get.c */
char *SYNOProxyInfoAttrGet(const PSYNO_PROXY_INFO pInfo, SYNO_PROXY_INFO_ATTR attr);
/* proxy_setting_attr_set.c */
int SYNOProxySettingAttrStrSet(PSYNO_PROXY_SETTING pSetting, SYNO_PROXY_SETTING_ATTR_STR attr, const char *szValue);
int SYNOProxySettingAttrBoolSet(PSYNO_PROXY_SETTING pSetting, SYNO_PROXY_SETTING_ATTR_BOOL attr, BOOL blValue);
/* proxy_setting_attr_get.c */
char *SYNOProxySettingAttrStrGet(const PSYNO_PROXY_SETTING pSetting, SYNO_PROXY_SETTING_ATTR_STR attr);
int SYNOProxySettingAttrBoolGet(const PSYNO_PROXY_SETTING pSetting, SYNO_PROXY_SETTING_ATTR_BOOL attr, BOOL *pValue);
/* proxy_info_apply.c */
int SYNOProxyInfoApply(SYNO_PROXY_TYPE type, const PSYNO_PROXY_INFO pInfo);
/* proxy_setting_apply.c */
int SYNOProxySettingApply(const PSYNO_PROXY_SETTING pSetting);
/* proxy_get_auth.c */
int SYNOProxyGetAuth(char *szAuth, int cbAuth);
/* proxy_get_addr.c */
int SYNOProxyGetAddr(SYNO_PROXY_TYPE type, char *szAddr, int cbAddr);
/* proxy_is_need_proxy.c */
int SYNOProxyIsNeedProxy(const char *szUrl);
/* proxy_get_addr_by_url.c */
int SYNOProxyGetAddrByUrl(const char *szUrl, char *szProxyAddr, int cbProxyAddr);
