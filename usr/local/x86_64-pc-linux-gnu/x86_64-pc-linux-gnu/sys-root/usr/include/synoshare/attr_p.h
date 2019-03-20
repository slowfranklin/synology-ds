// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef __SYNOSHARE_ATTR_PROTO_H__
#define __SYNOSHARE_ATTR_PROTO_H__

/* attr_readonly_handler.c */
int SYNOShareAttrReadOnlyReg(const char *szShareName, const char *szWho, const char *szMsg);
int SYNOShareAttrReadOnlyUnreg(const char *szShareName, const char *szWho);
BOOL SYNOShareAttrReadOnlyCanReg(const char *szShareName, const char *szWho, char **pszMsg);
BOOL SYNOShareAttrReadOnlyIsRegBy(const char *szShareName, const char *szWho);
int SYNOShareAttrReadOnlySubscriberGet(const char *szShareName, char **pszWho);

#endif  // __SYNOSHARE_ATTR_PROTO_H__
