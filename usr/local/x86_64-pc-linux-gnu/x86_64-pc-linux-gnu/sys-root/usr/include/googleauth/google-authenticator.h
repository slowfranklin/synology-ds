#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif

#include <security/pam_appl.h>
#include <security/pam_modules.h>

#define LOG(format, ...) syslog(LOG_ERR, "%s:%d "format, __FILE__, __LINE__, ## __VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

int  SYNOGoogleAuth(int argc, const char **argv);
int  SYNOGoogleAuthByName(const char *username, const char *code);
void SYNOGetSecretPathByUser(const char *username, char *secert_path, int cbPath);
int  SYNOUserOTPEnabled(const char *username);
int  SYNORemoveOTPsecretFile(const char *username);

#ifdef __cplusplus
};
#endif
