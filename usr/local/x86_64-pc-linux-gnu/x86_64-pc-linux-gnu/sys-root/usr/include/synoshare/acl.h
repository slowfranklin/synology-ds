// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOSHARE_ONLY_ACL_H__
#define __SYNOSHARE_ONLY_ACL_H__

#include <synosdk/share.h>
#include <synoacl/synoacl.h>

__BEGIN_DECLS;

#define SHARE_NONSET	0x0000
#define SHARE_CUSTOM	0x0008

#define IS_SHARE_SUPPORT_ACL(path) SYNOShareIsSupportAclByPath(path)

#ifndef NO_PROTO
#include "acl_p.h"
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNOSHARE_ONLY_ACL_H__
