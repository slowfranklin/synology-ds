/******************************************************************
 * Becareful! You can't use function as parameter of macro.       *
 * It will expand in macro, and execute the function as the       *
 * number of times in macro!                                      *
 ******************************************************************/
#ifndef _SYNO_TEST_H_
#define _SYNO_TEST_H_

#include <errno.h>
#include <string.h>

#include <check.h>

#include <synocore/synotype.h>
#include <synocore/error.h>

typedef Suite *(*PFUNC_TESTSUITE)(void);
typedef TCase *(*PFUNC_TESTCASE)(void);

typedef struct {
	char        szTest[32];
	PFUNC_TESTSUITE fpTestSuite;
	BOOL        blTest;
} SYNO_TEST_OPT;

/**
 * Stop and print messages when @a expr is true.
 * @param expr [IN] 
 * @ingroup UNITTEST_int
 */
#define SYNOCheck(expr) _fail_unless(!(expr), __FILE__, __LINE__,\
		"Failure '"#expr"' occured" , #expr, NULL)

#define SYNOCheckStrEq(str1, str2) \
		do { \
			if (str1 == NULL && str2 == NULL) {} \
			else if (str1 == NULL || str2 == NULL) { \
				fail(__FILE__, __LINE__, \
				"Failure '"#str1"[%s] == NULL or "#str2"[%s] == NULL' occured", \
				#str1"[%s] == NULL or "#str2"[%s] == NULL or ", str1, str2, NULL); \
			} else { \
				_fail_unless(0 == strcmp(str1, str2), __FILE__, __LINE__, \
				"Failure '"#str1"[%s] != "#str2"[%s]' occured" , \
				#str1"[%s] != "#str2"[%s]", str1, str2, NULL); \
			} \
		} while (0)

#define SYNOCheckStrNEq(str1, str2) _fail_unless((strcmp(str1, str2)), __FILE__, __LINE__,\
		"Failure '"#str1"[%s] == "#str2"[%s]' occured" , #str1"[%s] == "#str2"[%s]", str1, str2, NULL)

#define SYNOCheckHexEq(int1, int2) _fail_unless(int1 == int2, __FILE__, __LINE__,\
		"Failure '"#int1"[0x%04X] != "#int2"[0x%04X]' occured" , #int1"[0x%04X] != "#int2"[0x%04X]", int1, int2, NULL)

#define SYNOCheckHexLLEq(int1, int2) _fail_unless(int1 == int2, __FILE__, __LINE__,\
		"Failure '"#int1"[0x%04llX] != "#int2"[0x%04llX]' occured" , #int1"[0x%04llX] != "#int2"[0x%04llX]", int1, int2, NULL)

#define SYNOCheckFail(_NOT_EXPR, _MSG, ...)												\
	_fail_unless(_NOT_EXPR, __FILE__, __LINE__, "Failure '" _MSG "' occured", _MSG,		\
	## __VA_ARGS__, NULL)

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
#define _SYNOChkVar(_TYPE, _TFMT, _VAL, _OP, _EXPR) \
do {																					\
	_TYPE __temp_V;																		\
	_TYPE __temp_E; 																	\
	__temp_E = (_TYPE)(_EXPR); __temp_V = (_TYPE)(_VAL);								\
	SYNOCheckFail(__temp_V _OP __temp_E,												\
	"(%s=["_TFMT"]) %s (%s=["_TFMT"]) test failed",										\
	#_VAL, __temp_V, #_OP, #_EXPR, __temp_E);											\
} while (0)

/**
 * Pass when the two interger @a int1 equals to @a int2. 
 *  
 * @param int1 [IN] The integer to be tested.
 * @param int2 [IN] The variable or expression to be evaluated. 
 *  
 * @ingroup UNITTEST
 */
#define SYNOCheckIntEq(int1, int2) _SYNOChkVar(int, "%d", int1, ==, int2)

/**
 * Pass when the two interger @a int1 does not equal to @a int2.
 *  
 * @param int1 [IN] The integer to be tested.
 * @param int2 [IN] The variable or expression to be evaluated. 
 *  
 * @ingroup UNITTEST
 */
#define SYNOCheckIntNEq(int1, int2) _SYNOChkVar(int, "%d", int1, !=, int2)

/**
 * Pass when the @a ptr is NULL. 
 *  
 * @param ptr [IN] The pointer to be tested.
 *  
 * @ingroup UNITTEST
 */
#define SYNOCheckIsNull(ptr) _SYNOChkVar(void *, "%p", NULL, ==, ptr)

/**
 * Pass when the @a ptr is not NULL. 
 *  
 * @param ptr [IN] The pointer to be tested.
 *  
 * @ingroup UNITTEST
 */
#define SYNOCheckNonNull(ptr) _SYNOChkVar(void *, "%p", NULL, !=, ptr)

#define _SYNOCheckArray(_TFMT, _EXPR1, _EXPR2, _NUM) \
do {																				\
	int __idx = 0;																	\
	for ( __idx = 0; __idx < _NUM;	 ++__idx ) {									\
	SYNOCheckFail(((_EXPR1)[__idx]) == ((_EXPR2)[__idx]),							\
	"(%s[%d]=["_TFMT"]) == (%s[%d]=["_TFMT"]) test failed, ",						\
	#_EXPR1, (__idx), ((_EXPR1)[__idx]), #_EXPR2, __idx, ((_EXPR2)[__idx])			\
	);																				\
	}																				\
} while (0)

#define SYNOCheckArrayInt(_EXPR1, _EXPR2, _NUM) _SYNOCheckArray("%d", _EXPR1, _EXPR2, _NUM)
#define SYNOCheckArrayHex(_EXPR1, _EXPR2, _NUM) _SYNOCheckArray("%04X", _EXPR1, _EXPR2, _NUM)

#define SZ_SYNO_CHECK_SLIBERR_FMT "SLIBCErrGet()=[0x%04X, at %s:%d]"
#define SYNO_CHECK_SLIBERR_ARGS	SLIBCErrGet(), SLIBCErrorGetFile()?SLIBCErrorGetFile():"(NULL)", SLIBCErrorGetLine()

#define SYNOCheckSLIBErr(_slib_error) \
_fail_unless((_slib_error == SLIBCErrGet()), __FILE__, __LINE__,\
		"Failure '"#_slib_error" != SLIBCErrGet()=[0x%04X, at %s:%d]' occured" , \
		#_slib_error" != SLIBCErrGet()=[0x%04X, at %s:%d]", 						\
		SLIBCErrGet(), SLIBCErrorGetFile()?SLIBCErrorGetFile():"(NULL)", 			\
		SLIBCErrorGetLine(), NULL)

/**
 * Pass when the current errno is @a _libc_error.
 *  
 * @param _libc_error [IN] The error number to be tested.
 *  
 * @ingroup UNITTEST
 */
#define SYNOCheckErrno(_libc_error) SYNOCheckFail(_libc_error != errno,	"Failure '%s != errno=[%d(%s)]' occured" , #_libc_error, errno, strerror(errno))

#include "syno_test_chk_func.h"

#define SYNOCheckKeyInFile(_filename, _szKey) SYNOCheckFileByKey(_filename, _szKey, ':', TRUE, __FILE__, __LINE__);
#define SYNOCheckKeyNotInFile(_filename, _szKey) SYNOCheckFileByKey(_filename, _szKey, ':', FALSE, __FILE__, __LINE__);

#endif /* _SYNO_TEST_H_ */
