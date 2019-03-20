// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_NET_H_
#define __SYNO_HWCTL_NET_H_

#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZK_WOL_SUPPORT             "support_wol"
#define SZK_WOL_OPTIONS_POSTFIX     "_wol_options"
#define SZK_WOL_ENABLE_OPTIONS      "wol_enabled_options"

BOOL SYNONetWOLIsEnabled(const char *szDev);
int SYNONetWOLEnable(const char *szDev, const BOOL blEnable);

__END_DECLS;
#endif /* __SYNO_HWCTL_NET_H_ */
