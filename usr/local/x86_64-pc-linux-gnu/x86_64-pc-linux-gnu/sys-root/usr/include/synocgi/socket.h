/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNOCGI_SOCKET_H_
#define _SYNOCGI_SOCKET_H_
#define SZD_SYNOCGID_DAEMON_SOCKET_DIR "/var/run/synocgid/"
#define SZF_SYNOCGID_DAEMON_EVENT_AUTH_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.htua.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_CHECK_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.check.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_REMOVE_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.remove.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_EXIST_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.exist.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_GET_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.get.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_UPDATE_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.update.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_ADD_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.add.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_GETID_SESSION_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.session.getid.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_SSLDECRYPT_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.ssldecrypt.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_GETRSAMODULUS_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.getrsamodulus.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_GETRSAPUBLICKEY_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.getrsapublickey.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_REMOVE_USER_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.remove.user.socket"
#define SZF_SYNOCGID_DAEMON_EVENT_GET_API_KEY_SOCKET_PATH SZD_SYNOCGID_DAEMON_SOCKET_DIR "synocgid.apikey.get.socket"

#ifdef __cplusplus
extern "C" {
#endif
// Framework functions

void SynoCgiSocketClose(int socketfd);

// Server-side
int SynoCgiSocketSeverOpen(int *socketfd, const char *szSocketPath);
int SynoCgiSocketSeverRead(int serverfd, int *clientfd, char **szReq, int *cbReq);
int SynoCgiSocketSeverWrite(int client_socketfd, const char *szRes);

// Client-side
int SynoCgiSocketClientConnect(int *socketfd, const char *szSocketPath);
int SynoCgiSocketClientSend(int socketfd, const char *szReq);
int SynoCgiSocketClientRecv(int socketfd, char *szRes, int cbRes);
int SynoCgiSocketClient(const char *szReq, const char *szSocketPath, char *szRes, int cbRes);

int SynoCgiSocketClientEx(const char *szReq, const char *szSocketPath, char **szRes, int *cbRes);
#ifdef __cplusplus
}
#endif

#endif // _SYNOCGI_SOCKET_H_
