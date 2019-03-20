/* Copyright (c) 2000-2006 Synology Inc. All rights reserved. */
#ifndef _SYNO_DB_H_
#define _SYNO_DB_H_

typedef struct DBConnect_tag DBConnect;
typedef struct DBResult_tag DBResult;

typedef enum DATA_BASE_TYPE_tag {
	DBT_SQLITE3 = 0,
#ifdef USE_PGSQL
	DBT_PGSQL,
#endif
#ifdef USE_MYSQL
	DBT_MYSQL,
#endif
	DBT_NUM_OF_DB
}DATA_BASE_TYPE;

#ifndef USE_PGSQL
#ifndef USE_MYSQL
// sqlite3 default
typedef unsigned long			DBRow;
#endif
#endif

#ifdef USE_PGSQL
#include <libpq-fe.h>
typedef unsigned int 			DBRow;
#endif

//Note: Can not use MySQL!!
#ifdef	USE_MYSQL
#include <mysql.h>
typedef	MYSQL		DBConnect;
typedef	MYSQL_RES	DBResult;
typedef	MYSQL_ROW	DBRow;
#endif

#ifdef WIN32
#define snprintf	_snprintf
#define bzero(x,y)	memset(x, 0, y);
#define	ulonglong	unsigned __int64
#define	LOGMESG
ulonglong atoll(char *szStr);	
#define strtoll(x,y,z)	atoll(x)
#else
#define	ulonglong	unsigned long long
#define	LOGMESG(x...)	syslog(LOG_ERR, x)
#endif

