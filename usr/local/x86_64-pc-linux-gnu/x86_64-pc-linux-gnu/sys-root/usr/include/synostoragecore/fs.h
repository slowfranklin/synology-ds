// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_FS_H__
#define __SYNO_STGCORE_FS_H__

#include <hwctl/disk.h>
#include <hwctl/external.h>

__BEGIN_DECLS;

#define MAX_FS_BYTES        ((16ULL << 40) - (4ULL << 20)) // 16TB - LVM_VG_PESIZE (4) MB
#define MAX_FS_X64_BYTES    (1ULL << 60) // (2^20)TB
#define MAX_FS_SIZE_ONLINE_RESIZE (16ULL << 40) // 16TB
#define MAX_FS_BYTES_LIMIT  (108ULL << 40) //108TB, it's policy, not system limit
#define MAX_FS_BYTES_LIMIT_HIGH_END (200ULL << 40) //200TB, it's policy, not system limit, this limitation is applied to machines with 32GB RAM and create volume on RAID Group
/* Even if other 64-bit platforms have loosen policy limit later,
 * Alpine will still stick to its physical limit. */
#define MAX_FS_BYTES_LIMIT_ALPINE   (256ULL << 40) //256TB
#define REQUIRED_RAM_SIZE_GB_FOR_200TB_VOLUME 32

#define SZK_SUBVOL_SNAP_RUUID "ruuid"
#define SZK_SUBVOL_SNAP_TAKE_BY "take-by"
#define SZK_SUBVOL_SNAP_HIDE "hide"
#define SZK_SUBVOL_SNAP_LOCK "lock"
#define SZK_SUBVOL_SNAP_DESC "desc"
#define SZK_SUBVOL_SNAP_SIZE "snap_size"

#define SZF_TUNE2FS "/sbin/tune2fs"
#define SZK_TUNE2FS_BLOCK_COUNT "Block count:"
#define SZK_TUNE2FS_BLOCK_SIZE "Block size:"

#define SZD_BTRFS_DELETED_SUBVOL "@deleted_subvol"
#define SZF_EXT3_BAD_FILE_ARCHIVE ".@Ext3BadFileArchive"

#define SZF_FS_BTRFS_CKSUMFAILED_FILE "/tmp/btrfs_cksumfailed_files"

#include <synostoragecore/fs_p.h>

__END_DECLS;

#endif
