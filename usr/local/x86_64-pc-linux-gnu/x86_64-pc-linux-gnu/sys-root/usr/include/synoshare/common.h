// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOSHARE_COMMON_H__
#define __SYNOSHARE_COMMON_H__

__BEGIN_DECLS;

#ifdef DEBUG_ASSERTION
#include <assert.h>
#define ASSERT(exp) assert(exp)
#else
#define ASSERT(exp)
#endif

__END_DECLS;
#endif // __SYNOSHARE_COMMON_H__
