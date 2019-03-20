/* synoacl_ace_alloc.c */

/**
 * Allocate an ACE structure
 *
 * @return the pointer to an allocated @p SYNO_ACL_ENTRY
 *
 * @exception calloc()
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
SYNO_ACL_ENTRY *SYNOACLAceAlloc(void);

/* synoacl_ace_append.c */

/**
 * Append an ACE list into ACL structure
 *
 * @param[in] pAcl     ACL
 * @param[in] pAce     ACL Entry which should be append to @p pAcl
 *
 * @retval  >=0  append counts
 * @retval  < 0  error
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceAppend(SYNO_ACL *pAcl, SYNO_ACL_ENTRY *pAce);

/* synoacl_ace_copy.c */

/**
 * Copy ACE from an entry to another entry
 *
 * if @p pDst is in the middle of an ACL linked list,
 * the copied @p pSrc will be added between @p pDst and @p pDst->pNext
 *
 * @param[out] pDst     the ACL entry
 * @param[in]  pSrc     the ACL entry to be copied
 *
 * @retval  -1  error
 * @retval  0   success
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceCopy(SYNO_ACL_ENTRY *pDst, const SYNO_ACL_ENTRY *pSrc);

/* synoacl_ace_dup.c */

/**
 * Duplicate an ACE
 *
 * @param[in] pAce  the ACL entry to be copied
 *
 * @retval  NULL        failed to allocate memory
 * @retval  !NULL       a pointer to the memory stored duplicated ACE
 *
 * @exception malloc()
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
SYNO_ACL_ENTRY *SYNOACLAceDup(const SYNO_ACL_ENTRY *pAce);

/* synoacl_ace_find.c */

/**
 * Find first ACE in @p pAce which match the given fields in @p pFilter.
 *
 * If @p ppPrev is given,
 * it will point to the previos ACE of the first matched ACE.
 *
 * It is NULL returned when @p pFilter contains nothing.
 *
 * @param[in]  pAce        ACL Entry
 * @param[in]  pFilter     ACL Entry filter
 * @param[out] ppPrev      Optional, The previous ACE of the matched ACE
 *
 * @retval NULL   not found
 * @retval !NULL  found
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
SYNO_ACL_ENTRY *SYNOACLAceFind(SYNO_ACL_ENTRY *pAce, SYNO_ACE_FILTER *pFilter, SYNO_ACL_ENTRY **ppPrev);

/* synoacl_ace_free.c */

/**
 * Free the given ACL entry @p pAce
 *
 * Passing a NULL pointer to SYNOACLAceFree() is harmless.
 *
 * @param[in]  pAce        ACL entry to be free
 *
 * @return None
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
void SYNOACLAceFree(SYNO_ACL_ENTRY *pAce);

/**
 * Free a list of allocated ACL entry
 *
 * Passing a NULL pointer to SYNOACLAceListFree() is harmless.
 *
 * @param[in]  pAce      a list of ACL entry to be free
 *
 * @return None
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
void SYNOACLAceListFree(SYNO_ACL_ENTRY *pAce);

/* synoacl_ace_from_str.c */

/**
 * Parse ACE string to ACE memory representation
 *
 * @p szStr should be present as:
 *   - type:name:[allow|deny]:permissions:inheritMode
 *
 * Example:
 *   - user:root:allow:rwx-d---RWc--:fd--
 *   - owner:*:allow:rwx-d---RWc--:fd--
 *
 * @param[in]  tag         SYNOACL_STR_ACL_ENTRY or SYNOACL_STR_PERM
 * @param[in]  szStr       string of ACE parameter
 * @param[out] pAce        ACE
 *
 * @retval      0   success
 * @retval     -1   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOUserGet()
 * @exception SYNOGroupGet()
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceFromStr(SYNO_ACL_STR_PARSE_TAG tag, const char *szStr, SYNO_ACL_ENTRY *pAce);

/* synoacl_ace_isvalid.c */

