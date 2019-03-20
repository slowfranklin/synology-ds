/**
 * @addtogroup MYDS
 *
 * @{
 */

/**
 * @apparmor abstractions/mydscenter
 */
BOOL PaymentSignatureVerifyWithBin(const char *szSign, const char *szData, const size_t cbData, const char *pszKey, const size_t cbszKey);
/**
 * @apparmor abstractions/mydscenter
 */
BOOL PaymentSignatureVerifyWithPEM(const char *szSign, const char *szData, const size_t cbData, const char *szPEMPath);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSGetSerialNumber(char *szSerialOut, int cbSerial);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSGenerateToken(const char *szUser, const char *szPass, char *szSerialOut, int cbSerial, char *szToken, int cbToken);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentConfigGet(PAYMENT_INFO *pINFO);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSServerConfigGet(MYDS_SERVER_INFO *pINFO);
/**
 * @apparmor none
 */
int SYNOMYDSHttpsRequestSend(const LIBMYDS_SYNO_REQUEST *pReq, LIBMYDS_SYNO_RESPONSE *pResponse);
/**
 * @apparmor none
 */
void SYNOMYDSHttpsResponseFree(LIBMYDS_SYNO_RESPONSE *pResponse);
/**
 * @apparmor none
 */
void SYNOMYDSErrSet(MYDS_ERRCODE errCode);
/**
 * @apparmor none
 */
MYDS_ERRCODE SYNOMYDSErrGet(void);
/**
 * @apparmor none
 */
void printErrCode(MYDS_ERRCODE code);
/**
 * @apparmor none
 */
void MapLibMyDSCenterErrorCode(const char *szCode);
/**
 * @apparmor none
 */
MYDS_ERRCODE GetErrorCodeFromCloudService(void);
/**
 * @apparmor none
 */
int MyDSGetMd5String(const char *szIn, char *szOut, int cbOut);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountRemove(void);
/**
 * @apparmor abstractions/mydscenter
 */
BOOL PaymentSynoPaymentSignatureBase64PublicKeyGet(char *szOutput, size_t cbSzOutput);
/**
 * @apparmor abstractions/mydscenter
 */
BOOL PaymentSynoPaymentSignaturePublicKeyGet(char *szOutput, size_t *cbSzOutput);
/**
 * @apparmor abstractions/mydscenter
 */
BOOL PaymentPurchaseSignaturePublicKeyGet(char *szOutput, size_t *cbSzOutput);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSUserAgentNameGet(char *szAgent, int cbAgent);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountGet(MYDS_ACCOUNT *pAccount);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOPaymentMyDSAccountGet(MYDS_ACCOUNT *pAccount);
/**
 * @apparmor abstractions/mydscenter
 */
int SYNOMYDSAccountSet(MYDS_ACCOUNT *pAccount);

/**
 * @}
 */
