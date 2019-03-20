#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2010 Synology Inc. All rights reserved.
#ifndef __SYNO_ACL_H__
#define __SYNO_ACL_H__

#include <sys/stat.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/list.h>

#include <linux/syno.h>
#include <synocore/error.h>

#ifdef MY_ABC_HERE
#include <linux/syno_acl_xattr_ds.h>
#endif

__BEGIN_DECLS;

/**
 * @defgroup    ACE ACE
 * @brief       Functions about ACE operations
 */
/**
 * @defgroup    ACL ACL
 * @brief       Functions about ACL operations
 */
/**
 * @defgroup    Archive Archive
 * @brief       Functions about Archive bit operations
 */
/**
 * @defgroup    Print Print
 * @brief       Functions to print ACL Information
 */

/**
 * @addtogroup  ACE
 *
 * @{
 */
#define SYNOSDK_ACL_UNDEFINED_ID	(-1)
#define SYNOSDK_ACE_SELF_DEFINE		0
#define SYNOSDK_ACL_STR_EVERYONE "everyone"
#define SYNOSDK_ACL_STR_OWNER "owner"
#define SYNOSDK_ACL_STR_USER "user"
#define SYNOSDK_ACL_STR_GROUP "group"
#define SYNOSDK_ACL_STR_AUTHENTICATEDUSER "authenticated_user"
#define SYNOSDK_ACL_STR_SYSTEM "system"
#define SYNOSDK_ACL_STR_ACE_FORMAT	"["SYNOSDK_ACL_STR_USER"|"SYNOSDK_ACL_STR_GROUP"|"SYNOSDK_ACL_STR_OWNER"|"SYNOSDK_ACL_STR_EVERYONE"|"SYNOSDK_ACL_STR_AUTHENTICATEDUSER"|"SYNOSDK_ACL_STR_SYSTEM"]:name:[allow|deny]:permissions:inherit mode"
#define SYNOSDK_ACL_STR_ACE_EXAMPLE	SYNOSDK_ACL_STR_USER":root:allow:rwx-d---RWc--:fd--"
#define SYNOSDK_ACL_STR_ACE_EXAMPLE_2	SYNOSDK_ACL_STR_OWNER":*:allow:rwx-d---RWc--:fd--"
#define SYNOSDK_ACL_STR_PERMISSION "rwxpdDaARWcCo"
#define SYNOSDK_ACL_STR_INHERIT "fdin"
/**
 * @}
 */
/**
 * @addtogroup  ACL
 * @{
 */
#define SYNOSDK_ACL_STR_OPT_PSEUDO_INHERIT "pseudo_inherit"
#define SYNOSDK_ACL_STR_OPT_INHERIT "inherit"
#define SYNOSDK_ACL_STR_OPT_SINGLE "single"
#define SYNOSDK_ACL_STR_OPT "["SYNOSDK_ACL_STR_OPT_INHERIT"|"SYNOSDK_ACL_STR_OPT_SINGLE"]"
#define SYNOSDK_ACL_MAX_ACE_COUNT 200

#define MAX_NAME_LEN 492	//(SYNO_GROUPNAME_UTF8_MAX > SYNO_USERNAME_UTF8_MAX)?SYNO_GROUPNAME_UTF8_MAX:SYNO_USERNAME_UTF8_MAX

#define SYNO_AR_OWNER_IS_GROUP(name) SYNOACLArchiveIsEnabled(name, -1, SYNOACL_ARCHIVE_OWNER_GROUP)
#define FOR_EACH_SYNO_ACE(ace, acl) for(ace = acl->pFirstEnt ; ace ; ace = ace->pNext)
#define IS_ACE_INHERITED(ace) (ace->level > 0)?TRUE:FALSE

#define SYNOSDK_IS_PERM_VALID(x) (SYNOSDK_ACL_PERM_FULL_CONTROL & x)
#define SYNOSDK_IS_INHERIT_ONE_LEVEL(x) ((x & SYNOSDK_ACL_INHERIT_NO_PROPOGATE) && (x & (SYNOSDK_ACL_INHERIT_FILE | SYNOSDK_ACL_INHERIT_DIR)))

