/* Copyright (c) 2000-2007 Synology Inc. All rights reserved. */
#ifndef	_SYNO_SMTP_H
#define	_SYNO_STMP_H

#include <sys/cdefs.h>
__BEGIN_DECLS

typedef	struct _tag_MAIL_ACCOUNT {
	char *szName;
	char *szEmail;
	struct _tag_MAIL_ACCOUNT *next;
} MAIL_ACCOUNT;
typedef	struct _tag_SYNO_SMTP {
	struct MailServer {
		/**
		 * SMTP server's IP or hostname
		 */
		char *szServer;
		/**
		 *  SMTP server's port number 
		 */
		int Port;
		/**
		 *  AUTH LOGIN is need or not 
		 */
		int NeedAuth;
		/**
		 *  AUTH LOGIN username
		 */
		char *szUser;
		/**
		 *  AUTH LOGIN password
		 */
		char *szPass;
		/**
		 *  Use TLS or not
		 */
		int NeedSSL;
	} MailServer;
	/**
	 * Linked list of "to". Please notice the szName should be encoded by 
	 * base64 when it contains multi-byte chars.
	 */
	MAIL_ACCOUNT *pTo;
	/**
	 * The "From". Please notice the szName should be encoded by 
	 * base64 when it contains multi-byte chars. The field should
	 * have 1 EMAIL_ACCOUNT only.
	 */
	MAIL_ACCOUNT *pFrom;
	/**
	 * The linked list of "cc". Please notice the szName should be encoded by 
	 * base64 when it contains multi-byte chars.
	 */
	MAIL_ACCOUNT *pCc;
	/**
	 * The linked list of "Bcc". Please notice the szName should be encoded by 
	 * base64 when it contains multi-byte chars.
	 */
	MAIL_ACCOUNT *pBcc;
	/**
	 * Email subject. Please notice the subject should be encoded by 
	 * base64 when it contains multi-byte chars.
	 * 
	 * $subject = "=?UTF-8?B?". base64_encode($subject)."?=";
	 */
	char *szSubject;
	char *szMessage;
	/**
	 * Extra headers to be sent before sending messages.
	 * 
	 * For example, you can set the outlook's email priority by:
	 * $additional_headers .= "X-Priority: 1\n";
	 * $additional_headers .= "X-MSMail-Priority: High\n";
	 */
	char *szExtraHeader;
	/**
	 * Multuipart partial headers to be sent before sending messages
	 * with attachment. 
	 * 
	 * For example, you can set content-type of the attachment and 
	 * other headers like: "Content-type: 
	 * image/jpeg\r\nContent-Transfer-Encoding: 
	 * base64\nContent-Disposition: inline; 
	 * filename=\"xxx.jpg\"\r\n\r\n" 
	 */
	char *szPartHeader;
	/**
	 * Define the content-type of the multuipart header if the 
	 * attachment is been described. 
	 *  
	 * For example, you can set content-type of like: 
	 * 
	 * "multipart/mixed"
	 */
	char *szContentType;
	/**
	 * Define the multuipart boundary of the multipart mail. 
	 *  
	 * For example, you can set boundary of the multipart mail of 
	 * like: 
	 * 
	 * "myboundary"
	 */
	char *szBoundary;
	/**
	 * Set the attachment absoluate file path of sent mail. 
	 *  
	 * For example, you can set the attachment absoluate file path 
	 * of the multipart mail of like: 
	 * 
	 * "/tmp/xxx.jpg"
	 */
	char *szAttachFilePath;
	/**
	 * Set the bool value to distinguish either binart or text 
	 * attachment file of sent mail. 
	 *	
	 * 1: binary 
	 * 0: text 
	 */
	int	 blFileBinary;
} SYNO_SMTP;

void SYNOSMTPErrorSet(const char *fmt, ...);

/* ssl.c */
ssize_t SYNOSSLWrite(const void *buf, size_t count);
ssize_t SYNOSSLRead(void *buf, size_t count);
int SYNOSSLInit(void);
int SYNOSSLStart(int sockfd);
int SYNOSSLEnd(void);

/* socket.c */
int SYNOSMTPConnect(const char *szHost, int Port);

/* base64.c */
char *SzBase64Encode(const unsigned char *szStr, int Length);

/* parse.c */
int SYNOSMTPConcateEmail(MAIL_ACCOUNT *pAccount, char *szBuf, int BufLen);
MAIL_ACCOUNT *SYNOSMTPParseEmail(const char *szStr);

/* datetime.c */
int RFC2822DateGet(char *szBuf, int BuffLen);

/* smtp.c */
int SYNOSMTPSendEmail(SYNO_SMTP *pSMTP, void (*SYNOSMTPErrorCallback)(const char *));
void SYNOSMTPFreeEmailAccount(MAIL_ACCOUNT *pAccount);
void SYNOSMTPFreeSYNOSMTP(SYNO_SMTP *pSMTP);

__END_DECLS
#endif /* _SYNO_SMTP_H */
