#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/*
 * Copyright (c) 1990,1993 Regents of The University of Michigan.
 * All Rights Reserved.  See COPYRIGHT.
 */

#ifndef AFPD_GLOBALS_H
#define AFPD_GLOBALS_H 1

#include <sys/param.h>
#include <grp.h>
#include <sys/types.h>

#ifdef HAVE_NETDB_H
#include <netdb.h>  /* this isn't header-protected under ultrix */
#endif /* HAVE_NETDB_H */

#include <atalk/afp.h>
#include <atalk/compat.h>
#include <atalk/unicode.h>
#include <atalk/uam.h>
#include <atalk/iniparser.h>
#ifdef MY_ABC_HERE
#include <synosdk/user.h>
#include <pwd.h>
#include <stdio.h>
#endif
#ifdef WITH_DTRACE
#include <atalk/afp_dtrace.h>
#else
/* List of empty dtrace macros */
#define AFP_AFPFUNC_START(a,b)
#define AFP_AFPFUNC_DONE(a, b)
#define AFP_CNID_START(a)
#define AFP_CNID_DONE()
#define AFP_READ_START(a)
#define AFP_READ_DONE()
#define AFP_WRITE_START(a)
#define AFP_WRITE_DONE()
#endif

/* #define DOSFILELEN 12 */             /* Type1, DOS-compat*/
#define MACFILELEN 31                   /* Type2, HFS-compat */
#define UTF8FILELEN_EARLY 255           /* Type3, early Mac OS X 10.0-10.4.? */
/* #define UTF8FILELEN_NAME_MAX 765 */  /* Type3, 10.4.?- , getconf NAME_MAX */
/* #define UTF8FILELEN_SPEC 0xFFFF */   /* Type3, spec on document */
/* #define HFSPLUSFILELEN 510 */        /* HFS+ spec, 510byte = 255codepoint */

#ifdef MY_ABC_HERE
#define MAXUSERLEN SYNO_USERNAME_UTF8_MAX+1
#else
#define MAXUSERLEN 256
#endif

#define DEFAULT_MAX_DIRCACHE_SIZE 8192

#ifdef MY_ABC_HERE
#define OPTION_CUSTOMLOG	 (1 << 20) /* set log flag to avoid fd been closed while daemonize */
#endif
#define OPTION_DEBUG         (1 << 0)
#define OPTION_CLOSEVOL      (1 << 1)
#define OPTION_SERVERNOTIF   (1 << 2)
#define OPTION_NOSENDFILE    (1 << 3)
#define OPTION_VETOMSG       (1 << 4) /* whether to send an AFP message for veto file access */
#define OPTION_AFP_READ_LOCK (1 << 5) /* whether to do AFP spec conforming read locks (default: no) */
#define OPTION_ANNOUNCESSH   (1 << 6)
#define OPTION_UUID          (1 << 7)
#define OPTION_ACL2MACCESS   (1 << 8)
#define OPTION_NOZEROCONF    (1 << 9)
#define OPTION_ACL2MODE      (1 << 10)
#define OPTION_SHARE_RESERV  (1 << 11) /* whether to use Solaris fcntl F_SHARE locks */
#define OPTION_DBUS_AFPSTATS (1 << 12) /* whether to run dbus thread for afpstats */
#define OPTION_SPOTLIGHT     (1 << 13) /* whether to initialize Spotlight support */
#define OPTION_SPOTLIGHT_VOL (1 << 14) /* whether spotlight shall be enabled by default for volumes */
#define OPTION_RECVFILE      (1 << 15)
#define OPTION_SPOTLIGHT_EXPR (1 << 16) /* whether to allow Spotlight logic expressions */

#define PASSWD_NONE     0
#define PASSWD_SET     (1 << 0)
#define PASSWD_NOSAVE  (1 << 1)
#define PASSWD_ALL     (PASSWD_SET | PASSWD_NOSAVE)

#define IS_AFP_SESSION(obj) ((obj)->dsi && (obj)->dsi->serversock == -1)

/**********************************************************************************************
 * Ini config sections
 **********************************************************************************************/

#define INISEC_GLOBAL "Global"
#define INISEC_HOMES  "Homes"

struct DSI;
#define AFPOBJ_TMPSIZ (MAXPATHLEN)

struct afp_volume_name {
    time_t     mtime;
    int        loaded;
};

