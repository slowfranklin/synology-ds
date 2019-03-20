/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#pragma once

#ifdef __cplusplus
#include <cstdlib>
#include <cstdint>
#else
#include <stdlib.h>
#include <stdint.h>
#endif

#include <sys/types.h>
#ifdef __cplusplus
extern "C" {
#endif

struct s_SmartBlockContext;
typedef struct s_SmartBlockContext * SmartBlockContext;

// config key
typedef enum {
    kSmartBlockConfigMIN,

    kSmartBlockConfigEnable = kSmartBlockConfigMIN,
    kSmartBlockConfigUntrustTry,
    kSmartBlockConfigUntrustMinute,
    kSmartBlockConfigUntrustLock,
    kSmartBlockConfigTrustTry,
    kSmartBlockConfigTrustMinute,
    kSmartBlockConfigTrustLock,

    kSmartBlockConfigMAX,
} SmartBlockConfigKey;

typedef struct {
    time_t time;
    const char * id;
    size_t id_size;
    const char * ip;
    size_t ip_size;
    const char * agent;
    size_t agent_size;
} SmartBlockLockInfo;

typedef struct {
    time_t ctime;
    time_t atime;
    const char * id;
    size_t id_size;
    const char * ip;
    size_t ip_size;
    const char * agent;
    size_t agent_size;
} SmartBlockTokenInfo;

typedef void (*SmartBlockEnumCallback)(void *, const SmartBlockLockInfo *);
typedef void (*SmartBlockEnumTokenCallback)(void *, const SmartBlockTokenInfo *);

uid_t  SmartBlockGetUid(const char *user);

int    SmartBlockInitialize(SmartBlockContext *pcontext);
int    SmartBlockFinalize(SmartBlockContext context);

int    SmartBlockDestroyAllToken(SmartBlockContext context);
size_t SmartBlockIdSize(SmartBlockContext context);
size_t SmartBlockTokenSize(SmartBlockContext context);
int    SmartBlockTokenToId(SmartBlockContext context, const char *token, size_t token_size, char *id, size_t id_size);
int    SmartBlockCreateToken(SmartBlockContext context, uid_t uid, const char *ip, size_t ip_size, const char *agent, size_t agent_size, char *token, size_t token_size);
int    SmartBlockCreateTokenAlloc(SmartBlockContext context, uid_t uid, const char *ip, size_t ip_size, const char *agent, size_t agent_size, char **token);
int    SmartBlockIsValidToken(SmartBlockContext context, const char *token, size_t token_size);
int    SmartBlockGetInfo(SmartBlockContext context, const char *token, size_t token_size, void *callback_data, SmartBlockEnumTokenCallback callback);
void   SmartBlockDestroyToken(SmartBlockContext context, const char *token, size_t token_size);

int    SmartBlockIsTrusted(SmartBlockContext context, uid_t uid, const char *token, size_t token_size);
int    SmartBlockTrust(SmartBlockContext context, uid_t uid, const char *token, size_t token_size, const char *ip, size_t ip_size, const char *agent, size_t agent_size);
int    SmartBlockUntrust(SmartBlockContext context, uid_t uid, const char *id, size_t id_size);
int    SmartBlockUntrustAll(SmartBlockContext context, uid_t uid);

int    SmartBlockIsUntrustedLocked(SmartBlockContext context, uid_t uid);
int    SmartBlockUntrustedFailed(SmartBlockContext context, uid_t uid, const char *ip, size_t ip_size, const char *agent, size_t agent_size);
void   SmartBlockUntrustedUnlock(SmartBlockContext context, uid_t uid);

/* assume valid token */
int    SmartBlockIsTrustedLocked(SmartBlockContext context, const char *token, size_t token_size);
int    SmartBlockTrustedFailed(SmartBlockContext context, const char *token, size_t token_size, const char *ip, size_t ip_size, const char *agent, size_t agent_size);
void   SmartBlockTrustedUnlock(SmartBlockContext context, const char *id, size_t id_size);

int    SmartBlockIsEnabled(SmartBlockContext context);
int    SmartBlockConfigGet(SmartBlockContext context, SmartBlockConfigKey key, uint32_t *value);
int    SmartBlockConfigSet(SmartBlockContext context, SmartBlockConfigKey key, uint32_t value);
int    SmartBlockConfigGetAll(SmartBlockContext context, uint32_t values[kSmartBlockConfigMAX]);
int    SmartBlockConfigSetAll(SmartBlockContext context, uint32_t values[kSmartBlockConfigMAX]);

int    SmartBlockEnumLockedAccounts(SmartBlockContext context, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumLockedTokens(SmartBlockContext context, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumLockedAccountsLimited(SmartBlockContext context, int64_t offset, int64_t limit, int64_t *count, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumLockedTokensLimited(SmartBlockContext context, int64_t offset, int64_t limit, int64_t *count, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumTrustedTokens(SmartBlockContext context, uid_t uid, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumTrustedTokensLimited(SmartBlockContext context, uid_t uid, int64_t offset, int64_t limit, int64_t *count, void *callback_data, SmartBlockEnumCallback callback);
int    SmartBlockEnumTokens(SmartBlockContext context, void *callback_data, SmartBlockEnumTokenCallback callback);
int    SmartBlockEnumTokensLimited(SmartBlockContext context, int64_t offset, int64_t limit, int64_t *count, void *callback_data, SmartBlockEnumTokenCallback callback);

int    SmartBlockStripUsers(SmartBlockContext context);

#ifdef __cplusplus
} // extern "c"

#endif