#ifdef __cplusplus                 
extern "C" {
#endif

/**
 * This function is used to connect to a data base. For now, we 
 * support 2 dbs - postgresql and sqlite3. The way to find what 
 * db users want to connect is if the szDB[0] is '/', the target 
 * db is sqlite3. Otherwise, the target db is postgresql. This 
 * function will return a pointer and if you donot want to use 
 * it, call SYNODBClose() to free resource.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szHost [IN] Host address
 * @param szUser [IN] User name
 * @param szPass [IN] Password
 * @param szDB [IN] DB name for postgresql and DB path for 
 *  		   sqlite3
 * 
 * @return DBConnect* 
 * 		Pointer of DB connection handle. 
 * 		NULL: Error occurs. 
 */
DBConnect *SYNODBConnect(const char *szHost, const char *szUser, const char *szPass, const char *szDB);

/**
 * Capabiliy of this function is similiar with SYNODBConnect, 
 * but a persistent connect is maintained. 
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szHost [IN] Host address
 * @param szUser [IN] User name
 * @param szPass [IN] Password
 * @param szDB [IN] DB name for postgresql and DB path for 
 *  		   sqlite3
 * 
 * @return DBConnect* 
 * 		Pointer of DB connection handle. 
 * 		NULL: Error occurs. 
 */
DBConnect *SYNODBPConnect(const char *szHost, const char *szUser, const char *szPass, const char *szDB);

/**
 * This function is used to close a db connection.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 */
void SYNODBClose(DBConnect *pConnection);

/**
 * Execute a sql command "BEGIN" to begin a transation.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBTransBegin(DBConnect *pConnection);

/**
 * Execute a sql command "Commit" to commit a transation.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBTransCommit(DBConnect *pConnection);

/**
 * Execute a sql command "ROLLBACK" to rollback a sql command.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBTransRollback(DBConnect *pConnection);

/**
 * Execute a sql command. This function will saved the pointer 
 * of result handle to *ppResult and if you dont want to use 
 * this result, call SYNODBFreeResult() to release resource.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * @param szSQL [IN] SQL command string
 * @param ppResult [OUT] Pointer of Pointer to db result.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBExecute(DBConnect *pConnection, const char *szSQL, DBResult **ppResult);

/**
 * Capabiliy of this function is similiar with SYNODBExecute, 
 * but it accepts two more parameters - Offset and Limit.  
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * @param szSQL [IN] SQL command string
 * @param Limit [IN] Limitation of row count in result set.
 * @param Offset [IN] Indicate data offset from the query result 
 *  			 to form result set.
 * @param ppResult [OUT] Pointer of Pointer to db result.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBSelectLimit(DBConnect *pConnection, const char *szSQL, int Limit, int Offset, DBResult **ppResult);

/**
 * Return number of affected row duo to previous sql command 
 * like "INSERT", "DELETE", "UPDATE". 
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection [IN] Pointer to a connection handle.
 * @param pResult [IN] Pointer to a db result handle.
 * 
 * @return ulonglong 
 * 		the number of affected rows
 */
ulonglong SYNODBAffectedRows(DBConnect *pConnection, DBResult *pResult);

/**
 * Free db result handle.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pResult [IN] Pointer to a db result handle.
 */
void SYNODBFreeResult(DBResult *pResult);

/**
 * Return number of rows in a result set.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pResult [IN] Pointer to a db result handle.
 * 
 * @return unsigned long 
 * 		the number of rows in a result set.
 */
unsigned long SYNODBNumRows(DBResult *pResult);

/**
 * Fetch the next row in a result set. You can call this 
 * function sequentially to get rows of a result set. And then, 
 * call SYNODBFetchRow() to get a column value. 
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pResult [IN] Pointer to a db result handle.
 * @param pRow [OUT] ID of the row fetched.
 * 
 * @return int 
 *  	0: OK
 *  	-1: Error
 */
int SYNODBFetchRow(DBResult *pResult, DBRow *pRow);

/**
 * Fetch a field in a row.
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pResult [IN] Pointer to a db result handle.
 * @param Row [IN] ID of the target row
 * @param szFieldName [IN] field name
 * 
 * @return char* 
 *  	Value string of this field
 *  	NULL: Invalid parameter
 *  	"": NO value or error
 */
char *SYNODBFetchField(DBResult *pResult, DBRow Row, const char *szFieldName);

/**
 * Escape string for "like" condition. For now, this function 
 * only support postgreSQL usage. 
 * 
 * @author ericlee (2010/10/29)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szTo 
 * @param ToLength 
 * @param szFrom 
 * 
 * @return int 
 */
int SYNODBEscapeBackslash(char *szTo, int ToLength, const char *szFrom);

/**
 * Escape string for "like" condition. According to connection 
 * handle, it will do different escape mechanism. 
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * @param szTo 
 * @param ToLength 
 * @param szFrom 
 * 
 * @return int 
 */
int SYNODBEscapeBackslashEX(DBConnect *pConnection, char *szTo, int ToLength, const char *szFrom);

/**
 * Escape string for "like" condition. 
 * 
 * @author ericlee (2010/10/29) 
 *
 * @apparmor abstractions/synodb
 *  
 * @param dbType
 * @param szTo 
 * @param ToLength 
 * @param szFrom 
 * 
 * @return int 
 */
int SYNODBEscapeBackslashEX2(DATA_BASE_TYPE dbType, char *szTo, int ToLength, const char *szFrom);

/**
 * Escape string. It can be used for postgreSQL.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szTo 
 * @param szFrom 
 * @param FromLength 
 * 
 * @return int 
 */
int SYNODBEscapeString(char *szTo, const char *szFrom, int FromLength);

/**
 * Escape string. According to connection 
 * handle, it will do different escape mechanism. 
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * @param szTo 
 * @param ToLength
 * @param szFrom 
 * @param FromLength 
 * 
 * @return int 
 */
int SYNODBEscapeStringEX(DBConnect *pConnection, char *szTo, int ToLength, const char *szFrom, int FromLength);

/**
 * Escape string. According to connection 
 * handle, it will do different escape mechanism. 
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param dbType
 * @param szTo 
 * @param ToLength
 * @param szFrom 
 * @param FromLength 
 * 
 * @return int 
 */
int SYNODBEscapeStringEX2(DATA_BASE_TYPE dbType, char *szTo, int ToLength, const char *szFrom, int FromLength);

/**
 * Escape string according to db type. 
 * Pattern "@SYNO:VAR" and "@SYNO:LVAR" in pszFormat will be 
 * replaced by parameters following pszFormat. 
 * @SYNO:VAR is for normal string escape. 
 * @SYNO:LVAR is for "like" escape. 
 * 
 * @author Eric (2010/12/5)
 * 
 * @param dbType 
 * @param pszFormat 
 * 
 * @return char* 
 */
char* SYNODBEscapeStringEX3(DATA_BASE_TYPE dbType, const char *pszFormat, ...);

/**
 * Escape string between ' and '.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szCondition 
 * @param szEscapedCondition 
 * 
 * @return int 
 */
int EscapeCondition(const char *szCondition, char *szEscapedCondition);

/**
 * Escape string between ' and '. According to connection 
 * handle, it will do different escape mechanism.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * @param szCondition 
 * @param szEscapedCondition 
 * 
 * @return int 
 */
int EscapeConditionEX(DBConnect *pConnection, const char *szCondition, char *szEscapedCondition);

/**
 * Escape string between ' and '. According to connection 
 * handle, it will do different escape mechanism.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param dbType
 * @param szCondition 
 * @param szEscapedCondition 
 * 
 * @return int 
 */
int EscapeConditionEX2(DATA_BASE_TYPE dbType, const char *szCondition, char *szEscapedCondition);

/**
 * Encode BLOB. It only can be used for postgreSQL.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pFrom 
 * @param FormLength 
 * @param ToLength 
 * 
 * @return unsigned char* 
 */
unsigned char *SYNODBBlogEncode(const unsigned char *pFrom, size_t FormLength, size_t *ToLength);

/**
 * Decode BLOB. It only can be used for postgreSQL.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pFrom 
 * @param ToLength 
 * 
 * @return unsigned char* 
 */
unsigned char *SYNODBBlogDecode(const unsigned char *pFrom, size_t *ToLength);

/**
 * Free memory allocated by SYNODBBlogEncode or 
 * SYNODBBlogDecode. It only can be used for postgreSQL. 
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param ptr 
 */
void SYNODBFreemem(void *ptr);

/**
 * Get error message.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * 
 * @return const char* 
 */
const char *SYNODBErrorGet(DBConnect *pConnection);

/**
 * Set current row cursor of result set.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pResult 
 * @param row 
 */
void SYNODBSetRowCursor(DBResult *pResult, unsigned int row);

/**
 * Escape string and allocate output memory.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param szFrom 
 * 
 * @return char* 
 */
char* SYNODBEscapeStrAlloc(const char* szFrom);

/**
 * Escape string and allocate output memory. According to connection 
 * handle, it will do different escape mechanism.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * @param szFrom 
 * 
 * @return char* 
 */
char* SYNODBEscapeStrAllocEX(DBConnect *pConnection, const char* szFrom);

/**
 * Escape string and allocate output memory. According to connection 
 * handle, it will do different escape mechanism.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param dbType 
 * @param szFrom 
 * 
 * @return char* 
 */
char* SYNODBEscapeStrAllocEX2(DATA_BASE_TYPE dbType, const char* szFrom);

/**
 * Get data base type.
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * 
 * @return DATA_BASE_TYPE 
 */
DATA_BASE_TYPE SYNODBDatabaseTypeGet(DBConnect *pConnection);

/**
 * Get internal database handle. It is not recommended to use 
 * it! 
 * 
 * @author ericlee (2010/11/3)
 *
 * @apparmor abstractions/synodb
 * 
 * @param pConnection 
 * 
 * @return void* 
 */
void* SYNODBInternalDBHdlGet(DBConnect *pConnection);

#ifdef __cplusplus                 
}
#endif

#endif //end of _SYNO_DB_H_
