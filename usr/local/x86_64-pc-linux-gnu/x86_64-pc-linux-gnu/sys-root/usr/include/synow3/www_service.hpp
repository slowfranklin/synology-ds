/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_WWW_SERVICE_HPP__
#define __SYNO_W3_WWW_SERVICE_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

#include <boost/core/enable_if.hpp>

namespace synow3 {

class WWWService: public W3Base {
public:
    WWWService(Engine=Engine());
    virtual ~WWWService();

    static void     ResourceRegister(Engine & engine);
    uint16_t        GetHttpAddPort() const;
    bool            GetEnableHttpAddPort() const;
    uint16_t        GetHttpsAddPort() const;
    bool            GetEnableHttpsAddPort() const;
    bool            GetEnableSPDY() const;
    bool            GetEnableHSTS() const;

    std::string     GetCERT() const;
    std::string     GetKEY() const;

    virtual bool    Update();
    virtual bool    Save();
    virtual bool    Set();
    virtual bool    RestartService();

private:
    virtual void    DataInit();
    virtual bool    GetJson(Json::Value &setting);
    virtual bool    SetJson(Json::Value &setting);
    virtual void    TransJsonToVar(Json::Value &setting);
    virtual bool    TransVarToJson(Json::Value &setting);

    struct          Private;
    Private         *_;
};

} // namespace synow3

#endif // __SYNO_W3_WWW_SERVICE_HPP__
