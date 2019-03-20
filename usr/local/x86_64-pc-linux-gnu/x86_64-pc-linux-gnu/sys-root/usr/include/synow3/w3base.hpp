/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_W3BASE_HPP__
#define __SYNO_W3_W3BASE_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

namespace synow3 {

class W3Base {
public:
    W3Base(Engine=Engine());
    virtual ~W3Base();

    Engine          engine();
    bool            OK() const;
    bool            Dirty() const;

    virtual bool    Update();
    virtual bool    Save();
    virtual bool    Set();
    virtual bool    RestartService();

protected:
    void            SetOK(bool);
    void            SetDirty(bool);

    virtual bool    Get();
    virtual void    DataInit() = 0;
    virtual bool    GetJson(Json::Value &setting) = 0;
    virtual bool    SetJson(Json::Value &setting) = 0;
    virtual void    TransJsonToVar(Json::Value &setting) = 0;
    virtual bool    TransVarToJson(Json::Value &setting) = 0;

    //If allowNull, empty file and file no exist is acceptable
    static bool     ReadJsonFile(const std::string &file, Json::Value &conf, bool allowNull);
    static bool     WriteJsonFile(const std::string &file, Json::Value &conf);
    static bool     MakeParentFolderExist(const std::string&);
    static bool     MoveFile(const std::string &, const std::string &);

protected:
    struct          Private;
    Private         *_;
};

} // namespace synow3

#endif // __SYNO_W3_W3BASE_HPP__
