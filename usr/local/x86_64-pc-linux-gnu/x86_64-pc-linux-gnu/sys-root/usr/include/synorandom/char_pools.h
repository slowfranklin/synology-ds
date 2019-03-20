/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef LIBSYNORANDOM_INCLUDE_CHAR_POOLS_H_
#define LIBSYNORANDOM_INCLUDE_CHAR_POOLS_H_

namespace SYNO {
namespace RANDOM {

/**
 * char set, including: 0987654321abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
 */
extern const char* POOL_ALPHA_NUMERIC;

/**
 * chat set, including: -_0987654321abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
 */
extern const char* POOL_URL_FRIENDLY;

}} // namespace

#endif // LIBSYNORANDOM_INCLUDE_
