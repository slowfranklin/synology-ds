/* matrix_addition.c */
int MatrixAddition(PMATRIX pma, PMATRIX pmb, PMATRIX pmc);
/* matrix_alloc.c */
PMATRIX MatrixAlloc(int row, int col);
/* matrix_decode.c */
int MatrixDecode(char *szCode, char *szData);
/* matrix_encode.c */
int MatrixEncode(char *szData, char *szCode);
/* matrix_free.c */
void MatrixFree(PMATRIX pm);
/* matrix_int.c */
/* matrix_inversion.c */
int MatrixInversion(PMATRIX pm, PMATRIX pmi);
/* matrix_multiply.c */
int MatrixMultiply(PMATRIX pma, PMATRIX pmb, PMATRIX pmc);
/* matrix_subtraction.c */
int MatrixSubtraction(PMATRIX pma, PMATRIX pmb, PMATRIX pmc);
/* matrix_transpose.c */
int MatrixTranspose(PMATRIX pm, PMATRIX pmt);