#define IS_FILE_SUPPORT_ACL(path) SYNOACLIsSupport(path, -1, SYNO_ACL_IS_FILE_SUPPORT)
#define IS_FS_SUPPORT_ACL(path) SYNOACLIsSupport(path, -1, SYNO_ACL_IS_FS_SUPPORT)
#define IS_SYNOACL_ACCESS_DENY(path, syno_perm) ((0 >= SYNOACLPermCheck(path, syno_perm)) && (ERR_SYNOACL_NOT_SUPPORT != SLIBCErrGet()))
/**
 * @}
 */

/**
 *  @ingroup    ACE
 */
typedef enum _tag_SYNO_ACL_ID_TYPE_ {
	SYNOSDK_ACL_UNKNOWN=0,
	SYNOSDK_ACL_USER=0x0001,
	SYNOSDK_ACL_OWNER=0x0002,
	SYNOSDK_ACL_GROUP=0x0004,
	SYNOSDK_ACL_GROUP_EVERYONE=0x0008,
	SYNOSDK_ACL_AUTHENTICATEDUSER=0x0009,
	SYNOSDK_ACL_SYSTEM=0x000A,
	SYNOSDK_ACL_ID_BUILT_IN=SYNOSDK_ACL_GROUP_EVERYONE|SYNOSDK_ACL_OWNER,
} SYNO_ACL_ID_TYPE;

/**
 *  @ingroup    ACE
 */
typedef struct _tag_SYNO_ACL_ID_ {
	SYNO_ACL_ID_TYPE  type;
    /**
     *  Uid or Gid, -1 for special types
     */
	unsigned int id;	//uid or gid or -1
} SYNO_ACL_ID;

/**
 * @ingroup     ACE
 */
