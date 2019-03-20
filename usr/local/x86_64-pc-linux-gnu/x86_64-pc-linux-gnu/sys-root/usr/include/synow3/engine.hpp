/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_ENGINE_HPP__
#define __SYNO_W3_ENGINE_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

#include <boost/core/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/decay.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/move/core.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/atomic.hpp>

namespace synow3 {

class Engine {
private:
    BOOST_COPYABLE_AND_MOVABLE(Engine)
public:
    Engine(): _(new Private) {}
    Engine(const Engine &e): _(e._) {}
    Engine(BOOST_RV_REF(Engine) e): _(boost::move(e._)) {}
    Engine &operator=(const Engine &e)
    {
        if (this != &e) {
            _ = e._;
        }
        return *this;
    }
    Engine &operator=(BOOST_RV_REF(Engine) e)
    {
        if (this != &e) {
            _ = boost::move(e._);
        }
        return *this;
    }

    bool HupFirewall();
    bool W3FwReGenAll();
    bool GenerateFirewallConfig(const std::string &owner);

    template <typename T1, typename T2, typename T3>
    bool AquireFQDNPortSchema(
        BOOST_FWD_REF(T1) fqdn,
        BOOST_FWD_REF(T2) port,
        BOOST_FWD_REF(T3) schema
        ) {
        return AquireFQDNPortSchema(FQDNPortSchemaResource(fqdn, port, schema));
    }
    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    bool AquireFQDNPortSchema(
        BOOST_FWD_REF(T1) fqdn,
        BOOST_FWD_REF(T2) port,
        BOOST_FWD_REF(T3) schema,
        BOOST_FWD_REF(T4) section,
        BOOST_FWD_REF(T5) title_key,
        BOOST_FWD_REF(T6) desc,
        BOOST_FWD_REF(T7) desc_key,
        BOOST_FWD_REF(T8) protocol,
        BOOST_FWD_REF(T9) owner
        ) {
        return AquireFQDNPortSchema(FQDNPortSchemaResource(fqdn, port, schema, section, title_key, desc, desc_key, protocol, owner));
    }
    bool AquireFQDNPortSchema(const FQDNPortSchemaResource & r) {
        if (IsRuntimeTCPPortConflict(r.port)) {
            return false;
        }
        load();
        return _->manager.AquireFQDNPortSchema(r);
    }
    bool AquireFQDNPortSchema(BOOST_RV_REF(FQDNPortSchemaResource) r) {
        if (IsRuntimeTCPPortConflict(r.port)) {
            return false;
        }
        load();
        return _->manager.AquireFQDNPortSchema(boost::move(r));
    }

    template <typename T1, typename T2>
    void ReleaseFQDNPortSchema(
        BOOST_FWD_REF(T1) fqdn,
        BOOST_FWD_REF(T2) port
        ) {
        ReleaseFQDNPortSchema(FQDNPortSchemaResource(fqdn, port));
    }
    void ReleaseFQDNPortSchema(const FQDNPortSchemaResource & r) {
        load();
        _->manager.ReleaseFQDNPortSchema(r);
    }
    void ReleaseFQDNPortSchema(BOOST_RV_REF(FQDNPortSchemaResource) r) {
        load();
        _->manager.ReleaseFQDNPortSchema(boost::move(r));
    }

    bool AquireAlias(const AliasResource & r) {
        load();
        return _->manager.AquireAlias(r);
    }
    bool AquireAlias(BOOST_RV_REF(AliasResource) r) {
        load();
        return _->manager.AquireAlias(boost::move(r));
    }

    void ReleaseAlias(const AliasResource & r) {
        load();
        _->manager.ReleaseAlias(r);
    }
    void ReleaseAlias(BOOST_RV_REF(AliasResource) r) {
        load();
        _->manager.ReleaseAlias(boost::move(r));
    }

    static void Register(boost::function<void(Engine&)> callback);

    bool OK() const { return _->fd >= 0; }
    bool lock() { return _->lock(); }
    void unlock() { _->unlock(); }

private:
    void load();
    static bool IsRuntimeTCPPortConflict(uint16_t port);

    struct Private;
    struct Private {
        bool lock();
        void unlock();
        Private();
        ~Private();

        int fd;
        boost::atomic<int> loaded;
        boost::atomic<size_t> thread_id;
        ResourceManager manager;
    };
    boost::shared_ptr<Private> _;
};

} // namespace synow3

#endif // __SYNO_W3_ENGINE_HPP__