/**
 * Validate an ACL entry
 *
 * @p pResult is masked if the given ACE @p pAce is invalid.
 *
 * There are two types of mask for @p pResult:
 *   1. SYNOACL_ERR_IDTYPE
 *   2. SYNOACL_ERR_INHERIT
 *
 * @param[in]  pAce     the Ace to be validated
 * @param[out] pResult  stored the result of validation if it is not NULL
 *
 * @return      TURE    valid
 * @return      FALSE   invalid
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
BOOL SYNOACLAceIsValid(SYNO_ACL_ENTRY *pAce, int *pResult);

/* synoacl_ace_name_from_id.c */

/**
 * Get user/group name from uid/gid
 *
 * @param[in]  type	SYNOSDK_ACL_USER or SYNOSDK_ACL_GROUP
 * @param[in]  ID      uid/gid
 * @param[out] szName  return user/group name
 * @param[in]  cbName  memory size of @p szName array
 *
 * @retval  0   success
 * @retval  -1  fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOACLUserNameGetByUid()
 * @exception SYNOACLGroupNameGetByGid()
 *
 * @grantable no
 *
 * @apparmor abstractions/libsynoacl
 *
 * @see SYNOACLAceNameToID()
 * @ingroup ACE
 */
int SYNOACLAceNameFromID(SYNO_ACL_ID_TYPE type, unsigned int ID, char *szName, int cbName);

/* synoacl_ace_name_to_id.c */

/**
 * Get uid/gid from user/group name
 *
 * @param[in]  type	    SYNOSDK_ACL_USER or SYNOSDK_ACL_GROUP
 * @param[in]  szName      user/group name
 * @param[out] pID         uid/gid of user/group
 *
 * @retval  0   success
 * @retval  -1  fail
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NO_SUCH_USER
 * @exception ERR_NO_SUCH_GROUP
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_OP_FAILURE
 * @exception dlopen()
 * @exception dlsym()
 *
 * @grantable no
 *
 * @apparmor abstractions/libsynoacl
 *
 * @see SYNOACLAceNameFromID()
 * @ingroup ACE
 */
int SYNOACLAceNameToID(SYNO_ACL_ID_TYPE type, const char *szName, unsigned int *pID);

/* synoacl_ace_remove.c */

/**
 * Remove specified ACE, which matches @p pFilter, from ACL
 *
 * @param[in]  pAcl     ACL
 * @param[in]  pFilter  filter for remove
 * @param[out] ppOutAce removed ACEs
 *
 * @retval >=0  removed ace counts
 * @retval <0   error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SYNOACLAceFind()
 *
 * @see SYNOACLAceFind
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceRemove(SYNO_ACL *pAcl, SYNO_ACE_FILTER *pFilter, SYNO_ACL_ENTRY **ppOutAce);

/* synoacl_ace_replace.c */

/**
 * Replace the ACE in the index @p idx of ACL @p pACL with a copy of ACE @p pAce
 *
 * @param[in] pACL     ACL
 * @param[in] idx      the idx of replaced entry
 * @param[in] pAce     the ACE to replace with
 *
 * @retval  0   success
 * @retval -1   error
 *
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   ER_SYNOACL_NOT_VALID_TO_CHG     when replaced ACE is inherited
 * @exception SYNOACLAceFind()
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceReplace(SYNO_ACL *pACL, int idx, SYNO_ACL_ENTRY *pAce);

/* synoacl_ace_sort.c */
/**
 * Ensure aces' order is as following:
 *
 * Deny ace are in front of Allow ace
 * reference: http://www.ntfs.com/ntfs-permissions-acl-use.htm
 *
 * @param[in]  pAcl   ACL
 *
 * @retval    0     success
 * @retval   -1     error
 *
 * @exception SYNOACLAceRemove()
 * @exception SYNOACLAceAppend()
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup ACE
 */
int SYNOACLAceSort(SYNO_ACL *pAcl);

/* synoacl_ace_to_str.c */
/**
 *  Convert an ACE to string
 *
 * @param[in]   tag         SYNOACL_STR_ACL_ENTRY or SYNOACL_STR_PERM
 * @param[in]   pAce        the list of ACEs
 * @param[out]  pStrAce     strings of each fields of ACE
 *
 * @return  None
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLAceNameFromID()
 *
 * @grantable no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup ACE
 *
 * @see SYNOACLAceFromStr()
 */
