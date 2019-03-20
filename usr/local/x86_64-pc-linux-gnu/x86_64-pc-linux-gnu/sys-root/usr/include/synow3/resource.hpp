/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_RESOURCE_HPP__
#define __SYNO_W3_RESOURCE_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

#include <boost/move/core.hpp>

namespace synow3 {

class FQDNPortSchemaResource {
private:
    BOOST_COPYABLE_AND_MOVABLE(FQDNPortSchemaResource)
public:
    std::string fqdn;
    uint16_t port;
    enum Schema {
        kHTTP,
        kHTTPS
    } schema;
    static const Schema DEFAULT_SCHEMA = kHTTP;
    std::string section;
    std::string title_key;
    std::string desc;
    std::string desc_key;
    enum Protocol {
        kTCP,
        kUDP,
        kBOTH
    } protocol;
    static const Protocol DEFAULT_PROTOCOL = kTCP;
    std::string owner;

    template <typename T1>
    FQDNPortSchemaResource(
        BOOST_FWD_REF(T1) fqdn,
        uint16_t port):
        fqdn        (boost::forward<T1>(fqdn)),
        port        (port),
        schema      (DEFAULT_SCHEMA),
        protocol    (DEFAULT_PROTOCOL) {}
    template <typename T1>
    FQDNPortSchemaResource(
        BOOST_FWD_REF(T1) fqdn,
        uint16_t port,
        Schema schema):
        fqdn        (boost::forward<T1>(fqdn)),
        port        (port),
        schema      (schema),
        protocol    (DEFAULT_PROTOCOL) {}
    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    FQDNPortSchemaResource(
        BOOST_FWD_REF(T1) fqdn,
        uint16_t port,
        Schema schema,
        BOOST_FWD_REF(T2) section,
        BOOST_FWD_REF(T3) title_key,
        BOOST_FWD_REF(T4) desc,
        BOOST_FWD_REF(T5) desc_key,
        Protocol protocol,
        BOOST_FWD_REF(T6) owner):
        fqdn        (boost::forward<T1>(fqdn)),
        port        (port),
        schema      (schema),
        section     (boost::forward<T2>(section)),
        title_key   (boost::forward<T3>(title_key)),
        desc        (boost::forward<T4>(desc)),
        desc_key    (boost::forward<T5>(desc_key)),
        protocol    (protocol),
        owner       (owner) {}
    FQDNPortSchemaResource(const FQDNPortSchemaResource & p):
        fqdn(p.fqdn),
        port(p.port),
        schema(p.schema),
        section(p.section),
        title_key(p.title_key),
        desc(p.desc),
        desc_key(p.desc_key),
        protocol(p.protocol),
        owner(p.owner) {}
    FQDNPortSchemaResource(BOOST_RV_REF(FQDNPortSchemaResource) p):
        fqdn(boost::move(p).fqdn),
        port(boost::move(p).port),
        schema(boost::move(p).schema),
        section(boost::move(p).section),
        title_key(boost::move(p).title_key),
        desc(boost::move(p).desc),
        desc_key(boost::move(p).desc_key),
        protocol(boost::move(p).protocol),
        owner(boost::move(p).owner) {}
    FQDNPortSchemaResource & operator=(const FQDNPortSchemaResource & p)
    {
        if (this != &p) {
            fqdn = p.fqdn;
            port = p.port;
            schema = p.schema;
            section = p.section;
            title_key = p.title_key;
            desc = p.desc;
            desc_key = p.desc_key;
            protocol = p.protocol;
            owner = p.owner;
        }
        return *this;
    }
    FQDNPortSchemaResource & operator=(BOOST_RV_REF(FQDNPortSchemaResource) p)
    {
        if (this != &p) {
            fqdn = boost::move(p).fqdn;
            port = boost::move(p).port;
            schema = boost::move(p).schema;
            section = boost::move(p).section;
            title_key = boost::move(p).title_key;
            desc = boost::move(p).desc;
            desc_key = boost::move(p).desc_key;
            protocol = boost::move(p).protocol;
            owner = boost::move(p).owner;
        }
        return *this;
    }
};

class AliasResource {
private:
    BOOST_COPYABLE_AND_MOVABLE(AliasResource)
public:
    std::string alias;

    template <typename T1>
    AliasResource(
        BOOST_FWD_REF(T1) alias):
        alias(boost::forward<T1>(alias)) {}
    AliasResource(const AliasResource & p):
        alias(p.alias) {}
    AliasResource(BOOST_RV_REF(AliasResource) p):
        alias(boost::move(p).alias) {}
    AliasResource & operator=(const AliasResource & p)
    {
        if (this != &p) {
            alias = p.alias;
        }
        return *this;
    }
    AliasResource & operator=(BOOST_RV_REF(AliasResource) p)
    {
        if (this != &p) {
            alias = boost::move(p).alias;
        }
        return *this;
    }
};

struct ResourceManager {
    typedef boost::unordered_multimap< uint16_t, FQDNPortSchemaResource::Schema > PortSchemaMapType;
    typedef boost::unordered_map<std::pair<std::string, uint16_t>, FQDNPortSchemaResource> FQDNPortMapType;
    typedef boost::unordered_set<std::string> AliasSetType;

    PortSchemaMapType PortSchemaMap;
    FQDNPortMapType FQDNPortMap;
    AliasSetType AliasSet;

    template <class T>
    bool AquireFQDNPortSchema(BOOST_FWD_REF(T) r) {
        const std::string &section = r.section;
        if (!section.empty() && 0 == section.compare(0, 7, "synow3_")) {
            SYSLOG(LOG_ERR, "Firewall section has wrong section name");
            return false;
        }

        PortSchemaMapType::const_iterator iter1 = PortSchemaMap.find(r.port);
        if (iter1 != PortSchemaMap.end() && iter1->second != r.schema) {
            return false;
        }

        FQDNPortMapType::const_iterator iter2 = FQDNPortMap.find(std::make_pair(r.fqdn, r.port));
        if (iter2 != FQDNPortMap.end()) {
            return false;
        }

        PortSchemaMap.emplace(r.port, r.schema);
        FQDNPortMap.emplace(std::make_pair(r.fqdn, r.port), boost::forward<T>(r));

        return true;
    }
    template <class T>
    void ReleaseFQDNPortSchema(BOOST_FWD_REF(T) r) {
        PortSchemaMapType::const_iterator iter1 = PortSchemaMap.find(r.port);
        if (iter1 != PortSchemaMap.end()) {
            PortSchemaMap.quick_erase(iter1);
        }
        FQDNPortMapType::const_iterator iter2 = FQDNPortMap.find(std::make_pair(r.fqdn, r.port));
        if (iter2 != FQDNPortMap.end()) {
            FQDNPortMap.quick_erase(iter2);
        }
    }
    template <class T>
    bool AquireAlias(BOOST_FWD_REF(T) r) {
        return AliasSet.emplace(r.alias).second;
    }
    template <class T>
    void ReleaseAlias(BOOST_FWD_REF(T) r) {
        AliasSetType::const_iterator iter = AliasSet.find(r.alias);
        if (iter != AliasSet.end()) {
            AliasSet.quick_erase(iter);
        }
    }
};

} // namespace synow3

#endif // __SYNO_W3_RESOURCE_HPP__
