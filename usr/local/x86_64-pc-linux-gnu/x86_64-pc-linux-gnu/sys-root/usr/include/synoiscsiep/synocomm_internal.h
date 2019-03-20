#include <synoiscsiep/synocomm_macro_internal.h>
#include <synocomm/synocomm_types.h>

#ifndef _SYNOISCSIEP_SYNOCOMM_INTERNAL_H_
#define _SYNOISCSIEP_SYNOCOMM_INTERNAL_H_

#ifdef __cplusplus
__SYNO_BEGIN_DECLS
#endif // __cplusplus

typedef struct _syno_appcomm_ {
	void *comm_app;
} SYNOAPPCOMM, *P_SYNOAPPCOMM;

typedef struct _syno_engcomm_ {
	void *pPRqRx;
	void *pPRqSn;
	void *pSRqLn;
} SYNOENGCOMM, *P_SYNOENGCOMM;

typedef struct _syno_comm_envelope_ {
	void *pData;
} SYNOCOMM_ENVELOPE, *P_SYNOCOMM_ENVELOPE;

//#define SYNOCOMM_EXPORT
#ifdef SYNOCOMM_EXPORT
#define SYNOCOMM_DLL_EXP_API __declspec(dllexport)
SYNOCOMM_DLL_EXP_API int DestroySynoComm(P_SYNOAPPCOMM pComm);
SYNOCOMM_DLL_EXP_API int InitSynoComm(P_SYNOAPPCOMM pComm, const char *app_name);
SYNOCOMM_DLL_EXP_API P_SYNOAPPCOMM CreateSynoComm(const char *app_name);
SYNOCOMM_DLL_EXP_API const char *GetGlobalHostName(void);
SYNOCOMM_DLL_EXP_API const char *GetGlobalHostIP(void);
SYNOCOMM_DLL_EXP_API int SynoCommConnect(P_SYNOAPPCOMM pComm, const char *remote_hostip, const char *app_name);
SYNOCOMM_DLL_EXP_API int SynoCommDisconnect(P_SYNOAPPCOMM pComm, int fd);
SYNOCOMM_DLL_EXP_API int SynoCommIsConnect(P_SYNOAPPCOMM pComm, const char *remote_hostip, const char *app_name);
SYNOCOMM_DLL_EXP_API int CommSendMessage(P_SYNOAPPCOMM pComm, int fd, const char *data, int len);
SYNOCOMM_DLL_EXP_API int CommRecvMessage(P_SYNOAPPCOMM pComm, char *data, int len);
SYNOCOMM_DLL_EXP_API P_SYNOENGCOMM CreateEngComm(void);
SYNOCOMM_DLL_EXP_API int StartEngCommSockServer(P_SYNOENGCOMM pEngComm);
SYNOCOMM_DLL_EXP_API int StopEngCommSockServer(P_SYNOENGCOMM pEngComm);
SYNOCOMM_DLL_EXP_API int StartEngCommPipeServer(P_SYNOENGCOMM pEngComm);
SYNOCOMM_DLL_EXP_API int StopEngCommPipeServer(P_SYNOENGCOMM pEngComm);

SYNOCOMM_DLL_EXP_API int InitSynoCommEvlp(P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API P_SYNOCOMM_ENVELOPE CreateSynoCommEvlp(void);
SYNOCOMM_DLL_EXP_API void FreeSynoCommEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API void ReleaseSynoCommEvlp(P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API int CommRecvEvlp(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API char *CommGetEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API int CommRetEvlp(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp, char *data, int len);
SYNOCOMM_DLL_EXP_API char *CommGetEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
SYNOCOMM_DLL_EXP_API int CommGetEvlpFD(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp);

#else // SYNOCOMM_EXPORT
extern int DestroySynoComm(P_SYNOAPPCOMM pComm);
extern int InitSynoComm(P_SYNOAPPCOMM pComm, const char *app_name);
extern P_SYNOAPPCOMM CreateSynoComm(const char *app_name);
extern const char *GetGlobalHostName(void);
extern const char *GetGlobalHostIP(void);
extern int SynoCommConnect(P_SYNOAPPCOMM pComm, const char *remote_hostip, const char *app_name);
extern int SynoCommDisconnect(P_SYNOAPPCOMM pComm, int fd);
extern int SynoCommIsConnect(P_SYNOAPPCOMM pComm, const char *remote_hostip, const char *app_name);
extern int CommSendMessage(P_SYNOAPPCOMM pComm, int fd, const char *data, int len);
extern int CommUSendMessage(P_SYNOAPPCOMM pComm, void *pToUUID, const char *data, int len);
extern int CommRecvMessage(P_SYNOAPPCOMM pComm, char *data, int len);
extern P_SYNOENGCOMM CreateEngComm(void);
extern int StartEngCommSockServer(P_SYNOENGCOMM pEngComm);
extern int StopEngCommSockServer(P_SYNOENGCOMM pEngComm);
extern int StartEngCommPipeServer(P_SYNOENGCOMM pEngComm);
extern int StopEngCommPipeServer(P_SYNOENGCOMM pEngComm);

extern int InitSynoCommEvlp(P_SYNOCOMM_ENVELOPE pEvlp);
extern P_SYNOCOMM_ENVELOPE CreateSynoCommEvlp(void);
extern void FreeSynoCommEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
extern void ReleaseSynoCommEvlp(P_SYNOCOMM_ENVELOPE pEvlp);
extern int CommRecvEvlp(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp);
extern char *CommGetEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
extern int CommRetEvlp(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp, char *data, int len);
extern char *CommGetEvlpData(P_SYNOCOMM_ENVELOPE pEvlp);
extern int CommGetEvlpFD(P_SYNOAPPCOMM pComm, P_SYNOCOMM_ENVELOPE pEvlp);

#endif // SYNOCOMM_EXPORT

#ifdef __cplusplus
__SYNO_END_DECLS
#endif // __cplusplus

#endif // _SYNOISCSIEP_SYNOCOMM_INTERNAL_H_
