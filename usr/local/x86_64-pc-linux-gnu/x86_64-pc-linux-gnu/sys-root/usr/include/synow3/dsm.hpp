/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_DSM_HPP__
#define __SYNO_W3_DSM_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class DSM: public W3Base {
public:
    DSM(Engine=Engine());
    virtual ~DSM();

    static void     ResourceRegister(Engine & engine);
    static int      Worker2MaxConnections(int);
    static int      MAX2WorkerConnections(int);

    uint16_t        GetHttpPort() const;
    uint16_t        GetHttpDefaultPort() const;
    bool            SetHttpPort(PortValidator port);

    uint16_t        GetHttpsPort() const;
    uint16_t        GetHttpsDefaultPort() const;
    bool            SetHttpsPort(PortValidator port);

    bool            GetEnableSPDY() const;
    bool            SetEnableSPDY(bool enable);
    bool            SetEnableSPDY();
    bool            SetDisableSPDY();

    bool            getHSTS() const;
    bool            setHSTS(bool);

    bool            GetEnableHttpsRedirect() const;
    bool            SetEnableHttpsRedirect(bool enable);
    bool            SetEnableHttpsRedirect();
    bool            SetDisableHttpsRedirect();

    std::string     getFQDN() const;
    bool            setFQDN(const std::string&);
    W3_ERR          setFQDNEx(const std::string&);

    bool            GetEnableAccessDefaultPort() const;
    bool            SetEnableAccessDefaultPort(bool enable);
    bool            SetEnableAccessDefaultPort();
    bool            SetDisableAccessDefaultPort();

    bool            getHTTPCompression() const;
    bool            setHTTPCompression(bool);

    int             getTLSProfile() const;
    bool            setTLSProfile(int);

    bool            IsCustomizedMaxConnections() const;
    int             GetMaxConnections() const;
    int             GetUpperLimitMaxConnections() const;
    int             GetLowerLimitMaxConnections() const;
    int             CorrectMaxConnections(int) const;
    bool            SetEnableCustomizedMaxConnections(bool);
    bool            SetMaxConnections(int);
    bool            GetEnableServerHeader();
    std::string     GetServerHeader();
    bool            SetServerHeader(const bool, const std::string &);

    virtual bool    Update();
    virtual bool    Set();
    virtual bool    Save();
    virtual bool    RestartService();

private:
    virtual void    DataInit();
    virtual bool    GetJson(Json::Value &setting);
    virtual bool    SetJson(Json::Value &setting);
    virtual void    TransJsonToVar(Json::Value &setting);
    virtual bool    TransVarToJson(Json::Value &setting);

    bool            ProcessCertificate();

    struct          Private;
    Private         *_;
};

} // namespace synow3

#endif // __SYNO_W3_DSM_HPP__
