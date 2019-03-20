/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_REVERSE_PROXY_HPP__
#define __SYNO_W3_REVERSE_PROXY_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class ReverseProxy: public W3Base {
public:
    ReverseProxy(Engine=Engine());
    virtual ~ReverseProxy();

    static void     ResourceRegister(Engine & engine);

    Json::Value     index();
    RP_STATUS       create(const Json::Value&);
    RP_STATUS       update(const Json::Value&);
    bool            destroy(const std::string&);

    virtual bool    Update();
    virtual bool    Save();
    virtual bool    Set();
    virtual bool    RestartService();

private:
    virtual void    DataInit() {}
    virtual bool    Get() { return false; }
    virtual bool    GetJson(Json::Value&) { return false; }
    virtual bool    SetJson(Json::Value&) { return false; }
    virtual void    TransJsonToVar(Json::Value& ) {}
    virtual bool    TransVarToJson(Json::Value& ) { return false; }

    Json::Value     normalize(const Json::Value&);

    struct          Private;
    Private         *_;
};

} // namespace synow3

#endif // __SYNO_W3_REVERSE_PROXY_HPP__
