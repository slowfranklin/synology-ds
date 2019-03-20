/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef __SYNO_NOTIFY_H__
#define __SYNO_NOTIFY_H__

__BEGIN_DECLS;

typedef enum {
	SLIB_NOTIFY_NONE            = 0x00000000,
	SLIB_NOTIFY_ACCESS          = 0x00000001,
	SLIB_NOTIFY_MODIFY          = 0x00000002,
	SLIB_NOTIFY_ATTRIB          = 0x00000004,
	SLIB_NOTIFY_CLOSE_WRITE     = 0x00000008,
	SLIB_NOTIFY_CLOSE_NOWRITE   = 0x00000010,
	SLIB_NOTIFY_OPEN            = 0x00000020,
	SLIB_NOTIFY_CREATE          = 0x00000040,
	SLIB_NOTIFY_DELETE          = 0x00000080,
	// New invented event
	SLIB_NOTIFY_RENAME          = 0x00000100,
	SLIB_NOTIFY_RESCAN          = 0x00000200,
	SLIB_NOTIFY_QUEUE_RESET     = 0x00000400,
	SLIB_NOTIFY_PRIMITIVE_ALL   = 0x0000FFFF,
	// Customized notify event minimum
	SLIB_NOTIFY_CUSTOMIZED_MIN  = 0x00010000
} SLIB_NOTIFY_EVENT;

#define SZF_SYNOTIFYD_DOMAIN_SCK_PATH          "/var/run/synotifyd.sock"

#define SZK_SYNOTIFYD_COMMAND_TYPE             "type"
#define SZK_SYNOTIFYD_COMMAND_DATA             "data"
#define SZK_SYNOTIFYD_COMMAND_EVENT            "event"
#define SZK_SYNOTIFYD_COMMAND_PATH             "path"
#define SZK_SYNOTIFYD_COMMAND_PATH_OLD         "path_old"

#define SZV_SYNOTIFYD_COMMAND_TYPE_NOTIFY      "notify"

#ifndef NO_PROTO
#include <availability.h>
#include <synofileop/notify_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_NOTIFY_H__
