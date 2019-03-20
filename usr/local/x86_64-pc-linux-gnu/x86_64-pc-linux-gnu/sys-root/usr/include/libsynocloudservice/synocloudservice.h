// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_SDK_CLOUDSERVICE_H__
#define __SYNO_SDK_CLOUDSERVICE_H__

#define MAX_API_KEY_BUFFER_SIZE 1024
#define MAX_SERIAL_NO 256
#define MAX_SN_MD5 32

#include <synocore/synotype.h>
#include <stdint.h>

__BEGIN_DECLS;

typedef struct _tag_syno_cloudservice_apikey_ {
	char szKey[MAX_API_KEY_BUFFER_SIZE];
} SYNO_CLOUDSERVICE_APIKEY;

typedef enum _tag_crypt_mode_ {
	CRYPTO_ENCRYPT = 0,
	CRYPTO_DECRYPT = 1
} CRYPT_MODE;

typedef struct _tag_crypt_packet_header_ {
	uint16_t seed1;
	uint16_t seed2;
	uint16_t seed3;
	uint16_t length;
} CRYPT_PACKET_HEADER;

typedef enum _tag_syno_cloudservice_error_code_ {
	SYNO_CLOUDSERVICE_ERR_SUCCESS         = 0,
	SYNO_CLOUDSERVICE_ERR_NETWORK         = 1,
	SYNO_CLOUDSERVICE_ERR_PARAMETER       = 2,
	SYNO_CLOUDSERVICE_ERR_SERVER_INTERNAL = 3,
	SYNO_CLOUDSERVICE_ERR_SERVER_RESPONSE = 4,
	SYNO_CLOUDSERVICE_ERR_LOCK            = 5,
	SYNO_CLOUDSERVICE_ERR_WRITE_KEY_FILE  = 6,
	SYNO_CLOUDSERVICE_ERR_NO_KEY          = 7,
	SYNO_CLOUDSERVICE_ERR_KEY_NOT_FOUND   = 8,
	SYNO_CLOUDSERVICE_ERR_UNKNWON         = 255
} SYNO_CLOUDSERVICE_ERROR_CODE;

typedef enum _tag_syno_cloudservice_handle_ {
	SYNO_CLOUDSERVICE_HANDLE_API_KEY_NOT_FOUND = 1,
	SYNO_CLOUDSERVICE_HANDLE_API_KEY_EXPIRED   = 2
} SYNO_CLOUDSERVICE_HANDLE;

#include <availability.h>
#include <libsynocloudservice/synocloudservice_p.h>

__END_DECLS;

#endif
