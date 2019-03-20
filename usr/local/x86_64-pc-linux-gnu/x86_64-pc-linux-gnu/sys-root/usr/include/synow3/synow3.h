#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_H__
#define __SYNO_W3_H__

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <synocore/synoglobal.h>
#include <synosdk/user.h>

#ifdef __cplusplus
# include <cerrno>
# include <cstdio>
# include <cstdlib>
# include <fstream>
# include <set>
# include <sstream>
# include <string>
# include <memory>
# include <functional>
# include <json/json.h>
# include <sys/stat.h>
# include <unistd.h>
# include <glob.h>
# include <synoserviceconf/synoserviceconf.h>
# include <synocore/conf.h>
# include <synocore/proc.h>
# include <synofirewall/synofirewall.h>
# include <synofirewall/synoIptablesModule.hpp>
# include <boost/function.hpp>
# include <boost/move/unique_ptr.hpp>
# include <boost/unordered_map.hpp>
# include <boost/unordered_set.hpp>
# include <boost/uuid/uuid.hpp>
#else
# include <stdbool.h>
#endif

#ifdef __W3_PRIVATE__
# define ALIAS  "alias"
# define DESC   "desc"
# define FQDN   "fqdn"
# define HSTS   "hsts"
# define HTTP   "http"
# define HTTP2  "http2"
# define HTTPS  "https"
# define ID     "id"
# define ITEMS  "items"
# define NAME   "name"
# define PORT   "port"
# define TCP    "tcp"
# define TITLE  "title"
# define UDP    "udp"
# define UUID   "UUID"
# define ALTERNATIVE_PORT   "alternatePort"
# define APPLICATION        "application"
# define BACKEND            "backend"
# define COMPATIBILITY      "compatibility"
# define COMPRESSION        "compression"
# define DESCRIPTION        "description"
# define FRONTEND           "frontend"
# define HOSTNAME           "hostname"
# define PROTOCOL           "protocol"
# define REVERSE_PROXY      "ReverseProxy"
# define SECTION            "section"
# define VERSION            "version"
# define EXT_CONF           ".conf"
# define EXT_JSON           ".json"
# define EXT_TMP            ".tmp"
#endif

#define DEFAULT_MAX_VIRTUAL_HOST_NUM    30
#define VIRTUAL_HOST_NUM_UPPER_BOUND    100
#define SZK_MAXVHOST                    "maxvhost"

#define SZ_CERTIFICATE_SUBSCRIBER_DSM           "system"
#define SZ_CERTIFICATE_SERVICE_DSM              "FQDN"
#define SZ_CERTIFICATE_SUBSCRIBER_APP_PORTAL    "AppPortal"
/*
 * the service name of Application Portal = the file name of registered JSON w/o extension
 * e.g. File Station register a JSON configuration `FileStation.json' and the service name will be `FileStation'
 *
 */

#define SZK_SERVICE_DSM                           "DSM"
#define SZK_SERVICE_NGINX                         "nginx"
#define SZK_WEB_FW_SECTION_HTTP_SUFIX             "_http"
#define SZK_WEB_FW_SECTION_HTTPS_SUFIX            "_https"
#define SZF_NGINX_CONF_TMP                        "/var/tmp/nginx/nginx.conf"
#define SZF_JSON_CONF_DSM_DATASTORE               "/usr/syno/etc/www/DSM.json"
#define SZF_JSON_CONF_DSM_DEFAULT                 "/usr/syno/etc.defaults/www/DSM.json"
#define SZF_JSON_CONF_DSM_TMP                     "/var/tmp/nginx/DSM.json"
#define SZF_JSON_CONF_DSM_ADJUSTED                "/var/tmp/nginx/DSM.tmp"
#define SZF_FW_W3_SC                              SZD_BUILDIN_SERVICE_CONF "/synow3.sc"
#define SZF_FW_WEB_SC                             SZD_PACKAGE_SERVICE_CONF "/WebStation.sc"
#define SZF_JSON_CONF_APP_PATH_FILTER              "/usr/syno/etc/packages/*/AppPortal.json"
#define SZF_JSON_CONF_APP_PATH_HEAD                "/usr/syno/etc/packages/"
#define SZF_JSON_CONF_APP_PATH_TAIL                "/AppPortal.json"
#define SZF_JSON_CONF_APP_PATH_DEFAULT_FILTER      "/usr/syno/etc/www/app.d/*.json"
#define SZF_JSON_CONF_APP_PATH_DEFAULT_HEAD        "/usr/syno/etc/www/app.d/"
#define SZK_DEFAULT_CERT                           "/usr/syno/etc/ssl/ssl.chain.crt/server.crt"
#define SZK_DEFAULT_KEY                            "/usr/syno/etc/ssl/ssl.key/server.key"
#define SZF_JSON_CONF_WWW_DATASTORE                "/usr/syno/etc/www/WWWService.json"
#define SZF_JSON_CONF_WWW_TMP                      "/var/tmp/nginx/WWWService.json"
#define SZF_JSON_CONF_WWW_ADJUSTED                 "/var/tmp/nginx/WWWService.tmp"
#define SZF_JSON_CONF_WEB_DATASTORE                "/usr/syno/etc/packages/WebStation/WebStation.json"
#define SZF_JSON_CONF_WEB_DATASTORE_LINK           "/usr/syno/etc/www/WebStation.json"
#define SZF_JSON_CONF_WEB_TMP                      "/var/tmp/nginx/WebStation.json"
#define SZF_JSON_CONF_WEB_ADJUSTED                 "/var/tmp/nginx/WebStation.tmp"
#define SZF_JSON_CONF_WWW_FIREWARE                 "/usr/syno/etc/www/Firewall.json"
#define SZF_WEB_PATH                               "/var/services/web/"
#define SZF_NGX_PORT_443_MODE                      "/run/ngx_port_443"

