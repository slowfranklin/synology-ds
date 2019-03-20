#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2007 Synology Inc. All rights reserved.

#ifndef __SYNO_COPY_H_
#define __SYNO_COPY_H_
#ifndef __USE_XOPEN
#define __USE_XOPEN
#endif
#include <sys/cdefs.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/file.h>
#include <synocore/error.h>

#include <synofileop/ea.h>

__BEGIN_DECLS;

typedef enum _tag_synocopy_options {
    SYNOCOPY_OPT_NOOP           = 0u,
    SYNOCOPY_OPT_REMOVESRC      = (1u << 0),
    SYNOCOPY_OPT_OVERWRITE      = (1u << 1),
    SYNOCOPY_OPT_COPYACL        = (1u << 2),
    SYNOCOPY_OPT_FORCECHOWN     = (1u << 3),
    SYNOCOPY_OPT_FILEINDEX      = (1u << 4),
    SYNOCOPY_OPT_MEDIAINDEX     = (1u << 5),
    SYNOCOPY_OPT_REFLINK        = (1u << 6),
    SYNOCOPY_OPT_MAX            = (1u << 7),           /* no use, just for SYNOCOPY_OPT_ALL */
    SYNOCOPY_OPT_ALL            = SYNOCOPY_OPT_MAX - 1 /* all copy options*/
} synocopy_opt_t;

/** 
 * @defgroup COPY The zero-copy functions for duplicate files to file system. 
 * @{ 
 * @defgroup COPY_int The internal structure and functions for COPY.
 */

/**
 * The function pointer of taking two arguments to update COPY
 * progress. The first parameter is the bytes that are copyed in
 * one loop and the second parameter is the total bytes that
 * this file is copyed.
 */
typedef int (*PFUNC_Prog) (unsigned long long ui64Inc,
			   unsigned long long ui64Total);
typedef int (*PFUNC_THR_Prog) (void *pTHRData, unsigned long long ui64Inc,
				unsigned long long ui64Total);

/** 
 * This method provide the policy of renaming file. szPath is 
 * the full path of destination file. 
 *  
 * @param szOldPath 
 * 			[IN] existing filename, will not be NULL
 * @param szNewPath 
 * 			[OUT] buffer to store new filename, will not be NULL
 * @param cbNewPath 
 * 			[IN] buffer size of szRename
 * @return 
 *  	0: success
 *  	-1: fail
 */
typedef int (*PFUNC_Rename) (const char *szOldPath, char *szNewPath, int cbNewPath);
typedef int (*PFUNC_THR_Rename) (void *pTHRData, const char *szOldPath, char *szNewPath, int cbNewPath);

/**
 * The function pointer of taking two arguments to report copy 
 * error. The first parameter is the file path that error 
 * occured and the second parameter is the SynoErrorCode. 
 */
typedef int (*PFUNC_ErrReport) (const char *szPath, SYNOERR synoerr);
typedef int (*PFUNC_THR_ErrReport) (void *pTHRData, const char *szPath, SYNOERR synoerr);

/**
 * The function pointer of testing the copy operation is 
 * cancelled by user or not. Returns TRUE when cancelled.
 */
typedef int (*PFUNC_Test) (void);
typedef int (*PFUNC_THR_Test) (void *pTHRData);

/**
 * 
 */
typedef enum {
	CLEAN_NONE = 0,
	CLEAN_DST,
	CLEAN_SRC
}COPY_CLEAN_ARCHIVE_BIT;

typedef enum {
	COPY_UNKNOWN = -1,
	COPY_SKIP = FALSE,
	COPY_OVERWRITE = TRUE
} COPY_OVERWRITE_OPTION;

/**
 * The arguments for SYNOFileCopy() and SYNOFileCopyDirectory().
 *  
 * @author \$Author: ericlee $ 
 * @version \$Revision: 1.22 $
 * @struct SYNOCOPYARGS copy.h <synosdk/copy.h> 
 */