void SYNOACLAceToStr(SYNO_ACL_STR_PARSE_TAG tag, const SYNO_ACL_ENTRY *pAce, SYNO_ACE_STR *pStrAce);

/* synoacl_add.c */
/**
 * Add ACEs to the file in the @p szPath
 *
 * @param[in]  szPath      the file path
 * @param[in]  pAce        list of ACEs
 *
 * @retval   0  success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLGet()
 * @exception SYNOACLAceDup()
 * @exception SYNOACLAceAppend()
 * @exception SYNOACLSet()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLAdd(const char *szPath, const SYNO_ACL_ENTRY *pAce);

/* synoacl_alloc.c */
/**
 * Allocate SYNO_ACL according to ace counts
 *
 * @param[in] counts    number of ACEs in allocated ACL
 *
 * @retval  NULL    error
 * @retval  !NULL   success
 *
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception SYNOACLAceAppend()
 *
 * @grantable no
 *
 * @apparmor    None
 * @ingroup     ACL
 */
SYNO_ACL *SYNOACLAlloc(int counts);

/* synoacl_archive_copy.c */
/**
 * Copy ACL Archive from @p szSrcPath to @p szDstPath while @p szDstPath support
 * ACL
 *
 * @param[in]  szSrcPath   source path
 * @param[in]  szDstPath   destination path
 *
 * @retval  0   success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLArchiveGet()
 * @exception SYNOACLArchiveSet()
 *
 * @grantable no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 */
int SYNOACLArchiveCopy(const char *szSrcPath, const char *szDstPath);

/* synoacl_archive_correct.c */
/**
 * Correct SYNO_ACL_ARCHIVE Archive Bit.
 *
 * @param[in] archBit      Archive bit option to check
 *
 * @return reasonable Archive bit setting
 *
 * @exception None
 *
 * @grantable no
 *
 * @apparmor None
 * @ingroup  Archive
 */
int SYNOACLArchiveCorrect(int archBit);

/* synoacl_archive_enable.c */
/**
 * Enable/Disable Archive Bit
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  enable   Archive bit that enabled
 * @param[in]  disable  Archive bit that disabled
 *
 * @retval  0   success
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OPEN_FAILED
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception SYNOArchiveOverwrite()
 *
 * @grantable no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 */
int SYNOACLArchiveEnable(const char *szPath, int fd, unsigned int enable, unsigned int disable);

/* synoacl_archive_from_str.c */
/**
 * Parse the given string @p szOpt to Archive bits @p pOpt
 *
 * @param[in]  szOpt   string of archive options
 * @param[out] pOpt    output archive bits
 *
 * @retval   0  success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     Archive
 */
int SYNOACLArchiveFromStr(const char *szOpt, int *pOpt);

/* synoacl_archive_get.c */
/**
 * Get Archive bits from the given file @p szPath
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[out] pOpt    output archive bits
 *
 * @retval   0  success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLFileStat()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 */
int SYNOACLArchiveGet(const char *szPath, int fd, int *pOpt);

/* synoacl_archive_is_enabled.c */
/**
 * Check if the given archive option @p opt is enabled
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  opt      archive bit option to check
 *
 * @retval  TRUE    enabled
 * @retval  FALSE   disabled
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLArchiveGet()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 */
BOOL SYNOACLArchiveIsEnabled(const char *szPath, int fd, SYNO_ACL_ARCHIVE opt);

/* synoacl_archive_overwrite.c */
/**
 * Overwrite archive bit of the given file @p szPath
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  opt      archive bit option to set
 *
 * @retval    0     success
 * @retval   -1     error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OPEN_FAILED
 * @exception   ERR_STAT_FAILED
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 */
int SYNOACLArchiveOverwrite(const char *szPath, int fd, int opt);

