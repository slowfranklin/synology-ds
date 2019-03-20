// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

#ifndef __SYNO_DDSM_CORE_COMMUNICATE_H__
#define __SYNO_DDSM_CORE_COMMUNICATE_H__
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>

// Communication define
#define MAX_DDSM_COMMUNICATE_DATA_LENGTH 1024
#define SZD_DDSM_GUEST_CONFIG "/usr/syno/ddsm/"
#define SZ_DDSM_HOST_SOCK "ddsm_host.sock"
#define SZF_DDSM_HOST_SOCKET SZD_DDSM_GUEST_CONFIG SZ_DDSM_HOST_SOCK
__BEGIN_DECLS;

// DDSM Host Version
typedef struct _tag_ddsm_host_version {
	int majorVersion;
	int minorVersion;
	int buildNumber;
	int smallfixNumber;
}DDSM_HOST_VER;

// Communication util
typedef enum _tag_DDSMCORE_COMMUNICATE_ROLE_ {
	DDSM_COMMUNICATE_ROLE_HOST,
	DDSM_COMMUNICATE_ROLE_CONTAINER
} DDSMCORE_COMMUNICATE_ROLE;

int SocketConnectByPath(const char *szPath, int *sockfd);
int WriteDataToSocket(int sockfd, const char *pData);
int ReadDataFromSocket(int sockfd, char *pData, size_t cbData);
int SendDataToHost(const char *pszReq, char *pszResp, size_t cbResp);

// Container to Host util
int SYNODDSMIsHostHibernation(BOOL *blHibernation);
int SYNODDSMGetHostVersion(DDSM_HOST_VER *pHostInfo);
int SYNODDSMGetHostSerial(char *pszSerial, size_t cbSerial);

__END_DECLS;

#endif
