// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_BASE64_H__
#define __SYNO_BASE64_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

/**
 * @addtogroup BASE64
 *
 * Base64 module is for base64 encoding.
 * Note that there are some encoding functions to encode a null-terminated string or a binary string, with a given buffer or a statically allocated buffer.
 *
 * @brief Base64 encoding and decoding functions.
 *
 * @{
 */

#define MAX_SMBPASSWD_LEN	33
#define ENCODE_MAX_LEN		3072

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/base64_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif  /* __SYNO_BASE64_H__ */