/* synoacl_archive_set.c */
/**
 * Set archive bit to the given file @p szPath
 *
 * This function is equal to SYNOACLArchiveOverwrite()
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  opt      archive bit option to set
 *
 * @exception SYNOACLArchiveOverwrite()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     Archive
 *
 * @see SYNOACLArchiveOverwrite()
 */
int SYNOACLArchiveSet(const char *szPath, int fd, int opt);

/* synoacl_archive_to_str.c */
/**
 * Convert archive bit @p opt to archive option string @p szOut
 *
 * @param[in]  opt     archive bit
 * @param[out] szOut   output string space
 * @param[in]  cbOut   the size of output string space
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     Archive
 */
int SYNOACLArchiveToStr(int opt, char *szOut, int cbOut);

/* synoacl_copy.c */
/**
 * Copy ACL from source path to destination
 *
 * Copy ACL when:
 *  - Source file/dir has ACL.
 * 	- Destination file system support ACL.
 *
 * @param[in] szSrcPath    source path
 * @param[in] szDstPath    destination path
 *
 * @retval    0     success
 * @retval   -1     error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 *
 * @grantable    no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLCopy(const char *szSrcPath, const char *szDstPath);

/* synoacl_delete.c */
/**
 * Remove the ACL in the index @p idx from the the given file @p szPath
 *
 * @param[in] szPath   file path
 * @param[in] idx      Index of ACL entry to delete. It's
 *  			        zero-based. -1 means remove all entries.
 *
 * @retval  0    success
 * @retval -1    error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_SYS_UNKNOWN
 * @exception   ERR_KEY_NOT_FOUND
 * @exception   ERR_SYNOACL_NOT_VALID_TOCHG
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception SYNOACLAceRemove()
 * @exception SYNOACLSet()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLDelete(const char *szPath, int idx);

/* synoacl_dump_from_mode.c */
/**
 * Dump POSIX permission of the given file @p szPath into ACL format
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[out] ppACL    ACL
 *
 * @retval   0   success
 * @retval  -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception stat()
 * @exception SYNOACLModeToPerm()
 *
 * @grantable    no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLDumpFromMode(const char *szPath, int fd, SYNO_ACL **ppACL);

/* synoacl_enforce_inherit.c */
/**
 * Clear all ACL except inherited ACL from @p szPath
 *
 * If @p szPath has no inherited ACL, the default ACL is set to @p szPath.
 *
 * @param[in]  szPath  file
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception strdup()
 * @exception SYNOACLResetInherit()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLEnforceInherit(const char *szPath);

/* synoacl_errno_2_synoerr.c */
/**
 * Convert errno to SYNOERR
 *
 * @param[in]  err errno
 *
 * @retval  SYNOERR
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     ACL
 */
SYNOERR SYNOACLErrno2SynoErr(int err);

/* synoacl_free.c */
/**
 * Free the given ACL
 * Passing a NULL pointer to SYNOACLFree() is harmless.
 *
 * @param[in]  pAcl    ACL
 *
 * @return  None
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     ACL
 */
void SYNOACLFree(SYNO_ACL *pAcl);