struct afp_options {
    int connections;            /* Maximum number of possible AFP connections */
    int tickleval;
    int timeout;
    int flags;
    int dircachesize;
    int sleep;                  /* Maximum time allowed to sleep (in tickles) */
    int disconnected;           /* Maximum time in disconnected state (in tickles) */
    int fce_fmodwait;           /* number of seconds FCE file mod events are put on hold */
    unsigned int tcp_sndbuf, tcp_rcvbuf;
    unsigned char passwdbits, passwdminlen;
    uint32_t server_quantum;
    int dsireadbuf; /* scale factor for sizefof(dsi->buffer) = server_quantum * dsireadbuf */
    char *hostname;
    char *listen, *interfaces, *port;
    char *Cnid_srv, *Cnid_port;
    char *configfile;
    char *uampath, *fqdn;
    char *sigconffile;
    char *uuidconf;
    char *guest, *loginmesg, *keyfile, *passwdfile, *extmapfile;
    char *uamlist;
    char *signatureopt;
    unsigned char signature[16];
    char *k5service, *k5realm, *k5keytab;
    size_t k5principal_buflen;
    char *k5principal;
    char *unixcodepage, *maccodepage, *volcodepage;
    charset_t maccharset, unixcharset; 
    mode_t umask;
    mode_t save_mask;
    gid_t admingid;
    int    volnamelen;
    /* default value for winbind authentication */
    char *ntdomain, *ntseparator, *addomain;
    char *logconfig;
    char *logfile;
    char *mimicmodel;
    char *adminauthuser;
    char *ignored_attr;
    char *slmod_path;
    int  splice_size;
    char *cnid_mysql_host;
    char *cnid_mysql_user;
    char *cnid_mysql_pw;
    char *cnid_mysql_db;
    struct afp_volume_name volfile;
    struct afp_volume_name includefile;
    uint64_t sparql_limit;
};

typedef struct AFPObj {
    const char *cmdlineconfigfile;
    int cmdlineflags;
    const void *signature;
    struct DSI *dsi;
    struct afp_options options;
    dictionary *iniconfig;
    char username[MAXUSERLEN];
    /* to prevent confusion, only use these in afp_* calls */
    char oldtmp[AFPOBJ_TMPSIZ + 1], newtmp[AFPOBJ_TMPSIZ + 1];
    void *uam_cookie; /* cookie for uams */
    struct session_info  sinfo;
    uid_t uid; 	/* client running user id */
    int ipc_fd; /* anonymous PF_UNIX socket for IPC with afpd parent */
    gid_t *groups;
    int ngroups;
    int afp_version;
    int cnx_cnt, cnx_max;
    /* Functions */
    void (*logout)(void);
    void (*exit)(int);
    int (*reply)(void *, int);
    int (*attention)(void *, AFPUserBytes);
    int fce_version;
    char *fce_ign_names;
    char *fce_notify_script;
    struct sl_ctx *sl_ctx;
#ifdef MY_ABC_HERE
    int afp_enablexferlog;
#endif
#ifdef MY_ABC_HERE
    BOOL afp_enable_reflink;
#endif
} AFPObj;

/* typedef for AFP functions handlers */
typedef int (*AFPCmd)(AFPObj *obj, char *ibuf, size_t ibuflen, char *rbuf,  size_t *rbuflen);

/* Global variables */
extern AFPObj             *AFPobj;
extern int                afp_version;
extern int                afp_errno;
extern unsigned char      nologin;
extern struct dir         *curdir;
extern char               getwdbuf[];
extern struct afp_options default_options;
extern const char         *Cnid_srv;
extern const char         *Cnid_port;

extern int  get_afp_errno   (const int param);
extern void afp_options_init (struct afp_options *);
extern void afp_options_parse_cmdline(AFPObj *obj, int ac, char **av);
extern int setmessage (const char *);
extern void readmessage (AFPObj *);

/* afp_util.c */
extern const char *AfpNum2name (int );
extern const char *AfpErr2name(int err);

#ifdef MY_ABC_HERE
int SYNOUserConvert2Passwd(struct passwd *pPw, PSYNOUSER pUser);
#endif

#ifdef MY_ABC_HERE

#define AFPXFERLOG_DST(obj, size, szPath, blIsDir, err, ...) \
	AfpXferLog_dst(obj, size, szPath, blIsDir, err, ##__VA_ARGS__ , -1)  
#define AFPXFERLOG_SRC_DST(obj, size, szSrcPath, szDstPath, blIsDir, err, ...) \
	AfpXferLog_src_dst(obj, size, szSrcPath, szDstPath, blIsDir, err, ##__VA_ARGS__ , -1)  

extern int AfpXferLog_dst(AFPObj *obj, off_t Size, const char *szPath, int blIsDir, int err, int afp_cmd, ...);
extern int AfpXferLog_src_dst(AFPObj *obj, off_t Size, const char *szSrcPath, const char *szDstPath, int blIsDir, int err, int afp_cmd, ...);
#endif

#ifdef SYNO_PROFILING
#define AFP_PROFILE_DECORATOR(func_name) \
int profile_##func_name (AFPObj *obj, char *ibuf, size_t ibuflen, char *rbuf,  size_t *rbuflen){ \
	int ret; \
	LOG(log_debug, logtype_afpd, "PROFILING_AFP_COMMAND_FUNCTION = %s", #func_name);\
	SYNO_PROFILE_START(func_name); \
	ret = func_name(obj, ibuf, ibuflen, rbuf, rbuflen); \
	SYNO_PROFILE_END(func_name); \
	return ret; \
}
#define AFP_DEC(func) profile_##func
#endif

/* directory.c */
extern struct dir rootParent;

extern void afp_over_dsi (AFPObj *);
extern void afp_over_dsi_sighandlers(AFPObj *obj);
#endif /* globals.h */
