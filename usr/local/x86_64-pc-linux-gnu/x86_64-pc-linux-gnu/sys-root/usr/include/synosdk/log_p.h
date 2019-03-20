/**
 * @addtogroup LOG
 *
 * @{
 */

/**
 * Write given log content to specified FD.
 *
 * @param[in]   socketfd   Log fd to be written
 * @param[in]   Log   Log structure
 *
 * @retval   0   On success.
 * @retval   -1  On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOSyslogSocketWrite(int socketfd, SYNOSYSLOG *Log);

/**
 * convert event key by input
 *
 * @param[in]   eventID   get event from event text by eventID
 * @param[in]   szLang   specify language
 * @param[in]   szArg1   event key 1
 * @param[in]   szArg2   event key 2
 * @param[in]   szArg3   event key 3
 * @param[in]   szArg4   event key 4
 *
 * @return event string which be converted
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOLogConvertEventKey(unsigned long eventID, const char *szLang, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4);

/**
 * Convert @p timeid to printable format.
 *
 * @param[in]   timeid    The time to be converted.
 *
 * @return   A statically allocated string of printable time format.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOLogConvertTime1(long timeid);

/**
 * Get the log type string, e.g. "Information", "Warning", "Error".
 * See the section [11000000] in /usr/syno/synosdk/texts/enu/events.
 *
 * @param[in]    eventType   The event type. Should be one of LOG1_INFO, LOG1_WARN, LOG1_ERR, LOG1_CRIT.
 * @param[in]    szLang      The language of the type string. Currently only supports "enu".
 *
 * @return   A statically allocated string of log type.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOLogConvertType(unsigned char eventType, const char *szLang);

/**
 * Write @p logClass log message to @p szLogOutputFile
 *
 * @param[in]   logClass   logClass
 * @param[in]   szLogOutputFile   file the log to be wrote
 * @param[in]   szLang   not use
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLogGet1(int logClass, const char *szLogOutputFile, const char *szLang);

/**
 * Get @p logClass log file
 *
 * @param[in]   logClass        logClass
 * @param[out]  szLogFilePath   filename be to stored
 * @param[in]   cbLogFilePath   size of @p szLogFilePath
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLogFilePathGet(int logClass, char *szLogFilePath, int cbLogFilePath);

/**
 * Obtain the administrator's account by searching the environment list for a string that
 * matches the string pointed to by "USERNAME"
 *
 * @retval    "empty string"       On error.
 * @retval    "non-empty string"   On success, return administrator's account.
 *
 * @exception SYNOUserGetByUID()
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOLogObtainUser(void);

/**
 * Write log to synosyslog.
 *
 * @p logClass determine which log files:
 * - LOG1_MAN, LOG1_SYS: /var/log/synolog/synosys.log
 * - LOG1_CON: /var/log/synolog/synoconn.log
 * - LOG1_BAK: /var/log/synolog/synobkp.log
 * - LOG1_COPY: /var/log/synolog/usbcopy.log
 *
 * @param[in]   logClass    LOG1_SYS, LOG1_MAN, LOG1_CON, LOG1_BAK, or LOG1_COPY
 * @param[in]   eventType   LOG1_INFO, LOG1_WARN, LOG1_ERR or LOG1_CRIT
 * @param[in]   eventID     for example, 0x11100001
 * @param[in]   szArg1      "" or valid string pointer
 * @param[in]   szArg2      "" or valid string pointer
 * @param[in]   szArg3      "" or valid string pointer
 * @param[in]   szArg4      "" or valid string pointer
 *
 * @retval  0    On success.
 * @retval  -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLogSet1(int logClass, int eventType, unsigned long eventID, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4);

/**
 * Write synology log message to default domain socket.
 * The socket is listened by Syslog-ng, and message will be send
 * out to specified syslog server.
 *
 * @param[in]   SynoFacility   Synology defined facility
 * @param[in]   SynoSeverity   Synology defined severity
 * @param[in]   szContent   Log content
 *
 * @retval  0    On success.
 * @retval  -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOSyslogSend(int SynoFacility, int SynoSeverity, char *szContent);

/**
 * Clean log files which are belong to @p logClass
 *
 * @param[in]   logClass   logClass
 *
 * @return None.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_4_3) void SYNOLogClean(int logClass);

/**
 * Implemation to write log to synosyslog.
 *
 * @p logClass determine which log files:
 * - LOG1_MAN, LOG1_SYS: /var/log/synolog/synosys.log
 * - LOG1_CON: /var/log/synolog/synoconn.log
 * - LOG1_BAK: /var/log/synolog/synobkp.log
 * - LOG1_COPY: /var/log/synolog/usbcopy.log
 *
 * @param[in]   logClass   LOG1_SYS, LOG1_MAN, LOG1_CON, LOG1_BAK, or LOG1_COPY
 * @param[in]   eventType   LOG1_INFO, LOG1_WARN, LOG1_ERR or LOG1_CRIT
 * @param[in]   eventID   for example, 0x11100001
 * @param[in]   szArg1   "" or valid string pointer
 * @param[in]   szArg2   "" or valid string pointer
 * @param[in]   szArg3   "" or valid string pointer
 * @param[in]   szArg4   "" or valid string pointer
 * @param[in]   szSerialNumber   will be appended to the log
 *
 * @retval  0    On success.
 * @retval  -1   On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SYNOLogSet1Imp(int logClass, int eventType, unsigned long eventID, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4, const char *szSerialNumber);

/**
 * @}
 */
