// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNOAUTOBLOCK_API_H__
#define __SYNOAUTOBLOCK_API_H__

BOOL SYNOAutoBlockCheckDenied(const char *szAddr);
BOOL SYNOAutoBlockInWhiteList(const char *szAddr);

int SYNOAutoBlockFailLoginSetWithService(const char* szAddr, const char* szService) ;
int SYNOAutoBlockFailLoginReset(const char *szAddr);

/* administrator api, should has root permision. */
BOOL SYNOAutoBlockIsEnabled();
int SYNOAutoBlockConfGet(PAUTOBLOCKCONF pBlockConf);
int SYNOAutoBlockConfSet(const PAUTOBLOCKCONF pBlockConfNew);

int SYNOAutoBlockIpStatus(const char *szIP);
int SYNOAutoBlockIPStatusDate(const char *szIP, int *pStatus, time_t *pExpireDate, time_t *pRecordDate);
int SYNOAutoBlockIPListAdd(const PSLIBSZLIST pslIP, time_t expiretime, int type, BOOL isReplace);
int SYNOAutoBlockIPListDel(const PSLIBSZLIST pslIP);
int SYNOAutoBlockIPListDelType(const int type, const PSLIBSZLIST pslIP, PSLIBSZLIST *ppslDelList);
int SYNOAutoBlockIPListGet(const int type, const int start, const int limit, const char* szKey,
                            SYNO_AUTOBLOCKIP_COLUMN column, SYNOAUTOBLOCK_ORDER order,
                            PSYNO_AUTOBLOCK_IP_INFO* pprgBlockIP, int *pReadBlockNum, int *pTotalBlockNum);
PSYNO_AUTOBLOCK_IP_INFO SYNOAutoBlockIPInfoAlloc(int nMem);
void SYNOAutoBlockIPInfoFree(PSYNO_AUTOBLOCK_IP_INFO prgBlockIP);

// Interface extension for whitelist
int SYNOAutoBlockIPListAddEx(const PSYNO_AUTOBLOCK_IP_INFO* pprgBlockIP, int Count, time_t expiretime, int type, BOOL isReplace);
int SYNOAutoBlockIPListDelTypeEx(const int type, PSYNO_AUTOBLOCK_IP_INFO* pprgBlockIP, int Count, PSLIBSZLIST *ppslDelList);

#endif //__SYNO_AUTOBLOCK_API_H__