#define SZK_FIREWALL_SEC_ADD_HTTP                  "http_extra"
#define SZK_FIREWALL_SEC_ADD_HTTPS                 "https_extra"
#define SZK_FIREWALL_SEC_DSM_HTTP                  "dms"
#define SZK_FIREWALL_SEC_DSM_HTTPS                 "dms_https"
#define SZK_FIREWALL_TITLE_HTTP                    "HTTP"
#define SZK_FIREWALL_TITLE_HTTPS                   "HTTPS"
#define SZK_FIREWALL_REVERSEPROXY_PREFIX           "ReverseProxy_"
#define SZK_FIREWALL_VIRTUALHOST_PREFIX            "VirtualHost_"
#define SZK_MAX_CONNECTIONS                        "max_connections"
#define SZK_SERVER_TAG                             "server_tag"

#define DSM_DEFAULT_HTTP_PORT                      5000
#define DSM_DEFAULT_HTTPS_PORT                     5001
#define WWW_DEFAULT_HTTP_PORT                      80
#define WWW_DEFAULT_HTTPS_PORT                     443
#define MINIMUM_WORKER_CONNECTIONS                 1024
#define MAXIMUM_WORKER_CONNECTIONS                 65535
#define CONNECTIONS_COEFFICIENT                    2

#define TLS_PROFILE_OLD             0x0
#define TLS_PROFILE_INTERMEDIATE    0x1
#define TLS_PROFILE_MODERN          0x2

#define SZD_W3_DATASTORE                "/usr/syno/etc/www/"
#define SZD_W3_CONFTEST                 "/var/tmp/nginx/"
#define SZF_W3_DATASTORE_REVERSE_PROXY      SZD_W3_DATASTORE "ReverseProxy" ".json"
#define SZF_W3_CANDIDATE_REVERSE_PROXY      SZD_W3_CONFTEST  "ReverseProxy" ".json"
#define SZF_W3_INTERPRETED_REVERSE_PROXY    SZD_W3_CONFTEST  "ReverseProxy" ".tmp"

__BEGIN_DECLS

extern int SYNOServiceIsHttpDefaultConf(void);

/* Engine */
extern void* SYNOW3_Engine_Initialize(void);
extern void SYNOW3_Engine_Release(void *);
extern bool SYNOW3_Engine_RegenAll(void *);
/* Firewall */
extern bool SYNOW3_Fw_RegenAll(void);

/* DSM */
extern void* SYNOW3_DSM_Initialize(void *);
extern void SYNOW3_DSM_Release(void *);
extern bool SYNOW3_DSM_Update(void *);
extern bool SYNOW3_DSM_Set(void *);
extern bool SYNOW3_DSM_Save(void *);
extern int SYNOW3_DSM_Get_HTTPPort(const void *);
extern int SYNOW3_DSM_Get_HTTPDefaultPort(const void *);
extern bool SYNOW3_DSM_Set_HTTPPort(void *, const int);
extern int SYNOW3_DSM_Get_HTTPSPort(const void *);
extern int SYNOW3_DSM_Get_HTTPSDefaultPort(const void *);
extern bool SYNOW3_DSM_Set_HTTPSPort(void *, const int);
extern bool SYNOW3_DSM_SPDY_IsEnabled(const void *);
extern bool SYNOW3_DSM_Enable_SPDY(void *);
extern bool SYNOW3_DSM_Disable_SPDY(void *);
extern bool SYNOW3_DSM_HSTS_IsEnabled(const void *);
extern bool SYNOW3_DSM_Enable_HSTS(void *);
extern bool SYNOW3_DSM_Disable_HSTS(void *);
extern bool SYNOW3_DSM_ForceSSL_IsEnabled(const void *);
extern bool SYNOW3_DSM_Enable_ForceSSL(void *);
extern bool SYNOW3_DSM_Disable_ForceSSL(void *);