typedef struct {
	/** 
	 * The value that make this function remove the existed
	 * directory/file before copy when COPY_OVERWRITE/TRUE, 
	 * skip the existed file when COPY_SKIP/FALSE,
	 * or occur an ERR_PATH_CONFLICT error in the existed file when COPY_UNKNOWN.
	 */
	int         blOverWrite;
	/** 
	 * The boolean that remove the source file after copy is success
	 * when TRUE.
	 */
	BOOL        blRemoveSrc;
	/** 
	 * The boolean that make copy action stop when error occure when
	 * TRUE.
	 */
	BOOL        blStopWhenError;
	/** 
	 * The boolean that keep file owner when TRUE. 
	 */
	BOOL        blKeepOwner;
	/** 
	 * The boolean that copy ACL when TRUE. 
	 */
	BOOL        blCopyACL;
	/** 
	 * Enforce ACL inheritance of destination "file". 
	 *  
	 * Policy: 
	 *     1. ONLY effected:
	 *  		- Destination dir is in ACL mode.
	 
	 *     2. If parent dir doesn't propagate any ACE, then
	 *     defaultACL will be assigned.
	 *  
	 *     3. In general, only 'admin(root)' or 'file owner' have enough 
	 * privilege to use this option.
	 * 
	 *		4. Original ACL will be cleaned
	 *  
	 */ 
	BOOL		blEnforceACLInherit;
	/**
	 * The flag that judge whether need to clean archive bit (source
	 * data or destination data) or not.
	 */
	COPY_CLEAN_ARCHIVE_BIT cleanArchive;
	/** 
	 * The call back function that updates copy progress.  May be
	 * NULL.
	 */
	PFUNC_Prog  pfuncSetProgress;
	/** 
	 * The call back function that reports copy error.  May be
	 * NULL.
	 */
	PFUNC_ErrReport  pfuncErrReport;
	/** 
	 * The call back function that checks this operation should be
	 * terminated before it finished.  May be NULL.
	 */
	PFUNC_Test  pfuncIsCancel;
	/** 
	 * Rename policy when target file already exist. Only apply to
	*  files, no directories. May be NULL.
	*  This field take place When blOverWrite is false and target
	*  file already exists.	If it's not NULL, it will be executed
	*  only once and should return a name for copy retrying. If it's
	*  NULL, skip policy will apply.
	 */
	PFUNC_Rename	pfuncRename;
	/** 
	 * Force Copy the MY_ABC_HERE in @eaDir to destination
	 */
	BOOL		blForceCopySYNOEA;
	/** 
         * Set the file uid if the user ID of the calling process is 0
         */
	uid_t		userUID;
	/** 
         * Set the file gid if the user ID of the calling process is 0
         */
	gid_t		userGID;
	/**
	 * Check if it is necessary to trigger media indexing. For some
	 * conditions, it is not expected to do media indexing. For
	 * example, file operation in photo station will do media
	 * indexing in PHP, so media indexing is not expected to trigger
	 * in file/dir copy in synosdk.
	 */
	BOOL		blMediaIndexIsNotNeeded;
} SYNOCOPYARGS, *PSYNOCOPYARGS;

typedef long long(*PFUNC_GetReadSize) (unsigned long long ui64Inc, unsigned long long ui64Total);
typedef struct _SYNOCOPYARGSEX SYNOCOPYARGSEX;
typedef int(*PFUNC_ReadWriteData) (const char *szSrcFileName, const char *szDstFileName, 
					int *fdSrc, int *fdDst,
					off_t filesize,
					PFUNC_Prog pfuncSetProgress,
					PFUNC_Test pfuncIsCancel,
					const SYNOCOPYARGSEX * pArgsEx);
typedef int(*PFUNC_CopyFile) (const char *szSrcFileName, const char *szDstFileName, 
				const PSYNOCOPYARGS pArgs, int srcFsType, int destFsType, BOOL blFileIndexNeed, const SYNOCOPYARGSEX *pArgsEx);
