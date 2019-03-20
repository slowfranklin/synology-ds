#ifndef _SYNO_LOGIN_H_
#define _SYNO_LOGIN_H_

/* SYNO_OTP_PARAM_TYPE value(for iOtpType) */
#define SYNO_OTP_PARAM_TYPE_SKIP_CHECK_VALUE	0
#define SYNO_OTP_PARAM_TYPE_GET_BY_PARAM_VALUE	1
#define SYNO_OTP_PARAM_TYPE_GET_BY_CONV_VALUE	2

int SynoPAMLogin(int *pStep, const char *szUser, const char *szPass, const char *szOtp, int iOtpType, const char *szDeviceId, const char *szRemoteHost, const char *szfPamConfig, struct pam_conv *pConv);
int SynoPAMLogin_V2(int *pStep, const char *szUser, const char *szPass, const char *szOtp, int iOtpType, const char *szDeviceId, const char *szDeviceToken, const char *szDeviceAgent, const char *szRemoteHost, const char *szfPamConfig, struct pam_conv *pConv);

#endif /* _SYNO_LOGIN_H_ */
