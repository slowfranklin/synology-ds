// Copyright (c) 2000-2011 Synology Inc. All rights reserved.
#ifndef __SYNO_LDAP_H__
#define __SYNO_LDAP_H__

#include <sys/cdefs.h>
#include <sys/types.h>

#include <synocore/synotype.h>
#include <synocore/list.h>
#include <synocore/hash.h>

__BEGIN_DECLS;

/**
 * @addtogroup LDAP
 *
 * @brief The structure and operation of LDAP.
 *
 * @{
 */

#define MAX_NSS_ENTRYLEN 1024
#define MAX_DN_LEN 1024
#define MAX_URI_LEN 1024
#define MAX_ATTR_VALUE_LEN 1024
#define MAX_IP_ADDR_LEN 64
#define MAX_DNS_QUERY_LEN 256
#define MAX_DNS_RESPONSE_LINE_LEN 1024
#define MAX_CONF_LINE_LEN 1024
#define MAX_LDAP_PASSWORD_LEN 1024 // Should be larger than SYNO_USER_PLAIN_PWD_UTF8_MAX
#define SZK_LDAP_BINDED	"ldapbinded"
#define SZF_NSLCD_CONF "/usr/syno/etc/nslcd.conf"
#define SZF_NSLCD_CONF_TEMPLATE "/usr/syno/etc.defaults/nslcd.conf.template"
#define SZF_LDAP_SECRET "/usr/syno/etc/private/ldap.secret"
#define SZF_LDAP_SERVER_HOST_LOOKUP "/usr/syno/etc/private/ldap_server_host_lookup"
#define SZF_LDAP_SERVER_SRV_LOOKUP "/usr/syno/etc/private/ldap_server_srv_lookup"
#define SZF_LDAP_GRP_TMP "/usr/syno/etc/private/ldap_group.tmp"
#define SZF_LDAP_USER_TMP "/usr/syno/etc/private/ldap_user.tmp"
#define SZF_NSLCD_CONF_TMP "/usr/syno/etc/nslcd.conf.tmp"
#define SZF_NSLCD_CONF_BAK "/usr/syno/etc/nslcd.conf.bak"
#define SZF_NSLCD_PID_FILE "/var/run/nslcd.pid"
#define SZF_LDAP_GRP "/usr/syno/etc/private/ldap_group"
#define SZF_LDAP_USER "/usr/syno/etc/private/ldap_user"
#define SZF_LDAP_CLIENT_IDMAP_DB_FILE "/var/run/ldap_client_idmap.db"
#define SZD_NSLCD_PROFILE "/usr/syno/etc.defaults/nslcd.profile"
#define SYNO_BUILD_LDAP_USER_DB_RUN   "/tmp/ldap_user.pid"
#define SYNO_BUILD_LDAP_GROUP_DB_RUN  "/tmp/ldap_group.pid"
#define SZ_LDAP_CONF_URI "uri"
#define SZ_LDAP_CONF_BASEDN "base"
#define SZ_LDAP_CONF_BINDDN "binddn"
#define SZ_LDAP_CONF_SSL "ssl"
#define SZ_LDAP_CONF_SUFFIX "suffix"
#define SZ_LDAP_CONF_ROOTDN "rootdn"
#define SZ_LDAP_CONF_ROOTPW "rootpw"
#define SZ_LDAP_CONF_NESTED_GROUP "nss_nested_groups"
#define SZ_LDAP_CONF_LOGIN_SUFFIX "login_suffix"
#define SZ_LDAP_CONF_PROFILE	"profile"
#define SZ_LDAP_CONF_FILTER	"filter"
#define SZ_LDAP_CONF_MAP	"map"
#define SZ_LDAP_CONF_MAP_PASSWD	"passwd"
#define SZ_LDAP_CONF_MAP_SHADOW	"shadow"
#define SZ_LDAP_CONF_MAP_GROUP	"group"
#define SZ_ATTR_PARSE_SEPARATOR ":"

