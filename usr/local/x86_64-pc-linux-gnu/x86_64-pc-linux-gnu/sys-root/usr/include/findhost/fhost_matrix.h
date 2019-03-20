// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_MATRIX_H
#define SYNO_FHOST_MATRIX_H

#include <sys/cdefs.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define		ERR_PARAM		-1
#define		ERR_OPERANT		-2
#define		ERR_OUTOFMEM	-3

#define		SizeOfMatrix(row, col)	(sizeof(int)*2+sizeof(double)*(row)*(col))
#define		Matrix(pm, x, y)		((pm)->matrix[(pm)->row*(x)+(y)])

typedef	struct	_tag_matrix_ {
	int		row, col;
	double	matrix[1];
} MATRIX, *PMATRIX;

#ifndef NO_PROTO
#include "fhost_matrix_p.h"
#endif // NO_PROTO

#ifdef  __cplusplus
}
#endif
#endif
