// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_DSDEFAULT_H__
#define __SYNO_DSDEFAULT_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZF_RESTORE_TO_DEFAULT ".restore_to_default"
#define SZF_SYSTEM_CRASHED ".system_crashed"
#define SZ_ADMIN_GOOGLEAUTH_SETTINGS "/usr/syno/etc/preference/admin/google_authenticator"
#define SZK_OTP_ENFORCE_OPTION "otp_enforce_option"

#ifndef NO_PROTO
#include <synoserviceutil/dsdefault_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_DSDEFAULT_H__
