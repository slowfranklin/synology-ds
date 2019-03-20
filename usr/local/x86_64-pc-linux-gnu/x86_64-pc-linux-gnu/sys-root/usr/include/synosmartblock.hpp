/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#pragma once

#ifndef __cplusplus
#error "This header file is c++ only"
#endif

#include <string>
#include <vector>
#include <boost/config.hpp>
#include <synosmartblock.h>

namespace SYNO {
class SmartBlock
{
    BOOST_DELETED_FUNCTION(SmartBlock(const SmartBlock&))
    BOOST_DELETED_FUNCTION(SmartBlock& operator=(const SmartBlock&))
public:
    SmartBlock() BOOST_NOEXCEPT : context(0) {::SmartBlockInitialize(&context);}
    ~SmartBlock() BOOST_NOEXCEPT {::SmartBlockFinalize(context);}

    static uid_t GetUid(const char *user) BOOST_NOEXCEPT {return ::SmartBlockGetUid(user);}
    static uid_t GetUid(const std::string &user) BOOST_NOEXCEPT {return ::SmartBlockGetUid(user.c_str());}
    void DestroyAllToken() BOOST_NOEXCEPT {::SmartBlockDestroyAllToken(context);}
    size_t IdSize() BOOST_NOEXCEPT {return ::SmartBlockIdSize(context);}
    size_t TokenSize() BOOST_NOEXCEPT {return ::SmartBlockTokenSize(context);}
    bool TokenToId(const std::string &token, std::string &id) BOOST_NOEXCEPT {
        std::vector<char> buffer(IdSize());
        int ret = ::SmartBlockTokenToId(context, token.data(), token.size(), buffer.data(), buffer.size());
        if (0 == ret) {
            id.clear();
            id.append(buffer.data(), buffer.size());
            return true;
        } else {
            return false;
        }
    }
    bool CreateToken(uid_t uid, const std::string &ip, const std::string &agent, std::string &token) BOOST_NOEXCEPT {
        std::vector<char> buffer(TokenSize());
        int ret = ::SmartBlockCreateToken(context, uid, ip.data(), ip.size(), agent.data(), agent.size(), buffer.data(), buffer.size());
        if (0 == ret) {
            token.clear();
            token.append(buffer.data(), buffer.size());
            return true;
        } else {
            return false;
        }
    }
    bool IsValidToken(const std::string &token) BOOST_NOEXCEPT {
        return ::SmartBlockIsValidToken(context, token.data(), token.size());
    }
private:
    struct GetInfoHelperStruct {
        time_t &ctime;
        time_t &atime;
        std::string &id;
        std::string &ip;
        std::string &agent;
    };
    static void GetInfoHelper(void *data, const SmartBlockTokenInfo *info) {
        GetInfoHelperStruct &result = *reinterpret_cast<GetInfoHelperStruct*>(data);
        result.ctime = info->ctime;
        result.atime = info->atime;
        result.id = std::string(info->id, info->id_size);
        result.ip = std::string(info->ip, info->ip_size);
        result.agent = std::string(info->agent, info->agent_size);
    }
public:
    bool GetInfo(const std::string &token, time_t &ctime, time_t &atime, std::string &id, std::string &ip, std::string &agent) BOOST_NOEXCEPT {
        GetInfoHelperStruct result = {ctime, atime, id, ip, agent};
        return 0 == ::SmartBlockGetInfo(context, token.data(), token.size(), &result, GetInfoHelper);
    }
    void DestroyToken(const std::string &token) BOOST_NOEXCEPT {
        ::SmartBlockDestroyToken(context, token.data(), token.size());
    }
    bool IsTrusted(uid_t uid, const std::string &token) BOOST_NOEXCEPT {
        return ::SmartBlockIsTrusted(context, uid, token.data(), token.size());
    }
    bool Trust(uid_t uid, const std::string &token, const std::string &ip, const std::string &agent) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockTrust(context, uid, token.data(), token.size(), ip.data(), ip.size(), agent.data(), agent.size());
    }
    bool Untrust(uid_t uid, const std::string &id) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockUntrust(context, uid, id.data(), id.size());
    }
    bool UntrustAll(uid_t uid) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockUntrustAll(context, uid);
    }
    bool IsUntrustedLocked(uid_t uid) BOOST_NOEXCEPT {
        return ::SmartBlockIsUntrustedLocked(context, uid);
    }
    bool UntrustedFailed(uid_t uid, const std::string &ip, const std::string &agent) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockUntrustedFailed(context, uid, ip.data(), ip.size(), agent.data(), agent.size());
    }
    void UntrustedUnlock(uid_t uid) BOOST_NOEXCEPT {
        ::SmartBlockUntrustedUnlock(context, uid);
    }
    bool IsTrustedLocked(const std::string &token) BOOST_NOEXCEPT {
        return ::SmartBlockIsTrustedLocked(context, token.data(), token.size());
    }
    bool TrustedFailed(const std::string &token, const std::string &ip, const std::string &agent) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockTrustedFailed(context, token.data(), token.size(), ip.data(), ip.size(), agent.data(), agent.size());
    }
    void TrustedUnlock(const std::string &id) BOOST_NOEXCEPT {
        ::SmartBlockTrustedUnlock(context, id.data(), id.size());
    }
    bool IsEnabled() BOOST_NOEXCEPT {
        return ::SmartBlockIsEnabled(context);
    }
    bool ConfigGet(SmartBlockConfigKey key, uint32_t &value) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockConfigGet(context, key, &value);
    }
    bool ConfigSet(SmartBlockConfigKey key, uint32_t value) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockConfigSet(context, key, value);
    }
    bool ConfigGetAll(uint32_t values[kSmartBlockConfigMAX]) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockConfigGetAll(context, values);
    }
    bool ConfigSetAll(uint32_t values[kSmartBlockConfigMAX]) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockConfigSetAll(context, values);
    }
    bool EnumLockedAccounts(void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumLockedAccounts(context, callback_data, callback);
    }
    bool EnumLockedTokens(void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumLockedTokens(context, callback_data, callback);
    }
    bool EnumLockedAccountsLimited(int64_t offset, int64_t limit, int64_t *count, void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumLockedAccountsLimited(context, offset, limit, count, callback_data, callback);
    }
    bool EnumLockedTokensLimited(int64_t offset, int64_t limit, int64_t *count, void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumLockedTokensLimited(context, offset, limit, count, callback_data, callback);
    }
    bool EnumTrustedTokens(uid_t uid, void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumTrustedTokens(context, uid, callback_data, callback);
    }
    bool EnumTrustedTokensLimited(uid_t uid, int64_t offset, int64_t limit, int64_t *count, void *callback_data, ::SmartBlockEnumCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumTrustedTokensLimited(context, uid, offset, limit, count, callback_data, callback);
    }
    bool EnumTokens(void *callback_data, ::SmartBlockEnumTokenCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumTokens(context, callback_data, callback);
    }
    bool EnumTokensLimited(int64_t offset, int64_t limit, int64_t *count, void *callback_data, ::SmartBlockEnumTokenCallback callback) BOOST_NOEXCEPT {
        return 0 == ::SmartBlockEnumTokensLimited(context, offset, limit, count, callback_data, callback);
    }

    bool StripUsers() BOOST_NOEXCEPT {
        return 0 == ::SmartBlockStripUsers(context);
    }

private:
    ::SmartBlockContext context;
};

} // namespace SYNO
