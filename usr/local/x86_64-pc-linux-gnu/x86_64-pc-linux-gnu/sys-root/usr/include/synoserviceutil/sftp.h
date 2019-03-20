// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef __SYNO_SFTP_H__
#define __SYNO_SFTP_H__

#include <sys/cdefs.h>
#include <synocore/synotype.h>

__BEGIN_DECLS;

#define SZ_SFTP_SERVICE				"sftp"
#define SZ_SFTP_UPSTART_SSHD		"sshd"
#define SZ_SFTP_UPSTART_SSH_SFTP	"ssh-sftp"
#define SZ_SFTP_UPSTART_AVAHI		"sftp-avahi"
#define SZ_AVAHI_UPSTART			"avahi"
#define SZ_SFTP_UPSTART_SFTPD		"sftpd"
#define SZ_SFTP_FIREWALL_SSH		"ssh"
#define SZ_SFTP_FIREWALL_SFTP		"SFTP"

#ifndef NO_PROTO
#include <synoserviceutil/sftp_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif //__SYNO_SFTP_H__
