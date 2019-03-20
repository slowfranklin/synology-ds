// Copyright (c) 2000-2014 Synology Inc. All rights reserved.

/* share_get_acl.c */
int SYNOShareGetAcl(const PSYNOSHARE pShare, SYNO_ACL_ID_TYPE type, const char *szName);
/* share_set_acl.c */
int SYNOShareSetAcl(const PSYNOSHARE pShare, SYNO_ACL_ID_TYPE type, const char *szName, int share_perm);
/* share_list_acl.c */
int SYNOShareListAcl(const PSYNOSHARE pShare, PSLIBSZLIST *ppListAclRO, PSLIBSZLIST *ppListAclRW, PSLIBSZLIST *ppListAclNA, PSLIBSZLIST *ppListAclCU);
int SYNOShareAclToShare(const PSYNOSHARE pShare, PSLIBSZLIST *ppListAclRO, PSLIBSZLIST *ppListAclRW, PSLIBSZLIST *ppListAclNA);
/* share_get_groups_acl.c */
int SYNOShareGetGroupsAcl(const PSYNOSHARE pShare, const PSLIBSZLIST pListGroup);
int SYNOShareGetGroupsAclEx(const PSYNOSHARE pShare, const PSLIBSZLIST pListGroup, const char *szUser);
/* share_default_acl.c*/
int SYNOShareDefaultAclGet(const char *szShare, SYNO_ACL *pACL, BOOL isCreate);
int SYNOShareDefaultAclSet(const PSYNOSHARE pShare);
/* share_need_migrate.c */
int SYNOShareNeedMigrate(const PSYNOSHARE pShare, BOOL *blNeedMigrate);
/* share_is_acl_share.c */
BOOL SYNOShareIsSupportAcl(const PSYNOSHARE pShare);
BOOL SYNOShareIsSupportAclByPath(const char *szPath);
BOOL SYNOShareIsSupportAclByName(const char *szShare);
