// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef FHOST_FIELD_H
#define FHOST_FIELD_H

#include <stddef.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define LENGTHOF(s,m)   (size_t)(sizeof(((s *)0)->m))

typedef enum {
	FIELD_STRING,
	FIELD_INTEGER,
	FIELD_ARRAY,
	FIELD_TYPE_NUM,
} FHOST_FIELD_TYPE;

typedef int(*PFUNC_READER)(const FHOSTLOG *pLog, const unsigned char *szPKTInput, int cbPKTInput, void *pFieldOutput, size_t cbFieldOutput, int options, const unsigned int cArrayElement);
typedef int(*PFUNC_WRITER)(const FHOSTLOG *pLog, char *szPKTOutput, int cbPKTOutput, FHOST_PKT_ID PktId, const void *pFieldInput, size_t cbFieldInput, int options, const void *pNASInfo);

typedef struct {
	FHOST_FIELD_TYPE fieldType;
	PFUNC_READER pfuncReader;
	PFUNC_WRITER pfuncWriter;
} FIELD_PARSER;

typedef struct {
	FHOST_PKT_ID     pktID;
	FHOST_FIELD_TYPE fieldType;
	size_t           uiOffset;
	size_t           uiLength;
	int              iParserFlags;
	FHOST_PKT_MASK   ulMaskValue;
} FIELD_ATTRIB;

typedef struct {
	FHOST_PKT_ID ArrayPktID;
	FHOST_PKT_ID CountPktID;
} FIELD_ARRAY_COUNT_MAP;

#ifdef  __cplusplus
}
#endif
#endif // FHOST_FIELD_H
