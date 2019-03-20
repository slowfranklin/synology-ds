/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef LIBSYNORANDOM_INCLUDE_SYNO_RANDOM_H_
#define LIBSYNORANDOM_INCLUDE_SYNO_RANDOM_H_
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
/**
 * Get a random string, use POOL_ALPHA_NUMERIC as character pool
 * @param  length           string length
 * @param  szRandomString   output string
 * @param  randomStringSize output string size
 * @return                  0 when success
 * @return                  -1 when error
 */
int GetRandomString(size_t length, char *szRandomString, size_t randomStringSize);
#ifdef __cplusplus
}
#endif

#endif //LIBSYNORANDOM_INCLUDE_SYNO_RANDOM_H_
