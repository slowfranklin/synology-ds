/**
 * @addtogroup PLUGIN
 *
 * @{
 */

/**
 * Init data used by all module plugin mechanism.
 * This function will search scripts in (each path in @p pslSearchPath)/(@p szPath).
 *
 * @param[in]   szPath          Plugin directory.
 * @param[in]   pslSearchPath   List of absolute paths to search.
 * @param[in]   major           Major version number.
 * @param[in]   minor           Minor version number.
 * @param[out]  ppPlugin        A pointer to get plugin handler. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginInit(const char* szPath, const PSLIBSZLIST pslSearchPath, int major, int minor, PPSLIBPLUGIN ppPlugin);

/**
 * Init data used by all SDK module plugin mechanism
 *
 * @param[in]    szModule   Module name.
 * @param[in]    szPath     Scritps path name.
 * @param[out]   ppPlugin   A pointer to get plugin handler. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginSDKInit(const char* szModule, const char* szPath, PPSLIBPLUGIN ppPlugin);

/**
 * Clean common data used by all SDK module plugin mechanism
 *
 * @param[in]   pPlugin   plugin hander.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) void SLIBPluginExit(PSLIBPLUGIN pPlugin);

/**
 * Disable this plugin, action will not trigger this plugin.
 *
 * @param[in]   pPlugin   plugin hanlder. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginDisable(PSLIBPLUGIN pPlugin);

/**
 * Execute plugin pre-action or post-action
 *
 * @param[in]   action   plugin-action. only support SDK_PLUGIN_PRE or SDK_PLUGIN_POST.
 * @param[in]   pPlugin   plugin handler. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable Yes
 * @user root
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginAction(SDK_PLUGIN_ACTION action, PSLIBPLUGIN pPlugin);

/**
 * Set Plugin arguments
 *
 * @param[in]   pPlugin   plugin handler.
 * @param[in]   szKey   argument key. Should not be NULL or empty string.
 * @param[in]   szValue   argument value. Should not be NULL.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginSetArg(PSLIBPLUGIN pPlugin, const char *szKey, const char *szValue);

/**
 * Set Plugin arguments by array
 *
 * The give an @szPrefix to specified the array prefix
 * The @szPrefix_NUM will set to the total number of the array
 * The @szPrefix_1, @szPrefix_2, ..., @szPrefix_n will set to each array items.
 *
 * @param[in,out]   pPlugin   pPlugin
 * @param[in]   szPrefix   prefix to generate keys for the array. Should not be NULL or empty string.
 * @param[in]   array   value array to store. Should not be NULL.
 * @param[in]   size   size of the array.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginSetArgByArray(PSLIBPLUGIN pPlugin, const char *szPrefix, const char **array, const int size);

/**
 * Set Plugin arguments by int
 *
 * @param[in,out]   pPlugin   plugin handler.
 * @param[in]   szKey   argument key. Should not be NULL or empty string.
 * @param[in]   value   argument value.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginSetArgByInt(PSLIBPLUGIN pPlugin, const char *szKey, int value);

/**
 * Set Plugin arguments by SYNOERR array
 *
 * The give an @szPrefix to specified the array prefix
 * The @szPrefix_NUM will set to the total number of the array
 * The @szPrefix_1, @szPrefix_2, ..., @szPrefix_n will set to each array items.
 * The item value will be format as "0x%04X"
 *
 * @param[in,out]   pPlugin    Plugin handler.
 * @param[in]       szPrefix   prefix to generate keys for the array. Should not be NULL or empty string.
 * @param[in]       array      value array to store. Should not be NULL.
 * @param[in]       size       size of the array.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBPluginSetArgBySynoErrArray(PSLIBPLUGIN pPlugin, const char *szPrefix, const SYNOERR *array, const int size);

/**
 * Check plugin has inited.
 *
 * @param[in]   pPlugin   plugin handler.
 *
 * @retval TRUE has inited.
 * @retval FALSE has not inited.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_5_0) BOOL SLIBPluginHasInit(PSLIBPLUGIN pPlugin);

/**
 * Set Plugin arguments blBlocking
 *
 * @param[in]   pPlugin   plugin handler.
 * @param[in]   blBlocking   blBlocking value.
 *
 * @retval    0    On success.
 * @retval   -1    On error.
 *
 * @grantable No
 */
SDK_STARTING_FROM(SDK_VER_6_1) int SLIBPluginSetBlocking(PSLIBPLUGIN pPlugin, BOOL blBlocking);

/**
 * @}
 */
