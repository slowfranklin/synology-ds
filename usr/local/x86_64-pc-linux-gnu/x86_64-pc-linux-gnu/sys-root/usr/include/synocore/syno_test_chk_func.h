#ifndef _SYNO_TEST_CHK_FUNC_H_
#define _SYNO_TEST_CHK_FUNC_H_

#define SZ_SYNO_CHECK_SLIBERR_FMT "SLIBCErrGet()=[0x%04X, at %s:%d]"
#define SYNO_CHECK_SLIBERR_ARGS	SLIBCErrGet(), SLIBCErrorGetFile()?SLIBCErrorGetFile():"(NULL)", SLIBCErrorGetLine()

/**
 * Stop and print messages when the expression (@a _VAL @a _OP 
 * @a _EXPR) is false. 
 *  
 * @param _TYPE [IN] The type of function and value to be 
 *  			evaluated, ie, int, unsigned short, char *.
 *  			Should not be void.
 * @param _TFMT [IN] The format string of @a _TYPE to pass to 
 *  			printf(), ie, "%d", "%s", "%p".  Shoud not be
 *  			NULL or empty string.
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated. 
 *  
 * @ingroup UNITTEST_int
 */
#define _SYNOChkFunc(_TYPE, _TFMT, _VAL, _OP, _EXPR) \
do {																					\
	_TYPE __temp_V;																		\
	_TYPE __temp_E; 																	\
	SLIBCErrSet(0); 																		\
	errno = 0; SYNOCheck(0 != errno);													\
	__temp_E = (_TYPE)(_EXPR); __temp_V = (_TYPE)(_VAL);								\
	SYNOCheckFail(__temp_V _OP __temp_E,												\
	"(%s=["_TFMT"]) %s (%s=["_TFMT"]) test failed, errno=[%d], "SZ_SYNO_CHECK_SLIBERR_FMT,	\
	#_VAL, __temp_V, #_OP, #_EXPR, __temp_E, errno,										\
	SYNO_CHECK_SLIBERR_ARGS);	\
} while (0)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncInt(_VAL, _OP, _EXPR) _SYNOChkFunc(int, "%d", _VAL, _OP, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncIntEq(_VAL, _EXPR) SYNOChkFuncInt(_VAL, ==, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncIntNEq(_VAL, _EXPR) SYNOChkFuncInt(_VAL, !=, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncHex(_VAL, _OP, _EXPR) _SYNOChkFunc(unsigned int, "%X", _VAL, _OP, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncHexEq(_VAL, _EXPR) SYNOChkFuncHex(_VAL, ==, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncPtr(_VAL, _OP, _EXPR) _SYNOChkFunc(void *, "%p", _VAL, _OP, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncIsNull(_EXPR) SYNOChkFuncPtr(NULL, ==, _EXPR)

/**
 * Stop and print messages when the function expression (@a
 * _VAL @a _OP @a _EXPR) is false.
 * 
 * @param _VAL [IN] The value to be tested.
 * @param _OP [IN] The operator to be tested.
 * @param _EXPR [IN] The expression to be evaluated.
 * @ingroup UNITTEST
 * @remarks Output target mappings:
 * <table>
 * <tr>
 * <th>Return type</th>
 * <th>Operator ==</th>
 * <th>Operator !=</th>
 * <th>Other operators </th>
 * </tr>
 * <tr>
 * <th>int</th>
 * <td>SYNOChkFuncIntEq()</td>
 * <td>SYNOChkFuncIntNEq()</td>
 * <td>SYNOChkFuncInt()</td>
 * </tr>
 * <tr>
 * <th>HEX int</th>
 * <td>SYNOChkFuncHexEq()</td>
 * <td></td>
 * <td>SYNOChkFuncHex()</td>
 * </tr>
 * <th>void *</th>
 * <td>SYNOChkFuncPtrEq()</td>
 * <td>SYNOChkFuncPtrNEq()</td>
 * <td>SYNOChkFuncPtr()</td>
 * </tr>
 * </table>
 */
#define SYNOChkFuncNonNull(_EXPR) SYNOChkFuncPtr(NULL, !=, _EXPR)		
				
/**
 * Stop and print messages when the expression (@a _VAL ==
 * @a _EXPR) is false. 
 *  
 * @param _VAL [IN] The value to be tested.
 * @param _EXPR [IN] The expression to be evaluated. 
 *  
 * @ingroup UNITTEST
 */
#define SYNOChkFuncBool( _VAL, _EXPR) \
do {																				\
	int __temp_V;																	\
	int __temp_E; 																	\
	SLIBCErrSet(0); 																	\
	errno = 0; SYNOCheckIntEq(0, errno);											\
	__temp_E = (int)(_EXPR); __temp_V = (int)(_VAL);								\
	SYNOCheckFail(__temp_V == __temp_E,												\
	"%s == (%s=[%s]) test failed, errno=[%d], "SZ_SYNO_CHECK_SLIBERR_FMT,	\
	#_VAL, #_EXPR, (__temp_E?"TRUE":"FALSE"), errno,		\
	SYNO_CHECK_SLIBERR_ARGS);	\
} while (0)

#endif /* _SYNOSDK_TEST_CHK_FUNC_H_ */
