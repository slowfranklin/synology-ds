// Copyright (c) 2000-2015 Synology Inc. All rights reserved.

/* btrfs_share_op.c */
int SYNOShareSnapShareCreate(const char *szSharePath, const char *szShareName);
int SYNOShareSnapConfigDelete(const char *szShareRealPath);
int SYNOShareSnapDataDelete(const char *szShareRealPath);
int SYNOShareSnapShareRename(const PSYNOSHARE pOrigShare, const PSYNOSHARE pNewShare, const char *szSrcPath, const char *szTargetPath);
