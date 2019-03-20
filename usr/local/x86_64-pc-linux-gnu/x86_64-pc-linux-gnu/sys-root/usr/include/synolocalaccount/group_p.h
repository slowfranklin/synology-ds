// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

/* group_set.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountGroupSet(const char *szOldGroupName, const PSYNOGROUP pGroup);
/* group_desc_set.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountGroupDescSet(const char *szGrpName, const char *szDesc);
/* group_delete.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountGroupDelete(const char **rgszGroupName, const int nItem);
/* group_extra_admin_set.c */
DSM_STARTING_FROM(SDK_VER_6_0) int SYNOLocalAccountGroupExtraAdminSet(const char *category, unsigned int *pLocalUid, unsigned int *pLocalGid, unsigned int *pDirUid, unsigned int *pDirGid);

/**
 * @brief Join user into local group.
 *
 * @param[in] szUserName  Join user, must not be NULL.
 * @param[in] szGroupName Group which user join, must not be NULL.
 *
 * @retval 1: On success.
 * @retval 0: User already in group.
 * @retval -1: On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCUnicodeUTF8StrUpper()
 *
 * @grantable Yes
 * @user root
 * @apparmor libsynolocalaccount
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SYNOLocalAccountGroupMemberJoin(const char *szUserName, const char *szGroupName);
