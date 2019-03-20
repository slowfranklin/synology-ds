/**
 * @addtogroup UNICODE
 *
 * @{
 */

/**
 * This function opens a UCollator.
 *
 * @retval !NULL A pointer to a UCollator
 * @retval NULL An error occurred.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void *SLIBCUnicodeIOpenCollator(void);

/**
 * This function opens a specified codepage converter.
 *
 * @retval -1      error
 * @retval  1      success
 *
 * @grantable No
 *
 * @apparmor None.
 */
void *SLIBCUnicodeIOpenConvertor(SYNO_CODEPAGE Codepage);

/**
 * This function re-initializes the locale information.
 *
 * @retval -1      error
 * @retval  1      success
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note Because SLIBCUnicodeUTF8StrCaseCmp() and SLIBCUnicodeUTF8StrUpper()
 *       have to read the system locale to perform their function, any
 *       process which has called SLIBCUnicodeUTF8StrCaseCmp() or
 *       SLIBCUnicodeUTF8StrUpper() has to call this function to reload
 *       the new system locale when the system locale changes.
 */
int SLIBCUnicodeReInitLocale(void);

/**
 * This function converts a specified codepage string to the corresponding
 * UTF-8 string.
 *
 * @param[in]  Codepage     the codepage used for conversion
 * @param[in]  szInput      the input codepage string
 * @param[out] szOutput     the converted UTF-8 string on return
 * @param[in]  cbSzOutput   the size of the @p szOutput available in bytes
 *
 * @retval >=0     the converted UTF-8 string length in bytes, not including the terminating NULL
 * @retval -1      error
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note
 * 1. When calling this function with @p cbSzOutput set to 0, the function
 *    will not set @p szOutput, but it'll still return the number of bytes
 *    required for saving the output string. You could use this feature to
 *    get the actual buffer size for saving a converted result. But doing
 *    this is not recommended because it slows down the performance.
 * 2. The size of the converted string may be longer or shorter than
 *    the size of the @p szInput. If the @p cbSzOutput is less than the
 *    length of the converted string, the @p szOutput will be set to
 *    the empty string.
 */
int SLIBCUnicodeStrCPToUTF8(SYNO_CODEPAGE Codepage, const char *szInput, char *szOutput, int cbSzOutput);

/**
 * This function converts a UTF-16 string to the corresponding
 * UTF-8 string.
 *
 * @param[in]  szInput    the input UTF-16 string
 * @param[out] szOutput   the converted UTF-8 string on return
 * @param[in]  cbSzOutput the size of the @p szOutput available in bytes
 *
 * @retval >=0     the converted UTF-8 string length in bytes, not including the terminating NULL
 * @retval -1      error
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note
 * 1. When calling this function with @p cbSzOutput set to 0, the function
 *    will not set @p szOutput, but it'll still return the number of bytes
 *    required for saving the output string. You could use this feature to
 *    get the actual buffer size for saving a converted result. But doing
 *    this is not recommended because it slows down the performance.
 * 2. The size of the converted string may be longer or shorter than
 *    the size of the @p szInput. If the @p cbSzOutput is less than the
 *    length of the converted string, the @p szOutput will be set to
 *    the empty string.
 */
int SLIBCUnicodeStrUTF16ToUTF8(const char *szInput, char *szOutput, int cbSzOutput);

/**
 * This function converts a UTF-8 string to the corresponding specified
 * codepage string.
 *
 * @param[in]    CodePage     the codepage used for conversion
 * @param[in]    szInput      the input UTF-8 string
 * @param[out]   szOutput     the converted codepage string on return
 * @param[in]    cbSzOutput   the size of the @p szOutput available in bytes
 *
 * @retval  -1      error
 * @retval  >=0     the converted codepage string length in bytes, not including the terminating NULL
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note
 * 1. When calling this function with @p cbSzOutput set to 0, the function
 *    will not set @p szOutput, but it'll still return the number of bytes
 *    required for saving the output string. You could use this feature to
 *    get the actual buffer size for saving a converted result. But doing
 *    this is not recommended because it slows down the performance.
 * 2. The size of the converted string may be longer or shorter than
 *    the size of the @p szInput. If the @p cbSzOutput is less than the
 *    length of the converted string, the @p szOutput will be set to
 *    the empty string.
 */
int SLIBCUnicodeStrUTF8ToCP(SYNO_CODEPAGE CodePage, const char *szInput, char *szOutput, int cbSzOutput);

/**
 * This function uppercases the Unicode characters of a UTF-16 (UChar) string
 * according to the current locale.
 *
 * @param[in]    uszInput          the input UTF-16 string
 * @param[out]   puszOutput        the uppercased UTF-16 string
 * @param[in]    cuchPuszOutput    the size of the @p puszOutput available in bytes
 *
 * @retval   -1      error
 * @retval   >=0     the uppercased UTF-16 string length in UChar, not including the terminating NULL
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note When necessary, this function will automatically expand the size of @p puszOutput for fully saving the uppercased UTF-16 strings.
 */
int SLIBCUnicodeIUTF16StrUpper(const UChar *uszInput, UChar **puszOutput, int cuchPuszOutput);