typedef enum _tag_SYNOSDK_ACL_PERM_ {
	SYNOSDK_ACL_PERM_EXEC = 0x0001,
	SYNOSDK_ACL_PERM_WRITE = 0x0002,
	SYNOSDK_ACL_PERM_READ = 0x0004,
	SYNOSDK_ACL_PERM_APPEND = 0x0008,
	SYNOSDK_ACL_PERM_READ_EXT_ATTR = 0x0010,
	SYNOSDK_ACL_PERM_READ_PERMISSION = 0x0020,
	SYNOSDK_ACL_PERM_READ_ATTR = 0x0040,
	SYNOSDK_ACL_PERM_WRITE_ATTR = 0x0080,
	SYNOSDK_ACL_PERM_WRITE_EXT_ATTR = 0x0100,
	SYNOSDK_ACL_PERM_DEL = 0x0200,
	SYNOSDK_ACL_PERM_DEL_CHILD = 0x0400,
	SYNOSDK_ACL_PERM_WRITE_PERMISSION = 0x0800,
	SYNOSDK_ACL_PERM_GET_OWNER_SHIP = 0x1000,
	SYNOSDK_ACL_PERM_FULL_CONTROL = SYNOSDK_ACL_PERM_EXEC | \
									SYNOSDK_ACL_PERM_WRITE | \
									SYNOSDK_ACL_PERM_READ | \
									SYNOSDK_ACL_PERM_APPEND | \
									SYNOSDK_ACL_PERM_READ_EXT_ATTR | \
									SYNOSDK_ACL_PERM_READ_PERMISSION | \
									SYNOSDK_ACL_PERM_READ_ATTR | \
									SYNOSDK_ACL_PERM_WRITE_ATTR | \
									SYNOSDK_ACL_PERM_WRITE_EXT_ATTR | \
									SYNOSDK_ACL_PERM_DEL | \
									SYNOSDK_ACL_PERM_DEL_CHILD | \
									SYNOSDK_ACL_PERM_WRITE_PERMISSION | \
									SYNOSDK_ACL_PERM_GET_OWNER_SHIP,
	SYNOSDK_ACL_PERM_MODIFY = SYNOSDK_ACL_PERM_EXEC | \
									SYNOSDK_ACL_PERM_WRITE | \
									SYNOSDK_ACL_PERM_READ | \
									SYNOSDK_ACL_PERM_APPEND | \
									SYNOSDK_ACL_PERM_READ_EXT_ATTR | \
									SYNOSDK_ACL_PERM_READ_PERMISSION | \
									SYNOSDK_ACL_PERM_READ_ATTR | \
									SYNOSDK_ACL_PERM_WRITE_ATTR | \
									SYNOSDK_ACL_PERM_WRITE_EXT_ATTR | \
									SYNOSDK_ACL_PERM_DEL,
	SYNOSDK_MODE_READ = SYNOSDK_ACL_PERM_READ | \
						SYNOSDK_ACL_PERM_READ_EXT_ATTR | \
						SYNOSDK_ACL_PERM_READ_PERMISSION | \
						SYNOSDK_ACL_PERM_READ_ATTR,

	SYNOSDK_MODE_WRITE = SYNOSDK_ACL_PERM_WRITE | \
						 SYNOSDK_ACL_PERM_WRITE_ATTR | \
						 SYNOSDK_ACL_PERM_WRITE_EXT_ATTR | \
						 SYNOSDK_ACL_PERM_APPEND | \
						 SYNOSDK_ACL_PERM_DEL_CHILD,
	SYNOSDK_MODE_OWNER = SYNOSDK_ACL_PERM_READ_PERMISSION | \
						 SYNOSDK_ACL_PERM_WRITE_PERMISSION | \
						 SYNOSDK_ACL_PERM_GET_OWNER_SHIP,
	SYNOSDK_SHARE_RW = SYNOSDK_ACL_PERM_EXEC | \
			   SYNOSDK_ACL_PERM_WRITE | \
			   SYNOSDK_ACL_PERM_READ | \
			   SYNOSDK_ACL_PERM_APPEND | \
			   SYNOSDK_ACL_PERM_READ_EXT_ATTR | \
			   SYNOSDK_ACL_PERM_READ_PERMISSION | \
			   SYNOSDK_ACL_PERM_READ_ATTR | \
			   SYNOSDK_ACL_PERM_WRITE_ATTR | \
			   SYNOSDK_ACL_PERM_WRITE_EXT_ATTR | \
			   SYNOSDK_ACL_PERM_DEL | \
			   SYNOSDK_ACL_PERM_DEL_CHILD,
	SYNOSDK_SHARE_RO = SYNOSDK_ACL_PERM_READ | \
			   SYNOSDK_ACL_PERM_EXEC | \
			   SYNOSDK_ACL_PERM_READ_EXT_ATTR | \
			   SYNOSDK_ACL_PERM_READ_PERMISSION | \
			   SYNOSDK_ACL_PERM_READ_ATTR,

} SYNO_ACL_PERM;

/**
 *  @ingroup    Archive
 */
typedef enum _tag_SYNO_ACL_ARCHIVE_ {
	SYNOACL_ARCHIVE_INHERIT = 0x01, // Inherited from parent
	SYNOACL_ARCHIVE_READONLY = 0x02,
	SYNOACL_ARCHIVE_OWNER_GROUP = 0x04,
	SYNOACL_ARCHIVE_HAS_ACL = 0x08,
	SYNOACL_ARCHIVE_SUPPORT_ACL = 0x10,
	SYNOACL_ARCHIVE_ALL = SYNOACL_ARCHIVE_INHERIT | \
						  SYNOACL_ARCHIVE_READONLY | \
						  SYNOACL_ARCHIVE_OWNER_GROUP | \
						  SYNOACL_ARCHIVE_HAS_ACL | \
						  SYNOACL_ARCHIVE_SUPPORT_ACL
}SYNO_ACL_ARCHIVE;

/**
 *  @ingroup    ACE
 */
typedef enum _tag_SYNOSDK_ACL_INHERIT_ {
	SYNOSDK_ACL_INHERIT_ONLY = 0x01,
	SYNOSDK_ACL_INHERIT_FILE = 0x02,
	SYNOSDK_ACL_INHERIT_DIR = 0x04,
	SYNOSDK_ACL_INHERIT_NO_PROPOGATE = 0x08,
	SYNOSDK_ACL_INHERIT_ALL = SYNOSDK_ACL_INHERIT_ONLY | \
  	 						  SYNOSDK_ACL_INHERIT_FILE | \
  	 						  SYNOSDK_ACL_INHERIT_DIR | \
  	 						  SYNOSDK_ACL_INHERIT_NO_PROPOGATE
} SYNO_ACL_INHERIT;

