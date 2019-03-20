//Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __CONTENT_SEARCH_UTILS_CONNECTION_CWRAP_H__
#define __CONTENT_SEARCH_UTILS_CONNECTION_CWRAP_H__

#include <stdbool.h>
#include <synocontentsearchutils/common.h>

__BEGIN_DECLS;

/**
 * @addtogroup Connection_CWrap
 *
 * @brief The C function for connection operation
 *
 * @{
 */

/**
 * Send search query to daemon, and get the result in callback function
 *
 * @param [IN]  szShareName
 *					which share you want to search
 * @param [IN]  szQuery
 *					query string
 * @param [IN]  pageSize
 *					search result number per page
 * @param [IN]  pageNum
 *					which page you want
 * @param [IN]  pFuncSearchCallback
 *					callback function
 * @param [IN]  cbData
 *					user define data pointer
 * @param [IN]  szAgent
 *					search agent name
 * @param [IN]  uid
 *					search user uid
 * @param [OUT] err
 *					search error code
 *
 * @apparmor none
 *
 * @return true is success, false is failed and error will be set in err
 */
bool SYNOSearchQuerySend(const char *szShareName, const char *szQuery, int pageSize, int pageNum,
		SYNOSearchCallback pFuncSearchCallback, void *cbData, const char *szAgent, uid_t uid, ConnectionErr *err);

/**
 * Init a connection to synocontentsearch daemon.
 *
 * @param [IN] **connection a double pointer to SYNOQueryConnection(domain socket server)
 * @return CONNECTION_ERR_NONE: on success
 *         others             : on failed
 *
 * @apparmor none
 *
 * @code{.c}
 * usage example:
 *
 * SYNOQueryConnection *connection = NULL;
 * if (CONNECTION_ERR_NONE != SYNOQueryConnectionInit(&connection){
 *     SYSLOG(LOG_ERR, "Create SYNOQueryConnectionInit Error");
 *     goto Error;
 * }
 * @endcode
 */
int SYNOQueryConnectionInit(SYNOQueryConnection **connection);

/**
 * Open(send) a "query" to synocontentsearch daemon.
 *
 * @param [IN] *connection
 *          a pointer to SYNOQueryConnection(domain socket server)
 * @param [IN] szShareName
 *          share name
 * @param [IN] szQuery
 *			lucene query string
 * @param [IN] pageNum
 *          page number
 * @param [IN] pageSize
 *          max page size in page number
 * @param [IN]  szAgent
 *          search agent name
 * @param [IN]  uid
 *          search user uid
 * @return CONNECTION_ERR_NONE: on success
 *         others             : on failed
 *
 * @apparmor none
 *
 * @code{.c}
 * usage example:
 *
 * #define PAGE_NUM 1
 * #define MAX_SIZE 10
 * char *szShareName = "Share";
 * char *szQuery = "Hello World";
 *
 * if (CONNECTION_ERR_NONE != SYNOQueryConnectionOpen(
 *                              connection, szShareName,
 *                              szQuery, PAGE_NUM, MAX_SIZE){
 *     SYSLOG(LOG_ERR, "SYNOQueryConnectionOpen Error");
 *     goto Error;
 * }
 * @endcode
 */
int SYNOQueryConnectionOpen(SYNOQueryConnection *connection,
                            const char *szShareName, const char *szQuery,
                            int pageNum, int pageSize, const char *szAgent, uid_t uid);

/**
 * Receive one search record after calling "SYNOQueryConnectionOpen"
 *
 * @param [IN] connection
 *				connection to daemon(domain socket server)
 * @param [OUT] rec
 *				search record to be filled
 * @return error code
 *
 * @apparmor none
 *
 * @code{.c}
 * usage example:
 *
 * SYNOSearchRecord rec;
 *
 * for (int i=0;i<10;i++) {
 *     if(0 == SYNOQueryGetRecord(connection, rec)) {
 *         printf("%s\n",rec.szPath);
 *     } else {
 *         printf("error occured\n");
 *         break;
 *     }
 * }
 * @endcode
 *
 */
int SYNOQueryGetNextRecord(SYNOQueryConnection *connection, SYNOSearchRecord *rec);

/**
 * Fetch Query Result after calling "SYNOQueryConnectionOpen",
 * It just like a "generator", polling the result when needed.
 *
 * @param [IN] connection
 *				connection to daemon(domain socket server)
 * @param [IN] timeout set "select" timeout value
 * @return SYNOSearchRecord
 *
 * @apparmor none
 *
 * @code{.c}
 * usage example:
 *
 * SYNOSearchRecord rec = {"\0","\0"};
 * struct timeval timeout
 * timeout.tv_sec = 3;
 * timeout.tv_usec = 0;
 *
 * for (int i=0;i<10;i++) {
 *     rec = SYNOQueryFetchNext(connection, timeout);
 *     printf("%s\n",rec.szPath);
 * }
 * @endcode
 *
 */
SYNOSearchRecord SYNOQueryFetchNext(SYNOQueryConnection *connection, struct timeval timeout);

/**
 * Close SYNOQueryConnection
 *
 * @param [IN] connection
 *				connection to daemon(domain socket server)
 * @return no return
 *
 * @apparmor none
 *
 * @code{.c}
 * usage example:
 *
 * if (connection) {
 *     SYNOQueryConnectionClose(connection);
 *     connection = NULL;
 * }
 * @endcode
 */
void SYNOQueryConnectionClose(SYNOQueryConnection *connection);

/**
 * @}
 */

__END_DECLS;

#endif
