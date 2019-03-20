/* log_current_conn_refresh.c */

/**
 * Gets current connection logs and stores them in pData/szFile.
 * @author \$Author: claudiac $
 * @version \$Revision: 1.4 $
 * @ingroup LOG_int
 * @apparmor abstractions/libsynocurconn
 *
 * @param[in] ppData    The curconn structure to store result
 *
 * @retval  0  success
 * @retval >0  number of connections
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOCurConnGet(PSYNOCURCONN *ppData);

/**
 * Clear unused log of current connection
 *
 * @author \$Author: claudiac $
 * @version \$Revision: 1.6 $
 * @ingroup LOG_int
 * @param szFile [IN] file path to write log
 *
 * @return 0: success
 *         -1: error
 * @apparmor abstractions/libsynocurconn
 *
 * @grantable N
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOCurConnRefresh(const char *szFilePath);

/**
 * Check and refresh the Log
 *
 * @param[in] szFile      SZF_ATLOG or SZF_FTPD_CONNECTION_REC.
 * @param[in] szFileTmp   File to store result
 *
 * @retval  0  success
 * @retval -1  generic error
 *
 * @grantable N
 * @apparmor abstractions/libsynocurconn
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOCurConnCheckLog(char *szFile, char *szFileTmp);

/**
 * Get current ESTABLISHED tcp connection with specific @port
 *
 * @param ppRemoteAddress [IN/OUT] - The remote connection ip address, should not be NULL
 * @param port [IN] - The port want to search, when 0, means all port
 * @param blIPv4 [IN] - When true, find tcp connection from "/proc/net/tcp"
 * @param blIPv6 [IN] - When true, find tcp connection from "/proc/net/tcp6"
 *
 * @return 0: Success
 *         -1: Failed
 *
 * @apparmor abstractions/libsynocurconn
 * @grantable: N
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOCurConnGetTCPConByPort(PPSLIBSZLIST ppRemoteAddress, int port, BOOL blIPv4, BOOL blIPv6);