/**
 *  @ingroup    ACL
 */
typedef enum _tag_SYNOSDK_ACL_ERROR_ {
	SYNOACL_ERR_INHERIT = 0x01,
	SYNOACL_ERR_IDTYPE = 0x02,
} SYNO_ACL_ERROR;

/**
 *  @ingroup    ACL
 */
typedef enum _tag_SYNO_ACL_RANGE_ {
	SYNOACL_INHERITED = 1, //inherited + self defined
	SYNOACL_SELF,  //Only self-defined
	SYNOACL_PSEUDO_INHERIT_ONLY, //Includes only inherited ACE, even entry has no inherited attribute.
} SYNO_ACL_RANGE;

/**
 *  @ingroup    print
 */
typedef enum _tag_SYNO_ACL_PRINT_TYPE_ {
	SYNOACL_PRINT_CONSOLE = 1,
	SYNOACL_PRINT_LOG,
} SYNO_ACL_PRINT_TYPE;

/**
 *  @ingroup    ACL
 */
typedef enum _tag_SYNO_ACL_STR_PARSE_TAG_ {
	SYNOACL_STR_ACL_ENTRY = 1,
	SYNOACL_STR_PERM,
} SYNO_ACL_STR_PARSE_TAG;

/**
 *  @ingroup    ACL
 */
enum {
	SYNO_ACL_IS_FS_SUPPORT = 1, //File System support ACL
	SYNO_ACL_IS_FILE_SUPPORT,  //File System support ACL and File/Dir is ACL mode
	SYNO_ACL_IS_SHARE_SUPPORT,  //Share support ACL
};

/**
 *  @ingroup    ACE
 */
typedef struct _tag_SYNO_ACL_ENTRY_ {
    SYNO_ACL_ID  aid;
    unsigned int  perm;			//SYNO_ACL_PERM, use short because cpu_to_le16()
    unsigned short  inherit;  //SYNO_ACL_INHERIT, use short because cpu_to_le16()
    BOOL  isAllow;
	unsigned int level;		//inheritence level: 0 means self-defined, 1 means parent folder...etc.
	struct _tag_SYNO_ACL_ENTRY_ *pNext;  //next entry
} SYNO_ACL_ENTRY;

/**
 *  @ingroup    ACL
 */
typedef struct _tag_SYNO_ACL_ {
    unsigned int version;
    unsigned int counts;
	BOOL isInherited;
	SYNO_ACL_ENTRY *pFirstEnt;
	SYNO_ACL_ENTRY *pLastEnt;
} SYNO_ACL;

/**
 *  the filter for filtering out ACEs
 *  ACEs matched all field in ACL are filtered out.
 *  However if no field has value, there is no ACE filtered.
 *
 *  @ingroup    ACL
 */
typedef struct _tag_SYNO_ACE_FILTER_ {
	int	*pIdx;
    SYNO_ACL_ID  *pID;
    SYNO_ACL_PERM  	  *pPerm;
    SYNO_ACL_INHERIT  *pInheritMode;
    BOOL  *pIsAllow;
	BOOL  *pIsInherited;
} SYNO_ACE_FILTER;

/**
 * ingroup  ACL
 */
typedef struct _tag_SYNO_ACE_STR_ {
	char  szName[MAX_NAME_LEN];
	char  szIDType[64];
    char  szAllow[32];
    char  szPerm[256];
    char  szInherit[256];
} SYNO_ACE_STR;

static inline BOOL SYNOACLIsInheritValid(unsigned short inherit)
{
	if (0 != (inherit & ~SYNOSDK_ACL_INHERIT_ALL)){
		return FALSE;
	}

	if ((SYNOSDK_ACL_INHERIT_ONLY & inherit) &&
		!((SYNOSDK_ACL_INHERIT_FILE|SYNOSDK_ACL_INHERIT_DIR) & inherit)){
		return FALSE;
	}

	return TRUE;
}

#ifndef NO_PROTO
#include <synoacl/synoacl_p.h>
#endif // NO_PROTO

__END_DECLS;
#endif // __SYNO_ACL_H__