/* synoacl_get.c */
/**
 * Get acl raw data from EA
 *
 * @param[in]  szPath      file/dir path, can be NULL if @p fd is given
 * @param[in]  fd          file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  flag
 * @param[out] ppVal       EA value
 * @param[out] pcbSize     size of EA value
 *
 * @retval  1    found
 * @retval  0    not found
 * @retval  -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception getxattr()
 * @exception SLIBCErrGet()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLRawGetFromEA(const char *szPath, const int fd, SYNO_ACL_RANGE flag, char **ppVal, int *pcbSize);

/**
 * Get ACL from the given file @p szPath
 *
 * @param[in]  szPath      file/dir path, can be NULL if @p fd is given
 * @param[in]  fd          file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  flag
 * @param[out] ppACL
 *
 * @retval  1   found
 * @retval  0   not found
 * @retval  -1  error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_SYS_UNKNOWN
 * @exception ERR_SYNOACL_NOT_SUPPORT
 * @exception SYNOACLRawGetFromEA()
 * @exception SYNOACLArchiveGet()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLGet(const char *szPath, int fd, SYNO_ACL_RANGE flag, SYNO_ACL **ppACL);

/* synoacl_group_name_get_by_gid.c */
/**
 * Get group name from gid
 *
 * @param[in]  gid             gid
 * @param[out] szGroupName    group name
 * @param[in]  cbGroupName     sizeof szGroupName
 *
 * @retval   0  success
 * @retval   -1 fail
 *
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_OP_FAILURE
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLGroupNameGetByGid(gid_t gid, char *szGroupName, int cbGroupName);

/* synoacl_is_apply.c */
/**
 * Check if @p szPath has ACL
 *
 * @param[in]  szPath  file path
 *
 * @retval  TRUE
 * @retval  FALSE
 *
 * @exception   ERR_BAD_PARAMETERS
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
BOOL SYNOACLIsApply(const char *szPath);

/* synoacl_is_support_acl.c */
/**
 * Check if path @p szPath or @p fd supports ACL.
 *
 * @param[in]  szPath      file/dir path, can be NULL if @p fd is given
 * @param[in]  fd          file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  tag         Which support key to get
 *
 * @retval FALSE Does not support.
 * @retval TRUE  Supports.
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception SYNOACLSysIsSupport()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
BOOL SYNOACLIsSupport(const char *szPath, int fd, int tag);

/* synoacl_mode_to_perm.c */
/**
 * Map linux mode to ACL permission
 *
 * @param[in] mode  Linux mode, it shoud be shifted before calling this function.
 *
 * @return  >= 0
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     ACL
 */
unsigned int SYNOACLModeToPerm(mode_t mode);

/* synoacl_owner_get.c */
/**
 *  Get owner uid/gid of @p szPath
 *
 *  @param[in]  szPath  file path
 *  @param[out] pACLId  owner uid/gid
 *
 *  @retval 0   success
 *  @retval -1  failed
 *
 *  @exception  ERR_BAD_PARAMETERS
 *  @exception  ERR_ACCESS_DENIED
 *  @exception  ERR_PATH_NOT_FOUND
 *  @exception  ERR_STAT_FAILED
 *  @exception SYNOACLArchiveGet()
 *
 *  @grantable  no
 *
 *  @apparmor abstractions/libsynoacl
 *  @ingroup     ACL
 */
int SYNOACLOwnerIdGet(const char *szPath, SYNO_ACL_ID *pACLId);

/**
 *  Get owner of @p szPath
 *
 *  @param[in]     szPath  file path
 *  @param[out]    pType   owner type
 *  @param[out]    szName  owner name
 *  @param[in]     cbName  the size of @p szName
 *
 *  @retval 0   success
 *  @retval -1  failed
 *
 *  @exception  ERR_BAD_PARAMETERS
 *  @exception  ERR_SYS_UNKNOWN
 *  @exception SYNOACLOwnerIdGet()
 *
 *  @grantable  no
 *
 *  @apparmor abstractions/libsynoacl
 *  @ingroup     ACL
 *
 *  @see SYNOACLOwnerIdGet()
 */
int SYNOACLOwnerGet(const char *szPath, SYNO_ACL_ID_TYPE *pType, char *szName, int cbName);

/* synoacl_owner_set.c */
/**
 *  Set owner to @p szPath
 *
 *  @param[in]  szPath  file path
 *  @param[in]  pAclID  owner uid/gid
 *
 *  @retval 0   success
 *  @retval -1  failed
 *
 *  @exception  ERR_BAD_PARAMETERS
 *  @exception  ERR_ACCESS_DENIED
 *  @exception  ERR_NOT_ENOUGH_QUOTA
 *  @exception  ERR_SYS_UNKNOWN
 *  @exception  ERR_SYNOACL_NOT_SUPPORT
 *
 *  @grantable  no
 *
 *  @apparmor abstractions/libsynoacl
 *  @ingroup     ACL
 */
int SYNOACLOwnerSet(const char *szPath, SYNO_ACL_ID *pAclID);

