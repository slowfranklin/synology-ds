// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOSHARE_ATTR_H__
#define __SYNOSHARE_ATTR_H__

#include <synocore/synotype.h>

__BEGIN_DECLS;

typedef enum {
	SHARE_ATTR_UUID = 0,
	SHARE_ATTR_READONLY,
	SHARE_ATTR_LAST,  // just to specify upper bound of ID
} SHARE_ATTR_ID;

#ifndef NO_PROTO
#include "attr_p.h"
#endif  // NO_PROTO

__END_DECLS;

#endif  // __SYNOSHARE_ATTR_H__
