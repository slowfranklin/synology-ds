/* domain_check_and_join.c */
int SYNOWinsCheckAndJoinDomain(PSYNOWIN2 psw2, BOOL blFoundLDAP, BOOL blSigning);
/* domain_create_krb5conf.c */
int SYNOWinsCreateKrb5Conf(PSYNOWIN2 psw2, BOOL blUseSpecifyIp, BOOL blLookupKDC);
/* domain_do_krb5login.c */
int SYNOWinsDoKrb5Login(PSYNOWIN2 psw2, BOOL blUseSpecifyIp);
/* domain_get_ou.c */
int SYNOWinsUpdateOU(void);
int SYNOWinsEnumOU(PSLIBSZLIST *pListOU, PSLIBSZLIST *pListDN);
/* domain_join1.c */
int SYNOWinsJoinDomain(void *pData);
/* domain_nsswitch_set.c */
int SYNOWinsSetDomainNsswitch(BOOL blEnable);
/* domain_read_ads_workgroup.c */
int SYNOWinsReadADSWorkgroup(char *szWGName, int len);
/* domain_search_ldap.c */
BOOL SYNOWinsLookupLDAP(char *szDomain);
/* domain_set_configs.c */
int SYNOWinsSetDomainConfig(const BOOL fDomainJoined);
/* domain_set_section_key.c */
int SYNOWinsSetSectionKey(const char *szSection, const char *szKey, const char *szValue);
/* domain_state_get.c */
int SYNOWinsJoinStateGet(char *szKey, int iKeyLen, char *szValue, int iValueLen);
/* domain_state_set.c */
int SYNOWinsJoinStateSet(const char *szKey, char *szValue);
/* domain_test_join.c */
int SYNOWinsTestJoin(BOOL blADS);
/* domain_username_fqdn2netbios.c */
int SYNOWinsUserNameFqdn2Netbios(const char *szFqdnUserName, char *szNbiosUserName, size_t cbNbiosUserName);
/* domain_workgroup.c */
int SYNOWinsWorkgroup(char *szWGName, int len, const char *szKDCIP);
/* domain_add_admin_group.c */
int SYNOWinsDomainAddAdminGroup();
/* domain_sid_get.c */
int SYNOWinsGetDomainSID(char *szSID, size_t cbSID);
/* domain_ads_joined.c */
BOOL SYNOWinsADSJoined(void);
/* domain_build_db.c */
int SYNOWinsBuildDomainDB(int iType);
/* domain_get_all_trust.c */
int SYNOWinsUpdateAllDomains(void);
int SYNOWinsEnumAllDomains(PSLIBSZLIST *pListTrust);
int SYNOWinsGetDomainFQDN(const char *szDomain, char *szFQDN, int cbFQDN);
int SYNOWinsGetDomainSidFromInfo(const char *szDomain, char *szSid, int cbSid);
/* domain_get_auth_user.c */
int SYNOWinsGetAuthUser(char *szDomain,int iDomainSize, char *szUser, int iUserSize, char *szPass,int iPassSize);
/* domain_get_kdcip.c */
int SYNOWinsGetKDCIP(char *szKDCIP, int cbNeed);
/* domain_get_pdcip.c */
int SYNOWinsGetPDCIP(char *szPDCIP);
/* domain_get_ug.c */
int SYNOWinsGetDomainUGByDomain(int iType, PSLIBSZLIST *pListDomain);
int SYNOWinsGetDomainUG(int iType, const char *szDomain);
/* domain_name_get_by_sid.c */
int SYNOWinsDomainNameGetBySid(const char *szSID, char *szName, const int cbName);
/* domain_set_auth_user.c */
void SYNOWinsSetAuthUser(char *szDomain, char *szUser, char *szPass);
/* domain_is_adserver.c */
BOOL SYNOWinsIsADServer();
/* domain_remove_schedule.c */
int SYNOWinsDomainRemoveUpdatePeriod();
/* domain_remove_options.c */
int SYNOWinsDomainRemoveOptions();
/* domain_get_ads_info.c */
int SYNOWinsGetAdsInfo(const char *szDomain);
/* domain_set_enum_options.c */
int SYNOWinsDomainEnumOptSetStart(PSYNODOMENUMOPTION pOpt, int start);
int SYNOWinsDomainEnumOptSetLimit(PSYNODOMENUMOPTION pOpt, int limit);
int SYNOWinsDomainEnumOptSetUGType(PSYNODOMENUMOPTION pOpt, int UGType);
int SYNOWinsDomainEnumOptSetDomain(PSYNODOMENUMOPTION pOpt, const char *szDomain);
int SYNOWinsDomainEnumOptSetOU(PSYNODOMENUMOPTION pOpt, const char *szOU);
int SYNOWinsDomainEnumOptSetCaseSensitiveSearch(PSYNODOMENUMOPTION pOpt, BOOL blCaseSensitive);
int SYNOWinsDomainEnumOptSetSearchType(PSYNODOMENUMOPTION pOpt, SEARCH_TYPE type);
int SYNOWinsDomainEnumOptSetSearchSubString(PSYNODOMENUMOPTION pOpt, const char *szSubString);
int SYNOWinsDomainEnumOptSetSortASC(PSYNODOMENUMOPTION pOpt, BOOL blSortASC);
int SYNOWinsDomainEnumOptAddSearchFields(PSYNODOMENUMOPTION pOpt, const char *szField);
int SYNOWinsDomainEnumOptAddSortFields(PSYNODOMENUMOPTION pOpt, const char *szField);
int SYNOWinsDomainEnumOptSetMatchListExclude(PSYNODOMENUMOPTION pOpt, BOOL blExclude);
int SYNOWinsDomainEnumOptAddMatchList(PSYNODOMENUMOPTION pOpt, const char *szField);
/* domain_core_enum.c */
int SYNOWinsDomainCoreFullDbEnum(const PSYNODOMENUMOPTION pOpt, int (*SQLite_callback)(void*,int,char**,char**), void *data);
/* domain_alloc_enum_option.c */
int SYNOWinsDomainEnumOptAlloc(PSYNODOMENUMOPTION *ppOpt);
void SYNOWinsDomainEnumOptFree(PSYNODOMENUMOPTION pOpt);
/* domain_get_lockoutDuration.c */
int SYNOWinsDomainGetLockoutDuration(const char *szDomain, char *szVal, int cbVal);
/* domain_idmap.c */
uint32_t SYNOWinsDomainSID2ID(const char *szDomSid, const char *szRid);

int SYNOWinsChangeUserPassword(const char* szUser, const char* oldPw, const char* newPw);
/* domain_ntp_time_diff.c */
int SYNOWinsDcNtpTimeDiff(void);