/* synoacl_path_check.c */
/**
 * Check is path illegal for ACL SDK.
 *
 * @param[in] szPath file/dir path
 *
 * @retval FALSE    illegal
 * @retval TRUE     pass
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_INVALID_PATH
 * @exception stat()
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
BOOL SYNOACLPathCheck(const char *szPath);

/* synoacl_perm_calc.c */
/**
 * This function checks user file permission
 *
 * @param[in]  szUser  username
 * @param[in]  pGroups group list; if NULL, it will get grouplist
 * @param[in]  szPath  share path
 * @param[out] perm    share path
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_NOT_ENOUGH_MEMORY
 * @exception   ERR_OP_FAILURE
 * @exception getpwname()
 * @exception SYNOACLGet()
 * @exception SYNOACLDumpFromMode()
 * @exception SYNOACLIsSupport()
 * @exception SYNOACLAceNameToID()
 * @exception SYNOACLAceNameFromID()
 * @exception SLIBCSzHashSetValue()
 * @exception SLIBCSzHashGetValue()
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLPermCalc(const char *szUser, PSLIBSZLIST pGroups, const char *szPath, int *perm);

/* synoacl_perm_check.c */
/**
 * Check specified permission
 *
 * @param[in] szPath    path to check permission
 * @param[in] perm    specified permission to check
 *
 * @retval 1    pass the check
 * @retval 0    not pass
 * @retval -1   error
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_ACCESS_DENIED
 * @exception   ERR_SYNOACL_NO_PERM
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLPermCheck(const char *szPath, unsigned int perm);

/* synoacl_perm_get.c */
/**
 * Caculating allowed permissions from ACL or Linux permissions.
 * Permissions for root or owner is included.
 *
 * If user is root, full control permission will be returned.
 *
 * @param[in]  szPath  file/dir path
 * @param[out] pPerm   permissions
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_ACCESS_DENIED
 * @exception   ERR_SYNOACL_NO_PERM
 * @exception   ERR_PATH_NOT_FOUND
 * @exception stat()
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLPermGet(const char *szPath, int *pPerm);

/**
 * The same as SYNOACLPermGet()
 * Just the version for improving performance of Samba.
 *
 * @param[in]  szPath file/dir path
 * @param[in]  pSt    Here only need udi/gid/mode, can not be NULL
 * @param[in]  pStDir Here only need udi/gid/mode, can be NULL.
 * @param[out] pPerm  permissions
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_ACCESS_DENIED
 * @exception   ERR_SYNOACL_NO_PERM
 * @exception   ERR_PATH_NOT_FOUND
 * @exception stat()
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 *
 * @see SYNOACLPermGet()
 */
int SYNOACLPermGetWithStat(const char *szPath, const struct stat *pSt, const struct stat *pStDir, int *pPerm);

/* synoacl_print.c */
/**
 * Print ACL of file @p szPath
 *
 * @param[in]  szPath  file/dir path
 * @param[in]  prType  output type, SYNOACL_PRINT_CONSOLE or SYNOACL_PRINT_LOG
 * @param[in]  pACL    ACL
 *
 * @return None
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     Print
 */
void SYNOACLPrint(const char *szPath, SYNO_ACL_PRINT_TYPE prType, const SYNO_ACL *pACL);

/**
 * Print Error Message of errno
 *
 * @param[in]  synoerr errno
 * @param[in]  prType  output type, SYNOACL_PRINT_CONSOLE or SYNOACL_PRINT_LOG
 * @param[in]  szFile  filename, usually be given the macro __FILE__
 * @param[in]  line    line number, usually be given the macro __LINE__
 *
 * @return      None
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor    None
 * @ingroup     Print
 */
void SYNOACLPrintErr(int synoerr, SYNO_ACL_PRINT_TYPE prType, char *szFile, int line);

/**
 * Print Archive string of file @p szPath
 *
 * @param[in]  szPath  file/dir path
 * @param[in]  prType  output type, SYNOACL_PRINT_CONSOLE or SYNOACL_PRINT_LOG
 *
 * @return      None
 *
 * @exception   None
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     Print
 */
