#ifndef __DDOJP_MESSAGE_H__
#define __DDOJP_MESSAGE_H__
#define _GNU_SOURCE
#include <synocore/synoglobal.h>
#include <string.h>

static void DdojpErrToStringKey(const char *szFailMsg, const char *szErrDesc, char *szReport, int cbReport)
{
	int i = 0;
	struct DDO_MSG {
		char *szMsg;
		char *szStrKey;
	} ddoJPMsg[] = {
		{"ドメイン名またはパスワードが違います。", "service_ddns_status_auth_hostname_failed"},
		{"メールアドレスの確認が完了していませんので、IP更新は現在ご利用いただけません。", "service_ddns_status_email_not_verified"},
		{NULL, NULL},
	};

	for (i = 0; ddoJPMsg[i].szMsg; i++) {
		if (!strcmp(ddoJPMsg[i].szMsg, szFailMsg) || 
			!strcmp(ddoJPMsg[i].szMsg, szErrDesc)) {
			StrnCP(szReport, cbReport, ddoJPMsg[i].szStrKey);
			return;
		}
	}

	StrnCP(szReport, cbReport, "service_ddns_status_client_failed");
}

#endif
