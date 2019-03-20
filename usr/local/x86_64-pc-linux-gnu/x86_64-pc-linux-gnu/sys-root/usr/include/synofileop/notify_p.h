#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* notify.c */
#if defined(MY_DEF_HERE)
SDK_STARTING_FROM(SDK_VER_6_0) void SLIBSYNotify(const char *szPath, const char *szPath2, SLIB_NOTIFY_EVENT e);
#else
#define SLIBSYNotify(a, b, c)
#endif
SDK_STARTING_FROM(SDK_VER_6_1) void SLIBSYNotifyForce(const char *szPath, const char *szPath2, SLIB_NOTIFY_EVENT e);
