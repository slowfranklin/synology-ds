/**
 * @addtogroup SERVICECFG
 *
 * @{
 */

/**
 * Get the string value on @p szKey from @p szServ service config file and put to @p szVal.
 *
 * @param[in]   szServ   Service name used to find specific config file. Should not be NULL.
 * @param[in]   szKey   The searched key from the service config file. Should not be NULL.
 * @param[out]   szVal   The value of found key. Should not be NULL.
 * @param[in]   cbVal   The size of @p szVal.
 *
 * @retval    1 on success.
 * @retval    0 key not found.
 * @retval    -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_FORMAT_ERROR
 * @exception SLIBServicecfgRootObjGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgStrGet(const char *szService, const char *szKey, char *szVal, int cbVal);

/**
 * Replace the value on @p szKey by @p szVal from @p szServ service config file. If @p szKey do not
 * exists, create a new one.
 *
 * @param[in]   szService   Service name used to find specific config file. Should not be NULL.
 * @param[in]   szKey       The searched key. Should not be NULL.
 * @param[in]   szVal       The new value to replace old value. When NULL, delete @p szKey.
 * @param[in]   type        Service framework config type.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgRootObjGet
 * @exception SLIBServicecfgRootObjSet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBServicecfgStrSet(const char *szService, const char *szKey, const char *szVal, SLIB_SERVICECFG_CONFIG_TYPE type);

/**
 * Get @p field value from @p szServ config file and put to @p ppOutList
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   field   The search field.
 * @param[out]  ppOutList   The list store output info. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgRootObjGet
 * @exception ServicecfgListGetFromJArray
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgInfoGet(const char *szServ, SLIB_SERVICECFG_CATEGORY field, PPSLIBSZLIST ppOutList);

/**
 * Set @p field value based on string on @p pInList to @p szServ config file
 *
 * @param[in]   szServ    The service name. Should not be NULL.
 * @param[in]   field     Target field.
 * @param[out]  pInList   The new value to replace old value. When NULL, delete the field.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgRootObjGet
 * @exception SLIBServicecfgRootObjSet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgInfoSet(const char *szServ, SLIB_SERVICECFG_CATEGORY field, const PSLIBSZLIST pInList);

/**
 * Find if @p field have string @p szTarget from @p szServ config file.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   szTarget   Search string. Should not be NULL.
 * @param[in]   field   Target field.
 *
 * @retval    1 on success
 * @retval    0 key not found
 * @retval    -1 on error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBServicecfgInfoGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgInfoFind(const char *szServ, const char *szTarget, SLIB_SERVICECFG_CATEGORY field);

/**
 * If @p szServ has display_name field, return service @p szServ display name
 * (section:key); if @p szServ has display_name field, return service @p szServ
 * service name, otherwise, return @p szServ.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[out]   szVal   The value of found key. Should not be NULL.
 * @param[in]   cbVal   The size of szVal.
 *
 * @retval    0 service display name found
 * @retval    -1 on error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgDisplayNameGet(const char *szServ, char *szVal, int cbVal);

/**
 * Look up service config get service @p szService service name.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[out]   szName   The value of found key. Should not be NULL.
 * @param[in]   cbName   The size of @p szVal.
 *
 * @retval    1 on success.
 * @retval    0 service name not found on service config
 * @retval    -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBServicecfgServiceNameGet(const char *szServ, char *szName, int cbName);

/**
 * Check the run key on @p szServ service config file
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   status   The service status buffer. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgRunKeyGet(const char *szServ, SLIB_SERVICECFG_RUNKEY *status);

/**
 * Set the run key on @p szServ service config file to yes/no
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   status   set runkey based on the value on status,
 *                       should be RUNKEY_START/RUNKEY_STOP/RUNKEY_PAUSE
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrSet()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicecfgRunKeySet(const char *szServ, SLIB_SERVICECFG_RUNKEY status);

/**
 * Validate service config file @p szFilePath
 *
 * @param[in]   szFilePath   service config file.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_FILE_NOT_FOUND
 * @exception ERR_SYS_UNKNOWN
 * @exception ERR_FORMAT_ERROR
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServicecfgValidate(const char* szFilePath);

/**
 * Get service @p szServ status hook
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[out]  szBuf    The buffer to store service status.
 * @param[in]   cbBuf    Number of bytes in @p cbBuf.
 *
 * @retval    1 service have customize service status
 * @retval    0 service do not have customize service status
 * @retval    -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBServicecfgStatusHookGet(const char *szServ, char *szBuf, int cbBuf);

/**
 * Get service @p szServ status hook
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   action   Which action to get.
 * @param[out]  szBuf    The buffer to store service status.
 * @param[in]   cbBuf    Number of bytes in @p szBuf.
 *
 * @retval    1 service have customize service status
 * @retval    0 service do not have customize service status
 * @retval    -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgStrGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBServicecfgActionHookGet(const char *szServ, SLIB_SERVICECFG_ACTION action, char *szBuf, int cbBuf);

/**
 * Enum service config file. Error format file will be move to SZD_SYNOSERVICED_ERRCFG.
 *
 * @param[out]   ppListConfig   List store all service config file path.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBCFileEnumDir
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServciecfgEnum(PSLIBSZLIST *ppListConfig);

/**
 * Get particular settings in /usr/syno/etc/synoservice.d/global.setting by key @p szKey and parent @p szParent
 *
 * @param[in]   szKey       Json key value.
 * @param[in]   szParent    Parent of @p szKey, NULL if @p szKey doesn't have a parent.
 * @param[out]  ppslValue   Values of @p szKey.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_FORMAT_ERROR
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBServiceGlobalSettingGet(const char *szKey, const char *szParent, PSLIBSZLIST *ppslValue);

/**
 * Reset @p szServ service config to default.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServicecfgConfigReset(const char *szServ);

/**
 * Enable / Disable upstart jobs of a given service @p szServ.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   blAdd    TRUE to disable all reference upstart jobs of @p szServ.
 *                       FALSE to enable all reference upstart jobs of @p szServ.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgInfoGet()
 * @exception SLIBServiceInitJobRefCount()
 * @exception SLIBServicectlJobDisable()
 * @exception SLIBServicectlJobEnable()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int ServiceSetOverride(const char *szServ, BOOL blAdd);

/**
 * Manipulate service restart lock for @p szServ by @p value.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   value    App @p value to restart counter.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception SLIBCFileExist()
 * @exception SLIBCFileLockTimeByFile()
 * @exception SLIBCFileGetKeyValue()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int ServiceRestartLockCtl(const char *szServ, int value);

/**
 * Run service hook by given hook path @p szHookPath and given action @p action.
 *
 * @param[in]   szHookPath   The service hook path.
 * @param[in]   action       The service action.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCExec()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int ServiceRunHookByAction(const char *szHookPath, SLIB_SERVICECFG_ACTION action);

/**
 * Restart upstart jobs in @p pListUpstartJob. Stop when error occur if @p blStopOnError is TRUE
 *
 * @param[in]   pListUpstartJob   Upstart job list.
 * @param[in]   blStopOnError     Stop when any job restart failed if @p blStopOnError is TRUE.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicectlStop()
 * @exception ServicecfgInitJobStart()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int ServicecfgInitJobRestart(PSLIBSZLIST pListUpstartJob, BOOL blStopOnError);

/**
 * Reload upstart jobs in @p pListUpstartJob. Stop when error occur if @p blStopOnError is TRUE
 *
 * @param[in]   pListUpstartJob   Upstart job list.
 * @param[in]   blStopOnError     Stop when any job reload failed if @p blStopOnError is TRUE.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServiceGlobalSettingGet()
 * @exception SLIBServicectlReload()
 * @exception ServicecfgInitJobRestart()
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_6_0) int ServicecfgInitJobReload(PSLIBSZLIST pListUpstartJob, BOOL blStopOnError);

/**
 * Start service @p szServ and set the service runkey to yes.
 *
 * When blForce is TRUE, all depended/conflict service of @p
 * szServ will start/stop in dependency sequence.
 *
 * For example, X depend on A', A conflict with A', A depend on B
 * and B depend on C. The ServiceStart(A, TRUE) will perform action:
 * stop(X)->stop(A')->start(C)->start(B)->start(A)
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   blForce   TRUE start @p szServ and start/stop all dependent/conflict service. FALSE only start @p szServ.
 *
 * @retval     0 on success.
 * @retval    -1 on error.
 * @retval    -2 required resource or depend service is not ready
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_RESOURCE_NOT_READY required resource is not ready
 * @exception ERR_INCOMPLETE_DEPENDENCY depend service is disable and blForce=false
 * @exception ERR_CONFLICT_SERV_ENABLED conflict service is enabled and blForce=false
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceStatusGet
 * @exception SLIBServiceTraversal
 * @exception ServicecfgDependResourceIsReady
 * @exception ServicecfgConflictServGet
 * @exception SLIBServiceStateSelect
 * @exception SLIBCSzListPush
 * @exception SLIBServiceStop
 * @exception SLIBServicecfgRunKeySet
 * @exception SLIBServiceInitJobAction
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceStart(const char *szServ, BOOL blForce);

/**
 * Stop service @p szServ and set the service runkey to no.
 *
 * When blForce is TRUE, all service depend on @p szServ
 * will be stopped in dependency sequence.
 *
 * For example, A depend on B, B depend on C.
 * ServiceStop(C, TRUE) will perform action:
 * stop(A)->stop(B)->stop(C)
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   blForce   TRUE stop @p szServ and all the services depend on @p szServ. FALSE only stop @p szServ
 *
 * @retval    0 on success.
 * @retval    -1 on error.
 * @retval    -2 some service depend on @p szServ is enable but blForce=false
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INCOMPLETE_DEPENDENCY some service depend on @p szServ is enable but blForce=false
 * @exception SLIBServiceStatusGet
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceReverseTraversal
 * @exception SLIBServiceInitJobAction
 * @exception SLIBServicecfgRunKeySet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceStop(const char *szServ, BOOL blForce);

/**
 * 1.Stop all init job depended by @p szServ
 * 2.Start all init job depended by @p szServ and remove .override file
 *
 * @note
 * skip service which status is pause or disable.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServiceStatusGet
 * @exception SLIBServiceInitJobAction
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceRestart(const char *szServ);

/**
 * Reload szServ, skip service which status is pause or disable.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServiceStatusGet
 * @exception SLIBServiceInitJobAction
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceReload(const char *szServ);

/**
 * Pause @p szServ and all service depend on @p szServ.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_INCOMPLETE_DEPENDENCY some service depend on @p szServ is enable but blForce=false
 * @exception SLIBServiceStatusGet
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceReverseTraversal
 * @exception SLIBServiceInitJobAction
 * @exception SLIBServicecfgRunKeySet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicePause(const char *szServ);

/**
 * Resume @p szServ.
 * This function will use soft start to resume @p szServ and services which
 * depend on @p szServ.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    0 Resume @p szServ successfully; in other words, @p szServ is running.
 * @retval    -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServiceStatusGet
 * @exception SLIBServiceStart
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceResume(const char *szServ);

/**
 * Pause @p szServ and all service depend on @p szServ by specific @p szReason.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   szReason   The pause reason. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgInfoGet
 * @exception SLIBServicecfgInfoSet
 * @exception SLIBCSzListPush
 * @exception SLIBCSzListAlloc
 * @exception SLIBServicePause
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServicePauseByReason(const char *szServ, const char *szReason);

/**
 * Resume @p szServ by a specific @p szReason.
 * This function will use soft start to resume @p szServ and services which
 * depend on @p szServ.
 *
 * @param[in]   szServ     The service name. Should not be NULL.
 * @param[in]   szReason   The reason to resume. Should not be NULL.
 *
 * @retval    0 Resume @p szServ successfully; in other words, @p szServ is running.
 * @retval    -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServiceStatusGet
 * @exception SLIBServiceStart
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceResumeByReason(const char *szServ, const char *szReason);

 /**
 * Traversal all services depended by @p szServ and put in @p ppOutList.
 * Services on the list will follow dependency sequence. For example, A depend on B, B depend on
 * C. Then @p ppOutList return by ServTraversal(A) will be [C, B]
 *
 * @note
 * Not a thread-safe function.
 *
 * @param[in]    szServ      The service name. Should not be NULL.
 * @param[out]   ppOutList   The services depended by @p szServ on success or the services induce the dependency loop on error ERR_DEPENDENCY_CONTAIN_LOOP. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_DEPENDENCY_CONTAIN_LOOP service dependency contain loop
 * @exception SLIBCSzListAlloc
 * @exception SLIBServicecfgInfoGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceTraversal(const char *szServ, PPSLIBSZLIST ppOutList);

/**
 * Traversal all services depend on @p szServ and put in @p ppOutList. Services on the list will
 * follow dependency order. For example, A depend on B, B depend on C, C depend on D. Then
 * @p ppOutList return by SLIBServiceReverseTraversal(D, ppOutList) will be [A, B, C]
 *
 * @note
 * Not a thread-safe function.
 *
 * @param[in]    szServ      The service name. Should not be NULL.
 * @param[out]   ppOutList   The list store services depend on @p szServ. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceEnum
 * @exception SLIBServicecfgInfoFind
 * @exception SLIBServiceStatusGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceReverseTraversal(const char *szServ, PPSLIBSZLIST ppOutList);

/**
 * Enum all services in /usr/syno/etc/synoservice.d/
 *
 * @param[out]   ppListService   Service list.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServciecfgEnum()
 *
 * @grantable No
 */

SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceEnum(PSLIBSZLIST *ppListService);

/**
 * 1. Check service @p szServ runkey value.
 * 2. Check service @p szServ init job status
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[out]   state   Service status.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBServicecfgRunKeyGet
 * @exception SLIBServiceCheckStatus
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceStatusGet(const char *szServ, SLIB_SERVICECFG_STATE *state);

 /**
 * Check the status of service @p pInList. When @p ppOutList not NULL, put services which
 * status match @p selects to @p ppOutList. When @p ppOutList is NULL, remove services which status
 * not match @p selects from @p pInList.
 *
 * @param[in]    pInList     The services to check.
 * @param[in]    selects     The service status want to search.
 * @param[out]   ppOutList   When not NULL, put service which status match select to @p ppOutList.
 *                           When NULL, remove service which status not match @p select from @p pInList.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListGet
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceStateSelect(PSLIBSZLIST pInList, SLIB_SERVICECFG_STATE selects, PPSLIBSZLIST ppOutList);

/**
 * Check if @p szService is enabled or not.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    TRUE @p szService is enabled.
 * @retval    FALSE @p szService is disabled or on error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBServiceIsEnabled(const char* szService);

/**
 * Check if @p szService is running or not.
 * This function get service status and retrun True only if
 * service is running (runkey and daemon are ready)
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    TRUE @p szService is running
 * @retval    FALSE @p szService is disabled or on error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBServiceIsRunning(const char* szService);

/**
 * Check if @p szService is restarting.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    TRUE @p szService is restarting.
 * @retval    FALSE @p szService is not restarting.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_2) BOOL SLIBServiceIsRestarting(const char* szService);

/**
 * 1. Look up service config to find out @p szService support key.
 * 2. If @p szService do not specific support key, assume support
 * 3. if @p szService specific support key, check synoinfo and
 *    return support if value is yes, otherwise is not support
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    TRUE @p szService is support
 * @retval    FALSE @p szService is not support
 *
 * @grantable No
 *
 * @apparmor None.
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBServiceIsSupport(const char* szService);

/**
 * Check jobs in list @p pslQueryJob that should BrandNewStartStop and put them into @p ppslBrandNewJob.
 * BrandNewStartStopJob means that these job should always stop then start when start is triggered even if they are currently enabled.
 *
 * @param[in]   pslQueryJob       Jobs for query.
 * @param[out]  ppslBrandNewJob   BrandNewStartStopJobs in @p pslQueryJob.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceBrandNewStartStopJobQuery(const PSLIBSZLIST pslQueryJob, PSLIBSZLIST *ppslBrandNewJob);

/**
 * Look up service config to check @p szService have set_stop_on_bootup key or not.
 * If there is no SZ_SLIBSERVICCFG_SET_START_ON_BOOTUP in configure, default value is FALSE.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 *
 * @retval    TRUE @p always set service runkey to stop each time bootup.
 * @retval    FALSE @p no need to set service runkey to stop on bootup.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SLIBServiceIsSetStartOnBootup(const char* szService);

/**
 * Check if @p category resource @p szTarget is exist or not
 *
 * @param[in]   category   The resource category. Should be volume or share.
 * @param[in]   szTarget   The resource name. Should not be NULL.
 *
 * @retval    TRUE the resource is exist and available.
 * @retval    FALSE otherwise
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_VOLUME_NOT_FOUND
 * @exception SLIBShareIsAccessible
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBServiceResourceCheck(SLIB_SERVICECFG_CATEGORY category, const char *szTarget);

/**
 * @p szServ registers @p szShare.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   szShare   The share name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBCSzListPush
 * @exception SLIBServicecfgInfoGet
 * @exception SLIBServicecfgInfoSet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceShareRegister(const char* szServ, const char* szShare);

/**
 * @p szServ unregisters @p szShare.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   szShare   The share name. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBCSzListRemove
 * @exception SLIBServicecfgInfoGet
 * @exception SLIBServicecfgInfoSet
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceShareUnregister(const char* szServ, const char* szShare);

/**
 * Check if all resources depended by @p szServ is ready. When @p ppslVolumeOut or
 * @p ppslShareOut is not NULL, put unready volume/share to corresponding list.
 *
 * When @p szServ depend on other service, this function will also
 * check the resoure required by depended service.
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   type   specific resource type return on ppListOut
 * @param[out]   ppListOut   When not NULL, store unready reosurce
 *
 * @retval    1 all required resources is ready.
 * @retval    0 some required resources is unready.
 * @retval    -1 on error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceTraversal
 * @exception SLIBCSzListPush
 * @exception SLIBServicecfgInfoGet
 * @exception SLIBServiceResourceCheck
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceResourceTraversal(const char *szServ, SLIB_SERVICECFG_CATEGORY type, PPSLIBSZLIST ppListOut);

/**
 * Count the number of enabled services which is depend on @p szJob
 *
 * @param[in]   szJob   The job name. Should not be NULL.
 * @param[in]   job   The init job type. Should be upstart or systemV
 *
 * @retval    >=0 success.
 * @retval    -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBServiceEnum
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceInitJobRefCount(const char *szJob, SLIB_SERVICECFG_CATEGORY job);

/**
 * Start/Stop/Restart the init jobs depended by @p szServ
 *
 * @param[in]   szServ   The service name. Should not be NULL.
 * @param[in]   action   The service action.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCSzListAlloc
 * @exception SLIBServicecfgInfoGet
 * @exception SLIBServicecfgInitJobGet
 * @exception SLIBServicectlRestart
 * @exception SLIBServicectlStart
 * @exception SLIBServicectlStop
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) __attribute__((visibility("hidden"))) int SLIBServiceInitJobAction(const char *szServ, SLIB_SERVICECFG_ACTION action);

/**
 * @}
 */
