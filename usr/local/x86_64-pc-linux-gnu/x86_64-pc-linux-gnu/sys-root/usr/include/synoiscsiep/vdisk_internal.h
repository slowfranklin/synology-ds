/* Copyright (c) 2016 Synology Inc. All rights reserved. */
#ifndef _SYNOISCSIEP_VDISK_INTERNAL_H_
#define _SYNOISCSIEP_VDISK_INTERNAL_H_

#include <synoiscsiep/util_internal.h>

__BEGIN_DECLS;

/*** names, path or format of files and directories ***/

/*** constants ***/

/*** keys ***/

/*** etc ***/
#define ISCSI_VDISK_TAG                     "VDISK_"
#define ISCSI_VDISK_LOAD_NAME               ISCSI_VDISK_TAG "%s"

/*** types ***/

/*** macro or inline functions ***/

/*** function declarations ***/
int  SYNOiSCSIVhostTargetUnloadByNaa(const char *szNAA);
int  SYNOiSCSIVhostStopAll();
int  SYNOiSCSIVhostStopAllWithoutLock();
int  SYNOiSCSIVhostStartAll();

__END_DECLS

#endif // _SYNOISCSIEP_VDISK_INTERNAL_H_