int SYNOACLPrintArchive(const char *szPath, SYNO_ACL_PRINT_TYPE prType);

/* synoacl_reset_inherit.c */
/**
 * Reset ACL to only inherit, if there is no inherited ACL, set default ACL
 *
 * @param[in]  szPath  file/dir path
 *
 * @retval 0    success
 * @retval  -1  failed
 *
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception SYNOACLSet()
 * @exception SYNOACLGet()
 * @exception SYNOACLSetDefault()
 *
 * @grantable   Yes
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLResetInherit(const char *szPath);

/* synoacl_set.c */
/**
 * Set ACL raw data into xattr
 *
 * @param[in]  szPath   file/dir path, can be NULL if @p fd is given
 * @param[in]  fd       file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  szVal     value
 * @param[in]  cbSize   the size of @p pVal
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception setxattr()
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLRawSetToEA(const char *szPath, const int fd, char *szVal, int cbSize);

/**
 * Set ACL into file @p szPath
 *
 * @param[in]  szPath  file/dir path, can be NULL if @p fd is given
 * @param[in]  fd      file/dir's fd, can be -1   if @p szPath is given
 * @param[in]  pACL    ACL
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_SYNOACL_ENTRY_EXCEED
 * @exception   ERR_SYNOACL_NOT_SUPPORT
 * @exception   ERR_SYS_UNKNOWN
 * @exception SYNOACLAceRemove()
 * @exception SYNOACLDumpToEA()
 * @exception SYNOACLRawSetToEA()
 * @exception SYNOACLArchiveEnable()
 * @exception removexattr()
 * @exception fcntl()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLSet(const char *szPath, int fd, SYNO_ACL *pACL);

/* synoacl_set_def.c */
/**
 * Set default ACL info file @p szPath
 *
 * @param[in]  szPath  file/dir path, can be NULL if @p fd is given
 * @param[in]  fd      file/dir's fd, can be -1   if @p szPath is given
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception SYNOACLSet()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLSetDefault(const char *szPath, int fd);

/* synoacl_set_ea_dir_acl.c */
/**
 * Set default ACL info eadir @p szPath
 *
 * @param[in]  szEADirPath  eadir path, can be NULL if @p fd is given
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   ERR_OUT_OF_MEMORY
 * @exception SYNOACLSet()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLSetEADirACL(const char *szEADirPath);

/* synoacl_set_web_dir_acl.c */
/**
 * Get default web dir ACL
 *
 * @param[out] ppACL    web dir ACL; if pACL is NULL, create; else append
 * @param[in]  perm     perm of the new ACE
 *
 * @retval  0   success
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOACLAceAppend()
 *
 * @grantable   no
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLWebDirDefaultAclGet(SYNO_ACL **ppACL, unsigned int perm);

/**
 * Set default web dir ACL to @p szPath
 *
 * @param[in]  szPath  share path
 * @param[in]  perm    perm of the new ACE
 *
 * @retval  0   success or file already has ACL
 * @retval  -1  failed
 *
 * @exception   ERR_BAD_PARAMETERS
 * @exception   SYNOACLWebDirDefaultAclGet()
 * @exception   SYNOACLSet()
 *
 * @grantable   Yes
 *
 * @apparmor    abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLWebDirDefaultAclSet(const char *szPath, unsigned int perm);

/* synoacl_user_name_get_by_uid.c */
/**
 * Get user name from uid
 *
 * @param[in]  uid         uid
 * @param[out] szUserName  user name
 * @param[in]  cbUserName  the size of @p szUserName
 *
 * @retval  0   success
 * @retval  -1  fail
 *
 * @exception   ERR_OUT_OF_MEMORY
 * @exception   ERR_NO_SUCH_USER
 * @exception   ERR_OP_FAILURE
 *
 * @grantable   no
 *
 * @apparmor abstractions/libsynoacl
 * @ingroup     ACL
 */
int SYNOACLUserNameGetByUid(uid_t uid, char *szUserName, int cbUserName);
