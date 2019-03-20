// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_INTERNAL_H
#define SYNO_FHOST_INTERNAL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "fhost_log.h"
#ifndef WIN32
#define _FHOST_CKARGS1(es, l, e) do { 												\
if (!(e)) { 																		\
	FHOSTLogErr(l, "Invaild Argument (%s)=[%d]\n", #e, e); 							\
	es; 																			\
} } while(0)
#define _FHOST_CKARGS2(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS1(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS3(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS2(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS4(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS3(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS5(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS4(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS6(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS5(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS7(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS6(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS8(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS7(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS9(es, l, e, ... ) _FHOST_CKARGS1(es, l, e); _FHOST_CKARGS8(es, l, ##__VA_ARGS__)
#else // WIN32
#define _FHOST_CKARGS1(es, l, e) /* do { 												\
if (!(e)) { 																		\
	FHOSTLogErr(l, "Invaild Argument (%s)=[%d]\n", #e, e); 							\
	es; 																			\
} } while(0) */
#define _FHOST_CKARGS2(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS1(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS3(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS2(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS4(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS3(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS5(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS4(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS6(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS5(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS7(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS6(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS8(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS7(es, l, ##__VA_ARGS__)
#define _FHOST_CKARGS9(es, l, e, ... ) //_FHOST_CKARGS1(es, l, e); _FHOST_CKARGS8(es, l, ##__VA_ARGS__)
#endif

/**
 * Checks @a nr arguments, from expr1 to expr##nr, and log when 
 * check failed.  When check failed, this macro will cause the 
 * function return immediately. 
 *  
 * @param nr [IN] The number of expressions to be checked.  From 
 *  		 1 to 9 now.  Should be numeric literal, can not be
 *  		 varialbe.
 * @param exit_stat [IN] The statments to be executed when check 
 *                  expression failed. For example, return 0;
 * @param pLog [IN] The pointer of FHOSTLog to write log 
 *  		   messages.  May be NULL.
 * @param expr1 [IN] The first expression to be checked. 
 *  
 * @return no return 
 */
#define FHOST_CHECK_ARGS(nr, exit_stmt, pLog, expr1, ... ) _FHOST_CKARGS##nr(exit_stmt, pLog, expr1, ##__VA_ARGS__)

/**
 * Gets the number of elements for @a array in compiler time.
 * @param array [IN] The name of array from stack. 
 * @return The number of elements 
 */
#define ARRAY_NUMOF(array) (sizeof(array)/sizeof(array[0]))
#define DBGEXPR(format, expr) FHOSTLogErr(pLog, "%s=[" format "]\n", #expr,  (expr) )
#define DBGSTEP() FHOSTLogErr(pLog, "\n")
#ifdef  __cplusplus
}
#endif
#endif // SYNO_FHOST_INTERNAL_H
