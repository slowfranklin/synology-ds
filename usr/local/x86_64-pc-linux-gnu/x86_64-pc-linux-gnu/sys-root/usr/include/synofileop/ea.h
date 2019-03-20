// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef __SYNO_EA_H__
#define __SYNO_EA_H__
#include <limits.h>
#include <dirent.h>
#include <sys/cdefs.h>
#include <stdint.h>
#include <synocore/synotype.h>
#include <synocore/list.h>
#include <fcntl.h>
#include <unistd.h>

__BEGIN_DECLS;

/**
 * @addtogroup EA The structure and operation of EA.
 * @{
 * @defgroup EA_int The internal functions of EA.
 */
#define SZ_RESOURCE_FORK			"SynoResource"
#define SZ_EASTREAM					"SynoEAStream"
#define SZ_EASTREAM_CONN			"@"
#define SZ_XATTR_RESOURCE_FORK		"com.apple.ResourceFork"
#define SZ_XATTR_FINDERINFO			"com.apple.FinderInfo"

#define SYNO_HIDDEN_EA_PREFIX		"SYNO:"
#define SYNO_HIDDEN_EA_PREFIX_EX 	"SYNO@"
#define SYNO_PHOTO_PREFIX			"SYNOPHOTO:"
#define SYNO_PHOTO_STREAM_PREFIX	SYNO_PHOTO_PREFIX"THUMB_"
#define SYNO_EA_FAT_PREFIX			"._"
#define SYNO_EA_DSSTORE			".DS_Store"
#define SYNO_FINFO_IDX 0
#define SYNO_RFORK_IDX 1

#define SYNO_EA_DIR					"@eaDir"
#define SYNO_PHOTO_STREAM_PREFIX_LEN 	16 // strlen(SYNO_PHOTO_STREAM_PREFIX)

#define SYNO_AD_FILEEA_FLUSH_TIME "user.syno.filea.flushtime"
// copy from xattr.h
#define SYNO_XATTR_CREATE  0x1       /* set value, fail if attr already exists */
#define SYNO_XATTR_REPLACE 0x2       /* set value, fail if attr does not exist */

struct eaent {
	char e_name[NAME_MAX+1];
};

typedef enum {
	EATYPE_SYNOEA,			/* photo thumbnails, ...*/
	EATYPE_EASTREAM			/* AFP/SMB's SZ_RESOURCE_FORK, SZ_EASTREAM */
} EATYPE;

typedef enum {
	UP_ERR = -1,
	UP_SUCCESS = 0,
	UP_NEW_EXIST = 1,
	UP_OLD_NO_EXIST = 2
} EA_UPGRADE_STATUS;

typedef enum {
	AD_SUCCESS = 0,
	AD_ERR = -1,
	AD_WRONG_PREFIX = -2,
	AD_WRONG_FORMAT = -3,
	AD_NO_MASTER = -4
} EA_AD_STATUS;

typedef enum {
	SYNO_SHARE = 0,
	AD_SHARE
} EA_AD_SHARE;

#define IS_EXT_OR_GLUSTER_FSTYPE(type) (FSTYPE_EXT3 == (type) || FSTYPE_GLUSTERFS == (type))

#define ISADFS(fstype)	(FSTYPE_FAT == (fstype) || FSTYPE_NTFS == (fstype))
#define ISFILEEAFS(fstype) (FSTYPE_EXT4 == (fstype))
#define ISEADIRFS(type) (FSTYPE_BTRFS == (type) || FSTYPE_CIFS == (type) || IS_EXT_OR_GLUSTER_FSTYPE(type))
#define ISHFSPLUSFS(fstype) (FSTYPE_HFSPLUS == (fstype))

/**
 * A structure for apple double header( ._xxx files )
 * for FAT USB EA copy or localbkp
 */
typedef struct adouble_entry {
	uint32_t	id, offset, len;
} AD_ENTRY;

typedef struct adouble_header {
    uint32_t	ad_magic;
    uint32_t	ad_version;
    char		ad_filler[ 16 ];
    uint16_t	ad_num_entry;
} AD_HEADER;

/*
 * EASTREAM IMPLEMENTATION
 * For read / write / [un]lock the EA in the SZ_EASTREAM file
 * The headers and implementation limits will follow program-"cp" released in apple open source.
 */
/*
 * Apple Double Create
 * Create an Apple Double "._" file from a file's extented attributes
 * Copyright (c) 2004 Apple Computer, Inc. All rights reserved.
 */

