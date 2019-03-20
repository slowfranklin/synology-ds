#ifndef _SYNO_ACCESS_TOKEN_CPP_H_
#define _SYNO_ACCESS_TOKEN_CPP_H_
#include <json/value.h>

__BEGIN_DECLS

/* SynoAccessTokenCreate => Create new token
 * uid : required, when ticket grant, the connection can use uid as role
 * strFunction: required, description of your app, it can be any string,
 * jTokenOption: option, same format of jToken. If you don't want to any option, give Json::objectValue
 * strTidOut: required, tid output
 * Return: 0 : success, -1 : error
 */
int  SynoAccessTokenCreate(uid_t &uid, std::string &strFunction, Json::Value &jTokenOption, std::string &strTidOut);

/* Quickly generate token, but do not write into DB
 * so the tid is not take effect
 * Should use with SynoAccessTokenCreateByTid
 * to make tid take effect
 */
int  SynoAccessTokenGenerate(std::string &strTidOut);

/* If generate tid by SynoAccessTokenGenerate,
 * then use this function to write DB and create token
 */
int  SynoAccessTokenCreateByTid(uid_t &uid, std::string &strFunction, Json::Value &jTokenOption, std::string &strTidIn);

/* Delete token by specify tid 
 * Return: 0 : success, -1 : error
 */
int  SynoAccessTokenDeleteByTid(std::string &strTid);

/* Delete all tokens by specify strFunction
 * Using the function can clear all ticket belong to your application
 * Return: 0 : success, -1 : error
 */
int  SynoAccessTokenDeleteByFunction(std::string &strFunction);

/* Test token is grant or not. If grant pass, the usage count will decrease by 1
 * It is convience function of SynoAccessTokenGrantEx, see the doc of SynoAccessTokenGrantEx
 * szUserOut: if grant sucess, ticket can change to a user role, it is user name
 * cbUserOut: the buffer size of szUserOut
 */
int  SynoAccessTokenGrant(std::string &strTid, const char *szWebapiName, const char *szWebapiMethod, char *szUserOut, size_t cbUserOut);

/* Test token is grant or not. If grant pass, the usage count will decrease by 1
 * strTid: required, ticket id
 * szWebapiName: required, webapi name. If ap is cgi, it will be cgi name
 * szWebapiMethod: option, if using webapi, then the method will be required. If using cgi, just specify NULL
 * jTokenObjOut: complete token can be get if grant pass
 * return < 0 => error or grant failed
 *        = 0 => grant pass
 */
int  SynoAccessTokenGrantEx(std::string &strTid, const char *szWebapiName, const char *szWebapiMethod, Json::Value &jTokenObjOut);

__END_DECLS

#endif /*_SYNO_ACCESS_TOKEN_CPP_H_ */
