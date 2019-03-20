/**
 * @addtogroup CRYPT
 *
 * @{
 */

/**
 * The function to encrypt or decrypt buffer and
 * the length of input buffer is equal to the length of output
 * buffer. If input buffer is an encrypted string, output buffer
 * will be an plain string. If input buffer is a plain string,
 * output buffer will be an encrypted string.
 *
 * @param[in]     InBuf  the input string
 * @param[in]     InLen  the length of input bufferr
 * @param[out]    BufOut the output string after encrypt or decrypt
 * @param[in,out] BufLen the length is needed by output buffer
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCryptBufCrypt(const char *InBuf, size_t InLen, char *BufOut, size_t *pBufLen);

/**
 * Encrypt @p InBuf into @p BufOut.
 *
 * @param[in]      InBuf     The input string
 * @param[in]      InLen     The length of @p InBuf
 * @param[out]     BufOut    The output string after encrypt
 * @param[in,out]  BufLen    The length is needed by output buffer
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCryptBufEncrypt(const char *InBuf, size_t InLen, char *BufOut, size_t *pBufLen);

/**
 * Decrypt @p InBuf into @p BufOut.
 *
 * @param[in]      InBuf     The input string
 * @param[in]      InLen     The length of @p InBuf
 * @param[out]     BufOut    The output string after encrypt
 * @param[in,out]  BufLen    The length is needed by output buffer
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCryptBufDecrypt(const char *InBuf, size_t InLen, char *BufOut, size_t *pBufLen);

/**
 * Input plain text @p szPlain and output crypted/base64 encoded string in
 * @p szEncrypted. If the string length of @p szPlain is n, the output size
 * should be large than `(n + 2) / 3 * 4 + 1`.
 *
 * @param[in] szPlain  plain text to encrypt. should not be null.
 * @param[out] szEncrypted buffer for output. should not be null
 * @param[in] cbEncrypted  output buffer size
 *
 * @retval  NULL   error
 * @retval  !NULL  success, return the pointer to @p szEncrypted
 *
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCCryptSzEncrypt(const char *szPlain, char *szEncrypted, size_t cbEncrypted);

/**
 * Input encrypted text @p szEncrypted and output plain text in
 * @p szPlain. If the string length of @p szEncrypted is n, the output size
 * should be large than `(n + 3) / 4 * 3 + 1`.
 *
 * @param[in] szEncrypted  encrypted text. should not be null
 * @param[out] szPlain plain text output. should not be null.
 * @param[in] cbPlain  output buffer size
 *
 * @retval  NULL   error
 * @retval  !NULL  success, return the pointer to @p szPlain
 *
 * @exception ERR_FORMAT_ERROR
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCCryptSzDecrypt(const char *szEncrypted, char *szPlain, size_t cbPlain);

/**
 * Initialize crypt table.
 *
 * @return None.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SYNOICryptInit(void);

/**
 * @}
 */