/**
 * This function locates the (@p iNumFwdChar + 1)th Unicode character in the
 * given UTF-8 string.
 *
 * @param[in]   szStr         the input UTF-8 string
 * @param[in]   iNumFwdChar   the number of Unicode characters to be passed (forwarded)
 *
 * @retval   NULL        error
 * @retval   !NULL       a pointer to the (@p iNumFwdChar + 1)th Unicode character
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note
 * 1. The caller should ensure the input string @p szStr is a legal UTF-8
 *    string; otherwise, this function will only try to forward as many
 *    legal Unicode characters as posible and return a pointer to the first
 *    illegal Unicode character encountered.
 * 2. If the number of the Unicode characters in the input string @p szStr is
 *    less than the @p iNumFwdChar, this function will return a pointer to
 *    the terminating character of the input string.
 */
char *SLIBCUnicodeUTF8ForwardNChar(char *szStr, const int iNumFwdChar);

/**
 * This function compares two UTF-8 strings according to the current locale
 * collation.
 *
 * @param[in]    szStr1   the UTF-8 string 1
 * @param[in]    szStr2   the UTF-8 string 2
 *
 * @retval    -2      error
 * @retval    -1      if the @p szStr1 is less than the @p szStr2
 * @retval     0      if the @p szStr1 is equal to the @p szStr2
 * @retval     1      if the @p szStr1 is greater than the @p szStr2
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeUTF8StrCaseCmp(const char *szStr1, const char *szStr2);

/**
 * This function counts the number of Unicode characters (code points)
 * in a UTF-8 string.
 *
 * @param[in]   szStr    the input UTF-8 string
 *
 * @retval    -1      error
 * @retval    >=0     the number of Unicode characters in @p szStr
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeUTF8StrCountChar(const char *szStr);

/**
 * This function compares two UTF-8 strings case sensitively according to the current locale
 * collation.
 *
 * @param[in]    szStr1    the UTF-8 string 1
 * @param[in]    szStr2    the UTF-8 string 2
 *
 * @retval    -2      error
 * @retval    -1      if the @p szStr1 is less than the @p szStr2
 * @retval     0      if the @p szStr1 is equal to the @p szStr2
 * @retval     1      if the @p szStr1 is greater than the @p szStr2
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeUTF8StrCmp(const char *szStr1, const char *szStr2);

/**
 * This function uppercases the Unicode characters of a UTF-8 string
 * according to the current locale.
 *
 * @param[in]    szInput       the input UTF-8 string
 * @param[out]   szOutput      the uppercased UTF-8 string
 * @param[in]    cbSzOutput    the size of the @p szOutput available in bytes
 *
 * @retval   -1      error
 * @retval   >=0     the uppercased string length in bytes, not including the terminating NULL
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @note
 * 1. When calling this function with @p cbSzOutput set to 0, the function
 *    will not set @p szOutput, but it'll still return the number of bytes
 *    required for saving the output string. You could use this feature to
 *    get the actual buffer size for saving a converted result. But doing
 *    this is not recommended because it slows down the performance.
 * 2. The size of the uppercased string may be longer or shorter than
 *    the size of the @p szInput. If the @p cbSzOutput is less than the
 *    length of the uppercased string, the @p szOutput will be set to
 *    the empty string.
 */
int SLIBCUnicodeUTF8StrUpper(const char *szInput, char *szOutput, int cbSzOutput);

/**
 * Determine if a string @p szStr is in UTF-8 format.
 * Please refer to https://en.wikipedia.org/wiki/UTF-8#Description
 *
 * @param[in]    szStr    The input string.
 *
 * @retval 1 Is a UTF-8 string.
 * @retval 0 Is not a UTF-8 string.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeIsUTF8(const char *szStr);

/**
 * Returns SYNO_CODEPAGE according to application type @p Type
 * and language abbreviation string @p szCodepage.
 *
 * @param[in] Type Should be one of:
 *            - SYNO_CODEPAGE_DMS
 *            - SYNO_CODEPAGE_DOS
 *            - SYNO_CODEPAGE_MAC
 *            - SYNO_CODEPAGE_WIN
 * @param[in] szCodepage The string that is language abbreviation, ie, "enu", "cht", "chs"
 *
 * @retval SYNO_CODEPAGE   success
 * @retval -1              error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCodepageValueParse(int Type, const char *szCodepage);

/**
 * This function transfer utf-16 to puny code.
 *
 * @param[in]    src            The utf16 string that will be translated
 * @param[out]   dest           The buffer to save the result of puny code
 * @param[in]    destCapacity   The size of buffer dest
 *
 * @retval -1  On Error
 * @retval >=0 The real length of translated result(puny code)
 *
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_OP_FAILURE
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_UNKNOWN
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeStrUTF16ToPunycode(const char *src, char *dest, int destCapacity);

/**
 * Normalize UTF-8 string @p szIn to NFC, save result UTF-8 string in @p szOut.
 *
 * @param[in] szIn Input UTF-8 string, must not be NULL.
 * @param[out] szOut Result UTF-8 string in NFC, must not be NULL.
 * @param[in] cbOut Size of @p szOut, must >0.
 *
 * @retval 0 On success.
 * @retval -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_NOT_ENOUGH_MEMORY
 * @exception ERR_OP_FAILURE
 * @exception ERR_UNKNOWN
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCUnicodeUTF8StrNormalize(const char *szIn, char *szOut, int cbOut);

/**
 * @}
 */