/* WWWService */
extern void *SYNOW3_WWWService_Initialize(void *);
extern void SYNOW3_WWWService_Release(void *);
extern bool SYNOW3_WWWService_Update(void *);
extern bool SYNOW3_WWWService_Save(void *);
extern bool SYNOW3_WWWService_Set(void *);
extern int SYNOW3_WWWService_Get_HTTPAdditionalPort(const void *);
extern bool SYNOW3_WWWService_HTTPAdditionalPort_IsEnabled(const void *);
extern int SYNOW3_WWWService_Get_HTTPSAdditionalPort(const void *);
extern bool SYNOW3_WWWService_HTTPSAdditionalPort_IsEnabled(const void *);
extern bool SYNOW3_WWWService_SPDY_IsEnabled(const void *);
extern bool SYNOW3_WWWService_HSTS_IsEnabled(const void *);

/* WebVHost */
extern void *WebVHostInit(void *);
extern void WebVHostRelease(void *);

/* WebStation */
extern void *SYNOW3_WebStation_Initialize(void *);
extern void SYNOW3_WebStation_Release(void *);
extern bool SYNOW3_WebStation_Update(void *);
extern bool SYNOW3_WebStation_Save(void *);
extern bool SYNOW3_WebStation_Set(void *);
extern bool SYNOW3_WebStation_Web_IsEnabled(const void *);
extern bool SYNOW3_WebStation_Enable_Web(void *);
extern bool SYNOW3_WebStation_Disable_Web(void *);
extern bool SYNOW3_WebStation_UserDir_IsEnabled(const void *);
extern bool SYNOW3_WebStation_Enable_UserDir(void *);
extern bool SYNOW3_WebStation_Disable_UserDir(void *);

__END_DECLS

#ifdef __cplusplus

namespace synow3 {

typedef enum {
    NGINXCONF_OPER_NONE = -1,
    NGINXCONF_INIT,
    NGINXCONF_HUP,
    NGINXCONF_GEN_ALL,
    NGINXCONF_GEN_SC,
    NGINXCONF_GEN_NGINX,
    NGINXCONF_GET_MODE,
    NGINXCONF_FORCE_DEFAULT,
    NGINXCONF_IS_FORCED_DEFAULT
} NGINXCONF_OPERATOR;

typedef enum {
    NGINXCONF_NONE = -1,
    NGINXCONF_NORMAL,
    NGINXCONF_ABNORMAL,
    NGINXCONF_DEFAULT,
    NGINXCONF_TYPE_MAX
} NGINXCONF_TYPE;

typedef enum {
    OLD,
    INTERMEDIATE,
    MODERN
} TLS_PROFILE;

typedef enum {
    SUCCESS,
    BAD_PARAMETERS,
    FRONTEND_INVALID_FQDN,
    FRONTEND_INVALID_PORT,
    FRONTEND_FQDN_DUPLICATED,
    FRONTEND_PORT_CONFLICTED,
    BACKEND_INVALID_FQDN,
    BACKEND_INVALID_PORT,
    BACKEND_FQDN_DUPLICATED,
    BACKEND_PORT_CONFLICTED,
    NO_SUCH_MEMBER,
    INVALID_UUID,
    LOOP_DETECTED,
    CERTIFICATE_REGISTRATION
} RP_STATUS;

typedef enum {
    PORT_443_ON = 0,
    PORT_443_MULTIPLEX,
    PORT_443_OFF
} PORT_443_MODE;

enum W3_ERR {
    ERR_SUCCESS,
    ERR_INVALID_FQDN,
    ERR_FQDN_CONFLICTED,
    ERR_FQDN_ALREADY_ENABLE
};

} // namespace synow3

#include "resource.hpp"
#include "engine.hpp"
#include "validator.hpp"
#include "w3base.hpp"
#include "dsm.hpp"
#include "app_portal.hpp"
#include "www_service.hpp"
#include "web_station.hpp"
#include "web_vhost.hpp"
#include "reverse_proxy.hpp"

namespace synow3 {

class NginxConfOperator {
public:
    virtual ~NginxConfOperator() {};
    virtual int run() = 0;
    std::string GetMsg();

protected:
    std::string msg;
};

class NginxConfManager {
public:
    NginxConfManager(NGINXCONF_OPERATOR);
    ~NginxConfManager();
    int run();
    std::string GetMsg();

private:
    NginxConfOperator *oper;
};

} // namespace synow3

#endif

#endif // __SYNO_W3_H_
