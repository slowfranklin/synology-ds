/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef GLOBAL_H
#define GLOBAL_H

#define SECTOR_SIZE 512
#define INTPUT_BUFFER_SIZE 500
#define IN_RANGE(value, start, len)	((value) >= (start) && (value) < ((start) + (len)))
#define SZ_ROOT_DEVICE_PATH "/dev/root"

// Transfer number in define to strings. For example, STR(INTPUT_BUFFER_SIZE) will transfer to "500".
#define _STR(s) #s
#define STR(s) _STR(s)

#include <stdint.h>
// For 6281 and 853x and bromolowESM
#ifndef UINT64_MAX
#define UINT64_MAX 0xFFFFFFFFFFFFFFFFull
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFFul
#endif

#endif /* GLOBAL_H */
