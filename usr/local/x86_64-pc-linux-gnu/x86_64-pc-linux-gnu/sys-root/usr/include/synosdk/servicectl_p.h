/**
 * @addtogroup SERVICECTL
 *
 * @{
 */

/**
 * Start @p szJob by initctl and remove @p szJob.override file
 *
 * @param[in]   szJob      The job name.
 * @param[in]   category   Which type of job. System V is deprecated. Should use Upstart only.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicectlJobStart()
 * @exception SLIBServicectlJobEnable()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlStart(const char* szJob, SLIB_SERVICECTL_JOB category);

/**
 * 1.Stop @p szJob
 * 2.Start @p szJob and remove .override file
 *
 * @param[in]   szJob      The job name.
 * @param[in]   category   Which type of job. System V is deprecated. Should use Upstart only.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicectlJobStop()
 * @exception SLIBServicectlJobStart()
 * @exception SLIBServicectlJobEnable()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlRestart(const char* szJob, SLIB_SERVICECTL_JOB category);

/**
 * Reload @p szJob
 *
 * @param[in]   szJob         The job name.
 * @param[in]   category      Which type of job. System V is deprecated. Should use Upstart only.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_SCRIPT  erro when execute inictl
 * @exception SLIBCExec()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlReload(const char* szJob, SLIB_SERVICECTL_JOB category);

/**
 * Get status of @p szServiceName by initctl
 *
 * @param[in]    szJob         The job name.
 * @param[out]   goal          The pointer to a job goal. Should not be NULL.
 * @param[out]   state         The pointer to a job state. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_INVALID service is not enable or not exist
 * @exception ERR_SERVICE_SCRIPT  erro when execute inictl
 * @exception SLIBCExec()
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlStatus(const char* szJob, SLIB_SERVICECTL_GOAL *goal, SLIB_SERVICECTL_STATE *state);

/**
 * Stop @p szJob by initctl and creat @p szJob.override file
 *
 * @param[in]   szJob         The job name.
 * @param[in]   category      Which type of job. System V is deprecated. Should use Upstart only.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicectlJobStop()
 * @exception SLIBServicectlJobDisable()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlStop(const char* szJob, SLIB_SERVICECTL_JOB category);

/**
 * Start @p szJob by initctl. When job's goal is start but the status is not running,
 * try to busy waitting up to 600s.
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_SCRIPT  erro when execute inictl
 * @exception SLIBServicectlStatus()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlJobStart(const char *szJob);

/**
 * Stop @p szJob by initctl. When job's goal is stop but the status is not waitting,
 * try to busy waitting up to 600s.
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_SCRIPT  erro when execute inictl
 * @exception SLIBServicectlStatus()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlJobStop(const char *szJob);

/**
 * Create @p szJob.override file.
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 * @exception ERR_WRITE_FAILED
 * @exception ERR_RENAME_FAILED
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlJobDisable(const char *szJob);

/**
 * Remove @p szJob.override file
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_REMOVE_FAILED
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlJobEnable(const char *szJob);

/**
 * Reload @p szJob by initctl
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SERVICE_INVALID try to reload a stop job
 * @exception SLIBCExec()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicectlJobReload(const char* szJob);

/**
 * Check if @p szJob is running.
 *
 * @param[in]   szJob         The job name. Should not be NULL.
 * @param[in]   category      Which type of job. System V is deprecated. Should use Upstart only.
 *
 * @retval    TRUE    job is started.
 * @retval    FALSE   otherwise
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicectlStatus()
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBServicectlIsJobRunning(const char* szJob, SLIB_SERVICECTL_JOB category);

/**
 * Check if @p szJob.override file exist to distinguish if a job is enabled.
 * Override exist, the job can not received any upstart evnet.
 *
 * @param[in]   szJob   The upstart job name.
 *
 * @retval    TRUE the upstart job is enabled
 * @retval    FALSE the upstart job is not enabled
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) BOOL SLIBServicectlIsJobEnabled(const char* szJob);

/**
 * Emit an upstart event @p szEvent
 *
 *
 * @param[in]   szEvent    Upstart event.
 * @param[in]   pEnvHash   Everiment for this event.
 * @param[in]   blWait     Waiting for event return.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServicectlEventEmit(const char* szEvent, const PSLIBSZHASH pEnvHash, BOOL blWait);

/**
 * @}
 */
