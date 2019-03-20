/**
 * Init a SYNO_TMCONF struct (Time Machine config struct)
 *
 * @param[in] pTMConf        A pointer of time machine config struct
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineInit(SYNO_TMCONF *pTMConf);

/**
 * Free a SYNO_TMCONF struct
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 *
 * @grantable N
 */
void SYNOSDTimeMachineFree(SYNO_TMCONF *pTMConf);

/**
 * Enable SYNO_TMCONF strcut AFP adVFFlag
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] blEnableAFP   Set whether broadcast AFP Time Machine (TRUE or FALSE)
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineEnableAFP(SYNO_TMCONF *pTMConf, BOOL blEnableAFP);

/**
 * Enable SYNO_TMCONF strcut SMB adVFFlag
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] blEnableSMB   Set whether broadcast SMB Time Machine (TRUE or FALSE)
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineEnableSMB(SYNO_TMCONF *pTMConf, BOOL blEnableSMB);

/**
 * Find Time Machine Shares in SYNO_TMCONF
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] szShareName   Share Name which we want to search
 *
 * @retval >=0  success
 * @retval  -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineFindShare(const SYNO_TMCONF *pTMConf, const char *szShareName);

/**
 * Append Time Machine share into SYNO_TMCONF
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] szShareName   Share Name which we want to append
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineAppendShare(SYNO_TMCONF *pTMConf, const char *szShareName);

/**
 * Append Time Machine share into disable share list in SYNO_TMCONF,
 * then remove Time Machine share from share list int SYNO_TMCONF
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] szShareName   Share Name which we want to append
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineDisableShare(SYNO_TMCONF *pTMConf, const char *szShareName);

/**
 * Remove Time Machine share into SYNO_TMCONF
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] szShareName   Share Name which we want to remove
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineRemoveShare(SYNO_TMCONF *pTMConf, const char *szShareName);

/**
 * Remove Time Machine share from disable share list in SYNO_TMCONF,
 * then remove share from disable share list.
 *
 * @param[in] pTMConf       A pointer of time machine config struct
 * @param[in] szShareName   Share Name which we want to append
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable N
 */
int SYNOSDTimeMachineEnableShare(SYNO_TMCONF *pTMConf, const char *szShareName);

/**
 * Write SYNO_TMCONF struct into /usr/syno/etc/time_machine.conf
 *
 * @param[in] TMConf       A time machine config struct
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable Y
 */
int SYNOSDTimeMachineSet(const SYNO_TMCONF TMConf);

/**
 * Read /usr/syno/etc/time_machine.conf into SYNO_TMCONF struct
 *
 * @param[in] pTMConf       A pointer of time machien config struct
 *
 * @retval  0  success
 * @retval -1  error
 *
 * @grantable Y
 */
int SYNOSDTimeMachineGet(SYNO_TMCONF *pTMConf);

/**
 * Write xml format of tm.service file into /etc/avahi/services
 *
 * @param[in] TMConf        A time machine config struct
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @grantable Y
 */
int SYNOSDTimeMachineCreateAvahiConf(SYNO_TMCONF TMConf);

/**
 * Remove /etc/avahi/services/tm.services
 *
 * @retval   0  success
 * @retval  -1  error
 *
 * @grantable Y
 */
int SYNOSDTimeMachineDeleteAvahiConf();
