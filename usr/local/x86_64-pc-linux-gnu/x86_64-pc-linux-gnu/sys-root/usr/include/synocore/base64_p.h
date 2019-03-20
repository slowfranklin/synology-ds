/**
 * @addtogroup BASE64
 *
 * @{
 */

/**
 * Encode the data to a Base64 data
 *
 * @param[in]    szStartBuf        The input data. Should not be NULL.
 * @param[in]    bufferSize        The size of encoded input data.
 * @param[out]   szEncodedBuf      The value of found key. Should not be NULL.
 * @param[in]    encodedBufSize    The size of @p szEncodedBuf.
 * @param[in]    blChkZero         Check if stop encoding when szStartBuf points to zero.
 *
 * @retval TRUE On success.
 * @retval FALSE On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCBase64SzEncodeFull(unsigned char *szStartBuf, int bufferSize, char *szEncodedBuf, unsigned long long encodedBufSize, BOOL blChkZero);

/**
 * Encode the data to a base64 buffer with a default max length of output buffer.
 *
 * @param[in] BufStart          The input data. Should not be NULL.
 * @param[in] bufferSize        The size of encoded input data.
 * @param[in] blChkZero         Check if stop encoding when @p BufStart points to zero
 *
 * @retval NULL Failed.
 * @retval !NULL A pointer to a statically allocated buffer of the encoded result.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCBase64SzEncodeBuf(unsigned char *BufStart, int bufferSize, BOOL blChkZero);

/**
 * Encode the data to a base64 buffer, without checking of trailing '\0'.
 *
 * @param[in] BufferStart      The input data. Should not be NULL.
 * @param[in] bufferLength     The size of encoded input data.
 *
 * @retval NULL Failed.
 * @retval !NULL A pointer to a statically allocated buffer of the encoded result.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCBase64SzEncodeBuffer(unsigned char *BufferStart, int bufferLength);

/**
 * Encode the data to a base64 buffer, with checking of trailing '\0'.
 *
 * @param[in] szSubjectStart      The input data. Should not be NULL.
 * @param[in] subjectLength       The size of encoded input data.
 *
 * @retval NULL Failed.
 * @retval !NULL A pointer to a statically allocated buffer of the encoded result.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCBase64SzEncodeOneLine(unsigned char *szSubjectStart, int subjectLength);

/**
 * Decode the data from a Base64 buffer.
 * The length of the output @p outlen will be modified to the actual length of the output.
 *
 * @param[in]     in       The input base64 data. Should not be NULL.
 * @param[in]     inlen    The size of encoded input data.
 * @param[out]    out      The output buffer. Should not be NULL.
 * @param[in,out] outlen   The pointer to the size of @p out. Should not be NULL.
 *
 * @retval TRUE On success.
 * @retval FALSE On error.
 *
 * @exception None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
BOOL SLIBCBase64Decode(const char *in, size_t inlen, char *out, size_t *outlen);

/**
 * @}
 */