#define SZ_LDAP_ATTR_O "o"
#define SZ_LDAP_ATTR_OU "ou"
#define SZ_LDAP_ATTR_DC "dc"
#define SZ_LDAP_ATTR_DN "dn"
#define SZ_LDAP_ATTR_CN "cn"
#define SZ_LDAP_ATTR_UID "uid"
#define SZ_LDAP_ATTR_UIDNUMBER "uidNumber"
#define SZ_LDAP_ATTR_GIDNUMBER "gidNumber"
#define SZ_LDAP_ATTR_MEMBERUID "memberUid"
#define SZ_LDAP_ATTR_UNIQUEMEMBER "uniqueMember"
#define SZ_LDAP_ATTR_MEMBER "member"
#define SZ_LDAP_ATTR_OBJECTCLASS "objectClass"
#define SZ_LDAP_ATTR_USERPASSWD	"userPassword"
#define SZ_LDAP_ATTR_CREATE_TIMESTAMP "createTimestamp"
#define SZ_LDAP_ATTR_MODIFY_TIMESTAMP "modifyTimestamp"
#define SZ_LDAP_VALUE_POSIXACCOUNT "posixAccount"
#define SZ_LDAP_VALUE_POSIXGROUP "posixGroup"
#define SZ_LDAP_VALUE_USERS "users"
#define SZ_LDAP_VALUE_GROUPS "groups"

#define SZ_LDAP_FILTER_USERS SZ_LDAP_ATTR_OBJECTCLASS "=" SZ_LDAP_VALUE_POSIXACCOUNT
#define SZ_LDAP_FILTER_GROUPS SZ_LDAP_ATTR_OBJECTCLASS "=" SZ_LDAP_VALUE_POSIXGROUP

#define CH_LDAP_DOMAIN_SEPARATOR '@'
#define SZ_LDAP_RDN_USER SZ_LDAP_ATTR_CN "=" SZ_LDAP_VALUE_USERS
#define SZ_LDAP_RDN_GROUP SZ_LDAP_ATTR_CN "=" SZ_LDAP_VALUE_GROUPS

#define SZF_LDAPSEARCH "/usr/bin/ldapsearch"
#define SZK_UIDMAP_MIN "uidmap_min"
#define SZK_UIDMAP_MAX "uidmap_max"
#define SZK_GIDMAP_MIN "gidmap_min"
#define SZK_GIDMAP_MAX "gidmap_max"
#define SZ_SSL_NO			"no"
#define SZ_SSL_YES			"yes"
#define SZ_SSL_START_TLS	"start_tls"

/** Default user and group */
#define SZ_DIR_GROUP_ADMIN "administrators"
#define SZ_DIR_GROUP_USERS "users"
#define SZ_DIR_GROUP_MAC "staff"
#define SZ_DIR_USER_ADMIN "admin"

#define SZ_SLAPD_SERVICE_NAME "ldap-server"
#define SZF_SLAPD_SERVICE_SCRIPT SZD_SYSTEMV"/S10slapd.sh"

typedef enum {
	LDAP_SSL_NONE = 0,
	LDAP_SSL_ON,
	LDAP_SSL_TLS,
} LDAP_SSL_TYPE;

typedef enum {
	LDAP_SMB_NONE = 0,
	LDAP_SMB_PAM,
	LDAP_SMB_LDAPSAM,
} LDAP_SMB_TYPE;
/**
 * The string that represents the key of the time that LDAP
 * expire the cached data. To rebuild ldap data db.
 *
 * @see SYNOLDAPBdbIsNeedToRebuild()
 */
#define SZK_LDAP_EXPIRE_TIME	SYNO_BDB_SZK_PREFIX"SYNO@LDAP@EXPIRE@TIME"
/**
 * The expire time of ldap cache. (300sec = 5min)
 * If ldap expired time is greater than it, the ldap db
 * should rebuild.
 *
 * @see SYNOLDAPBdbIsNeedToRebuild()
 */
#define LDAP_CACHE_TIME 300

/**
 * Search filter/attributes for ldapsearch command.
 * Use SYNOLDAPSearchOptionGet() to initialize members of it.
 */
typedef struct {
	char *szFilter;
	char *szNameAttr;
	char *szIDAttr;
	BOOL blHashID;
} SYNOLDAP_SEARCH_OPTION, *PSYNOLDAP_SEARCH_OPTION;

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synosdk/ldap_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_LDAP_H__
