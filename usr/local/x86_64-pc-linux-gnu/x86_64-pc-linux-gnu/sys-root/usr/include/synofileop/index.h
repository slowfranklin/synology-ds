// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_INDEX_H__
#define __SYNO_INDEX_H__

#include <stdint.h>
#include <sys/cdefs.h>
#include <linux/syno.h>
#include <synocore/synotype.h>
#include <synofileop/ea.h>
#include <synosdk/share.h>

__BEGIN_DECLS;

typedef enum {
	SLIB_INDEX_PACKAGE_SKIP,
	SLIB_INDEX_PACKAGE_ONLY
} SLIB_INDEX_PACKAGE_OP;

typedef enum {
	SLIB_INDEX_MIN,
	SLIB_INDEX_ADD,
	SLIB_INDEX_DEL,
	SLIB_INDEX_ADD_RECURSIVE,
	SLIB_INDEX_ADD_DIR = SLIB_INDEX_ADD_RECURSIVE,
	SLIB_INDEX_RENAME,
	SLIB_INDEX_UPDATE,		// deprecated
	SLIB_INDEX_TRUNCATE,		// deprecated
	SLIB_INDEX_DEL_DIR,
	SLIB_INDEX_ONLINE,
	SLIB_INDEX_OFFLINE,
	SLIB_INDEX_REINDEX,
	SLIB_INDEX_RENAME_DIR,
	SLIB_INDEX_MAX
} SLIB_INDEX_OP;

#define SZF_INDEX_DAEMON_PID		"/var/run/synoindexd.pid"
#define SZF_DMS_DAEMON_PID			"/var/run/dms.pid"
#define SZF_PHOTO_THUMB_DAEMON_PID	"/var/run/synomkthumbd.pid"

#define SZF_INDEXING_QUEUE      "/var/spool/syno_indexing_queue"
#define SZF_INDEXING_QUEUE_TMP	"/var/spool/syno_indexing_queue.tmp"
#define SZF_THUMB_CREATE_QUEUE		"/var/spool/thumb_create.queue"
#define SZF_THUMB_CREATE_QUEUE_TMP	"/var/spool/thumb_create.queue.tmp"
#define SZF_PROG_SYNOTHUMB		"/usr/syno/bin/synothumb"
#define SZF_PROG_SYNOMKTHUMBD	"/usr/syno/bin/synomkthumbd"

#define SZF_PHOTOSTATION_SETTING	"/var/packages/PhotoStation/etc/settings.conf"
#define SZF_AUDIOSTATION_SETTING	"/var/packages/AudioStation/etc/audio.conf"
#define SZK_ENABLE_PERSONAL_PHOTO	"runpersonalphotostation"
#define SZK_ENABLE_PERSONAL_AUDIO	"enable_personal_library"

#ifdef SYNO_MARVELL_88F6180
#define SZD_INDEX_ROOT			"/volume1"
#else
#define SZD_INDEX_ROOT			"/var/service/"
#endif

//Used for personal photo station
#define SZF_PERSONAL_PHOTO_STATION_DB_NAME ".SYNOPPSDB"

// Service Framework Service Name
#define SZ_SYNOINDEXD_SERVICE_NAME                              "synoindexd"
#define SZ_SYNOMKTHUMBD_SERVICE_NAME                              "synomkthumbd"
#define SZ_SYNOMKFLVD_SERVICE_NAME                              "synomkflvd"

typedef enum _tag_THUMB_TYPE_{
	THUMB_TYPE_IMAGE = 0x01,
	THUMB_TYPE_VIDEO = 0x02,
	THUMB_TYPE_ALL = THUMB_TYPE_IMAGE | THUMB_TYPE_VIDEO,
}THUMB_TYPE;

#ifndef NO_PROTO
#include <availability.h>
#include <synofileop/index_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_INDEX_H__
