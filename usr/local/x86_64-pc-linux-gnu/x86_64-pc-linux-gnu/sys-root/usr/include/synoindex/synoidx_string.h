// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_STRING_H
#define _SYNO_IDX_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

void StringTrim(char *pString);
int EscapePercentSign(const char *szIn, char *szOut, int cbOut);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
