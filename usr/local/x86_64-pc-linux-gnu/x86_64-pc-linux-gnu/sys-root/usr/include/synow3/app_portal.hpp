/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_APP_PORTAL_HPP__
#define __SYNO_W3_APP_PORTAL_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class AppPortal: public W3Base {
public:
    AppPortal(Engine=Engine());
    virtual ~AppPortal();

    static void         ResourceRegister(Engine & engine);
    static Json::Value  ListAlias();
    static Json::Value  ListAltPort();
    static Json::Value  ListDefaultJson();
    static Json::Value  getApps();

    std::string         GetAlias() const;
    bool                GetEnableAlias() const;
    bool                SetEnableAlias(const std::string &);
    bool                SetDisableAlias();

    uint16_t            GetHTTPAltPort() const;
    bool                GetEnableHTTPAltPort() const;
    bool                SetEnableHTTPAltPort(PortValidator port);
    bool                SetDisableHTTPAltPort();

    uint16_t            GetHTTPSAltPort() const;
    bool                GetEnableHTTPSAltPort() const;
    bool                SetEnableHTTPSAltPort(PortValidator port);
    bool                SetDisableHTTPSAltPort();

    uint16_t            GetAltPort(bool isHttps) const;
    bool                GetEnableAltPort(bool isHttps) const;
    bool                SetEnableAltPort(const bool enable, const bool isHttps, PortValidator port = 0); // if port is 0, disable

    std::string         getFQDN() const;
    bool                setFQDN(const std::string&);
    W3_ERR              setDefaultFQDN();
    W3_ERR              setFQDNEx(const std::string&);
    bool                getHSTS() const;
    bool                setHSTS(bool);
    bool                getHTTP2() const;
    bool                setHTTP2(bool);

    static bool         GetDefaultJson(const std::string&, Json::Value&);
    bool                GetApp(const std::string &confName);

    virtual bool        Update();
    virtual bool        Save();
    virtual bool        Set();
    virtual bool        RestartService();

private:
    virtual void        DataInit();
    virtual bool        GetJson(Json::Value &setting);
    virtual bool        SetJson(Json::Value &setting);
    virtual void        TransJsonToVar(Json::Value &setting);
    virtual bool        TransVarToJson(Json::Value &setting);

    static bool         GetNameFromPath(const std::string &strPath, std::string &strName);
    static bool         GetNameFromDefaultPath(const std::string &strPath, std::string &strName);
    bool                ProcessCertificate(const std::string &);

    struct              Private;
    Private             *_;
};

} // namespace synow3

#endif // __SYNO_W3_APP_PORTAL_HPP__