typedef unsigned long long(*PFUNC_GetDirSize) (const char *szSrcPath, const char *szDstPath);

/*
 * Thread-safe version
 * */
typedef struct {
	/**
	 * The value that make this function remove the existed
	 * directory/file before copy when COPY_OVERWRITE/TRUE,
	 * skip the existed file when COPY_SKIP/FALSE,
	 * or occur an ERR_PATH_CONFLICT error in the existed file when COPY_UNKNOWN.
	 */
	int         blOverWrite;
	/**
	 * The boolean that remove the source file after copy is success
	 * when TRUE.
	 */
	BOOL        blRemoveSrc;
	/**
	 * The boolean that make copy action stop when error occure when
	 * TRUE.
	 */
	BOOL        blStopWhenError;
	/**
	 * The boolean that keep file owner when TRUE.
	 */
	BOOL        blKeepOwner;
	/**
	 * The boolean that copy ACL when TRUE.
	 */
	BOOL        blCopyACL;
	/**
	 * Enforce ACL inheritance of destination "file".
	 *
	 * Policy:
	 *     1. ONLY effected:
	 *  		- Destination dir is in ACL mode.
	 *     2. If parent dir doesn't propagate any ACE, then
	 *     defaultACL will be assigned.
	 *
	 *     3. In general, only 'admin(root)' or 'file owner' have enough
	 * privilege to use this option.
	 *
	 *		4. Original ACL will be cleaned
	 *
	 */
	BOOL		blEnforceACLInherit;
	/**
	 * The flag that judge whether need to clean archive bit (source
	 * data or destination data) or not.
	 */
	COPY_CLEAN_ARCHIVE_BIT cleanArchive;
	/**
	 * Force Copy the MY_ABC_HERE in @eaDir to destination
	 */
	BOOL		blForceCopySYNOEA;
	/**
         * Set the file uid if the user ID of the calling process is 0
         */
	uid_t		userUID;
	/**
         * Set the file gid if the user ID of the calling process is 0
         */
	gid_t		userGID;
	/**
	 * Check if it is necessary to trigger media indexing. For some
	 * conditions, it is not expected to do media indexing. For
	 * example, file operation in photo station will do media
	 * indexing in PHP, so media indexing is not expected to trigger
	 * in file/dir copy in synosdk.
	 */
	BOOL		blMediaIndexIsNotNeeded;
} SYNOCOPYTHRARGS, *PSYNOCOPYTHRARGS;

typedef struct _SYNOCOPYTHRCALLBACK SYNOCOPYTHRCALLBACK;
typedef long long(*PFUNC_THR_GetReadSize) (void *pTHRData, unsigned long long ui64Inc, unsigned long long ui64Total);
typedef int(*PFUNC_THR_ReadWriteData) (void *pTHRData, const char *szSrcFileName, const char *szDstFileName,
					int *fdSrc, int *fdDst,
					off_t filesize,
					PFUNC_THR_Prog pfuncSetProgress,
					PFUNC_THR_Test pfuncIsCancel,
					const SYNOCOPYTHRCALLBACK *pCallbackArgs);
typedef int(*PFUNC_THR_CopyFile) (void *pTHRData, const char *szSrcFileName, const char *szDstFileName,
				const PSYNOCOPYTHRARGS pTHRArgs, int srcFsType, int destFsType, BOOL blFileIndexNeed, const SYNOCOPYTHRCALLBACK *pCallbackArgs);
typedef unsigned long long(*PFUNC_THR_GetDirSize) (void *pTHRData, const char *szSrcPath, const char *szDstPath);

/**
 * @}
 */

#ifndef NO_PROTO
#include <availability.h>
#include <synofileop/copy_p.h>
#endif // NO_PROTO

__END_DECLS;

#endif
