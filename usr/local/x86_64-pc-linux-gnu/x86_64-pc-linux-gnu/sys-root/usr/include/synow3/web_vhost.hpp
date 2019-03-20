/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_WEB_VHOST_HPP__
#define __SYNO_W3_WEB_VHOST_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class WebVHost: public W3Base {
public:
    WebVHost(Engine=Engine());
    virtual ~WebVHost();

    virtual bool    Update()  { return false; }
    virtual bool    Get(Json::Value&) { return false; };
    virtual bool    Save(const Json::Value&) { return false; }
    virtual bool    Set(const Json::Value& )  { return false; }
    virtual bool    RestartService()  { return false; }

private:
    virtual void    DataInit() {}
    virtual bool    GetJson(Json::Value &) { return false; }
    virtual bool    SetJson(Json::Value &) { return false; }
    virtual void    TransJsonToVar(Json::Value&) {}
    virtual bool    TransVarToJson(Json::Value&) {return false;};
};

} // namespace synow3

#endif // __SYNO_W3_WEB_VHOST_HPP__
