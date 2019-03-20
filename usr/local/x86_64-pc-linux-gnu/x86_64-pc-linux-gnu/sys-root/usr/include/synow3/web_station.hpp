/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_WEB_STATION_HPP__
#define __SYNO_W3_WEB_STATION_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class WebStation: public W3Base {
public:
    WebStation(Engine=Engine());
    virtual ~WebStation();

    bool            GetEnableWeb() const;
    bool            SetEnableWeb();
    bool            SetDisableWeb();

    bool            GetEnableUsrDir() const;
    bool            SetEnableUsrDir();
    bool            SetDisableUsrDir();

    virtual bool    Save();
    virtual bool    Set();
    virtual bool    RestartService();

private:
    virtual void    DataInit();
    virtual void    TransJsonToVar(Json::Value &setting);
    virtual bool    TransVarToJson(Json::Value &setting);
    virtual bool    GetJson(Json::Value &setting);
    virtual bool    SetJson(Json::Value &setting);

    bool            CreateUserDir();

    struct          Private;
    Private         *_;
};

} // namespace synow3

#endif // __SYNO_W3_WEB_STATION_HPP__