/*
   Typical "._" AppleDouble Header File layout:
  ------------------------------------------------------------
         MAGIC          0x00051607
         VERSION        0x00020000
         FILLER         0
         COUNT          2
     .-- AD ENTRY[0]    Finder Info Entry (must be first)
  .--+-- AD ENTRY[1]    Resource Fork Entry (must be last)
  |  '-> FINDER INFO
  |      /////////////  Fixed Size Data (32 bytes)
  |      EXT ATTR HDR
  |      /////////////
  |      ATTR ENTRY[0] --.
  |      ATTR ENTRY[1] --+--.
  |      ATTR ENTRY[2] --+--+--.
  |         ...          |  |  |
  |      ATTR ENTRY[N] --+--+--+--.
  |      ATTR DATA 0   <-'  |  |  |
  |      ////////////       |  |  |
  |      ATTR DATA 1   <----'  |  |
  |      /////////////         |  |
  |      ATTR DATA 2   <-------'  |
  |      /////////////            |
  |         ...                   |
  |      ATTR DATA N   <----------'
  |      /////////////
  |                      Attribute Free Space
  |
  '----> RESOURCE FORK
         /////////////   Variable Sized Data
         /////////////
         /////////////
         /////////////
         /////////////
         /////////////
            ...
         /////////////
 
  ------------------------------------------------------------

   NOTE: The EXT ATTR HDR, ATTR ENTRY's and ATTR DATA's are
   stored as part of the Finder Info.  The length in the Finder
   Info AppleDouble entry includes the length of the extended
   attribute header, attribute entries, and attribute data.
*/
/*
 * On Disk Data Structures
 * Note: Motorola 68K alignment and big-endian.
 * See RFC 1740 for additional information about the AppleDouble file format.
 */

#define ADH_MAGIC     0x00051607
#define ADH_VERSION   0x00020000
#define ADH_MACOSX    "Mac OS X        "

#define ATTR_HDR_MAGIC     0x41545452   /* 'ATTR' */
#define ATTR_BUF_SIZE      4096        /* default size of the attr file and how much we'll grow by */

/* Implementation Limits */
#define ATTR_MAX_SIZE      (128*1024)  /* 128K maximum attribute data size */
#define ATTR_MAX_NAME_LEN  128
#define ATTR_MAX_HDR_SIZE  (65536+18) // 64K + 18

/*
 * Note: ATTR_MAX_HDR_SIZE is the largest attribute header
 * size supported (including the attribute entries). All of
 * the attribute entries must reside within this limit.
 */

#define FINDERINFOSIZE	32
// 11 = offset + length + flags + namelen
#define ATTR_ENTRY_LENGTH_PART 11

typedef struct apple_double_entry {
	uint32_t   type;     /* entry type: see list, 0 invalid */ 
	uint32_t   offset;   /* entry data offset from the beginning of the file. */
	uint32_t   length;   /* entry data length in bytes. */
} __attribute__((aligned(2), packed)) apple_double_entry_t;

typedef struct apple_double_header {
	uint32_t   magic;         /* == ADH_MAGIC */
	uint32_t   version;       /* format version: 2 = 0x00020000 */ 
	uint32_t   filler[4];
	uint16_t   numEntries;	   /* number of entries which follow */ 
	apple_double_entry_t   entries[2];  /* 'finfo' & 'rsrc' always exist */
	uint8_t    finfo[FINDERINFOSIZE];  /* Must start with Finder Info (32 bytes) */
	uint8_t    pad[2];        /* get better alignment inside attr_header */
} __attribute__((aligned(2), packed)) apple_double_header_t;

#define EASENTRIES_COUNT(pEAStream)			(const int)(pEAStream)->AttrHeader.num_attrs
#define EASENTRY_NAME(pEAStream, num)		(const char*)(pEAStream)->AttrEntries[num].name
#define EASENTRY_DATALEN(pEAStream, num)	(const int)(pEAStream)->AttrEntries[num].length
/* Header + entries must fit into 64K */
typedef struct attr_header {
	apple_double_header_t  appledouble;
	uint32_t	magic;        /* == ATTR_HDR_MAGIC */
	uint32_t	debug_tag;    /* for debugging == file id of owning file */
	uint32_t   	total_size;   /* total size of attribute header + entries + data */ 
	uint32_t   	data_start;   /* file offset to attribute data area */
	uint32_t   	data_length;  /* length of attribute data area */
	uint32_t   	reserved[3];
	uint16_t   	flags;
	uint16_t   	num_attrs;
} __attribute__((aligned(2), packed)) attr_header_t;

/* Entries are aligned on 4 byte boundaries */
typedef struct attr_entry {
	uint32_t	offset;    /* file offset to data */
	uint32_t	length;    /* size of attribute data */
	uint16_t	flags;
	uint8_t		namelen;   /* length of name including NULL termination char */ 
	uint8_t		*name;   /* NULL-terminated UTF-8 name (up to 128 bytes max) */
} __attribute__((aligned(2), packed)) attr_entry_t;

typedef struct syno_easteam {
	attr_header_t	AttrHeader;
	attr_entry_t	*AttrEntries;
	int				EASInited;
	int				fdEASFile;
	int				iEntryNum; /* Number of entries allocated */
	int				iLockType;
} SYNO_EASTREAM;

#define EAS_OVERWRITE		0x01
#define EAS_NO_CREAT		0x02
/**
 * Used to determine if file/media index is needed for ea 
 * functions 
 */
typedef struct syno_index_enable {
	int FileIndexIsNeed;
	int MediaIndexIsNeed;
}SYNO_INDEX_ENABLE;

typedef int(*PFUNC_CopyEA) (const char *szSrcFileName, const char *szDstFileName);
typedef int(*PFUNC_THR_CopyEA) (const char *szSrcFileName, const char *szDstFileName, void *pData);

#ifndef NO_PROTO
#include <availability.h>
#include <synofileop/ea_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif /* __SYNO_EA_H__ */
