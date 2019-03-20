// Copyright (c) 2000-2011 Synology Inc. All rights reserved.
#ifndef __SYNO_PUSHSERVICE_H__
#define __SYNO_PUSHSERVICE_H__

#include <synocore/hash.h>

__BEGIN_DECLS

#define SZ_PUSH_SERVICE_REGISTER_PHP "register.php"
#define SZ_PUSH_SERVICE_IM_PHP "im.php"
#define SZ_PUSH_SERVICE_EVENT_PHP "event.php"
#define SZ_PUSH_SERVICE_CONNECT_PHP "connect.php"

#define SZK_PUSHSERVICE_MOBILE_ENABLE "pushservice_mobile_enabled"
#define SZK_PUSHSERVICE_MSN_ENABLE "pushservice_msn_enabled"
#define SZK_PUSHSERVICE_SKYPE_ENABLE "pushservice_skype_enabled"
#define SZK_PUSHSERVICE_MAIL_ENABLE "pushservice_mail_enabled"

#define SZK_PUSHSERVICE_DS_INFO_UPDATED "pushservice_ds_info_updated"
#define SZK_PUSHSERVICE_MSN_ACCOUNT_UPDATED "pushservice_msn_account_updated"
#define SZK_PUSHSERVICE_SKYPE_ACCOUNT_UPDATED "pushservice_skype_account_updated"
#define SZK_PUSHSERVICE_MAIL_ACCOUNT_UPDATED "pushservice_mail_account_updated"

#define SZK_PUSHSERVICE_MSN_ACCOUNT "pushservice_msn_account"
#define SZK_PUSHSERVICE_SKYPE_ACCOUNT "pushservice_skype_account"
#define SZK_PUSHSERVICE_MAIL_ACCOUNT "pushservice_mail_account"

#define SZK_PUSHSERVICE_MSN_BOT "pushservice_msn_bot"
#define SZK_PUSHSERVICE_SKYPE_BOT "pushservice_skype_bot"

#define SZK_PUSHSERVICE_LAST_SENDING_TIME "pushservice_last_sending_time"
#define SZK_PUSHSERVICE_SENDING_INTERVAL "pushservice_sending_interval"

#define SZK_PUSHSERVICE_DSTOKEN "pushservice_dstoken"
#define SZK_PUSHSERVICE_DSSERIAL "pushservice_dsserial"

#define SZ_PUSHSERVICE_MOBILE "mobile"
#define SZ_PUSHSERVICE_MSN "msn"
#define SZ_PUSHSERVICE_SKYPE "skype"
#define SZ_PUSHSERVICE_MAIL "mail"
#define SZ_PUSHSERVICE_ALL "mobile,msn,skype"

#define SZ_PUSHSERVICE_RESPONES_SUCCEESS_TRUE "\"success\":true"
#define SZ_PUSHSERVICE_RESPONSE_UNAUTHORIZED "\"message\":\"ERR_UNAUTHORIZED\""
#define SZ_PUSHSERVICE_RESPONSE_APIKEY_NOTFOUND "\"message\":\"ERR_NOTFOUND\""

#define MAX_PUSHSERVICE_DSTOKEN 46 //include '\0', no need to +1 for array

#ifndef NO_PROTO
#include <availability.h>
#include <synosysnotify/pushservice_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_PUSHSERVICE_H__
