// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_MAIL_H__
#define __SYNO_MAIL_H__

#include <unistd.h>
#include <sys/cdefs.h>

#include <synocore/hash.h>
#include <synosmtp/synosmtp.h>

__BEGIN_DECLS;

#define SZK_SMTP_MAIL_ENABLED		"smtp_mail_enabled"
#define SZK_EVENT_SMTP				"eventsmtp"
#define	SZK_EVENT_PORT				"eventport"
#define SZK_EVENT_MAIL1				"eventmail1"
#define SZK_EVENT_MAIL2				"eventmail2"
#define SZK_EVENT_AUTH				"eventauth" 
#define SZK_EVENT_USER				"eventuser"
#define SZK_EVENT_PASS_CRYPTED		"eventpasscrypted"
#define	SZK_EVENT_SSL				"eventusessl"
#define SZK_EVENT_SUBJECT_PREFIX	"eventsubjectprefix"
#define SZK_SEND_NEWUSER_MAIL		"sendnewusermail"
#define SZK_SMTP_FROM_NAME			"smtp_from_name"
#define SZK_SMTP_FROM_MAIL			"smtp_from_mail"
#define SZK_SMTP_ERR_MSG			"smtp_err_msg"
#define SZK_SMTP_EXPIRE_IN			"smtp_expire_in"
#define SZK_SMTP_ACCESS_TOKEN			"smtp_access_token"
#define SZK_SMTP_REFRESH_TOKEN			"smtp_refresh_token"

#define SZV_SMTP_GOOGLE_OAUTH			"google_oauth"

#define SZF_SMTP_ERR_FILE		"/tmp/synosmtp_errmsg"
#define SZF_SMTP_CONF			"/usr/syno/etc/synosmtp.conf"
#define SZF_SMTP_CONF_TEMPLATE		"/usr/syno/etc.defaults/synosmtp.conf"
#define SZF_SMTP_OAUTH_CONF		"/tmp/synosmtpoauth.conf"

typedef struct _tag_SYNO_MAIL_ {
	char *szServer;
	int Port;
	int NeedAuth;
	char *szUser;
	char *szPass;
	int NeedSSL;
	char *szMail1;
	char *szMail2;
	char *szSubjectPrefix;
	char *szTextDir;
	char *szFromName;
	char *szFromMail;
} SYNOMAIL;

#ifndef NO_PROTO
#include <availability.h>
#include <synosysnotify/mail_p.h>
#endif

__END_DECLS;
#endif // __SYNO_MAIL_H__
